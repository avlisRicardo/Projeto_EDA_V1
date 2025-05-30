#include "pch.h"
#include "FicheiroBinario.h"
#include "Grafo.h"

//bool SaveGraph(const char* nomeFicheiro, Grafo* grafo) {
//
//    FILE* file = fopen(fileName, "wb");
//    if (!file) {
//        return false;  // Erro a abir ficheiro
//    }
//
//     gravar n�mero de vertices
//    fwrite(....);
//
//    Gravar Vertices e Adjacencias
//    Vertice* currentVertex = g->head;
//    while (currentVertex) {
//
//        gravar Dados do Vertice
//        gravar tamanho do nome da cidade
//        frite(...,file)
//         gravar nome da cidade
//        fwrite(..., file);
//
//         gravar lista de adjacencia para este vertice
//        AdjD* currentAdj = currentVertex->adjacencias;
//        while (currentAdj) {
//             gravar distancia e vertice destino
//            fwrite(, file);
//            fwrite(, 1, file);
//            currentAdj = currentAdj->next;
//        }
//
//         Marcar fim de adjacencias deste vertice
//        fwrite(... file);
//
//         proximo vertice
//        current
//}