## 0037 · Vetores

O relógio da academia contou seus passos na semana: 8200 no domingo, 10450 na
segunda, e assim por diante. Para somar, tirar a média e achar o recorde, você
precisaria de sete variáveis, `passos_dom`, `passos_seg` e as outras. No mês
seriam trinta; no ano, 365. Cada nova variável pede uma linha nova de soma, e
nenhum laço consegue andar por nomes diferentes. Falta um jeito de dar um nome
só a um grupo de valores e escolher um deles por número.

Pense num armário de escritório com gavetas numeradas. O armário tem um nome
na porta, e cada gaveta guarda uma coisa do mesmo tipo. Para pegar uma pasta,
você diz o nome do armário e o número da gaveta. Em C, esse armário é o
**vetor** (*array*, também chamado de arranjo): um conjunto de variáveis do
mesmo tipo, com um nome só, guardadas lado a lado na memória. Por ter todos os
itens do mesmo tipo, ele é um dado composto **homogêneo**; a struct do módulo
08, que junta tipos diferentes, é o caso **heterogêneo** (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 1).

```c
int passos[7];                 // 7 gavetas de int, com lixo dentro
int notas[4] = {7, 9, 6, 10};  // declara e inicializa
int zeros[100] = {0};          // a 1ª vira 0 e as outras também
int dias[] = {31, 28, 31};     // sem tamanho: o compilador conta (3)
```

A declaração diz o tipo, o nome e, entre colchetes, quantas gavetas o vetor
tem. Para chegar a uma gaveta, você escreve o nome e o **índice**, a posição
entre colchetes: `passos[0]` é a primeira, `passos[6]` é a última. O índice
vai de `0` a `tamanho - 1`, então num vetor de 7 não existe `passos[7]`. Ele
pode ser qualquer expressão inteira, como `v[i + 1]` ou `v[n - 1]`, e é isso
que casa o vetor com o `for`: o contador do laço vira o número da gaveta
(DEITEL; DEITEL, 2011, cap. 6).

Contar a partir de 0 parece estranho, mas tem um motivo concreto. As 7
gavetas de `int` ocupam 28 bytes seguidos (7 × 4). O nome do vetor marca o
começo desse bloco, e o índice diz **quantos itens pular** a partir dali:
`passos[5]` fica no começo mais 5 × 4 bytes. O primeiro item não pula nada,
por isso é o 0. A mesma conta explica por que ler `v[0]` ou `v[999]` custa o
mesmo tempo: é uma multiplicação e uma soma, sem percorrer nada (BACKES, 2013,
cap. 6).

Cada gaveta se comporta como uma variável comum. Ela entra em conta, em `if`,
em `printf` e em `scanf("%d", &notas[i])`. A diferença está só no jeito de
nomeá-la.

O tamanho do vetor é **fixo**: você o decide na declaração e ele não cresce
depois. Por isso vale guardar o tamanho num `#define`, como `#define DIAS 7`:
se a semana virar mês, você muda um número e o laço acompanha. Desde o C99 o
tamanho pode vir de uma variável (`int v[n];`), o **VLA** do assunto 0172, mas
ele também não cresce depois de criado (DEITEL; DEITEL, 2011, cap. 6).

Para dar valores na declaração, use chaves. Se você listar menos valores que
gavetas, as que sobram recebem 0, e é assim que `{0}` zera um vetor inteiro.
Se deixar os colchetes vazios, o compilador conta os valores e decide o
tamanho. As chaves só valem na declaração: `passos = {1, 2};` numa linha
depois não compila (DEITEL; DEITEL, 2011, cap. 6).

O vetor também não guarda o próprio tamanho; quem sabe quantas gavetas existem
é você. No mesmo bloco em que o vetor foi declarado, `sizeof(v) /
sizeof(v[0])` faz a conta: os bytes do vetor inteiro divididos pelos bytes de
um item (KERNIGHAN; RITCHIE, 1989, cap. 5). O assunto 0038 mostra por que essa
conta falha dentro de uma função.

Por fim, um vetor não se copia com `=`. A linha `copia = passos;` não compila,
porque o nome do vetor não é uma variável que se possa trocar de lugar. Para
copiar, ande pelas gavetas num laço e copie uma por uma (BACKES, 2013, cap. 6).

> [!WARNING]
> **O C não confere o índice.** `v[7] = 0` num `int v[7]` compila e mexe na
> memória vizinha, talvez em outra variável sua. É **comportamento
> indefinido**: pode não acontecer nada, pode mudar outro valor ou derrubar o
> programa. O erro clássico é o `i <= 7` no laço, que passa uma vez a mais; o
> AddressSanitizer mostra `stack-buffer-overflow`.

{{exemplo}}

O relógio contou os passos da semana: 7 gavetas, uma por dia. O laço soma e
guarda a maior; o recorde está na gaveta 5, o dia 6 do relatório:

{{ideia}}

```c
#include <stdio.h>

#define DIAS 7

int main(void) {
    // 7 gavetas de int, uma por dia; o índice vai de 0 a 6
    int passos[DIAS] = {8200, 10450, 6300, 12000, 9100, 15300, 7400};

    int total = 0;
    int maior = passos[0]; // começa pelo primeiro, não por 0
    int dia_maior = 0;

    for (int i = 0; i < DIAS; i++) { // i < DIAS: o último índice é 6
        total += passos[i];
        if (passos[i] > maior) {
            maior = passos[i];
            dia_maior = i;
        }
    }

    printf("Total: %d passos\n", total);
    printf("Média: %.1f por dia\n", (double) total / DIAS);
    printf("Recorde: %d passos no dia %d\n", maior, dia_maior + 1);
    return 0;
}
// Saída:
// Total: 68750 passos
// Média: 9821.4 por dia
// Recorde: 15300 passos no dia 6
```

É o acumulador e o maior/menor do assunto 0025, com os valores vindos do vetor;
`i < 7?` impede o laço de passar da última gaveta:

{{fluxograma}}
