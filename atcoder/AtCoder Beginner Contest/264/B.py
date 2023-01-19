R, C = map(int, input().split())
R -= 1
C -= 1
flag = True

if (R%2 == 0 and C >= min(R, 14-R) and C <= max(R, 14-R)):
    flag = True
elif (R%2 == 1 and C >= min(R, 14-R) and C <= max(R, 14-R)):
    flag = False
else:
    if C%2 == 0:
        flag = True
    else:
        flag = False

if flag:
    print("black")
else:
    print("white")