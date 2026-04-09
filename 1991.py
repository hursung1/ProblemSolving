import sys

def get_orders(tree: dict, current: str, preorder_list: list, inorder_list: list, postorder_list: list):
    """
    (1) 현 node를 먼저 출력 후 (2) 왼쪽 자식을 보고 (3) 오른쪽 자식을 본다. 
    """
    left_child = tree[current][0]
    right_child = tree[current][1]
    preorder_list.append(current)

    if left_child != ".":
        preorder_list, inorder_list, postorder_list = get_orders(tree, left_child, preorder_list, inorder_list, postorder_list)
        
    inorder_list.append(current)

    if right_child != ".":
        preorder_list, inorder_list, postorder_list = get_orders(tree, right_child, preorder_list, inorder_list, postorder_list)
    
    postorder_list.append(current)
    return preorder_list, inorder_list, postorder_list


tree = {}
raw_input = sys.stdin.read().strip().split("\n")
num_edges = int(raw_input[0])

for i in range(num_edges):
    edge = raw_input[i+1].split()
    node = edge[0]; left_child = edge[1]; right_child = edge[2]

    tree[node] = [left_child, right_child]

preorder_list, inorder_list, postorder_list = get_orders(tree, "A", [], [], [])
print("".join(preorder_list))
print("".join(inorder_list))
print("".join(postorder_list))