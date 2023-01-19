N = int(input())
A = list(map(int, input().split()))

P = 0
masu = [False]*4

for i in range(N):
    masu[0] = True
    for j in reversed(range(4)):
        if masu[j]:
            if j+A[i] < 4:
                masu[j] = False
                masu[j+A[i]] = True
            else:
                masu[j] = False
                P += 1

print(P)