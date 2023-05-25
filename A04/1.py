from math import *
x = int(input())
print(
    gcd(
        ceil(pow(x, 5 / 3) + tan(radians(x))),
        floor(pow(pi, 2 + atan(pow(sin(radians(x)), 2))))
    )
)