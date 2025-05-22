#include "Antena.h"
#include "AntenaArquivo.h"
#include "AntenaLocalizacao.h"



int main() {

    //Antena* listaAntenas = NULL;

    //MatrizDimensao dimensao;
    //listaAntenas = carregarAntenasDeArquivo("C:\\Users\\Dev_RicardoSilva\\Desktop\\IPCA\\Lufer\\TrabalhoPratico\\TrabalhoPratico\\FicheiroExemplo.txt", &dimensao);

    //// Adicionando algumas antenas
    //listaAntenas = AdicionarAntena(listaAntenas, 'A', 1, 2);

    //// Calcular e exibir localizações com efeito nefasto
    //Localizacao* listaLocalizacoes = calcularEfeitoNefasto(listaAntenas);
    //exibirLocalizacoes(listaLocalizacoes);

    //// Exibir as antenas
    //ApresentaAntenas(listaAntenas);

    // Supondo que já tenha uma função para carregar o grafo de um ficheiro:
    Grafo* grafo = CarregarGrafoDeFicheiro("dados_antenas.txt");

    if (!grafo) {
        printf("Erro ao carregar o grafo.\n");
        return 1;
    }

    int origem = 0;   // Índice da antena de origem
    int destino = 3;  // Índice da antena de destino

    // Chama a função que retorna os caminhos como string
    char* caminhos = CaminhosEntreAntenasTexto(grafo, origem, destino);

    if (caminhos) {
        printf("Caminhos entre antena %d e %d:\n%s", origem, destino, caminhos);
        free(caminhos); // Importante liberar a memória retornada
    }
    else {
        printf("Não foi possível encontrar caminhos ou parâmetros inválidos.\n");
    }

    // Libera memória do grafo
    liberarGrafo(grafo);

    return 0;

}