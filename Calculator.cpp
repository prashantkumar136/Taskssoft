import tkinter as tk
import random
import string


class PasswordGenerator(tk.Tk):
    def _init_(self):
        tk.Tk._init_(self)
        self.title("Password Generator")
        self.geometry("400x400")
        
        self.password_generator = tk.Label(self, text="Password Generator", font=("Arial", 20, "bold"), fg="darkblue")
        self.password_generator.pack(pady=10)
        
        self.name_label = tk.Label(self, text="User's name:")
        self.name_label.pack()
        
        self.name_entry = tk.Entry(self)
        self.name_entry.pack()
        
        self.length_label = tk.Label(self, text="Password Length:")
        self.length_label.pack()

        self.length_entry = tk.Entry(self)
        self.length_entry.pack()

        self.lower_var = tk.IntVar()
        self.lower_check = tk.Checkbutton(self, text="Lowercase", variable=self.lower_var)
        self.lower_check.pack()

        self.upper_var = tk.IntVar()
        self.upper_check = tk.Checkbutton(self, text="Uppercase", variable=self.upper_var)
        self.upper_check.pack()

        self.digit_var = tk.IntVar()
        self.digit_check = tk.Checkbutton(self, text="Digits", variable=self.digit_var)
        self.digit_check.pack()

        self.special_var = tk.IntVar()
        self.special_check = tk.Checkbutton(self, text="Special Characters", variable=self.special_var)
        self.special_check.pack()
        
        self.password_label = tk.Label(self, text="Generated Password:")
        self.password_label.pack()

        self.password_entry = tk.Entry(self)
        self.password_entry.pack()

        self.generate_button = tk.Button(self, text="Generate", command=self.generate_password, font=("Calibri", 10, "bold"),bg="darkblue", fg="white")
        self.generate_button.pack()
        
        

    def generate_password(self):
        password_length = int(self.length_entry.get())
        use_lower = bool(self.lower_var.get())
        use_upper = bool(self.upper_var.get())
        use_digits = bool(self.digit_var.get())
        use_special = bool(self.special_var.get())

        character_set = ""
        if use_lower:
            character_set += string.ascii_lowercase
        if use_upper:
            character_set += string.ascii_uppercase
        if use_digits:
            character_set += string.digits
        if use_special:
            character_set += string.punctuation

        if character_set:
            password = "".join(random.choice(character_set) for _ in range(password_length))
        else:
            password = "No character set selected"

        self.password_entry.delete(0, tk.END)
        self.password_entry.insert(tk.END, password)

if _name_ == "_main_":
    password_generator = PasswordGenerator()
    password_generator.mainloop()