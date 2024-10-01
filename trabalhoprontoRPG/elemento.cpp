#include "Elementos.h"
#include <string>
#include <iostream>
using namespace std;

// Implementação das armas;
Elementos::Elementos(){
	// Inicializa os dados predefinidos para os elementos;
        elemento[0] = {"Fogo", "Arma", 100, 20};
        elemento[1] = {"Veneno", "Arma", 200, 15};
        elemento[2] = {"Gelo", "Arma", 300, 10};
        elemento[3] = {"Regenerar", "pocao", 300, 10};
		elemento[4] = {"Aumentar ataque", "pocao", 100, 5};
		elemento[5] = {"Escudo", "pocao", 200, 0}; // 1 == true

}

// Implementacao do metodo exibirElemento;
void Elementos::exibirElemento(int p){
    // Verifica se o índice é válido antes de acessar o array;
    if (p < 0 || p >= 6) {
        cout << "Erro: indice invalido!" << endl;
        return;
    }

    cout << endl << "Voce encontrou um elemento!" << endl;
    cout << "Nome: " << elemento[p].nome << endl;
    cout << "Tipo: " << elemento[p].tipo << endl;
    cout << "Peso: " << elemento[p].peso_g << "g" << endl;

    if (elemento[p].tipo == "Arma" || elemento[p].nome == "Aumentar ataque") {
        cout << "Dano: " << elemento[p].capacidade << endl;
    } 
    else if (elemento[p].nome == "Regenerar") {
        cout << "Cura: " << elemento[p].capacidade << endl;
    } 
    else {
        cout << "Protecao: " << elemento[p].capacidade << endl;
    }
}

// Implementacao do metodo getElemento;
Elementos::Elemento Elementos::getElemento(int p) {
    // Verifica se o índice é válido;
    if (p >= 0 && p < 6) {  
        return elemento[p];
    } else {
        return {"", "", 0, 0};  // Retorna um elemento vazio se o índice for inválido;
    }
}

