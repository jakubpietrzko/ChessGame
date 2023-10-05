#tworzenie srodowiska do gry w szachy  python

import chess
import chess.svg  
import random
import tkinter as tk
from PIL import Image, ImageTk

class ChessEnvironment:
    def __init__(self):
        self.board = chess.Board()
        self.current_player = chess.WHITE

    def reset(self):
        self.board = chess.Board()
        self.current_player = chess.WHITE

    def get_state(self):
        return str(self.board)

    def get_valid_moves(self):
        return list(self.board.legal_moves)

    def take_action(self, action):
        self.board.push(action)
        self.current_player = not self.current_player

    def is_game_over(self):
        return self.board.is_game_over()

    def get_reward(self):
        result = self.board.result()
        if result == "1-0":
            return 1.0
        elif result == "0-1":
            return -1.0
        else:
            return 0.0

    def render(self):
        print(self.board)
        
def render_board(board_svg):
    root = tk.Tk()
    root.title("Szachy")

       
    board_image = Image.open(io.BytesIO(board_svg.encode()))
    board_photo = ImageTk.PhotoImage(board_image)

    label = tk.Label(root, image=board_photo)
    label.pack()

        
    root.mainloop()

env = ChessEnvironment()

for _ in range(10):  
    state = env.get_state()
    valid_moves = env.get_valid_moves()

    
    action = random.choice(valid_moves)

    env.take_action(action)
    reward = env.get_reward()

    board_svg = chess.svg.board(board=env.board)
    render_board(board_svg)

    if env.is_game_over():
        print("Koniec gry!")
        break
