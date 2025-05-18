/*
*	@file	antena.c
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Antenas
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "Antena.h"
#include "Grafo.h"
#include <cstddef>

/// <summary>
/// Adiciona uma antena ao grafo na posi��o especificada
/// </summary>
/// <param name="grafo"></param>
/// <param name="id"></param>
/// <param name="posicaoX"></param>
/// <param name="posicaoY"></param>
/// <param name="frequencia"></param>
/// <returns>Apontador para a antena criada</returns>
Antena* AdicionarAntena(Grafo* grafo, int id, int posicaoX, int posicaoY, char frequencia) {

    //  teste erro
    if (id >= grafo->numeroVertices) return NULL;

    Antena* nova = (Antena*)malloc(sizeof(Antena));
    if (!nova) return NULL;

    nova->codigoAntena = id;
    nova->posicaoX = posicaoX;
    nova->posicaoY = posicaoY;
    nova->frequencia = frequencia;

    grafo->antenas[id] = nova;

    return nova;
}

/// <summary>
/// Fun��o respos�vel pela cria��o da lista de antenas em forma de string para visualiza��o externa
/// </summary>
/// <param name="grafo"></param>
/// <returns>lista de antenas sob forma de string</returns>
char* ListarAntenas(Grafo* grafo) {
    int capacidade = 1024;
    char* buffer = (char*)malloc(capacidade);
    if (!buffer) return NULL;
    buffer[0] = '\0';
    int offset = 0;

    for (int i = 0; i < grafo->numeroVertices; i++) {
        if (grafo->antenas[i]) {
            char linha[128];
            int len = snprintf(linha, sizeof(linha), "Antena %d: (%d, %d), Freq: %c\n",
                i, grafo->antenas[i]->posicaoX, grafo->antenas[i]->posicaoY, grafo->antenas[i]->frequencia);

            if (offset + len >= capacidade) {
                capacidade *= 2;
                buffer = (char*)realloc(buffer, capacidade);
                if (!buffer) return NULL;
            }

            strcpy(buffer + offset, linha);
            offset += len;
        }
    }
    return buffer;
}

/// <summary>
/// Fun��o respons�vel por apresentar lista de interse��es entre duas frequencias
/// </summary>
/// <param name="g"></param>
/// <param name="frequencia1"></param>
/// <param name="frequencia2"></param>
/// <returns>lista (string) da interse��o de duas frequencias</returns>
char* ListaIntersecaoFrequencias(Grafo* g, char frequencia1, char frequencia2) {
    char* buffer = (char*)malloc(1024);
    int offset = 0;
    offset += sprintf(buffer + offset, "Interse��es entre frequ�ncias '%c' e '%c':\n", frequencia1, frequencia2);

    for (int i = 0; i < g->numeroVertices; i++) {
        if (!g->antenas[i] || g->antenas[i]->frequencia != frequencia1) continue;

        for (int j = 0; j < g->numeroVertices; j++) {
            if (!g->antenas[j] || g->antenas[j]->frequencia != frequencia2) continue;

            if (g->antenas[i]->posicaoX == g->antenas[j]->posicaoX && g->antenas[i]->posicaoY == g->antenas[j]->posicaoY)
                offset += sprintf(buffer + offset, "Mesma coordenada: (%d, %d)\n", g->antenas[i]->posicaoX, g->antenas[i]->posicaoY);
        }
    }

    return buffer;
}
