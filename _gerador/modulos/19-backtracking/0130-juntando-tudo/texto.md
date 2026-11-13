## 0130 · Juntando tudo

- **Sudoku**: completar a grade 9 × 9 com dígitos de 1 a 9 sem repetir numa
  linha, numa coluna ou numa das nove caixas 3 × 3. É problema de satisfação
  de restrições, resolvido por tentativa e erro (DEITEL; DEITEL, 2011).
- **Grade**: matriz `int g[9][9]`, com 0 de casa vazia. Cada casa vazia é uma
  decisão com 9 opções (DEITEL; DEITEL, 2011).
- **Vetores de marcação**: `na_linha[l][d]`, `na_coluna[c][d]` e
  `na_caixa[b][d]` dizem se o dígito `d` já aparece; a poda vira três
  leituras, como nas N-rainhas (WIRTH, 1989).
- **Caixa**: a casa `(l, c)` está na caixa `b = (l / 3) * 3 + c / 3`, de 0 a 8.
- **`resolve(k)`**: percorre as casas em ordem de leitura (linha `k / 9`,
  coluna `k % 9`), pula as dadas e, na primeira vazia, tenta os dígitos que
  passam pela poda: **escreve e marca**, desce, **apaga e desmarca**
  (FEOFILOFF, 2009).
- **Ordem das casas**: escolher a casa com menos candidatos poda muito mais
  cedo (ZIVIANI, 2010, cap. 2).
- **Dígito para número**: `jogo[l][c] - '0'` funciona porque os dígitos são
  consecutivos na tabela de caracteres (assunto 0040) (KERNIGHAN; RITCHIE, 1989).

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
