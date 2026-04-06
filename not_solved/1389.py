import sys

raw_input = sys.stdin.read().split("\n")
node = int(raw_input[0].strip().split()[0])
edge = int(raw_input[0].strip().split()[1])
graph = []

bfs_queue = []
visited = []

for k in range(edge):
    rel_info = raw_input[k+1].strip().split()
    graph.append([int(rel_info[0]), int(rel_info[1])].sort())

# kevin beacon number를 구하기 위한 BFS 순회
kb_dict = []

for n in range(node):
    kb_num = 0
    current_node = n

    for e in graph:
        if current_node in e:


    bfs_queue.append()
    kb_dict.append()
print(graph)