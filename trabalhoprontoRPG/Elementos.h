#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
using namespace std;


// Classe que representa elementos como armas e pocao;
class Elementos {
public:
    Elementos(); // Construtor da classe Elementos;
    struct Elemento { // Estrutura que define um elemento;
        string nome; // Nome do elemento;
        string tipo; // Tipo do elemento;
        int peso_g; // Peso do elemento em gramas;
        int capacidade; // Capacidade do elemento;
    };
    
    void exibirElemento(int p); // Exibe as informacoes de um elemento dado o indice;
    Elemento getElemento(int index);// Retorna o elemento no indice especificado;

private:
    Elemento elemento[6]; // Array de elementos;
};

#endif