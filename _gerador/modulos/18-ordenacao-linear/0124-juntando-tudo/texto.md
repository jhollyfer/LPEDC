## 0124 · Juntando tudo

- **Ordenação linear**: troca a comparação por **suposições sobre os dados**,
  como chave inteira numa faixa conhecida (CORMEN et al., 2024, cap. 8).
- **Duas chaves**: ordene pela **menos** importante e depois, com um método
  **estável**, pela mais importante. É a ideia do radix LSD
  (CORMEN et al., 2024, cap. 8).
- **`qsort`**: ordena qualquer tipo. Move blocos de bytes e chama a função de
  comparação por ponteiro, sem conhecer o tipo nem a faixa da chave
  (KERNIGHAN; RITCHIE, 1989).
- **`clock()`**: de `<time.h>`, dá o tempo de processador. A diferença entre
  duas chamadas, dividida por `CLOCKS_PER_SEC`, vira segundos (CPPREFERENCE, s.d.).
- **Teste por comparação**: ordenar uma cópia com o `qsort` e conferir se a
  ordem bate é o jeito mais simples de testar uma ordenação escrita à mão.

| Algoritmo | Custo | Memória extra | Estável | Quando usar |
| --- | --- | --- | --- | --- |
| shell sort | ~n^1,25 (Knuth: pior n^1,5) | O(1) | não | vetores médios, pouca memória, código curto |
| counting sort | O(n + k) | O(n + k) | sim | chaves inteiras num intervalo pequeno |
| radix sort | O(d · (n + b)) | O(n + b) | sim | inteiros ou strings de tamanho fixo |
| bucket sort | O(n) médio, O(n²) pior | O(n) | sim (inserindo depois dos iguais) | valores reais bem espalhados num intervalo conhecido |
| quickselect | O(n) médio, O(n²) pior | O(1) | não | o k-ésimo, a mediana, os k maiores, sem ordenar |
| qsort | O(n log n) | depende da biblioteca | não garantido | qualquer tipo, qualquer critério |

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
