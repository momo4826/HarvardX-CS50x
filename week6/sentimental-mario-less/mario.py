def main():
    while True:
        try:
            h = int(input("Height: "))
            if h >= 1 and h <= 8:
                break
        except:
            pass
    for i in range(h):
        print(" " * (h - i - 1) + "#" * (i + 1))


if __name__ == "__main__":
    main()
