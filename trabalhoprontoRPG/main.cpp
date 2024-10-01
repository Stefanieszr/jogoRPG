#include "mapa.h"
#include "Heroi.h"
#include "Inimigos.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // Para rand()
#include <ctime>    // Para srand()

using namespace std;


//Luana Araujo 2245003
//Stefanie de Souza Rodrigues 2244069
//Livia Ferreira Souza 2199838

// Grava em um arquivo .txt os pontos do jogador;
void whiteArquivo(string arq, int nivel, string nome) {
    ofstream arq_w(arq, ios::app); // Abre o arquivo em modo de adicao;
    arq_w << "Nome do jogador: " << nome << ", nível atingido: " << nivel << endl; // Adiciona um espaço entre o nome e o nivel
    arq_w.close();
}

int main() {
    string nome; // Armazena o nome do jogador;
    int nivel = 0; // Inicializa o nivel do jogador;
    Mapa m; // Cria um objeto do tipo Mapa;
    Heroi heroi; // Cria um objeto do tipo Heroi;

    // Declaração dos inimigos
    Inimigos Boss("Boss", 10, 50, 50, 6, 10);  // Cria o Boss;
    Inimigos XGaster1("X-Gaster", 5, 35, 35, 3, 5);  // Cria um inimigo X-Gaster;
    Inimigos Lord("Lord", 3, 15, 15, 2, 3); // Cria um inimigo Lord;

    // Armazenando inimigos que podem ser selecionados aleatoriamente
    Inimigos inimigos[] = { XGaster1, Lord };

    // Inicializa o gerador de números aleatórios
    srand(time(0));

cout << " ____    __                                _____                                                     " << endl;
cout << "/\\  _`\\ /\\ \\__                            /\\___ \\                                                    " << endl;
cout << "\\ \\ ,\\L\\_\\ \\ ,_\\    __   __  __     __     \\/__/\\ \\    ___   __  __  _ __    ___      __   __  __    " << endl;
cout << " \\/_\\__ \\\\ \\ \\/  /'__`\\/\\ \\/\\ \\  /'__`\\      _\\ \\ \\  / __`\\/\\ \\/\\ \\/\\`'__\\/\' _ `\\  /'__`\\/\\ \\/\\ \\   " << endl;
cout << "   /\\ \\L\\ \\ \\ \\_/\\  __/\\ \\ \\_/ |/\\  __/     /\\ \\_\\ \\/\\ \\L\\ \\ \\ \\_\\ \\ \\ \\/ /\\ \\/\\ \\/\\  __/\\ \\ \\_\\ \\  " << endl;
cout << "   \\ `\\____\\ \\__\\ \\____\\\\ \\___/ \\ \\____\\    \\ \\____/\\ \\____/\\ \\____/\\ \\_\\ \\ \\_\\ \\_\\ \\____\\/`____ \\ " << endl;
cout << "    \\/_____/\\/__/\\/____/ \\/__/   \\/____/     \\/___/  \\/___/  \\/___/  \\/_/  \\/_/\\/_/\\/____/ `/___/> \\ " << endl;
cout << "                                                                                              /\\___/ " << endl;
cout << "                                                                                              \\/__/  " << endl;


 cout << "------------------------------------------SEJA BEM VINDO AO STEVE JOURNEY---------------------------------------------" << endl;
 cout << endl;

 cout <<   "Steve, um guerreiro destemido, parte em uma jornada epica para resgatar sua amada Elena,\n"
           "sequestrada pelo temido Boss, que busca o poder do Desejo Supremo. Para alcanca-la, Steve\n"
           "deve enfrentar hordas de monstros como Lords e XGasters e assim o temido Boss, uma criatura sombria e implacavel.\n"
           "Com coragem no coracao, sua missao é levar Steve a vitoria, pois ele luta não so pelo amor, mas\n"
           "tambem para derrotar as forcas do mal que ameacam destruir o mundo." << endl;

 cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Para iniciarmos, informe seu primeiro nome: "; // Solicita o nome do jogador;
    cin >> nome;
    system("cls"); // Limpa a tela apos cada interacao;

cout << "  _   _ _           _   __ " << endl;
cout << " | \\ | (_)         | | /_ |" << endl;
cout << " |  \\| |___   _____| |  | |" << endl;
cout << " | . ` | \\ \\ / / _ \\ |  | |" << endl;
cout << " | |\\  | |\\ V /  __/ |  | |" << endl;
cout << " |_| \\_|_| \\_/ \\___|_|  |_|" << endl;
cout << endl;

    // Niveis percorrendo sqms definidos no construtor do Mapa;
    int contadorElementos = 0;  // Conta quantos elementos foram exibidos
    for (int i = 0; i < 49; i++) {
        heroi.exibirStatusHeroi(); // Exibe o status do heroi;
        nivel = 1; // Nivel começa em 1;
        
        if (m.sqm[i] == 0) {
            m.sqmVazio(heroi); // Executa acao para espaço vazio;
            system("cls"); // Limpa a tela;

        } else if (m.sqm[i] == 1) {
            int elementoIndice; // Armazena o indice do elemento;

            if (contadorElementos % 2 == 1 || contadorElementos == 0) { // A cada dois elementos, exibe uma arma
                elementoIndice = rand() % 3;  // Armas estão nos índices 0, 1, 2
            } else {
                elementoIndice = 3 + rand() % 3;  // Poções estão nos índices 3, 4, 5
            }

            m.sqmElemento(heroi, elementoIndice); // Executa acao para o elemento;

            contadorElementos++;
            system("cls");
           } else if (m.sqm[i] == 2) {
            // Seleciona aleatoriamente um inimigo que não seja o Boss
            int inimigoAleatorioIndice = rand() % 2;  // Índices 0 e 1 correspondem a XGaster1 e Lord

            if (m.sqmInimigo(heroi, inimigos[inimigoAleatorioIndice])) { // Verifica se o heroi venceu o inimigo;
            int vidaInimigo = inimigos[inimigoAleatorioIndice].getVida(); // Obtem a vida do inimigo;
            inimigos[inimigoAleatorioIndice]; // Atualiza inimigo;

            } else {
                whiteArquivo("high_scores.txt", nivel, nome); // Grava o nivel e nome do jogador no arquivo;
                m.gameover(); //chama o gameover;
                main(); // Chama o main novamente;
                return 0; // Continua para a proxima interacao;    
     }
        } else if (m.sqm[i] == 3){
        // Seleciona o inimigo boss;
        cout << " _       _________          _______  _          ______   _______  _______  _______ " << endl;
        cout << "( (    /|\\__   __/|\\     /|(  ____ \\( \\        (  ___ \\ (  ___  )(  ____ \\(  ____ \\" << endl;
        cout << "|  \\  ( |   ) (   | )   ( || (    \\/| (        | (   ) )| (   ) || (    \\/| (    \\/" << endl;
        cout << "|   \\ | |   | |   | |   | || (__    | |        | (__/ / | |   | || (_____ | (_____ " << endl;
        cout << "| (\\ \\) |   | |   ( (   ) )|  __)   | |        |  __ (  | |   | |(_____  )(_____  )" << endl;
        cout << "| | \\   |   | |    \\ \\_/ / | (      | |        | (  \\ \\ | |   | |      ) |      ) |" << endl;
        cout << "| )  \\  |___) (___  \\   /  | (____/\\| (____/\\  | )___) )| (___) |/\\____) |/\\____) |" << endl;
        cout << "|/    )_\\_______/   \\_/   (_______/(_______/  |/ \\___/ (_______)\\_______)\\_______)" << endl;

        // Inicia a batalha contra o Boss
        if (m.sqmInimigo(heroi, Boss)) {
            nivel = 2; // muda par ao nivel 2
            m.adicionarSQMInimigo(m.posicaoAtual(), true);
            // Chama a função que armazena o nome e o nível máximo atingido pelo jogador
            whiteArquivo("high_scores.txt", nivel, nome);
            
            // Finaliza o jogo se o Boss for derrotado
            cout << "-----------------------------------------------------" << endl;
            cout << "Parabens, voce derrotou o Boss e completou o jogo!\n" << endl;
            m.adicionarSQMfinal();
            cout << "Obrigado por jogar!" << endl;
            return 0;  // Finaliza o programa após a vitória do jogador
        } else {
            whiteArquivo("high_scores.txt", nivel, nome); // Grava o nivel e nome do jogador no arquivo;
            m.gameover(); //chama o gameover;
            main(); // Chama o main novamente;
            return 0; // Continua para a proxima interacao;
        }
        cout << endl << "Pressione ENTER para continuar a percorrer o caminho.";
        cin.ignore();  // Ignora o '\n' pendente do último cin
        cin.get();     // Espera o Enter para continuar

        system("cls");
        }
    }

    return 0;
}