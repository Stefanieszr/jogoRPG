#include "Inimigos.h"
#include <iostream>
#include <ctime>  
#include <string>

using namespace std;

Inimigos::Inimigos(string nome, int ataque, int vidaAtual, int vidaMax, int min, int max) {
	this->nome = nome; // Atribui o nome do inimigo;
	this->ataque = ataque; // Atribui o ataque do inimigo;
	this->vidaAtual = vidaAtual; // Atribui a vida atual do inimigo;
	this->vidaMax = vidaMax; // Atribui a vida maxima do inimigo;
	definirAtaque(min, max); // Define o ataque aleatorio do inimigo;
}

// Implementacao do metodo exibirInimigo;
void Inimigos::exibirInimigo() {
	cout << "Voce encontrou um inimigo!" << endl;
	cout << "Inimigo: " << this->nome << endl;
	cout << "Ataque: " << this->ataque << endl;
	cout << "Vida: " << this->vidaAtual << endl;
}

// Implementacao do metodo definirAtaque;
void Inimigos::definirAtaque(int min, int max) {
	srand(time(0)); // Seta a semente para geracao de numeros aleatorios;
	ataque = rand() % (max - min + 1) + min; // Define ataque aleatorio entre min e max;
}

// Implementacao do metodo reduzirVida;
void Inimigos::reduzirVida(int dano) {
    vidaAtual = vidaAtual - dano;
    if (vidaAtual < 0) { // Garante que a vida não seja negativa;
		vidaAtual = 0;
	}  
}

// Implementacao do metodo getAtaque;
int Inimigos::getAtaque() {
	return this->ataque;
}

// Implementacao do metodo getVida;
int Inimigos::getVida() {
	return this->vidaAtual;
}

// Implementacao do metodo setVida;
void Inimigos::setVida(){
	this->vidaAtual = vidaMax;
}