# Módulo 20 · Divisão e conquista e algoritmos gulosos

Até aqui, cada algoritmo do curso resolvia um problema específico: buscar,
ordenar, achar caminho. Este módulo muda o foco para as **técnicas** que estão
por trás deles. Saber o nome de uma técnica é ganhar um jeito de atacar
problemas novos: em vez de inventar do zero, você pergunta "isso se divide em
pedaços iguais menores?" ou "dá para decidir um passo de cada vez, sem voltar
atrás?".

A primeira técnica é a **divisão e conquista**: quebrar o problema em pedaços
do mesmo tipo, resolver cada um com a própria função e combinar as respostas.
Você já a usou sem esse nome na busca binária, no merge sort e no quick sort.
Aqui ela calcula potências em O(log n), conta inversões e acha o melhor
trecho de um vetor em O(n log n).

A segunda é a **estratégia gulosa**: escolher, a cada passo, o que parece
melhor agora, e nunca desfazer. Quando funciona, dá os algoritmos mais simples
e rápidos que existem; quando não funciona, erra com toda a confiança. Por
isso o módulo insiste em duas habilidades: achar um **contraexemplo** e
entender o argumento de **troca** que prova que um guloso está certo.

O módulo termina com um projeto de verdade: um compactador de arquivos com o
código de Huffman, que junta heap, árvore binária, bits, arquivos binários e
TAD num programa só.

## O que você vai aprender

- a técnica de **divisão e conquista** (dividir, conquistar, combinar) e a **potência rápida**
- contar **inversões** pegando carona no merge sort e achar o **subvetor de soma máxima**
- a ideia dos **algoritmos gulosos**, o **troco** e o contraexemplo das fichas {1, 3, 4}
- a **seleção de intervalos**: por que "termina primeiro" funciona e os outros critérios falham
- a **mochila fracionária** e por que o guloso não serve para a mochila 0/1
- o **código de Huffman**: códigos livres de prefixo montados com um heap de mínimo
- um **compactador e descompactador** de arquivos que grava bits de verdade

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com os
   mesmos valores do código.
2. Leia o código. Nos dois últimos assuntos há um **TAD** na pasta
   (`huffman.h`, `compactador.h`): o exemplo usa só a interface, mas abra o
   `.c` para ver o algoritmo.
3. Siga o **fluxograma** com o dedo: é o caminho que o exemplo faz.
4. Rode os exemplos. Troque os valores, procure um caso em que o guloso erra.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

Nos gulosos, desconfie sempre. Antes de acreditar num critério, gaste cinco
minutos tentando quebrá-lo com três ou quatro casos pequenos no papel.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue e o que foi
escolhido; cinza, o que ficou de fora; vermelho, a escolha que deu errado.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você vai precisar de **recursão** (assuntos 0032 e 0033), do **merge sort**
(0094), do **`qsort`** com funções de comparação (0050 e 0096), do **heap**
(0102) e de **arquivos binários** (0068). A análise por recorrência do módulo
17 (0114 e 0115) explica os custos da divisão e conquista, mas dá para seguir
sem ela.

O `rodar` compila junto os `.c` de apoio da pasta (como `huffman.c`). Os
comandos são os de sempre:

```bash
~/LPEDC/rodar 20-dc-e-gulosos/0136-huffman/A271.c
```

Alguns programas do último assunto criam arquivos de teste na pasta em que
você está no terminal e os apagam no fim. Rode de uma pasta em que você possa
escrever (a `~/LPEDC` serve).

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
ficam a 4 arestas da raiz. É o caso do E816 em tamanho menor.

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

## Para ler mais

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 4 (divisão e conquista e o subvetor máximo), problema 2-4 (inversões) e cap. 16 (algoritmos gulosos: seleção de atividades, mochila fracionária e códigos de Huffman).
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
