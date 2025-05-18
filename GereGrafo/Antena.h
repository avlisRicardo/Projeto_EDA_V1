/*
*	@file	antena.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
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

//	Adiciona uma antena ao grafo na posição especificada
Antena* AdicionarAntena(Grafo* grafo, int id, int posicaoX, int posicaoY, char frequencia);

//	Função responsável por disponibilizar lista de antenas sob a forma lista
char* ListarAntenas(Grafo* grafo);

//	Função responsável por listar interseção entre duas frequencias
char* ListaIntersecaoFrequencias(Grafo* g, char frequencia1, char frequencia2);