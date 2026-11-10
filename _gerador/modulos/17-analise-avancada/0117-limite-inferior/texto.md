## 0117 · Limite inferior da ordenação

Nos Correios chegaram três encomendas, A, B e C, e a única ferramenta é uma
balança de dois pratos, que só diz qual lado pesa mais. Quantas pesagens são
necessárias, no pior caso, com o **melhor** método possível?

Até aqui, a análise media **um algoritmo**. Agora a pergunta é sobre o
**problema**: existe jeito de ordenar com menos? A resposta vale para todo
algoritmo que só **compara** dois elementos, como a balança: a **ordenação
por comparação** (módulo 13, heapsort, `qsort`).

A ferramenta é a **árvore de decisão**: cada nó interno é uma pergunta ("A é
mais pesada que B?"), cada aresta é uma resposta e cada folha é a ordem final.
Rodar o algoritmo é descer da raiz a uma folha; o pior caso é a **altura**.

1. Com 3 encomendas há `3! = 6` ordens, e cada uma precisa da sua folha: duas
   ordens diferentes na mesma folha receberiam a mesma resposta, e uma estaria
   errada.
2. Cada pergunta tem 2 respostas, então a árvore de altura `h` tem no máximo
   `2^h` folhas.
3. Logo `2^h ≥ 6`. Com `h = 2` cabem 4 folhas; precisa de `h ≥ 3`.

Nenhum método ordena 3 encomendas com menos de 3 pesagens. Para `n`
elementos, `2^h ≥ n!`, ou seja, **`h ≥ log₂(n!)`**.

O desenho é o insertion sort de 3 elementos como árvore de decisão. O
caminho verde, A = 5 kg, B = 9 kg e C = 2 kg, acaba na folha C A B:

{{ideia}}

O programa passa as 6 ordens pela balança; `mais_pesada` anota cada pergunta:

```c
#include <stdio.h>

typedef struct {
    char nome;
    int peso; // kg
} Encomenda;

int pesagens = 0;

// a balança de dois pratos: x é mais pesada que y? (anota a pergunta)
int mais_pesada(Encomenda x, Encomenda y) {
    pesagens++;
    int resposta = x.peso > y.peso;
    printf("%c>%c? %s  ", x.nome, y.nome, resposta ? "sim" : "não");
    return resposta;
}

// insertion sort de 3 encomendas, do mais leve ao mais pesado, só com a balança
void ordena3(Encomenda e[]) {
    for (int i = 1; i < 3; i++) {
        Encomenda atual = e[i];
        int j = i - 1;
        while (j >= 0 && mais_pesada(e[j], atual)) {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = atual;
    }
}

int main(void) {
    // as 3! = 6 maneiras de os pesos 2, 5 e 9 kg chegarem como A, B e C
    int chegada[6][3] = {{2, 5, 9}, {2, 9, 5}, {5, 2, 9}, {5, 9, 2}, {9, 2, 5}, {9, 5, 2}};
    int pior = 0;
    for (int k = 0; k < 6; k++) {
        Encomenda e[3] = {{'A', chegada[k][0]}, {'B', chegada[k][1]}, {'C', chegada[k][2]}};
        printf("%d %d %d | ", chegada[k][0], chegada[k][1], chegada[k][2]);
        pesagens = 0;
        ordena3(e);
        printf("%s-> %c %c %c (%d)\n", pesagens == 2 ? "          " : "",  // alinha
               e[0].nome, e[1].nome, e[2].nome, pesagens);
        if (pesagens > pior) {
            pior = pesagens;
        }
    }
    printf("pior caso: %d pesagens\n", pior);
    return 0;
}
// Saída:
// 2 5 9 | A>B? não  B>C? não            -> A B C (2)
// 2 9 5 | A>B? não  B>C? sim  A>C? não  -> A C B (3)
// 5 2 9 | A>B? sim  A>C? não            -> B A C (2)
// 5 9 2 | A>B? não  B>C? sim  A>C? sim  -> C A B (3)
// 9 2 5 | A>B? sim  A>C? sim  B>C? não  -> B C A (3)
// 9 5 2 | A>B? sim  A>C? sim  B>C? sim  -> C B A (3)
// pior caso: 3 pesagens
```

Cada linha é um caminho da raiz a uma folha, e as 6 folhas são diferentes. O
pior caso, 3, iguala o limite: para 3 elementos, o insertion sort é **ótimo**.

O fluxograma é o argumento inteiro, para qualquer método que só compara:

{{fluxograma}}

`log₂(n!)` cresce como `n log₂ n` (menos cerca de `1,44 n`). Contra o merge
sort:

| n | n! | limite ⌈log₂ n!⌉ | merge sort (pior caso) |
| --- | --- | --- | --- |
| 3 | 6 | 3 | 3 |
| 4 | 24 | 5 | 5 |
| 5 | 120 | 7 | 8 |
| 10 | 3.628.800 | 22 | 25 |
| 1000 | (2.568 dígitos) | 8.530 | 8.977 |

O limite se escreve com **Ω** (ômega), o piso, contrário do teto `O`: ordenar
por comparação é **Ω(n log n)** no pior caso. Merge sort e heapsort fazem
O(n log n): são **assintoticamente ótimos**.

> [!WARNING]
> O limite vale para o **pior caso** de **qualquer** algoritmo que só compara.
> O insertion sort ordena um vetor já em ordem com `n - 1` comparações. Quem
> não compara escapa: o counting sort (módulo 18) usa o valor como **índice** e
> ordena inteiros pequenos em O(n). O **maior** de `n` elementos
> precisa só de `n - 1` comparações.

> [!TIP]
> **Por dentro do C:** o `qsort` recebe o vetor como `void *` e uma `compara`,
> e só sabe da ordem pelas respostas dela. Logo nenhuma implementação faz menos
> de `⌈log₂ n!⌉` chamadas à `compara` no pior caso: para `n = 1000`, alguma
> entrada passa de 8.530.

> [!NOTE]
> **Pergunta para você:** com 4 encomendas, quantas pesagens são o mínimo no
> pior caso? E o insertion sort de 4 elementos faz quantas? Ainda é ótimo?

{{pratique}}
