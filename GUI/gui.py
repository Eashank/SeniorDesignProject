import tkinter as tk
import serial
import time

#arduino = serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=.1)


def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data



def display_values1():
    write_read("C0")
    time.sleep(1)
    write_read("X0")
    time.sleep(1)
    write_read("Y0")
   
    print("Button 1 clicked")

def display_values2():
    write_read("C8000")
    print("Button 2 clicked")

def display_values3():
    write_read("C0")
    print("Button 3 clicked")

def display_values4():
    write_read("X5000")
    time.sleep(1)
    write_read("Y3000")
    print("Button 4 clicked")

def display_values5():
    write_read("X0")
    time.sleep(1)
    write_read("Y0")
    print("Button 5 clicked")

def display_values6():
    write_read("X5000")
    time.sleep(1)
    write_read("Y0")
    print("Button 6 clicked")

root = tk.Tk()

title_label = tk.Label(root, text="Object Coordinates", font=("Arial", 20, "bold"), pady=10)
title_label.grid(row=0, column=0, columnspan=2)
names = ["temp","Reset", "Couple", "Decouple", "Cathode", "Fixture", "Filler tube"]


for i in range(1, 7):
    object_label = tk.Label(root, text=names[i], font=("Arial", 14))
    object_label.grid(row=i, column=0, padx=10, pady=5)

    btn = tk.Button(root, text="MOVE", font=("Arial", 14), padx=10, pady=5, bg="#4CAF50", fg="white")

    if i == 1:
        btn.config(command=display_values1)
    elif i == 2:
        btn.config(command=display_values2)
    elif i == 3:
        btn.config(command=display_values3)
    elif i == 4:
        btn.config(command=display_values4)
    elif i == 5:
        btn.config(command=display_values5)
    elif i == 6:
        btn.config(command=display_values6)

    btn.grid(row=i, column=1, padx=10, pady=5)

root.mainloop()
