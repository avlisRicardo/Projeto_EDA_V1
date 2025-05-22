#include <stdlib.h>
#include "antena.h"

/// <summary>
/// Função responsável por criar antena
/// </summary>
/// <param name="id"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="freq"></param>
/// <returns>Apontador para nova antena ou null em caso de erro</returns>
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia) {
    
    //  Aloca memória
    Antena* antena = malloc(sizeof(Antena));

    //  Trata caso de erro
    if (!antena)
        return NULL;
    
    //  Atribui valores antena
    antena->codigoAntena = codigoAntena;
    antena->posicaoX = posicaoX;
    antena->posicaoY = posicaoY;
    antena->frequencia = frequencia;

    return antena;
}

/// <summary>
/// Função responsável por liberar memória de determinada antena
/// </summary>
/// <param name="a"></param>
void ApagaAntena(Antena* antena) {
    free(antena);
}

/// <summary>
/// Função responsável por comparar coordenadas de duas antenas distintas
/// </summary>
/// <param name="a1">antena 1</param>
/// <param name="a2">antena 2</param>
/// <returns>
/// 1-  se duas antenas estiverem na mesma posição
/// 0-  caso contrário
/// </returns>
int VerificaCoordenada(Antena* a1, Antena* a2) {
    return a1->posicaoX == a2->posicaoX && a1->posicaoY == a2->posicaoY;
}

/// <summary>
/// Função responsável por comprara antenas com a mesma frequência
/// </summary>
/// <param name="a1">antena 1</param>
/// <param name="a2">antena 2</param>
/// <returns>
/// 1-  se duas antenas estiverem na mesma posição
/// 0-  caso contrário
/// </returns>
int VerificaFrequencia(Antena* a1, Antena* a2) {
    return a1->frequencia == a2->frequencia;
}