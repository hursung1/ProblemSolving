def mergesort(lst):
    lst_len = len(lst)
    split_idx = lst_len // 2
    former = lst[:split_idx]
    latter = lst[split_idx:]
    if len(former) > 1:
        former = mergesort(former)
    if len(latter) > 1:
        latter = mergesort(latter)

    idx_f, idx_l = 0, 0
    for i in range(lst_len):
        if idx_f < len(former) and idx_l < len(latter):
            if former[idx_f] < latter[idx_l]:
                lst[i] = former[idx_f]
                idx_f += 1
            elif former[idx_f] >= latter[idx_l]:
                lst[i] = latter[idx_l]
                idx_l += 1

        else:
            if idx_l >= len(latter):
                lst[i] = former[idx_f]
                idx_f += 1
            elif idx_f >= len(former):
                lst[i] = latter[idx_l]
                idx_l += 1

    return lst

N = int(input())
coords = {}
x_coords = []
y_coords = []
for _ in range(N):
    coord_raw = input()
    coord_raw = coord_raw.split()
    x_coord = int(coord_raw[0])
    y_coord = int(coord_raw[1])
    
    if not x_coord in coords.keys():
        coords[x_coord] = []
    coords[x_coord].append(y_coord)

x_coord_sorted = mergesort(list(coords.keys()))
for x_coord in x_coord_sorted:
    y_coords = coords[x_coord]
    y_coords_sorted = mergesort(y_coords)

    for y_coord in y_coords_sorted:
        print(f"{x_coord} {y_coord}")