n = int(input())

tot = 0
apps = set()

for iiiiii in range(n):
    hours = [0 for i in range(24)]
    mins = [0 for i in range(60)]
    secs = [0 for i in range(60)]

    inp = input().split(' ')

    h = inp[0].split(',')
    for s in h:
        if (s[0] == '*'):
            hours = [1 for i in range(24)]
        elif ('-' in s):
            t = s.split('-')
            l = int(t[0])
            r = int(t[1])
            for x in range(r-l+1):
                hours[x + l] = 1
        else:
            x = int(s)
            hours[x] = 1

    h = inp[1].split(',')
    for s in h:
        if (s[0] == '*'):
            mins = [1 for i in range(60)]
        elif ('-' in s):
            t = s.split('-')
            l = int(t[0])
            r = int(t[1])
            for x in range(r-l+1):
                mins[x + l] = 1
        else:
            x = int(s)
            mins[x] = 1

    h = inp[2].split(',')
    for s in h:
        if (s[0] == '*'):
            secs = [1 for i in range(60)]
        elif ('-' in s):
            t = s.split('-')
            l = int(t[0])
            r = int(t[1])
            for x in range(r-l+1):
                secs[x + l] = 1
        else:
            x = int(s)
            secs[x] = 1


    cnt_h = 0
    cnt_m = 0
    cnt_s = 0
    for x in hours:
        cnt_h += x
    for x in mins:
        cnt_m += x
    for x in secs:
        cnt_s += x

    
    for i in range(24):
        if (hours[i] == 1):
            for j in range(60):
                if (mins[j] == 1):
                    for k in range(60):
                        if (secs[k] == 1):
                            apps.add(60*60*i + 60*j + k)
    tot += cnt_h*cnt_m*cnt_s

print(len(apps), tot)