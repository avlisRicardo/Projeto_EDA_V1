/*
*	@file	adjacencia.c
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "Adjacencia.h"
#include "Grafo.h"
#include <cstddef>

/// <summary>
/// Adiciona uma aresta entre duas antenas (de mesma frequ�ncia) e retorna ponteiro para a aresta criada
/// </summary>
/// <param name="grafo"></param>
/// <param name="origem"></param>
/// <param name="destino"></param>
/// <returns>Apontador para a nova adjacencia</returns>
Adjacencia* AdicionarAresta(Grafo* grafo, int origem, int destino) {
    if (origem >= grafo->numeroVertices || destino >= grafo->numeroVertices)
        return NULL;

    Antena* antena1 = grafo->antenas[origem];
    Antena* antena2 = grafo->antenas[destino];

    if (!antena1 || !antena2) return NULL;
    if (antena1->frequencia != antena2->frequencia) return NULL;

    // Verifica se aresta j� existe (opcional)
    for (Adjacencia* atual = grafo->adjacencia[origem]; atual != NULL; atual = atual->proxima)
        if (atual->destino == destino)
            return NULL;

    Adjacencia* nova = (Adjacencia*)malloc(sizeof(Adjacencia));
    nova->destino = destino;
    nova->proxima = grafo->adjacencia[origem];
    grafo->adjacencia[origem] = nova;

    return nova;
}