#ifndef TICTACTOE_GRA_H
#define TICTACTOE_GRA_H
#include "Scena.h"

//bool init_game(); //TODO
//void Gra(); //TODO
//Funkcja blokujaca nadpisywanie TODO

struct {
    int var;     // Wybor PvP, PvAI
    int rozmiar; // Wybor rozmiaru
} Para;

class Gra {
    char Player1 ='X', Player2 = 'O', Plansza = ' ';
    int size;
    int wybor;
public:
    bool SprawdzWygrana(char *tab, char x);
    bool SprawdzRemis(char *tab);
    void UstawRozmiar(int size);
    void UstawWybor(int var);
    static int UstawGre1();
    static int UstawGre2();
    Gra(int var, int size);
    void RuchGracza(char *tab, char x);
    void RuchAI(char *tab, char x);
    int MiniMax(char *tab, char x);
    int SzukajMin(char *tab);
    int SzukajMax(char *tab);
    bool CzyPowtorzony(char *tab, char x);
};

#endif //TICTACTOE_GRA_H
