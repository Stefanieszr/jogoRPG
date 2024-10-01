#include <iostream>
#include "Heroi.h"
#include "Elementos.h"

using namespace std;

Heroi::Heroi() {
    vidaAtual = vidaMaxima; // Inicializa os pontos de vida com o máximo;
    this->nome = "Steve"; // Nomeia o herói com o nome do usuário;
}

// Implementacao do metodo getVidaAtual;
int Heroi::getVidaAtual() {
    return vidaAtual;
}

// Implementacao do metodo exibirStatusHeroi;
void Heroi::exibirStatusHeroi() {
    Elementos::Elemento elementoNoTopo;
    cout << "-----------------------------------------------" << endl;

    // Exibe a vida do heroi;
    cout << "STATUS DO HEROI" << endl;
    cout << endl << "VIDA: " << vidaAtual << " / " << vidaMaxima << endl;

    // Exibe elementos guardados no cinto;
    cout << "CINTO: " << endl;
    cout << "  - Peso: " << cintoHeroi.getPeso() << "g / 580g";
    cintoHeroi.exibirElementos();

    // Exibe elemento guardado no topo da mochila;
    cout << "TOPO DA MOCHILA: ";
    mochilaHeroi.ExibirTop();
    cout << "-----------------------------------------------" << endl;
}

// Implementacao do metodo reduzirPontosVida;
void Heroi::reduzirPontosVida(int dano) {
    if(escudoAtivo){
        cout << "Voce foi protegido com o escudo"<<endl;
        escudoAtivo = false;
        return;
    }
    vidaAtual = vidaAtual - dano;
    if (vidaAtual < 0) {
        vidaAtual = 0; // Evita que a vida fique negativa;
    }
}

// Implementacao do metodo getAtaque;
int Heroi::getAtaque(){
    return ataqueArma;
}

// Implementacao do metodo getAtaqueBonus;
int Heroi::getAtaqueBonus(){
    return ataqueBonus;
}

// Implementacao do metodo usarPocao;
void Heroi::usarPocao(Elementos::Elemento &pocao) {
    if(pocao.nome == "Regenerar"){
        int cura = pocao.capacidade;  // Quantidade de vida que a poção cura;
        vidaAtual += cura;
        
        // Garante que a vida não excede o máxima;
        if (vidaAtual > vidaMaxima) {
            vidaAtual = vidaMaxima;
        }
        cout << "Vida restaurada em " << cura << " pontos. Vida atual: " << vidaAtual << endl;
    }
    else if(pocao.nome == "Aumentar ataque"){
        ataqueBonus = pocao.capacidade;  // valor de aumento de ataque;
        cout << "Ataque aumentado! Seu próximo ataque terá " << ataqueBonus << " pontos extras." << endl;
    }
    else if(pocao.nome == "Escudo"){
        escudoAtivo = true;
        cout << "Escudo ativado " << endl;
    }
}

// Implementacao do metodo usarArma;
void Heroi::usarArma(Elementos::Elemento &arma) {
    cout << "Sua vez de atacar!" << endl;
    
    int escolha;
    cout << "Escolha sua acao: " << endl;
    cout << "1. Usar arma do cinto" << endl;
    cout << "2. Usar arma da mochila" << endl;  
    cout << "3. Nao tenho arma para usar" <<endl;
    cin >> escolha;      
            
    if (escolha == 1) {
        int posicaoCinto;
        cout << "Escolha a arma do cinto (1 a 3): ";
        cin >> posicaoCinto;
        elementoCinto(x,posicaoCinto);
        if (x.tipo != "Arma") {
            cout << "Nao pode utilizar pocoes durante a batalha, escolha novamente..." << endl;
            usarArma(x); // Chama recursivamente a função
            return;
        }
        arma = x;
        ataqueArma = arma.capacidade;
        cintoHeroi.Delete(x,posicaoCinto);
    }
    else if(escolha == 2){
        topoMochila(x);
        if (x.tipo != "Arma") {
            char opcao;
            cout << "Nao pode utilizar pocoes durante a batalha, escolha novamente..." << endl;
            cout << "Deseja retirar o topo da mochila para encontrar? (S/N)"<<endl;
            cin >> opcao;

            if(opcao == 'S' || opcao == 's'){
                retiraElementoMochila(x);
                topoMochila(x);
                cout << "O topo da mochila agora é: " << x.nome << endl;
            }
            if(opcao == 'N' || opcao == 'n'){
                usarArma(x); // Chama recursivamente a função
                return;
            }
        }
        arma = x;
        ataqueArma = arma.capacidade;
        retiraElementoMochila(x);
    } 
    else if(escolha == 3){
        ataqueArma = 0;
        return;
    }
    else{
        cout << "Escolha invalida, tente novamente" << endl;
        usarArma(x); // Chama recursivamente a função
    }
}

// Implementacao do metodo adicionaElementoCinto;
bool Heroi::adicionaElementoCinto(int indiceElemento) {
    int posicaoCinto;
    cout << "Qual posicao deseja inserir de 1 a 3: ";
    cin >> posicaoCinto;

    // Verifica se o elemento foi inserido com sucesso
    if(!cintoHeroi.Insert(posicaoCinto, indiceElemento)){
        return false;
    }
    return true;
}

// Implementacao do metodo adicionaElementoMochila;
bool Heroi::adicionaElementoMochila(int indiceElemento){
    if(!mochilaHeroi.Push(indiceElemento)){
        return false;
    }
    return true;
};

// Implementacao do metodo retiraElementoCinto;
bool Heroi::retiraElementoCinto(Elementos::Elemento &x){
    int posicaoCinto;
    cout << "Qual posicao deseja retirar de 1 a 3: ";
    cin >> posicaoCinto;
    if(!cintoHeroi.Delete(x, posicaoCinto)){
        return false;
    }
    cout << endl << "Cinto atualizado!" <<endl;
    cintoHeroi.exibirElementos();
    return true;
};

// Implementacao do metodo retiraCinto;
void Heroi::retiraCinto(Elementos::Elemento &x,int posicaoCinto){
    if(!cintoHeroi.Delete(x, posicaoCinto)){
        return;
    }
    return;
};

// Implementacao do metodo retiraElementoMochila;
bool Heroi::retiraElementoMochila(Elementos::Elemento &x){
    if(!mochilaHeroi.Pop(x)){
        return false;
    }
    return true;
};

// Implementacao do metodo elementoCinto;
void Heroi::elementoCinto(Elementos::Elemento &x, int indice){
    cintoHeroi.Retrieve(x,indice);
}

// Implementacao do metodo topoMochila;
void Heroi::topoMochila(Elementos::Elemento &x){
    mochilaHeroi.Top(x);
}

// FIM


