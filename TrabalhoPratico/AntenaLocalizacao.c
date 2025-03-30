/*
*	@file	AntenaLicalizacao.C
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o da localiza��o de determinada antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Mar�o 2025
*/

#include "AntenaLocalizacao.h"
#include <cstddef>

/// <summary>
/// Fun��o respons�vel por cria localiza��es
/// </summary>
/// <param name="coordenadaX"></param>
/// <param name="coordenadaY"></param>
/// <returns>Apontador para nova localiza��o</returns>
Localizacao* CriaLocalizacao(int coordenadaX, int coordenadaY)
{

	 //	Cria nova licaliza��o
	 Localizacao* novaLocalizacao = (Localizacao*)malloc(sizeof(Localizacao));

	 if (novaLocalizacao) {
		 novaLocalizacao->coordendadaX = coordenadaX;
		 novaLocalizacao->coordendadaY = coordenadaY;
		 novaLocalizacao->proximaLocalizacao = NULL;
	 }

	 return novaLocalizacao;
}

/// <summary>
/// Fun��o repons�vel por adicionar nova localizacao a lista de localizacaoes
/// </summary>
/// <param name="listaLocalizacao"></param>
/// <param name="coordenadaX"></param>
/// <param name="coordenadaY"></param>
/// <returns> lista de localiza��es</returns>
Localizacao* AdicionarLocalizacao(Localizacao* listaLocalizacao, int coordenadaX, int coordenadaY) {

	//	Cria localiza��o
	Localizacao* novaLocalizacao = CriaLocalizacao(coordenadaX, coordenadaY);

	//	devo validar casos de erro e returnar informa��o

	novaLocalizacao->proximaLocalizacao = listaLocalizacao;
	return novaLocalizacao;
}

/// <summary>
/// Fun��o respons�vel verificar pares de antenas com a mesma frequ�ncia e calcula as localiza��es afetadas com base nas condi��es fornecidas
/// As antenas com a mesma frequ�ncia e que est�o alinhadas (na mesma linha ou coluna) s�o verificadas para encontrar as localiza��es afetadas
/// </summary>
/// <param name="listaAntenas"></param>
/// <returns></returns>
Localizacao* CalcularEfeitoNefasto(Antena* listaAntenas) {
    Localizacao* listaLocalizacoes = NULL;

    for (Antena* a = listaAntenas; a != NULL; a = a->proximaAntena) {
        for (Antena* b = a->proximaAntena; b != NULL; b = b->proximaAntena) {
            if (a->frequencia == b->frequencia && estaoAlinhadas(a, b)) {

                // Verificar se a dist�ncia de uma antena at� o ponto � metade da outra
                int distanciaX = abs(a->coordenadaX - b->coordenadaX);
                int distanciaY = abs(a->coordenadaY - b->coordenadaY);

                if (distanciaX == 0 || distanciaY == 0) {
                    int deltaX = (a->coordenadaX + b->coordenadaX) / 2;
                    int deltaY = (a->coordenadaY + b->coordenadaY) / 2;

                    // Adicionar as localiza��es afetadas � lista
                    listaLocalizacoes = adicionarLocalizacao(listaLocalizacoes, deltaX, deltaY);
                }
            }
        }
    }
    return listaLocalizacoes;
}

// Fun��o para exibir as localiza��es afetadas
void ApresentaLocalizacoes(Localizacao* lista) {
    while (lista) {
        printf("Localiza��o com efeito nefasto: (%d, %d)\n", lista->coordendadaX, lista->coordendadaY);
        lista = lista->proximaLocalizacao;
    }
}