// 0168 · Complexidade espacial
// Exercício E1008 · ★★★
//
// De quantas formas dá para subir uma escada de n degraus, de 1 em 1 ou de
// 2 em 2? formas(0) = formas(1) = 1 e formas(n) = formas(n-1) + formas(n-2).
// Escreva três versões e meça tempo e espaço de cada uma para n = 30:
// - formas_rec(n): recursão pura, contando as chamadas e a profundidade
//   máxima da pilha;
// - formas_tabela(n, &bytes): um vetor de n + 1 long com malloc, preenchido
//   de baixo para cima; devolve em bytes o tamanho do vetor;
// - formas_duas(n): só duas variáveis long (os dois últimos valores).
//
//   Saída esperada:
//   recursão: 1346269 formas, 2692537 chamadas, 30 frames na pilha
//   tabela:   1346269 formas, 248 bytes na tabela
//   duas:     1346269 formas, 16 bytes extras
//
// Dicas:
// 1. A recursão é Θ(1,618ⁿ) de tempo, mas só Θ(n) de pilha: o ramo mais
//    fundo desce de 30 até 1.
// 2. A tabela troca espaço por tempo: Θ(n) de tempo e (30 + 1) · 8 = 248
//    bytes. Não esqueça o free.
// 3. Duas variáveis: Θ(n) de tempo e 2 · 8 = 16 bytes, para qualquer n.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
