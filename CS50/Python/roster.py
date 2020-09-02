from sys import argv, exit
from cs50 import SQL

db = SQL("sqlite:///students.db")

# check command-line argument
if len(argv) != 2:
    print("Usage: python roster.py HouseName")
    exit(0)

house = argv[1]

# query database for students in house
# db.execute(SELECT) - return: list of dicts

# sorted alphabetically by last name, then first name
rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", house)
for row in rows:
    # check for null values
    if row['middle'] == None:
        print(f"{row['first']} {row['last']}, born {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")