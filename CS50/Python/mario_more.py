while True:
    try:
        height = int(input("Height: "))
        if 0 < height < 9:
            for i in range(height):
                print(" " * (height - 1 - i) + "#" * (i + 1) + "  "
                      + "#" * (i + 1))
            break
    except ValueError:
        pass
