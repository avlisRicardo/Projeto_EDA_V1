/*
*	@file	Antena.C
*	@brief	Aloca��o din�mica de mem�ria
*			Implementa��o de fun��es de manipula��o de Localiza��o de Antena
*	@Other	Elaborado para a disciplina de Estrutura de Dados Avan�ada
*
*	@Author	Ricardo Silva
*	@date	Mar�o 2025
*/

#include "Antena.h"

/// <summary>
/// Fun��o respons�vel por cria nova antena
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
/// Fun��o respons�vel por adicionar determinada anterna h� lista de antenas
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
		printf("Erro ao alocar mem�ria!\n");
		return listaAntenas; // Retorna a lista inalterada em caso de erro
	}

	novaAntena->proximaAntena = listaAntenas;

	return novaAntena;
}

/// <summary>
/// Procedimento respons�vel pela apresenta��o da lista de antenas ao utilizador
/// </summary>
/// <param name="listaAntenas"></param>
void ApresentaAntenas(Antena* listaAntenas) {
	while (listaAntenas) {
		printf("Antena [%c] - Coordenadas: (%d, %d)\n", listaAntenas->frequencia, listaAntenas->coordenadaX, listaAntenas->coordenadaY);
		listaAntenas = listaAntenas->proximaAntena;
	}
}

/// <summary>
/// Fun��o respons�vel por verificar alinhamento entre duas antenas
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>true or false</returns>
int VerificaAlinhamento(Antena* a, Antena* b) {
	return (a->coordenadaX == b->coordenadaX || a->coordenadaY == b->coordenadaY);
}