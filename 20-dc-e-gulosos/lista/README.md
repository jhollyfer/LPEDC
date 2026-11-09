<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 20 · Divisão e conquista e algoritmos gulosos

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/20-dc-e-gulosos/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2001** · ★☆☆ · A senha do painel

No painel do posto de saúde, as senhas chamadas hoje estão em ordem
crescente: 3 8 12 15 21 27 33 40 46 52 58 64 71 79 85 90. Escreva do
zero a busca binária RECURSIVA busca(v, ini, fim, x): olha o meio; se é
x, devolve o índice; se x é menor, procura só na metade da esquerda;
senão, só na da direita. Pedaço vazio (ini > fim) devolve -1. Conte as
chamadas e procure as senhas 64, 3 e 50.


```text
Saída esperada:
Senha 64: posição 11 (2 chamadas)
Senha 3: posição 0 (4 chamadas)
Senha 50: não chamada (5 chamadas)
```

**Dicas:**

1. int meio = ini + (fim - ini) / 2; escrito assim, ini + fim nunca
   estoura em vetores enormes.
2. Zere o contador antes de cada busca. Com 16 elementos, são no máximo
   lg 16 + 1 = 5 chamadas que olham o vetor, mais a do pedaço vazio.
3. Resposta esperada: 64 na posição 11 (2 chamadas), 3 na posição 0 (4
   chamadas) e 50 não chamada (5 chamadas, a última com o pedaço vazio).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2001.c
```

---

**Exercício P2002** · ★☆☆ · Maior e menor temperatura, dividindo ao meio

A estação de Manaus registrou as máximas de 8 dias: 31 34 29 36 33 30 35
32 graus. Complete a função recursiva extremos(v, ini, fim, &menor,
&maior), que acha os DOIS de uma vez por divisão e conquista: um
elemento só é menor e maior ao mesmo tempo (0 comparações); dois
elementos custam 1 comparação; com mais, divida ao meio, resolva cada
metade e junte com 2 comparações (menor com menor, maior com maior).
Conte as comparações entre temperaturas.


```text
Saída esperada:
Menor: 29 graus
Maior: 36 graus
Comparações: 10
```

**Dicas:**

1. No caso de dois elementos: comps++; if (v[ini] < v[fim]) {...} else
   {...}.
2. Para juntar: chame para [ini, meio] e [meio + 1, fim] com variáveis
   locais e faça dois comps++.
3. Resposta esperada: menor 29, maior 36 e 10 comparações, que é 3n/2 -
   2 para n = 8. Achar os dois com dois laços separados custaria 2(n - 1)
   = 14.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2002.c
```

---

**Exercício P2003** · ★☆☆ · Os três últimos dígitos de 3^200

3^200 tem 96 dígitos e não cabe em nenhum inteiro do C. Mas para saber
só os três últimos dígitos basta fazer a conta módulo 1000, reduzindo
depois de cada multiplicação: (a · b) % m = ((a % m) · (b % m)) % m.
Complete potmod(b, e, m), a potência rápida recursiva do assunto 0131
com o resto em cada passo, e conte as multiplicações. Mostre 3^200,
7^222 e 2^1000, todos módulo 1000.


```text
Saída esperada:
3^200 termina em 001 (11 multiplicações)
7^222 termina em 049 (14 multiplicações)
2^1000 termina em 376 (16 multiplicações)
```

**Dicas:**

1. potmod(b, 0, m) = 1 % m. Para e > 0: calcule meia = potmod(b, e / 2,
   m); o resultado é meia · meia % m, e, se e for ímpar, mais uma vez
   vezes b % m.
2. Use long long: 999 · 999 cabe folgado, mas o hábito evita estouro
   quando m for grande.
3. Resposta esperada: 3^200 termina em 001, 7^222 em 049 e 2^1000 em
   376; as multiplicações estão na saída de cima.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2003.c
```

---

**Exercício P2004** · ★☆☆ · O caixa da feira com poucas moedas

A barraca de tapioca tem no caixa só 2 notas de R$ 10, 3 de R$ 5, 4
moedas de R$ 2 e 5 de R$ 1. O guloso do troco continua valendo (sempre a
maior que cabe), mas agora ele precisa respeitar o estoque: uma nota só
sai se ainda há dela. Complete troco(valor), que mostra o que sai, tira
do estoque e devolve 1 se conseguiu pagar tudo (0 se faltou). Dê, nesta
ordem, os trocos de R$ 27, R$ 18 e R$ 9.


```text
Saída esperada:
Troco de R$ 27: 10 10 5 2
Troco de R$ 18: 5 5 2 2 2 1 1
Troco de R$ 9: 1 1 1
  faltou troco!
Sobrou no caixa: 0 de 10, 0 de 5, 0 de 2, 0 de 1
```

**Dicas:**

1. Para cada valor de nota, do maior para o menor: enquanto a nota cabe
   no que falta E estoque[i] > 0, entregue uma.
2. O estoque é global: o troco de 27 gasta notas que o de 18 não terá.
3. Resposta esperada: 27 = 10 + 10 + 5 + 2; 18 = 5 + 5 + 2 + 2 + 2 + 1 +
   1; o de 9 falha, porque sobram só 3 moedas de R$ 1.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2004.c
```

---

**Exercício P2005** · ★☆☆ · A melhor semana da lanchonete

A lanchonete anotou o lucro (ou prejuízo) de 10 dias, em reais:


```text
dia:    0    1    2    3    4    5    6    7    8    9
lucro: -40  120  -30   80  -150  60   90  -20   70  -60
```


Qual sequência de dias SEGUIDOS deu o maior lucro somado? Escreva do
zero o subvetor de soma máxima por divisão e conquista (assunto 0132),
mas devolvendo também ONDE ele começa e termina: use um struct Trecho {
int ini, fim, soma; }. O trecho que cruza o meio é o melhor final da
esquerda grudado no melhor começo da direita.


```text
Saída esperada:
Melhor trecho: dias 1 a 8
Lucro: R$ 220
```

**Dicas:**

1. Caso base: um dia só é o trecho (i, i, v[i]).
2. Cruzando: a partir de meio, ande para a esquerda guardando a maior
   soma e onde ela começa; a partir de meio + 1, para a direita
   guardando a maior soma e onde ela termina.
3. Resposta esperada: dias 1 a 8, lucro de R$ 220. Vale a pena atravessar
   o prejuízo de R$ 150 do dia 4: os dias 5 a 8 sozinhos dão R$ 200.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2005.c
```

---

**Exercício P2006** · ★☆☆ · O barco de Parintins

Um barco sai de Manaus para Parintins com 500 kg livres no porão. O dono
pode levar qualquer quantidade (dá para fracionar) de cinco produtos:


```text
produto     kg disponíveis   valor total (R$)
castanha         200              3000
farinha          300              1500
guaraná          100              2500
pirarucu         150              4200
cupuaçu          250              2000
```


Escreva do zero a mochila fracionária: um struct Produto com nome, kg e
valor; ordene com qsort pela razão valor/kg, da maior para a menor; leve
inteiro enquanto couber e, no primeiro que não cabe, só a parte que
cabe. Mostre o que vai e o valor total.


```text
Saída esperada:
pirarucu: 150 kg, R$ 4200.00
guaraná: 100 kg, R$ 2500.00
castanha: 200 kg, R$ 3000.00
cupuaçu: 50 kg, R$ 400.00
Total: R$ 10100.00
```

**Dicas:**

1. As razões são 15, 5, 25, 28 e 8 R$/kg.
2. Na comparação do qsort, compare as razões com < e > e devolva -1, 0
   ou 1; subtrair doubles e converter para int estraga a ordem.
3. Resposta esperada: pirarucu, guaraná e castanha inteiros (450 kg) e
   50 kg de cupuaçu: R$ 10100.00.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2006.c
```

---

**Exercício P2007** · ★☆☆ · O código que confunde

O código de Huffman é LIVRE DE PREFIXO: nenhum código é o começo de
outro, e por isso dá para ler a sequência de bits sem separador. Um
estagiário montou três tabelas para os símbolos A, B, C, D e E e quer
saber quais servem. Escreva do zero livre_de_prefixo(cod, n), que
compara cada par de códigos e devolve 0 ao achar um que é começo do
outro (mostrando qual), ou 1 se a tabela serve.


```text
Tabela 1: A=0   B=10  C=110  D=1110  E=1111
Tabela 2: A=0   B=01  C=110  D=111   E=10
Tabela 3: A=00  B=01  C=10   D=110   E=111
```



```text
Saída esperada:
Tabela 1:
  serve
Tabela 2:
  A=0 é começo de B=01
  não serve
Tabela 3:
  serve
```

**Dicas:**

1. a é prefixo de b quando strlen(a) <= strlen(b) e strncmp(a, b,
   strlen(a)) == 0.
2. Teste os dois sentidos para cada par i < j.
3. Resposta esperada: as tabelas 1 e 3 servem; na 2, o 0 do A é começo
   do 01 do B (e "01" poderia ser AE... ou B).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2007.c
```

---

**Exercício P2008** · ★☆☆ · Os consertos da oficina

O mecânico faz um conserto por dia e tem 6 pedidos. Cada pedido tem um
prazo (até que dia o cliente aceita esperar) e um valor; se ficar para
depois do prazo, o cliente vai embora. Os pedidos JÁ estão em ordem
decrescente de valor:


```text
pedido   A    B    C    D    E    F
valor   300  250  200  150  100   80
prazo    2    1    2    3    3    1
```


O guloso do AGENDAMENTO COM PRAZOS pega os pedidos do mais valioso para
o menos e põe cada um no ÚLTIMO dia livre que ainda está dentro do prazo
dele (deixando os dias cedo para quem tem prazo curto). Se não há dia
livre, o pedido é recusado. Complete o laço que procura o dia.


```text
Saída esperada:
Recusado: C (R$ 200)
Recusado: E (R$ 100)
Recusado: F (R$ 80)
Dia 1: B (R$ 250)
Dia 2: A (R$ 300)
Dia 3: D (R$ 150)
Total: R$ 700
```

**Dicas:**

1. Os dias vão de 1 a 3 (o maior prazo). dia[d] guarda o índice do
   pedido do dia d, ou -1.
2. for (int d = prazo[i]; d >= 1; d--) if (dia[d] == -1) { dia[d] = i;
   break; }
3. Resposta esperada: dia 1 B, dia 2 A, dia 3 D, total R$ 700.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2008.c
```

---

**Exercício P2009** · ★☆☆ · Quando a razão engana

A mochila fracionária é resolvida pelo guloso da razão valor/peso. Na
mochila 0/1 (cada item vai inteiro ou não vai), o mesmo guloso pode
errar. Uma mochila de 50 kg e três itens:


```text
item   peso   valor
TV      10     600
som     20    1000
PC      30    1200
```


O programa abaixo já tem o guloso 0/1 (pega pela razão, inteiro, se
couber). Complete otimo(), que testa os 2^3 subconjuntos por máscara de
bits (assunto 0125) e devolve o maior valor que cabe. Mostre os dois.


```text
Saída esperada:
Guloso pela razão: R$ 1600
Ótimo (força bruta): R$ 2200
```

**Dicas:**

1. for (int m = 0; m < (1 << N); m++): some peso e valor dos itens com o
   bit ligado; se o peso cabe e o valor é o maior até agora, guarde.
2. As razões são 60, 50 e 40 R$/kg: o guloso pega TV e som e sobram 20
   kg, onde o PC não cabe.
3. Resposta esperada: guloso R$ 1600, ótimo R$ 2200 (som + PC).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2009.c
```

---

**Exercício P2010** · ★☆☆ · A poltrona com o próprio número

No teatro, os ingressos vendidos (já em ordem crescente e sem repetição)
foram para as poltronas -5 -2 0 1 2 5 9 12 15 18 (o negativo é o
camarote). O gerente desconfia que algum ingresso está na POSIÇÃO igual
ao próprio número: v[i] == i. Escreva do zero pos_fixa(v, ini, fim), por
divisão e conquista como a busca binária: se v[meio] < meio, a resposta
só pode estar à direita; se v[meio] > meio, só à esquerda. Conte as
chamadas.


```text
Saída esperada:
Posição 5: v[5] = 5
Chamadas: 3
```

**Dicas:**

1. Por que dá para jogar metade fora? Com valores inteiros distintos e
   crescentes, v[i + 1] >= v[i] + 1: a diferença v[i] - i nunca diminui.
2. Se v[meio] - meio < 0, à esquerda todas as diferenças são < 0.
3. Resposta esperada: posição 5 (v[5] = 5), em 3 chamadas.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2010.c
```

## ★★☆ Para pensar

**Exercício P2011** · ★★☆ · Mínimo e máximo de dois em dois

O aplicativo da corrida de rua guarda os tempos dos 10 atletas da
categoria, em segundos: 1520 1384 1702 1455 1611 1398 1830 1290 1477
1563. Achar o menor com um laço e o maior com outro custa 2(n - 1) = 18
comparações. Dá para fazer com 3n/2 - 2: ande de DOIS em DOIS, compare
os dois entre si (1 comparação), depois o menor deles com o mínimo e o
maior com o máximo (mais 2). São 3 comparações para cada 2 elementos.
Escreva do zero as duas versões, contando as comparações, e mostre os
resultados.


```text
Saída esperada:
Ingênuo: menor 1290, maior 1830, 18 comparações
Aos pares: menor 1290, maior 1830, 13 comparações
```

**Dicas:**

1. Comece com o primeiro par: compare v[0] com v[1] (1 comparação) e
   eles viram o mínimo e o máximo iniciais. Depois, de i = 2 em diante,
   de 2 em 2.
2. Com n ímpar, o primeiro elemento sozinho seria mínimo e máximo, e os
   pares começariam em i = 1. Aqui n = 10.
3. Resposta esperada: 1290 e 1830 nas duas; 18 comparações contra 13
   (3 · 10 / 2 - 2). É o limite inferior para achar os dois (Cormen 9.1).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2011.c
```

---

**Exercício P2012** · ★★☆ · As duas antenas mais próximas

A operadora tem 8 antenas de celular num bairro, em coordenadas (em
centenas de metros): (2, 3) (12, 30) (40, 50) (5, 1) (12, 10) (3, 4)
(31, 33) (18, 21). Duas antenas muito perto se atrapalham. Qual é o PAR
MAIS PRÓXIMO? A força bruta testa os 28 pares. Escreva do zero a divisão
e conquista simples: ordene por x, divida ao meio, resolva cada metade,
e depois olhe só os pontos da FAIXA a menos de d da linha do meio (d é a
menor distância das metades), comparando cada um com os da faixa. Use
força bruta quando houver 3 pontos ou menos. Mostre o par, a distância e
quantas distâncias cada método calculou.


```text
Saída esperada:
Força bruta: (2, 3) e (3, 4), 1.41, 28 distâncias
Divisão e conquista: (2, 3) e (3, 4), 1.41, 6 distâncias
```

**Dicas:**

1. Ordene uma cópia com qsort por x. Trabalhe com a distância ao
   quadrado (inteira) e tire a raiz só no fim, com sqrt de <math.h>.
2. Na faixa, monte um vetor com os pontos em que (x - xmeio)^2 < d e
   compare-os dois a dois (com poucos pontos, a força bruta na faixa
   basta; com muitos, ordene a faixa por y).
3. Resposta esperada: (2, 3) e (3, 4), distância 1.41 (raiz de 2).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2012.c
```

---

**Exercício P2013** · ★★☆ · A mediana sem ordenar tudo

Na fila do banco, o gerente cronometrou o atendimento de 11 clientes, em
minutos: 7 15 3 22 9 4 18 11 6 13 2. Ele quer a MEDIANA (o 6º menor) sem
ordenar o vetor inteiro. O SELECT pela partição do quicksort faz isso:
particione em volta de um pivô; se o pivô caiu na posição k, achou; se
k está à esquerda, continue só na esquerda; senão, só na direita. Uma
metade só, a cada passo. Complete seleciona(v, ini, fim, k), usando a
particao (Lomuto, pivô = último) que já está no programa.


```text
Saída esperada:
 6º menor: 9 (partições: 3)
 1º menor: 2 (partições: 1)
11º menor: 22 (partições: 5)
```

**Dicas:**

1. int p = particao(v, ini, fim); if (p == k) return v[p];
2. Se k < p, chame para (ini, p - 1); senão, para (p + 1, fim). k é o
   índice no vetor inteiro, não muda.
3. Resposta esperada: mediana 9; o 1º menor é 2 e o 11º é 22.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2013.c
```

---

**Exercício P2014** · ★★☆ · Quantas salas para o congresso?

O congresso de computação em Manaus tem 9 palestras, cada uma num
intervalo [ini, fim) em horas:


```text
[9, 11) [9, 10) [10, 12) [11, 13) [10, 11) [12, 14) [13, 15) [9, 12)
[14, 16)
```


Qual é o MENOR número de salas para que nenhuma palestra tenha choque?
Diferente da seleção de atividades (que escolhe um subconjunto), aqui
todas acontecem. O guloso: ordene pelo início e ponha cada palestra
numa sala que já ficou livre (fim da última palestra dela <= ini); se
nenhuma está livre, abra uma sala nova. Escreva do zero e mostre a sala
de cada palestra e o total.


```text
Saída esperada:
[9, 10) -> sala 1
[9, 11) -> sala 2
[9, 12) -> sala 3
[10, 11) -> sala 1
[10, 12) -> sala 4
[11, 13) -> sala 1
[12, 14) -> sala 2
[13, 15) -> sala 1
[14, 16) -> sala 2
Salas: 4
```

**Dicas:**

1. Guarde livre_em[s], a hora em que a sala s fica livre. Para cada
   palestra, na ordem do início, use a primeira sala com livre_em[s] <=
   ini.
2. Ordene por início com qsort num vetor de structs { ini, fim }; empate
   de início, o que termina antes vem primeiro.
3. Resposta esperada: 4 salas. Entre 10h e 11h há quatro palestras ao
   mesmo tempo ([9, 11), [9, 12), [10, 11) e [10, 12)), então nenhum
   arranjo usa menos: o guloso acerta o ótimo.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2014.c
```

---

**Exercício P2015** · ★★☆ · Huffman sem heap, para poucos símbolos

Com só 6 símbolos, o heap é exagero: dá para achar os dois nós de menor
frequência com um laço simples, O(n) por passo. A rádio comunitária vai
transmitir boletins com as letras A, E, M, N, O e S, com estas
frequências (em cada 100 letras):


```text
A: 30   E: 20   M: 5   N: 10   O: 25   S: 10
```


Escreva do zero a árvore de Huffman num vetor de nós (folhas nas
posições 0 a 5, nós internos de 6 em diante), cada nó com freq, esq, dir
e um flag de "já usado". Em cada passo, junte os dois de menor
frequência ainda não usados. Depois, calcule a profundidade de cada
folha (o tamanho do código) e o total de bits.


```text
Saída esperada:
A: freq 30, código de 2 bits
E: freq 20, código de 2 bits
M: freq  5, código de 4 bits
N: freq 10, código de 4 bits
O: freq 25, código de 2 bits
S: freq 10, código de 3 bits
Total: 240 bits (código fixo: 300)
```

**Dicas:**

1. menor_livre(n) devolve o índice do nó livre de menor freq entre 0 e n
   - 1 (empate: o de menor índice). Chame duas vezes, marcando o
   primeiro como usado antes de procurar o segundo.
2. A profundidade sai de uma recursão a partir da raiz (o último nó
   criado): prof(no, d) chega na folha com d = tamanho do código.
3. Resposta esperada: 240 bits para as 100 letras, contra 300 de um
   código fixo de 3 bits.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2015.c
```

---

**Exercício P2016** · ★★☆ · O menor atraso da gráfica

A gráfica tem 5 encomendas e uma impressora só. Cada encomenda tem a
duração (em horas) e o prazo (a hora, contando do início do dia, em que
o cliente vem buscar):


```text
encomenda   convites  cardápios  banner  folhetos  crachás
duração         3          2        4        1         2
prazo           6          4       10        3         7
```


O atraso de uma encomenda é max(0, fim - prazo). O guloso PRAZO MAIS
CEDO PRIMEIRO (ordenar por prazo) minimiza o MAIOR atraso. Escreva do
zero: compare a ordem da tabela com a ordem por prazo, mostrando o
início e o fim de cada encomenda e o maior atraso de cada ordem.


```text
Saída esperada:
Ordem da tabela:
  convites: 0 a 3 (prazo 6, atraso 0)
  cardápios: 3 a 5 (prazo 4, atraso 1)
  banner: 5 a 9 (prazo 10, atraso 0)
  folhetos: 9 a 10 (prazo 3, atraso 7)
  crachás: 10 a 12 (prazo 7, atraso 5)
  Maior atraso: 7 h
Prazo mais cedo primeiro:
  folhetos: 0 a 1 (prazo 3, atraso 0)
  cardápios: 1 a 3 (prazo 4, atraso 0)
  convites: 3 a 6 (prazo 6, atraso 0)
  crachás: 6 a 8 (prazo 7, atraso 1)
  banner: 8 a 12 (prazo 10, atraso 2)
  Maior atraso: 2 h
```

**Dicas:**

1. Use um struct { nome, dur, prazo } e qsort pelo prazo para a segunda
   ordem. A hora corrente começa em 0 e soma a duração de cada uma.
2. Por que funciona? Trocar duas encomendas vizinhas fora da ordem de
   prazo nunca aumenta o maior atraso (o argumento de troca do Cormen).
3. Resposta esperada: a ordem da tabela tem atraso máximo 7 (os folhetos
   ficam prontos às 10, com prazo 3) e a ordem por prazo, só 2.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2016.c
```

---

**Exercício P2017** · ★★☆ · Os postos da BR-319

Um carro sai de Manaus pela BR-319 rumo a Porto Velho, 880 km, e o
tanque cheio dá 250 km. Os postos ficam nos quilômetros 90, 180, 240,
330, 420, 470, 560, 650, 700 e 790. O motorista quer parar o MENOR
número de vezes. O guloso: só pare quando o próximo posto ficar fora do
alcance, e pare no posto mais distante que ainda dá para alcançar.
Escreva do zero e mostre as paradas e o total; se algum trecho entre
postos for maior que 250 km, avise que é impossível.


```text
Saída esperada:
Parada 1: km 240
Parada 2: km 470
Parada 3: km 700
Chegou a Porto Velho com 3 paradas
```

**Dicas:**

1. Ponha o destino como último "posto" (km 880). Guarde ultima, o km do
   último abastecimento (começa em 0).
2. Enquanto o destino não está ao alcance (880 - ultima > 250): ande pelos
   postos enquanto posto[i + 1] - ultima <= 250; pare em posto[i].
3. Resposta esperada: 3 paradas, nos km 240, 470 e 700.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2017.c
```

---

**Exercício P2018** · ★★☆ · Quem tem maioria absoluta?

Na eleição do síndico, os 15 votos (números dos candidatos) foram:


```text
4 7 4 4 2 4 7 4 9 4 4 2 4 7 4
```


Um candidato tem MAIORIA ABSOLUTA se recebeu mais da metade dos votos.
Escreva do zero por divisão e conquista: se v[ini..fim] tem majoritário,
ele é majoritário de pelo menos uma das metades. Então resolva as duas
metades e, para cada candidato que voltar, conte os votos dele no
pedaço inteiro. Devolva -1 se não houver. Mostre o resultado também para
a apuração da segunda urna: 1 2 3 1 2 3 1 2.


```text
Saída esperada:
Urna 1: candidato 4, com 9 de 15 votos
Urna 2: ninguém tem maioria
```

**Dicas:**

1. Caso base: um voto só é majoritário de si mesmo.
2. conta(v, ini, fim, x) em O(n); a recorrência fica T(n) = 2T(n/2) +
   O(n), ou seja, O(n log n).
3. Resposta esperada: na primeira urna, o 4, com 9 de 15 votos; na
   segunda, ninguém.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2018.c
```

---

**Exercício P2019** · ★★☆ · Rotas de ônibus com potência de matriz

Quatro terminais de ônibus (T0 a T3) são ligados por linhas diretas,
dadas pela matriz de adjacência A (A[i][j] = 1 se há linha de Ti para
Tj). Um fato bonito: o elemento (i, j) de A^k conta quantas rotas de
EXATAMENTE k trechos vão de Ti a Tj. Calcule A^k pela potência rápida
(assunto 0131), trocando a multiplicação de números pela de matrizes 4 ×
4, e mostre quantas rotas de T0 a T3 existem com 3, 6 e 12 trechos, e
quantos produtos de matriz cada potência custou.


```text
A = | 0 1 1 0 |
    | 1 0 1 1 |
    | 1 1 0 1 |
    | 0 1 1 0 |
```



```text
Saída esperada:
 3 trechos: 2 rotas de T0 a T3 (4 produtos)
 6 trechos: 58 rotas de T0 a T3 (5 produtos)
12 trechos: 15178 rotas de T0 a T3 (6 produtos)
```

**Dicas:**

1. Um typedef struct { long long m[4][4]; } Mat; facilita devolver
   matriz de função. A identidade é o caso base (k = 0).
2. potencia(A, k): meia = potencia(A, k / 2); r = meia · meia; se k é
   ímpar, r = r · A. Conte cada chamada de multiplica.
3. Resposta esperada: com 3 trechos são 2 rotas (T0 T1 T2 T3 e T0 T2 T1
   T3); com 12 trechos, 15178, em só 6 produtos de matriz.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2019.c
```

---

**Exercício P2020** · ★★☆ · A fila do cartório

Seis pessoas chegaram juntas ao cartório e há um atendente só. Os
serviços levam 12, 3, 8, 1, 20 e 5 minutos, na ordem de chegada. A
espera de cada um é a soma das durações de quem foi atendido antes. O
guloso que minimiza a ESPERA MÉDIA é atender primeiro o serviço mais
curto. O programa abaixo já calcula a espera média na ordem de chegada.
Estenda-o: ordene as durações (qsort) e mostre a nova ordem e a nova
espera média.


```text
Saída esperada:
Ordem de chegada: 12 3 8 1 20 5 -> espera média 19.67 min
Mais curto primeiro: 1 3 5 8 12 20 -> espera média 10.00 min
```

**Dicas:**

1. Reaproveite a função espera_media, chamando-a de novo depois do qsort.
2. Por que o mais curto primeiro? O serviço na posição i (contando de 0)
   entra na espera dos n - 1 - i que vêm depois: o mais curto deve ser o
   que "pesa" mais vezes.
3. Resposta esperada: de 19.67 para 10.00 minutos.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2020.c
```

## ★★★ Desafio

**Exercício P2021** · ★★★ · Karatsuba contra os quatro produtos

Para multiplicar x e y de n dígitos por divisão e conquista, escreva x =
a·p + b e y = c·p + d, com p = 10^(n/2). O jeito direto faz QUATRO
produtos menores (ac, ad, bc, bd): T(n) = 4T(n/2) + O(n), que é O(n²) e
não ganha nada da escola. Karatsuba faz TRÊS (ac, bd e (a + b)(c + d)):
T(n) = 3T(n/2) + O(n), O(n^1,59). Escreva do zero as duas versões,
recursivas, com caso base "um dos números tem 1 dígito" (aí multiplica
direto e conta 1), e compare as contagens para 12345678 × 87654321 e
para 99999999 × 99999999.


```text
Saída esperada:
12345678 x 87654321 = 1082152022374638
  4 produtos: 64 multiplicações (resultado certo)
  Karatsuba: 33 multiplicações (resultado certo)
99999999 x 99999999 = 9999999800000001
  4 produtos: 64 multiplicações (resultado certo)
  Karatsuba: 63 multiplicações (resultado certo)
```

**Dicas:**

1. n é a quantidade de dígitos do MAIOR dos dois; p = 10^(n / 2).
2. Quatro produtos: ac·p² + (ad + bc)·p + bd. Karatsuba: meio =
   (a + b)(c + d) - ac - bd no lugar de ad + bc.
3. Resposta esperada: os produtos certos e, para os números de 8
   dígitos, 64 multiplicações de um dígito na versão de 4 produtos
   (8 · 8, a mesma conta da escola). Karatsuba gasta 33 no primeiro e 63
   no segundo: com os 9s, cada a + b ganha um dígito (99 + 99 = 198) e a
   recursão desce um nível a mais.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2021.c
```

---

**Exercício P2022** · ★★★ · Strassen numa matriz 4 × 4

O produto de matrizes n × n pela definição custa n³ multiplicações. Em
1969, Strassen dividiu cada matriz em quatro blocos n/2 × n/2 e mostrou
que bastam SETE produtos de blocos, e não oito:


```text
M1 = (A11 + A22)(B11 + B22)   M5 = (A11 + A12) B22
M2 = (A21 + A22) B11          M6 = (A21 - A11)(B11 + B12)
M3 = A11 (B12 - B22)          M7 = (A12 - A22)(B21 + B22)
M4 = A22 (B21 - B11)
C11 = M1 + M4 - M5 + M7       C12 = M3 + M5
C21 = M2 + M4                 C22 = M1 - M2 + M3 + M6
```


Escreva do zero strassen(n, A, B, C) recursiva, caso base n == 1, e
conte as multiplicações de números. Para não precisar de matriz de
tamanho variável, toda matriz é int [4][4] e a função usa só o canto
n × n de cima à esquerda. Multiplique as matrizes 4 × 4 do main pelos
dois métodos e confira que dão o mesmo resultado.


```text
Saída esperada:
  14  10   5   5
  10   7   5  12
   9  11   7   9
  12   3   9  14
Definição: 64 multiplicações
Strassen: 49 multiplicações
Resultados iguais
```

**Dicas:**

1. Escreva auxiliares soma(n, x, y, r), subtrai(n, x, y, r), pega(n, m,
   l0, c0, bloco) (copia um bloco) e poe(n, bloco, m, l0, c0).
2. Os blocos são VLAs locais int a11[N][N], com h = n / 2. Com n = 4 a
   pilha aguenta folgada.
3. Resposta esperada: o produto de cima, 64 multiplicações na definição
   e 49 no Strassen (7 · 7). Para n = 2^k, são 7^k contra 8^k: O(n^2,81).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2022.c
```

---

**Exercício P2023** · ★★★ · Huffman de ida e volta

Escreva do zero, sem o TAD do módulo, um Huffman completo para a frase


```text
MANAUS AMAZONAS
```


(1) conte as frequências dos caracteres; (2) monte a árvore com um
heap-mínimo de índices de nós, escrito à mão (sobe e desce do assunto
de heap), juntando sempre os dois de menor frequência; (3) gere o código
de cada caractere (esquerda = 0, direita = 1); (4) codifique a frase numa
string de '0' e '1'; (5) decodifique essa string descendo a árvore e
confira que voltou a frase original. Para a saída sair igual, desempate
no heap pelo índice do nó (o menor índice sai primeiro), crie as folhas
em ordem de código ASCII e ponha o primeiro retirado à esquerda.


```text
Saída esperada:
' ' 1 vez(es): 1010
'A' 5 vez(es): 11
'M' 2 vez(es): 010
'N' 2 vez(es): 011
'O' 1 vez(es): 1011
'S' 2 vez(es): 100
'U' 1 vez(es): 000
'Z' 1 vez(es): 001
Bits: 010110111100010010101101011001101101111100
15 caracteres, 42 bits (ASCII: 120)
Decodificado: MANAUS AMAZONAS (igual)
```

**Dicas:**

1. Nós num vetor: folhas de 0 a f - 1, internos depois. menor(i, j)
   compara freq e, no empate, o índice.
2. Para gerar os códigos, uma recursão com um buffer char cod[32] e a
   profundidade: na folha, copie o buffer para a tabela do caractere.
3. Resposta esperada: 15 caracteres, 42 bits (contra 120 em ASCII de 8
   bits) e a frase decodificada igual à original.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2023.c
```

---

**Exercício P2024** · ★★★ · O máximo de entregas no prazo

A lavanderia recebeu 7 pedidos para hoje. Cada um leva um tempo (em
horas de máquina) e tem um prazo (a hora em que o cliente vem buscar).
A máquina lava um pedido por vez. Pedido atrasado é cliente perdido,
então o dono quer o MAIOR NÚMERO de pedidos prontos no prazo:


```text
pedido   A  B  C  D  E  F  G
tempo    2  4  3  1  5  2  3
prazo    3  5  6  7  9 10 11
```


O algoritmo de Moore-Hodgson é guloso: percorra os pedidos por prazo
crescente, sempre aceitando o pedido; se a soma dos tempos aceitos passa
do prazo do pedido atual, DESCARTE o aceito de MAIOR tempo (é o que mais
libera a máquina). Escreva do zero, mostrando cada descarte e, no fim,
os pedidos aceitos e a hora em que cada um fica pronto.


```text
Saída esperada:
Descarta B (tempo 4)
Descarta E (tempo 5)
A pronto às 2 (prazo 3)
C pronto às 5 (prazo 6)
D pronto às 6 (prazo 7)
F pronto às 8 (prazo 10)
G pronto às 11 (prazo 11)
Pedidos no prazo: 5
```

**Dicas:**

1. Os pedidos já estão em ordem de prazo. Guarde os aceitos num vetor
   (com 7 pedidos, procurar o de maior tempo com um laço basta; com
   milhares, use um heap de máximo).
2. Descartar o maior pode descartar o próprio pedido que acabou de
   entrar: tudo bem.
3. Resposta esperada: descarta B e E e entrega 5 pedidos: A, C, D, F e G.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2024.c
```

---

**Exercício P2025** · ★★★ · A mediana das medianas

O SELECT pela partição (com pivô qualquer) pode cair no pior caso O(n²).
O algoritmo da MEDIANA DAS MEDIANAS (Cormen 9.3) escolhe um pivô bom de
propósito: divida o vetor em grupos de 5, ache a mediana de cada grupo
(ordenando os 5 com insertion sort), ache recursivamente a mediana
dessas medianas e use-a como pivô. Assim cada lado da partição tem pelo
menos cerca de 3n/10 elementos, e o tempo é O(n) no pior caso.

Os 23 lances de um leilão de gado, em mil reais, estão no main. Escreva
do zero seleciona(v, n, k), que devolve o k-ésimo menor (k a partir de
0) com esse pivô, e mostre o menor, a mediana (k = 11) e o maior,
conferindo com o vetor ordenado por qsort.


```text
Saída esperada:
Menor: 41 (qsort: 41)
Mediana: 69 (qsort: 69)
Maior: 98 (qsort: 98)
```

**Dicas:**

1. Com n <= 5, ordene e devolva v[k]. Senão, copie as medianas dos grupos
   para um vetor med[] (o último grupo pode ter menos de 5) e chame
   seleciona(med, ng, ng / 2) para achar o pivô.
2. Particione em três vetores: menores, iguais e maiores que o pivô (com
   malloc, e free no fim). Se k < nmen, desça nos menores; se k < nmen +
   nig, a resposta é o pivô; senão, desça nos maiores com k - nmen - nig.
3. Resposta esperada: menor 41, mediana 69 e maior 98, iguais ao qsort.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2025.c
```

---

**Exercício P2026** · ★★★ · Comprar barato, vender caro

O preço de fechamento de uma ação em 12 pregões, em reais:


```text
dia:    0  1  2  3  4  5  6  7  8  9 10 11
preço: 31 27 34 22 25 41 36 19 24 33 38 29
```


Você compra num dia i e vende num dia j > i. Qual o maior lucro? Por
divisão e conquista: o melhor negócio está todo na metade esquerda, ou
todo na direita, ou compra na esquerda e vende na direita (aí é o menor
preço da esquerda com o maior da direita). Escreva do zero uma função
que, para v[ini..fim], devolve num struct o lucro, os dias de compra e
venda, e também o menor e o maior preço do pedaço (com os dias), para o
caso que cruza sair em O(1). Confira com a força bruta de todos os pares.


```text
Saída esperada:
Compra no dia 3 (R$ 22), vende no dia 5 (R$ 41)
Lucro: R$ 19
Força bruta: R$ 19
```

**Dicas:**

1. Caso base, um dia só: lucro 0 (não há venda), menor = maior = v[i].
2. Junte: cruza = d.maior - e.menor; o menor do pedaço é o menor entre
   e.menor e d.menor; o maior, o maior entre e.maior e d.maior. Com o
   trabalho de junção O(1), a recorrência é T(n) = 2T(n/2) + O(1), O(n).
3. Resposta esperada: compra no dia 3 (R$ 22) e vende no dia 5 (R$ 41),
   lucro R$ 19. A força bruta concorda.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2026.c
```

---

**Exercício P2027** · ★★★ · Quantos passaram?

Este programa tem um erro de propósito. As notas da turma (vezes 10,
para ficar em inteiros) estão em ordem crescente, com repetições:


```text
35 40 50 60 70 70 70 85 90 100
```


Aprovado é quem tem nota >= 70. A função primeira(v, ini, fim, x) devia
devolver, por busca binária recursiva, o índice do PRIMEIRO elemento >=
x (ou n, se nenhum for); os aprovados são n menos esse índice. Ela
compila sem aviso e roda limpo, mas diz que só 3 passaram, e para nota de
corte 50 diz 7. Conserte a função (o main está certo).


```text
Saída esperada:
Corte 70: 6 aprovados
Corte 50: 8 aprovados
Corte 101: 0 aprovados
```

**Dicas:**

1. Acrescente um printf com ini, fim e meio em cada chamada e veja o que
   acontece quando v[meio] é igual a x.
2. Se v[meio] >= x, o meio PODE ser a resposta (ou haverá outra igual
   antes dele): procure em [ini, meio], sem jogar o meio fora. Se v[meio]
   < x, a resposta está em [meio + 1, fim].
3. Resposta esperada: troque o > por >= no teste. 6 aprovados com corte
   70, 8 com corte 50 e 0 com corte 101.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2027.c
```

---

**Exercício P2028** · ★★★ · Vigias para o dia inteiro

O condomínio precisa de vigia das 0h às 24h, sem buraco, e cada vigia da
lista só aceita um turno fixo [ini, fim] (horas, e um turno cobre de ini
até fim, inclusive as pontas):


```text
Edu [0, 6]   Bia [2, 9]   Gil [5, 12]   Ana [8, 14]   Caio [10, 18]
Rui [15, 20]   Lia [17, 24]   Davi [19, 24]   Teo [0, 4]
```


Contratar custa caro: qual o MENOR número de vigias que cobre [0, 24]?
O guloso da COBERTURA DE INTERVALOS: com a cobertura indo até a hora t
(começa em 0), entre os turnos que começam em t ou antes, escolha o que
termina MAIS TARDE; agora t vira o fim dele. Pare quando t chegar a 24 ou
quando ninguém conseguir avançar (aí há um buraco). Escreva do zero e,
depois, rode de novo sem a Caio e mostre onde fica o buraco.


```text
Saída esperada:
Todos:
  Edu [0, 6]
  Gil [5, 12]
  Caio [10, 18]
  Lia [17, 24]
  Total: 4 vigias
Sem a Caio:
  Edu [0, 6]
  Gil [5, 12]
  Ana [8, 14]
  Buraco: ninguém cobre depois das 14h
```

**Dicas:**

1. Com poucos turnos, cada passo pode olhar todos (O(n²) no total);
   ordenando por início dá O(n log n).
2. "Ninguém consegue avançar" é: o melhor fim achado é <= t.
3. Resposta esperada: 4 vigias (Edu, Gil, Caio e Lia); sem a Caio, a
   cobertura trava às 14h: o Rui só chega às 15h.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2028.c
```

---

**Exercício P2029** · ★★★ · Juntando as notas de quatro turmas

A secretaria tem as notas de 4 turmas, cada lista já em ordem crescente,
e quer uma lista única ordenada. Intercalar uma a uma (a primeira com a
segunda, o resultado com a terceira...) faz os primeiros elementos serem
comparados de novo a cada rodada. Por divisão e conquista, intercale as
turmas 0 e 1, as 2 e 3, e depois os dois resultados: com k listas são
só lg k rodadas. Escreva do zero intercala(a, na, b, nb, saida), que
conta as comparações, e as duas estratégias. Mostre a lista final e as
comparações de cada uma.


```text
Turma 0: 52 61 78 90 95          Turma 1: 48 55 70
Turma 2: 35 66 74 81 88 93 99    Turma 3: 40 59
```



```text
Saída esperada:
Lista: 35 40 48 52 55 59 61 66 70 74 78 81 88 90 93 95 99
Uma a uma: 25 comparações
Divisão e conquista: 24 comparações
Listas iguais: sim
```

**Dicas:**

1. A intercalação do merge sort: compare a[i] com b[j] (1 comparação),
   copie o menor; quando uma acabar, copie o resto da outra sem comparar.
2. junta(listas, ini, fim): com ini == fim devolve a própria lista; senão
   junta a metade de cima, a de baixo e intercala as duas. Use vetores
   locais de tamanho 17 (o total).
3. Resposta esperada: a mesma lista, com 25 comparações uma a uma e 24
   por divisão e conquista. A diferença é pequena com listas curtas; com
   k listas de m notas, uma a uma custa O(k² m) e a divisão e conquista,
   O(k m lg k).

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2029.c
```

---

**Exercício P2030** · ★★★ · O guloso que pinta demais

Oito transmissores de rádio comunitária ficam em dois morros: A0, A1, A2
e A3 num, B0, B1, B2 e B3 no outro. Ai interfere com Bj sempre que i !=
j (e os do mesmo morro não interferem entre si). Transmissores que
interferem precisam de frequências diferentes. Isso é colorir o grafo, e
o guloso popular é: percorra os vértices numa ordem e dê a cada um a
menor frequência que nenhum vizinho já pintado usa. Escreva do zero:
(a) o guloso na ordem A0 B0 A1 B1 A2 B2 A3 B3; (b) o guloso na ordem A0
A1 A2 A3 B0 B1 B2 B3; (c) o mínimo de cores por backtracking (como no
módulo 19). Mostre a frequência de cada um e o total de cada método.


```text
Saída esperada:
Guloso intercalado: A0=0 A1=1 A2=2 A3=3 B0=0 B1=1 B2=2 B3=3 (4 frequências)
Guloso por morro: A0=0 A1=0 A2=0 A3=0 B0=1 B1=1 B2=1 B3=1 (2 frequências)
Ótimo: A0=0 A1=0 A2=0 A3=0 B0=1 B1=1 B2=1 B3=1 (2 frequências)
```

**Dicas:**

1. Numere A0..A3 como 0..3 e B0..B3 como 4..7; viz(u, v) é verdadeiro
   quando um é A, o outro é B e os números são diferentes.
2. guloso(ordem[]) usa cor[] = -1 para "ainda não pintado" e procura a
   menor cor c que nenhum vizinho pintado tem.
3. Resposta esperada: a ordem intercalada usa 4 frequências, a ordem por
   morro usa 2, e o ótimo é 2. O guloso depende da ordem e pode errar
   feio: neste tipo de grafo (a "coroa"), com n pares, ele chega a n cores.

```bash
~/LPEDC/rodar 20-dc-e-gulosos/lista/P2030.c
```
