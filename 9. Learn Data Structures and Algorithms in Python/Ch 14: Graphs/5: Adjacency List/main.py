class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        self.graph[u] = self.graph.get(u, set())
        self.graph[u].add(v)
        self.graph[v] = self.graph.get(v, set())
        self.graph[v].add(u)

    # don't touch below this line

    def edge_exists(self, u, v):
        if u in self.graph and v in self.graph:
            return (v in self.graph[u]) and (u in self.graph[v])
        return False

