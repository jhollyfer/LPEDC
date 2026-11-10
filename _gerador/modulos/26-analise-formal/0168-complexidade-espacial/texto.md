## 0168 · Complexidade espacial

O motorista tem a rota do dia: paradas 12, 7, 30, 5, 18 e 9. Na volta, quer o
caminho ao contrário: pode copiar a rota invertida numa folha nova ou trocar
na própria folha (a primeira com a última, a segunda com a penúltima...), sem
gastar papel. Com 1 milhão de paradas, a folha nova pesa 4 MB.

A **complexidade espacial** conta **memória** em função de `n`, com as
mesmas notações O, Ω e Θ.

Quase sempre interessa o **espaço extra** (ou **auxiliar**): o que a função
usa **além da entrada**. Número fixo de variáveis simples é **Θ(1)**: o
algoritmo é **in-place** (no lugar). Uma cópia da entrada é **Θ(n)**.

O espaço extra aparece em três lugares:

- **vetores e `malloc`**: um auxiliar de `n` posições é Θ(n), uma matriz
  `n × n` é Θ(n²);
- **a pilha de chamadas**: cada chamada recursiva ativa ocupa um frame
  (assunto 0031). O espaço é a **profundidade máxima** vezes o tamanho do
  frame, não o total de chamadas;
- **tabelas para ganhar tempo**: memoização, vetor de contagem, tabela hash.
  É a troca de **tempo por espaço**.

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

Em cima, a cópia: 6 gavetas a mais, `6 · 4 = 24` bytes. Embaixo, a inversão
no lugar: só a caixinha `tmp`, 4 bytes, para qualquer rota:

{{ideia}}

O programa faz as duas inversões e devolve os bytes extras de cada uma.
Depois repete com 1 milhão de paradas:

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

Nenhuma caixa cria memória. O `i` anda da esquerda e o `j` da direita, até se
cruzarem: 3 trocas para 6 paradas. Tempo Θ(n), espaço extra Θ(1):

{{fluxograma}}

> [!WARNING]
> Recursão **custa** espaço, mesmo sem vetor. `soma(v, n) = v[n-1] + soma(v,
> n-1)` tem espaço extra Θ(n): `n` frames empilhados. Com 1 milhão de
> elementos, a pilha (8 MB no Linux) estoura em *segmentation fault*; o laço
> usa Θ(1). Procure a **profundidade máxima**, não só os `malloc`.

> [!TIP]
> Locais e frames ficam na **pilha**, pequena e fixa (`ulimit -s` mostra 8192
> KB). O `malloc` usa o **heap**, que cresce até a RAM. O `static int
> grande[1000000]` fica nos **dados estáticos**; sem `static`, seriam 4 MB na
> pilha, metade do limite.

> [!NOTE]
> **Pergunta para você:** quantos bytes extras a `inverte_copiando` pediria
> com 1 milhão de `double` em vez de `int`? E a `inverte_no_lugar`, com `tmp`
> `double`? Calcule e troque os tipos no programa.

{{pratique}}
