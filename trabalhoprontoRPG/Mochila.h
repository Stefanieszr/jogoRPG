#ifndef MOCHILA_H
#define MOCHILA_H

#include "Elementos.h"

class Mochila {
public:
    Mochila(); // Construtor da mochila;
    ~Mochila(); // Destrutor da mochila;
    bool Empty(); // Verifica se a mochila esta vazia;
    bool Push(int indiceElemento); // Adiciona elementos do tipo "Elemento" na mochila;
    bool Pop(Elementos::Elemento& x); // Retira elementos da mochila com limitacao de peso;
    int Size(); // Retorna o tamanho da estrutura da mochila;
    void Top(Elementos::Elemento& x); // Indica o elemento que esta no topo da mochila;
    void ExibirTop(); // Exibe o elemento que esta no topo da mochila;

private:
    struct mochilaNode { // Estrutura do nodo da mochila;
        Elementos::Elemento entry; // Entrada do elemento;
        mochilaNode* nextNode; // Proximo nodo na lista;
    };
    typedef mochilaNode* mochilaPointer; // Tipo de ponteiro para o nodo da mochila;
    mochilaPointer top; // Ponteiro para o topo da mochila;
    Elementos::Elemento x; // Elemento temporario para manipulacao;
};

#endif