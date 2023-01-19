N, X, Y, Z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
passed = [False]*N

Awithindex = [(-A[i], i) for i in range(N)]
Bwithindex = [(-B[i], i) for i in range(N)]
ABwithindex = [(-A[i]-B[i], i) for i in range(N)]

Awithindex.sort()
Bwithindex.sort()
ABwithindex.sort()

ans = []

cnt1 = 0
for i in range(N):
    if cnt1 == X:
        break
    if not passed[Awithindex[i][1]]:
        passed[Awithindex[i][1]] = True
        ans.append(Awithindex[i][1]+1)
        cnt1 += 1

cnt1 = 0
for i in range(N):
    if cnt1 == Y:
        break
    if not passed[Bwithindex[i][1]]:
        passed[Bwithindex[i][1]] = True
        ans.append(Bwithindex[i][1]+1)
        cnt1 += 1

cnt1 = 0
for i in range(N):
    if cnt1 == Z:
        break
    if not passed[ABwithindex[i][1]]:
        passed[ABwithindex[i][1]] = True
        ans.append(ABwithindex[i][1]+1)
        cnt1 += 1

ans.sort()
print(*ans)