/*
*	@file	Operacoes.C
*	@brief	Trata-se de um módulo que contém funções para manipulação de grafos
*   como a pesquisa em profundidade (DFS) e a pesquisa em largura (BFS).
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date   2025-05-12
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Antena.h"
#include "Grafo.h"

#define MAX_ANTENAS 1000 // Definindo um tamanho máximo para o número de antenas

/// <summary>
/// Procedimento auxiliar utilizada para realizar a Procura em Profundidade
/// </summary>
/// <param name="g">grafo</param>
/// <param name="v">vértice</param>
/// <param name="visitado">0 ou 1</param>
/// <param name="resultado"></param>
void DFSRecursivo(Antena* antena, char* resultado) {

	// Buffer auxiliar para armazenar o ID da antena
    char buffer[32];

	// Verifica se a antena é nula ou já foi visitada
    if (!antena || antena->visitado)
        return;

	// Marca a antena como visitada
    antena->visitado = 1;

	// Adiciona o ID da antena ao resultado
    for (Adjacencia* adj = antena->adjacencias; adj; adj = adj->proxima) {
        DFSRecursivo(adj->antena, resultado);
    }
}

/// <summary>
/// Função responsável pela pesquisa recursiva do grafo em profundidade (DFS).
/// </summary>
/// <param name="grafo">Apontador para o grafo onde será realizada a pesquisa</param>
/// <param name="inicio">Índice da antena de onde se inicia a pesquisa</param>
/// <returns>String com o caminho percorrido no formato "id(x,y) "</returns>
char* DFS(Grafo* grafo, int codigoInicial) {

    // Procurar antena inicial
    Antena* inicial = BuscarAntenaPorID(grafo, codigoInicial);
    if (!inicial) return NULL;

    // Alocar resultado
    char* resultado = (char*)calloc(1024, sizeof(char));  // ou realloc se crescer muito

    // Fazer reset ao campo visitado de todas as antenas
    Antena* atual = grafo->listaAntenas;
    while (atual) {
        atual->visitado = 0;
        atual = atual->proximaAntena;
    }

    // Iniciar DFS
    DFSRecursivo(inicial, resultado);

    return resultado;
}

/// <summary>
/// Função responsável pela pesquisa em largura (BFS) de um grafo.
/// </summary>
/// <param name="grafo"></param>
/// <param name="codigoInicial"></param>
/// <returns></returns>
char* BFS(Grafo* grafo, int codigoInicial) {
    
    Antena* origem = BuscarAntenaPorID(grafo, codigoInicial);
    if (!origem) return NULL;

    // Marcar todas as antenas como não visitadas
    for (Antena* a = grafo->listaAntenas; a != NULL; a = a->proximaAntena) {
        a->visitado = 0;
    }

}

/// <summary>
/// Função responsável por encontrar todos os caminhos possíveis entre duas antenas em um grafo.
/// </summary>
/// <param name="grafo"></param>
/// <param name="inicio"></param>
/// <param name="fim"></param>
/// <returns>string com todos os caminhos, onde cada linha representa um caminho diferente.</returns>
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim) {
        
    int* visitado = calloc(MAX_ANTENAS, sizeof(int));
    int* caminho = malloc(MAX_ANTENAS * sizeof(int));
    char* resultado = calloc(2048, sizeof(char));

    ProcuraCaminhoEntreAntenas(inicio, fim, visitado, caminho, 0, resultado);

    free(visitado);
    free(caminho);
    return resultado;
}

/// <summary>
/// Função responsável pela procura de todos os caminhos possíveis entre duas antenas
/// </summary>
/// <param name="atual"></param>
/// <param name="destino"></param>
/// <param name="visitado"></param>
/// <param name="caminho"></param>
/// <param name="nivel"></param>
/// <param name="resultado"></param>
void ProcuraCaminhoEntreAntenas(Antena* atual, Antena* destino, int* visitado, int* caminho, int nivel, char* resultado) {

    visitado[atual->codigoAntena] = 1;          // Marca como visitado
    caminho[nivel] = atual->codigoAntena;       // Adiciona ao caminho atual
	nivel++;                                    // Incrementa o nível

    if (atual == destino) {

        // Se chegou ao destino, constrói a string do caminho
        char buffer[256] = "";
        for (int i = 0; i < nivel; i++) {
            char passo[16];
            snprintf(passo, sizeof(passo), "%d ", caminho[i]);
            strcat(buffer, passo);
        }
        strcat(buffer, "\n");
        strcat(resultado, buffer);  // Adiciona ao resultado final
    }
    else {

        // Explora todos os vizinhos (adjacentes)
        for (Adjacencia* adj = atual->adjacencias; adj; adj = adj->proxima) {
            if (!visitado[adj->antena->codigoAntena]) {
                CaminhosSimples(adj->antena, destino, visitado, caminho, nivel, resultado);
            }
        }
    
    }

	visitado[atual->codigoAntena] = 0;  // Marca como não visitado para permitir outros caminhos
}