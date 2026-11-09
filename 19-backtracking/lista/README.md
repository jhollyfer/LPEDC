<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 19 · Enumeração e backtracking

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/19-backtracking/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

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
3. Resposta esperada: 1, 0, 0, 2, 10, 4, 40, 92, 352. Repare que 6 tem
   menos soluções que 5.

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

## ★★☆ Para pensar

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

## ★★★ Desafio

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
