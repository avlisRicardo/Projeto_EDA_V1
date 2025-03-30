/*
*	@file	AntenaArquivo.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de matriz de determinada Anterna
*			Guarda e trata dimens�o de determinada matriz
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Mar�o 2025
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Antena.h"

//	struct matriz dimens�o
typedef struct MatrizDimensao {
	int quantidadeLinhas;
	int quantidadeColunas;
} MatrizDimensao;

//	Fun��o respons�vel por carregar matriz de antenas de determinado arquivo
Antena* CarregaAntenasArquivo(const char* nomeArquivo, MatrizDimensao* dimensao);