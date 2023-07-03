import tkinter as tk

class StartMenu(tk.Frame):
    def __init__(self, parent, start_game_callback):
        super().__init__(parent)
        self.parent = parent
        self.start_game_callback = start_game_callback
        
        self.create_widgets()
        
    def create_widgets(self):
        # Etykieta z opisem menu
        label = tk.Label(self, text="Wybierz tryb gry:", font=("Arial", self.parent.winfo_height() // 20))
        label.pack(pady=self.parent.winfo_height() // 10)
        
        # Przyciski do wyboru trybu gry
        button_width = self.parent.winfo_width() // 40
        button_height = self.parent.winfo_height() // 60
        button_font_size = self.parent.winfo_height() // 80
        
        button1 = tk.Button(self, text="2 graczy lokalnie", command=lambda: self.start_game_callback("2_graczy_lokalnie"), width=button_width, height=button_height, font=("Arial", button_font_size))
        button1.pack(pady=self.parent.winfo_height() // 30)
        
        button2 = tk.Button(self, text="2 graczy przez internet", command=lambda: self.start_game_callback("2_graczy_przez_internet"), width=button_width, height=button_height, font=("Arial", button_font_size))
        button2.pack(pady=self.parent.winfo_height() // 30)
        
        button3 = tk.Button(self, text="Gracz vs komputer", command=lambda: self.start_game_callback("gracz_vs_komputer"), width=button_width, height=button_height, font=("Arial", button_font_size))
        button3.pack(pady=self.parent.winfo_height() // 30)
        
        button4 = tk.Button(self, text="Komputer vs komputer", command=lambda: self.start_game_callback("komputer_vs_komputer"), width=button_width, height=button_height, font=("Arial", button_font_size))
        button4.pack(pady=self.parent.winfo_height() // 30)