## 0180 · Pigeonhole e chave composta

- **Pigeonhole sort** (casas de pombo): para chave inteira num intervalo
  pequeno `[min, max]`. Cria `r = max - min + 1` casas; põe cada registro no
  fim da fila da sua casa e depois esvazia as casas em ordem. Custa O(n + r).
- **Primo do counting sort** (0120): o counting só conta e calcula posições;
  o pigeonhole guarda os registros, cada casa uma fila.
- **Ordenação estável**: registros com chaves iguais saem na ordem relativa em
  que entraram. O pigeonhole é estável porque cada casa é uma fila
  (ZIVIANI, 2010).
- **Quem é estável**: merge (se no empate pegar da esquerda) e inserção (se só
  deslocar quem é estritamente maior). Os não estáveis trocam elementos
  distantes (ZIVIANI, 2010).
- **Chave composta com comparador**: compara o campo principal e, no empate,
  o secundário. É o jeito do `qsort`, que o padrão não garante estável
  (CPPREFERENCE, s.d.).
- **Chave composta em passadas**: ordene pela chave menos importante e, com
  método estável, pela mais importante. A última passada manda; as anteriores
  desempatam, como no radix LSD (CORMEN et al., 2024).
- **Memória proporcional a `r`**: CPF (11 dígitos) pediria 100 bilhões de
  casas; para chaves grandes, use o radix (0121).

| Estáveis | Não estáveis |
| --- | --- |
| bubble, inserção, merge sort, counting, radix (LSD), bucket (com filas), pigeonhole | seleção, shell sort, quick sort, heapsort |

> [!WARNING]
> Nas passadas em sequência, a ordem é **da menos importante para a mais
> importante**: para "por cidade e, dentro dela, por nota", ordene pela nota e
> por último pela cidade. E a última passada **tem** que ser estável.

{{exemplo}}

Uma professora ordena a turma pela nota do simulado (0 a 10), e quem empata
fica na ordem da chamada. A chamada já está em ordem de nome, então uma
passada estável pela nota entrega a chave composta (nota, nome):

{{ideia}}

No `pombal.c`, a casa é uma fila de índices em três vetores (`primeiro`,
`ultimo` e `prox`), sem `malloc` por aluno. As duas passadas:

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

O programa compara com a seleção:

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

Na seleção, a Elisa passou na frente da Ana: na primeira volta, o Fabio trocou
com a Ana, que foi parar depois da Elisa. O fluxograma tem as duas passadas,
sem comparação entre alunos:

{{fluxograma}}
