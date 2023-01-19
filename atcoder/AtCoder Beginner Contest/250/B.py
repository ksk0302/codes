N, A, B = map(int, input().split())

for i in range(N*A):
    for j in range(N*B):
        if ((int)(i/A) % 2 == 0 and (int)(j/B) % 2 == 1) or ((int)(i/A) % 2 == 1 and (int)(j/B) % 2 == 0):
            print('#', end='')
        else:
            print('.', end='')
    print("")