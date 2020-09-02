# Open the file mbox-short.txt and read it line by line. 
# When you find a line that starts with 'From ' like the given line
# Parse the From line using split() and print out the second word in the line 
# Then print out a count at the end.

fname = input("Enter file name: ")
if len(fname) < 1 : fname = "mbox-short.txt"

fh = open(fname)
count = 0
for line in fh:
    if line.startswith("From") and len(line.split()) > 2:
        print(line.split()[1])
        count += 1
        
print("There were", count, "lines in the file with From as the first word")
fh.close()
