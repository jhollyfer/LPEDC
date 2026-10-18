## 0066 · Vetor de structs

Abra qualquer app de futebol e olhe a tabela do campeonato. Cada linha é um
time, e toda linha tem as mesmas colunas: nome, vitórias, empates, derrotas.
Uma linha é uma struct. A tabela inteira é um **vetor de structs**.

Você já conhece as duas peças. Um vetor guarda vários valores do mesmo tipo,
lado a lado. Uma struct é um tipo. Junte as duas: `Time tabela[4];` são quatro
`Time` seguidos na memória. O vetor não guarda **referências** para structs
espalhadas pela memória: os bytes das structs ficam **dentro** do vetor, um
time colado no outro.

Para chegar num campo, você primeiro escolhe a linha e depois a coluna:
`tabela[2].nome`. O índice vem **antes** do ponto, porque `tabela[2]` é um
`Time`, e um `Time` tem o campo `nome`. Já `tabela.nome[2]` não faz sentido:
o vetor não tem campo nenhum.

A inicialização junta as duas sintaxes, chaves dentro de chaves:

```c
Time tabela[] = {
    {"Bahia", 8, 5, 3},
    {"Flamengo", 9, 6, 1},
};
```

Sem o tamanho entre colchetes, o compilador conta os elementos. E o truque de
sempre para saber quantos são continua valendo: `sizeof tabela / sizeof
tabela[0]`.

Vamos ver na prática. Quatro times, cada um com seus números. O programa
percorre o vetor, calcula os pontos de cada um (3 por vitória, 1 por empate) e
guarda o **índice** do melhor até agora. Palmeiras, no índice 2, termina na
frente:

{{ideia}}

O código faz exatamente esse passeio:

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

Guardar o índice, e não uma cópia do time, é de propósito: com o índice você
sabe **onde** está o líder e pode mexer nele (`tabela[lider].vitorias++`).
Uma cópia seria um time solto, desligado da tabela.

Repara no fluxograma: é o padrão "maior até agora" do módulo de laços, só que
a comparação olha um campo calculado de cada struct:

{{fluxograma}}

> [!WARNING]
> `tabela[i] = tabela[j]` copia o time **inteiro**, todos os campos. Isso é
> ótimo para trocar dois times de lugar ao ordenar: troque as structs, não os
> campos um por um. O erro clássico é trocar só o nome e esquecer os números,
> deixando a tabela com nomes e pontos embaralhados. E lembre que o C não
> confere limites: `tabela[4]` num vetor de 4 times lê lixo (ou derruba o
> programa) do mesmo jeito que num vetor de `int`.

> [!TIP]
> **Por dentro do C:** cada `Time` ocupa 32 bytes (20 do nome + 3 inteiros de
> 4), e os quatro ficam colados: 128 bytes seguidos. Para achar
> `tabela[2].vitorias`, o compilador faz uma conta só: início do vetor
> + 2 × 32 (pula dois times) + 20 (pula o nome). Por isso percorrer um vetor de
> structs é rápido: os dados estão em sequência, e o processador traz vários
> de uma vez para o cache. Dados espalhados pela memória não têm essa
> vantagem.

> [!NOTE]
> **Pergunta para você:** se o Vasco tivesse 9 vitórias, 7 empates e 0
> derrotas, quem seria o líder? E se houvesse empate em pontos com o
> Palmeiras, com o `>` do código, quem ficaria: o primeiro ou o último a
> aparecer na tabela?

{{pratique}}
