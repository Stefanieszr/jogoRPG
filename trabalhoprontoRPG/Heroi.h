#ifndef HEROI_H
#define HEROI_H

#include "Mochila.h"
#include "Cinto.h"
#include "Elementos.h"

using namespace std;


class Heroi {
public:
    Heroi(); // Construtor do heroi;

    void exibirStatusHeroi(); // Exibe o status do heroi;
    void reduzirPontosVida(int dano); // Reduz os pontos de vida do heroi com base no dano recebido;
    int getVidaAtual(); // Retorna a vida atual do heroi;
    int getAtaque(); // Retorna o ataque do heroi;
    int getAtaqueBonus(); // Retorna o ataque bonus do heroi;

    void usarPocao(Elementos::Elemento& pocao); // Heroi usa a pocao;
    void usarArma(Elementos::Elemento& arma); // Heroi usa a arma;

    void topoMochila(Elementos::Elemento& x); // Retorna o elemento do topo da mochila;
    bool adicionaElementoMochila(int indiceElemento); // Adiciona um elemento na mochila do heroi;
    bool retiraElementoMochila(Elementos::Elemento& x); // Retira um elemento da mochila do heroi;
    bool adicionaElementoCinto(int indiceElemento); // Adiciona um elemento no cinto do heroi;
    void elementoCinto(Elementos::Elemento& x, int indice); // Retorna um elemento do cinto em uma posicao especifica;
    bool retiraElementoCinto(Elementos::Elemento& x); // Retira um elemento do cinto do heroi;
    void retiraCinto(Elementos::Elemento& x, int posicaoCinto); // Retira um elemento do cinto em uma posicao especifica;

private:
    string nome; // Nome do heroi;
    int vidaAtual; // Pontos de vida atual do heroi;
    const int vidaMaxima = 25; // Maximo de pontos de vida do heroi;
    bool escudoAtivo = false; // Indica se o escudo esta ativo;
    int ataqueArma; // Ataque da arma equipada pelo heroi;
    int ataqueBonus = 0; // Ataque bonus do heroi;

    Mochila mochilaHeroi; // Mochila do heroi, ja implementada;
    Cinto cintoHeroi; // Cinto do heroi, ja implementado;
    Elementos::Elemento x; // Elemento temporario para manipulacao;
};

#endif