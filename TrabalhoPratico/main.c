#include "Antena.h"
#include "AntenaArquivo.h"
#include "AntenaLocalizacao.h"

int main() {

    Antena* listaAntenas = NULL;

    MatrizDimensao dimensao;
    listaAntenas = carregarAntenasDeArquivo("C:\\Users\\Dev_RicardoSilva\\Desktop\\IPCA\\Lufer\\TrabalhoPratico\\TrabalhoPratico\\FicheiroExemplo.txt", &dimensao);

    // Adicionando algumas antenas
    listaAntenas = AdicionarAntena(listaAntenas, 'A', 1, 2);

    // Calcular e exibir localizações com efeito nefasto
    Localizacao* listaLocalizacoes = calcularEfeitoNefasto(listaAntenas);
    exibirLocalizacoes(listaLocalizacoes);

    // Exibir as antenas
    ApresentaAntenas(listaAntenas);

}