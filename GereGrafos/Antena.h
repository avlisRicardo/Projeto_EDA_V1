/*
*	@file	antena.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef ANTENA_H
#define ANTENA_H

#include "Grafo.h"
#include "Antena.h"
#include "Adjacencia.h"

//  Estrutura antena
typedef struct {
    int codigoAntena;
    int posicaoX, posicaoY;
    char frequencia;
    int visitado;

    struct Antena* proximaAntena;
	struct Adjacencia* adjacencias;    //  lista ligada de adjacencias
} Antena;

//  Função responsável por criar antena
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia, int* erro);

//  Função responsável por adicionar uma nova antena ao grafo
int AdicionarAntena(Grafo* grafo, Antena* novaAntena);

//  Função responsável pela pesquisa de determinada antena por id
Antena* GetAntenaPorID(Grafo* grafo, int idAntena, int* erro);

//  Procedimento responsável por liberar memória de determinada antena
//  retorna 1 se a antena foi libertada com sucesso, 0 se o ponteiro era NULL
int RemoverAntena(Grafo* grafo, int idAntena);

//  Função responsável por verificar antenas com as mesmas coordenadas
int VerificaCoordenada(Antena* a1, Antena* a2);

//  Função responsável por verificar antenas com a mesma frequencia
int VerificaFrequencia(Antena* a1, Antena* a2);

#endif
