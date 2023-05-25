n = int(input())

goods = {}

for _ in range(n):
    items = input().split()
    name = " ".join(items[:-3])
    calories, fat, sign = items[-3:]
    if int(calories) <= 100 and int(fat) <= 50 and sign.upper() == "YES":
        goods.update({name: goods.get(name, 0) + 1})

print(dict(sorted(goods.items(), key = lambda x: x[1], reverse = True)))