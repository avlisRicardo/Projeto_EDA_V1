/*
*	@file	AntenaLicalizacao.C
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação da localização de determinada antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#include "AntenaLocalizacao.h"
#include <cstddef>

/// <summary>
/// Função responsável por cria localizações
/// </summary>
/// <param name="coordenadaX"></param>
/// <param name="coordenadaY"></param>
/// <returns>Apontador para nova localização</returns>
Localizacao* CriaLocalizacao(int coordenadaX, int coordenadaY)
{

	 //	Cria nova licalização
	 Localizacao* novaLocalizacao = (Localizacao*)malloc(sizeof(Localizacao));

	 if (novaLocalizacao) {
		 novaLocalizacao->coordendadaX = coordenadaX;
		 novaLocalizacao->coordendadaY = coordenadaY;
		 novaLocalizacao->proximaLocalizacao = NULL;
	 }

	 return novaLocalizacao;
}

/// <summary>
/// Função reponsável por adicionar nova localizacao a lista de localizacaoes
/// </summary>
/// <param name="listaLocalizacao"></param>
/// <param name="coordenadaX"></param>
/// <param name="coordenadaY"></param>
/// <returns> lista de localizações</returns>
Localizacao* AdicionarLocalizacao(Localizacao* listaLocalizacao, int coordenadaX, int coordenadaY) {

	//	Cria localização
	Localizacao* novaLocalizacao = CriaLocalizacao(coordenadaX, coordenadaY);

	//	devo validar casos de erro e returnar informação

	novaLocalizacao->proximaLocalizacao = listaLocalizacao;
	return novaLocalizacao;
}

/// <summary>
/// Função responsável verificar pares de antenas com a mesma frequência e calcula as localizações afetadas com base nas condições fornecidas
/// As antenas com a mesma frequência e que estão alinhadas (na mesma linha ou coluna) são verificadas para encontrar as localizações afetadas
/// </summary>
/// <param name="listaAntenas"></param>
/// <returns></returns>
Localizacao* CalcularEfeitoNefasto(Antena* listaAntenas) {
    Localizacao* listaLocalizacoes = NULL;

    for (Antena* a = listaAntenas; a != NULL; a = a->proximaAntena) {
        for (Antena* b = a->proximaAntena; b != NULL; b = b->proximaAntena) {
            if (a->frequencia == b->frequencia && estaoAlinhadas(a, b)) {

                // Verificar se a distância de uma antena até o ponto é metade da outra
                int distanciaX = abs(a->coordenadaX - b->coordenadaX);
                int distanciaY = abs(a->coordenadaY - b->coordenadaY);

                if (distanciaX == 0 || distanciaY == 0) {
                    int deltaX = (a->coordenadaX + b->coordenadaX) / 2;
                    int deltaY = (a->coordenadaY + b->coordenadaY) / 2;

                    // Adicionar as localizações afetadas à lista
                    listaLocalizacoes = adicionarLocalizacao(listaLocalizacoes, deltaX, deltaY);
                }
            }
        }
    }
    return listaLocalizacoes;
}

// Função para exibir as localizações afetadas
void ApresentaLocalizacoes(Localizacao* lista) {
    while (lista) {
        printf("Localização com efeito nefasto: (%d, %d)\n", lista->coordendadaX, lista->coordendadaY);
        lista = lista->proximaLocalizacao;
    }
}