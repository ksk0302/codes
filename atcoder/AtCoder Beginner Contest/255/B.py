import math

N, K = map(int, input().split())
A = list(map(int, input().split()))
X = [0]*N
Y = [0]*N
for i in range(N):
    x, y = map(int, input().split())
    X[i] = x
    Y[i] = y

ans = 0
for i in range(N):
    if i+1 not in A:
        length = 1e15
        for j in A:
            tmp = math.sqrt((X[i]-X[j-1])*(X[i]-X[j-1]) + (Y[i]-Y[j-1])*(Y[i]-Y[j-1]))
            length = min(tmp, length)
        ans = max(ans,  length)

print(ans)