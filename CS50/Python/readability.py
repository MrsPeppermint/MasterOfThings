from cs50 import get_string


def main():
    text = get_string("Text: ")
    countL = 0
    countW = 1  # no space before first word
    countS = 0
    for i in range(len(text)):
        # look for upper and lower case letters
        if chr(64) < text[i] < chr(91) or chr(96) < text[i] < chr(123):
            countL += 1
        # look for spaces
        elif text[i] == chr(32):
            countW += 1
        # look for punctuation
        elif text[i] == chr(46) or text[i] == chr(63) or text[i] == chr(33):
            countS += 1
    avgL = (countL / countW) * 100
    avgS = (countS / countW) * 100
    index = ColemanLiau(avgL, avgS)
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def ColemanLiau(avgL, avgS):
    clIndex = 0.0588*avgL - 0.296*avgS - 15.8
    return int(round(clIndex))


main()