## 0056 · Matriz dinâmica

- **Só vetores**: o C aloca blocos de uma dimensão. A matriz dinâmica é montada
  com vetores, de dois jeitos (CELES; RANGEL, 2002).
- **Bloco único**: `linhas * colunas` elementos, com o elemento `(i, j)` em
  `v[i * colunas + j]`. Um `malloc`, um `free`, mas `v[i][j]` não funciona
  (BACKES, 2013, cap. 11).
- **Vetor de ponteiros**: um vetor de `linhas` ponteiros (`int **m`) e um
  `malloc` por linha. Agora `m[i][j]` funciona, e as linhas podem ter tamanhos
  diferentes (FEOFILOFF, 2009, ap. F).
- **Regra do `sizeof`**: o que você aloca tem um `*` a menos que o ponteiro
  que recebe. Use `sizeof *m` e `sizeof *m[i]` (BACKES, 2013, cap. 11).
- **Liberar na ordem**: primeiro cada linha, depois o vetor de ponteiros. Se
  uma linha falhar ao criar, desfaça as anteriores antes de devolver `NULL`
  (CELES; RANGEL, 2002).
- **VLA** (C99): `int vendas[lojas][semanas];` mora na pilha, que é pequena e
  não avisa quando estoura (BACKES, 2013).
- **Custo**: `m[i][j]` com `int **` faz dois acessos à memória; o bloco único
  faz um (CELES; RANGEL, 2002).

> [!WARNING]
> `int **m = malloc(linhas * sizeof(int));` é bug: num PC de 64 bits, `int` tem
> 4 bytes e `int *` tem 8. Você aloca metade e grava fora do bloco. Escreva
> `sizeof *m`.

{{exemplo}}

A planilha de vendas de 3 lojas por 4 semanas (em R$ mil) vira um vetor de 3
ponteiros, cada um para uma linha de 4 inteiros, em qualquer lugar do heap:

{{ideia}}

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
