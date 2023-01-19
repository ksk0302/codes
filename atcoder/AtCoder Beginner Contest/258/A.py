K = int(input())

HH = "21"
if(K / 60 >= 1):
    HH = "22"

K %= 60
MM = str(K)
MM = MM.zfill(2)

ans = HH + ':' + MM

print(ans)