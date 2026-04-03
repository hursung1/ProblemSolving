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


buffer_input = sys.stdin.read().split()
n = int(buffer_input[0].strip())
score_list = [int(s.strip()) for s in buffer_input[1:]]

# 절삭 범위 계산
except_range = round(n * 0.15)

# 점수 통계
score_list = mergesort(score_list)

# 평균 점수 계산
target_scores = score_list[except_range: -except_range]
if not target_scores:
    print(0)
else:
    avg = sum(target_scores) / len(target_scores)
    print(round(avg))