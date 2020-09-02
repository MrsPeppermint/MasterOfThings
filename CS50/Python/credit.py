from cs50 import get_int


def main():
    number = get_int("Number: ")
    if not number < 0:  # number is positive
        sum1 = 0
        sum2 = 0
        check1 = number
        while check1 > 0:
            # start from the right - last digit
            n1 = check1 % 10
            # add digit to sum1
            sum1 += n1
            # subtract from the main number
            check1 -= n1
            # go to second last digit
            check1 /= 10
            n2 = check1 % 10
            # fix mistake: multiply makes 2 digits
            if (n2*2) > 9:
                sum2 += (n2 * 2) % 10
                sum2 += 1
            else:
                sum2 += n2 * 2
            check1 -= n2
            check1 /= 10
            valid = "INVALID"
        suma = sum1 + sum2
        if suma % 10 == 0:
            valid = banks(number)
        print(valid)


def banks(n):
    # choose a provider
    bank = "INVALID"
    if 340000000000000 < n < 350000000000000 or 370000000000000 < n < 380000000000000:
        bank = "AMEX"
    elif 5100000000000000 < n < 5600000000000000:
        bank = "MASTERCARD"
    elif 4000000000000 < n < 5000000000000 or 4000000000000000 < n < 5000000000000000:
        bank = "VISA"
    return bank


main()