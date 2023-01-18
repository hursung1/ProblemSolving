from copy import deepcopy

done_position = []

def set_false(chess_map, i, j):
    _map = deepcopy(chess_map)
    for idx in range(len(chess_map)):
        _map[i][idx] = False
        _map[idx][j] = False

        if i-idx >= 0:
            if j-idx >= 0:
                _map[i-idx][j-idx] = False
            if j+idx < len(chess_map):
                _map[i-idx][j+idx] = False
        if i+idx < len(chess_map): 
            if j-idx >= 0:
                _map[i+idx][j-idx] = False
            if j+idx < len(chess_map):
                _map[i+idx][j+idx] = False

    return _map

    
def n_queen(N, n, chess_map, cnt, position):
    for i in range(N):
        for j in range(N):
            if chess_map[i][j]:
                position.append((i, j))
                if n == 1:
                    cnt += 1
                    print(done_position)
                    print(position)
                    if not position in done_position:
                        done_position.append(position)
                    # print("!!")
                else:
                    # set false for impossible region
                    new_map = set_false(chess_map, i, j)
                    # print(new_map)
                    cnt = n_queen(N, n-1, new_map, cnt, position)
                
                del position[-1]


    return cnt

N = int(input())
chess_map = [[True for __ in range(N)] for _ in range(N)]
possible_cnt = 0
print(n_queen(N, N, chess_map, possible_cnt, []))