/*
*	@file	OPERACOES.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de grafos
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef OPERACOES_H
#define OPERACOES_H

#include "Grafo.h"

///	Fun��o respons�vel pela pesquisa em profundidade de determinado grafo
char* DFS(Grafo* grafo, int codigoInicial);

void DFSRecursivo(Antena* antena, char* resultado);

///	Fun��o respons�vel pela pesquisa em largura de determinado grafo
char* BFS(Grafo* grafo, int codigoInicial);

///	Fun��o respons�vel por encontrar todos os caminhos poss�veis entre duas antenas em um grafo.
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim);

///	Fun��o respons�vel pela procura de caminhos entre antenas
void ProcuraCaminhoEntreAntenas(Antena* atual, Antena* destino, int* visitado, int* caminho, int nivel, char* resultado);

#endif
