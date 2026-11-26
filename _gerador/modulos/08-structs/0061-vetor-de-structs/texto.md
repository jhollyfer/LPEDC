## 0061 · Vetor de structs

Uma struct guarda um time. Um campeonato tem vinte. Declarar `Time t1, t2,
t3...` traz de volta o problema das variáveis soltas: não dá para percorrer
os times com um laço, nem achar o líder sem escrever vinte comparações. A
saída é juntar as duas ferramentas que você já conhece, o vetor e a struct.

Olhe a tabela do campeonato no jornal. Cada linha é um time, e todas as
linhas têm as mesmas colunas: nome, vitórias, empates, derrotas. Uma linha é
uma struct; a tabela inteira é um **vetor de structs**, um vetor em que cada
posição guarda uma struct completa. `Time tabela[4];` declara quatro `Time`
seguidos na memória, com os bytes de cada struct guardados dentro do próprio
vetor, um time colado no outro (BACKES, 2013, cap. 8).

Para chegar a um dado, você escolhe primeiro a linha e depois a coluna:
`tabela[2].nome`. O índice vem **antes** do ponto, e o motivo está nos
tipos. `tabela` é um vetor; `tabela[2]` é um `Time`; e um `Time` tem o campo
`nome`. Já `tabela.nome[2]` não faz sentido, porque o vetor em si não tem
campos, só posições (BACKES, 2013, cap. 8). Lendo da esquerda para a direita,
cada operador entrega o tipo que o próximo espera.

A inicialização junta as duas sintaxes que você já viu: as chaves do vetor
por fora e as chaves de cada struct por dentro (DEITEL; DEITEL, 2011,
cap. 10):

```c
Time tabela[] = {
    {"Bahia", 8, 5, 3},
    {"Flamengo", 9, 6, 1},
};
```

Repare que os colchetes ficaram vazios. Quando você não diz o tamanho, o
compilador conta os elementos da lista. Para o programa saber quantos são, use
a conta de sempre: `sizeof tabela / sizeof tabela[0]`, o tamanho total do
vetor dividido pelo tamanho de um time. Com dois times de 32 bytes, dá 64 / 32
= 2 (DEITEL; DEITEL, 2011, cap. 10). Essa conta só funciona no mesmo bloco
em que o vetor foi declarado; dentro de uma função que o recebeu, ele já virou
ponteiro e o `sizeof` mede o ponteiro.

Uma posição do vetor é uma struct inteira, então `tabela[i] = tabela[j]`
copia o time todo de uma vez: nome, vitórias, empates e derrotas. Isso é o
que você quer na hora de ordenar a tabela. Para trocar dois times de lugar,
troque as structs com uma variável auxiliar do tipo `Time`, e não campo a
campo (BACKES, 2013, cap. 8). Se trocar só o nome, o Bahia fica com os
pontos do Flamengo.

Quando você procura um elemento, como o time com mais pontos, guarde o
**índice** dele, não uma cópia. O índice diz em que posição o líder está, e
com ele você pode mexer no time verdadeiro: `tabela[lider].vitorias++` muda a
tabela. Uma cópia (`Time melhor = tabela[i];`) seria um time solto,
desligado do vetor; aumentar `melhor.vitorias` não altera nada na tabela.

Percorrer o vetor segue o mesmo padrão de qualquer vetor: um `for` de 0 até
`n - 1`, e em cada volta você lê os campos de `tabela[i]`. A diferença é que
agora cada elemento traz vários dados juntos, e o laço pode calcular algo com
eles, como os pontos (3 por vitória, 1 por empate).

> [!WARNING]
> O C não confere limites: `tabela[4]` num vetor de 4 times (índices 0 a 3)
> lê lixo ou derruba o programa, como num vetor de `int`. E ao ordenar,
> troque o time **inteiro** (`tabela[i] = tabela[j]`): trocar só o nome
> embaralha nomes e pontos.

{{exemplo}}

Quatro times na tabela do campeonato. O programa calcula os pontos de cada um
(3 por vitória, 1 por empate) e guarda o **índice** do melhor até agora.
Palmeiras, no índice 2, termina na frente:

{{ideia}}

```c
#include <stdio.h>

typedef struct {
    char nome[20];
    int vitorias;
    int empates;
    int derrotas;
} Time;

int pontos(Time t) {
    return 3 * t.vitorias + t.empates;
}

int main(void) {
    Time tabela[] = {
        {"Bahia", 8, 5, 3},
        {"Flamengo", 9, 6, 1},
        {"Palmeiras", 10, 4, 2},
        {"Vasco", 7, 7, 2},
    };
    int n = sizeof tabela / sizeof tabela[0]; // 4 times

    int lider = 0; // índice do melhor até agora
    for (int i = 0; i < n; i++) {
        printf("%d. %-10s %2d pts\n", i, tabela[i].nome, pontos(tabela[i]));
        if (pontos(tabela[i]) > pontos(tabela[lider])) {
            lider = i;
        }
    }
    printf("Líder: %s, com %d pontos\n", tabela[lider].nome, pontos(tabela[lider]));
    printf("A tabela ocupa %zu bytes (%d x %zu)\n", sizeof tabela, n, sizeof(Time));
    return 0;
}
// Saída:
// 0. Bahia      29 pts
// 1. Flamengo   33 pts
// 2. Palmeiras  34 pts
// 3. Vasco      28 pts
// Líder: Palmeiras, com 34 pontos
// A tabela ocupa 128 bytes (4 x 32)
```

É o padrão "maior até agora" do módulo de laços, comparando um valor calculado
de cada struct:

{{fluxograma}}
