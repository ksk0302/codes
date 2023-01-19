N = int(input())
N += 1

A = [[1]*i for i in range(N)]

for i in range(1, N):
    for j in range(1, i):
        if(j+1 == i):
            A[i][j] = 1
        else:
            A[i][j] = A[i-1][j-1] + A[i-1][j]

for i in range(N):
    print(*A[i])