/*
*	@file	Ficheiros.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de matriz de determinada Anterna
*			Guarda e trata dimensão de determinada matriz
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef FICHEIRO_H
#define FICHEIRO_H

#include "Grafo.h"

//	Função responsável por carregar determinado grafo contido em ficheiro
Grafo* CarregarGrafoFicheiro(const char* nomeFicheiro, int* erro);

#endif
