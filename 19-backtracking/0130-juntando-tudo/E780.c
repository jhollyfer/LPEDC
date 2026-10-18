// 0130 · Juntando tudo
// Exercício E780 · ★★★
//
// O sudoku X tem uma regra a mais: as duas diagonais grandes da grade (a
// principal, de (0, 0) a (8, 8), e a secundária, de (0, 8) a (8, 0)) também
// precisam ter os dígitos de 1 a 9 sem repetir. É a mistura do sudoku com as
// diagonais das N-rainhas. Escreva um resolvedor de sudoku X (pode partir do
// texto) e resolva o jogo abaixo, contando as chamadas da função recursiva.
//
//   24.3..7.5
//   ....7..2.
//   ...54..3.
//   ....8.49.
//   ....9.2.3
//   8........
//   ...6...5.
//   675.3.1..
//   .......68
//
//   Saída esperada:
//   249368715
//   356971824
//   781542639
//   512783496
//   467195283
//   893426571
//   928614357
//   675839142
//   134257968
//   diagonais: 251796348 e 526394871
//   4171 chamadas
//
// Dicas:
// 1. Acrescente dois vetores bool[10]: um para a diagonal principal (casas
//    com l == c) e outro para a secundária (l + c == 8).
// 2. A poda e a marcação só mexem nesses vetores quando a casa está na
//    diagonal. A casa do centro, (4, 4), está nas duas.
// 3. Teste os dígitos de 1 a 9 em ordem crescente, na ordem de leitura das
//    casas, para a contagem de chamadas bater.
// 4. Este jogo depende da regra nova: sem as diagonais, ele tem mais de uma
//    solução (confira com o conta do E778, se quiser).
// 5. Resposta esperada: as 11 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const char *jogo[9] = {
        "24.3..7.5", "....7..2.", "...54..3.",
        "....8.49.", "....9.2.3", "8........",
        "...6...5.", "675.3.1..", ".......68",
    };
    (void)jogo; // apague esta linha quando usar o vetor

    return 0;
}
