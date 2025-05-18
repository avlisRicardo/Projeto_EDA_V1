/*
*	@file	Grafo.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
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

//	Função responsável por criar determiando grafo
Grafo* CriaGrafo(int numeroVertices);

// Função responsável por limpar determinado grado
int LimparGrafo(Grafo* g);
