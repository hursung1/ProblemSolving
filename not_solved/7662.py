"""
red-black tree 구현하면 됨
"""
def get_parent(i):
    return (i-1)//2

def get_left_child(i):
    return (i*2)+1

def get_right_child(i):
    return (i*2)+2

def is_root(i):
    return True if i == 0 else False

def enqueue(q, elem):
    i = 0
    while i < len(q):


if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        dpq = []
        num_op = int(input())
        for __ in range(num_op):
            command, num = input().split()
            num = int(num)

            if command == "I":
                pass

            elif command == "D":
                if num == 1:
                    pass
                elif num == -1:
                    pass