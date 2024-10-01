#ifndef CINTO_H
#define CINTO_H

#include "Elementos.h"

// Classe que representa um cinto que armazena elementos;
class Cinto {
public:
    
    Cinto(); // Construtor da classe Cinto;
    bool Empty(); // Verifica se o cinto esta vazio;
    bool Full(); // Verifica se o cinto esta cheio;
    bool Insert(int y, int indiceElemento); // Insere um elemento na posicao y do cinto, dado o indice do vetor de elementos;
    bool Delete(Elementos::Elemento& x, int y); // Remove um elemento do cinto na posicao y e armazena em x;
    bool Replace(int indice, int y); // Substitui um elemento do cinto por outro;
    void Retrieve(Elementos::Elemento& x, int y); // Recupera um elemento do cinto e o armazena em x na posicao y;
    void exibirElementos(); // Exibe todos os elementos contidos no cinto;
    int getCount(); // Retorna a quantidade de elementos no cinto;
    int getPeso(); // Retorna o peso total dos elementos no cinto;

private:
    static const int maxItens = 3; // Quantidade maxima de itens no cinto;
    Elementos::Elemento cinto[maxItens + 1]; // Array que armazena os elementos no cinto;
    int pesoCinto; // Peso total atual do cinto;
    int count; // Quantidade atual de elementos no cinto;
    Elementos::Elemento x; // Elemento auxiliar para operacoes;
};

#endif