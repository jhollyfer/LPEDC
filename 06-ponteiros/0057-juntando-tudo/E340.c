// 0057 · Juntando tudo: o ranking da feira
// Exercício E340 · ★★☆
//
// O mapa do jogo de viagem lista as capitais pelo tamanho do nome (do mais
// curto ao mais comprido); empates ficam em ordem alfabética. Ordene com
// qsort:
//
//   const char *capitais[] = {"Natal", "Rio Branco", "Recife", "Palmas",
//                             "Maceio", "Salvador", "Teresina", "Aracaju"};
//
//   Saída esperada:
//   Natal Maceio Palmas Recife Aracaju Salvador Teresina Rio Branco
//
// Dicas:
// 1. A comparação recebe endereços de const char *: pegue as strings com
//    *(const char * const *)a.
// 2. Compare strlen primeiro; se forem iguais, devolva strcmp.
// 3. Cuidado: strlen devolve size_t (sem sinal). Não subtraia: compare com
//    < e >.
// 4. Resposta esperada: a linha acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
