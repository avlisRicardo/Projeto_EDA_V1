#include "Antena.h"
#include "AntenaArquivo.h"
#include "AntenaLocalizacao.h"

#include "../GereGrafo/Grafo.h"
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
    

    /*
    *   Lista Erros
    *   0   -   Sucesso
    *   1   -   Grafo null
	*   2   -   Antena n�o encontrada
	*   3   -   N�mero inv�lido de antenas
    */

    Grafo* grafo = CriarGrafo();
    Antena* a1 = CriarAntena(1, 10, 20, 'A');
    AdicionarAntena(grafo, a1);

    int erro;
    int sucesso = RemoveGrafo(grafo, &erro);

    if (!sucesso || erro != 0) {
        printf("Erro ao remover o grafo (c�digo: %d)\n", erro);
    }
    else {
        printf("Grafo removido com sucesso.\n");
    }

}