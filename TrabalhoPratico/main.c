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

    //// Calcular e exibir localizações com efeito nefasto
    //Localizacao* listaLocalizacoes = calcularEfeitoNefasto(listaAntenas);
    //exibirLocalizacoes(listaLocalizacoes);

    //// Exibir as antenas
    //ApresentaAntenas(listaAntenas);

    // Supondo que já tenha uma função para carregar o grafo de um ficheiro:
    

    /*
    *   Lista Erros
    *   0   -   Sucesso
    *   1   -   Grafo null
	*   2   -   Antena não encontrada
	*   3   -   Número inválido de antenas
    */

    Grafo* grafo = CriarGrafo();
    Antena* a1 = CriarAntena(1, 10, 20, 'A');
    AdicionarAntena(grafo, a1);

    int erro;
    int sucesso = RemoveGrafo(grafo, &erro);

    if (!sucesso || erro != 0) {
        printf("Erro ao remover o grafo (código: %d)\n", erro);
    }
    else {
        printf("Grafo removido com sucesso.\n");
    }

}