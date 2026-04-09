def modular(base: int, power: int, divisor: int):
    """
    1. base와 power, divisor를 받는다.
    2. base^(power//2)가 int 최대값을 넘지 않을 때 까지 재귀적으로 함수 호출
    3. 넘지 않은 시점에 base^(power//2) % divisor 계산 후 return
    4. ab mod c = {(a mod c) * (b mod c)} mod c 이므로, 각 재귀함수로부터 remain값들을 곱해 modular 연산 수행
    5. modular 연산 결과를 return
    """
    if power < 2:
        return (base ** power) % divisor
    
    p1 = power//2
    p2 = power - p1

    r1 = modular(base, p1, divisor)
    if p1 != p2:
        r2 = modular(base, p2, divisor)
    else:
        r2 = r1

    return (r1 * r2) % divisor

a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)

print(modular(a, b, c))