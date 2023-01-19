N, M = map(int, input().split())
graph = [[0]*N for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

cnt = 0
for a in range(0, N):
    for b in range(a+1, N):
        for c in range(b+1, N):
            if graph[a][b] and graph[b][c] and graph[c][a]:
                cnt += 1

print(cnt)