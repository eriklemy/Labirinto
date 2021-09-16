#include "Labirinto.h"
#include <iostream>
using namespace std;

bool Labirinto::solve(int x, int y) {
    if (labirinto[x][y] == 'S'){
        labirinto[x][y] = '*';
        cout << "Saida   (" << x << ", " << y << ") " << endl;
        return true; // saida encontrada
    } 
    
    // marca o caminho
    labirinto[x][y] = '*';
    
    // checa as direções - se retornar true é pq encontrou um caminho
    if (available(x - 1, y) && solve(x - 1, y)) // para direita
        return true;
    if (available(x + 1, y) && solve(x + 1, y)) // para esquerda
        return true;
    if (available(x, y - 1) && solve(x, y - 1)) // para cima
            return true;
    if (available(x, y + 1) && solve(x, y + 1)) // para baixo
        return true;

    // se nenhum caminho for encontrado retorna falso
    // remarca a passagem que n leva a saida
    labirinto[x][y] = ' ';
    return false;
}

bool Labirinto::available(int x, int y) {
    return (x >= 0 && x < labirinto.size()
            && y >= 0 && y < labirinto[x].size()
            && (labirinto[x][y] == ' ' || labirinto[x][y] == 'S'));
}

void Labirinto::showLab(){
    for(int x = 0; x <= labirinto.size(); ++x) {
        for(int y = 0; y <= labirinto[x].size(); y++)
            cout << labirinto[x][y];
        cout << endl;
    }
}