## 0117 · Limite inferior da ordenação

- **Limite inferior**: uma afirmação sobre o **problema**, não sobre um
  algoritmo. Diz que nenhum método resolve com menos que tanto
  (SZWARCFITER; MARKENZON, 2010).
- **Ordenação por comparação**: só aprende a ordem perguntando "x > y?". Vale
  para o módulo 13, o heapsort e o `qsort`, que só conhece a ordem pelas
  respostas da `compara` (CORMEN et al., 2024, cap. 8).
- **Árvore de decisão**: cada nó interno é uma pergunta, cada aresta uma
  resposta e cada folha uma ordem final. O pior caso é a **altura**
  (CORMEN et al., 2024, cap. 8).
- **O argumento**: há `n!` ordens e cada uma precisa da sua folha. Com 2
  respostas por pergunta, altura `h` dá no máximo `2^h` folhas. Logo
  `2^h ≥ n!`, isto é, **`h ≥ log₂(n!)`** (LINTZMAYER; MOTA, 2023).
- **Ω(n log n)**: `log₂(n!)` cresce como `n log₂ n`. O **Ω** (ômega) é o piso,
  o contrário do teto `O` (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).
- **Assintoticamente ótimo**: merge sort e heapsort fazem O(n log n) e
  alcançam o limite (CORMEN et al., 2024, cap. 8).

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
