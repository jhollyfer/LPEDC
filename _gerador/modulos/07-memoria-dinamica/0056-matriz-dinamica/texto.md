## 0056 · Matriz dinâmica

Uma rede de lojas quer a planilha de vendas: uma linha por loja, uma coluna
por semana. Este mês são 3 lojas e 4 semanas. No mês que vem abre a quarta
loja, e o relatório do trimestre tem 13 semanas. Uma matriz fixa como `int
vendas[3][4]` (assunto 0039) não serve, porque as dimensões só aparecem com
o programa rodando. Você precisa de uma matriz pedida ao heap.

O problema é que o `malloc` só entrega blocos de **uma dimensão**: uma fila
de bytes, sem linhas nem colunas. A matriz dinâmica é montada a partir de
vetores, e há dois jeitos clássicos de montá-la (CELES; RANGEL, 2002).

O primeiro é o **bloco único**. Você aloca `linhas * colunas` elementos de
uma vez, uma fila só, e calcula a posição de cada célula: o elemento da linha
`i` e coluna `j` fica em `v[i * colunas + j]`. É a mesma conta que o
compilador faz por você numa matriz fixa, guardada linha após linha. A
vantagem é a simplicidade: um `malloc`, um `free` e tudo colado na memória.
O preço é a escrita: `v[i][j]` não funciona, porque `v` é um vetor simples
(BACKES, 2013, cap. 11).

O segundo é o **vetor de ponteiros**. Primeiro você aloca um vetor com
`linhas` ponteiros, guardado num `int **m`; depois faz um `malloc` por linha,
cada um com `colunas` inteiros, e guarda o endereço em `m[i]`. Agora
`m[i][j]` funciona: `m[i]` é o endereço da linha `i`, e o `[j]` anda dentro
dela, os dois saltos do assunto 0049. Pense num fichário: a primeira folha é
um índice que diz em que página começa cada loja, e cada página é uma linha.
Como cada linha é pedida em separado, elas podem ter **tamanhos diferentes**;
no triângulo de Pascal, a linha `i` tem `i + 1` elementos (FEOFILOFF, 2009,
ap. F).

Na hora de pedir, o `sizeof` confunde. A regra é: **o que você aloca tem um
`*` a menos que o ponteiro que recebe**. `int **m` recebe um vetor de
`int *`, então o primeiro pedido usa o tamanho de um `int *`. `m[i]`, que é
um `int *`, recebe um vetor de `int`. Escrever `sizeof *m` e `sizeof *m[i]`
deixa o compilador fazer essa conta por você (BACKES, 2013, cap. 11).

Liberar também tem ordem: **primeiro cada linha, depois o vetor de
ponteiros**. Se você fizer `free(m)` antes, perde os endereços das linhas, e
elas ficam presas no heap. O mesmo cuidado vale na criação: se o `malloc` da
terceira linha falhar, as duas primeiras já foram alocadas, e a função
precisa liberá-las antes de devolver `NULL` (CELES; RANGEL, 2002).

O C99 oferece um atalho, o **VLA**: `int vendas[lojas][semanas];`, com as
dimensões vindas de variáveis. Ele mora na **pilha**, que é pequena e não
avisa quando estoura (BACKES, 2013). O assunto 0172 mostra quando ele vale a
pena.

Os dois jeitos têm custos diferentes. Com `int **`, cada `m[i][j]` faz
**dois** acessos à memória, um para buscar o ponteiro `m[i]` e outro para o
inteiro. No bloco único, ou numa matriz fixa, é um acesso só (CELES; RANGEL,
2002). Em troca, o vetor de ponteiros dá a escrita `m[i][j]` e as linhas de
tamanhos diferentes.

> [!WARNING]
> `int **m = malloc(linhas * sizeof(int));` é bug: num PC de 64 bits, `int`
> tem 4 bytes e `int *` tem 8. Você aloca metade do necessário e as últimas
> linhas são gravadas fora do bloco. Escreva `sizeof *m`.

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
