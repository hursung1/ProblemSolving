import sys

line = sys.stdin.readline()
m, n = line.strip().split()
m = int(m); n = int(n)

line = sys.stdin.readline()
up, left, right, down = [int(elem) for elem in line.strip().split()]

original_letters = []
new_lines_num = up + m + down
new_line_length = left + right + n

for line_num in range(new_lines_num):
    new_line = ("#." * ((new_line_length+1) // 2))[:new_line_length] if line_num % 2 == 0 else (".#" * ((new_line_length+1) // 2))[:new_line_length]

    if line_num >= up and line_num < up + m:
        orig_line = sys.stdin.readline().strip()
        if line_num % 2 == 0:
            new_line = ("#." * ((new_line_length+1) // 2))[:new_line_length]
            new_line = new_line[:left] + orig_line + new_line[new_line_length-right:]
            
        else:
            new_line = (".#" * ((new_line_length+1) // 2))[:new_line_length]
            new_line = new_line[:left] + orig_line + new_line[new_line_length-right:]

    sys.stdout.write(new_line + "\n")


# for line_num in range(up):
#     line = ("#." * ((new_line_length+1) // 2))[:new_line_length] if line_num % 2 == 0 else (".#" * ((new_line_length+1) // 2))[:new_line_length]
#     sys.stdout.write(line + "\n")

# for line_num in range(m):
#     orig_line = sys.stdin.readline().strip()
#     if line_num % 2 == 0:
#         new_line = ("#." * ((new_line_length+1) // 2))[:new_line_length]
#         new_line = new_line[:left] + orig_line + new_line[-right:]
        
#     else:
#         new_line = (".#" * ((new_line_length+1) // 2))[:new_line_length]
#         new_line = new_line[:left] + orig_line + new_line[-right:]

#     sys.stdout.write(new_line+"\n")
    
# for line_num in range(down):
#     line = ("#." * ((new_line_length+1) // 2))[:new_line_length] if line_num % 2 == 0 else (".#" * ((new_line_length+1) // 2))[:new_line_length]
#     sys.stdout.write(line + "\n")