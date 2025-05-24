class Graph:
    def bfs_path(self, start, end):
        visited = []
        to_visit = []
        to_visit.append(start)
        while len(to_visit) != 0:
            current_node = to_visit.pop(0)
            sorted_neighbours = sorted(self.graph[current_node])
            for v in sorted_neighbours:
                if v == end:
                    visited.append(v)
                    return visited
                if v not in visited and v not in to_visit:
                    to_visit.append(v)
        return None

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

