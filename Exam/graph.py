class GraphMatrix:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        if u >= self.V or v >= self.V:
            print("Invalid edge")
            return
        self.graph[u][v] = 1
        self.graph[v][u] = 1  # For undirected graph

    def count_vertices(self):
        return self.V

    def count_edges(self):
        count = 0
        for i in range(self.V):
            for j in range(i + 1, self.V):
                if self.graph[i][j] == 1:
                    count += 1
        return count

    def adjacent_vertices(self, vertex):
        if vertex >= self.V:
            print("Invalid vertex")
            return []
        return [i for i, val in enumerate(self.graph[vertex]) if val == 1]

    def search_vertex(self, vertex):
        return 0 <= vertex < self.V


# Example usage
if __name__ == "__main__":
    g = GraphMatrix(4)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 3)

    print("Vertices:", g.count_vertices())
    print("Edges:", g.count_edges())
    v = 2
    print(f"Adjacent vertices to {v}:", g.adjacent_vertices(v))
    search_node = 3
    print(f"Vertex {search_node} {'found' if g.search_vertex(search_node) else 'not found'} in the graph.")
