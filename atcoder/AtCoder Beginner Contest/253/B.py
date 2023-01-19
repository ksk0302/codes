H, W = map(int, input().split())
S = [input() for i in range(H)]

x1 = 0
y1 = 0
x2 = 0
y2 = 0
cnt = 0
for i in range(H):
    for j in range(W):
        if S[i][j] == 'o' and cnt == 0:
            x1 = i+1
            y1 = j+1
            cnt += 1
        if S[i][j] == 'o' and cnt == 1:
            x2 = i+1
            y2 = j+1

print(abs(x2-x1) + abs(y2-y1))