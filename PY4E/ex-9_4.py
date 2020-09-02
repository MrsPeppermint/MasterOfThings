# Write a program to read through the mbox-short.txt and figure out who has sent the greatest number of mail messages. 

name = input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
count = dict()

for line in handle:
    if line.startswith("From"):        
        words = line.split()
        if len(words) == 2:
            name = words[1]
            count[name] = count.get(name, 0) + 1
sort = [(v, k) for (k, v) in count.items()]
print(max(sort)[1], max(sort)[0])        
handle.close()
