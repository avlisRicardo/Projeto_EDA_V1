/*
*	@file	BFS.c
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de BFS
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "Grafo.h"

/// <summary>
/// Função responsável por cria string com o percurso BFS
/// </summary>
/// <param name="g"></param>
/// <param name="inicio"></param>
/// <returns>string com percurso BFS</returns>
char* Bfs(Grafo* g, int inicio) {
    int* visitado = (int*)calloc(g->numeroVertices, sizeof(int));
    int* fila = (int*)malloc(sizeof(int) * g->numeroVertices);
    int frente = 0, tras = 0;
    char* buffer = (char*)malloc(2048);
    int offset = 0;

    visitado[inicio] = 1;
    fila[tras++] = inicio;

    while (frente < tras) {
        int atual = fila[frente++];
        Antena* a = g->antenas[atual];
        offset += sprintf(buffer + offset, "Visitado BFS: Antena %d - (%d, %d)\n", a->codigoAntena, a->posicaoX, a->posicaoY);

        for (Adjacencia* adj = g->adjacencia[atual]; adj != NULL; adj = adj->proxima) {
            if (!visitado[adj->destino]) {
                visitado[adj->destino] = 1;
                fila[tras++] = adj->destino;
            }
        }
    }

    free(fila);
    free(visitado);
    return buffer;
}