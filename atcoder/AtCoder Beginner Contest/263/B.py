N = int(input())
P = list(map(int, input().split()))
P.insert(0, 0)
P.insert(0, 0)

ans = 0
now = N
while P[now] != 1:
    now = P[now]
    ans += 1

print(ans+1)