/*
*	@file	AntenaArquivo.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de matriz de determinada Anterna
*			Guarda e trata dimensão de determinada matriz
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Antena.h"

//	struct matriz dimensão
typedef struct MatrizDimensao {
	int quantidadeLinhas;
	int quantidadeColunas;
} MatrizDimensao;

//	Função responsável por carregar matriz de antenas de determinado arquivo
Antena* CarregaAntenasArquivo(const char* nomeArquivo, MatrizDimensao* dimensao);