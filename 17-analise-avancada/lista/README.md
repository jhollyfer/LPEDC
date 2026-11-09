<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 17 · Medindo algoritmos recursivos

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/17-analise-avancada/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1701** · ★☆☆ · O faturamento somado pelas metades

A padaria guarda o faturamento de cada dia (em reais) num vetor. A função
soma(v, ini, fim) do esqueleto soma v[ini..fim] dividindo o pedaço ao meio e
somando as duas metades. A recorrência do número de chamadas é


```text
C(1) = 1,  C(n) = C(⌈n/2⌉) + C(⌊n/2⌋) + 1
```


Confira no computador que C(n) = 2n - 1, para QUALQUER n (não só potência
de 2): acrescente um contador global de chamadas e mostre, para n = 1, 2,
3, 4, 10, 16, 64 e 100, a soma dos n primeiros dias, as chamadas contadas e
2n - 1.


```text
Saída esperada:
  n       soma  chamadas  2n-1
  1        900         1     1
  2       1850         3     3
  3       2850         5     5
  4       3900         7     7
 10      10200        19    19
 16      16550        31    31
 64      67050       127   127
100     104750       199   199
```

**Dicas:**

1. Some 1 no contador na primeira linha de soma(). Zere o contador antes
   de cada n.
2. A árvore de recursão tem n folhas (um dia cada) e n - 1 nós internos
   (cada um junta dois pedaços): 2n - 1 nós no total.
3. Por isso o custo é Θ(n): dividir ao meio não deixa a soma mais rápida
   que um laço; só muda a forma.
4. Resposta esperada: as duas colunas de chamadas são sempre iguais; com
   n = 100 são 199 chamadas.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1701.c
```

---

**Exercício P1702** · ★☆☆ · A maior nota dividindo a turma em três

Complete a função maior3(v, ini, n), que acha a maior nota de v[ini ..
ini + n - 1] dividindo o pedaço em TRÊS terços iguais (n é potência de 3),
achando a maior de cada terço com uma chamada recursiva e comparando as
três. Um contador global soma 1 a cada chamada.

A recorrência das chamadas é C(1) = 1 e C(n) = 3 C(n/3) + 1. Pela árvore
de recursão, C(n) = 1 + 3 + 9 + ... + n = (3n - 1) / 2. Mostre, para n = 1,
3, 9, 27, 81 e 243, a maior nota, as chamadas contadas e (3n - 1) / 2.


```text
Saída esperada:
  n  maior  chamadas  (3n-1)/2
  1     11         1         1
  3     85         4         4
  9     95        13        13
 27     98        40        40
 81    100       121       121
243    100       364       364
```

**Dicas:**

1. Caso base: n == 1, devolve v[ini]. Senão, t = n / 3 e as chamadas são
   em ini, ini + t e ini + 2t, todas com tamanho t.
2. A árvore tem log₃ n + 1 níveis, com 3^i nós no nível i: a soma da
   progressão geométrica dá (3n - 1) / 2.
3. Pelo teorema mestre, T(n) = 3 T(n/3) + Θ(1) é o caso 1 (n^(log₃ 3) = n
   ganha de 1): Θ(n), como um laço.
4. Resposta esperada: com n = 243, 364 chamadas, igual a (3 · 243 - 1) / 2.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1702.c
```

---

**Exercício P1703** · ★☆☆ · O hodômetro do ônibus: custo amortizado em base 10

O hodômetro mecânico de um ônibus tem 4 rodinhas de dígitos (0000 a 9999)
e soma 1 a cada quilômetro. Girar uma rodinha custa 1. Quase sempre só a
rodinha das unidades gira, mas de 0999 para 1000 giram quatro.

Guarde os dígitos num vetor int d[4] (d[0] = unidades) e escreva int
incrementa(int d[]), que soma 1 e devolve quantas rodinhas giraram. Mostre
o custo de cada passo de 0997 até 1000, e o custo TOTAL e o custo por
incremento depois de 10, 100, 1000 e 10000 quilômetros a partir de 0000.


```text
Saída esperada:
0998 (giraram 1)
0999 (giraram 1)
1000 (giraram 4)
   10 km:    11 rodinhas, 1.100 por km
  100 km:   111 rodinhas, 1.110 por km
 1000 km:  1111 rodinhas, 1.111 por km
10000 km: 11110 rodinhas, 1.111 por km
```

**Dicas:**

1. incrementa: i = 0; enquanto i < 4 e d[i] == 9, d[i] = 0 e i++ (cada
   uma é uma rodinha girada); se i < 4, d[i]++ (mais uma).
2. Análise agregada: em n incrementos, a rodinha das unidades gira n
   vezes, a das dezenas n/10, a das centenas n/100... A soma fica abaixo
   de n · 10/9 ≈ 1,111 n.
3. Em 10000 km o hodômetro volta para 0000: a rodinha dos milhares também
   gira 10 vezes.
4. Resposta esperada: 1, 1 e 4 rodinhas nos passos 0997 -> 0998 -> 0999 ->
   1000; 1111 rodinhas em 1000 km e 11110 em 10000 km (1,111 por km).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1703.c
```

---

**Exercício P1704** · ★☆☆ · Contador binário: quantas vezes cada bit troca

A catraca da academia conta os acessos num contador binário de 8 bits,
guardado em int b[8] (b[0] é o bit menos significativo). Incrementar custa
o número de bits trocados.

Escreva int incrementa(int b[]) e um programa que faça 32 incrementos a
partir de 00000000, mostrando os oito primeiros (o contador e o custo) e,
no fim, quantas vezes CADA bit trocou, o total e o limite 2n da análise
agregada.


```text
Saída esperada:
00000001  custo 1
00000010  custo 2
00000011  custo 1
00000100  custo 3
00000101  custo 1
00000110  custo 2
00000111  custo 1
00001000  custo 4
bit 0: 32 trocas
bit 1: 16 trocas
bit 2:  8 trocas
bit 3:  4 trocas
bit 4:  2 trocas
bit 5:  1 trocas
bit 6:  0 trocas
bit 7:  0 trocas
Total: 63 trocas em 32 incrementos (limite 2n = 64)
```

**Dicas:**

1. incrementa: enquanto b[i] == 1, zere b[i] e avance i (cada um é uma
   troca); depois, se i < 8, b[i] = 1 (mais uma troca).
2. Some 1 em trocas[i] a cada troca do bit i: é a análise agregada do
   Cormen olhando bit por bit.
3. O bit i troca a cada 2^i incrementos: n, n/2, n/4, ... A soma é menor
   que 2n, então o custo amortizado é O(1) por incremento, mesmo com um
   incremento isolado custando até 8.
4. Resposta esperada: o bit 0 troca 32 vezes, o bit 1 16, ..., o bit 5
   uma vez; total 63, abaixo de 2n = 64.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1704.c
```

---

**Exercício P1705** · ★☆☆ · A árvore de recursão do merge sort, nível por nível

O merge sort do esqueleto ordena os preços de 16 produtos. A recorrência
é T(n) = 2 T(n/2) + n: cada chamada com um pedaço de tamanho m custa m (o
trabalho de intercalar).

Instrumente o merge sort com um parâmetro nivel (a raiz é o nível 0) e,
em vetores globais, acumule por nível o número de chamadas e o custo (a
soma dos tamanhos dos pedaços). Mostre a tabela da árvore de recursão para
n = 16 e para n = 10 e o custo total. Para n potência de 2, o total é
n lg n + n: lg n + 1 níveis com custo n cada.


```text
Saída esperada:
n = 16: 2 3 5 7 8 9 11 12 15 18 19 22 25 30 33 40
nível  chamadas  custo
    0         1     16
    1         2     16
    2         4     16
    3         8     16
    4        16     16
Total: 80
n = 10: 3 5 8 9 12 15 18 22 30 40
nível  chamadas  custo
    0         1     10
    1         2     10
    2         4     10
    3         8     10
    4         4      4
Total: 44
```

**Dicas:**

1. Acrescente int nivel aos parâmetros: a chamada recursiva passa
   nivel + 1. Logo no começo, faça nos[nivel]++ e custo[nivel] += m.
2. Conte também as folhas (pedaços de tamanho 1): elas formam o último
   nível, com custo 1 cada.
3. Com n = 10 os pedaços não têm o mesmo tamanho, e o último nível fica
   incompleto. Mesmo assim cada nível cheio custa n.
4. Resposta esperada: n = 16 dá 5 níveis de custo 16 (total 80 = 16 · 4 +
   16); n = 10 dá 5 níveis, o último com 4 chamadas e custo 4 (total 44).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1705.c
```

---

**Exercício P1706** · ★☆☆ · O desfazer do editor: pilha com multipop

Um editor de texto guarda cada tecla digitada numa pilha. "Desfazer k"
tira k teclas de uma vez (ou todas, se houver menos de k): é o MULTIPOP. O
custo real de empilhar é 1, e o de desfazer k é min(k, tamanho da pilha).

Complete int multipop(Pilha *p, int k), que devolve quantas teclas tirou,
e rode a sessão do esqueleto mostrando o custo de cada operação, o maior
custo de uma operação só, o custo total e o limite 2 · (empilhamentos) da
análise amortizada.


```text
Saída esperada:
digita "manaux" custo  6 | texto: "manaux"
desfaz 1        custo  1 | texto: "manau"
digita "s! ok"  custo  5 | texto: "manaus! ok"
desfaz 12       custo 10 | texto: ""
digita "oi"     custo  2 | texto: "oi"
desfaz 1        custo  1 | texto: "o"
Empilhadas 13, tiradas 12, total 25 (limite 2 x 13 = 26)
Operação mais cara: 10
```

**Dicas:**

1. multipop: enquanto k > 0 e a pilha não estiver vazia, tire o topo e
   diminua k. Devolva quantas saíram.
2. Uma operação isolada pode custar muito (o "desfazer 12" custa 10), mas
   cada tecla só sai da pilha se entrou antes: o total de pops não passa
   do total de pushes.
3. Por isso n operações custam no máximo 2n: custo amortizado O(1).
4. Resposta esperada: 13 teclas empilhadas, 12 tiradas, total 25, dentro
   do limite 26; a operação mais cara custou 10.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1706.c
```

---

**Exercício P1707** · ★☆☆ · Insertion sort recursivo e a recorrência T(n-1) + n

Escreva do zero um insertion sort RECURSIVO para as senhas de atendimento
de uma agência: ordena(v, n) ordena v[0..n-2] com uma chamada recursiva e
depois insere v[n-1] na posição certa, deslocando os maiores. Conte as
comparações entre elementos num contador global.

A recorrência do pior caso é T(1) = 0 e T(n) = T(n - 1) + (n - 1), que
soma 1 + 2 + ... + (n - 1) = n(n - 1)/2. No melhor caso, cada inserção faz
uma comparação só: n - 1. Mostre as comparações para os três vetores de 10
senhas do esqueleto, junto com n - 1 e n(n - 1)/2.


```text
Saída esperada:
crescente     9 comparações: 101 102 103 104 105 106 107 108 109 110
decrescente  45 comparações: 101 102 103 104 105 106 107 108 109 110
misturado    26 comparações: 101 102 103 104 105 106 107 108 109 110
Melhor caso n - 1 = 9 | pior caso n(n - 1)/2 = 45
```

**Dicas:**

1. Caso base: n <= 1, nada a fazer. Depois da chamada, x = v[n - 1];
   j = n - 2; enquanto j >= 0 e (conte 1) v[j] > x, desloque v[j] para
   v[j + 1].
2. Conte a comparação ANTES de testar: se o laço para porque j < 0, não
   houve comparação.
3. O vetor crescente é o melhor caso (Θ(n)), o decrescente o pior
   (Θ(n²)). O misturado fica no meio.
4. Resposta esperada: 9 comparações no crescente, 45 no decrescente e 26
   no misturado.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1707.c
```

---

**Exercício P1708** · ★☆☆ · Quão funda fica a pilha de chamadas

A recorrência mede o TEMPO; a altura da árvore de recursão mede a PILHA.
O esqueleto tem duas somas recursivas das contas de luz de um condomínio,
as duas com Θ(n) chamadas:

- soma_fila(v, n) = v[n - 1] + soma_fila(v, n - 1): T(n) = T(n - 1) + 1;
- soma_meio(v, ini, fim) divide ao meio: T(n) = 2 T(n/2) + 1.

Instrumente as duas com um parâmetro de profundidade e guarde a maior
profundidade alcançada (a raiz tem profundidade 1). Mostre, para n = 10,
100 e 1000, as chamadas e a profundidade máxima de cada uma.


```text
Saída esperada:
n =   10  fila: soma   1385,   11 chamadas, profundidade   11
          meio: soma   1385,   19 chamadas, profundidade    5
n =  100  fila: soma  15350,  101 chamadas, profundidade  101
          meio: soma  15350,  199 chamadas, profundidade    8
n = 1000  fila: soma 154400, 1001 chamadas, profundidade 1001
          meio: soma 154400, 1999 chamadas, profundidade   11
```

**Dicas:**

1. Passe prof + 1 nas chamadas recursivas e atualize uma variável global
   max_prof logo no começo da função.
2. soma_fila desce até n == 0: a pilha chega a n + 1 chamadas abertas ao
   mesmo tempo.
3. soma_meio para em pedaços de 1 elemento. A altura é ⌈lg n⌉ + 1: com
   n = 1000, só 11 chamadas abertas, contra 1001.
4. Resposta esperada: as duas somas dão o mesmo valor; chamadas n + 1 e
   2n - 1; profundidades 1001 e 11 para n = 1000.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1708.c
```

---

**Exercício P1709** · ★☆☆ · A função que se chama duas vezes à toa

Um colega escreveu a função do esqueleto para calcular a meta de vendas do
mês n de uma loja: a meta dobra todo mês, e a de janeiro (n = 1) é R$ 100.
Ela funciona, mas chama meta(n - 1) DUAS vezes com o mesmo argumento:


```text
C(1) = 1,  C(n) = 2 C(n - 1) + 1  =>  C(n) = 2^n - 1 chamadas
```


Acrescente um contador de chamadas, escreva meta_boa(n), que chama
meta_boa(n - 1) uma vez só e guarda o resultado numa variável (C(n) =
C(n - 1) + 1 = n), e mostre, para n = 1, 5, 10, 20 e 25, a meta e as
chamadas das duas versões, junto com 2^n - 1.


```text
Saída esperada:
 n        meta  ruim: chamadas     2^n-1  boa: chamadas
 1         100                1         1              1
 5        1600               31        31              5
10       51200             1023      1023             10
20    52428800          1048575   1048575             20
25  1677721600         33554431  33554431             25
```

**Dicas:**

1. Use long para a meta: 100 · 2^24 passa de 1,6 bilhão.
2. A árvore de recursão da versão ruim é uma árvore binária cheia de
   altura n - 1: 2^n - 1 nós.
3. 2^n - 1 dá para calcular com (1L << n) - 1.
4. Resposta esperada: com n = 25, a meta é 1677721600, a versão ruim faz
   33554431 chamadas e a boa, 25.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1709.c
```

---

**Exercício P1710** · ★☆☆ · Adivinhe o preço: o limite da árvore de decisão

No programa de auditório, o participante adivinha um preço inteiro de 1 a
n reais, e o apresentador responde "é esse", "mais" ou "menos". Qualquer
estratégia é uma árvore de decisão com n respostas possíveis; uma árvore
binária de altura h tem no máximo 2^h - 1 nós de "é esse", então o pior
caso precisa de pelo menos ⌈lg(n + 1)⌉ palpites.

A busca binária atinge esse limite. Escreva:


```text
int palpites(int n, int preco);   // palpites da busca binária até acertar
int teto_lg(int x);               // menor h com 2^h >= x, só com inteiros
```


e mostre, para n = 7, 15, 100, 1000 e 1000000, o pior caso da busca
binária (testando TODOS os preços de 1 a n) e o limite ⌈lg(n + 1)⌉.


```text
Saída esperada:
      n  pior caso  limite
      7          3       3
     15          4       4
    100          7       7
   1000         10      10
1000000         20      20
```

**Dicas:**

1. palpites: ini = 1, fim = n; a cada volta, chute meio = (ini + fim) / 2
   e conte 1; se acertou, pare; se o preço é maior, ini = meio + 1; senão,
   fim = meio - 1.
2. teto_lg: h = 0, p = 1; enquanto p < x, p *= 2 e h++. Use long para p.
3. Com n = 1000000, testar todos os preços custa uns 20 milhões de passos:
   roda em menos de um segundo.
4. Resposta esperada: as duas colunas são iguais; 3, 4, 7, 10 e 20.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1710.c
```

## ★★☆ Para pensar

**Exercício P1711** · ★★☆ · A árvore de 3T(n/4) + n² contada por nível

A recorrência T(n) = 3 T(n/4) + n² é o exemplo clássico da árvore de
recursão no Cormen. Transforme-a num programa: trabalho(n, nivel) faz n²
unidades de trabalho (um laço duplo que soma 1 num contador do nível) e se
chama três vezes com n/4; com n == 1, faz 1 unidade e para.

Rode com n = 256 e mostre, por nível: o número de chamadas, o tamanho de
cada pedaço e o custo do nível. Mostre também o total e a razão total / n²,
que tem de ficar abaixo de 1/(1 - 3/16) = 16/13 ≈ 1,2308: a soma é uma
progressão geométrica de razão 3/16, e a RAIZ domina (caso 3 do teorema
mestre, Θ(n²)).


```text
Saída esperada:
nível  chamadas  tamanho  custo
    0         1      256  65536
    1         3       64  12288
    2         9       16   2304
    3        27        4    432
    4        81        1     81
Total: 80641 | total / n² = 1.2305 (limite 16/13 = 1.2308)
```

**Dicas:**

1. Guarde chamadas[nivel] e custo[nivel] em vetores globais; 256 = 4^4,
   então são 5 níveis (0 a 4).
2. O nível i tem 3^i chamadas com pedaços de n/4^i: o custo é
   3^i (n/4^i)² = (3/16)^i n².
3. Faça o laço duplo de verdade (for i < n, for j < n, custo++): com
   n = 256 são 65536 voltas na raiz, nada que demore.
4. Resposta esperada: custos 65536, 12288, 2304, 432 e 81; total 80641;
   razão 1.2305.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1711.c
```

---

**Exercício P1712** · ★★☆ · Três funções, três casos, três fórmulas fechadas

As três funções do esqueleto fazem um laço de n voltas (custo n) e se
chamam com n/2, mudando só QUANTAS vezes:


```text
quatro(n): T(n) = 4 T(n/2) + n   caso 1: Θ(n²)
duas(n):   T(n) = 2 T(n/2) + n   caso 2: Θ(n lg n)
uma(n):    T(n) = T(n/2) + n     caso 3: Θ(n)
```


com T(1) = 1. Resolvendo exatamente para n potência de 2 (pela árvore de
recursão), as fórmulas são 2n² - n, n lg n + n e 2n - 1. Instrumente as três
com um contador global (some 1 em cada volta do laço e 1 no caso base) e
mostre, para n = 1, 2, 4, ..., 1024, o custo contado e a fórmula de cada
uma.


```text
Saída esperada:
   n    quatro   2n²-n   duas  nlgn+n   uma  2n-1
   1         1       1      1       1     1     1
   2         6       6      4       4     3     3
   4        28      28     12      12     7     7
   8       120     120     32      32    15    15
  16       496     496     80      80    31    31
  32      2016    2016    192     192    63    63
  64      8128    8128    448     448   127   127
 128     32640   32640   1024    1024   255   255
 256    130816  130816   2304    2304   511   511
 512    523776  523776   5120    5120  1023  1023
1024   2096128 2096128  11264   11264  2047  2047
```

**Dicas:**

1. Zere o contador antes de cada chamada de topo. Use long: quatro(1024)
   passa de 2 milhões.
2. Para o lg n, use um contador de expoente que sobe junto com n no laço do
   main (n = 1 << k).
3. As fórmulas saem da soma por nível: quatro tem 4^i pedaços de n/2^i
   (custo 2^i n no nível i); duas tem custo n em todo nível; uma tem
   n/2^i no nível i.
4. Resposta esperada: as colunas contadas e as fórmulas batem em todas as
   linhas; com n = 1024: 2096128, 11264 e 2047.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1712.c
```

---

**Exercício P1713** · ★★☆ · Quando o mestre não serve: 2T(n/2) + n lg n

Um sistema de relatórios divide os registros ao meio, processa cada metade
recursivamente e, para juntar, gasta n lg n (ele ordena o resultado). A
recorrência é T(n) = 2 T(n/2) + n lg n, com T(1) = 1.

Parece o caso 3 (n lg n é maior que n^(log₂ 2) = n), mas não é: n lg n
não é POLINOMIALMENTE maior que n (não existe ε > 0 com n lg n = Ω(n^(1+ε))).
O teorema mestre na forma básica não se aplica. A árvore de recursão
resolve: o nível i custa n (lg n - i), e a soma dá


```text
T(n) = n + n · lg n (lg n + 1) / 2 = Θ(n lg² n)
```


Escreva relatorio(n), que conta n · lg n unidades de trabalho (lg n
calculado com inteiros) e se chama duas vezes com n/2, e mostre, para
n = 2, 4, 8, ..., 2^16, o custo contado, a fórmula, a razão custo/(n lg n)
(que CRESCE) e a razão custo/(n lg² n) (que se aproxima de 1/2).


```text
Saída esperada:
    n      custo    fórmula  c/(n lg n)  c/(n lg² n)
    2          4          4       2.000        2.000
    4         16         16       2.000        1.000
    8         56         56       2.333        0.778
   16        176        176       2.750        0.688
   32        512        512       3.200        0.640
   64       1408       1408       3.667        0.611
  128       3712       3712       4.143        0.592
  256       9472       9472       4.625        0.578
  512      23552      23552       5.111        0.568
 1024      57344      57344       5.600        0.560
 2048     137216     137216       6.091        0.554
 4096     323584     323584       6.583        0.549
 8192     753664     753664       7.077        0.544
16384    1736704    1736704       7.571        0.541
32768    3964928    3964928       8.067        0.538
65536    8978432    8978432       8.562        0.535
```

**Dicas:**

1. lg n com inteiros: conte quantas vezes dá para dividir n por 2 até
   chegar a 1.
2. Não precisa de laço de n lg n voltas: some n * lg(n) direto no
   contador (o custo é o que interessa, não o tempo).
3. Uma razão que cresce sem parar mostra que o palpite Θ(n lg n) está
   errado; uma razão que se estabiliza mostra a classe certa.
4. Resposta esperada: custo igual à fórmula em todas as linhas; com
   n = 65536, 8978432, razões 8.562 e 0.535.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1713.c
```

---

**Exercício P1714** · ★★☆ · Apertando √ na calculadora: T(n) = T(√n) + 1

Na calculadora, você digita um número e aperta a tecla √ até o visor
mostrar 2 ou menos. Quantas vezes? A função raizes(n) do enunciado faz
isso recursivamente: se n <= 2, para; senão, chama raizes(⌊√n⌋). A
recorrência é T(n) = T(√n) + 1.

Ela não tem a forma a T(n/b) + f(n), mas a MUDANÇA DE VARIÁVEL resolve:
com n = 2^m, fica S(m) = S(m/2) + 1, que é Θ(lg m). Voltando, T(n) =
Θ(lg lg n). Para n = 2^(2^k) a conta é exata: k + 1 chamadas.

Escreva raiz_inteira(n) (o maior r com r · r <= n, só com inteiros, por
busca binária), teto_lg(n) (o menor h com 2^h >= n, só com inteiros) e
raizes(n) com um contador de chamadas, e mostre as chamadas e
⌈lg ⌈lg n⌉⌉ + 1 para n = 4, 16, 256, 65536, 4294967296 e
18446744073709551615 (o maior unsigned long long, que não é potência de
2^(2^k)).


```text
Saída esperada:
                   n  chamadas  teto(lg teto(lg n)) + 1
                   4         2            2
                  16         3            3
                 256         4            4
               65536         5            5
          4294967296         6            6
18446744073709551615         7            7
```

**Dicas:**

1. Use unsigned long long. Na busca binária, teste r <= n / r em vez de
   r * r <= n: o produto estoura para n perto de 2^64.
2. teto_lg(n): conte quantos bits tem n - 1 (desloque para a direita até
   zerar). Não use p *= 2 até passar de n: p estoura antes de 2^64.
3. Mesmo o maior número de 64 bits cai para 2 em 7 apertos: lg lg n cresce
   devagar demais para ser visto na prática.
4. Resposta esperada: 2, 3, 4, 5 e 6 chamadas para as potências, e 7 para
   o maior unsigned long long; a coluna da fórmula bate em todas.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1714.c
```

---

**Exercício P1715** · ★★☆ · O método do potencial no vetor que dobra

O vetor de pedidos de um app começa VAZIO (capacidade 0). Ao inserir com o
vetor cheio, ele aloca o dobro (ou 1, se a capacidade era 0) e copia tudo.
O custo real de uma inserção é 1, mais o número de cópias.

O método do potencial do Cormen usa Φ = 2 · num - cap (num = itens, cap =
capacidade). O custo AMORTIZADO de uma operação é o real mais a variação do
potencial: ĉ = c + Φ(depois) - Φ(antes). Escreva o vetor com malloc (copie
os itens à mão, para contar as cópias) e mostre, para 17 inserções: num,
cap, custo real, Φ e custo amortizado. Mostre também a soma dos custos reais
e a dos amortizados.


```text
Saída esperada:
num  cap  real  phi  amortizado
  1    1     1    1           2
  2    2     2    2           3
  3    4     3    2           3
  4    4     1    4           3
  5    8     5    2           3
  6    8     1    4           3
  7    8     1    6           3
  8    8     1    8           3
  9   16     9    2           3
 10   16     1    4           3
 11   16     1    6           3
 12   16     1    8           3
 13   16     1   10           3
 14   16     1   12           3
 15   16     1   14           3
 16   16     1   16           3
 17   32    17    2           3
Soma real: 48 | soma amortizada: 50 (3n = 51)
```

**Dicas:**

1. Antes de inserir, guarde Φ = 2 · num - cap. Depois, calcule o novo Φ
   e ĉ = c + Φnovo - Φvelho.
2. Sem expansão: c = 1 e Φ sobe 2, então ĉ = 3. Com expansão de num = cap
   = k para 2k: c = k + 1 e Φ cai de k para 2, então ĉ = 3 também.
3. Como Φ começa em 0 e nunca fica negativo depois da primeira inserção, a
   soma dos reais nunca passa da soma dos amortizados: no máximo 3n.
4. Resposta esperada: amortizado 3 em todas as linhas (2 na primeira);
   soma real 48 e soma amortizada 50.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1715.c
```

---

**Exercício P1716** · ★★☆ · Contador com zerar: o reset que não varre tudo

O contador de passageiros de uma estação tem 16 bits e duas operações:
INCREMENTA e ZERA (no fim de cada turno). Zerar varrendo os 16 bits custa
16 sempre. Dá para fazer melhor: guarde em maior o índice do bit 1 mais
alto já ligado desde o último zerar, e zere só os bits 0..maior (custo
maior + 1).

Com isso, n operações quaisquer custam O(n) no total. Pelo método
contábil, cada INCREMENTA paga 3: 1 pelo bit que liga, 1 de crédito para
quando esse bit for desligado, e 1 de crédito para o ZERA varrer a posição,
caso o incremento tenha subido o maior (ele sobe no máximo 1 por vez).

Escreva as duas versões do zerar e rode a sequência do esqueleto contando o
custo total de cada uma (incrementar custa os bits trocados; zerar custa os
bits varridos). Mostre também o limite 3 · (incrementos) + (zerares).


```text
Saída esperada:
Incrementos: 1150 | zerares: 52
Zerar varrendo tudo: 3026
Zerar até o maior:   2304
Limite 3·1150 + 52 = 3502
```

**Dicas:**

1. No incrementa, depois de ligar o bit i, faça maior = i se i > maior.
   Comece com maior = -1.
2. zera_esperto: para i de 0 até maior, b[i] = 0 (custo maior + 1); depois
   maior = -1. zera_bobo: varre os 16.
3. Um zerar logo depois de outro custa 0 na versão esperta (maior = -1).
4. Resposta esperada: versão boba 3026, esperta 2304, limite 3502; nos 50
   turnos curtos, cada zerar esperto custa 2 em vez de 16.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1716.c
```

---

**Exercício P1717** · ★★☆ · Conserte o vetor que cresce de 10 em 10

Conserte o programa. O app de delivery guarda os pedidos do dia num vetor
dinâmico, e o colega fez o vetor crescer de 10 em 10 posições "para não
desperdiçar memória". O erro de propósito não é de memória (o
AddressSanitizer não reclama): é de ANÁLISE. Com crescimento aditivo, n
inserções copiam 10 + 20 + 30 + ... ≈ n²/20 itens: Θ(n²) no total, Θ(n)
por inserção. Veja a saída com 10 mil pedidos:


```text
Saída que aparece:
Pedidos: 10000 | capacidade: 10000
Realocações: 999 | cópias: 4995000 (499.50 por pedido)
```


Troque a regra de crescimento para DOBRAR a capacidade (começando em 10) e
confira que as cópias caem para menos de 2n, ou seja, O(1) amortizado:


```text
Saída esperada:
Pedidos: 10000 | capacidade: 10240
Realocações: 10 | cópias: 10230 (1.02 por pedido)
```

**Dicas:**

1. A única linha que muda é a da nova capacidade.
2. Dobrando a partir de 10, as cópias são 10 + 20 + 40 + ... + 5120: uma
   progressão geométrica que soma menos que o dobro do último termo.
3. Se quiser ver a diferença no relógio, aumente para 1 milhão de pedidos:
   a versão aditiva copia uns 50 bilhões de itens.
4. Resposta esperada: 10 realocações e 10230 cópias, contra 999 e 4995000.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1717.c
```

---

**Exercício P1718** · ★★☆ · O laço que dobra dentro da recursão

A função do esqueleto organiza as filas de um evento: em cada pedaço de n
pessoas, um laço for (i = 1; i < n; i *= 2) faz lg n passos, e depois a
função se chama para as duas metades. A recorrência é


```text
T(1) = 1,  T(n) = 2 T(n/2) + lg n
```


Leia o código, ache a recorrência e aplique o teorema mestre: a = 2,
b = 2, n^(log₂ 2) = n, e f(n) = lg n = O(n^(1 - ε)): caso 1, Θ(n). A
árvore de recursão dá a fórmula exata para n potência de 2:
T(n) = 3n - lg n - 2.

Acrescente um contador global (1 por volta do laço e 1 no caso base) e
mostre, para n = 1, 4, 16, ..., 2^20 (potências de 4), o custo contado,
3n - lg n - 2 e a razão custo / n.


```text
Saída esperada:
      n    custo  3n-lg n-2  custo/n
      1        1          1   1.0000
      4        8          8   2.0000
     16       42         42   2.6250
     64      184        184   2.8750
    256      758        758   2.9609
   1024     3060       3060   2.9883
   4096    12274      12274   2.9966
  16384    49136      49136   2.9990
  65536   196590     196590   2.9997
 262144   786412     786412   2.9999
1048576  3145706    3145706   3.0000
```

**Dicas:**

1. Para ler a recorrência do código: duas chamadas com n/2 dão 2 T(n/2);
   o laço com i *= 2 roda ⌈lg n⌉ vezes; o resto é constante.
2. Mesmo com o trabalho por chamada crescendo (lg n), a quantidade de
   folhas (n) domina: o caso 1 diz que as folhas ganham.
3. A razão custo / n se aproxima de 3, a constante da fórmula.
4. Resposta esperada: o custo bate com 3n - lg n - 2 em todas as linhas;
   com n = 2^20, 3145706.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1718.c
```

---

**Exercício P1719** · ★★☆ · Quantas chamadas para escolher o time do futsal

O técnico quer saber de quantos jeitos dá para escolher k jogadores de um
grupo de n. A função comb(n, k) do esqueleto usa a relação de Pascal:
C(n, k) = C(n - 1, k - 1) + C(n - 1, k), com C(n, 0) = C(n, n) = 1.

Toda folha da árvore de recursão devolve 1, então ela tem exatamente
C(n, k) folhas. E todo nó interno tem dois filhos. Numa árvore assim
(binária cheia), nós = 2 · folhas - 1. Logo:


```text
chamadas(n, k) = 2 C(n, k) - 1
```


Acrescente um contador e mostre, para (6, 2), (10, 5), (20, 10) e (26, 13),
o valor, as chamadas e 2 C(n, k) - 1. Depois escreva comb_linha(n, k), que
calcula o mesmo número sem recursão, pela fórmula multiplicativa
C(n, k) = C(n, k - 1) · (n - k + 1) / k, e conte as multiplicações.


```text
Saída esperada:
 n  k     C(n,k)  chamadas  2C-1      linha  mult
 6  2         15        29        29         15    2
10  5        252       503       503        252    5
20 10     184756    369511    369511     184756   10
26 13   10400600  20801199  20801199   10400600   13
```

**Dicas:**

1. Use long: C(26, 13) passa de 10 milhões, e as chamadas, de 20 milhões.
2. Na fórmula multiplicativa, faça r = r * (n - i + 1) / i para i de 1 a k,
   nessa ordem: a divisão é sempre exata.
3. A recursão gasta Θ(C(n, k)) chamadas, que crescem como 2^n / √n; a
   fórmula gasta k multiplicações.
4. Resposta esperada: 15, 252, 184756 e 10400600, com 29, 503, 369511 e
   20801199 chamadas; a fórmula faz 2, 5, 10 e 13 multiplicações.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1719.c
```

---

**Exercício P1720** · ★★☆ · Quatro ordenações contando comparações

Em vez de cronometrar, conte. O esqueleto gera os preços de n produtos com
um gerador pseudoaleatório fixo (a mesma sequência em toda execução).
Escreva insertion sort, merge sort, heapsort e quicksort (pivô no último
elemento, partição de Lomuto) e conte as COMPARAÇÕES ENTRE ELEMENTOS de
cada um, todos ordenando cópias do mesmo vetor.

Mostre as contagens para n = 1000 e n = 2000, a razão entre as duas (quanto
cresce quando n dobra) e as referências n²/4 e n lg n. Confira também que
os quatro deixam o vetor ordenado.


```text
Saída esperada:
            n = 1000  n = 2000  razão
insertion     250962   1021285   4.07
merge           8707     19411   2.23
heapsort       16835     37713   2.24
quicksort      10531     23811   2.26
n²/4         250000   1000000   4.00
n lg n          9966     21932   2.20
Todos ordenados: sim
```

**Dicas:**

1. Faça a comparação passar por uma função menor(a, b) que soma 1 num
   contador global: assim nenhuma comparação escapa.
2. Quadrático: dobrar n multiplica por 4. Θ(n lg n): multiplica por um
   pouco mais que 2 (2 · lg 2n / lg n ≈ 2,2 para n = 1000).
3. O insertion sort faz em média n²/4 comparações: cada par fora de ordem
   custa uma. Os outros três são Θ(n lg n) com constantes diferentes; o
   heapsort compara duas vezes por nível ao descer, e por isso perde.
4. Resposta esperada: o insertion sort fica perto de n²/4 e quadruplica
   (razão 4,07); merge, heap e quick ficam entre 0,8 e 1,8 vezes n lg n e
   crescem cerca de 2,2 vezes.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1720.c
```

## ★★★ Desafio

**Exercício P1721** · ★★★ · Matrizes por blocos: 8 chamadas contra as 7 de Strassen

Uma rede de farmácias multiplica matrizes n × n (transferências entre
filiais vezes custos) com n potência de 2. Dividindo cada matriz em quatro
blocos n/2 × n/2, o produto sai de 8 produtos de blocos:


```text
C11 = A11 B11 + A12 B21    C12 = A11 B12 + A12 B22
C21 = A21 B11 + A22 B21    C22 = A21 B12 + A22 B22
```


Isso dá M(n) = 8 M(n/2) multiplicações escalares, com M(1) = 1: n³, igual ao
laço triplo (caso 1 do mestre, n^(log₂ 8)). Strassen descobriu como fazer
com 7 produtos de blocos: S(n) = 7 S(n/2) = n^(log₂ 7) ≈ n^2,807.

Escreva:

1. mult_blocos(), recursiva com as 8 chamadas (trabalhe com deslocamentos
de linha e coluna nas matrizes globais, sem copiar blocos), contando as
multiplicações escalares;
2. a conferência com o laço triplo para n = 2, 4, 8 e 16;
3. a tabela de n³ e 7^(lg n) para n = 2, 4, ..., 1024, calculada pelas
recorrências, com a razão entre elas.


```text
Saída esperada:
n =  2:    8 multiplicações (n³ =    8), igual ao laço triplo: sim
n =  4:   64 multiplicações (n³ =   64), igual ao laço triplo: sim
n =  8:  512 multiplicações (n³ =  512), igual ao laço triplo: sim
n = 16: 4096 multiplicações (n³ = 4096), igual ao laço triplo: sim
    n          8 blocos   Strassen  razão
    2                 8          7   1.14
    4                64         49   1.31
    8               512        343   1.49
   16              4096       2401   1.71
   32             32768      16807   1.95
   64            262144     117649   2.23
  128           2097152     823543   2.55
  256          16777216    5764801   2.91
  512         134217728   40353607   3.33
 1024        1073741824  282475249   3.80
```

**Dicas:**

1. mult(ar, ac, br, bc, cr, cc, n): no caso base, C[cr][cc] += A[ar][ac] *
   B[br][bc]. Senão, com h = n/2, cada bloco Cxy recebe dois produtos:
   por exemplo, C11 += A11 B11 é mult(ar, ac, br, bc, cr, cc, h) e
   C11 += A12 B21 é mult(ar, ac + h, br + h, bc, cr, cc, h).
2. Zere C antes de cada n: as chamadas SOMAM em C.
3. A razão n³ / 7^(lg n) = (8/7)^(lg n) cresce devagar: só fica grande
   para n enorme, e por isso Strassen só compensa em matrizes grandes.
4. Resposta esperada: as multiplicações contadas são n³ e os produtos
   batem com o laço triplo; com n = 1024, 1073741824 contra 282475249
   (razão 3.80).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1721.c
```

---

**Exercício P1722** · ★★★ · A árvore de recursão de qualquer a T(n/b) + n^k

O teorema mestre é a árvore de recursão resumida. Escreva um programa que
DESENHE a árvore, por nível, para qualquer recorrência T(n) = a T(n/b) + n^k
com T(1) = 1 (n potência de b), e que confira o total com uma função
recursiva que realmente soma os custos.


```text
void arvore(int a, int b, int k, long n);
```


Para cada nível i: o número de nós a^i, o tamanho n/b^i, o custo de cada
nó (n/b^i)^k e o custo do nível. No fim: o total da tabela, o total da
recursão (têm de bater) e o diagnóstico pela razão r = a / b^k entre o
custo de um nível e o do anterior:

- r > 1: o custo cresce para baixo, as FOLHAS dominam (caso 1);
- r == 1: todos os níveis custam o mesmo, total = custo × níveis (caso 2);
- r < 1: o custo cai, a RAIZ domina (caso 3).

Rode para (8, 2, 2), (4, 2, 2) e (2, 2, 2), todas com n = 64, e para
(9, 3, 1) com n = 81.


```text
Saída esperada:
T(n) = 8 T(n/2) + n^2, n = 64
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       64      4096            4096
      1        8       32      1024            8192
      2       64       16       256           16384
      3      512        8        64           32768
      4     4096        4        16           65536
      5    32768        2         4          131072
      6   262144        1         1          262144
  total da tabela 520192, da recursão 520192
  r = 8/4 > 1: as folhas dominam (caso 1)
T(n) = 4 T(n/2) + n^2, n = 64
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       64      4096            4096
      1        4       32      1024            4096
      2       16       16       256            4096
      3       64        8        64            4096
      4      256        4        16            4096
      5     1024        2         4            4096
      6     4096        1         1            4096
  total da tabela 28672, da recursão 28672
  r = 1: 7 níveis iguais (caso 2)
T(n) = 2 T(n/2) + n^2, n = 64
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       64      4096            4096
      1        2       32      1024            2048
      2        4       16       256            1024
      3        8        8        64             512
      4       16        4        16             256
      5       32        2         4             128
      6       64        1         1              64
  total da tabela 8128, da recursão 8128
  r = 2/4 < 1: a raiz domina (caso 3)
T(n) = 9 T(n/3) + n^1, n = 81
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       81        81              81
      1        9       27        27             243
      2       81        9         9             729
      3      729        3         3            2187
      4     6561        1         1            6561
  total da tabela 9801, da recursão 9801
  r = 9/3 > 1: as folhas dominam (caso 1)
```

**Dicas:**

1. Compare a com b^k em inteiros: nada de double nem de log, que erram por
   arredondamento.
2. A função recursiva custo(a, b, k, n) devolve n^k + a · custo(a, b, k,
   n/b), com custo(1) = 1. É a própria recorrência.
3. A última linha da tabela (tamanho 1) tem a^(log_b n) = n^(log_b a)
   folhas: é o termo que o caso 1 compara com f(n).
4. Resposta esperada: 8T(n/2)+n² tem folhas 262144 de 520192 (caso 1);
   4T(n/2)+n² tem 7 níveis de 4096 (caso 2); 2T(n/2)+n² tem raiz 4096 de
   8128 (caso 3); 9T(n/3)+n é caso 1.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1722.c
```

---

**Exercício P1723** · ★★★ · Stooge sort: correto, recursivo e pior que o bubble

O stooge sort (problema 7-3 do Cormen) ordena v[i..j] assim: se v[i] >
v[j], troca os dois; se o pedaço tem 3 ou mais elementos, com t = ⌊(j - i +
1)/3⌋, ordena os primeiros 2/3, depois os últimos 2/3, depois os primeiros
2/3 de novo. Ele funciona, mas a recorrência é


```text
T(n) = 3 T(2n/3) + Θ(1)  =>  Θ(n^(log_{3/2} 3)) ≈ Θ(n^2,71)
```


pior que os Θ(n²) do bubble e do insertion sort.

Escreva o stooge sort com um contador de chamadas e a profundidade máxima
da recursão (a raiz tem profundidade 1), e ordene os tempos de volta de um
kart (vetor do esqueleto) para n = 10, 20, 40, ..., 640. Mostre, para
cada n: as chamadas, se ficou ordenado, a profundidade, log_{3/2} n e as
n(n - 1)/2 comparações do bubble sort. No fim, estime o expoente entre n = 10 e
n = 640 com log(c₆₄₀ / c₁₀) / log(64) e compare com log(3) / log(1,5).


```text
Saída esperada:
  n  chamadas  ordenado  prof  log1.5(n)  bubble
 10       364       sim     6       5.68      45
 20      3280       sim     8       7.39     190
 40      9841       sim     9       9.10     780
 80     88573       sim    11      10.81    3160
160    797161       sim    13      12.52   12720
320   7174453       sim    15      14.23   51040
640  21523360       sim    16      15.94  204480
Expoente estimado: 2.642 | teoria log(3) / log(1,5) = 2.7095
```

**Dicas:**

1. Os dois "2/3" se sobrepõem: primeiros vão de i até j - t, últimos de
   i + t até j. É essa sobreposição que garante que o maior chega ao fim.
2. Repare que as chamadas são sempre (3^p - 1)/2, com p a profundidade: a
   árvore é ternária e cheia. Cada fator 3/2 no tamanho acrescenta um
   nível, então p ≈ log_{3/2} n e as chamadas ≈ 3^(log_{3/2} n) =
   n^(log_{3/2} 3).
3. Por causa do ⌊ ⌋, a profundidade anda aos saltos: a razão entre n e 2n
   oscila. Estime o expoente num intervalo longo.
4. Resposta esperada: todos ordenados; com n = 640, 21523360 chamadas
   (contra 204480 comparações do bubble); expoente estimado 2.642, teoria
   2.7095.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1723.c
```

---

**Exercício P1724** · ★★★ · A fila circular que dobra sem perder a ordem

A fila de senhas de um banco é um vetor CIRCULAR: ini aponta o primeiro,
num diz quantos há, e o próximo entra em (ini + num) % cap. Quando enche,
a fila dobra. A pegadinha: não dá para copiar o vetor velho como está,
porque a fila pode "dar a volta" no fim. É preciso copiar NA ORDEM DA FILA
(de ini até o fim, depois do começo até ini - 1) para o começo do vetor
novo, e fazer ini = 0.

Escreva enfileira, desenfileira e cresce, contando as cópias. Comece com
cap = 1 e rode o dia do esqueleto: 1000 rodadas de "chega, chega, atende,
chega, atende, chega, atende". Confira que as senhas saem na ordem em que chegaram,
mostre cada vez que a fila cresceu (de quanto para quanto, e com ini em
que posição) e o total de cópias, comparado com o número de enfileiramentos.


```text
Saída esperada:
cresce    1 ->    2 (ini era 0)
cresce    2 ->    4 (ini era 1)
cresce    4 ->    8 (ini era 2)
cresce    8 ->   16 (ini era 4)
cresce   16 ->   32 (ini era 8)
cresce   32 ->   64 (ini era 16)
cresce   64 ->  128 (ini era 32)
cresce  128 ->  256 (ini era 64)
cresce  256 ->  512 (ini era 128)
cresce  512 -> 1024 (ini era 256)
Crescimentos: 10 | cópias: 1023 | senhas enfileiradas: 4000
Atendidas em ordem: sim | na fila: 1000 (cap 1024)
```

**Dicas:**

1. Em cresce: para i de 0 a num - 1, novo[i] = velho[(ini + i) % cap].
   Depois libere o velho, ini = 0 e cap *= 2.
2. Mostre o ini ANTES da cópia: quando ele não é 0, a fila estava dando a
   volta, e um memcpy do vetor inteiro embaralharia a ordem.
3. As cópias somam 1 + 2 + 4 + ... + 512 = 1023: menos de uma cópia por
   senha enfileirada. Custo amortizado O(1).
4. Resposta esperada: 10 crescimentos (até cap 1024), quase todos com a
   fila dando a volta (ini na metade do vetor); 1023 cópias para 4000
   senhas; ordem conferida; 1000 senhas na fila no fim.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1724.c
```

---

**Exercício P1725** · ★★★ · O método da substituição testado no computador

O merge sort com n qualquer (não só potência de 2) segue


```text
T(1) = 0,  T(n) = T(⌈n/2⌉) + T(⌊n/2⌋) + n - 1
```


(n - 1 é o pior caso de comparações ao intercalar). No método da
substituição, você chuta T(n) <= c · n lg n e prova por indução. O
computador não prova, mas mostra se o chute é bom e qual c serve.

Escreva um programa que calcule T(n) para todo n de 1 a 1000000 numa
tabela (de baixo para cima: T[n] só usa índices menores), e mostre:

- T(n) e T(n) / (n lg n) para n = 10, 100, ..., 1000000;
- o maior valor de T(n) / (n lg n) para 2 <= n <= 1000000, e em que n;
- a conferência da fórmula exata do pior caso do merge sort:
T(n) = n ⌈lg n⌉ - 2^⌈lg n⌉ + 1, para todo n de 1 a 1000000.


```text
Saída esperada:
      n          T(n)  T/(n lg n)
     10            25       0.753
    100           573       0.862
   1000          8977       0.901
  10000        123617       0.930
 100000       1568929       0.945
1000000      18951425       0.951
Maior razão: 0.9531, em n = 762546
Fórmula n teto(lg n) - 2^teto(lg n) + 1: 0 n errados
```

**Dicas:**

1. Um vetor de 1 milhão de long ocupa 8 MB: deixe-o global ou static.
2. T[n] = T[(n + 1) / 2] + T[n / 2] + n - 1: com inteiros, (n + 1) / 2 é
   o teto e n / 2 é o chão.
3. Para ⌈lg n⌉ e 2^⌈lg n⌉ sem double, ande com uma potência p que dobra
   enquanto p < n.
4. A razão fica abaixo de 1 em todo n: c = 1 serve no chute T(n) <= c n lg n,
   e o chute fica justo (a razão se aproxima de 1 por baixo).
5. Resposta esperada: a fórmula confere em todos os n; com n = 1000000,
   T = 18951425 e razão 0.951.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1725.c
```

---

**Exercício P1726** · ★★★ · Busca na tabela de fretes: escada contra quadrantes

A transportadora tem uma tabela n × n de fretes, em reais, crescente em
cada linha (peso) e em cada coluna (distância): frete[i][j] = 10i + 7j.
Dado um valor, ela quer saber se ele aparece na tabela. Escreva as duas
buscas e conte as comparações com elementos da tabela:

- ESCADA: comece no canto de cima à direita. Se o valor é menor, vá para a
esquerda; se é maior, desça. No máximo 2n - 1 passos: Θ(n).
- QUADRANTES: compare com o elemento do meio m = frete[mi][mj]. Se o valor
é menor, ele não está no quadrante de baixo à direita (linhas >= mi e
colunas >= mj); se é maior, não está no de cima à esquerda (linhas <= mi
e colunas <= mj). Procure recursivamente nos TRÊS pedaços que sobram. A
recorrência é T(n) = 3 T(n/2) + 1, caso 1: Θ(n^(lg 3)) ≈ Θ(n^1,585).

Para n = 8, 16, 32 e 64, procure TODOS os valores de 0 até o maior da
tabela e mostre o pior caso de cada busca, 2n - 1 e n^(lg 3). Confira que as
duas buscas concordam em todos os valores.


```text
Saída esperada:
 n  escada  2n-1  quadrantes  n^lg3  concordam
 8      15    15          40     27        sim
16      25    31         121     81        sim
32      41    63         364    243        sim
64      73   127        1093    729        sim
```

**Dicas:**

1. A busca por quadrantes trabalha num retângulo (l0, c0, l1, c1); se ele
   está vazio (l0 > l1 ou c0 > c1), devolve falso sem comparar.
2. Com mi = (l0 + l1) / 2 e mj = (c0 + c1) / 2, os três pedaços para
   "valor menor" são (l0, c0, mi - 1, mj - 1), (l0, mj, mi - 1, c1) e
   (mi, c0, l1, mj - 1). Para "valor maior": (l0, mj + 1, mi, c1),
   (mi + 1, c0, l1, mj) e (mi + 1, mj + 1, l1, c1).
3. Dividir parece sempre melhor, mas aqui não é: três subproblemas de
   metade do lado dão n^1,585, que perde de 2n.
4. Resposta esperada: as buscas concordam; com n = 64, a escada faz no
   pior caso 73 comparações (o limite é 127) e a de quadrantes, 1093.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1726.c
```

---

**Exercício P1727** · ★★★ · Montar o heap: n inserções ou BUILD-HEAP?

A central do SAMU recebe de uma vez a lista de chamados do turno e precisa
de um heap MÍNIMO pela gravidade (1 é o mais grave). Há dois jeitos:

- inserir um por um: cada inserção sobe o novo item, até lg i trocas. Total
O(n lg n);
- BUILD-HEAP (Floyd): põe tudo no vetor e chama "desce" para i de n/2 - 1
até 0. Um nó de altura h desce no máximo h níveis, e só ~n/2^(h+1) nós
têm altura h: a soma Σ h · n/2^(h+1) é menor que n. Total O(n).

Implemente os dois, contando as TROCAS, e teste no pior caso de cada um:
gravidades em ordem DECRESCENTE (n, n - 1, ..., 1), com n = 2^k - 1 para
k = 4, 8, 12, 16 e 20. Mostre as trocas, n lg n e n, e confira que os dois
heaps são válidos.


```text
Saída esperada:
      n   inserindo   build-heap      n lg n  válidos
     15          34           11          59      sim
    255        1538          247        2039      sim
   4095       40962         4083       49139      sim
  65535      917506        65519     1048559      sim
1048575    18874370      1048555    20971499      sim
```

**Dicas:**

1. Em ordem decrescente, cada novo item é o menor de todos: sobe até a
   raiz. São ⌊lg i⌋ trocas para o i-ésimo item.
2. No BUILD-HEAP, cada nó desce até uma folha. Para n = 2^k - 1, a soma das
   alturas dá exatamente n - k.
3. Heap mínimo válido: v[(i - 1) / 2] <= v[i] para todo i >= 1.
4. Resposta esperada: com n = 1048575, 18874370 trocas inserindo e 1048555
   com BUILD-HEAP (n - 20).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1727.c
```

---

**Exercício P1728** · ★★★ · Fabrique o pior caso do merge sort

O merge sort intercala com no máximo n - 1 comparações; o pior caso total,
para n potência de 2, é n lg n - n + 1. Que entrada provoca isso? Uma
intercalação faz n - 1 comparações quando as duas metades se alternam até
o fim: o maior e o segundo maior ficam em metades diferentes, e assim por
diante. Dá para FABRICAR a entrada desfazendo o merge sort:


```text
pior(v[0..n-1] ordenado): os elementos das posições pares vão para a
metade esquerda, os das ímpares para a direita, e cada metade é
arrumada recursivamente do mesmo jeito.
```


Escreva pior() e um merge sort que conte comparações. Para n = 8, 16 e
1024, mostre as comparações com a entrada já ordenada, com a fabricada, a
fórmula n lg n - n + 1 e o limite inferior ⌈lg n!⌉ de qualquer ordenação
por comparação. Mostre também a entrada fabricada para n = 8 (com as notas
1 a 8 de uma prova).


```text
Saída esperada:
   n  ordenada  fabricada  n lg n - n + 1  teto(lg n!)
   8        12         17              17           16
  16        32         49              49           45
1024      5120       9217            9217         8770
Entrada fabricada (n = 8): 1 5 3 7 2 6 4 8
```

**Dicas:**

1. pior(v, n): copie os de índice par para aux[0..n/2-1] e os de índice
   ímpar para aux[n/2..n-1], chame pior nas duas metades de aux e copie de
   volta. Com n == 1, nada a fazer.
2. Na entrada ordenada, cada intercalação esgota a metade esquerda primeiro:
   n/2 comparações por nível, (n/2) lg n no total.
3. ⌈lg n!⌉ sai de somar log2(i) para i de 2 a n (com double) e arredondar
   para cima.
4. Resposta esperada: para n = 8, a entrada 1 5 3 7 2 6 4 8 dá 17
   comparações (fórmula 17, limite 16); para n = 1024, 9217 contra o limite
   8770.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1728.c
```

---

**Exercício P1729** · ★★★ · A roda do amigo-secreto: simular ou recorrer?

Na roda de n pessoas, numeradas de 1 a n no sentido horário, a pessoa 1
começa: ela "pula" a vizinha, que sai da roda, e a vez passa para a pessoa
seguinte à que saiu. Isso se repete (sai uma, pula uma) até sobrar uma,
que escolhe o primeiro presente. É o problema de Josephus com passo 2.

Dois jeitos de achar quem sobra:

- SIMULAR com uma lista circular encadeada (malloc): n - 1 remoções, cada
uma com um passo de ponteiro: Θ(n) passos.
- RECORRER: J(1) = 1, J(2m) = 2 J(m) - 1 e J(2m + 1) = 2 J(m) + 1. Uma
chamada com n/2: C(n) = C(n/2) + 1 = ⌊lg n⌋ + 1 chamadas.

Escreva os dois, contando passos e chamadas, e confira com a fórmula
fechada J(n) = 2(n - 2^⌊lg n⌋) + 1. Rode para n = 5, 10, 41, 1000 e
100000.


```text
Saída esperada:
     n  simulação  passos  recursão  chamadas  fórmula
     5          3       4         3         3        3
    10          5       9         5         4        5
    41         19      40        19         6       19
  1000        977     999       977        10      977
100000      68929   99999     68929        17    68929
```

**Dicas:**

1. Lista circular: crie os nós 1..n, ligue o último ao primeiro e guarde
   em atual a pessoa da vez. Remover: alvo = atual->prox; atual->prox =
   alvo->prox; free(alvo); atual = atual->prox (conte 1 passo).
2. Sobra um nó só quando atual->prox == atual. Libere-o no fim.
3. Na recursão, J(m) é a resposta para metade da roda: depois da primeira
   volta, só sobram os ímpares, e a numeração deles é "dobrada".
4. Resposta esperada: sobram 3, 5, 19, 977 e 68929; a simulação gasta
   n - 1 passos, a recursão no máximo 17 chamadas.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1729.c
```

---

**Exercício P1730** · ★★★ · Contador em que trocar o bit i custa 2^i

No contador binário comum, trocar qualquer bit custa 1, e n incrementos
custam menos que 2n: O(1) amortizado. Agora imagine um contador de placas
mecânicas em que a placa i é 2^i vezes mais pesada: trocar o bit i custa
2^i. O custo amortizado continua constante?

Análise agregada: em n = 2^k incrementos a partir de 0, o bit i (i < k)
troca n/2^i vezes, a 2^i cada: n por bit. Com k bits trocando, e mais a
placa k ligada uma vez no fim (custo 2^k = n), o total é n(k + 1) =
n(lg n + 1). Amortizado: lg n + 1, que CRESCE com n.

Escreva o contador (24 bits) com os dois custos e mostre, para n = 2^k com
k = 4, 8, 12, 16 e 20: o custo total comum, o total pesado, n(lg n + 1) e o
custo pesado por incremento.


```text
Saída esperada:
      n    comum      pesado  n(lg n + 1)  pesado/n
     16       31          80           80       5.0
    256      511        2304         2304       9.0
   4096     8191       53248        53248      13.0
  65536   131071     1114112      1114112      17.0
1048576  2097151    22020096     22020096      21.0
```

**Dicas:**

1. Um só incrementa() devolve as duas contagens por ponteiro: some 1 em
   *comum e 1 << i em *pesado a cada bit i trocado.
2. Use long para o custo pesado: com n = 2^20, passa de 20 milhões.
3. A análise agregada não muda de método, só de conta: o que importa é
   quantas vezes cada bit troca, multiplicado pelo preço do bit.
4. Resposta esperada: o comum fica em 2n - 1; o pesado bate com
   n(lg n + 1) em todas as linhas (21 por incremento com n = 2^20).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1730.c
```
