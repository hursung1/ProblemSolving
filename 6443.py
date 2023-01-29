def backtrack(stack, lst):
    if not lst:
        string = "".join(stack)
        print(string)
        return
    
    for i in range(len(lst)):
        if i > 0 and lst[i] == lst[i-1]:
            continue
        stack.append(lst[i])
        backtrack(stack, lst[:i]+lst[i+1:])
        stack.pop(-1)

n = int(input())
for _ in range(n):
    in_str = input()
    st_str = sorted(in_str)
    stack = []
    backtrack([], st_str)