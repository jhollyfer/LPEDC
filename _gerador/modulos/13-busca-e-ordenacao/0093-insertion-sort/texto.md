## 0093 · Insertion sort

Numa rodada de buraco, você recebe as cartas uma a uma: 7, 4, 9, 2, 5. Ninguém
espera a mão inteira para arrumar. Cada carta nova é **encaixada** no lugar
certo entre as que você já segura, que já estão em ordem. O 4 vai antes do 7;
o 9 fica no fim; o 2 atravessa a mão até a ponta esquerda.

Esse é o **insertion sort** (ordenação por inserção): cada elemento novo é
inserido no lugar certo de uma parte que já está ordenada (CORMEN et al.,
2024, cap. 2). Como no selection sort do 0092, o vetor tem uma parte pronta à
esquerda, `v[0..j-1]`. A diferença está no que "pronta" quer dizer. No
selection, a parte pronta já tem os menores do vetor inteiro, no lugar final.
Aqui ela está só **em ordem entre si**: um valor que ainda não chegou pode
precisar entrar no meio dela (FEOFILOFF, 2009).

Cada passo encaixa `v[j]` na parte pronta. Você guarda o valor em `x`. Depois
anda para a esquerda a partir de `j - 1` e, enquanto o elemento olhado for
**maior** que `x`, empurra esse elemento uma casa para a direita. Esse
movimento é um **deslocamento**: uma única escrita, e não uma troca de dois
valores. Quando você acha um elemento menor ou igual a `x`, ou chega ao começo
do vetor, a gaveta logo à direita dele, `v[i + 1]`, ficou livre, e `x` entra
ali (FEOFILOFF, 2009).

```c
int x = v[j];
int i = j - 1;
while (i >= 0 && v[i] > x) {
    v[i + 1] = v[i]; // desloca uma casa para a direita
    i--;
}
v[i + 1] = x;
```

Guardar `x` antes do laço é obrigatório. O primeiro deslocamento escreve em
`v[j]`, a gaveta onde `x` estava, e sem a cópia o valor se perderia.

O custo depende de quão bagunçado o vetor está. Cada deslocamento desfaz uma
**inversão** (o par fora de ordem do 0091), como a troca do bubble sort, mas
com uma escrita em vez das três de uma troca. No pior caso, com o vetor ao
contrário, cada elemento atravessa toda a parte pronta, e o total é
`n(n - 1)/2` comparações: **O(n²)**. No melhor caso, com o vetor já ordenado,
cada elemento compara uma vez e fica onde está: `n - 1` comparações, **O(n)**
(CORMEN et al., 2024, cap. 2). Por isso o insertion sort é o melhor dos três
métodos simples, e bibliotecas de ordenação o usam para pedaços pequenos, de
16 a 32 posições, dentro de métodos mais rápidos.

Duas propriedades fecham o retrato. O insertion sort é **estável** (a
definição está no 0092): o laço para no primeiro elemento que **não** é maior
que `x`, ou seja, para num igual, e `x` entra depois dele, mantendo a ordem de
chegada. E ele é **online**: consegue ordenar à medida que os dados chegam,
sem conhecer a entrada inteira, como a mão de cartas que você arruma a cada
compra (FEOFILOFF, 2009).

> [!WARNING]
> Escreva `while (i >= 0 && v[i] > x)`. Na ordem inversa, com `i = -1` o
> programa lê `v[-1]`. O curto-circuito do `&&` (0013) protege o vetor.

{{exemplo}}

Numa rodada de buraco, as cartas chegam uma a uma: 7, 4, 9, 2, 5. Cada linha é
uma carta nova: verde é a mão arrumada, amarela é a carta que entrou. O 9 não
anda; o 2 atravessa a mão inteira:

{{ideia}}

A função `maior` só conta as comparações:

```c
#include <stdio.h>
#include <stdbool.h>

static int comparacoes = 0;

// a > b, contando a comparação
bool maior(int a, int b) {
    comparacoes++;
    return a > b;
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void insertion_sort(int v[], int n) {
    int deslocamentos = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];                   // a carta que vai ser encaixada
        int i = j - 1;
        while (i >= 0 && maior(v[i], x)) {
            v[i + 1] = v[i];            // abre espaço: empurra para a direita
            deslocamentos++;
            i--;
        }
        v[i + 1] = x;                   // encaixa no buraco
        printf("j = %d (x = %d):", j, x);
        mostra(v, n);
    }
    printf("%d comparações, %d deslocamentos\n", comparacoes, deslocamentos);
}

int main(void) {
    int mao[] = {7, 4, 9, 2, 5};
    int n = 5;

    printf("início:       ");
    mostra(mao, n);
    insertion_sort(mao, n);
    return 0;
}
// Saída:
// início:         7  4  9  2  5
// j = 1 (x = 4):  4  7  9  2  5
// j = 2 (x = 9):  4  7  9  2  5
// j = 3 (x = 2):  2  4  7  9  5
// j = 4 (x = 5):  2  4  5  7  9
// 8 comparações, 6 deslocamentos
```

### Passo a passo

O encaixe do 2 (`j = 3`), o mais caro. A mão antes é `4 7 9 | 2 5`:

| i | v[i] | `v[i] > 2`? | o que acontece | vetor |
| --- | --- | --- | --- | --- |
| 2 | 9 | sim | `v[3] = 9` | 4 7 9 9 5 |
| 1 | 7 | sim | `v[2] = 7` | 4 7 7 9 5 |
| 0 | 4 | sim | `v[1] = 4` | 4 4 7 9 5 |
| -1 | | (`i >= 0` falso: nem compara) | `v[0] = 2` | 2 4 7 9 5 |

Somando todos os encaixes: 1 + 1 + 3 + 3 = **8 comparações** e
1 + 0 + 3 + 2 = **6 deslocamentos**.

O laço de dentro para por dois motivos: acabou o vetor ou achou alguém que
não é maior:

{{fluxograma}}
