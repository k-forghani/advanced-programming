n = int(input())

d = dict(
    (
        input(),
        {
            "name": " ".join(x.capitalize() for x in input().split()),
            "age": int(input()),
            "major": input()
        }
    )
    for _ in range(n)
)

print(dict(sorted(d.items(), key = lambda x: x[1]["major"][1])))