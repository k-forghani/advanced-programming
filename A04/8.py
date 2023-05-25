n, m = [int(x) for x in input().split()]

l, u = -1, -1

if 1 <= m <= 9 * n:
    l = ["1"] + ["0"] * (n - 1)
    s = m - 1

    for i in range(n - 1, -1, -1):
        if s >= 9:
            l[i] = "9"
            s -= 9
        else:
            l[i] = str(s + int(l[i]))
            break
    
    l = "".join(l)
    
    u = ["0"] * n
    s = m

    for i in range(n):
        if s >= 9:
            u[i] = "9"
            s -= 9
        else:
            u[i] = str(s)
            break
    
    u = "".join(u)

print(u, l)