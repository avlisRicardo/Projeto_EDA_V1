/*
*	@file	adjacencia.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

//	struct adjacencia
typedef struct Adjacencia {
	int destino;
	struct Adjacencia* proxima;
} Adjacencia;

/// Adiciona uma aresta entre duas antenas (de mesma frequência) e retorna ponteiro para a aresta criada
Adjacencia* AdicionarAresta(Grafo* grafo, int origem, int destino);
