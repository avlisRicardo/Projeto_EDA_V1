#include "Antena.h"
#include "AntenaArquivo.h"
#include "AntenaLocalizacao.h"



int main() {

    //Antena* listaAntenas = NULL;

    //MatrizDimensao dimensao;
    //listaAntenas = carregarAntenasDeArquivo("C:\\Users\\Dev_RicardoSilva\\Desktop\\IPCA\\Lufer\\TrabalhoPratico\\TrabalhoPratico\\FicheiroExemplo.txt", &dimensao);

    //// Adicionando algumas antenas
    //listaAntenas = AdicionarAntena(listaAntenas, 'A', 1, 2);

    //// Calcular e exibir localiza��es com efeito nefasto
    //Localizacao* listaLocalizacoes = calcularEfeitoNefasto(listaAntenas);
    //exibirLocalizacoes(listaLocalizacoes);

    //// Exibir as antenas
    //ApresentaAntenas(listaAntenas);

    // Supondo que j� tenha uma fun��o para carregar o grafo de um ficheiro:
    Grafo* grafo = CarregarGrafoDeFicheiro("dados_antenas.txt");

    if (!grafo) {
        printf("Erro ao carregar o grafo.\n");
        return 1;
    }

    int origem = 0;   // �ndice da antena de origem
    int destino = 3;  // �ndice da antena de destino

    // Chama a fun��o que retorna os caminhos como string
    char* caminhos = CaminhosEntreAntenasTexto(grafo, origem, destino);

    if (caminhos) {
        printf("Caminhos entre antena %d e %d:\n%s", origem, destino, caminhos);
        free(caminhos); // Importante liberar a mem�ria retornada
    }
    else {
        printf("N�o foi poss�vel encontrar caminhos ou par�metros inv�lidos.\n");
    }

    // Libera mem�ria do grafo
    liberarGrafo(grafo);

    return 0;

}