import tkinter as tk
from .frontend_io import send_data_to_backend

#CALLBACKS
def on_submit():
    response =  send_data_to_backend(gross_income=gross_income_entry.get(),
                                    adjustments=adjustments_entry.get(), 
                                    adjusted_gross_income=adjusted_gross_income_entry.get(), 
                                    family_size=family_size_entry.get(),
                                    principal=principal_entry.get(),
                                    interest=interest_entry.get())
    response_label.config(text=response)  

#WINDOW
root = tk.Tk()

#LAYOUT
LABEL_COLUMN = 0
ENTRY_COLUMN = 1

gross_income_label = tk.Label(root, text="Gross Income")
gross_income_entry = tk.Entry(root)
gross_income_label.grid(row=0, column=LABEL_COLUMN)
gross_income_entry.grid(row=0, column=ENTRY_COLUMN)

adjustments_label = tk.Label(root, text="Adjustments")
adjustments_entry = tk.Entry(root)
adjustments_label.grid(row=1, column=LABEL_COLUMN)
adjustments_entry.grid(row=1, column=ENTRY_COLUMN)

adjusted_gross_income_label = tk.Label(root, text="Adjusted Gross Income")
adjusted_gross_income_entry = tk.Entry(root)
adjusted_gross_income_label.grid(row=2, column=LABEL_COLUMN)
adjusted_gross_income_entry.grid(row=2, column=ENTRY_COLUMN)

family_size_label = tk.Label(root, text="Family Size")
family_size_entry = tk.Entry(root)
family_size_label.grid(row=3, column=LABEL_COLUMN)
family_size_entry.grid(row=3, column=ENTRY_COLUMN)

principal_label = tk.Label(root, text="Principal")
principal_entry = tk.Entry(root)
principal_label.grid(row=4, column=LABEL_COLUMN)
principal_entry.grid(row=4, column=ENTRY_COLUMN)

interest_label = tk.Label(root, text="Interest")
interest_entry = tk.Entry(root)
interest_label.grid(row=5, column=LABEL_COLUMN)
interest_entry.grid(row=5, column=ENTRY_COLUMN)

#INTERFACE
submit_button = tk.Button(root, text="Submit", command=on_submit)
submit_button.grid(row=6, column=LABEL_COLUMN, columnspan=2)

response_label = tk.Label(root, text="")
response_label.grid(row=7, column=LABEL_COLUMN, columnspan=2)

#EXECUTE
root.mainloop()
