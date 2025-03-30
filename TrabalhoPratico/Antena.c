/*
*	@file	Antena.C
*	@brief	Alocação dinâmica de memória
*			Implementação de funções de manipulação de Localização de Antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avançada
*
*	@Author	Ricardo Silva
*	@date	Março 2025
*/

#include "Antena.h"

/// <summary>
/// Função responsável por cria nova antena
/// </summary>
/// <param name="frequencia"></param>
/// <param name="coordenadaX"></param>
/// <param name="coordenadaY"></param>
/// <returns>Apontador para nova antena</returns>
Antena* CriaAntena(char frequencia, int coordenadaX, int coordenadaY) {

	//	Inicializa antena
	Antena* novaAntena = (Antena*)malloc(sizeof(Antena));

	if (novaAntena) {
		novaAntena->frequencia = frequencia;
		novaAntena->coordenadaX = coordenadaX;
		novaAntena->coordenadaY = coordenadaY;
		novaAntena->proximaAntena = NULL;
	}

	return novaAntena;
}

/// <summary>
/// Função responsável por adicionar determinada anterna há lista de antenas
/// </summary>
/// <param name="listaAntenas"></param>
/// <param name="frequencia"></param>
/// <param name="coordenadaX"></param>
/// <param name="coordenadaY"></param>
/// <returns>Apontador para nova elemento da lista. Representa o elemento inicial da lista de antenas.</returns>
Antena* AdicionarAntena(Antena* listaAntenas, char frequencia, int coordenadaX, int coordenadaY) {

	//	Cria nova antana
	Antena* novaAntena = CriaAntena(frequencia, coordenadaX, coordenadaY);

	if (!novaAntena) {
		printf("Erro ao alocar memória!\n");
		return listaAntenas; // Retorna a lista inalterada em caso de erro
	}

	novaAntena->proximaAntena = listaAntenas;

	return novaAntena;
}

/// <summary>
/// Procedimento responsável pela apresentação da lista de antenas ao utilizador
/// </summary>
/// <param name="listaAntenas"></param>
void ApresentaAntenas(Antena* listaAntenas) {
	while (listaAntenas) {
		printf("Antena [%c] - Coordenadas: (%d, %d)\n", listaAntenas->frequencia, listaAntenas->coordenadaX, listaAntenas->coordenadaY);
		listaAntenas = listaAntenas->proximaAntena;
	}
}

/// <summary>
/// Função responsável por verificar alinhamento entre duas antenas
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>true or false</returns>
int VerificaAlinhamento(Antena* a, Antena* b) {
	return (a->coordenadaX == b->coordenadaX || a->coordenadaY == b->coordenadaY);
}