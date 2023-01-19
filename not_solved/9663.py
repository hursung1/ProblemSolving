# 굳이 둘째 줄 이상을 더 탐색할 필요는 없음
def n_queen(N, r, Q_pos):
    global cnt
    for i in range(N):
        is_possible = True
        for r_q, c_q in Q_pos:
            if (r_q - c_q) == r - i or (r_q + c_q) == r + i or r == r_q or i == c_q:
                is_possible = False
                break
                
        if is_possible:
            Q_pos += [(r, i)]
            if r == N-1:
                cnt += 1
            else:
                n_queen(N, r+1, Q_pos)

            del Q_pos[-1]


N = int(input())
cnt = 0
n_queen(N, 0, [])
print(cnt)