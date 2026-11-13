## 0117 · Limite inferior da ordenação

Até aqui, toda análise media **um algoritmo**: o merge sort faz Θ(n log n), o
insertion sort faz Θ(n²). Agora a pergunta muda de lado e passa a ser sobre o
**problema**. Existe algum jeito de ordenar com menos trabalho do que o merge
sort, ou ele já é o melhor possível? Para responder, você precisa de um
argumento que valha para todo algoritmo, inclusive os que ninguém inventou
ainda.

Esse tipo de resposta se chama **limite inferior**: uma afirmação de que
nenhum método resolve o problema gastando menos do que certa quantidade
(SZWARCFITER; MARKENZON, 2010). Um limite superior se prova mostrando um
algoritmo. Um limite inferior exige mostrar que todos os algoritmos possíveis
gastam pelo menos aquilo.

O argumento precisa de uma regra do jogo. Imagine três encomendas nos
Correios e uma balança de dois pratos, que só diz qual lado pesa mais. Você
não pode ler o peso; só pode comparar duas encomendas por vez. Os algoritmos
que funcionam assim formam a **ordenação por comparação**: eles só aprendem a
ordem dos elementos perguntando "x é maior que y?" (CORMEN et al., 2024,
cap. 8). Todos os do módulo 13 são assim, o heapsort também, e o `qsort` da
biblioteca idem: ele recebe o vetor como `void *` e só fica sabendo da ordem
pelas respostas da função `compara`.

Para enxergar todas as execuções de um algoritmo desses de uma vez, use a
**árvore de decisão**. Cada nó interno é uma pergunta, como "A pesa mais que
B?". Cada aresta é uma resposta, sim ou não. Cada folha é uma ordem final dos
elementos. Rodar o algoritmo numa entrada é descer da raiz até uma folha,
seguindo as respostas. O número de perguntas no pior caso é o caminho mais
longo da raiz até uma folha, a **altura** da árvore (CORMEN et al., 2024,
cap. 8).

Agora o argumento, em três passos. Com `n` elementos distintos, há `n!`
ordens possíveis, e cada uma precisa de uma folha só dela: se duas ordens
diferentes caíssem na mesma folha, o algoritmo daria a mesma resposta para as
duas, e uma delas sairia errada. Cada pergunta tem 2 respostas, então uma
árvore de altura `h` tem no máximo `2^h` folhas. Juntando, `2^h ≥ n!`, isto é,
**`h ≥ log₂(n!)`** (LINTZMAYER; MOTA, 2023). Com 3 encomendas há `3! = 6`
ordens; altura 2 só comporta 4 folhas, então nenhum método garante a ordem com
menos de 3 pesagens.

Falta ver quanto vale `log₂(n!)`. O fatorial é o produto de `n` números, e
metade deles é pelo menos `n/2`. Por isso `n!` passa de `(n/2)^(n/2)`, e
`log₂(n!)` cresce no mesmo ritmo de `n log₂ n`. Toda ordenação por comparação
faz **Ω(n log n)** comparações no pior caso. O **Ω** (ômega) é o piso, o
oposto do teto `O`: diz que o custo não fica abaixo daquele ritmo (TENENBAUM;
LANGSAM; AUGENSTEIN, 1995, cap. 6). Para `n = 1000`, alguma entrada obriga
qualquer implementação do `qsort` a chamar a `compara` mais de 8.530 vezes.

O merge sort e o heapsort fazem O(n log n) comparações no pior caso e
encostam nesse piso. Algoritmos assim se chamam **assintoticamente ótimos**:
fora constantes, ninguém que só compara faz melhor (CORMEN et al., 2024,
cap. 8). A tabela compara o limite com o que o merge sort gasta:

| n | n! | limite ⌈log₂ n!⌉ | merge sort (pior caso) |
| --- | --- | --- | --- |
| 3 | 6 | 3 | 3 |
| 4 | 24 | 5 | 5 |
| 5 | 120 | 7 | 8 |
| 10 | 3.628.800 | 22 | 25 |
| 1000 | (2.568 dígitos) | 8.530 | 8.977 |

> [!WARNING]
> O limite vale para o **pior caso** de **qualquer** algoritmo que só compara.
> O insertion sort ordena um vetor já em ordem com `n - 1` comparações, e o
> counting sort (módulo 18) usa o valor como **índice** e escapa do limite.

{{exemplo}}

Nos Correios, três encomendas e uma balança de dois pratos. Há `3! = 6`
ordens e altura 2 só dá 4 folhas: são precisas 3 pesagens. O desenho é o
insertion sort de 3 elementos; o caminho verde (A = 5, B = 9, C = 2 kg) acaba
na folha C A B:

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

Cada linha é um caminho da raiz a uma folha, e o pior caso, 3, iguala o
limite: para 3 elementos, o insertion sort é **ótimo**. O fluxograma é o
argumento inteiro, para qualquer método que só compara:

{{fluxograma}}
