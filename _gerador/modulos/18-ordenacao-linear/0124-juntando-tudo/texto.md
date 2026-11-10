## 0124 · Juntando tudo

Um banco registrou 1 milhão de Pix, cada um com número, hora (segundos desde a
meia-noite) e valor em centavos. O time de fraudes pede dois relatórios: as
transações em ordem de **valor** e a linha do tempo do dia em ordem de
**horário**, com os Pix do mesmo segundo do menor para o maior valor.

O `qsort` (assunto 0096) faria uns 20 milhões de comparações por ponteiro de
função. Como as chaves são inteiros (horário de 0 a 86399, valor em 4 bytes),
servem as ordenações lineares do módulo. O TAD `pix.h` tem um registro de 12
bytes:

```c
typedef struct {
    uint32_t id;       // número da transação, na ordem em que chegou
    int32_t segundo;   // hora do dia, em segundos desde a meia-noite
    int32_t centavos;  // valor, em centavos (sempre positivo)
} Pix;
```

As funções principais:

- `pix_por_valor`: **radix sort** em base 256 (assunto 0121) sobre
  `centavos`: quatro passadas de counting sort estável, com um vetor auxiliar
  do mesmo tamanho;
- `pix_por_horario`: **counting sort** (assunto 0120) direto, com
  `k = 86400` contadores (337 KB): `k` é menor que `n`, e o O(n + k) é linear;
- `pix_compara_valor`: a comparação para o `qsort`, usada no teste de tempo.

O segundo relatório tem **duas chaves**: horário e, no empate, valor. Pela
ideia do radix sort LSD, ordene pela chave **menos** importante (valor) e
depois, com um método **estável**, pela mais importante (horário). A
estabilidade preserva a ordem de valor dentro de cada segundo.

O `qsort` ordena uma cópia dos dados e o radix a outra, e os valores têm que
sair na mesma ordem. Depois, o counting sort reorganiza o vetor do radix pelo
horário:

{{ideia}}

O programa mede o tempo com `clock()`, de `<time.h>`: a diferença entre duas
chamadas, dividida por `CLOCKS_PER_SEC`, dá os segundos gastos.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pix.h"

#define N 1000000

// tempo de processador gasto desde inicio, em segundos
double desde(clock_t inicio) {
    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
}

int main(void) {
    Pix *a = malloc(N * sizeof(Pix));
    Pix *b = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    if (a == NULL || b == NULL || aux == NULL) {
        free(a);
        free(b);
        free(aux);
        return 1;
    }
    pix_gera(a, N, 2024);
    memcpy(b, a, N * sizeof(Pix));     // os mesmos dados nos dois vetores

    clock_t t = clock();
    qsort(a, N, sizeof(Pix), pix_compara_valor);
    printf("qsort pelo valor:      %.2f s\n", desde(t));

    t = clock();
    pix_por_valor(b, aux, N);
    printf("radix pelo valor:      %.2f s\n", desde(t));

    int iguais = 1;
    for (int i = 0; i < N; i++) {
        if (a[i].centavos != b[i].centavos) {
            iguais = 0;
        }
    }
    printf("mesma ordem de valores? %s\n", iguais ? "sim" : "não");

    // segunda chave: pelo horário. O counting sort é estável, então dentro
    // do mesmo segundo os Pix continuam em ordem de valor
    t = clock();
    bool ok = pix_por_horario(b, aux, N);
    printf("counting pelo horário: %.2f s\n", desde(t));
    if (ok) {
        printf("os 4 primeiros do dia:\n");
        for (int i = 0; i < 4; i++) {
            pix_mostra(&b[i]);
        }
    }
    free(a);
    free(b);
    free(aux);
    return 0;
}
// Saída (os tempos mudam a cada execução e de máquina para máquina):
// qsort pelo valor:      0.28 s
// radix pelo valor:      0.08 s
// mesma ordem de valores? sim
// counting pelo horário: 0.04 s
// os 4 primeiros do dia:
// #0024846 00:00:00 R$       1,98
// #0293406 00:00:00 R$       7,46
// #0871952 00:00:00 R$      14,86
// #0653423 00:00:00 R$      21,63
```

O radix levou menos de um terço do tempo do `qsort`, e o counting pelo horário
menos ainda. Os quatro primeiros do dia são de 00:00:00 e estão em ordem de
valor: a primeira ordenação sobreviveu à segunda. Comparar com o `qsort` é o
jeito mais simples de testar uma ordenação escrita à mão:

{{fluxograma}}

### Qual usar?

O resumo do módulo:

| Algoritmo | Custo | Memória extra | Estável | Quando usar |
| --- | --- | --- | --- | --- |
| shell sort | ~n^1,25 (Knuth: pior n^1,5) | O(1) | não | vetores médios, pouca memória, código curto |
| counting sort | O(n + k) | O(n + k) | sim | chaves inteiras num intervalo pequeno |
| radix sort | O(d · (n + b)) | O(n + b) | sim | inteiros ou strings de tamanho fixo |
| bucket sort | O(n) médio, O(n²) pior | O(n) | sim (inserindo depois dos iguais) | valores reais bem espalhados num intervalo conhecido |
| quickselect | O(n) médio, O(n²) pior | O(1) | não | o k-ésimo, a mediana, os k maiores, sem ordenar |
| qsort | O(n log n) | depende da biblioteca | não garantido | qualquer tipo, qualquer critério |

> [!WARNING]
> Ordenação linear troca a comparação por **suposições sobre os dados**. Um
> registro com `segundo = 86400` faz `c[86400]` escrever fora do vetor:
> confira a faixa antes de usar o valor como índice. O radix deste TAD também
> supõe `centavos` positivo; um estorno negativo sairia no fim (o E726 mostra o
> conserto).

> [!TIP]
> **Por dentro do C:** o `qsort` não conhece o `Pix`: move blocos de 12 bytes e
> chama `pix_compara_valor` por ponteiro. As ordenações lineares exploram o que
> ele ignora, o tipo e a faixa da chave.

> [!NOTE]
> **Pergunta para você:** nenhum Pix passa de R$ 9999,99 (999999 centavos,
> menos que 2²⁰), então o byte 3 de todos os valores é zero. Quantas passadas
> bastariam, e o que a quarta faz com o vetor?

{{pratique}}
