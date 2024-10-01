#ifndef MAPA_H
#define MAPA_H

#include "Mochila.h"
#include "Cinto.h"
#include "Elementos.h"
#include "Heroi.h"
#include "Inimigos.h"

class Mapa{
    public:
    int sqm[50];  // Array que representa as posições do mapa;
    Mapa();// construtor do mapa;
    void sqmVazio(Heroi &heroi); // Manipular elementos, poderá retirar/usar elementos 
    void sqmElemento(Heroi &heroi,int indiceElemento); // Precisa interagir com usuario se quer pegar o elemento
    bool sqmInimigo(Heroi &heroi, Inimigos &inimigo); // Realiza a batalha com o inimigo;
    int posicaoAtual(); // Indica a posicao atual no mapa;
    
    void adicionarSQMsElemento(int inicio, int quantidade); // Adiciona um numero de SQMs com elementos;
    void adicionarSQMVazio(int posicao); // Adiciona um SQM vazio em uma posicao especifica;
    void adicionarSQMInimigo(int posicao, bool ehboss); // Adiciona um SQM com inimigo em uma posicao especifica;
    void adicionarSQMfinal();  // Adiciona um SQM final ao mapa;

    void gameover(); // Método para gameover
    
    private:
    int nivel;  // Nivel atual do mapa;
    int posicao = 0; // Posicao atual do heroi no mapa;
    Elementos::Elemento x; // Elemento temporario para manipulacao;
};

#endif