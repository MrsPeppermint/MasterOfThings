import urllib.request, urllib.parse, urllib.error
import json

api_key = 42
serviceurl= "http://py4e-data.dr-chuck.net/json?"

while True:
	address = input("Enter location: ")
	if len(address) < 1:
		break
	parameters = dict()
	parameters["address"] = address
	parameters["key"] = api_key
	url = serviceurl + urllib.parse.urlencode(parameters)

	print("Retrieving", url)
	d_encoded = urllib.request.urlopen(url)
	data = d_encoded.read().decode()
	print("Retrieved", len(data), "characters")

	try:
		js = json.loads(data)
	except:
		js = None
	place_id = js["results"][0]["place_id"]
	print("Place id", place_id )
