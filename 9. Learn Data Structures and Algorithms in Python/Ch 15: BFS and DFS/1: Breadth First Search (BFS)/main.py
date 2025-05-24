class Graph:
    def breadth_first_search(self, v):
        visited = []
        to_visit = []
        to_visit.append(v)
        while len(to_visit) != 0:
            current_vertex = to_visit.pop(0)
            visited.append(current_vertex)
            sorted_neighbours = sorted(self.graph[current_vertex])
            for v in sorted_neighbours:
                if v not in visited and v not in to_visit:
                    to_visit.append(v)
        return visited

    # don't touch below this line

    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        if u in self.graph.keys():
            self.graph[u].add(v)
        else:
            self.graph[u] = set([v])
        if v in self.graph.keys():
            self.graph[v].add(u)
        else:
            self.graph[v] = set([u])

    def __repr__(self):
        result = ""
        for key in self.graph.keys():
            result += f"Vertex: '{key}'\n"
            for v in sorted(self.graph[key]):
                result += f"has an edge leading to --> {v} \n"
        return result

