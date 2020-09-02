import csv
import sys

# sys module - sys.argv for cmd line arguments
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")

# open csv file and dna sequence, read into memory
# cvs module - reader and DictReader
with open(sys.argv[1], 'r') as database:
    data = csv.reader(database)
    header = next(data)

    # opening text file fname = open(filename), read using fname.read()
    with open(sys.argv[2]) as seque:
        sequence = seque.read()

    # for each STR, compute the longest run of consecutive repeats in the DNA sequence
    compare = [0] * len(header)
    for i in range(1, len(header)):
        count = [0] * (len(sequence) + 1)
        for j in range(len(sequence)):
            substring = sequence[j:  len(header[i]) + j]
            if substring == header[i]:
                count[j] = count[j - len(header[i])] + 1
        compare[i] = max(count)

    # compare STR counts against each row in the csv
    for row in data:
        name = row[0]
        for i in range(1, len(header)):
            if not compare[i] == int(row[i]):
                name = "No match"
        if not name == "No match":
            break
    print(name)
