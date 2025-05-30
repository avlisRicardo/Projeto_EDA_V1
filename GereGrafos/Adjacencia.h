/*	
*   @file	adjacencia.h
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#ifndef ADJACENCIA_H
#define ADJACENCIA_H

#include "Antena.h"

//  Estrutura Adjacencia
typedef struct Adjacencia {
    struct Antena* antena;          // Apontador para o vértice de destin
    struct Adjacencia* proxima;     // Próxima adjacência na lista ligada
} Adjacencia;

//  Função responsável por criar uma aresta
Adjacencia* CriaAdjacencia(Antena* antenaOrigem, Antena* antenaDestino);

//  Procedimento responsável por remover determinada adjacencia
//  Se removido alguma adjacencia, retorna 1, caso contrário 0
int RemoveAdjacencia(Antena* antenaOrigem, int idDestino);

#endif