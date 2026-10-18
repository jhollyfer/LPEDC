# Fichamento — "Manual de Sintaxe da Linguagem C" (Apêndice D)

- **Título:** Apêndice D — Manual de Sintaxe da Linguagem C (28 p.), de um livro de *Fundamentos de programação —
  Algoritmos, estruturas de dados e objetos* (tradução de obra espanhola; exemplos citam Jaén, Cazorla, "Serra Magna").
- **Autor:** não identificado no trecho (o cabeçalho é do livro; estilo e exemplos sugerem L. Joyanes Aguilar).
- **Arquivo lido:** `bc908519-manual-de-sintaxe-da-linguagem-c.md` (1222 linhas, lido por completo).
- **Avaliação geral:** referência rápida, sem didática: lista palavras reservadas, tipos e faixas, escapes,
  operadores (inclusive bit a bit e compostos `<<=`, `&=`...), tabela de precedência completa com 15 níveis,
  sintaxe de cada comando, protótipos, arrays, strings, struct, union, campos de bits, ponteiros e **o melhor resumo
  de pré-processador das cinco fontes** (`#if/#elif/#else/#endif`, `#ifdef`, `#ifndef` com include guard, `#undef`,
  `#line`, `#pragma`, `#error`, `__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`, `__STDC__`). Útil como "cola" para
  montar tabelas do curso. **A tradução e a diagramação introduziram muitos erros** (listados abaixo) — vários
  servem de "ache o erro".

---

### 0005-compilacao / 0006-primeiro-programa
- Organização típica de um arquivo-fonte: comentários (propósito, autor, data) → diretivas → declarações visíveis no
  arquivo → definições de funções. `static` em global/função limita ao módulo; `extern` indica definição em outro
  arquivo (bom para 0039).
- Primeiro programa ANSI com `int main()` e `return 0;`.
- Palavras reservadas do C89 (32): auto, break, case, char, const, continue, default, do, double, else, enum, extern,
  float, for, goto, if, int, long, register, return, short, signed, sizeof, static, struct, switch, typedef, union,
  unsigned, void, volatile, while. (Bom para tabela; acrescentar as do C99/C11: `inline`, `restrict`, `_Bool`...)
- Comentários não aninham: `/* a /* b */ c */` é ilegal.

### 0007-variaveis / 0008-tipos-e-limites
- **Conceito útil:** *declaração* informa o tipo; se reserva armazenamento é *definição*. Maiúsculas importam
  (`Temperatura`, `TEMPERATURA`, `temperatura` são três variáveis). `int v1, v2, v3, v4;` numa linha.
- Tabelas de inteiros (signed/unsigned char, short, int, long com bytes, bits, mín. e máx.) e de reais (float,
  double, long double). Com `int` de 2 bytes (antigo) — usar `sizeof`/`limits.h` no curso.
- **Pegadinhas na fonte (ache o erro):** `float total = 42,125;` (vírgula decimal → erro de sintaxe; o certo é
  `42.125`); `int x = 0, não = 0;` (identificador com acento); `inte v4;`.
- `char` e `int` são intercambiáveis para guardar caracteres (o literal `'M'` é um int com o código 77).

### 0009-constantes
- Literal sem ponto é inteiro; com ponto é `double`; `025` é octal (= 21), `0x25` hexa (= 37), `250L` long.
  **Exercício:** quanto vale `025 + 0x25`? (21 + 37 = 58).
- Tabela de escapes com códigos ASCII (`\a` 7, `\b` 8, `\f` 12, `\n` 10, `\r` 13, `\t` 9, `\v` 11, `\\` 92, `\?` 63,
  `\'` 39, `\"` 34, `\nnn` octal, `\xnn` hexa, `'\0'`). **Erro na fonte:** lista "\h" como nova linha (é `\n`).
- `const int z = 4350; z = 3475;` → erro de compilação ("cannot modify a const object"); `const` não serve onde C
  exige expressão constante (ex.: tamanho de array global em C89 — diferença para `#define`).
- Strings literais adjacentes são concatenadas: `"um" "caractere" "cadeia"` ≡ `"umcaracterecadeia"` (útil para
  quebrar strings longas no `printf`).

### 0010-printf / 0011-scanf
- Cadeia de controle = texto + especificadores + escapes; nº de especificadores = nº de argumentos. Tabelas de
  códigos (`%d %c %s %f %e %g %lf %u %o %x`; no scanf também `%ld`, `%h`).
- **Exemplo:** `printf("/%s/", "Serra Magna")` e `printf("/%-20s/", ...)` — mostrar largura e alinhamento à esquerda
  (a saída impressa na fonte está errada: com `%-20s` os espaços ficam à DIREITA: `/Serra Magna         /`).
- **Pegadinha na fonte:** `scanf("%d*c%d", &x, &y)` — o supressor é `%*c` (lê e descarta um caractere, ex.: a
  barra em "12/5"); como está escrito, o scanf espera um `*` literal.
- `scanf("%s %s", cidade, provincia)` sem `&` (arrays).

### 0012-aritmetica / 0013-conversao / 0014-atribuicao
- Tabela de compostos completa: `*= /= %= += -= <<= >>= &= ^= |=`; `C = A = B` (direita para esquerda);
  `C = (A = B)`.
- Cast: `(int)29.55 + (int)21.99` → 29 + 21 = **50**; `(float)6 / (float)4` → **1.5** (sem cast, 6/4 = 1).
- `sizeof(tipo)` e `sizeof expr`; quantidade de elementos de um array:
  `sizeof(lista) / sizeof(lista[0])` — ótimo para 0042 (com o aviso: não funciona com parâmetro, que é ponteiro).
- **Operador vírgula:** avalia da esquerda para a direita, valor e tipo do último; uso típico no `for`
  (`for (i = 0, soma = 0; i <= 100; soma += i, i++);`).

### 0017-relacionais / 0018-logicos / 0070-bits
- `if (expr != 0)` ≡ `if (expr)`. Tabela de operadores bit a bit: `& | ^ << >> ~` com exemplos `C = A & B`.
- **Tabela de precedência (15 níveis)** — base para a tabela do curso: `() [] . ->` | unários `* & ! ~ ++ -- + -
  (cast) sizeof` (D→E) | `* / %` | `+ -` | `<< >>` | `< <= > >=` | `== !=` | `&` | `^` | `|` | `&&` | `||` | `?:`
  (D→E) | atribuições (D→E) | `,`. **Pegadinha derivada:** `&` bit a bit está ABAIXO de `==`, então
  `if (x & 1 == 0)` é `x & (1 == 0)` = sempre 0 — usar parênteses `(x & 1) == 0`.

### 0019-if … 0023-switch
- Sintaxes de `if`, `if-else`, `else if` com `SentençaPorOmissão` opcional; ternário: `premio = (opcao == 'S') ?
  1000 : 0;` (a fonte diz que b e c devem ter o mesmo tipo — na verdade são convertidos para um tipo comum).
- **Pegadinha (exemplo D.3 da fonte):** `switch (op) { case 'a': func1(); break; case 'b': func2(); break;
  case 'H': printf("Olá\n"); default: printf("Saída\n"); }` — com 'H' imprime "Olá" **e** "Saída" (falta break).
  Exercício: o que imprime para 'a', 'H' e 'z'? (nada/func1; Olá + Saída; Saída).
- Erros de digitação na fonte: `case valor3;` e `default;` com ponto e vírgula no lugar de dois-pontos.

### 0025-while / 0026-do-while / 0027-for / 0028-break-continue
- Equivalência `for(e1; e2; e3) s;` ≡ `e1; while (e2) { s; e3; }`.
- **Sentença nula:** `for (i = 0; cad[i] != '\0'; i++);` acha o fim da string (corpo vazio de propósito).
  **Pegadinha associada para o curso:** o `;` acidental — `for (i = 0; i < 10; i++); printf("%d", i);` imprime só 10;
  `while (x > 0); { ... }` trava. Recomenda-se escrever o corpo vazio como `{ }` ou comentar.
- `break` sai do laço ou do switch; `continue` volta ao início; `goto` com rótulo terminado em `:`.

### 0033-funcoes / 0034-parametros
- Formato, chamada e protótipo (`int SelecionarMenu(void); double Area(int x, int y); void sair(int estado);`);
  `void` para "nada retorna/nada recebe" e para ponteiro genérico.
- **"Erros típicos de funções" (lista boa para o curso):** (1) função não-void que termina sem `return` devolve valor
  imprevisível; (2) `if` com `return` só em alguns caminhos; (3) sem protótipo, o C antigo assume que a função
  devolve `int` mesmo que retorne `double` (resultado lixo); (4) efeitos colaterais por alteração de globais.
- `exit(0)` termina na hora e fecha os arquivos; `return valor;` no `main` é o jeito normal.

### 0040-preprocessador / 0039-modulos
- **Conceitos-chave:** três usos — `#include` (inserir arquivo), `#define` (constantes e macros), compilação
  condicional (`#if`, `#ifdef`, `#ifndef`, `#elif`, `#else`, `#endif`) para código de vários sistemas. `#undef` apaga
  uma macro; `#error texto` aborta a compilação com mensagem (a fonte escreve "#erro"); `#pragma` é específico do
  compilador (ignorado se desconhecido); `#line` muda número/nome nas mensagens; `#` sozinho é diretiva nula;
  macros predefinidas `__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`, `__STDC__`.
- **Include guard (para 0039):** `#ifndef NOME_H / #define NOME_H / ... / #endif` evita processar o mesmo
  cabeçalho duas vezes. (A fonte usa `_PAREJA` e depois fala em `_DUPLA` — inconsistência de tradução; e nomes
  começando com `_` + maiúscula são reservados à implementação: preferir `PAREJA_H`.)
- **Erro na fonte:** diz que `#elif`/`#else` NÃO podem ser usados com `#ifndef` — podem, como com `#ifdef`.
- **Pegadinhas de macro (a própria fonte comete):** `#define quadrado(x) x*x` → `quadrado(2+3)` = 11;
  `#define SOMA(x,y) (x) + (y)` → `2 * SOMA(1,2)` = `2*(1)+(2)` = 4, não 6 (faltam os parênteses externos);
  `#define TTYPORT 0x17755U;` com `;` no final — o `;` entra em toda expansão. Na seção D.7 a versão certa:
  `#define quadrado(x) ((x)*(x))`. Exercício: corrigir as três.
- Ideia de exemplo: `#ifdef DEBUG printf("x = %d (linha %d)\n", x, __LINE__); #endif` e compilar com
  `gcc -DDEBUG`.

### 0042-vetores / 0044-matrizes / 0046-strings
- Índices começam em 0; `float lista[10][25]`; `int tres_d[5][2][20]` tem 200 inteiros.
- Inicialização de matriz: `int m[4][3] = {{1,2,3},{4,5,6},{7,8,9},{0,0,0}}` ≡ `{1,2,3,4,5,6,7,8,9}` (o que falta
  vira 0). **Erro na fonte (bom exercício):** explica `int m[4][3] = {{1},{4},{7}}` como "1º, 2º e 3º elemento da
  1ª fila" — na verdade cada `{}` é uma LINHA: m[0] = {1,0,0}, m[1] = {4,0,0}, m[2] = {7,0,0}, m[3] = {0,0,0}.
- **Pegadinha MODELO:** `char hoje[] = "Domingo";` tem 8 posições (com `'\0'`); `char hoje[7] = "Domingo";` é válido
  em C mas **não tem `'\0'`** — não é string (`printf("%s")` lê além). Exercício: qual o tamanho mínimo? (8).
- `char frutas[][10] = {"laranja", "banana", "maçã"};` (matriz de char) × `char *cores[] = {...}` (vetor de
  ponteiros para literais).

### 0050-ponteiros / 0052-ponteiros-e-vetores / 0054 / 0055 / 0056
- `int *p; p = &m;` `*p` acessa o valor; ponteiro nulo (`NULL` ou `0`), testar `if (fp != NULL)`; `void *` aponta
  tipo não especificado. `listafloat[4]` ≡ `*(listafloat + 4)`; `ponteiro = lista` ≡ `= &lista[0]`.
- `char **lista;` "equivale a" `char *lista[]` — **só é verdade em parâmetro de função** (pegadinha para 0054).
- Distinção de declarações (ótima para 0055): `float *minhafun(void);` = função que devolve ponteiro;
  `int (*ptrafuncao)(void);` = ponteiro para função; `float (*pf)(int, int);`.
- **Erros na fonte:** `double *total; double ctotal; total = &total;` (deveria ser `&ctotal` — tipo incompatível);
  `comprimentoOnda = *cabo1;` sem sentido.

### 0064-struct / 0065-typedef / 0068-enum / 0069-union / 0070-bits
- `struct data { int mes; int dia; int ano; }; struct data hoje;` + notação ponto; struct coordenada; `typedef
  struct coordenada {...} Coordenadas;`; `typedef struct { float x, y; } PONTO; PONTO origem = {0.0, 0.0};`.
- **enum:** começa em 0; pode-se fixar valores. **Erro na fonte (pegadinha ótima):** com
  `enum diasSemana {Segunda, Terca, Quarta, Quinta = 10, Sexta, Sabado, Domingo}` diz que "Terça é igual a 2" —
  na verdade Segunda = 0, Terça = 1, Quarta = 2, Quinta = 10, Sexta = 11, Sábado = 12, Domingo = 13. Exercício:
  `if (dia >= Sexta) "não é dia de trabalho"`.
- **union:** vários tipos na mesma posição; inicializa-se pelo 1º membro (`= {75}`). A fonte tem `união`, `long 1`,
  `demo.y` (membro inexistente) — ruído de tradução.
- **Campos de bits:** `struct pessoa { unsigned idade:7; unsigned sexo:1; unsigned filhos:4; }` — 12 bits em vez de
  3 ints; idade 0..127 (a fonte escreve "0..1127"); são dependentes da implementação.
- `volatile` em ponteiro para porta de hardware (`volatile char *porto17`).

---

## Obsoleto / evitar
| Na fonte | Problema | Alternativa |
|---|---|---|
| `sizeof(int)` "proporciona 2 bytes" | plataforma antiga | `sizeof` real (4 nos PCs atuais) |
| `long double` "10 bytes" | depende da plataforma | não decorar; `sizeof` |
| `#if VGA`, "modelo de memória" | DOS | `#ifdef DEBUG`, `#ifdef _WIN32` |
| identificadores com acento (`não`, `três_d`, `área_círculo`) | não portáveis | ASCII: `nao`, `tres_d`, `area_circulo` |
| nomes de guarda como `_PAREJA` | reservados | `PAREJA_H` |
| "sem protótipo a função devolve int" | int implícito removido no C99 | sempre declarar protótipos |
| `char hoje[7] = "Domingo"` como "string" | sem terminador | `char hoje[] = "Domingo"` |

## Extras que não cabem no sumário
- `#line`, `#pragma`, `#error`, diretiva nula `#`, macros predefinidas (`__FILE__`, `__LINE__`, `__DATE__`,
  `__TIME__`, `__STDC__`) — úteis para mensagens de depuração.
- Concatenação de literais adjacentes.
- Operadores compostos bit a bit (`<<=`, `>>=`, `&=`, `^=`, `|=`).
- `volatile` com registradores de hardware.
