num_com = int(input())
num_edge = int(input())

graph_info = {}
for i in range(num_com):
    graph_info[i+1] = []

for _ in range(num_edge):
    v1, v2 = input().split()
    v1 = int(v1)
    v2 = int(v2)
    
    graph_info[v1].append(v2)
    graph_info[v2].append(v1)

visited = []
queue = [1]

while queue:
    to_visit = queue.pop(0)
    if to_visit in visited:
        continue

    visited.append(to_visit)
    queue.extend(graph_info[to_visit])

print(len(visited)-1)
