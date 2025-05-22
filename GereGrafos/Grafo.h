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

//  Fun��o respons�vel por criar grafo
Grafo* CriaGrafo(int numVertices);

//  Fun��o respons�vel por libertar grafo de mem�ria
void RemoveGrafo(Grafo* grafo);

#endif