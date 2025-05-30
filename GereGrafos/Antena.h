/*
*	@file	antena.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
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

//  Fun��o respons�vel por criar antena
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia, int* erro);

//  Fun��o respons�vel por adicionar uma nova antena ao grafo
int AdicionarAntena(Grafo* grafo, Antena* novaAntena);

//  Fun��o respons�vel pela pesquisa de determinada antena por id
Antena* GetAntenaPorID(Grafo* grafo, int idAntena, int* erro);

//  Procedimento respons�vel por liberar mem�ria de determinada antena
//  retorna 1 se a antena foi libertada com sucesso, 0 se o ponteiro era NULL
int RemoverAntena(Grafo* grafo, int idAntena);

//  Fun��o respons�vel por verificar antenas com as mesmas coordenadas
int VerificaCoordenada(Antena* a1, Antena* a2);

//  Fun��o respons�vel por verificar antenas com a mesma frequencia
int VerificaFrequencia(Antena* a1, Antena* a2);

#endif
