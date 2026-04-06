import sys

def check_parenthesis(test_string: str) -> bool:
    stack = []

    for c in test_string:
        if c == "(" or c == "[":
            stack.append(c)
        
        elif c == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else: 
                return False

        elif c == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else: 
                return False

    return False if stack else True    


while True:
    raw_line = sys.stdin.readline().strip("\n")
    if raw_line == ".":
        break

    if check_parenthesis(raw_line):
        print("yes")
    else:
        print("no")