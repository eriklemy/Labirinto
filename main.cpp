#include "src/Labirinto.h"
#include "src/Labirinto.cpp"

void Start(){
	cout << "===================================" << endl;
	cout << "|         PROJETO LABIRINTO       |" << endl;
	cout << "|            PATH FINDER          |" << endl;
	cout << "| ERICK LEMMY DOS SANTOS OLIVEIRA |" << endl;
	cout << "===================================" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
}

int main(){
    Labirinto labirinto({
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
    Start();
    cout << "\033[1;31m	ENTRADA (10, 0)\033[0m" << endl;
    if(labirinto.solve(10, 0)) {         
      	labirinto.showLab();
        cout << "\033[1;31mCAMINHO ENCONTRADO!!\033[0m" << endl;
    } else 
        cout << "NENHUM CAMINHO ENCONTRADO!!" << endl;
}