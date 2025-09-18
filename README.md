# X și 0 (Tic-Tac-Toe)

**Autor:** Țîgîrlaș Antoanela

**Grupa:** DJ2401

## Descrierea jocului
X și 0 (Tic-Tac-Toe) este un joc pe o tablă 3×3 în care doi jucători, **X** și **O**, pe rând marchează câte o celulă liberă. Scopul este ca unul din jucători să alinieze 3 simboluri identice pe orizontală, verticală sau diagonală. Dacă toate cele 9 celule sunt ocupate și nu există o aliniere din partea oricăruia dintre jucători, jocul se termină la egalitate.

## Reguli de joc
1. Jocul se desfășoară pe o grilă 3×3.
2. Primul jucător folosește simbolul **X**, al doilea **O**.
3. Jucătorii fac mutări alternativ, câte o celulă liberă per tură.
4. Câștigă jucătorul care formează primul o linie de 3 simboluri identice (orizontal, vertical sau diagonal).
5. Dacă nu mai sunt mutări posibile și nu există linie de 3, rezultatul este **remiză**.

## Structuri de date (rol / sarcină)
`enum class Player`
 Reprezintă jucătorul curent. Poate avea valorile:
- None – celula este liberă.
- X – celula este ocupată de jucătorul X.
- O – celula este ocupată de jucătorul O.

`struct Move`
Reține coordonatele unei mutări (linie și coloană).

`class Board`
Reprezintă tabla de joc, modelată intern ca o matrice 3×3 de tip `Player`.
Expune operații de bază:
- inițializare/resetare;
- verifică dacă o celulă este liberă sau ocupată;
- aplicarea unei mutări;
- afișarea tablei (în consolă).

`class GameEngine`
Gestionează logica principală a jocului:
- reține jucătorul curent (X sau 0);
- verifică dacă mutările făcute sunt valide;
- schimbă tura pentru fiecare jucător după fiecare mutare;
- determină câștigătorul sau remiza;
- permite resetarea jocului și rularea buclei principale în consolă.
