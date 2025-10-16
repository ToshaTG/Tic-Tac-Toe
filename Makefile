all: TicTacToe

TicTacToe: Board.o GameEngine.o Move.o Player.o ConsoleRenderer.o main.o
	g++ -o TicTacToe Board.o GameEngine.o Move.o Player.o ConsoleRenderer.o main.o

Board.o:
	g++ Board.cpp -o Board.o -c

GameEngine.o:
	g++ GameEngine.cpp -o GameEngine.o -c

Move.o:
	g++ Move.cpp -o Move.o -c

Player.o:
	g++ Player.cpp -o Player.o -c

ConsoleRenderer.o:
	g++ ConsoleRenderer.cpp -o ConsoleRenderer.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o TicTacToe TicTacToe.exe
