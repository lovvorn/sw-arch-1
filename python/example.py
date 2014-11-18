import httplib

# Request: Market Quotes (https://sandbox.tradier.com/v1/markets/quotes?symbols=spy)

connection = httplib.HTTPSConnection('sandbox.tradier.com', 443, timeout = 30)

# Headers

headers = {"Accept":"application/json",
           "Authorization":"Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3"}

# Send synchronously

connection.request('GET', '/v1/markets/quotes?symbols=spy', None, headers)
try:
  response = connection.getresponse()
  content = response.read()
  # Success
  print('Response status ' + str(response.status))
except httplib.HTTPException, e:
  # Exception
  print('Exception during request')