<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/19-backtracking/ e rode: cd _gerador && npm run gerar -->

# Módulo 19 · Enumeração e backtracking

Muito problema real não tem fórmula. Que combinação de produtos fecha o
crédito exato? Em que ordem o motoboy faz as entregas? Onde ficam as rainhas,
como sair do labirinto, que dígito vai em cada casa do sudoku? Para todos
eles, o jeito honesto é **testar as possibilidades**, com método: sem esquecer nenhuma, sem repetir nenhuma e sem perder tempo com as
que já se sabe que não servem.

O módulo começa pela **enumeração**: gerar todos os subconjuntos e todas as
permutações com recursão. Daí nasce o **backtracking**, a técnica que
constrói a solução uma escolha por vez e **volta atrás** assim que percebe que
o caminho não dá em nada. O resto do módulo aplica a mesma ideia a
problemas cada vez maiores: soma de subconjuntos, N-rainhas, labirintos,
flood fill e, no fim, um resolvedor de sudoku completo.

O problema passa a ser uma **árvore de decisões**. Cada nível é uma
escolha; cada caminho da raiz até uma folha é uma tentativa completa.
Enumerar é visitar a árvore inteira. Fazer backtracking é visitar a árvore
**podando** os galhos que não podem ter solução. Tudo o que você muda antes
de descer, você **desfaz** depois de voltar: é a regra que mais derruba
código.

## O que você vai aprender

- gerar todos os **subconjuntos** de um conjunto, pela recursão e pelos **bits** de um número
- gerar todas as **permutações** com troca, recursão e desfazer, e o vetor de **usados**
- o esqueleto do **backtracking**: caso de parada, **poda** e escolha com desfazer
- a **soma de subconjuntos** e o efeito da poda no número de chamadas
- as **N-rainhas** com vetores de colunas e diagonais, testando o ataque em O(1)
- achar um caminho num **labirinto** em matriz e pintar regiões com **flood fill**
- juntar tudo num **resolvedor de sudoku**, e acelerar a busca escolhendo a casa mais apertada

## Antes de começar

Este módulo é **recursão** do começo ao fim: revise os assuntos 0031 (pilha de
chamadas), 0032 e 0033 se ainda precisar pensar muito para seguir uma função
que chama a si mesma. Você também vai usar matrizes (0039), operadores de
bits (0065) e o vetor de `bool` de `<stdbool.h>`. O labirinto é a DFS do
assunto 0111 com a matriz no lugar do grafo, e a BFS (0110) aparece como a
ferramenta certa para o menor caminho. A pilha (0082) é a saída quando a
recursão ficaria funda demais.

Em cada função recursiva, procure três partes: em que ponto ela **para**, em
que ponto ela **poda** e em que ponto ela **escolhe e desfaz**. O fluxograma
é curto, porque cada caixa de chamada recursiva é o fluxograma inteiro de
novo. Quase todo programa conta as **chamadas**: com a poda, a saída fica
igual e o número cai. Nas árvores de decisão, amarelo é uma decisão ainda
aberta, verde é uma solução, vermelho é um galho podado e cinza é um beco
sem saída; nos tabuleiros, as casas verdes são a solução e as vermelhas, as
proibidas.

Uma convenção vale para o módulo todo: **os vetores de marcação começam e
terminam a busca do mesmo jeito**. Se, depois de um backtracking, sobrou algum
`true` que não estava lá no começo, faltou um desfazer.

Um aviso: o exercício E773 é um "ache o bug" cujo código, de propósito,
derruba o programa com estouro de pilha. O AddressSanitizer vai acusar
`stack-overflow` até você consertar.

| # | Assunto | Pasta |
| --- | --- | --- |
| [0125](#0125--subconjuntos) | Subconjuntos | [`0125-subconjuntos/`](19-backtracking/0125-subconjuntos/) |
| [0126](#0126--permutações) | Permutações | [`0126-permutacoes/`](19-backtracking/0126-permutacoes/) |
| [0127](#0127--backtracking) | Backtracking | [`0127-backtracking/`](19-backtracking/0127-backtracking/) |
| [0128](#0128--n-rainhas) | N-rainhas | [`0128-n-rainhas/`](19-backtracking/0128-n-rainhas/) |
| [0129](#0129--labirinto) | Labirinto | [`0129-labirinto/`](19-backtracking/0129-labirinto/) |
| [0130](#0130--juntando-tudo) | Juntando tudo | [`0130-juntando-tudo/`](19-backtracking/0130-juntando-tudo/) |

---

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
de novo. Quando `i` chega a `n`, todas as decisões foram tomadas e o
subconjunto é mostrado.

Os itens escolhidos vão para o vetor `cesta`, e `k` diz quantos lugares dele
estão ocupados. Como `k` é **parâmetro**, cada chamada tem a sua cópia. Quando
uma chamada termina e a de cima continua, o `k` de cima ainda vale o que valia
antes: a escolha se **desfaz sozinha**.

Existe um segundo jeito, sem recursão: os bits de um número (assunto 0065).
Conte `m` de 0 a 2ⁿ - 1 e leia o bit `i` de `m` como "o item `i` entra". O
número 5 é `101` em binário: bits 0 e 2 ligados, granola e paçoca.

```c
for (int m = 0; m < (1 << N); m++)      // 1 << 3 vale 8
    for (int i = 0; i < N; i++)
        if (m & (1 << i)) { /* o item i está no subconjunto m */ }
```

Na árvore de decisões, cada nível é um complemento. O ramo da esquerda deixa
o item de fora; o da direita põe. As 8 folhas são os 8 copos, na ordem em
que o programa os mostra:

<p align="center"><img src="19-backtracking/0125-subconjuntos/ideia.svg" alt="Diagrama da ideia: Subconjuntos" width="864"></p>

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

As 15 chamadas vêm da árvore: ela tem 1 + 2 + 4 + 8 = 15 nós, e cada nó é
uma chamada de `gera`. Em geral, são 2ⁿ⁺¹ - 1 chamadas e 2ⁿ folhas. Cada folha
ainda gasta até `n` passos para mostrar a cesta, então o custo total é
**O(n · 2ⁿ)**. Com 20 itens já são mais de um milhão de subconjuntos; com 40,
mais de um trilhão. Enumerar tudo só serve para `n` pequeno.

O fluxograma não tem laço. Quem "repete" é a recursão, que chama `gera` duas
vezes por nó, uma por caminho:

<p align="center"><img src="19-backtracking/0125-subconjuntos/fluxograma.svg" alt="Fluxograma: Subconjuntos" width="531"></p>

> [!WARNING]
> No jeito por bits, o erro clássico é testar `if ((m & (1 << i)) == 1)`. A
> conta `m & (1 << i)` não dá 1 quando o bit está ligado: dá o próprio
> `1 << i`, que vale 1, 2, 4, 8... Com `== 1`, só o item 0 é reconhecido e os
> outros nunca entram. Teste só se o resultado é diferente de zero:
> `if (m & (1 << i))`. Sem os parênteses, `m & 1 << i == 1` nem faz o que
> parece, porque o `==` é avaliado antes do `&`.

> [!TIP]
> **Por dentro do C:** a pilha de chamadas nunca passa de `n + 1` frames
> (aqui, 4), mesmo com 15 chamadas no total: a recursão desce, volta e desce
> de novo pelo mesmo espaço. O vetor `cesta` é global e um só para todo mundo;
> o que muda de frame para frame é o `k`, guardado em cada frame. Depois de
> voltar, os lugares de `cesta` a partir de `k` ficam com lixo das escolhas
> antigas, sem problema: ninguém lê além de `k`, e a próxima escolha escreve
> por cima. No jeito por bits, `1 << i` com `int` só vale até `i = 30`; para mais
> itens, use `unsigned long long` e `1ULL << i`.

> [!NOTE]
> **Pergunta para você:** se a moça acrescentar um quarto complemento, leite
> em pó (R$ 1), no fim da lista, quantas linhas o programa mostra e quantas
> chamadas faz? Qual é a segunda linha da saída?

### Hora de praticar

Arquivos em [`0125-subconjuntos/`](19-backtracking/0125-subconjuntos/).

**Exemplo A249 · Quem vai na carona: subconjuntos pelos bits**

```c
#include <stdio.h>

#define N 4

int main(void) {
    const char *amigos[N] = {"Ana", "Beto", "Caio", "Duda"};
    int cabem = 0; // grupos que cabem no carro (até 3 caronas)

    // cada número de 0 a 15 é um grupo: o bit i ligado = o amigo i vai
    // (o bit 0, da Ana, é o último dígito da direita)
    for (int m = 0; m < (1 << N); m++) {
        int pessoas = 0;
        printf("%2d = ", m);
        for (int b = N - 1; b >= 0; b--) {
            printf("%d", (m >> b) & 1);   // o número em binário, bit 3 primeiro
        }
        printf(":");
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) {           // diferente de zero = bit ligado
                printf(" %s", amigos[i]);
                pessoas++;
            }
        }
        if (pessoas == 0) {
            printf(" ninguém");
        }
        if (pessoas <= 3) {
            cabem++;
        }
        printf("\n");
    }
    printf("%d grupos possíveis, %d cabem no carro\n", 1 << N, cabem);
    return 0;
}
// Saída:
//  0 = 0000: ninguém
//  1 = 0001: Ana
//  2 = 0010: Beto
//  3 = 0011: Ana Beto
//  4 = 0100: Caio
//  5 = 0101: Ana Caio
//  6 = 0110: Beto Caio
//  7 = 0111: Ana Beto Caio
//  8 = 1000: Duda
//  9 = 1001: Ana Duda
// 10 = 1010: Beto Duda
// 11 = 1011: Ana Beto Duda
// 12 = 1100: Caio Duda
// 13 = 1101: Ana Caio Duda
// 14 = 1110: Beto Caio Duda
// 15 = 1111: Ana Beto Caio Duda
// 16 grupos possíveis, 15 cabem no carro
```

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/A249.c
```

**Exemplo A250 · Dois sabores na casquinha: só os subconjuntos de tamanho k**

```c
#include <stdio.h>

#define N 5
#define K 2

const char *sabores[N] = {"açaí", "coco", "limão", "manga", "uva"};
int escolha[K];
int total = 0;

// escolhe o sabor da posição pos da casquinha, a partir do sabor inicio
void combina(int pos, int inicio) {
    if (pos == K) {
        total++;
        printf("%2d: %s + %s\n", total, sabores[escolha[0]], sabores[escolha[1]]);
        return;
    }
    // só sabores depois do último escolhido: "coco + açaí" não aparece,
    // porque é a mesma casquinha que "açaí + coco"
    for (int s = inicio; s < N; s++) {
        escolha[pos] = s;
        combina(pos + 1, s + 1);
    }
}

int main(void) {
    combina(0, 0);
    printf("C(%d, %d) = %d casquinhas\n", N, K, total);
    return 0;
}
// Saída:
//  1: açaí + coco
//  2: açaí + limão
//  3: açaí + manga
//  4: açaí + uva
//  5: coco + limão
//  6: coco + manga
//  7: coco + uva
//  8: limão + manga
//  9: limão + uva
// 10: manga + uva
// C(5, 2) = 10 casquinhas
```

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/A250.c
```

#### Exercícios

**Exercício E745** · ★☆☆

O restaurante por quilo do trabalho tem uma marmita fixa (a carne) e três
acompanhamentos opcionais: arroz, feijão e salada. Escreva do zero um
programa que mostre todas as marmitas possíveis contando m de 0 a 7 e lendo
os bits de m (bit 0 = arroz, bit 1 = feijão, bit 2 = salada), sem recursão.


```text
Saída esperada:
0: só a carne
1: arroz
2: feijão
3: arroz feijão
4: salada
5: arroz salada
6: feijão salada
7: arroz feijão salada
```

**Dicas:**

1. Com 3 itens, o laço de fora vai de 0 até (1 << 3) - 1.
2. O item i entra quando m & (1 << i) é diferente de zero.
3. Use uma variável para saber se algum item entrou; se nenhum entrou,
   escreva "só a carne".

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/E745.c
```

**Exercício E746** · ★☆☆

No bolso há três moedas: R$ 1,00, R$ 0,50 e R$ 0,25. O programa abaixo
quer mostrar todos os valores que dá para pagar escolhendo um subconjunto
delas. Ele usa um vetor de bool, pega[i], em vez da cesta do texto, e
decide o caminho "com a moeda" ANTES do caminho "sem a moeda". Complete a
função gera nos pontos marcados (quatro linhas).


```text
Saída esperada:
R$ 1.75: 100 50 25
R$ 1.50: 100 50
R$ 1.25: 100 25
R$ 1.00: 100
R$ 0.75: 50 25
R$ 0.50: 50
R$ 0.25: 25
R$ 0.00:
```

**Dicas:**

1. Caminho 1: marque pega[i] como true e chame gera(i + 1).
2. Caminho 2: marque pega[i] como false e chame gera(i + 1) de novo.
3. Com o "com" primeiro, a ordem sai do maior valor para o menor. Por
   quê? Pense na moeda de 100: todas as escolhas com ela vêm antes.

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/E746.c
```

**Exercício E747** · ★★☆

Você tem R$ 30 de crédito na barraca da feira e quer gastar o valor exato.
Os produtos são:


```text
queijo 12   café 7   carne 18   pão 5   frutas 9   frango 14
```


Escreva um programa que teste TODOS os 64 subconjuntos (pelos bits, com
m de 0 a 63, bit 0 = queijo) e mostre os que somam exatamente 30, um por
linha, e no fim quantos são.


```text
Saída esperada:
queijo carne
café carne pão
café frutas frango
3 combinações de 64
```

**Dicas:**

1. Para cada m, some os preços dos itens cujo bit está ligado. Só depois
   de somar decida se a linha aparece.
2. Guarde os nomes e os preços em dois vetores paralelos (ou num vetor de
   structs, assunto 0061).
3. Muitos subconjuntos passam de 30 logo nos primeiros itens e
   mesmo assim são somados até o fim. No assunto 0127 você vai cortar
   esse desperdício.

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/E747.c
```

**Exercício E748** · ★★☆

Uma tia doou seis brinquedos para os sobrinhos Ana e Beto dividirem:


```text
bicicleta R$ 500   patinete R$ 300   skate R$ 250
patins R$ 200      bola R$ 150       livro R$ 100
```


O programa abaixo já mostra TODAS as 64 divisões: cada subconjunto vai
para a Ana e o resto (o complemento) vai para o Beto. Rode e veja. Depois
estenda o programa para mostrar só as divisões JUSTAS (os dois recebem o
mesmo valor) e, no fim, quantas são. Para não mostrar a mesma divisão duas
vezes (com os nomes trocados), mostre só as que dão a bicicleta para a Ana.


```text
Saída esperada:
Ana: bicicleta skate | Beto: patinete patins bola livro
Ana: bicicleta bola livro | Beto: patinete skate patins
2 divisões justas
```

**Dicas:**

1. O total dos seis é R$ 1500, então cada um precisa de R$ 750.
2. Na folha da recursão (i == N), some o valor da Ana antes de mostrar.
   Se não der 750, ou se da_ana[0] for false, volte sem mostrar.
3. Use um contador global para o total de divisões justas.

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/E748.c
```

**Exercício E749** · ★★★

Ache o bug. A pizzaria cobra à parte quatro adicionais: bacon (R$ 6),
cheddar (R$ 4), catupiry (R$ 5) e cebola (R$ 2). O programa abaixo devia
listar todas as combinações de adicionais que custam no máximo R$ 10 e
contá-las. Ele compila sem aviso e roda, mas a lista sai errada: aparecem
as 16 combinações, quase todas de graça. Ache a linha com erro, conserte e
rode de novo.


```text
Saída esperada:
R$ 0: nenhum
R$ 6: bacon
R$ 4: cheddar
R$ 10: bacon cheddar
R$ 5: catupiry
R$ 9: cheddar catupiry
R$ 2: cebola
R$ 8: bacon cebola
R$ 6: cheddar cebola
R$ 7: catupiry cebola
10 combinações até R$ 10
```

**Dicas:**

1. Acrescente um printf que mostre m & (1 << i) para m = 6. Quais valores
   aparecem quando o bit está ligado?
2. O resultado de m & (1 << i) é 0 ou o próprio 1 << i (1, 2, 4 ou 8).
   Ele só vale 1 para o bit 0.
3. Resposta esperada: o teste certo é if (m & (1 << i)), sem o == 1. Com
   ele consertado, a saída é a de cima.

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/E749.c
```

**Exercício E750** · ★★★

O pisca-pisca da varanda tem 3 lâmpadas, cada uma com seu interruptor, e
você quer testar as 8 combinações de lâmpadas acesas. Contar 000, 001,
010, 011... obriga a mexer em vários interruptores de uma vez (de 011
para 100 são três). Escreva do zero um programa que percorra as 8
combinações mexendo em UM interruptor por vez (o código de Gray), mostre
o estado (lâmpada 2 à esquerda, lâmpada 0 à direita) e diga qual
lâmpada mudou.


```text
Saída esperada:
000 começo, tudo apagado
001 liga a lâmpada 0
011 liga a lâmpada 1
010 desliga a lâmpada 0
110 liga a lâmpada 2
111 liga a lâmpada 0
101 desliga a lâmpada 1
100 desliga a lâmpada 0
```

**Dicas:**

1. O m-ésimo estado do código de Gray é g = m ^ (m >> 1). Confira no
   papel para m = 0 a 7.
2. O bit que mudou é o único ligado em anterior ^ g. Ache qual é com um
   laço que testa cada bit (assunto 0065).
3. Se o bit mudou e agora está ligado em g, a lâmpada acendeu; senão,
   apagou.
4. Também é uma
   enumeração de todos os subconjuntos de {0, 1, 2}, só que em outra ordem.

```bash
~/LPEDC/rodar 19-backtracking/0125-subconjuntos/E750.c
```

---

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
posição `i`. Para lá pode ir qualquer elemento ainda não usado, e os não
usados são os que estão em `v[i..n-1]`. Então, para cada `j` de `i` até
`n - 1`:

1. **escolhe**: troca `v[i]` com `v[j]`, levando o candidato para a posição `i`;
2. **desce**: chama `permuta(v, i + 1)` para decidir o resto;
3. **desfaz**: troca `v[i]` com `v[j]` de novo, devolvendo o vetor como
   estava antes da escolha.

Sem o passo 3, a enumeração quebra. No assunto anterior, a escolha se
desfazia sozinha porque morava num parâmetro. Aqui a escolha mexe no
**vetor**, que é um só para todas as chamadas. Se a chamada não arrumar a
bagunça antes de voltar, a próxima volta do laço de quem a chamou parte de um
vetor diferente do que esperava.

Quando `i` chega a `n`, todas as posições estão decididas e a ordem é
mostrada.

Na árvore, cada ramo do primeiro nível leva um grupo diferente para a frente
da fila; o segundo nível faz o mesmo com a segunda posição. As 6 folhas são
as 6 ordens, na sequência em que o programa as mostra:

<p align="center"><img src="19-backtracking/0126-permutacoes/ideia.svg" alt="Diagrama da ideia: Permutações" width="860"></p>

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

Na última linha, depois de tudo, o vetor voltou a ser `Rap, Samba, Forró`:
cada chamada desfez o que fez. Nas linhas 5 e 6, a troca de `Rap` com
`Forró` deixou o `Samba` no meio, então a ordem que sai **não** é a
alfabética nem a "de dicionário". Quem precisa dessa ordem usa outro jeito
(exemplo A251).

O laço do `j` abre os ramos, e cada volta dele tem o par troca e destroca em
volta da chamada recursiva:

<p align="center"><img src="19-backtracking/0126-permutacoes/fluxograma.svg" alt="Fluxograma: Permutações" width="520"></p>

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

### Hora de praticar

Arquivos em [`0126-permutacoes/`](19-backtracking/0126-permutacoes/).

**Exemplo A251 · Os anagramas de AMOR em ordem de dicionário**

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4

const char letras[N + 1] = "AMOR"; // já em ordem alfabética
char palavra[N + 1];               // a permutação sendo montada
bool usada[N];                     // usada[k]: a letra k já está na palavra?
int total = 0;

// em vez de trocar, escolhe para a posição pos a primeira letra livre,
// sempre da esquerda para a direita: a saída sai em ordem de dicionário
void anagramas(int pos) {
    if (pos == N) {
        palavra[N] = '\0';
        total++;
        printf("%s%s", palavra, total % 6 == 0 ? "\n" : " ");
        return;
    }
    for (int k = 0; k < N; k++) {
        if (usada[k]) {
            continue;              // essa letra já foi usada antes
        }
        usada[k] = true;           // escolhe
        palavra[pos] = letras[k];
        anagramas(pos + 1);        // desce
        usada[k] = false;          // desfaz (palavra[pos] é sobrescrita depois)
    }
}

int main(void) {
    anagramas(0);
    printf("%d anagramas\n", total);
    return 0;
}
// Saída:
// AMOR AMRO AOMR AORM ARMO AROM
// MAOR MARO MOAR MORA MRAO MROA
// OAMR OARM OMAR OMRA ORAM ORMA
// RAMO RAOM RMAO RMOA ROAM ROMA
// 24 anagramas
```

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/A251.c
```

**Exemplo A252 · ARARA: anagramas sem repetir quando há letras iguais**

```c
#include <stdio.h>
#include <string.h>

#define MAX 16

int conta[26];      // quantas de cada letra ainda estão disponíveis
char palavra[MAX];
int n, total = 0;

// em cada posição, tenta cada LETRA diferente uma vez só (e não cada
// cópia dela): assim os dois R de ARARA nunca geram anagramas repetidos
void gera(int pos) {
    if (pos == n) {
        palavra[n] = '\0';
        total++;
        printf("%2d: %s\n", total, palavra);
        return;
    }
    for (int c = 0; c < 26; c++) {
        if (conta[c] == 0) {
            continue;
        }
        conta[c]--;                 // escolhe uma letra c
        palavra[pos] = (char)('A' + c);
        gera(pos + 1);
        conta[c]++;                 // desfaz: devolve a letra
    }
}

int main(void) {
    const char *origem = "ARARA";
    n = (int)strlen(origem);
    for (int i = 0; i < n; i++) {
        conta[origem[i] - 'A']++;   // A: 3, R: 2
    }
    gera(0);
    // 5! / (3! · 2!) = 120 / 12 = 10: trocar os A entre si ou os R entre si
    // não muda a palavra
    printf("5! = 120 ordens das letras, mas só %d anagramas diferentes\n", total);
    return 0;
}
// Saída:
//  1: AAARR
//  2: AARAR
//  3: AARRA
//  4: ARAAR
//  5: ARARA
//  6: ARRAA
//  7: RAAAR
//  8: RAARA
//  9: RARAA
// 10: RRAAA
// 5! = 120 ordens das letras, mas só 10 anagramas diferentes
```

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/A252.c
```

#### Exercícios

**Exercício E751** · ★☆☆

Você esqueceu a senha de 3 dígitos do cadeado da mochila. Lembra só que
ela usa os dígitos 4, 7 e 9, cada um uma vez. Escreva do zero um programa
que gere todas as senhas possíveis com a recursão por trocas do texto
(troca, desce, desfaz), mostre cada uma como um número inteiro e, no fim,
a soma de todas (para conferir que nenhuma faltou nem repetiu).


```text
Saída esperada:
479
497
749
794
974
947
soma: 4440
```

**Dicas:**

1. Guarde os dígitos num vetor de int: {4, 7, 9}. A troca é a de int do
   assunto 0046.
2. Na folha, monte o número com numero = numero * 10 + v[k].
3. Por que 4440? Cada dígito aparece 2 vezes em cada casa: (4 + 7 + 9)
   × 2 × 111.

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/E751.c
```

**Exercício E752** · ★☆☆

Lia, Max e Nina vão tirar uma foto lado a lado e querem ver todas as
ordens possíveis. O programa abaixo usa o vetor usado[] (como no exemplo
A251) em vez de trocas, mas faltam três linhas dentro do laço: marcar a
pessoa como usada, colocá-la na posição pos da foto e desmarcar depois da
chamada recursiva. Complete.


```text
Saída esperada:
Lia Max Nina
Lia Nina Max
Max Lia Nina
Max Nina Lia
Nina Lia Max
Nina Max Lia
```

**Dicas:**

1. A posição pos da foto guarda o ÍNDICE da pessoa: foto[pos] = p.
2. Marque usado[p] = true antes de chamar fotos(pos + 1) e volte para
   false depois. Se esquecer de desmarcar, só a primeira linha aparece.
3. Resposta esperada: as 6 linhas acima (repare que, ao contrário das
   trocas do texto, esta saída está em ordem alfabética).

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/E752.c
```

**Exercício E753** · ★★☆

O motoboy sai da pizzaria (local 0), entrega em quatro bairros (1 a 4) e
volta para a pizzaria. A matriz dist (em km, já no programa) diz a
distância entre cada par de locais. Gere todas as 4! = 24 ordens de
entrega, calcule o percurso de cada uma (ida, entregas e volta) e mostre a
menor distância e a PRIMEIRA ordem, na ordem em que a sua recursão gera,
que a atinge.


```text
Saída esperada:
24 rotas testadas
menor: 16 km
rota: Pizzaria -> Lagoa -> Centro -> Jardim -> Vila -> Pizzaria
```

**Dicas:**

1. Permute o vetor {1, 2, 3, 4} com trocas, como no texto. Na folha, some
   dist[0][v[0]], depois dist[v[k]][v[k + 1]] e, no fim, dist[v[3]][0].
2. Guarde a melhor rota num segundo vetor, copiando v quando achar uma
   distância MENOR (estritamente) que a melhor até agora.
3. A rota de trás para frente (Vila, Jardim, Centro, Lagoa) também dá
   16 km, mas aparece depois. Por que toda rota empata com a inversa?
4. Este é o problema do caixeiro
   viajante: com 15 bairros seriam mais de um trilhão de ordens.

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/E753.c
```

**Exercício E754** · ★★☆

Cinco atletas correm a final: Ana, Bia, Cris, Dani e Edu. O programa abaixo
conta todas as ordens de chegada (5! = 120). Mas a premiação só liga para
o PÓDIO: ouro, prata e bronze, nessa ordem. Estenda o programa para contar
os pódios possíveis e quantos deles têm a Bia (em qualquer dos três
lugares). Não gere as 120 ordens e depois filtre: pare a recursão quando
as 3 primeiras posições estiverem decididas.


```text
Saída esperada:
120 ordens de chegada
60 pódios possíveis
Bia aparece em 36
```

**Dicas:**

1. Escreva uma segunda função, podios(v, i), igual a ordens, mas com a
   folha em i == 3 em vez de i == N. Isso é um ARRANJO: 5 × 4 × 3 = 60.
2. Na folha, olhe só v[0], v[1] e v[2] para saber se a Bia está lá.
3. Confira a conta: pódios sem a Bia são 4 × 3 × 2 = 24, e 60 - 24 = 36.

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/E754.c
```

**Exercício E755** · ★★★

Ache o bug. Um mágico quer listar todas as ordens das cartas A, 2, 3 e 4
para ensaiar um truque. Devem sair 4! = 24 ordens, todas diferentes, seis
por linha. O programa compila sem aviso e roda, mas mostra menos ordens do
que devia. O erro está numa linha só. Ache, conserte e rode de novo.


```text
Saída esperada:
A234 A243 A324 A342 A432 A423
2A34 2A43 23A4 234A 243A 24A3
32A4 324A 3A24 3A42 34A2 342A
423A 42A3 432A 43A2 4A32 4A23
24 ordens
```

**Dicas:**

1. Acrescente um printf no começo de embaralha mostrando i. Algum nível é
   pulado?
2. A chamada recursiva decide a PRÓXIMA posição. Depois de escolher quem
   fica na posição i, a próxima é a i + 1, não importa de onde veio a
   carta escolhida.
3. Resposta esperada: a chamada era embaralha(v, j + 1); o certo é
   embaralha(v, i + 1). Com o erro saem só 8 ordens.

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/E755.c
```

**Exercício E756** · ★★★

Às vezes você não quer TODAS as permutações de uma vez, só a próxima
depois de uma dada, em ordem de dicionário. Escreva do zero a função


```text
bool proxima(int v[], int n)
```


que transforma v na permutação seguinte e devolve true, ou devolve false
se v já é a última (em ordem decrescente). Sem recursão. Depois use-a para
listar as permutações de {1, 2, 3} e teste os dois casos abaixo.


```text
Saída esperada:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
depois de 1 3 5 4 2 vem 1 4 2 3 5
5 4 3 2 1 é a última
```

**Dicas:**

1. Ande da direita para a esquerda e ache o maior i com v[i] < v[i + 1]
   (o "pivô"). Se não existe, v é a última. Em 1 3 5 4 2, o pivô é o 3.
2. Ache o maior j > i com v[j] > v[i] (o 4), troque v[i] com v[j] e
   inverta o trecho v[i + 1..n - 1]: 1 4 5 3 2 vira 1 4 2 3 5.
3. Para listar todas: comece da ordem crescente e use
   do { mostra(v); } while (proxima(v, n));

```bash
~/LPEDC/rodar 19-backtracking/0126-permutacoes/E756.c
```

---

## 0127 · Backtracking

Você ganhou um cartão-presente de R$ 35 da livraria do bairro, e o cartão não
dá troco: ou você gasta o valor exato, ou o resto fica perdido. Na vitrine há
um atlas (R$ 30), um mangá (R$ 20), um livro de poesia (R$ 15) e um marcador
de página (R$ 5). Que combinações fecham exatamente R$ 35?

Dá para resolver com o assunto 0125: gerar os 2⁴ = 16 subconjuntos, somar
cada um e ficar com os que dão 35. Isso desperdiça trabalho: atlas e mangá já
somam R$ 50, nenhum subconjunto que comece assim pode dar certo, e mesmo
assim a enumeração cega vai até o fim de cada um deles.

O **backtracking** (retrocesso; o Ziviani chama de **tentativa e erro**) é a
enumeração que **desiste cedo**. Ela constrói a solução uma escolha por vez,
como antes, mas a cada passo pergunta: "este começo ainda pode virar uma
solução?". Se não pode, ela nem desce: volta um passo e tenta a próxima
opção. Cortar assim um galho inteiro da árvore de decisões se chama **poda**.

O esqueleto tem três partes, e a primeira e a última você já viu:

1. **caso de parada**: a solução está completa? Mostre (ou conte) e volte;
2. **poda**: o começo já é inviável? Volte sem descer;
3. **escolha**: para cada opção, escolha, desça e **desfaça**.

Neste problema, a poda é simples: os preços são positivos, então se a soma
**passou** de 35, acrescentar mais itens só piora. E quando a soma bate
**exatamente** 35, também não precisa descer: os próximos itens só poderiam
entrar com a soma passando de 35.

Cada caixa da árvore mostra a soma até ali. O galho da
esquerda leva o item do nível, o da direita não leva. As caixas vermelhas são
podas, as verdes são soluções e as cinzas são becos sem saída (os itens
acabaram antes de a soma chegar a 35):

<p align="center"><img src="19-backtracking/0127-backtracking/ideia.svg" alt="Diagrama da ideia: Backtracking" width="858"></p>

No código, a poda é o primeiro `if` da função. A chamada que passou do alvo
começa, percebe o problema e volta na hora:

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4
#define ALVO 35

const char *itens[N] = {"atlas", "mangá", "poesia", "marcador"};
const int precos[N] = {30, 20, 15, 5}; // reais
bool leva[N];
int chamadas = 0;

// já decidiu os itens 0..i-1, que somam soma reais
void tenta(int i, int soma) {
    chamadas++;
    if (soma > ALVO) {
        return;                         // poda: passou, nada abaixo serve
    }
    if (soma == ALVO) {                 // fechou: mostra e não desce mais
        printf("R$ %d:", soma);
        for (int j = 0; j < i; j++) {
            if (leva[j]) {
                printf(" %s", itens[j]);
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;                         // acabaram os itens sem fechar
    }
    leva[i] = true;                     // tenta com o item i
    tenta(i + 1, soma + precos[i]);
    leva[i] = false;                    // volta e tenta sem ele
    tenta(i + 1, soma);
}

int main(void) {
    tenta(0, 0);
    printf("%d chamadas (sem poda seriam 31)\n", chamadas);
    return 0;
}
// Saída:
// R$ 35: atlas marcador
// R$ 35: mangá poesia
// 21 chamadas (sem poda seriam 31)
```

A árvore completa de 4 itens tem 1 + 2 + 4 + 8 + 16 = 31 nós. A poda deixou
21. Parece pouco, mas o efeito cresce com o tamanho: cada poda perto da raiz
corta um galho com metade da árvore. Com 30 itens e um alvo pequeno, são
alguns milhares de chamadas em vez de um bilhão.

As duas perguntas de cima mandam embora cedo; só quem passa por elas chega
às duas chamadas recursivas:

<p align="center"><img src="19-backtracking/0127-backtracking/fluxograma.svg" alt="Fluxograma: Backtracking" width="588"></p>

> [!WARNING]
> A ordem dos testes importa. Se o `if (i == N) return;` viesse **antes** do
> `if (soma == ALVO)`, a solução que fecha justo com o último item
> (`atlas marcador`, que chega a 35 com `i` valendo 4) seria descartada como
> "acabaram os itens", e só `mangá poesia` apareceria. Outro clássico é
> escrever a poda com `>=` no lugar de `>`: aí toda soma que bate o alvo é
> cortada antes de ser mostrada, e a saída fica vazia. A poda só pode cortar
> o que **com certeza** não leva a solução; uma poda ambiciosa demais deixa
> o programa rápido e errado.

> [!TIP]
> **Por dentro do C:** a soma viaja como **parâmetro**, então cada frame tem a
> sua e voltar desfaz a soma de graça. Já `leva[]` é global e um só: por isso
> a linha `leva[i] = false` antes do segundo caminho. O vetor ocupa `N` bytes
> e a pilha nunca passa de `N + 1` frames, mesmo quando as chamadas somam
> milhões. O custo no pior caso continua **O(2ⁿ)**: a poda não muda a ordem
> de grandeza garantida, muda o quanto da árvore você visita na prática.
> Ordenar os preços do maior para o menor, como aqui, faz a soma estourar
> mais cedo e podar mais perto da raiz.

> [!NOTE]
> **Pergunta para você:** se o cartão fosse de R$ 50, quais combinações
> sairiam? A primeira linha da saída ainda seria a do atlas?

### Hora de praticar

Arquivos em [`0127-backtracking/`](19-backtracking/0127-backtracking/).

**Exemplo A253 · Lote de 40 kg: a segunda poda, "o que falta não alcança"**

```c
#include <stdbool.h>
#include <stdio.h>

#define N 7
#define ALVO 40

const int pesos[N] = {18, 15, 12, 9, 7, 4, 2}; // caixas de doação, em kg
int resto[N + 1];   // resto[i] = soma dos pesos de i até o fim
bool leva[N];
int chamadas;

// modo 0: sem poda; 1: só "passou do alvo"; 2: as duas podas
void tenta(int i, int soma, int modo, bool mostrar) {
    chamadas++;
    if (modo >= 1 && soma > ALVO) {
        return;                       // poda 1: passou
    }
    if (modo >= 2 && soma + resto[i] < ALVO) {
        return;                       // poda 2: nem levando tudo chega
    }
    if (i == N) {
        if (soma == ALVO && mostrar) {
            printf("  40 kg:");
            for (int j = 0; j < N; j++) {
                if (leva[j]) {
                    printf(" %d", pesos[j]);
                }
            }
            printf("\n");
        }
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + pesos[i], modo, mostrar);
    leva[i] = false;
    tenta(i + 1, soma, modo, mostrar);
}

int main(void) {
    resto[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        resto[i] = resto[i + 1] + pesos[i];  // somas do fim para o começo
    }
    printf("Lotes possíveis:\n");
    tenta(0, 0, 2, true);

    const char *nomes[3] = {"sem poda", "poda 1", "podas 1 e 2"};
    for (int modo = 0; modo <= 2; modo++) {
        chamadas = 0;
        tenta(0, 0, modo, false);
        printf("%-12s %3d chamadas\n", nomes[modo], chamadas);
    }
    return 0;
}
// Saída:
// Lotes possíveis:
//   40 kg: 18 15 7
//   40 kg: 18 9 7 4 2
//   40 kg: 15 12 9 4
//   40 kg: 15 12 7 4 2
// sem poda     255 chamadas
// poda 1       193 chamadas
// podas 1 e 2   55 chamadas
```

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/A253.c
```

**Exemplo A254 · Playlist de 30 minutos: parar na primeira solução**

```c
#include <stdbool.h>
#include <stdio.h>

#define N 7
#define ALVO 30

const char *musicas[N] = {"Aquarela", "Bossa", "Ciranda", "Dengo", "Estrada", "Frevo", "Garoa"};
const int minutos[N] = {7, 4, 9, 5, 6, 3, 8};
bool toca[N];
int chamadas = 0;

// devolve true assim que acha uma playlist; o true sobe pela pilha de
// chamadas e cada nível volta na hora, sem tentar mais nada
bool procura(int i, int soma) {
    chamadas++;
    if (soma > ALVO) {
        return false;
    }
    if (soma == ALVO) {
        return true;                    // achou: toca[0..i-1] é a resposta
    }
    if (i == N) {
        return false;
    }
    toca[i] = true;
    if (procura(i + 1, soma + minutos[i])) {
        return true;                    // não desfaz: a resposta fica em toca[]
    }
    toca[i] = false;
    return procura(i + 1, soma);
}

// a mesma busca, mas conta todas as soluções em vez de parar
int conta_todas(int i, int soma) {
    chamadas++;
    if (soma > ALVO) {
        return 0;
    }
    if (soma == ALVO) {
        return 1;
    }
    if (i == N) {
        return 0;
    }
    return conta_todas(i + 1, soma + minutos[i]) + conta_todas(i + 1, soma);
}

int main(void) {
    if (procura(0, 0)) {
        printf("Primeira playlist:");
        for (int j = 0; j < N; j++) {
            if (toca[j]) {
                printf(" %s (%d)", musicas[j], minutos[j]);
            }
        }
        printf("\nachada em %d chamadas\n", chamadas);
    }
    chamadas = 0;
    int total = conta_todas(0, 0);
    printf("todas: %d playlists, %d chamadas\n", total, chamadas);
    return 0;
}
// Saída:
// Primeira playlist: Aquarela (7) Bossa (4) Dengo (5) Estrada (6) Garoa (8)
// achada em 36 chamadas
// todas: 4 playlists, 247 chamadas
```

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/A254.c
```

#### Exercícios

**Exercício E757** · ★☆☆

Para a trilha do fim de semana, a mochila tem que pesar exatamente 12 kg
(nem mais, para não cansar, nem menos, para não faltar nada). Os itens
pesam: barraca 7, comida 5, água 4, saco de dormir 3 e fogareiro 2. O
programa abaixo enumera todas as escolhas, mas ainda não poda nada: ele
mostra as soluções certas e faz 63 chamadas. Complete os dois testes do
começo da função tenta (a poda e a solução) para que ele faça só o
necessário.


```text
Saída esperada:
barraca comida
barraca saco fogareiro
comida água saco
45 chamadas
```

**Dicas:**

1. Primeiro teste: se soma passou de ALVO, volte.
2. Segundo teste: se soma é igual a ALVO, mostre leva[0..i-1] e volte.
   Esse teste precisa vir ANTES do if (i == N), senão "barraca saco
   fogareiro" (que fecha com o último item) se perde.
3. Quando tudo estiver certo, apague o bloco do if (i == N) que mostra a
   solução: com o seu segundo teste, ele vira só "return;".

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/E757.c
```

**Exercício E758** · ★☆☆

Sobrou um vão de 100 cm na estante, e você quer preenchê-lo exatamente
com caixas organizadoras. As caixas disponíveis têm larguras de 45, 35,
30, 25, 20 e 10 cm (uma de cada). Escreva do zero um backtracking que
mostre todas as combinações que dão 100 cm exatos, com a poda "passou de
100, volte", e no fim quantas são.


```text
Saída esperada:
45 35 20
45 30 25
45 25 20 10
35 30 25 10
4 combinações
```

**Dicas:**

1. Use o esqueleto do texto: tenta(i, soma), com a poda, o teste de
   solução, o teste de fim e os dois caminhos (leva e não leva).
2. Leve o item ANTES de tentar sem ele: é isso que faz o 45 aparecer
   primeiro.

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/E758.c
```

**Exercício E759** · ★★☆

A caminhonete do frete aguenta 100 kg e há cinco caixas para levar, com
47, 39, 28, 23 e 16 kg. Não dá para levar todas. Que caixas levar para
aproveitar ao máximo a carga, sem passar de 100 kg? Agora não existe um
alvo exato: o backtracking precisa guardar a MELHOR solução vista até o
momento. Escreva o programa do zero.


```text
Saída esperada:
melhor carga: 98 kg
caixas: 47 28 23
```

**Dicas:**

1. A poda continua: se a soma passou de 100, volte.
2. Em toda chamada que não foi podada, compare soma com a melhor até
   agora. Se for maior, guarde a soma e copie leva[0..i-1] para um vetor
   melhor[] (e zere melhor[i..N-1]).
3. Não pare quando achar uma carga boa: só no fim da busca você sabe que
   ela é a melhor.
4. Bônus: uma segunda poda corta os ramos em que soma + (tudo o que
   ainda falta decidir) não passa da melhor carga até agora.

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/E759.c
```

**Exercício E760** · ★★☆

Na banca, os pacotes de figurinhas vêm com quantidades diferentes: 25,
20, 15, 12, 10, 8 e 5 figurinhas (um pacote de cada). Você precisa de
exatamente 60 figurinhas para completar o álbum. O programa abaixo já
mostra todas as combinações. Estenda-o para, no fim, mostrar também a
combinação com MENOS pacotes (se houver empate, fique com a primeira
encontrada).


```text
Saída esperada:
25 20 15
25 20 10 5
25 15 12 8
25 12 10 8 5
20 15 12 8 5
menos pacotes: 25 20 15 (3 pacotes)
```

**Dicas:**

1. Passe a quantidade de pacotes escolhidos como parâmetro (k), do mesmo
   jeito que a soma: assim ela se desfaz sozinha na volta.
2. Na solução, se k for menor que o melhor até agora, copie leva[0..i-1]
   para um vetor melhor[] (e zere o resto dele).

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/E760.c
```

**Exercício E761** · ★★★

Ache o bug. No buffet a quilo, você quer montar um prato de sobremesas com
exatamente 500 g. As porções pesam: pudim 250 g, mousse 200 g, torta
150 g, gelatina 100 g e brigadeiro 50 g. Para economizar parâmetros, o
autor guardou a soma numa variável GLOBAL. O programa compila sem aviso e
roda, mas não mostra nenhuma combinação. Ache o erro, conserte (sem
transformar a soma em parâmetro) e rode de novo.


```text
Saída esperada:
pudim mousse brigadeiro
pudim torta gelatina
mousse torta gelatina brigadeiro
```

**Dicas:**

1. Mostre soma no começo de cada chamada. Depois de voltar do caminho
   "com o item", quanto ela vale?
2. Com a soma em parâmetro, voltar desfaz a escolha de graça. Global, ela
   é uma só para todas as chamadas: quem soma precisa subtrair na volta.
3. Resposta esperada: falta soma -= porcoes[i]; logo depois da primeira
   chamada recursiva (antes de tentar sem o item). Com isso, a saída é a
   de cima.

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/E761.c
```

**Exercício E762** · ★★★

Desafio da revista de passatempos: coloque um sinal + ou - antes de cada
número de 2 a 7, na sequência 1 _ 2 _ 3 _ 4 _ 5 _ 6 _ 7, para que a conta
dê 10 (o 1 é sempre positivo). Escreva do zero um backtracking que mostre
todas as soluções, tentando sempre + antes de -, e conte as chamadas da
função recursiva. Use esta poda, no começo de cada chamada: se nem
somando nem subtraindo todos os números que faltam dá para chegar a 10,
volte.


```text
Saída esperada:
1+2+3-4-5+6+7 = 10
1+2-3+4+5-6+7 = 10
1-2+3+4+5+6-7 = 10
1-2-3-4+5+6+7 = 10
4 expressões, 83 chamadas
```

**Dicas:**

1. A função tenta(k, soma) decide o sinal do número k; a primeira chamada
   é tenta(2, 1). Guarde os sinais num vetor de char.
2. Os números que faltam são k, k + 1, ..., 7. Se a distância
   abs(10 - soma) for maior que a soma deles, nenhuma escolha de sinais
   fecha a conta. Pré-calcule essas somas num vetor resto[].
3. Sem a poda seriam 127 chamadas (a árvore completa de 6 decisões).

```bash
~/LPEDC/rodar 19-backtracking/0127-backtracking/E762.c
```

---

## 0128 · N-rainhas

No clube de xadrez da praça, o desafio da semana está no quadro: pôr 4
rainhas num tabuleiro 4 × 4 sem que nenhuma ataque outra. A rainha ataca na
linha, na coluna e nas duas diagonais, até onde o tabuleiro for. Quantas
arrumações existem?

A força bruta escolheria 4 das 16 casas: 1820 jeitos, quase todos absurdos.
O primeiro corte vem de graça: duas rainhas na mesma linha se atacam, então
cada linha tem **exatamente uma** rainha. Basta decidir a coluna da rainha de
cada linha, e a solução vira um vetor `pos`, com `pos[l]` igual à coluna da
rainha da linha `l`.

O resto é backtracking: a função `rainha(l)` põe a rainha da linha `l`.
Ela tenta cada coluna `c` e **poda** as casas atacadas pelas rainhas das
linhas de cima. Se a casa está livre, marca, desce para a linha `l + 1` e,
na volta, desmarca. Se nenhuma coluna serve, a função termina, e quem a
chamou passa para a próxima coluna: é o retrocesso.

O ganho vem de testar o ataque em O(1), sem varrer as rainhas anteriores.
Cada casa `(l, c)` pertence a uma coluna e a duas diagonais, e as diagonais
têm um "endereço" fácil:

- na diagonal **↗** (sobe para a direita), `l + c` é o mesmo em todas as casas;
  vai de 0 a `2N - 2`;
- na diagonal **↘** (desce para a direita), `l - c` é o mesmo; vai de
  `-(N - 1)` a `N - 1`, então somamos `N - 1` para virar um índice válido.

Três vetores de `bool` guardam o que está ocupado: `coluna[N]`,
`diag1[2N - 1]` e `diag2[2N - 1]`. Uma casa está livre se as três posições
dela estão `false`.

O desenho mostra, à esquerda, a primeira solução que o programa acha; no
meio, o número `l + c` de cada casa; à direita, `l - c + 3`. A rainha da
linha 1, coluna 3, ocupa a diagonal ↗ número 4 e a diagonal ↘ número 1: as
casas destacadas ficam proibidas para as outras rainhas:

<p align="center"><img src="19-backtracking/0128-n-rainhas/ideia.svg" alt="Diagrama da ideia: N-rainhas" width="858"></p>

O programa mostra cada solução como um tabuleiro e conta as chamadas:

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4

int pos[N];               // pos[l] = coluna da rainha da linha l
bool coluna[N];           // coluna[c]: já tem rainha na coluna c?
bool diag1[2 * N - 1];    // diagonal ↗, índice l + c
bool diag2[2 * N - 1];    // diagonal ↘, índice l - c + N - 1
int solucoes = 0, chamadas = 0;

void mostra(void) {
    printf("Solução %d:\n", solucoes);
    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            printf(c == 0 ? "%c" : " %c", pos[l] == c ? 'R' : '.');
        }
        printf("\n");
    }
}

// as linhas 0..l-1 já têm rainha; põe a da linha l
void rainha(int l) {
    chamadas++;
    if (l == N) {
        solucoes++;
        mostra();
        return;
    }
    for (int c = 0; c < N; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + N - 1]) {
            continue;                   // poda: a casa (l, c) está atacada
        }
        pos[l] = c;                     // escolhe
        coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = true;
        rainha(l + 1);                  // desce
        coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = false; // desfaz
    }
}

int main(void) {
    rainha(0);
    printf("%d soluções, %d chamadas\n", solucoes, chamadas);
    return 0;
}
// Saída:
// Solução 1:
// . R . .
// . . . R
// R . . .
// . . R .
// Solução 2:
// . . R .
// R . . .
// . . . R
// . R . .
// 2 soluções, 17 chamadas
```

### Passo a passo

O começo da busca, até a primeira solução. "Atacada" quer dizer que a poda
cortou a casa antes de qualquer chamada:

| linha | tenta | o que acontece |
| --- | --- | --- |
| 0 | coluna 0 | livre: marca e desce |
| 1 | colunas 0 e 1 | atacadas (coluna 0; diagonal ↘ da rainha (0, 0)) |
| 1 | coluna 2 | livre: marca e desce |
| 2 | colunas 0 a 3 | todas atacadas: volta, desmarca (1, 2) |
| 1 | coluna 3 | livre: marca e desce |
| 2 | coluna 1 | livre: marca e desce |
| 3 | colunas 0 a 3 | todas atacadas: volta; na linha 2, as colunas 2 e 3 também estão atacadas, e a linha 1 já tentou tudo: volta à linha 0 |
| 0 | coluna 1 | livre: desce, e o caminho 3, 0, 2 fecha a solução 1 |

A rainha da linha 0 na coluna 0 nunca dá certo: a busca gasta 4 chamadas
(uma na linha 1, duas na linha 2, uma na linha 3) para descobrir isso, e
depois esquece o galho inteiro.

O fluxograma é o esqueleto do assunto anterior, com um laço pelas colunas no
lugar de "leva ou não leva":

<p align="center"><img src="19-backtracking/0128-n-rainhas/fluxograma.svg" alt="Fluxograma: N-rainhas" width="757"></p>

> [!WARNING]
> O índice da diagonal ↘ é `l - c + N - 1`, e não `l - c`. Para a casa
> (0, 3), `l - c` vale -3, e `diag2[-3]` escreve **fora** do vetor: o C não
> confere, o AddressSanitizer acusa e, sem ele, o programa estraga outra
> variável em silêncio. O outro erro comum é desmarcar só a coluna e esquecer
> as diagonais: o programa não trava, só acha menos soluções do que devia.

> [!TIP]
> **Por dentro do C:** os três vetores ocupam `N + 2(2N - 1)` bytes, 46 bytes
> para `N = 8`, e cada teste de ataque são três leituras de memória, em vez de
> um laço pelas rainhas anteriores. A expressão
> `coluna[c] = diag1[l + c] = diag2[...] = true` funciona porque a atribuição
> em C devolve o valor atribuído e é feita da direita para a esquerda. A
> pilha desce só `N + 1` frames. O que cresce é o número de nós da árvore,
> mas a poda é tão forte que o 8-rainhas acha as 92 soluções com 2057
> chamadas, contra 8⁸ = 16.777.216 tabuleiros da força bruta por linha.

> [!NOTE]
> **Pergunta para você:** troque `N` para 5 e para 6 antes de rodar. Quantas
> soluções você espera? O número sobe quando o tabuleiro cresce?

### Hora de praticar

Arquivos em [`0128-n-rainhas/`](19-backtracking/0128-n-rainhas/).

**Exemplo A255 · Quantas soluções de 1 a 12 rainhas: o tabuleiro em bits**

```c
#include <stdio.h>

long long chamadas;

// cada bit de um unsigned é uma coluna. cols: colunas ocupadas;
// d1 e d2: casas desta linha atacadas pelas diagonais das rainhas de cima
long long conta(int n, unsigned cols, unsigned d1, unsigned d2) {
    chamadas++;
    unsigned todas = (1u << n) - 1;   // n bits ligados
    if (cols == todas) {
        return 1;                     // uma rainha em cada coluna: solução
    }
    long long total = 0;
    unsigned livres = todas & ~(cols | d1 | d2);
    while (livres != 0) {
        unsigned bit = livres & (~livres + 1);   // o bit ligado mais baixo
        livres -= bit;
        // na linha de baixo, a diagonal ↘ ataca uma coluna à frente (<< 1)
        // e a ↙ uma coluna atrás (>> 1): basta deslocar os bits
        total += conta(n, cols | bit, ((d1 | bit) << 1) & todas, (d2 | bit) >> 1);
    }
    return total;
}

int main(void) {
    // as chamadas batem com as do texto (17 para n = 4): mesma árvore,
    // só que o teste de ataque virou uma conta de bits
    printf(" n  soluções   chamadas\n");
    for (int n = 1; n <= 12; n++) {
        chamadas = 0;
        long long s = conta(n, 0, 0, 0);
        printf("%2d  %8lld  %9lld\n", n, s, chamadas);
    }
    return 0;
}
// Saída:
//  n  soluções   chamadas
//  1         1          2
//  2         0          3
//  3         0          6
//  4         2         17
//  5        10         54
//  6         4        153
//  7        40        552
//  8        92       2057
//  9       352       8394
// 10       724      35539
// 11      2680     166926
// 12     14200     856189
```

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/A255.c
```

**Exemplo A256 · A primeira solução do 8-rainhas, sem vetores auxiliares**

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

int pos[N];
int chamadas = 0;

// a casa (l, c) é atacada por alguma rainha das linhas 0..l-1?
// custa O(l) em vez de O(1), mas não precisa de vetor nenhum além de pos
bool pode(int l, int c) {
    for (int k = 0; k < l; k++) {
        if (pos[k] == c || abs(pos[k] - c) == l - k) {
            return false;   // mesma coluna, ou mesma distância nas duas direções
        }
    }
    return true;
}

// devolve true na primeira solução: o true sobe e ninguém tenta mais nada
bool rainha(int l) {
    chamadas++;
    if (l == N) {
        return true;
    }
    for (int c = 0; c < N; c++) {
        if (pode(l, c)) {
            pos[l] = c;     // não precisa desfazer: pos[l] é sobrescrito
            if (rainha(l + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    if (rainha(0)) {
        for (int l = 0; l < N; l++) {
            for (int c = 0; c < N; c++) {
                printf(c == 0 ? "%c" : " %c", pos[l] == c ? 'R' : '.');
            }
            printf("\n");
        }
        printf("pos = {");
        for (int l = 0; l < N; l++) {
            printf(l == 0 ? "%d" : ", %d", pos[l]);
        }
        printf("}, achada em %d chamadas\n", chamadas);
    }
    return 0;
}
// Saída:
// R . . . . . . .
// . . . . R . . .
// . . . . . . . R
// . . . . . R . .
// . . R . . . . .
// . . . . . . R .
// . R . . . . . .
// . . . R . . . .
// pos = {0, 4, 7, 5, 2, 6, 1, 3}, achada em 114 chamadas
```

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/A256.c
```

#### Exercícios

**Exercício E763** · ★☆☆

Antes de resolver o tabuleiro inteiro, o clube quer um juiz: uma função


```text
bool ataca(int l1, int c1, int l2, int c2)
```


que diz se duas rainhas, nas casas (l1, c1) e (l2, c2) de um tabuleiro
8 × 8, se atacam (mesma linha, mesma coluna ou mesma diagonal). Escreva a
função do zero e teste com os seis pares do programa.


```text
Saída esperada:
(0, 0) e (3, 3): ataca
(1, 2) e (3, 1): não ataca
(2, 5) e (2, 0): ataca
(4, 1) e (1, 4): ataca
(0, 3) e (5, 3): ataca
(6, 2) e (3, 0): não ataca
```

**Dicas:**

1. Linha e coluna são comparações diretas.
2. Nas diagonais, a distância entre as linhas é igual à distância entre
   as colunas: abs(l1 - l2) == abs(c1 - c2) (abs vem de stdlib.h).
3. Outro jeito: mesma diagonal ↗ quando l1 + c1 == l2 + c2, e mesma ↘
   quando l1 - c1 == l2 - c2. Os dois jeitos dão o mesmo resultado.

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/E763.c
```

**Exercício E764** · ★☆☆

O programa abaixo resolve as 6-rainhas e mostra cada solução como o vetor
pos (a coluna da rainha de cada linha). Faltam as linhas que marcam e
desmarcam a coluna e as duas diagonais. Complete usando os índices do
texto (l + c para a diagonal ↗ e l - c + N - 1 para a ↘).


```text
Saída esperada:
1 3 5 0 2 4
2 5 1 4 0 3
3 0 4 1 5 2
4 2 0 5 3 1
4 soluções
```

**Dicas:**

1. Marcar: coluna[c], diag1[l + c] e diag2[l - c + N - 1] recebem true,
   logo antes da chamada rainha(l + 1).
2. Desmarcar: as mesmas três posições recebem false, logo depois.
3. As soluções vêm em pares espelhados: trocando cada c de
   1 3 5 0 2 4 por 5 - c, sai 4 2 0 5 3 1.

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/E764.c
```

**Exercício E765** · ★★☆

No tabuleiro 8 × 8 do clube, alguém colou a rainha da linha 0 na coluna 3,
e ela não sai mais. Quantas das 92 soluções do 8-rainhas ainda são
possíveis? Escreva o programa (pode partir do código do texto) e mostre a
primeira solução encontrada e o total.


```text
Saída esperada:
primeira: 3 0 4 7 1 6 2 5
18 soluções com a rainha em (0, 3)
```

**Dicas:**

1. Jeito simples: na linha 0, só deixe passar c == 3 (um continue a
   mais no laço).
2. Jeito melhor: marque a coluna 3 e as diagonais da casa (0, 3) no main,
   ponha pos[0] = 3 e comece a busca em rainha(1). Os dois jeitos dão o
   mesmo resultado; o segundo nem visita as outras colunas da linha 0.
3. Para mostrar só a primeira, guarde uma cópia de pos quando o contador
   de soluções passar de 0 para 1.

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/E765.c
```

**Exercício E766** · ★★☆

Na sala de prova, as carteiras formam uma grade n × n. O fiscal vai
sentar n alunos: um em cada fileira (linha) e um em cada coluna. A regra
contra cola é mais fraca que a da rainha: dois alunos de fileiras VIZINHAS
não podem estar em colunas vizinhas (aí um enxerga a prova do outro na
diagonal). Alunos em fileiras mais distantes podem estar na diagonal sem
problema.

O programa abaixo conta as soluções das n-rainhas para n = 4, 5 e 6.
Estenda-o (mudando a poda e o que for preciso) para contar as arrumações
da sala de prova e mostrar a primeira de cada n.


```text
Saída esperada:
n = 4: 2 arrumações, primeira: 1 3 0 2
n = 5: 14 arrumações, primeira: 0 2 4 1 3
n = 6: 90 arrumações, primeira: 0 2 4 1 3 5
```

**Dicas:**

1. A coluna continua proibida de repetir. As diagonais saem: o único
   teste novo compara c com pos[l - 1], e só quando l > 0.
2. "Colunas vizinhas" quer dizer abs(c - pos[l - 1]) == 1.
3. Guarde a primeira arrumação de cada n num vetor separado.

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/E766.c
```

**Exercício E767** · ★★★

Ache o bug. Este programa conta as soluções do 8-rainhas e devia mostrar
92, mas mostra 0. Ele compila sem aviso e roda sem erro do sanitizer: os
índices nunca saem dos vetores. O erro está numa linha só. Ache,
conserte e rode de novo.


```text
Saída esperada:
92 soluções
vetores limpos no fim: sim
```

**Dicas:**

1. Uma regra do backtracking: depois que a busca termina, todo vetor de
   marcação volta a ser o que era no começo (tudo false). A função limpos
   confere isso. O que ela diz antes do conserto?
2. Compare, letra por letra, a linha que marca com a linha que desmarca.
   Um índice errado no desmarcar não dá erro: só deixa uma diagonal
   marcada para sempre e libera outra que estava ocupada.
3. Resposta esperada: o desmarcar usava diag2[c - l + N - 1]; o certo é
   diag2[l - c + N - 1], o mesmo índice da marcação. Consertado, a saída é
   a de cima.

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/E767.c
```

**Exercício E768** · ★★★

O passeio do cavalo: num tabuleiro 5 × 5, o cavalo começa no canto (0, 0)
e precisa visitar as 25 casas, cada uma uma vez só, saltando em L. Escreva
do zero um backtracking que ache o primeiro passeio, numerando as casas na
ordem da visita (o canto é 1), e conte as chamadas da função recursiva.
Tente os 8 saltos sempre nesta ordem (linha, coluna):


```text
(+2, +1) (+1, +2) (-1, +2) (-2, +1) (-2, -1) (-1, -2) (+1, -2) (+2, -1)
```



```text
Saída esperada:
  1  6 15 10 21
 14  9 20  5 16
 19  2  7 22 11
  8 13 24 17  4
 25 18  3 12 23
8840 chamadas
```

**Dicas:**

1. Guarde os saltos em dois vetores, dl[8] e dc[8]. A matriz casa[5][5]
   começa com 0 (livre) e recebe o número do salto.
2. salta(l, c, k): o cavalo está em (l, c), a casa de número k. Se k é 25,
   achou. Senão, para cada salto que cai dentro do tabuleiro numa casa
   livre: numere com k + 1, desça, e se não deu certo, volte a casa para 0.
3. Pare na primeira solução devolvendo bool, como no exemplo A256. Cada
   número sai com printf("%3d", ...).
4. Resposta esperada: o tabuleiro e a contagem acima. Confira no papel
   que cada passo de k para k + 1 é mesmo um L.

```bash
~/LPEDC/rodar 19-backtracking/0128-n-rainhas/E768.c
```

---

## 0129 · Labirinto

Festa junina na fazenda, e a atração é o labirinto de milho. Você entra pelo
canto de cima e quer achar a saída, no canto de baixo. Sem mapa, você anda e,
quando dá num beco, volta até a última bifurcação e tenta outro corredor.
Para não andar em círculos, vai deixando pedrinhas pelo caminho.

Isso é backtracking numa **matriz**. O mapa é um `char lab[L][C + 1]`: `'#'`
é parede, `'.'` é corredor, `'S'` é a entrada e `'F'` é a saída. A função
`anda(l, c)` responde "dá para chegar à saída a partir da casa (l, c)?". Ela
recusa na hora as casas impossíveis: fora do mapa, parede, ou casa que já
está no caminho. Se a casa é a saída, responde que sim. Senão, **marca** a
casa com `'*'`, tenta os quatro vizinhos e, se nenhum deu certo, **desfaz** a
marca.

A diferença para os assuntos anteriores: o desfazer não volta a casa para
`'.'`, e sim para `'x'`. Uma casa da qual não se chega à saída continua sem
saída na próxima vez que a busca passar por ali, então não vale entrar de
novo. Com o `'x'`, cada casa é visitada no máximo uma vez, e a
busca custa **O(L · C)**: é a busca em profundidade (DFS) do assunto 0111,
com a matriz fazendo o papel do grafo e os quatro vizinhos fazendo o papel
das arestas.

Atenção ao `||` encadeado do código. Pelo curto-circuito (assunto
0013), assim que um vizinho devolve `true`, os seguintes nem são chamados. A
ordem das direções no `if` (direita, baixo, esquerda, cima) decide qual
caminho a busca acha primeiro.

No desenho, os números mostram a ordem dos passos do caminho encontrado. A
busca entrou primeiro no bolsão da direita, achou só becos
(vermelho) e voltou. Depois desceu pela coluna 1 até o corredor de baixo:

<p align="center"><img src="19-backtracking/0129-labirinto/ideia.svg" alt="Diagrama da ideia: Labirinto" width="858"></p>

No fim, as casas com `*` são o caminho, e as com `x` são os becos que a
busca visitou e abandonou:

```c
#include <stdbool.h>
#include <stdio.h>

#define L 6
#define C 7

char lab[L][C + 1] = {   // + 1 para o '\0' de cada linha
    "S.....#",
    "#..#..#",
    "..#.##.",
    "...##.#",
    ".#.#.##",
    "......F",
};
int chamadas = 0;

// tenta chegar à saída a partir da casa (l, c)
bool anda(int l, int c) {
    chamadas++;
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return false;                   // fora do mapa
    }
    if (lab[l][c] == 'F') {
        return true;                    // achou a saída
    }
    if (lab[l][c] != '.' && lab[l][c] != 'S') {
        return false;                   // parede, caminho atual ou beco
    }
    lab[l][c] = '*';                    // escolhe: estou passando por aqui
    if (anda(l, c + 1) || anda(l + 1, c) || anda(l, c - 1) || anda(l - 1, c)) {
        return true;                    // direita, baixo, esquerda, cima
    }
    lab[l][c] = 'x';                    // desfaz: beco sem saída
    return false;
}

int main(void) {
    if (anda(0, 0)) {
        int passos = 0;
        for (int l = 0; l < L; l++) {
            for (int c = 0; c < C; c++) {
                printf(c == 0 ? "%c" : " %c", lab[l][c]);
                passos += lab[l][c] == '*';
            }
            printf("\n");
        }
        printf("%d passos até a saída, %d chamadas\n", passos, chamadas);
    } else {
        printf("sem saída\n");
    }
    return 0;
}
// Saída:
// * * * x x x #
// # * * # x x #
// . * # . # # .
// . * * # # . #
// . # * # . # #
// . . * * * * F
// 13 passos até a saída, 41 chamadas
```

O caminho tem 13 passos, mas existe um de 11: descer direto pela coluna 1,
sem o desvio por (0, 2) e (1, 2). O backtracking acha **um** caminho, não o
**menor**. Para o menor, a ferramenta é a BFS (assunto 0110), ou um
backtracking que testa todos os caminhos (exemplo A258).

A mesma recursão, sem a saída e sem o desfazer, vira o **flood fill**
(preenchimento por inundação): a partir de uma casa, pinta todas as casas
alcançáveis. É o balde de tinta do editor de imagens, assunto do exemplo
A257.

Três perguntas mandam embora as casas impossíveis antes de qualquer
marcação, e só uma casa nova chega ao `'*'`:

<p align="center"><img src="19-backtracking/0129-labirinto/fluxograma.svg" alt="Fluxograma: Labirinto" width="700"></p>

> [!WARNING]
> Sem a marca de visitada, a busca anda em círculos. Da casa (0, 0) ela vai
> para (0, 1), que tenta a direita e o resto e, em algum momento, tenta a
> esquerda: volta para (0, 0), que tenta (0, 1) de novo, e assim para
> sempre. Não há laço infinito no código, mas a recursão não tem fim: a
> pilha estoura (*stack overflow*) e o programa morre. Marque a casa **antes**
> de chamar os vizinhos, não depois.

> [!TIP]
> **Por dentro do C:** a matriz `lab` é contínua na memória (assunto 0039):
> `lab[l][c]` fica no byte `l * (C + 1) + c` a partir do começo, e o `+ 1`
> existe porque cada linha foi escrita como uma string, com o `'\0'` no fim.
> A profundidade da recursão é o tamanho do caminho atual, que pode chegar a
> `L · C` casas. Um mapa 1000 × 1000 pede até um milhão de frames, bem mais
> que os 8 MB de pilha que o Linux costuma dar. Para mapas grandes, troque a
> recursão por uma pilha explícita de coordenadas (assunto 0082): é o mesmo
> algoritmo, com a pilha no heap.

> [!NOTE]
> **Pergunta para você:** troque a ordem das direções para baixo, direita,
> esquerda, cima. Quantos passos tem o caminho encontrado agora? Ainda
> aparece algum `x`?

### Hora de praticar

Arquivos em [`0129-labirinto/`](19-backtracking/0129-labirinto/).

**Exemplo A257 · Balde de tinta: o flood fill pinta a sala inteira**

```c
#include <stdio.h>

#define L 7
#define C 12

// a planta do apartamento: # é parede, . é piso
char planta[L][C + 1] = {
    "############",
    "#....#.....#",
    "#....#.....#",
    "#..###.#####",
    "#......#...#",
    "#####..#...#",
    "############",
};

// pinta com cor a região de piso que contém (l, c); devolve quantas casas
// pintou. Não tem saída para procurar nem nada para desfazer: a tinta fica
int pinta(int l, int c, char cor) {
    if (l < 0 || l >= L || c < 0 || c >= C || planta[l][c] != '.') {
        return 0;                    // fora, parede ou já pintada
    }
    planta[l][c] = cor;              // pintar É marcar como visitada
    return 1 + pinta(l, c + 1, cor) + pinta(l + 1, c, cor)
             + pinta(l, c - 1, cor) + pinta(l - 1, c, cor);
}

void mostra(void) {
    for (int l = 0; l < L; l++) {
        printf("%s\n", planta[l]);
    }
}

int main(void) {
    int sala = pinta(2, 2, 'o');     // um clique na sala (a cozinha, à direita,
                                     // vem junto: o corredor liga as duas)
    int quarto = pinta(4, 9, '+');   // outro clique no quarto
    mostra();
    printf("sala e cozinha: %d casas; quarto: %d casas\n", sala, quarto);
    printf("clicar de novo na sala pinta %d casas\n", pinta(2, 2, 'o'));
    return 0;
}
// Saída:
// ############
// #oooo#ooooo#
// #oooo#ooooo#
// #oo###o#####
// #oooooo#+++#
// #####oo#+++#
// ############
// sala e cozinha: 29 casas; quarto: 6 casas
// clicar de novo na sala pinta 0 casas
```

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/A257.c
```

**Exemplo A258 · Todos os caminhos da praça: desfazer de verdade para achar o menor**

```c
#include <stdio.h>

#define L 4
#define C 5

char mapa[L][C + 1] = {
    "S...#",
    ".#...",
    "...#.",
    "#...F",
};
char melhor[L][C + 1];   // cópia do mapa com o menor caminho desenhado
int caminhos = 0, menor = -1, maior = -1;

// conta TODOS os caminhos simples (sem repetir casa) até F. Na volta, a casa
// volta a ser '.': outro caminho pode passar por ela. Sem o 'x' do texto, a
// busca deixa de ser O(L · C) e vira exponencial
void anda(int l, int c, int passos) {
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return;
    }
    if (mapa[l][c] == 'F') {
        caminhos++;
        if (maior < 0 || passos > maior) {
            maior = passos;
        }
        if (menor < 0 || passos < menor) {
            menor = passos;
            for (int i = 0; i < L; i++) {
                for (int j = 0; j <= C; j++) {
                    melhor[i][j] = mapa[i][j];   // guarda o desenho
                }
            }
        }
        return;
    }
    if (mapa[l][c] != '.' && mapa[l][c] != 'S') {
        return;
    }
    char antes = mapa[l][c];
    mapa[l][c] = '*';
    anda(l, c + 1, passos + 1);
    anda(l + 1, c, passos + 1);
    anda(l, c - 1, passos + 1);
    anda(l - 1, c, passos + 1);
    mapa[l][c] = antes;              // desfaz: libera a casa
}

int main(void) {
    anda(0, 0, 0);
    printf("%d caminhos diferentes, de %d a %d passos\n", caminhos, menor, maior);
    printf("um dos menores:\n");
    for (int l = 0; l < L; l++) {
        printf("%s\n", melhor[l]);
    }
    return 0;
}
// Saída:
// 12 caminhos diferentes, de 7 a 13 passos
// um dos menores:
// ****#
// .#.**
// ...#*
// #...F
```

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/A258.c
```

#### Exercícios

**Exercício E769** · ★☆☆

No mapa do sítio, # é cerca e . é grama. A vaca está na casa (2, 3) e
anda livre pela grama, mas não pula cerca. O sitiante quer saber quantas
casas de grama ela alcança (a área do pasto dela). A função pasto abaixo
faz um flood fill, mas falta a linha que soma as casas: complete o return
com as quatro chamadas recursivas.


```text
Saída esperada:
##########
#vvvv#...#
#vvvv#...#
#vv###...#
#vv#.....#
##########
a vaca alcança 12 casas
```

**Dicas:**

1. A casa atual vale 1. Some a ela o que cada vizinho alcança: direita,
   baixo, esquerda e cima.
2. A marca 'v' é posta ANTES das chamadas, senão dois vizinhos ficariam
   se chamando para sempre.
3. Resposta esperada: o mapa e a contagem acima. O pasto da direita não
   entra: a cerca separa os dois.

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/E769.c
```

**Exercício E770** · ★☆☆

O ratinho do laboratório entra pelo canto (0, 0) de cada labirinto e o
queijo está no canto oposto, marcado com Q. Escreva do zero a função


```text
bool chega(int l, int c)
```


que diz se o rato alcança o queijo (andando para cima, baixo, esquerda e
direita, sem atravessar paredes #), e use-a nos dois labirintos do
programa. Copie o labirinto da vez para a matriz global lab antes de
chamar a função (strcpy em cada linha).


```text
Saída esperada:
labirinto 1: o rato chega ao queijo
labirinto 2: sem caminho até o queijo
```

**Dicas:**

1. É a função anda do texto, sem a marca de beco: aqui não interessa o
   caminho, só a resposta. Marque as casas visitadas com qualquer letra.
2. Recuse fora do mapa, parede e casa já visitada; aceite o Q.
3. No labirinto 2, uma parede fecha o caminho na coluna 3: confira no
   papel antes de rodar.

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/E770.c
```

**Exercício E771** · ★★☆

Na foto de satélite da fazenda, ~ é água e . é terra. Duas casas de água
são do mesmo lago quando são vizinhas na horizontal ou na vertical
(diagonal não conta). Escreva um programa que conte os lagos e mostre,
para cada um, a primeira casa encontrada (varrendo linha por linha, da
esquerda para a direita) e o tamanho.


```text
Saída esperada:
lago 1: começa em (0, 0), tamanho 5
lago 2: começa em (1, 6), tamanho 4
lago 3: começa em (2, 10), tamanho 5
lago 4: começa em (3, 1), tamanho 4
lago 5: começa em (5, 6), tamanho 1
5 lagos
```

**Dicas:**

1. Varra a matriz com dois laços. Achou um ~? É um lago novo: conte e
   chame um flood fill a partir dali.
2. O flood fill troca cada ~ do lago por outro caractere (pode ser '.') e
   devolve quantas casas trocou. Assim o mesmo lago não é contado de novo
   quando a varredura passar pelas outras casas dele.
3. É a contagem de componentes conexos do assunto 0111, com a matriz no
   lugar do grafo.

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/E771.c
```

**Exercício E772** · ★★☆

O robô aspirador precisa ir da base (S) até a tomada (F), e o programa
abaixo já acha um caminho e desenha a planta com ele marcado. Mas o robô não
entende desenho: ele precisa da lista de casas, na ordem. Estenda o
programa para guardar o caminho enquanto a busca anda e mostrar as
coordenadas, da base até a tomada, e o número de passos.


```text
Saída esperada:
* * # . . .
. * # . # .
. * * * # .
# # # * * *
. . . . # F
caminho: (0,0) (0,1) (1,1) (2,1) (2,2) (2,3) (3,3) (3,4) (3,5) (4,5)
9 passos
```

**Dicas:**

1. Acrescente um parâmetro k em anda: é a posição da casa (l, c) no
   caminho. A base é a posição 0. Quem chama os vizinhos passa k + 1.
2. Guarde a casa em dois vetores globais, cl[k] = l e cc[k] = c, logo
   quando ela for marcada com '*'. Ao chegar na tomada, guarde-a também e
   anote o tamanho (k + 1 casas, k passos).
3. Não precisa apagar nada na volta: quando a busca recua e tenta outro
   vizinho, ele escreve por cima da mesma posição k.

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/E772.c
```

**Exercício E773** · ★★★

Ache o bug. Este é o balde de tinta de um editor de pixel art: balde(l, c,
nova) troca pela cor nova toda a região da cor que está em (l, c). O
primeiro clique funciona. O segundo, que pinta a mesma região com a MESMA
cor que ela já tem, derruba o programa: o AddressSanitizer acusa
stack-overflow. (Este erro é de propósito: rode, veja a falha, conserte e
rode de novo.)


```text
Saída esperada:
1º clique: 9 pixels
..oo....
.oooo.##
..oo..##
..o.....
2º clique: 0 pixels
3º clique: 4 pixels
..oo....
.oooo.++
..oo..++
..o.....
```

**Dicas:**

1. Siga o 2º clique no papel: velha e nova são 'o'. A casa (1, 2) é
   pintada de 'o'... e continua sendo da cor velha. O que acontece quando
   o vizinho volta a ela?
2. No flood fill, pintar é o que marca a casa como visitada. Se a cor
   nova é igual à velha, a marca não marca nada.
3. Resposta esperada: em balde, antes de começar, se velha == nova,
   devolva 0 (não há nada a fazer). Consertado, a saída é a de cima.

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/E773.c
```

**Exercício E774** · ★★★

O entregador quer o MENOR caminho da loja (S) até o cliente (F) no mapa
do condomínio. O backtracking do texto acha um caminho qualquer; aqui
você vai testar todos, com o "desfazer" do exemplo A258 (a casa volta a
'.' na volta), e podar com o melhor resultado conhecido: se o caminho
atual já tem tantos passos quanto o menor achado até agora, volte. Escreva
do zero, tentando os vizinhos na ordem direita, baixo, esquerda, cima, e
conte as chamadas da função recursiva.


```text
Saída esperada:
menor caminho: 9 passos
******
.##.#*
.....*
.#.##*
...#.F
177 chamadas
```

**Dicas:**

1. anda(l, c, passos): o primeiro teste da função é a poda,
   passos >= menor. Comece menor com um valor maior que qualquer caminho
   possível (L * C + 1 serve).
2. Ao chegar em F, a poda garante que passos < menor: atualize menor e
   copie o mapa inteiro (com os '*') para uma matriz melhor.
3. Sem a poda, testando todos os caminhos e comparando só na chegada,
   seriam 449 chamadas, e a diferença cresce muito com o mapa. Mesmo
   assim, para menor caminho em mapa grande, a BFS (assunto 0110) é a
   ferramenta certa: O(L · C), sem retrocesso.

```bash
~/LPEDC/rodar 19-backtracking/0129-labirinto/E774.c
```

---

## 0130 · Juntando tudo

Na banca da rodoviária, a revista de passatempos traz um sudoku "difícil", e
você empaca na terceira casa. A regra é curta: completar a grade 9 × 9 com
dígitos de 1 a 9 sem repetir nenhum numa linha, numa coluna ou numa das nove
caixas 3 × 3. O computador resolve por você.

O sudoku junta o que o módulo mostrou. A grade é uma **matriz**
`int g[9][9]`, com 0 nas casas vazias. Cada casa vazia é uma decisão, como as
posições das permutações, e as opções são os dígitos de 1 a 9. A **poda** é a
regra do jogo: um dígito que já aparece na linha, na coluna ou na caixa nem é
tentado. E, como nas N-rainhas, o teste é O(1) com **vetores de marcação**:

- `na_linha[l][d]` diz se o dígito `d` já está na linha `l`;
- `na_coluna[c][d]`, o mesmo para a coluna `c`;
- `na_caixa[b][d]`, para a caixa `b`, numerada de 0 a 8 por
  `b = (l / 3) * 3 + c / 3`.

A função `resolve(k)` olha as casas na ordem de leitura (casa `k` é a linha
`k / 9`, coluna `k % 9`), pula as preenchidas e, na primeira vazia, tenta os
dígitos que passam pela poda. Para cada um: **escreve e marca**, desce para
`resolve(k + 1)`, e se lá embaixo não deu certo, **apaga e desmarca**. Se
nenhum dígito serve, devolve `false` e quem chamou tenta o próximo dígito
dele. Quando não sobra casa vazia, a grade está resolvida, e o `true` sobe
pela pilha de chamadas até o `main`, como no exemplo A254.

A primeira casa vazia é a (0, 1). A linha 0 já tem 2,
3 e 8; a coluna 1 tem 4, 9, 6, 3 e 1; a caixa 0 tem 2, 3, 6, 4 e 1. Sobram o
5 e o 7. O programa tenta o 5 primeiro, e só depois de muitos retrocessos lá
embaixo descobre que a resposta é o 7:

<p align="center"><img src="19-backtracking/0130-juntando-tudo/ideia.svg" alt="Diagrama da ideia: Juntando tudo" width="858"></p>

O programa completo, com o jogo da revista escrito como texto (`.` é casa
vazia):

```c
#include <stdbool.h>
#include <stdio.h>

int g[9][9];
bool na_linha[9][10];    // na_linha[l][d]: o dígito d já está na linha l?
bool na_coluna[9][10];
bool na_caixa[9][10];    // caixas 3 × 3 numeradas de 0 a 8
long chamadas = 0;

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
}

// resolve a partir da casa número k (0 a 80, lendo linha por linha)
bool resolve(int k) {
    chamadas++;
    while (k < 81 && g[k / 9][k % 9] != 0) {
        k++;                            // pula as casas já preenchidas
    }
    if (k == 81) {
        return true;                    // nenhuma casa vazia: resolvido
    }
    int l = k / 9, c = k % 9;
    for (int d = 1; d <= 9; d++) {
        if (na_linha[l][d] || na_coluna[c][d] || na_caixa[caixa(l, c)][d]) {
            continue;                   // poda: d já aparece
        }
        g[l][c] = d;                    // escolhe
        marca(l, c, d, true);
        if (resolve(k + 1)) {
            return true;
        }
        marca(l, c, d, false);          // desfaz
        g[l][c] = 0;
    }
    return false;                       // nenhum dígito serve: volta
}

int main(void) {
    const char *jogo[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            if (jogo[l][c] != '.') {
                g[l][c] = jogo[l][c] - '0';
                marca(l, c, g[l][c], true);
            }
        }
    }
    if (resolve(0)) {
        for (int l = 0; l < 9; l++) {
            for (int c = 0; c < 9; c++) {
                printf("%d%s", g[l][c], c == 8 ? "\n" : (c % 3 == 2 ? " | " : " "));
            }
            if (l % 3 == 2 && l < 8) {
                printf("------+-------+------\n");
            }
        }
    }
    printf("%ld chamadas\n", chamadas);
    return 0;
}
// Saída:
// 2 7 3 | 6 8 5 | 1 4 9
// 6 8 5 | 9 4 1 | 3 7 2
// 9 4 1 | 2 7 3 | 5 8 6
// ------+-------+------
// 5 2 8 | 1 6 4 | 7 9 3
// 3 9 7 | 5 2 8 | 4 6 1
// 1 6 4 | 3 9 7 | 8 2 5
// ------+-------+------
// 8 3 2 | 4 5 6 | 9 1 7
// 4 5 6 | 7 1 9 | 2 3 8
// 7 1 9 | 8 3 2 | 6 5 4
// 2999 chamadas
```

São 51 casas vazias e 2999 chamadas: cerca de 59 por casa. A força bruta
pura testaria até 9⁵¹ preenchimentos, um número com 49 algarismos. Quase
todo o ganho vem da poda, e dá para podar ainda mais escolhendo **qual** casa
preencher: começar pela casa com menos candidatos derruba as chamadas deste
mesmo jogo para 64 (exemplo A260).

O fluxograma repete o esqueleto do módulo, com a casa no lugar do item e a
regra do jogo no lugar da poda:

<p align="center"><img src="19-backtracking/0130-juntando-tudo/fluxograma.svg" alt="Fluxograma: Juntando tudo" width="767"></p>

> [!WARNING]
> No desfazer, as duas coisas precisam voltar: o `g[l][c] = 0` **e** o
> `marca(..., false)`. Esquecer o `g[l][c] = 0` parece inofensivo, porque a
> próxima tentativa escreve outro dígito por cima. Mas, se nenhum dígito
> serve, a casa fica com o último que foi tentado e, na volta, o `while` do
> começo de `resolve` passa a tratá-la como uma casa **dada**. Faça o teste:
> sem essa linha, este programa termina em 64 chamadas mostrando uma grade
> "resolvida" com três 9 seguidos na primeira linha.

> [!TIP]
> **Por dentro do C:** os três vetores de marcação ocupam 3 × 9 × 10 = 270
> bytes (o índice 0 de cada linha nunca é usado: desperdiçar um byte deixa o
> código usar o próprio dígito como índice). A grade `int g[9][9]` tem 324
> bytes, contínuos na memória. A recursão desce no máximo 52 frames, um por
> casa vazia mais o último: nada para a pilha. A conta
> `jogo[l][c] - '0'` transforma o caractere `'7'` (código 55) no número 7,
> porque os dígitos são consecutivos na tabela ASCII (assunto 0040).

> [!NOTE]
> **Pergunta para você:** apague o 5 da última casa da linha 5 (troque
> `"164.9...5"` por `"164.9...."`). O programa ainda mostra a mesma grade? O
> número de chamadas sobe ou desce? E o jogo continua com uma solução só?
> (Para responder a última, faça o exercício E778.)

### Hora de praticar

Arquivos em [`0130-juntando-tudo/`](19-backtracking/0130-juntando-tudo/).

**Exemplo A259 · Quantas grades de sudoku 4 × 4 existem?**

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4

int g[N][N];
int grades = 0;
long chamadas = 0;

// confere direto na grade, sem vetores de marcação: com N = 4, varrer a
// linha, a coluna e o bloco 2 × 2 custa só alguns passos
bool cabe(int l, int c, int d) {
    int bl = l / 2 * 2, bc = c / 2 * 2;
    for (int i = 0; i < N; i++) {
        if (g[l][i] == d || g[i][c] == d || g[bl + i / 2][bc + i % 2] == d) {
            return false;
        }
    }
    return true;
}

// preenche a casa k e CONTA as soluções: não para na primeira
void preenche(int k) {
    chamadas++;
    if (k == N * N) {
        grades++;
        if (grades == 1) {
            printf("a primeira:\n");
            for (int l = 0; l < N; l++) {
                printf("%d %d | %d %d\n", g[l][0], g[l][1], g[l][2], g[l][3]);
            }
        }
        return;
    }
    int l = k / N, c = k % N;
    for (int d = 1; d <= N; d++) {
        if (cabe(l, c, d)) {
            g[l][c] = d;
            preenche(k + 1);
            g[l][c] = 0;     // desfaz: senão cabe() enxerga um d que não existe
        }
    }
}

int main(void) {
    preenche(0);
    printf("%d grades 4 × 4 válidas, %ld chamadas\n", grades, chamadas);
    printf("com a 1ª linha fixa em 1 2 3 4: %d\n", grades / 24); // 4! trocas de dígitos
    return 0;
}
// Saída:
// a primeira:
// 1 2 | 3 4
// 3 4 | 1 2
// 2 1 | 4 3
// 4 3 | 2 1
// 288 grades 4 × 4 válidas, 2753 chamadas
// com a 1ª linha fixa em 1 2 3 4: 12
```

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/A259.c
```

**Exemplo A260 · Sudoku com heurística: começar pela casa mais apertada**

```c
#include <stdbool.h>
#include <stdio.h>

int g[9][9];
long chamadas;

// quantos dígitos cabem em (l, c); os que cabem ficam marcados em pode[]
int candidatos(int l, int c, bool pode[10]) {
    for (int d = 1; d <= 9; d++) {
        pode[d] = true;
    }
    int bl = l / 3 * 3, bc = c / 3 * 3;
    for (int i = 0; i < 9; i++) {
        pode[g[l][i]] = false;                       // linha (casa vazia
                                                     // apaga pode[0]: tanto faz)
        pode[g[i][c]] = false;                       // coluna
        pode[g[bl + i / 3][bc + i % 3]] = false;     // caixa (i de 0 a 8)
    }
    int n = 0;
    for (int d = 1; d <= 9; d++) {
        n += pode[d];
    }
    return n;
}

// em vez da próxima casa vazia na leitura, escolhe a vazia com MENOS
// candidatos: se ela tem 1, não há escolha; se tem 0, o ramo morre já
bool resolve(void) {
    chamadas++;
    int ml = -1, mc = -1, menor = 10;
    bool pode[10], melhor[10];
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            if (g[l][c] == 0) {
                int n = candidatos(l, c, pode);
                if (n < menor) {
                    menor = n;
                    ml = l;
                    mc = c;
                    for (int d = 1; d <= 9; d++) {
                        melhor[d] = pode[d];
                    }
                }
            }
        }
    }
    if (ml < 0) {
        return true;                 // nenhuma casa vazia
    }
    for (int d = 1; d <= 9; d++) {   // se menor for 0, o laço nem entra
        if (melhor[d]) {
            g[ml][mc] = d;
            if (resolve()) {
                return true;
            }
            g[ml][mc] = 0;
        }
    }
    return false;
}

int main(void) {
    const char *jogo[9] = {  // o mesmo jogo do texto (lá: 2999 chamadas)
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
        }
    }
    chamadas = 0;
    if (resolve()) {
        printf("linha do meio: ");
        for (int c = 0; c < 9; c++) {
            printf("%d", g[4][c]);
        }
        printf("\n%ld chamadas com a casa mais apertada primeiro\n", chamadas);
    }
    return 0;
}
// Saída:
// linha do meio: 397528461
// 64 chamadas com a casa mais apertada primeiro
```

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/A260.c
```

#### Exercícios

**Exercício E775** · ★☆☆

Antes de confiar num resolvedor, você precisa de um conferente. Escreva a
função


```text
bool confere(int g[9][9], char *onde, int *qual)
```


que diz se uma grade COMPLETA de sudoku está certa. Se não estiver, ela
guarda em *onde o tipo do primeiro problema ('L' linha, 'C' coluna, 'X'
caixa) e em *qual o número dele. Confira nessa ordem: todas as linhas,
depois todas as colunas, depois todas as caixas. Teste com as duas grades
do programa: a primeira é a solução do texto; na segunda, alguém trocou
dois números de lugar.


```text
Saída esperada:
grade 1: certa
grade 2: errada (coluna 0)
```

**Dicas:**

1. Para cada linha, use um vetor bool visto[10] zerado: se um dígito já
   foi visto, a linha está errada.
2. A caixa b (0 a 8) começa na linha (b / 3) * 3 e na coluna (b % 3) * 3.
   A i-ésima casa dela (i de 0 a 8) está em (+ i / 3, + i % 3).
3. Na grade 2, a troca foi dentro da linha 4: as linhas continuam certas,
   por isso o primeiro problema aparece nas colunas.

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/E775.c
```

**Exercício E776** · ★☆☆

Um aplicativo de sudoku mostra, em letra miúda, os candidatos de cada
casa vazia: os dígitos que ainda podem entrar ali. O programa abaixo tem
o jogo do texto e a função candidatos, que deve marcar em usado[] os
dígitos que já aparecem na linha, na coluna e na caixa da casa (l, c).
Falta o laço que faz essa marcação. Complete.


```text
Saída esperada:
(0, 1): 5 7
(3, 1): 2 8
(4, 0): 3
(6, 0): 7 8 9
(8, 8): 4 7 9
(3, 8): 1 2 3 4 7 8 9
```

**Dicas:**

1. Um laço só, com i de 0 a 8, marca três casas por volta: g[l][i] (a
   linha), g[i][c] (a coluna) e uma casa da caixa.
2. A caixa começa em (l / 3 * 3, c / 3 * 3); a i-ésima casa dela fica i / 3
   linhas abaixo e i % 3 colunas à direita.
3. Casas vazias valem 0 e marcam usado[0], que ninguém olha.
4. A casa (4, 0) tem candidato
   único: um humano escreveria o 3 sem chutar nada.

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/E776.c
```

**Exercício E777** · ★★☆

O caderno infantil de passatempos traz o sudoku 6 × 6: dígitos de 1 a 6,
sem repetir na linha, na coluna e em cada bloco de 2 linhas por 3 colunas.
Escreva um resolvedor para ele (pode adaptar o do texto) e resolva o jogo
abaixo, contando as chamadas da função recursiva.


```text
..2..3
1..2..
.1....
6..3..
24.6..
.6.5..
```



```text
Saída esperada:
4 5 2 | 1 6 3
1 3 6 | 2 5 4
------+------
5 1 3 | 4 2 6
6 2 4 | 3 1 5
------+------
2 4 5 | 6 3 1
3 6 1 | 5 4 2
73 chamadas
```

**Dicas:**

1. Troque os 9 por constantes: N = 6, BL = 2 (linhas do bloco) e BC = 3
   (colunas do bloco). Os vetores de marcação ficam [N][N + 1].
2. O número do bloco muda: (l / BL) * (N / BC) + c / BC. Confira no papel
   que ele vai de 0 a 5.
3. Teste os dígitos de 1 a N em ordem crescente, na ordem de leitura das
   casas, para a contagem de chamadas bater.

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/E777.c
```

**Exercício E778** · ★★☆

Um sudoku bem feito tem UMA solução só. A editora da revista quer
conferir os jogos antes de imprimir. O programa abaixo prepara e resolve
dois jogos: o do texto e o mesmo jogo sem o 5 do fim da linha 5. Estenda o
programa com uma função


```text
int conta(int k, int limite)
```


que conta as soluções a partir da casa k, mas para assim que a contagem
chegar a limite. Com limite 2, ela responde o que a editora quer saber:
1 é solução única, 2 é "mais de uma". No main, troque a chamada de
resolve por conta(0, 2) e mostre o veredito.


```text
Saída esperada:
jogo 1: solução única
jogo 2: mais de uma solução
```

**Dicas:**

1. conta é o resolve com duas mudanças: na folha (k == 81) devolve 1, e
   no laço SOMA o que cada chamada devolve, em vez de parar no primeiro
   true.
2. Depois de cada chamada, se a soma já chegou ao limite, desfaça a
   marcação e devolva. Sem isso, um jogo com milhares de soluções faria a
   busca rodar por muito tempo.
3. Não esqueça de desfazer antes de qualquer return dentro do laço: a
   grade e os vetores precisam voltar como estavam.

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/E778.c
```

**Exercício E779** · ★★★

Ache o bug. Este resolvedor recebeu um jogo novo da revista, que tem
solução, mas responde "sem solução". Ele compila sem aviso e roda sem
erro do sanitizer. O erro está numa linha que FALTA. Ache, conserte e rode
de novo.


```text
Saída esperada:
354617892
987523146
162894753
493165278
725438619
618279435
549782361
231946587
876351924
```

**Dicas:**

1. Depois que resolve(0) devolve false, mostre quantos true sobraram nos
   três vetores de marcação. Quantos deviam sobrar? (Só os das 30 casas
   dadas: 30 em cada vetor.)
2. Compare o que o programa faz antes da chamada recursiva com o que ele
   desfaz depois. Uma das duas ações não é desfeita.
3. Resposta esperada: falta marca(l, c, d, false); logo depois da chamada
   recursiva que falhou (junto do g[l][c] = 0). Sem ela, um dígito
   tentado e abandonado continua "ocupando" a linha, a coluna e a caixa, e
   a poda corta dígitos que eram a resposta.

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/E779.c
```

**Exercício E780** · ★★★

O sudoku X tem uma regra a mais: as duas diagonais grandes da grade (a
principal, de (0, 0) a (8, 8), e a secundária, de (0, 8) a (8, 0)) também
precisam ter os dígitos de 1 a 9 sem repetir. É a mistura do sudoku com as
diagonais das N-rainhas. Escreva um resolvedor de sudoku X (pode partir do
texto) e resolva o jogo abaixo, contando as chamadas da função recursiva.


```text
24.3..7.5
....7..2.
...54..3.
....8.49.
....9.2.3
8........
...6...5.
675.3.1..
.......68
```



```text
Saída esperada:
249368715
356971824
781542639
512783496
467195283
893426571
928614357
675839142
134257968
diagonais: 251796348 e 526394871
4171 chamadas
```

**Dicas:**

1. Acrescente dois vetores bool[10]: um para a diagonal principal (casas
   com l == c) e outro para a secundária (l + c == 8).
2. A poda e a marcação só mexem nesses vetores quando a casa está na
   diagonal. A casa do centro, (4, 4), está nas duas.
3. Teste os dígitos de 1 a 9 em ordem crescente, na ordem de leitura das
   casas, para a contagem de chamadas bater.
4. Este jogo depende da regra nova: sem as diagonais, ele tem mais de uma
   solução (confira com o conta do E778, se quiser).

```bash
~/LPEDC/rodar 19-backtracking/0130-juntando-tudo/E780.c
```

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu.
Eles misturam os assuntos do módulo.

**1. Amigo secreto.** Quatro amigos sorteiam o amigo secreto e ninguém pode
tirar o próprio nome. Quantos sorteios válidos existem? E com cinco amigos?

<details><summary>Resposta</summary>

São **9** com quatro e **44** com cinco. Cada sorteio é uma permutação em que
`pos[i] != i` para todo `i` (um **desarranjo**). Caminho: a permutação com
vetor de usados do exemplo A251, com uma poda a mais: na posição `i`, pule o
candidato `i`. A conta direta é 4! · (1 - 1 + 1/2 - 1/6 + 1/24) = 9.

</details>

**2. O quadrado mágico.** Quantos jeitos há de escolher três números
diferentes de 1 a 9 que somam 15 (sem importar a ordem)?

<details><summary>Resposta</summary>

São **8**: {1, 5, 9}, {1, 6, 8}, {2, 4, 9}, {2, 5, 8}, {2, 6, 7}, {3, 4, 8},
{3, 5, 7} e {4, 5, 6}. São exatamente as 3 linhas, as 3 colunas e as 2
diagonais do quadrado mágico 3 × 3. Caminho: combinações de 3 com o
`inicio` do exemplo A250 e a poda "passou de 15, volte".

</details>

**3. Somando 15.** Quantos subconjuntos de {1, 2, ..., 10} somam exatamente
15? Que poda funciona quando os números estão em ordem crescente?

<details><summary>Resposta</summary>

São **20** subconjuntos. Com os números em ordem crescente, dá para podar mais
cedo que no texto: se `soma + v[i]` já passa de 15, nenhum item a partir de
`i` cabe (todos são maiores), e a função pode voltar sem tentar nem o caminho
"sem o item".

</details>

**4. Dois times de mesma soma.** As camisas de 1 a 8 precisam ser divididas
em dois times cuja soma dos números seja igual. De quantas formas?

<details><summary>Resposta</summary>

A soma total é 36, então cada time soma **18**. Há 14 subconjuntos de
{1..8} com soma 18, mas cada divisão aparece duas vezes (o time e o
complemento): **7** divisões. Caminho: o E748, fixando a camisa 1 num dos
times para não contar em dobro.

</details>

**5. BANANA.** Quantos anagramas diferentes tem a palavra BANANA? Quantas
linhas a recursão por trocas do texto mostraria?

<details><summary>Resposta</summary>

São 6! / (3! · 2!) = 720 / 12 = **60** anagramas diferentes. A recursão por
trocas não sabe que as letras iguais são iguais: mostraria as **720** ordens,
cada anagrama repetido 12 vezes. O jeito do exemplo A252, com a contagem de
cada letra, gera só os 60.

</details>

**6. Troco de R$ 1,00.** De quantas formas dá para formar R$ 1,00 com moedas
de 5, 10, 25 e 50 centavos, podendo repetir moedas? Como evitar contar
"50 + 25 + 25" e "25 + 50 + 25" como formas diferentes?

<details><summary>Resposta</summary>

São **40** formas. Para não repetir, escolha as moedas em ordem não
crescente: a função recebe o índice da maior moeda ainda permitida e só
desce para moedas iguais ou menores. É a mesma ideia do `inicio` das
combinações (A250), e o problema volta no módulo de programação dinâmica.

</details>

**7. Caminhos na praça.** Numa grade vazia 3 × 3, quantos caminhos sem
repetir casa vão de um canto ao canto oposto (andando na horizontal e na
vertical)? E numa 4 × 4?

<details><summary>Resposta</summary>

São **12** na 3 × 3 e **184** na 4 × 4 (numa 5 × 5, 8512). É o exemplo A258
sem paredes. O número explode porque, ao desmarcar a casa na volta, a busca
deixa de ser O(L · C): cada caminho diferente é visitado inteiro.

</details>

**8. Rainhas impossíveis.** Mostre, no papel, por que não existe solução das
N-rainhas para N = 2 e N = 3. E das 92 soluções do 8-rainhas, quantas têm uma
rainha em algum canto do tabuleiro?

<details><summary>Resposta</summary>

N = 2: as duas casas da linha 1 estão na coluna ou na diagonal da rainha da
linha 0. N = 3: rainha da linha 0 no canto deixa uma casa só na linha 1, e as
duas juntas atacam a linha 2 inteira; no meio, ela ataca a linha 1 inteira. No
8-rainhas, **16** soluções têm rainha num canto. Caminho: conte as soluções
em que `pos[0]` ou `pos[7]` vale 0 ou 7.

</details>

**9. O décimo estado.** No código de Gray de 4 bits (o pisca-pisca do E750
com quatro lâmpadas), qual é o 10º estado, contando o 0000 como o 1º?

<details><summary>Resposta</summary>

O 10º estado é o de `m = 9`: `9 ^ (9 >> 1)` = `1001 ^ 0100` = **1101**. O
anterior (m = 8) é 1100, então a passagem acende a lâmpada 0.

</details>

**10. Sudoku sem chute.** No jogo do texto (assunto 0130), quantas casas vazias
têm um candidato só logo no começo? Por que preencher essas casas antes da
busca ajuda?

<details><summary>Resposta</summary>

São **2**: a (4, 0), que só aceita o 3, e a (5, 5), que só aceita o 7.
Preencher uma casa de candidato único não cria ramo nenhum na árvore, e ainda
corta candidatos das vizinhas, que às vezes ficam com um candidato só também.
A heurística do exemplo A260 faz isso naturalmente: a casa de 1 candidato é
sempre a mais apertada.

</details>

**11. Quanto tempo?** Um computador faz uns 100 milhões de chamadas
recursivas simples por segundo. Quanto tempo leva enumerar todos os
subconjuntos de 30 itens, sem poda nenhuma? E de 40?

<details><summary>Resposta</summary>

A árvore tem 2ⁿ⁺¹ - 1 nós. Com 30 itens, uns **2,1 bilhões** de chamadas:
cerca de 21 segundos. Com 40, uns **2,2 trilhões**: mais de 6 horas. Cada
item a mais dobra o tempo. Por isso a poda importa, e problemas como a
mochila ganham, no módulo 21, um método que não testa tudo.

</details>

## Lista de exercícios práticos

30 exercícios que misturam os assuntos do módulo, no ritmo da prova do PPGI. Arquivos em [`lista/`](19-backtracking/lista/); resoluções em `_respostas/19-backtracking/lista/`.

### ★☆☆ Aquecimento

**Exercício P1901** · ★☆☆ · Três sabores no pote

A sorveteria da praça tem 5 sabores: açaí, cupuaçu, tapioca, graviola e
buriti. O pote médio leva 3 sabores diferentes, e a ordem não importa
(açaí + cupuaçu + tapioca é o mesmo pote que tapioca + açaí + cupuaçu).
Escreva do zero a função recursiva combina(ini, k), que escolhe os
sabores em ordem crescente de índice: cada chamada só olha sabores a
partir de ini. Mostre todos os potes, numerados, e o total.


```text
Saída esperada:
 1: açaí cupuaçu tapioca
 2: açaí cupuaçu graviola
 3: açaí cupuaçu buriti
 4: açaí tapioca graviola
 5: açaí tapioca buriti
 6: açaí graviola buriti
 7: cupuaçu tapioca graviola
 8: cupuaçu tapioca buriti
 9: cupuaçu graviola buriti
10: tapioca graviola buriti
Total: 10 potes
```

**Dicas:**

1. Guarde os índices escolhidos num vetor esc[3]. Quando já escolheu 3,
   mostre e volte.
2. for (int i = ini; i < 5; i++) { esc[k] = i; combina(i + 1, k + 1); }.
   Começar em i + 1 é o que impede repetir o mesmo pote em outra ordem.
3. Resposta esperada: 10 potes, que é C(5, 3) = 5! / (3! 2!).

```bash
~/LPEDC/rodar 19-backtracking/lista/P1901.c
```

---

**Exercício P1902** · ★☆☆ · Cara ou coroa quatro vezes

Na pelada de domingo, o juiz tira cara (C) ou coroa (K) quatro vezes
para decidir quem escolhe o lado em cada tempo da prorrogação. Quais são
as sequências possíveis? Aqui pode repetir símbolo: é permutação COM
repetição, 2 opções em cada uma das 4 posições. O programa abaixo já
mostra cada sequência e conta; complete o corpo de sorteia(pos), que
preenche a posição pos com cada símbolo e chama a próxima.


```text
Saída esperada:
CCCC
CCCK
CCKC
CCKK
CKCC
CKCK
CKKC
CKKK
KCCC
KCCK
KCKC
KCKK
KKCC
KKCK
KKKC
KKKK
16 sequências, 6 com duas caras
```

**Dicas:**

1. Não há vetor usado[]: qualquer símbolo pode entrar em qualquer
   posição, mesmo que já tenha aparecido.
2. for (int s = 0; s < 2; s++) { seq[pos] = simbolos[s]; sorteia(pos + 1); }
3. Resposta esperada: 16 sequências (2^4), de CCCC até KKKK; 6 delas têm
   duas caras e duas coroas.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1902.c
```

---

**Exercício P1903** · ★☆☆ · Luzes que não ficam lado a lado

Na fachada da loja há 5 lâmpadas em fila. Para economizar energia e não
esquentar o letreiro, a regra é: nunca duas lâmpadas vizinhas acesas ao
mesmo tempo. Escreva do zero um backtracking que monta a fila da
esquerda para a direita, com 0 (apagada) ou 1 (acesa), e CORTA o ramo na
hora em que ia acender uma lâmpada ao lado de outra acesa. Mostre as
configurações válidas e o total.


```text
Saída esperada:
00000
00001
00010
00100
00101
01000
01001
01010
10000
10001
10010
10100
10101
Total: 13 configurações
```

**Dicas:**

1. Guarde a fila num char luz[6] com '\0' no fim. Na posição p, o 0 sempre
   pode; o 1 só pode se p == 0 ou luz[p - 1] == '0'.
2. Teste o '0' antes do '1' para a saída sair na ordem de cima.
3. Resposta esperada: 13 configurações. Com n lâmpadas, o total segue
   Fibonacci: 2, 3, 5, 8, 13...

```bash
~/LPEDC/rodar 19-backtracking/lista/P1903.c
```

---

**Exercício P1904** · ★☆☆ · Quantas vezes a função foi chamada

O programa abaixo gera os subconjuntos dos 4 ingredientes da tapioca
(queijo, coco, banana, tucumã) com a recursão "leva ou não leva". Ele já
funciona. Instrumente: conte quantas vezes gera() é chamada (contando a
primeira) e quantas chamadas chegam ao fim (as folhas), e mostre os dois
números no fim, sem mudar o resto da saída.


```text
Saída esperada:
{ queijo coco banana tucumã }
{ queijo coco banana }
{ queijo coco tucumã }
{ queijo coco }
{ queijo banana tucumã }
{ queijo banana }
{ queijo tucumã }
{ queijo }
{ coco banana tucumã }
{ coco banana }
{ coco tucumã }
{ coco }
{ banana tucumã }
{ banana }
{ tucumã }
{ }
Chamadas: 31, folhas: 16
```

**Dicas:**

1. Uma variável global chamadas++ na primeira linha de gera(); outra,
   folhas++, dentro do if (i == N).
2. A árvore de decisões tem 1 + 2 + 4 + 8 + 16 nós.
3. Resposta esperada: 31 chamadas e 16 folhas (2^(n+1) - 1 e 2^n).

```bash
~/LPEDC/rodar 19-backtracking/lista/P1904.c
```

---

**Exercício P1905** · ★☆☆ · Os sócios que sumiram da mesa

Este programa tem um erro de propósito. Ana, Bia e Caio vão sentar lado a
lado na mesa do bar, e o programa devia mostrar as 3! = 6 ordens, gerando
as permutações por trocas. Ele compila sem aviso e roda limpo, mas não
mostra ordem nenhuma: "0 ordens". Conserte a linha errada.


```text
Saída esperada:
Ana Bia Caio
Ana Caio Bia
Bia Ana Caio
Bia Caio Ana
Caio Bia Ana
Caio Ana Bia
6 ordens
```

**Dicas:**

1. Na posição k, quem pode sentar? Todos os que ainda não sentaram:
   v[k], v[k + 1], ..., v[n - 1]. Incluindo o próprio v[k].
2. O laço começa em k + 1, e aí v[k] nunca fica na posição k. Troque
   v[k] com ele mesmo também: o laço começa em k.
3. Resposta esperada: for (int i = k; i < N; i++). As 6 ordens saem
   na ordem de cima.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1905.c
```

---

**Exercício P1906** · ★☆☆ · Presidente e vice do grêmio

Quatro alunos se candidataram ao grêmio: Davi, Eva, Fábio e Gil. Um vai
ser presidente e outro vice (a ordem importa: Davi presidente com Eva
vice é diferente de Eva presidente com Davi vice). Escreva do zero um
backtracking com vetor usado[] que escolhe 2 dos 4, em ordem, e mostra
cada chapa no formato "presidente / vice", e o total.


```text
Saída esperada:
Davi / Eva
Davi / Fábio
Davi / Gil
Eva / Davi
Eva / Fábio
Eva / Gil
Fábio / Davi
Fábio / Eva
Fábio / Gil
Gil / Davi
Gil / Eva
Gil / Fábio
Total: 12 chapas
```

**Dicas:**

1. É a permutação do assunto 0126 que para na profundidade 2, não na 4.
2. if (k == 2) { mostra; return; } e, no laço, pule quem tem usado[i].
3. Resposta esperada: 12 chapas, o arranjo A(4, 2) = 4 · 3.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1906.c
```

---

**Exercício P1907** · ★☆☆ · A playlist de 30 minutos

O motorista do ônibus de turismo quer uma playlist que dure exatamente 30
minutos até a próxima parada. As músicas duram 7, 12, 5, 9, 11 e 4
minutos. Escreva a função acha(i, soma), que devolve 1 assim que achar UM
subconjunto que soma 30 (e 0 se não houver), marcando em leva[] as
músicas escolhidas. Corte o ramo quando a soma passar de 30. O main já
mostra o resultado.


```text
Saída esperada:
Playlist: 7 12 11 = 30 minutos
```

**Dicas:**

1. Caso base: soma == ALVO devolve 1; soma > ALVO ou i == N devolve 0.
2. Tente primeiro levar a música i: leva[i] = 1; if (acha(i + 1, soma +
   dur[i])) return 1; leva[i] = 0; depois tente sem ela.
3. Resposta esperada: 7 + 12 + 11 = 30. É a primeira que a ordem "leva
   antes de não levar" encontra.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1907.c
```

---

**Exercício P1908** · ★☆☆ · O fogo que pula na diagonal

No mapa de uma área de reserva, # é aceiro (faixa sem mato, o fogo não
passa) e . é mato. O fogo começa na casa (0, 0) e, com o vento, pula
também na DIAGONAL: são 8 vizinhos, não 4. Escreva do zero o flood fill
recursivo queima(l, c), que troca por * cada casa de mato alcançada.
Mostre o mapa depois do fogo e quantas casas queimaram.


```text
Saída esperada:
**#****
**#*#**
##*##**
###**#*
..#*#**
Queimadas: 20 casas
```

**Dicas:**

1. Saia logo se (l, c) está fora do mapa ou não é '.'. Senão marque '*',
   conte e chame para os 8 vizinhos.
2. Os 8 vizinhos cabem em dois laços: for dl de -1 a 1, for dc de -1 a 1,
   pulando dl == 0 && dc == 0.
3. Resposta esperada: 20 casas queimadas. Com só 4 vizinhos, o fogo
   pararia nas 4 do canto. As 2 casas de mato do canto de baixo à
   esquerda escapam mesmo com o vento.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1908.c
```

---

**Exercício P1909** · ★☆☆ · Rainhas de 1 a 9

O clube de xadrez vai pendurar um cartaz com o número de soluções das
N-rainhas para cada tamanho de tabuleiro, de 1 a 9. O programa abaixo
já tem os vetores de coluna e das duas diagonais e o laço do main. Falta
o corpo de coloca(lin, n): para cada coluna livre, marque, desça para a
próxima linha e desmarque. Monte a tabela.


```text
Saída esperada:
 N  soluções
 1  1
 2  0
 3  0
 4  2
 5  10
 6  4
 7  40
 8  92
 9  352
```

**Dicas:**

1. A diagonal "\" de (lin, col) é lin - col + n - 1; a "/" é lin + col.
   Os dois índices cabem em 0..2n-2.
2. if (lin == n) { solucoes++; return; } e, no laço, pule a coluna se
   col_ocup, d1 ou d2 estiver marcado.
3. Resposta esperada: 1, 0, 0, 2, 10, 4, 40, 92, 352. O 6 tem
   menos soluções que o 5.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1909.c
```

---

**Exercício P1910** · ★☆☆ · Três dígitos que somam 15

No kakuro da revista de passatempos, uma faixa de 3 casas precisa somar
15 com dígitos de 1 a 9, todos diferentes. Que trincas servem? Escreva do
zero um backtracking que escolhe os dígitos em ordem crescente (cada um
maior que o anterior, assim a mesma trinca não aparece duas vezes) e
corta o ramo quando a soma passa de 15. Mostre as trincas e o total.


```text
Saída esperada:
1 5 9
1 6 8
2 4 9
2 5 8
2 6 7
3 4 8
3 5 7
4 5 6
Total: 8 trincas
```

**Dicas:**

1. escolhe(menor, k, soma): tenta os dígitos d de menor a 9; se soma + d
   > 15, pode dar break (os próximos são maiores ainda).
2. Com k == 3, só mostre se soma == 15.
3. Resposta esperada: 8 trincas, de 1 5 9 até 4 5 6.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1910.c
```

### ★★☆ Para pensar

**Exercício P1911** · ★★☆ · Pintando o mapa do Norte

O professor de geografia quer pintar os 7 estados da região Norte com
só 3 cores (verde, amarelo e azul) de modo que estados com fronteira
nunca tenham a mesma cor. As fronteiras estão na matriz viz do programa
(sem contar o Mato Grosso e os outros vizinhos de fora da região). Este é
o problema da COLORAÇÃO DE GRAFO. Escreva pinta(e): tente cada cor no
estado e, pule a cor se um vizinho já pintado tem a mesma, desça para
e + 1 e desfaça. Guarde a primeira coloração achada e conte todas.


```text
Saída esperada:
Primeira coloração:
  AC: verde
  AM: amarelo
  RR: verde
  RO: azul
  PA: azul
  AP: verde
  TO: verde
Colorações com 3 cores: 48
```

**Dicas:**

1. pode(e, c): para todo v < e com viz[e][v] == 1, cor[v] != c. Os
   estados acima de e ainda não têm cor.
2. Quando e == N, some 1 no total; se for a primeira, copie cor[] para
   primeira[].
3. Resposta esperada: a primeira coloração é a de cima e há 48 jeitos
   de pintar. Repare que 48 é múltiplo de 3! = 6: trocar as cores entre
   si sempre dá outra coloração válida.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1911.c
```

---

**Exercício P1912** · ★★☆ · Quantos horários de prova?

A coordenação do curso vai marcar as provas finais de 6 disciplinas.
Duas disciplinas com algum aluno em comum não podem ter prova no mesmo
horário. Os conflitos são:


```text
Cálculo - Física      Cálculo - Álgebra     Cálculo - Programação
Física - Química      Física - Programação  Álgebra - Programação
Química - Inglês      Programação - Inglês
```


Qual é o MENOR número de horários que resolve? Escreva do zero: para k =
1, 2, 3..., tente colorir o grafo com k cores por backtracking (a cor é o
horário) e pare no primeiro k que dá certo. Mostre cada tentativa e, no
fim, a grade de horários achada.


```text
Saída esperada:
1 horário(s): não dá
2 horário(s): não dá
3 horários: dá
Horário 1: Cálculo Química
Horário 2: Física Álgebra Inglês
Horário 3: Programação
```

**Dicas:**

1. colore(v, k) devolve 1 se conseguiu pintar de v até o fim com cores 0
   a k - 1. Na primeira coloração que fecha, devolva 1 sem desfazer: a cor[]
   fica com a resposta.
2. Cálculo, Física e Programação são vizinhas duas a duas (um triângulo):
   com 2 cores não dá, e o programa tem que descobrir isso sozinho.
3. Resposta esperada: 3 horários (o número cromático do grafo é 3).

```bash
~/LPEDC/rodar 19-backtracking/lista/P1912.c
```

---

**Exercício P1913** · ★★☆ · ARARA em pedaços palíndromos

Um palíndromo se lê igual dos dois lados (ARA, ARARA, A). De quantos
jeitos dá para cortar a palavra ARARA em pedaços que sejam todos
palíndromos? Escreva do zero um backtracking: a partir da posição ini,
tente cada pedaço s[ini..fim]; se ele for palíndromo, guarde e continue
a partir de fim + 1. Mostre cada corte com os pedaços separados por | e
o total.


```text
Saída esperada:
A|R|A|R|A
A|R|ARA
A|RAR|A
ARA|R|A
ARARA
Total: 5 jeitos
```

**Dicas:**

1. eh_pal(s, i, j) compara s[i] com s[j], s[i + 1] com s[j - 1]... até
   os índices se cruzarem.
2. Guarde onde cada pedaço termina num vetor fimp[] e o número de pedaços
   em np. Quando ini == tamanho, mostre os pedaços.
3. Resposta esperada: 5 jeitos, do A|R|A|R|A até o ARARA inteiro.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1913.c
```

---

**Exercício P1914** · ★★☆ · Os anagramas de BOLO sem repetir

A permutação com usado[] gera 4! = 24 ordens para as letras de BOLO, mas
como o O aparece duas vezes, cada anagrama sai repetido. Escreva do zero
um gerador que conta quantas vezes cada letra sobra (B: 1, L: 1, O: 2) e,
em cada posição, tenta cada letra DIFERENTE que ainda tem sobra. Assim
cada anagrama sai uma vez só, em ordem alfabética.


```text
Saída esperada:
BLOO
BOLO
BOOL
LBOO
LOBO
LOOB
OBLO
OBOL
OLBO
OLOB
OOBL
OOLB
Total: 12 anagramas
```

**Dicas:**

1. Guarde as letras distintas em ordem (B, L, O) e um vetor sobra[] = {1,
   1, 2}. Escolher a letra j é sobra[j]--; desfazer é sobra[j]++.
2. Como cada letra distinta é tentada uma vez por posição, a ordem dos
   Os não importa mais.
3. Resposta esperada: 12 anagramas, que é 4! / 2!.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1914.c
```

---

**Exercício P1915** · ★★☆ · Quanto a poda economiza

O caixa da cooperativa precisa achar quais boletos somam exatamente R$
100 entre 12 boletos pendentes. O programa abaixo testa todos os 2^12
subconjuntos, sem poda, e conta as chamadas. Estenda-o: escreva
com_poda(i, soma, resto), igual a sem_poda, mas que corta o ramo em dois
casos: quando soma > ALVO (passou) e quando soma + resto < ALVO (nem
levando tudo o que falta chega lá). resto é a soma dos boletos de i em
diante. Mostre as soluções e as chamadas das duas versões.


```text
Saída esperada:
Sem poda: 50 soluções, 8191 chamadas
Com poda: 50 soluções, 745 chamadas
```

**Dicas:**

1. Calcule o resto inicial (soma de todos) no main. Ao descer para i + 1,
   o resto perde v[i], leve ou não leve o boleto.
2. Os dois cortes vêm antes do teste i == N. O teste soma == ALVO pode
   contar a solução na hora e voltar: os boletos que faltam só aumentariam
   a soma.
3. Resposta esperada: as duas acham 50 soluções; sem poda são 8191
   chamadas (2^13 - 1), com poda só 745.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1915.c
```

---

**Exercício P1916** · ★★☆ · Pacotes de pão de queijo

A padaria embala pão de queijo em pacotes de 3, 4 e 5 unidades, e pode
usar quantos pacotes de cada tamanho quiser. Uma encomenda de 15 pães
pode sair como 5 + 5 + 5, como 3 + 3 + 4 + 5 e de outros jeitos. Escreva
do zero um backtracking que lista todos os jeitos, cada um em ordem
crescente de pacote (3 + 4 + 4 + 4 e 4 + 3 + 4 + 4 são o mesmo jeito),
e o total.


```text
Saída esperada:
3 + 3 + 3 + 3 + 3
3 + 3 + 4 + 5
3 + 4 + 4 + 4
5 + 5 + 5
Total: 4 jeitos
```

**Dicas:**

1. É combinação COM repetição: escolhe(menor, falta) tenta os pacotes do
   índice menor em diante, e pode escolher o mesmo de novo (chama com
   menor = j, não j + 1).
2. Corte quando o pacote não cabe no que falta. Com falta == 0, mostre.
3. Resposta esperada: 4 jeitos.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1916.c
```

---

**Exercício P1917** · ★★☆ · Todos os caminhos até a saída

No mapa do shopping, # é parede e . é corredor. Você entra em S, no
canto de cima à esquerda, e quer chegar à saída F, no canto de baixo à
direita, andando nas 4 direções e sem passar duas vezes pela mesma casa.
O labirinto do assunto 0129 para no primeiro caminho; aqui você quer
CONTAR todos e saber o tamanho do mais curto e do mais longo. Complete
anda(l, c, passos).


```text
Saída esperada:
Caminhos: 12
Mais curto: 7 passos
Mais longo: 13 passos
```

**Dicas:**

1. Ao chegar em F, conte o caminho, atualize o menor e o maior e volte
   (não marque F).
2. Senão: saia se a casa está fora, é parede ou já foi visitada; marque,
   tente os 4 vizinhos com passos + 1 e DESMARQUE ao voltar. Sem
   desmarcar, um caminho bloqueia os outros e a conta sai menor.
3. Resposta esperada: 12 caminhos, o mais curto com 7 passos e o mais
   longo com 13.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1917.c
```

---

**Exercício P1918** · ★★☆ · A ordem das quadrilhas

No arraial da escola, 5 quadrilhas vão se apresentar: Arrasta-Pé (A),
Balancê (B), Caipira (C), Dendê (D) e Estrela (E). A organização tem
duas regras: a Arrasta-Pé vem antes da Balancê (não precisa ser logo
antes), e a Caipira e a Dendê não podem se apresentar uma logo depois da
outra, porque dividem os mesmos sanfoneiros. Escreva do zero um
backtracking que monta a ordem posição por posição e CORTA o ramo assim
que uma regra é quebrada (sem esperar a ordem ficar completa). Mostre as
5 primeiras ordens válidas e o total.


```text
Saída esperada:
ABCED
ABDEC
ACBDE
ACBED
ACEBD
Total: 36 ordens
```

**Dicas:**

1. Para a regra 1, ao pôr B numa posição, confira se A já está usado.
   Se não está, A viria depois de B: corte.
2. Para a regra 2, ao pôr C ou D na posição p > 0, olhe ordem[p - 1].
3. Resposta esperada: 36 ordens. Sem regras são 120; a regra 1 deixa 60
   e a regra 2 tira mais 24.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1918.c
```

---

**Exercício P1919** · ★★☆ · Rainhas no tabuleiro furado

O tabuleiro 6 × 6 do clube tem casas estragadas, marcadas com X, onde não
dá para pôr peça. A rainha ainda ataca POR CIMA das casas estragadas (o
furo não bloqueia o ataque). Quantas soluções das 6-rainhas sobram? O
programa abaixo é o das N-rainhas do assunto 0128, que conta 4 soluções
sem furos. Estenda-o: não coloque rainha numa casa X e mostre cada
solução que sobra como o vetor de colunas, além do total.


```text
Saída esperada:
pos = 2 5 1 4 0 3
pos = 4 2 0 5 3 1
Soluções: 2
```

**Dicas:**

1. Basta um teste a mais no laço: if (tab[lin][col] == 'X') continue;
2. Para mostrar o vetor, guarde pos[lin] = col ao colocar a rainha.
3. Resposta esperada: sobram 2 soluções.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1919.c
```

---

**Exercício P1920** · ★★☆ · O rodízio dos quatro feirantes

Quatro feirantes (1, 2, 3 e 4) dividem quatro barracas e quatro dias da
semana. A escala é uma grade 4 × 4: a linha é o dia, a coluna é a
barraca e o número é o feirante. Cada feirante aparece uma vez em cada
dia e uma vez em cada barraca. Isso é um QUADRADO LATINO, o sudoku sem os
blocos. Escreva do zero um backtracking que preenche a grade casa a casa
e conta quantas escalas existem. Mostre a primeira, o total e quantas
têm o primeiro dia na ordem 1 2 3 4.


```text
Saída esperada:
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
Escalas: 576
Com o primeiro dia 1 2 3 4: 24
```

**Dicas:**

1. Casa k vai de 0 a 15: lin = k / 4, col = k % 4. Um número pode entrar
   se não está na linha nem na coluna; dois vetores booleanos por linha e
   por coluna deixam o teste em O(1).
2. Ao fechar a grade, confira se a linha 0 é 1 2 3 4 para o segundo
   contador.
3. Resposta esperada: 576 escalas e 24 com o primeiro dia 1 2 3 4
   (576 / 4! = 24: qualquer escala vira uma dessas trocando os nomes).

```bash
~/LPEDC/rodar 19-backtracking/lista/P1920.c
```

### ★★★ Desafio

**Exercício P1921** · ★★★ · O cavalo com a regra de Warnsdorff

No passeio do cavalo, o backtracking puro tenta os 8 saltos sempre na
mesma ordem e, num tabuleiro 6 × 6, pode levar milhões de passos. Em
1823, Warnsdorff propôs uma regra simples: salte primeiro para a casa
que tem MENOS saídas livres (a casa mais "apertada", que ficaria isolada
depois). Escreva o passeio com essa regra, saindo do canto (0, 0) de um
tabuleiro 6 × 6, mantendo o backtracking para o caso de a regra errar.
Mostre o tabuleiro com a ordem de visita (1 a 36) e quantas vezes o
programa precisou voltar atrás. Empate de saídas: vale a ordem dos
saltos em dl[] e dc[].


```text
Saída esperada:
  1 10 19 26  7 12
 20 27  8 11 18 25
  9  2 31 24 13  6
 36 21 28 15 32 17
  3 30 23 34  5 14
 22 35  4 29 16 33
Voltas: 0
```

**Dicas:**

1. saidas(l, c) conta os saltos de (l, c) que caem dentro do tabuleiro
   numa casa ainda com 0.
2. Em cada casa, monte um vetor com os candidatos (até 8) e o número de
   saídas de cada um, ordene por saídas (insertion sort, estável, para
   o empate seguir a ordem dos saltos) e tente nessa ordem.
3. Ao desfazer uma casa (tab = 0), some 1 em voltas.
4. Resposta esperada: o tabuleiro de cima e 0 voltas. A regra acerta de
   primeira; sem ela (saltos sempre na ordem fixa), o mesmo programa
   volta atrás 248133 vezes.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1921.c
```

---

**Exercício P1922** · ★★★ · Palavras cruzadas 3 × 3

A revistinha de passatempos tem uma cruzadinha 3 × 3 sem casas pretas:
as 3 linhas (horizontais) e as 3 colunas (verticais) são palavras, e as
6 palavras têm que ser DIFERENTES. As palavras permitidas são:


```text
ALA AMO ARO ASA MAL MAR MAU OCA OLA RUA PAU SAL
```


Escreva do zero um backtracking que escolhe a palavra de cada linha e
poda cedo: depois de escolher a linha k, cada coluna tem k + 1 letras, e
esse começo tem que ser começo de alguma palavra da lista (senão nenhuma
escolha das linhas de baixo salva). Mostre cada grade achada (as 3
linhas, separadas por / ) e quantas vezes o programa testou uma palavra
numa linha.


```text
Saída esperada:
AMO / SAL / ALA
ASA / MAL / OLA
Palavras testadas: 120
```

**Dicas:**

1. eh_prefixo(p, tam) percorre a lista e compara as tam primeiras letras
   com strncmp.
2. Na linha 2 (a última), o começo da coluna já tem 3 letras: aí
   eh_prefixo vira "é palavra". No fim, confira que as 6 palavras são
   diferentes (3 linhas e 3 colunas).
3. Resposta esperada: 2 grades, AMO / SAL / ALA e ASA / MAL / OLA (uma é
   a outra virada: as linhas de uma são as colunas da outra).

```bash
~/LPEDC/rodar 19-backtracking/lista/P1922.c
```

---

**Exercício P1923** · ★★★ · Três programadores, carga igual

Uma software house tem 9 tarefas para a semana, com 9, 8, 7, 6, 5, 4, 3,
2 e 1 horas, e 3 programadores. O gerente quer que cada um pegue
exatamente 15 horas. Escreva do zero o backtracking da PARTIÇÃO EM k
GRUPOS: para cada tarefa, em ordem, tente pô-la no programador 0, 1 ou 2,
sem passar de 15 horas. Use duas podas: (a) a carga não passa de 15; (b)
se dois programadores estão com a mesma carga, pôr a tarefa em um ou em
outro dá na mesma, então tente só o primeiro deles. Mostre a primeira
divisão achada e quantas chamadas a recursão fez.


```text
Saída esperada:
Programador 1: 9 6 (15 h)
Programador 2: 8 7 (15 h)
Programador 3: 5 4 3 2 1 (15 h)
Chamadas: 10
```

**Dicas:**

1. distribui(i) devolve 1 quando i == 9 (todas as tarefas colocadas: como
   a soma é 45 e ninguém passa de 15, cada um ficou com 15).
2. A poda (b) é um laço que olha se algum programador anterior p2 < p
   tem carga[p2] == carga[p]; se tem, pule p. Ela evita testar as 3! = 6
   trocas de nome dos programadores.
3. Resposta esperada: 9 + 6, 8 + 7 e 5 + 4 + 3 + 2 + 1 (veja as chamadas
   na saída de cima).

```bash
~/LPEDC/rodar 19-backtracking/lista/P1923.c
```

---

**Exercício P1924** · ★★★ · SEIS + SEIS = DOZE

Na criptoaritmética, cada letra é um dígito, letras diferentes são
dígitos diferentes e nenhuma palavra começa com 0. Resolva


```text
SEIS + SEIS = DOZE
```


Escreva do zero um backtracking que atribui dígitos às 6 letras (S, E, I,
D, O, Z, nesta ordem), sem repetir dígito (vetor usado[10]), e confere a
conta quando todas têm valor. Mostre todas as soluções no formato da
saída e o total. Conte também quantas atribuições completas foram
conferidas.


```text
Saída esperada:
3643 + 3643 = 7286
4814 + 4814 = 9628
4854 + 4854 = 9708
4864 + 4864 = 9728
Soluções: 4
Atribuições conferidas: 120960
```

**Dicas:**

1. Guarde o dígito de cada letra em val[6]. Uma função valor("SEIS")
   monta o número trocando cada letra pelo seu dígito.
2. S e D não podem ser 0: corte na hora de atribuir.
3. Resposta esperada: 4 soluções e 120960 atribuições conferidas. Sem o
   corte do zero seriam 10 · 9 · 8 · 7 · 6 · 5 = 151200.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1924.c
```

---

**Exercício P1925** · ★★★ · A poda que corta demais

Este programa tem um erro de propósito. A ONG do bairro recebeu doações
de cestas básicas com 18, 14, 11, 9, 7, 5 e 3 kg e quer montar um lote de
exatamente 30 kg. O backtracking abaixo lista todos os lotes, com as
cestas em ordem decrescente e uma poda "se a cesta i não cabe, pare". Ele
compila sem aviso e roda limpo, mas acha só 1 lote. Conserte a poda sem
tirá-la: ela ainda deve cortar o ramo de LEVAR a cesta que não cabe.


```text
Saída esperada:
Lote 1: 18 9 3
Lote 2: 18 7 5
Lote 3: 14 11 5
Lote 4: 14 9 7
Lote 5: 11 9 7 3
Total: 5 lotes
```

**Dicas:**

1. Acrescente um printf no começo de busca(i, soma) e veja: quando a
   cesta de 14 não cabe junto com a de 18, o programa desiste de tudo,
   inclusive de seguir SEM a de 14 e tentar a de 11.
2. Não caber a cesta i não impede que as próximas (menores) caibam. O
   certo é pular só o ramo "levo a cesta i".
3. Resposta esperada: troque o return da poda por um if em volta do ramo
   de levar. Saem os 5 lotes de cima.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1925.c
```

---

**Exercício P1926** · ★★★ · O roteiro turístico de Manaus

Um guia quer um roteiro a pé que passe por 6 pontos de Manaus, cada um
UMA vez, saindo do Teatro Amazonas. Só há ligação direta entre alguns
pares (a matriz liga[][] do programa). Um caminho que visita todos os
vértices uma vez só é um CAMINHO HAMILTONIANO, e não se conhece jeito
rápido de achá-lo: backtracking é o caminho. Escreva roteiro(v, k), que
já está em v depois de visitar k pontos, e liste todos os roteiros, o
total e quantos terminam num ponto ligado ao Teatro (dá para voltar a pé:
um CICLO hamiltoniano).


```text
Saída esperada:
Teatro > Mercado > Palácio > MUSA > Ponta Negra > Encontro
Teatro > Mercado > Palácio > MUSA > Encontro > Ponta Negra
Teatro > Mercado > Palácio > Ponta Negra > MUSA > Encontro
Teatro > Mercado > Palácio > Ponta Negra > Encontro > MUSA (fecha)
Teatro > Mercado > Encontro > MUSA > Palácio > Ponta Negra
Teatro > Mercado > Encontro > MUSA > Ponta Negra > Palácio (fecha)
Teatro > Mercado > Encontro > Ponta Negra > Palácio > MUSA (fecha)
Teatro > Mercado > Encontro > Ponta Negra > MUSA > Palácio (fecha)
Teatro > Palácio > Mercado > Encontro > MUSA > Ponta Negra
Teatro > Palácio > Mercado > Encontro > Ponta Negra > MUSA (fecha)
Teatro > Palácio > MUSA > Ponta Negra > Encontro > Mercado (fecha)
Teatro > Palácio > Ponta Negra > MUSA > Encontro > Mercado (fecha)
Teatro > MUSA > Palácio > Mercado > Encontro > Ponta Negra
Teatro > MUSA > Palácio > Ponta Negra > Encontro > Mercado (fecha)
Teatro > MUSA > Ponta Negra > Palácio > Mercado > Encontro
Teatro > MUSA > Ponta Negra > Encontro > Mercado > Palácio (fecha)
Teatro > MUSA > Encontro > Mercado > Palácio > Ponta Negra
Teatro > MUSA > Encontro > Ponta Negra > Palácio > Mercado (fecha)
Roteiros: 18, ciclos: 10
```

**Dicas:**

1. Guarde o roteiro em rota[] e marque os visitados. Com k == N, mostre;
   se liga[v][0], conte como ciclo.
2. Para cada w com liga[v][w] e não visitado: marque, rota[k] = w, chame
   roteiro(w, k + 1), desmarque.
3. Resposta esperada: 18 roteiros, 10 deles fecham um ciclo.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1926.c
```

---

**Exercício P1927** · ★★★ · Futoshiki 4 × 4

O futoshiki é um quadrado latino 4 × 4 (1 a 4 sem repetir na linha nem
na coluna) com sinais de desigualdade entre algumas casas vizinhas, e
nenhum número dado. O jogo de hoje tem 6 sinais (linha, coluna):


```text
(0,1) < (0,0)    (2,2) < (2,3)    (1,2) < (0,2)
(1,3) < (0,3)    (3,2) < (2,2)    (2,3) < (3,3)
```


Escreva do zero o resolvedor: preencha casa a casa, como no sudoku, e,
ao pôr um número, confira só as desigualdades em que as DUAS casas já
estão preenchidas (as de casas anteriores na ordem de preenchimento).
Conte as soluções (um bom jogo tem uma só) e mostre a grade.


```text
Saída esperada:
Soluções: 1
3 1 4 2
4 2 3 1
1 4 2 3
2 3 1 4
```

**Dicas:**

1. Guarde os sinais num vetor de structs { la, ca, lb, cb }: a casa A é
   menor que a casa B. Casa vazia vale 0.
2. ok_sinais(): para cada sinal com as duas casas diferentes de 0, a
   casa A tem que ser menor. Chame depois de pôr o número.
3. Resposta esperada: 1 solução, a grade de cima.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1927.c
```

---

**Exercício P1928** · ★★★ · A próxima trinca pelos bits

O técnico do vôlei de praia escolhe 3 entre 5 jogadoras (Ana, Bia, Cris,
Dani e Eli) para um treino. Cada escolha é uma máscara de 5 bits com
exatamente 3 bits ligados (bit i = jogadora i). Em vez de recursão, use o
truque de Gosper, que salta de uma máscara direto para a PRÓXIMA maior
com o mesmo número de bits:


```text
c = x & -x;               (o bit ligado mais baixo)
r = x + c;                (soma, empurrando o bloco de 1s)
x = (((r ^ x) >> 2) / c) | r;
```


Complete proxima(x) e o laço do main, que começa em 0b00111 (7) e para
quando a máscara passa de 5 bits. Mostre cada máscara em binário (bit 4
à esquerda) e as jogadoras dela.


```text
Saída esperada:
00111: Ana Bia Cris
01011: Ana Bia Dani
01101: Ana Cris Dani
01110: Bia Cris Dani
10011: Ana Bia Eli
10101: Ana Cris Eli
10110: Bia Cris Eli
11001: Ana Dani Eli
11010: Bia Dani Eli
11100: Cris Dani Eli
Total: 10 trincas
```

**Dicas:**

1. Use unsigned: com unsigned, -x é bem definido (vale 2^32 - x) e x &
   -x isola o bit mais baixo.
2. Condição do laço: x < (1u << N). A primeira é (1u << K) - 1.
3. Resposta esperada: 10 trincas (C(5, 3)), de 00111 (Ana Bia Cris) até
   11100 (Cris Dani Eli), em ordem crescente de máscara.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1928.c
```

---

**Exercício P1929** · ★★★ · A balança de dois pratos

O feirante tem uma balança de dois pratos e só três pesos: 1, 3 e 9 kg.
Cada peso pode ficar no prato oposto ao da mercadoria (soma), no MESMO
prato da mercadoria (subtrai) ou fora da balança. Assim, 2 kg de farinha
se pesam com o 3 de um lado e o 1 junto da farinha: 2 = 3 - 1. Escreva
do zero um gerador de todas as 3^3 = 27 escolhas (permutação com
repetição de -1, 0 e +1 em cada peso) e, para cada peso de 1 a 13 kg,
mostre a primeira escolha que dá certo, no formato da saída.


```text
Saída esperada:
 1 = 1
 2 = 3 - 1
 3 = 3
 4 = 3 + 1
 5 = 9 - 3 - 1
 6 = 9 - 3
 7 = 9 - 3 + 1
 8 = 9 - 1
 9 = 9
10 = 9 + 1
11 = 9 + 3 - 1
12 = 9 + 3
13 = 9 + 3 + 1
```

**Dicas:**

1. gera(i, soma) tenta lado[i] = +1, -1 e 0, nesta ordem; quando i == 3
   e a soma é positiva e ainda sem resposta, guarde as escolhas em
   resp[soma][].
2. Para mostrar, percorra os pesos do maior (9) para o menor: o primeiro
   +1 sai sem sinal e os outros com " + " ou " - ".
3. Resposta esperada: todos os pesos de 1 a 13 kg saem (é a base 3
   balanceada). Por exemplo, 5 = 9 - 3 - 1 e 13 = 9 + 3 + 1.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1929.c
```

---

**Exercício P1930** · ★★★ · Quantos caminhões?

A transportadora precisa levar 9 cargas de 5, 4, 3, 3, 3, 3, 3, 3 e 2
toneladas em caminhões de 10 toneladas. Este é o EMPACOTAMENTO (bin
packing). Escreva do zero duas soluções e compare:

(a) o guloso "primeiro que cabe, em ordem decrescente": cada carga vai

```text
  para o primeiro caminhão em que ainda cabe; se não cabe em nenhum,
  abre um novo;
```

(b) o backtracking com poda: cada carga tenta cada caminhão aberto e um

```text
  caminhão novo; corte o ramo quando o número de caminhões abertos já
  não é menor que o melhor achado.
```


Mostre quantos caminhões cada um usa e a divisão do ótimo.


```text
Saída esperada:
Guloso: 4 caminhões
Ótimo: 3 caminhões
Caminhão 1: 5 3 2 (10 t)
Caminhão 2: 4 3 3 (10 t)
Caminhão 3: 3 3 3 (9 t)
```

**Dicas:**

1. Comece o melhor com N (um caminhão por carga) e atualize quando a
   carga N - 1 for colocada. Guarde a divisão em melhor_cam[].
2. A poda de simetria ajuda: se dois caminhões abertos têm a mesma
   carga, tentar um ou outro dá na mesma.
3. Resposta esperada: o guloso usa 4 caminhões e o ótimo usa 3 (5 + 3 +
   2, 4 + 3 + 3 e 3 + 3 + 3). Guloso rápido não garante o ótimo.

```bash
~/LPEDC/rodar 19-backtracking/lista/P1930.c
```

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. Todo código daqui compila: rode para
conferir.

**1.** Quantas vezes a função `gera` é chamada, contando a primeira, quando
`n = 5` e o programa faz `gera(0)`?

```c
void gera(int i) {
    if (i == n) {
        mostra();
        return;
    }
    gera(i + 1);   // o item i fica de fora
    gera(i + 1);   // o item i entra
}
```

- (A) 32
- (B) 31
- (C) 63
- (D) 64
- (E) 120

<details><summary>Gabarito</summary>

**C.** A árvore de decisões é binária completa com 6 níveis (i = 0 a 5): 1 +
2 + 4 + 8 + 16 + 32 = 2⁶ - 1 = 63 chamadas, das quais 32 são folhas (os 2⁵
subconjuntos). Veja 0125.

</details>

**2.** A função abaixo gera as permutações de `v[0..n-1]` por trocas. Com
`n = 4`, quantas permutações ela mostra e quantas vezes `permuta` é chamada,
contando a primeira?

```c
void permuta(int v[], int i) {
    if (i == n) {
        mostra(v);
        return;
    }
    for (int j = i; j < n; j++) {
        troca(&v[i], &v[j]);
        permuta(v, i + 1);
        troca(&v[i], &v[j]);
    }
}
```

- (A) 24 permutações e 65 chamadas
- (B) 24 permutações e 24 chamadas
- (C) 16 permutações e 31 chamadas
- (D) 24 permutações e 41 chamadas
- (E) 256 permutações e 341 chamadas

<details><summary>Gabarito</summary>

**A.** O nível `i` tem 4!/(4 - i)! chamadas: 1, 4, 12, 24 e 24 (o último nível
é o das folhas, com `i == n`). Soma: 65. As folhas são as 4! = 24
permutações. Veja 0126.

</details>

**3.** O que o programa mostra?

```c
#include <stdio.h>

void f(int n) {
    if (n == 0) return;
    f(n - 1);
    printf("%d", n);
    f(n - 1);
}

int main(void) {
    f(3);
    printf("\n");
    return 0;
}
```

- (A) 123
- (B) 321
- (C) 3213121
- (D) 1231231
- (E) 1213121

<details><summary>Gabarito</summary>

**E.** `f(1)` mostra `1`; `f(2)` mostra f(1), `2`, f(1): `121`; `f(3)` mostra
`121`, `3`, `121`. São 2³ - 1 = 7 dígitos, o mesmo padrão dos movimentos da
Torre de Hanói. Veja 0033 e 0125.

</details>

**4.** Sobre o problema das N-rainhas resolvido por backtracking (uma rainha
por linha, poda por coluna e diagonais), analise as afirmações.

- I. Para N = 4 existem exatamente 2 soluções.
- II. O número de soluções sempre cresce quando N cresce.
- III. Para N = 3 não há solução: o programa percorre a árvore, volta de todos
  os ramos e termina sem mostrar nada.

Marque a alternativa **CORRETA**.

- (A) I e III, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) I, II e III.
- (E) II, apenas.

<details><summary>Gabarito</summary>

**A.** I é verdadeira (N = 4 dá 2). II é falsa por causa do "sempre": N = 5
dá 10 soluções e N = 6 dá só 4. III é verdadeira: N = 2 e N = 3 não têm
solução. Mesmo com a poda, a árvore continua exponencial no pior caso. Veja
0128.

</details>

**5.** O backtracking abaixo procura subconjuntos dos preços `{7, 5, 4, 3}`
que somem exatamente 12. Quantas vezes `soma` é chamada, contando
`soma(0, 0)`?

```c
int preco[] = {7, 5, 4, 3};

void soma(int i, int s) {
    if (s > 12) return;               // poda: passou do alvo
    if (s == 12) { mostra(); return; }
    if (i == 4) return;               // acabaram os itens
    soma(i + 1, s + preco[i]);        // leva o item i
    soma(i + 1, s);                   // não leva
}
```

- (A) 16
- (B) 31
- (C) 2
- (D) 25
- (E) 15

<details><summary>Gabarito</summary>

**D.** Sem poda, seriam 31 chamadas (a árvore completa de 4 itens). A poda
corta, por exemplo, o ramo 7 + 5 + ... (a soma bate 12 e volta) e o 7 + 4 + 3
(passa de 12). As soluções são {7, 5} e {5, 4, 3}; contando as chamadas com
um contador global, saem 25. Veja 0127.

</details>

**6.** Um programa gera e **mostra** todos os subconjuntos de `n` itens (cada
subconjunto impresso item a item) e, em outra versão, todas as permutações.
Quais são os custos?

- (A) Θ(2ⁿ) e Θ(n!)
- (B) Θ(n · 2ⁿ) e Θ(n · n!)
- (C) Θ(n²) e Θ(n³)
- (D) Θ(2ⁿ) e Θ(2ⁿ)
- (E) Θ(n log n) e Θ(n!)

<details><summary>Gabarito</summary>

**B.** São 2ⁿ subconjuntos e n! permutações, e mostrar cada um custa até `n`
passos. A recursão em si (os nós internos) não muda a classe. Veja 0125 e
0126.

</details>

**7.** No N-rainhas com `N = 8`, a casa da linha 2 e coluna 5 ocupa quais
índices nos vetores `diag1` (↗, índice `l + c`) e `diag2` (↘, índice
`l - c + N - 1`)?

- (A) `diag1[3]` e `diag2[7]`
- (B) `diag1[7]` e `diag2[-3]`
- (C) `diag1[10]` e `diag2[4]`
- (D) `diag1[7]` e `diag2[10]`
- (E) `diag1[7]` e `diag2[4]`

<details><summary>Gabarito</summary>

**E.** `l + c = 2 + 5 = 7` e `l - c + N - 1 = 2 - 5 + 7 = 4`. O `-3` da (B) é
o `l - c` sem o deslocamento, que escreveria fora do vetor. Veja 0128.

</details>

**8.** Num labirinto em grade, sem pesos, analise as afirmações.

- I. O backtracking em profundidade (a DFS do labirinto) acha um caminho até a
  saída, mas não garante que seja o mais curto.
- II. A BFS, que explora por distância, acha com certeza o caminho com menor
  número de passos.
- III. Se as casas já visitadas não forem marcadas, a busca termina sempre,
  porque a grade é finita.

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) I e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**B.** I e II estão certas: a DFS para no primeiro caminho que dá certo, e a
ordem das direções decide qual é ele; a BFS anda por camadas e a primeira vez
que chega à saída é pelo menor número de passos. III é falsa: sem a marca,
duas casas vizinhas se chamam uma à outra sem fim (ou a busca anda em
círculos) e a pilha estoura. Veja 0129 e 0110.

</details>

**9.** Quantas chamadas a função faz para calcular `fib(6)`, contando a
primeira?

```c
int fib(int n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}
```

- (A) 6
- (B) 13
- (C) 15
- (D) 25
- (E) 64

<details><summary>Gabarito</summary>

**D.** Chamando de `C(n)` as chamadas: C(0) = C(1) = 1 e C(n) = 1 + C(n - 1)
+ C(n - 2). Daí C(2) = 3, C(3) = 5, C(4) = 9, C(5) = 15, **C(6) = 25**. Em
geral, C(n) = 2 · fib(n + 1) - 1, que cresce como φⁿ (φ ≈ 1,618): a mesma
sub-resposta é recalculada muitas vezes. A programação dinâmica do módulo 21
resolve isso. Veja 0032.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulo sobre enumeração (subsequências, combinações e permutações) e os exercícios de backtracking.
- FEOFILOFF, P. *Projeto de algoritmos em C*: enumeração e backtracking. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 3: recursividade (oito rainhas e labirinto com backtracking).
- WIRTH, N. *Algoritmos e estruturas de dados*. Rio de Janeiro: LTC, 1989. Capítulo sobre algoritmos de tentativa e erro (as oito rainhas e o passeio do cavalo).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 2: paradigmas de projeto (recursividade e tentativa e erro).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Exercícios do passeio do cavalo, das oito rainhas e do labirinto; apêndice sobre sudoku.
- CASTILHO, M. A.; SILVA, F.; WEINGAERTNER, D. *Algoritmos e estruturas de dados 1*. Curitiba: UFPR, 2020. Capítulos sobre matrizes e o flood fill.
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Pilhas: o labirinto e a memória de decisões.
- KNUTH, D. E. *The art of computer programming*. v. 4A: combinatorial algorithms, part 1. Boston: Addison-Wesley, 2011. Geração de tuplas (código de Gray), permutações e combinações.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 20: busca em profundidade e busca em largura (a base do labirinto e do flood fill).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.10: recursividade.
