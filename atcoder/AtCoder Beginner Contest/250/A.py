H, W = map(int, input().split())
R, C = map(int, input().split())

ansh = 2
answ = 2

if H == 1:
    ansh -= 2
elif R == 1 or R == H:
    ansh -= 1

if W == 1:
    answ -= 2
elif C == 1 or C == W:
    answ -= 1

print(ansh+answ)