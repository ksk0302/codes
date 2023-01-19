N, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

Amax = max(A)
flag = False

for i in range(K):
    if A[B[i]-1] == Amax:
        flag = True

if flag:
    print("Yes")
else:
    print("No")