import sys

def mergesort(target_list: list) -> list:
    if len(target_list) <= 1:
        return target_list

    pivot = len(target_list) // 2

    left_list = target_list[:pivot]
    right_list = target_list[pivot:]

    sorted_list = []
    left_list = mergesort(left_list)
    right_list = mergesort(right_list)

    left_idx = right_idx = 0
    while left_idx < len(left_list) and right_idx < len(right_list):
        if left_list[left_idx] <= right_list[right_idx]:
            sorted_list.append(left_list[left_idx])
            left_idx += 1
        else:
            sorted_list.append(right_list[right_idx])
            right_idx += 1

        if left_idx == len(left_list):
            sorted_list.extend(right_list[right_idx:])
            right_idx = len(right_list)

        if right_idx == len(right_list):
            sorted_list.extend(left_list[left_idx:])
            left_idx = len(left_list)
    
    return sorted_list

raw_input = sys.stdin.read().split()
num_nums = int(raw_input[0])
num_list = mergesort([int(s) for s in raw_input[1:]])

start_idx = 0
end_idx = 0
cnt_most = 0 # end_idx - start_idx
idx_most = [0]

for i in range(num_nums):
    if (i == num_nums - 1) or (num_list[i] != num_list[i+1]):
        start_idx = end_idx
        end_idx = i+1
        cnt = end_idx - start_idx

        if cnt > cnt_most:
            idx_most = [start_idx]
            cnt_most = cnt

        elif cnt == cnt_most:
            idx_most.append(start_idx)


print(round(sum(num_list) / num_nums)) # 평균
print(num_list[num_nums // 2]) # 중앙값
idx_most = num_list[idx_most[1]] if len(idx_most) > 1 else num_list[idx_most[0]]
print(idx_most) # 최빈값
print(num_list[-1] - num_list[0]) # 범위