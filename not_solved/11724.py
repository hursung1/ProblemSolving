import sys
from collections import defaultdict

def bfs(vertices, edge_info):
    visited = []
    queue = [vertices[0]]
    while queue:
        vtx = queue.pop(0)
        if vtx in visited:
            continue
        visited.append(vtx)
        queue.extend(edge_info[vtx])
        
        front = 0
        rear = len(vertices) - 1
        
        while front <= rear:
            mid = (front + rear) // 2
            if vertices[mid] < vtx:
                front = mid + 1
            elif vertices[mid] > vtx:
                rear = mid - 1
            else:
                del vertices[mid]
                break


def dfs(vertices, edge_info, stack, visited):
    print(stack, visited)
    vtx = stack[-1]
    visited.append(vtx)
    for elem in edge_info[vtx]:
        if not elem in visited:
            stack.append(elem)
            dfs(vertices, edge_info, stack, visited)

    stack = stack[:-1]

    front = 0
    rear = len(vertices) - 1
    
    while front <= rear:
        mid = (front + rear) // 2
        if vertices[mid] < vtx:
            front = mid + 1
        elif vertices[mid] > vtx:
            rear = mid - 1
        else:
            del vertices[mid]
            break


n, m = sys.stdin.readline().strip().split()
n = int(n)
m = int(m)

comp_num = 0
vertices = list(range(1, n+1))
edge_info = defaultdict(list)

for _ in range(m):
    v1, v2 = sys.stdin.readline().strip().split()
    v1 = int(v1)
    v2 = int(v2)

    edge_info[v1].append(v2)
    edge_info[v2].append(v1)

while vertices:
    stack, visited = [vertices[0]], []
    dfs(vertices, edge_info, stack, visited)
    # bfs(vertices, edge_info)
    comp_num += 1

print(comp_num)
