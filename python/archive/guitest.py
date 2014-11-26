# -*- coding: utf-8 -*-
"""
Created on Thu Nov 20 15:52:11 2014

@author: Kazi Zakia
"""

import tkinter
import tkinter.messagebox
import tkinter.scrolledtext

def show_entry_fields():
    tkinter.messagebox.showinfo("Messagebox","Thanks for your Query")    
    textPad = tkinter.scrolledtext.ScrolledText(width=30, height=20)
    textPad.pack()
   

def main():
    master = tkinter.Tk()
    tkinter.Label(master, text="Query").grid(row=0)
    e1 = tkinter.Entry(master)
    e1.grid(row=0, column=1)
    tkinter.Button(master, text='Show', command=show_entry_fields).grid(row=3, column=1, sticky=tkinter.W, pady=4)
    tkinter.mainloop( )
    
main()