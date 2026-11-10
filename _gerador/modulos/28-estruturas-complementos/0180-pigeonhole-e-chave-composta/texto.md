## 0180 · Pigeonhole e chave composta

A professora quer a turma pela nota do simulado, da menor para a maior. As
notas vão de 0 a 10, e quem empata continua na ordem alfabética da chamada.
Com só 11 notas, dá para ordenar sem comparar alunos.

O **pigeonhole sort** (casas de pombo) serve quando a chave é um inteiro num
intervalo pequeno `[min, max]`. Ele cria uma **casa** para cada valor, `r =
max - min + 1` casas, e faz duas passadas:

1. põe cada registro **no fim da fila** da casa da sua chave (`chave - min`);
2. percorre as casas em ordem e devolve os registros, **na ordem em que
   entraram**.

O custo é **O(n + r)**, linear se `r` for pequeno perto de `n`. Ele é primo do
**counting sort** (0120): o counting só **conta** e calcula posições; o
pigeonhole **guarda os registros**, cada casa uma fila.

Por isso é **estável**: uma ordenação é **estável** quando registros com
**chaves iguais** saem na ordem relativa em que entraram. Os clássicos:

| Estáveis | Não estáveis |
| --- | --- |
| bubble, inserção, merge sort, counting, radix (LSD), bucket (com filas), pigeonhole | seleção, shell sort, quick sort, heapsort |

O merge é estável se, no empate, pegar primeiro da esquerda; a inserção, se só
deslocar quem é **estritamente** maior. Os não estáveis **trocam elementos
distantes**.

A **chave composta** junta campos em ordem de prioridade: nota e, no empate,
nome. Há dois jeitos:

- **um comparador composto**: compara o campo principal e, no empate, o
  secundário. É o jeito do `qsort`, que **não** é estável pelo padrão C: o
  desempate tem que estar no comparador;
- **várias passadas estáveis, da chave menos importante para a mais
  importante**: ordene pela secundária e, com método estável, pela principal.
  A última passada manda; as anteriores desempatam. É o raciocínio do radix
  LSD.

A chamada (Ana 7, Bruno 5, Carla 9, Diego 5, Elisa 7, Fabio 3, Gabi 9, Hugo 5)
já está em ordem de nome, então uma passada **estável** pela nota entrega a
chave composta (nota, nome):

{{ideia}}

No `pombal.h`, a casa é uma fila de **índices**, montada com três vetores
(`primeiro`, `ultimo` e `prox`), sem `malloc` por aluno. As duas passadas, no
`pombal.c`:

```c
    for (int i = 0; i < n; i++) { // 1. cada aluno entra no fim da fila da sua casa
        int c = v[i].nota - min;
        prox[i] = -1;
        if (primeiro[c] == -1) {
            primeiro[c] = i;
        } else {
            prox[ultimo[c]] = i;
        }
        ultimo[c] = i;
    }
    int k = 0;
    for (int c = 0; c < casas; c++) { // 2. esvazia as casas em ordem
        for (int i = primeiro[c]; i != -1; i = prox[i]) {
            saida[k++] = v[i];
        }
    }
```

A seleção, para comparar:

```c
#include <stdio.h>
#include "pombal.h"

int main(void) {
    Aluno chamada[] = { // em ordem alfabética, como na lista de chamada
        {"Ana", 7, 1},   {"Bruno", 5, 2}, {"Carla", 9, 1}, {"Diego", 5, 1},
        {"Elisa", 7, 2}, {"Fabio", 3, 2}, {"Gabi", 9, 2},  {"Hugo", 5, 1},
    };
    int n = 8;
    Aluno a[8], b[8];
    for (int i = 0; i < n; i++) {
        a[i] = chamada[i];
        b[i] = chamada[i];
    }
    if (pb_pigeonhole(a, n, 0, 10) != 0) { // notas de 0 a 10: 11 casas
        return 1;
    }
    printf("Pigeonhole: ");
    pb_mostra(a, n);
    pb_selecao(b, n);
    printf("Seleção:    ");
    pb_mostra(b, n);
    return 0;
}
// Saída:
// Pigeonhole: Fabio(3) Bruno(5) Diego(5) Hugo(5) Ana(7) Elisa(7) Carla(9) Gabi(9)
// Seleção:    Fabio(3) Bruno(5) Diego(5) Hugo(5) Elisa(7) Ana(7) Gabi(9) Carla(9)
```

Na seleção, a Elisa passou na frente da Ana: na primeira volta, o Fabio
(posição 5) trocou com a Ana (posição 0), que foi parar depois da Elisa.

O fluxograma tem as duas passadas, sem comparação entre alunos: a primeira
põe cada um na sua casa; a segunda esvazia as 11 casas em ordem:

{{fluxograma}}

> [!WARNING]
> Nas passadas em sequência, a ordem é **da menos importante para a mais
> importante**. Para "por cidade e, dentro dela, por nota", ordene primeiro
> pela nota e **por último** pela cidade. E a última passada **tem** que ser
> estável: com a seleção, ela embaralha o que a primeira arrumou (o A360
> mostra).

> [!TIP]
> A memória é proporcional a `r`: CPF (11 dígitos) pediria 100 bilhões de
> casas. Para chaves grandes existe o radix (0121).

> [!NOTE]
> **Pergunta para você:** se a lista de chamada estivesse em ordem
> **contrária** (de Hugo para Ana), em que ordem sairiam Bruno, Diego e Hugo
> no pigeonhole? E na seleção, dá para prever sem rodar?

{{pratique}}
