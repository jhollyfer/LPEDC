## 0091 · Bubble sort

No app de delivery, cinco restaurantes prometem entregar em 42, 17, 35, 8 e 23
minutos. Para mostrar do mais rápido ao mais lento, o vetor precisa estar
**ordenado**. Ordenar também é o que libera a busca binária do 0090, que só
funciona em vetor ordenado. O módulo apresenta vários métodos de ordenação, e
este é o mais simples de entender.

Imagine cinco pessoas numa fila, que devem ficar da mais baixa para a mais
alta, e só podem trocar de lugar com quem está do lado. Você anda pela fila
comparando cada par de vizinhos e, se o da esquerda for mais alto, troca os
dois. O **bubble sort** (ordenação por bolha) faz exatamente isso: compara
`v[j]` com `v[j + 1]` e troca os dois se o da esquerda for maior. Cada
varredura do começo ao fim do vetor se chama **passada** (CELES; RANGEL,
2002). O nome vem da imagem dos valores grandes subindo como bolhas, ou, no
desenho com o vetor na horizontal, indo parar no fim.

O que torna o método correto é o que acontece com o maior elemento. Assim que
a passada o encontra, ele vence toda comparação e é carregado troca a troca
até a última gaveta livre. Depois da primeira passada, o maior está no lugar
final; depois da segunda, o segundo maior também, e assim por diante (DEITEL;
DEITEL, 2011, cap. 6). Daí saem duas regras. Bastam `n - 1` passadas, porque
com os `n - 1` maiores no lugar o que sobra só pode ser o menor, já na frente.
E a passada `k` não precisa olhar as últimas `k - 1` gavetas, que já estão
prontas: o laço interno vai até `j < n - passada`.

Uma terceira regra vem de uma variável `bool`, a **bandeira** `trocou`. Ela
começa cada passada valendo `false` e vira `true` a cada troca. Se uma passada
inteira termina sem nenhuma troca, todo vizinho já está em ordem, então o
vetor está ordenado e o laço pode parar antes das `n - 1` passadas (CELES;
RANGEL, 2002).

No pior caso, com o vetor ao contrário, a primeira passada compara `n - 1`
pares, a segunda `n - 2`, até a última com 1. A soma dá `n(n - 1)/2`
comparações, e todas viram trocas: o custo é **O(n²)**. No melhor caso, com o
vetor já em ordem e a bandeira ligada, uma passada de `n - 1` comparações
basta: **O(n)** (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).

Uma forma de medir a bagunça de um vetor é contar **inversões**: pares de
posições `i < j` com `v[i] > v[j]`, ou seja, dois valores na ordem errada. Em
`42 17 35`, os pares (42, 17) e (42, 35) são inversões. Cada troca de vizinhos
desfaz exatamente uma inversão, e um vetor aleatório tem cerca de `n²/4`
delas (CORMEN et al., 2024, cap. 2). Por isso o bubble sort serve para
aprender a ideia, mas não para código real: os métodos dos próximos assuntos
desfazem as mesmas inversões gastando menos.

> [!WARNING]
> `v[j] = v[j + 1]; v[j + 1] = v[j];` não troca nada: os dois ficam iguais.
> Use uma variável auxiliar. Com `j < n` no laço interno, a última volta lê
> `v[n]`, fora do vetor.

{{exemplo}}

Cinco restaurantes prometem entregar em 42, 17, 35, 8 e 23 minutos. Na
passada 1 o 42 afunda até o fim; na 2, o 35 acha o seu lugar; na 3, o 8 chega
à frente. A passada 4 não troca nada e a bandeira encerra:

{{ideia}}

O código conta comparações e trocas:

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

A passada 1 por dentro; em negrito, o par comparado:

| j | antes | `v[j] > v[j+1]`? | depois |
| --- | --- | --- | --- |
| 0 | **42 17** 35 8 23 | sim, troca | 17 42 35 8 23 |
| 1 | 17 **42 35** 8 23 | sim, troca | 17 35 42 8 23 |
| 2 | 17 35 **42 8** 23 | sim, troca | 17 35 8 42 23 |
| 3 | 17 35 8 **42 23** | sim, troca | 17 35 8 23 42 |

Nas quatro passadas: 4 + 3 + 2 + 1 = **10 comparações** e 4 + 2 + 1 + 0 =
**7 trocas**, o número de inversões do vetor original.

O laço de dentro (`j`) faz uma passada; o de fora repete enquanto a bandeira
indicar troca:

{{fluxograma}}
