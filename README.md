# X și 0 (Tic-Tac-Toe)

**Autor:** Țîgîrlaș Antoanela  
**Grupa:** DJ2401  

---

## Descrierea jocului
X și 0 (Tic-Tac-Toe) este un joc clasic pe o tablă 3×3 în care doi jucători, **X** și **O**, marchează alternativ câte o celulă liberă.  
Scopul este ca unul dintre jucători să alinieze 3 simboluri identice pe orizontală, verticală sau diagonală.  
Dacă toate cele 9 celule sunt ocupate și niciun jucător nu a reușit o aliniere, jocul se termină la egalitate.

---

## Reguli de joc
1. Jocul se desfășoară pe o grilă 3×3.  
2. Primul jucător folosește simbolul **X**, al doilea **O**.  
3. Jucătorii efectuează mutări alternativ, câte o celulă liberă per tură.  
4. Câștigă jucătorul care formează primul o linie de 3 simboluri identice (orizontal, vertical sau diagonal).  
5. Dacă nu mai sunt mutări posibile și nu există o linie de 3 simboluri identice, rezultatul este **remiză**.

---

## Structuri de date (rol / sarcină)
### `enum class Player`
Reprezintă jucătorul curent.  
Valori posibile:
- `None` – celula este liberă  
- `X` – jucătorul X  
- `O` – jucătorul O  

### `struct Move`
Reține coordonatele unei mutări (rând, coloană), valori între 0 și 2.  

### `class Board`
Reprezintă tabla de joc 3×3, stocată intern ca matrice de tip `Player`.  
Metode:
- `Reset()` – inițializează tabla cu celule libere  
- `InBounds()` – verifică dacă o poziție e validă  
- `IsEmpty()` – verifică dacă o celulă e liberă  
- `Place()` – plasează simbolul jucătorului curent  
- `IsFull()` – verifică dacă tabla e complet ocupată  

### `class GameEngine`
Gestionează logica jocului:
- determină jucătorul curent  
- aplică mutările  
- verifică starea jocului (victorie / remiză)  
- gestionează bucla principală și afișarea rezultatului  


