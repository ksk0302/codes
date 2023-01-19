N, X = map(int, input().split())

str = []
for i in range(65, 91):
    tmp = [chr(i)]*N
    str = str + tmp

print(str[X-1])