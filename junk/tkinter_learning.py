import tkinter
from tkinter import messagebox
#import answers


top = tkinter.Tk()

def send_ans(ans:int):
	pass
	#answers.submit(ans)

def a_picked():
	messagebox.showinfo("A", "Picked A!")
	send_ans(ans)
def b_picked():
	messagebox.showinfo("C", "Picked B!")
def c_picked():
	messagebox.showinfo("D", "Picked C!")


b = tkinter.Button(top, bg="red", text="A", command=a_picked)
m = tkinter.Button(top, bg="blue",text="B", command=b_picked)
t = tkinter.Button(top, bg="yellow",text="C", command=c_picked)

b.pack()
m.pack()
t.pack()
top.mainloop()

