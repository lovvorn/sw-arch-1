import http.client
import re
# Request: Market Quotes (https://sandbox.tradier.com/v1/markets/quotes?symbols=spy)
i = 0
info = []
test = []
connection = http.client.HTTPSConnection('sandbox.tradier.com', 443, timeout = 30)

# Headers

sym = input("Enter symbol to search: ")
headers = {"Accept":"application/json",
           "Authorization":"Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3"}

# Send synchronously

req = '/v1/markets/quotes?symbols=' + sym
print(req)
connection.request('GET',req, None, headers)

#recieves data and decodes so that it can be altered
response = connection.getresponse()
content = response.read()
content = content.decode('utf-8')

# Success
print('Response status ' + str(response.status))
#print(content)


#removes quotes from recieved data
line = re.sub('"','', content)

#breaks apart data into each section and then divides it into the field and value
for each_line in line:
  
  info=line.split(',')
  
for each_line in info:
  test.append(info[i].split(":"))
  i = i + 1

  
final = (' Symbol:',test[0][3],'\n','Description:',test[1][1],'\n Exchange:',test[2][1],
      '\n Closing Price:',test[4][1],'\n Daily Net Change:',test[5][1],'\n Dail Net Change %:',test[6][1],
      '\n Volume:',test[7][1],'\n Average Volume:',test[8][1],'\n 52-Week High:',test[16][1],
      '\n 52-Week Low:',test[17][1])

print(final)

#print (info[0],' ',info[1],' ',info[2],' ',info[3])
#print(test)
print(' Symbol:',test[0][3],'\n','Description:',test[1][1],'\n Exchange:',test[2][1],
      '\n Closing Price:',test[4][1],'\n Daily Net Change:',test[5][1],'\n Dail Net Change %:',test[6][1],
      '\n Volume:',test[7][1],'\n Average Volume:',test[8][1],'\n 52-Week High:',test[16][1],
      '\n 52-Week Low:',test[17][1])
