case_num = int(input())
for _ in range(case_num):
    row = input()
    floor, room_num, customer = [int(each) for each in row.split()]
    
    assigned_floor = ((customer-1) % floor) + 1
    assigned_room = ((customer-1) // floor) + 1

    assigned_floor = str(assigned_floor)
    if assigned_room < 10:
        assigned_room = f"0{assigned_room}"
    else:
        assigned_room = f"{assigned_room}"

    print(assigned_floor + assigned_room)
