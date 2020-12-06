import urllib.request
import xml.etree.ElementTree as ET

while True:
	location = input("Enter location: ")
	if len(location) < 1:
		break
	hand = urllib.request.urlopen(location)
	data = hand.read()
	tree = ET.fromstring(data)
	result = 0
	counts = tree.findall(".//count")
	for num in counts:
		result += int(num.text)
	print(result)
