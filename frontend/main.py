import tkinter as tk
from .frontend_io import send_data_to_backend

def on_submit():
    agi = agi_entry.get()
    response = send_data_to_backend(agi)
    response_label.config(text=response)

window = tk.Tk()
window.title("AGI Input")

instruction_label = tk.Label(window, text="Please enter your Adjusted Gross Income (AGI):")
instruction_label.pack()

agi_entry = tk.Entry(window)
agi_entry.pack()

submit_button = tk.Button(window, text="Submit", command=on_submit)
submit_button.pack()

response_label = tk.Label(window, text="")
response_label.pack()

# Running the application
window.mainloop()
