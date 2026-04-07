import sys

raw_input = sys.stdin.read().strip().split("\n")
n, m = raw_input[0].split()
n = int(n)
m = int(m)
num_list = [int(s) for s in raw_input[1].split()]

sum_memo = [[0 for __ in range(n)] for _ in range(n)]

for i in range(m):
    i, j = raw_input[i+2].split()
    i = int(i) - 1
    j = int(j) - 1
    print(i, j)

    if not sum_memo[i][j]:
        t = i
        while t <= j and sum_memo[i][t]:
            t += 1

        while t <= j:
            s = 0
            while s <= t:
                if not sum_memo[i][j]:
                    if t == 0:
                        sum_memo[s][t] = num_list[t]
                    else:
                        sum_memo[s][t] = sum_memo[s][t-1] + num_list[t]
                s += 1
            
            t += 1

    print(sum_memo)