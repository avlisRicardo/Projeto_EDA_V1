/*
*	@file	Antena.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
* 
*	@Author	Ricardo Silva
*	@date	Mar�o 2025
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

//	Fun��o respons�vel por cria nova antena
Antena* CriaAntena(char frequencia, int coordenadaX, int coordenadaY);

//	Fun��o respons�vel por adicionar antena a lista de antenas
Antena* AdicionarAntena(Antena* listaAntenas, char frequencia, int coordenadaX, int coordenadaY);

//	Procedimento respons�vel pela apresenta��o de antenas ao utilizador
void ApresentaAntenas(Antena* listaAntenas);

//	Fun��o respons�vel por verificar alinhamento entre duas antenas
int VerificaAlinhamento(Antena* a, Antena* b);