## 0124 · Juntando tudo

Fim do dia num banco digital: 1 milhão de Pix registrados, cada um com um
número, a hora (em segundos desde a meia-noite) e o valor em centavos. O time
de prevenção a fraudes pede dois relatórios: as transações em ordem de
**valor**, e a linha do tempo do dia em ordem de **horário**, com os Pix do
mesmo segundo do menor para o maior valor.

O caminho de sempre é o `qsort` (assunto 0096): ele ordena qualquer coisa,
desde que você dê uma função de comparação. Para 1 milhão de registros, são
uns 20 milhões de comparações, e cada uma é uma **chamada de função** por
ponteiro. Mas aqui as chaves são inteiros: o horário vai de 0 a 86399, e o
valor cabe em 4 bytes. É território das ordenações lineares deste módulo.

O TAD `pix.h` junta as peças. O registro tem 12 bytes:

```c
typedef struct {
    uint32_t id;       // número da transação, na ordem em que chegou
    int32_t segundo;   // hora do dia, em segundos desde a meia-noite
    int32_t centavos;  // valor, em centavos (sempre positivo)
} Pix;
```

E as funções que importam:

- `pix_por_valor`: **radix sort** em base 256 (assunto 0121) sobre o campo
  `centavos`. Quatro passadas, cada uma um counting sort estável pelo byte da
  vez, com um vetor auxiliar do mesmo tamanho;
- `pix_por_horario`: **counting sort** (assunto 0120) direto, com
  `k = 86400` contadores. Um vetor de 337 KB de contadores para 1 milhão de
  registros: `k` é menor que `n`, e o O(n + k) é linear de verdade;
- `pix_compara_valor`: a função de comparação para o `qsort`, para a
  comparação de tempo.

O segundo relatório tem **duas chaves**: horário e, no empate, valor. Não
precisa de uma função de comparação composta. É a ideia do radix sort LSD:
ordene pela chave **menos** importante (valor) e depois, com um método
**estável**, pela mais importante (horário). A estabilidade do counting
sort preserva a ordem de valor dentro de cada segundo.

Vamos ver na prática. Os mesmos dados vão para dois vetores: um é ordenado
pelo `qsort`, o outro pelo radix. Os dois têm que terminar com os valores na
mesma ordem. Depois, o counting sort reorganiza o vetor do radix pelo
horário:

{{ideia}}

O programa mede o tempo de processador com `clock()`, de `<time.h>`: a
diferença entre duas chamadas, dividida por `CLOCKS_PER_SEC`, dá os
segundos gastos entre elas.

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

O radix ordenou o milhão de valores em bem menos tempo que o `qsort`
(nesta execução, menos de um terço), e o counting pelo horário levou menos
ainda. Sem o AddressSanitizer
e com `gcc -O2`, os números caem para uns 0,18 s, 0,03 s e 0,01 s: a
proporção fica até maior. Os quatro primeiros do dia são todos de
00:00:00, e estão em ordem de valor: a primeira ordenação sobreviveu à
segunda.

Repara no fluxograma: a conferência entre os dois vetores vem antes do
segundo relatório. Comparar com uma implementação confiável (o `qsort`) é o
jeito mais simples de testar uma ordenação escrita à mão:

{{fluxograma}}

### Qual usar?

O resumo do módulo, com os algoritmos do módulo 13 de referência:

| Algoritmo | Custo | Memória extra | Estável | Quando usar |
| --- | --- | --- | --- | --- |
| shell sort | ~n^1,25 (Knuth: pior n^1,5) | O(1) | não | vetores médios, pouca memória, código curto |
| counting sort | O(n + k) | O(n + k) | sim | chaves inteiras num intervalo pequeno |
| radix sort | O(d · (n + b)) | O(n + b) | sim | inteiros ou strings de tamanho fixo |
| bucket sort | O(n) médio, O(n²) pior | O(n) | sim (inserindo depois dos iguais) | valores reais bem espalhados num intervalo conhecido |
| quickselect | O(n) médio, O(n²) pior | O(1) | não | o k-ésimo, a mediana, os k maiores, sem ordenar |
| qsort | O(n log n) | depende da biblioteca | não garantido | qualquer tipo, qualquer critério |

> [!WARNING]
> Ordenação linear não é mágica: ela troca a comparação por **suposições
> sobre os dados**. O counting sort pelo horário só funciona porque o
> horário vai de 0 a 86399; se um registro chegar com `segundo = 86400` (um
> bug na origem dos dados), `c[86400]` escreve fora do vetor. Antes de usar
> o valor como índice, confira a faixa, ou confie numa fonte que garanta.
> E o radix deste TAD supõe `centavos` positivo: um estorno negativo
> sairia no fim da lista (o exercício E726 mostra o conserto).

> [!TIP]
> **Por dentro do C:** cada passada do radix lê o vetor inteiro em
> sequência, do fim para o começo, e escreve espalhado em 256 regiões do
> auxiliar. 12 MB não cabem no cache, mas a leitura sequencial é a que o
> processador mais gosta: ele adivinha os próximos endereços e busca antes.
> Já o `qsort` não sabe nada sobre o `Pix`: move cada registro como um
> bloco genérico de 12 bytes (só conhece o tamanho) e chama
> `pix_compara_valor` por ponteiro, sem poder colocar o código dela no
> lugar da chamada. Saber o tipo e a
> faixa da chave é a vantagem que as ordenações lineares exploram.

> [!NOTE]
> **Pergunta para você:** o radix fez 4 passadas, mas nenhum Pix passa de
> R$ 9999,99 (999999 centavos, menos que 2²⁰). Quantas passadas seriam
> realmente necessárias? O byte 3 de todos os valores é zero: o que a
> quarta passada faz com o vetor?

{{pratique}}
