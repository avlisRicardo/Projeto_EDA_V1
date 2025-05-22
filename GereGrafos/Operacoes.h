#ifndef OPERACOES_H
#define OPERACOES_H

#include "Grafo.h"

///	Fun��o respons�vel pela pesquisa em profundidade de determinado grafo
char* DFS(Grafo* g, int inicio);

///	Fun��o respons�vel pela pesquisa em largura de determinado grafo
char* BFS(Grafo* g, int inicio);

///	Fun��o respons�vel por encontrar todos os caminhos poss�veis entre duas antenas em um grafo.
char* CaminhosEntreAntenas(Grafo* grafo, int inicio, int fim);

#endif
