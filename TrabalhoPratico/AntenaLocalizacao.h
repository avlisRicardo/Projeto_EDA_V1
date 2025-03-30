/*
*	@file	Antena.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Localiza��o de determinada antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Mar�o 2025
*/

#include "Antena.h"

//	Estrutura de localiza��o
typedef struct Localizacao {
	int coordendadaX;
	int coordendadaY;

	struct Localizacao* proximaLocalizacao;
} Localizacao;

//	Fun��o respons�vel por cria nova localiza��o
Localizacao* CriaLocalizacao(int coordenadaX, int coordenadaY);

//	Fun��o repons�vel por adicionar nova localizacao a lista de localizacaoes
Localizacao* AdicionarLocalizacao(Localizacao* listaLocalizacao, int coordenadaX, int coordenadaY);

//	Fun��o respons�vel por calcular efeiro nefasco com base nos parametros sugeridos
Localizacao* CalcularEfeitoNefasto(Antena* listaAntenas);

//	Procedimento respons�vel por apresentar localiza��es
void ApresentaLocalizacoes(Localizacao* lista);
