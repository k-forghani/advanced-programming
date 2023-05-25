from math import sqrt, fabs

vx, vy, y0, h = [float(x) for x in input().split()]

a = -5
b = vy
c = y0 - h
delta = b ** 2 - 4 * a * c

if delta == 0:
    t = -b / (2 * a)
    r = fabs(vx * t)
    if t >= 0:
        print(f"{r:.2f}")
elif delta > 0:
    t1 = (-b + sqrt(delta)) / (2 * a)
    t2 = (-b - sqrt(delta)) / (2 * a)
    r1, r2 = fabs(vx * t1), fabs(vx * t2)
    if t1 >= 0 and t2 >= 0:
        if r2 > r1:
            print(f"{r1:.2f}\n{r2:.2f}")
        else:
            print(f"{r2:.2f}\n{r1:.2f}")
    elif t1 >= 0:
        print(f"{r1:.2f}")
    elif t2 >= 0:
        print(f"{r2:.2f}")
    else:
        print("impossible")
else:
    print("impossible")