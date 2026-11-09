<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 25 · Estruturas especiais

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/25-estruturas-extras/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2501** · ★☆☆ · As poltronas ocupadas do cinema

A sessão das 14h tem 6 fileiras de 10 poltronas. A matriz sala guarda a
idade de quem comprou cada poltrona (0 = vazia), e quase tudo é zero.
Escreva o programa: percorra a matriz e monte o vetor de triplas
(linha, coluna, valor), em ordem, só com as poltronas ocupadas. Mostre
as triplas, quantas estão ocupadas, quantos números cada formato guarda
e até quantas ocupadas as triplas compensam.


```text
Saída esperada:
(1, 2, 34)
(1, 3, 31)
(3, 4, 12)
(3, 5, 40)
(3, 6, 41)
(5, 0, 70)
(5, 9, 68)
Ocupadas: 7 de 60
Números guardados: matriz 60, triplas 21
As triplas compensam enquanto houver menos de 20 ocupadas
```

**Dicas:**

1. typedef struct { int lin, col, valor; } Tripla; e um vetor de L * C
   triplas (o pior caso).
2. A matriz guarda L × C números; as triplas, 3 por ocupada. Compensa
   enquanto 3n < L × C.
3. Resposta esperada: 7 ocupadas, 21 números contra 60; compensa com
   menos de 20 ocupadas.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2501.c
```

---

**Exercício P2502** · ★☆☆ · O mapa do estacionamento

O sistema do estacionamento guarda só as triplas (andar, vaga, horas
parado), em ordem de andar e de vaga:


```text
(0, 2, 3) (0, 7, 1) (1, 0, 5) (1, 1, 2) (2, 5, 8) (3, 3, 4) (3, 4, 1)
```


São 4 andares de 8 vagas. Escreva do zero o mapa para o painel da
entrada: uma linha por andar, com as horas de cada vaga ocupada e um
ponto nas livres, numa passada só pelas triplas (sem montar a matriz
cheia). No fim, os carros e as horas somadas.


```text
Saída esperada:
andar 0: . . 3 . . . . 1
andar 1: 5 2 . . . . . .
andar 2: . . . . . 8 . .
andar 3: . . . 4 1 . . .
Carros: 7, horas somadas: 24
```

**Dicas:**

1. Use um índice k na tripla da vez. Ao visitar (i, j), se t[k] é
   exatamente (i, j), mostre o valor e avance k; senão, mostre '.'.
2. Isso só funciona porque as triplas estão em ordem: é um "merge" entre
   a varredura da matriz e a lista.
3. Resposta esperada: 7 carros, 24 horas; o andar 2 só tem a vaga 5.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2502.c
```

---

**Exercício P2503** · ★☆☆ · Busca binária nas triplas

O condomínio guarda o consumo de luz (kWh) só dos apartamentos que
tiveram leitura, como triplas (andar, número, kWh) em ordem. Como estão
em ordem de (lin, col), dá para procurar com busca binária em vez de
varrer tudo. Complete valor(t, n, i, j, &comparacoes): devolve o kWh do
apartamento (i, j), ou 0 se não houver leitura, e conta as triplas
examinadas.


```text
Saída esperada:
(2, 3): 150 kWh, 1 comparação(ões)
(0, 1): 120 kWh, 3 comparação(ões)
(7, 3): 105 kWh, 4 comparação(ões)
(4, 2):   0 kWh, 4 comparação(ões)
(5, 2): 190 kWh, 2 comparação(ões)
```

**Dicas:**

1. A tripla do meio vem "antes" de (i, j) quando lin < i, ou lin == i e
   col < j: aí ini = meio + 1.
2. Com 10 triplas, a busca binária examina no máximo 4.
3. Resposta esperada: (4, 2) não tem leitura (0 kWh, 4 comparações);
   (2, 3) é achado logo na primeira.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2503.c
```

---

**Exercício P2504** · ★☆☆ · As horas extras do mês

A empresa registra as horas extras de 5 funcionários nos 30 dias do mês,
mas quase ninguém faz hora extra. Escreva do zero uma matriz esparsa com
uma lista encadeada por funcionário (em ordem de dia):
- define(f, dia, horas): se a célula do dia já existe, troca as horas;

```text
senão, cria a célula no lugar certo da lista;
```

- o main faz os lançamentos abaixo, mostra cada funcionário com os dias

```text
e o total, conta as células e libera tudo.
```



```text
Lançamentos (funcionário, dia, horas):
(0, 12, 2) (3, 5, 1) (0, 3, 3) (2, 28, 4) (0, 20, 1) (3, 5, 2)
(4, 9, 2) (4, 1, 1) (0, 12, 3)
```



```text
Saída esperada:
Ana    dia 3: 3h; dia 12: 3h; dia 20: 1h; total 7h
Bruno  total 0h
Carla  dia 28: 4h; total 4h
Diego  dia 5: 2h; total 2h
Elisa  dia 1: 1h; dia 9: 2h; total 3h
Células: 7 de 150
```

**Dicas:**

1. Com um ponteiro para ponteiro (Celula **p = &linha[f]) você anda até
   o lugar e insere sem tratar o começo da lista à parte.
2. Os lançamentos (0, 12) e (3, 5) aparecem duas vezes: vale o último,
   e a célula não é duplicada.
3. Resposta esperada: Ana com 7h, Bruno sem nada; 7 células de 150.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2504.c
```

---

**Exercício P2505** · ★☆☆ · O caminho da busca na skip list

A skip list das paradas da rodovia (km) já está montada com andares
escolhidos à mão (sem sorteio). Complete busca(chave): ela desce do
andar mais alto ao 0 e, a cada vez que o ponteiro AVANÇA, mostra
[aK]chave, com K o andar em que avançou. No fim, diz se achou.


```text
Saída esperada:
busca 47: [a2]23 [a1]40 -> achou
busca 18: [a1]12 -> achou
busca 60: [a3]56 -> achou
busca 35: [a2]23 [a0]31 -> não tem
```

**Dicas:**

1. Em cada andar k (de MAX - 1 até 0): enquanto x->prox[k] existe e tem
   chave menor, avance. Depois do andar 0, o candidato é x->prox[0].
2. As paradas e os andares: 5(1) 12(2) 18(1) 23(3) 31(1) 40(2) 47(1)
   56(4) 60(1). Na busca do 60, um avanço só, no andar 3, até o 56.
3. Resposta esperada: o 47 é achado com 2 avanços (23 no andar 2, 40 no
   andar 1); o 35 não existe.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2505.c
```

---

**Exercício P2506** · ★☆☆ · Quantos nós em cada andar

Na skip list, cada nó novo começa com 1 andar e sobe mais um enquanto a
moeda der cara. Sem montar a lista, simule o sorteio de 1000 nós com a
moeda do esqueleto (semente fixa 2026, até 16 andares) e mostre, para
cada andar, quantos nós chegam até ele, ao lado do esperado N / 2^a.
Mostre também o total de ponteiros (cada nó tem um por andar) e a média
por nó.


```text
Saída esperada:
andar  0: 1000 nós (esperado 1000.0)
andar  1:  517 nós (esperado  500.0)
andar  2:  255 nós (esperado  250.0)
andar  3:  120 nós (esperado  125.0)
andar  4:   67 nós (esperado   62.5)
andar  5:   36 nós (esperado   31.2)
andar  6:   17 nós (esperado   15.6)
andar  7:   11 nós (esperado    7.8)
andar  8:    2 nós (esperado    3.9)
andar  9:    2 nós (esperado    2.0)
andar 10:    2 nós (esperado    1.0)
Ponteiros: 2029 (2.03 por nó)
```

**Dicas:**

1. Guarde por_andar[a] = quantos nós têm exatamente a andares. Os que
   chegam ao andar a - 1 são N menos os que têm menos de a andares.
2. A média de ponteiros por nó tende a 2 (1 + 1/2 + 1/4 + ...): a skip
   list gasta, em média, só o dobro dos ponteiros de uma lista simples.
3. Resposta esperada: 517 nós no andar 1, 2029 ponteiros (2.03 por nó).

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2506.c
```

---

**Exercício P2507** · ★☆☆ · Os emojis usados por último

O teclado do celular mostra os emojis numa fileira de 6 e procura da
esquerda para a direita. Depois de cada uso, o emoji vai para a frente
(mover para a frente) e os que estavam antes dele andam uma casa. Escreva
do zero usa(v, emoji), que faz isso num vetor de strings e devolve o
custo (quantos foram comparados). Faça a sequência do dia e mostre o
custo e a fileira depois de cada uso, e o custo total.


```text
Fileira inicial: risada coracao joinha palmas fogo choro
Usos: fogo fogo joinha fogo choro joinha fogo
```



```text
Saída esperada:
fogo    custo 5: fogo risada coracao joinha palmas choro
fogo    custo 1: fogo risada coracao joinha palmas choro
joinha  custo 4: joinha fogo risada coracao palmas choro
fogo    custo 2: fogo joinha risada coracao palmas choro
choro   custo 6: choro fogo joinha risada coracao palmas
joinha  custo 3: joinha choro fogo risada coracao palmas
fogo    custo 3: fogo joinha choro risada coracao palmas
Custo total: 24
```

**Dicas:**

1. O vetor é de ponteiros (const char *v[]): mover é trocar ponteiros,
   nenhuma letra é copiada.
2. Para abrir espaço na frente, ande de i até 1: v[k] = v[k - 1].
3. Resposta esperada: custo total 24; o segundo "fogo" custa 1.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2507.c
```

---

**Exercício P2508** · ★☆☆ · Os mais pedidos da lanchonete

O cardápio digital da lanchonete se reorganiza pela CONTAGEM: cada item
guarda quantas vezes foi pedido e o vetor fica em ordem decrescente de
pedidos. Escreva do zero pede(v, nome): acha o item, soma 1 e o faz
subir, trocando com o da frente, enquanto tiver MAIS pedidos que ele (no
empate, quem já estava na frente fica). Mostre o cardápio depois de cada
pedido.


```text
Cardápio inicial: misto coxinha pastel tapioca suco (todos com 0)
Pedidos: suco pastel suco coxinha pastel suco tapioca pastel pastel
```



```text
Saída esperada:
suco     -> suco(1) misto(0) coxinha(0) pastel(0) tapioca(0)
pastel   -> suco(1) pastel(1) misto(0) coxinha(0) tapioca(0)
suco     -> suco(2) pastel(1) misto(0) coxinha(0) tapioca(0)
coxinha  -> suco(2) pastel(1) coxinha(1) misto(0) tapioca(0)
pastel   -> suco(2) pastel(2) coxinha(1) misto(0) tapioca(0)
suco     -> suco(3) pastel(2) coxinha(1) misto(0) tapioca(0)
tapioca  -> suco(3) pastel(2) coxinha(1) tapioca(1) misto(0)
pastel   -> suco(3) pastel(3) coxinha(1) tapioca(1) misto(0)
pastel   -> pastel(4) suco(3) coxinha(1) tapioca(1) misto(0)
```

**Dicas:**

1. typedef struct { const char *nome; int pedidos; } Item;
2. A subida é um passo do insertion sort: troque v[i] com v[i - 1] e
   faça i-- enquanto i > 0 e v[i].pedidos > v[i - 1].pedidos.
3. Resposta esperada: o pastel só passa o suco no último pedido (4 a 3).

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2508.c
```

---

**Exercício P2509** · ★☆☆ · A agenda que sobe um degrau

A agenda do telefone fixo é uma lista encadeada simples e usa a
TRANSPOSIÇÃO: o contato achado troca de lugar com o que estava logo
antes dele. Escreva do zero:
- poe_no_fim(nome), para montar a agenda inicial;
- liga(nome), que procura do começo, troca o achado com o anterior

```text
(pode trocar só os nomes, sem mexer nos ponteiros) e devolve o custo;
```

- mostra(), e no fim libere todos os nós.


```text
Agenda inicial: Mãe Chefe Pizzaria Dentista Vizinho
Ligações: Vizinho Vizinho Pizzaria Vizinho Vizinho
```



```text
Saída esperada:
Vizinho   custo 5: Mãe Chefe Pizzaria Vizinho Dentista
Vizinho   custo 4: Mãe Chefe Vizinho Pizzaria Dentista
Pizzaria  custo 4: Mãe Chefe Pizzaria Vizinho Dentista
Vizinho   custo 4: Mãe Chefe Vizinho Pizzaria Dentista
Vizinho   custo 3: Mãe Vizinho Chefe Pizzaria Dentista
Custo total: 20
```

**Dicas:**

1. Guarde o nó anterior enquanto anda. Se o achado é o primeiro, não há
   troca.
2. Repare na Pizzaria: uma ligação para ela desfez o degrau que o
   Vizinho tinha subido. A transposição anda devagar e "briga" assim.
3. Resposta esperada: custo total 20; no fim, Mãe Vizinho Chefe
   Pizzaria Dentista.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2509.c
```

---

**Exercício P2510** · ★☆☆ · A conta da feira em formato esparso

A matriz compras[cliente][produto] (4 clientes, 10 produtos) guarda
quantas unidades cada cliente levou e está em triplas, só com o que não
é zero. O vetor preco[] tem o preço de cada produto em R$. A conta de
cada cliente é a multiplicação matriz × vetor: conta = compras × preco.
Escreva do zero, fazendo UMA multiplicação por tripla (os zeros não
custam nada), e mostre quantas multiplicações a matriz cheia faria.


```text
Triplas (cliente, produto, unidades):
(0, 1, 2) (0, 6, 1) (1, 0, 3) (1, 4, 2) (1, 8, 5) (2, 3, 1) (3, 1, 4) (3, 9, 2)
Preços: 5 8 12 3 7 10 4 6 2 9
```



```text
Saída esperada:
cliente 0: R$ 20
cliente 1: R$ 39
cliente 2: R$ 3
cliente 3: R$ 50
Multiplicações: 8 (a matriz cheia faria 40)
```

**Dicas:**

1. conta[t.lin] += t.valor * preco[t.col], para cada tripla t.
2. A ordem das triplas nem importa aqui: cada uma soma no seu cliente.
3. Resposta esperada: R$ 20, 39, 3 e 50; 8 multiplicações contra 40.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2510.c
```

## ★★☆ Para pensar

**Exercício P2511** · ★★☆ · O estoque que não esquece o zero

Ache o bug. A rede de farmácias guarda o estoque numa matriz esparsa
filial × produto, uma lista por filial. Regra da matriz esparsa: zero
NÃO se guarda. Mas quando um produto zera, a célula continua lá com 0, e
zerar um produto que nem existia CRIA uma célula:


```text
Saída que aparece:
filial 0: p4=10 p7=0
filial 1: p2=8 p5=0
filial 2: p4=0 p9=6
Células: 6
```


Conserte a função define: com qtd 0, a célula que existe sai da lista (e
é liberada) e a que não existe não é criada. O contador de células tem
que acompanhar.


```text
Saída esperada:
filial 0: p4=10
filial 1: p2=8
filial 2: p9=6
Células: 3
```

**Dicas:**

1. Com Celula **p apontando para o ponteiro que leva à célula, tirar é
   *p = velha->prox e depois free(velha).
2. São dois casos novos: "achou e qtd é 0" (remove) e "não achou e qtd é
   0" (não faz nada).
3. Resposta esperada: 3 células: p4=10, p2=8 e p9=6.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2511.c
```

---

**Exercício P2512** · ★★☆ · Amigos em comum

A rede de amizades de oito pessoas é uma matriz de adjacência quase
toda de zeros, guardada como matriz esparsa: linha[i] é a lista dos
amigos de i, em ordem de índice. O programa já monta as listas.
Estenda-o:
- grau(i): quantos amigos i tem;
- mostre cada pessoa com o grau e os amigos, e o total de células;
- em_comum(a, b): os amigos em comum de a e b, andando nas duas listas

```text
ao mesmo tempo, como no merge (sem matriz e sem laço dentro de laço).
```

Pergunte por Ana e Beto, Caio e Hugo, Duda e Gabi.


```text
Saída esperada:
Ana (3): Beto Caio Edu
Beto (4): Ana Caio Duda Edu
Caio (4): Ana Beto Edu Fábio
Duda (2): Beto Edu
Edu (5): Ana Beto Caio Duda Hugo
Fábio (2): Caio Hugo
Gabi (0):
Hugo (2): Edu Fábio
Células: 22 de 64
Ana e Beto: Caio Edu (2 em comum)
Caio e Hugo: Edu Fábio (2 em comum)
Duda e Gabi: (0 em comum)
```

**Dicas:**

1. No merge: se x->col < y->col, avance x; se maior, avance y; se igual,
   é amigo em comum e os dois avançam.
2. A matriz cheia teria 64 casas; as listas guardam só 22 células (cada
   amizade aparece nas duas listas).
3. Resposta esperada: Ana e Beto têm Caio e Edu em comum; Gabi não tem
   amigo nenhum.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2512.c
```

---

**Exercício P2513** · ★★☆ · A parada desativada

As paradas da rodovia estão numa skip list com andares escolhidos à mão.
A concessionária desativou algumas. Complete remove_chave(chave): desça
como na busca guardando em antes[k] o último nó antes da chave em cada
andar; se a chave existe, desligue o nó de TODOS os andares dele e
libere. Remova 23, 56, 35 (não existe) e 5, e mostre os andares.


```text
Saída esperada:
remove 23: removida
remove 56: removida
remove 35: não existe
remove 5: removida
  andar 3:
  andar 2:
  andar 1: 12 40
  andar 0: 12 18 31 40 47 60
```

**Dicas:**

1. O alvo é antes[0]->prox[0]. Para k de 0 até alvo->andares - 1:
   antes[k]->prox[k] = alvo->prox[k].
2. Desligar só o andar 0 deixaria ponteiros dos andares de cima para um
   nó já liberado (use-after-free na próxima busca).
3. Resposta esperada: sem o 56 e o 23, os andares 3 e 2 ficam vazios; o
   andar 0 fica 12 18 31 40 47 60.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2513.c
```

---

**Exercício P2514** · ★★☆ · Skip list contra lista simples

O catálogo tem 2000 códigos (3, 6, 9, ..., 6000) numa skip list com
moeda de semente fixa. O programa já insere tudo e tem busca(chave),
que devolve quantas chaves ela comparou. Estenda o main: busque todos os
2000 códigos, some as comparações e guarde a pior; ao lado, mostre o que
uma lista simples ordenada gastaria (a chave da posição c custa c
comparações), sem montar a lista: use a fórmula da soma 1 + 2 + ... + N.


```text
Saída esperada:
Skip list: 40255 comparações, média 20.1, pior 35
Lista simples: 2001000 comparações, média 1000.5, pior 2000
```

**Dicas:**

1. A soma de 1 a N é N(N + 1)/2. Guarde em long.
2. A média da skip list fica perto de 2 log2(N): para N = 2000, uns 22.
3. Resposta esperada: média 20.1 e pior 35 na skip list, contra média
   1000.5 e pior 2000 na lista simples.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2514.c
```

---

**Exercício P2515** · ★★☆ · A busca que sobe a escada

Ache o bug. Esta skip list acha todas as paradas certas, mas a busca
anda demais: para o km 60, que está logo depois do 56 (o único nó do
andar 3), ela faz 8 avanços:


```text
Saída que aparece:
km 60: achou, 8 avanço(s)
km 47: achou, 6 avanço(s)
km 31: achou, 4 avanço(s)
km 35: não tem, 5 avanço(s)
```


A resposta sai certa porque, no andar 0, ela vira uma lista simples. O
erro está numa linha só da busca. Conserte.


```text
Saída esperada:
km 60: achou, 1 avanço(s)
km 47: achou, 2 avanço(s)
km 31: achou, 1 avanço(s)
km 35: não tem, 2 avanço(s)
```

**Dicas:**

1. Em que ordem a busca visita os andares? O ônibus expresso serve para
   o começo da viagem ou para o fim?
2. A skip list ganha porque os andares altos pulam MUITO no começo e o
   andar 0 só acerta os detalhes no fim.
3. Resposta esperada: o laço dos andares vai de MAX - 1 até 0; o km 60
   sai com 1 avanço.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2515.c
```

---

**Exercício P2516** · ★★☆ · Mover para a frente contra a melhor ordem fixa

O app do mercadinho mostra cinco produtos numa lista e procura do
começo. Os 14 pedidos do dia estão no esqueleto. Compare três jeitos:
- a ordem do cadastro, fixa: arroz feijao cafe leite pao;
- a MELHOR ordem fixa, que só dá para montar sabendo o futuro: os mais

```text
pedidos na frente (empate: a ordem do cadastro);
```

- mover para a frente, que não sabe nada do futuro.
Escreva do zero: mostre as frequências, a ordem ótima e o custo total
(comparações) de cada jeito.


```text
Saída esperada:
Frequências: arroz=3 feijao=3 cafe=1 leite=2 pao=5
Ordem ótima fixa: pao arroz feijao leite cafe
Ordem do cadastro: 45
Ordem ótima fixa: 33
Mover para a frente: 39
```

**Dicas:**

1. Custo de achar x numa ordem = posição de x + 1. Some para os 14.
2. Para a ordem ótima, escolha 5 vezes o de maior frequência ainda não
   usado (o primeiro, no empate).
3. Resposta esperada: cadastro 45, ótima 33, mover para a frente 39. O
   MTF não ganha da ótima, mas se aproxima dela sem saber o futuro (o
   Sleator e o Tarjan provaram: nunca passa do dobro).

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2516.c
```

---

**Exercício P2517** · ★★☆ · Cache LRU contra cache FIFO

O app de mapas guarda na memória os pedaços do mapa usados há pouco. Os
pedidos de pedaços do dia são:


```text
1 2 3 1 4 1 2 5 1 2 3 4 1 5 2 1
```


Quando o cache está cheio e chega um pedaço novo, alguém sai. No FIFO
sai o que ENTROU há mais tempo; no LRU sai o que foi USADO há mais tempo
(acertar um pedaço o renova). Escreva simula(cap, lru), que devolve os
acertos, e mostre a tabela para capacidades de 1 a 5.


```text
Saída esperada:
capacidade  LRU  FIFO
         1    0     0
         2    1     1
         3    5     4
         4    7     5
         5   11    11
```

**Dicas:**

1. Use um vetor em que a posição 0 é sempre a próxima a sair. Falta com
   o cache cheio: tire a posição 0 e ponha o novo no fim.
2. A única diferença: no LRU, um acerto leva o pedaço para o fim do
   vetor; no FIFO, o acerto não muda nada.
3. Resposta esperada: com capacidade 4, LRU 7 acertos e FIFO 5; com 5
   todos cabem e os dois dão 11 (16 pedidos - 5 primeiras entradas).

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2517.c
```

---

**Exercício P2518** · ★★☆ · A transposição que perde o contato

Ache o bug. Esta agenda faz transposição religando os ponteiros:
aa -> a -> x vira aa -> x -> a. Na segunda ligação para a Clínica ela
some da lista, e o AddressSanitizer acusa vazamento de memória (memory
leak) no fim, porque ninguém mais aponta para o nó dela:


```text
Saída que aparece:
início: Avó Banco Clínica Dona Rosa
Clínica: Avó Clínica Banco Dona Rosa
Clínica: Avó Banco Dona Rosa
Dona Rosa: Avó Dona Rosa Banco
```


Falta tratar um caso numa linha só. Conserte.


```text
Saída esperada:
início: Avó Banco Clínica Dona Rosa
Clínica: Avó Clínica Banco Dona Rosa
Clínica: Clínica Avó Banco Dona Rosa
Dona Rosa: Clínica Avó Dona Rosa Banco
```

**Dicas:**

1. Na segunda ligação, a Clínica é o segundo nó: a é a Avó e aa é NULL.
   Quem deveria passar a apontar para a Clínica?
2. Quando o anterior do achado é o primeiro, o achado vira o primeiro:
   é o ponteiro inicio que muda.
3. Resposta esperada: acrescente else inicio = x; a Clínica chega à
   frente e a última linha fica Clínica Avó Dona Rosa Banco.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2518.c
```

---

**Exercício P2519** · ★★☆ · Transpor as triplas sem ordenar

As notas da turma (4 alunos × 5 disciplinas) estão em triplas
(aluno, disciplina, nota) em ordem de aluno. A coordenação quer por
disciplina. Trocar lin com col e ordenar custaria O(n log n). A
TRANSPOSIÇÃO RÁPIDA faz em O(n + colunas):

```text
1. conte quantas triplas cada coluna tem;
2. calcule onde a primeira tripla de cada coluna vai cair no resultado
   (a soma das contagens das colunas anteriores);
3. numa passada só, mande cada tripla para inicio[col]++, já trocada.
```

Escreva transpoe(a, n, colunas, b) do zero, mostrando a contagem e o
início de cada coluna.


```text
Saída esperada:
por aluno: (0,1,7) (0,3,9) (1,0,6) (1,3,8) (1,4,5) (2,1,10) (3,0,4) (3,2,8) (3,4,9)
coluna 0: 2 tripla(s), começa em 0
coluna 1: 2 tripla(s), começa em 2
coluna 2: 1 tripla(s), começa em 4
coluna 3: 2 tripla(s), começa em 5
coluna 4: 2 tripla(s), começa em 7
por disciplina: (0,1,6) (0,3,4) (1,0,7) (1,2,10) (2,3,8) (3,0,9) (3,1,8) (4,1,5) (4,3,9)
```

**Dicas:**

1. inicio[0] = 0 e inicio[c] = inicio[c - 1] + conta[c - 1].
2. Como a entrada está em ordem de aluno, dentro de cada disciplina os
   alunos já saem em ordem: o resultado fica ordenado sem sort.
3. Resposta esperada: a disciplina 2 só tem uma nota e começa na posição
   4; o resultado começa com (0,1,6) (0,3,4).

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2519.c
```

---

**Exercício P2520** · ★★☆ · A playlist que aprende o gosto

A playlist é uma lista encadeada que se reorganiza pela CONTAGEM: cada
nó guarda quantas vezes a música tocou, e a lista fica em ordem
decrescente de toques. Escreva do zero toca(m): procura do começo
(custo = posição, contando de 1), soma 1 nos toques e reinsere o nó
depois de TODOS os que têm toques maior ou igual (no empate, quem já
estava na frente fica). Religue ponteiros: não troque conteúdo.


```text
Lista inicial: Asa Branca, Garota de Ipanema, Evidências, Aquarela,
               Tempo Perdido (todas com 0)
Toques: Aquarela, Evidências, Aquarela, Tempo Perdido, Evidências,
        Evidências, Asa Branca, Aquarela
```



```text
Saída esperada:
custo 4: Aquarela(1) Asa Branca(0) Garota de Ipanema(0) Evidências(0) Tempo Perdido(0)
custo 4: Aquarela(1) Evidências(1) Asa Branca(0) Garota de Ipanema(0) Tempo Perdido(0)
custo 1: Aquarela(2) Evidências(1) Asa Branca(0) Garota de Ipanema(0) Tempo Perdido(0)
custo 5: Aquarela(2) Evidências(1) Tempo Perdido(1) Asa Branca(0) Garota de Ipanema(0)
custo 2: Aquarela(2) Evidências(2) Tempo Perdido(1) Asa Branca(0) Garota de Ipanema(0)
custo 2: Evidências(3) Aquarela(2) Tempo Perdido(1) Asa Branca(0) Garota de Ipanema(0)
custo 4: Evidências(3) Aquarela(2) Tempo Perdido(1) Asa Branca(1) Garota de Ipanema(0)
custo 2: Evidências(3) Aquarela(3) Tempo Perdido(1) Asa Branca(1) Garota de Ipanema(0)
Custo total: 24
```

**Dicas:**

1. Com No **p você acha o nó e o tira (*p = x->prox) sem casos à parte.
2. Para reinserir, ande com outro No **q do começo enquanto
   (*q)->toques >= x->toques; depois x->prox = *q e *q = x.
3. Resposta esperada: custo total 24; no fim, Evidências(3) Aquarela(3)
   na frente.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2520.c
```

## ★★★ Desafio

**Exercício P2521** · ★★★ · O cache de CEPs em O(1)

O LRU com vetor gasta O(capacidade) por consulta: procurar e empurrar.
O jeito profissional faz tudo em O(1) com DUAS estruturas juntas:
- uma lista DUPLAMENTE encadeada, da frente (usado agora) para o fundo

```text
(usado há mais tempo): tirar um nó do meio e pôr na frente é O(1);
```

- uma tabela hash (13 baldes, cep % 13, encadeamento pelo campo irmao)

```text
que leva do CEP direto ao nó da lista.
```

Escreva do zero, com capacidade 3, consulta(cep), que devolve 1 no
acerto. Mostre os 10 pedidos com o cache depois de cada um. Depois
confira contra uma versão simples com vetor em 5000 consultas sorteadas
(o gerador do esqueleto), com CEPs múltiplos de 13 para cair todos no
mesmo balde.


```text
Pedidos: 69050 69060 69050 69077 69083 69060 69050 69083 69091 69077
```



```text
Saída esperada:
69050 falta  cache: 69050
69060 falta  cache: 69060 69050
69050 acerto cache: 69050 69060
69077 falta  cache: 69077 69050 69060
69083 falta  cache: 69083 69077 69050
69060 falta  cache: 69060 69083 69077
69050 falta  cache: 69050 69060 69083
69083 acerto cache: 69083 69050 69060
69091 falta  cache: 69091 69083 69050
69077 falta  cache: 69077 69091 69083
Acertos: 2 de 10
5000 consultas: 1885 acertos, igual a versão simples
```

**Dicas:**

1. struct No { int cep; struct No *ant, *prox; struct No *irmao; }.
   Escreva desliga(x), na_frente(x) e tira_do_balde(x).
2. Na falta com o cache cheio, o que sai é o do FUNDO: desligue, tire do
   balde, free. Só então crie o novo.
3. Resposta esperada: 2 acertos nos 10 pedidos; 1885 nas 5000 consultas,
   iguais aos da versão simples.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2521.c
```

---

**Exercício P2522** · ★★★ · A skip list perfeita

A skip list sorteia andares para, NA MÉDIA, ficar parecida com uma
estrutura perfeita: metade dos nós com 2 andares ou mais, um quarto com
3 ou mais... Quando as chaves já chegam em ordem, dá para montar a
versão perfeita sem moeda: o nó da posição i (contando de 1) tem
1 + (quantos zeros há no fim de i em binário) andares. Escreva do zero,
com as chaves 10, 20, ..., 150 e no máximo 5 andares:
- monte a lista numa passada, ligando cada nó no fim de cada andar dele

```text
(guarde o último nó de cada andar);
```

- mostre os andares;
- busque cada chave contando as comparações (cada olhada em x->prox[k])

```text
e mostre a média e o pior caso.
```



```text
Saída esperada:
andar 4:
andar 3: 80
andar 2: 40 80 120
andar 1: 20 40 60 80 100 120 140
andar 0: 10 20 30 40 50 60 70 80 90 100 110 120 130 140 150
comparações: 4 5 5 6 5 6 6 7 4 5 5 6 4 5 4
média 5.13, pior 7
```

**Dicas:**

1. Os andares saem assim: andares = 1; para t = i, enquanto t é par,
   andares++ e t /= 2.
2. É uma busca binária disfarçada: o nó 80 está no meio, 40 e 120 nos
   quartos, e assim por diante.
3. Resposta esperada: o andar 3 só tem o 80; média 5.13, pior 7.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2522.c
```

---

**Exercício P2523** · ★★★ · O jogo da vida esparso

No jogo da vida de Conway, numa grade infinita, cada célula viva com 2 ou
3 vizinhas vivas (das 8 em volta) sobrevive, e cada célula morta com
exatamente 3 vizinhas vivas nasce. Grade infinita não cabe em matriz:
guarde só as VIVAS, num vetor de (lin, col) em ordem. Para a próxima
geração:

```text
1. para cada viva, ponha num vetor de candidatos as 8 vizinhas dela;
2. ordene os candidatos (qsort); uma célula aparece ali uma vez para
   cada vizinha viva, então o tamanho de cada grupo de iguais é a
   contagem de vizinhas;
3. ela fica viva com contagem 3, ou 2 se já era viva (bsearch).
```

Escreva do zero e rode o planador abaixo por 4 gerações, mostrando as
vivas de cada uma, e depois até a geração 400.


```text
Planador: (0,1) (1,2) (2,0) (2,1) (2,2)
```



```text
Saída esperada:
geração 0 (5 vivas): (0,1) (1,2) (2,0) (2,1) (2,2)
geração 1 (5 vivas): (1,0) (1,2) (2,1) (2,2) (3,1)
geração 2 (5 vivas): (1,2) (2,0) (2,2) (3,1) (3,2)
geração 3 (5 vivas): (1,1) (2,2) (2,3) (3,1) (3,2)
geração 4 (5 vivas): (1,2) (2,3) (3,1) (3,2) (3,3)
geração 400 (5 vivas): (100,101) (101,102) (102,100) (102,101) (102,102)
```

**Dicas:**

1. Use o mesmo comparador (lin, depois col) no qsort e no bsearch. Os
   candidatos já ordenados geram a nova geração em ordem.
2. Célula viva sem vizinha nenhuma nem aparece nos candidatos: morre
   sozinha, como deve.
3. Resposta esperada: na geração 4 o planador é o da geração 0 andado
   uma casa na diagonal; na 400, ele está 100 casas longe, ainda com 5
   células.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2523.c
```

---

**Exercício P2524** · ★★★ · Desfazer o mover para a frente

O codificador "mover para a frente" troca cada letra pela posição dela
num alfabeto que se reorganiza (a letra usada vai para a frente). Quem
recebe os números consegue voltar ao texto? Sim: começa com o MESMO
alfabeto e repete o MESMO movimento. Escreva do zero:
- decodifica(cod, n, saida): para cada número p, a letra é alf[p], e ela

```text
vai para a frente;
```

- codifica(texto, saida), para conferir a ida.
Decodifique a mensagem recebida, codifique o resultado e confira se dá
os mesmos números. Por fim, codifique "aaaabbbbaaaabbbb".


```text
Recebido: 1 1 13 1 1 1 2 1 2 1 1 1
```



```text
Saída esperada:
Mensagem: bananabanana
Codificando de novo: mesmos números
Números menores que 3: 11 de 12
aaaabbbbaaaabbbb -> 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0
```

**Dicas:**

1. Comece com char alf[27] = "abcdefghijklmnopqrstuvwxyz" nas duas
   funções. Levar para a frente: desloque alf[0..p-1] uma casa e
   ponha a letra em alf[0].
2. Os dois lados ficam com o alfabeto igual depois de cada letra: por
   isso a volta funciona sem mandar o alfabeto junto.
3. Resposta esperada: a mensagem é bananabanana; o último texto vira
   quase só zeros, com um 1 em cada troca de letra.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2524.c
```

---

**Exercício P2525** · ★★★ · O relógio da segunda chance

O sistema operacional não consegue mover páginas numa lista a cada
acesso, como o LRU pede. Ele usa o RELÓGIO (segunda chance): os quadros
ficam numa roda, cada um com um bit de uso. Acesso a página que está lá
liga o bit. Na falta com a roda cheia, o ponteiro anda: quem tem bit 1
perde a chance (bit vira 0) e é pulado; o primeiro com bit 0 sai, a
página nova entra ali com bit 1 e o ponteiro avança uma casa. Escreva
do zero relogio(cap, mostrar) e lru(cap), que devolvem os acertos.
Mostre o passo a passo do relógio com 3 quadros (o ponteiro marcado com
'>' e cada quadro como página:bit) e a tabela para 2, 3 e 4 quadros.


```text
Pedidos: 1 2 3 4 1 2 5 1 2 3 4 5
```



```text
Saída esperada:
1 falta  >1:1
2 falta  >1:1  2:1
3 falta  >1:1  2:1  3:1
4 falta   4:1 >2:0  3:0
1 falta   4:1  1:1 >3:0
2 falta  >4:1  1:1  2:1
5 falta   5:1 >1:0  2:0
1 acerto  5:1 >1:1  2:0
2 acerto  5:1 >1:1  2:1
3 falta   5:0  3:1 >2:0
4 falta  >5:0  3:1  4:1
5 acerto >5:1  3:1  4:1
Relógio, 3 quadros: 3 acertos
quadros  LRU  relógio
       2    0        0
       3    2        3
       4    4        2
```

**Dicas:**

1. Enquanto a roda não está cheia, a página entra no próximo quadro
   livre e o ponteiro fica em 0.
2. O relógio é uma aproximação do LRU com UM bit por página. Às vezes
   acerta mais, às vezes menos: com 4 quadros, esta sequência engana o
   relógio.
3. Resposta esperada: com 3 quadros, relógio 3 e LRU 2; com 4, relógio
   2 e LRU 4.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2525.c
```

---

**Exercício P2526** · ★★★ · A skip list que não sabe se desmontar

Ache o bug. Nesta skip list, cada nó tem um vetor prox alocado à parte,
com o tamanho exato dos andares dele (economiza memória). Ela monta e
mostra os andares certinho, mas na hora de desmontar o AddressSanitizer
para o programa com heap-use-after-free dentro de destroi (é de
propósito). E, mesmo que não parasse, a memória dos vetores prox
vazaria. Conserte destroi (duas linhas faltando, uma fora do lugar).


```text
Saída esperada:
andar 5: 640
andar 4: 310 640
andar 3: 310 640
andar 2: 125 310 640 870
andar 1: 7 125 310 640 870
andar 0: 7 42 125 310 555 640 870 999
memória devolvida
```

**Dicas:**

1. Depois de free(x), ler x->prox[0] é ler memória devolvida. Guarde o
   próximo ANTES de liberar.
2. Cada nó fez dois malloc (o nó e o vetor prox): precisa de dois free,
   e o do vetor vem antes do do nó.
3. Resposta esperada: No *seguinte = x->prox[0]; free(x->prox);
   free(x); x = seguinte; e o programa termina com "memória devolvida".

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2526.c
```

---

**Exercício P2527** · ★★★ · A tabela de símbolos que aprende

O compilador guarda os nomes das variáveis numa tabela hash com
encadeamento (5 baldes; h = soma dos bytes do nome % 5). Cada nome novo
entra no FIM da lista do seu balde. Dentro de um laço, "i" e "j" são
procurados o tempo todo, mas ficaram no fundo dos baldes. A ideia:
cada balde vira uma lista com MOVER PARA A FRENTE. Escreva do zero
monta, procura(balde, nome, mtf) (devolve as comparações) e libera.
Rode os 20 usos com a lista fixa e com mover para a frente, mostrando
os baldes no começo e no fim.


```text
Nomes, na ordem: total soma media n vetor aux maior menor k x i j
Usos: i j i soma i j i j k i j i soma i j i total i j i
```



```text
Saída esperada:
Baldes no começo:
  balde 0: n vetor menor x i
  balde 1: maior j
  balde 2: soma media k
  balde 3: total
  balde 4: aux
Lista fixa: 68 comparações em 20 buscas
Com mover para a frente: 28 comparações em 20 buscas
Baldes no fim:
  balde 0: i n vetor menor x
  balde 1: j maior
  balde 2: soma k media
  balde 3: total
  balde 4: aux
```

**Dicas:**

1. Com No **p andando pelo balde, mover o achado para a frente é
   *p = x->prox; x->prox = balde[b]; balde[b] = x.
2. O custo de uma busca é o número de nomes comparados no balde (o hash
   já levou ao balde certo).
3. Resposta esperada: 68 comparações com a lista fixa e 28 com mover
   para a frente; no fim, i e j abrem os seus baldes.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2527.c
```

---

**Exercício P2528** · ★★★ · As vendas lançadas fora de ordem

O caixa das três lojas lançou as vendas do mês como triplas (loja, dia,
valor em R$) na ordem em que foram chegando, com repetições (duas vendas
no mesmo dia) e estornos (valor negativo). Para virar uma matriz esparsa
de verdade, as triplas precisam estar em ordem, sem repetidas e sem
zero. Escreva normaliza(t, n), que ordena com qsort por (loja, dia),
junta as repetidas somando os valores e descarta as que somaram zero, no
próprio vetor, e devolve quantas sobraram.


```text
Lançamentos:
(2,14,300) (0,3,120) (1,7,80) (0,3,45) (2,1,60) (1,7,-80)
(0,20,210) (2,14,150) (1,2,95) (0,3,-30) (2,1,-60) (1,30,40)
```



```text
Saída esperada:
Lançamentos: 12
loja 0, dia  3: R$ 135
loja 0, dia 20: R$ 210
loja 1, dia  2: R$ 95
loja 1, dia 30: R$ 40
loja 2, dia 14: R$ 450
Triplas que ficaram: 5
```

**Dicas:**

1. Depois do qsort, as repetidas ficam vizinhas: some um grupo inteiro
   de (loja, dia) iguais antes de decidir se ele fica.
2. Escreva por cima do próprio vetor com um índice m que anda mais
   devagar que o de leitura.
3. Resposta esperada: 5 triplas; loja 0, dia 3 fica com R$ 135 e a
   loja 1 perde o dia 7 (80 - 80 = 0).

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2528.c
```

---

**Exercício P2529** · ★★★ · A agenda do consultório

Os horários marcados do consultório (em minutos desde 0h) ficam numa
skip list. A recepção precisa de quatro operações, todas em O(log n)
esperado. O programa já tem desce(h, antes), que desce os andares
parando no último nó com chave < h (e guarda esse nó de cada andar em
antes[], se antes não for NULL), e marca(h). Escreva:
- desmarca(h): remove o horário, se existir, de todos os andares;
- proximo(h): o menor horário >= h, ou -1;
- anterior(h): o maior horário < h, ou -1.


```text
Saída esperada:
marca 10:15 de novo: já ocupado
desmarca 11:00: ok
desmarca 12:00: não havia
07:00 -> anterior nenhum, próximo 08:00
10:15 -> anterior 09:00, próximo 10:15
10:16 -> anterior 10:15, próximo 13:00
12:00 -> anterior 10:15, próximo 13:00
17:00 -> anterior 16:00, próximo nenhum
Agenda: 08:00 09:00 10:15 13:00 14:30 16:00
```

**Dicas:**

1. Depois de desce(h, ...), o nó devolvido é o maior com chave < h: é a
   resposta de anterior (se for a cabeça, não há). O seguinte dele no
   andar 0 é a resposta de proximo.
2. Em desmarca, o alvo é desce(h, antes)->prox[0]; desligue-o de
   antes[k] para k menor que os andares dele e só então libere.
3. Resposta esperada: 10:16 tem anterior 10:15 e próximo 13:00 (o 11:00
   foi desmarcado); a agenda final é 08:00 09:00 10:15 13:00 14:30 16:00.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2529.c
```

---

**Exercício P2530** · ★★★ · Três políticas no mesmo balcão

No balcão da farmácia, 10 remédios (0 a 9) são pedidos com frequências
muito desiguais: o remédio i sai com peso 2520 / (i + 1). A lista começa
AO CONTRÁRIO (9, 8, ..., 0), o pior caso. Sorteie 5000 pedidos com o
gerador fixo (s = s * 1103515245u + 12345u, começando em 2026, e o
sorteio (s >> 16) % soma_dos_pesos) e compare o custo total e médio de:
lista fixa, mover para a frente, transposição, contagem e a ótima fixa
(em ordem de frequência, que só dá para montar sabendo o futuro).
Escreva tudo do zero com vetores.


```text
Saída esperada:
Frequências: 1755 894 585 441 320 251 237 192 159 166
Ordem ótima: 0 1 2 3 4 5 6 7 9 8
 custo  média  política
 38546   7.71  fixa (ao contrário)
 20786   4.16  mover para a frente
 18027   3.61  transposição
 16521   3.30  contagem
 16447   3.29  ótima fixa
```

**Dicas:**

1. Para sortear com pesos: tire o sorteio de cada peso, em ordem, até
   ele ficar menor que o peso da vez; esse é o remédio.
2. Na contagem, guarde c[i] junto com a posição: ao trocar dois itens,
   troque as contagens também.
3. Resposta esperada: fixa 38546, MTF 20786, transposição 18027,
   contagem 16521 e ótima 16447. Começando no pior caso, o MTF corrige a
   lista na hora, mas paga por jogar na frente até remédio raro.

```bash
~/LPEDC/rodar 25-estruturas-extras/lista/P2530.c
```
