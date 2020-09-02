# Write a program to read through the mbox-short.txt and figure out the distribution by hour of the day for each of the messages. 
# Print out the counts, sorted by hour as shown.

name = input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
result = dict()

for line in handle:
    if line.startswith("From"):
        words = line.split()
        if len(words) == 7:
            time = words[5]
            hours = (time.split(":"))[0]
            result[hours] = result.get(hours,0) + 1

for key in sorted(result):
    print(key, result[key])
handle.close()
