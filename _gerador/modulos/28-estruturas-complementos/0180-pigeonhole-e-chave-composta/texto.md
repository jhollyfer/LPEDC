## 0180 · Pigeonhole e chave composta

A professora do cursinho corrigiu o simulado e quer a lista da turma pela
nota, da menor para a maior. As notas são inteiras, de 0 a 10, e a lista de
chamada já está em ordem alfabética. E quer que quem tirou a mesma nota continue
em ordem alfabética. Com 11 notas possíveis, dá para ordenar sem
comparar um aluno com outro.

O **pigeonhole sort** (ordenação por casas de pombo) serve quando a chave é um
inteiro num intervalo pequeno `[min, max]`. Ele cria uma **casa** para cada
valor possível, `r = max - min + 1` casas, e faz duas passadas:

1. percorre a entrada e põe cada registro **no fim da fila** da casa da sua
   chave (`chave - min`);
2. percorre as casas em ordem e devolve os registros, **na ordem em que
   entraram**.

O custo é **O(n + r)**: uma passada nos registros e uma nas casas. Se `r` for
pequeno perto de `n` (notas, idades, dias do mês), é linear. Ele é primo do
**counting sort** (0120): o counting só **conta** quantos caem em cada valor e
calcula posições; o pigeonhole **guarda os próprios registros** nas casas. Com
número solto, a casa só precisa contar; com registro (nome e nota), cada casa
vira uma fila.

Como cada casa é uma fila, quem entrou primeiro sai primeiro: o pigeonhole é
**estável**. Uma ordenação é **estável** quando registros com **chaves
iguais** saem na mesma ordem relativa em que entraram. Os clássicos:

| Estáveis | Não estáveis |
| --- | --- |
| bubble, inserção, merge sort, counting, radix (LSD), bucket (com filas), pigeonhole | seleção, shell sort, quick sort, heapsort |

O merge é estável se, no empate, pegar primeiro da metade da esquerda; a
inserção, se só deslocar quem é **estritamente** maior. Os não estáveis
**trocam elementos distantes**: a troca pula por cima de quem está no meio.

Estabilidade importa quando há mais de uma chave. A **chave simples** é um
campo só (a nota). A **chave composta** junta campos em ordem de prioridade:
nota e, no empate, nome; ou turma, depois nota. Há dois jeitos de ordenar por
ela:

- **um comparador composto**: compara o campo principal; se empatar, o
  secundário; e assim por diante. É o jeito do `qsort` (que **não** é estável
  pelo padrão C, então o desempate tem que estar no comparador);
- **várias passadas estáveis, da chave menos importante para a mais
  importante**: ordene pela secundária e depois, com um método estável, pela
  principal. A última passada manda; as anteriores só desempatam. É o
  raciocínio do radix LSD.

A lista de chamada (Ana 7, Bruno 5, Carla 9, Diego 5,
Elisa 7, Fabio 3, Gabi 9, Hugo 5) já está em ordem de nome. Uma passada
**estável** pela nota entrega a chave composta (nota, nome) de graça. No
desenho, os alunos entrando nas casas 3, 5, 7 e 9 e saindo em ordem:

{{ideia}}

O TAD é o `pombal.h`. A casa é uma fila de **índices**, montada com três
vetores (`primeiro`, `ultimo` e `prox`), sem um `malloc` por aluno. As duas
passadas, no `pombal.c`:

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

E a professora, que compara com a seleção:

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

Na seleção, a Elisa passou na frente da Ana, e a Gabi na frente da Carla. Na
primeira volta, o Fabio (posição 5) trocou com a Ana (posição 0), e a Ana foi
parar depois da Elisa: a troca pulou por cima dela.

O fluxograma tem as duas passadas do pigeonhole, sem nenhuma comparação entre
alunos. A primeira põe cada um na sua casa; a segunda esvazia as 11 casas em
ordem:

{{fluxograma}}

> [!WARNING]
> Nas passadas em sequência, a ordem é **da menos importante para a mais
> importante**. Para "por cidade e, dentro dela, por nota", ordene primeiro
> pela nota e **por último** pela cidade. Trocar a ordem dá uma lista por
> nota com as cidades misturadas (é o bug do E1079). E a última passada
> **tem** que ser estável: com a seleção, ela embaralha o que a primeira
> arrumou (o A360 mostra).

> [!TIP]
> **Por dentro do C:** o pigeonhole gasta memória proporcional a `r`, o
> tamanho do intervalo, não a `n`. Para notas, 11 casas de dois `int` são 88
> bytes. Para CPF (11 dígitos), seriam 100 bilhões de casas: não cabe. Por
> isso ele só serve para intervalos pequenos, e por isso o radix (0121) existe:
> ele quebra a chave grande em pedaços pequenos e faz uma passada estável por
> pedaço. Outro custo: o `pb_pigeonhole` copia structs inteiras

> (`saida[k++] = v[i]`, 24 bytes cada): com registros grandes, ordene um vetor
> de índices ou de ponteiros e mova só eles.

> [!NOTE]
> **Pergunta para você:** se a lista de chamada estivesse em ordem
> **contrária** (de Hugo para Ana), em que ordem sairiam Bruno, Diego e Hugo
> no pigeonhole? E na seleção, dá para prever sem rodar?

{{pratique}}
