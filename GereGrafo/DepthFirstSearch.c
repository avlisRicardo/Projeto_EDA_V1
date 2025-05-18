/*
*	@file	DFS.c
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de DFS
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "DepthFirstSearch.h"
#include "Grafo.h"
#include <cstddef>

/// <summary>
/// Função recursiva DFS que preenche vetor com os nós visitados
/// </summary>
/// <param name="grafo">ponteiro para o grafo</param>
/// <param name="atual">índice do vértice atual</param>
/// <param name="visitado">vetor de visitados (1 = visitado, 0 = não)</param>
void DfsRecursivo(Grafo* grafo, int atual, int* visitado) {
    if (visitado[atual]) return;

    visitado[atual] = 1; // marca como visitado

    Adjacencia* adjacente = g->adj[atual];
    while (adjacente != NULL) {
        if (!visitado[adjacente->destino]) {
            dfsRec(g, adjacente->destino, visitado);
        }
        adjacente = adjacente->proxima;
    }
}

/// <summary>
/// Função principal que inicia a DFS
/// </summary>
/// <param name="grafo"></param>
/// <param name="origem"></param>
/// <returns>
/// Retorna vetor de vértices visitados (1 = visitado, 0 = não)
/// </returns>
int* Dfs(Grafo* grafo, int origem) {

    //  Verificação erros
    if (grafo == NULL || origem < 0 || origem >= grafo->numeroVertices) return NULL;

    int* visitado = criarVisitado(g->numVertices);
    DfsRecursivo(grafo, origem, visitado);
    return visitado;
}