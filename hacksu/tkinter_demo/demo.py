#!/usr/bin/python3

from tkinter import *
from tkinter import ttk
from tkinter import filedialog

class PyGUI:

	def shutdown(self):
		self.root.destroy()

	def openFile(self):
		file_path = filedialog.askopenfilename()
		if (not isinstance(file_path, tuple)) and (file_path != ''):
			cur_file = open(file_path, "r")
			self.text.insert(1.0, cur_file.read())
			cur_file.close()

	def saveFile(self):
		file_path = filedialog.asksaveasfilename()
		if (not isinstance(file_path, tuple)) and (file_path != ''):
			cur_file = open(file_path, "w+")
			cur_file.write(self.text.get(1.0, END))
			cur_file.close()

	def __init__(self):
		self.root = Tk()
		self.root.title("PJ's Window")
		self.root.protocol('WM_DELETE_WINDOW', self.shutdown)
	

		self.main_menu = Menu(self.root)
		self.root.config(menu=self.main_menu)

		self.file_menu = Menu(self.main_menu)
		self.main_menu.add_cascade(label="File", menu=self.file_menu)
		self.file_menu.add_command(label="Open", command=self.openFile)
		self.file_menu.add_command(label="Save", command=self.saveFile)
		self.file_menu.add_separator()
		self.file_menu.add_command(label="Exit", command=self.shutdown)

		self.text = Text(self.root)
		self.text.grid(column=0, row=0)

		self.root.mainloop()


if __name__ == '__main__':
	PyGUI()