/*
*	@file	Ficheiros.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de matriz de determinada Anterna
*			Guarda e trata dimens�o de determinada matriz
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef FICHEIRO_H
#define FICHEIRO_H

#include "Grafo.h"

//	Fun��o respons�vel por carregar determinado grafo contido em ficheiro
Grafo* CarregarGrafoFicheiro(const char* nomeFicheiro, int* erro);

#endif
