import re


def main():
    while True:
        try:
            n = input("Number: ")
            if re.match(r"(\d)+", n):
                break
        except:
            pass

    if not checker(n):
        print("INVALID")
        return
    if re.match(r"^3(4|7)\d{13}$", n):
        print("AMEX")
        return

    if re.match(r"^5(1|2|3|4|5)\d{14}$", n):
        print("MASTERCARD")
        return

    if re.match(r"^4\d{12}$", n) or re.match(r"^4\d{15}$", n):
        print("VISA")
        return

    print("INVALID")


def checker(n):
    res = 0
    n = n[::-1]
    for i in range(len(n)):
        if i % 2 == 1:
            tmp = int(n[i]) * 2
            while tmp:
                res += tmp % 10
                tmp //= 10
        else:
            res += int(n[i])
        # print(res)
    if res % 10 == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    main()
