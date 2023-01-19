N, M, X, T, D = map(int, input().split())

heights = [0]*(N+1)

heights[N] = T

for i in range(X, N):
    heights[i] = T

for i in reversed(range(0, X)):
    heights[i] = heights[i+1] - D

print(heights[M])