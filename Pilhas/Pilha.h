#ifndef PILHA_H
#define PILHA_H
#include <array>

// cria uma constante
constexpr int MAXPILHA = 25;
using TipoDado = char; // equivalente a typedef

class Pilha {
    private:
        // atributos
        // TipoDado dados[MAXPILHA]; // normal
        std::array<TipoDado, MAXPILHA> dados; // cool mode
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