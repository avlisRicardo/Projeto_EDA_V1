/*
*	@file	Antena.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
* 
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// Estrutura Antena
/// </summary>
typedef struct Antena {
	char frequencia;
	int coordenadaX;
	int coordenadaY;
	struct Antena* proximaAntena;
} Antena;

//	Função responsável por cria nova antena
Antena* CriaAntena(char frequencia, int coordenadaX, int coordenadaY);

//	Função responsável por adicionar antena a lista de antenas
Antena* AdicionarAntena(Antena* listaAntenas, char frequencia, int coordenadaX, int coordenadaY);

//	Procedimento responsável pela apresentação de antenas ao utilizador
void ApresentaAntenas(Antena* listaAntenas);

//	Função responsável por verificar alinhamento entre duas antenas
int VerificaAlinhamento(Antena* a, Antena* b);