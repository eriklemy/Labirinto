#include "Pilha.h"
#include "Labirinto.h"
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for
#include <iostream>

using namespace std;

Labirinto::Labirinto(vector<string> lab){
    labirinto = lab;
};

bool Labirinto::solve(int x, int y) {
    Pilha px, py;
    px.push(x);
    py.push(y);

    while(labirinto[x][y] != 'S' && !px.vazia() && !py.vazia()) {
        cout << "-----   (" << x << ", " << y << ") " << endl;
        x = px.topo();
        y = py.topo();
        labirinto[x][y] = '*';

        showLab();
        this_thread::sleep_for(chrono::milliseconds(10));
        system("CLS");

        if(labirinto[x][y + 1] != 'X' && available(x, y + 1)) { // direita
            px.push(x);
            py.push(y + 1);
            y++;
        }
        else if(labirinto[x + 1][y] != 'X' && available(x + 1, y)) { // baixo
            px.push(x + 1);
            py.push(y);
            x++;
        }
        else if(labirinto[x][y - 1] != 'X' && available(x, y - 1)) { // esquerda
            px.push(x);
            py.push(y - 1);
            y--;
        }
        else if(labirinto[x - 1][y] != 'X' && available(x - 1, y)) { // cima
            px.push(x - 1);
            py.push(y);
            x--;
        } else {
            px.pop();
            py.pop();
            labirinto[x][y] = '-';
            cout << "Saida   (" << px.topo() << ", " << py.topo() << ") " << endl;

        }
    }            
    if(px.vazia() && py.vazia())
        return false;
    cout << "SAIDA  (" << x << ", " << y << ") " << endl;
    return true;
};

bool Labirinto::available(int x, int y) {
    return (x >= 0 && x < labirinto.size()
            && y >= 0 && y < labirinto[x].size()
            && (labirinto[x][y] == ' ' || labirinto[x][y] == 'S'));
};

void Labirinto::showLab(){
    for(int x = 0; x < labirinto.size(); ++x) {
        for(int y = 0; y < labirinto[x].size(); y++)
            if(labirinto[x][y] == '-'){
                cout << ' ';
                continue;
            } else {
                if(labirinto[x][y] == '*')
                    cout << "\033[1;31m*\033[0m";
                else
                    cout << labirinto[x][y]; 
            }
            cout << endl;
        }
};