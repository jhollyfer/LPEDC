## 0168 · Complexidade espacial

O motorista de entregas tem a rota do dia anotada numa folha: paradas 12,
7, 30, 5, 18 e 9. Na volta, quer fazer o caminho ao contrário. Ele pode
copiar a rota invertida numa folha nova, ou pode trocar os números na
própria folha: a primeira parada com a última, a segunda com a penúltima, e
assim por diante, sem gastar papel. Com 6 paradas tanto faz. Com 1 milhão
de paradas guardadas como `int`, a folha nova pesa 4 MB.

Até aqui a análise contou passos, o **tempo**. A **complexidade espacial**
conta **memória**: quanto o algoritmo ocupa em função de `n`, medido com as
mesmas notações O, Ω e Θ (ZIVIANI, 2010, cap. 1). Quase sempre o que
interessa é o **espaço extra**, também chamado de **espaço auxiliar**: o
que a função usa **além da entrada** que recebeu (LINTZMAYER; MOTA, 2023).
A rota em si já existe antes da função ser chamada, então não conta.

Com essa medida, as duas inversões se separam. Copiar numa folha nova pede
um vetor auxiliar de `n` posições: espaço extra Θ(n). Trocar as pontas
pede uma única variável para guardar um valor durante a troca, seja a rota
de 6 ou de 1 milhão de paradas: espaço extra Θ(1). Um algoritmo que usa só
um número fixo de variáveis simples, mexendo na própria entrada, se chama
**in-place**, ou "no lugar" (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 6).

```c
for (int i = 0, j = n - 1; i < j; i++, j--) {
    int tmp = rota[i];   // a única memória extra
    rota[i] = rota[j];
    rota[j] = tmp;
}
```

O espaço extra aparece em três lugares, e vale olhar cada um. O primeiro é
o mais visível: vetores declarados e blocos pedidos ao `malloc`. Um vetor
auxiliar de `n` posições é Θ(n); uma matriz `n × n` é Θ(n²).

O segundo é a **pilha de chamadas**, e é o que passa despercebido. Cada
chamada de função que ainda não terminou ocupa um **frame** na pilha, com
seus parâmetros e variáveis locais (assunto 0031). Numa recursão, os frames
se acumulam enquanto as chamadas descem. O espaço da recursão é a
**profundidade máxima**, o maior número de chamadas ativas ao mesmo tempo,
vezes o tamanho do frame. Não é o total de chamadas feitas ao longo da
execução (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3). A busca binária
recursiva faz umas `log n` chamadas, uma dentro da outra, e por isso usa
Θ(log n) de pilha; a versão com laço usa Θ(1).

O terceiro são as tabelas criadas para ganhar tempo: a memoização, que
guarda resultados já calculados, o vetor de contagem do counting sort, a
tabela hash. Em todos, o algoritmo gasta memória para economizar passos. É
a troca de **tempo por espaço** (CORMEN et al., 2024).

Cada tipo de memória mora num lugar diferente do processo, com limites
diferentes. Variáveis locais e frames ficam na **pilha**, que é pequena e
tem tamanho fixo: no Linux, `ulimit -s` costuma mostrar 8192 KB. O
`malloc` usa o **heap**, que pode crescer até o tamanho da RAM. Uma
variável `static` fica na área de **dados estáticos**, reservada quando o
programa começa (LINUX MAN-PAGES, s.d.). Um `static int grande[1000000]`
ocupa 4 MB nos dados estáticos; sem o `static`, dentro de uma função,
seriam 4 MB na pilha, metade do limite.

A tabela resume tempo e espaço extra dos algoritmos que você já viu:

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
> Recursão **custa** espaço, mesmo sem vetor. `soma(v, n) = v[n-1] +
> soma(v, n-1)` tem espaço extra Θ(n): `n` frames empilhados. Com 1 milhão
> de elementos, a pilha de 8 MB estoura em *segmentation fault*; o laço usa
> Θ(1). Procure a **profundidade máxima**, não só os `malloc`.

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
