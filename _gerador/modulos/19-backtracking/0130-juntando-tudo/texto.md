## 0130 · Juntando tudo

No sudoku, completa-se a grade 9 × 9 com dígitos de 1 a 9 sem repetir numa
linha, numa coluna ou numa das nove caixas 3 × 3. Ele junta o que o módulo
mostrou: a grade é uma **matriz** `int g[9][9]` (0 é casa vazia), cada casa
vazia é uma decisão com 9 opções, e a **poda** é a regra do jogo, testada em
O(1) com **vetores de marcação**, como nas N-rainhas:

- `na_linha[l][d]` diz se o dígito `d` já está na linha `l`;
- `na_coluna[c][d]`, para a coluna `c`;
- `na_caixa[b][d]`, para a caixa `b = (l / 3) * 3 + c / 3`, de 0 a 8.

`resolve(k)` percorre as casas em ordem de leitura (a casa `k` é a linha
`k / 9`, coluna `k % 9`), pula as preenchidas e, na primeira vazia, tenta os
dígitos que passam pela poda: **escreve e marca**, desce para `resolve(k + 1)`
e, se não deu certo, **apaga e desmarca**. Sem casa vazia, o `true` sobe até o
`main`, como no exemplo A254.

Na casa (0, 1), a poda deixa só o 5 e o 7. O programa tenta o 5 e, só depois
de muitos retrocessos, descobre que é o 7:

{{ideia}}

O programa, com o jogo escrito como texto (`.` é casa vazia):

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

São 51 casas vazias e 2999 chamadas; a força bruta testaria até 9⁵¹
preenchimentos. Escolher **qual** casa preencher (a com menos candidatos)
derruba este jogo para 64 chamadas (exemplo A260). O fluxograma é o esqueleto
do módulo, com a casa no lugar do item e a regra do jogo no da poda:

{{fluxograma}}

> [!WARNING]
> No desfazer, as duas coisas precisam voltar: `g[l][c] = 0` **e**
> `marca(..., false)`. Sem o `g[l][c] = 0`, uma casa sem dígito possível fica
> com o último tentado e, na volta, o `while` de `resolve` a trata como casa
> **dada**: o programa termina em 64 chamadas com uma grade "resolvida" errada.

> [!TIP]
> **Por dentro do C:** o índice 0 de cada linha dos vetores de marcação fica
> sem uso para o dígito servir de índice. `jogo[l][c] - '0'` dá o número do
> caractere porque os dígitos são consecutivos na tabela ASCII (assunto 0040).

> [!NOTE]
> **Pergunta para você:** troque `"164.9...5"` por `"164.9...."`. O programa
> mostra a mesma grade? As chamadas sobem ou descem? O jogo continua com uma
> solução só? (Para a última, faça o exercício E778.)

{{pratique}}
