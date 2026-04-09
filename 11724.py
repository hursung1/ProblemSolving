import sys
import copy
from collections import defaultdict

def bfs(vertices: list[bool], edge_info: dict):
    not_visited = [i for i in range(len(vertices))]

    queue = [0]
    vertices[0] = True
    connected_graphs = 0

    while True:
        current = queue.pop(0)

        if current in not_visited:
            not_visited.remove(current)
        
        for node in edge_info[current]:
            if not vertices[node]:
                queue.append(node)
                vertices[node] = True

        if not queue:
            connected_graphs += 1
            if not_visited:
                queue.append(not_visited[0])
            else:
                break

    return connected_graphs


raw_input = sys.stdin.read().strip().split("\n")
n, m = raw_input[0].split()
n = int(n)
m = int(m)

comp_num = 0
vertices = [False for _ in range(0, n)]
edge_info = defaultdict(list)

for i in range(1, m+1):
    v1, v2 = raw_input[i].split()
    v1 = int(v1)-1
    v2 = int(v2)-1

    edge_info[v1].append(v2)
    edge_info[v2].append(v1)

print(bfs(vertices=vertices, edge_info=edge_info))
