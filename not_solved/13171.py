a = int(input())
x = int(input())

mod_sum = 1
i = 0
while x > 0:
    rem = x % 2
    if rem:
        if i < 30:
            mod_sum *= a ** (2 ** i)

        else:
            mod_sum *= (a**(2**i) % 1000000007)

    mod_sum = mod_sum % 1000000007
    i += 1
    x = x // 2

print(mod_sum)