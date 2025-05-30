/*
*	@file	Grafo.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef GRAFO_H
#define GRAFO_H

#include "Antena.h"

//  Estrutura Grafo
typedef struct {
    int numeroVertices;
	Antena* listaAntenas;	//  lista ligada de vértices
} Grafo;

//  Função responsável por criar grafo
Grafo* CriarGrafo();

//  Função responsável por libertar grafo de memória
//  Retorna 1 se foi libertado com sucesso, 0 se grafo era NULL
int RemoveGrafo(Grafo* grafo, int* erro);

#endif