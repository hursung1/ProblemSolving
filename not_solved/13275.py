s = input()
# max_pal = ""
max_len = 0
for i in range(len(s)):
    j = 1
    while i - j >= 0 and i + j < len(s) and s[i-j] == s[i+j]:
        j += 1

    if max_len < len(s[i-j+1: i+j]):
        max_len = len(s[i-j+1: i+j])


    j = 1
    while i - j + 1 >= 0 and i + j < len(s) and s[i-j+1] == s[i+j]:
        j += 1

    if max_len < len(s[i-j+2: i+j]):
        max_len = len(s[i-j+2: i+j])

print(max_len)