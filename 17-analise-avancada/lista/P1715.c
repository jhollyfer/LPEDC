// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1715 · ★★☆ · O método do potencial no vetor que dobra
//
// O vetor de pedidos de um app começa VAZIO (capacidade 0). Ao inserir com o
// vetor cheio, ele aloca o dobro (ou 1, se a capacidade era 0) e copia tudo.
// O custo real de uma inserção é 1, mais o número de cópias.
//
// O método do potencial do Cormen usa Φ = 2 · num - cap (num = itens, cap =
// capacidade). O custo AMORTIZADO de uma operação é o real mais a variação do
// potencial: ĉ = c + Φ(depois) - Φ(antes). Escreva o vetor com malloc (copie
// os itens à mão, para contar as cópias) e mostre, para 17 inserções: num,
// cap, custo real, Φ e custo amortizado. Mostre também a soma dos custos reais
// e a dos amortizados.
//
//   Saída esperada:
//   num  cap  real  phi  amortizado
//     1    1     1    1           2
//     2    2     2    2           3
//     3    4     3    2           3
//     4    4     1    4           3
//     5    8     5    2           3
//     6    8     1    4           3
//     7    8     1    6           3
//     8    8     1    8           3
//     9   16     9    2           3
//    10   16     1    4           3
//    11   16     1    6           3
//    12   16     1    8           3
//    13   16     1   10           3
//    14   16     1   12           3
//    15   16     1   14           3
//    16   16     1   16           3
//    17   32    17    2           3
//   Soma real: 48 | soma amortizada: 50 (3n = 51)
//
// Dicas:
// 1. Antes de inserir, guarde Φ = 2 · num - cap. Depois, calcule o novo Φ
//    e ĉ = c + Φnovo - Φvelho.
// 2. Sem expansão: c = 1 e Φ sobe 2, então ĉ = 3. Com expansão de num = cap
//    = k para 2k: c = k + 1 e Φ cai de k para 2, então ĉ = 3 também.
// 3. Como Φ começa em 0 e nunca fica negativo depois da primeira inserção, a
//    soma dos reais nunca passa da soma dos amortizados: no máximo 3n.
// 4. Resposta esperada: amortizado 3 em todas as linhas (2 na primeira);
//    soma real 48 e soma amortizada 50.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int num, cap;
} Vetor;

int main(void) {
    Vetor v = {NULL, 0, 0};

    free(v.item);
    return 0;
}
