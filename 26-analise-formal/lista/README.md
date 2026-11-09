<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 26 · Notação assintótica, somatórios e espaço

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/26-analise-formal/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2601** · ★☆☆ · Fiscal de dois em dois

O fiscal do estacionamento confere as vagas de 2 em 2: a 0, a 2, a 4...
Escreva vagas_conferidas(n), com o laço for (i = 0; i < n; i += 2) e um
contador, e mostre a contagem ao lado da fórmula (n + 1) / 2 (divisão
inteira) para n = 10, 11, 1 e 1000:


```text
Saída esperada:
n =   10:   5 vagas, fórmula   5
n =   11:   6 vagas, fórmula   6
n =    1:   1 vagas, fórmula   1
n = 1000: 500 vagas, fórmula 500
```

**Dicas:**

1. Com n = 11, o laço passa por 0, 2, 4, 6, 8 e 10: são 6 vagas.
2. (n + 1) / 2 em inteiro é o teto de n/2. Teste com n = 1 antes de
   confiar.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2601.c
```

---

**Exercício P2602** · ★☆☆ · O n₀ do frete

O cálculo do frete de n pacotes custa f(n) = 2n + 100 operações. Prove
com um programa que f(n) é O(n): escreva acha_n0(c), que testa todo n de
1 até 10000 e devolve o menor n0 a partir do qual 2n + 100 <= c * n
sempre vale. Mostre o n0 para c = 3, 4, 12 e 102:


```text
Saída esperada:
c =   3: n0 = 100
c =   4: n0 = 50
c =  12: n0 = 10
c = 102: n0 = 1
```

**Dicas:**

1. Comece com n0 = 1 e, a cada n que falha, faça n0 = n + 1.
2. À mão: 2n + 100 <= 3n vira n >= 100. Quanto maior o c, menor o n0.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2602.c
```

---

**Exercício P2603** · ★☆☆ · Piso do sorteio de duplas

O sorteio de duplas do torneio de vôlei faz f(n) = n² - 20n comparações.
Mostre com um programa que f(n) é Ω(n²) com c = 0.5: ache o menor n0
(testando n de 1 até 10000) a partir do qual f(n) >= 0.5 * n² sempre
vale. Faça o mesmo com c = 0.75 e com c = 0.9:


```text
Saída esperada:
c = 0.50: n0 = 40
c = 0.75: n0 = 80
c = 0.90: n0 = 200
```

**Dicas:**

1. A falha agora é f(n) < c * n * n. Use double para c.
2. À mão: n² - 20n >= n²/2 vira n >= 40.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2603.c
```

---

**Exercício P2604** · ★☆☆ · Turno e returno

No campeonato de turno e returno, cada time joga uma vez em casa contra
cada um dos outros. Escreva jogos(n) com dois laços (for i < n, for j < n)
que conta só os pares com i != j, e compare com a fórmula n(n-1) para
n = 4, 20 e 380:


```text
Saída esperada:
n =   4:     12 jogos, n(n-1) =     12
n =  20:    380 jogos, n(n-1) =    380
n = 380: 144020 jogos, n(n-1) = 144020
```

**Dicas:**

1. Cada time i joga em casa contra n - 1 adversários.
2. n(n-1) é o dobro de n(n-1)/2: os jogos de ida e os de volta.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2604.c
```

---

**Exercício P2605** · ★☆☆ · Quantas vezes dá para dividir

A gráfica dobra uma folha ao meio até sobrar 1 pedaço. Escreva
cortes(n), com o laço while (n > 1) { n /= 2; } e um contador, e mostre o
resultado ao lado de floor(log2(n)) para n = 1, 2, 1000, 1024 e 1000000:


```text
Saída esperada:
n =       1:  0 cortes, floor(log2 n) =  0
n =       2:  1 cortes, floor(log2 n) =  1
n =    1000:  9 cortes, floor(log2 n) =  9
n =    1024: 10 cortes, floor(log2 n) = 10
n = 1000000: 19 cortes, floor(log2 n) = 19
```

**Dicas:**

1. floor e log2 ficam em <math.h>.
2. Divisão inteira por 2 é o mesmo que descer uma potência de 2: são
   floor(log2 n) cortes.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2605.c
```

---

**Exercício P2606** · ★☆☆ · O primeiro débito do extrato

A função primeiro_debito procura o primeiro valor negativo do extrato e
conta as comparações. Rode-a nos três extratos de 8 lançamentos do main
e mostre as comparações de cada um, dizendo qual é o melhor caso e qual
é o pior:


```text
Saída esperada:
extrato a (melhor caso): posição 0, 1 comparações
extrato b: posição 3, 4 comparações
extrato c (pior caso): posição -1, 8 comparações
```

**Dicas:**

1. Acrescente um contador global, zerado antes de cada busca e somado a
   cada valor olhado.
2. O melhor caso olha 1 valor; o pior olha os 8 (o débito no fim ou nenhum
   débito).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2606.c
```

---

**Exercício P2607** · ★☆☆ · A pilha do Euclides

O MDC de Euclides recursivo, mdc(a, b) = mdc(b, a % b) com mdc(a, 0) = a,
é usado para simplificar frações de receitas. Meça a profundidade máxima
da pilha (prof e prof_max globais) para mdc(84, 36), mdc(89, 55) e
mdc(1000000, 3):


```text
Saída esperada:
mdc(84, 36) = 12, profundidade 3
mdc(89, 55) = 1, profundidade 10
mdc(1000000, 3) = 1, profundidade 3
```

**Dicas:**

1. prof++ na entrada (atualizando prof_max), prof-- antes de devolver;
   guarde o resultado numa variável.
2. 89 e 55 são Fibonacci vizinhos: o pior caso do Euclides, mas ainda Θ(log
   n) de pilha.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2607.c
```

---

**Exercício P2608** · ★☆☆ · Soma dos ímpares

Na escada da praça, o degrau k tem 2k - 1 tijolos (1, 3, 5, ...). Some os
tijolos dos n primeiros degraus com um laço for (i = 1; i < 2 * n; i += 2)
e compare com a fórmula n² para n = 10, 100 e 5000. Mostre também quantas
voltas o laço deu:


```text
Saída esperada:
n =   10:      100 tijolos em   10 voltas, n² =      100
n =  100:    10000 tijolos em  100 voltas, n² =    10000
n = 5000: 25000000 tijolos em 5000 voltas, n² = 25000000
```

**Dicas:**

1. O laço dá n voltas: i = 1, 3, ..., 2n - 1.
2. 1 + 3 + ... + (2n - 1) = n²: a soma aritmética com parcelas de 2 em 2.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2608.c
```

---

**Exercício P2609** · ★☆☆ · Dobrou n, multiplicou por oito

A função trios_de_cores testa toda combinação (i, j, k) de n tintas, com
três laços de 0 a n - 1. Acrescente um contador de passos, rode com
n = 10, 20, 40 e 80 e mostre a razão entre cada contagem e a anterior:


```text
Saída esperada:
n = 10:   1000 passos
n = 20:   8000 passos, razão 8.0
n = 40:  64000 passos, razão 8.0
n = 80: 512000 passos, razão 8.0
```

**Dicas:**

1. São n³ passos. Dobrar n multiplica por 2³ = 8: a assinatura de Θ(n³).
2. Na primeira linha não há razão anterior; mostre só a contagem.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2609.c
```

---

**Exercício P2610** · ★☆☆ · Quanto pesa a matriz

O mapa de calor de uma loja guarda uma matriz n × n de double. Para
n = 10, 100 e 1000, aloque a matriz com um único malloc de n * n double,
preencha tudo com 0.0, mostre quantos bytes ela ocupa (e quantos MB, com
1 MB = 1048576 bytes) e libere com free:


```text
Saída esperada:
n =   10:      800 bytes (0.00 MB)
n =  100:    80000 bytes (0.08 MB)
n = 1000:  8000000 bytes (7.63 MB)
```

**Dicas:**

1. Os bytes são n * n * sizeof(double): Θ(n²) de espaço.
2. Use size_t para os bytes e %zu no printf. Confira o NULL do malloc.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2610.c
```

## ★★☆ Para pensar

**Exercício P2611** · ★★☆ · O sanduíche completo

O fechamento mensal da farmácia faz f(n) = 4n² + 30n + 100 operações com n
produtos. Escreva n0_teto(c) e n0_piso(c) (testando n de 1 até 100000) e
mostre o n0 do teto para c = 5, 6 e 8, e o do piso para c = 4. No fim,
escreva a conclusão com os valores de c1, c2 e n0 do Θ (use o teto com
c = 5):


```text
Saída esperada:
teto c = 5: n0 = 34
teto c = 6: n0 = 18
teto c = 8: n0 = 10
piso c = 4: n0 = 1
Θ(n²) com c1 = 4, c2 = 5 e n0 = 34
```

**Dicas:**

1. Teto: falha quando f(n) > c n². Piso: falha quando f(n) < c n².
2. À mão: 4n² + 30n + 100 <= 5n² vira n² - 30n - 100 >= 0, n >= 33,2.
3. O piso com c = 4 vale desde n = 1, então o n0 do Θ é o do teto.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2611.c
```

---

**Exercício P2612** · ★★☆ · Caso médio com quem não está

O balcão de achados e perdidos tem 100 objetos numa lista, e a busca é
sequencial. Por experiência, 75% das consultas procuram um objeto que
está na lista (qualquer posição, com a mesma chance) e 25% procuram um
que não está. Escreva um programa que mede as comparações de verdade:
busque cada um dos 100 objetos (média dos presentes), busque um ausente,
e calcule a média ponderada. Compare com a fórmula
0.75 * (n + 1) / 2 + 0.25 * n:


```text
Saída esperada:
presentes: média 50.50, ausente: 100
caso médio medido: 62.875
fórmula:           62.875
```

**Dicas:**

1. Conte uma comparação a cada objeto olhado; o ausente olha os 100.
2. A média dos presentes é (1 + 2 + ... + 100) / 100 = 50,5.
3. O caso médio depende da hipótese sobre as consultas: mude o 0.25 e veja.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2612.c
```

---

**Exercício P2613** · ★★☆ · Cubos de gelo

A fábrica de gelo empilha os blocos em torres: a torre i (i = 1..n) tem
i × i × i cubinhos. Escreva cubinhos(n) com dois laços, o de dentro
contando de 0 até i * i * i, e compare com a fórmula (n(n+1)/2)² (a soma
dos cubos é o quadrado da soma aritmética) para n = 4, 10 e 50:


```text
Saída esperada:
n =  4:      100 cubinhos, fórmula      100
n = 10:     3025 cubinhos, fórmula     3025
n = 50:  1625625 cubinhos, fórmula  1625625
```

**Dicas:**

1. Use long no contador e na fórmula: com n = 50, o total passa de 1,6
   milhão.
2. Σ i³ = (Σ i)². O custo é Θ(n⁴).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2613.c
```

---

**Exercício P2614** · ★★☆ · A rede que triplica

Uma corrente de mensagens: na rodada k, 3^k pessoas recebem a mensagem
(1, 3, 9, 27, ...), e o sistema processa cada uma. Com o laço
for (t = 1; t <= n; t *= 3) e um laço de dentro de 0 até t, conte o
processamento total para n = 100, 1000 e 1000000. Mostre ao lado a
fórmula da soma geométrica (3t - 1) / 2, onde t é a última potência de 3
que entrou, e a razão total / n:


```text
Saída esperada:
n =     100: total    121, fórmula    121, razão 1.210
n =    1000: total   1093, fórmula   1093, razão 1.093
n = 1000000: total 797161, fórmula 797161, razão 0.797
```

**Dicas:**

1. 1 + 3 + 9 + ... + t = (3t - 1) / 2: a soma geométrica de razão 3.
2. A razão total / n fica sempre abaixo de 1,5: Θ(n), mesmo com dois laços.
3. Guarde a última potência de 3 usada numa variável fora do laço.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2614.c
```

---

**Exercício P2615** · ★★☆ · Os passos do crivo

O crivo de Eratóstenes marca os múltiplos de cada primo p a partir de
p * p. Escreva o crivo com um vetor de char alocado com malloc (n + 1
posições), conte as marcações (um passo por múltiplo marcado, mesmo que
já estivesse marcado) e os primos, para n = 100, 10000 e 1000000. Mostre
também a razão marcações / (n ln ln n):


```text
Saída esperada:
n =     100:     25 primos,     104 marcações, razão 0.681
n =   10000:   1229 primos,   16981 marcações, razão 0.765
n = 1000000:  78498 primos, 2122048 marcações, razão 0.808
```

**Dicas:**

1. O laço de fora vai enquanto p * p <= n; o de dentro anda de p em p.
2. A soma n/2 + n/3 + n/5 + ... sobre os primos cresce como n ln ln n:
   quase linear.
3. log de <math.h> é o ln. O vetor tem n + 1 bytes: Θ(n) de espaço. Não
   esqueça o free.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2615.c
```

---

**Exercício P2616** · ★★☆ · A pilha do quick sort azarado

O quick sort abaixo usa o último elemento como pivô. Meça a profundidade
máxima da recursão (prof e prof_max globais) ao ordenar 1000 senhas de
atendimento em três situações: já em ordem crescente, em ordem
decrescente e embaralhadas (com o gerador do programa):


```text
Saída esperada:
crescente  : profundidade 1000
decrescente: profundidade 1000
embaralhado: profundidade 22
```

**Dicas:**

1. Conte o frame na entrada do quick e descarte na saída, antes do return.
2. Com a entrada em ordem, cada partição tira só o pivô: 1000 níveis, Θ(n)
   de pilha.
3. Embaralhado, a profundidade fica perto de alguns log2 n: Θ(log n) em
   média.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2616.c
```

---

**Exercício P2617** · ★★☆ · CPF repetido no cadastro

O cadastro da academia tem 5000 sócios, cada um com um código de 0 a
9999 (gerado no programa). Existe código repetido? Escreva duas versões,
contando passos e bytes extras:
- pares: compara todos os pares i < j, para no primeiro repetido;
- tabela: um vetor de 10000 char (calloc) marca os códigos já vistos;

```text
para no primeiro que já estava marcado.
```

Mostre o primeiro código repetido que cada uma acha (pela ordem em que
acham), os passos e os bytes:


```text
Saída esperada:
pares:  repetido 8249,   15994 passos,     0 bytes
tabela: repetido 3716,      81 passos, 10000 bytes
```

**Dicas:**

1. Na versão pares, o "primeiro" é o primeiro j para o menor i que tem par.
2. Na tabela, um passo por sócio olhado; os bytes são 10000.
3. Θ(n²) e Θ(1) de espaço contra Θ(n) e Θ(k) de espaço, com k = 10000
   códigos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2617.c
```

---

**Exercício P2618** · ★★☆ · Potência sem pilha

A potência abaixo é recursiva e linear: para 3^e, empilha e + 1 frames e
faz e multiplicações. Reescreva potencia com um laço só, sem recursão,
pelo método das potências de 2 (quadrados sucessivos): enquanto e > 0,
se e é ímpar multiplique o resultado pela base; eleve a base ao quadrado;
divida e por 2. Faça as contas módulo 1000000007 e conte as
multiplicações. Mostre o resultado e as multiplicações para e = 10, 1000
e 1000000000:


```text
Saída esperada:
3^10 mod p = 59049, 6 multiplicações
3^1000 mod p = 56888193, 16 multiplicações
3^1000000000 mod p = 235939645, 43 multiplicações
```

**Dicas:**

1. São 2 multiplicações no máximo por volta, e floor(log2 e) + 1 voltas.
2. Espaço extra Θ(1) (três variáveis) e tempo Θ(log e). A versão do
   esqueleto é Θ(e) nos dois.
3. Os resultados batem com o exercício E1005.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2618.c
```

---

**Exercício P2619** · ★★☆ · O maior n que cabe no orçamento

O servidor da prefeitura aguenta 100 milhões de operações por consulta.
Para cada custo, ache o maior n tal que custo(n) <= 100000000: n, n log2 n,
n², n³ e 2ⁿ. Faça uma busca: dobre n até passar do orçamento e depois
faça uma busca binária entre o último que coube e o primeiro que não
coube:


```text
Saída esperada:
n      : n até 100000000
n log n: n até 4523071
n^2    : n até 10000
n^3    : n até 464
2^n    : n até 26
```

**Dicas:**

1. Calcule os custos em double: n³ e 2ⁿ estouram long rápido.
2. Guarde os cinco custos num vetor de ponteiros para função double
   f(double n).
3. Repare na escala: o orçamento que roda 100 milhões em Θ(n) roda só 26 em
   Θ(2ⁿ).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2619.c
```

---

**Exercício P2620** · ★★☆ · A tabela de distâncias pela metade

A tabela de distâncias entre n bairros é simétrica (d[i][j] = d[j][i]) e
tem zeros na diagonal. Em vez de uma matriz n × n de double, guarde só os
pares i < j num vetor compacto de n(n-1)/2 posições, com o índice
pos(i, j) = i * n - i * (i + 1) / 2 + (j - i - 1). Preencha com
d(i, j) = 2.5 * (i + j) + 1 (só para ter valores), mostre os bytes da
matriz e do vetor para n = 100 e confira que os valores lidos pela
função distancia(i, j) (que aceita i > j e i == j) batem com a fórmula
em todos os pares:


```text
Saída esperada:
matriz: 80000 bytes
vetor:  39600 bytes
pares conferidos: 10000, erros: 0
distancia(7, 3) = 26.0
```

**Dicas:**

1. distancia(i, j): se i == j devolve 0; se i > j troca os dois; senão lê
   v[pos(i, j)].
2. Matriz: n² × 8 = 80000 bytes. Vetor: n(n-1)/2 × 8 = 39600 bytes. Mesma
   classe Θ(n²), menos da metade da memória.
3. Para conferir, conte quantos pares (i, j), com i e j de 0 a 99, dão
   diferença maior que 1e-9.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2620.c
```

## ★★★ Desafio

**Exercício P2621** · ★★★ · As fatias que deram zero

Conserte o programa. Ele mede os passos da conferência de pares da fila
do banco, f(n) = n(n+1)/2 + 3n, e procura as fatias do sanduíche do Θ(n²):
c1 = menor e c2 = maior valor de passos / n² para n de 10 a 2000. Mas a
saída sai assim:


```text
Saída que aparece:
c1 = 0.0000, c2 = 0.0000
```


Ache o erro na conta da razão (o laço e o contador estão certos):


```text
Saída esperada:
c1 = 0.5018, c2 = 0.8500
```

**Dicas:**

1. passos / (n * n) é divisão de inteiros, e a razão é sempre menor que 1:
   dá 0 em toda a faixa.
2. Converta antes de dividir: (double)passos / ((double)n * n). Converter o
   resultado já truncado não adianta.
3. Com n = 10, a razão é (55 + 30) / 100 = 0,85. Ela desce para 0,5 sem
   chegar lá.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2621.c
```

---

**Exercício P2622** · ★★★ · Sanduíche com logaritmo

A indexação das notas fiscais custa f(n) = n log2 n + 5n operações. Ache
por busca as fatias do Θ(n log n): para n de 2 até 100000, calcule a razão
f(n) / (n log2 n) e guarde o menor e o maior valor. Mostre também a razão
em n = 2, 1024 e 100000, e conclua com os c1, c2 e n0 que servem:


```text
Saída esperada:
n =      2: razão 6.0000
n =   1024: razão 1.5000
n = 100000: razão 1.3010
menor 1.3010, maior 6.0000
Θ(n log n) com c1 = 1, c2 = 6 e n0 = 2
```

**Dicas:**

1. A razão é 1 + 5 / log2 n: começa em 6 e desce devagar para 1.
2. Como ela nunca fica abaixo de 1, c1 = 1 vale para todo n >= 2; c2 = 6 é
   o valor em n = 2.
3. Comece em n = 2: com n = 1, log2 n = 0 e a razão divide por zero.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2622.c
```

---

**Exercício P2623** · ★★★ · Raiz contra logaritmo

Refute com um programa: √n NÃO é O(log n). Para c = 1, 2, 5 e 10, ache o
último n de 2 até 1000000 em que sqrt(n) <= c * log2(n) e mostre a partir
de onde a desigualdade quebra de vez. Mostre também, para cada c, a razão
sqrt(n) / log2(n) em n = 1000000:


```text
Saída esperada:
c =  1: falha de n = 17 em diante
c =  2: falha de n = 257 em diante
c =  5: falha de n = 3454 em diante
c = 10: falha de n = 20520 em diante
sqrt(n) / log2(n) em n = 1000000: 50.2
```

**Dicas:**

1. Qualquer potência de n, por menor que seja o expoente, passa de qualquer
   c log n.
2. A razão em 1 milhão é a mesma para todo c (uns 50): já passou de todos
   os c testados.
3. sqrt e log2 estão em <math.h>.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2623.c
```

---

**Exercício P2624** · ★★★ · Laço que dobra dentro do laço

Conte exatamente quantas vezes o x++ executa:


```text
for (long i = 1; i < n; i++)
    for (long j = 1; j <= i; j *= 2)
        x++;
```


O laço de dentro roda floor(log2 i) + 1 vezes. Para n potência de 2,
n = 2^k, a soma dá (k - 1) * 2^k + 1. Escreva o programa com o contador e
compare com a fórmula para k = 4, 10 e 16. Mostre também a razão
x / (n log2 n):


```text
Saída esperada:
n =     16: x =      49, fórmula      49, razão 0.766
n =   1024: x =    9217, fórmula    9217, razão 0.900
n =  65536: x =  983041, fórmula  983041, razão 0.938
```

**Dicas:**

1. Agrupe os i que têm o mesmo floor(log2 i) = m: são 2^m valores, cada um
   com m + 1 voltas.
2. Σ (m + 1) 2^m para m de 0 a k - 1 dá (k - 1) 2^k + 1. É Θ(n log n): a
   razão vai para 1.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2624.c
```

---

**Exercício P2625** · ★★★ · Total alocado contra pico de memória

Este merge sort pede um vetor auxiliar novo a CADA intercalação, do
tamanho do pedaço, e libera logo depois. Instrumente o programa com três
medidas: o total de bytes pedidos ao malloc somando todas as chamadas,
os bytes vivos agora e o pico de bytes vivos ao mesmo tempo. Mostre as
três para n = 1024 e 4096 (o "vivos agora" no fim tem que ser 0):


```text
Saída esperada:
n = 1024: total  40960 bytes, pico  4096 bytes, vivos no fim 0
n = 4096: total 196608 bytes, pico 16384 bytes, vivos no fim 0
```

**Dicas:**

1. Some os bytes no malloc (total e vivos, atualizando o pico) e subtraia
   no free.
2. O total é 4 n log2 n: cada nível da recursão aloca n inteiros. Mas só um
   auxiliar vive por vez: o pico é 4n, o da última intercalação.
3. Espaço é o pico, não o total: Θ(n). O total pesa no tempo (o malloc
   custa), não na memória.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2625.c
```

---

**Exercício P2626** · ★★★ · Mesma soma, pilha menor

A soma recursiva soma(v, n) = v[n-1] + soma(v, n-1) empilha n + 1 frames.
Escreva soma_meio(v, ini, fim), também recursiva, que divide o pedaço ao
meio e soma as duas metades (pedaço vazio dá 0, pedaço de 1 dá o próprio
valor). Meça chamadas e profundidade máxima das duas versões para os
100000 consumos de energia do main (consumo[i] = i % 50 + 100):


```text
Saída esperada:
linear: soma 12450000, 100001 chamadas, profundidade 100001
metade: soma 12450000, 199999 chamadas, profundidade 18
```

**Dicas:**

1. soma_meio faz uns 2n chamadas (o tempo continua Θ(n)), mas a
   profundidade cai para uns log2 n + 1.
2. Use dois contadores globais por versão, ou zere os mesmos antes de cada
   medida.
3. Espaço Θ(n) contra Θ(log n), com o mesmo resultado e o mesmo tempo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2626.c
```

---

**Exercício P2627** · ★★★ · Selection contra insertion

Compare o selection sort e o insertion sort em 1000 notas de alunos, nas
três entradas clássicas: já ordenada, ao contrário e embaralhada (com o
gerador do programa). Conte comparações entre elementos e movimentações
(no selection, cada troca conta 1; no insertion, cada elemento deslocado
conta 1 e a colocação do x conta 1):


```text
Saída esperada:
entrada       selection: comps   movs | insertion: comps   movs
ordenada               499500      0 |              999    999
invertida              499500    500 |           499500 500499
embaralhada            499500    990 |           250293 250302
```

**Dicas:**

1. O selection faz n(n-1)/2 = 499500 comparações em qualquer entrada:
   melhor e pior caso coincidem, Θ(n²).
2. O insertion faz n - 1 = 999 comparações na entrada ordenada (Θ(n)) e
   n(n-1)/2 na invertida.
3. Conte a troca do selection só quando o menor não está já na posição (min
   != i). Use o mesmo vetor embaralhado nos dois.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2627.c
```

---

**Exercício P2628** · ★★★ · Estimando o expoente

Três funções sem documentação. Instrumente cada uma com um contador de
passos (no laço mais interno), rode com n = 4096 e n = 8192 e estime o
expoente p do custo n^p por p = log2(passos(2n) / passos(n)). Mostre os
passos e o p estimado com 3 casas:


```text
Saída esperada:
a:   176736 ->   498316, p = 1.495
b:  8386560 -> 33550336, p = 2.000
c:    49152 ->   106496, p = 1.115
```

**Dicas:**

1. a: o laço de dentro roda enquanto j * j < i: uns sqrt(i) passos, e a
   soma dá uns (2/3) n^1,5.
2. b: laço dependente j < i: n(n-1)/2, p perto de 2.
3. c: o de fora dobra e o de dentro anda n: n log n. O p sai um pouco acima
   de 1 (o log engana o expoente).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2628.c
```

---

**Exercício P2629** · ★★★ · Distância de edição em duas linhas

A distância de edição (assunto 0142) entre "paralelepipedo" e
"paralelogramo" se calcula com uma tabela de (m + 1) × (k + 1) inteiros.
Mas cada linha só depende da anterior. Escreva duas versões:
- tabela: a matriz inteira com malloc;
- linhas: só dois vetores de k + 1 inteiros, trocando os papéis a cada

```text
linha.
```

Mostre a distância e os bytes de cada uma, e repita para duas palavras
de 2000 letras geradas no programa (a[i] = 'a' + i % 7, b[i] = 'a' + i % 5):


```text
Saída esperada:
curtas: tabela 6 (840 bytes), linhas 6 (112 bytes)
longas: tabela 912 (16016004 bytes), linhas 912 (16008 bytes)
```

**Dicas:**

1. d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + (a[i-1] !=
   b[j-1])).
2. Na versão de linhas, ant e atual são dois ponteiros; no fim de cada i,
   troque-os.
3. Tempo Θ(mk) nas duas; espaço Θ(mk) contra Θ(k). Com 2000 letras: 16 MB
   contra 16 KB.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2629.c
```

---

**Exercício P2630** · ★★★ · Três jeitos do melhor trecho

O saldo diário de uma lanchonete (lucro ou prejuízo, em reais) está no
vetor do main, gerado com saldo[i] = sorteia(201) - 100. Qual trecho de
dias seguidos dá a maior soma? Escreva três versões, cada uma com seu
contador de passos (no laço mais interno):
- cubica: para cada início e fim, soma o trecho do zero: Θ(n³);
- quadratica: para cada início, vai somando ao estender o fim: Θ(n²);
- linear (Kadane): uma passada, guardando a melhor soma que termina no

```text
dia atual: Θ(n).
```

Rode com n = 100 e n = 200 e mostre a maior soma e os passos de cada uma:


```text
Saída esperada:
n = 100
  cubica    : soma 669,   171700 passos
  quadratica: soma 669,     5050 passos
  linear    : soma 669,      100 passos
n = 200
  cubica    : soma 669,  1353400 passos
  quadratica: soma 669,    20100 passos
  linear    : soma 669,      200 passos
```

**Dicas:**

1. As três têm que dar a mesma soma. A cúbica faz Σ dos tamanhos de todos
   os trechos: n(n+1)(n+2)/6.
2. Kadane: atual = max(saldo[i], atual + saldo[i]); melhor = max(melhor,
   atual).
3. Gere os 200 saldos uma vez só; o caso n = 100 usa os 100 primeiros.
4. Ao dobrar n, os passos vão perto de × 8, × 4 e × 2.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 26-analise-formal/lista/P2630.c
```
