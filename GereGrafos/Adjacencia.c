#include "Adjacencia.h"
#include <stdlib.h>

/// <summary>
/// Função responsável por criar uma nova adjacência
/// Destino - indica sempre o caminho da aresta
/// </summary>
/// <param name="destino"></param>
/// <returns>Apontador para adjacencia criada</returns>
Adjacencia* CriaAdjacencia(int destino) {

    //  Aloca memória
    Adjacencia* novo = (Adjacencia*)malloc(sizeof(Adjacencia));

    //  Trata null
    if (!novo) 
        return NULL;

    novo->destino = destino;
    novo->proxima = NULL;

    return novo;
}

/// <summary>
/// Procedimento responsável por remover determinada adjacencia
/// Recebe o inicio da lista
/// </summary>
/// <param name="inicioLista"></param>
void RemoveAdjacencia(Adjacencia* inicioLista) {
    while (inicioLista) {
        Adjacencia* adjacenciaAux = inicioLista;
        adjacenciaAux = inicioLista->proxima;

        //  liberta memória
        free(adjacenciaAux);
    }
}
