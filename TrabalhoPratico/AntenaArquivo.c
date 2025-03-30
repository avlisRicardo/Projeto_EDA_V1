/*
*	@file	AntenaArquivo.C
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de matriz de determinada antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#include "AntenaArquivo.h"
#include <stdio.h>
#include <stdlib.h>

Antena* CarregaAntenasArquivo(const char* nomeArquivo, MatrizDimensao* dimensao) {

    FILE* arquivo = fopen(nomeArquivo, "r");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }

    char linha[256];
    if (!fgets(linha, sizeof(linha), arquivo)) {
        fclose(arquivo);
        return NULL;
    }
    sscanf(linha, "%d %d", &dimensao->quantidadeLinhas, &dimensao->quantidadeColunas);

    Antena* lista = NULL;
    for (int i = 0; i < dimensao->quantidadeLinhas; i++) {
        if (!fgets(linha, sizeof(linha), arquivo)) break;
        for (int j = 0; j < dimensao->quantidadeColunas; j++) {
            if (linha[j] != '.' && linha[j] != '\n' && linha[j] != ' ') {
                lista = AdicionarAntena(lista, linha[j], j, i);
            }
        }
    }
    fclose(arquivo);
    return lista;
}