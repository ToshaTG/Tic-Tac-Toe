# X și 0 (Tic-Tac-Toe)

**Autor:** Țîgîrlaș Antoanela (Tosha)  
**Grupa:** DJ2401

## Descrierea jocului
X și 0 (Tic-Tac-Toe) este un joc pe o tablă 3×3 în care doi jucători, **X** și **O**, mută pe rând marcând câte o celulă liberă. Scopul este să aliniază 3 simboluri identice pe orizontală, verticală sau diagonală. Dacă toate cele 9 celule sunt ocupate și nu există o aliniere, jocul se termină la egalitate.

## Reguli de joc
1. Jocul se desfășoară pe o grilă 3×3.
2. Primul jucător folosește simbolul **X**, al doilea **O**.
3. Jucătorii fac mutări alternativ, câte o celulă liberă per tură.
4. Câștigă jucătorul care formează primul o linie de 3 simboluri identice (orizontal, vertical sau diagonal).
5. Dacă nu mai sunt mutări posibile și nu există linie de 3, rezultatul este **remiză**.

## Structuri de date (rol / sarcină)
- `enum class Player`: reprezintă jucătorul curent (**None**, **X**, **O**).
- `struct Move`: reține coordonatele unei mutări (`row`, `col`), valori 0..2.
- `class Board`:
  - Reprezintă tabla 3×3, stocată intern ca matrice de `Player`.
  - Expune operații de inițializare, verificare celulă liberă, aplicare mutare și afișare.
- `class GameEngine`:
  - Gestionează logica jocului: jucător curent, mutări valide, verificarea victoriei/egalității, resetarea jocului și bucla principală în consolă.
