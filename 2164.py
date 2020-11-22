n = int(input())
lst = [i for i in range(n)]
delete_flag = True # if true, delete front one. else, delete rear one.
len_lst = len(lst)

while len(lst) > 1:
    pre_lst = lst
    lst = []
           
    for i in range(len(pre_lst)):
        if delete_flag and i % 2 == 1: # delete front one
            lst.append(pre_lst[i])
            
        elif not delete_flag and i % 2 == 0: # delete rear one
            lst.append(pre_lst[i])
    
    if len(pre_lst) % 2 == 1: # odd
        delete_flag = not delete_flag # change
     
    
print(lst[0]+1)
