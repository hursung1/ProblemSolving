import sys

def mergesort(split_list: list):
	if len(split_list) == 1:
		return split_list
	
	sorted_list = []
	pivot = len(split_list) // 2

	sp_list_1 = mergesort(split_list[:pivot])
	sp_list_2 = mergesort(split_list[pivot:])

	i = j = 0
	do_loop_flag = True

	while do_loop_flag:
		if sp_list_1[i] <= sp_list_2[j]:
			sorted_list.append(sp_list_1[i])
			i += 1
		else:
			sorted_list.append(sp_list_2[j])
			j += 1

		if i == len(sp_list_1) and j < len(sp_list_2):
			sorted_list.extend(sp_list_2[j:])
			do_loop_flag = False
			
		if i < len(sp_list_1) and j == len(sp_list_2):
			sorted_list.extend(sp_list_1[i:])
			do_loop_flag = False

		if i == len(sp_list_1) and j == len(sp_list_2):
			do_loop_flag = False

	return sorted_list


def binary_search(target_list, num):
	while target_list:
		pivot = len(target_list) // 2
		if target_list[pivot] > num:
			target_list = target_list[:pivot]
		elif target_list[pivot] < num:
			target_list = target_list[pivot+1:]
		else:
			return True
		
	return False

set_n = int(sys.stdin.readline().strip())
set_list = [int(a) for a in sys.stdin.readline().strip().split()]

set_list = mergesort(set_list)

target_n = int(sys.stdin.readline().strip())
target_list = [int(a) for a in sys.stdin.readline().strip().split()]

for i in range(target_n):
    print(int(binary_search(set_list, target_list[i])))
