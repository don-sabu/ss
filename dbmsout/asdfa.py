import tkinter as tk
from tkinter import ttk
import cx_Oracle

conn = cx_Oracle.connect("C21AD24", "12345", "172.16.80.10:1521/orcl")


def create_patient_table():
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE patients (
            id NUMBER PRIMARY KEY,
            name VARCHAR2(50),
            gender VARCHAR2(10),
            place VARCHAR2(50),
            disease VARCHAR2(100)
        )
    ''')
    conn.commit()
    cursor.close()


def add_patient():
    def add_patient():
        patient_data = (
            id_entry.get(),
            name_entry.get(),
            gender_entry.get(),
            place_entry.get(),
            disease_entry.get()
        )
        cursor = conn.cursor()
        cursor.execute('INSERT INTO patients VALUES (:1, :2, :3, :4, :5)', patient_data)
        conn.commit()
        cursor.close()
        top.destroy()

    top = tk.Toplevel(root)
    top.title("Register Patient")

    tk.Label(top, text="ID:").grid(row=0, column=0, padx=10, pady=10)
    tk.Label(top, text="Name:").grid(row=1, column=0, padx=10, pady=10)
    tk.Label(top, text="Gender:").grid(row=2, column=0, padx=10, pady=10)
    tk.Label(top, text="Place:").grid(row=3, column=0, padx=10, pady=10)
    tk.Label(top, text="Disease:").grid(row=4, column=0, padx=10, pady=10)

    id_entry = tk.Entry(top)
    name_entry = tk.Entry(top)
    gender_entry = tk.Entry(top)
    place_entry = tk.Entry(top)
    disease_entry = tk.Entry(top)

    id_entry.grid(row=0, column=1, padx=10, pady=10)
    name_entry.grid(row=1, column=1, padx=10, pady=10)
    gender_entry.grid(row=2, column=1, padx=10, pady=10)
    place_entry.grid(row=3, column=1, padx=10, pady=10)
    disease_entry.grid(row=4, column=1, padx=10, pady=10)

    ttk.Button(top, text="Register", command=add_patient).grid(row=5, column=0, columnspan=2, pady=10)


def view_patients():
    cursor = conn.cursor()
    cursor.execute('SELECT * FROM patients')
    result = cursor.fetchall()
    cursor.close()

    top = tk.Toplevel(root)
    top.title("View Patients")

    tk.Label(top, text="ID").grid(row=0, column=0, padx=10, pady=10)
    tk.Label(top, text="Name").grid(row=0, column=1, padx=10, pady=10)
    tk.Label(top, text="Gender").grid(row=0, column=2, padx=10, pady=10)
    tk.Label(top, text="Place").grid(row=0, column=3, padx=10, pady=10)
    tk.Label(top, text="Disease").grid(row=0, column=4, padx=10, pady=10)

    for i, row in enumerate(result, start=1):
        for j, value in enumerate(row):
            tk.Label(top, text=value).grid(row=i, column=j, padx=10, pady=5)


if __name__ == "__main__":
    root = tk.Tk()
    root.title("Hospital Management System")
    root.geometry("600x400")

#     create_patient_table()

    ttk.Button(root, text="Register Patient", command=add_patient).pack(pady=10)
    ttk.Button(root, text="View Patients", command=view_patients).pack(pady=10)

    root.mainloop()
