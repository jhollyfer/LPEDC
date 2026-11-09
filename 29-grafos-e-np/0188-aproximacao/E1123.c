// 0188 · Aproximação
// Exercício E1123 · ★☆☆
//
// Um barco menor só tem um porão aberto por vez: se a carga não cabe na
// viagem atual, ela parte e abre-se outra (não dá para voltar a uma viagem
// anterior). Isso é o NEXT FIT. Escreva int next_fit(const int carga[],
// int n) e compare com o first fit do texto e com o limite inferior, para
// as cargas 6, 5, 6, 5, 1, 7, 2, 2, 5, 4 (capacidade 10).
//
//   Saída esperada:
//   Limite inferior: 5 viagens
//   Next fit: 7 viagens
//   First fit: 5 viagens
//
// Dicas:
// 1. O next fit só guarda o espaço livre da viagem ATUAL: uma variável, não
//    um vetor. Se a carga não cabe, conta uma viagem nova e volta a 10.
// 2. Limite inferior: (soma + 9) / 10, a divisão arredondada para cima.
// 3. Resposta esperada: a saída acima. O next fit é O(n) e também é
//    2-aproximado, mas joga fora espaço que o first fit aproveita.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
