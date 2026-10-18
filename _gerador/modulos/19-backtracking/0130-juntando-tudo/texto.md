## 0130 · Juntando tudo

Na banca da rodoviária, a revista de passatempos traz um sudoku "difícil", e
você empaca na terceira casa. A regra é curta: completar a grade 9 × 9 com
dígitos de 1 a 9 sem repetir nenhum numa linha, numa coluna ou numa das nove
caixas 3 × 3. Que tal deixar o computador resolver?

O sudoku junta tudo o que o módulo mostrou. A grade é uma **matriz**
`int g[9][9]`, com 0 nas casas vazias. Cada casa vazia é uma decisão, como as
posições das permutações, e as opções são os dígitos de 1 a 9. A **poda** é a
regra do jogo: um dígito que já aparece na linha, na coluna ou na caixa nem é
tentado. E, como nas N-rainhas, o teste é O(1) com **vetores de marcação**:

- `na_linha[l][d]` diz se o dígito `d` já está na linha `l`;
- `na_coluna[c][d]`, o mesmo para a coluna `c`;
- `na_caixa[b][d]`, para a caixa `b`, numerada de 0 a 8 por
  `b = (l / 3) * 3 + c / 3`.

A função `resolve(k)` olha as casas na ordem de leitura (casa `k` é a linha
`k / 9`, coluna `k % 9`), pula as preenchidas e, na primeira vazia, tenta os
dígitos que passam pela poda. Para cada um: **escreve e marca**, desce para
`resolve(k + 1)`, e se lá embaixo não deu certo, **apaga e desmarca**. Se
nenhum dígito serve, devolve `false` e quem chamou tenta o próximo dígito
dele. Quando não sobra casa vazia, a grade está resolvida, e o `true` sobe
pela pilha de chamadas até o `main`, como no exemplo A254.

Vamos ver na prática. A primeira casa vazia é a (0, 1). A linha 0 já tem 2,
3 e 8; a coluna 1 tem 4, 9, 6, 3 e 1; a caixa 0 tem 2, 3, 6, 4 e 1. Sobram o
5 e o 7. O programa tenta o 5 primeiro, e só depois de muitos retrocessos lá
embaixo descobre que a resposta é o 7:

{{ideia}}

O programa completo, com o jogo da revista escrito como texto (`.` é casa
vazia):

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

São 51 casas vazias e 2999 chamadas: cerca de 59 por casa. A força bruta
pura testaria até 9⁵¹ preenchimentos, um número com 49 algarismos. A poda faz
quase todo o trabalho. E dá para podar ainda mais escolhendo **qual** casa
preencher: começar pela casa com menos candidatos derruba as chamadas deste
mesmo jogo para 64 (exemplo A260).

Repara no fluxograma: é o esqueleto do módulo inteiro, com a casa no lugar
do item e a regra do jogo no lugar da poda:

{{fluxograma}}

> [!WARNING]
> No desfazer, as duas coisas precisam voltar: o `g[l][c] = 0` **e** o
> `marca(..., false)`. Esquecer o `g[l][c] = 0` parece inofensivo, porque a
> próxima tentativa escreve outro dígito por cima. Mas, se nenhum dígito
> serve, a casa fica com o último que foi tentado e, na volta, o `while` do
> começo de `resolve` passa a tratá-la como uma casa **dada**. Faça o teste:
> sem essa linha, este programa termina em 64 chamadas mostrando uma grade
> "resolvida" com três 9 seguidos na primeira linha. O retrocesso só funciona
> se o estado volta a ser **exatamente** o de antes da escolha.

> [!TIP]
> **Por dentro do C:** os três vetores de marcação ocupam 3 × 9 × 10 = 270
> bytes (o índice 0 de cada linha nunca é usado: desperdiçar um byte deixa o
> código usar o próprio dígito como índice). A grade `int g[9][9]` tem 324
> bytes, contínuos na memória. A recursão desce no máximo 52 frames, um por
> casa vazia mais o último, então a pilha nem percebe. A conta
> `jogo[l][c] - '0'` transforma o caractere `'7'` (código 55) no número 7,
> porque os dígitos são consecutivos na tabela ASCII (assunto 0040).

> [!NOTE]
> **Pergunta para você:** apague o 5 da última casa da linha 5 (troque
> `"164.9...5"` por `"164.9...."`). O programa ainda mostra a mesma grade? O
> número de chamadas sobe ou desce? E o jogo continua com uma solução só?
> (Para responder a última, faça o exercício E778.)

{{pratique}}
