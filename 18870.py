n = int(input())
nums = input().split()
for i in range(n):
    nums[i] = int(nums[i])

nums_sort = sorted(set(nums))
nums_dict = {}
for i, num in enumerate(nums_sort):
    nums_dict[num] = i
    

zipped = []
for num in nums:
    zipped.append(str(nums_dict[num]))

print(" ".join(zipped))
