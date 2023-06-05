n = int(input())
l = list(map(int, input().split()))
r = []

i = True

while l:
    r.append(max(l) if i else min(l))
    del l[l.index(r[-1])]
    i = not i

print(*r)