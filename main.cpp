/*
*  PEDA - PROGRAMAÇÃO COM ESTRUTURAS DE DADOS AVANÇADAS
*  PROJETO LABIRINTO USANDO PILHA
*  ALUNO: ERICK LEMMY DOS SANTOS OLIVEIRA
*  ENGENHARIA DE COMPUTAÇÃO
*/
#include <iostream>
#include "src/Labirinto.h"

using namespace std;

void start(){
	cout << "===================================" << endl;
	cout << "|         PROJETO - PEDA          |" << endl;
	cout << "|     LABIRINTO USANDO PILHA      |" << endl;
	cout << "|           PATH FINDER           |" << endl;
	cout << "| ERICK LEMMY DOS SANTOS OLIVEIRA |" << endl;
	cout << "===================================" << endl;
}

int main(){
    int entradaX = 10;
    int entradaY = 0;
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
    
    start();
    
    cout << "ENTRADA (" << entradaX << ", " << entradaY << ")"<< endl;
    if(labirinto.solve(entradaX, entradaY)) {         
      	labirinto.showLab();
        cout << "\033[1;31mCAMINHO ENCONTRADO!!!\033[0m" << endl; // \033[1;31m Letra em Vermelho \033[0m
    } else 
        cout << "NENHUM CAMINHO ENCONTRADO!!" << endl;
}