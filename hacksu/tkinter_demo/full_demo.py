#!/usr/bin/python3

'''
File: full_demo.py
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

	def getFileName(self):
		full_name = filedialog.askopenfilename()
		if not isinstance(full_name, tuple):
			self.file_full.set(full_name)
			self.file_name.set(full_name[full_name.rfind("/") + 1:])
			self.file_path.set(full_name[:full_name.rfind("/") + 1])

	def openFile(self):
		self.getFileName()
		current_file = open(self.file_full.get(), "r")
		self.text.insert(1.0, current_file.read())

	def printName(self):
		print(self.entry.get())

	def save(self):
		content = self.text.get(1.0, END)
		print(content)

	def __init__(self):
		self.root = Tk()
		self.root.title("PJ's Window")
		self.root.protocol('WM_DELETE_WINDOW', self.shutdown)

		#Label/Entry/Button
		'''
		self.label = Label(self.root, text="First Name: ")
		self.label.grid(column=0, row=0, padx=5, pady=5)
		
		self.entry = Entry(self.root)
		self.entry.grid(column=1, row=0, padx=5, pady=5)

		self.button = Button(self.root, text="Print", command=self.printName)
		self.button.grid(column=0, row=1, padx=5, pady=5)
		'''

		#Canvas
		'''
		self.canvas = Canvas(self.root, width=200, height=100)
		self.canvas.grid(column=1, row=1)#, padx=5, pady=5)
		#self.canvas.pack()

		self.canvas.create_line(0, 0, 200, 100)
		self.canvas.create_line(0, 100, 200, 0, fill="red", dash=(4, 4))
		self.canvas.create_rectangle(50, 25, 150, 75, fill="blue")
		'''

		#Text
		'''
		self.text = Text(self.root)
		self.text.grid(column=0, row=0)
		Button(self.root, text="Save", command=self.save).grid(column=0, row=1, sticky=W)
		'''

		#Notebook/Tabs
		'''
		self.notebook = ttk.Notebook(self.root)
		self.notebook.grid()

		self.database_setup = Frame(self.notebook)
		self.notebook.add(self.database_setup, text="Database")

		self.tab_setup = Frame(self.notebook)
		self.notebook.add(self.tab_setup, text="Import XML")
		'''

		#Menu/Toolbar
		'''
		self.menu = Menu(self.root)
		self.root.config(menu=self.menu)

		self.filemenu = Menu(self.menu)
		self.menu.add_cascade(label="File", menu=self.filemenu)
		self.filemenu.add_command(label="New")
		self.filemenu.add_command(label="Open", command=self.openFile)
		self.filemenu.add_command(label="Save", command=self.save)
		self.filemenu.add_separator()
		self.filemenu.add_command(label="Exit", command=self.shutdown)
		
		self.toolbar = Frame(self.root)
		self.button = Button(self.toolbar, text="NEW", width=6)
		self.button.grid(sticky=W, padx=2, pady=2)
		self.toolbar.grid(sticky=W)
		'''

		#Spinbox
		'''
		self.spin = Spinbox(self.root, values=(1, 2, 4, 8))
		self.spin.grid()
		'''

		#Options Menu
		'''
		self.var = StringVar()
		self.var.set("one") #default Value
		self.options = OptionMenu(self.root, self.var, "one", "two", "three")
		self.options.grid()
		'''


		self.file_name = StringVar()
		self.file_path = StringVar()
		self.file_full = StringVar()
		
		#Setups up loop and "runs" the gui
		self.root.mainloop()



if __name__ == '__main__':
	PyGUI()
