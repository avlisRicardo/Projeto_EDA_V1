/*
*	@file	adjacencia.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

//	struct adjacencia
typedef struct Adjacencia {
	int destino;
	struct Adjacencia* proxima;
} Adjacencia;

/// Adiciona uma aresta entre duas antenas (de mesma frequ�ncia) e retorna ponteiro para a aresta criada
Adjacencia* AdicionarAresta(Grafo* grafo, int origem, int destino);
