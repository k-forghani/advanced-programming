n = int(input())
s = input().upper()
k = int(input())

ops = {i: c for i, c in enumerate("ABCD")}

for i in range(k):
    sc = 0
    for j in range(n):
        a = input()
        if a.count("#") == 1:
            if ops[a.find("#")] == s[j]:
                sc += 3
            else:
                sc -= 1
        elif a.count("#") > 1:
            sc -= 1
    print(sc)