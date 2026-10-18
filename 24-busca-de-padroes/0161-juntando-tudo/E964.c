// 0161 · Juntando tudo
// Exercício E964 · ★★☆
//
// O grep colorido pinta o que achou. Sem cores, use colchetes: escreva
// void destaca(const char *linha, const char *padrao), que usa as posições do
// pb_horspool para mostrar a linha com cada ocorrência entre [ e ], seguida
// do total entre parênteses. Linhas sem o padrão não aparecem. Procure
// "chuva" na previsão do tempo:
//
//   "segunda: sol, sem chuva"
//   "terça: chuva forte à tarde; depois da chuva, frio"
//   "quarta: nublado"
//   "quinta: chuvarada de manhã"
//
//   Saída esperada:
//   segunda: sol, sem [chuva]   (1)
//   terça: [chuva] forte à tarde; depois da [chuva], frio   (2)
//   quinta: [chuva]rada de manhã   (1)
//
// Dicas:
// 1. Percorra a linha letra a letra com um índice prox para a próxima
//    ocorrência: quando i == pos[prox], escreva '[' antes da letra.
// 2. Guarde onde fechar (i + m) e escreva ']' quando chegar lá, inclusive no
//    fim da linha (por isso o laço vai até i <= n).
// 3. As letras acentuadas passam intactas: você só copia bytes com putchar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "padroes.h"

int main(void) {

    return 0;
}
