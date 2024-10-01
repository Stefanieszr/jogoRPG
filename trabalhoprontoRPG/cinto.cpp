#include <iostream>
#include "Cinto.h"

using namespace std;

Cinto::Cinto() {
	count = 0; // Inicializa a contagem de elementos no cinto como 0;
	pesoCinto = 0; // Inicializa o peso total do cinto como 0;
}

// Implementacao do metodo Empty;
bool Cinto::Empty(){
	return count == 0;  // Verifica se o cinto esta vazio;
}

// Implementacao do metodo Full;
bool Cinto::Full() {
	return count == maxItens; // Verifica se o cinto esta cheio;
}

// Implementacao do metodo Insert;
bool Cinto::Insert(int y, int indiceElemento) {
	Elementos elementoCinto;
	x = elementoCinto.getElemento(indiceElemento); // Acessando os elementos que foram definido no construtor
	
	// Verifica se a posicao fornecida e valida para insercao;
	if (y < 1 || y > count + 1) { 
	    int posicao;
		cout << "Erro: posicao invalida! "<< endl;
		cout << "Escolha uma posicao valida: " << endl;
		cin >> posicao;
		Insert(posicao, indiceElemento); // Chama recursivamente para nova posicao;
		return true;
	}

	// Verifica se o cinto esta cheio e chama substitui o item se necessario;
	if (Full()) {
		cout << "Seu cinto esta cheio..." << endl;
		Replace(indiceElemento, y);
		return true;
	}

	 // Verifica se a insercao causaria excesso de peso no cinto;
	if (x.peso_g + pesoCinto >= 580) {
		char escolha;
		cout << "Nao foi possivel inserir, o cinto vai ficar pesado demais!"<< endl;
		cout << "Deseja retirar algum elemento para poder guardar o " << x.nome << "? (S/N)" << endl;
		cin >> escolha;

	// Permite ao usuario retirar um elemento para inserir o novo;
		if(escolha == 'S' || escolha == 's'){
			Elementos::Elemento z;
			int posicaoCinto;
			cout << "Qual posicao deseja retirar de 1 a 3: ";
			cin >> posicaoCinto;
			if(!Delete(z, posicaoCinto)){
				return false; // Retorna falso se a exclusao falhar;
			}
			cout << z.nome << " Item retirado com sucesso!"<<endl;
			Insert(y, indiceElemento);
			return true;
		}
		return false; // Se o usuario nao quiser retirar, retorna falso;
	}

	// Move os elementos para abrir espaco para o novo elemento;
	for (int i = count; i >= y; i--){
		cinto[i + 1] = cinto[i];
	}

	cinto[y] = x; // Insere o novo elemento na posicao y;
	pesoCinto += x.peso_g;  // Atualiza o peso total;
	count++; // Incrementa a contagem de elementos;
	cout << x.nome << " Item inserido com sucesso!" << endl;
	return true;
}

// Implementacao do metodo Delete;
bool Cinto::Delete(Elementos::Elemento& x, int y) {
	if (y < 1 || y > count) {
		cout << "ERROR: Invalid position selected" << endl;
		return false;
	}
	x = cinto[y];
	for (int i = y; i <= count - 1; i++) {
		cinto[i] = cinto[i + 1];
	}
	pesoCinto -= x.peso_g;
	count--;
	return true;
}

// Implementacao do metodo Replace;
bool Cinto::Replace(int indice, int y) {
	char escolha;
	cout << "Deseja substituir o elemento da posicao " << y << "? (S/N)" << endl;
	cin >> escolha;

	if(escolha == 'N' || escolha == 'n'){
		return false; // Retorna falso se o usuario nao quiser substituir;
	}

	pesoCinto -= cinto[y].peso_g; // Retira o peso do elemento que sera substituido;

	// Verifica se a nova insercao causaria excesso de peso;
	if (x.peso_g + pesoCinto >= 580) {
		pesoCinto += cinto[y].peso_g;
		char escolha;
		cout << "Nao foi possivel substituir, o cinto vai ficar pesado demais!"<< endl;
		cout << "Deseja retirar elementos para poder guardar o " << x.nome << "? (S/N)" << endl;
		cin >> escolha;

		// Permite ao usuario retirar um elemento para a substituicao;
		if(escolha == 'S' || escolha == 's'){
			Elementos::Elemento z;
			int posicaoCinto;
			cout << "Qual posicao deseja retirar de 1 a 3: ";
			cin >> posicaoCinto;
			if(!Delete(z, posicaoCinto)){
				return false;
			}
			cout << z.nome << "Item retirado com sucesso!"<<endl;
			Insert(posicaoCinto, indice); // Insere o novo elemento;
			return true;
		}
	}
	cinto[y] = x; // Substitui o elemento na posicao y;
	pesoCinto += x.peso_g; // Atualiza o peso total;
	cout << "Item substituido com sucesso!" << endl;
	return true;
}

// Implementacao do metodo Retrieve;
void Cinto::Retrieve(Elementos::Elemento& x, int y) {
	if (y < 1 || y > count) {
		cout << "Posicao invalida" << endl; // Mensagem de erro se a posicao for invalida;
		return;
	}
	x = cinto[y]; // Armazena o elemento na variavel x;
}

// Implementacao do metodo exibirElementos;
void Cinto::exibirElementos() {
	cout << endl;
    for (int i = 1; i <= maxItens; i++) {
        if (i <= count) {
            cout << "  - Posicao " << i << ": " << cinto[i].nome << ", capacidade: " << cinto[i].capacidade << ", peso: " << cinto[i].peso_g << " ";
        } else {
            cout << "  - Posicao " << i << ": Vazio ";
        }
        cout << endl; // Adiciona quebra de linha após cada elemento;
    }
}

// Implementacao do metodo getCount;
int Cinto::getCount() {
	return count; // Retorna a contagem de elementos no cinto;
}

// Implementacao do metodo getPeso;
int Cinto::getPeso(){
	return pesoCinto; // Retorna o peso total do cinto;
}
