#include <iostream>
#include "Pilha.h"
#include "Labirinto.h"
// #include <chrono> // std::chrono::microseconds
// #include <thread> // std::this_thread::sleep_for

using namespace std;

Labirinto::Labirinto(const vector<string> &lab){
    labirinto = lab;
};

bool Labirinto::solve(int x, int y) {
    Pilha px, py;
    px.push(x);
    py.push(y);

    while(labirinto[x][y] != 'S' && !px.vazia() && !py.vazia()) {
        x = px.topo();
        y = py.topo();
        labirinto[x][y] = '*';

        // mostra o progresso da busca
        // PS: Em comentario pois para labirintos grandes e sem saida pode demorar demais 
        
        // showLab();
        // this_thread::sleep_for(chrono::milliseconds(10));
        // system("CLS");

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
        }
    }            
    cout << "SAIDA  (" << x << ", " << y << ") " << endl;
    return (!px.vazia() && !py.vazia());
};

bool Labirinto::availablePath(int x, int y) {
    return (x >= 0 && x < labirinto.size()
            && y >= 0 && y < labirinto[x].size()
            && (labirinto[x][y] == ' ' || labirinto[x][y] == 'S'));
};

void Labirinto::showLab(){
    for(int x = 0; x < labirinto.size(); ++x) {
        for(int y = 0; y < labirinto[x].size(); y++){
            if(labirinto[x][y] == '-'){
                cout << ' ';
                continue;
            } else {
                if(labirinto[x][y] == '*')
                    cout << "\033[41;1;37m*\033[0m"; // \033[41;1;37m Fundo Vermelho \033[0m
                else
                    cout << labirinto[x][y]; 
            }
            cout << endl;
        }
    }
};