#include "mochila.h"
#include <iostream>
using namespace std;

// Implementacao do construtor da Mochila;
Mochila::Mochila(){
    top = NULL;
}

// Implementacao do destrutor da Mochila;
Mochila::~Mochila(){
    Elementos::Elemento x;
    while (!Empty()){
        Pop(x);
    } 
}

// Implementacao do metodo Empty;
bool Mochila::Empty(){
    return top == NULL;
}

// Implementacao do metodo Push;
bool Mochila::Push(int indiceElemento){
    Elementos elementos; 
    x = elementos.getElemento(indiceElemento); // Acessando os elementos que foram definido no construtor;

    mochilaPointer p = new mochilaNode; // Tenta alocar um novo espaço para mochilaNode;
    if(p == NULL){  // Verifica espaço;
        cout << "ERRO: Não há espaco na mochila para guardar"<<endl;
        return false;
    }

    p -> entry = x; // Acessa o campo 'Entry' da Struck e guarda o numero indicado;
    p -> nextNode = top; // Acessa campo 'NextNode' da Struck e guarda o endereço do penultimo num inserido (topo antigo), apontando para ele
    top = p; // top aponta para o novo topo (Ultimo num inserido);
    return true;
}

// Implementacao do metodo Pop;
bool Mochila::Pop(Elementos::Elemento &x){
    if(Empty()){
        cout << "Nao ha elementos para retirar, mochila vazia"<<endl;
        return false;
    }
    mochilaPointer p = top; // Aponta para topo;
    x = top -> entry; // Recebe o numero que está guardado no topo (Acessando o campo Entry da Struck);
    top = top -> nextNode; 
    delete p;
    return true;
}

// Implementacao do metodo Size;
int Mochila::Size(){
    mochilaPointer p;
    int tamanho = 0;
    p = top;
    while(p != NULL){
        tamanho++;
        p = p -> nextNode;
    }
    return tamanho;
}

// Implementacao do metodo Top;
void Mochila::Top(Elementos::Elemento &x){
    if(Empty()){
        cout << "Vazio" << endl;
        return;
    }
    x = top -> entry;
}

// Implementacao do metodo ExibirTop;
void Mochila::ExibirTop(){
    if(Empty()){
        cout << "Vazio" << endl;
        return;
    }
    x = top->entry;
    cout << x.nome << ", capacidade: " << x.capacidade << endl;
}
