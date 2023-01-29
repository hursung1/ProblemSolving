from queue import PriorityQueue

v, e = input().split()
v = int(v)
e = int(e)
s = int(input())

edge_info = {}
for _ in range(e):
    stpt, endpt, cost = input().split()
    stpt = int(stpt)
    endpt = int(endpt)
    cost = int(cost)
    if not stpt in edge_info.keys():
        edge_info[stpt] = []

    edge_info[stpt].append((endpt, cost))

cost = [float("inf") for _ in range(v)]
current = s
cost[current-1] = 0
unvisited = list(range(1, v+1))


while unvisited:
    cost_heap = PriorityQueue() # elem: (vertex, cost)
    for v, c in enumerate(cost):
        cost_heap.put((c, v+1))

    _, current = cost_heap.get()

    print(unvisited)
    print(current)
    if current in edge_info.keys():
        for v, c in edge_info[current]:
            new_cost = cost[current-1] + c
            if cost[v-1] > new_cost:
                cost[v-1] = new_cost
    
    if current in unvisited:
        unvisited.remove(current)

print(cost)