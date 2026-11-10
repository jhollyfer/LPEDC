## 0056 · Matriz dinâmica

Uma rede de lojas quer a planilha de vendas: uma linha por loja, uma coluna
por semana. Este mês são 3 lojas e 4 semanas. Mês que vem abre a quarta loja,
e o trimestre tem 13 semanas. Uma matriz `int vendas[3][4]` não serve: as
dimensões só aparecem quando o programa roda.

O C só aloca **vetores** (uma dimensão). Para ter uma matriz, você monta uma
com vetores, de dois jeitos.

**1. Um bloco só.** Aloque `linhas * colunas` elementos e calcule a posição: o
elemento `(i, j)` fica em `v[i * colunas + j]`, a conta que o compilador faz
numa matriz fixa (assunto 0039). Um `malloc`, um `free`, tudo contíguo. O
preço: `v[i][j]` não funciona.

**2. Vetor de ponteiros.** Um vetor de `linhas` ponteiros (`int **m`), um por
linha, e um `malloc` por linha com `colunas` inteiros. Agora `m[i][j]`
funciona: `m[i]` é o endereço da linha i e `[j]` anda dentro dela (o `**` do
assunto 0049).

Regra para o `sizeof`: **o que você aloca tem um `*` a menos que o ponteiro
que recebe**. `int **m` recebe um vetor de `int *`; `m[i]` (`int *`) recebe um
vetor de `int`. Com `sizeof *m` e `sizeof *m[i]`, a conta sai certa.

O C99 tem um atalho, o **VLA**: `int vendas[lojas][semanas];`. Ele mora na
**pilha**, que é pequena e não avisa quando estoura; o assunto 0172 mostra
quando vale a pena.

Para liberar, a ordem importa: **primeiro cada linha, depois o vetor de
ponteiros**. Com `free(m)` antes, você perde os endereços das linhas, que
ficam presas no heap.

Se o `malloc` da terceira linha falhar, as duas primeiras já foram alocadas. A
função de criação precisa desfazê-las antes de devolver `NULL`.

A matriz de 3 lojas por 4 semanas é um vetor de 3 ponteiros, cada um para uma
linha de 4 inteiros. As linhas podem estar em qualquer lugar do heap:

{{ideia}}

O código separa criar e liberar em funções. As vendas estão em R$ mil:

```c
#include <stdio.h>
#include <stdlib.h>

void liberar_matriz(int **m, int linhas) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < linhas; i++) {
        free(m[i]); // primeiro cada linha...
    }
    free(m);        // ...depois o vetor de ponteiros
}

int **criar_matriz(int linhas, int colunas) {
    int **m = malloc(linhas * sizeof *m); // vetor de int *: uma por linha
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        m[i] = malloc(colunas * sizeof *m[i]); // cada linha: colunas ints
        if (m[i] == NULL) {
            liberar_matriz(m, i); // desfaz as linhas que já deram certo
            return NULL;
        }
    }
    return m;
}

int main(void) {
    int lojas = 3;
    int semanas = 4;
    int vendas[3][4] = {{12, 15, 11, 18}, {9, 10, 14, 13}, {20, 17, 19, 22}}; // R$ mil

    int **m = criar_matriz(lojas, semanas);
    if (m == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    for (int i = 0; i < lojas; i++) {
        for (int j = 0; j < semanas; j++) {
            m[i][j] = vendas[i][j]; // a notação de sempre
        }
    }

    for (int i = 0; i < lojas; i++) {
        int total = 0;
        for (int j = 0; j < semanas; j++) {
            total += m[i][j];
        }
        printf("Loja %d: R$ %d mil\n", i + 1, total);
    }

    liberar_matriz(m, lojas);
    return 0;
}
// Saída:
// Loja 1: R$ 56 mil
// Loja 2: R$ 46 mil
// Loja 3: R$ 78 mil
```

A criação é um laço com saída de emergência: se uma linha falhar, o caminho de
erro libera o que já existe:

{{fluxograma}}

> [!WARNING]
> `int **m = malloc(linhas * sizeof(int));` é um bug comum. Num PC de 64 bits,
> `int` tem 4 bytes e `int *` tem 8: você aloca metade do necessário e as
> últimas linhas são gravadas fora do bloco. Escreva `sizeof *m`.

> [!TIP]
> `m[i][j]` com `int **` faz **dois** acessos à memória (o ponteiro `m[i]` e
> o inteiro); numa matriz fixa ou no bloco único é um só. Em troca, as linhas
> podem ter **tamanhos diferentes** (no triângulo de Pascal, a linha i tem
> i + 1 elementos).

> [!NOTE]
> **Pergunta para você:** quantos `malloc` e quantos `free` o código acima faz
> para 3 lojas? E para 100 lojas? Quantos faria a versão de bloco único (A112)?

{{pratique}}
