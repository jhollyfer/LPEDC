<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 28 · Estruturas: o que faltava

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/28-estruturas-complementos/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2801** · ★☆☆ · A fila do caixa com sentinela

O caixa rápido do mercado atende pela ordem de chegada. Escreva, do zero,
uma lista dupla circular com nó sentinela (a struct da lista guarda o nó
nil dentro dela): inicia(L), insere_fim(L, senha), mostra(L) do primeiro
ao último, mostra_inverso(L) do último ao primeiro e libera(L). Entram as
senhas 31, 32, 33 e 34. Mostre a fila nos dois sentidos e, no fim, se a
sentinela da lista vazia aponta para ela mesma.


```text
Saída esperada:
ida:   [ 31 32 33 34 ]
volta: [ 34 33 32 31 ]
vazia: nil aponta para ela mesma? sim
```

**Dicas:**

1. Lista vazia: nil.prox e nil.ant apontam para &L->nil.
2. Inserir no fim é inserir depois de nil.ant: quatro ponteiros, sem if.
3. Os laços começam em nil.prox (ou nil.ant) e param quando voltam a
   &L->nil.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2801.c
```

---

**Exercício P2802** · ★☆☆ · A chave guardada na sentinela

Na busca com sentinela do Cormen, a chave procurada é copiada para
nil.chave antes do laço, e o laço só testa x->chave != k. Monte a lista
com sentinela 4, 8, 15, 16, 23, 42 (insira no fim) e escreva busca(L, k,
&comparacoes), que devolve o nó achado (ou &L->nil) e conta quantas vezes
x->chave != k foi avaliado. Busque 15, 42 e 99.


```text
Saída esperada:
15: achou, 3 comparações
42: achou, 6 comparações
99: não está, 7 comparações
```

**Dicas:**

1. Antes do laço: L->nil.chave = k; x = L->nil.prox.
2. Cada volta do while é uma comparação; a última (a que dá falso) também
   conta.
3. Para 99, o laço passa pelos 6 nós e para na sentinela: 7 comparações.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2802.c
```

---

**Exercício P2803** · ★☆☆ · O grau de cada nó

O catálogo da livraria guarda os códigos 60, 30, 90, 20, 45, 75, 40, 50,
95 numa BST (insira nessa ordem). Escreva grau(x), que devolve quantos
filhos x tem, e mostre, em ordem, cada chave com o grau entre parênteses.
Depois mostre o grau da árvore (o maior grau) e quantas folhas ela tem.


```text
Saída esperada:
em ordem: 20(0) 30(2) 40(0) 45(2) 50(0) 60(2) 75(0) 90(2) 95(0)
grau da árvore: 2 | folhas: 5
```

**Dicas:**

1. grau(x) = (x->esq != NULL) + (x->dir != NULL).
2. Folha é o nó de grau 0. Percorra em ordem e conte.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2803.c
```

---

**Exercício P2804** · ★☆☆ · Quantos nós em cada nível

Com a mesma árvore do P2803 (60, 30, 90, 20, 45, 75, 40, 50, 95), escreva
profundidade(x), que sobe pelo ponteiro pai contando arestas, e altura(x),
em arestas (vazia: -1). Mostre quantos nós há em cada nível, de 0 até a
altura da árvore, e quais são.


```text
Saída esperada:
nível 0: 60 (1 nós)
nível 1: 30 90 (2 nós)
nível 2: 20 45 75 95 (4 nós)
nível 3: 40 50 (2 nós)
altura: 3
```

**Dicas:**

1. A raiz está no nível 0 e a altura da árvore é a maior profundidade.
2. Um vetor conta[10] somado num percurso qualquer resolve a contagem.
3. Para listar os nós de um nível, percorra em ordem e mostre quem tem a
   profundidade certa.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2804.c
```

---

**Exercício P2805** · ★☆☆ · O fator de cada nó

Ainda com a árvore do P2803 (60, 30, 90, 20, 45, 75, 40, 50, 95), mostre
em ordem cada chave com o seu fator de balanceamento, altura(esq) -
altura(dir), e diga no fim se a árvore é AVL (todo fator em -1, 0 ou 1).
Depois insira 55 e repita.


```text
Saída esperada:
fatores: 20(0) 30(-1) 40(0) 45(0) 50(0) 60(1) 75(0) 90(0) 95(0)
é AVL
fatores: 20(0) 30(-2) 40(0) 45(-1) 50(-1) 55(0) 60(2) 75(0) 90(0) 95(0)
não é AVL
```

**Dicas:**

1. O fator de uma folha é (-1) - (-1) = 0.
2. Uma flag global ou um ponteiro para bool marca se algum fator saiu de
   -1..1.
3. O 55 entra à direita do 50 e desequilibra o 30 e o 60.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2805.c
```

---

**Exercício P2806** · ★☆☆ · Mínimo, máximo e sucessor

O painel de embarque guarda os horários (HHMM) 1210, 830, 1545, 700, 945,
1400, 1700, 900 numa BST com ponteiro para o pai. Escreva minimo(x),
maximo(x) e sucessor(x) (o TREE-SUCCESSOR do Cormen: com subárvore
direita, o mínimo dela; sem, sobe até chegar por um filho esquerdo).
Mostre o primeiro e o último voo e o sucessor de 945, de 1210 e de 1700.


```text
Saída esperada:
primeiro: 700 | último: 1700
depois de 945: 1210
depois de 1210: 1400
depois de 1700: nenhum
```

**Dicas:**

1. Ache o nó com uma busca comum antes de pedir o sucessor.
2. O 945 não tem filho direito: o sucessor é um ancestral.
3. O 1700 é o máximo: o sucessor é NULL.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2806.c
```

---

**Exercício P2807** · ★☆☆ · Divisão e colisões

A locadora de bicicletas espalha as matrículas 1013, 2026, 3039, 4052,
5065, 1500, 2600 e 3700 numa tabela de m = 13 baldes com h(k) = k mod 13.
Mostre o balde de cada matrícula, o número de colisões (chaves que caem
num balde já ocupado) e repita com m = 10.


```text
Saída esperada:
m = 13: 12 11 10 9 8 5 0 8 | colisões: 1
m = 10: 3 6 9 2 5 0 0 0 | colisões: 2
```

**Dicas:**

1. Um vetor de contagem por balde: colisão é quando conta[h] já era maior
   que 0.
2. Repare que 1013, 2026, ... são múltiplos de 1013 = 13 · 78 - 1.
3. Com m = 10, a função só vê o último dígito.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2807.c
```

---

**Exercício P2808** · ★☆☆ · Multiplicação em ponto flutuante

Escreva h(k, m) = floor(m · (k·A mod 1)) com A = (raiz de 5 - 1) / 2, em
double. Para as senhas 10, 20, ..., 80 e m = 8, mostre o balde de cada uma
e quantos baldes diferentes foram usados. Compare com k mod 8.


```text
Saída esperada:
senha | mult | k % 8
   10 |    1 | 2
   20 |    2 | 4
   30 |    4 | 6
   40 |    5 | 0
   50 |    7 | 2
   60 |    0 | 4
   70 |    2 | 6
   80 |    3 | 0
baldes usados: multiplicação 7, divisão 4
```

**Dicas:**

1. "mod 1" é tirar a parte inteira: p - floor(p).
2. Com k mod 8, as senhas múltiplas de 10 só usam baldes pares.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2808.c
```

---

**Exercício P2809** · ★☆☆ · Sondagem linear e a tabela final

O estacionamento tem 11 vagas e usa h(k, i) = (k mod 11 + i) mod 11.
Entram as placas (só os números) 23, 45, 12, 34, 56, 9 e 1. Para cada uma,
mostre a vaga e quantas sondagens fez; no fim, imprima a tabela inteira
("." para vaga livre).


```text
Saída esperada:
23 -> vaga  1 (1 sondagens)
45 -> vaga  2 (2 sondagens)
12 -> vaga  3 (3 sondagens)
34 -> vaga  4 (4 sondagens)
56 -> vaga  5 (5 sondagens)
 9 -> vaga  9 (1 sondagens)
 1 -> vaga  6 (6 sondagens)
tabela: . 23 45 12 34 56 1 . . 9 .
```

**Dicas:**

1. Um vetor de 11 posições começando em -1 (livre).
2. 23, 45, 12, 34 e 56 começam todas no 1: o agrupamento primário aparece
   na hora.
3. O 1 também começa no 1 e só acha lugar depois do bloco.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2809.c
```

---

**Exercício P2810** · ★☆☆ · Pigeonhole dos dados

Num jogo de tabuleiro, foram anotados 15 lançamentos de um dado: 3, 6, 1,
3, 5, 2, 6, 6, 4, 1, 3, 5, 6, 2, 3. Ordene com o pigeonhole sort (uma casa
para cada face, de 1 a 6) e mostre a sequência ordenada e quantas vezes
saiu cada face.


```text
Saída esperada:
frequências: 1:2 2:2 3:4 4:1 5:2 6:4
ordenados: 1 1 2 2 3 3 3 3 4 5 5 6 6 6 6
```

**Dicas:**

1. casa[face - 1]++ na primeira passada.
2. Na segunda, a casa c devolve o valor c + 1, casa[c] vezes.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2810.c
```

## ★★☆ Para pensar

**Exercício P2811** · ★★☆ · Sondagem quadrática

Refaça o estacionamento do P2809 (m = 11, placas 23, 45, 12, 34, 56, 9 e
1) com sondagem quadrática: h(k, i) = (k mod 11 + i * i) mod 11. Mostre a
vaga e as sondagens de cada placa, a tabela final e o total de sondagens.
Compare com o P2809.


```text
Saída esperada:
23 -> vaga  1 (1 sondagens)
45 -> vaga  2 (2 sondagens)
12 -> vaga  5 (3 sondagens)
34 -> vaga 10 (4 sondagens)
56 -> vaga  6 (5 sondagens)
 9 -> vaga  9 (1 sondagens)
 1 -> vaga  4 (6 sondagens)
tabela: . 23 45 . 1 12 56 . . 9 34
total de sondagens: 22
```

**Dicas:**

1. A placa que começa no 1 tenta 1, 2, 5, 10, 6 (1 + 16 = 17), ...
2. O total é o mesmo da linear (22) neste caso, mas o bloco de vagas
   seguidas some, mas todas as placas que começam no 1 seguem a mesma
   trilha (agrupamento secundário).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2811.c
```

---

**Exercício P2812** · ★★☆ · Dispersão dupla

Agora com dispersão dupla, numa tabela de m = 13: h(k, i) = (h1(k) + i ·
h2(k)) mod 13, com h1(k) = k mod 13 e h2(k) = 1 + (k mod 11). Insira 14,
27, 40, 53, 66, 79 (todas com h1 = 1) e 5. Mostre o passo h2, a posição e
as sondagens de cada uma, a tabela final e o total de sondagens.


```text
Saída esperada:
14: passo  4 ->  1 (1 sondagens)
27: passo  6 ->  7 (2 sondagens)
40: passo  8 ->  9 (2 sondagens)
53: passo 10 -> 11 (2 sondagens)
66: passo  1 ->  2 (2 sondagens)
79: passo  3 ->  4 (2 sondagens)
 5: passo  6 ->  5 (1 sondagens)
tabela: . 14 66 . 79 5 . 27 . 40 . 53 .
total de sondagens: 12
```

**Dicas:**

1. h2 nunca é 0 por causa do + 1, e como 13 é primo, qualquer passo de 1
   a 12 visita todas as posições.
2. Cada chave anda com o seu passo: as trilhas se separam logo na segunda
   sondagem.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2812.c
```

---

**Exercício P2813** · ★★☆ · A lápide no meio do caminho

Numa tabela de m = 7 com sondagem linear, cada posição tem um estado:
LIVRE, OCUPADA ou LAPIDE. Escreva insere (reaproveita a primeira lápide do
caminho), busca (para na LIVRE, passa reto pela LAPIDE) e remove (marca
LAPIDE). Insira 10, 17, 24 e 5 (os três primeiros começam no 3), remova o
17, busque o 24, insira 31 e mostre a tabela depois de cada passo ("."
livre, "x" lápide).


```text
Saída esperada:
inseridos:   .  .  . 10 17 24  5
tira 17:     .  .  . 10  x 24  5
busca 24: posição 5
insere 31:   .  .  . 10 31 24  5
```

**Dicas:**

1. Na inserção, guarde a posição da primeira lápide vista; se a chave não
   estiver na tabela, use essa posição (ou a livre onde parou).
2. O 31 também começa no 3 e ocupa o lugar do 17 removido.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2813.c
```

---

**Exercício P2814** · ★★☆ · Do maior para o menor com o antecessor

A tabela de recordes do fliperama guarda as pontuações 5200, 3100, 8800,
2500, 4700, 7600, 9900, 4100 numa BST com ponteiro para o pai. Escreva
antecessor(x) (o espelho do sucessor: com subárvore esquerda, o máximo
dela; sem, sobe até chegar por um filho direito) e mostre o ranking, do
maior para o menor, sem recursão: comece no máximo e ande pelo antecessor.
Mostre também o antecessor do 4700 e do 2500.


```text
Saída esperada:
ranking: 9900 8800 7600 5200 4700 4100 3100 2500
antes de 4700: 4100 | antes de 2500: nenhum
```

**Dicas:**

1. for (No *x = maximo(raiz); x != NULL; x = antecessor(x)).
2. O 4700 tem filho esquerdo (4100): o antecessor é o máximo dele.
3. O 2500 é o mínimo: não tem antecessor.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2814.c
```

---

**Exercício P2815** · ★★☆ · O fiscal da rubro-negra

Três árvores foram coloridas à mão e você tem que conferir se são rubro-
negras. Cada nó tem chave, cor ('V' ou 'P') e dois filhos (NULL faz o
papel da folha nil, preta). Escreva fiscal(x), que devolve a altura negra
de x (pretos de x até NULL, contando x, sem contar o NULL) ou -1 se: um
vermelho tem filho vermelho, ou os dois lados têm alturas negras
diferentes. Confira também a raiz preta. As árvores (pré-ordem, com o
filho vazio como -):


```text
A: 20P (10V (5P, 15P), 30P (-, 35V))
B: 20P (10V (5V, 15P), 30P)
C: 20P (10P (5P, -), 30P)
```


Monte-as com uma função novo(chave, cor, esq, dir) que usa malloc.


```text
Saída esperada:
A: rubro-negra, altura negra 2
B: não é rubro-negra
C: não é rubro-negra
```

**Dicas:**

1. NULL devolve 0. Se um filho devolveu -1, devolva -1.
2. Em B, o 10 vermelho tem o 5 vermelho embaixo (propriedade 4).
3. Em C, à esquerda do 10 há dois pretos e à direita só um (propriedade
   5).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2815.c
```

---

**Exercício P2816** · ★★☆ · Escreva a remoção da AVL

Escreva, do zero, uma AVL com inserção e remoção (nó com altura guardada,
rotações à esquerda e à direita e um equilibra que serve para as duas
operações; na remoção de nó com dois filhos, use o sucessor). Conte as
rotações simples num contador global (a dupla conta 2). Insira 30, 20, 40,
10, 25, 35, 50, 5, 15, 45, 1 e remova 35, 40 e 25, mostrando a pré-ordem,
a altura e as rotações de cada remoção.


```text
Saída esperada:
início: pré 30 10 5 1 20 15 25 40 35 50 45 | altura 3
tira 35: pré 30 10 5 1 20 15 25 45 40 50 | altura 3 | rotações 2
tira 40: pré 30 10 5 1 20 15 25 45 50 | altura 3 | rotações 0
tira 25: pré 30 10 5 1 20 15 45 50 | altura 3 | rotações 0
```

**Dicas:**

1. O equilibra recalcula a altura, olha o fator e escolhe simples ou
   dupla: na remoção, filho com fator 0 pede a simples.
2. raiz = remove_chave(raiz, k): a raiz pode mudar.
3. Tirar o 35 deixa o 40 pesado à direita, com o filho 50 pendendo para
   dentro (fator 1): rotação dupla.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2816.c
```

---

**Exercício P2817** · ★★☆ · Quem é estável?

Os pedidos do delivery chegam com número (1 a 8, a ordem de chegada) e
bairro (código 1 a 3): (1,2) (2,1) (3,2) (4,3) (5,1) (6,3) (7,2) (8,1).
Ordene cópias pelo bairro com a inserção, com a seleção e com o pigeonhole
(uma fila por bairro), e escreva estavel(v, n): entre vizinhos de mesmo
bairro, o número de chegada tem que crescer. Mostre cada resultado como
numero:bairro e o veredito.


```text
Saída esperada:
inserção:   2:1 5:1 8:1 1:2 3:2 7:2 4:3 6:3 | estável
seleção:    2:1 5:1 8:1 1:2 7:2 3:2 4:3 6:3 | não estável
casas:      2:1 5:1 8:1 1:2 3:2 7:2 4:3 6:3 | estável
```

**Dicas:**

1. A seleção troca o menor com a posição i e pode pular por cima de
   iguais.
2. Para o pigeonhole, três vetores (início, fim e próximo) como no
   pombal.c, ou simplesmente passe 3 vezes pela entrada, uma por bairro,
   copiando na ordem.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2817.c
```

---

**Exercício P2818** · ★★☆ · A classificação da corrida

Na corrida de rua do bairro, a classificação é pelo tempo (em segundos, o
menor primeiro); no empate, o mais velho fica na frente; se ainda empatar,
o nome em ordem alfabética. Escreva o comparador composto e ordene com
qsort: Lia 1520 s 34 anos, Davi 1490 s 28, Rita 1520 s 41, Caio 1490 s 28,
Bia 1610 s 22, Teo 1520 s 41. Mostre posição, nome, tempo em min:s e
idade.


```text
Saída esperada:
1. Caio  24:50  28 anos
2. Davi  24:50  28 anos
3. Rita  25:20  41 anos
4. Teo   25:20  41 anos
5. Lia   25:20  34 anos
6. Bia   26:50  22 anos
```

**Dicas:**

1. Compare o tempo; se igual, a idade ao contrário (y - x); se igual,
   strcmp.
2. O qsort não é estável: o desempate pelo nome deixa a ordem completa.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2818.c
```

---

**Exercício P2819** · ★★☆ · Aniversários em duas passadas

O RH quer os aniversários do ano em ordem de mês e, dentro do mês, de dia.
Faça duas passadas de pigeonhole estável: primeiro pelo dia (31 casas),
depois pelo mês (12 casas). Datas (dia/mês) e nomes: Ana 15/3, Beto 2/11,
Cris 28/3, Duda 2/3, Enzo 15/1, Fábio 9/11, Gil 1/12, Hana 30/1. Mostre a
lista depois de cada passada.


```text
Saída esperada:
por dia: Gil 1/12 Beto 2/11 Duda 2/3 Fabio 9/11 Ana 15/3 Enzo 15/1 Cris 28/3 Hana 30/1
por mês: Enzo 15/1 Hana 30/1 Duda 2/3 Ana 15/3 Cris 28/3 Beto 2/11 Fabio 9/11 Gil 1/12
```

**Dicas:**

1. Uma função genérica com chave = 0 (dia) ou 1 (mês) evita escrever o
   código duas vezes.
2. Cada passada: para cada casa em ordem, copie da entrada, em ordem,
   quem cai nela.
3. A última passada é a da chave principal (o mês).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2819.c
```

---

**Exercício P2820** · ★★☆ · Múltiplos de 32 na tabela

Os lotes do almoxarifado têm números múltiplos de 32: 32, 64, ..., 3200
(100 lotes). Compare, numa tabela de m = 32 baldes, a divisão k mod 32 e a
multiplicação em inteiros (k * 2654435769u) >> 27, com uint32_t. Mostre
para cada uma quantos baldes ficaram vazios e o tamanho do balde mais
cheio. Depois repita a divisão com m = 31.


```text
Saída esperada:
vazios 31 | mais cheio 100 | divisão, m = 32
vazios  5 | mais cheio   5 | multiplicação, m = 32
vazios  0 | mais cheio   4 | divisão, m = 31
```

**Dicas:**

1. m = 32 = 2^5: a multiplicação pega os 5 bits mais altos do produto (>>
   27).
2. k mod 32 só olha os 5 bits de baixo de k, que são todos zero.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2820.c
```

## ★★★ Desafio

**Exercício P2821** · ★★★ · A rubro-negra do Cormen, do zero

Escreva a rubro-negra clássica com a sentinela nil (um nó preto global que
faz o papel de toda folha e do pai da raiz): rotações à esquerda e à
direita que acertam o pai, inserção como na BST com o nó novo vermelho e o
conserto com os três casos do tio (e os espelhos). Conte quantas vezes
cada caso rodou. Insira 30, 15, 60, 10, 20, 50, 70, 5, 1, 55, 65, 80 e 90
e mostre a pré-ordem (vermelhos com *), as contagens, a altura negra e o
resultado de um fiscal das propriedades 4 e 5.


```text
Saída esperada:
pré: 30 15 5 1* 10* 20 60 50 55* 70* 65 80 90*
caso 1: 5 | caso 2: 0 | caso 3: 1
altura negra: 3 | fiscal: ok
```

**Dicas:**

1. Caso 1: tio vermelho, recolore pai, tio e avô e faz z = avô. Caso 2:
   tio preto e z em triângulo, z = pai e gira. Caso 3: tio preto e z em
   linha, recolore e gira no avô.
2. Com a sentinela, o tio pode ser nil (preto) sem nenhum teste de NULL.
3. A altura negra pode ser contada descendo sempre pela esquerda.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2821.c
```

---

**Exercício P2822** · ★★★ · A remoção que esqueceu de subir

Ache o bug. A cozinha guarda os pedidos numa AVL, e o pedido 30 foi
entregue. A remoção apaga o nó direitinho, mas a árvore fica torta: o
fiscal reclama. O erro está no FIM de remove_chave: a volta da recursão só
recalcula a altura, sem rebalancear. Conserte e rode de novo.


```text
Saída esperada:
pré: 12 6 3 1 4 9 8 10 20 16 14 18 26 25 28
altura 3 | rotações na remoção: 3
fiscal: AVL ok
```

**Dicas:**

1. Na remoção, todo ancestral tem que passar pelo mesmo equilibra da
   inserção, na volta da recursão.
2. Aqui, o 28 precisa de uma rotação dupla e, depois dela, a raiz 20
   precisa de uma simples: 3 rotações.
3. Resposta esperada: troque "atualiza(r); return r;" por "return
   equilibra(r);" no fim de remove_chave. Com a correção, a saída é a de
   cima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2822.c
```

---

**Exercício P2823** · ★★★ · O passo zero da dispersão dupla

Ache o bug. O guarda-volumes usa dispersão dupla com m = 11: h1(k) =
k mod 11 e um passo h2(k). Entram os cartões 21, 32, 10 e 43, todos com h1 = 10.
O cartão 10 "não coube", com a tabela quase vazia. O erro está em UMA
conta do passo. Conserte e rode de novo.


```text
Saída esperada:
21: passo 2 -> 10
32: passo 3 -> 2
10: passo 1 -> 0
43: passo 4 -> 3
tabela: 10 . 32 43 . . . . . . 21
```

**Dicas:**

1. Calcule o passo do cartão 10 com o código como está. O que acontece
   com h1 + i · 0?
2. O passo nunca pode ser 0 e tem que ser primo com m.
3. Resposta esperada: o passo é 1 + k % (M - 1), não k % (M - 1). Com a
   correção, a saída é a de cima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2823.c
```

---

**Exercício P2824** · ★★★ · Lápides demais: hora de reconstruir

Uma tabela de sondagem linear com m = 13 sofre com as lápides. Escreva
insere, busca (contando sondagens) e remove (com lápide). Insira as chaves
1, 14, 27, 40, 53 e 66 (todas começam no 1), remova 14, 27, 40 e 53 e meça
quantas sondagens custa buscar o 79 (que não está). Depois reconstrua:
crie uma tabela nova só com as chaves vivas, meça de novo e mostre as duas
tabelas ("." livre, "x" lápide).


```text
Saída esperada:
antes:   . 1 x x x x 66 . . . . . .
busca 79: 7 sondagens
depois:  . 1 66 . . . . . . . . . .
busca 79: 3 sondagens
```

**Dicas:**

1. A busca sem sucesso só para numa posição LIVRE: as lápides alongam o
   caminho.
2. Reconstruir é percorrer a tabela velha e inserir as OCUPADAS numa
   tabela zerada.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2824.c
```

---

**Exercício P2825** · ★★★ · As três sondagens lado a lado

Compare as três sondagens numa tabela de m = 17 com as mesmas chaves,
nesta ordem: 20, 37, 54, 71, 88, 5, 22, 39 (as cinco primeiras começam no
3). Linear: (k mod 17 + i) mod 17; quadrática: (k mod 17 + i * i) mod 17;
dupla: (k mod 17 + i * (1 + k mod 16)) mod 17. Para cada método, imprima a
tabela final e o total de sondagens.


```text
Saída esperada:
linear:      .  .  . 20 37 54 71 88  5 22 39  .  .  .  .  .  . | 30 sondagens
quadrática:  .  . 88 20 37  5 22 54  . 39  .  . 71  .  .  .  . | 21 sondagens
dupla:       .  . 22 20  .  5  .  .  . 37 54 71 88 39  .  .  . | 15 sondagens
```

**Dicas:**

1. Uma função posicao(metodo, k, i) com um switch deixa um laço só para
   os três.
2. O 22 começa no 5: na linear, ele cai no meio do bloco que as cinco
   primeiras formaram.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2825.c
```

---

**Exercício P2826** · ★★★ · Relatório por intervalo

O sistema da farmácia guarda os códigos dos remédios 412, 157, 890, 233,
501, 678, 120, 345, 999, 460 numa BST com pai. Escreva teto(raiz, a) (o
primeiro nó com chave >= a, descendo da raiz) e sucessor(x), e com eles
relatorio(raiz, a, b), que mostra em ordem as chaves de a até b e conta
quantas chamadas de sucessor foram feitas. Teste [200, 500], [0, 150],
[900, 2000] e [600, 650].


```text
Saída esperada:
[200, 500]: 233 345 412 460 (4 sucessores)
[0, 150]: 120 (1 sucessores)
[900, 2000]: 999 (1 sucessores)
[600, 650]: (0 sucessores)
```

**Dicas:**

1. No teto, quando x->chave >= a, x vira candidato e você desce à
   esquerda; senão, à direita.
2. O laço: for (x = teto(raiz, a); x != NULL && x->chave <= b; x =
   sucessor(x)).
3. Num intervalo vazio, o teto já passa de b e nenhum sucessor é chamado.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2826.c
```

---

**Exercício P2827** · ★★★ · A AVL mais magra de cada altura

A AVL com o menor número de nós para a altura h (a árvore de Fibonacci)
tem N(h) = N(h - 1) + N(h - 2) + 1 nós, com N(0) = 1 e N(1) = 2. Calcule
N(h) de baixo para cima, para h de 0 a 12, e mostre também o máximo,
2^(h+1) - 1, e a razão h / log2(N(h) + 1), que cresce devagar em direção a
1,44: a AVL mais torta é no máximo uns 44% mais alta que a perfeita.


```text
Saída esperada:
 h | mínimo | máximo | h / log2(N + 1)
 0 |      1 |      1 | 0.00
 1 |      2 |      3 | 0.63
 2 |      4 |      7 | 0.86
 3 |      7 |     15 | 1.00
 4 |     12 |     31 | 1.08
 5 |     20 |     63 | 1.14
 6 |     33 |    127 | 1.18
 7 |     54 |    255 | 1.21
 8 |     88 |    511 | 1.24
 9 |    143 |   1023 | 1.26
10 |    232 |   2047 | 1.27
11 |    376 |   4095 | 1.29
12 |    609 |   8191 | 1.30
```

**Dicas:**

1. Um vetor long N[13] preenchido num for, como no Fibonacci da
   programação dinâmica.
2. log2 está em <math.h>; para h = 0, a razão é 0.
3. N(h) = F(h + 3) - 1, onde F é a sequência de Fibonacci.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2827.c
```

---

**Exercício P2828** · ★★★ · A tabela do campeonato em duas passadas

A liga do bairro tem os times em ordem alfabética, com pontos (0 a 30) e
saldo de gols (-10 a 10): Aleixo 13 +4, Betânia 16 -1, Coroado 13 +4, Dom
Pedro 16 +6, Educandos 9 -3, Flores 13 -2, Glória 16 -1. A classificação é
por pontos, depois saldo (os dois do maior para o menor) e, no empate
total, nome. Faça com duas passadas de pigeonhole estável, esvaziando as
casas da maior para a menor: primeiro pelo saldo (21 casas), depois pelos
pontos (31 casas). Mostre a tabela.


```text
Saída esperada:
1. Dom Pedro: 16 pontos, saldo +6
2. Betânia: 16 pontos, saldo -1
3. Glória: 16 pontos, saldo -1
4. Aleixo: 13 pontos, saldo +4
5. Coroado: 13 pontos, saldo +4
6. Flores: 13 pontos, saldo -2
7. Educandos: 9 pontos, saldo -3
```

**Dicas:**

1. O saldo s vai para a casa s + 10.
2. Como a entrada já está em ordem alfabética, a estabilidade cuida do
   desempate pelo nome sem nenhuma comparação.
3. A última passada é a da chave principal: os pontos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2828.c
```

---

**Exercício P2829** · ★★★ · O cache da biblioteca

O sistema da biblioteca guarda as 3 páginas do catálogo mais recentes num
cache. A ordem de uso fica numa lista dupla circular com sentinela (a mais
recente logo depois da sentinela) e, para achar a página sem percorrer a
lista, uma tabela de sondagem linear com m = 7 leva o número da página ao
nó dela (com lápide na remoção). A cada acesso: se a página está no cache
(acerto), o nó vai para a frente; senão (falta), se o cache está cheio,
sai o último da lista (o menos recente), e a página nova entra na frente.
Acessos: 7 0 1 2 0 3 0 4 2 3 0 3 2. Mostre, a cada acesso, A (acerto) ou F
(falta) e o cache; no fim, o total de faltas.


```text
Saída esperada:
7: F [ 7 ]
0: F [ 0 7 ]
1: F [ 1 0 7 ]
2: F [ 2 1 0 ]
0: A [ 0 2 1 ]
3: F [ 3 0 2 ]
0: A [ 0 3 2 ]
4: F [ 4 0 3 ]
2: F [ 2 4 0 ]
3: F [ 3 2 4 ]
0: F [ 0 3 2 ]
3: A [ 3 0 2 ]
2: A [ 2 3 0 ]
faltas: 9 de 13
```

**Dicas:**

1. A tabela guarda pares (página, No *) com estado LIVRE, OCUPADA ou
   LAPIDE; a busca passa reto pela lápide.
2. Mover para a frente: tira o nó (dois ponteiros) e insere depois da
   sentinela (quatro), sem if.
3. O menos recente é nil.ant.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2829.c
```

---

**Exercício P2830** · ★★★ · O painel de voos

O painel do aeroporto guarda os horários (HHMM) 1415, 905, 1830, 640,
1120, 1600, 2210, 1000 numa BST com ponteiro para o pai. Escreva teto(r,
h) (o primeiro voo às h ou depois), piso(r, h) (o último às h ou antes) e
a remoção do Cormen com transplanta(raiz, u, v), que põe a subárvore v no
lugar de u acertando o pai (no caso dos dois filhos, o sucessor y sobe
para o lugar do nó removido). Para as horas 1130 e 1415, mostre o piso e o
teto; cancele os voos 1415 (a raiz, com dois filhos) e 640 e repita,
mostrando também a árvore em pré-ordem.


```text
Saída esperada:
pré: 1415 905 640 1120 1000 1830 1600 2210
  1130: antes 1120, depois 1415
  1415: antes 1415, depois 1415
sem 1415 e 640: pré 1600 905 1120 1000 1830 2210
  1130: antes 1120, depois 1600
  1415: antes 1120, depois 1600
```

**Dicas:**

1. transplanta: se u é a raiz, v vira a raiz; senão, v entra no lado de u
   no pai; se v != NULL, v->pai = u->pai.
2. Dois filhos: y = mínimo(z->dir). Se y não é filho direito de z,
   transplanta(y, y->dir) e y herda z->dir; depois transplanta(z, y) e y
   herda z->esq.
3. A remoção devolve a nova raiz, que pode mudar.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 28-estruturas-complementos/lista/P2830.c
```
