# -*- coding: utf-8 -*-
"""
Created on Thu Nov 20 15:52:11 2014

@author: Kazi Zakia
"""
from tkinter import *
import tkinter
import tkinter.messagebox
import tkinter.scrolledtext
import http.client
import re

def show_entry_fields(sym):
    tkinter.messagebox.showinfo("Messagebox","Thanks for your Query")    
    textPad = tkinter.scrolledtext.ScrolledText(width=60, height=15)


    i = 0
    info = []
    test = []
    connection = http.client.HTTPSConnection('sandbox.tradier.com', 443, timeout = 30)

    headers = {"Accept":"application/json","Authorization":"Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3"}
    req = '/v1/markets/quotes?symbols=' + sym.get()
    connection.request('GET',req, None, headers)

    response = connection.getresponse()
    content = response.read()
    content = content.decode('utf-8')

    line = re.sub('"','', content)
    
    for each_line in line:
      info=line.split(',')
  
    for each_line in info:
      test.append(info[i].split(":"))
      i = i + 1
   # textPad.insert(INSERT,' Symbol:')
   # textPad.insert(END,test[0][3])
    #textPad.insert(END,' Description:',test[1][1])
    try:
        textPad.insert(END,'Symbol: \t\t\t', END, test[0][3],END,'\nDescription: \t\t\t',END,test[1][1],END,'\nExchange: \t\t\t',END,test[2][1],END,
          '\nClosing Price: \t\t\t',END,test[4][1],END,'\nDaily Net Change: \t\t\t',END,test[5][1],END,'\nDaily Net Change %: \t\t\t',END,test[6][1],END,
          '\nVolume: \t\t\t',END,test[7][1],END,'\nAverage Volume: \t\t\t',END,test[8][1],END,'\n52-Week High: \t\t\t',END,test[16][1],END,
          '\n52-Week Low: \t\t\t',END,test[17][1])
    except IndexError:
        textPad.insert(END, "Invalid symbol")

    textPad.pack()

   

def main():
    master = tkinter.Tk()
    tkinter.Label(master, text="Query").grid(row=0)
    e1 = tkinter.Entry(master)
    e1.grid(row=0, column=1)
    #e1.pack()
    tkinter.Button(master, text='Show', command= lambda: show_entry_fields(e1)).grid(row=3, column=1, sticky=tkinter.W, pady=4)
    tkinter.mainloop( )


def display():
    i = 0
    info = []
    test = []
    connection = http.client.HTTPSConnection('sandbox.tradier.com', 443, timeout = 30)
    headers = {"Accept":"application/json","Authorization":"Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3"}
    req = '/v1/markets/quotes?symbols=' + sym

    
main()
