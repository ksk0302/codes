N, K, Q = map(int, input().split())
A = list(map(int, input().split()))
L = list(map(int, input().split()))

for i in range(Q):
    if A[L[i]-1] == N:
        continue
    elif L[i] == K or A[L[i]-1]+1 < A[L[i]]:
        A[L[i]-1] += 1

print(*A)