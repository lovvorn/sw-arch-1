from tkinter import *
from TradeController import TradeController

import tkinter.scrolledtext as tkst

class TradeView(Frame):

    def getInformation(self):
        try:
            self.controller.updateModel(self.textBox.get())

            self.textBox2.delete(1.0, 10.0)
            self.textBox2.insert(1.0, "Symbol: " + self.controller.updateView().getSymbol() + "\n")
            self.textBox2.insert(2.0, "Description: " + self.controller.updateView().getDescription() + "\n")
            self.textBox2.insert(3.0, "Exchange: " + self.controller.updateView().getExchange() + "\n")
            self.textBox2.insert(4.0, "ClosingPrice: " + self.controller.updateView().getClosingPrice() + "\n")
            self.textBox2.insert(5.0, "DailyNetChange: " + self.controller.updateView().getDailyNetChange() + "\n")
            self.textBox2.insert(6.0, "DailyNetChangePercent: " + self.controller.updateView().getDailyNetChangePercent() + "\n")
            self.textBox2.insert(7.0, "Volume: " + self.controller.updateView().getVolume() + "\n")
            self.textBox2.insert(8.0, "AverageVolume: " + self.controller.updateView().getAverageVolume() + "\n")
            self.textBox2.insert(9.0, "High: " + self.controller.updateView().getHigh() + "\n")
            self.textBox2.insert(10.0, "Low: " + self.controller.updateView().getLow() + "\n")
        except IndexError:
            self.textBox2.delete(1.0, 10.0)
            self.textBox2.insert(1.0, "That symbol does not exist.") 


    def show(self):
        self.QUIT = Button(self)
        self.QUIT["text"] = "QUIT"
        self.QUIT["fg"]   = "red"
        self.QUIT["command"] =  self.quit

        self.QUIT.pack(side = BOTTOM)

        self.textBox2 = Text(self, font = ("Monaco", 18), width = 60, height = 13, bg = "#333", fg = "#fff")
        self.textBox2.pack(side = BOTTOM)

        self.hi_there = Button(self)
        self.hi_there["text"] = "Get Information"
        self.hi_there["command"] = self.getInformation

        self.hi_there.pack(side = BOTTOM)

        self.textBox = Entry(self)
        self.textBox.pack(side = BOTTOM)


    def __init__(self, master=None):
        self.controller = TradeController()

        Frame.__init__(self, master)
        self.pack()
        self.show()

root = Tk()
app = TradeView(master = root)
app.mainloop()
root.destroy()
