from math import ceil, sqrt

a, b = [int(x) for x in input().split()]

def is_prime (n):
    if n < 2:
        return False
    if n == 2:
        return True
    for i in range(2, ceil(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

for x in range(a, b + 1):
    if is_prime(x):
        x = str(x)
        if all(is_prime(int(x[i:i + 2])) for i in range(len(x) - 1)):
            print(x)