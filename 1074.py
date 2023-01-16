def find_z(N, r, c):
    N -= 1
    r_quota = r // (2 ** N)
    c_quota = c // (2 ** N)
    r_remain = r % (2 ** N)
    c_remain = c % (2 ** N)

    stpt = (2 ** N) ** 2 * (r_quota * 2  + c_quota)
    if stpt == 1:
        stpt = 0
    
    if N > 0:
        out = find_z(N, r_remain, c_remain)

    else:
        return r * 2 + c

    return out + stpt

N, r, c = input().split()
N = int(N)
r = int(r)
c = int(c)

print(find_z(N, r, c))