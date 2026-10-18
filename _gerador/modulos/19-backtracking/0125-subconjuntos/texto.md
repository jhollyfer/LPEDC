## 0125 · Subconjuntos

Fila do açaí. A moça do caixa avisa: além da base, você pode pôr qualquer
combinação dos três complementos do dia, granola (R$ 2), banana (R$ 3) e
paçoca (R$ 4). Pode ser nenhum, um, dois ou os três. Quantos copos diferentes
dá para montar, e quanto custa cada um?

Cada complemento é uma decisão de sim ou não. Três decisões independentes dão
2 × 2 × 2 = **8** copos. Cada copo é um **subconjunto** do conjunto
{granola, banana, paçoca}, e a lista de todos eles é o **conjunto das
partes**. Com `n` itens, são **2ⁿ** subconjuntos, contando o vazio e o
conjunto inteiro.

Gerar todos sem esquecer nenhum e sem repetir é **enumerar**. O jeito mais
limpo é a recursão (assunto 0032): a função `gera(i, k)` cuida do item `i` e
abre dois caminhos. No primeiro, o item fica **de fora** e ela chama
`gera(i + 1, ...)`. No segundo, o item **entra** e ela chama `gera(i + 1, ...)`
de novo. Quando `i` chega a `n`, todas as decisões foram tomadas: é hora de
mostrar o subconjunto.

Os itens escolhidos vão para o vetor `cesta`, e `k` diz quantos lugares dele
estão ocupados. Como `k` é **parâmetro**, cada chamada tem a sua cópia. Quando
uma chamada termina e a de cima continua, o `k` de cima ainda vale o que valia
antes: a escolha se **desfaz sozinha**. Essa ideia de escolher, descer e
desfazer é a espinha de todo o módulo.

Existe um segundo jeito, sem recursão: os bits de um número (assunto 0065).
Conte `m` de 0 a 2ⁿ - 1 e leia o bit `i` de `m` como "o item `i` entra". O
número 5 é `101` em binário: bits 0 e 2 ligados, granola e paçoca.

```c
for (int m = 0; m < (1 << N); m++)      // 1 << 3 vale 8
    for (int i = 0; i < N; i++)
        if (m & (1 << i)) { /* o item i está no subconjunto m */ }
```

Vamos ver na prática. Cada nível da árvore de decisões é um complemento. O
ramo da esquerda deixa o item de fora; o da direita põe. As 8 folhas são os 8
copos, na mesma ordem em que o programa vai mostrar:

{{ideia}}

O programa segue a árvore da esquerda para a direita e conta as chamadas:

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

Por que 15 chamadas? A árvore tem 1 + 2 + 4 + 8 = 15 nós, e cada nó é uma
chamada de `gera`. Em geral, são 2ⁿ⁺¹ - 1 chamadas e 2ⁿ folhas. Cada folha
ainda gasta até `n` passos para mostrar a cesta, então o custo total é
**O(n · 2ⁿ)**. Com 20 itens já são mais de um milhão de subconjuntos; com 40,
mais de um trilhão. Enumerar tudo só serve para `n` pequeno.

Repara no fluxograma: não há laço nenhum. Quem "repete" é a recursão, que
chama `gera` duas vezes por nó, uma por caminho:

{{fluxograma}}

> [!WARNING]
> No jeito por bits, o erro clássico é testar `if ((m & (1 << i)) == 1)`. A
> conta `m & (1 << i)` não dá 1 quando o bit está ligado: dá o próprio
> `1 << i`, que vale 1, 2, 4, 8... Com `== 1`, só o item 0 é reconhecido e os
> outros nunca entram. Teste só se o resultado é diferente de zero:
> `if (m & (1 << i))`. E sem os parênteses, `m & 1 << i == 1` nem faz o que
> parece, porque o `==` é feito antes do `&`.

> [!TIP]
> **Por dentro do C:** a pilha de chamadas nunca passa de `n + 1` frames
> (aqui, 4), mesmo com 15 chamadas no total: a recursão desce, volta e desce
> de novo pelo mesmo espaço. O vetor `cesta` é global e um só para todo mundo;
> o que muda de frame para frame é o `k`, guardado em cada frame. Depois de
> voltar, os lugares de `cesta` a partir de `k` ficam com lixo das escolhas
> antigas, e tudo bem: ninguém lê além de `k`, e a próxima escolha escreve por
> cima. No jeito por bits, `1 << i` com `int` só vale até `i = 30`; para mais
> itens, use `unsigned long long` e `1ULL << i`.

> [!NOTE]
> **Pergunta para você:** se a moça acrescentar um quarto complemento, leite
> em pó (R$ 1), no fim da lista, quantas linhas o programa mostra e quantas
> chamadas faz? Qual é a segunda linha da saída?

{{pratique}}
