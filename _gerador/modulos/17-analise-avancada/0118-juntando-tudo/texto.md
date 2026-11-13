## 0118 · Juntando tudo

O relatório de uma loja virtual vai ordenar 1 milhão de pedidos, e o
programador só testou com 16 mil. Rodar para ver pode levar meia hora, ou
nunca terminar. A análise do módulo serve exatamente para isso: **prever**
antes de rodar. Conhecida a classe de custo de um algoritmo, uma medida num
tamanho pequeno estima o tamanho grande (ZIVIANI, 2010, cap. 1).

O primeiro passo é conhecer a classe de cada candidato, com as ferramentas dos
assuntos anteriores. O insertion sort tem recorrência `T(n) = T(n-1) + n`, que
a árvore de recursão resolve em Θ(n²). O merge sort tem `2 T(n/2) + n`, caso 2
do teorema mestre, Θ(n log n). O heapsort faz `n` descidas no heap, cada uma
de O(log n). O quick sort fica em Θ(n log n) na média (CORMEN et al., 2024,
cap. 4).

O segundo passo é medir em dois tamanhos, um o dobro do outro, e olhar a
razão entre as medidas. Ela confirma a classe. Na classe n², dobrar `n`
multiplica o custo por 4, porque `(2n)² = 4n²`. Na classe n log n, multiplica
por pouco mais de 2: o fator 2 vem do `n`, e o log também sobe um pouco
(FEOFILOFF, 2009). Se você esperava 2 e mediu 4, a classe não é a que você
pensava.

O terceiro passo é extrapolar. Para ir de um tamanho `n` medido a um tamanho
`N` maior, multiplique a medida por `(N/n)²` na classe n², ou por
`(N log N)/(n log n)` na classe n log n (ZIVIANI, 2010, cap. 1). De 16 mil
para 1 milhão, `N/n` é 62,5. Na classe n², isso multiplica o custo por cerca
de 3.900; na classe n log n, por cerca de 89. É a diferença entre alguns
segundos e algumas horas. O quarto passo, quando dá, é rodar o tamanho grande
e conferir a previsão.

Há duas réguas para medir. A **contagem de comparações** dá o mesmo número em
qualquer computador, porque depende só do algoritmo e da entrada. O **tempo**
varia de máquina para máquina e de execução para execução (TENENBAUM;
LANGSAM; AUGENSTEIN, 1995, cap. 6). O exemplo usa as duas: as quatro
ordenações ficam num TAD, e toda comparação passa por uma função escondida no
`.c` que conta as chamadas.

Para o tempo, `<time.h>` oferece `clock()`, que devolve quantos tiques de
processador o programa já gastou. A constante `CLOCKS_PER_SEC` diz quantos
tiques cabem num segundo, e no Linux vale 1.000.000. Os dois são inteiros, e
isso pega muita gente: `(clock() - ini) / CLOCKS_PER_SEC` é divisão inteira e
dá **0** para qualquer trecho abaixo de um segundo. Por isso o código põe
`1000.0 *` na frente, que força a conta em `double` e já converte para
milissegundos (CPPREFERENCE, s.d.). O exemplo compila sem otimização e com
AddressSanitizer, o verificador de memória do gcc: os tempos saem maiores, mas
as **razões** entre eles não mudam.

> [!WARNING]
> Na classe n log n, dobrar `n` **não** dá ×2 exato: de 8 mil para 16 mil, é
> 2,15. Com `n` pequeno, constantes e cache distorcem as razões. Meça com
> tamanhos grandes e com a **mesma entrada**: o `memcpy` do `mede` restaura o
> vetor antes de cada ordenação.

{{exemplo}}

O relatório da loja virtual vai ordenar **1 milhão** de pedidos, e o
programador só mediu com 16 mil. Cada algoritmo ordena 8 mil e 16 mil; a razão
confirma a classe e a medida de 16 mil prevê o milhão. Verde acertou;
vermelho nem dá para rodar:

{{ideia}}

As quatro ordenações ficam no TAD `ordena.h` e `ordena.c`. Toda comparação
passa por uma função `menor`, escondida no `.c`, que conta:

```c
void ord_insertion(int v[], int n); // Θ(n²) no caso médio e no pior
void ord_merge(int v[], int n);     // Θ(n log n) sempre; usa um rascunho de n
void ord_heap(int v[], int n);      // Θ(n log n) sempre; in-place
void ord_quick(int v[], int n);     // Θ(n log n) em média; pivô = o do meio

void ord_zera_contagem(void);
long ord_contagem(void);
int ord_confere(const int v[], int n);
```

O programa mede, prevê e confere; o `insertion` só ganha previsão, pois rodar
levaria quase meia hora:

```c
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordena.h"

typedef struct {
    const char *nome;
    void (*ordena)(int[], int);
    int quadratico; // 1 se Θ(n²), 0 se Θ(n log n)
} Algoritmo;

// gerador próprio: a mesma entrada em qualquer computador
unsigned semente = 42;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8) % 1000000;
}

// ordena uma cópia de original[0..n-1] e devolve o tempo em ms
double mede(Algoritmo a, const int original[], int v[], int n) {
    memcpy(v, original, n * sizeof *v);   // sempre a mesma entrada
    ord_zera_contagem();
    clock_t ini = clock();
    a.ordena(v, n);
    double ms = 1000.0 * (clock() - ini) / CLOCKS_PER_SEC;
    if (!ord_confere(v, n)) {
        printf("%s não ordenou!\n", a.nome);
    }
    return ms;
}

// quanto o custo cresce de n0 para n1, conforme a classe
double fator(int quadratico, double n0, double n1) {
    if (quadratico) {
        return (n1 / n0) * (n1 / n0);
    }
    return (n1 * log2(n1)) / (n0 * log2(n0));
}

int main(void) {
    Algoritmo algs[] = {
        {"insertion", ord_insertion, 1}, {"merge", ord_merge, 0},
        {"heap", ord_heap, 0},           {"quick", ord_quick, 0},
    };
    int n0 = 8000, n1 = 16000, grande = 1000000;
    int *original = malloc(grande * sizeof *original);
    int *v = malloc(grande * sizeof *v);
    if (original == NULL || v == NULL) {
        return 1;
    }
    for (int i = 0; i < grande; i++) {
        original[i] = sorteia();
    }

    for (int k = 0; k < 4; k++) {
        Algoritmo a = algs[k];
        double t0 = mede(a, original, v, n0);
        long c0 = ord_contagem();
        double t1 = mede(a, original, v, n1);
        long c1 = ord_contagem();
        printf("%s: %ld -> %ld comparações (x%.2f), %.1f -> %.1f ms\n",
               a.nome, c0, c1, (double)c1 / c0, t0, t1);

        double f = fator(a.quadratico, n1, grande);
        printf("  previsão para 1 milhão: %8.1f milhões de comparações, %7.2f s\n", c1 * f / 1e6, t1 * f / 1000);
        if (!a.quadratico) {                // o insertion levaria tempo demais
            double t = mede(a, original, v, grande);
            printf("  medido para 1 milhão:   %8.1f milhões de comparações, %7.2f s\n", ord_contagem() / 1e6, t / 1000);
        }
    }
    free(original);
    free(v);
    return 0;
}
// Saída (os tempos são de uma execução; na sua máquina serão outros, mas
// as comparações e as razões saem iguais):
// insertion: 16227286 -> 64831293 comparações (x4.00), 89.4 -> 421.3 ms
//   previsão para 1 milhão: 253247.2 milhões de comparações, 1645.73 s
// merge: 93744 -> 203390 comparações (x2.17), 1.6 -> 3.3 ms
//   previsão para 1 milhão:     18.1 milhões de comparações,    0.29 s
//   medido para 1 milhão:       18.7 milhões de comparações,    0.29 s
// heap: 182686 -> 397420 comparações (x2.18), 2.4 -> 5.3 ms
//   previsão para 1 milhão:     35.4 milhões de comparações,    0.47 s
//   medido para 1 milhão:       36.8 milhões de comparações,    0.53 s
// quick: 120347 -> 275805 comparações (x2.29), 1.3 -> 2.8 ms
//   previsão para 1 milhão:     24.6 milhões de comparações,    0.25 s
//   medido para 1 milhão:       25.0 milhões de comparações,    0.26 s
```

As **razões** confirmam as classes (×4,00 no insertion, ×2,17 a ×2,29 nos
outros) e as **previsões** ficaram a menos de 4% do medido. O fluxograma
aplica a receita ao merge sort:

{{fluxograma}}

### Passo a passo

A previsão do merge sort, de `n = 16.000` para `N = 1.000.000`:

| passo | conta | valor |
| --- | --- | --- |
| fator n log n | (1.000.000 · log₂ 1.000.000) / (16.000 · log₂ 16.000) | 19.931.569 / 223.453 = 89,2 |
| comparações previstas | 203.390 · 89,2 | 18,1 milhões |
| comparações medidas | (rodando) | 18,7 milhões |
| fator n² (insertion) | (1.000.000 / 16.000)² | 62,5² = 3.906 |
| comparações previstas | 64.831.293 · 3.906 | 253 bilhões |
