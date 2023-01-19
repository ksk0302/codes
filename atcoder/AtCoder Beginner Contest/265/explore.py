N, M, T = map(int, input().split())
A = list(map(int, input().split()))
X = [0] * (N+1)
for i in range(M):
    x, y = map(int, input().split())
    X[x-1] = y

possible_or_not = True

for i in range(N-1):
    if T - A[i] > 0:
        T -= A[i]
        T += X[i+1]
    else:
        possible_or_not = False
        break

if possible_or_not:
    print("Yes")
else:
    print("No")