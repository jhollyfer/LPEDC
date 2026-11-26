## 0124 · Juntando tudo

Este módulo trouxe ordenações que fazem menos que n log n comparações, e o
assunto 0117 provou que isso é impossível para quem só compara. A conta fecha
porque essas ordenações não jogam o mesmo jogo. Elas trocam a comparação por
**suposições sobre os dados**: a chave é um inteiro numa faixa conhecida, os
dígitos têm tamanho fixo, os reais se espalham por um intervalo sabido
(CORMEN et al., 2024, cap. 8). Quando a suposição vale, o ganho é grande.
Quando falha, o resultado pode sair errado ou o programa pode escrever fora do
vetor.

Pense num banco que registrou 1 milhão de Pix, cada um com um número, a hora
em segundos desde a meia-noite e o valor em centavos. O time de fraudes quer
as transações em ordem de valor e a linha do tempo do dia em ordem de horário.
O `qsort` resolveria com uns 20 milhões de comparações. Só que as chaves são
inteiros: o horário vai de 0 a 86399 e o valor cabe em 4 bytes. É o terreno
das ordenações lineares.

O `qsort` da biblioteca (assunto 0096) ordena qualquer tipo, e o preço dessa
generalidade está no jeito como ele trabalha. Ele recebe o vetor como `void *`,
move blocos de bytes do tamanho que você informar e, para decidir a ordem,
chama a sua função de comparação por um ponteiro para função. Ele não conhece
o tipo do registro nem a faixa da chave (KERNIGHAN; RITCHIE, 1989). As
ordenações lineares exploram exatamente o que o `qsort` ignora.

Um dos relatórios tem **duas chaves**: horário e, no empate, valor. Os Pix do
mesmo segundo devem sair do menor para o maior valor. A solução vem do radix
sort LSD do assunto 0121. Ordene primeiro pela chave **menos** importante, o
valor. Depois ordene pela mais importante, o horário, com um método
**estável**. A estabilidade preserva, dentro de cada segundo, a ordem de valor
que a primeira passada deixou (CORMEN et al., 2024, cap. 8). O counting sort
com `k = 86400` contadores faz essa segunda passada.

Para comparar os métodos, o exemplo mede o tempo com `clock()`, de
`<time.h>`, que devolve o tempo de processador já gasto pelo programa. A
diferença entre duas chamadas, dividida por `CLOCKS_PER_SEC`, vira segundos
(CPPREFERENCE, s.d.). O assunto 0118 mostra o cuidado com a divisão inteira.

Ordenação escrita à mão precisa de teste, e há um jeito simples de testar:
ordene uma cópia dos dados com o `qsort`, que você sabe que está certo,
ordene outra com o seu método e confira se as duas saem na mesma ordem. Se
uma posição diferir, o erro está no seu código.

A tabela reúne os métodos do módulo e o `qsort`, para você escolher pelo que
os dados oferecem. Shell sort e quickselect funcionam com qualquer chave
comparável; counting, radix e bucket dependem de uma suposição sobre as
chaves; o `qsort` aceita qualquer tipo e qualquer critério:

| Algoritmo | Custo | Memória extra | Estável | Quando usar |
| --- | --- | --- | --- | --- |
| shell sort | ~n^1,25 (Knuth: pior n^1,5) | O(1) | não | vetores médios, pouca memória, código curto |
| counting sort | O(n + k) | O(n + k) | sim | chaves inteiras num intervalo pequeno |
| radix sort | O(d · (n + b)) | O(n + b) | sim | inteiros ou strings de tamanho fixo |
| bucket sort | O(n) médio, O(n²) pior | O(n) | sim (inserindo depois dos iguais) | valores reais bem espalhados num intervalo conhecido |
| quickselect | O(n) médio, O(n²) pior | O(1) | não | o k-ésimo, a mediana, os k maiores, sem ordenar |
| qsort | O(n log n) | depende da biblioteca | não garantido | qualquer tipo, qualquer critério |

As suposições aparecem também no código do exemplo. O radix sort do TAD
supõe `centavos` positivo: um estorno com valor negativo tem o byte mais alto
cheio de bits 1 e sairia no fim do relatório, depois dos maiores valores. O
exercício E726 mostra o conserto.

> [!WARNING]
> Chave fora da faixa escreve fora do vetor: um registro com
> `segundo = 86400` faz `c[86400]` estourar. Confira a faixa antes de usar o
> valor como índice.

{{exemplo}}

Um banco registrou 1 milhão de Pix. O time de fraudes pede dois relatórios:
por **valor** e por **horário**, com os Pix do mesmo segundo do menor para o
maior valor. O TAD `pix.h` tem um registro de 12 bytes:

```c
typedef struct {
    uint32_t id;       // número da transação, na ordem em que chegou
    int32_t segundo;   // hora do dia, em segundos desde a meia-noite
    int32_t centavos;  // valor, em centavos (sempre positivo)
} Pix;
```

- `pix_por_valor`: **radix sort** em base 256 (assunto 0121) sobre
  `centavos`, quatro passadas com um vetor auxiliar;
- `pix_por_horario`: **counting sort** (assunto 0120) com `k = 86400`
  contadores (337 KB), menor que `n`;
- `pix_compara_valor`: a comparação para o `qsort`, usada no teste de tempo.

O `qsort` ordena uma cópia e o radix a outra; os valores têm que sair na mesma
ordem. Depois, o counting sort reorganiza o vetor do radix pelo horário:

{{ideia}}

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

O radix levou menos de um terço do tempo do `qsort`. Os quatro primeiros do
dia estão em ordem de valor: a primeira ordenação sobreviveu à segunda. O
radix deste TAD supõe `centavos` positivo; um estorno negativo sairia no fim
(o E726 mostra o conserto).

{{fluxograma}}
