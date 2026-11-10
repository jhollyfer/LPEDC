# Módulo 20 · Divisão e conquista e algoritmos gulosos

Este módulo trata de **técnicas**. Diante de um problema novo, pergunte: "isso
se divide em pedaços iguais menores?" ou "dá para decidir um passo de cada vez,
sem voltar atrás?".

A **divisão e conquista** quebra o problema em pedaços do mesmo tipo, resolve
cada um e combina as respostas, como no merge sort. Aqui ela calcula
potências em O(log n), conta inversões e acha o melhor trecho de um vetor.

A **estratégia gulosa** escolhe, a cada passo, o que parece melhor e nunca
desfaz. Quando falha, erra sem avisar; por isso o módulo treina o
**contraexemplo** e o argumento de **troca**, que prova o critério.

## O que você vai aprender

- **divisão e conquista** e a **potência rápida**
- **inversões** pelo merge sort e o **subvetor de soma máxima**
- **algoritmos gulosos**, o **troco** e o contraexemplo das fichas {1, 3, 4}
- **seleção de intervalos**: "termina primeiro" funciona, outros critérios falham
- **mochila fracionária** e por que o guloso não serve para a 0/1
- **código de Huffman**: códigos livres de prefixo com um heap de mínimo
- um **compactador** de arquivos que grava bits de verdade

## Antes de começar

Revise recursão (0032 e 0033), merge sort (0094), `qsort` (0050 e 0096), heap
(0102) e arquivos binários (0068). Os custos usam as recorrências do módulo
17 (0114 e 0115).

**Progressão.** Do módulo 18 vem a ordenação, primeiro passo dos gulosos; do
19, a recursão, aqui sem enumerar tudo. O 21 apresenta a programação
dinâmica.

Os dois últimos assuntos trazem um TAD na pasta (`huffman.h`,
`compactador.h`); o comando compila junto o `.c` de apoio:

```bash
gcc ~/LPEDC/A271.c ~/LPEDC/0136-huffman.c -o ~/LPEDC/A271 && ~/LPEDC/A271
```

O último assunto cria arquivos de teste na pasta atual e os apaga no fim.

Nos gulosos, tente quebrar o critério com casos pequenos no papel. Nos
desenhos, verde é o escolhido, cinza o que ficou de fora e vermelho a escolha
errada.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu.
Eles misturam os assuntos do módulo.

**1. Contando multiplicações.** Com a função `potencia` do assunto 0131 (1
multiplicação quando o expoente é par, 2 quando é ímpar), quantas
multiplicações custa x¹⁰⁰? E x¹²⁷? Ache uma regra que dê a resposta direto
pelo expoente escrito em binário.

<details><summary>Resposta</summary>

x¹⁰⁰: os expoentes visitados são 100, 50, 25, 12, 6, 3, 1 (e o 0 do caso
base); três ímpares e quatro pares, **10** multiplicações. x¹²⁷: 127, 63, 31,
15, 7, 3, 1, todos ímpares, **14**. A regra: número de bits do expoente +
número de bits 1. 100 = 1100100₂ (7 bits, três 1): 7 + 3 = 10; 127 = 1111111₂:
7 + 7 = 14.

</details>

**2. O empate que vira inversão.** Quantas inversões tem `2 2 1 1`? Agora
troque o `<=` da intercalação do assunto 0132 por `<` e calcule à mão o que o
programa passa a contar.

<details><summary>Resposta</summary>

São **4** inversões: cada 2 com cada 1. Com `<`, a intercalação de `[2]` com
`[2]` tira o da direita primeiro e soma 1, e o mesmo acontece com `[1]` e
`[1]`: o programa conta **6**, dois pares de iguais tratados como fora de
ordem. Dois valores iguais nunca formam inversão.

</details>

**3. O melhor trecho.** Qual é o subvetor de soma máxima de
`3 -4 5 -1 2 -6 4 1`? Na divisão e conquista, qual dos três casos (esquerda,
direita ou cruzando) dá a resposta na primeira chamada?

<details><summary>Resposta</summary>

A soma máxima é **6**, com `5 -1 2` (posições 2 a 4). Na primeira chamada, a
esquerda (`3 -4 5 -1`) tem melhor trecho `5` (soma 5); a direita
(`2 -6 4 1`), `4 1` (5); o cruzamento junta o melhor final da esquerda (`5 -1`,
soma 4) com o melhor começo da direita (`2`): **6**. Ganha o caso que cruza.

</details>

**4. O caixa sem moeda.** O caixa eletrônico só tem notas de 200, 100, 50, 20,
10, 5 e 2 reais. Para quais saques entre R$ 1 e R$ 15 o guloso trava, mesmo
existindo um jeito de pagar?

<details><summary>Resposta</summary>

O guloso trava em **6, 8, 11 e 13**: ele pega a nota de 5 (ou de 10) e sobra
R$ 1, que nenhuma nota paga. Mas 6 = 2 + 2 + 2, 8 = 2 + 2 + 2 + 2,
11 = 5 + 2 + 2 + 2 e 13 = 5 + 2 + 2 + 2 + 2. R$ 1 e R$ 3 não têm solução
nenhuma. Sem a "moeda de 1", o guloso não garante nem achar uma resposta.

</details>

**5. Reservas com preço.** O salão de festas cobra pelo tamanho do evento. Os
pedidos são [0, 10) pagando R$ 1000, [0, 5) pagando R$ 300 e [5, 10) pagando
R$ 300. O guloso "termina primeiro" maximiza o número de eventos. Ele
maximiza o faturamento?

<details><summary>Resposta</summary>

Não. Ele escolhe [0, 5) e [5, 10): dois eventos, **R$ 600**. Aceitar só o
[0, 10) rende **R$ 1000**. Com pesos, a seleção de intervalos deixa de ser
gulosa: é um problema de programação dinâmica (módulo 21), em que cada
pedido é "aceito" ou "recusado" e as duas opções são comparadas.

</details>

**6. Fracionária contra 0/1.** Uma mochila de 40 kg e quatro itens (peso,
valor): (5, R$ 50), (10, R$ 70), (20, R$ 120) e (15, R$ 60). Quanto rende a
mochila fracionária? E a 0/1?

<details><summary>Resposta</summary>

As razões são 10, 7, 6 e 4 R$/kg. Fracionária: os três primeiros inteiros (35
kg, R$ 240) e 5/15 do último (R$ 20): **R$ 260**. A 0/1: os três primeiros dão
R$ 240 com 35 kg, e nenhuma outra combinação que cabe passa disso (5 + 20 + 15
dá R$ 230): **R$ 240**. A fracionária é sempre um teto para a 0/1.

</details>

**7. Huffman que quase não ganha.** Monte a árvore de Huffman de
`MISSISSIPPI` (M 1, P 2, I 4, S 4). Quantos bits ela dá? E um código fixo de 2
bits?

<details><summary>Resposta</summary>

Junções: M + P = 3; 3 + I = 7 (ou com o S, conforme o desempate); 7 + S = 11.
Comprimentos: S 1 bit, I 2, M e P 3. Total: 4·1 + 4·2 + 1·3 + 2·3 = **21 bits**
(a soma das junções: 3 + 7 + 11). O código fixo de 2 bits dá 11 · 2 = **22**.
Com frequências parecidas, o Huffman ganha pouco.

</details>

**8. Juntar arquivos.** Quatro arquivos ordenados têm 10, 20, 30 e 40 mil
registros. Juntar dois custa a soma dos tamanhos. Qual é o menor custo total
para juntar os quatro? E se você juntar do maior para o menor?

<details><summary>Resposta</summary>

Guloso de Huffman (os dois menores primeiro): 10 + 20 = 30; 30 + 30 = 60;
60 + 40 = 100. Total **190** mil. Do maior para o menor: 40 + 30 = 70;
70 + 20 = 90; 90 + 10 = 100. Total **260** mil. O arquivo de 40 mil devia ser
juntado por último, uma vez só.

</details>

**9. O código mais comprido.** Com 5 símbolos, qual é o maior comprimento de
código que o Huffman pode dar? Mostre frequências que produzem esse caso
qualquer que seja a regra de desempate.

<details><summary>Resposta</summary>

Com k símbolos, a árvore pode virar uma "escada" de altura k - 1: para 5
símbolos, **4 bits**. Frequências como **1, 1, 2, 3, 5** (Fibonacci) fazem
isso: 1 + 1 = 2; os dois 2 (o nó novo e a folha) se juntam em 4, seja qual
for o desempate; 3 + 4 = 7; 5 + 7 = 12. Os dois símbolos de frequência 1
ficam a 4 arestas da raiz. É o caso do exercício E815, em tamanho menor.

</details>

**10. Palestras no auditório.** Os pedidos são [1, 3), [2, 5), [4, 7), [6, 9),
[8, 10), [9, 12) e [11, 13). Quantas palestras cabem, no máximo? Quais o
guloso escolhe?

<details><summary>Resposta</summary>

Ordenados pelo fim (já estão), o guloso aceita **[1, 3), [4, 7), [8, 10) e
[11, 13)**: 4 palestras. Não dá para ter 5: os sete pedidos formam uma cadeia
em que cada um se choca com o seguinte, e quaisquer 5 deles teriam dois
vizinhos na cadeia.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. Sempre que a questão traz código ou
números, dá para conferir rodando.

**1.** O programa abaixo segue a função `potencia` do assunto 0131 (uma
multiplicação quando o expoente é par, duas quando é ímpar, nenhuma no caso
base) e conta as multiplicações. O que ele mostra?

```c
#include <stdio.h>

int mult = 0;

long long potencia(long long x, int n) {
    if (n == 0) return 1;
    long long m = potencia(x, n / 2);
    mult++;
    if (n % 2 == 1) {
        mult++;
        return m * m * x;
    }
    return m * m;
}

int main(void) {
    long long r = potencia(3, 12);
    printf("%lld %d\n", r, mult);
    return 0;
}
```

- (A) 531441 11
- (B) 531441 6
- (C) 531441 4
- (D) 1594323 6
- (E) 531441 12

<details><summary>Gabarito</summary>

**B.** 3¹² = 531441. Os expoentes visitados são 12, 6, 3, 1 e 0. O 12 e o 6
são pares (1 multiplicação cada) e o 3 e o 1 são ímpares (2 cada): 1 + 1 + 2 +
2 = 6. O laço simples faria 11 multiplicações; o 1594323 é 3¹³. Veja 0131.

</details>

**2.** Na mesma potência, alguém escreve
`return potencia(x, n / 2) * potencia(x, n / 2);` em vez de guardar a metade
numa variável. Qual passa a ser a recorrência e o custo?

- (A) `T(n) = T(n/2) + 1`; Θ(log n)
- (B) `T(n) = 2 T(n/2) + n`; Θ(n log n)
- (C) `T(n) = 2 T(n - 1) + 1`; Θ(2ⁿ)
- (D) `T(n) = 2 T(n/2) + 1`; Θ(n)
- (E) `T(n) = T(n/2) + n`; Θ(n)

<details><summary>Gabarito</summary>

**D.** São duas chamadas iguais com metade do expoente e trabalho constante
fora delas: `a = 2`, `b = 2`, `f(n) = 1`. Como `n^(log₂ 2) = n` é maior,
caso 1 do teorema mestre: Θ(n). O resultado continua certo, mas a vantagem da
divisão e conquista some. Veja 0131 e 0115.

</details>

**3.** Quantas inversões tem o vetor `4 1 3 5 2`?

- (A) 5
- (B) 4
- (C) 6
- (D) 3
- (E) 10

<details><summary>Gabarito</summary>

**A.** Os pares `i < j` com `v[i] > v[j]` são (4, 1), (4, 3), (4, 2), (3, 2) e
(5, 2). O máximo para 5 elementos seria 5 · 4 / 2 = 10, no vetor ao
contrário. O merge sort conta todas em O(n log n). Veja 0132.

</details>

**4.** Qual é a maior soma de um subvetor contíguo (não vazio) de
`-2 5 -1 3 -6 4 2 -3`?

- (A) 6
- (B) 8
- (C) 5
- (D) 14
- (E) 7

<details><summary>Gabarito</summary>

**E.** `5 - 1 + 3 = 7`. Ir além custa: somar `-6 4 2` dá 7 de novo, e o `-3`
do fim só tira. O `4 2` sozinho dá 6, e somar todos os positivos (14) não
vale, porque o subvetor tem de ser contíguo. A divisão e conquista testa a
melhor soma da esquerda, a da direita e a que cruza o meio. Veja 0132.

</details>

**5.** Um país tem moedas de 1, 5, 6 e 9 centavos. O caixa usa o guloso "a
maior moeda que cabe". Para qual destes trocos o guloso **não** dá o menor
número de moedas?

- (A) 6
- (B) 9
- (C) 10
- (D) 11
- (E) 15

<details><summary>Gabarito</summary>

**D.** Para 11, o guloso dá 9 + 1 + 1 (três moedas), e o ótimo é 6 + 5 (duas).
Nos outros, ele acerta: 6 e 9 são uma moeda; 10 = 9 + 1 e 15 = 9 + 6 são duas,
o mínimo. Um contraexemplo basta para mostrar que o sistema não é canônico.
Veja 0133.

</details>

**6.** Uma sala tem os pedidos de reserva `[9, 11)`, `[10, 12)`, `[11, 13)`,
`[8, 10)`, `[12, 15)`, `[13, 14)`, `[14, 17)`, `[9, 16)` e `[15, 18)`. O guloso
que aceita primeiro quem **termina** mais cedo escolhe quantos pedidos?

- (A) 3
- (B) 5
- (C) 4
- (D) 6
- (E) 2

<details><summary>Gabarito</summary>

**C.** Em ordem de fim: `[8,10)` entra; `[9,11)` choca; `[10,12)` entra;
`[11,13)` choca; `[13,14)` entra; `[12,15)` e `[9,16)` chocam; `[14,17)`
entra; `[15,18)` choca. São 4, e testando os 2⁹ subconjuntos não há escolha
com 5. É o `GREEDY-ACTIVITY-SELECTOR` do Cormen. Veja 0134.

</details>

**7.** Uma caminhonete leva 45 kg. Os itens são W (5 kg, R$ 40), X (10 kg,
R$ 50), Y (25 kg, R$ 150) e Z (20 kg, R$ 80). Qual é o maior valor na
mochila **fracionária** e na mochila **0/1**?

- (A) R$ 260 e R$ 240
- (B) R$ 260 e R$ 260
- (C) R$ 240 e R$ 240
- (D) R$ 320 e R$ 270
- (E) R$ 250 e R$ 230

<details><summary>Gabarito</summary>

**A.** Valor por quilo: W 8, Y 6, X 5, Z 4. A fracionária leva W, Y e X
inteiros (40 kg, R$ 240) e 5 kg de Z (um quarto, R$ 20): R$ 260. Na 0/1, Z não
pode ser partido, e o melhor que cabe em 45 kg é W + X + Y = R$ 240. O
guloso pela razão é ótimo só na fracionária. Veja 0135.

</details>

**8.** Os símbolos P, Q, R, S e T aparecem 10, 3, 6, 2 e 15 vezes. Quantos bits
tem a mensagem codificada com o código de Huffman?

- (A) 108
- (B) 80
- (C) 73
- (D) 72
- (E) 36

<details><summary>Gabarito</summary>

**C.** Junções: S2 + Q3 = 5; 5 + R6 = 11; P10 + 11 = 21; T15 + 21 = 36. O total
é a soma dos nós internos: 5 + 11 + 21 + 36 = 73. As profundidades são T 1,
P 2, R 3, Q 4 e S 4: 15 + 20 + 18 + 12 + 8 = 73. Com código fixo de 3 bits
seriam 36 × 3 = 108. Veja 0136.

</details>

**9.** Sobre o método guloso, analise as afirmações.

- I. O Bellman-Ford não é guloso: ele relaxa todas as arestas V - 1 vezes, sem
  fixar um vértice por vez como o Dijkstra.
- II. O guloso pela razão valor/peso é ótimo na mochila fracionária, mas não
  garante o ótimo na mochila 0/1.
- III. Todo problema com subestrutura ótima é resolvido por um algoritmo
  guloso.
- IV. Escolher sempre o intervalo mais curto primeiro maximiza o número de
  reservas.

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) III e IV, apenas.
- (E) I, II e IV, apenas.

<details><summary>Gabarito</summary>

**B.** I e II são verdadeiras. III é falsa: subestrutura ótima sozinha não
basta, e a mochila 0/1 tem e pede programação dinâmica; o guloso precisa
também da propriedade da escolha gulosa. IV é falsa: o intervalo mais curto
pode bloquear dois intervalos compridos que caberiam; o que funciona é o que
termina primeiro. Veja 0133, 0134 e 0135.

</details>

**10.** Sobre divisão e conquista, analise as afirmações.

- I. No Strassen, `T(n) = 7 T(n/2) + Θ(n²)` leva a Θ(n^(log₂ 7)), cerca de
  Θ(n^2,81), menos que o Θ(n³) do método escolar.
- II. Na busca binária, `T(n) = T(n/2) + Θ(1)` leva a Θ(log n).
- III. No merge sort, `T(n) = 2 T(n/2) + Θ(n)` leva a Θ(n log n), seja qual
  for a entrada.

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) II, apenas.
- (C) I e II, apenas.
- (D) II e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**E.** As três recorrências estão certas. I: `n^(log₂ 7) ≈ n^2,81` é
polinomialmente maior que `n²`, caso 1 do teorema mestre; o método escolar,
com 8 multiplicações de metades, dá Θ(n³). II: caso 2 com `a = 1`. III: caso 2
com `a = b = 2`, e o merge sort não depende da ordem da entrada. Veja 0115 e
0131.

</details>

## Para ler mais

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 4 (divisão e conquista, Strassen e teorema mestre), problema 2-4 (inversões) e cap. 15 (algoritmos gulosos: seleção de atividades, elementos da estratégia gulosa, mochila fracionária e códigos de Huffman). A 3. ed. (2012) traz o subvetor máximo na seção 4.1.
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 2: paradigmas de projeto (divisão e conquista, balanceamento e algoritmos gulosos).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Rascunho. Partes sobre divisão e conquista, algoritmos gulosos e Huffman.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Capítulo sobre códigos de Huffman e compactação.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Seção 5.3: o algoritmo de Huffman.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulos sobre recursão e mergesort.
- KLEINBERG, J.; TARDOS, É. *Algorithm design*. Boston: Pearson, 2006. Caps. 4 (algoritmos gulosos e o argumento de "ficar à frente") e 5 (divisão e conquista, contagem de inversões).
- HUFFMAN, D. A. A method for the construction of minimum-redundancy codes. *Proceedings of the IRE*, v. 40, n. 9, p. 1098-1101, 1952.
- KOZEN, D.; ZAKS, S. Optimal bounds for the change-making problem. *Theoretical Computer Science*, v. 123, n. 2, p. 377-388, 1994.
- SHANNON, C. E. A mathematical theory of communication. *The Bell System Technical Journal*, v. 27, p. 379-423, 1948.
- CPPREFERENCE. *Fixed width integer types*. Disponível em: <https://en.cppreference.com/w/c/types/integer>.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 2.9 (operadores bit a bit) e cap. 7 (entrada e saída).
