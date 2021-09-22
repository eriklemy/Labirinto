#ifndef PILHA_H
#define PILHA_H
#include <array>

// cria uma constante
constexpr int MAXPILHA = 100;
using TipoDado = char; 

class Pilha {
    private:
        // atributos
        std::array<TipoDado, MAXPILHA> dados;
        int topo_;
        
    public:
        // metodos
        Pilha(); // construtor: cria pilha vazia
        void push(TipoDado elemento);
        void pop();
        TipoDado topo();
        bool vazia();
        bool cheia();
        int size();
};

#endif //  !PILHA_H