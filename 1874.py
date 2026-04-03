# 수열을 역순으로 거슬러 올라간다.
# trace_stack에 역순으로 push 하는데, trace_stack에는 항상 수가 오름차순으로 정렬되어 있어야 한다.
# 수열에서 현재 보고 있는 숫자가 만약 top 보다 작다면, trace_stack에서 이것보다 작은 수가 top이 될 때 까지 pop 한다.
# trace_stack에서 pop된 숫자들은 임시 stack에 들어간다. 이 stack이 가장 큰 숫자부터 내림차순으로 빠짐없이 존재한다면 그대로 삭제한다
# 만약 중간에 빠진 숫자가 있다면 -> 원래 숫자를 오름차순으로 넣지 않았다는 의미이므로 stack 수열로 나올 수 없음. 즉시 중단 후 NO 출력
# operation은 순서대로 list에 기록되고, 만약 수열의 모든 숫자가 trace_stack과 temp_stack을 거쳐 정상적으로 소멸했다면, 1부터 N까지 오름차순으로 trace_stack에 이치에 맞게 push와 pop을 거쳐 수열을 구성했다는 방증이므로 operation을 출력해주면 된다.

import sys

raw_input = sys.stdin.read().split()
series_len = num_nums = int(raw_input[0])
series = [int(s) for s in raw_input[1:]]

trace_stack = []
temp_stack = []
operation_history = []

for i in range(series_len-1, -1, -1):
    elem = series[i]
    if not trace_stack or elem > trace_stack[-1]:
        trace_stack.append(elem)
        operation_history.append("-")
    
    else:
        while trace_stack and trace_stack[-1] > elem:
            top_elem = trace_stack.pop()
            temp_stack.append(top_elem)
            operation_history.append("+")
            
        while temp_stack and temp_stack[0] == num_nums:
            num_nums -= 1
            _ = temp_stack.pop(0)

        if temp_stack:
            operation_history = []
            break
        else:
            trace_stack.append(elem)
            operation_history.append("-")

while trace_stack:
    top_elem = trace_stack.pop()
    if top_elem != num_nums:
        operation_history = []
        break
    else:
        operation_history.append("+")
        num_nums -= 1

if operation_history:
    for op in reversed(operation_history):
        print(op)
else:
    print("NO")