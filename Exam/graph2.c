#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since undirected graph, add edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Count edges in the graph
int countEdges(struct Graph* graph) {
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            count++;
            temp = temp->next;
        }
    }
    // Each edge counted twice in undirected graph
    return count / 2;
}

// Print adjacent vertices of given vertex
void printAdjacentVertices(struct Graph* graph, int vertex) {
    if (vertex >= graph->numVertices) {
        printf("Vertex does not exist\n");
        return;
    }
    printf("Adjacent vertices of vertex %d: ", vertex);
    struct Node* temp = graph->adjLists[vertex];
    if (!temp) {
        printf("None");
    }
    while (temp) {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

// Search a vertex existence (by checking adjacency)
int searchVertex(struct Graph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->numVertices) {
        return 0;
    }
    return 1;
}

int main() {
    int vertices, edges, src, dest, vertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Number of vertices: %d\n", graph->numVertices);
    printf("Number of edges: %d\n", countEdges(graph));

    printf("Enter a vertex to print adjacent vertices: ");
    scanf("%d", &vertex);
    printAdjacentVertices(graph, vertex);

    printf("Enter a vertex to search in graph: ");
    scanf("%d", &vertex);
    if (searchVertex(graph, vertex))
        printf("Vertex %d exists in the graph.\n", vertex);
    else
        printf("Vertex %d does not exist in the graph.\n", vertex);

    // Free graph memory here if needed

    return 0;
}
