/*
*	@file	DFS.c
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de DFS
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "DepthFirstSearch.h"
#include "Grafo.h"
#include <cstddef>

/// <summary>
/// Fun��o recursiva DFS que preenche vetor com os n�s visitados
/// </summary>
/// <param name="grafo">ponteiro para o grafo</param>
/// <param name="atual">�ndice do v�rtice atual</param>
/// <param name="visitado">vetor de visitados (1 = visitado, 0 = n�o)</param>
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
/// Fun��o principal que inicia a DFS
/// </summary>
/// <param name="grafo"></param>
/// <param name="origem"></param>
/// <returns>
/// Retorna vetor de v�rtices visitados (1 = visitado, 0 = n�o)
/// </returns>
int* Dfs(Grafo* grafo, int origem) {

    //  Verifica��o erros
    if (grafo == NULL || origem < 0 || origem >= grafo->numeroVertices) return NULL;

    int* visitado = criarVisitado(g->numVertices);
    DfsRecursivo(grafo, origem, visitado);
    return visitado;
}