a, b, c = int(input()), int(input()), int(input())

x = 0

if (b < a < c) or (b > a > c): 
    x += abs(b - c) * 2

print(x)