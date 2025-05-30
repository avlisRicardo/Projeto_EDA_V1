/*
*	@file	Grafo.c
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "Grafo.h"
#include <cstddef>

/// <summary>
/// Fun��o respons�vel por criar um grafo com um n�mero fixo de v�rtices
/// </summary>
/// <returns>Apontador para o grafo criado ou NULL em caso de erro</returns>
Grafo* CriarGrafo() {
   
    //  aloca��o de mem�ria
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

	if (!grafo) {
		return NULL; // Falha na aloca��o de mem�ria
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
			*erro = 1; // Indica erro se o grafo � NULL

		return 0; // Grafo era NULL, n�o h� nada a libertar
	} 

    Antena* antenaAtual = grafo->listaAntenas;

    while (antenaAtual) {

        // Guardar pr�ximo antes de libertar
        Antena* proximaAntena = antenaAtual->proximaAntena;

        // Liberta adjac�ncias
        Adjacencia* adjacencia = antenaAtual->adjacencias;
        while (adjacencia) {
            Adjacencia* adjacenciaAux = adjacencia;
            adjacencia = adjacencia->proxima;
            free(adjacenciaAux);
        }

        // Libertar a antena
        free(antenaAtual);

        // Passar para a pr�xima antena
        antenaAtual = proximaAntena;
    }

    // Libertar a estrutura principal do grafo
    free(grafo);

	if (erro)
		*erro = 0; // Indica sucesso na liberta��o

    return 1;
}


