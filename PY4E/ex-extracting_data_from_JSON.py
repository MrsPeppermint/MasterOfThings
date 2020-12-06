import urllib.request
import json

while True:
	location = input("Enter location: ")
	if len(location) < 1:
		break
	hand = urllib.request.urlopen(location)
	data = json.loads(hand.read())
	result = 0
	for row in data['comments']:
		result += row['count']
	print(result)
