if __name__ == '__main__':
    m, a, b = int(input()), int(input()), int(input())
    c = m - a - b
    x = max(a, b)
    x = max(x, c)
    print(x)
