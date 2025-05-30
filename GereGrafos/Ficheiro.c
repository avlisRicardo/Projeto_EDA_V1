/*
*	@file	Ficheiros.h
*	@brief	Aloca��o din�mica de mem�ria
*       	Implementa��o de fun��es de manipula��o de matriz de determinada Anterna
*			Guarda e trata dimens�o de determinada matriz
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Maio 2025
*/

#include "pch.h"
#include <stdio.h>
#include <cstdio>
#include "Ficheiro.h"
#include "Antena.h"
#include "Adjacencia.h"


/// <summary>
/// Fun��o respons�vel por carregar o grafo a partir de um ficheiro de texto.
/// O ficheiro deve conter:
/// - o n�mero total de antenas (int)
/// - para cada antena: id (int), posicaoX (int), posicaoY (int), frequ�ncia (char)
/// - uma lista de liga��es v�lidas (pares de inteiros representando liga��es entre antenas com mesma frequ�ncia)
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro a carregar</param>
/// <returns>Apontador para o grafo carregado ou NULL em caso de erro</returns>
Grafo* CarregarGrafoFicheiro(const char* nomeFicheiro, int* erro) {

    FILE* file = fopen(nomeFicheiro, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro");
        return NULL;
    }

    int numAntenas;
    if (fscanf(file, "%d", &numAntenas) != 1) {
        fclose(file);
        return NULL;
    }

	if (numAntenas <= 0) {
		fclose(file);
        *erro = 3;
		return NULL;                                    // N�mero inv�lido de antenas
	}

    Grafo* grafo = CriarGrafo();                        // Fun��o que inicializa a estrutura do grafo
    if (!grafo) {
        fclose(file);
		*erro = 1;
        return NULL;
    }

    // Leitura das antenas
    for (int i = 0; i < numAntenas; i++) {
        int id, x, y;
        char freq;
        if (fscanf(file, "%d %d %d %c", &id, &x, &y, &freq) != 4) {
            RemoveGrafo(grafo, 0);
            fclose(file);
            return NULL;
        }

        Antena* nova = CriarAntena(id, x, y, freq, 0);  // Cria antena
        if (!nova) {
            RemoveGrafo(grafo, 0);
            fclose(file);
            return NULL;
        }

        AdicionarAntena(grafo, nova);                   // Adiciona antena ao grafo
    }

    // Leitura das liga��es (adjac�ncias)
    int origem, destino;
    while (fscanf(  file, "%d %d", &origem, &destino) == 2) {

        Antena* a1 = GetAntenaPorID(grafo, origem, 0);
        Antena* a2 = GetAntenaPorID(grafo, destino, 0);

        if (a1 && a2 && a1->frequencia == a2->frequencia) {
            CriaAdjacencia(a1, a2);                    // Cria liga��o se tiverem mesma frequ�ncia
		}
        else
        {
			//  Se n�o tiverem mesma frequ�ncia, n�o cria liga��o
			RemoveGrafo(grafo, 0);                    
			fclose(file);
			*erro = 2;                                
			return NULL;    
        }
    }

    fclose(file);
    return grafo;
}