import tkinter as tk
from PIL import Image, ImageTk
import subprocess
import os
import signal
import subprocess
class boardView(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent)
        self.piece_images  = parent.piece_images
        self.mode=parent.mode
        self.ruch=0
        self.selected_piece=None
        self.square_size = parent.square_size  
        self.selected_piece_image = None
        self.selected_piece_position = None 
        self.initial_col=None
        self.initial_row=None
        self.row_target=None
        self.col_target=None
        self.board= parent.board
        try:
            self.engine = subprocess.Popen(["./chess"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            parent.protocol("WM_DELETE_WINDOW", self.on_close)
            self.create_widgets(parent=parent)
        except KeyboardInterrupt:
            self.engine.kill()

    def on_close(self):
        self.engine.kill()
        self.master.destroy()
    def create_widgets(self, parent):
        # Utworzenie planszy
        self.canvas = tk.Canvas(self, width=parent.board_size, height=parent.board_size)
        self.canvas.pack()
        
        # Przypisanie funkcji do zdarzeń przeciągania figury
        self.canvas.bind("<Button-1>", self.select_piece)
        self.canvas.bind("<B1-Motion>", self.drag_piece)
        self.canvas.bind("<ButtonRelease-1>", self.release_piece)
        
        # Rysowanie początkowej planszy
        self.update_board()
        
    def update_board(self):
        self.draw_board()
        self.draw_pieces()
        print("upadte")
        if self.mode==1 and self.ruch==0:
            self.engine_run()
    def draw_board(self):
        self.canvas.delete("all")
        colors = ["white", "gray"]

        for row in range(8):
            for col in range(8):
                x1 = col * self.square_size
                y1 = row * self.square_size
                x2 = x1 + self.square_size
                y2 = y1 + self.square_size
                color = colors[(row + col) % 2]
                self.canvas.create_rectangle(x1, y1, x2, y2, fill=color)

    def draw_pieces(self):
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece != "":
                    x = col * self.square_size
                    y = row * self.square_size
                    self.canvas.create_image(x, y, image=self.piece_images[piece], anchor="nw")
                    
    def select_piece(self,event):

        # Sprawdź, czy jest figura na wybranym polu
        row = event.y // self.square_size
        col = event.x // self.square_size
        piece = self.board[row][col]
        
        # Jeśli figura istnieje, zapisz jej informacje i przeciągaj
        if piece:
            self.selected_piece = piece
            self.selected_piece_image = self.piece_images[self.selected_piece]
            self.selected_piece_position = (event.x, event.y)
            self.canvas.lift(self.selected_piece_image)

            # Przesuń figurę na współrzędne kliknięcia
            self.canvas.coords(self.selected_piece_image, event.x - self.square_size // 2, event.y - self.square_size // 2)

    def drag_piece(self,event):
       
        # Sprawdź, czy jest wybrana figura do przeciągania
        if self.selected_piece:
            # Aktualizuj pozycję przeciąganej figury
            self.canvas.coords(self.selected_piece_image, event.x - self.square_size // 2, event.y - self.square_size // 2)
            

    def release_piece(self,event):
        
        # Sprawdź, czy jest wybrana figura do przeciągania
        if self.selected_piece:
            # Pobierz aktualne współrzędne pola docelowego
            self.row_target = event.y // self.square_size
            self.col_target = event.x // self.square_size

            # Przemieszczenie figury na nowe pole
            self.board[self.row_target][self.col_target] = self.selected_piece

            # Wyczyść pole, z którego figura została przemieszczona
            self.initial_col, self.initial_row = self.selected_piece_position
            self.initial_col=self.initial_col//self.square_size
            self.initial_row=self.initial_row//self.square_size
            
            self.board[self.initial_row][self.initial_col] = ""

            if (self.selected_piece=="bk" and self.initial_col==3 and self.col_target==1):
                self.board[7][2]="br"
                self.board[7][0]=""
            if (self.selected_piece=="bk" and self.initial_col==3 and self.col_target==5):
                self.board[7][4]="br"
                self.board[7][7]=""
            if (self.selected_piece=="wk" and self.initial_col==3 and self.col_target==1):
                self.board[0][2]="wr"
                self.board[0][0]=""
            if (self.selected_piece=="wk" and self.initial_col==3 and self.col_target==5):
                self.board[0][4]="wr"
                self.board[0][7]=""
            # Zresetuj zmienną selected_piece
            self.selected_piece = None
            self.selected_piece_position = None

            # Aktualizacja planszy
            self.update_board()
            self.update_idletasks() 
            if self.mode==1:
                self.engine_run()
          
    def engine_run(self):
        
        if(self.ruch==0):
            self.ruch+=1
            self.engine.stdin.flush()
            response = self.engine.stdout.readline()
            print("c " ,response)
            self.move(response)
        elif self.ruch !=0:
            st=self.send_to_script()
            print(st)
            self.engine.stdin.write(st)
            self.engine.stdin.flush()
         # Odczytanie odpowiedzi z silnika szachowego
            response = self.engine.stdout.readline()
            print("c ",response)
            self.move(response)
            
    def move(self, route):
        d={'a':7,'b':6,'c':5,'d':4,'e':3,'f':2,'g':1,'h':0}
        
        figura=self.board[int(route[1])-1][d[route[0]]]
        self.board[int(route[1])-1][d[route[0]]] = ""
       
        self.board[int(route[3])-1][d[route[2]]]=figura
        if (figura=="wk" and d[route[0]]==3 and d[route[2]]==1):
                self.board[0][2]="wr"
                self.board[0][0]=""
        if (figura=="wk" and d[route[0]]==3 and d[route[2]]==5):
                self.board[0][4]="wr"
                self.board[0][7]=""
        self.update_board()
    
    def send_to_script(self):
        d=['h','g','f','e','d','c','b','a']
        s=str(d[self.initial_col])+str(self.initial_row+1)+str(d[self.col_target])+str(self.row_target+1)+'\n'
        return s
            
            

