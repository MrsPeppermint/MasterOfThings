# Use the file name mbox-short.txt as the file name
# Write a program that prompts for a file name, then opens that file and reads through the file, looking for lines in given form
# Count these lines and extract the floating point values from each of the lines and compute the average of those values 
# Do not use the sum() function or a variable named sum in your solution.

fname = input("Enter file name: ")
fh = open(fname)
num = 0
count = 0
for line in fh:
    if not line.startswith("X-DSPAM-Confidence:") : continue
    for line in fh:
    	if not line.startswith("X-DSPAM-Confidence:"):
        	continue
    	elif line.startswith("X-DSPAM-Confidence:"):
        	num += float(line[line.find('0'): ])
        	count += 1

print("Average spam confidence:", num/count)
fh.close()
