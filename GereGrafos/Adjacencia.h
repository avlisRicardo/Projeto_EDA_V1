/*	
*   @file	adjacencia.h
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef ADJACENCIA_H
#define ADJACENCIA_H

#include "Antena.h"

//  Estrutura Adjacencia
typedef struct Adjacencia {
    struct Antena* antena;          // Apontador para o v�rtice de destin
    struct Adjacencia* proxima;     // Pr�xima adjac�ncia na lista ligada
} Adjacencia;

//  Fun��o respons�vel por criar uma aresta
Adjacencia* CriaAdjacencia(Antena* antenaOrigem, Antena* antenaDestino);

//  Procedimento respons�vel por remover determinada adjacencia
//  Se removido alguma adjacencia, retorna 1, caso contr�rio 0
int RemoveAdjacencia(Antena* antenaOrigem, int idDestino);

#endif