n = int(input())

table_t = []
table_p = []

for i in range(n):
    row = input().split()
    t, p = int(row[0]), int(row[1])

    if (i + t) > n: # 현재 시점에서 t를 수행하면 퇴사일을 넘길 경우: 이전 날짜 중 가장 최대값을 선택
        table_t.append(0)
        if i == 0:
            table_p.append(0)
        else:
            table_p.append(max(table_p))
        # table.append((0, )) # i == 0 일 때 handling 필요

    else: # 그 외의 경우: 현재 작업을 받을 수 있는 날에 한해, p를 최대화하는 경우를 찾아 기록
        # available_ps = []
        max_tj = 0
        max_pj = 0
        for j in range(i):
            t_j = table_t[j]
            p_j = table_p[j]
            if j + t_j <= i: # 현재 시점에 작업 받기 가능
                # available_ps.append(p_j)
                if max_pj < p_j:
                    max_tj = t_j
                    max_pj = p_j

        table_t.append(t)
        table_p.append(max_pj + p)
    
    print(table_t)
    print(table_p)

print(max(table_p))