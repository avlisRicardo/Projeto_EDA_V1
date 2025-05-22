#ifndef ADJACENCIA_H
#define ADJACENCIA_H

//  Estrutura Adjacencia
typedef struct Adjacencia {
    int destino;
    struct Adjacencia* proxima;
} Adjacencia;

//  Fun��o respons�vel por criar uma aresta
Adjacencia* CriaAdjacencia(int destino);

//  Procedimento respons�vel por remover determinada adjacencia
void RemoveAdjacencia(Adjacencia* inicioLista);

#endif