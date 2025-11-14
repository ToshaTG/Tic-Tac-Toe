# ---------- Setări de bază ----------
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET   = TicTacToe

# Folosim alt prefix pentru rețete, ca să nu fim obligați la TAB
.RECIPEPREFIX = >

# ---------- Ținta implicită ----------
all: $(TARGET)

# ---------- Linkarea executabilului cu bibliotecile ----------
$(TARGET): libboard.a libmove.a libplayer.a GameEngine.o ConsoleRenderer.o main.o
> $(CXX) $(CXXFLAGS) GameEngine.o ConsoleRenderer.o main.o libboard.a libmove.a libplayer.a -o $(TARGET)

# ---------- Biblioteci statice ----------
libboard.a: Board.o
> ar rcs libboard.a Board.o

libmove.a: Move.o
> ar rcs libmove.a Move.o

libplayer.a: Player.o
> ar rcs libplayer.a Player.o

# ---------- Obiecte pentru clasele de date ----------
Board.o: Board.cpp Board.hpp
> $(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Move.o: Move.cpp Move.hpp
> $(CXX) $(CXXFLAGS) -c Move.cpp -o Move.o

Player.o: Player.cpp Player.hpp
> $(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o

# ---------- Obiecte pentru clasele de aplicație ----------
GameEngine.o: GameEngine.cpp GameEngine.hpp
> $(CXX) $(CXXFLAGS) -c GameEngine.cpp -o GameEngine.o

ConsoleRenderer.o: ConsoleRenderer.cpp ConsoleRenderer.hpp
> $(CXX) $(CXXFLAGS) -c ConsoleRenderer.cpp -o ConsoleRenderer.o

# ---------- Obiect pentru main ----------
main.o: main.cpp
> $(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# ---------- Curățare ----------
clean:
> rm -f *.o *.a $(TARGET)

.PHONY: all clean
