import sys 

# 1. 길이 중간값으로 계산.
# 2. 만약 


def binary_search(target_list, num):
    left = 0
    right = len(target_list)

    while left < right:
        pivot = (left + right) // 2
        if target_list[pivot] < num:
            left = pivot + 1
        elif target_list[pivot] > num:
            right = pivot 
        else:
            return target_list[pivot-1]
        
    return target_list[pivot]


def search_height(target_list, num):
    height = (target_list[0] + target_list[-1]) // 2
    height_idx = binary_search(target_list, height)
    while aaa:
        remainder_sum = sum([elem for elem in target_list if elem > height])

        if remainder_sum < num:
            height = target_list[height_idx-1]

        elif remainder_sum > num:
            height = target_list[height_idx+1]

        else:
            return height
    
    
raw_input = sys.stdin.read().split("\n")
n, m = raw_input[0].split()
tree_heights = raw_input[1].split()

tree_heights.sort()
pivot = search_height(tree_heights, m)