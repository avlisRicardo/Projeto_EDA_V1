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
#include <cstddef>

/// <summary>
/// Função responsável por criar um grafo com um número fixo de vértices
/// </summary>
/// <returns>Apontador para o grafo criado ou NULL em caso de erro</returns>
Grafo* CriarGrafo() {
   
    //  alocação de memória
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

	if (!grafo) {
		return NULL; // Falha na alocação de memória
	}

	return grafo;
}

/// <summary>
/// Liberta os recursos de um grafo e indica sucesso
/// </summary>
/// <param name="grafo">Ponteiro para o grafo</param>
/// <returns>1 se foi libertado com sucesso, 0 se grafo era NULL</returns>
int RemoveGrafo(Grafo* grafo, int* erro) {

	if (!grafo) {
        if (erro)
			*erro = 1; // Indica erro se o grafo é NULL

		return 0; // Grafo era NULL, não há nada a libertar
	} 

    Antena* antenaAtual = grafo->listaAntenas;

    while (antenaAtual) {

        // Guardar próximo antes de libertar
        Antena* proximaAntena = antenaAtual->proximaAntena;

        // Liberta adjacências
        Adjacencia* adjacencia = antenaAtual->adjacencias;
        while (adjacencia) {
            Adjacencia* adjacenciaAux = adjacencia;
            adjacencia = adjacencia->proxima;
            free(adjacenciaAux);
        }

        // Libertar a antena
        free(antenaAtual);

        // Passar para a próxima antena
        antenaAtual = proximaAntena;
    }

    // Libertar a estrutura principal do grafo
    free(grafo);

	if (erro)
		*erro = 0; // Indica sucesso na libertação

    return 1;
}


