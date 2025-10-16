# Tic-Tac-Toe – lab03

## Ce s-a adăugat în lab03
- **Move**: ctor implicit, ctor cu parametri, copiere, `operator=`, `operator==/!=/<`, I/O (`<<`, `>>`).
- **Board**: ctor implicit, ctor cu parametru (umple tabla), copiere, `operator=`,
  `operator==/!=`, I/O (`<<`, `>>`), metode const-correct.
- **Player**: operatori I/O (`<<`, `>>`).
- **Renderer**: clasă de bază **abstractă** (`Renderer`) și implementare `ConsoleRenderer`.

## Compilare (exemple)
### Un fișier -> obiect (cerință laborator)
g++ Move.cpp -o Move.o -c

### Build complet (Makefile)
make clean
make

### Rulare
./TicTacToe
# Introdu mutări ca perechi "r c" (0..2) sau `q` pentru a ieși.
