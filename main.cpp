#include "Pilhas/Pilha.h"
#include "Labirinto.h"
#include "Labirinto.cpp"

int main(){
    Labirinto lab({
                    "XXXXXXXXXXXXXXXXXXXXX",
                    "X     X     X     X X",
                    "XX XX XXXXX X X X   X",
                    "X   X       XXX XXX X",
                    "X X X XXXXXXX   X   X",
                    "X X   X   X X X   X X",
                    "X XXXXX X X   XXXXX X",
                    "X X     X XXX  X    X",
                    "X X X X X   XX XX XXX",
                    "X X XXX X X     X   X",
                    "E X X X X XXXXX XXX X",
                    "X     X X   X X X   X",
                    "X XXXXX XXX X XXX X X",
                    "X X       X X   X X X",
                    "X   XXX X X XXX X X X",
                    "XXX X X X X X X X XXX",
                    "X X   X X   X   X   X",
                    "X XXX XXXXXXXXX XXX X",
                    "X                 X X",
                    "XXXXXXXXXXXXXXXXXXXSX"
                });

    cout << "Entrada (10, 0) " << endl;
    if(lab.solve(10, 0)) { //  funciona
        cout << "CAMINHO ENCONTRADO!!" << endl;
      	lab.showLab();
    } else cout << "NENHUM CAMINHO ENCONTRADO!!" << endl;
}
