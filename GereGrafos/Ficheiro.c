#include "Ficheiro.h"
#include "Antena.h"
#include "Adjacencia.h"
#include <cstdio>

/// <summary>
/// Função reponsável por carregar grafo contido em determinado ficheiro
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <returns>apontador para o ficheiro carregado</returns>
Grafo* CarregarGrafoFicheiro(const char* nomeFicheiro) {
    FILE* file = fopen("dados.txt", "r");

    int numAntenas;
    fscanf(file, "%d", &numAntenas);

    Grafo* g = CriaGrafo(numAntenas);

    for (int i = 0; i < numAntenas; i++) {

        int id, x, y;
        char freq;

        fscanf(file, "%d %d %d %c", &id, &x, &y, &freq);

        //  cria antena
        Antena* antenaCriada = CriarAntena(g, id, x, y, freq);
        if (antenaCriada == NULL)
            return;
    }

    int origem, destino;
    while (fscanf(file, "%d %d", &origem, &destino) == 2) {

        if (g->antenas[origem] && g->antenas[destino] &&
            g->antenas[origem]->frequencia == g->antenas[destino]->frequencia) {

            //  Cria adjacencia
            Adjacencia* adjacencia = CriaAdjacencia(g, origem, destino); 
            if (adjacencia == NULL)
                return;
        }
    }
}