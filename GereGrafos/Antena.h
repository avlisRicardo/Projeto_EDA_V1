#ifndef ANTENA_H
#define ANTENA_H

//  Estrutura antena
typedef struct {
    int codigoAntena;
    int posicaoX, posicaoY;
    char frequencia;
} Antena;

//  Função responsável por criar antena
Antena* CriarAntena(int codigoAntena, int posicaoX, int posicaoY, char frequencia);

//  Procedimento responsável por liberar memória de determinada antena
void ApagaAntena(Antena* antena);

//  Função responsável por verificar antenas com as mesmas coordenadas
int VerificaCoordenada(Antena* a1, Antena* a2);

//  Função responsável por verificar antenas com a mesma frequencia
int VerificaFrequencia(Antena* a1, Antena* a2);

#endif
