#include "Operacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// Procedimento auxiliar utilizada para realizar a Procura em Profundidade
/// </summary>
/// <param name="g">grafo</param>
/// <param name="v">vértice</param>
/// <param name="visitado">0 ou 1</param>
/// <param name="resultado"></param>
void DFSRecursivo(Grafo* grafo, int vertice, int* visitado, char* resultado) {

    // Marca o vértice atual como visitado
    visitado[vertice] = 1;

    // Cria uma string temporária para armazenar as informações da antena atual
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d(%d,%d) ", vertice, grafo->antenas[vertice]->posicaoX, grafo->antenas[vertice]->posicaoY);
    
    // Concatena o buffer ao resultado final da DFS
    strcat(resultado, buffer);

    // Percorre a lista de adjacências do vértice atual e chama recursivamente a DFS para esse vértice
    for (Adjacencia* adj = grafo->adjacencia[vertice]; adj; adj = adj->proxima) {
        if (!visitado[adj->destino])
            DFSRecursivo(grafo, adj->destino, visitado, resultado);
    }
}

/// <summary>
/// Função responsável pela pesquisa recursiva do grafo em profundidade (DFS).
/// </summary>
/// <param name="grafo">Apontador para o grafo onde será realizada a pesquisa</param>
/// <param name="inicio">Índice da antena de onde se inicia a pesquisa</param>
/// <returns>String com o caminho percorrido no formato "id(x,y) "</returns>
char* DFS(Grafo* grafo, int inicio) {

    // Aloca dinamicamente um vetor para marcar os vértices visitados
    int* visitado = (int*)calloc(grafo->numeroVertices, sizeof(int));

    // Aloca memória para a string de resultado que conterá o percurso
    char* resultado = (char*)calloc(1024, sizeof(char)); // Pode ser ajustado conforme o tamanho esperado

    // Chamada recursiva da DFS a partir do vértice inicial
    DFSRecursivo(grafo, inicio, visitado, resultado);

    free(visitado);

    return resultado;
}

char* BFS(Grafo* grafo, int inicio) {

    // Vetor para marcar vértices visitados, inicializado com 0
    int* visitado = (int*)calloc(grafo->numeroVertices, sizeof(int));

    // Fila para controle da ordem de visita dos vértices (BFS)
    int* fila = (int*)malloc(sizeof(int) * grafo->numeroVertices);

    // Índices para frente e traseira da fila
    int frente = 0, tras = 0;

    char* resultado = (char*)calloc(1024, sizeof(char));

    // Adiciona vértice inicial à fila e marca como visitado
    fila[tras++] = inicio;
    visitado[inicio] = 1;

    // Enquanto houver vértices na fila
    while (frente < tras) {

        // Remove vértice da frente da fila
        int atual = fila[frente++];

        // Obtém antena correspondente ao vértice atual
        Antena* a = grafo->antenas[atual];

        // Prepara string com id e coordenadas da antena
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d(%d,%d) ", atual, a->posicaoX, a->posicaoY);

        // Adiciona ao resultado final
        strcat(resultado, buffer);

        // Percorre lista de adjacência do vértice atual
        for (Adjacencia* adj = grafo->adjacencia[atual]; adj; adj = adj->proxima) {

            // Se o vértice adjacente ainda não foi visitado adiciona à fila e marca como visitado
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
/// Função auxiliar recursiva para encontrar caminhos entre dois vértices de um grafo.
/// Esta função é chamada internamente pela função principal e utiliza busca em profundidade (DFS).
/// </summary>
/// <param name="grafo"></param>
/// <param name="atual"></param>
/// <param name="destino"></param>
/// <param name="visitado"></param>
/// <param name="caminho"></param>
/// <param name="nivel"></param>
/// <param name="resultado"></param>
void CaminhosRecursivo(Grafo* grafo, int atual, int destino, int* visitado, int* caminho, int nivel, char* resultado) {
    visitado[atual] = 1;                      // Marca o vértice atual como visitado
    caminho[nivel++] = atual;                // Adiciona o vértice atual ao caminho atual e incrementa o nível

    if (atual == destino) {                  // Se o vértice atual é o destino
        char buffer[256] = "";               // Inicializa um buffer temporário para armazenar o caminho
        for (int i = 0; i < nivel; i++) {
            Antena* a = grafo->antenas[caminho[i]]; // Obtém a antena correspondente ao vértice do caminho
            char passo[32];
            snprintf(passo, sizeof(passo), "%d(%d,%d) ", caminho[i], a->posicaoX, a->posicaoY); // Formata o passo
            strcat(buffer, passo);           // Adiciona o passo ao buffer
        }
        strcat(buffer, "\n");                // Adiciona quebra de linha após o caminho
        strcat(resultado, buffer);           // Junta o buffer ao resultado final
    }
    else {
        // Explora recursivamente os vértices adjacentes não visitados
        for (Adjacencia* adj = grafo->adjacencia[atual]; adj; adj = adj->proxima) {
            if (!visitado[adj->destino]) {
                CaminhosRecursivo(grafo, adj->destino, destino, visitado, caminho, nivel, resultado);
            }
        }
    }

    visitado[atual] = 0;                     // Backtracking: desmarca o vértice atual para permitir outros caminhos
}

/// <summary>
/// Função responsável por encontrar todos os caminhos possíveis entre duas antenas em um grafo.
/// </summary>
/// <param name="grafo"></param>
/// <param name="inicio"></param>
/// <param name="fim"></param>
/// <returns>string com todos os caminhos, onde cada linha representa um caminho diferente.</returns>
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim) {

    // Verifica se os parâmetros são válidos
    if (!grafo || inicio < 0 || fim < 0 ||
        inicio >= grafo->numeroVertices || fim >= grafo->numeroVertices)
        return NULL;

    // Aloca memória para o vetor de visitados
    int* visitado = (int*)calloc(grafo->numeroVertices, sizeof(int));

    // Aloca vetor para armazenar o caminho atual durante a recursão
    int* caminho = (int*)malloc(sizeof(int) * grafo->numeroVertices);
    char* resultado = (char*)calloc(4096, sizeof(char)); 

    // Inicia a chamada recursiva para encontrar os caminhos
    CaminhosRecursivo(grafo, inicio, fim, visitado, caminho, 0, resultado);

    free(visitado);
    free(caminho);

    return resultado;
}
