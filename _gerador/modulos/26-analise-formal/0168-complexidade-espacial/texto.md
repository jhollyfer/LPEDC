## 0168 · Complexidade espacial

- **Complexidade espacial**: a memória que o algoritmo usa em função de `n`,
  medida com as mesmas notações O, Ω e Θ (ZIVIANI, 2010, cap. 1).
- **Espaço extra** (ou **auxiliar**): o que a função usa **além da entrada**.
  É o que quase sempre interessa (LINTZMAYER; MOTA, 2023).
- **In-place** (no lugar): o espaço extra é Θ(1), um número fixo de
  variáveis simples. Uma cópia da entrada já é Θ(n)
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).
- **Pilha da recursão**: cada chamada ativa ocupa um frame. O espaço é a
  **profundidade máxima** vezes o frame, não o total de chamadas
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3).
- **Onde mora a memória**: locais e frames ficam na **pilha**, pequena e fixa
  (`ulimit -s` mostra 8192 KB); o `malloc` usa o **heap**; um `static` fica nos
  dados estáticos (LINUX MAN-PAGES, s.d.).
- **Tempo por espaço**: memoização, vetor de contagem e tabela hash gastam
  memória para ganhar tempo (CORMEN et al., 2024).

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

> [!WARNING]
> Recursão **custa** espaço mesmo sem vetor. `soma(v, n) = v[n-1] + soma(v,
> n-1)` empilha `n` frames: com 1 milhão de elementos, a pilha de 8 MB estoura
> em *segmentation fault*. Procure a **profundidade máxima**, não só os `malloc`.

{{exemplo}}

Um motorista quer a rota do dia ao contrário. Em cima, a cópia: 6 gavetas a
mais, `6 · 4 = 24` bytes. Embaixo, a inversão no lugar: só a caixinha `tmp`, 4
bytes, para qualquer rota:

{{ideia}}

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

O `i` anda da esquerda e o `j` da direita até se cruzarem: 3 trocas para 6
paradas, tempo Θ(n) e espaço extra Θ(1):

{{fluxograma}}
