## 0180 · Pigeonhole e chave composta

Uma ordenação que só compara pares de elementos faz da ordem de n log n
comparações no pior caso (módulo 17). O módulo 18 mostrou que, quando a chave
é um inteiro num intervalo curto, como uma nota de 0 a 10, dá para ordenar
sem comparar ninguém com ninguém. Aqui entra mais um método desse tipo, e com
ele uma pergunta que aparece em todo sistema real: como ordenar por mais de
um critério, "pela nota e, quem empatar, pelo nome"?

Imagine o pombal de um correio antigo: uma parede de escaninhos numerados,
um para cada rua. O carteiro pega cada carta e a põe no escaninho da rua dela,
sem comparar uma carta com outra. Depois esvazia os escaninhos da esquerda
para a direita, e as cartas saem agrupadas por rua. Esse é o **pigeonhole
sort** (ordenação por casas de pombo): para chaves inteiras num intervalo
`[min, max]`, ele cria uma **casa** para cada valor possível, `r = max - min +
1` casas ao todo.

O método tem duas passadas. Na primeira, cada registro entra **no fim da
fila** da casa da sua chave, a casa de índice `chave - min`. Na segunda, você
percorre as casas em ordem e tira os registros de cada fila, na ordem em que
entraram. A primeira passada custa O(n) e a segunda passa pelas `r` casas e
pelos `n` registros, então o total é **O(n + r)**. Se `r` for pequeno perto de
`n`, o custo é linear. Com notas de 0 a 10, `r` é 11, qualquer que seja o
tamanho da turma.

O pigeonhole é primo do **counting sort** do 0120. O counting só **conta**
quantas chaves há de cada valor e calcula a posição final de cada uma; ele
nem precisa guardar os registros em casas. O pigeonhole **guarda os
registros**, e cada casa é uma fila. É essa fila que dá ao pigeonhole a
propriedade da segunda metade do assunto.

Uma ordenação é **estável** quando registros com chaves iguais saem na mesma
ordem relativa em que entraram (ZIVIANI, 2010). Se Ana e Elisa tiraram 7 e
Ana vinha antes na lista, numa ordenação estável Ana continua antes. O
pigeonhole é estável porque cada casa é uma fila: quem entra primeiro sai
primeiro. A tabela mostra os métodos clássicos:

| Estáveis | Não estáveis |
| --- | --- |
| bubble, inserção, merge sort, counting, radix (LSD), bucket (com filas), pigeonhole | seleção, shell sort, quick sort, heapsort |

Dois da coluna da esquerda dependem de um detalhe de código. O merge sort é
estável se, no empate, pegar primeiro o elemento da metade esquerda. A
inserção é estável se deslocar só quem é **estritamente** maior que o
elemento sendo inserido. Os da coluna da direita perdem a estabilidade porque
trocam elementos distantes: a seleção, por exemplo, troca o menor com o
primeiro da parte não ordenada e pode jogar um registro para depois de outro
de chave igual (ZIVIANI, 2010).

A **chave composta** junta vários campos em ordem de prioridade, como "nota
e, no empate, nome". O primeiro jeito de ordenar por ela é um **comparador
composto**: uma função que compara o campo principal e, só quando ele empata,
compara o secundário. É o jeito de usar o `qsort` da biblioteca padrão, que
recebe o comparador por ponteiro para função e não garante estabilidade; o
desempate tem de estar escrito no comparador (CPPREFERENCE, s.d.).

O segundo jeito usa várias passadas de um método estável, **da chave menos
importante para a mais importante**. Para "nota e, no empate, nome", ordene
primeiro pelo nome e depois, com um método estável, pela nota. A última passada
decide a ordem principal; como ela é estável, quem empata na nota mantém a
ordem que a passada anterior deixou, e essa ordem é a do nome. É o mesmo
raciocínio do radix LSD, que ordena dígito a dígito começando pelo menos
significativo (CORMEN et al., 2024).

O pigeonhole tem um limite: a memória cresce com `r`, não com `n`. Ordenar
por CPF, que tem 11 dígitos, pediria 100 bilhões de casas para poucos
registros. Para chaves grandes, o caminho é o radix do 0121, que quebra a
chave em dígitos e usa poucas casas por passada.

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
