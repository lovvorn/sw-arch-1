from tkinter import *
from TradeModel import TradeModel

class TradeController():

    def updateModel(self, info):
        self.model = TradeModel()
        self.model.setSymbol(info)
        self.model.update()

    def updateView(self):
        return self.model
