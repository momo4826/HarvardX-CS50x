def main():
    while True:
        try:
            h = int(input("Height: "))
            if h >= 1 and h <= 8:
                break
        except:
            pass
    for i in range(1, h + 1):
        print(" " * (h - i) + "#" * i + " " * 2 + "#" * i)


if __name__ == "__main__":
    main()
