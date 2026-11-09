<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 15 · Tabelas hash

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/15-hash/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1501** · ★☆☆ · Cem baldes ou noventa e sete?

Os números de pedido de uma loja online terminam sempre em 00 ou 50:
31250, 48700, 52150, 61900, 77350, 80200, 93450, 15600. Escreva
void distribui(const int chaves[], int n, int m), que usa o método da
divisão, h(k) = k % m, e mostra quantos baldes foram usados, quantas
colisões houve (em cada balde, todo mundo depois do primeiro conta como
colisão) e o balde de cada pedido. Rode com m = 100 e com m = 97.


```text
Saída esperada:
m = 100: baldes usados 2, colisões 6
  31250 -> 50
  48700 -> 0
  52150 -> 50
  61900 -> 0
  77350 -> 50
  80200 -> 0
  93450 -> 50
  15600 -> 0
m = 97: baldes usados 8, colisões 0
  31250 -> 16
  48700 -> 6
  52150 -> 61
  61900 -> 14
  77350 -> 41
  80200 -> 78
  93450 -> 39
  15600 -> 80
```

**Dicas:**

1. Um vetor int conta[100] = {0} serve para os dois tamanhos.
2. Com m = 100, o resto é só os dois últimos dígitos: o padrão dos dados
   vira o padrão dos baldes. Um primo longe de potências de 10 e de 2
   mistura todos os dígitos.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1501.c
```

---

**Exercício P1502** · ★☆☆ · As encomendas nos escaninhos

A portaria do prédio guarda as encomendas numa tabela hash com 7 baldes,
h(k) = k % 7, e ENCADEAMENTO: cada balde é uma lista encadeada, e a
encomenda nova entra no INÍCIO da lista do seu balde. Insira os códigos
40, 23, 17, 52, 11, 66, 5, 31, 26, mostre a tabela balde por balde e
libere tudo.


```text
Saída esperada:
0:
1:
2: 23
3: 31 66 52 17
4: 11
5: 26 5 40
6:
```

**Dicas:**

1. A tabela é um vetor de ponteiros: No *tabela[7] = {NULL};
2. Inserir no início custa O(1): novo->prox = tabela[b]; tabela[b] = novo;
3. Por isso o último a chegar aparece primeiro na corrente.
4. Para liberar, percorra cada corrente guardando o prox antes do free.
5. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1502.c
```

---

**Exercício P1503** · ★☆☆ · Sondagem linear nos armários

Os armários da academia usam endereçamento aberto com m = 11 posições,
h(k) = k % 11 e sondagem LINEAR: (h(k) + i) % 11, para i = 0, 1, 2, ...
Escreva int insere(int tab[], int k), que devolve quantas posições olhou
até achar uma vazia (VAZIO = -1). Insira 35, 46, 13, 24, 57, 10, 21, 2,
mostre as sondagens de cada um e a tabela final (_ para posição vazia).


```text
Saída esperada:
35 (h = 2): sondagens 1
46 (h = 2): sondagens 2
13 (h = 2): sondagens 3
24 (h = 2): sondagens 4
57 (h = 2): sondagens 5
10 (h = 10): sondagens 1
21 (h = 10): sondagens 2
2 (h = 2): sondagens 6
tabela: 21 _ 35 46 13 24 57 2 _ _ 10
```

**Dicas:**

1. pos = (h + i) % M: o % faz a sondagem dar a volta (o 21 cai em 10,
   ocupado, e vai para 0).
2. Repare no 2: ele chega por último e paga 6 sondagens, porque o bloco
   2..7 já está todo ocupado. É o agrupamento primário: quanto maior o
   bloco, mais chaves caem nele e mais ele cresce.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1503.c
```

---

**Exercício P1504** · ★☆☆ · Sondagem quadrática nas vagas

O estacionamento usa uma tabela com m = 8 vagas e sondagem QUADRÁTICA:
h(k, i) = (k % 8 + (i + i²) / 2) % 8, para i = 0, 1, 2, ... (o caso
c₁ = c₂ = 1/2 do Cormen; os deslocamentos são 0, 1, 3, 6, 10, ...).
Escreva int insere(int tab[], int k), que devolve a posição onde k ficou
(ou -1). Insira 12, 20, 4, 28, 13, 36 e mostre a tabela final.


```text
Saída esperada:
12 -> posição 4
20 -> posição 5
4 -> posição 7
28 -> posição 2
13 -> posição 6
36 -> posição 3
tabela: _ _ 28 36 12 20 13 4
```

**Dicas:**

1. 12, 20, 4, 28 e 36 têm todos k % 8 = 4. Com a linear, eles fariam um
   bloco 4, 5, 6, 7, 0; com a quadrática, cada um salta mais longe.
2. Faça à mão o 28: 4 (ocupado), 5 (ocupado), 7 (ocupado), 4 + 6 = 10 % 8
   = 2 (livre).
3. Com m potência de 2 e esses c₁ e c₂, a sequência visita todas as
   posições. Com outros m, pode não visitar.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1504.c
```

---

**Exercício P1505** · ★☆☆ · Dispersão dupla no guarda-volumes

O guarda-volumes da rodoviária tem m = 13 posições e usa DISPERSÃO DUPLA:
h(k, i) = (h1(k) + i · h2(k)) % 13, com h1(k) = k % 13 e
h2(k) = 1 + (k % 11). Escreva h1, h2 e int insere(int tab[], int k), que
devolve a posição. Insira os tickets 27, 40, 53, 14, 66, 1 (todos com
h1 = 1) e mostre a tabela final.


```text
Saída esperada:
27 (h1 = 1, h2 = 6) -> posição 1
40 (h1 = 1, h2 = 8) -> posição 9
53 (h1 = 1, h2 = 10) -> posição 11
14 (h1 = 1, h2 = 4) -> posição 5
66 (h1 = 1, h2 = 1) -> posição 2
1 (h1 = 1, h2 = 2) -> posição 3
tabela: _ 27 66 1 _ 14 _ _ _ 40 _ 53 _
```

**Dicas:**

1. Cada chave anda com um passo próprio, h2(k): mesmo com o mesmo h1, as
   sequências se separam logo. É isso que acaba com o agrupamento.
2. h2 nunca pode ser 0 (a sondagem ficaria parada): daí o "1 +".
3. Com m primo, qualquer passo entre 1 e m - 1 visita as 13 posições.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1505.c
```

---

**Exercício P1506** · ★☆☆ · O fator de carga subindo

Uma tabela com encadeamento tem m = 5 baldes e h(k) = k % 5. Para estudar
só os tamanhos, nem precisa de lista: guarde int tamanho[5] com o
comprimento de cada corrente. Insira as senhas 12, 7, 30, 22, 15, 9, 41, 3,
17, 25 e, depois de cada inserção, mostre n, o fator de carga
α = n / m e o tamanho da maior corrente.


```text
Saída esperada:
n =  1: alfa = 0.2, maior corrente = 1
n =  2: alfa = 0.4, maior corrente = 2
n =  3: alfa = 0.6, maior corrente = 2
n =  4: alfa = 0.8, maior corrente = 3
n =  5: alfa = 1.0, maior corrente = 3
n =  6: alfa = 1.2, maior corrente = 3
n =  7: alfa = 1.4, maior corrente = 3
n =  8: alfa = 1.6, maior corrente = 3
n =  9: alfa = 1.8, maior corrente = 4
n = 10: alfa = 2.0, maior corrente = 4
```

**Dicas:**

1. Divida em double: (double)n / M. Com int, 3 / 5 daria 0.
2. α é o tamanho MÉDIO das correntes: a busca sem sucesso custa
   Θ(1 + α). Com encadeamento, α pode passar de 1.
3. A maior corrente é o pior caso. Ela cresce mais rápido que a média
   quando as chaves se concentram (12, 7, 22, 17 caem todas no balde 2).
4. Use printf("n = %2d: alfa = %.1f, maior corrente = %d\n", ...).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1506.c
```

---

**Exercício P1507** · ★☆☆ · O hash djb2 dos nomes

Um hash clássico para strings é o djb2: começa com h = 5381 e, para cada
caractere c, faz h = h * 33 + c. Complete a função djb2 (com
unsigned long long, para o estouro ser bem definido) e mostre o hash e o
balde (h % 16) de cada nome.


```text
Saída esperada:
ana   193486357 -> balde 5
bia   193487281 -> balde 1
caio  6385107873 -> balde 1
davi  6385144233 -> balde 9
eva   193490977 -> balde 1
abc   193485963 -> balde 11
acb   193485995 -> balde 11
```

**Dicas:**

1. Converta o char com (unsigned char)*s antes de somar.
2. Em unsigned, o estouro dá a volta (aritmética módulo 2⁶⁴); em int com
   sinal, estourar é comportamento indefinido.
3. "abc" e "acb" têm hashes diferentes (a ordem conta, ao contrário da
   soma dos códigos), mas a diferença é 32: com m = 16, potência de 2, só
   os 4 bits de baixo contam, e eles batem. Um m primo separaria os dois.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1507.c
```

---

**Exercício P1508** · ★☆☆ · Quanto custa procurar na corrente

A secretaria guarda os RAs numa tabela com encadeamento de 5 baldes,
h(k) = k % 5, inserindo no início da corrente. O main insere 21, 6, 11,
33, 18, 40, 16, 3. Complete int busca(No *t[], int k, int *comp), que
devolve 1 se achou e conta em *comp quantas chaves comparou, e procure 21,
16, 33, 40, 26 e 8.


```text
Saída esperada:
21: achou (comparações: 4)
16: achou (comparações: 1)
33: achou (comparações: 3)
40: achou (comparações: 1)
26: não achou (comparações: 4)
8: não achou (comparações: 3)
```

**Dicas:**

1. A busca só olha a corrente do balde k % M.
2. O balde 1 ficou 16 11 6 21: o 21, primeiro a entrar, é o último da
   corrente e custa 4. Busca sem sucesso percorre a corrente inteira.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1508.c
```

---

**Exercício P1509** · ★☆☆ · A busca que desistia cedo

A tabela abaixo (m = 11, sondagem linear) insere 14, 25, 7, 36, 19. A
inserção está certa, mas a busca tem um erro de propósito: ela diz que o
25 e o 36 não estão lá. Rode, entenda e conserte a busca.


```text
Saída esperada (depois do conserto):
14: posição 3
25: posição 4
36: posição 5
19: posição 8
47: posição -1
```

**Dicas:**

1. O 25 e o 36 têm h = 3, a mesma casa do 14, e foram empurrados para 4 e 5.
2. Quando a busca vê uma chave DIFERENTE na posição, isso prova que o k não
   está ali, mas não que ele não está na tabela.
3. Resposta esperada: a busca só pode devolver -1 ao achar uma posição
   VAZIA (ou depois de olhar as M posições). Tire o else que devolve -1 e
   deixe a sondagem continuar; a saída fica igual à de cima.

```bash
~/LPEDC/rodar 15-hash/lista/P1509.c
```

---

**Exercício P1510** · ★☆☆ · O método da multiplicação

O método da MULTIPLICAÇÃO do Cormen calcula h(k) = ⌊m · (k · A mod 1)⌋:
multiplica k por uma constante 0 < A < 1, fica só com a parte fracionária
e multiplica por m. A vantagem: o m pode ser potência de 2 sem estragar a
distribuição. Escreva int h_mult(int k) com m = 16 e A = 0.6180339887 (a
sugestão de Knuth, (√5 - 1)/2) e compare com a divisão k % 16 para os
códigos 100, 101, 102, 103, 200, 300, 1000, 1024.


```text
Saída esperada:
 100: divisão  4, multiplicação 12
 101: divisão  5, multiplicação  6
 102: divisão  6, multiplicação  0
 103: divisão  7, multiplicação 10
 200: divisão  8, multiplicação  9
 300: divisão 12, multiplicação  6
1000: divisão  8, multiplicação  0
1024: divisão  0, multiplicação 13
```

**Dicas:**

1. A parte fracionária de x (positivo) é x - (long)x.
2. Depois, (int)(M * fracao) faz o piso.
3. Repare: na divisão, códigos seguidos caem em baldes seguidos, e todo
   múltiplo de 16 (como 1024) vai para o 0. A multiplicação espalha.
4. Use printf("%4d: divisão %2d, multiplicação %2d\n", ...).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1510.c
```

## ★★☆ Para pensar

**Exercício P1511** · ★★☆ · A lápide que segura a busca

Os escaninhos da biblioteca usam endereçamento aberto com m = 7, sondagem
linear e h(k) = k % 7. VAZIO = -1 e LAPIDE = -2 (a marca DELETED do
Cormen). Escreva:


```text
int busca(const int t[], int k)     passa reto pela lápide, para no VAZIO
void insere(int t[], int k)         ocupa o primeiro VAZIO ou LAPIDE
void remove_chave(int t[], int k, int marca)   troca k por marca
void mostra(const char *rotulo, const int t[])  _ vazio, X lápide
```


Monte DUAS tabelas iguais com 10, 17, 24, 5, 12. Remova o 17 de uma
marcando VAZIO e da outra marcando LAPIDE, procure o 24 nas duas e, na
tabela com lápide, insira o 31. Os rótulos têm 11 colunas ("início:    ",
"sem lápide:", ...) e mostra imprime cada posição com um espaço antes.


```text
Saída esperada:
início:     12 _ _ 10 17 24 5
sem lápide: 12 _ _ 10 _ 24 5
com lápide: 12 _ _ 10 X 24 5
busca 24 sem lápide: -1
busca 24 com lápide: 5
entra o 31: 12 _ _ 10 31 24 5
```

**Dicas:**

1. O 10, o 17 e o 24 têm h = 3: o 24 só chegou à posição 5 passando pela
   4. Se a 4 vira VAZIO, a busca pelo 24 para ali e desiste.
2. A lápide não é igual a chave nenhuma (as chaves são positivas), então
   a busca nem precisa tratá-la à parte: só o VAZIO encerra.
3. O 31 também tem h = 3 e reaproveita a lápide da posição 4.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1511.c
```

---

**Exercício P1512** · ★★☆ · Contando as palavras do trava-língua

Conte quantas vezes cada palavra aparece no trava-língua


```text
o rato roeu a roupa do rei de roma e o rei riu do rato
```


com uma tabela hash de 7 baldes, encadeamento (palavra nova entra no
início da corrente) e o hash djb2 (h = 5381; h = h * 33 + c), balde =
djb2 % 7. Cada nó guarda a palavra (char palavra[16]), o contador e o
prox. Separe as palavras pelos espaços, andando na frase caractere por
caractere. No fim, mostre cada balde com palavra=vezes, os totais, e
libere a tabela.


```text
Saída esperada:
0: e=1
1: riu=1 do=2
2: roma=1 rato=2
3: a=1 roeu=1 o=2
4: rei=2 roupa=1
5: de=1
6:
15 palavras, 11 distintas
```

**Dicas:**

1. conta(t, p): procura p na corrente do balde; achou, soma 1; não achou,
   cria o nó com vezes = 1 no início.
2. Para separar: junte os caracteres num buffer até achar ' ' ou '\0';
   aí feche com '\0', conte e recomece. Trate o '\0' DENTRO do laço, para
   a última palavra não ficar de fora.
3. A palavra "o" aparece depois de "roeu" no balde 3 porque já existia
   quando a frase passou pelo segundo "o": só o contador muda.
4. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1512.c
```

---

**Exercício P1513** · ★★☆ · Quantos pares fecham o vale-presente

Você ganhou um vale de R$ 100 e quer saber quantos PARES de produtos da
vitrine custam exatamente R$ 100 juntos. Os preços (com repetidos) são
20, 30, 50, 30, 70, 20, 80, 50, 45. Conte os pares i < j em O(n) com uma
tabela hash que guarda, para cada preço, QUANTAS VEZES ele já apareceu:
para cada preço p, na ordem, some à resposta quantos (100 - p) já foram
vistos e só então registre p.

Use endereçamento aberto com m = 17 e sondagem linear, em dois vetores
globais: int chave[17] (VAZIO = -1) e int vezes[17]. Mostre cada preço que
fecha algum par e, no fim, compare com a força bruta (dois laços).


```text
Saída esperada:
R$ 70 com os R$ 30 anteriores: +2
R$ 80 com os R$ 20 anteriores: +2
R$ 50 com os R$ 50 anteriores: +1
pares com hash: 5, força bruta: 5
```

**Dicas:**

1. Escreva posicao(k), que devolve onde k está ou onde ele entraria;
   quantas(k) e soma_um(k) usam essa mesma função.
2. Registrar DEPOIS de consultar evita contar o par (j, j): o segundo 50
   acha só o primeiro.
3. A força bruta é O(n²); a versão com hash é O(n) em média.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1513.c
```

---

**Exercício P1514** · ★★☆ · A tabela que cresce sozinha

Uma tabela com endereçamento aberto (sondagem linear, h(k) = k % m) começa
com m = 5 e não deixa o fator de carga passar de 0,5. Antes de cada
inserção, se 2 · (n + 1) > m, ela faz REHASH: cria uma tabela com m novo =
o primeiro primo >= 2 · m, reinsere todas as chaves (com o m novo!) e
libera a antiga. Use


```text
typedef struct { int *t; int m, n; } Tabela;
```


e malloc para o vetor. Insira 12, 7, 33, 21, 18, 40, 9, mostrando a tabela
depois de cada inserção (e avisando cada rehash).


```text
Saída esperada:
+12
  m =  5: _ _ 12 _ _
+7
  m =  5: _ _ 12 7 _
rehash: 5 -> 11
+33
  m = 11: 33 12 _ _ _ _ _ 7 _ _ _
+21
  m = 11: 33 12 _ _ _ _ _ 7 _ _ 21
+18
  m = 11: 33 12 _ _ _ _ _ 7 18 _ 21
rehash: 11 -> 23
+40
  m = 23: _ _ _ _ _ _ _ 7 _ _ 33 _ 12 _ _ _ _ 40 18 _ _ 21 _
+9
  m = 23: _ _ _ _ _ _ _ 7 _ 9 33 _ 12 _ _ _ _ 40 18 _ _ 21 _
n = 7, alfa = 0.30
```

**Dicas:**

1. Não dá para copiar o vetor velho para o começo do novo: com m diferente,
   cada chave tem outra casa (o 12 sai da 2 e vai para a 1, e depois para a
   12). Reinsira uma por uma.
2. Escreva eh_primo, proximo_primo, cria(m) e coloca(t, m, k).
3. Um rehash custa O(n), mas como m dobra, ele acontece cada vez mais raro:
   o custo médio por inserção continua O(1).
4. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1514.c
```

---

**Exercício P1515** · ★★☆ · Três sondagens, as mesmas chaves

Compare as três sondagens numa tabela de m = 13 posições, com as mesmas
chaves 13, 26, 39, 52, 1, 14 (as quatro primeiras com h = 0, as duas
últimas com h = 1). As funções recebem a chave k e a tentativa i:


```text
linear:      (k % 13 + i) % 13
quadrática:  (k % 13 + i * i) % 13
dupla:       (k % 13 + i * (1 + k % 11)) % 13
```


Escreva testa(nome, sonda, chaves, n), que recebe a sondagem como ponteiro
para função, monta a tabela do zero, conta o TOTAL de posições olhadas e
mostra a tabela final com printf("%-10s sondagens %2d:", ...).


```text
Saída esperada:
linear     sondagens 19: 13 26 39 52 1 14 _ _ _ _ _ _ _
quadrática sondagens 15: 13 26 1 _ 39 14 _ _ _ 52 _ _ _
dupla      sondagens 13: 13 1 _ _ 14 26 _ 39 _ 52 _ _ _
```

**Dicas:**

1. A assinatura do parâmetro é int (*sonda)(int k, int i).
2. Na linear, o 1 e o 14 pagam pelo bloco que o 13, o 26, o 39 e o 52
   formaram (agrupamento primário). Na quadrática, quem tem o mesmo h
   ainda segue a mesma trilha (agrupamento secundário). Na dupla, cada
   chave tem um passo próprio.
3. Com 6 chaves o ganho é pequeno; com a tabela mais cheia, a diferença
   explode (veja o P1528).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1515.c
```

---

**Exercício P1516** · ★★☆ · Cancelando matrículas na tabela encadeada

A academia guarda as matrículas numa tabela com encadeamento de 5 baldes,
h(k) = k % 5, inserindo no início. O main insere 101, 206, 311, 416, 122,
227, 133. Escreva int remove_chave(No *t[], int k), que tira k da corrente
e libera o nó (devolve 1) ou devolve 0 se não achar. Remova 311 (meio da
corrente), 416 (começo), 101 (fim) e 999 (não existe), e libere o resto no
fim usando a própria remove_chave.


```text
Saída esperada:
início:
  0:
  1: 416 311 206 101
  2: 227 122
  3: 133
  4:
remove 311: ok
remove 416: ok
remove 101: ok
remove 999: não existe
fim:
  0:
  1: 206
  2: 227 122
  3: 133
  4:
```

**Dicas:**

1. Com um ponteiro para ponteiro, No **p = &t[k % M], o começo da corrente
   não é caso especial: ande com p = &(*p)->prox e, ao achar, faça
   *p = sai->prox.
2. Lembre de free(sai) DEPOIS de religar a corrente.
3. Ao contrário do endereçamento aberto, aqui a remoção é de verdade: nada
   de lápide.
4. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1516.c
```

---

**Exercício P1517** · ★★☆ · O primeiro crachá repetido na catraca

A catraca da fábrica registrou os crachás na ordem em que passaram:
4821, 3307, 9954, 1220, 6638, 3307, 4821, 7012, 9954. A segurança quer o
PRIMEIRO crachá que passou pela segunda vez (o que repetiu mais cedo).
Use um conjunto hash: endereçamento aberto, m = 17, sondagem linear,
VAZIO = -1, com a função bool ja_viu(int t[], int k), que devolve true se
k já estava e, se não estava, guarda k. Pare na primeira repetição.


```text
Saída esperada:
primeiro repetido: 3307, na passagem 6
```

**Dicas:**

1. Uma passada só, em O(n) médio. A força bruta (comparar cada um com
   todos os anteriores) seria O(n²).
2. O 4821 é o primeiro a APARECER entre os repetidos, mas o 3307 repete
   ANTES: a pergunta é pela repetição, não pela primeira aparição.
3. Um conjunto é uma tabela hash só com chaves, sem valor.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1517.c
```

---

**Exercício P1518** · ★★☆ · O produto mais vendido do dia

O caixa do mercadinho registrou estes códigos de produto, um por item
vendido:


```text
78912 55301 78912 10450 55301 78912 33017 10450
55301 55301 90008 78912 55301 33017
```


Conte as vendas de cada código com uma tabela hash: endereçamento aberto,
m = 23, sondagem linear, dois vetores globais int codigo[23] (VAZIO = -1)
e int vendas[23]. Depois, percorra a TABELA (na ordem das posições),
mostrando cada código e as vendas, e diga quantos produtos distintos houve
e qual foi o mais vendido.


```text
Saída esperada:
10450: vendas 2
55301: vendas 5
90008: vendas 1
33017: vendas 2
78912: vendas 4
5 produtos distintos; mais vendido: 55301 (5 vendas)
```

**Dicas:**

1. registra(k): sonde enquanto a posição está ocupada por OUTRO código;
   ao parar, grave o código (se era vazio) e some 1 nas vendas.
2. A ordem da listagem é a das posições na tabela (k % 23 com as
   colisões), não a ordem de chegada: hash não guarda ordem.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1518.c
```

---

**Exercício P1519** · ★★☆ · Medindo os blocos da sondagem linear

Insira 27, 40, 2, 15, 8, 21, 34, 50, 11 numa tabela de m = 13 com sondagem
linear (h(k) = k % 13) e meça o AGRUPAMENTO PRIMÁRIO: mostre a tabela, cada
bloco de posições ocupadas seguidas (com a posição onde começa e o
tamanho) e o maior bloco. Um bloco pode dar a volta no fim da tabela.


```text
Saída esperada:
tabela: _ 27 40 2 15 _ _ _ 8 21 34 50 11
bloco começando em 1, tamanho 4
bloco começando em 8, tamanho 5
maior bloco: 5
```

**Dicas:**

1. Uma posição i começa um bloco se está ocupada e a anterior,
   (i - 1 + M) % M, está vazia.
2. Para não cortar um bloco que dá a volta, comece a varredura logo depois
   de uma posição vazia e ande M posições com % M.
3. O 11 (h = 11) e o 50 (h = 11) acabaram grudados no bloco do 8 e do 21:
   blocos grandes atraem mais chaves, e a busca dentro deles fica cara.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1519.c
```

---

**Exercício P1520** · ★★☆ · O estacionamento pela placa

O estacionamento cobra R$ 5,00 por hora e acha o carro pela placa com uma
tabela hash de structs: m = 11, endereçamento aberto, sondagem linear,
balde = djb2(placa) % 11. Placa vazia ("") marca posição livre.


```text
typedef struct { char placa[8]; int entrada; } Carro;
```


Escreva entra(t, placa, hora) e const Carro *procura(t, placa). Entram
QWE1A23 às 8h, RTY4B56 às 9h, JKL7C89 às 9h, ZXC0D12 às 11h e MNB3E45 às
13h. Às 15h, saem JKL7C89, MNB3E45 e AAA0A00 (que nunca entrou).


```text
Saída esperada:
JKL7C89: entrou às 9h, ficou 6h, paga R$ 30,00
MNB3E45: entrou às 13h, ficou 2h, paga R$ 10,00
AAA0A00: não entrou aqui
```

**Dicas:**

1. Inicialize com Carro t[M] = {{"", 0}}; e teste vaga livre com
   t[pos].placa[0] == '\0'.
2. Compare placas com strcmp, nunca com ==.
3. Use o djb2 com unsigned long long e copie a placa com snprintf.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1520.c
```

## ★★★ Desafio

**Exercício P1521** · ★★★ · O contador da feira que cresce sozinho

Conte as frutas da lista da feira com uma tabela de encadeamento que
CRESCE: ela começa com m = 3 baldes e, sempre que uma palavra NOVA faz
n > m (α > 1), faz rehash para 2m + 1 baldes. No rehash, os nós são
MOVIDOS para as correntes novas (nada de malloc nem de copiar palavras).


```text
typedef struct No { char palavra[16]; int vezes; struct No *prox; } No;
typedef struct { No **baldes; int m, n; } Tabela;
```


Use djb2 % m como balde e insira no início da corrente. A lista é:
banana maca uva banana pera maca banana limao uva kiwi manga pera banana
caju coco figo. No fim, mostre os baldes, as estatísticas e libere tudo
(os nós e o vetor de baldes).


```text
Saída esperada:
rehash depois de "pera": 3 -> 7 baldes
rehash depois de "caju": 7 -> 15 baldes
0: figo=1
1: maca=2 uva=2
2:
3:
4:
5:
6: coco=1
7: manga=1
8:
9: limao=1
10: banana=4
11:
12: kiwi=1 caju=1
13: pera=2
14:
16 palavras, 10 distintas, m = 15, alfa = 0.67, maior corrente = 2
```

**Dicas:**

1. Crie os baldes com calloc(m, sizeof(No *)): todos começam NULL.
2. No rehash, percorra cada corrente guardando o prox ANTES de religar o
   nó na corrente nova; depois, free no vetor velho.
3. Só palavra nova aumenta n; repetida só soma no contador.
4. Como m dobra, o custo dos rehashes somados é O(n): em média, O(1) por
   palavra.
5. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1521.c
```

---

**Exercício P1522** · ★★★ · Quando as lápides tomam conta

A lápide resolve a remoção no endereçamento aberto, mas cobra um preço: a
busca SEM sucesso só para no VAZIO, então as lápides deixam as buscas tão
caras quanto se as chaves ainda estivessem lá. Meça isso.

Tabela global int t[11] (VAZIO = -1, LAPIDE = -2), sondagem linear,
h(k) = k % 11. Escreva busca(k, &sondagens), insere(k) (não duplica,
reaproveita lápide), remove_chave(k) (marca lápide), reconstroi() (tira as
chaves vivas, limpa a tabela e reinsere só elas) e relatorio(quando), que
mostra a tabela (_ vazio, X lápide), as vivas, as lápides e a média de
sondagens de 11 buscas sem sucesso, uma começando em cada posição (use as
chaves 1100 a 1110: 1100 + h começa em h). Use printf("%-11s", quando).

Insira 22, 34, 46, 58, 13, 70, 81, 92; remova 22, 46, 13, 81, 92;
reconstrua.


```text
Saída esperada:
cheia:      22 34 46 58 13 70 81 92 _ _ _
  vivas 8, lápides 0, busca sem sucesso: 4.27 sondagens
removidas:  X 34 X 58 X 70 X X _ _ _
  vivas 3, lápides 5, busca sem sucesso: 4.27 sondagens
refeita:    _ 34 _ 58 70 _ _ _ _ _ _
  vivas 3, lápides 0, busca sem sucesso: 1.36 sondagens
```

**Dicas:**

1. Uma sondagem é cada posição olhada, inclusive o VAZIO que encerra.
2. Depois das remoções, a tabela tem 3 chaves, mas as buscas custam o
   mesmo que com 8: a lápide conta como ocupada para quem procura.
3. Na reconstrução, o 70 (h = 4) sai da posição 5 e volta para a 4.
4. Por isso bibliotecas reconstroem a tabela quando vivas + lápides passam
   de um limite, e não só quando as vivas passam.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1522.c
```

---

**Exercício P1523** · ★★★ · O cadastro que duplicava pacientes

O posto de saúde guarda as fichas numa tabela aberta (m = 11, sondagem
linear, VAZIO = -1, LAPIDE = -2). Ela insere 10, 21, 32, 43, 5 (os quatro
primeiros com h = 10), remove o 21, procura o 32 e o 43 e tenta inserir o
32 DE NOVO (insere devolve -1 se a ficha já existe) e o 54. O código tem
DOIS erros de propósito: um na busca e um na inserção. Ache, conserte e
rode até sair:


```text
Saída esperada:
tabela: 21 32 43 _ _ 5 _ _ _ _ 10
busca 32: 1
busca 43: 2
insere 32 de novo: -1
insere 54: 0
tabela: 54 32 43 _ _ 5 _ _ _ _ 10
```

**Dicas:**

1. Antes do conserto, a busca não acha o 32 nem o 43, e o 32 aparece duas
   vezes na tabela final.
2. Na busca, o que pode encerrar a procura: o VAZIO, a LAPIDE ou os dois?
3. Na inserção, ocupar a primeira lápide é certo, mas só depois de ter
   certeza de que a chave não está mais adiante no caminho.
4. Resposta esperada: a busca para só no VAZIO (a lápide é pulada), e a
   inserção chama busca(t, k) primeiro e devolve -1 se achar. Com os dois
   consertos, a saída fica igual à de cima.

```bash
~/LPEDC/rodar 15-hash/lista/P1523.c
```

---

**Exercício P1524** · ★★★ · Os períodos em que o caixa zerou

O caixa da cantina registrou as movimentações de 10 dias, em reais:
50, -20, -30, 10, 40, -50, 20, -20, 30, -30. Quantos PERÍODOS de dias
seguidos (do dia i ao dia j) têm soma exatamente zero?

Truque: com S(j) = soma dos dias 1..j (e S(0) = 0), o período i+1..j zera
quando S(j) == S(i). Então, para cada dia j, a resposta ganha o número de
vezes que o saldo S(j) já tinha aparecido antes. Guarde essas contagens
numa tabela hash aberta (m = 31, sondagem linear) com três vetores
globais: int usada[31], soma[31], vezes[31]. Comece registrando S(0) = 0
uma vez. Mostre cada dia que fecha algum período e, no fim, compare com a
força bruta.


```text
Saída esperada:
dia 3 (saldo 0): +1
dia 5 (saldo 50): +1
dia 6 (saldo 0): +2
dia 8 (saldo 0): +3
dia 9 (saldo 30): +1
dia 10 (saldo 0): +4
períodos que zeram: 12 (força bruta: 12)
```

**Dicas:**

1. Os saldos podem ser negativos, e em C -7 % 31 é -7. Use
   h(k) = ((k % M) + M) % M para cair sempre entre 0 e M - 1.
2. Como 0 pode ser um saldo de verdade, não dá para usar 0 como "vazio":
   por isso o vetor usada[].
3. O dia 5 fecha o período 2..5 (-20 - 30 + 10 + 40 = 0): o saldo 50 já
   tinha aparecido no dia 1.
4. O hash deixa O(n); a força bruta (todos os pares i, j) é O(n²).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1524.c
```

---

**Exercício P1525** · ★★★ · Quem joga futebol e vôlei

A escolinha tem duas listas de inscritos (com um nome repetido por
engano):


```text
futebol: Lia Rui Davi Bia Caio Rui Nina
vôlei:   Bia Theo Lia Gil Nina Ana
```


Monte um CONJUNTO hash de nomes para cada esporte (encadeamento, 7 baldes,
djb2 % 7, sem repetidos) com bool contem(t, nome) e adiciona(t, nome).
Mostre, na ordem das listas e sem repetir ninguém: quem está nos dois,
quem está só no futebol, quem está só no vôlei, e o total de pessoas
diferentes (o tamanho da união). Libere os conjuntos no fim.


```text
Saída esperada:
os dois: Lia Bia Nina
só futebol: Rui Davi Caio
só vôlei: Theo Gil Ana
nos dois: 3, total de pessoas: 9
```

**Dicas:**

1. Para não listar o Rui duas vezes, use um terceiro conjunto "já
   mostrados".
2. União = (pessoas do futebol) + (só vôlei). Conte o futebol percorrendo
   o conjunto, que já não tem repetidos.
3. Cada consulta é O(1) em média: o total é O(n + m), contra O(n · m)
   comparando todo mundo com todo mundo.
4. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1525.c
```

---

**Exercício P1526** · ★★★ · O cache das páginas mais recentes

O navegador guarda as 3 páginas usadas mais recentemente (cache LRU).
Quando o cache está cheio e chega uma página nova, sai a usada há mais
tempo. As duas operações precisam ser O(1), e isso pede DUAS estruturas
juntas:

- uma lista DUPLA, da mais recente (frente) à mais antiga (fundo): mover

```text
para a frente e tirar do fundo é O(1);
```

- uma tabela hash com encadeamento (7 baldes, id % 7) que leva do id da

```text
página direto ao nó da lista.
```



```text
typedef struct Pagina {
    int id;
    struct Pagina *ant, *prox;   // lista dupla
    struct Pagina *prox_balde;   // corrente do balde
} Pagina;
```


Escreva int acessa(Cache *c, int id): se a página está no cache, é um
acerto e ela vai para a frente; se não, é uma falta: se o cache está
cheio, a do fundo sai (da lista E da tabela, com free) e a nova entra na
frente. Acessos: 10 20 10 30 40 20 10 40 50 40.


```text
Saída esperada:
página 10: falta, cache: 10
página 20: falta, cache: 20 10
página 10: acerto, cache: 10 20
página 30: falta, cache: 30 10 20
página 40: (sai 20) falta, cache: 40 30 10
página 20: (sai 10) falta, cache: 20 40 30
página 10: (sai 30) falta, cache: 10 20 40
página 40: acerto, cache: 40 10 20
página 50: (sai 20) falta, cache: 50 40 10
página 40: acerto, cache: 40 50 10
acertos: 3 de 10
```

**Dicas:**

1. Escreva acha, tira_da_lista, poe_na_frente e tira_da_tabela (com
   Pagina **pp, como na remoção do P1516).
2. O "(sai X)" é impresso dentro de acessa, antes do resultado.
3. No fim, libere percorrendo a lista: todo nó está nela.
4. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1526.c
```

---

**Exercício P1527** · ★★★ · Dispersão dupla com o tamanho errado

Na dispersão dupla, h(k, i) = (h1(k) + i · h2(k)) % m, a sequência de k só
visita todas as m posições se h2(k) e m não tiverem divisor comum. Com m
primo isso sempre vale; com m = 8, um passo par deixa metade da tabela de
fora. Mostre o problema.

Use h1(k) = k % m e h2(k) = 1 + k % (m - 1). Escreva:


```text
int sondagem(int k, int i, int m)
int visitadas(int k, int m)    quantas posições DIFERENTES a sequência
                               de k visita em m tentativas
void testa(int m, const int chaves[], int n)
```


testa monta a tabela do zero e, para cada chave, mostra h2, quantas
posições ela visita e onde ficou (ou "NÃO COUBE", se as m tentativas só
acharam posições ocupadas). Rode com m = 8 e com m = 11, chaves
3, 19, 43, 99, 59, 27.


```text
Saída esperada:
m = 8:
  3: h2 = 4, visita 2 de 8 posições, ficou na 3
  19: h2 = 6, visita 4 de 8 posições, ficou na 1
  43: h2 = 2, visita 4 de 8 posições, ficou na 5
  99: h2 = 2, visita 4 de 8 posições, ficou na 7
  59: h2 = 4, visita 2 de 8 posições, NÃO COUBE
  27: h2 = 7, visita 8 de 8 posições, ficou na 2
m = 11:
  3: h2 = 4, visita 11 de 11 posições, ficou na 3
  19: h2 = 10, visita 11 de 11 posições, ficou na 8
  43: h2 = 4, visita 11 de 11 posições, ficou na 10
  99: h2 = 10, visita 11 de 11 posições, ficou na 0
  59: h2 = 10, visita 11 de 11 posições, ficou na 4
  27: h2 = 8, visita 11 de 11 posições, ficou na 5
```

**Dicas:**

1. A sequência visita m / mdc(h2, m) posições: com m = 8 e passo 4, só 2
   (a 3 e a 7).
2. O 59 não coube com a tabela pela metade: as posições livres existiam,
   mas a sequência dele nunca passa por elas.
3. O Cormen dá duas saídas: m primo, ou m potência de 2 com h2 sempre
   ímpar.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1527.c
```

---

**Exercício P1528** · ★★★ · A teoria do fator de carga, medida

O Cormen e o Knuth dizem quanto custa, em média, uma busca SEM sucesso no
endereçamento aberto com fator de carga α:


```text
sondagem linear:                  (1 + 1/(1 - α)²) / 2
hashing uniforme (≈ dispersão dupla):  1 / (1 - α)
```


Confira na prática. Tabela de M = 1009 posições, sondagem linear
(k % M + i) % M e dupla (k % M + i · (1 + k % (M - 1))) % M. Para cada α
em 0,5, 0,75 e 0,9: reinicie a semente, encha a tabela com n = α · M
chaves sorteadas e meça a média de posições olhadas em 2000 buscas de
chaves que NÃO estão lá (1000000 + sorteio), até achar um VAZIO.

Use este gerador, para o resultado ser igual em qualquer máquina:


```text
unsigned long long semente = 2026;
int sorteia(void) {
    semente = (semente * 1103515245ULL + 12345ULL) % 2147483648ULL;
    return (int)(semente % 1000000);
}
```



```text
Saída esperada:
alfa  linear (teoria)   dupla (teoria)
0.50   2.57 ( 2.50)      2.02 ( 2.00)
0.75   9.14 ( 8.50)      3.88 ( 4.00)
0.90  49.35 (50.50)      9.73 (10.00)
```

**Dicas:**

1. Escreva double mede(int (*sonda)(int, int), double alfa) e chame com
   linear e com dupla. Ponha semente = 2026 no começo de mede.
2. Use printf("%.2f  %5.2f (%5.2f)     %5.2f (%5.2f)\n", ...).
3. Com α = 0,9, a linear custa 5 vezes a dupla: o agrupamento primário é o
   que separa as duas. Por isso tabelas abertas costumam fazer rehash
   antes de α chegar perto de 1.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1528.c
```

---

**Exercício P1529** · ★★★ · As três palavras mais usadas

Ache as 3 palavras mais frequentes do texto


```text
o sol nasce e o mar brilha e o vento sopra e o barco sai do cais e o
sol se poe no mar
```


em duas etapas: (1) conte com uma tabela de encadeamento (11 baldes,
djb2 % 11); (2) monte um vetor de PONTEIROS para os nós (No **, com
malloc do tamanho certo), ordene esse vetor com qsort (mais vezes
primeiro; empate em ordem alfabética) e mostre os 3 primeiros. Libere o
vetor e a tabela.


```text
Saída esperada:
15 palavras distintas
1º o: 5
2º e: 4
3º mar: 2
```

**Dicas:**

1. Faça conta() devolver 1 quando a palavra é nova: assim você já sabe o
   tamanho do vetor.
2. O qsort entrega ponteiros para os elementos; como os elementos são
   No *, a compara recebe No **: const No *x = *(const No *const *)a;
3. "mar" e "sol" empatam com 2: o desempate alfabético põe "mar" na frente.
4. Hash não guarda ordem; para ranquear, junte com ordenação (módulo 13).
   O custo é O(n) para contar mais O(d log d) para ordenar as d distintas.
5. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 15-hash/lista/P1529.c
```

---

**Exercício P1530** · ★★★ · O carro que passou duas vezes mais rápido

O radar da avenida anotou as placas na ordem das passagens:


```text
ABC1D23 QWE4R56 ZXC7V89 ABC1D23 JKL0M12 QWE4R56 POI3U45 ZXC7V89
JKL0M12 QWE4R56
```


Para cada placa que já tinha passado, a DISTÂNCIA é quantas passagens
separam esta da anterior da mesma placa. Ache a menor distância (no
empate, a que aparece primeiro) numa passada só, com uma tabela hash que
guarda, para cada placa, a posição da última passagem:


```text
typedef struct { char placa[8]; int ultima; } Registro;
```


Use endereçamento aberto (m = 17, sondagem linear, djb2 % 17, placa ""
= livre) e uma função Registro *registro(t, placa, &nova) que devolve o
registro da placa, criando se for nova. Mostre cada volta e o resultado.


```text
Saída esperada:
ABC1D23 voltou (distância 3)
QWE4R56 voltou (distância 4)
ZXC7V89 voltou (distância 5)
JKL0M12 voltou (distância 4)
QWE4R56 voltou (distância 4)
menor intervalo: ABC1D23, passagens 1 e 4 (distância 3)
```

**Dicas:**

1. Depois de calcular a distância, atualize r->ultima = i: a próxima volta
   é medida a partir desta passagem, não da primeira.
2. As passagens no resultado contam a partir de 1 (posição + 1).
3. Com hash, O(n); comparando cada passagem com todas as anteriores,
   O(n²).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 15-hash/lista/P1530.c
```
