import sys

raw_input = sys.stdin.read().strip().split("\n")
num_nodes = int(raw_input[0])

edge_info = []
parent_info = {i+1: 0 for i in range(num_nodes)}
bfs_queue = [1]
visited = [1]

for i in range(1, len(raw_input)):
    edge = raw_input[i].split()
    node1, node2 = int(edge[0]), int(edge[1])
    edge_info.append((node1, node2))

# BFS 수행하며 각 node의 parent 확인
while len(visited) < num_nodes:
    current_node = bfs_queue.pop(0)
    for edge in edge_info:
        if current_node in edge:
            another_node = edge[0] if current_node == edge[1] else edge[1]
            if not another_node in visited:
                bfs_queue.append(another_node)
                parent_info[another_node] = current_node
                visited.append(another_node)

for value in parent_info.values():
    if value: print(value)