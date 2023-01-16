def dijkstra(graph, n, stpt, dest):
    ## Dijkstra Algorithm
    f = lambda i: dist[i]
    dist = [float("inf") for i in range(n)]
    visited = []
   
    dist[stpt] = 0
    while True:
        if min(dist) == float("inf"):
            print("INF")
            break

        tmp = sorted(range(len(dist)), key=f)
        '''
        print(dist)
        print(tmp)
        print("======================")
        '''
        for index in tmp:
            if index not in visited:
                cur = index
                visited.append(cur)
                break
        
        if cur == dest:
            if dist[cur] == float("inf"):
                print("INF")
            else:
                print(dist[cur])
            break

        for tup in graph[cur]:
            nextpt = tup[0] # dest
            weight = tup[1] # weight
            dist[nextpt] = min(dist[nextpt], dist[cur] + weight)
            
n, m = input().split()
n = int(n)
m = int(m)
stpt = int(input()) - 1

## Graph: double array
graph = {}

for i in range(n):
    graph[i] = []

for i in range(m):
    start, end, weight = input().split()
    start = int(start) - 1
    end = int(end) - 1
    weight = int(weight)

    graph[start].append((end, weight))

for i in range(n):
    dijkstra(graph, n, stpt, i)
