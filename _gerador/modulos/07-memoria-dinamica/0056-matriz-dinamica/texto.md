## 0056 · Matriz dinâmica

Uma rede de lojas quer a planilha de vendas: uma linha por loja, uma coluna
por semana. Este mês são 3 lojas e 4 semanas. Mês que vem abre a quarta loja,
e o trimestre tem 13 semanas. Uma matriz `int vendas[3][4]` não serve: as
dimensões só aparecem quando o programa roda.

O C só sabe alocar dinamicamente **vetores**, blocos de uma dimensão. Para ter
uma matriz, você monta uma com vetores. Tem dois jeitos clássicos.

**1. Um bloco só.** Aloque `linhas * colunas` elementos e calcule a posição na
mão: o elemento `(i, j)` fica em `v[i * colunas + j]`. É a mesma conta que o
compilador faz por baixo numa matriz fixa (assunto 0039). Um `malloc`, um
`free`, tudo contíguo. O preço: a notação `v[i][j]` não funciona.

**2. Vetor de ponteiros.** Primeiro um vetor de `linhas` ponteiros
(`int **m`), um para cada linha. Depois, um `malloc` por linha, cada uma com
`colunas` inteiros. Agora `m[i][j]` funciona: `m[i]` é o endereço da linha i,
e `[j]` anda dentro dela (é o `**` do assunto 0049 em ação).

Uma regra ajuda a não errar o `sizeof`: **o que você aloca tem um `*` a menos
que o ponteiro que recebe**. `int **m` recebe um vetor de `int *`; `m[i]`, que
é `int *`, recebe um vetor de `int`. Com `sizeof *m` e `sizeof *m[i]`, a conta
sai certa sozinha.

Para liberar, a ordem importa: **primeiro cada linha, depois o vetor de
ponteiros**. Se você der `free(m)` antes, perde os endereços das linhas, e
elas ficam presas no heap para sempre.

E se o `malloc` da terceira linha falhar? As duas primeiras já foram
alocadas. A função de criação precisa desfazer o que já fez antes de devolver
`NULL`: é o tipo de cuidado que separa um programa de brinquedo de um
programa de verdade.

Vamos ver na prática. A matriz de 3 lojas por 4 semanas é um vetor de 3
ponteiros, cada um apontando para uma linha de 4 inteiros. As linhas podem
estar em qualquer lugar do heap, nem precisam ficar juntas:

{{ideia}}

O código separa criar e liberar em funções, como você faria num projeto. As
vendas estão em R$ mil:

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

Repara no fluxograma da criação: é um laço com uma saída de emergência. Se
uma linha falhar, o caminho de erro passa pela liberação do que já existe:

{{fluxograma}}

> [!WARNING]
> O `sizeof` errado no vetor de ponteiros é um bug que muitos livros trazem:
> `int **m = malloc(linhas * sizeof(int));`. Num PC de 64 bits, `int` tem 4
> bytes e `int *` tem 8: você aloca metade do necessário e as últimas linhas
> são gravadas fora do bloco. Funciona "às vezes" e corrompe o heap. Escreva
> `sizeof *m` e esse erro some.

> [!TIP]
> **Por dentro do C:** `m[i][j]` com `int **` faz **dois** acessos à memória:
> lê o ponteiro `m[i]` e depois o inteiro. Numa matriz fixa ou no bloco único,
> é um acesso só, com uma conta. As linhas soltas no heap também não ficam
> vizinhas, o que piora o uso do cache do processador. Em troca, você ganha
> `m[i][j]` e linhas de **tamanhos diferentes**: num triângulo de Pascal, a
> linha i tem i + 1 elementos. Existe ainda um meio-termo: um bloco único com
> os dados e um vetor de ponteiros com `m[i] = bloco + i * colunas`. São só
> dois `malloc`, os dados ficam contíguos e `m[i][j]` continua valendo.

> [!NOTE]
> **Pergunta para você:** quantos `malloc` e quantos `free` o A111 faz para 3
> lojas? E para 100 lojas? Quantos faria a versão de bloco único (A112)?

{{pratique}}
