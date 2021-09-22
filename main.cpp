#include <iostream>
#include <string>
#include <vector>
#include "Pilhas/Pilha.h"

using namespace std;

class Labirinto {
    private:
        vector<string> labirinto;
    public:
        Labirinto(vector<string> lab)
            :labirinto(lab){ } // CONSTRUTOR

        bool solve(int x, int y) {
            if (labirinto[x][y] == 'S'){
                labirinto[x][y] = '*';
                cout << "Saida   (" << x << ", " << y << ") " << endl;
                return true; // saida encontrada
            } 
                
            // marca o caminho
            labirinto[x][y] = '*';
            
            // checa as direções - se retornar true é pq encontrou um caminho
            if (available(x - 1, y) && solve(x - 1, y)) // para cima
                return true; //  px.push() py.push()
            if (available(x + 1, y) && solve(x + 1, y)) // para baixo
                return true;
            if (available(x, y - 1) && solve(x, y - 1)) // para esquerda
                 return true;
            if (available(x, y + 1) && solve(x, y + 1)) // para direita
				return true;

            // se nenhum caminho for encontrado retorna falso
            // remarca a passagem que n leva a saida
            labirinto[x][y] = ' ';
            return false;
        }

        bool available(int x, int y) {
            return (x >= 0 && x < labirinto.size()
                 && y >= 0 && y < labirinto[x].size()
                 && (labirinto[x][y] == ' ' || labirinto[x][y] == 'S'));
        }

        void showLab(){
            for(int x = 0; x < labirinto.size(); ++x) {
                for(int y = 0; y < labirinto[x].size(); y++)
                    cout << labirinto[x][y];
                cout << endl;
            }
        }

        auto getLabSize() { return labirinto; }
};

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
      	lab.showLab();
        cout << "CAMINHO ENCONTRADO!!" << endl;
    } else cout << "NENHUM CAMINHO ENCONTRADO!!" << endl;
}

/*
A estrutura de dados PILHA pode ser usada para implementar isso.
A ideia é partir de um ponto E ("entrada") e escolher arbitrariamente uma das suas conexões para a 
busca do ponto S ("saída"), armazenando o novo ponto a que se chegou na pilha. 
Assim, prossegue-se até que não seja mais possível partir para um novo caminho ou até que o ponto S 
seja atingido. No primeiro caso, deve-se retornar a um ponto anterior a partir do qual novos caminhos 
podem ser possíveis. Isto é feito retirando-se o último elemento da pilha. 
Este procedimento é repetido até voltar a um ponto a partir do qual caminhos não explorados podem ser 
tentados ou até voltar ao início (ponto E).
Nesse caso, se não hover mais outras opções de caminho saindo de E, é porque S não existe.


calcule e mostre na tela o caminho de "E" a "S" (marcando o caminho com asteriscos
O caractere "X" na matriz labirinto corresponde a uma "parede". 
Assim, se labirinto[x][y] == 'X' (0≤x<20 e 0≤y<21), então esta posição não deve ser percorrida.
*/