def backtrack(nums, retrieval, m):
    for i in range(len(nums)):
        retrieval.append(str(nums[i]))
        if len(retrieval) == m:
            print(" ".join(retrieval))
        else:
            backtrack(nums[i+1:], retrieval, m)

        del retrieval[-1]

n, m = input().split()
n = int(n)
m = int(m)

nums = list(range(1, n+1))
backtrack(nums, [], m)