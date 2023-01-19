N = int(input())
A = [input() for i in range(N)]

correct_or_not = True

for i in range(N):
    for j in range(i+1, N):
        if (A[i][j] == 'W' and A[j][i] != 'L') or (A[i][j] == 'L' and A[j][i] != 'W') or (A[i][j] == 'D' and A[j][i] != 'D'):
            correct_or_not = False

if(correct_or_not):
    print("correct")
else:
    print("incorrect")