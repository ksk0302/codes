from itertools import combinations

n, m = map(int, input().split())
for i in combinations(range(1, m+1), n):
    print(*i, sep=' ')