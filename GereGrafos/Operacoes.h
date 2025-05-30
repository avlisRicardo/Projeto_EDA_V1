/*
*	@file	OPERACOES.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef OPERACOES_H
#define OPERACOES_H

#include "Grafo.h"

///	Função responsável pela pesquisa em profundidade de determinado grafo
char* DFS(Grafo* grafo, int codigoInicial);

void DFSRecursivo(Antena* antena, char* resultado);

///	Função responsável pela pesquisa em largura de determinado grafo
char* BFS(Grafo* grafo, int codigoInicial);

///	Função responsável por encontrar todos os caminhos possíveis entre duas antenas em um grafo.
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim);

///	Função responsável pela procura de caminhos entre antenas
void ProcuraCaminhoEntreAntenas(Antena* atual, Antena* destino, int* visitado, int* caminho, int nivel, char* resultado);

#endif
