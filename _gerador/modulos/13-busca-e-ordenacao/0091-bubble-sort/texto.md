## 0091 · Bubble sort

No app de delivery, cinco restaurantes prometem entregar em 42, 17, 35, 8 e
23 minutos. Você quer a lista do mais rápido para o mais lento. Para usar a
busca binária do assunto anterior, ou só para mostrar bonito, o vetor precisa
estar **ordenado**. Como ordenar?

O **bubble sort** (ordenação por bolha) é o algoritmo mais simples de
explicar: percorra o vetor comparando **vizinhos**, `v[j]` com `v[j + 1]`. Se
o da esquerda for maior, troque os dois. Isso é uma **passada**.

Repara no que uma passada faz com o maior elemento: ele ganha todas as
comparações e vai sendo carregado para a direita, troca após troca, até a
última gaveta. Ele "borbulha" até o fim (ou afunda, depende do seu ponto de
vista). Depois da passada 1, o maior está no lugar certo. Depois da passada 2,
o segundo maior também. Daí vêm duas regras:

- **n - 1 passadas bastam**: com os `n - 1` maiores no lugar, o que sobra só
  pode ser o menor, já na frente.
- a passada `k` não precisa olhar as últimas `k - 1` gavetas: elas já estão
  prontas. O laço interno vai até `j < n - passada`.

E uma terceira, a **bandeira** (`bool trocou`): se uma passada inteira não
trocou ninguém, todos os vizinhos estão em ordem, então o vetor está
ordenado. Pode parar.

Custo: no pior caso (vetor ao contrário), `(n - 1) + (n - 2) + ... + 1 =
n(n - 1)/2` comparações, e todas viram trocas. É **O(n²)**. Com a bandeira, o
melhor caso (vetor já em ordem) cai para uma passada só: `n - 1` comparações,
**O(n)**.

Vamos ver na prática. Na passada 1 o 42 ganha de todo mundo e afunda até o
fim (verde). Na passada 2 o 35 encontra o seu lugar. Na 3, o 8 chega à frente.
A passada 4 não troca nada, e a bandeira encerra:

{{ideia}}

O mesmo exemplo em C, contando comparações e trocas:

```c
#include <stdio.h>
#include <stdbool.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void bubble_sort(int v[], int n) {
    int comparacoes = 0, trocas = 0;
    for (int passada = 1; passada < n; passada++) {
        bool trocou = false;
        // os últimos passada-1 já estão no lugar: nem olha
        for (int j = 0; j < n - passada; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {      // vizinhos fora de ordem: troca
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocas++;
                trocou = true;
            }
        }
        printf("passada %d:", passada);
        mostra(v, n);
        if (!trocou) {
            break;                      // nenhuma troca: já está ordenado
        }
    }
    printf("%d comparações, %d trocas\n", comparacoes, trocas);
}

int main(void) {
    int minutos[] = {42, 17, 35, 8, 23};
    int n = 5;

    printf("início:   ");
    mostra(minutos, n);
    bubble_sort(minutos, n);
    return 0;
}
// Saída:
// início:    42 17 35  8 23
// passada 1: 17 35  8 23 42
// passada 2: 17  8 23 35 42
// passada 3:  8 17 23 35 42
// passada 4:  8 17 23 35 42
// 10 comparações, 7 trocas
```

### Passo a passo

A passada 1 por dentro. Cada linha é uma comparação de vizinhos; em negrito, o
par comparado:

| j | antes | `v[j] > v[j+1]`? | depois |
| --- | --- | --- | --- |
| 0 | **42 17** 35 8 23 | sim, troca | 17 42 35 8 23 |
| 1 | 17 **42 35** 8 23 | sim, troca | 17 35 42 8 23 |
| 2 | 17 35 **42 8** 23 | sim, troca | 17 35 8 42 23 |
| 3 | 17 35 8 **42 23** | sim, troca | 17 35 8 23 42 |

Somando as quatro passadas: 4 + 3 + 2 + 1 = **10 comparações** e
4 + 2 + 1 + 0 = **7 trocas**. Esse 7 não é acaso: é o número de **inversões**
do vetor original, os pares que estão na ordem errada (42 com 17, 42 com 35,
42 com 8, 42 com 23, 17 com 8, 35 com 8 e 35 com 23). Cada troca de vizinhos
desfaz exatamente uma inversão.

Repara no fluxograma: são dois laços. O de dentro (`j`) faz uma passada; o de
fora repete passadas enquanto a bandeira disser que houve troca:

{{fluxograma}}

> [!WARNING]
> Troca sem variável auxiliar não troca nada: `v[j] = v[j + 1]; v[j + 1] =
> v[j];` deixa os dois com o mesmo valor, porque o primeiro valor foi apagado
> na primeira linha. E cuidado com o limite do laço interno: com
> `j < n`, a última volta lê `v[n]`, uma gaveta depois do fim. O
> AddressSanitizer pega; o C sozinho, não.

> [!TIP]
> **Por dentro do C:** cada troca são **três** escritas na memória (`aux`,
> `v[j]`, `v[j + 1]`), e o bubble faz uma troca por inversão. Num vetor
> aleatório, metade dos pares está invertida: são cerca de `n²/4` trocas, ou
> `3n²/4` escritas. Com 100 mil elementos, isso dá uns 7,5 bilhões de
> escritas. É por isso que o bubble sort quase nunca aparece em código de
> verdade. Ele vale como primeira ordenação: mostra a ideia de inversão, de
> passada e de "a parte do fim já está pronta", que voltam em todos os outros.

> [!NOTE]
> **Pergunta para você:** quantas passadas o bubble com bandeira faz no vetor
> `8 17 23 35 42`, que já está ordenado? E em `17 23 35 42 8`, com o menor lá
> no fim? Faça a previsão e teste no A181.

{{pratique}}
