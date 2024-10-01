#ifndef INIMIGOS_H
#define INIMIGOS_H

#include <string>
using namespace std;


class Inimigos {
public:
    Inimigos(string nome, int ataque, int vidaAtual, int vidaMax, int min, int max); // Construtor do inimigo;
    void exibirInimigo(); // Exibe as informacoes do inimigo;
    void definirAtaque(int min, int max); // Define o ataque do inimigo com base em um intervalo;
    void reduzirVida(int dano); // Reduz a vida do inimigo com base no dano recebido;
    void setVida(); // Define a vida do inimigo;
    int getAtaque(); // Retorna o ataque do inimigo;
    int getVida(); // Retorna a vida atual do inimigo;

private:
    string nome; // Nome do inimigo;
    int ataque; // Ataque do inimigo;
    int vidaAtual; // Vida atual do inimigo;
    int vidaMax; // Vida maxima do inimigo;
    int min; // Valor minimo de ataque;
    int max; // Valor maximo de ataque;
};

#endif