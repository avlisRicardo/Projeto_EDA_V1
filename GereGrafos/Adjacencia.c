/*
*	@file	Adjacencia.C
*	@brief  Trata-se de um módulo que contém as funções responsáveis por criar e remover adjacências
* 		    que representam as arestas do grafo.
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date   2025-05-12
*/

#include "Adjacencia.h"
#include "Antena.h" 
#include <stdlib.h>
#include "pch.h"

/// <summary>
/// Função responsável por criar uma nova adjacência (ligação entre antenas) no grafo
/// Destino - indica sempre o caminho da aresta
/// </summary>
/// <param name="destino">Índice da antena de destino a ser ligada</param>
/// <returns>Apontador para adjacencia criada ou NULL em caso de falha</returns>
Adjacencia* CriaAdjacencia(Antena* antenaOrigem, Antena* antenaDestino) {

	//  Verifica se os ponteiros de origem e destino são válidos
    if (!antenaOrigem || !antenaDestino)
        return 0;

    //  Aloca memória
    Adjacencia* nova = (Adjacencia*)malloc(sizeof(Adjacencia));

    //  Trata null
    if (!nova) 
        return 0;

    nova->destino = antenaDestino;
    nova->proxima = antenaOrigem->adjacencias;
    antenaOrigem->adjacencias = nova;

    return nova;
}

/// <summary>
/// Procedimento responsável por remover determinada adjacencia
/// Recebe o inicio da lista
/// </summary>
/// <param name="inicioLista"></param>
int RemoveAdjacencia(Antena* antenaOrigem, int idDestino) {

	//  Verifica se a origem é válida
    if (!antenaOrigem)
        return 0;

    Adjacencia* atual = antenaOrigem->adjacencias;
    Adjacencia* anterior = NULL;

    while (atual) {
        if (atual->destino->codigoAntena == idDestino) {    /// ver este caso !!!!!!    (definição estrutura)
            if (anterior) {
                anterior->proxima = atual->proxima;
            }
            else {
                antenaOrigem->adjacencias = atual->proxima;
            }

            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->proxima;
    }

    return 0;
}
