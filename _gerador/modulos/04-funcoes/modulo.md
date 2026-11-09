# Módulo 04 · Funções e modularização

Até aqui, todo programa foi um `main` só, de cima para baixo. Funciona para
vinte linhas. Com duzentas, o mesmo cálculo aparece copiado em três lugares,
um conserto esquece uma das cópias e ninguém mais acha nada. Este módulo é
sobre **dividir**: dar nome a cada tarefa, escrever uma vez e chamar quantas
vezes precisar.

No C, isso se faz com funções e com módulos (`.h` e `.c`). E dá para ver **o
que acontece por baixo** de cada chamada: a cópia dos argumentos, o quadro que
nasce na pilha, o endereço de volta, a variável que some no `return`. Com essa
imagem na cabeça, a **recursão** vira só mais uma chamada.

No fim, o programa sai de um arquivo só: você monta **módulos** com `.h` e
`.c`, compila cada parte separada e deixa o ligador juntar tudo. É o mesmo
formato das estruturas de dados da segunda metade do curso.

## O que você vai aprender

- definir, chamar e declarar funções, com **protótipo** e `return`
- a **passagem por valor**: por que a função recebe uma cópia, e o `void`
- **escopo** e **tempo de vida**: local, global e `static`
- a **pilha de chamadas**: o quadro de cada chamada e o stack overflow
- **recursão**: caso base, caso recursivo e como confiar na função
- o custo da recursão no Fibonacci e os casos em que ela compensa: Hanói e Euclides
- **módulos** com `.h` e `.c`, include guards e compilação separada
- **macros** e `#ifdef`, e as armadilhas da troca de texto

## Antes de começar

Nos desenhos de pilha e recursão, cada caixa empilhada é o quadro de uma
chamada, e a de cima é a que está rodando.

Você precisa dos módulos 01 a 03: tipos, `printf` e `scanf`, `if`, `switch` e
laços. Vetores ainda **não** aparecem aqui (são o módulo 05), então todos os
exemplos trabalham com números soltos.

Dois assuntos ficam melhores com o depurador `gdb`, que mostra a pilha de
chamadas com o comando `bt`:

```bash
sudo pacman -S gdb          # Arch Linux
sudo apt install gdb        # Debian / Ubuntu
```

Nos assuntos 0034 e 0036, a pasta tem arquivos de apoio (`conversao.h` e
`conversao.c`, `cardapio.h` e `cardapio.c`). O `rodar` compila esses `.c`
junto com o exemplo; o texto mostra também o comando `gcc` para fazer isso à
mão.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver num arquivo seu, misturando os assuntos do módulo. Do
médio ao difícil.

**1. Dígito verificador.** Escreva `int digito_mod11(int numero)` para números
de até 9 dígitos: multiplique os dígitos, do último para o primeiro, por 2, 3,
4, 5..., some tudo, calcule `11 - soma % 11` e, se der 10 ou 11, use 0. Qual é
o dígito de 261533?

<details><summary>Resposta</summary>

Do fim para o começo: 3×2 + 3×3 + 5×4 + 1×5 + 6×6 + 2×7 = 6 + 9 + 20 + 5 + 36 +
14 = 90. 90 % 11 = 2, e 11 - 2 = **9**. Caminho: um `while (numero > 0)` que
pega `numero % 10`, multiplica pelo peso e faz `numero /= 10`, com o peso
subindo a cada volta.

</details>

**2. Potência recursiva com expoente negativo.** Estenda `potencia(base,
expoente)` para `double` e expoente negativo: `2^-3` vale 0,125. Use recursão
nos dois sentidos.

<details><summary>Resposta</summary>

Três casos: expoente 0 devolve 1; expoente positivo devolve `base *
potencia(base, e - 1)`; expoente negativo devolve `1 / potencia(base, -e)`. O
último caso chama o positivo uma vez só, e a recursão continua convergindo
para 0. `potencia(2, -3)` = **0.125**.

</details>

**3. Collatz.** Começando de n, se for par divida por 2, se for ímpar faça
`3n + 1`, até chegar a 1. Escreva `int passos(int n)` recursiva. Quantos passos
para 27? E qual n até 100 tem mais passos?

<details><summary>Resposta</summary>

`passos(1) = 0`; senão `1 + passos(próximo)`. 27 leva **111 passos** (e passa
por 9232 no caminho). Até 100, o campeão é o **97**, com 118 passos. Ninguém
provou que toda sequência chega a 1: a recursão só termina porque, até hoje,
sempre terminou.

</details>

**4. Contador de chamadas por função.** Sem globais, faça três funções,
`int pix(bool so_ler)`, `int boleto(bool so_ler)` e `int cartao(bool so_ler)`,
saberem quantas vezes já foram chamadas: cada uma soma 1 no seu contador e
devolve o valor, mas com `so_ler` verdadeiro só devolve, sem somar. Escreva
`void relatorio(void)` que mostra os três números. No `main`, chame `pix` 3
vezes, `boleto` 1 e `cartao` 2, chame `relatorio`, chame `pix` mais uma vez e
chame `relatorio` de novo.

<details><summary>Resposta</summary>

```text
pix: 3, boleto: 1, cartao: 2
pix: 4, boleto: 1, cartao: 2
```

Um `static int vezes = 0;` em cada função guarda a contagem entre as
chamadas, mas `relatorio` não enxerga o `static` de outra função: por isso o
parâmetro "só consultar", que devolve o contador sem somar. As chamadas de
`relatorio` não mudam nada, e a segunda linha mostra isso. Outra saída seria
um módulo com contadores `static` de arquivo e funções de consulta, como o
`conversoes_feitas` do assunto 0034.

</details>

**5. Ackermann.** `A(0, n) = n + 1`; `A(m, 0) = A(m - 1, 1)`; `A(m, n) = A(m - 1,
A(m, n - 1))`. Calcule `A(2, 3)` e conte as chamadas. Tente `A(3, 6)`.

<details><summary>Resposta</summary>

`A(2, 3)` = **9**, com 44 chamadas. `A(3, 6)` = 509, com mais de 170 mil
chamadas. É uma função que sempre termina, mas cresce mais rápido que qualquer
exponencial; `A(4, 2)` já tem 19.729 dígitos. Use `long long` no contador.

</details>

**6. A pilha de mdc.** Acrescente ao `mdc` recursivo de Euclides um parâmetro
`int nivel`: cada chamada mostra `mdc(a, b)` recuado dois espaços por nível
e, no caso base, devolve quantos quadros de `mdc` estavam empilhados no ponto
mais fundo (`nivel + 1`). Mostre a pilha e os quadros de `mdc(100, 75)` e de
`mdc(89, 55)`.

<details><summary>Resposta</summary>

```text
mdc(100, 75)
  mdc(75, 25)
    mdc(25, 0)
Quadros: 3
```

`mdc(89, 55)` desce em escada por (55, 34), (34, 21), (21, 13), (13, 8),
(8, 5), (5, 3), (3, 2), (2, 1) e (1, 0) e termina com `Quadros: 10`. Números
de Fibonacci consecutivos são o pior caso de Euclides. O recuo é um `for` de
0 a `nivel` mostrando dois espaços antes do `printf`, e a chamada recursiva
passa `nivel + 1`.

</details>

**7. Macro de troca.** Escreva `#define TROCAR(a, b) int t = a; a = b; b =
t;` e use num `if (x > y) TROCAR(x, y);` sem chaves: rode com o `rodar` e veja
o `gcc` recusar. Conserte a macro para que esta função compile e funcione,
sem mexer nela:

```c
void ordena(int x, int y) {
    if (x > y)
        TROCAR(x, y);
    else
        printf("já em ordem: ");
    printf("%d %d\n", x, y);
}
```

Chame `ordena(9, 4)` e `ordena(1, 5)`.

<details><summary>Resposta</summary>

A versão ingênua dá `error: expected expression before 'int'`: só a primeira
instrução da macro fica no `if`, e uma declaração não pode ser o corpo de um
`if` sem chaves. Com a forma segura, `#define TROCAR(a, b) do { int t_ = (a);
(a) = (b); (b) = t_; } while (0)`:

```text
4 9
já em ordem: 1 5
```

Só com chaves (`{ ... }`) o `;` depois de `TROCAR(x, y)` fecharia o `if` e
deixaria o `else` órfão; o `do { } while (0)` engole esse `;`. Aqui a
macro **consegue** trocar e uma função não conseguiria: ela não recebe
cópias, ela é colada no lugar.

</details>

**8. Módulo de temperatura.** Crie `clima.h` e `clima.c` com `void
registrar(double celsius)`, `double media(void)`, `double maxima(void)` e
`int leituras(void)`, guardando tudo em `static` de arquivo. Registre 22.5,
31.0, 18.0 e 27.5. Escreva também o comando `gcc`.

<details><summary>Resposta</summary>

Média **24.75**, máxima **31.0**, 4 leituras. Guarde soma, máximo e contador
(não precisa guardar cada leitura). Na primeira leitura, o máximo recebe o
valor direto. Comando: `gcc -std=c17 -Wall -Wextra main.c clima.c -o clima`.

</details>

**9. Números de Catalan.** C(0) = 1 e C(n) = soma de C(i) × C(n - 1 - i) para i
de 0 a n - 1. Eles contam, por exemplo, de quantos jeitos dá para pôr
parênteses numa conta. Calcule de C(0) a C(10) recursivamente e conte as
chamadas de C(10).

<details><summary>Resposta</summary>

1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, **16796**. C(10) faz 59.049
chamadas (3¹⁰): cada C(n) chama todos os menores, duas vezes cada. É Fibonacci
piorado; com vetores (módulo 05) você guarda os resultados e faz em 55 somas.

</details>

**10. Imprimir com separador de milhar.** Escreva `void milhar(int n)`
recursiva que mostra 1234567 como `1.234.567` e 45 como `45`.

<details><summary>Resposta</summary>

Se `n < 1000`, mostre `n` e pare. Senão, chame `milhar(n / 1000)` e depois
mostre `.%03d` com `n % 1000`. O `%03d` garante os zeros: 1000005 vira
`1.000.005`, não `1.0.5`. É o mesmo padrão do binário recursivo: imprimir na
volta.

</details>

## Questões no estilo da prova

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. Nas de recursão, desenhe a pilha de chamadas: um quadro
por chamada, com os parâmetros e o que cada uma devolve.

**1.** Sobre funções e escopo em C, considere as afirmações e marque a alternativa CORRETA.

- **I.** Alterar um parâmetro `int` dentro da função não altera a variável original do chamador.
- **II.** Toda função recursiva precisa de um caso base alcançável para terminar.
- **III.** Uma variável local `static` perde o valor ao fim de cada chamada.
- **IV.** Uma variável local com o mesmo nome de uma global esconde a global dentro do bloco.

- (A) Apenas I e II
- (B) Apenas II e IV
- (C) Apenas I e IV
- (D) Apenas I, II e IV
- (E) Todas, de I a IV

<details><summary>Gabarito</summary>

**(D).** I é verdadeira: a passagem é por valor e o parâmetro é uma cópia. II é verdadeira: sem caso base, a recursão empilha quadros até estourar a pilha. III é falsa: a `static` local guarda o valor entre as chamadas. IV é verdadeira: é o sombreamento. Veja 0029, 0030 e 0032.

</details>

**2.** Qual a saída?

```c
int conta(void) {
    static int c = 0;
    c++;
    return c;
}

int main(void) {
    conta();
    conta();
    printf("%d\n", conta() + conta());
    return 0;
}
```

- (A) 2
- (B) 3
- (C) 4
- (D) 5
- (E) 7

<details><summary>Gabarito</summary>

**(E).** A variável `static` local é inicializada **uma vez só** e guarda o
valor entre as chamadas. As duas primeiras deixam `c` em 2; as duas do
`printf` devolvem 3 e 4. Sem o `static`, toda chamada devolveria 1 e a saída
seria 2. Veja 0030.

</details>

**3.** Qual a saída?

```c
int x = 1;

void f(void) {
    x = x + 10;
}

int main(void) {
    int x = 5;
    {
        int x = 7;
        x++;
    }
    f();
    printf("%d\n", x);
    return 0;
}
```

- (A) 5
- (B) 8
- (C) 11
- (D) 15
- (E) 16

<details><summary>Gabarito</summary>

**(A).** Há três variáveis `x`. O `x` do bloco interno (7, depois 8) morre na
`}`. O `f` mexe no `x` **global**, que vira 11. O `printf` do `main` enxerga o
`x` local do `main`, que **esconde** o global e continua 5. Veja 0030.

</details>

**4.** Quanto vale `g(7)`?

```c
int g(int n) {
    if (n <= 1)
        return 1;
    return n + g(n - 2);
}
```

- (A) 28
- (B) 15
- (C) 16
- (D) 13
- (E) a recursão nunca termina

<details><summary>Gabarito</summary>

**(C).** `g(7) = 7 + g(5) = 7 + 5 + g(3) = 7 + 5 + 3 + g(1)`, e `g(1)` é o
caso base, 1. Total: 16. O 15 esquece o 1 do caso base; o 28 seria a soma de
1 a 7. Como `n` desce de 2 em 2, o `n <= 1` (e não `n == 0`) é o que garante
a parada também para `n` par. Veja 0032.

</details>

**5.** O que `p(3)` mostra?

```c
void p(int n) {
    if (n == 0)
        return;
    printf("%d", n);
    p(n - 1);
    printf("%d", n);
}
```

- (A) 321
- (B) 123321
- (C) 321321
- (D) 321123
- (E) 3210123

<details><summary>Gabarito</summary>

**(D).** O primeiro `printf` roda na **ida**, antes da chamada: 3, 2, 1. O
segundo roda na **volta**, quando cada quadro retoma depois que a chamada de
baixo terminou, do mais fundo para o mais raso: 1, 2, 3. O `p(0)` não mostra
nada. Veja 0031 e 0032.

</details>

**6.** Com a função abaixo, quantas chamadas a `fib` acontecem ao todo para
calcular `fib(5)`, contando a primeira?

```c
int fib(int n) {
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

- (A) 5
- (B) 15
- (C) 8
- (D) 9
- (E) 32

<details><summary>Gabarito</summary>

**(B).** Chamando `C(n)` o número de chamadas: `C(0) = C(1) = 1` e
`C(n) = 1 + C(n - 1) + C(n - 2)`. Fica `C(2) = 3`, `C(3) = 5`, `C(4) = 9` e
`C(5) = 15`. O 5 é o **valor** de `fib(5)`, não o número de chamadas. Esse
crescimento exponencial é o que a memoização resolve (assunto 0138). Veja
0033.

</details>

**7.** Qual a saída?

```c
#define AREA(l) l * l

int main(void) {
    printf("%d\n", 100 / AREA(5));
    return 0;
}
```

- (A) 100
- (B) 4
- (C) 20
- (D) 25
- (E) não compila

<details><summary>Gabarito</summary>

**(A).** O pré-processador só troca texto: a linha vira `100 / 5 * 5`. Com
`/` e `*` empatados, vale a esquerda primeiro: `(100 / 5) * 5`, que é 100. A
macro certa leva parênteses em volta de tudo e de cada parâmetro:
`#define AREA(l) ((l) * (l))`, e aí sairia 4. Veja 0035.

</details>

**8.** Sobre sub-rotinas em C, considere as afirmações e marque a alternativa CORRETA.

- **I.** Uma função com retorno `void` faz o papel de procedimento: executa uma tarefa e não devolve valor.
- **II.** O C tem passagem por referência nativa: basta declarar o parâmetro com `&`.
- **III.** Uma função recursiva é sempre mais rápida que a versão com laço.
- **IV.** Uma variável global declarada com `static` fica invisível para os outros arquivos `.c`.

- (A) Apenas II e III
- (B) Apenas I e II
- (C) Apenas III e IV
- (D) Apenas I e III
- (E) Apenas I e IV

<details><summary>Gabarito</summary>

**(E).** I é verdadeira. II é falsa: o C só passa por valor, e a "referência" se faz com ponteiro. III é falsa: cada chamada custa um quadro na pilha. IV é verdadeira: `static` numa global esconde o nome dos outros arquivos. Veja 0028, 0029 e 0034.

</details>

**9.** Qual o valor devolvido por `mdc(84, 36)` e quantas chamadas a `mdc`
acontecem ao todo?

```c
int mdc(int a, int b) {
    return b == 0 ? a : mdc(b, a % b);
}
```

- (A) 6, com 3 chamadas
- (B) 12, com 2 chamadas
- (C) 12, com 3 chamadas
- (D) 4, com 4 chamadas
- (E) 12, com 4 chamadas

<details><summary>Gabarito</summary>

**(C).** As chamadas são `mdc(84, 36)`, `mdc(36, 12)` (porque 84 % 36 = 12)
e `mdc(12, 0)` (porque 36 % 12 = 0), que é o caso base e devolve 12. É o
algoritmo de Euclides. Veja 0033.

</details>

## Para ler mais

- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 5: funções, classes de armazenamento, escopo e recursão; cap. 13: o pré-processador.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Capítulos de funções, pilha de execução, recursão e pré-processador.
- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 2 e 4: algoritmos recursivos e divisão e conquista.
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 2: paradigmas de projeto de algoritmos, recursividade.
- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 9: funções e recursão; cap. 13: classes de armazenamento e pré-processador.
- BACKES, A. R. *Linguagem C: descomplicada*. Uberlândia: UFU, [s.d.]. Apostila. Funções, recursão e diretivas.
- MARTINS, L. G. A. *Apostila de linguagem C: conceitos básicos*. Uberlândia: Faculdade de Computação, UFU, [s.d.].
- HARA, C.; ZOLA, W. *Linguagem C: notas de aula*. Curitiba: UFPR, 2008.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, [s.d.]. Programação modular e recursividade.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 5: recursão e algoritmos recursivos.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 3: recursividade.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Recursividade.
- LAGO, S. *Linguagem C*. Apostila. [S.l.: s.n., s.d.]. Macros e funções.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Cap. 4: funções e estrutura de programas.
- CPPREFERENCE. *C language: functions, storage duration and the preprocessor*. Disponível em: <https://en.cppreference.com/w/c/language>.
- GNU. *The C Preprocessor*. Disponível em: <https://gcc.gnu.org/onlinedocs/cpp/>.
- GDB. *Debugging with GDB*: Backtraces. Disponível em: <https://sourceware.org/gdb/current/onlinedocs/gdb/Backtrace.html>.
