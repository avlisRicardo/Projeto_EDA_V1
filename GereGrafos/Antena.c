#include <stdlib.h>
#include "antena.h"

/// <summary>
/// Fun��o respons�vel por criar antena
/// </summary>
/// <param name="id"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="freq"></param>
/// <returns>Apontador para nova antena ou null em caso de erro</returns>
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia) {
    
    //  Aloca mem�ria
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
/// Fun��o respons�vel por liberar mem�ria de determinada antena
/// </summary>
/// <param name="a"></param>
void ApagaAntena(Antena* antena) {
    free(antena);
}

/// <summary>
/// Fun��o respons�vel por comparar coordenadas de duas antenas distintas
/// </summary>
/// <param name="a1">antena 1</param>
/// <param name="a2">antena 2</param>
/// <returns>
/// 1-  se duas antenas estiverem na mesma posi��o
/// 0-  caso contr�rio
/// </returns>
int VerificaCoordenada(Antena* a1, Antena* a2) {
    return a1->posicaoX == a2->posicaoX && a1->posicaoY == a2->posicaoY;
}

/// <summary>
/// Fun��o respons�vel por comprara antenas com a mesma frequ�ncia
/// </summary>
/// <param name="a1">antena 1</param>
/// <param name="a2">antena 2</param>
/// <returns>
/// 1-  se duas antenas estiverem na mesma posi��o
/// 0-  caso contr�rio
/// </returns>
int VerificaFrequencia(Antena* a1, Antena* a2) {
    return a1->frequencia == a2->frequencia;
}