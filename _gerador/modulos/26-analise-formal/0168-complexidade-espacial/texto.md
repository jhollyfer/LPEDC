## 0168 · Complexidade espacial

O motorista de entregas sai do centro de distribuição com a rota do dia: as
paradas 12, 7, 30, 5, 18 e 9, nessa ordem. Na volta, ele quer fazer o
caminho ao contrário. Dá para escrever a rota invertida numa folha nova,
de baixo para cima, e jogar a velha fora. Ou dá para riscar e trocar na
própria folha: a primeira com a última, a segunda com a penúltima... A
segunda opção não gasta papel. Com 6 paradas, tanto faz. Com 1 milhão, a
folha nova pesa 4 MB.

Até aqui, a análise contou **tempo** (passos). A **complexidade espacial**
conta **memória**: quantos bytes a função usa, em função de `n`, com as
mesmas notações O, Ω e Θ e as mesmas constantes `c` e `n₀`.

Quase sempre interessa o **espaço extra** (também chamado de espaço
**auxiliar**): o que a função usa **além da entrada**. A rota de `n` paradas
já existe antes da chamada; o que conta é o que a função pede a mais. Uma
função que usa um número fixo de variáveis simples tem espaço extra **Θ(1)**: é um algoritmo **in-place** (no lugar). Uma que faz uma cópia
da entrada tem espaço extra **Θ(n)**.

O espaço extra aparece em três lugares:

- **vetores e `malloc`**: um auxiliar de `n` posições é Θ(n), uma matriz
  `n × n` é Θ(n²);
- **a pilha de chamadas**: cada chamada recursiva ainda ativa ocupa um
  frame (assunto 0031). O espaço é a **profundidade máxima** vezes o tamanho
  do frame, mesmo que o total de chamadas seja muito maior;
- **tabelas para ganhar tempo**: memoização, vetor de contagem, tabela
  hash. É a troca clássica de **tempo por espaço**: pagar memória para não
  repetir trabalho.

| algoritmo | tempo | espaço extra |
| --- | --- | --- |
| inverter trocando as pontas | Θ(n) | Θ(1) |
| busca binária com laço | Θ(log n) | Θ(1) |
| busca binária recursiva | Θ(log n) | Θ(log n), da pilha |
| soma recursiva de `n` elementos | Θ(n) | Θ(n), da pilha |
| insertion sort, heapsort | Θ(n²), Θ(n log n) | Θ(1) |
| merge sort | Θ(n log n) | Θ(n), do vetor auxiliar |
| quick sort | Θ(n log n) em média | Θ(log n) em média, Θ(n) no pior, da pilha |
| counting sort com valores de 0 a k | Θ(n + k) | Θ(n + k) |

No desenho, em cima, está a rota invertida numa folha nova: 6 gavetas a
mais, `6 · 4 = 24` bytes. Embaixo, a mesma inversão no lugar: só a caixinha
`tmp`, 4 bytes, para qualquer tamanho de rota:

{{ideia}}

O programa faz as duas inversões e devolve quantos bytes extras cada uma
pediu. Depois repete com 1 milhão de paradas:

```c
#include <stdio.h>
#include <stdlib.h>

// inverte usando uma rota auxiliar do mesmo tamanho: Θ(n) de espaço extra
size_t inverte_copiando(int rota[], int n) {
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        aux[i] = rota[n - 1 - i];
    }
    for (int i = 0; i < n; i++) {
        rota[i] = aux[i];
    }
    free(aux);
    return n * sizeof(int);              // bytes extras que a função pediu
}

// inverte trocando as pontas: só uma variável extra, Θ(1) de espaço
size_t inverte_no_lugar(int rota[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int tmp = rota[i];
        rota[i] = rota[j];
        rota[j] = tmp;
    }
    return sizeof(int);                  // o tmp (i e j existem nas duas)
}

void mostra(const int rota[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", rota[i]);
    }
    printf("\n");
}

int main(void) {
    int rota[6] = {12, 7, 30, 5, 18, 9}; // paradas da entrega, na ida

    size_t b1 = inverte_copiando(rota, 6);
    printf("volta (copiando): ");
    mostra(rota, 6);
    size_t b2 = inverte_no_lugar(rota, 6);
    printf("ida (no lugar):   ");
    mostra(rota, 6);
    printf("bytes extras com 6 paradas: %zu e %zu\n", b1, b2);

    static int grande[1000000];
    printf("bytes extras com 1 milhão: %zu e %zu\n",
           inverte_copiando(grande, 1000000), inverte_no_lugar(grande, 1000000));
    return 0;
}
// Saída:
// volta (copiando): 9 18 5 30 7 12
// ida (no lugar):   12 7 30 5 18 9
// bytes extras com 6 paradas: 24 e 4
// bytes extras com 1 milhão: 4000000 e 4
```

O fluxograma segue a `inverte_no_lugar`, e nenhuma caixa dele cria memória.
O laço anda com duas marcas, `i` da esquerda e `j` da direita, e para quando
elas se cruzam: com 6 paradas, são 3 trocas. Tempo Θ(n), espaço extra Θ(1):

{{fluxograma}}

> [!WARNING]
> Recursão **custa** espaço, mesmo sem vetor. A soma recursiva
> `soma(v, n) = v[n-1] + soma(v, n-1)` não declara vetor nenhum e tem
> espaço extra Θ(n): `n` frames empilhados ao mesmo tempo. Com 1 milhão
> de elementos, a pilha (8 MB por padrão no Linux) pode estourar e o
> programa morre com *segmentation fault*. O laço equivalente usa Θ(1). Ao
> analisar espaço, procure a **profundidade máxima** da recursão, não só os
> `malloc`.

> [!TIP]
> **Por dentro do C:** a memória de um programa C tem três regiões que
> importam aqui. As variáveis locais e os frames ficam na **pilha**
> (*stack*), que é pequena e fixa: `ulimit -s` mostra 8192 KB na maioria
> dos Linux. O `malloc` pega memória do **heap**, que pode crescer até a
> RAM disponível. E o `static int grande[1000000]` do exemplo fica na área
> de **dados estáticos**, reservada antes do `main` começar: declarar esse
> vetor sem `static`, dentro do `main`, colocaria 4 MB na pilha, metade do
> limite. Por isso um Θ(n) de espaço feito com `malloc` costuma funcionar, e
> o mesmo Θ(n) feito com recursão funda costuma quebrar.


> [!NOTE]
> **Pergunta para você:** quantos bytes extras a `inverte_copiando` pediria
> para inverter 1 milhão de `double` em vez de `int`? E a
> `inverte_no_lugar`, com `tmp` do tipo `double`? Calcule e depois troque os
> tipos no programa.

{{pratique}}
