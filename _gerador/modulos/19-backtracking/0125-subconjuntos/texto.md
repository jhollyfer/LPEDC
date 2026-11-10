## 0125 · Subconjuntos

Na fila do açaí, você pode pôr qualquer combinação de três complementos:
granola (R$ 2), banana (R$ 3) e paçoca (R$ 4). Quantos copos existem e quanto
custa cada um?

Cada complemento é um sim ou não: 2 × 2 × 2 = **8** copos. Cada copo é um
**subconjunto** de {granola, banana, paçoca}, e a lista de todos é o
**conjunto das partes**: com `n` itens, **2ⁿ** subconjuntos, contando o vazio
e o conjunto inteiro.

**Enumerar** é gerar todos sem esquecer nem repetir. Na recursão (assunto
0032), `gera(i, k)` cuida do item `i` e abre dois caminhos: com o item **de
fora** e com o item **dentro**, ambos chamando `gera(i + 1, ...)`. Quando `i`
chega a `n`, o subconjunto é mostrado.

Os itens escolhidos ficam em `cesta`, e `k` conta os lugares ocupados. Como `k`
é **parâmetro**, a escolha se **desfaz sozinha** quando a chamada termina.

Sem recursão, use os bits de um número (assunto 0065): conte `m` de 0 a
2ⁿ - 1 e leia o bit `i` de `m` como "o item `i` entra". O 5 é `101`: granola
e paçoca.

```c
for (int m = 0; m < (1 << N); m++)      // 1 << 3 vale 8
    for (int i = 0; i < N; i++)
        if (m & (1 << i)) { /* o item i está no subconjunto m */ }
```

Na árvore de decisões, cada nível é um complemento: o ramo da esquerda deixa o
item de fora e o da direita o põe. As 8 folhas são os 8 copos, na ordem em que
o programa os mostra:

{{ideia}}

O programa percorre a árvore da esquerda para a direita:

```c
#include <stdio.h>

#define N 3

const char *nomes[N] = {"granola", "banana", "paçoca"};
const int precos[N] = {2, 3, 4}; // reais

int cesta[N];       // índices dos itens escolhidos até agora
int chamadas = 0;

// decide o item i; os k primeiros lugares da cesta já estão ocupados
void gera(int i, int k) {
    chamadas++;
    if (i == N) {                       // decidiu todos: mostra a cesta
        int total = 0;
        printf("{");
        for (int j = 0; j < k; j++) {
            printf(j == 0 ? "%s" : ", %s", nomes[cesta[j]]);
            total += precos[cesta[j]];
        }
        printf("} R$ %d\n", total);
        return;
    }
    gera(i + 1, k);                     // caminho 1: sem o item i
    cesta[k] = i;                       // caminho 2: com o item i
    gera(i + 1, k + 1);
}

int main(void) {
    gera(0, 0);
    printf("%d chamadas\n", chamadas);
    return 0;
}
// Saída:
// {} R$ 0
// {paçoca} R$ 4
// {banana} R$ 3
// {banana, paçoca} R$ 7
// {granola} R$ 2
// {granola, paçoca} R$ 6
// {granola, banana} R$ 5
// {granola, banana, paçoca} R$ 9
// 15 chamadas
```

A árvore tem 1 + 2 + 4 + 8 = 15 nós, um por chamada: em geral, 2ⁿ⁺¹ - 1
chamadas e 2ⁿ folhas. Cada folha gasta até `n` passos para mostrar a cesta: o
custo é **O(n · 2ⁿ)**, e com 40 itens passa de um trilhão de subconjuntos.
Enumerar tudo só serve para `n` pequeno. O fluxograma não tem laço: quem
repete é a recursão:

{{fluxograma}}

> [!WARNING]
> No jeito por bits, `m & (1 << i)` não dá 1 quando o bit está ligado: dá o
> próprio `1 << i` (1, 2, 4, 8...). Com `== 1`, só o item 0 é reconhecido.
> Teste `if (m & (1 << i))`, com os parênteses: o `==` é avaliado antes do `&`.

> [!TIP]
> **Por dentro do C:** a pilha nunca passa de `n + 1` frames (aqui, 4), mesmo
> com 15 chamadas. Com `int`, `1 << i` só vale até `i = 30`; para mais itens,
> use `1ULL << i`.

> [!NOTE]
> **Pergunta para você:** com um quarto complemento, leite em pó (R$ 1), no
> fim da lista, quantas linhas o programa mostra e quantas chamadas faz? Qual
> é a segunda linha da saída?

{{pratique}}
