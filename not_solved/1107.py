def check_num_in(nwn, num):
    for elem in nwn:
        if str(elem) in str(num):
            return False

    return True

channel = int(input())
m = int(input())
not_working_num = []
if m:
    for num in input().split():
        not_working_num.append(int(num))

num = 0
channel_minus = channel
channel_plus = channel
while True:
    candidate = -1
    if check_num_in(not_working_num, channel_minus):
        interval = 100 - channel_plus
        if len(str(channel_minus)) > interval and interval > 0:
            candidate = num + interval
        else:
            candidiate = num + len(str(channel_minus))

    if check_num_in(not_working_num, channel_plus):
        interval = channel_minus - 100
        if len(str(channel_plus)) > interval and interval > 0:
            if candidate == -1 or num + interval < candidate:
                candidate = num + interval
        else:
            if candidate == -1 or num + len(str(channel_plus)) < candidate:
                candidate = num + len(str(channel_plus))

    if channel_minus == 100 or channel_plus == 100:
        candidate = num
        
    if candidate > -1:
        print(candidate)
        break

    channel_minus -= 1
    if channel_minus < 0:
        channel_minus = 0
    channel_plus += 1
    num += 1