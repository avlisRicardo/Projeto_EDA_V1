/*
*	@file	Grafo.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de DFS
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

/// Fun��o recursiva DFS que preenche vetor com os n�s visitados
void DfsRecursivo(Grafo* grafo, int atual, int* visitado);

// Fun��o principal que inicia a DFS
int* Dfs(Grafo* grafo, int origem);