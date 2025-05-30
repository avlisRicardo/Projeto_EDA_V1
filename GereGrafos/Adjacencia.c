/*
*	@file	Adjacencia.C
*	@brief  Trata-se de um m�dulo que cont�m as fun��es respons�veis por criar e remover adjac�ncias
* 		    que representam as arestas do grafo.
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date   2025-05-12
*/

#include "Adjacencia.h"
#include "Antena.h" 
#include <stdlib.h>
#include "pch.h"

/// <summary>
/// Fun��o respons�vel por criar uma nova adjac�ncia (liga��o entre antenas) no grafo
/// Destino - indica sempre o caminho da aresta
/// </summary>
/// <param name="destino">�ndice da antena de destino a ser ligada</param>
/// <returns>Apontador para adjacencia criada ou NULL em caso de falha</returns>
Adjacencia* CriaAdjacencia(Antena* antenaOrigem, Antena* antenaDestino) {

	//  Verifica se os ponteiros de origem e destino s�o v�lidos
    if (!antenaOrigem || !antenaDestino)
        return 0;

    //  Aloca mem�ria
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
/// Procedimento respons�vel por remover determinada adjacencia
/// Recebe o inicio da lista
/// </summary>
/// <param name="inicioLista"></param>
int RemoveAdjacencia(Antena* antenaOrigem, int idDestino) {

	//  Verifica se a origem � v�lida
    if (!antenaOrigem)
        return 0;

    Adjacencia* atual = antenaOrigem->adjacencias;
    Adjacencia* anterior = NULL;

    while (atual) {
        if (atual->destino->codigoAntena == idDestino) {    /// ver este caso !!!!!!    (defini��o estrutura)
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
