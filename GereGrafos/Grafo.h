/*
*	@file	Grafo.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
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
	Antena* listaAntenas;	//  lista ligada de v�rtices
} Grafo;

//  Fun��o respons�vel por criar grafo
Grafo* CriarGrafo();

//  Fun��o respons�vel por libertar grafo de mem�ria
//  Retorna 1 se foi libertado com sucesso, 0 se grafo era NULL
int RemoveGrafo(Grafo* grafo, int* erro);

#endif