import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
count = int(input('Enter count: '))
position = int(input('Enter position: '))
i = 0
# Retrieve all of the anchor tags
while i <= count:
	html = urllib.request.urlopen(url, context=ctx).read()
	soup = BeautifulSoup(html, 'html.parser')
	tags = soup('a')
	j = 0
	print("Retrieving: ",url)
	for tag in tags:
		if (j < position):
			url = tag.get('href', None)
			j += 1
		else:break
	i += 1
