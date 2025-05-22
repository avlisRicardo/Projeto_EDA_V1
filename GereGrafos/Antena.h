#ifndef ANTENA_H
#define ANTENA_H

//  Estrutura antena
typedef struct {
    int codigoAntena;
    int posicaoX, posicaoY;
    char frequencia;
} Antena;

//  Fun��o respons�vel por criar antena
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia);

//  Procedimento respons�vel por liberar mem�ria de determinada antena
void ApagaAntena(Antena* antena);

//  Fun��o respons�vel por verificar antenas com as mesmas coordenadas
int VerificaCoordenada(Antena* a1, Antena* a2);

//  Fun��o respons�vel por verificar antenas com a mesma frequencia
int VerificaFrequencia(Antena* a1, Antena* a2);

#endif
