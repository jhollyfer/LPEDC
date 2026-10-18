## 0117 · Limite inferior da ordenação

Na agência dos Correios chegaram três encomendas, A, B e C, e a única
ferramenta é uma balança de dois pratos. Ela não mostra quilos: só diz qual
lado é mais pesado. Você quer enfileirar as três da mais leve para a mais
pesada. Quantas pesagens são necessárias, no pior caso, com o **melhor**
método possível?

Até aqui, toda análise media **um algoritmo**: o merge sort faz tantas
comparações, o insertion sort faz tantas. A pergunta agora é sobre o
**problema**: existe algum jeito de ordenar com menos? Responder isso para
todos os algoritmos de uma vez, inclusive os que ninguém inventou ainda,
parece impossível. Não é, desde que eles só aprendam sobre os dados
**comparando** dois elementos, como a balança. Esses são os algoritmos de
**ordenação por comparação**: todos os do módulo 13, o heapsort e o `qsort`.

A ferramenta é a **árvore de decisão**. Cada nó interno é uma pergunta
("A é mais pesada que B?"), cada aresta é uma resposta (sim ou não), e cada
folha é uma resposta final: a ordem das encomendas. Rodar o algoritmo numa
entrada é descer da raiz até uma folha. O número de comparações no pior caso
é a **altura** da árvore.

Agora o argumento, em três passos:

1. Com 3 encomendas há `3! = 6` ordens possíveis, e cada uma precisa ter a
   sua folha: se duas entradas com ordens diferentes chegassem à mesma
   folha, o algoritmo daria a mesma resposta para as duas e erraria uma.
2. Cada pergunta tem 2 respostas, então uma árvore de altura `h` tem no
   máximo `2^h` folhas.
3. Logo `2^h ≥ 6`. Com `h = 2`, só cabem 4 folhas. Precisa de `h ≥ 3`.

Nenhum método, por mais esperto, ordena 3 encomendas com menos de 3
pesagens no pior caso. Para `n` elementos, o mesmo raciocínio dá
`2^h ≥ n!`, ou seja, **`h ≥ log₂(n!)`**.

Vamos ver na prática. Este é o insertion sort de 3 elementos desenhado como
árvore de decisão. O caminho em verde é o da entrada A = 5 kg, B = 9 kg e
C = 2 kg, que termina na folha C A B depois de 3 pesagens:

{{ideia}}

O programa passa as 6 ordens possíveis pela balança. A função
`mais_pesada` é a única forma de o algoritmo olhar os pesos, e ela anota
cada pergunta:

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

Cada linha da saída é um caminho da raiz até uma folha, e as 6 folhas são
diferentes. Duas entradas têm sorte e param com 2 pesagens, mas o pior caso
é 3: exatamente o limite. Para 3 elementos, o insertion sort é **ótimo**.

Repara no fluxograma: é o argumento inteiro, sem nenhum algoritmo
específico. Ele vale para qualquer método que só compara:

{{fluxograma}}

E para `n` grande? `log₂(n!)` cresce como `n log₂ n` (um pouco menos: a
diferença é perto de `1,44 n`). A tabela compara o limite com o pior caso do
merge sort:

| n | n! | limite ⌈log₂ n!⌉ | merge sort (pior caso) |
| --- | --- | --- | --- |
| 3 | 6 | 3 | 3 |
| 4 | 24 | 5 | 5 |
| 5 | 120 | 7 | 8 |
| 10 | 3.628.800 | 22 | 25 |
| 1000 | (2.568 dígitos) | 8.530 | 8.977 |

O limite inferior se escreve com **Ω** (ômega): ordenar por comparação é
**Ω(n log n)** no pior caso. É o piso, o contrário do teto `O`. Como o merge
sort e o heapsort fazem O(n log n), eles encostam no piso: são
**assintoticamente ótimos**. Ninguém vai inventar uma ordenação por
comparação O(n) ou O(n log log n). O que dá para ganhar é constante.

> [!WARNING]
> O limite fala do **pior caso** de **qualquer** algoritmo que só compara.
> Ele não diz que toda entrada custa `n log n`: o insertion sort ordena um
> vetor que já está em ordem com `n - 1` comparações. E não vale para quem
> não compara: o counting sort do módulo 18 usa o valor como **índice** de
> um vetor e ordena inteiros pequenos em O(n), sem contradição nenhuma. Ele
> também não vale para outros problemas: achar o **maior** de `n` elementos
> precisa só de `n - 1` comparações, e não de `n log n`.

> [!TIP]
> **Por dentro do C:** o `qsort` da biblioteca é o modelo de comparação em
> pessoa. Ele recebe o vetor como `void *` e uma função `compara`, e nunca
> olha os bytes dos elementos por conta própria: tudo o que ele sabe sobre a
> ordem vem das respostas da sua função, uma de cada vez. Por isso nenhuma
> implementação de `qsort`, em nenhuma biblioteca, consegue fazer menos de
> `⌈log₂ n!⌉` chamadas à `compara` no pior caso. Ponha um contador dentro da
> sua função e confira: para `n = 1000`, ele passa de 8.530.

> [!NOTE]
> **Pergunta para você:** com 4 encomendas, quantas pesagens são o mínimo
> no pior caso? E o insertion sort de 4 elementos, quantas faz no pior caso?
> Ele ainda é ótimo?

{{pratique}}
