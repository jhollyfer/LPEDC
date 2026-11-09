// 0185 · Cadeia de matrizes
// Exercício E1107 · ★★☆
//
// O texto preenche a tabela de baixo para cima. Escreva a versão de cima
// para baixo, com memoização (0138): long custo(int i, int j) segue a
// recorrência ao pé da letra, mas guarda cada m[i][j] numa tabela memo e
// devolve direto quando já calculou. Use sete matrizes,
// p = 8, 20, 4, 15, 6, 25, 10, 12, e conte as chamadas e as casas
// realmente calculadas.
//
//   Saída esperada:
//   Custo mínimo: 3464
//   Chamadas com memória: 113
//   Casas calculadas: 21
//
// Dicas:
// 1. Encha memo com -1 antes de começar (custo 0 é um valor válido, para
//    i == j). Conte chamadas na entrada da função e casas só quando for
//    calcular de verdade.
// 2. As casas com i < j são n(n-1)/2 = 21. Sem a memória (A369), seriam
//    3^6 = 729 chamadas.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

int main(void) {

    return 0;
}
