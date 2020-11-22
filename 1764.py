n, m = input().split()
n = int(n)
m = int(m)

deutbo = []
namelist = []
for i in range(n):
    name = input()
    namelist.append(name)

namelist.sort()

for i in range(m):
    name = input()
    mid = len(namelist) // 2
    low = 0
    high = len(namelist)

    while low <= high and mid < len(namelist):
        if name == namelist[mid]:
            deutbo.append(name)
            break

        elif name > namelist[mid]:
            low = mid + 1
            mid = (low + high) // 2
            
        else:
            high = mid - 1
            mid = (low + high) // 2


print(len(deutbo))
deutbo.sort()
for name in deutbo:
    print(name)
