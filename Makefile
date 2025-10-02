all: TicTacToe

TicTacToe: Board.o GameEngine.o main.o
	g++ -o TicTacToe Board.o GameEngine.o main.o

Board.o:
	g++ Board.cpp -o Board.o -c

GameEngine.o:
	g++ GameEngine.cpp -o GameEngine.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o TicTacToe TicTacToe.exe
