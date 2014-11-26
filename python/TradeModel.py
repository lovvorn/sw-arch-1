import http.client
import re

class TradeModel():

    def __init__(self):
        self.connection = http.client.HTTPSConnection('sandbox.tradier.com', 443, timeout = 30)
        self.headers = {
                "Accept": "application/json",
                "Authorization": "Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3"
                }

    def update(self):
        i = 0
        self.result = []

        self.request = '/v1/markets/quotes?symbols=' + self.symbol
        self.connection.request('GET', self.request, None, self.headers)

        response = self.connection.getresponse()

        content = response.read()
        content = content.decode('utf-8')

        line = re.sub('"', '', content)

        for each_line in line:
            info = line.split(',')

        for each_line in info:
            self.result.append(info[i].split(":"))
            i = i + 1

    def setSymbol(self, symbol):
        self.symbol = symbol

    def getSymbol(self):
        return self.result[0][3]

    def getDescription(self):
        return self.result[1][1]

    def getExchange(self):
        return self.result[2][1]

    def getClosingPrice(self):
        return self.result[4][1]

    def getDailyNetChange(self):
        return self.result[5][1]

    def getDailyNetChangePercent(self):
        return self.result[6][1]

    def getVolume(self):
        return self.result[7][1]

    def getAverageVolume(self):
        return self.result[8][1]

    def getHigh(self):
        return self.result[16][1]

    def getLow(self):
        return self.result[17][1]
