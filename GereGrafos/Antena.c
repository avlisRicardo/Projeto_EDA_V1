/*
*	@file	Antena.C
*	@brief	
* 			Aloca��o din�mica de mem�ria
*           Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Mar�o 2025
*/

#include <stdlib.h>
#include "antena.h"
#include "grafo.h"
#include "pch.h"

/// <summary>
/// Fun��o respons�vel por criar uma nova antena com os dados fornecidos.
/// </summary>
/// <param name="codigoAntena">Identificador �nico da antena</param>
/// <param name="posicaoX">Coordenada X da antena</param>
/// <param name="posicaoY">Coordenada Y da antena</param>
/// <param name="frequencia">Frequ�ncia da antena (representada por um caractere)</param>
/// <returns>Apontador para a nova estrutura Antena ou NULL em caso de erro</returns>
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia, int* erro) {
    
    //  Aloca mem�ria
    Antena* antena = malloc(sizeof(Antena));

    //  Trata caso de erro
    if (!antena) {
        if (erro)
            *erro = 1; // Indica erro de aloca��o
        return NULL;
    }
    
    //  Atribui valores antena
    antena->codigoAntena = codigoAntena;
    antena->posicaoX = posicaoX;
    antena->posicaoY = posicaoY;
    antena->frequencia = frequencia;

    return antena;
}

/// <summary>
/// Fun��o respons�vel por adicionar uma nova antena ao grafo
/// </summary>
/// <param name="grafo"></param>
/// <param name="novaAntena"></param>
/// <returns></returns>
int AdicionarAntena(Grafo* grafo, Antena* novaAntena) {

	// Verifica se o grafo e a antena s�o v�lidos
    if (!grafo || !novaAntena)
        return 0;

    // Inserir no in�cio da lista
    novaAntena->proximaAntena = grafo->listaAntenas;
    grafo->listaAntenas = novaAntena;

    return 1;
}

/// <summary>
/// Fun��o respons�vel pela pesquisa de determinada antena por id
/// </summary>
/// <param name="grafo"></param>
/// <param name="idAntena"></param>
/// <returns></returns>
Antena* GetAntenaPorID(Grafo* grafo, int idAntena, int* erro) {
    
	// Verifica se o grafo � v�lido
    if (!grafo) {
        if (erro) *erro = 1;
        return NULL;
    }

    Antena* atual = grafo->listaAntenas;
    while (atual) {
        if (atual->codigoAntena == idAntena) {
            if (erro) 
                *erro = 0;

            return atual;
        }
        atual = atual->proximaAntena;
    }


    if (erro)
        *erro = 2;

    return NULL; // Antena n�o encontrada
}

/// <summary>
/// Fun��o respons�vel por libertar a mem�ria ocupada por uma antena.
/// </summary>
/// <param name="antena">Apontador para a estrutura Antena a ser apagada</param>
/// <returns>1 se a antena foi libertada com sucesso, 0 se o ponteiro era NULL</returns>
int RemoverAntena(Grafo* grafo, int idAntena) {

	// Verifica se o grafo � v�lido
    if (!grafo)
        return 0;

	// Procura a antena na lista ligada
    Antena* atual = grafo->listaAntenas;
    Antena* anterior = NULL;

    while (atual) {

        //  se codigo antena igual ao c�digo pretendido
        if (atual->codigoAntena == idAntena) {

            // Remove da lista ligada
            if (anterior)
                anterior->proximaAntena = atual->proximaAntena;
            else
                grafo->listaAntenas = atual->proximaAntena;

            // Liberta adjac�ncias da antena
            Adjacencia* adj = atual->adjacencias;
            while (adj) {
                Adjacencia* temp = adj;
                adj = adj->proxima;
                free(temp);
            }

            // Liberta antena
            free(atual);

            return 1;
        }

        anterior = atual;
        atual = atual->proximaAntena;
    }

    return 0;
}

/// <summary>
/// Fun��o respons�vel por comparar coordenadas de duas antenas distintas
/// </summary>
/// <param name="a1">antena 1</param>
/// <param name="a2">antena 2</param>
/// <returns>
/// 1 - se duas antenas estiverem na mesma posi��o  
/// 0 - caso contr�rio ou se algum ponteiro for NULL
/// </returns>
int VerificaCoordenada(Antena* a1, Antena* a2) {
    if (!a1 || !a2)
        return 0;

    return a1->posicaoX == a2->posicaoX && a1->posicaoY == a2->posicaoY;
}

/// <summary>
/// Fun��o respons�vel por comparar se duas antenas t�m a mesma frequ�ncia
/// </summary>
/// <param name="a1">Antena 1</param>
/// <param name="a2">Antena 2</param>
/// <returns>
/// 1 - se as duas antenas tiverem a mesma frequ�ncia  
/// 0 - caso contr�rio ou se algum dos ponteiros for inv�lido
/// </returns>
int VerificaFrequencia(Antena* a1, Antena* a2) {
    if (!a1 || !a2)
        return 0;
    return a1->frequencia == a2->frequencia;
}
