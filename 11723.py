import sys
input = sys.stdin.readline
print = sys.stdout.write

m = int(input())

_set = 0

for _ in range(m):
    raw_command = input()
    command = raw_command.split()[0]

    if command == "add":
        element = 2 ** (int(raw_command.split()[1]) - 1)
        _set = _set | element

    elif command == "remove":
        element = 2 ** (int(raw_command.split()[1]) - 1)
        _set = _set & ~element

    elif command == "check":
        element = 2 ** (int(raw_command.split()[1]) - 1)
        check_flag = _set & element
        print(str(int(bool(check_flag)))+"\n")

    elif command == "toggle":
        element = 2 ** (int(raw_command.split()[1]) - 1)
        _set = _set ^ element

    elif command == "all":
        _set = (2 ** 20) - 1

    elif command == "empty":
        _set = 0

    else:
        ...