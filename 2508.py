import sys
input = sys.stdin.readline
print = sys.stdout.write

t = int(input().strip())

for _ in range(t):
    input()
    r, c = input().strip().split()
    r = int(r); c = int(c)

    candies = 0
    box = [input().strip() for __ in range(r)]
    for r_idx in range(r):
        for c_idx in range(c):
            if box[r_idx][c_idx] == "o": 
                # check horizontal candy
                if (c_idx - 1 >= 0 and c_idx + 1 < c) and\
                (box[r_idx][c_idx-1] == ">" and box[r_idx][c_idx+1] == "<"):
                    candies += 1
                    continue

                # check vertical candy
                if (r_idx - 1 >= 0 and r_idx + 1 < r) and\
                (box[r_idx-1][c_idx] == "v" and box[r_idx+1][c_idx] == "^"):
                    candies += 1

    print(str(candies)+"\n")