/*
*	@file	Grafo.c
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "Grafo.h"
#include "Adjacencia.h"
#include <cstddef>

/// <summary>
/// Função responsável por criar grafos
/// </summary>
/// <param name="numVertices"></param>
/// <returns>Apontador para grafo criado</returns>
Grafo* CriaGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numeroVertices = numVertices;
    grafo->antenas = (Antena**)malloc(sizeof(Antena*) * numVertices);
    grafo->adjacencia = (Adjacencia**)malloc(sizeof(Adjacencia*) * numVertices);

    for (int i = 0; i < numVertices; i++) {
        grafo->antenas[i] = NULL;
        grafo->adjacencia[i] = NULL;
    }

    return grafo;
}

/// <summary>
/// Função responsável por limpar determinado grado
/// </summary>
/// <param name="g"></param>
/// <returns>
/// 1   -   sucesso
/// 0   -   erro
/// </returns>
int LimparGrafo(Grafo* grafo) {

    //  valida erro
    if (!grafo) return 0;

    for (int i = 0; i < grafo->numeroVertices; i++) {
        if (grafo->antenas[i]) free(grafo->antenas[i]);

        Adjacencia* adj = grafo->adjacencia[i];
        while (adj) {
            Adjacencia* temp = adj;
            adj = adj->proxima;
            free(temp);
        }
    }

    free(g->antenas);
    free(g->adjacencia);
    free(g);

    return 1;
}
