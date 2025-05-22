#include "Grafo.h"
#include <cstddef>

/// <summary>
/// Função responsável por criar determinado grafo
/// </summary>
/// <param name="numVertices">número de vértices do grafo</param>
/// <returns>Apontador para o grafico criado</returns>
static Grafo* CriarGrafo(int numVertices) {

    //  Aloca memória
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

    //  Cria grafo
    grafo->numeroVertices = numVertices;
    grafo->antenas = (Antena**)malloc(sizeof(Antena*) * numVertices);
    grafo->adjacencia = (Adjacencia**)malloc(sizeof(Adjacencia*) * numVertices);

    for (int i = 0; i < numVertices; i++) {
        grafo->antenas[i] = NULL;
        grafo->adjacencia[i] = NULL;
    }

    return grafo;
}

/// <summary>
/// Procedimento responsável por libertar memória de determinado grafo
/// </summary>
/// <param name="grafo"></param>
void RemoveGrafo(Grafo* grafo) {

    //  percorre grafo
    for (int i = 0; i < grafo->numeroVertices; i++) {

        if (grafo->antenas[i])
            free(grafo->antenas[i]);

        Adjacencia* adjacenciaAtual = grafo->adjacencia[i];
        while (adjacenciaAtual) {
            Adjacencia* adjacenciaAux = adjacenciaAtual;
            adjacenciaAtual = adjacenciaAux->proxima;
            free(adjacenciaAux);
        }
    }

    free(grafo->antenas);
    free(grafo->adjacencia);
    free(grafo);
}
