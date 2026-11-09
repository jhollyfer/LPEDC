<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 10 · Pensar como cientista da computação

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/10-analise/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1001** · ★☆☆ · Quantas vezes dá para dividir

O laço "while (n > 1) n = n / 2;" roda cerca de log₂ n vezes, e com
"n = n / 3" roda cerca de log₃ n vezes. Escreva duas funções,
int passos_metade(int n) e int passos_terco(int n), que rodam cada laço e
devolvem quantas voltas ele deu. Mostre a tabela para n = 10, 100, 1000 e
1000000, com printf("%8d %4d %4d\n", ...) e o cabeçalho abaixo.


```text
Saída esperada:
       n   /2   /3
      10    3    2
     100    6    4
    1000    9    6
 1000000   19   12
```

**Dicas:**

1. Conte uma volta a cada divisão; com n = 1 o laço nem começa (0 voltas).
2. O cabeçalho é printf("%8s %4s %4s\n", "n", "/2", "/3").
3. Repare: multiplicar n por 1000 só soma umas 10 voltas no /2. Trocar a
   base do log muda a conta por uma constante (log₃ n = log₂ n / log₂ 3),
   por isso as duas funções são O(log n).
4. Resposta esperada: a tabela acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1001.c
```

---

**Exercício P1002** · ★☆☆ · A planilha inteira contra a diagonal

Uma planilha quadrada n x n tem, na linha i e coluna j, o valor i + j
(contando de 0). Escreva duas funções que recebem n (até 8) e um ponteiro
para um contador de somas:


```text
int soma_tudo(int m[8][8], int n, int *somas)       // todas as células
int soma_diagonal(int m[8][8], int n, int *somas)   // só m[i][i]
```


Cada "s += ..." conta 1 soma. Preencha a matriz no main e mostre os
resultados para n = 2, 4 e 8.


```text
Saída esperada:
n = 2: soma 4 (4 somas), diagonal 2 (2 somas)
n = 4: soma 48 (16 somas), diagonal 12 (4 somas)
n = 8: soma 448 (64 somas), diagonal 56 (8 somas)
```

**Dicas:**

1. soma_tudo tem dois for aninhados de 0 a n - 1: n · n somas, O(n²).
2. soma_diagonal tem um for só: n somas, O(n).
3. Repare: dobrar n multiplica por 4 as somas da planilha inteira e só
   por 2 as da diagonal.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1002.c
```

---

**Exercício P1003** · ★☆☆ · O laço contra a fórmula de Gauss

Um app de poupança junta 1 real no dia 1, 2 no dia 2, ..., n no dia n.
Quanto há no dia n? Escreva duas funções que devolvem a soma 1 + 2 + ...
+ n e contam, em *passos, quantas operações aritméticas fizeram:


```text
long long soma_laco(int n, int *passos)     // um for: 1 passo por soma
long long soma_formula(int n, int *passos)  // n (n + 1) / 2: conte 3
```


Mostre o resultado para n = 100 e n = 100000.


```text
Saída esperada:
n = 100: laço 5050 (100 passos), fórmula 5050 (3 passos)
n = 100000: laço 5000050000 (100000 passos), fórmula 5000050000 (3 passos)
```

**Dicas:**

1. Com n = 100000 a soma passa de 2 bilhões: use long long e "%lld".
2. Na fórmula, faça a conta em long long: (long long) n * (n + 1) / 2.
   A soma, a multiplicação e a divisão são os 3 passos.
3. O laço é O(n); a fórmula é O(1): não importa o tamanho de n.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1003.c
```

---

**Exercício P1004** · ★☆☆ · Multiplicar somando, com invariante

A máquina de cartão antiga só sabia somar, então multiplicava assim:


```text
int multiplica(int a, int b) {   // b >= 0
    int r = 0;
    for (int i = 0; i < b; i++) {
        r = r + a;
    }
    return r;
}
```


Escreva a função com DOIS assert: um no começo do corpo do for, com o
invariante (o que vale sobre r e i em toda volta), e um depois do laço,
com o que vale no término. Teste com 7 x 6, 12 x 0 e 3 x 15.


```text
Saída esperada:
7 x 6 = 42
12 x 0 = 0
3 x 15 = 45
```

**Dicas:**

1. Antes da volta i, quantas vezes o a já foi somado em r?
2. O invariante é r == a * i. Quando o laço termina, i == b, então o
   invariante vira r == a * b, que é justamente o que se queria.
3. Com b = 0 o corpo nem roda, mas o assert do término ainda vale: r == 0.
4. Resposta esperada: a saída acima, sem nenhum assert disparar.

```bash
~/LPEDC/rodar 10-analise/lista/P1004.c
```

---

**Exercício P1005** · ★☆☆ · O termômetro do freezer (só pela interface)

O TAD Termometro abaixo já está pronto: a parte "termometro.h" é a
interface, e a "termometro.c", a implementação. Escreva SÓ o cliente (o
main), sem tocar nos campos da struct: registre as leituras do freezer
-18, -20, -15, -22 e -19 graus e mostre o resumo. Conte também, no
cliente, quantas leituras passaram de -16 graus (o alarme do freezer).


```text
Saída esperada:
Leituras: 5
Mínima: -22.0
Máxima: -15.0
Média: -18.8
Alarmes (acima de -16): 1
```

**Dicas:**

1. Comece com Termometro *t = termometro_cria(); e confira se veio NULL.
2. Para o alarme, compare a leitura ANTES de registrá-la: o TAD não
   guarda a lista de leituras, só o resumo.
3. Não esqueça termometro_libera(t) no fim.
4. Resposta esperada: a saída acima (média -94 / 5 = -18.8).

```bash
~/LPEDC/rodar 10-analise/lista/P1005.c
```

---

**Exercício P1006** · ★☆☆ · Quantos dígitos tem o valor do boleto

Escreva int digitos(long long n, int *passos), que conta os dígitos de
n >= 0 dividindo por 10 até sobrar zero, e conta em *passos quantas
divisões fez. Use um do-while, para que o 0 tenha 1 dígito. Mostre o
resultado para 0, 7, 70, 7000, 7000000 e 7000000000.


```text
Saída esperada:
0: 1 dígito(s), 1 divisões
7: 1 dígito(s), 1 divisões
70: 2 dígito(s), 2 divisões
7000: 4 dígito(s), 4 divisões
7000000: 7 dígito(s), 7 divisões
7000000000: 10 dígito(s), 10 divisões
```

**Dicas:**

1. do { n = n / 10; cont++; } while (n > 0);
2. 7000000000 não cabe num int: use long long e "%lld".
3. n multiplicado por 1000 custa só 3 divisões a mais: o número de passos
   é piso(log₁₀ n) + 1, ou seja, O(log n).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1006.c
```

---

**Exercício P1007** · ★☆☆ · O caixa que o invariante dedurou

A função soma abaixo devia somar as vendas do dia, e alguém já deixou o
invariante escrito num assert: no começo de cada volta, s é a soma de
v[0..i-1]. Rode: o assert dispara logo na primeira volta, porque o laço
tem um erro de propósito. Conserte o LAÇO (não mexa no assert) para a
saída ficar:


```text
Saída esperada:
Caixa do dia: R$ 187
Média por venda: R$ 46.75
```

**Dicas:**

1. Na primeira volta, quanto vale s e quanto vale soma_ate(v, i)?
2. Que venda o laço nunca soma?
3. Resposta esperada: o for começa em i = 1 e pula a primeira venda; com
   i = 0 o invariante vale em toda volta e a soma dá 45 + 30 + 62 + 50 =
   187.

```bash
~/LPEDC/rodar 10-analise/lista/P1007.c
```

---

**Exercício P1008** · ★☆☆ · O polinômio pelo jeito de Horner

O preço do frete de uma transportadora segue o polinômio
p(x) = 2x⁴ - 3x³ + 0x² + 5x - 7, em que x é a distância em centenas de km.
Os coeficientes ficam num vetor do grau 0 ao 4: c = {-7, 5, 0, -3, 2}.
Escreva duas funções que calculam p(x) e contam as multiplicações:


```text
long ingenuo(const int c[], int grau, int x, int *mult)
  para cada termo k, calcula x elevado a k com um laço (k
  multiplicações) e multiplica pelo coeficiente (mais 1);
long horner(const int c[], int grau, int x, int *mult)
  r = c[grau]; depois, para k de grau - 1 até 0, r = r * x + c[k].
```


Mostre os dois para x = 3.


```text
Saída esperada:
Ingênuo: p(3) = 89 com 15 multiplicações
Horner:  p(3) = 89 com 4 multiplicações
```

**Dicas:**

1. Horner reescreve p(x) como (((2x - 3)x + 0)x + 5)x - 7.
2. No ingênuo, grau 4 dá 0 + 1 + 2 + 3 + 4 = 10 multiplicações das
   potências mais 5 dos coeficientes. Para grau n: (n + 1)(n + 2) / 2,
   O(n²). Horner faz n: O(n).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1008.c
```

---

**Exercício P1009** · ★☆☆ · O TAD da rifa da escola

A rifa tem números de 0 a 63. A interface "conjunto.h" já está escrita, e
o cliente também. Falta a implementação: escreva o "conjunto.c" com uma
struct que guarda um vetor bool de 64 posições e um contador, de modo que
pertence, insere e remove custem O(1) e tamanho também (sem contar o
vetor a cada chamada). Número fora de 0..63 é recusado (insere devolve
false). Inserir de novo um número que já está não muda nada.


```text
Saída esperada:
Vendidos: 3
42 vendido? sim
13 vendido? não
64 aceito? não
```

**Dicas:**

1. struct conjunto { bool tem[64]; int n; };
2. Em insere, só some 1 em n se o número ainda não estava. Em remove, só
   subtraia se estava. Assim o invariante "n é o número de posições true"
   vale depois de toda operação.
3. Resposta esperada: a saída acima (vendidos 7, 42 e 63; o 13 saiu).

```bash
~/LPEDC/rodar 10-analise/lista/P1009.c
```

---

**Exercício P1010** · ★☆☆ · Os apertos de mão da reunião

Numa reunião de condomínio com n pessoas, cada uma aperta a mão de cada
outra uma vez. Escreva long apertos_laco(int n), que conta os apertos com
dois for aninhados (a pessoa i aperta a mão de cada j > i), e
long apertos_formula(int n), que devolve n (n - 1) / 2. Mostre os dois
para n = 5, 10, 50 e 1000, e diga se conferem.


```text
Saída esperada:
n = 5: laço 10, fórmula 10, confere
n = 10: laço 45, fórmula 45, confere
n = 50: laço 1225, fórmula 1225, confere
n = 1000: laço 499500, fórmula 499500, confere
```

**Dicas:**

1. for (i = 0; i < n; i++) for (j = i + 1; j < n; j++) cont++;
2. A pessoa 0 faz n - 1 apertos, a 1 faz n - 2, ..., a última faz 0:
   (n - 1) + (n - 2) + ... + 0 = n (n - 1) / 2. É Θ(n²), e é o mesmo
   número de comparações de quem testa "todo par" num vetor.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1010.c
```

## ★★☆ Para pensar

**Exercício P1011** · ★★☆ · Achar a fórmula exata de T(n)

Este trecho pinta faixas de um mural: a cada duas colunas, pinta da
coluna i até o fim.


```text
for (int i = 0; i < n; i += 2)
    for (int j = i; j < n; j++)
        passos++;
```


Escreva long conta(int n), que roda o trecho e devolve passos, e
long formula(int n), que calcula o mesmo número SEM laço nenhum, com uma
expressão em n. Mostre conta(n) para n = 1 a 6 e depois confira se
formula(n) == conta(n) para todo n de 1 a 1000.


```text
Saída esperada:
T(1) = 1
T(2) = 2
T(3) = 4
T(4) = 6
T(5) = 9
T(6) = 12
Fórmula confere de 1 a 1000: sim
```

**Dicas:**

1. Separe n par (n = 2m) e n ímpar (n = 2m + 1). Com n = 2m, o laço de
   dentro roda 2m, 2m - 2, ..., 2 vezes: 2 (1 + 2 + ... + m) = m (m + 1).
2. Com n = 2m + 1: 2m + 1, 2m - 1, ..., 1, a soma dos ímpares: (m + 1)².
3. As duas cabem numa expressão só com divisão inteira:
   ((n + 1) / 2) * ((n + 2) / 2). Confira com n = 5: 3 * 3 = 9.
4. Resposta esperada: a saída acima. T(n) ≈ n² / 4, então Θ(n²).

```bash
~/LPEDC/rodar 10-analise/lista/P1011.c
```

---

**Exercício P1012** · ★★☆ · Primos: dividir contra peneirar

Para sortear senhas, o sistema precisa de todos os primos até N. Escreva
dois jeitos de contar os primos de 2 a N, contando o trabalho de cada um:


```text
int por_divisao(int n, long *ops)
  para cada k de 2 a n, testa os divisores d = 2, 3, ... enquanto
  d * d <= k, parando no primeiro que divide. Cada k % d é 1 operação.
int por_crivo(int n, long *ops)
  o crivo de Eratóstenes: um vetor bool com todos "primo", e para cada
  i primo com i * i <= n, marca i*i, i*i + i, ... como não primo. Cada
  marcação é 1 operação.
```


Mostre os dois para N = 100 e N = 10000 (use um vetor de 10001 bool).


```text
Saída esperada:
N = 100: 25 primos | divisão: 236 ops | crivo: 104 ops
N = 10000: 1229 primos | divisão: 117527 ops | crivo: 16981 ops
```

**Dicas:**

1. Na divisão, o laço de dentro é for (d = 2; d * d <= k; d++) e sai com
   break quando k % d == 0.
2. No crivo, o laço de dentro começa em i * i porque os múltiplos menores
   já foram marcados por primos menores que i.
3. A divisão custa perto de N·√N / log N; o crivo, N·log log N. Com N
   100 vezes maior, a divisão ficou 500 vezes mais cara e o crivo, 160.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1012.c
```

---

**Exercício P1013** · ★★☆ · Busca binária com o invariante à vista

As senhas atendidas no dia estão em ordem: 3, 8, 15, 21, 29, 34, 42, 50,
57 e 63. Escreva int busca(const int v[], int n, int x, int *passos), a
busca binária com ini e fim (intervalo fechado), e ponha dois assert:


```text
- no começo de cada volta, o invariante: "x não está fora de
  v[ini..fim]", isto é, não está em v[0..ini-1] nem em v[fim+1..n-1];
- depois do laço (quando não achou), ini > fim: o intervalo ficou vazio,
  e então o invariante garante que x não está no vetor.
```


Para o assert, escreva bool fora_ausente(v, n, ini, fim, x), que confere
as duas pontas de fora com laços simples. Conte em *passos as voltas do
laço. Procure 42, 3 e 60.


```text
Saída esperada:
42: posição 6 (4 passos)
3: posição 0 (3 passos)
60: não está (4 passos)
```

**Dicas:**

1. Se v[meio] < x, todo v[0..meio] é < x (o vetor é crescente): ini =
   meio + 1 preserva o invariante. O mesmo vale do outro lado.
2. fora_ausente custa O(n) por chamada, então ela só serve para provar a
   corretude. Numa versão de produção, os assert saem (ou se compila com
   -DNDEBUG) e a busca volta a ser O(log n).
3. Resposta esperada: a saída acima, sem nenhum assert disparar.

```bash
~/LPEDC/rodar 10-analise/lista/P1013.c
```

---

**Exercício P1014** · ★★☆ · Separar débitos e créditos no lugar

O extrato do mês tem os lançamentos 120, -30, 45, -80, -10, 60, 0 e -5.
Escreva int separa(int v[], int n), que deixa todos os negativos (os
débitos) no começo do vetor, sem vetor auxiliar, e devolve quantos são.
Use um índice i (a fronteira) e um j que percorre o vetor: quando v[j] é
negativo, troque v[i] com v[j] e avance i. Conte as trocas.

Ponha no começo de cada volta um assert com o invariante: v[0..i-1] são
todos negativos e v[i..j-1] são todos >= 0. Escreva a função auxiliar
bool invariante(const int v[], int i, int j) para isso.


```text
Saída esperada:
Débitos: -30 -80 -10 -5
Créditos: 45 60 0 120
Trocas: 4
```

**Dicas:**

1. Comece com i = 0 e j de 0 a n - 1. Com j = 0, as duas faixas estão
   vazias, e o invariante vale "de graça".
2. No fim, j == n: o invariante diz que v[0..i-1] < 0 e v[i..n-1] >= 0.
   É exatamente o que se queria, e i é a resposta.
3. A função é O(n): cada j é visto uma vez. A ordem dentro de cada grupo
   muda (o 120 foi para o fim): essa partição não é estável.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1014.c
```

---

**Exercício P1015** · ★★☆ · O TAD Data e a contagem para a prova

Escreva um TAD Data, num arquivo só ("data.h", "data.c" e cliente), com o
invariante "a data guardada sempre existe no calendário" (ano bissexto:
divisível por 4 e não por 100, ou divisível por 400). Operações:


```text
Data *data_cria(int dia, int mes, int ano);   // NULL se a data não existe
Data *data_seguinte(const Data *d);           // o dia seguinte (nova Data)
int data_compara(const Data *a, const Data *b);  // < 0, 0 ou > 0
int data_dias_entre(const Data *a, const Data *b); // a <= b
void data_imprime(const Data *d);             // dd/mm/aaaa
void data_libera(Data *d);
```


No cliente, mostre o dia seguinte de 28/02/2024, 28/02/2025 e
31/12/2026, tente criar 30/02/2025 e conte os dias do fim das
inscrições do PPGI (09/11/2026) até a prova (27/11/2026).


```text
Saída esperada:
Depois de 28/02/2024 vem 29/02/2024
Depois de 28/02/2025 vem 01/03/2025
Depois de 31/12/2026 vem 01/01/2027
30/02/2025: data inválida
De 09/11/2026 até 27/11/2026: 18 dias
```

**Dicas:**

1. Uma função static int dias_no_mes(int mes, int ano) resolve a validação
   e o dia seguinte.
2. data_dias_entre pode andar de dia em dia com data_seguinte até chegar
   em b (O(dias)). Libere cada Data intermediária.
3. data_compara: compare ano, depois mês, depois dia.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1015.c
```

---

**Exercício P1016** · ★★☆ · Crescer de um em um ou dobrar?

Um vetor que cresce com realloc precisa, quando enche, copiar os itens
para um bloco maior. Quanto custa inserir n itens, um de cada vez, com
cada estratégia? Simule SEM alocar nada, só contando as cópias:


```text
long copias_mais_um(int n)  // capacidade começa em 1 e cresce de 1 em 1
long copias_dobra(int n)    // capacidade começa em 1 e dobra
```


Em ambas: quando o vetor tem tam == cap itens e chega mais um, ele cresce
e copia os tam itens que já tinha. Mostre para n = 1000 e n = 2000, e a
média de cópias por inserção com n = 2000.


```text
Saída esperada:
n = 1000: +1 copia 499500, dobrando copia 1023
n = 2000: +1 copia 1999000, dobrando copia 2047
Por inserção (n = 2000): +1 = 999.5, dobrando = 1.0
```

**Dicas:**

1. Simule com duas variáveis, tam e cap: para cada inserção, se tam ==
   cap, some tam às cópias e aumente cap; depois, tam++.
2. Crescendo de 1 em 1: 1 + 2 + ... + (n - 1) = n (n - 1) / 2 cópias,
   O(n²) no total. Dobrando: 1 + 2 + 4 + ... < 2n, O(n) no total, O(1)
   por inserção "em média" (o custo amortizado).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1016.c
```

---

**Exercício P1017** · ★★☆ · A busca que não acha o último ônibus

Os horários de saída do terminal (em minutos depois das 5h) estão em
ordem: 5, 12, 20, 33, 41 e 58. A busca binária abaixo compila sem aviso e
acha o 5, mas diz que o 58 e o 33 "não têm". Ela tem um erro de propósito.
Conserte, usando o invariante para guiar: "se x está no vetor, está em
v[ini..fim]" (intervalo FECHADO, com as duas pontas valendo).


```text
Saída esperada:
58: posição 5
5: posição 0
33: posição 3
40: não tem
```

**Dicas:**

1. Faça o teste de mesa do 58: ini = 0, fim = 5, meio = 2, ...
   Quando ini == fim, quantas posições ainda podem ter o x?
2. Com intervalo fechado, o intervalo só fica vazio quando ini > fim.
3. Resposta esperada: o laço é while (ini < fim), que para com uma
   posição ainda sem olhar. O certo é while (ini <= fim). A saída fica
   igual à de cima.

```bash
~/LPEDC/rodar 10-analise/lista/P1017.c
```

---

**Exercício P1018** · ★★☆ · Euclides, o invariante e o pior caso

O marceneiro quer cortar duas tábuas em pedaços iguais, do maior tamanho
possível: é o mdc dos comprimentos. Escreva int mdc(int a, int b, int
*passos), o algoritmo de Euclides iterativo (troca (a, b) por (b, a % b)
até b == 0), contando as divisões. Ponha um assert com o invariante: o
mdc do par atual é sempre o mesmo do par original. Para conferir, escreva
int mdc_lento(int a, int b), que testa os divisores de cima para baixo.
Teste com (1071, 462), (89, 55) e (100, 75).


```text
Saída esperada:
mdc(1071, 462) = 21 em 3 passos
mdc(89, 55) = 1 em 9 passos
mdc(100, 75) = 25 em 2 passos
```

**Dicas:**

1. Guarde g = mdc_lento(a, b) antes do laço e, no começo de cada volta,
   assert(mdc_lento(a, b) == g). Cuidado: mdc_lento(x, 0) é x.
2. O invariante vale porque todo divisor de a e b também divide a % b
   (e vice-versa).
3. Dois Fibonacci seguidos (89 e 55) são o pior caso de Euclides: cada
   passo só desce um degrau na sequência. Mesmo assim o número de passos
   é O(log n).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1018.c
```

---

**Exercício P1019** · ★★☆ · O resumo da corrida em O(1)

O app de corrida mostra o resumo depois de cada treino e não quer guardar
a lista inteira de tempos. Escreva o TAD Resumo, num arquivo só
("resumo.h", "resumo.c" e cliente), em que TODA operação custa O(1),
guardando só agregados (quantidade, soma, soma dos quadrados, menor e
maior):


```text
Resumo *resumo_cria(void);
void resumo_adiciona(Resumo *r, double x);
int resumo_quantidade(const Resumo *r);
double resumo_media(const Resumo *r);
double resumo_menor(const Resumo *r);
double resumo_maior(const Resumo *r);
double resumo_desvio(const Resumo *r);  // desvio padrão populacional
void resumo_libera(Resumo *r);
```


Teste com os tempos, em minutos, 32, 29, 35, 31, 28 e 33.


```text
Saída esperada:
Corridas: 6
Média: 31.33 min
Melhor: 28 min
Pior: 35 min
Desvio: 2.36 min
```

**Dicas:**

1. Variância = (soma dos quadrados / n) - média². O desvio é a raiz
   (sqrt, de math.h; o rodar já liga a biblioteca com -lm).
2. A interface não muda se um dia você trocar a implementação para
   guardar todos os tempos (para ter a mediana, por exemplo): o cliente
   continua compilando igual. Só o custo muda.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1019.c
```

---

**Exercício P1020** · ★★☆ · As duplas da gincana em O(n)

Na gincana da escola, uma dupla ganha bônus se a soma das idades dos dois
for par. As idades dos 8 inscritos são 3, 8, 5, 12, 7, 10, 1 e 4 (é a
gincana da família). Quantas duplas ganham bônus? Escreva:


```text
long duplas_lento(const int v[], int n, long *passos)
  testa todo par i < j e conta 1 passo por par testado;
long duplas_rapido(const int v[], int n, long *passos)
  percorre o vetor UMA vez contando pares e ímpares (1 passo por item) e
  depois calcula a resposta com uma conta.
```



```text
Saída esperada:
Lento: 12 duplas em 28 passos
Rápido: 12 duplas em 8 passos
```

**Dicas:**

1. Soma par só acontece com par + par ou ímpar + ímpar.
2. Com p pares e q ímpares: p (p - 1) / 2 + q (q - 1) / 2 duplas.
3. O lento é Θ(n²) (n (n - 1) / 2 pares); o rápido é Θ(n). Pensar no
   problema, e não só no código, foi o que trocou a classe.
4. Resposta esperada: a saída acima (4 pares e 4 ímpares: 6 + 6 = 12).

```bash
~/LPEDC/rodar 10-analise/lista/P1020.c
```

## ★★★ Desafio

**Exercício P1021** · ★★★ · A melhor sequência de dias do food truck

O lucro diário do food truck, em centenas de reais, nos últimos 10 dias
foi: -3, 5, -2, 8, -10, 4, 7, -1, -7, 3. Qual sequência de dias SEGUIDOS
deu o maior lucro somado? É o problema do subvetor de soma máxima.
Escreva três versões, todas devolvendo a soma e preenchendo *ini e *fim
(índices de 0 a n - 1) e contando as somas feitas em *somas:


```text
int cubica(const int v[], int n, int *ini, int *fim, long *somas)
  para cada par (i, j), soma v[i..j] do zero com um terceiro laço;
int quadratica(const int v[], int n, int *ini, int *fim, long *somas)
  para cada i, vai somando v[j] para j = i, i + 1, ... (aproveita a
  soma anterior);
int linear(const int v[], int n, int *ini, int *fim, long *somas)
  o algoritmo de Kadane: percorre uma vez, guardando a melhor soma que
  TERMINA no dia atual. Se essa soma ficou <= 0, recomece no dia atual.
```


Em todas, troque a melhor só quando a nova soma for ESTRITAMENTE maior.
Mostre os dias contando de 1.


```text
Saída esperada:
Cúbica:     12 (dias 2 a 7), 220 somas
Quadrática: 12 (dias 2 a 7), 55 somas
Linear:     12 (dias 2 a 7), 10 somas
```

**Dicas:**

1. Na cúbica, o par (i, j) faz j - i + 1 somas; no total
   n (n + 1) (n + 2) / 6 = 220 para n = 10: Θ(n³). A quadrática faz
   n (n + 1) / 2 = 55: Θ(n²). Kadane faz n: Θ(n).
2. Kadane: atual = soma da melhor sequência que termina em j. Se
   atual <= 0, atual = v[j] e comeco = j; senão, atual += v[j]. Conte 1
   soma por dia.
3. O invariante de Kadane: depois de processar o dia j, melhor é a maior
   soma de um subvetor de v[0..j].
4. Resposta esperada: a saída acima (5 - 2 + 8 - 10 + 4 + 7 = 12).

```bash
~/LPEDC/rodar 10-analise/lista/P1021.c
```

---

**Exercício P1022** · ★★★ · Turmas como conjuntos ordenados

O cursinho quer cruzar as matrículas das turmas de Python e de C. Escreva
um TAD Conjunto, num arquivo só ("conjunto.h", "conjunto.c" e cliente),
guardado como um vetor ORDENADO e sem repetidos (o invariante), que cresce
com realloc dobrando a capacidade:


```text
Conjunto *conj_cria(void);
bool conj_insere(Conjunto *c, int x);  // mantém a ordem; ignora repetido
Conjunto *conj_uniao(const Conjunto *a, const Conjunto *b, long *comp);
Conjunto *conj_intersecao(const Conjunto *a, const Conjunto *b, long *comp);
void conj_imprime(const Conjunto *c);
void conj_libera(Conjunto *c);
```


União e interseção devem ser feitas por INTERCALAÇÃO, andando com um
índice em cada vetor: O(n + m). Conte 1 comparação por volta do laço em
que os dois vetores ainda têm itens. No cliente, compare com a interseção
ingênua (para cada item de a, percorre b inteiro: O(n · m)), que pode ser
escrita usando um vetor comum com os mesmos números.

Python: 25, 3, 12, 8, 20 (inseridos nesta ordem). C: 30, 8, 5, 20, 8.


```text
Saída esperada:
Python: 3 8 12 20 25
C: 5 8 20 30
União: 3 5 8 12 20 25 30 (6 comparações)
Interseção: 8 20 (6 comparações)
Interseção ingênua: 8 20 (20 comparações)
```

**Dicas:**

1. Na intercalação: se a[i] < b[j], o a[i] só está em a (avança i); se
   a[i] > b[j], avança j; se são iguais, está nos dois (avança os dois).
2. Na união, quando um vetor acaba, copie o resto do outro sem comparar.
3. Como os dois já estão em ordem, os resultados saem em ordem, e o
   invariante do TAD vale para eles sem ordenar nada.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1022.c
```

---

**Exercício P1023** · ★★★ · Quem tem a maioria no grêmio?

Na eleição do grêmio estudantil, um candidato só leva no primeiro turno se
tiver MAIS DA METADE dos votos. Escreva duas funções que devolvem o
candidato da maioria (ou -1 se não houver) e contam as comparações:


```text
int maioria_ingenua(const int v[], int n, long *comp)
  para cada i, conta quantas vezes v[i] aparece no vetor inteiro (n
  comparações) e devolve assim que achar um com mais de n / 2;
int maioria_boyer_moore(const int v[], int n, long *comp)
  fase 1: um candidato e um contador; para cada voto, se o contador é 0,
  o voto vira o candidato; se o voto é igual ao candidato, contador++;
  senão, contador--. Fase 2: conta os votos do candidato para confirmar.
  Conte 1 comparação por voto em cada fase.
```


Eleição 1: 1, 3, 2, 2, 1, 2, 2, 3, 2, 2, 2. Eleição 2: 1, 2, 3, 1, 2, 3, 1.


```text
Saída esperada:
Eleição 1: candidato 2 com 7 de 11 votos
  ingênuo: 33 comparações, Boyer-Moore: 22
Eleição 2: ninguém tem maioria
  ingênuo: 49 comparações, Boyer-Moore: 14
```

**Dicas:**

1. Por que a fase 1 funciona: cada "contador--" cancela um voto do
   candidato contra um voto de outro. Quem tem mais da metade não pode ser
   cancelado por inteiro, então sobra no fim.
2. A fase 2 é obrigatória: na eleição 2 a fase 1 termina com um candidato
   (o 1), mas ele tem só 3 de 7.
3. O ingênuo é O(n²) no pior caso (sem maioria, n · n); Boyer-Moore é
   O(n) e usa O(1) de memória extra.
4. Resposta esperada: a saída acima. Imprima a contagem de votos na
   eleição 1 com mais um laço.

```bash
~/LPEDC/rodar 10-analise/lista/P1023.c
```

---

**Exercício P1024** · ★★★ · A busca em escada na tabela de preços

A tabela de fretes tem as linhas (distâncias) e as colunas (pesos) em
ordem crescente: cada linha cresce para a direita e cada coluna cresce
para baixo.


```text
 2  5  9 14 20
 4  8 13 18 25
 7 11 16 22 30
10 15 21 27 35
```


Escreva bool escada(int m[4][5], int x, int *lin, int *col, int *comp),
que começa no canto de CIMA À DIREITA: se o valor é maior que x, a coluna
inteira dali para baixo também é, então vá para a esquerda; se é menor,
a linha inteira dali para a esquerda também é, então desça. Escreva
também a força bruta (linha por linha, parando ao achar) e compare as
comparações para x = 16 e x = 17.


```text
Saída esperada:
16: linha 2, coluna 2 (escada: 5 comparações, força bruta: 13)
17: não está (escada: 7 comparações, força bruta: 20)
```

**Dicas:**

1. Invariante da escada: se x está na matriz, está nas linhas i..3 e nas
   colunas 0..j. Cada passo descarta uma linha ou uma coluna inteira.
2. O laço é while (i < 4 && j >= 0); conte 1 comparação por volta.
3. Com L linhas e C colunas, a escada faz no máximo L + C - 1
   comparações, O(L + C), contra O(L · C) da força bruta.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1024.c
```

---

**Exercício P1025** · ★★★ · Os lugares do cinema num punhado de bits

A sala do cinema tem 256 lugares (0 a 255). Guardar um bool por lugar
gasta 256 bytes; guardando um BIT por lugar, bastam 32. Escreva o TAD
Lugares, num arquivo só ("lugares.h", "lugares.c" e cliente), com um
unsigned char bits[32] escondido na struct:


```text
Lugares *lugares_cria(void);                 // todos livres
void lugares_ocupa(Lugares *l, int k);
void lugares_libera_lugar(Lugares *l, int k);
bool lugares_ocupado(const Lugares *l, int k);
int lugares_conta(const Lugares *l);          // quantos ocupados
Lugares *lugares_uniao(const Lugares *a, const Lugares *b);
Lugares *lugares_intersecao(const Lugares *a, const Lugares *b);
int lugares_bytes(void);                      // memória do vetor de bits
void lugares_libera(Lugares *l);
```


Sessão da tarde: 0, 1, 2, 50, 99, 150 e 199. Sessão da noite: 2, 3, 50,
100 e 199. Mostre quantos foram ocupados em cada sessão, os ocupados nas
duas, quantos foram ocupados em alguma e o tamanho do vetor de bits.


```text
Saída esperada:
Tarde: 7 ocupados
Noite: 5 ocupados
Ocupados nas duas: 2 50 199
Ocupados em alguma: 9
Memória: 32 bytes para 256 lugares
```

**Dicas:**

1. O lugar k fica no byte k / 8, no bit k % 8. Ocupar:
   bits[k / 8] |= 1u << (k % 8). Liberar: &= ~(1u << (k % 8)).
   Testar: (bits[k / 8] >> (k % 8)) & 1.
2. União e interseção são um laço de 32 voltas com | e &: 8 lugares por
   operação. Mesma classe O(n) de um vetor bool, mas 8 vezes menos
   trabalho e memória.
3. Para contar, some os bits de cada byte (com um laço de 8 ou com
   b &= b - 1, que apaga o bit 1 mais baixo).
4. lugares_bytes devolve sizeof(struct lugares), e só pode ser escrita
   DENTRO do lugares.c: o cliente não enxerga a struct, então não
   consegue fazer esse sizeof.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1025.c
```

---

**Exercício P1026** · ★★★ · Duas implementações da lista de presença

A portaria do evento marca quem entrou (pelo número do crachá) e depois
responde "fulano entrou?". Implemente a MESMA interface de dois jeitos,
num arquivo só, e meça qual compensa (os nomes ganharam um sufixo só para
as duas caberem no mesmo arquivo):


```text
Presenca *pres_cria_X(int capacidade);
void pres_marca_X(Presenca *p, int cracha);
bool pres_entrou_X(Presenca *p, int cracha);   // sem const: soma passos
long pres_passos_X(const Presenca *p);   // passos gastos até agora
void pres_libera_X(Presenca *p);
```


- X = A, vetor DESORDENADO: marca põe no fim (1 passo); entrou é a busca

```text
sequencial (1 passo por comparação).
```

- X = B, vetor ORDENADO: marca desloca os maiores para abrir espaço (1

```text
passo por deslocamento, mais 1 para gravar); entrou é a busca binária
(1 passo por volta).
```


Carga de teste: marque os crachás (7 * k) % 1000 para k = 0..999 (os
números de 0 a 999, embaralhados) e depois pergunte por 0, 1, ..., 1999
(metade entrou, metade não). Mostre os passos de cada fase. A struct de
cada versão pode ser igual: int *v, int n e long passos.


```text
Saída esperada:
A (desordenado): marcar 1000 passos, consultar 1500500 passos
B (ordenado):    marcar 214213 passos, consultar 18987 passos
Respostas iguais: sim
```

**Dicas:**

1. Em B, a marcação é a inserção ordenada: i = n; while (i > 0 &&
   v[i - 1] > x) { v[i] = v[i - 1]; i--; } e depois v[i] = x.
2. A consulta de A custa até n por pergunta: 1000 perguntas sem sucesso
   custam 1000 · 1000. A de B custa cerca de log₂ 1000 ≈ 10.
3. Nenhuma é "a melhor": com muitas marcações e poucas consultas, A ganha;
   com muitas consultas, B ganha. Como o cliente só usa a interface, dá
   para trocar uma pela outra sem mexer nele.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1026.c
```

---

**Exercício P1027** · ★★★ · O topo da trilha em O(log n)

O GPS da trilha registrou as altitudes, em metros, a cada quilômetro. Um
PICO é um ponto que não é menor que os vizinhos (as pontas só têm um
vizinho). Todo vetor tem pelo menos um pico, e dá para achar um sem olhar
o vetor inteiro. Escreva:


```text
int pico_sequencial(const int v[], int n, int *comp)
  anda até o primeiro i com v[i] >= v[i + 1] (ou até o fim);
int pico_binario(const int v[], int n, int *comp)
  com ini = 0 e fim = n - 1, enquanto ini < fim: olhe meio e meio + 1.
  Se v[meio] < v[meio + 1], há um pico à direita: ini = meio + 1. Senão,
  há um à esquerda (o meio incluído): fim = meio.
```


Ponha no começo de cada volta do binário um assert com o invariante:
(ini == 0 ou v[ini - 1] < v[ini]) e (fim == n - 1 ou v[fim] >= v[fim + 1]).
Conte 1 comparação por volta em cada versão. Teste com a trilha
120, 340, 560, 610, 580, 430, 470, 520, 300, 150 e com a rampa 100, 200,
..., 1600 (16 pontos).


```text
Saída esperada:
Trilha: pico na posição 3 (610 m), binária 3, sequencial 4
Rampa: pico na posição 15 (1600 m), binária 4, sequencial 15
```

**Dicas:**

1. Por que existe pico em [ini, fim]: o invariante diz que se "sobe" ao
   entrar no intervalo e "desce" (ou fica igual) ao sair dele. Andando lá
   dentro, em algum ponto a subida tem que parar.
2. Quando ini == fim, o invariante diz que v[ini] não é menor que nenhum
   vizinho: é um pico.
3. As duas podem achar picos DIFERENTES (a trilha tem dois: 610 e 520).
   Aqui, por acaso, acharam o mesmo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1027.c
```

---

**Exercício P1028** · ★★★ · Quantos times de futsal? Recursão contra tabela

Com 12 jogadores, quantos times de 5 dá para montar? É C(12, 5), e a
relação de Pascal diz que C(n, k) = C(n - 1, k - 1) + C(n - 1, k), com
C(n, 0) = C(n, n) = 1. Escreva:


```text
long comb_rec(int n, int k, long *chamadas)
  a recursão direta da fórmula, contando todas as chamadas;
long comb_tabela(int n, int k, long *somas)
  monta o triângulo de Pascal linha por linha numa matriz long
  t[21][21], só até a coluna k, contando as somas.
```


Mostre os dois para C(12, 5) e C(20, 10).


```text
Saída esperada:
C(12, 5) = 792 | recursão: 1583 chamadas | tabela: 45 somas
C(20, 10) = 184756 | recursão: 369511 chamadas | tabela: 145 somas
```

**Dicas:**

1. A árvore de chamadas da recursão tem uma folha (valor 1) para cada
   unidade do resultado, então tem C(n, k) folhas e 2 · C(n, k) - 1 nós:
   o custo cresce como o próprio resultado, que é exponencial.
2. Na tabela, t[i][0] = 1 e t[i][i] = 1; para 0 < j < i e j <= k,
   t[i][j] = t[i-1][j-1] + t[i-1][j]. São O(n · k) somas.
3. A recursão recalcula os mesmos C(a, b) muitas e muitas vezes; a tabela
   calcula cada um uma vez só. É a ideia da programação dinâmica.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1028.c
```

---

**Exercício P1029** · ★★★ · O lado do terreno por busca binária

Um terreno quadrado tem área A m². Qual o maior lado inteiro L com
L · L <= A (a raiz quadrada inteira)? Sem math.h, escreva:


```text
long long raiz_linear(long long a, long *passos)
  testa L = 0, 1, 2, ... enquanto (L + 1)² <= a; 1 passo por teste;
long long raiz_binaria(long long a, long *passos)
  com lo = 0 e hi = a + 1 e o invariante lo² <= a < hi², enquanto
  hi - lo > 1: meio = lo + (hi - lo) / 2; se meio² <= a, lo = meio;
  senão, hi = meio. 1 passo por volta. A resposta é lo.
```


Ponha o invariante num assert no começo de cada volta da binária. Teste
com A = 50, 1000000 e 2000000000.


```text
Saída esperada:
A = 50: lado 7 | linear 8 passos | binária 6 passos
A = 1000000: lado 1000 | linear 1001 passos | binária 20 passos
A = 2000000000: lado 44721 | linear 44722 passos | binária 31 passos
```

**Dicas:**

1. Use long long em tudo: com a = 2 bilhões, hi² passa de 4 · 10¹⁸, que
   ainda cabe (o limite é cerca de 9,2 · 10¹⁸). Para conferir o
   invariante no assert sem estourar, escreva hi > a / hi no lugar de
   hi * hi > a.
2. O invariante no fim (hi - lo == 1) diz lo² <= a < (lo + 1)²: lo é
   exatamente a raiz inteira.
3. A linear é O(√A); a binária é O(log A).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 10-analise/lista/P1029.c
```

---

**Exercício P1030** · ★★★ · Moda e mediana sem ordenar nada

As notas do simulado são inteiras de 0 a 10. Como só existem 11 notas
possíveis, dá para guardar um HISTOGRAMA (quantas vezes cada nota saiu)
em vez da lista de notas. Escreva o TAD Histograma, num arquivo só
("histograma.h", "histograma.c" e cliente):


```text
Histograma *hist_cria(void);
bool hist_adiciona(Histograma *h, int nota);   // false se fora de 0..10
int hist_quantidade(const Histograma *h);
int hist_moda(const Histograma *h, int *vezes); // a menor, no empate
int hist_mediana(const Histograma *h);  // o elemento (n + 1) / 2 na ordem
double hist_media(const Histograma *h);
void hist_libera(Histograma *h);
```


adiciona custa O(1); moda e mediana percorrem as 11 contagens, custo que
NÃO depende de quantas notas existem. Teste com 7, 8, 5, 10, 7, 6, 9, 7,
4, 8, 7; depois acrescente doze notas 10 e mostre de novo moda e mediana.


```text
Saída esperada:
Notas: 11
Moda: 7 (4 vezes)
Mediana: 7
Média: 7.09
Depois de mais doze notas 10: moda 10 (13 vezes), mediana 10
```

**Dicas:**

1. struct histograma { int cont[11]; int n; long soma; };
2. Mediana: ande pelas notas de 0 a 10 somando as contagens; a mediana é
   a primeira nota em que a soma acumulada chega a (n + 1) / 2.
3. Ordenar n notas custaria pelo menos O(n log n) com comparações; aqui o
   truque é que o universo de valores é pequeno e fixo.
4. Resposta esperada: a saída acima (com 23 notas, a 12ª da fila é 10).

```bash
~/LPEDC/rodar 10-analise/lista/P1030.c
```
