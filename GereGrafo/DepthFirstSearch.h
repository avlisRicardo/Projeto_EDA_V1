/*
*	@file	Grafo.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de DFS
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

/// Função recursiva DFS que preenche vetor com os nós visitados
void DfsRecursivo(Grafo* grafo, int atual, int* visitado);

// Função principal que inicia a DFS
int* Dfs(Grafo* grafo, int origem);