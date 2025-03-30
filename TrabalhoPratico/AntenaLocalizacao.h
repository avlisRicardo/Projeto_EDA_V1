/*
*	@file	Antena.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Localização de determinada antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#include "Antena.h"

//	Estrutura de localização
typedef struct Localizacao {
	int coordendadaX;
	int coordendadaY;

	struct Localizacao* proximaLocalizacao;
} Localizacao;

//	Função responsável por cria nova localização
Localizacao* CriaLocalizacao(int coordenadaX, int coordenadaY);

//	Função reponsável por adicionar nova localizacao a lista de localizacaoes
Localizacao* AdicionarLocalizacao(Localizacao* listaLocalizacao, int coordenadaX, int coordenadaY);

//	Função responsável por calcular efeiro nefasco com base nos parametros sugeridos
Localizacao* CalcularEfeitoNefasto(Antena* listaAntenas);

//	Procedimento responsável por apresentar localizações
void ApresentaLocalizacoes(Localizacao* lista);
