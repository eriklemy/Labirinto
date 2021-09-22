#include "Pilha.h"
#include <iostream>

using namespace std;

// metodos
Pilha::Pilha(){
    topo_ = -1; // pilha vazia
}; // construtor: cria pilha vazia

void Pilha::push(TipoDado elemento){
    if(cheia())     // cerr -> mensagem de erro
        cerr << "Pilha cheia!" << endl; // STACKOVERFLOW
    else {
        ++topo_;    // aceitavel tbm topo_++;
        dados[topo_] = elemento; // nesse caso [++topo_] != [topo_++]
    }
};

void Pilha::pop(){
    if(vazia())
        cerr << "Pilha vazia!" << endl; // STACKOVERFLOW
    else
        --topo_;   // ++topo_ se inverter
};

TipoDado Pilha::topo(){
    if(!vazia())
        return dados[topo_];
    else {
        // cerr << "Pilha vazia!" << endl; // STACKOVERFLOW
        return 0; // obrigatorio retorno, nesse caso 0 para aviso de erro
    }
};

bool Pilha::vazia(){
    return (topo_ == -1); // se vazia 
};

bool Pilha::cheia(){
    return (topo_ == MAXPILHA - 1); // se cheia
};

int Pilha::size(){
    return dados.size();
};