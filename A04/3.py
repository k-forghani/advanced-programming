s = input()
print(
    all(
        len(x) == len(y)
        for x, y in zip(
            [x for x in s.split("0") if x],
            [x for x in s.split("1") if x]
        )
    ) and "0" in s and "1" in s
)