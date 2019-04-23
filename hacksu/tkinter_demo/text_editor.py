#!/usr/bin/python3

'''
File: text_editor.py
Name: P.J. Leyden
Date: April 23rd, 2019
Desc: Tkinter Demo for HacKSU Lesson
'''

from tkinter import *
from tkinter import ttk
from tkinter import filedialog

class PyGUI:

	def shutdown(self):
		self.root.destroy()

	def openFile(self):
		file_full = filedialog.askopenfilename()
		if (not isinstance(file_full, tuple)) & (file_full != ''):
			current_file = open(file_full, "r")
			self.text.insert(1.0, current_file.read())
			current_file.close()

	def saveFile(self):
		file_full = filedialog.asksaveasfilename()
		if (not isinstance(file_full, tuple)) & (file_full != ''):
			current_file = open(file_full, "w+")
			current_file.write(self.text.get(1.0, END))
			current_file.close()

	def __init__(self):
		self.root = Tk()
		self.root.title("PJ's Text Editor")
		self.root.protocol('WM_DELETE_WINDOW', self.shutdown)

		#Text
		self.text = Text(self.root)
		self.text.grid(column=0, row=0)
		
		#Menu/Toolbar
		self.menu = Menu(self.root)
		self.root.config(menu=self.menu)

		self.filemenu = Menu(self.menu)
		self.menu.add_cascade(label="File", menu=self.filemenu)
		self.filemenu.add_command(label="New")
		self.filemenu.add_command(label="Open", command=self.openFile)
		self.filemenu.add_command(label="Save", command=self.saveFile)
		self.filemenu.add_separator()
		self.filemenu.add_command(label="Exit", command=self.shutdown)
		
		#Setups up loop and "runs" the gui
		self.root.mainloop()



if __name__ == '__main__':
	PyGUI()
