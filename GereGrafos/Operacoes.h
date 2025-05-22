#ifndef OPERACOES_H
#define OPERACOES_H

#include "Grafo.h"

///	Função responsável pela pesquisa em profundidade de determinado grafo
char* DFS(Grafo* g, int inicio);

///	Função responsável pela pesquisa em largura de determinado grafo
char* BFS(Grafo* g, int inicio);

///	Função responsável por encontrar todos os caminhos possíveis entre duas antenas em um grafo.
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim);

#endif
