#include "Antena.h"
#include "Adjacencia.h"

#ifndef GRAFO_H
#define GRAFO_H

//  Estrutura Grafo
typedef struct {
    int numeroVertices;
    Antena** antenas;
    Adjacencia** adjacencia;
} Grafo;

//  Função responsável por criar grafo
Grafo* CriaGrafo(int numVertices);

//  Função responsável por libertar grafo de memória
void RemoveGrafo(Grafo* grafo);

#endif