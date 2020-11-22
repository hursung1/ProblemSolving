n = int(input())
timelist = []
best = []
for i in range(n):
    tmp = input().split()
    timelist.append([int(tmp[i]) for i in range(len(tmp))])

timelist.sort(key=lambda x:x[0])
timelist.sort(key=lambda x:x[1])

print(timelist)


best.append(timelist[0])
for i in range(1, len(timelist)):
    if timelist[i][0] >= best[len(best)-1][1]:
        best.append(timelist[i])

print(best)
print(len(best))
