/*
*	@file	Antena.C
*	@brief	
* 			Alocação dinâmica de memória
*           Implementação de funções de manipulação de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#include <stdlib.h>
#include "antena.h"
#include "grafo.h"
#include "pch.h"

/// <summary>
/// Função responsável por criar uma nova antena com os dados fornecidos.
/// </summary>
/// <param name="codigoAntena">Identificador único da antena</param>
/// <param name="posicaoX">Coordenada X da antena</param>
/// <param name="posicaoY">Coordenada Y da antena</param>
/// <param name="frequencia">Frequência da antena (representada por um caractere)</param>
/// <returns>Apontador para a nova estrutura Antena ou NULL em caso de erro</returns>
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia, int* erro) {
    
    //  Aloca memória
    Antena* antena = malloc(sizeof(Antena));

    //  Trata caso de erro
    if (!antena) {
        if (erro)
            *erro = 1; // Indica erro de alocação
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
/// Função responsável por adicionar uma nova antena ao grafo
/// </summary>
/// <param name="grafo"></param>
/// <param name="novaAntena"></param>
/// <returns></returns>
int AdicionarAntena(Grafo* grafo, Antena* novaAntena) {

	// Verifica se o grafo e a antena são válidos
    if (!grafo || !novaAntena)
        return 0;

    // Inserir no início da lista
    novaAntena->proximaAntena = grafo->listaAntenas;
    grafo->listaAntenas = novaAntena;

    return 1;
}

/// <summary>
/// Função responsável pela pesquisa de determinada antena por id
/// </summary>
/// <param name="grafo"></param>
/// <param name="idAntena"></param>
/// <returns></returns>
Antena* GetAntenaPorID(Grafo* grafo, int idAntena, int* erro) {
    
	// Verifica se o grafo é válido
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

    return NULL; // Antena não encontrada
}

/// <summary>
/// Função responsável por libertar a memória ocupada por uma antena.
/// </summary>
/// <param name="antena">Apontador para a estrutura Antena a ser apagada</param>
/// <returns>1 se a antena foi libertada com sucesso, 0 se o ponteiro era NULL</returns>
int RemoverAntena(Grafo* grafo, int idAntena) {

	// Verifica se o grafo é válido
    if (!grafo)
        return 0;

	// Procura a antena na lista ligada
    Antena* atual = grafo->listaAntenas;
    Antena* anterior = NULL;

    while (atual) {

        //  se codigo antena igual ao código pretendido
        if (atual->codigoAntena == idAntena) {

            // Remove da lista ligada
            if (anterior)
                anterior->proximaAntena = atual->proximaAntena;
            else
                grafo->listaAntenas = atual->proximaAntena;

            // Liberta adjacências da antena
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
/// Função responsável por comparar coordenadas de duas antenas distintas
/// </summary>
/// <param name="a1">antena 1</param>
/// <param name="a2">antena 2</param>
/// <returns>
/// 1 - se duas antenas estiverem na mesma posição  
/// 0 - caso contrário ou se algum ponteiro for NULL
/// </returns>
int VerificaCoordenada(Antena* a1, Antena* a2) {
    if (!a1 || !a2)
        return 0;

    return a1->posicaoX == a2->posicaoX && a1->posicaoY == a2->posicaoY;
}

/// <summary>
/// Função responsável por comparar se duas antenas têm a mesma frequência
/// </summary>
/// <param name="a1">Antena 1</param>
/// <param name="a2">Antena 2</param>
/// <returns>
/// 1 - se as duas antenas tiverem a mesma frequência  
/// 0 - caso contrário ou se algum dos ponteiros for inválido
/// </returns>
int VerificaFrequencia(Antena* a1, Antena* a2) {
    if (!a1 || !a2)
        return 0;
    return a1->frequencia == a2->frequencia;
}
