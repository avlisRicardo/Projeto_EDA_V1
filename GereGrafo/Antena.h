/*
*	@file	antena.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

//	Estrutura Antena
typedef struct Antena {
	int codigoAntena;
	int posicaoX, posicaoY;
	char frequencia;
} Antena;

//	Adiciona uma antena ao grafo na posi��o especificada
Antena* AdicionarAntena(Grafo* grafo, int id, int posicaoX, int posicaoY, char frequencia);

//	Fun��o respons�vel por disponibilizar lista de antenas sob a forma lista
char* ListarAntenas(Grafo* grafo);

//	Fun��o respons�vel por listar interse��o entre duas frequencias
char* ListaIntersecaoFrequencias(Grafo* g, char frequencia1, char frequencia2);