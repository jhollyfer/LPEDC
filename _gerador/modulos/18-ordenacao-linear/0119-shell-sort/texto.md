## 0119 · Shell sort

O insertion sort do assunto 0093 tem um defeito de locomoção: cada elemento
anda **uma casa por movimento**. Um elemento pequeno que está no fim do vetor
precisa de um empurrão para cada casa até chegar à frente. Num vetor invertido,
a conta chega a n²/2 movimentos. Pense no motorista de uma van que recebe 10
pacotes fora da ordem da rota: se o pacote que deve sair primeiro está na
quinta posição, ele leva quatro empurrões para chegar ao lugar.

Em 1959, Donald Shell propôs deixar os elementos andarem **de h em h** casas.
O **shell sort** repete o insertion sort várias vezes, com **saltos** `h`
cada vez menores. Num salto grande, um elemento atravessa o vetor em poucos
movimentos e já fica perto do lugar certo (SHELL, 1959).

O que cada rodada produz tem nome. Depois da rodada com salto `h`, o vetor
está **h-ordenado**: se você pegar um elemento a cada `h` casas, começando de
qualquer posição, a fileira que sai está em ordem. Com `n = 10` e `h = 4`, as
fileiras são as posições 0, 4, 8; depois 1, 5, 9; depois 2, 6; e 3, 7. A
rodada com `h = 4` é, portanto, quatro insertion sorts pequenos entrelaçados
no mesmo vetor, um por fileira (KNUTH, 1998).

A rodada final usa sempre `h = 1`, que é o insertion sort comum. A diferença
é que ela recebe um vetor **quase ordenado**, em que cada elemento está a
poucas casas do seu lugar. Nesse caso o insertion sort faz poucos movimentos e
fica rápido (ZIVIANI, 2010, cap. 4). As rodadas anteriores existem para
preparar esse vetor.

Falta decidir quais saltos usar. A escolha mais ensinada é a sequência de
**Knuth**, em que cada salto é `h = 3h + 1` do anterior: 1, 4, 13, 40, 121,
364, e assim por diante. O código gera a sequência enquanto `h` fica abaixo de
`n / 3` e usa o último valor gerado como primeiro salto; depois divide por 3 a
cada rodada até chegar em 1 (SEDGEWICK, 1998, cap. 6). Com `n = 10`, `n / 3`
é 3 na divisão inteira, o 1 vira 4, o 4 já não é menor que 3, e os saltos são
4 e 1.

A sequência muda o custo. Com os saltos de Knuth, o pior caso é O(n^1,5),
bem abaixo do n² do insertion sort. Com os saltos que o próprio Shell propôs,
`n/2, n/4, ..., 1`, o pior caso continua O(n²). O motivo: quando `n` é
potência de 2, todos esses saltos são pares até o último, então os elementos
das posições pares e os das ímpares nunca se comparam antes da rodada final,
e ela pode ter de fazer quase todo o trabalho (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).

Quanto à memória, o shell sort ordena **no lugar**: troca elementos dentro do
próprio vetor e não precisa de vetor extra. Mas ele não é **estável**. Uma
ordenação estável mantém, entre elementos de chave igual, a ordem em que eles
vieram na entrada. No shell sort, dois elementos iguais podem cair em fileiras
diferentes numa rodada com salto grande, e um pode pular por cima do outro
(ZIVIANI, 2010, cap. 4).

> [!WARNING]
> A última rodada **tem** que ser com `h = 1`; sem ela o vetor termina fora de
> ordem e sem erro. No laço de dentro, use `j >= h`, não `j > 0`, senão
> `v[j - h]` lê antes do vetor.

{{exemplo}}

O motorista da van recebe 10 pacotes fora da ordem de rota. Com `n = 10`, os
saltos são 4 e 1; cada cor do desenho é uma fileira de salto 4:

{{ideia}}

```c
#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

// insertion sort com saltos: os saltos seguem a sequência de Knuth
void shell_sort(int v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;                  // 1, 4, 13, 40, 121...
    }
    for (; h >= 1; h /= 3) {            // ..., 121, 40, 13, 4, 1
        int movimentos = 0;
        // insertion sort entre elementos que estão a h casas de distância
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];        // empurra h casas para a direita
                j -= h;
                movimentos++;
            }
            v[j] = x;
        }
        printf("h = %d:", h);
        mostra(v, n);
        printf("  (%d movimentos)\n", movimentos);
    }
}

int main(void) {
    int rotas[] = {62, 17, 85, 40, 9, 73, 28, 51, 94, 33};
    int n = 10;

    printf("início:");
    mostra(rotas, n);
    printf("\n");
    shell_sort(rotas, n);
    return 0;
}
// Saída:
// início: 62 17 85 40 9 73 28 51 94 33
// h = 4: 9 17 28 40 62 33 85 51 94 73  (3 movimentos)
// h = 1: 9 17 28 33 40 51 62 73 85 94  (6 movimentos)
```

São 9 movimentos; o insertion sort comum faria 21. O `h /= 3` desfaz o
`3 * h + 1` e o laço para quando `h` vira 0:

{{fluxograma}}

### Passo a passo

A rodada com `h = 4`; cada `v[i]` se compara só com quem está 4, 8, ... casas
para trás:

| i | x | compara com | ação | vetor depois |
| --- | --- | --- | --- | --- |
| 4 | 9 | v[0] = 62 | 62 pula para v[4]; 9 vai para v[0] | 9 17 85 40 62 73 28 51 94 33 |
| 5 | 73 | v[1] = 17 | nada | 9 17 85 40 62 73 28 51 94 33 |
| 6 | 28 | v[2] = 85 | 85 pula para v[6]; 28 vai para v[2] | 9 17 28 40 62 73 85 51 94 33 |
| 7 | 51 | v[3] = 40 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 8 | 94 | v[4] = 62 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 9 | 33 | v[5] = 73, depois v[1] = 17 | 73 pula para v[9]; 33 vai para v[5] | 9 17 28 40 62 33 85 51 94 73 |
