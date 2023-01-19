str1 = input()
str2 = input()

i = j = 0
memo = [[0 for _ in range(len(str2)+1)] for __ in range(len(str1)+1)]

lcs = 0
for i_str1 in range(1, len(str1)+1):
    for i_str2 in range(1, len(str2)+1):
        if str1[i_str1-1] == str2[i_str2-1]:
            memo[i_str1][i_str2] = memo[i_str1-1][i_str2-1] + 1
        else:
            memo[i_str1][i_str2] = max(memo[i_str1-1][i_str2], memo[i_str1][i_str2-1])

print(memo[len(str1)][len(str2)])