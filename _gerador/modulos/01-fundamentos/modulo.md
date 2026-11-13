# Módulo 01 · Fundamentos de C

Um **algoritmo** é uma sequência finita de passos sem ambiguidade; um programa
é um algoritmo escrito em C. Este módulo cobre a **estrutura sequencial**:
variáveis, tipos e limites, constantes, `printf`, `scanf`, aritmética,
conversões e `math.h`, no modelo entrada → processamento → saída. É o ponto de
partida e não depende de nenhum módulo; o 02 e o 03 constroem sobre ele.

## O que você vai aprender

- o esqueleto de um programa em C e o caminho do `.c` ao executável
- os três tipos de erro: compilação, ligação e execução
- **variáveis**: nome, tipo, valor e endereço; `int`, `float`, `double`, `char` e `sizeof`
- bit, byte, binário, hexadecimal, limites dos tipos e **overflow**
- constantes (`#define`, `const`), literais e sequências de escape
- `printf` (largura, precisão, alinhamento) e `scanf` (o `&`, o `%lf`, o buffer)
- aritmética, divisão inteira, resto e precedência
- conversão automática e **cast**
- operadores compostos, `++` e `--`
- `math.h`: `pow`, `sqrt`, `round`, `floor`, `ceil`, `fabs`

## Antes de começar

Você precisa do `gcc` e, para os módulos de memória, do `gdb` e do
`valgrind`. As resoluções ficam em `_respostas/01-fundamentos/`.

**Arch Linux** (e derivados, como Manjaro e EndeavourOS):

```bash
sudo pacman -S --needed base-devel gdb valgrind
```

**Debian / Ubuntu** (e derivados, como Mint e Pop!_OS):

```bash
sudo apt install build-essential gdb valgrind
```

**Windows**: use o **WSL** com Ubuntu (`wsl --install` no PowerShell como
administrador, reinicie e use o comando do Debian/Ubuntu). Clone o curso
dentro do Linux do WSL (`~/LPEDC`).

Confira com `gcc --version`. Para compilar e rodar um arquivo do curso:

```bash
gcc ~/LPEDC/material/A001.c -o ~/LPEDC/material/A001 && ~/LPEDC/material/A001
```

O `-o` dá o nome do executável. Acrescente antes dele as **flags de estudo**,
`-std=c17 -Wall -Wextra -pedantic -g -fsanitize=address,undefined -lm`: padrão
C17, todos os avisos, o **AddressSanitizer** (erros de memória), o detector de
**comportamento indefinido** e a biblioteca matemática. Os avisos citados nos
módulos aparecem com elas, e os exercícios devem compilar **sem nenhum aviso**.

Para testar sem digitar, use um cano (`|`): o que vem antes vira o teclado do
programa.

```bash
gcc ~/LPEDC/material/A011.c -o ~/LPEDC/material/A011 && printf '3 4.99\n2\n' | ~/LPEDC/material/A011
```

> [!NOTE]
> Material antigo de C usa `void main`, `conio.h`, `getch()`,
> `system("pause")`, `fflush(stdin)` e `gets`. Nada disso é C padrão ou
> seguro; quando aparecer, o curso mostra a alternativa.

{{indice}}

---

{{assuntos}}

---

### Desafios do módulo

Problemas com variáveis, `scanf`, aritmética, conversões, `math.h` e
`printf`. Nenhum precisa de `if` nem de laço. Escreva cada um num arquivo seu
e compile com as flags de estudo.

**1. Troco em moedas.** O caixa da padaria só tem moedas de R$ 1, R$ 0,50,
R$ 0,25, R$ 0,10 e R$ 0,05. Leia um troco em reais (`double`) e mostre quantas
moedas de cada valor entregar, sempre da maior para a menor. Teste com 3.85.

<details><summary>Resposta</summary>

3 de R$ 1, 1 de R$ 0,50, 1 de R$ 0,25, 1 de R$ 0,10 e nenhuma de R$ 0,05: **6
moedas**. O caminho: converta para centavos inteiros **arredondando**
(`(int) round(troco * 100)`; sem o round, 19.99 * 100 dá 1998.99999... e o cast cortaria para 1998) e, para cada moeda,
`quantidade = centavos / moeda` e `centavos %= moeda`.

</details>

**2. Que dia da semana?** Numere os dias de 0 (domingo) a 6 (sábado). Hoje é
sábado (6). Escreva um programa que leia daqui a quantos dias e mostre o
número do dia da semana que vai ser. Rode com 100 e com 1000.

<details><summary>Resposta</summary>

```text
Daqui a quantos dias? 100
Dia da semana: 1
```

Com 1000 sai `Dia da semana: 5`: **segunda-feira** e **sexta-feira**.
A conta inteira é `(6 + dias) % 7`. O `%` serve para tudo que "dá a volta",
como dias da semana e horas do relógio.

</details>

**3. A senha embaralhada.** Uma empresa embaralha senhas de 4 dígitos assim:
troca cada dígito por `(dígito + 7) % 10` e depois troca o 1º dígito com o
3º e o 2º com o 4º. Leia uma senha, mostre a embaralhada com `%04d` e escreva
o programa que desfaz. Teste com 2026.

<details><summary>Resposta</summary>

2, 0, 2, 6 viram 9, 7, 9, 3 e, com as trocas, **9397**. Para desfazer, troque
as posições de volta e some 3 em cada dígito, com `% 10` (somar 7 e depois 3
dá 10, que o `% 10` zera). Separe os dígitos com `/` e `%` como no E042.

</details>

**4. Até onde o fatorial cabe?** Qual o maior `n` cujo fatorial cabe num
`int`? E num `long long`? Escreva um programa que mostre os fatoriais
multiplicando um por um e use o gcc com as flags de estudo para descobrir onde estoura.

<details><summary>Resposta</summary>

**12!** = 479.001.600 cabe no `int`; 13! = 6.227.020.800 passa de `INT_MAX`.
No `long long`, **20!** = 2.432.902.008.176.640.000 cabe; 21! não. O detector
de comportamento indefinido do gcc com as flags de estudo acusa `signed integer overflow` na
primeira multiplicação que estoura.

</details>

**5. Quanto preciso tirar?** A média final é ponderada: P1 com peso 3, P2 com
peso 4 e P3 com peso 3. Escreva um programa que leia a P1, a P2 e a média
desejada e mostre, com duas casas, quanto precisa tirar na P3. Teste com
5.0, 6.5 e 6.0.

<details><summary>Resposta</summary>

```text
P1, P2 e média desejada: 5.0 6.5 6.0
Precisa tirar na P3: 6.33
```

Média = (3·P1 + 4·P2 + 3·P3) / 10. Isolando: P3 = (média·10 − 3·P1 − 4·P2) / 3
= (60 − 15 − 26) / 3. Use `double` em tudo: com `int`, a divisão final daria 6.

</details>

**6. O voo noturno.** São Paulo está uma hora à frente de Manaus. Escreva um
programa que leia a hora e o minuto de saída de um voo em Manaus (horário de
Manaus) e a duração em minutos, e mostre a hora do pouso no horário de São
Paulo, no formato `hh:mm`, e quantos dias ela avançou. Teste com um voo que
sai às 22:40 e dura 3h50 (230 minutos).

<details><summary>Resposta</summary>

```text
Saída (hh mm) e duração em minutos: 22 40 230
Pouso em São Paulo: 03:30 (+1 dia)
```

Em minutos: 22·60 + 40 = 1360; mais 230 de voo e 60 de fuso = 1650. Os dias
são `1650 / 1440` = 1; o resto, `1650 % 1440` = 210 minutos, vira `210 / 60`
horas e `210 % 60` minutos, mostrados com `%02d`. É a mesma técnica do E066.

</details>

**7. O preço na bomba.** Um posto arredonda o total para o múltiplo de 5
centavos mais próximo. Escreva a conta com `round` e teste com R$ 6.37, R$
6.38 e R$ 152.12.

<details><summary>Resposta</summary>

`round(valor / 0.05) * 0.05`: 6.37 vira **6.35**, 6.38 vira **6.40** e 152.12
vira **152.10**. A ideia vale para qualquer passo: divida pelo passo,
arredonde e multiplique de volta.

</details>

**8. sizeof de cada um.** Escreva um programa que mostre, uma por linha, o
`sizeof` de `char`, de `'a'`, de `"a"`, de `1.0f` e de `1.0`, e no fim o total
das cinco. Rode num PC de 64 bits.

<details><summary>Resposta</summary>

```text
sizeof(char) = 1
sizeof('a')  = 4
sizeof("a")  = 2
sizeof(1.0f) = 4
sizeof(1.0)  = 8
Total: 19
```

As armadilhas: `'a'` é `int` no C (4 bytes) e `"a"` tem o byte zero do fim (2
bytes). O resultado de `sizeof` é do tipo `size_t`: mostre com `%zu`, e para
o `"` dentro do `printf` use a sequência de escape `\"`.

</details>

**9. O cronômetro.** O cronômetro do celular guarda o tempo em milissegundos.
Leia um valor e mostre no formato `mm:ss.mmm`. Teste com 754321.

<details><summary>Resposta</summary>

`754321 / 60000` = 12 minutos; `754321 % 60000` = 34321; `34321 / 1000` = 34
segundos; `34321 % 1000` = 321. Com `printf("%02d:%02d.%03d\n", ...)` sai
**12:34.321**. Sem o `%03d`, 5 milissegundos sairiam como `.5`, que parece
meio segundo.

</details>

**10. Qual dá a volta com garantia?** Coloque os dois trechos abaixo num
`main`, mostre `placar` e `pontos` com `printf` e rode com as flags de estudo. Depois
conserte o trecho que o gcc com as flags de estudo acusar, mudando só o tipo da variável, para
que ele mostre o valor certo, sem estourar.

```c
unsigned short placar = 65530;
placar += 10;

int pontos = INT_MAX;
pontos += 1;
```

<details><summary>Resposta</summary>

Na primeira rodada, o gcc com as flags de estudo mostra `runtime error: signed integer overflow:
2147483647 + 1 cannot be represented in type 'int'`. Depois do conserto
(`long long pontos`, mostrado com `%lld`):

```text
placar = 4
pontos = 2147483648
```

O `unsigned short` dá a volta com garantia: 65540 − 65536 = 4. O `int` com
sinal estoura, e isso é **comportamento indefinido**: costuma virar
-2147483648, mas o padrão não garante nada.

</details>

### Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2024 | 45 | Tipos de dados básicos de linguagem | A | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2024.pdf) |


### Questões no estilo da prova

Questões objetivas no formato da Prova do PPGI, com uma alternativa certa.
Resolva no papel antes do gabarito e, na dúvida, rode o trecho com as flags
de estudo.

**1.** Qual a saída do trecho abaixo?

```c
int a = 7, b = 2;
double m = a / b;
printf("%.1f\n", m);
```

- (A) 3.5
- (B) 3.0
- (C) 4.0
- (D) 3
- (E) o programa não compila: `int` não pode ir para `double`

<details><summary>Gabarito</summary>

**(B).** `a / b` é uma divisão entre dois `int`: dá 3, e só **depois** o 3
vira `double` na atribuição. O `%.1f` mostra `3.0`. Para sair 3.5, um dos
operandos tem que ser real antes da conta: `(double) a / b`. O (D) seria o
`printf` com `%d`, que nem combina com `double`. Veja 0007 e 0008.

</details>

**2.** Quanto vale a expressão `10 - 4 - 3 * 2 % 4` em C?

- (A) 0
- (B) 9
- (C) 3
- (D) 4
- (E) 6

<details><summary>Gabarito</summary>

**(D).** `*` e `%` têm a mesma precedência e associam da esquerda para a
direita: `3 * 2` é 6 e `6 % 4` é 2. Os dois `-` também vão da esquerda para a
direita: `(10 - 4) - 2` é 4. Quem faz `4 - 3` primeiro chega em 9 ou em
outros valores. Veja 0007.

</details>

**3.** Num compilador que segue o C99 ou mais novo, o que mostra
`printf("%d %d\n", -7 / 2, -7 % 3);`?

- (A) -3 -1
- (B) -4 2
- (C) -3 2
- (D) -4 -1
- (E) -3 1

<details><summary>Gabarito</summary>

**(A).** Desde o C99, a divisão inteira corta **em direção ao zero**: -3,5
vira -3. O resto acompanha o sinal do dividendo e mantém a identidade
`(a / b) * b + a % b == a`: `(-7 / 3) * 3 + (-7 % 3)` é `-6 + (-1)`. O par
(-4, 2) seria o arredondamento para baixo da matemática. Veja 0007.

</details>

**4.** Qual a saída?

```c
int x = 5;
int y = x++ + 2;
int z = ++x * 2;
printf("%d %d %d\n", x, y, z);
```

- (A) 6 7 12
- (B) 7 8 14
- (C) 5 7 12
- (D) 7 8 16
- (E) 7 7 14

<details><summary>Gabarito</summary>

**(E).** O pós-incremento `x++` vale o valor **antigo** (5) e só depois `x`
vira 6: `y = 5 + 2 = 7`. O pré-incremento `++x` aumenta primeiro (7) e vale o
valor novo: `z = 7 * 2 = 14`. No fim, `x` é 7. Veja 0009.

</details>

**5.** Numa máquina em que `unsigned char` tem 8 bits, o que este trecho
mostra?

```c
unsigned char c = 250;
c = c + 10;
printf("%d\n", c);
```

- (A) 260
- (B) 255
- (C) 4
- (D) -6
- (E) o comportamento é indefinido

<details><summary>Gabarito</summary>

**(C).** Um `unsigned char` vai de 0 a 255. Para tipos **sem sinal**, o C
garante a volta (aritmética módulo 256): 260 - 256 = 4. Comportamento
indefinido é o estouro de um tipo **com sinal**, como o `int`. O (B) seria
uma saturação, que o C não faz. Veja 0003.

</details>

**6.** Sobre os tipos primitivos do C, considere as afirmações e marque a alternativa CORRETA.

- **I.** `sizeof(char)` vale 1 por definição do padrão, em qualquer máquina.
- **II.** `int` ocupa sempre 4 bytes, por exigência do padrão.
- **III.** `sizeof` é um operador, e não uma função de `<stdlib.h>`.
- **IV.** `unsigned int` ocupa o dobro de bytes de `int`, porque não guarda o sinal.

- (A) Apenas I
- (B) Apenas I e II
- (C) Apenas II e III
- (D) Apenas III e IV
- (E) Apenas I e III

<details><summary>Gabarito</summary>

**(E).** I é verdadeira: `char` é a unidade de medida do `sizeof`. II é falsa: o padrão só exige mínimos (o `int` tem pelo menos 16 bits). III é verdadeira: `sizeof` é resolvido na compilação e não precisa de `#include`. IV é falsa: `unsigned` muda a faixa de valores, não o tamanho. Veja 0002 e 0003.

</details>

**7.** Considere as afirmações sobre operadores e conversões e marque a alternativa CORRETA.

- **I.** Depois de `int x = 10; x *= 2 + 3;`, `x` vale 50.
- **II.** Desde o C99, `-7 / 2` vale -4, porque a divisão inteira arredonda para baixo.
- **III.** Em `y = x++;`, `y` recebe o valor que `x` tinha antes do incremento.
- **IV.** `(double) 7 / 2` vale 3.5, porque o cast age antes da divisão.

- (A) Apenas I e II
- (B) Apenas II e IV
- (C) Apenas I e III
- (D) Apenas I, III e IV
- (E) Apenas II, III e IV

<details><summary>Gabarito</summary>

**(D).** I é verdadeira: `x *= 2 + 3` é `x = x * (2 + 3)`. II é falsa: o C99 corta em direção ao zero e `-7 / 2` vale -3. III é verdadeira: o pós-incremento entrega o valor antigo. IV é verdadeira: o cast tem precedência maior que o `/`, então a divisão já é real. Veja 0007, 0008 e 0009.

</details>

**8.** Qual das expressões abaixo vale **3.5**?

- (A) `(double) (7 / 2)`
- (B) `7 / 2 * 1.0`
- (C) `(double) 7 / 2`
- (D) `(int) 7.0 / 2`
- (E) `7 / (int) 2.0`

<details><summary>Gabarito</summary>

**(C).** O cast tem precedência maior que a divisão: `(double) 7` vira 7.0
**antes** do `/`, e real dividido por inteiro é divisão real. Em (A) e (B) a
divisão inteira `7 / 2` acontece primeiro e o 3 vira 3.0 tarde demais. Em (D)
e (E) os dois operandos são `int`. Veja 0008.

</details>

**9.** Qual a saída?

```c
char ch = 'A' + 2;
printf("%c %d\n", ch, ch);
```

- (A) C 67
- (B) A2 67
- (C) C 65
- (D) não compila: não se soma número com caractere
- (E) B 66

<details><summary>Gabarito</summary>

**(A).** Um `char` é um número pequeno: `'A'` é 65 na tabela ASCII, e
65 + 2 = 67, que é o código de `'C'`. O `%c` mostra o caractere desse código e
o `%d` mostra o próprio número. Veja 0002 (e 0040, no módulo 05).

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Caps. 1 a 3.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Apêndice C: números inteiros.
- BACKES, A. R. *Linguagem C: descomplicada*. Apostila. Uberlândia: FACOM/UFU, [s.d.].
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Caps. 2, 3, 5 e 9.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Capítulos iniciais: tipos, expressões, entrada e saída.
- HARA, C.; ZOLA, W. *Linguagem C: notas de aula*. Rev. A. L. N. Delgado. Curitiba: UFPR, 2008.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Maringá: Unicesumar, 2016. Unidade I.
- CARVALHO, V. A. *Lógica de programação*. Colatina: IFES / e-Tec Brasil, 2010. Aulas 5 a 7.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- MARTINS, L. G. A. *Apostila de linguagem C: conceitos básicos*. Uberlândia: FACOM/UFU, [s.d.].
- DORNELLES FILHO, A. A. *Fundamentos de linguagem C*. Caxias do Sul: SENAI-RS, 1997.
- LAGO, S. *Linguagem C*. Apostila, [s.d.].
- UNICAMP. Centro de Computação. *Introdução à linguagem C*: versão 2.0. Campinas: UNICAMP, [s.d.].
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Caps. 1 e 2.
- ISO/IEC. *ISO/IEC 9899:2018*: Information technology: Programming languages: C. Genebra: ISO, 2018.
- CPPREFERENCE. *C reference*. Disponível em: <https://en.cppreference.com/w/c>.
- KERRISK, M. (org.). *Linux man-pages*: printf(3), scanf(3), math.h(0p). Disponível em: <https://man7.org/linux/man-pages/>.
- GNU. *Using the GNU Compiler Collection (GCC)*: Overall options e Warning options. Disponível em: <https://gcc.gnu.org/onlinedocs/gcc/>.
