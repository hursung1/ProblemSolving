import sys
###

raw_input = sys.stdin.read().strip().split("\n")
n, max_weight = raw_input[0].split()
n = int(n)
max_weight = int(max_weight)
knapsack = [[0 for __ in range(max_weight+1)] for _ in range(n+1)]

for i in range(1, n+1):
    elem = raw_input[i].split()
    elem_weight = int(elem[0])
    elem_value = int(elem[1])

    for weight in range(max_weight+1):
        # 1. 이 물건을 못 담는 경우 - 이전의 최적 값을 그대로 기록
        if weight < elem_weight:
            optimal_value = knapsack[i-1][weight]

        # 2. 이 물건을 담을 수 있는 경우 - 담는 경우와 안 담는 경우를 비교하여 값이 더 큰 경우를 기록
        else:
            optimal_value = knapsack[i-1][weight-elem_weight] + elem_value
            if optimal_value < knapsack[i-1][weight]:
                optimal_value = knapsack[i-1][weight]

        knapsack[i][weight] = optimal_value

print(knapsack[n][max_weight])