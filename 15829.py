l = int(input())
hashee = input()

r = 31
m = 1234567891
a_ascii = 96

remainder = 0
for i in range(l):
	ch_num = ord(hashee[i]) - a_ascii
	remainder += (ch_num * (r ** i)) % m

print(remainder % m)
