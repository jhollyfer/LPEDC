# Módulo 27 · Detalhes de C que caem em prova

Você já escreve C há 26 módulos. Mesmo assim, uma linha como
`x & 1 == 0`, `i < u` ou `n - 1` com `size_t` pode enganar, porque o
compilador lê a expressão por regras que o olho não aplica sozinho. Uma prova
de múltipla escolha adora esse tipo de linha: o código é curto, compila, e
as alternativas trazem justamente o resultado que a intuição sugere.

Este módulo junta as regras que decidem o valor dessas linhas: quem pega os
operandos primeiro (precedência e associatividade), em que ordem as partes
rodam e quando a resposta é "comportamento indefinido"; o que acontece quando
um número com sinal encontra um sem sinal, e por que `-1 > 0u` é verdadeiro;
e o vetor de tamanho variável (VLA), o único vetor do C cujo `sizeof` é
calculado com o programa rodando.

O truque é ler a expressão como o compilador, e não como
matemática: primeiro os tipos (promoção e conversão), depois a árvore
(precedência), e só então os valores. Aí a pegadinha vira conta.

## O que você vai aprender

- ler qualquer expressão com a **tabela de precedência e associatividade**, incluindo bit a bit, `?:`, vírgula e atribuição composta
- separar **agrupamento** de **ordem de avaliação**, reconhecer **efeito colateral** e o **comportamento indefinido** de `i = i++`
- prever o que acontece quando **com sinal e sem sinal** se misturam: promoção inteira, conversão aritmética usual, `-1 > 0u`
- usar `>>`, máscaras e `size_t` sem cair nas armadilhas do negativo e do laço que desce
- criar e passar **VLAs** (`void f(int l, int c, int m[l][c])`), entender o `sizeof` em tempo de execução, o `__STDC_NO_VLA__` e o risco da pilha
- juntar tudo num controle de acesso com struct, enum, máscaras e VLA

## Antes de começar

Este módulo usa os operadores dos módulos 01 e 02 (aritmética, atribuição,
`++`, lógicos, ternário), os bits e máscaras do 0065, struct e enum do
módulo 08, e `malloc`/`free` do módulo 07. Se `p &= ~MASCARA;` ainda não
parece natural, revise o 0065 antes.

Os valores dos comentários são os de um PC de 64 bits com Linux e gcc: `int`
e `unsigned` de 4 bytes, `long` e `size_t` de 8. Algumas respostas (como
`-17 >> 2`) dependem do compilador, e o texto avisa quando for o caso.

O comando do exemplo compila com `-Wall -Wextra`, e esses avisos pegam vários erros
deste módulo. Os exemplos compilam limpos; quando o texto mostra uma linha
que o gcc avisaria, ela aparece fora do programa ou com a conversão escrita
à vista. Ao rodar, tire um parêntese, troque `unsigned` por `int`, aumente o
VLA e leia o que o gcc diz.

```bash
gcc ~/LPEDC/27-c-detalhes/0170-precedencia-e-avaliacao/A339.c -o ~/LPEDC/27-c-detalhes/0170-precedencia-e-avaliacao/A339 && ~/LPEDC/27-c-detalhes/0170-precedencia-e-avaliacao/A339
```

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver num arquivo seu, misturando os assuntos do módulo. Do
médio ao difícil.

**1. A tabela na prática.** Escreva um programa que mostre o valor de cada
expressão abaixo e, ao lado, a mesma expressão com todos os parênteses do
jeito que o C agrupa: `2 + 3 * 4 % 5`, `1 << (2 + 1)`, `(5 & 3) | 8`,
`10 - 2 - 3`, `!0 + 1`, `-3 % 2`, `(7 > 3) > 1` e `~0u >> 28`.

<details><summary>Resposta</summary>

4, 8, 9, 5, 2, -1, 0 e 15. Os que mais enganam: `%` está no nível do `*`,
então `3 * 4 % 5` é `(3 * 4) % 5` = 2; `7 > 3 > 1` compara o **resultado**
de `7 > 3` (que é 1) com 1, e dá 0; `-3 % 2` é -1, porque o resto tem o sinal
do dividendo; e `~0u >> 28` desloca 32 bits ligados e sobram 4: 15.
Algumas dessas, sem os parênteses, fazem o gcc avisar: deixe os parênteses.

</details>

**2. Ano bissexto numa linha.** Escreva `bool bissexto(int a)` com uma
expressão só e teste com 1900, 2000, 2024 e 2026.

<details><summary>Resposta</summary>

`(a % 4 == 0 && a % 100 != 0) || a % 400 == 0`. Sem os parênteses o valor é
o mesmo, porque `&&` vem antes de `||`, mas o gcc avisa ("suggest parentheses
around '&&' within '||'"), e com razão: quem lê não precisa lembrar da
tabela. Resultado: 1900 não, 2000 sim, 2024 sim, 2026 não.

</details>

**3. Contar bits ligados.** Escreva `int contar_bits(unsigned x)` com o
truque `x &= x - 1` e teste com `0xF0F0`. Por que o parâmetro precisa ser
`unsigned`?

<details><summary>Resposta</summary>

`x - 1` apaga o bit 1 mais baixo e liga os zeros à direita dele; o `&` com
`x` apaga exatamente esse bit. O laço roda uma vez por bit ligado: `0xF0F0`
dá **8**. Com `int`, um `x` negativo faria `x - 1` estourar em `INT_MIN - 1`,
comportamento indefinido; com `unsigned`, a conta dá a volta e está definida.

</details>

**4. Girar bits.** Escreva `unsigned girar(unsigned x, unsigned n)`, que
empurra os bits `n` casas para a esquerda e traz de volta, pela direita, os
que caíram. Teste `girar(0x80000001, 1)` e `girar(x, 0)`.

<details><summary>Resposta</summary>

`(x << n) | (x >> (32 - n))`, mas com cuidado: com `n = 0`, o `x >> 32`
desloca pela largura inteira do tipo, o que é comportamento indefinido (o
UBSan acusa). Faça `n &= 31;` e, se `n == 0`, devolva `x`. `girar(0x80000001,
1)` dá **0x00000003**: o bit 31 voltou como bit 0.

</details>

**5. O valor absoluto que não cabe.** `abs(INT_MIN)` é comportamento
indefinido, porque 2147483648 não cabe num `int`. Escreva `unsigned
modulo(int x)` que funcione para qualquer `int`, inclusive `INT_MIN`.

<details><summary>Resposta</summary>

`x < 0 ? 0u - (unsigned)x : (unsigned)x`. A conversão `(unsigned)x` é sempre
definida (soma 2³² ao negativo), e a subtração sem sinal também. Para
`INT_MIN`, `(unsigned)x` é 2147483648, e `0u - 2147483648u` dá **2147483648**,
o valor certo, agora num tipo que comporta.

</details>

**6. A média que não estoura.** Com `unsigned a = 4000000000u, b =
4000000002u;`, `(a + b) / 2` dá um valor absurdo. Escreva duas versões
corretas da média.

<details><summary>Resposta</summary>

`a + b` passa de `UINT_MAX` e dá a volta. Versão 1: `a + (b - a) / 2`, com
`a <= b` (a diferença nunca estoura). Versão 2, sem exigir ordem:
`(a & b) + ((a ^ b) >> 1)`: os bits comuns contam inteiros, os diferentes
contam pela metade. As duas dão **4000000001**. É o mesmo erro clássico do
`meio = (ini + fim) / 2` da busca binária.

</details>

**7. Espiral numa matriz VLA.** Leia `l` e `c`, crie `int m[l][c]` e preencha
de 1 até `l * c` em espiral, no sentido horário, começando no canto de cima à
esquerda. Mostre o resultado para 3 x 4.

<details><summary>Resposta</summary>

Guarde quatro limites (cima, baixo, esquerda, direita) e ande: a linha de
cima para a direita, a coluna da direita para baixo, a linha de baixo para a
esquerda, a coluna da esquerda para cima, fechando um limite a cada lado.
Pare quando o contador passar de `l * c`. Para 3 x 4: `1 2 3 4` / `10 11 12
5` / `9 8 7 6`. Confira `l` e `c` antes de criar o VLA.

</details>

**8. Triângulo de Pascal.** Leia `n` (até 30), crie `long long t[n][n]` e
mostre a linha 10 do triângulo de Pascal.

<details><summary>Resposta</summary>

`t[i][0] = t[i][i] = 1` e, no meio, `t[i][j] = t[i - 1][j - 1] + t[i -
1][j]`. A linha 10 (contando a primeira como 0) é **1 10 45 120 210 252 210
120 45 10 1**. Com `n = 30`, o VLA tem 30 × 30 × 8 = 7200 bytes, tranquilo
na pilha. Use `long long`: os valores do meio passam de `INT_MAX` perto da
linha 34.

</details>

**9. O byte com dois nomes.** Mostre os 8 bits de `signed char s = -5` e o
valor dos mesmos bits lidos como `unsigned char`. Depois calcule `~5 + 1` e
compare.

<details><summary>Resposta</summary>

Os bits são `11111011`. Como `unsigned char`, valem **251** (= 256 - 5). E
`~5 + 1` dá -5: é o complemento de dois, a regra que o processador usa para
negativos. Para mostrar os bits sem armadilha, converta antes:
`unsigned char u = (unsigned char)s;` e desloque `u`, nunca o negativo.

</details>

**10. Soma com aviso de estouro.** Escreva `bool somar(int a, int b, int
*r)`, que guarda `a + b` em `*r` e devolve `true`, ou devolve `false` sem
somar quando o resultado não caberia num `int`. Teste com `INT_MAX` e 1, e
com -5 e 3.

<details><summary>Resposta</summary>

Não dá para somar e conferir depois: o estouro com sinal já é comportamento
indefinido. Teste antes: se `b > 0 && a > INT_MAX - b`, estoura para cima; se
`b < 0 && a < INT_MIN - b`, para baixo. Nenhuma dessas subtrações estoura.
`somar(INT_MAX, 1, &r)` devolve `false`; `somar(-5, 3, &r)` devolve `true`
com `r = -2`.

</details>

## Questões no estilo da prova

Questões de múltipla escolha, como as da prova do PPGI. Resolva no papel,
marque a letra e só então abra o gabarito. Os trechos de código estão dentro
de um `main` com `#include <stdio.h>`; foram compilados e rodados no gcc (os
que geram aviso, também: o aviso não impede de rodar).

**1.** O que o trecho abaixo mostra?

```c
int a = 5, b = 10;
int r = a + b > 12 ? 1 : 0 + 100;
printf("%d", r);
```

- (A) 1
- (B) 101
- (C) 100
- (D) 16
- (E) 0

<details><summary>Gabarito</summary>

**(A).** O `?:` tem precedência menor que `+` e `>`: a expressão é
`((a + b) > 12) ? 1 : (0 + 100)`. Como 15 > 12, vale 1. O `+ 100` faz parte
só do ramo do "senão". Veja 0170.

</details>

**2.** Qual a saída?

```c
int x = 6;
if (x & 1 == 0) printf("par");
else printf("impar");
```

- (A) par
- (B) impar
- (C) erro de compilação
- (D) comportamento indefinido
- (E) nada é impresso

<details><summary>Gabarito</summary>

**(B).** O `==` vem antes do `&`: a condição é `x & (1 == 0)`, isto é,
`6 & 0`, que é 0. Cai no `else`, mesmo com 6 sendo par. Compila (com um
aviso do gcc). O certo é `(x & 1) == 0`. Veja 0170 e 0065.

</details>

**3.** Qual a saída?

```c
unsigned int u = 1;
int i = -1;
printf("%s", i < u ? "menor" : "maior");
```

- (A) menor
- (B) erro de compilação
- (C) maior
- (D) depende do valor de lixo de `i`
- (E) comportamento indefinido

<details><summary>Gabarito</summary>

**(C).** Pela conversão aritmética usual, o `int` vira `unsigned`: -1 vira
4294967295, que é maior que 1. A conversão é definida pelo padrão; o gcc
avisa com `-Wsign-compare`. Veja 0171.

</details>

**4.** Sobre o laço abaixo, é correto afirmar:

```c
for (unsigned i = 3; i >= 0; i--)
    printf("%u ", i);
```

- (A) mostra `3 2 1 0` e termina.
- (B) mostra `3 2 1` e termina.
- (C) não mostra nada.
- (D) nunca termina: depois do 0, `i` vira 4294967295.
- (E) não compila, porque `i` é `unsigned`.

<details><summary>Gabarito</summary>

**(D).** Um `unsigned` é sempre `>= 0`, então a condição nunca é falsa. Ao
descer de 0, `i` dá a volta para `UINT_MAX`. O certo é
`for (unsigned i = 4; i-- > 0;)`. Veja 0171.

</details>

**5.** Qual a saída?

```c
unsigned char c = 250;
int s = c + 10;
c = c + 10;
printf("%d %d", s, c);
```

- (A) comportamento indefinido
- (B) 4 4
- (C) 260 260
- (D) 4 260
- (E) 260 4

<details><summary>Gabarito</summary>

**(E).** Na soma, `c` sofre promoção inteira e vira `int`: 250 + 10 = 260,
guardado em `s`, um `int`. Ao guardar de volta em `c`, sobra o resto da
divisão por 256: 4. Conversão para sem sinal é sempre definida. Veja 0171.

</details>

**6.** Sobre `switch`, operadores bit a bit, `union` e `enum`, num sistema com
`int` de 32 bits, analise as afirmações.

- I. Com `unsigned char c = 0xF0;`, a expressão `~c` vale -241, porque `c` é
  promovido a `int` antes do `~`.
- II. Num `switch`, um `case` sem `break` no fim deixa a execução seguir para
  o `case` seguinte.
- III. Numa `union` com um `int` e um `char[8]`, o tamanho é a soma dos
  tamanhos dos membros, 12 bytes.
- IV. Num `enum` sem valores explícitos, o primeiro enumerador vale 0 e os
  seguintes crescem de 1 em 1.

Marque a alternativa **CORRETA**.

- (A) I, II e IV, apenas.
- (B) I e III, apenas.
- (C) II e III, apenas.
- (D) II, III e IV, apenas.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**(A).** I: `~0x000000F0` é `0xFFFFFF0F`, que como `int` vale -241. Só ao
guardar de volta num `unsigned char` sobraria o byte `0x0F`. II: é o "cair para o
próximo caso" do `switch` (fall-through). III é falsa: os membros da `union`
**compartilham** o mesmo espaço, e o tamanho é o do maior membro (arredondado
pelo alinhamento): 8 bytes. IV: é a regra do `enum`. Veja 0170, 0171 e 0172.

</details>

**7.** Sobre os vetores de tamanho variável (VLA) no C17, analise as
afirmações.

- I. `int v[n] = {0};`, com `n` variável, é válido sempre que `n > 0`.
- II. O `sizeof` de um VLA é calculado em tempo de execução.
- III. Desde o C11 o suporte a VLA é opcional, e o compilador que não o aceita
  define `__STDC_NO_VLA__`.
- IV. Se faltar memória, a declaração do VLA devolve `NULL`.

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) II e III, apenas.
- (C) I e IV, apenas.
- (D) III e IV, apenas.
- (E) II, III e IV, apenas.

<details><summary>Gabarito</summary>

**(B).** II: como o tamanho só é conhecido na execução, o `sizeof` também é.
III: é o que o padrão diz. I é falsa: VLA não aceita inicializador no C17
(um `memset` ou um laço faz o serviço). IV é falsa: VLA não é ponteiro e não
avisa falha; quem devolve `NULL` é o `malloc`. Veja 0172.

</details>

**8.** Qual protótipo recebe corretamente uma matriz de `l` linhas e `c`
colunas, com `l` e `c` conhecidos só na execução?

- (A) `void f(int m[l][c], int l, int c);`
- (B) `void f(int l, int c, int m[][]);`
- (C) `void f(int l, int c, int m[l][c]);`
- (D) `void f(int m[][], int l, int c);`
- (E) `void f(int l, int c, int m[l][]);`

<details><summary>Gabarito</summary>

**(C).** Num parâmetro VLA, as dimensões precisam ser declaradas **antes** da
matriz, porque o tipo `m[l][c]` usa os dois nomes. Em (A), `l` e `c` ainda
não existem quando `m` é lida. Em (B), (D) e (E), falta o número de colunas,
e o compilador precisa dele para calcular `m[i][j]`. Veja 0172.

</details>

**9.** Qual a saída?

```c
int i = 0, j = 0;
if (i++ || ++j) i += 10;
printf("%d %d", i, j);
```

- (A) 1 1
- (B) 10 1
- (C) 11 0
- (D) 11 1
- (E) 10 0

<details><summary>Gabarito</summary>

**(D).** `i++` vale 0 (o valor antigo) e deixa `i` = 1. Como o lado esquerdo
do `||` deu falso, o direito roda: `++j` deixa `j` = 1 e vale 1. A condição
é verdadeira e `i += 10` dá 11. O `||` garante que o lado esquerdo termina,
`++` incluído, antes do direito. Veja 0170.

</details>

**10.** Qual a saída?

```c
#define QUAD(x) x * x
printf("%d", QUAD(2 + 3));
```

- (A) 25
- (B) erro de compilação
- (C) 13
- (D) 10
- (E) 11

<details><summary>Gabarito</summary>

**(E).** O `#define` só troca texto: `QUAD(2 + 3)` vira `2 + 3 * 2 + 3`, que
pela precedência é 2 + 6 + 3 = 11. Para dar 25, a macro precisa de
parênteses: `#define QUAD(x) ((x) * (x))`. Veja 0170 (E1019) e 0004.

</details>

## Para ler mais

- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 2 a 4: operadores, precedência, associatividade e ordem de avaliação; cap. 10: manipulação de bits; apêndice D: sistemas de numeração e complemento de dois.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Cap. 2: tipos, operadores e expressões (seção 2.7, conversões de tipo; 2.12, precedência e ordem de avaliação).
- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 2 e 3: tipos, modificadores `signed`/`unsigned` e operadores.
- ISO/IEC. *ISO/IEC 9899:2018: Information technology: programming languages: C*. Genebra: ISO, 2018. Seções 6.3.1 (conversões aritméticas), 6.5 (expressões) e 6.7.6.2 (declaradores de vetor, VLA).
- CPPREFERENCE. *C operator precedence*; *Order of evaluation*; *Implicit conversions*; *Array declaration* (VLA). Disponível em: <https://en.cppreference.com/w/c/language>.
- GNU. *Using the GNU Compiler Collection (GCC)*: *Warning options* (`-Wparentheses`, `-Wsign-compare`, `-Wsequence-point`, `-Wtype-limits`). Disponível em: <https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>.
