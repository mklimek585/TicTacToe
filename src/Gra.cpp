#include "Gra.h"
#include <string>
using namespace std;

Gra::Gra(int var, int size) {
    bool flaga = true;
    UstawRozmiar(size);
    UstawWybor(var);
    char *tab = new char[size];
    for (int i = 0; i < size; i++) { tab[i] = Plansza;}
    WyswietlWstep(size);

    /// Gra PvP
    if (wybor == 2136) {
        while (flaga) {
            Gra::RuchGracza(tab,Player1);
            if (SprawdzWygrana(tab,Player1)) { cout << "___WYGRAŁ Player1 - X___ \n"; break; }
            if(Gra::SprawdzRemis(tab)) { cout << "REMIS!!!" << endl; break;};

            Gra::RuchGracza(tab,Player2);
            if (SprawdzWygrana(tab,Player2)) { cout << "___WYGRAŁ Player2 - O___ \n"; break;}
            if(Gra::SprawdzRemis(tab)) { cout << "REMIS!!!" << endl; break;};
        }
    }
    /// Gra PvAI
    else if (wybor == 2137) {
        while (flaga) {
            Gra::RuchGracza(tab,Player1);
            if (SprawdzWygrana(tab,Player1)) { cout << "___WYGRAŁ Player1 - X___ \n"; break; }
            if(Gra::SprawdzRemis(tab)) { cout << "REMIS!!!" << endl; break;};

            Gra::RuchAI(tab,Player2);
            if (SprawdzWygrana(tab,Player2)) { cout << "___WYGRAŁ Player2 - O___ \n"; break;}
            if(Gra::SprawdzRemis(tab)) { cout << "REMIS!!!" << endl; break;};
        }
    }
}

int Gra::UstawGre1() {
    char zmienna;
    int var;
    cout << "PvP - (p) czy PvAI - (a)" << endl;
    cin >> zmienna;
    switch(zmienna) {
        case 'p':
            var = 2136;
            break;
        case 'a':
            var = 2137;
            break;
    }
    return var;
}
int Gra::UstawGre2() {
    int rozmiar;
            cout << "Podaj rozmiar planszy: \n";
            cin >> rozmiar;
            cout << endl;
    return rozmiar;
}

void Gra::RuchGracza(char *tab, char x) { //TODO
    int var, k = 0;
    string nazwa_gracza;
    bool flaga = true;

    if (x == 'O') {
        nazwa_gracza = "Player2 - O";
        cout << "Ruch " << nazwa_gracza << "\n";
        while(flaga) {
            cout << "Podaj pole: ";
            cin >> var;
            if (var > 0 && var <= size) {
                if (tab[var-1] == 'X' || tab[var-1] == 'O') { // Sprawdza czy pole jest zajete
                    cout << "Podane pole jest zapisane \n";
                }
                else {
                    tab[var-1] = x;
                    cout << endl;
                    WyswietlPlansze(tab,size);
                    flaga = false;
                }
            }
            else {
                cout << "Podane pole wychodzi poza zakres planszy \n";
                k++;
                if (k == 3) break;
            }
        }
    }
    else if (x == 'X') {
        nazwa_gracza = "Player1 - X";
        cout << "Ruch " << nazwa_gracza << "\n";
        while(flaga) {
            cout << "Podaj pole: ";
            cin >> var;
            if (var > 0 && var <= size) {
                if (tab[var - 1] == 'X' || tab[var - 1] == 'O') { // Sprawdza czy pole jest zajete
                    cout << "Podane pole jest zapisane \n";
                }
                else {
                    tab[var - 1] = x;
                    cout << endl;
                    WyswietlPlansze(tab, size);
                    flaga = false;
                }
            }
            else {
                cout << "Podane pole wychodzi poza zakres planszy \n";
                k++;
                if (k == 3) break;
            }
        }
    }

}

void Gra::UstawRozmiar(int size) {
    this->size = size;
}
void Gra::UstawWybor(int var) {
    this->wybor = var;
}

bool Gra::SprawdzWygrana(char *tab, char x) {
    int licznik = 0;
    for (int j = 0; j < size; j += sqrt(size)) { // Szuka wygranych poziomych
        for (int i = j; i < sqrt(size) + j; i++) {
            if (tab[i] == x) {
                licznik++;
                if (licznik == sqrt(size)) { return true; }
            }
        }
        licznik = 0;
    }
    licznik = 0;
    for (int j = 0; j < sqrt(size); j++) { // Szuka wygranych pionowych
        for (int i = j; i < size; i += sqrt(size)) {
            if (tab[i] == x) {
                licznik++;
                if (licznik == sqrt(size)) { return true; }
            }
        }
        licznik = 0;
    }
    licznik = 0;

    for (int i = 0; i < size; i += sqrt(size)+1) { // Szuka wygranej po skosie w prawo
        if (tab[i] == x) {
            licznik++;
            if (licznik == sqrt(size)) { return true; }
        }
    }
    licznik = 0;

    for (int i = sqrt(size)-1; i < (size-sqrt(size)+1); i += sqrt(size)-1) { // Szuka wygranej po skosie w lewo
        if (tab[i] == x) {
            licznik++;
            if (licznik == sqrt(size)) { return true; }
        }
    }
    return false;
}

bool Gra::SprawdzRemis(char *tab) {
    int licznik = 0;
    for(int i = 0; i < size; i++) {
        if (tab[i] == 'X') { licznik++; } // cout << "Licznik inkrementowany przez X wynosi " << licznik << endl; }
        else if (tab[i] == 'O') { licznik++; } // cout << "Licznik inkrementowany przez O wynosi " << licznik << endl;}
    }
    if (licznik == size) { return true; }
    else { return false; }
}

bool Gra::CzyPowtorzony(char *tab, char x) { //TODO moze do AI?

    return false;
}

int Gra::MiniMax(char *tab, char x) { // Algorytm minimax
    {
        if (size >= 16) { cout << "\n Obliczam ruch komputera... \n"; }
        int ruch;
        int punkty = INT_MAX; // Ustawiam punkty na max

        for (int i = 0; i < size; i++) // Przechodze po calej tablicy
        {
                if (tab[i] == Plansza) // Sprawdzam czy pole nie jest już zajęte
                {
                    tab[i] = Player2; // Przypisuje ruch komputera
                                               // Sprawdza ścieżke rekurencyjnym wywoływaniem sie funkci SzukajMax, SzukajMin
                    int temp = SzukajMax(tab); // do znalezienia minimaxowego ruchu
                                               // Zapusuje punkty tej sciezki do zmiennej temp
                    if (temp < punkty) // Sprawdza czy nowe zwrócone punkty są mniejsze od poprzednich
                    {                  // Jeśli tak,
                        punkty = temp; // przypisuje ich wartość jako aktualne
                        ruch = i;      // Zapisuje ruch jako optymalny minimaxowy
                    }
                    tab[i] = Plansza;  // Przywraca plansze do stanu przed nadpisania
                }
            }
        return ruch; // Po wykonaniu petli zwracam ruch który zdobył największą liczbe punktów
    }
}

int Gra::SzukajMax(char *tab) { // Wchodzimy do funkcji z tablica z aktualnym polem gracza zgodnie z petla w funkcji glownej
    if (SprawdzWygrana(tab, Player1)) { return 10; }        //
    else if (SprawdzWygrana(tab,Player2)) { return -10; }   // Sprawdzam czy nie jestem na ostatnim ruchu
    else if (SprawdzRemis(tab)) { return 0; }                  //

    int punkty = INT_MIN; // Ustawiam punkty na min

    for (int i = 0; i < size; i++) // Przechodze po mozliwosciach ruchu gracza(komputera)
    {
        if (tab[i] == Plansza) // Sprawdzam czy pole jest puste
        {
            tab[i] = Player1;                     // Stawiamy znak gracza,
            punkty = max(punkty, SzukajMin(tab)); // po czym wyznaczamy jego wartość rekurencyjnym wywołaniem
            tab[i] = Plansza;                     // Przywraca plansze do pierwotnego stanu
        }
    }
    return punkty; // Zwraca punkty przypisane ruchowi
}

int Gra::SzukajMin(char *tab) { // Jak poprzednio wchodzimy do funkcji z tablica z aktualnym polem gracza zgodnie z petla w funkcji glownej
    if (SprawdzWygrana(tab, Player1)) { return 10; }        //
    else if (SprawdzWygrana(tab,Player2)) { return -10; }   // Sprawdzam czy nie jestem na ostatnim ruchu
    else if (SprawdzRemis(tab)) { return 0; }                  //

    int punkty = INT_MAX; // Ustawiam punkty na max

    for (int i = 0; i < size; i++) // Przechodze po mozliwosciach ruchu przeciwnika(człowieka)
    {
        if (tab[i] == Plansza) // Sprawdzam czy pole jest puste
        {
            tab[i] = Player2;                     // Stawiamy znak gracza,
            punkty = min(punkty, SzukajMax(tab)); // po czym wyznaczamy jego wartość rekurencyjnym wywołaniem
            tab[i] = Plansza;                     // Przywraca plansze do pierwotnego stanu
        }
    }
    return punkty; // Zwraca punkty
}

void Gra::RuchAI(char *tab, char x) {
    tab[MiniMax(tab,x)] = x;
    cout << endl;
    WyswietlPlansze(tab, size);
}

