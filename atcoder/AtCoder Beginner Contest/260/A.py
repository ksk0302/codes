S = input()
alphabets = [0]*26

for s in S:
    alphabets[ord(s)-ord('a')] += 1

for i in range(26):
    if alphabets[i] == 1:
        print(chr(i+97))
        exit()

print(-1)