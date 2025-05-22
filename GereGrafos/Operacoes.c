#include "Operacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// Procedimento auxiliar utilizada para realizar a Procura em Profundidade
/// </summary>
/// <param name="g">grafo</param>
/// <param name="v">v�rtice</param>
/// <param name="visitado">0 ou 1</param>
/// <param name="resultado"></param>
void DFSRecursivo(Grafo* grafo, int vertice, int* visitado, char* resultado) {

    // Marca o v�rtice atual como visitado
    visitado[vertice] = 1;

    // Cria uma string tempor�ria para armazenar as informa��es da antena atual
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d(%d,%d) ", vertice, grafo->antenas[vertice]->posicaoX, grafo->antenas[vertice]->posicaoY);
    
    // Concatena o buffer ao resultado final da DFS
    strcat(resultado, buffer);

    // Percorre a lista de adjac�ncias do v�rtice atual e chama recursivamente a DFS para esse v�rtice
    for (Adjacencia* adj = grafo->adjacencia[vertice]; adj; adj = adj->proxima) {
        if (!visitado[adj->destino])
            DFSRecursivo(grafo, adj->destino, visitado, resultado);
    }
}

/// <summary>
/// Fun��o respons�vel pela pesquisa recursiva do grafo em profundidade (DFS).
/// </summary>
/// <param name="grafo">Apontador para o grafo onde ser� realizada a pesquisa</param>
/// <param name="inicio">�ndice da antena de onde se inicia a pesquisa</param>
/// <returns>String com o caminho percorrido no formato "id(x,y) "</returns>
char* DFS(Grafo* grafo, int inicio) {

    // Aloca dinamicamente um vetor para marcar os v�rtices visitados
    int* visitado = (int*)calloc(grafo->numeroVertices, sizeof(int));

    // Aloca mem�ria para a string de resultado que conter� o percurso
    char* resultado = (char*)calloc(1024, sizeof(char)); // Pode ser ajustado conforme o tamanho esperado

    // Chamada recursiva da DFS a partir do v�rtice inicial
    DFSRecursivo(grafo, inicio, visitado, resultado);

    free(visitado);

    return resultado;
}

char* BFS(Grafo* grafo, int inicio) {

    // Vetor para marcar v�rtices visitados, inicializado com 0
    int* visitado = (int*)calloc(grafo->numeroVertices, sizeof(int));

    // Fila para controle da ordem de visita dos v�rtices (BFS)
    int* fila = (int*)malloc(sizeof(int) * grafo->numeroVertices);

    // �ndices para frente e traseira da fila
    int frente = 0, tras = 0;

    char* resultado = (char*)calloc(1024, sizeof(char));

    // Adiciona v�rtice inicial � fila e marca como visitado
    fila[tras++] = inicio;
    visitado[inicio] = 1;

    // Enquanto houver v�rtices na fila
    while (frente < tras) {

        // Remove v�rtice da frente da fila
        int atual = fila[frente++];

        // Obt�m antena correspondente ao v�rtice atual
        Antena* a = grafo->antenas[atual];

        // Prepara string com id e coordenadas da antena
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d(%d,%d) ", atual, a->posicaoX, a->posicaoY);

        // Adiciona ao resultado final
        strcat(resultado, buffer);

        // Percorre lista de adjac�ncia do v�rtice atual
        for (Adjacencia* adj = grafo->adjacencia[atual]; adj; adj = adj->proxima) {

            // Se o v�rtice adjacente ainda n�o foi visitado adiciona � fila e marca como visitado
            if (!visitado[adj->destino]) {
                fila[tras++] = adj->destino;
                visitado[adj->destino] = 1;
            }
        }
    }

    free(fila);
    free(visitado);

    return resultado;
}

/// <summary>
/// Fun��o auxiliar recursiva para encontrar caminhos entre dois v�rtices de um grafo.
/// Esta fun��o � chamada internamente pela fun��o principal e utiliza busca em profundidade (DFS).
/// </summary>
/// <param name="grafo"></param>
/// <param name="atual"></param>
/// <param name="destino"></param>
/// <param name="visitado"></param>
/// <param name="caminho"></param>
/// <param name="nivel"></param>
/// <param name="resultado"></param>
void CaminhosRecursivo(Grafo* grafo, int atual, int destino, int* visitado, int* caminho, int nivel, char* resultado) {
    visitado[atual] = 1;                      // Marca o v�rtice atual como visitado
    caminho[nivel++] = atual;                // Adiciona o v�rtice atual ao caminho atual e incrementa o n�vel

    if (atual == destino) {                  // Se o v�rtice atual � o destino
        char buffer[256] = "";               // Inicializa um buffer tempor�rio para armazenar o caminho
        for (int i = 0; i < nivel; i++) {
            Antena* a = grafo->antenas[caminho[i]]; // Obt�m a antena correspondente ao v�rtice do caminho
            char passo[32];
            snprintf(passo, sizeof(passo), "%d(%d,%d) ", caminho[i], a->posicaoX, a->posicaoY); // Formata o passo
            strcat(buffer, passo);           // Adiciona o passo ao buffer
        }
        strcat(buffer, "\n");                // Adiciona quebra de linha ap�s o caminho
        strcat(resultado, buffer);           // Junta o buffer ao resultado final
    }
    else {
        // Explora recursivamente os v�rtices adjacentes n�o visitados
        for (Adjacencia* adj = grafo->adjacencia[atual]; adj; adj = adj->proxima) {
            if (!visitado[adj->destino]) {
                CaminhosRecursivo(grafo, adj->destino, destino, visitado, caminho, nivel, resultado);
            }
        }
    }

    visitado[atual] = 0;                     // Backtracking: desmarca o v�rtice atual para permitir outros caminhos
}

/// <summary>
/// Fun��o respons�vel por encontrar todos os caminhos poss�veis entre duas antenas em um grafo.
/// </summary>
/// <param name="grafo"></param>
/// <param name="inicio"></param>
/// <param name="fim"></param>
/// <returns>string com todos os caminhos, onde cada linha representa um caminho diferente.</returns>
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim) {

    // Verifica se os par�metros s�o v�lidos
    if (!grafo || inicio < 0 || fim < 0 ||
        inicio >= grafo->numeroVertices || fim >= grafo->numeroVertices)
        return NULL;

    // Aloca mem�ria para o vetor de visitados
    int* visitado = (int*)calloc(grafo->numeroVertices, sizeof(int));

    // Aloca vetor para armazenar o caminho atual durante a recurs�o
    int* caminho = (int*)malloc(sizeof(int) * grafo->numeroVertices);
    char* resultado = (char*)calloc(4096, sizeof(char)); 

    // Inicia a chamada recursiva para encontrar os caminhos
    CaminhosRecursivo(grafo, inicio, fim, visitado, caminho, 0, resultado);

    free(visitado);
    free(caminho);

    return resultado;
}
