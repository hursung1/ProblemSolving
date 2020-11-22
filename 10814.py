n = int(input())
name_dict = {}
for i in range(n):
    age_name = input().split()
    age, name = age_name
    age = int(age)
    if age not in name_dict.keys():
        name_dict[age] = []

    name_dict[age].append(name)
    
for age, names in sorted(name_dict.items()):
    for name in names:
        print("{} {}".format(age, name))
