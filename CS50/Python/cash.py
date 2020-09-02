from cs50 import get_float
# check for a correct input
while True:
    cash = get_float("Change owed: ")
    if not (cash < 0):
        break

cents = cash*100
# counter
coins = 0
# coin values
value = [25, 10, 5, 1]
for i in range(4):
    while cents >= value[i]:
        cents -= value[i]
        coins += 1
print(coins)
