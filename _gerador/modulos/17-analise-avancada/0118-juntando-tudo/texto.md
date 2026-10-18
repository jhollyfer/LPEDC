## 0118 · Juntando tudo

A loja virtual vai mudar o relatório do fim do dia: em vez de 16 mil pedidos,
agora ele vai ordenar **1 milhão**. O programador testou com 16 mil e mediu
alguns milissegundos. A pergunta da gerente é simples: "e com 1 milhão,
quanto tempo vai levar?". Rodar para ver pode demorar meia hora. Dá para
**prever** antes?

Dá, e é para isso que serve tudo o que veio neste módulo. A receita tem
quatro passos:

1. **Conhecer a classe.** Pela recorrência ou pela contagem: o insertion
   sort é `T(n) = T(n-1) + n`, Θ(n²); o merge sort é `2 T(n/2) + n`,
   Θ(n log n) pelo teorema mestre; o heapsort faz `n` descidas de
   O(log n); o quick sort é Θ(n log n) em média. E o limite inferior diz que
   nenhum deles pode fazer menos de `log₂ n!` comparações no pior caso.
2. **Medir em dois tamanhos, um o dobro do outro.** Se a classe está certa,
   dobrar `n` multiplica o custo por 4 (n²) ou por um pouco mais de 2
   (n log n). Se a razão não bater, a análise ou o código têm problema.
3. **Extrapolar.** Do tamanho medido `n` para o tamanho `N`, o custo é
   multiplicado por `(N/n)²` na classe n², ou por `(N log N)/(n log n)` na
   classe n log n.
4. **Conferir**, quando der para rodar o tamanho grande.

Medir tem duas réguas. A **contagem de comparações** sai igual em qualquer
computador e é a que confere a teoria. O **tempo** (com `clock()`, de
`<time.h>`) é o que a gerente quer saber, mas muda de máquina para máquina e
até de uma execução para outra. O programa usa as duas.

As quatro ordenações ficam num TAD, `ordena.h` e `ordena.c`, na pasta do
assunto. Toda comparação passa por uma função `menor` escondida no `.c`, que
conta:

```c
void ord_insertion(int v[], int n); // Θ(n²) no caso médio e no pior
void ord_merge(int v[], int n);     // Θ(n log n) sempre; usa um rascunho de n
void ord_heap(int v[], int n);      // Θ(n log n) sempre; in-place
void ord_quick(int v[], int n);     // Θ(n log n) em média; pivô = o do meio

void ord_zera_contagem(void);
long ord_contagem(void);
int ord_confere(const int v[], int n);
```

Vamos ver na prática. Os pedidos são números sorteados com um gerador
próprio, para a entrada ser a mesma em qualquer máquina. Cada algoritmo
ordena 8 mil e 16 mil; da razão sai a confirmação da classe, e da medida de
16 mil sai a previsão para 1 milhão. Em verde, o que a previsão acertou; em
vermelho, o que nem dá para rodar:

{{ideia}}

O programa mede, prevê e confere. O `insertion` só ganha previsão: rodar de
verdade levaria quase meia hora:

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

Leia a saída em três camadas. As **razões** confirmam as classes: ×4,00 no
insertion, ×2,17 a ×2,29 nos outros três. As **previsões** de comparações
ficaram a menos de 4% do medido: o modelo `n log n` ignora termos menores,
então erra um pouco para baixo. E o **tempo** do insertion para 1 milhão,
1.600 segundos, é uns 27 minutos, contra um terço de segundo do merge sort:
a mesma tarefa, mais de 5 mil vezes mais lenta.

Repara no fluxograma: é a receita, para um algoritmo. O caminho marcado é o
do merge sort, que passa pela previsão e pela conferência:

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

> [!WARNING]
> Na classe n log n, dobrar `n` **não** dá ×2 exato. De 8 mil para 16 mil, a
> conta é `2 · log₂ 16.000 / log₂ 8.000 = 2,15`, e quem espera ×2 acha que o
> algoritmo "está piorando". E o contrário também engana: com `n` pequeno
> (algumas centenas), o tempo é dominado por constantes, chamadas de função e
> cache, e as razões saem malucas. Meça com tamanhos grandes o bastante para
> o tempo passar de alguns milissegundos, e sempre a partir da **mesma
> entrada**: o `memcpy` do `mede` restaura o vetor original antes de cada
> ordenação. Sem ele, o segundo algoritmo receberia o vetor já ordenado.

> [!TIP]
> **Por dentro do C:** `clock()` devolve o tempo de processador gasto pelo
> programa, em "tiques"; `CLOCKS_PER_SEC` diz quantos tiques há num segundo
> (no Linux, 1.000.000). As duas coisas são inteiras: escrever
> `(clock() - ini) / CLOCKS_PER_SEC` faz divisão inteira e dá **0** para
> tudo que dura menos de um segundo. Por isso o `1000.0 *` na frente, que
> converte para `double` antes de dividir. E lembre que o `rodar` compila sem
> otimização e com o AddressSanitizer, que vigia cada acesso à memória: os
> tempos aqui são várias vezes maiores que os de um `gcc -O2` sem
> sanitizador. As **razões**, porém, continuam valendo, e é com elas que a
> previsão trabalha.

> [!NOTE]
> **Pergunta para você:** o quick sort daqui usa o elemento do meio como
> pivô. Ele continuaria rápido se o vetor de entrada já estivesse em ordem?
> E se os 1 milhão de pedidos tivessem só 10 valores diferentes (as notas de
> 0 a 9 de uma avaliação)? Pense na partição antes de rodar o exemplo A235.

{{pratique}}
