## 0130 · Juntando tudo

O sudoku junta tudo o que o módulo mostrou num problema que muita gente
resolve no papel. A grade tem 9 × 9 casas, algumas já preenchidas. O objetivo
é completar as vazias com dígitos de 1 a 9 sem repetir nenhum dígito numa
linha, numa coluna ou numa das nove caixas 3 × 3 em que a grade se divide.
Problemas assim, em que se procura uma atribuição de valores que respeite um
conjunto de regras, se chamam **problemas de satisfação de restrições**, e o
backtracking é a forma natural de atacá-los (DEITEL; DEITEL, 2011).

A grade vira uma matriz `int g[9][9]`, com 0 marcando a casa vazia. Do ponto
de vista do backtracking, cada casa vazia é uma decisão com 9 opções, e a
árvore de decisões tem um nível por casa vazia (DEITEL; DEITEL, 2011). Com 51
casas vazias, a força bruta pura teria 9⁵¹ folhas, um número impossível de
percorrer. A poda é o que torna o problema viável.

A poda é a própria regra do jogo: um dígito que já aparece na linha, na
coluna ou na caixa da casa não pode entrar. Para testar isso sem varrer a
grade, o programa usa **vetores de marcação**, como os das N-rainhas no
assunto 0128. `na_linha[l][d]` diz se o dígito `d` já está na linha `l`;
`na_coluna[c][d]` faz o mesmo para a coluna `c`; e `na_caixa[b][d]`, para a
caixa `b`. O teste vira três leituras, em O(1) (WIRTH, 1989). Os vetores têm 10
posições por linha, e o índice 0 fica sem uso, para que o próprio dígito sirva
de índice.

Falta numerar as caixas. As linhas 0 a 2 formam a primeira faixa de caixas, as
linhas 3 a 5 a segunda e as 6 a 8 a terceira; o mesmo vale para as colunas. A
divisão inteira `l / 3` dá a faixa da linha e `c / 3` dá a faixa da coluna, e a
casa `(l, c)` fica na caixa `b = (l / 3) * 3 + c / 3`, um número de 0 a 8. A
casa (4, 7), por exemplo, está na caixa `1 * 3 + 2 = 5`.

A função `resolve(k)` percorre as casas em ordem de leitura, da esquerda para
a direita e de cima para baixo. A casa número `k`, de 0 a 80, fica na linha
`k / 9` e na coluna `k % 9`. A função pula as casas já preenchidas e, na
primeira vazia, tenta cada dígito que passa pela poda: **escreve e marca**,
desce para `resolve(k + 1)` e, se não deu certo, **apaga e desmarca**
(FEOFILOFF, 2009). Quando não sobra casa vazia, a grade está completa, e o
`true` sobe pelas chamadas até o `main`.

A ordem em que as casas são decididas pesa muito. Ir em ordem de leitura é
simples, mas escolher primeiro a casa com **menos** candidatos poda muito mais
cedo: uma casa com uma opção só não gera ramo nenhum, e uma escolha errada é
descoberta antes de a árvore crescer (ZIVIANI, 2010, cap. 2).

A grade do exemplo chega como texto, uma string por linha, com `.` para casa
vazia. Para transformar o caractere `'7'` no número 7, o código faz
`jogo[l][c] - '0'`. A conta funciona porque os caracteres de `'0'` a `'9'` são
consecutivos na tabela de caracteres (assunto 0040): a distância entre `'7'` e
`'0'` é exatamente 7 (KERNIGHAN; RITCHIE, 1989).

> [!WARNING]
> No desfazer, as duas coisas voltam: `g[l][c] = 0` **e**
> `marca(..., false)`. Sem o `g[l][c] = 0`, a casa fica com o último dígito
> tentado e o `while` passa a tratá-la como **dada**: a grade sai errada.

{{exemplo}}

Um jogo com 51 casas vazias, escrito como texto (`.` é casa vazia). Na casa
(0, 1), a poda deixa só o 5 e o 7. O programa tenta o 5 e, só depois de muitos
retrocessos, descobre que é o 7:

{{ideia}}

```c
#include <stdbool.h>
#include <stdio.h>

int g[9][9];
bool na_linha[9][10];    // na_linha[l][d]: o dígito d já está na linha l?
bool na_coluna[9][10];
bool na_caixa[9][10];    // caixas 3 × 3 numeradas de 0 a 8
long chamadas = 0;

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
}

// resolve a partir da casa número k (0 a 80, lendo linha por linha)
bool resolve(int k) {
    chamadas++;
    while (k < 81 && g[k / 9][k % 9] != 0) {
        k++;                            // pula as casas já preenchidas
    }
    if (k == 81) {
        return true;                    // nenhuma casa vazia: resolvido
    }
    int l = k / 9, c = k % 9;
    for (int d = 1; d <= 9; d++) {
        if (na_linha[l][d] || na_coluna[c][d] || na_caixa[caixa(l, c)][d]) {
            continue;                   // poda: d já aparece
        }
        g[l][c] = d;                    // escolhe
        marca(l, c, d, true);
        if (resolve(k + 1)) {
            return true;
        }
        marca(l, c, d, false);          // desfaz
        g[l][c] = 0;
    }
    return false;                       // nenhum dígito serve: volta
}

int main(void) {
    const char *jogo[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            if (jogo[l][c] != '.') {
                g[l][c] = jogo[l][c] - '0';
                marca(l, c, g[l][c], true);
            }
        }
    }
    if (resolve(0)) {
        for (int l = 0; l < 9; l++) {
            for (int c = 0; c < 9; c++) {
                printf("%d%s", g[l][c], c == 8 ? "\n" : (c % 3 == 2 ? " | " : " "));
            }
            if (l % 3 == 2 && l < 8) {
                printf("------+-------+------\n");
            }
        }
    }
    printf("%ld chamadas\n", chamadas);
    return 0;
}
// Saída:
// 2 7 3 | 6 8 5 | 1 4 9
// 6 8 5 | 9 4 1 | 3 7 2
// 9 4 1 | 2 7 3 | 5 8 6
// ------+-------+------
// 5 2 8 | 1 6 4 | 7 9 3
// 3 9 7 | 5 2 8 | 4 6 1
// 1 6 4 | 3 9 7 | 8 2 5
// ------+-------+------
// 8 3 2 | 4 5 6 | 9 1 7
// 4 5 6 | 7 1 9 | 2 3 8
// 7 1 9 | 8 3 2 | 6 5 4
// 2999 chamadas
```

São 2999 chamadas; a força bruta testaria até 9⁵¹ preenchimentos. Escolher a
casa com menos candidatos derruba este jogo para 64 chamadas (exemplo A260). O
fluxograma é o esqueleto do módulo, com a regra do jogo no lugar da poda:

{{fluxograma}}
