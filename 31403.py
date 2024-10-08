nums = []
for _ in range(3):
    nums.append(int(input()))

a, b, c = nums
print(a+b-c)
a_b = int(str(a) + str(b))
print(a_b - c)
