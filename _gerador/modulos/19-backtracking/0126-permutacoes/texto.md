## 0126 · Permutações

Sarau na praça. Três grupos confirmaram, um de rap, um de samba e um de
forró, e a organização precisa decidir a ordem das apresentações. Antes de
votar, alguém pede a lista de todas as ordens possíveis.

Para a primeira apresentação há 3 escolhas. Escolhida a primeira, sobram 2
para a segunda, e a última fica com quem sobrou: 3 × 2 × 1 = **6** ordens.
Cada ordem é uma **permutação** dos três grupos, e com `n` elementos há
**n!** permutações (fatorial de `n`).

A recursão gera todas decidindo **uma posição por vez**. A função
`permuta(v, i)` sabe que as posições `0..i-1` já estão decididas e cuida da
posição `i`. Quem pode ir para lá? Qualquer elemento ainda não usado, e os não
usados são justamente os que estão em `v[i..n-1]`. Então, para cada `j` de `i`
até `n - 1`:

1. **escolhe**: troca `v[i]` com `v[j]`, levando o candidato para a posição `i`;
2. **desce**: chama `permuta(v, i + 1)` para decidir o resto;
3. **desfaz**: troca `v[i]` com `v[j]` de novo, devolvendo o vetor como
   estava antes da escolha.

O passo 3 é o que separa a enumeração que funciona da que não funciona. No
assunto anterior, a escolha se desfazia sozinha porque morava num parâmetro.
Aqui a escolha mexe no **vetor**, que é um só para todas as chamadas. Se a
chamada não arrumar a bagunça antes de voltar, a próxima volta do laço de quem
a chamou parte de um vetor diferente do que esperava.

Quando `i` chega a `n`, todas as posições estão decididas: é hora de mostrar a
ordem.

Vamos ver na prática. No primeiro nível, cada ramo leva um grupo diferente
para a frente da fila. No segundo, o mesmo para a segunda posição. As 6 folhas
são as 6 ordens, na ordem em que o programa mostra:

{{ideia}}

O vetor guarda ponteiros para os nomes (assunto 0048). Trocar dois elementos
é trocar dois ponteiros: os textos não saem do lugar.

```c
#include <stdio.h>

#define N 3

int ordens = 0;

void troca(const char **a, const char **b) {
    const char *t = *a;   // troca só os ponteiros, não as letras
    *a = *b;
    *b = t;
}

// as posições 0..i-1 já estão decididas; decide a posição i
void permuta(const char *v[], int i) {
    if (i == N) {
        ordens++;
        printf("%d: %s, %s, %s\n", ordens, v[0], v[1], v[2]);
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);    // escolhe: v[j] vai para a posição i
        permuta(v, i + 1);      // decide o resto
        troca(&v[i], &v[j]);    // desfaz: devolve o vetor como estava
    }
}

int main(void) {
    const char *shows[N] = {"Rap", "Samba", "Forró"};
    permuta(shows, 0);
    printf("%d ordens; no fim: %s, %s, %s\n", ordens, shows[0], shows[1], shows[2]);
    return 0;
}
// Saída:
// 1: Rap, Samba, Forró
// 2: Rap, Forró, Samba
// 3: Samba, Rap, Forró
// 4: Samba, Forró, Rap
// 5: Forró, Samba, Rap
// 6: Forró, Rap, Samba
// 6 ordens; no fim: Rap, Samba, Forró
```

Repara na última linha: depois de tudo, o vetor voltou a ser
`Rap, Samba, Forró`. É a prova de que cada chamada desfez o que fez. Repara
também nas linhas 5 e 6: a troca de `Rap` com `Forró` deixou o `Samba` no
meio, então a ordem que sai **não** é a alfabética nem a "de dicionário".
Quem precisa dessa ordem usa outro jeito (exemplo A251).

Repara no fluxograma: o laço do `j` é o que abre os ramos, e cada volta dele
tem o par troca e destroca em volta da chamada recursiva:

{{fluxograma}}

> [!WARNING]
> Esquecer o **desfaz** é o erro clássico. Sem a segunda troca, este mesmo
> programa mostra `Rap, Samba, Forró` e `Rap, Forró, Samba` duas vezes cada, e
> o `Samba` nunca abre o sarau: ainda saem 6 linhas, só que erradas, e no fim o
> vetor fica `Rap, Forró, Samba`. Toda alteração feita antes da chamada
> recursiva precisa ser desfeita depois dela, na ordem inversa.

> [!TIP]
> **Por dentro do C:** a recursão desce só `n + 1` níveis, mas o número de
> folhas é `n!`, e cada folha gasta `n` passos para mostrar: o custo é
> **O(n · n!)**, pior que os 2ⁿ dos subconjuntos. 10! já passa de 3,6 milhões,
> 13! (6.227.020.800) não cabe num `int` de 32 bits, e 20! fica perto de
> 2,4 · 10¹⁸, no limite de um `long long`. Trocar ponteiros é barato: 8 bytes
> por elemento, não importa o tamanho do nome. Trocar structs grandes ou
> strings inteiras com `strcpy` custaria muito mais em cada uma das `n!`
> folhas.

> [!NOTE]
> **Pergunta para você:** com um quarto grupo, de pagode, no fim do vetor,
> quantas linhas saem? Qual grupo abre o sarau na linha 7? E na linha 19?

{{pratique}}
