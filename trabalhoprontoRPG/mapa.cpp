#include "mapa.h"
#include <iostream>
#include <string> 
using namespace std;

// Implementacao do constutor do Mapa;
Mapa::Mapa(){
    int posicao = 0;
  //nivel 1
  for (int i = 0; i < 3; ++i) { // Loop 3 vezes
        adicionarSQMsElemento(posicao, 5); // 5 SQMs com elementos;
        posicao += 5;
        adicionarSQMVazio(posicao++); // 1 SQM vazia;
        adicionarSQMInimigo(posicao++, false); // 1 SQM com inimigo (pode ser Lord ou XGaster, decidido na main);
        adicionarSQMVazio(posicao++); // 1 SQM vazia;
    }
   // nível 2
    adicionarSQMVazio(posicao++);// 1 SQM vazia;
    adicionarSQMsElemento(posicao, 10); // 10 SQMs com elementos;
    posicao += 10;
    adicionarSQMVazio(posicao++);// 1 SQM vazia
    adicionarSQMInimigo(posicao++, true); //1 SQM com inimigo que será o boss    
}

// Implementacao do metodo sqmVazio;
void Mapa::sqmVazio(Heroi &heroi){
    int posicao = posicaoAtual();
    cout << "POSICAO NO MAPA: " << posicao << endl;
    
    int opcao = 0;
    cout << "Deseja retirar ou usar uma pocao? " << endl;
    cout << endl << "1. Usar pocao do Cinto" << endl;
    cout << "2. Usar pocao da Mochila" << endl;
    cout << "3. Retirar elementos do Cinto" << endl;
    cout << "4. Retirar elementos da Mochila" << endl;
    cout << "5. Nao quero fazer nada" << endl;
    cin >> opcao;

    switch(opcao){
        case 1: {
            int posicao;
            cout << "Pocao de qual posicao deseja usar? " << endl;
            cin >> posicao;

            heroi.elementoCinto(x, posicao);
            if (x.tipo == "Arma") {
                cout << "Voce so pode usar armas durante a batalha" << endl;
                sqmVazio(heroi);
            }
            heroi.usarPocao(x);
            heroi.retiraCinto(x,posicao);
        }
        break;

        case 2: {
            bool repetir = true; // Controla se o case será repetido;
            while (repetir) { // Loop que repete o case 2

                heroi.topoMochila(x); // Confere o que tem no topo da mochila;

                // Verifica o tipo do elemento
                if (x.tipo == "Arma") {
                    char escolha;
                    cout << "Voce so pode usar armas durante a batalha" << endl;
                    cout << "Deseja jogar fora a arma do topo para encontrar uma pocao? (S/N)" << endl;
                    cin >> escolha;

                    if (escolha == 'S' || escolha == 's') {
                        heroi.retiraElementoMochila(x);
                        repetir = true; 
                    } else if (escolha == 'N' || escolha == 'n') {
                        repetir = false; 
                    }
                }
                else {
                    heroi.usarPocao(x);
                    heroi.retiraElementoMochila(x);
                    repetir = false; // Encerra o loop quando a poção é usada;
                }
            }
        }
        break;

        case 3:{
            bool repetir = true; // Controla se o case será repetido;
            while (repetir) { // Loop que repete o case 3;
                if (!heroi.retiraElementoCinto(x)){
                    bool repetir = false;
                    break;
                };
                cout << x.nome << " retirado com sucesso!" << endl;
                char escolha;
                cout << "Deseja retirar mais elementos? (S/N)" << endl;
                cin >> escolha;

                if (escolha == 'S' || escolha == 's') {
                    repetir = true; // Continua retirando mais elementos
                } else {
                    repetir = false; // Encerra o loop
                }
            } 
        }
        break;

        case 4: {
            bool repetir = true; // Controla se o case será repetido
            while (repetir) { // Loop que repete o case 
                if(!heroi.retiraElementoMochila(x)){
                    bool repetir = false;
                    break;
                }
                cout << x.nome << " retirado com sucesso!" << endl;
                char escolha;
                cout << endl << "Deseja retirar mais elementos? (S/N)" << endl;
                cin >> escolha;

                if (escolha == 'S' || escolha == 's') {
                    repetir = true; // Continua retirando mais elementos
                } else {
                    repetir = false; // Encerra o loop
                }
            }     
        }
        break;

        case 5: 
            // continua no caminho
        break;

        default:
        cout << "Escolha invalida, tente novamente" << endl;
    }
}

// Implementacao do metodo sqmElemento;
void Mapa::sqmElemento(Heroi &heroi, int indiceElemento){
    posicaoAtual();
    cout << "POSICAO NO MAPA: " << posicao << endl;
    int opcao;
    Elementos elementoHeroi;
    elementoHeroi.exibirElemento(indiceElemento); 

    cout << endl << "Escolha sua acao:" << endl;
    cout << "1. Guardar elemento no Cinto" << endl;
    cout << "2. Guardar elementos da Mochila" << endl;
    cout << "3. Nao quero pegar o elemento" << endl;
    cin >> opcao;

    switch(opcao){
        case 1: {
            // Verifica se foi guardado com sucesso o item;
            if(!heroi.adicionaElementoCinto(indiceElemento)){
                sqmElemento(heroi, indiceElemento);
            }
        }
        break;

        case 2: {
            // Verifica se foi guardado com sucesso o item;
            if(!heroi.adicionaElementoMochila(indiceElemento)){
                sqmElemento(heroi, indiceElemento);
            }  
        } 
        break;

        case 3:
            //Não vai acontecer nada, o usuario continua pelo caminho
        break;

        default:
        cout << "Escolha invalida, tente novamente" << endl;
    }
}

// Implementacao do metodo sqmInimigo;
bool Mapa::sqmInimigo(Heroi &heroi, Inimigos &inimigo) {
    posicaoAtual();
    cout << "POSICAO NO MAPA: " << posicao << endl;

    Elementos::Elemento elemento;
    inimigo.exibirInimigo(); // Chama a função que exibe o inimigo que foi encontrado
    heroi.usarArma(elemento); // Chama a função que interage com o usuário sobre o elemento que ele quer usar
    int ataqueInimigo = inimigo.getAtaque();
    int heroiAtaque = heroi.getAtaque();
    int heroiVida = heroi.getVidaAtual();
    int inimigoVida = inimigo.getVida();

    int heroiBonus = heroi.getAtaqueBonus();
    if(heroiBonus != 0){
        heroiAtaque + heroiBonus;
    }
 
    while (heroiVida > 0 && inimigoVida > 0) {
        cout << endl << "Vida do Heroi: " << heroiVida << endl;
        cout << "Vida do Inimigo: " << inimigoVida << endl;

        //Herói ataca;
        cout << endl << "Sua vez de atacar!" << endl;
        cout << "Voce atacou o inimigo com " << " causando "<< heroiAtaque << " de dano!" << endl;
        inimigo.reduzirVida(heroiAtaque);
        
        //Verifica se inimigo foi derrotado
        inimigoVida = inimigo.getVida();
        if (inimigoVida <= 0) {
        cout << "Voce derrotou o inimigo!" << endl;
        inimigo.setVida();
        return true;
        }
        // Vez do inimigo atacar;
        cout << endl << "Vez do inimigo atacar!" << endl;

        // O inimigo realiza seu ataque de acordo com seu tipo;
        inimigo.definirAtaque(2, 10);  // Ajuste o intervalo de dano conforme o tipo de inimigo;
        heroi.reduzirPontosVida(ataqueInimigo);
        cout << "Inimigo te atacou" << " causando "<< ataqueInimigo << " de dano!" << endl;

        //Verifica de heroi foi derrotado;
        heroiVida = heroi.getVidaAtual();
         if (heroiVida <= 0) {
        cout << "Voce foi derrotado!" << endl;
        return false;
         }
    }
    return false;
}

// Implementacao do metodo posicaoAtual;
int Mapa::posicaoAtual(){
    posicao++;
    return posicao;
};

// Implementacao do metodo adicionarSQMVazio;
void Mapa::adicionarSQMVazio(int posicao) {
    sqm[posicao] = 0;  // SQM vazia
}

// Implementacao do metodo adicionarSQMsElemento;
void Mapa::adicionarSQMsElemento(int inicio, int quantidade) {
    for (int i = inicio; i < inicio + quantidade; i++) {
        sqm[i] = 1;  // SQMs de elementos
    }
}

// Implementacao do metodo adicionarSQMInimigo;
void Mapa::adicionarSQMInimigo(int posicao, bool ehBoss) {
    if(ehBoss){
        sqm[posicao] = 3;
    }else{
        sqm[posicao] = 2; // SQM de inimigo (decisão de qual inimigo na main)
    }
}

// Implementacao do metodo adicionarSQMfinal;
void Mapa::adicionarSQMfinal(){
    cout << "Voce salvou sua amada Elena" << endl;
}

// Implementacao do metodo gameover;
void Mapa::gameover(){
    char escolha;
        
                cout << "  ____                                                   " << endl;
                cout << " /  __/__    __   __     ___  _ _____  " << endl;
                cout << "/   \\  _\\_  \\  /     \\/ _ \\   /  _ \\  \\/ // _ \\_  __ \\ " << endl;
                cout << "\\    \\\\  \\/ _ \\|  Y Y  \\  _/  (  <> )   /\\  __/|  | \\/ " << endl;
                cout << " \\__  (__  /_||  /\\_  >  \\_/ \\/  \\_  >__|    " << endl;
                cout << "        \\/     \\/      \\/     \\/                   \\/       " << endl;

                cout << endl<< "Pressione ENTER para jogar de novo ou 0 para sair." << endl;

                cin.ignore();  // Ignora o '\n' pendente do último cin
                escolha = cin.get();     // Espera o Enter para continuar

                if (escolha == '0') {  // Se o usuário pressionar '0'
                    system("cls");
                    cout << endl << "Saindo do jogo..." << endl;
                    abort();  // Encerra o loop e o jogo
                }
                else {  // Se o usuário pressionar qualquer outra tecla
                    system("cls");
                    cout << endl << "Jogando de novo..." << endl;
                    
                }
}
