## 0052 · Juntando tudo: o ranking da feira

Sábado, fim de feira. A associação dos feirantes quer o ranking das barracas
pelo faturamento do dia e o nome da campeã. Há uma condição: a planilha
original não pode mudar de ordem, porque outras contas usam a posição de
cada barraca. Ordenar sem mexer nos dados parece contraditório, e resolver
isso usa quase tudo o que o módulo mostrou.

Os dados ficam em **vetores paralelos**: `produtos`, `qtd` e `preco` guardam
o nome, a quantidade vendida e o preço de cada barraca, e a mesma posição
`i` fala da mesma barraca nos três. O faturamento sai de uma conta por
posição, `fat[i] = qtd[i] * preco[i]`, e vai para um quarto vetor (DEITEL;
DEITEL, 2011, cap. 7).

A ideia central é ordenar **ponteiros** em vez de dados. Pense no índice
remissivo de um livro: as páginas não mudam de lugar, só a lista que aponta
para elas. Aqui, o índice é um **vetor de ponteiros** `const double
*ordem[N]` (assunto 0049), em que cada posição aponta para um elemento de
`fat`. O programa ordena `ordem`, e `fat` continua na ordem de sempre (CELES;
RANGEL, 2002).

Quem ordena é o **`qsort`** (assunto 0050), com uma função de comparação
escrita por você. Repare no que ela recebe. Os elementos de `ordem` são
`const double *`, e o `qsort` entrega à comparação o **endereço** de cada
elemento, como `const void *` (assunto 0051). A função converte esse
endereço para um ponteiro para ponteiro e dá dois saltos, `**`, até chegar
ao faturamento (KERRISK, s.d.).

Depois da ordenação, `ordem[0]` aponta para o maior faturamento. Para saber
o nome dessa barraca, falta a posição dela em `fat`. A **subtração de
ponteiros** (assunto 0047) resolve: `ordem[i] - fat` dá quantos elementos
existem entre o começo de `fat` e o elemento apontado, que é o índice. O
mesmo índice dá o nome em `produtos` (KERNIGHAN; RITCHIE, 1989, cap. 5).

O resumo da feira usa a **passagem por referência** (assunto 0046). A função
`resumo` devolve duas respostas: o total do dia, num `double *`, e **onde**
está o maior faturamento, num `const double **`. O segundo parâmetro tem dois
asteriscos porque a função muda um ponteiro do `main`, fazendo-o apontar para
a campeã (DEITEL; DEITEL, 2011, cap. 7).

Com tantos `const` e `*`, as declarações ficam longas. A técnica é ler da
direita para a esquerda: `const double * const *p` é "p é ponteiro para um
ponteiro constante para `double` constante". Cada `const` protege o que está
imediatamente à esquerda dele, ou o tipo, quando vem no começo (DEITEL;
DEITEL, 2011, cap. 7).

Ordenar ponteiros é uma técnica clássica por dois motivos. Cada troca do
`qsort` move só 8 bytes, mesmo que cada dado seja uma struct de 200 bytes
(módulo 08). E vários vetores de ponteiros, um por faturamento e outro por
nome, podem existir ao mesmo tempo sobre os mesmos dados; é a ideia dos
índices de um banco de dados.

> [!WARNING]
> `sizeof(double)` no `qsort` de `ordem` está errado: os elementos são
> **ponteiros**. Aqui os dois têm 8 bytes e o erro se esconde; com
> `int *ordem[]` e `sizeof(int)`, o `qsort` trocaria meio ponteiro. Escreva
> sempre `sizeof ordem[0]`.

{{exemplo}}

Fim de feira, 4 barracas: tomate (30 × R$ 6,50), alface (45 × R$ 3,00), queijo
(8 × R$ 32,00) e pastel (60 × R$ 9,00). Depois do `qsort`, `ordem[0]` aponta
para o pastel e `ordem[3]` para a alface, e `fat` segue igual:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

#define N 4

// devolve dois resultados: o total (double *) e ONDE está o maior (const double **)
void resumo(const double *v, int n, double *total, const double **maior) {
    *total = 0;
    *maior = v;
    for (const double *p = v; p < v + n; p++) {
        *total += *p;
        if (*p > **maior) {
            *maior = p;
        }
    }
}

// cada elemento de ordem é um const double *; o qsort entrega o ENDEREÇO dele
int maior_primeiro(const void *a, const void *b) {
    double x = **(const double * const *)a;
    double y = **(const double * const *)b;
    return (x < y) - (x > y); // decrescente
}

int main(void) {
    const char *produtos[N] = {"tomate", "alface", "queijo", "pastel"};
    int qtd[N] = {30, 45, 8, 60};
    double preco[N] = {6.50, 3.00, 32.00, 9.00};
    double fat[N];               // faturamento de cada barraca
    const double *ordem[N];      // ponteiros para fat: é isso que vamos ordenar

    for (int i = 0; i < N; i++) {
        fat[i] = qtd[i] * preco[i];
        ordem[i] = &fat[i];
    }
    qsort(ordem, N, sizeof ordem[0], maior_primeiro); // fat continua intacto

    for (int i = 0; i < N; i++) {
        int k = (int)(ordem[i] - fat); // ponteiro - início = índice do produto
        printf("%dº %-7s R$ %7.2f\n", i + 1, produtos[k], *ordem[i]);
    }

    double total;
    const double *maior;
    resumo(fat, N, &total, &maior);
    printf("Total: R$ %.2f  Campeão: %s\n", total, produtos[maior - fat]);
    return 0;
}
// Saída:
// 1º pastel  R$  540.00
// 2º queijo  R$  256.00
// 3º tomate  R$  195.00
// 4º alface  R$  135.00
// Total: R$ 1126.00  Campeão: pastel
```

Três fases: calcula e aponta, ordena os ponteiros e percorre a ordem nova,
traduzindo cada ponteiro em índice:

{{fluxograma}}
