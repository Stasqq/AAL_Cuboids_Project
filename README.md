# Cuboids project

Treść polecenia:

Dany jest zbiór prostopadłościanów {a1, … , an} oraz obszar
prostopadłościenny o zadanych dwóch bokach nie mniejszych od
największego z boków prostopadłościanów w zbiorze. Należy wyznaczyć,
stosując różne metody heurystyczne, a także przeszukiwanie
systematyczne, najmniejszą długość trzeciego boku obszaru pozwalającą na
rozmieszczenie ortogonalne bez kolizji zbioru w obszarze. Porównać czas
obliczeń i wyniki różnych metod.


## Struktura projektu

### Część obliczeniowa

Zaimplementowana w języku C++, odpowiedzialna jest za wykonanie obliczeń.

Dostępne są 4 algorytmy:

BruteForce - algorytm siłowy, dla wszystkich permutacji wejsciowych prostopadloscianow oblicza on wysokość przestrzeni, następnie
jak wynik obliczeń wybiera najlepsze znalezione rozwiązanie. Każdy kolejny prostopadłościan zostaje umieszczony w możliwie 
najniższe miejsce, dosunięte do osi OY.

SingleTower - algorytm ustawiający prostopadłościany "jeden na drugim", tworzy w ten sposób wieżę w rogu przestrzeni.

FourTowers - algorytm ustawiający prostopadłościany "jeden na drugim", ale w odróżnieniu od SingleTower tworzy on czrety wieże, po jednej w każdym rogu przestrzeni. Każdy kolejny prostopadłościan zostaje dodawany do możliwie najniższej wieży.

Searching - algorytm sortuje prostopadłościany od największego(największa objętość) do najmniejszego. Następnie każdy kolejny 
prostopadłościan zostaje umieszczony w możliwie najniższe miejsce, dosunięte do osi OY (algorytm umieszczania prostopadłościanu taki sam ja w przypadku algorytmu siłowego)

### Część prezentacyjna

Zaimplementowana w języku Java, z wykorzystaniem technologii JavaFX. Odpowiedzialna jest za graficzną prezentację obliczonego wcześniej rozwiązania.

## Instalacja

Projekt działa w systemach Windows oraz Linux.

W obu z nich instalacja przebiega tak samo.

Podane komendy należy wykonywać będąc w głównym katalogu projektu.

### Część obliczeniowa

Do instalacji części obliczeniowej potrzebny jest program make oraz kompilator g++.

Aby skompilować program należy wywołać komendę:
```bash
make
```
Wynikiem poprawnej kompilacji będzie aplikacja o nazwie: cuboids_AAL

Dla systemu Linux dostępna jest komenda:
```bash
make clean
```
Wywołanie jej pod kontrolą systemu Windows nie powiedzie się.

### Część prezentacyjna

Do instalacji części prezentacyjnej potrzebne jest Java JDK, dodatkowo w zależności od wersji JDK może być niezbędne także JavaFX SDK.

Aby skompilować program należy wywołać komendę:
```bash
javac java_src/*.java -d .
```
Wynikiem poprawnej kompilacji będą skompilowane klasy Java.

## Uruchomienie

### Część obliczeniowa

Generalna struktura wywołania programu:
```bash
cuboids_AAL   wybrany_algorytm   tryb_programu   <dalsze parametry danego trybu>
```
wybrany_algorytm:

    bf - BruteForce

    st - SingleTower

    ft - FourTowers

    sa - SearchingAlgorithm

tryb_programu:
    
    f - odczyt z pliku, zapis do pliku
    
    g - generator danych
    
    p - przeprowadzenie i prezentacja pomiarów

#### Tryb odczyt z pliku, zapis do pliku

Dane wejściowe pobierane są z pliku wejściowego, a wynik obliczeń zapisywany jest do pliku wyjściowego.

Wywołanie programu:
```bash
cuboids_AAL   wybrany_algorytm   f   plik_wejściowy   plik_wyjściowy
```

Przykladowe wywołanie:
```bash
cuboids_AAL bf f wejscie.txt wyjscie.txt
```
Algorytm BruteForce, odczyt z pilku wejscie.txt, zapis do pliku wyjscie.txt
#### Tryb generatora danych

Dane wejściowe generowane są przez generator(generowana przestrzeń ma wymiary X, Y od 20 do 100), a wynik obliczeń zapisywany jest do pliku wyjściowego.

Wywołanie programu:
```bash
cuboids_AAL   wybrany_algorytm   g   ilość_prostopadłościanów   zakres_stosunku_długości_prostopadłościanów   plik_wyjściowy
```
ilość_prostopadłościanów - ile prostopadłościanów ma wygenerować generator

zakres_stosunek_długości_prostopadłościanów - wartość od 0.01 do 1.0, szerokość zakresu, z którego program generuje 
długości boków prostopadłościanów w stosunku do wielkości wygenerowanej przestrzeni przestrzeni.

Np.:

Dla wartości 0.5 program będzie generował długości boków prostowadłościanów z zakresu od 0.25 do 0.75 wartości długości krótszego boku 
przestrzeni.

Dla wartości 0.8(zakres 0.1 - 0.9) i krótszego boku przestrzeni 100 program będzie genrował prostopadłościany z bokami od 10 do 90.

Dla wartości 1 będzie generował dowolne prostopadłościany spełnijące warunki zadania.


Przykladowe wywołanie:
```bash
cuboids_AAL st g 20 0.6 wyjscie.txt
```
Algorytm SingleTower, 20 prostopadłościanów, stosunek 0.6, zapis do pliku wyjscie.txt

#### Tryb generatora danych z podaną wielkości X,Y przestrzeni

Dane wejściowe generowane są przez generator z narzuconą wielkością X, Y przestrzeni (wygenerowana przestrzeń będzie kwadratem), a wynik 
obliczeń zapisywany jest do pliku wyjściowego.
Wywołanie programu:
```bash
cuboids_AAL   wybrany_algorytm   g   ilość_prostopadłościanów   zakres_stosunku_długości_prostopadłościanów   wielkość_przestrzeni  plik_wyjściowy 
```

wielkość_przestrzeni - wymiar X i Y podstawy przestrzeni


Przykladowe wywołanie:
```bash
cuboids_AAL ft g 20 0.6 20 wyjscie.txt
```
Algorytm FoutTower, 20 prostopadłościanów, stosunek 0.6, wymiary podstawy przestzeni 20x20, zapis do pliku wyjscie.txt
#### Tryb przeprowadzenia i prezentacji pomiarów

Wykonanie pomiarów wykonuje wielokrotnie wybrany algorytm, dane wejściowe generowane są przez generator. Po dokonaniu pomiarów 
wyświetlana jest tabela średnich czasów wykonania dla zadanych wielkości problemów oraz porównanie z teoretyczną złożonością obliczeniową.
Wywołanie programu:
```bash
cuboids_AAL   wybrany_algorytm   p   zakres_stosunku_długości_prostopadłościanów   wielkość_przestrzeni  ilość_prostopadłościanów   przyrost_co_krok   ilość_kroków    ilość_rozwiązanych_problemów_na_krok
```
przyrost_co_krok - o ile zwiększyć liczbę prostopadłościanów w każdym kolejnym kroku

ilość_kroków - ile kroków wykonać

ilość_rozwiązanych_problemów_na_krok - ile razy wykonać algorytm podczas jednego kroku

Przykladowe wywołanie:
```bash
cuboids_AAL sa p 0.6 20 15 10 5
```
Algorytm Searching, stosunek 0.6, wymiary podstawy przestzeni 20x20, 15 prostopadłościanów na start, 10 prostopadłościanów więcej co krok, 5 rozwiązanych problemów na krok
### Część prezentacyjna

Aby uruchomić część prezentacyjną należy wywołać komendę:
```bash
java Main
```
Wywołanie to otworzy okno dialogowe, gdzie należy podać nazwę lub ścieżkę pliku(z rozszerzeniem), którego dane chcemy zaprezentować.

Po wpisaniu nazwy należy kliknąć widoczny przycisk "Załaduj dane" albo na klawiaturze przycisk "Enter"

Jeśli nazwa pliku była poprawna pojawi się nowe okno dialogowe, w którym wyświetlone będą podstawowe informacje o załadowanym rozwiązaniu.

Aby wyświetlić graficzną reprezentację rozwiązania należy wybrać Tryb widoku (Poziomo - widok przekroju poprzecznego, Pionowo - widok przekroju pionowego), tryb ten można potem zmieniać.
Następnie korzystając z suwaka i miejsca do wpisywania można wybierać numer wyświetlanego przekroju.


## Struktura plików
### Plik wejsciowy części obliczeniowej
```txt
Wymiar_x_przestrzeni Wymiar_y_przestrzeni
X_p1 Y_p1 Z_p1
X_p2 Y_p2 Z_p2
...
```
p1, p2 są to kolejne prostopadłościany.

X, Y, Z to wymiary prostopadłościanu.

Przykładowy plik znajduje się w repozytorium.
### Plik wyjsciowy części obliczeniowe oraz wejściowy części prezentacyjnej
```txt
Czas_wykonania_w_ms
Wymiar_x_przestrzeni Wymiar_y_przestrzeni Wymiar_z_przestrzeni
X_p1 Y_p1 Z_p1 pozycja_x_p1 pozycja_y_p1 pozycja_z_p1
X_p2 Y_p2 Z_p2 pozycja_x_p2 pozycja_y_p2 pozycja_z_p2
...
```
p1, p2 są to kolejne prostopadłościany.

X, Y, Z to wymiary prostopadłościanu.

Pozycja oznacza położenie według danej osi współrzędnych.

Przykładowy plik znajduje się w repozytorium.
