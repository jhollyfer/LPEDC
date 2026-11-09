# Módulo 02 · Decisões

Até aqui, todo programa do curso descia de cima para baixo, linha por linha,
sempre pelo mesmo caminho. Agora ele passa a **escolher**: cobrar ou não o
frete, liberar ou barrar a catraca, achar a faixa certa da multa. Essa é a
segunda das três peças de qualquer algoritmo (sequência, decisão e
repetição).

A sintaxe é curta: `if`, `else`, `switch` e o ternário. O que importa é o que
está por baixo. No C não existe
um tipo "verdadeiro ou falso" de nascença: a verdade é um **número**, 0 é
falso e qualquer outra coisa é verdade. Daí vêm pegadinhas,
como um `=` no lugar de `==` que compila, roda e estraga a variável em
silêncio.

Por isso o módulo tem dois focos: escrever decisões claras e **desconfiar**
de decisões que parecem certas. Os avisos do compilador viram aliados: o
`rodar` liga todos, e quase toda pegadinha deste módulo dispara um.

## O que você vai aprender

- os **operadores relacionais** e a verdade em C: comparação vale 0 ou 1, e `bool` de `<stdbool.h>`
- os **operadores lógicos** `&&`, `||` e `!`, a tabela-verdade, o **curto-circuito** e as leis de De Morgan
- o **`if`**, as chaves e a armadilha do `;` depois da condição
- o **`if/else`** e a pegadinha mais famosa do C: `=` no lugar de `==`
- **`else if`**, `if` aninhado e o **else pendurado**
- o **operador ternário**, a decisão que devolve um valor
- o **`switch`**, o `break` e o **fall-through** (o acidental e o de propósito)
- juntar tudo num programa que lê dados, valida a entrada e decide

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz. Em
   decisões, o caminho verde mostra por onde o exemplo passou.
4. Rode os exemplos. Mude um valor para cair no outro ramo, quebre de
   propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

> [!TIP]
> Para testar uma decisão de verdade, rode o programa **uma vez para cada
> caminho** e, principalmente, nos **valores de fronteira**: se a regra é
> "a partir de R$ 200", teste 199,99, 200 e 200,01. A maioria dos erros de
> decisão mora na troca de um `>` por um `>=`.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa estar à vontade com o módulo 01: variáveis, `printf`, `scanf`
(e o valor que ele devolve), os operadores aritméticos, em especial o `%`, e
o `math.h`. Os exercícios que leem do teclado aceitam a entrada por um pipe,
o que facilita testar vários casos seguidos:

```bash
printf '12.90 8.50\n' | ~/LPEDC/rodar 02-condicionais/0014-if/A028.c
```

Alguns exercícios do tipo "ache o erro" trazem o código quebrado **de
propósito** e por isso mostram avisos ao compilar. O enunciado sempre diz
quando é o caso. Fora deles, a regra do curso vale: código bom compila com
**zero avisos**.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras para fechar o módulo. Escreva cada um num arquivo seu, rode
com o `rodar` e teste todos os caminhos. Nada de laços ainda: só decisões.

**1. Maior e menor de quatro.** Leia quatro números inteiros e mostre o maior
e o menor, usando só `if` (sem `else`). Conte as comparações com uma variável
`comparacoes`, somando 1 antes de cada `if`, e mostre o total. Depois
acrescente ao mesmo programa uma segunda versão que ache o maior e o menor
com só 4 comparações e mostre a contagem dela também. Teste com 7 2 9 4.

<details><summary>Resposta</summary>

```text
Quatro números: 7 2 9 4
Direto: maior 9, menor 2, 6 comparações
Em pares: maior 9, menor 2, 4 comparações
```

O jeito direto (`maior = a`, depois um `if` para cada outro número, e o mesmo
para o menor) faz 6 comparações. A versão de 4 compara em pares (a com b, c
com d): o maior de cada par disputa o maior e o menor de cada par disputa o
menor. Zere `comparacoes` antes da segunda versão.

</details>

**2. Três números em ordem.** Leia três inteiros e mostre em ordem
crescente. Use trocas com uma variável auxiliar, como no A028.

<details><summary>Resposta</summary>

Com 8, 3, 5 → **3 5 8**. Bastam três `if` com troca, nesta ordem: se `a > b`,
troca a e b; se `b > c`, troca b e c; se `a > b` de novo, troca a e b. Depois
disso `a <= b <= c`. Teste também com números repetidos (5, 5, 1).

</details>

**3. Bhaskara completo.** Estenda o E090: se `a` for 0, avise que não é
equação do 2º grau (e resolva a do 1º grau, se `b` não for 0); se delta for
zero, mostre uma raiz só; se for positivo, as duas; se for negativo, "Sem
raízes reais".

<details><summary>Resposta</summary>

0 2 -8 → "não é do 2º grau", x = **4.00**; 1 -6 9 → raiz única **3.00**;
1 -3 -4 → **4.00** e **-1.00**; 1 0 1 → sem raízes reais. Cuidado com o
`delta == 0` em `double`: com coeficientes inteiros ele funciona, mas com
valores quebrados prefira `fabs(delta) < 1e-9`.

</details>

**4. Conceito por switch.** Leia uma nota inteira de 0 a 100 e mostre o
conceito: 90 a 100 é A, 80 a 89 é B, 70 a 79 é C, 60 a 69 é D e abaixo de 60
é F. A regra: use `switch`, sem nenhum `if` (fora a validação da faixa).

<details><summary>Resposta</summary>

O truque é `switch (nota / 10)`: a divisão inteira transforma 87 em 8. Os
casos ficam `case 10: case 9:` → A (fall-through empilhado: 100 / 10 é 10),
`case 8:` → B, `case 7:` → C, `case 6:` → D e `default:` → F. 100 → A,
87 → B, 60 → D, 59 → F.

</details>

**5. Bom dia, boa tarde, boa noite.** Leia a hora (0 a 23) e cumprimente: de
5h a 11h59 "Bom dia", de 12h a 17h59 "Boa tarde", senão "Boa noite". No mesmo
programa, faça duas versões, uma com `else if` e outra com ternários
encadeados dentro de um `printf("%s")`, e mostre as duas respostas, uma por
linha, para conferir que batem. Rode com 4, 5, 12 e 18.

<details><summary>Resposta</summary>

```text
Hora: 12
else if:  Boa tarde
ternário: Boa tarde
```

4 → Boa noite; 5 → Bom dia; 18 → Boa noite, nas duas linhas. Repare que "Boa
noite" cobre duas faixas separadas (0 a 4 e 18 a 23): com `else if`
começando por `hora >= 5 && hora < 12`, ela cai naturalmente no `else`. O
ternário encadeado fica `cond1 ? "Bom dia" : cond2 ? "Boa tarde" : "Boa
noite"`: compacto, mas só vale quando cabe numa linha curta.

</details>

**6. Quem chegou primeiro?** Leia dois horários no formato `hh:mm` (com
`scanf("%d:%d", ...)`) e diga qual é mais cedo e quantos minutos separam um
do outro. Valide as horas (0 a 23) e os minutos (0 a 59).

<details><summary>Resposta</summary>

Converta tudo para minutos desde a meia-noite: `h * 60 + m`. 08:45 e 10:20 →
525 e 620: o primeiro é mais cedo, **95 minutos** de diferença. Comparar
horas e minutos separados também funciona, mas exige `if` aninhado
(`h1 < h2 || (h1 == h2 && m1 < m2)`). Converter para uma unidade só é um truque
que você vai usar muito.

</details>

**7. De Morgan na prática.** Simplifique, sem mudar o resultado, a condição
`!(nota < 5 || faltas > 15) && !(trancou != 0)`. Depois escreva um programa
que imprima as duas versões para alguns valores e prove que batem.

<details><summary>Resposta</summary>

`!(nota < 5 || faltas > 15)` vira `nota >= 5 && faltas <= 15`, e
`!(trancou != 0)` vira `trancou == 0`. Resultado:
`nota >= 5 && faltas <= 15 && trancou == 0`. Em português: aprovado é quem
tem nota, frequência e não trancou.

</details>

**8. O else que trocou de dono.** Sem mudar nenhuma linha, só acrescentando
chaves, faça este trecho mostrar exatamente o que se pede em cada caso:

```c
if (x > 0)
if (y > 0)
printf("A ");
else
printf("B ");
printf("C\n");
```

(a) com x = 1 e y = -1, mostrar só "C"; (b) com x = -1 e y = 1, mostrar
"B C"; (c) com x = 1 e y = 1, mostrar "A C".

<details><summary>Resposta</summary>

Sem chaves, o `else` é do `if (y > 0)`: (b) mostraria só "C". Colocando
chaves em volta do `if (y > 0) printf("A ");`, o `else` passa para o
`if (x > 0)`: (a) "C", (b) "B C", (c) "A C". As três condições pedem a mesma
versão.

</details>

**9. Jogo de dados.** Dois dados foram lançados (leia os dois valores, de 1 a
6). Na primeira jogada do craps: soma 7 ou 11 vence; soma 2, 3 ou 12 perde;
qualquer outra soma vira o "ponto". Mostre o resultado com um `switch` na
soma.

<details><summary>Resposta</summary>

`case 7: case 11:` → vence; `case 2: case 3: case 12:` → perde;
`default:` → "Ponto: %d". 3 e 4 → soma 7, vence; 1 e 1 → 2, perde; 4 e 6 →
10, ponto 10. Valide antes os dados (1 a 6) com uma guarda: valor 0 ou 7 não
existe num dado.

</details>

**10. Signo pela data.** Leia dia e mês de nascimento e mostre o signo. Cada
signo começa num dia de um mês e termina no mês seguinte (Áries: 21/03 a
19/04; Touro: 20/04 a 20/05; e assim por diante).

<details><summary>Resposta</summary>

Um `switch (mes)` com um `if` dentro de cada `case`: em abril, por exemplo,
`dia <= 19` é Áries, senão Touro. 25/04 → **Touro**; 10/04 → **Áries**. São
12 `case`, cada um com um ternário ou `if/else`. Valide a data antes (o E111
já faz isso).

</details>

## Questões no estilo da prova

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. Resolva no papel antes de abrir o gabarito. Vários trechos
fazem o `-Wall` reclamar de propósito: é exatamente a pegadinha.

**1.** Qual a saída?

```c
int x = 0, y = 0, z;
z = x++ && y++;
printf("%d %d %d\n", x, y, z);
```

- (A) 1 1 0
- (B) 0 0 0
- (C) 1 0 0
- (D) 1 1 1
- (E) 0 1 0

<details><summary>Gabarito</summary>

**(C).** `x++` vale o valor antigo de `x`, 0 (falso), e `x` vira 1. Como o
lado esquerdo do `&&` deu falso, o **curto-circuito** pula o lado direito: o
`y++` nunca roda. O resultado do `&&` é 0. Veja 0013 (e 0009 para o `x++`).

</details>

**2.** Qual o valor de `t` no fim?

```c
int op = 2, t = 0;
switch (op) {
case 1: t += 1;
case 2: t += 2;
case 3: t += 3; break;
default: t += 10;
}
```

- (A) 2
- (B) 15
- (C) 3
- (D) 6
- (E) 5

<details><summary>Gabarito</summary>

**(E).** O `switch` pula direto para o `case 2` (o `case 1` não roda) e, sem
`break`, **cai** no `case 3`: 2 + 3 = 5. O `break` do `case 3` sai antes do
`default`. Veja 0018.

</details>

**3.** O que o trecho mostra?

```c
int a = 5, b = 3;
if (a > 10)
    if (b > 2) printf("X");
else printf("Y");
printf("Z\n");
```

- (A) YZ
- (B) Z
- (C) XZ
- (D) XYZ
- (E) Y

<details><summary>Gabarito</summary>

**(B).** É o **else pendurado**: o `else` pertence ao `if` mais próximo que
ainda não tem `else`, o `if (b > 2)`, não importa o recuo. Como `a > 10` é
falso, o `if` de fora pula tudo, inclusive o `else`. Só o `Z` aparece. O gcc
avisa: `suggest explicit braces to avoid ambiguous 'else'`. Veja 0016.

</details>

**4.** Qual a saída?

```c
int n = 0;
if (n = 5) printf("sim"); else printf("nao");
printf(" %d\n", n);
```

- (A) sim 5
- (B) nao 0
- (C) sim 0
- (D) nao 5
- (E) não compila: `=` não pode aparecer dentro do `if`

<details><summary>Gabarito</summary>

**(A).** `n = 5` é uma **atribuição**, não uma comparação: guarda 5 em `n` e
vale 5, que é diferente de zero, logo verdadeiro. Compila (com aviso
`suggest parentheses around assignment used as truth value`). Veja 0015.

</details>

**5.** Com `int k = 15;`, quanto vale `10 < k < 12`?

- (A) 0, porque 15 não está entre 10 e 12
- (B) 15
- (C) não compila
- (D) 1
- (E) o valor é indefinido

<details><summary>Gabarito</summary>

**(D).** O C lê da esquerda para a direita: `10 < k` vale 1 (verdade), e
depois `1 < 12` também vale 1. O intervalo se escreve com um E:
`k > 10 && k < 12`, que daria 0. Veja 0012 e 0013.

</details>

**6.** Qual o valor de `r`?

```c
int q = 3;
int r = q > 2 ? 10 : 20 + 5;
```

- (A) 15
- (B) 10
- (C) 25
- (D) 35
- (E) 30

<details><summary>Gabarito</summary>

**(B).** O `?:` tem precedência **menor** que o `+`, então o lado falso é
`20 + 5` inteiro e a expressão é `(q > 2) ? 10 : (20 + 5)`. Como `q > 2`,
sai 10. O 15 viria de ler `(q > 2 ? 10 : 20) + 5`. Veja 0017.

</details>

**7.** Qual expressão é equivalente a `!(a > 0 && b <= 5)` para quaisquer
inteiros `a` e `b`?

- (A) `a < 0 && b > 5`
- (B) `a <= 0 && b > 5`
- (C) `a <= 0 || b > 5`
- (D) `a < 0 || b >= 5`
- (E) `!(a > 0) || b <= 5`

<details><summary>Gabarito</summary>

**(C).** Pela lei de De Morgan, o NÃO entra nos parênteses, nega cada
comparação e troca `&&` por `||`: `!(a > 0)` é `a <= 0` e `!(b <= 5)` é
`b > 5`. O (A) erra o contrário de `>` (é `<=`, não `<`); o (B) esquece de
trocar o E pelo OU. Veja 0013.

</details>

**8.** Qual a saída?

```c
int p = 2, s = 4;
printf("%d %d\n", p & s, p && s);
```

- (A) 1 1
- (B) 6 1
- (C) 2 4
- (D) 0 0
- (E) 0 1

<details><summary>Gabarito</summary>

**(E).** `&` é o E **bit a bit**: `010 & 100` não tem nenhum bit ligado em
comum, dá 0. `&&` é o E **lógico**: 2 e 4 são diferentes de zero, os dois
são verdade, dá 1. O 6 seria o `|` bit a bit. Veja 0013 (o aviso) e 0065.

</details>

**9.** O que o trecho mostra?

```c
char c = 'b';
switch (c) {
default: printf("D");
case 'a': printf("A"); break;
case 'c': printf("C");
}
```

- (A) D
- (B) nada, porque o `default` tem que ser o último
- (C) DAC
- (D) DA
- (E) não compila: `char` não pode ir num `switch`

<details><summary>Gabarito</summary>

**(D).** Nenhum `case` vale `'b'`, então o `switch` pula para o `default`,
**onde quer que ele esteja**. Sem `break`, cai no `case 'a'`, mostra `A` e o
`break` sai. `char` é número, então vale no `switch`. Veja 0018.

</details>

**10.** O que o trecho mostra numa máquina comum (IEEE 754)?

```c
float f = 0.1f;
if (f == 0.1) printf("igual\n"); else printf("diferente\n");
```

- (A) diferente
- (B) igual
- (C) depende de o `if` ter chaves
- (D) não compila: `float` não se compara com `double`
- (E) igual, porque o `float` vira `double` antes da comparação

<details><summary>Gabarito</summary>

**(A).** O 0.1 não tem representação exata em binário. O `0.1f` guarda a
aproximação de 24 bits; o `0.1` (sem `f`) é um `double`, com 53 bits. O
`float` é convertido para `double` sim, mas a aproximação dele continua
diferente da do `double`. Compare reais com uma tolerância:
`fabs(f - 0.1) < 1e-6`. Veja 0012.

</details>

## Para ler mais

- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 3 (seleção com `if` e `if...else`) e cap. 4 (`switch` e operadores lógicos).
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Capítulo de controle de fluxo: `if`, `switch` e operadores lógicos.
- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 3 (operadores) e cap. 4 (comandos de controle condicional).
- BACKES, A. R. *Linguagem C: descomplicada*. Uberlândia: FACOM/UFU, [s.d.]. Apostila. Capítulos de operadores e de condicionais.
- HARA, C.; ZOLA, W. *Linguagem C: notas de aula*. Curitiba: UFPR, 2008.
- CARVALHO, V. A. *Lógica de programação*. Colatina: IFES / e-Tec Brasil, 2010.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Maringá: Unicesumar, 2016.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- LAGO, S. *Linguagem C*. Apostila. São Paulo, [s.d.].
- MARTINS, L. G. A. *Apostila de linguagem C: conceitos básicos*. Uberlândia: FACOM/UFU, [s.d.].
- DORNELLES F., A. A. *Fundamentos de linguagem C*. Caxias do Sul: SENAI-RS, 1997.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seções 2.6 (relacionais e lógicos), 2.11 (expressões condicionais) e 3.1 a 3.4 (`if-else`, `else-if`, `switch`).
- CPPREFERENCE. *if statement*; *switch statement*; *Operator precedence*. Disponível em: <https://en.cppreference.com/w/c/language>.
- GNU. *Using the GNU Compiler Collection (GCC)*: Warning Options (`-Wparentheses`, `-Wempty-body`, `-Wimplicit-fallthrough`, `-Wdangling-else`). Disponível em: <https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>.
