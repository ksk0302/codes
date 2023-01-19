import math

a, b, d = map(int, input().split())

d = d * math.pi / 180
ans_a = a * math.cos(d) - b * math.sin(d)
ans_b = a * math.sin(d) + b * math.cos(d)

print(ans_a, ans_b)