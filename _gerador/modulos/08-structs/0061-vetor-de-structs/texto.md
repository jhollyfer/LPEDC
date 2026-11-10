## 0061 · Vetor de structs

Na tabela do campeonato, cada linha é um time e todas têm as mesmas colunas:
nome, vitórias, empates, derrotas. Uma linha é uma struct. A tabela inteira é
um **vetor de structs**.

`Time tabela[4];` são quatro `Time` seguidos na memória: os bytes das structs
ficam **dentro** do vetor, um time colado no outro.

Para chegar a um campo, escolha a linha e depois a coluna: `tabela[2].nome`. O
índice vem **antes** do ponto, porque `tabela[2]` é um `Time`, e um `Time` tem
o campo `nome`. `tabela.nome[2]` não faz sentido: o vetor não tem campos.

A inicialização junta as duas sintaxes, chaves dentro de chaves:

```c
Time tabela[] = {
    {"Bahia", 8, 5, 3},
    {"Flamengo", 9, 6, 1},
};
```

Sem o tamanho entre colchetes, o compilador conta os elementos. O truque de
sempre dá a quantidade: `sizeof tabela / sizeof tabela[0]`.

São quatro times. O programa percorre o vetor, calcula os pontos de cada um (3
por vitória, 1 por empate) e guarda o **índice** do melhor até agora.
Palmeiras, no índice 2, termina na frente:

{{ideia}}

O código faz esse passeio:

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

Guardar o índice, e não uma cópia, é de propósito: com ele você sabe **onde**
está o líder e pode mexer nele (`tabela[lider].vitorias++`). Uma cópia seria
um time solto, desligado da tabela.

É o padrão "maior até agora" do módulo de laços, comparando um valor
calculado de cada struct:

{{fluxograma}}

> [!WARNING]
> `tabela[i] = tabela[j]` copia o time **inteiro**. Use para trocar dois times
> ao ordenar: troque as structs, não campo a campo (trocar só o nome embaralha
> nomes e pontos). O C não confere limites: `tabela[4]` num vetor de 4 times
> lê lixo ou derruba o programa, como num vetor de `int`.

> [!NOTE]
> **Pergunta para você:** se o Vasco tivesse 9 vitórias, 7 empates e 0
> derrotas, quem seria o líder? E se houvesse empate em pontos com o
> Palmeiras, com o `>` do código, quem ficaria: o primeiro ou o último a
> aparecer na tabela?

{{pratique}}
