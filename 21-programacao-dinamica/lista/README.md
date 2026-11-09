<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 21 · Programação dinâmica

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/21-programacao-dinamica/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2101** · ★☆☆ · Tribonacci com e sem memória

A sequência de Tribonacci soma os TRÊS anteriores: T(0) = 0, T(1) = 0,
T(2) = 1 e T(n) = T(n - 1) + T(n - 2) + T(n - 3). O programa abaixo tem
a versão recursiva ingênua, que conta as chamadas. Estenda-o com a
versão memoizada: um vetor memo[] com -1 em "ainda não calculado", e a
função só calcula quando não sabe a resposta. Mostre T(25) e as chamadas
das duas versões.


```text
Saída esperada:
Ingênua: T(25) = 755476, 2700421 chamadas
Memoizada: T(25) = 755476, 70 chamadas
```

**Dicas:**

1. long long memo[MAX]; preencha com -1 no main antes de chamar.
2. Na memoizada, conte a chamada logo na entrada (antes de olhar o memo):
   assim a conta inclui as chamadas que voltam na hora.
3. Resposta esperada: T(25) = 755476; a ingênua faz 2700421 chamadas e
   a memoizada, só 70 (cada n de 3 a 25 calcula uma vez e chama 3).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2101.c
```

---

**Exercício P2102** · ★☆☆ · A escada com degraus quebrados

A escada do mirante tem 12 degraus, e você sobe de 1 ou de 2 degraus por
vez. Os degraus 4 e 7 estão quebrados: não dá para pisar neles. De
quantos jeitos dá para chegar ao degrau 12, saindo do chão (degrau 0)?
Escreva do zero a tabela de baixo para cima: formas[0] = 1 e, para cada
degrau i, formas[i] = formas[i - 1] + formas[i - 2], menos nos quebrados,
que ficam com 0. Mostre a tabela e a resposta.


```text
Saída esperada:
degrau  0: 1
degrau  1: 1
degrau  2: 2
degrau  3: 3
degrau  4: 0
degrau  5: 3
degrau  6: 3
degrau  7: 0
degrau  8: 3
degrau  9: 3
degrau 10: 6
degrau 11: 9
degrau 12: 15
Jeitos de chegar ao topo: 15
```

**Dicas:**

1. Cuidado com o degrau 1: só dá para chegar nele vindo do 0 (i - 2 seria
   negativo).
2. Um vetor bool quebrado[13] deixa o teste simples.
3. Resposta esperada: 15 jeitos. Sem degraus quebrados seriam 233.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2102.c
```

---

**Exercício P2103** · ★☆☆ · O carteiro e as ruas em obra

O carteiro sai da agência no canto de cima à esquerda de um bairro em
grade 5 × 6 e vai até a última casa, no canto de baixo à direita,
andando só para a direita ou para baixo. As esquinas com X estão em
obra e não dá para passar. Quantos caminhos ele tem? Complete o laço que
preenche a tabela: cam[l][c] = cam[l - 1][c] + cam[l][c - 1], com 0 nas
esquinas em obra. O programa mostra a tabela inteira.


```text
. . . . . .
. X . . X .
. . . X . .
X . . . . .
. . X . . .
```



```text
Saída esperada:
   1   1   1   1   1   1
   1   0   1   2   0   1
   1   1   2   0   0   1
   0   1   3   3   3   4
   0   1   0   3   6  10
Caminhos: 10
```

**Dicas:**

1. A partida vale 1 (se não estiver em obra). Na primeira linha e na
   primeira coluna, só há um vizinho de onde vir.
2. Trate fora da grade como 0: if (l > 0) soma o de cima; if (c > 0)
   soma o da esquerda.
3. Resposta esperada: 10 caminhos. Repare que a esquina (3, 0) em obra
   zera toda a coluna 0 abaixo dela.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2103.c
```

---

**Exercício P2104** · ★☆☆ · As fichas do fliperama

O fliperama vende fichas em pacotes de 1, 5, 6 e 9 fichas, e você quer
exatamente 11 fichas com o menor número de pacotes. O guloso pega 9 + 1
+ 1 (3 pacotes), mas dá para fazer melhor. Complete a tabela do troco
mínimo, min[v] = 1 + o menor min[v - p] entre os pacotes p que cabem, e
guarde em ult[v] o pacote usado no ótimo, para reconstruir a compra.


```text
Saída esperada:
Mínimo para 11 fichas: 2 pacotes
Compra: 5 6
```

**Dicas:**

1. min[0] = 0 e, para v de 1 a 11, comece com um valor enorme (INF) e
   teste cada pacote p <= v com min[v - p] + 1 < min[v].
2. Para reconstruir: v = 11; enquanto v > 0, mostre ult[v] e faça v -=
   ult[v].
3. Resposta esperada: 2 pacotes, 6 + 5 (ou 5 + 6: a ordem depende de
   como você testa).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2104.c
```

---

**Exercício P2105** · ★☆☆ · As fatias do bolo de rolo

A doceira vende bolo de rolo em fatias, e o preço depende do comprimento
da fatia (o preço por cm muda de um tamanho para outro):


```text
cm     1   2   3   4   5   6
R$     3   7  11  13  16  20
```


Um rolo de 10 cm pode ser cortado como ela quiser (ou não cortado, se
coubesse na tabela). Quanto ela ganha, no máximo? Este é o CORTE DE
HASTE do Cormen (15.1). Complete o laço de baixo para cima: melhor[j] é o
maior valor de um pedaço de j cm, testando a primeira fatia de cada
tamanho i e somando melhor[j - i].


```text
Saída esperada:
 1 cm: R$ 3
 2 cm: R$ 7
 3 cm: R$ 11
 4 cm: R$ 14
 5 cm: R$ 18
 6 cm: R$ 22
 7 cm: R$ 25
 8 cm: R$ 29
 9 cm: R$ 33
10 cm: R$ 36
Fatias: 1 3 3 3
```

**Dicas:**

1. melhor[0] = 0. Para cada j de 1 a 10, teste i de 1 até o menor entre j
   e 6: preco[i] + melhor[j - i].
2. Guarde em corte[j] o i que deu o máximo; para listar as fatias, ande
   de j = 10 tirando corte[j].
3. Resposta esperada: R$ 36, com fatias de 1, 3, 3 e 3 cm. A fatia de
   3 cm é a que rende mais por cm (R$ 3,67), mas 10 não é múltiplo de 3.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2105.c
```

---

**Exercício P2106** · ★☆☆ · A maior fila em ordem de altura

Na foto da turma, 10 crianças estão na ordem da chamada, com estas
alturas em cm:


```text
121 135 118 140 127 132 145 124 150 138
```


Sem trocar ninguém de lugar, a professora quer tirar crianças da foto
para que as que ficam estejam em altura crescente, deixando o MAIOR
número possível. Isso é a SUBSEQUÊNCIA CRESCENTE MÁXIMA. Escreva do zero
a PD O(n²): lis[i] é o tamanho da maior subsequência crescente que
TERMINA na criança i; lis[i] = 1 + o maior lis[j] com j < i e altura[j] <
altura[i]. Mostre lis[] e a resposta.


```text
Saída esperada:
lis: 1 2 1 3 2 3 4 2 5 4
Maior fila crescente: 5 crianças
```

**Dicas:**

1. Todo lis[i] começa em 1 (a criança sozinha).
2. A resposta é o MAIOR dos lis[i], não o último: a melhor fila pode
   terminar em qualquer criança.
3. Resposta esperada: 5 crianças, por exemplo 121 135 140 145 150 ou
   121 127 132 145 150.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2106.c
```

---

**Exercício P2107** · ★☆☆ · Plantões sem dois seguidos

Uma enfermeira pode pegar plantões extras nos próximos 9 dias, mas a
regra do hospital proíbe dois plantões em dias seguidos. Cada dia paga
um valor diferente (fim de semana e feriado pagam mais):


```text
dia:   1    2    3    4    5    6    7    8    9
R$:   180  250  160  300  120  220  400  150  210
```


Quanto ela ganha, no máximo? Escreva do zero a PD: ganho[i] é o melhor
valor usando os dias 1 a i. No dia i, ou ela não trabalha (fica
ganho[i - 1]) ou trabalha (valor[i] + ganho[i - 2]). Depois, reconstrua
os dias escolhidos andando de trás para a frente.


```text
Saída esperada:
Ganho máximo: R$ 1160
Dias: 2 4 7 9
```

**Dicas:**

1. ganho[0] = 0 e ganho[1] = valor[1]. Use índices de 1 a 9 para o
   i - 2 não sair do vetor.
2. Reconstrução: i = 9; se ganho[i] == ganho[i - 1], o dia i ficou de
   fora (i--); senão, ele entrou (mostre e i -= 2).
3. Resposta esperada: R$ 1160, nos dias 2, 4, 7 e 9.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2107.c
```

---

**Exercício P2108** · ★☆☆ · A tabela da LCS na tela

Para entender a LCS de verdade, vale ver a tabela. O programa abaixo
calcula a LCS de ARARA e ARAPUA e mostra só o tamanho. Instrumente-o:
mostre a tabela inteira, com as letras de B no cabeçalho e as de A na
frente de cada linha, como na saída. A linha 0 e a coluna 0 (a palavra
vazia) também aparecem.


```text
Saída esperada:
     -  A  R  A  P  U  A
  -  0  0  0  0  0  0  0
  A  0  1  1  1  1  1  1
  R  0  1  2  2  2  2  2
  A  0  1  2  3  3  3  3
  R  0  1  2  3  3  3  3
  A  0  1  2  3  3  3  4
LCS de ARARA e ARAPUA: 4 letras
```

**Dicas:**

1. Cabeçalho: printf("   %3c", '-') faz a margem e a coluna vazia; depois,
   cada letra de B com printf("%3c", b[j]).
2. Cada linha i começa com a letra a[i - 1] (ou '-' na linha 0) e segue
   com t[i][j] em %3d.
3. Resposta esperada: a tabela de cima, com 4 no canto (ARAA, por
   exemplo, é comum às duas).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2108.c
```

---

**Exercício P2109** · ★☆☆ · O maior trecho igual

A LCS deixa pular letras. Às vezes você quer o maior trecho CONTÍGUO que
aparece nas duas sequências: a MAIOR SUBSTRING COMUM. O laboratório
comparou dois pedaços de DNA:


```text
A: GATTACAGGT
B: TTACCAGGTA
```


Escreva do zero a PD: s[i][j] é o tamanho do maior trecho comum que
TERMINA em A[i - 1] e B[j - 1]. Se as letras são iguais, s[i][j] =
s[i - 1][j - 1] + 1; se são diferentes, o trecho quebra: s[i][j] = 0.
Guarde o maior valor e onde ele termina, e mostre o trecho.


```text
Saída esperada:
Maior trecho comum: CAGGT (5 letras)
```

**Dicas:**

1. A diferença para a LCS está só no "diferentes": aqui é 0, não o
   máximo dos vizinhos.
2. Se o maior termina em A[fim - 1] com tamanho t, o trecho é A[fim - t ..
   fim - 1]: printf("%.*s", t, a + fim - t).
3. Resposta esperada: CAGGT, com 5 letras (a LCS das duas é maior).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2109.c
```

---

**Exercício P2110** · ★☆☆ · Quantas mensagens cabem nesses números?

Um aplicativo antigo codifica letras como números: A = 1, B = 2, ...,
Z = 26, e manda tudo grudado. A sequência 226 pode ser BZ (2 26), VF
(22 6) ou BBF (2 2 6): 3 leituras. Quantas leituras tem 1122612?
Escreva do zero a PD: formas[i] é o número de leituras dos i primeiros
dígitos. O dígito i sozinho vale se não é '0'; os dígitos i - 1 e i
juntos valem se formam um número de 10 a 26.


```text
Saída esperada:
226: 3 leituras
1122612: 16 leituras
301: 0 leituras
```

**Dicas:**

1. formas[0] = 1 (a sequência vazia tem uma leitura: nenhuma letra).
2. formas[i] = (s[i - 1] != '0' ? formas[i - 1] : 0) + (i >= 2 e 10 <=
   dois dígitos <= 26 ? formas[i - 2] : 0).
3. Resposta esperada: 3 para 226, 16 para 1122612 e 0 para 301 (o 30 e o
   0 sozinho não são letras).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2110.c
```

## ★★☆ Para pensar

**Exercício P2111** · ★★☆ · Dois barcos com o mesmo peso

Oito caixas de açaí vão descer o rio em dois barcos, e para a viagem ser
segura os dois precisam levar EXATAMENTE o mesmo peso. As caixas pesam
(kg): 12 7 9 15 6 11 8 4. Dá para dividir? Este é o problema da
PARTIÇÃO: com total 72, basta achar um subconjunto que some 36. Escreva
do zero a tabela booleana pode[i][s] ("com as i primeiras caixas, dá
para somar s?") e, se der, reconstrua as caixas do primeiro barco.


```text
Saída esperada:
Barco 1: 12 9 15 (36 kg)
Barco 2: 7 6 11 8 4 (36 kg)
```

**Dicas:**

1. Total ímpar já responde "não dá". pode[0][0] = true; pode[i][s] =
   pode[i - 1][s] || (s >= peso[i - 1] && pode[i - 1][s - peso[i - 1]]).
2. Reconstrução: de (8, 36) para trás; se pode[i - 1][s] já era true, a
   caixa i - 1 não foi; senão, ela foi e s -= peso[i - 1].
3. Resposta esperada: dá. Barco 1 com 12 + 9 + 15 = 36 kg (a
   reconstrução de trás para a frente acha esta) e o resto no barco 2.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2111.c
```

---

**Exercício P2112** · ★★☆ · A mochila de uma linha só

Este programa tem um erro de propósito. A mochila 0/1 não precisa da
tabela n × W inteira: uma linha só, melhor[w], basta, desde que o laço
de w ande de TRÁS PARA A FRENTE. A feirante tem uma caixa térmica de 10
kg e quatro produtos, cada um levado inteiro ou não levado:


```text
produto   queijo  manteiga  doce  requeijão
kg          4        3       5       2
R$         40       27      45      16
```


O programa compila sem aviso e roda, mas responde R$ 96, mais do que é
possível: ele está levando o mesmo produto mais de uma vez. Conserte.


```text
Saída esperada:
Melhor valor em 10 kg: R$ 88
```

**Dicas:**

1. Acrescente um printf de melhor[] depois de cada produto. Com o laço
   de frente para trás, melhor[w - kg] já foi atualizado com o MESMO
   produto quando você chega em melhor[w].
2. De trás para a frente, melhor[w - kg] ainda é o valor da linha
   anterior (sem o produto atual).
3. Resposta esperada: for (int w = CAP; w >= kg[i]; w--). O ótimo é R$ 88:
   manteiga + doce + requeijão, exatamente 10 kg.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2112.c
```

---

**Exercício P2113** · ★★☆ · LCS de três versões

Três alunos copiaram o mesmo resumo e cada um errou umas letras. O
professor quer a maior sequência de letras que aparece, na ordem, nas
TRÊS versões. É a LCS com três strings: a tabela vira um cubo
t[i][j][k]. Se as três letras a[i - 1], b[j - 1] e c[k - 1] são iguais,
t = 1 + t[i - 1][j - 1][k - 1]; senão, o máximo de tirar uma letra de
cada uma das três (t[i - 1][j][k], t[i][j - 1][k] e t[i][j][k - 1]).
Escreva do zero e reconstrua a sequência.


```text
A: AMAZONIA
B: AMAZONAS
C: MAZOMBA
```



```text
Saída esperada:
Comum às três: MAZOA (5 letras)
```

**Dicas:**

1. int t[9][9][9]; com i, j ou k igual a 0, vale 0.
2. Reconstrução, de (m, n, p) para trás: letras iguais e t = 1 + diagonal
   entra na resposta; senão, vá para o vizinho que tem o mesmo valor.
   Monte a string de trás para a frente.
3. Resposta esperada: MAZOA, 5 letras. O custo é O(m · n · p).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2113.c
```

---

**Exercício P2114** · ★★☆ · Edição com troca mais cara

No corretor do teclado do celular, trocar uma letra por outra é menos
provável que esquecer ou repetir uma letra, então a empresa deu pesos:
inserir custa 1, remover custa 1 e TROCAR custa 2 (o mesmo que remover e
inserir). O programa abaixo é o Levenshtein comum, com troca custando 1.
Estenda-o para receber os três custos como parâmetros e mostre, para
cada par, a distância comum e a ponderada.


```text
Saída esperada:
CASA -> COISA: comum 2, troca cara 3
GATO -> PATO: comum 1, troca cara 2
BOLA -> LOBA: comum 2, troca cara 4
FEIRA -> FERIADO: comum 4, troca cara 4
```

**Dicas:**

1. Borda: d[i][0] = i · custo_remove e d[0][j] = j · custo_insere.
2. Letras iguais custam 0 na diagonal; diferentes, custo_troca.
3. Resposta esperada: com troca 2, a distância de edição é m + n - 2 ·
   LCS. CASA para COISA vai de 2 para 3; veja os outros na saída.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2114.c
```

---

**Exercício P2115** · ★★☆ · A trilha que só sobe

Um trilheiro mediu a altitude (em metros) de 12 pontos de uma trilha na
Serra do Tepequém, na ordem do caminho:


```text
640 702 655 690 735 610 760 720 805 780 850 830
```


Ele quer escolher pontos para fotografar, sem mudar a ordem, de modo que
cada foto seja num ponto MAIS ALTO que a anterior, com o maior número de
fotos. Escreva do zero a subsequência crescente máxima O(n²) com
RECONSTRUÇÃO: além de lis[i], guarde ant[i], o ponto anterior na melhor
sequência que termina em i (-1 se não há). Mostre a sequência.


```text
Saída esperada:
Fotos: 7
Altitudes: 640 655 690 735 760 805 850
```

**Dicas:**

1. Ao atualizar lis[i] = lis[j] + 1, faça ant[i] = j.
2. Ache o i com maior lis e siga ant[] até -1, guardando num vetor; mostre
   o vetor de trás para a frente.
3. Resposta esperada: 7 fotos: 640 655 690 735 760 805 850. Empate de
   lis: fica o primeiro j que achou (use >, não >=).

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2115.c
```

---

**Exercício P2116** · ★★☆ · Corte de haste com custo de corte

A serralheria vende barras de alumínio por comprimento, e cada CORTE
custa R$ 3 de mão de obra (o Cormen propõe essa variação no exercício
15.1-3). Os preços:


```text
m     1   2   3   4   5   6   7   8
R$    2   6   9  12  15  18  20  22
```


O programa abaixo é o corte de haste sem custo de corte, para uma barra
de 8 m. Estenda-o: some o custo de R$ 3 a cada corte (vender a barra
inteira não tem corte) e mostre, para as duas versões, o valor máximo e
os pedaços.


```text
Saída esperada:
Custo por corte R$ 0: R$ 24, pedaços: 2 6
Custo por corte R$ 3: R$ 22, pedaços: 8
```

**Dicas:**

1. melhor[j] = max(preco[j], max sobre i < j de preco[i] + melhor[j - i]
   - CUSTO). O pedaço inteiro entra sem custo; cada vez que você separa
   uma primeira fatia i < j, há um corte.
2. Guarde corte[j] = j quando vender inteiro é o melhor.
3. Resposta esperada: sem custo, R$ 24 com pedaços de 2 m e 6 m (quatro
   de 2 m empatam); com R$ 3 por corte, o melhor é vender a barra inteira
   por R$ 22.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2116.c
```

---

**Exercício P2117** · ★★☆ · Pagar com o mínimo de cédulas da carteira

No troco mínimo do assunto 0139, cada moeda pode ser usada quantas vezes
quiser. Na carteira não: há UMA cédula de cada. Você tem 50, 20, 20, 10,
5, 5, 2 e 2 reais e vai pagar R$ 64 exatos com o menor número de
cédulas. Escreva do zero a PD 0/1: min[s] é o menor número de cédulas
que soma s; para cada cédula, atualize min[s] de TRÁS PARA A FRENTE (como
na mochila de uma linha), e guarde quem foi usada numa tabela usou[i][s]
para reconstruir.


```text
Saída esperada:
Mínimo: 4 cédulas
Cédulas: 2 2 10 50
```

**Dicas:**

1. min[0] = 0 e o resto INF. Para a cédula i, de s = 64 até c[i]: se
   min[s - c[i]] + 1 < min[s], atualize e marque usou[i][s] = 1.
2. Reconstrução: s = 64; para i de 7 até 0, se usou[i][s], a cédula i
   entrou: s -= c[i]. (Isso funciona porque usou[i][s] guarda a decisão
   tomada com as cédulas 0..i.)
3. Resposta esperada: 4 cédulas, 50 + 10 + 2 + 2.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2117.c
```

---

**Exercício P2118** · ★★☆ · O drone que gasta menos bateria

Um drone de entregas cruza uma grade 5 × 5 de quarteirões do canto de
cima à esquerda até o canto de baixo à direita, só para a direita (D) ou
para baixo (B). Cada quarteirão gasta uma porcentagem da bateria (o
vento muda), e # é prédio alto, onde ele não pode passar:


```text
3 2 4 1 5
1 # 2 # 2
4 1 3 1 1
2 # 5 2 #
6 2 1 3 2
```


Escreva do zero a PD do CAMINHO MÍNIMO EM GRADE: custo[l][c] = gasto do
quarteirão + o menor entre custo[l - 1][c] e custo[l][c - 1]. Prédio vale
infinito. Reconstrua o caminho como uma string de D e B.


```text
Saída esperada:
Bateria gasta: 20%
Caminho: BBDDDBBD
```

**Dicas:**

1. Guarde a grade como int, com -1 no prédio. O custo inclui o
   quarteirão de saída e o de chegada.
2. Reconstrução: do fim, volte para o vizinho (de cima ou da esquerda)
   com o menor custo, empilhando 'B' ou 'D'; inverta no fim.
3. Resposta esperada: 20% da bateria, pelo caminho BBDDDBBD.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2118.c
```

---

**Exercício P2119** · ★★☆ · O triângulo do cofrinho

No jogo da quermesse, as moedas estão num triângulo. Você começa no topo
e, a cada linha, desce para a moeda logo abaixo ou para a de baixo à
direita, somando os valores (em reais). Qual o maior total?


```text
      7
     3 8
    8 1 0
   2 7 4 4
  4 5 2 6 5
 1 6 9 3 2 8
```


Testar todos os caminhos custa 2^(n-1). Escreva do zero a PD de BAIXO
PARA CIMA: a última linha já é a resposta de cada moeda; em cada linha de
cima, melhor[l][c] = t[l][c] + o maior entre melhor[l + 1][c] e
melhor[l + 1][c + 1]. O topo fica com a resposta. Mostre também o
caminho.


```text
Saída esperada:
Maior total: R$ 39
Caminho: 7 3 8 7 5 9
```

**Dicas:**

1. Guarde o triângulo numa matriz 6 × 6 em que a linha l usa as colunas 0
   a l.
2. Para o caminho, comece no topo (c = 0) e, em cada linha, vá para a
   coluna c ou c + 1, a que tiver o maior melhor[][] embaixo.
3. Resposta esperada: R$ 39, pelo caminho 7 3 8 7 5 9.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2119.c
```

---

**Exercício P2120** · ★★☆ · Quantas árvores de busca diferentes?

Com as chaves 1, 2 e 3 dá para montar 5 árvores binárias de busca
diferentes (raiz 1, 2 ou 3, e as formas das subárvores). Quantas há com
n chaves? Escolhendo a raiz r, as r - 1 chaves menores formam a
subárvore esquerda e as n - r maiores a direita, e cada combinação vale:


```text
arv(0) = 1;   arv(n) = soma, para r de 1 a n, de arv(r - 1) · arv(n - r)
```


Esses são os números de CATALAN. Escreva do zero a versão memoizada
(de cima para baixo, com memo[] e -1 em "não sei") e mostre arv(n) para
n de 1 a 15, contando quantas vezes a soma foi de fato calculada.


```text
Saída esperada:
n =  1: 1
n =  2: 2
n =  3: 5
n =  4: 14
n =  5: 42
n =  6: 132
n =  7: 429
n =  8: 1430
n =  9: 4862
n = 10: 16796
n = 11: 58786
n = 12: 208012
n = 13: 742900
n = 14: 2674440
n = 15: 9694845
Cálculos: 16
```

**Dicas:**

1. Use long long: arv(15) passa de 9 milhões.
2. Conte calculos++ só quando a função passa do teste do memo (quando
   vai realmente somar).
3. Resposta esperada: 1, 2, 5, 14, 42, ... até 9694845, com 16 cálculos
   (um para cada n de 0 a 15): sem memo, arv(15) faria milhões de
   chamadas.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2120.c
```

## ★★★ Desafio

**Exercício P2121** · ★★★ · A ordem das multiplicações de matrizes

Multiplicar uma matriz p × q por uma q × r custa p · q · r
multiplicações de números. Num produto A1 A2 A3 A4 A5, o resultado é o
mesmo em qualquer parentização, mas o custo muda muito. As dimensões
são (Ai é d[i - 1] × d[i]):


```text
d = 30 35 15 5 10 20
```


Escreva do zero a PD da MULTIPLICAÇÃO EM CADEIA (Cormen 15.2): m[i][j] é
o menor custo para multiplicar Ai..Aj; m[i][i] = 0 e, para i < j,
m[i][j] = min, para k de i a j - 1, de m[i][k] + m[k + 1][j] + d[i - 1]
· d[k] · d[j]. Preencha por tamanho de trecho crescente, guarde o k
ótimo em s[i][j] e mostre a parentização com uma função recursiva.
Compare com a ordem da esquerda para a direita.


```text
Saída esperada:
Ótimo: 11875 multiplicações com ((A1(A2A3))(A4A5))
Da esquerda para a direita: 25500 multiplicações
```

**Dicas:**

1. Laço externo: tam de 2 a n; i de 1 a n - tam + 1; j = i + tam - 1.
2. mostra(i, j): se i == j, imprime "A" e i; senão, "(", mostra(i,
   s[i][j]), mostra(s[i][j] + 1, j), ")".
3. Resposta esperada: 11875 multiplicações com ((A1(A2A3))(A4A5)),
   contra 25500 da esquerda para a direita.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2121.c
```

---

**Exercício P2122** · ★★★ · Todas as maiores subsequências comuns

A LCS nem sempre é única. Entre ABCBDAB e BDCABA (o exemplo clássico do
Cormen) há várias sequências de tamanho máximo. Escreva do zero: monte a
tabela da LCS e depois uma recursão que, a partir de (m, n), gera TODAS
as LCS: se as letras são iguais, a letra entra e você vai na diagonal;
senão, siga para CADA vizinho (de cima e da esquerda) que tem o mesmo
valor da casa atual. Caminhos diferentes podem dar a mesma string: guarde
as achadas num vetor de strings e só acrescente as novas. Mostre-as em
ordem alfabética (qsort com strcmp).


```text
Saída esperada:
LCS de ABCBDAB e BDCABA: tamanho 4
  BCAB
  BCBA
  BDAB
3 sequências diferentes
```

**Dicas:**

1. gera(i, j, buf, pos): buf é preenchido de trás para a frente; pos
   começa no tamanho da LCS. Quando pos == 0 (ou i == 0 ou j == 0),
   copie buf + pos para a lista, se for nova.
2. Na comparação do qsort, os elementos são char[8]: use strcmp(a, b)
   direto nos ponteiros recebidos.
3. Resposta esperada: 3 LCS de 4 letras: BCAB, BCBA e BDAB.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2122.c
```

---

**Exercício P2123** · ★★★ · A árvore de busca ótima do dicionário

Um dicionário de bolso tem 5 palavras, em ordem alfabética, e se sabe
quantas vezes cada uma é procurada por mil buscas:


```text
chave    açaí  boto  cuia  jambu  tacacá
buscas    15    10    5     40     30
```


Numa árvore binária de busca, procurar uma chave na profundidade p (a
raiz tem profundidade 1) custa p comparações. Qual árvore minimiza o
custo total (soma de buscas · profundidade)? Esta é a ÁRVORE DE BUSCA
ÓTIMA (Cormen 15.5, aqui sem as buscas que falham). Escreva do zero a
PD: c[i][j] é o custo ótimo para as chaves i..j; escolhendo a raiz r,
c[i][j] = c[i][r - 1] + c[r + 1][j] + soma das buscas de i a j (todas
descem um nível). Mostre o custo, a raiz de cada subárvore em pré-ordem e
compare com a árvore "equilibrada" de raiz cuia.


```text
Saída esperada:
Custo ótimo: 180 comparações
  jambu (nível 1)
  açaí (nível 2)
  boto (nível 3)
  cuia (nível 4)
  tacacá (nível 2)
Raiz cuia: 235 comparações
```

**Dicas:**

1. Use índices de 1 a 5 e c[i][i - 1] = 0 (trecho vazio). Preencha por
   tamanho de trecho, como na cadeia de matrizes, guardando raiz[i][j].
2. pre(i, j, prof): se i > j, volte; senão mostre a chave raiz[i][j] com
   a profundidade e chame para os dois lados com prof + 1.
3. Resposta esperada: custo 180, com jambu na raiz e tacacá logo abaixo.
   A árvore de raiz cuia (açaí e boto à esquerda, jambu e tacacá à
   direita) custa 235: equilibrar não é o mesmo que otimizar.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2123.c
```

---

**Exercício P2124** · ★★★ · A mochila quando a capacidade é enorme

A tabela da mochila 0/1 tem n × W casas. Quando W é enorme (um caminhão
de 100 000 kg) e os valores são pequenos, é melhor trocar de dimensão:
menor_peso[v] é o MENOR peso para conseguir valor exatamente v, e a
resposta é o maior v com menor_peso[v] <= W. Uma transportadora tem 6
lotes (peso em kg, valor em mil reais) e um caminhão de 100 000 kg:


```text
lote     1      2      3      4      5      6
kg     41000  23000  37000  18000  29000  52000
valor    12      7     11      5      9     15
```


Escreva do zero essa PD (uma linha só, v de trás para a frente, como na
mochila de uma linha) e reconstrua os lotes guardando, numa tabela
pegou[i][v], se o lote i melhorou menor_peso[v].


```text
Saída esperada:
Maior valor: 29 mil reais (99000 kg)
Lotes: 4 5 6
Posições da tabela: 60 (a mochila comum teria 100001)
```

**Dicas:**

1. A soma dos valores é 59: o vetor tem 60 posições, contra 100 001 da
   mochila comum. menor_peso[0] = 0 e o resto "infinito".
2. Para o lote i, de v = 59 até valor[i]: se menor_peso[v - valor[i]] +
   peso[i] < menor_peso[v], atualize e marque pegou[i][v].
3. Resposta esperada: 29 mil reais com os lotes 4, 5 e 6 (99000 kg). Os
   lotes 1, 2 e 3 valeriam 30, mas pesam 101000 kg.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2124.c
```

---

**Exercício P2125** · ★★★ · Dois times equilibrados

Dez amigos vão jogar futebol, e cada um tem uma nota de 1 a 10 dada pelo
grupo: Ana 8, Beto 6, Caio 9, Duda 4, Enzo 7, Fábio 5, Gabi 10, Hugo 3,
Iara 6 e João 7. Eles querem DOIS TIMES DE 5 com a soma das notas o mais
parecida possível. Escreva do zero a PD com o tamanho do time na tabela:
pode[k][s] diz se dá para escolher k jogadores com soma s. Processe os
jogadores um a um (k e s de trás para a frente, para cada um entrar uma
vez), guardando quem completou cada casa pela primeira vez para
reconstruir. Escolha a soma s com 5 jogadores mais perto de total / 2.


```text
Saída esperada:
Time 1: Ana Beto Caio Duda Fábio (32 pontos)
Time 2: Enzo Gabi Hugo Iara João (33 pontos)
```

**Dicas:**

1. Total 65: o ideal seria 32,5, então a melhor diferença possível é 1
   (32 contra 33).
2. quem[k][s] = índice do jogador que tornou pode[k][s] verdadeiro pela
   primeira vez. Reconstrução: j = quem[5][s]; ele entra; k = 4; s -=
   nota[j]; e assim por diante. Como ele foi processado antes dos
   seguintes, a casa (k - 1, s - nota[j]) foi formada só com jogadores
   de índice menor.
3. Resposta esperada: times de 32 e 33 pontos (diferença 1); confira os
   nomes na saída.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2125.c
```

---

**Exercício P2126** · ★★★ · Subsequência crescente em O(n log n)

A PD O(n²) da subsequência crescente máxima fica lenta com 1 milhão de
valores. Existe um jeito O(n log n): mantenha fim[k] = o MENOR valor que
termina uma subsequência crescente de tamanho k + 1 achada até agora. O
vetor fim[] é sempre crescente, então, para cada valor x, uma BUSCA
BINÁRIA acha a primeira posição com fim[k] >= x: x substitui fim[k] (ou
estende o vetor, se maior que todos). O tamanho de fim[] é a resposta.

Na academia, a carga do supino (kg) em 16 treinos seguidos foi:


```text
40 42 38 45 43 47 41 50 48 52 44 55 53 49 58 60
```


Escreva do zero, guardando o ÍNDICE do valor em cada fim[k] e, para cada
treino, o índice do anterior na sequência (ant[]), para reconstruir a
maior sequência de treinos com carga sempre crescente.


```text
Saída esperada:
Maior sequência crescente: 9 treinos
Cargas: 40 42 43 47 48 52 53 58 60
```

**Dicas:**

1. Guarde idx[k] (o índice do valor que está em fim[k]). Ao colocar x na
   posição k, ant[i] = k > 0 ? idx[k - 1] : -1.
2. A reconstrução começa em idx[tam - 1] e segue ant[] até -1.
3. Resposta esperada: 9 treinos: 40 42 43 47 48 52 53 58 60. Há outras
   de mesmo tamanho (40 42 45 47 50 52 55 58 60, por exemplo); o fim[]
   com o menor final de cada tamanho leva a esta.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2126.c
```

---

**Exercício P2127** · ★★★ · A distância que erra por uma letra

Este programa tem um erro de propósito. Ele calcula a distância de
edição (Levenshtein: inserir, remover ou trocar, custo 1 cada) entre
pares de palavras e compila sem aviso e roda limpo no sanitizer, mas os
números estão errados: diz que CAVALO e CAVALO estão a distância 2,
por exemplo. Ache e conserte o erro. A tabela, a borda e o mínimo dos
três vizinhos estão certos.


```text
Saída esperada:
CAVALO -> CAVALO: 0
CAVALO -> CABELO: 2
MANAUS -> MANAUARA: 3
TUCANO -> TUCUMA: 3
```

**Dicas:**

1. Instrumente: mostre a tabela de CAVALO com CAVALO. A diagonal devia
   ficar toda com 0.
2. A casa d[i][j] fala dos prefixos a[0..i - 1] e b[0..j - 1]. Quais são
   as últimas letras desses prefixos? Compare com o que o programa olha.
3. Resposta esperada: compare a[i - 1] com b[j - 1]. A tabela tem uma
   linha e uma coluna a mais que as strings (a da palavra vazia), por
   isso os índices andam deslocados de um.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2127.c
```

---

**Exercício P2128** · ★★★ · As reservas que dão mais dinheiro

O salão de festas recebeu 8 pedidos de reserva para sábado, cada um
[ini, fim) em horas e com o valor que o cliente paga:


```text
pedido   A       B       C       D        E        F        G        H
horas  [8,11)  [9,13)  [10,12) [11,15)  [12,16)  [14,18)  [15,20)  [17,22)
R$      400     700     300     600      500     1500      900      450
```


Como no módulo 20, só cabe uma festa por vez. Mas agora o objetivo é o
MAIOR FATURAMENTO, e o guloso "termina primeiro" não serve mais. A PD da
SELEÇÃO DE INTERVALOS COM PESOS: ordene por fim; p[j] é o último pedido
(na ordem) que termina até o início do j; melhor[j] = max(melhor[j - 1],
valor[j] + melhor[p[j]]). Escreva do zero, ache p[j] por busca binária e
reconstrua os pedidos aceitos.


```text
Saída esperada:
Faturamento máximo: R$ 2200
Pedidos: B F
```

**Dicas:**

1. Indexe de 1 a 8 depois de ordenar, com melhor[0] = 0 e p[j] = 0
   quando nenhum termina antes.
2. Reconstrução: j = 8; se valor[j] + melhor[p[j]] >= melhor[j - 1], o
   pedido j entrou (j = p[j]); senão, j--.
3. Resposta esperada: R$ 2200 com B e F. O guloso "termina primeiro"
   pega A, D e G: mais festas (3), mas só R$ 1900.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2128.c
```

---

**Exercício P2129** · ★★★ · Juntar os sacos vizinhos

No armazém, 6 sacos de farinha estão enfileirados, com 4, 7, 2, 6, 3 e 5
kg. A máquina junta DOIS SACOS VIZINHOS num só, e o custo da operação é
o peso do saco resultante. Ela repete até sobrar um saco. Qual a ordem
mais barata? Se desse para juntar quaisquer dois (não só vizinhos), o
guloso de Huffman (módulo 20) resolveria. Com a regra dos vizinhos, o
guloso falha e entra a PD DE INTERVALOS: c[i][j] é o menor custo para
transformar os sacos i..j em um; c[i][i] = 0 e c[i][j] = min, para k de
i a j - 1, de c[i][k] + c[k + 1][j] + soma(i, j). Escreva do zero as
duas contas e mostre a ordem ótima entre vizinhos como parênteses.


```text
Saída esperada:
Só vizinhos: custo 70 com ((4 7) ((2 6) (3 5)))
Quaisquer dois (Huffman): custo 68
```

**Dicas:**

1. É a mesma forma da multiplicação em cadeia: preencha por tamanho de
   trecho e guarde o k ótimo em s[i][j].
2. Para o custo "quaisquer dois", repita: ache os dois menores pesos,
   some o resultado ao custo e troque os dois pelo resultado (com 6
   sacos, dois laços simples bastam).
3. Resposta esperada: o custo entre vizinhos é maior que o de Huffman,
   e a ordem ótima está na saída.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2129.c
```

---

**Exercício P2130** · ★★★ · O caixeiro viajante do Amazonas

Um vendedor sai de Manaus, visita Itacoatiara, Manacapuru, Parintins,
Tefé e Coari (cada uma uma vez) e volta a Manaus. As distâncias (em
horas de barco, num mapa simplificado) estão na matriz do main. Testar
as 5! = 120 ordens funciona, mas com 20 cidades seriam 19! (mais de 10^17).
A PD de HELD-KARP faz O(2^n · n²): custo[S][v] é o menor tempo para sair
de Manaus, passar por TODAS as cidades do conjunto S (uma máscara de
bits) e terminar em v (v está em S). Então


```text
custo[S][v] = min, para u em S sem v, de custo[S sem v][u] + dist[u][v]
```


e a resposta é o min de custo[todas][v] + dist[v][0]. Escreva do zero a
PD, reconstrua a rota e confira com a força bruta das permutações.


```text
Saída esperada:
Held-Karp: 94 horas
Rota: Manaus > Manacapuru > Coari > Tefé > Parintins > Itacoatiara > Manaus
Força bruta: 94 horas
```

**Dicas:**

1. As cidades 1 a 5 são os bits 0 a 4 de S (cidade v é o bit v - 1).
   custo[{v}][v] = dist[0][v]. Percorra S em ordem crescente: todo
   subconjunto de S é menor que S.
2. Guarde em pai[S][v] o u que deu o mínimo; para reconstruir, ande de
   (todas, último) tirando v de S a cada passo.
3. Resposta esperada: o tempo mínimo e a rota da saída, iguais nos dois
   métodos. A PD preenche 32 · 5 casas; a força bruta, 120 rotas.

```bash
~/LPEDC/rodar 21-programacao-dinamica/lista/P2130.c
```
