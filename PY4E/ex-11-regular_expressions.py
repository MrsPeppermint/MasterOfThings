# Look for integers in given file and return sum
import re

file = open('regex_sum_931959.txt')
sum = 0;
for line in file:
	numbers = re.findall('[0-9]+', line)
	for i in range (len(numbers)):
		sum += int(numbers[i])
print(sum)
file.close()
