import sys

class PriorityQueue:
    def __init__(self) -> None:
        self.heap = []

    def insert(self, elem):
        self.heap.append(elem)
        current = len(self.heap)-1

        while current > 0: 
            # 바꾸는 조건
            # 1. 절댓값이 작으면
            # 2. 절댓값이 같은데, 실제 값이 작을 때 
            parent = (current-1) // 2
            if abs(self.heap[current]) < abs(self.heap[parent]) or\
                (abs(self.heap[current]) == abs(self.heap[parent]) and self.heap[current] < self.heap[parent]):
                temp = self.heap[current]
                self.heap[current] = self.heap[parent]
                self.heap[parent] = temp
                
                current = parent
            
            else:
                current = 0


    def remove(self, ):
        current = 0

        if not self.heap:
            return current
        if len(self.heap) == 1:
            return self.heap.pop()
        
        root = self.heap[0]
        self.heap[0] = self.heap.pop()

        while current < len(self.heap):
            left_child = 2 * current + 1
            right_child = 2 * current + 2
            
            if left_child >= len(self.heap):
                current = len(self.heap)
                continue

            else:
                if right_child >= len(self.heap):
                    target = left_child
                else:
                    if abs(self.heap[left_child]) < abs(self.heap[right_child]):
                        target = left_child
                    elif abs(self.heap[left_child]) > abs(self.heap[right_child]):
                        target = right_child
                    elif abs(self.heap[left_child]) == abs(self.heap[right_child]):
                        target = left_child if self.heap[left_child] < self.heap[right_child] else right_child

            # 바꾸는 조건
            # 1. 절댓값이 작으면
            # 2. 절댓값이 같고 실제값이 작으면
            if abs(self.heap[current]) > abs(self.heap[target]) or\
                (abs(self.heap[current]) == abs(self.heap[target]) and self.heap[current] > self.heap[target]):
                temp = self.heap[current]
                self.heap[current] = self.heap[target]
                self.heap[target] = temp
                
                current = target

            else:
                current = len(self.heap)

        return root


heap = PriorityQueue()

raw_input = sys.stdin.read().split()
num_ops = int(raw_input[0].strip())

for i in range(num_ops):
    op = int(raw_input[i+1].strip())

    if op == 0: # queue pop
        root = heap.remove()
        print(root)

    else: # queue push
        heap.insert(op)