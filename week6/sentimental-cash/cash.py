def main():
    while True:
        try:
            inp = input("Change owed: ").split(".")
            if len(inp) == 1:
                a, b = int(inp[0]), 0
            elif len(inp) == 2:
                if len(inp[1]) > 2:
                    inp[1] = inp[1][:2]
                elif len(inp[1]) == 1:
                    inp[1] = inp[1] + '0'
                a, b = list(map(lambda x: int(x), inp))
            if a >= 0:
                break
        except:
            pass
    c = a * 100 + b
    count = 0
    coins = [25, 10, 5]
    for i in range(3):
        if c == 0:
            break
        while c != 0 and c - coins[i] >= 0:
            c -= coins[i]
            count += 1
    count += c
    print(count)
    

if __name__ == "__main__":
    main()
