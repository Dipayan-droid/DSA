#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

// Function to initialize the graph with zero edges
void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices (undirected graph)
void addEdge(int u, int v) {
    if (u >= numVertices || v >= numVertices) {
        printf("Invalid vertex number.\n");
        return;
    }
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Count the number of edges in the graph
int countEdges() {
    int count = 0;
    for(int i = 0; i < numVertices; i++) {
        for(int j = i+1; j < numVertices; j++) {
            if(graph[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Print adjacent vertices of a given vertex
void printAdjacentVertices(int v) {
    if (v >= numVertices) {
        printf("Invalid vertex number.\n");
        return;
    }
    printf("Adjacent vertices of vertex %d are: ", v);
    int found = 0;
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

// Search if a vertex exists in the graph
int searchVertex(int vertex) {
    return (vertex >= 0 && vertex < numVertices);
}

int main() {
    int vertices, edges, u, v, vertex;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) pairs (0-based indexing):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Number of vertices: %d\n", numVertices);
    printf("Number of edges: %d\n", countEdges());

    printf("Enter vertex to find adjacent vertices: ");
    scanf("%d", &vertex);
    printAdjacentVertices(vertex);

    printf("Enter vertex to search in graph: ");
    scanf("%d", &vertex);
    if(searchVertex(vertex)) {
        printf("Vertex %d exists in the graph.\n", vertex);
    } else {
        printf("Vertex %d does not exist in the graph.\n", vertex);
    }

    return 0;
}
