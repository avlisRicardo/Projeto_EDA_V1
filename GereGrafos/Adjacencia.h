#ifndef ADJACENCIA_H
#define ADJACENCIA_H

//  Estrutura Adjacencia
typedef struct Adjacencia {
    int destino;
    struct Adjacencia* proxima;
} Adjacencia;

//  Função responsável por criar uma aresta
Adjacencia* CriaAdjacencia(int destino);

//  Procedimento responsável por remover determinada adjacencia
void RemoveAdjacencia(Adjacencia* inicioLista);

#endif