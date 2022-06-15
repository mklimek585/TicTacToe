#include "Scena.h"
using namespace std;

void MenuPoczatkowe() { //TODO
cout << "___ K Ó Ł K O   I   K R Z Y Ż Y K ___" << endl;
cout << "By rozpocząć gre wciśnij przycisk:" << endl;
cout << "By zakończyć wciśnij z:" << endl;
}


void WyswietlPlansze(char *tab, int size) {
    int k = 0;
    int pierwiastek = sqrt(size);

    for (int j = 0; j < pierwiastek; j++) {
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) break;
            cout << "     |";
        }
        cout << endl;

        k = pierwiastek*j;
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) {
                cout << "  " << tab[k] << endl;
                break;
            }
            cout << "  " << tab[k] << "  |";
            k++;
        }

        if ((j+1) == pierwiastek) {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {
                    cout << "     " << endl;
                    break;
                }
                cout << "     |";
            }
        }
        else {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {
                    cout << "_____" << endl;
                    break;
                }
                cout << "_____|";
            }
        }
    }
}

void WyswietlWstep(int size) {
    int tab[size], k = 0;
    int pierwiastek = sqrt(size);
    for (int i = 0; i < size; i++) { // Wypełniam tablice od 1 do size by oznaczyc pola
        tab[i] = i+1;
    }
    cout << "Tak wygląda plansza do gry: \n";
    for (int j = 0; j < pierwiastek; j++) {
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) break;
            cout << "     |";
        }
        cout << endl;

        k = pierwiastek*j;
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) {
                if (k >= 99) { cout << " " << tab[k] << endl; }
                else { cout << "  " << tab[k] << endl; }

                break;
            }
            if (k >= 9) { // By nie było przesuniete po 10
                if (k >= 99) { cout << " " << tab[k] << " |"; } // By nie było przesuniete po 100
                else { cout << "  " << tab[k] << " |"; } // Po 10 do 99
            }
            else { cout << "  " << tab[k] << "  |"; } // Do 10
            k++;
        }

        if ((j+1) == pierwiastek) {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {
                    cout << "     " << endl;
                    break;
                }
                cout << "     |";
            }
        }
        else {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {
                    cout << "_____" << endl;
                    break;
                }
                cout << "_____|";
            }
        }
    }
    cout << "Podaj indeks pola wybranego pola by postawić znak \n\n";
}

void WyswietlWstep3x3() {
    int tab[9] = {1,2,3,4,5,6,7,8,9};
    cout << "     |     |     " << endl;
    cout << "  " << tab[0] << "  |  " << tab[1] << "  |  " << tab[2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tab[3] << "  |  " << tab[4] << "  |  " << tab[5] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tab[6] << "  |  " << tab[7] << "  |  " << tab[8] << endl;

    cout << "     |     |     " << endl << endl;
}

void WyswietlPlansze3x3(char *tab) {
    cout << "     |     |     " << endl;
    cout << "  " << tab[0] << "  |  " << tab[1] << "  |  " << tab[2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tab[3] << "  |  " << tab[4] << "  |  " << tab[5] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tab[6] << "  |  " << tab[7] << "  |  " << tab[8] << endl;

    cout << "     |     |     " << endl << endl;
}


