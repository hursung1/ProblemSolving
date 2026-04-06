import sys
# max heap을 두어 최대값 찾아야 함

class heap:
    def __init__(self, heap: list) -> None:
        self.heap = heap
        self.build_heap(0)

    def build_heap(self, node):
        if node < len(self.heap):
            self.build_heap(node*2+1) # left child
            self.build_heap(node*2+2) # right child
        
        else:
            return

        current = node

        while current < len(self.heap):
            left_child = current*2+1
            right_child = current*2+2

            if right_child < len(self.heap):
                target = left_child if self.heap[left_child] >= self.heap[right_child] else right_child
            
            else:
                target = left_child

            if target < len(self.heap) and self.heap[target] > self.heap[current]:
                temp = self.heap[target]
                self.heap[target] = self.heap[current]
                self.heap[current] = temp

            current = target

        return

    def remove(self):
        if len(self.heap) == 1:
            return self.heap.pop()
        
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        current = 0

        while current < len(self.heap):
            left_child = current*2+1
            right_child = current*2+2

            if right_child < len(self.heap):
                target = left_child if self.heap[left_child] >= self.heap[right_child] else right_child
            
            else:
                target = left_child

            if target < len(self.heap) and self.heap[target] > self.heap[current]:
                temp = self.heap[target]
                self.heap[target] = self.heap[current]
                self.heap[current] = temp

            current = target

        return root
        

raw_input = sys.stdin.read().split("\n")
t = int(raw_input[0])

for t_i in range(1, 2*t+1, 2):
    n_and_idx = raw_input[t_i].split()
    n = int(n_and_idx[0])
    index = int(n_and_idx[1])

    priority_list = [int(s) for s in raw_input[t_i+1].split()]
    queue = [(i, p) for i, p in enumerate(priority_list)] # queue에는 (index, priority) 튜플로 저장
    priority_list_heap = heap(priority_list)

    # print queue 동작 과정
    # 1. Queue 0번 원소가 최대 우선순위를 가지는지 확인
    # 2. 해당 -> priority queue에서 제거, 해당 원소도 queue에서 제거
    # 3. 해당 x -> 해당 원소 제일 뒤로 미룸

    order = 0
    while True:
        first_elem = queue.pop(0)

        if first_elem[1] == priority_list_heap.heap[0]:
            root_elem = priority_list_heap.remove()
            order += 1
            if first_elem[0] == index:
                print(order)
                break
        else:
            queue.append(first_elem)
