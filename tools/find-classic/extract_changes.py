from urllib import request
from bs4 import BeautifulSoup

url = "https://www.wxpython.org/Phoenix/docs/html/classic_vs_phoenix.html#classic-vs-phoenix"
html = request.urlopen(url).read()
soup = BeautifulSoup(html, features="html.parser")

classic_items = []
for table in soup.find_all('table'):
    for row in table.tbody.findAll('tr'):
        classic = row.find_all('td')[0]
        classic_items.append(classic.text)

with open('classic-items.txt', 'w') as f:
    [f.write(item + '\n') for item in classic_items]
