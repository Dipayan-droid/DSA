class GraphList:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v):
        if u >= self.V or v >= self.V:
            print("Invalid edge")
            return
        self.graph[u].append(v)
        self.graph[v].append(u)  # Undirected graph

    def count_vertices(self):
        return self.V

    def count_edges(self):
        count = sum(len(adj) for adj in self.graph)
        return count // 2  # Each edge counted twice in undirected

    def adjacent_vertices(self, vertex):
        if vertex >= self.V:
            print("Invalid vertex")
            return []
        return self.graph[vertex]

    def search_vertex(self, vertex):
        return 0 <= vertex < self.V


# Example usage
if __name__ == "__main__":
    g = GraphList(4)
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
