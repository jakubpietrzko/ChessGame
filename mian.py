import tkinter as tk
from menu import StartMenu
from chess_board import boardView
from PIL import Image, ImageTk

class MainApplication(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Menu Początkowe")
        self.geometry("400x300")
        self.current_view = None
        self.mode=None
        self.board_size=700
        self.square_size=self.board_size//8
        self.piece_images ={
                                "wp": ImageTk.PhotoImage(Image.open("img/bialy_pion.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "bp": ImageTk.PhotoImage(Image.open("img/czarny_pion.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "wr": ImageTk.PhotoImage(Image.open("img/biala_wieza.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "br": ImageTk.PhotoImage(Image.open("img/czarna_wieza.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "wb": ImageTk.PhotoImage(Image.open("img/bialy_goniec.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "bb": ImageTk.PhotoImage(Image.open("img/czarny_goniec.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "wn": ImageTk.PhotoImage(Image.open("img/bialy_kon.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "bn": ImageTk.PhotoImage(Image.open("img/czarny_kon.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "wq": ImageTk.PhotoImage(Image.open("img/bialy_hetman.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "bq": ImageTk.PhotoImage(Image.open("img/czarny_hetman.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "wk": ImageTk.PhotoImage(Image.open("img/bialy_krol.png").convert("RGBA").resize((self.square_size,self.square_size))),
                                "bk": ImageTk.PhotoImage(Image.open("img/czarny_krol.png").convert("RGBA").resize((self.square_size,self.square_size))),
                            }
        self.board =[["wr", "wn", "wb", "wk", "wq", "wb", "wn", "wr"],
                     ["wp", "wp", "wp", "wp", "wp", "wp", "wp", "wp"],
                    ["", "", "", "", "", "", "", ""],
                    ["", "", "", "", "", "", "", ""],
                    ["", "", "", "", "", "", "", ""],
                    ["", "", "", "", "", "", "", ""],
                    ["bp", "bp", "bp", "bp", "bp", "bp", "bp", "bp"],
                    ["br", "bn", "bb", "bk", "bq", "bb", "bn", "br"]
                ]
        self.create_start_menu()
        
        
    def create_start_menu(self):
        if self.current_view:
            self.current_view.destroy()
        
        self.current_view = StartMenu(self, self.start_game)
        self.current_view.pack()
    
    def start_game(self, game_mode):
        if self.current_view:
            self.current_view.destroy()
        self.geometry("700x700")
        if game_mode == "2_graczy_lokalnie":
          self.mode=2
        elif game_mode == "gracz_vs_komputer":
           self.mode=1
        self.current_view = boardView(self)
        
        """elif game_mode == "2_graczy_przez_internet":
          pass # self.current_view = GameMode2(self)
       
        elif game_mode == "komputer_vs_komputer":
           pass# self.current_view = GameMode4(self)"""
        
        self.current_view.pack()


app = MainApplication()
app.mainloop()
