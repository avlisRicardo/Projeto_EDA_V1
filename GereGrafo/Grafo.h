/*
*	@file	Grafo.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "Antena.h"
#include "Adjacencia.h"

//	struct grafo
typedef struct Grafo {
	int numeroVertices;
	Antena** antenas;
	Adjacencia** adjacencia;
} Grafo;

//	Fun��o respons�vel por criar determiando grafo
Grafo* CriaGrafo(int numeroVertices);

// Fun��o respons�vel por limpar determinado grado
int LimparGrafo(Grafo* g);
