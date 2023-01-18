def mult(a, b, c):
    if b == 1 or b == 0:
        return (a ** b) % c

    b_half = b // 2
    return (mult(a, b_half, c) * mult(a, b-b_half, c)) % c

a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)

q = b // 2
r = b % 2

(a ** 2) % c


while True:
    b_half = b // 2

    if b % 2 == 0: # Even
        pass
    else: # odd
        pass