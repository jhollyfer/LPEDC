## 0125 · Subconjuntos

Muitos problemas se resolvem testando todas as possibilidades: todas as
combinações de itens que cabem num orçamento, todas as escalas de plantão,
todas as jogadas. Para isso, você precisa de um jeito de gerar cada
possibilidade uma vez, sem esquecer nenhuma e sem repetir. Este módulo começa
pelo caso mais simples: escolher quais itens de uma lista entram.

Pense num copo de açaí com três complementos à escolha: granola, banana e
paçoca. Para cada complemento a pergunta é sim ou não, e as respostas são
independentes. Dois jeitos para a granola, vezes dois para a banana, vezes
dois para a paçoca: 2 × 2 × 2 = 8 copos. Cada copo é um **subconjunto** do
conjunto {granola, banana, paçoca}: um grupo formado por alguns dos itens, em
que a ordem não importa. Com `n` itens há **2ⁿ** subconjuntos, contando o
vazio (o copo puro) e o conjunto inteiro (o copo com tudo). A coleção de todos
eles se chama **conjunto das partes** (FEOFILOFF, 2009).

Gerar todos os casos de um problema, sem esquecer nem repetir nenhum, se chama
**enumerar** (FEOFILOFF, 2009). A enumeração fica fácil de enxergar numa
**árvore de decisões**. Cada nível da árvore decide um item. De cada nó saem
dois ramos: um deixa o item de fora, o outro o põe. Depois de `n` níveis, cada
caminho da raiz até uma folha é uma sequência completa de decisões, e as
folhas são exatamente os 2ⁿ subconjuntos (ZIVIANI, 2010, cap. 2).

A recursão do assunto 0032 percorre essa árvore. A função `gera(i, k)` cuida
do item `i` e abre os dois ramos: chama `gera(i + 1, ...)` sem o item e depois
chama de novo com o item dentro. Quando `i` chega a `n`, todas as decisões
foram tomadas, e a função mostra o subconjunto. Os itens escolhidos ficam num
vetor `cesta`, e `k` conta quantas posições dele estão ocupadas. Como `k` é
**parâmetro**, cada chamada recebe a sua cópia. Quando uma chamada termina, a
anterior continua com o `k` dela, e a escolha feita lá embaixo se desfaz
sozinha (KERNIGHAN; RITCHIE, 1989).

Há um segundo jeito, sem recursão, que usa os bits de um número inteiro
(assunto 0065). Um número de `n` bits tem exatamente 2ⁿ valores, de 0 a
2ⁿ - 1, e cada bit pode valer 0 ou 1, como cada item pode estar fora ou
dentro. Conte `m` de 0 a 2ⁿ - 1 e leia o bit `i` de `m` como "o item `i`
entra". O 5 em binário é `101`: bits 0 e 2 ligados, itens 0 e 2 dentro, ou
seja, granola e paçoca (KNUTH, 2011). O teste do bit usa `1 << i`, um 1
deslocado `i` casas para a esquerda:

```c
for (int m = 0; m < (1 << N); m++)      // 1 << 3 vale 8
    for (int i = 0; i < N; i++)
        if (m & (1 << i)) { /* o item i está no subconjunto m */ }
```

Escreva o teste como `if (m & (1 << i))`, sem comparar com nada. Se escrever
`m & 1 << i == 1`, o `==` é avaliado antes do `&`, e a conta sai outra.

Quanto custa enumerar tudo? A árvore tem 2ⁿ folhas e 2ⁿ⁺¹ - 1 nós ao todo,
então a versão recursiva faz 2ⁿ⁺¹ - 1 chamadas: 15 para três itens. Mostrar
cada subconjunto custa até `n` passos, e o total é **O(n · 2ⁿ)**. O número
dobra a cada item novo: 20 itens já dão mais de um milhão de subconjuntos, e
o método só serve para `n` pequeno (FEOFILOFF, 2009). A memória é bem menor:
a pilha guarda só os frames de um caminho da raiz até a folha, no máximo
`n + 1` ao mesmo tempo, 4 para três itens.

> [!WARNING]
> `m & (1 << i)` não dá 1 com o bit ligado: dá o próprio `1 << i`. Com `== 1`,
> só o item 0 é reconhecido. Com `int`, `1 << i` vale até `i = 30`; acima,
> use `1ULL << i`.

{{exemplo}}

Na fila do açaí há três complementos: granola (R$ 2), banana (R$ 3) e paçoca
(R$ 4). São 8 copos possíveis, as 8 folhas da árvore, na ordem em que o
programa os mostra:

{{ideia}}

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

A árvore tem 1 + 2 + 4 + 8 = 15 nós, um por chamada, e a pilha nunca passa de
4 frames. O fluxograma não tem laço: quem repete é a recursão:

{{fluxograma}}
