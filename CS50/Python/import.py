import csv
from sys import argv, exit
from cs50 import SQL

if (len(argv) != 2):
    print("Usage: python import.py csvfile.csv")
    exit(0)

# get access to database
# use db.execute("QUERY") = select, insert..
db = SQL("sqlite:///students.db")

# clear potential previous copies
db.execute("DELETE FROM students")

with open(argv[1], 'r') as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:

        # parse name (first, middle/None, last)
        name = (row[0].split())
        first = name[0]
        if len(name) == 3:
            middle = name[1]
            last = name[2]
        elif len(name) == 2:
            middle = None
            last = name[1]
        house = row[1]
        birth = row[2]
        data = (first, middle, last, row[1], row[2])

        # insert each into students table in students.db
        db.execute("INSERT INTO students (first,middle,last,house,birth)"
                   "VALUES (?, ?, ?, ?, ?)", data)
