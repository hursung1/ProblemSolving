import sys
input = sys.stdin.readline
# print = sys.stdout.write

blue_cnt = 0
white_cnt = 0

def check_all_blue(pane):
    global blue_cnt, white_cnt
    if all([all(row) for row in pane]): # pane is nothing but 1's
        blue_cnt += 1
    elif not any([any(row) for row in pane]): # pane is nothing but 0's
        white_cnt += 1

    else:
        cut_line = len(pane) >> 1
        pane_upper_left = [pane[i][:cut_line] for i in range(cut_line)]
        pane_upper_right = [pane[i][cut_line:] for i in range(cut_line)]
        pane_lower_left = [pane[i][:cut_line] for i in range(cut_line, len(pane))]
        pane_lower_right = [pane[i][cut_line:] for i in range(cut_line, len(pane))]

        check_all_blue(pane_upper_left) # upper left
        check_all_blue(pane_upper_right) # upper right
        check_all_blue(pane_lower_left) # lower left
        check_all_blue(pane_lower_right) # lower right



n = int(input().strip())
pane = []
for _ in range(n): # get input
    row = input().strip()
    pane.append([int(elem) for elem in row.split()])

check_all_blue(pane)
print(white_cnt)
print(blue_cnt)