# Fichamento — "Linguagem C: Descomplicada" (apostila)

- **Autor:** Prof. André R. Backes (apostila, ~345 páginas, 12 capítulos).
- **Lido:** integralmente (8089 linhas do .md convertido).
- **Avaliação geral:** didática, muito "passo a passo", com caixas de alerta ("pegadinhas") em
  quase toda página e muitos exemplos curtos lado a lado (certo × errado, com × sem). Cobre do
  esqueleto do programa até alocação dinâmica, arquivos e um capítulo "Avançado" bem rico
  (diretivas, ponteiro para função, argc/argv, printf/scanf completos, classes de armazenamento,
  campos de bits, volatile, funções variádicas). **Não cobre estruturas de dados** (listas, pilhas,
  filas, árvores, hash, grafos), nem busca/ordenação, nem análise de algoritmos — só C.
  Pontos fracos: estilo Windows/Code::Blocks dos anos 2010 (`system("pause")` em todo exemplo,
  `gets`, `fflush(stdin)`, `setbuf(stdin,NULL)`), tabelas com erros factuais e vários exemplos com
  bugs ou comportamento indefinido (listados abaixo — ótimos como material de "ache o erro").
- **O que a apostila tem de mais útil em relação ao livro (para nosso curso):**
  1. Catálogo comentado das bibliotecas padrão (stdio, stdlib, math, ctype, string, time) logo no cap. 1.
  2. Passo a passo do *debugger* (breakpoint, watches, next line, step into/out, continue).
  3. Capítulo de alocação dinâmica com **três soluções para matriz dinâmica** (vetor 1D com
     `i*ncol+j`; `int**` com linhas separadas, inclusive matriz triangular; `int**` apontando
     para um bloco único) e a ordem correta de `free`.
  4. Capítulo de arquivos completo: modos de abertura, caminhos relativo/absoluto, `fputc/fgetc`,
     `EOF` × `feof`, `fflush`, `ftell`, `fputs/fgets`, `fwrite/fread`, `fprintf/fscanf`, `fseek`,
     `rewind`, `remove`, `ferror/perror`, gravar o tamanho antes da string.
  5. Capítulo "Avançado": `#line`, `#error`, `#pragma`, `__LINE__/__FILE__/__DATE__/__TIME__`,
     operadores `#` e `##`, ponteiro para array × array de ponteiros, vetor de ponteiros para
     função (calculadora), `printf` com flags/largura/precisão/`*`, `scanf` com `*`, largura e
     *scanset* `%[...]`, `auto/extern/static/register`, campos de bits, `volatile`, `stdarg.h`.

---

## 00-logica

### 0001-algoritmo / 0003-fluxograma
- **Conceitos-chave:** a apostila não ensina algoritmo do zero, mas usa fluxogramas (losango =
  decisão) para explicar `if`, `else`, `switch`, `while`, `for`, `do-while`, `break`, `continue`.
  Mostra o mesmo laço em pseudocódigo ("enquanto A < B faça…") e em fluxograma.
- **Analogias/explicações boas:** laço = losango cuja saída "volta" para a condição depois do bloco;
  `do-while` = o bloco vem antes do losango.
- **Ideias de exemplos:** "imprimir todos os inteiros entre a e b" desenhado como fluxograma e
  depois traduzido para `while`, `for` e `do-while` (o mesmo problema nas três formas).
- **Ideias de exercícios:** dado o pseudocódigo "X ← 4; enquanto X < 5: X ← X − 1; imprima X",
  dizer o que acontece. Resposta: laço infinito (X só diminui, nunca chega a 5).

### 0004-binario
- **Conceitos-chave:** literais em octal (prefixo `0`) e hexadecimal (`0x`); conversão manual
  (`044` = 4·8+4 = 36; `0x44` = 4·16+4 = 68). Número 44 em binário = `00101100` (usado nos
  exemplos de operadores bit a bit).
- **Pegadinhas:** um zero à esquerda muda a base: `int x = 010;` vale 8, não 10.
- **Ideias de exercícios:** quanto vale `int a = 017;`? (15). E `0x1F`? (31). Imprimir 125 em
  `%o`, `%x`, `%X` → `175`, `7d`, `7D`.

### 0005-compilacao
- **Conceitos-chave:** compilar arquivo → objeto; *build* → compila tudo e liga (linkagem) →
  executável; *build and run*. Diretivas são processadas antes da compilação pelo pré-processador.
  `#include <...>` procura nos diretórios do sistema; `#include "..."` procura primeiro na pasta do
  projeto (aceita caminho).
- **Extra valioso:** roteiro de **depuração**: colocar breakpoints, iniciar o debugger, abrir a
  janela de *watches*, avançar linha a linha (*next line*), entrar na função (*step into*), sair
  dela (*step out*), ir ao próximo breakpoint (*continue*), parar. Exemplo usado: programa que lê x
  e calcula fatorial se positivo. Adaptar para `gdb` (`break`, `run`, `next`, `step`, `finish`,
  `continue`, `print`/`display`).
- **Ideias de exercícios:** pôr breakpoint dentro de `fatorial(n)` e anotar o valor de `f` a cada
  volta para n = 4 (1, 2, 6, 24).

---

## 01-fundamentos

### 0006-primeiro-programa
- **Conceitos-chave:** esqueleto (`#include`, `int main()`, chaves delimitam bloco, `return 0`
  avisa que terminou bem); quase todo comando termina em `;`; parênteses delimitam argumentos de
  função; indentação mostra hierarquia (o mesmo programa em 3 linhas compila, mas é ilegível);
  comentários `//` (linha) e `/* */` (bloco) — servem de documentação interna.
- **Pegadinhas:** `system("pause")` aparece em todo exemplo — é só do Windows; **não usar** no curso.
- **Ideias de exercícios:** reescrever um programa "achatado" em uma linha com indentação correta.

### 0007-variaveis
- **Conceitos-chave:** variável = posição de memória com nome e tipo; o tipo define valores e
  operações possíveis; declarar antes de usar; várias na mesma linha separadas por vírgula.
  Regras de nome: letras, dígitos e `_`, começando por letra ou `_`; maiúsculas ≠ minúsculas
  (`Soma`, `soma`, `SOMA` são três variáveis); palavras reservadas proibidas.
  `sizeof` dá o tamanho em bytes de tipo (`sizeof(int)`) ou variável (`sizeof x`).
- **Analogias/explicações boas:** "memória nunca está vazia": toda posição já tem 0s e 1s; variável
  recém-criada contém **lixo**. Exemplo: imprimir `x` antes de atribuir → "qualquer valor".
- **Pegadinhas:** usar variável não inicializada; char sempre entre aspas simples (`'a'`), senão o
  compilador acha que `a` é outra variável; número real usa ponto, não vírgula.
- **Ideias de exemplos:** tabela de nomes válidos × inválidos (`cont`, `Cont`, `_x`, `int1` válidos;
  `1cont`, `-x`, `comp!`, `int`, `x&` inválidos).
- **Ideias de exercícios:** classificar 10 nomes como válidos ou não, justificando.

### 0008-tipos-e-limites
- **Conceitos-chave:** tipos básicos `char`, `int`, `float`, `double`, `void`; modificadores
  `signed`, `unsigned`, `short`, `long` (podem combinar: `unsigned long int`). `unsigned` "ganha" o
  bit de sinal e dobra o máximo positivo. `void` não serve para variável.
- **Pegadinhas (erros da própria apostila — não copiar):** tabela diz `signed int` 32 bits com faixa
  −32768..32767 (incoerente); `void` com "8 bits"; afirma que `short` tem 16 e `long` 32 bits
  "independente do processador" (o padrão só garante mínimos); diz que `float` ocupa mais memória
  que `int` (em geral ambos têm 4 bytes). A lista de palavras reservadas traz `typeof` no lugar de
  `typedef`. Usar `limits.h`/`stdint.h` para mostrar os valores reais da máquina.
- **Ideias de exemplos:** `unsigned int n = 2147483647; n = n + 1;` impresso com `%d` e com `%u`
  (−2147483648 × 2147483648) — mostra que o mesmo bit-padrão é lido de jeitos diferentes.
- **Ideias de exercícios:** prever a saída do exemplo acima; escrever programa que imprime
  `sizeof` de todos os tipos e compara com a tabela.

### 0009-constantes
- **Conceitos-chave:** `#define NOME valor` (substituição textual antes da compilação) × `const
  tipo NOME = valor;` (variável que não pode mudar, segue regras de escopo). Constante precisa ser
  inicializada na declaração. `#define TAMANHO 100` permite redimensionar todos os vetores mudando
  uma linha. Sequências de escape: `\a \b \n \v \t \r \' \" \\ \f`. Notação científica:
  `5.0e10`.
- **Ideias de exemplos:** imprimir `"Hello \\ World"` e `"\"Hello World\""`.
- **Ideias de exercícios:** escrever um `printf` que produza exatamente: `Caminho: C:\temp\novo` e
  outra linha com aspas. Resposta: `printf("Caminho: C:\\temp\\novo\n\"ok\"\n");`

### 0010-printf
- **Conceitos-chave (básico, cap. 2):** string de formato + lista de valores na mesma ordem;
  `%c %d %i %u %f %s %p %e`; texto livre antes/entre/depois dos especificadores; `printf` **não** usa
  `&`. `putchar` escreve um caractere (aceita int: `putchar(65)` imprime `A`).
- **Conceitos-chave (avançado, cap. 12):** formato completo `%[flag][largura][.precisão][comprimento]tipo`.
  Flags: `-` (alinha à esquerda), `+` (sempre mostra sinal), espaço, `#` (prefixo `0`/`0x` em
  octal/hex; força ponto decimal), `0` (completa com zeros). Largura pode vir de variável: `%*d`
  (`printf("%*d", largura, n)`). Precisão: em real = casas decimais; em inteiro = mínimo de dígitos
  com zeros (`%.8d` de 125 → `00000125`); em `%g` = dígitos significativos; em string = máximo de
  caracteres (`%.3s` de "Meu programa C" → `Meu`); também via `%.*f`. `%%` imprime `%`. `%o %x %X %g
  %G`. Comprimento `h`, `l`, `L`. `printf` retorna o nº de caracteres escritos (negativo se erro).
  Uma string longa pode continuar na linha seguinte com `\` no fim.
- **Pegadinhas:** `%d` com `unsigned` acima de INT_MAX mostra negativo; imprimir endereço com `%x`
  ou `%d` em vez de `%p` (errado em 64 bits); `%c` com `char` e `%d` com o mesmo `char` mostram letra
  × código ASCII.
- **Ideias de exemplos:** tabela de preços alinhada: `printf("%-10s|%8.2f\n", nome, preco);`;
  "Juros de 25%%"; mostrar 125 em decimal/octal/hex com e sem `#`.
- **Ideias de exercícios:** prever a saída de `printf("[%5d][%-5d][%05d][%+d]", 5,5,5,5)` →
  `[    5][5    ][00005][+5]`; imprimir `123.45678` com `%.3f`, `%.5e`, `%.5g`.

### 0011-scanf
- **Conceitos-chave:** cada variável lida leva `&` (scanf precisa do endereço); `%d%d` e `%d %d` são
  equivalentes (espaços em branco são ignorados); usuário pode separar com espaço ou ENTER.
  Caracteres fixos no formato precisam ser digitados e são descartados: `scanf("%d/%d/%d", &d,&m,&a)`
  para datas. `getchar()` lê um caractere e devolve `int` (EOF em erro).
  **Avançado:** retorno = nº de itens lidos (ou EOF); `%*d` lê e descarta (ex.: "nome idade curso"
  guardando só nome e curso); largura máxima (`%2d` para dia; `%10s` num `char[11]` evita estouro);
  *scanset*: `%[aeiou]` só aceita vogais, `%[A-Z0-9]` intervalos — para no primeiro caractere fora
  da lista; `%i` aceita `0x..` e octal; modificadores `h`, `l`, `L` (`%lf` para double!).
- **Pegadinhas:** esquecer `&`; ler `double` com `%f` (a apostila faz isso num exemplo — está errado,
  é `%lf`); ler `char` com `%d` (a apostila sugere — escreve 4 bytes num `char`, UB); sobras no
  buffer depois de `%d` atrapalham `%c`/`gets` seguintes. **A apostila recomenda `fflush(stdin)` e
  `setbuf(stdin, NULL)` para "limpar o buffer" — ambos errados** (`fflush` em entrada é indefinido;
  `setbuf` só muda o modo de buffer, a explicação dada é falsa). Ensinar: `scanf(" %c", &c)` ou laço
  `while ((c = getchar()) != '\n' && c != EOF);`.
- **Ideias de exercícios:** ler data `dd/mm/aaaa` e imprimir `aaaa-mm-dd`; ler "Ana 20 Computação"
  com `%s %*d %s`; validar retorno do scanf (repetir até ler um inteiro).

### 0012-aritmetica
- **Conceitos-chave:** `+ - * / %`; menos unário inverte sinal; `/` entre inteiros descarta a parte
  fracionária (`5/4` = 1, `5/4.0` = 1.25); `%` só para inteiros; precedência segue a matemática,
  parênteses forçam ordem. Tabela grande de precedência no fim do cap. 2.
- **Pegadinhas:** `float x = 5/4;` dá 1.000000 (a divisão acontece antes da conversão). A tabela de
  precedência da apostila coloca pré-incremento **acima** de `()` e `[]` — está errada (pós-fixos
  têm a maior precedência).
- **Ideias de exercícios:** média de 3 notas inteiras: por que `(a+b+c)/3` erra e `(a+b+c)/3.0`
  acerta?

### 0013-conversao
- **Conceitos-chave:** atribuição entre tipos diferentes converte para o tipo da esquerda, podendo
  perder informação: `char ch = 65;` → 'A'; `int x = 25.1;` → 25; `float f = ch;` → 65.0. Cast
  explícito `(tipo)expressão`: `y = (int)(65.5/10.0)` → 6.0.
- **Ideias de exemplos:** o exemplo `x = f/10.0` × `y = (int)(f/10.0)` com f = 65.5 (6.55 × 6.00).

### 0014-atribuicao
- **Conceitos-chave:** `=` copia o valor da direita para a variável da esquerda (`5 = x` e
  `y + 5 = x` são erros); atribuição múltipla `x = y = z = 5` (da direita para a esquerda);
  compostos `+= -= *= /= %= &= |= ^= <<= >>=` (`x += 10*y` ≡ `x = x + 10*y`); `++x` incrementa antes
  de usar, `x++` depois (`y = ++x` → x=11,y=11; `y = x++` → x=11,y=10). Operador vírgula:
  `x = (y = 2, y + 3)` → x = 5; vírgula separa, ponto e vírgula termina.
- **Pegadinhas:** a apostila mostra `*p = (*p)++;` e `index = (index==3) ? 0 : ++index;` — ambos
  modificam a mesma variável duas vezes sem ponto de sequência (comportamento indefinido). Corrigir
  para `(*p)++;` e `index = (index + 1) % 4;`.
- **Ideias de exercícios:** prever x e y após `x=10; y = x++ + 1;` (x=11, y=11).

### 0015-math
- **Conceitos-chave:** lista de `math.h`: trigonométricas (radianos), hiperbólicas, `exp`, `log`,
  `log10`, `modf`, `pow`, `sqrt`, `ceil`, `floor`, `fabs`, `fmod`. `stdlib.h`: `abs`, `labs`,
  `div`, `ldiv`.
- **Ideias de exercícios:** usar `modf` para separar parte inteira e fracionária de 3.75; `fmod(7.5, 2)`
  = 1.5.

---

## 02-condicionais

### 0017-relacionais
- **Conceitos-chave:** `> >= < <= == !=` devolvem 1 (verdadeiro) ou 0 (falso); em C qualquer valor
  ≠ 0 é verdadeiro: `if (num)` ≡ `if (num != 0)`; `if (!num)` ≡ `if (num == 0)`. Condição pode
  misturar aritméticos, relacionais e lógicos (`x/2 > y - 3`).
- **Pegadinhas:** não existem `=<`, `=>` nem `<>` (este é do Pascal).
- **Ideias de exercícios:** com x=5, y=3, avaliar `x > 4`, `x == 4`, `x != y`, `x != y+2` → 1,0,1,0.

### 0018-logicos
- **Conceitos-chave:** `&&`, `||`, `!` com tabela-verdade; intervalo 0 < x < 10 vira `x > 0 && x < 10`.
- **Pegadinhas:** escrever `0 < x < 10` em C compila mas não faz o que parece. (A apostila não fala
  de curto-circuito — completar com outra fonte.)
- **Ideias de exercícios:** montar a tabela-verdade de `!a || b`.

### 0019-if / 0020-if-else
- **Conceitos-chave:** `if` executa só o comando seguinte, a menos que haja bloco `{}`; `else` não
  tem condição (é o "caso contrário"); cada um tem seu próprio par de chaves.
- **Pegadinhas (todas com exemplo certo × errado):** `if (num > 10);` — o `;` vira o corpo do if e o
  printf roda sempre (compila sem erro!); `else (num != 10) {` é erro; `else;` também esvazia o
  else; usar `=` no lugar de `==` compila e quebra a lógica (o contrário dá erro de compilação).
- **Ideias de exemplos:** "número digitado é igual a 10?" em versão certa e nas três versões erradas.
- **Ideias de exercícios:** "ache o erro": entregar 4 trechos com `;` após if, `else (cond)`, `=` no
  lugar de `==`, chaves faltando; pedir a saída para num = 3.

### 0021-else-if
- **Conceitos-chave:** if aninhado para três caminhos (igual/maior/menor que 10). O `else` liga-se
  ao `if` mais próximo sem else dentro do mesmo bloco, **independente da indentação**; para ligar ao
  de fora, isolar o interno com `{}`. Não existe "else de else".
- **Ideias de exercícios:** prever saída de `if (a>0) if (b>0) printf("A"); else printf("B");` para
  a = −1, b = 5 (não imprime nada).

### 0022-ternario
- **Conceitos-chave:** `cond ? expr1 : expr2`, típico em atribuição (`z = x > y ? x : y`); pode
  chamar funções nos ramos.
- **Ideias de exemplos:** contador circular 0,1,2,3,0,… (corrigido: `i = (i == 3) ? 0 : i + 1`).

### 0023-switch
- **Conceitos-chave:** compara uma variável inteira/char com constantes (`case`), `default`
  opcional; mais elegante que cadeia de if-else para igualdades. Sem `break` a execução "cai" nos
  cases seguintes. Se o primeiro comando de um case declara variável, envolver o case em `{}`
  (um salto não pode pular uma declaração no mesmo escopo).
- **Analogias/explicações boas:** o fall-through como recurso: contagem regressiva por extenso —
  digitar 5 imprime "Cinco, Quatro, …, Zero" (cases de 9 a 0 sem break).
- **Ideias de exemplos:** classificar pontuação (`.`, `,`, `:`, `;`); calculadora com `+ - * /`.
- **Ideias de exercícios:** o exemplo de pontuação **sem** break: o que sai digitando `.`? (todas as
  mensagens, inclusive "Não é pontuação").

---

## 03-repeticoes

### 0025-while
- **Conceitos-chave:** testa antes, repete 0 ou mais vezes; atua só no comando seguinte sem `{}`.
  Laço infinito: falta condição de parada ou ela nunca é atingida (variável da condição não muda, ou
  muda no sentido errado).
- **Pegadinhas:** `while (a < b); { ... }` — laço infinito vazio.
- **Ideias de exercícios:** imprimir os inteiros entre a e b (exclusivo) com while.

### 0026-do-while
- **Conceitos-chave:** executa ao menos uma vez; exige `;` após `while(cond)`. Uso típico: menu que
  repete enquanto opção inválida (`while (i < 1 || i > 3)`).
- **Ideias de exercícios:** menu de 3 opções com validação; depois transformar em função `int menu()`.

### 0027-for
- **Conceitos-chave:** inicialização → teste → corpo → incremento → teste…; qualquer cláusula pode
  ser omitida mas os dois `;` ficam; sem condição = laço infinito; "incremento" pode ser qualquer
  atualização (`c = c + 2`, ou até `scanf`); vírgula permite duas variáveis
  (`for (i=0, j=100; i<j; i++, j--)`); variável de controle pode ser `char` (`for (c='A'; c<='Z'; c++)`).
  Comparação lado a lado for × while (soma de 1 a 10).
- **Ideias de exercícios:** imprimir o alfabeto; i sobe de 0 e j desce de 100 até se cruzarem —
  quantas linhas? (50).

### 0028-break-continue
- **Conceitos-chave:** `break` sai do laço/switch; `continue` pula para a próxima iteração (só em
  laços). `goto rótulo` (mesma função) existe, programação estruturada dispensa; único uso defendido:
  sair de laços aninhados.
- **Pegadinhas:** a apostila escreve "o comando break interrompe apenas aquela repetição" no
  parágrafo do continue (troca de palavras).
- **Ideias de exemplos:** ler opções até digitar 5, ignorando (continue) valores fora de 1..5.
- **Ideias de exercícios:** três laços aninhados (i,j,k de 0 a 4) que param quando i=2, j=3, k=1:
  fazer com `goto`, depois sem goto (flag ou função com `return`).

### 0029-lacos-aninhados
- **Conceitos-chave:** laço dentro de laço para percorrer pares (linha, coluna); pode misturar tipos
  de laço.
- **Ideias de exemplos:** matriz identidade 4×4 impressa com dois `for` e com dois `while`.

### 0030-padroes-de-laco
- **Ideias de exemplos (cap. 5):** soma de vetor, maior valor (começa com `lista[0]` e varre de 1),
  média (`soma / 5.0`), soma de matriz, impressão linha a linha.

### 0031-aleatorios
- **Conceitos-chave:** apenas listados (`rand`, `srand` em stdlib; `time`, `clock`, `difftime`,
  `CLOCKS_PER_SEC` em time.h). Sem exemplos — completar com outra fonte.

---

## 04-funcoes

### 0033-funcoes
- **Conceitos-chave:** motivos: estruturar o programa em blocos e reutilizar código. Forma
  `tipo nome(parâmetros) { ... }`; definir antes do `main` ou declarar **protótipo** antes (nomes
  dos parâmetros são opcionais no protótipo). Funcionamento: chamada interrompe o fluxo, valores são
  copiados para os parâmetros, corpo executa, `return` devolve e o fluxo volta ao ponto da chamada.
  `return` encerra a função na hora (código depois dele nunca roda); `return;` em função `void`;
  vários `return` são permitidos (a apostila prefere um só, com variável auxiliar). Função não pode
  retornar vetor, mas pode retornar `struct` que contém vetor.
- **Analogias/explicações boas:** função deve fazer só sua tarefa: cálculo do fatorial recebe n e
  devolve o resultado; `scanf`/`printf` ficam em quem chama (generalidade). Exceção legítima: função
  cujo objetivo é a interação (ex.: `menu()` que valida a opção).
- **Pegadinhas:** `int soma(int x, y)` é erro — cada parâmetro precisa de tipo. `void f()` ×
  `void f(void)`: com parênteses vazios o compilador aceita `f(5)` sem reclamar; com `void` é erro.
- **Ideias de exercícios:** extrair o fatorial do `main` para uma função; escrever `int maior(int,int)`
  com um e com dois `return`.

### 0034-parametros
- **Conceitos-chave:** em C tudo é passado por valor (cópia); alterar o parâmetro não altera a
  variável original (`soma_mais_um(x)`: antes 5, dentro 6, depois 5). Parâmetro é variável local.
- **Ideias de exercícios:** prever a saída do exemplo `Troca(x, y)` por valor (dentro troca, fora
  não) — ponte para ponteiros.

### 0035-escopo
- **Conceitos-chave:** escopo = onde e quando a variável vale. Global (fora de funções) vive o
  programa todo e é visível em todo lugar; local vive só no bloco `{}`. Variável local com mesmo nome
  **oculta** a global/externa; a declaração mais próxima vence. Exemplo célebre: x global = 5, depois
  `int x = 4` no main, depois bloco interno `int x = 3`, e de volta: saída 5, 4, 3, 4 (o primeiro
  printf vem antes da declaração local, por isso enxerga a global).
  **Avançado (12.6):** `auto` (padrão das locais), `extern` (avisa que a variável global foi definida
  em outro arquivo, não pode ser inicializada ali), `static` local (mantém valor entre chamadas — o
  exemplo imprime 0..9 em 10 chamadas), `static` em função/global (visível só no arquivo),
  `register` (dica de usar registrador; não aceita `&`; compiladores ignoram).
- **Pegadinhas:** evitar globais (qualquer parte altera, difícil manter, ocupam memória o tempo todo)
  e evitar nomes repetidos. **Erro da apostila:** afirma que `static` é "o modo padrão" das globais e
  usa `static y = 10;` sem tipo (int implícito é inválido desde C99). Correto: global sem `static`
  tem ligação externa; com `static` fica restrita ao arquivo.
- **Ideias de exercícios:** prever a saída do exemplo 5/4/3/4; função `contaChamadas()` com `static`.

### 0036-pilha-de-chamadas
- **Conceitos-chave:** cada chamada guarda parâmetros, locais e endereço de retorno; na recursão isso
  é empilhado a cada chamada, por isso custa memória e tempo. Figura de fatorial(3) descendo
  (chamadas) e subindo (retornos).

### 0037-recursao / 0038-recursao-na-pratica
- **Conceitos-chave:** função que chama a si mesma; "definição circular"; dividir para conquistar.
  Dois cuidados: **critério de parada** (0! = 1) e **parâmetro que muda** a cada chamada (n−1).
  Versões recursiva e iterativa de fatorial e Fibonacci.
- **Analogias/explicações boas:** a árvore de chamadas de `fibo(4)` e `fibo(5)` com os
  sub-cálculos repetidos destacados — "elegância não é eficiência".
- **Ideias de exercícios:** contar quantas chamadas `fibo(5)` faz (15); escrever Fibonacci
  iterativo com a, b, c.

### 0039-modulos
- **Conceitos-chave:** `#include "arquivo.h"` com caminho; `extern` para compartilhar global entre
  arquivos; `static` para esconder função no arquivo. (Não mostra include guards explicitamente, mas
  mostra `#ifndef ... #define ... #endif`, que é a base.)

### 0040-preprocessador
- **Conceitos-chave:** diretivas começam com `#`, uma por linha. `#define` em três usos: símbolo
  (só para testar com `#ifdef`), constante, macro com parâmetros. `#undef` apaga para redefinir.
  `#ifdef/#ifndef/#if/#elif/#else/#endif`. Macro multilinha com `\` no fim. `#x` transforma
  parâmetro em string; `x ## y` cola tokens (`concatena(print, f)` vira `printf`). `#line`, `#error`
  (aborta a compilação com mensagem — ex.: "PI não definido"), `#pragma` (específico do compilador,
  ignorado se desconhecido). Macros pré-definidas `__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`.
- **Analogias/explicações boas:** "macro não é função, é substituição de texto": `prod1(a+2, b)` com
  `x*y` vira `a+2*b` = 5; com `(x)*(y)` vira `(a+2)*(b)` = 6 (a = 1, b = 2).
- **Pegadinhas:** parâmetros sem parênteses; a apostila põe `;` no fim do `#define prod1` (gera `;;`
  — mau hábito). Macro de troca genérica `TROCA(a,b,tipo)` precisa de `{}` para criar escopo do
  temporário. **Erro da apostila:** diz que `#if` não resolve expressões matemáticas — resolve
  expressões inteiras constantes (`#if TAMANHO > 100` é exatamente isso).
- **Ideias de exercícios:** prever c e d no exemplo prod1/prod2; escrever `QUADRADO(x)` e testar com
  `QUADRADO(1+2)`; usar `#ifndef TAMANHO / #define TAMANHO 100`; macro `DEBUG` que imprime
  `__FILE__:__LINE__`.

---

## 05-vetores-e-strings

### 0042-vetores
- **Conceitos-chave:** motivação: 5 alunos com 5 variáveis já é ruim, 100 é inviável → um nome só
  com índice. `tipo nome[N]`, índices de 0 a N−1; cada posição é uma variável comum (scanf com
  `&notas[i]`); acesso em tempo igual para qualquer posição; o nome indica onde começa e o índice
  quantas posições pular (por isso começa em 0). Inicialização com `{}` só na declaração; tamanho
  pode ser omitido (`int v[] = {1,...,10}` → 10). Vetor não se atribui a vetor (`v1 = v` é erro):
  copiar elemento a elemento.
- **Pegadinhas:** C não confere limites: `notas[100]` ou `notas[-1]` acessam memória de outras
  variáveis sem aviso.
- **Ideias de exemplos:** o problema "imprimir alunos com nota acima da média" (motivador).
- **Ideias de exercícios:** ler 5 notas, calcular média e listar as acima da média.

### 0043-vetores-e-funcoes
- **Conceitos-chave:** vetor é sempre passado por "referência" (vai o endereço do 1º elemento) —
  evita cópia e a função altera o original; passar o tamanho em outro parâmetro.
  `int *m`, `int m[]`, `int m[5]` são equivalentes no parâmetro (o 5 é ignorado). Na chamada, só o
  nome, sem colchetes.
- **Ideias de exercícios:** `void imprime(int *v, int n)`; função que dobra todos os elementos.

### 0044-matrizes
- **Conceitos-chave:** `tipo m[L][C]`; dois índices; multidimensionais com um par de colchetes por
  dimensão; armazenamento linear, **o índice mais à direita varia mais rápido**; inicialização com
  um único `{}` (preenche linha a linha) ou com chaves aninhadas; só a 1ª dimensão pode ficar sem
  tamanho (`int m[][2] = {1,...,10}` → 5 linhas). Em parâmetro precisa de todas as dimensões menos a
  primeira (`int m[][5]`) — matriz é "vetor de vetores" e o compilador precisa do tamanho de cada
  linha. Pode-se passar `&mat[0][0]` e tratar como vetor 1D de L·C elementos.
- **Ideias de exercícios:** zerar um cubo 5×5×5; somar matriz 3×3; imprimir matriz 3×2 via função
  com `int m[][2]` e via ponteiro 1D.

### 0045-caracteres
- **Conceitos-chave:** `char` guarda número pequeno ou código ASCII; `%c` × `%d` do mesmo char;
  `putchar(65)` → `A`. Lista de `ctype.h`: `isalnum isalpha iscntrl isdigit islower isprint ispunct
  isspace isupper isxdigit tolower toupper`. `enum` pode receber caracteres (`novalinha = '\n'`).

### 0046-strings
- **Conceitos-chave:** string = vetor de `char` terminado em `'\0'`; o `'\0'` separa o texto do lixo
  nas posições não usadas; num `char s[50]` cabem 49 letras. Inicializar com aspas duplas já põe o
  `'\0'` (`char texto[] = "Linguagem C."` tem 13 posições). Acesso por índice (`str[0] = 'L'`
  troca "Teste" por "Leste"). String não se atribui com `=` nem se compara com `==`.
  `strlen` (conta até o `'\0'`, não o tamanho do vetor: "teste" num `char[15]` → 5), `strcpy(dest,
  orig)`, `strcat(dest, orig)` (a 1ª letra de orig ocupa o lugar do `'\0'` de dest), `strcmp` (0 se
  iguais; diferencia maiúsculas). Cópia manual com laço até `'\0'` e pôr o `'\0'` no fim.
  Catálogo de `string.h`: `memcpy memmove strncpy strncat memcmp strncmp memchr strchr strcspn
  strpbrk strrchr strspn strtok memset strerror`.
- **Pegadinhas:** destino pequeno em `strcpy`/`strcat` → estouro de buffer; aspas duplas para string,
  simples para char.
- **Ideias de exemplos:** "bom" + "dia" com strcat (sem espaço! → "bomdia").
- **Ideias de exercícios:** implementar `meu_strlen` e `meu_strcpy`; comparar senha com `strcmp`.

### 0047-lendo-strings
- **Conceitos-chave:** `scanf("%s", str)` sem `&` lê só até o primeiro espaço; `fgets(str, tam,
  stdin)` lê até ENTER ou tam−1 caracteres e **guarda o `'\n'`**; `fputs(str, stdout)`.
- **Pegadinhas:** a apostila apresenta `gets` como "alternativa mais eficiente" e a usa em dezenas
  de exemplos (inclusive `gets` depois de `scanf("%d")`, que lê a linha vazia). **gets foi removida
  do C11** — no curso, sempre `fgets` + remover o `'\n'` (`str[strcspn(str, "\n")] = '\0'`).
  Não ensinar `setbuf(stdin, NULL)`.
- **Ideias de exercícios:** ler nome completo com fgets e imprimir quantas letras tem (sem contar o
  `'\n'`).

---

## 06-ponteiros

### 0049-memoria
- **Conceitos-chave:** toda informação está na memória e tem endereço; o programador pensa no nome,
  o computador no endereço. `&x` dá o endereço; `%p` imprime.
- **Analogias/explicações boas:** ponteiro para ponteiro = "anotar o endereço de um papel que contém o
  endereço da casa do seu amigo" (vale também para ponteiro simples: o ponteiro é o papel com o
  endereço).

### 0050-ponteiros
- **Conceitos-chave:** variável guarda valor; ponteiro guarda endereço. `tipo *p;` — o tipo diz para
  que tipo ele pode apontar. `*` tem três papéis conforme o contexto: multiplicação (binário),
  declaração, acesso ao conteúdo. Ponteiro não inicializado aponta para lugar indefinido (UB);
  `NULL` = endereço de lugar nenhum (≠ não inicializado). `p = &count; *p = 12;` muda `count`.
  Atribuir endereço de `float` a `int*` compila mas lê lixo (1101004800); com cast `*(float*)p`
  funciona. Ponteiros do mesmo tipo podem ser atribuídos entre si. Pode-se pôr um endereço literal
  (`0x3F8`) — útil em microcontroladores, perigoso em PC.
- **Pegadinhas:** `int soma, *p2;` — o `*` vale só para p2. Na apostila os exemplos de endereço
  literal fazem `int *p = 0x5DC;` sem cast (gera aviso) e imprimem ponteiro com `%d` (errado).
- **Ideias de exercícios:** tabela "o que vale" para `x`, `&x`, `p`, `*p`, `&p` após `p = &x`.

### 0051-passagem-por-referencia
- **Conceitos-chave:** passar o endereço (`&x` na chamada) e receber ponteiro (`int *n`), usando
  `*n` dentro; é o que `scanf` faz — por isso o `&`. Troca (swap) por valor (não funciona fora) ×
  por referência (funciona): saídas "Antes 2 e 3 / Dentro 3 e 2 / Depois 2 e 3" × "... Depois 3 e 2".
  Struct por referência: `(*p).x` — os parênteses são obrigatórios porque `.` tem precedência maior
  que `*` (`*p.x` significa `*(p.x)`); `p->x` substitui `(*p).x`.
- **Ideias de exercícios:** `void minmax(int *v, int n, int *min, int *max)`; função que zera uma
  struct ponto recebida por ponteiro, nas duas notações.

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** nome do vetor = endereço do 1º elemento (`p = vet` ≡ `p = &vet[0]`);
  `p[i]` ≡ `*(p+i)`; `&vet[i]` ≡ `vet + i`. Aritmética só soma/subtrai inteiros e anda em unidades
  do tipo (int* +1 → +4 bytes; double* +1 → +8). `void*` anda de 1 em 1 byte (extensão do GCC; no
  padrão é proibido). Comparação: `==`/`!=` (mesma posição), `< >` (mais adiante na memória — só faz
  sentido dentro do mesmo vetor). Matriz via ponteiro: `*(*(mat + l) + c)` ou `int *p =
  &mat[0][0]` percorrendo L·C posições.
- **Pegadinhas:** comparar com `>` ponteiros de variáveis diferentes (como faz a apostila) não tem
  significado garantido.
- **Ideias de exercícios:** percorrer vetor com `*(p+i)` e com `p++`; somar matriz 2×2 com um único
  laço via ponteiro.

### 0053-ponteiros-e-strings
- **Conceitos-chave:** ponteiro pode percorrer string; vetor de ponteiros (`int *pvet[2]`) guarda
  endereço de variável ou de outro vetor (`pvet[1] = y; pvet[1][1]`).
  **Avançado:** `int (*p3)[10]` = ponteiro para vetor de 10 ints; `int *p4[10]` = vetor de 10
  ponteiros para int.
- **Pegadinhas:** a apostila escreve `typedef vetor int[10];` (sintaxe errada; o certo é
  `typedef int vetor[10];`).

### 0054-ponteiro-para-ponteiro
- **Conceitos-chave:** `int **p2 = &p;` — `*p2` é o endereço de x, `**p2` é x; nº de `*` =
  níveis; evitar muitos níveis. Base para matriz dinâmica (cada nível = uma dimensão).
- **Ideias de exemplos:** `char letra = 'a'` acessada por `*ptrChar`, `**ptrPtrChar`, `***ptrPtr`.

### 0055-ponteiro-para-funcao
- **Conceitos-chave:** função também está na memória; o nome da função é seu endereço (`p = max;`
  sem `&`); declaração `int (*p)(int, int);` — parênteses obrigatórios (sem eles é função que
  retorna `int*`); só aponta para funções com o mesmo protótipo; chamar `p(x, y)`; pode ser NULL;
  passar como parâmetro: `int executa(int (*op)(int,int), int x, int y)`; vetor de ponteiros para
  função: `int (*ops[4])(int,int) = {soma, sub, prod, div}`.
- **Analogias/explicações boas:** motivação: uma ordenação genérica que recebe a função de
  comparação (ponte para `qsort`).
- **Ideias de exemplos:** calculadora: lê `+ - * /`, escolhe a função num switch (ou índice no
  vetor de funções) e chama `ops[i](x, y)`.
- **Ideias de exercícios:** reescrever a calculadora sem switch, mapeando o caractere para índice.

### 0056-void-generico
- **Conceitos-chave:** `void *pp` aceita endereço de qualquer tipo (até de ponteiro), mas não pode
  ser desreferenciado sem cast: `*(int*)pp`. `malloc` retorna `void*` porque não sabe o uso.

---

## 07-memoria-dinamica

### 0058-pilha-e-heap
- **Conceitos-chave:** motivação: salários de uma empresa — `float salarios[1000]` desperdiça se
  houver menos e não cabe se houver mais; alocação dinâmica pede memória em tempo de execução e
  devolve o endereço num ponteiro. Variáveis comuns são liberadas automaticamente; dinâmicas não.
  `exit(1)` encerra o programa (fecha arquivos abertos). Locais ficam na pilha (dito no capítulo de
  funções).

### 0059-malloc-free
- **Conceitos-chave:** `malloc(nbytes)` → `void*` (ou NULL); sempre `n * sizeof(tipo)` (1000 bytes
  = 1000 chars, mas 250 ints); testar `if (p == NULL)`; usar como vetor (`p[i]`). `free(p)` com o
  ponteiro do início do bloco; o sistema sabe o tamanho por uma tabela interna. Depois de `free`, o
  ponteiro continua com o endereço antigo (pode "funcionar" e ler lixo) → fazer `p = NULL`.
  `sizeof` funciona com tipo ou variável.
- **Pegadinhas:** usar memória após `free` (a apostila mostra que "nenhum erro ocorre" — é UB
  silencioso, ótimo para discutir); esquecer de liberar. A apostila chama `sizeof` de "função" (é
  operador) e tem o typo "50 * 4 bytes" para 5 ints.
- **Ideias de exercícios:** ler N, alocar N notas, calcular média, liberar.

### 0060-calloc-realloc
- **Conceitos-chave:** `calloc(n, tam)` recebe quantidade e tamanho separados e zera todos os bits
  (comparar impressão de `calloc` × `malloc` não inicializado); `realloc(p, novoTam)` aumenta ou
  diminui, pode mover o bloco (copia o conteúdo), área nova não inicializada; `realloc(NULL, t)` ≡
  `malloc(t)`; se falhar, devolve NULL e o bloco antigo fica intacto.
- **Pegadinhas:** `p = realloc(p, t)` (como na apostila) perde o bloco original se falhar → usar
  ponteiro temporário. `realloc(p, 0)` como `free` é dependente da implementação (e indefinido no
  C23) — não ensinar.
- **Ideias de exemplos:** vetor 1..5, encolhe para 3, cresce para 10 e imprime (as 7 novas posições
  com lixo).
- **Ideias de exercícios:** ler números até 0, dobrando a capacidade com realloc quando encher.

### 0061-matriz-dinamica (destaque da apostila)
- **Conceitos-chave — três soluções:**
  1. **Vetor 1D** de L·C elementos, acesso `p[i*ncol + j]` (perde-se `p[i][j]`; um `malloc`, um
     `free`).
  2. **`int **p`**: `malloc(L * sizeof(int*))` para as linhas e, para cada linha,
     `malloc(C * sizeof(int))`. Mantém `p[i][j]`. Liberar na ordem inversa: cada `p[i]` e depois
     `p` (se liberar `p` primeiro perde os endereços das linhas). Permite linhas de tamanhos
     diferentes — matriz triangular inferior com `malloc((i+1)*sizeof(int))`.
  3. **Bloco único + vetor de ponteiros**: `v = malloc(L*C*sizeof(int))`, `p = malloc(L*sizeof(int*))`,
     `p[i] = v + i*C`. Mantém `p[i][j]`, só dois `malloc` e dois `free`, memória contígua.
- **Analogias/explicações boas:** "o que se aloca tem sempre um nível de ponteiro a menos que o
  ponteiro que recebe" (int** recebe vetor de int*; int* recebe vetor de int).
- **Ideias de exercícios:** implementar as três para uma matriz 3×4 lida do teclado e comparar o nº
  de malloc/free; triângulo de Pascal com matriz triangular.

### 0062-erros-de-memoria
- **Conceitos-chave:** ponteiro solto (*dangling*) após free; ponteiro não inicializado; usar
  memória liberada; esquecer free. (Sem valgrind/ASan — completar.)

---

## 08-structs

### 0064-struct
- **Conceitos-chave:** agrupa variáveis de tipos possivelmente diferentes sob um nome ("variável que
  contém variáveis"); declarada em geral no escopo global; `;` obrigatório após `}`; pode declarar
  variáveis junto (`} cad1, cad2;`); declarar com `struct cadastro c;`; acesso com `.`; campos string
  recebem com `strcpy`. Inicialização `{"Carlos", 18, "Avenida Brasil", 1082}` na ordem dos campos;
  omitidos viram 0/"" . Atribuição `p1 = p2` copia tudo (inclusive vetores internos!) mas só entre
  variáveis do **mesmo tipo struct** (struct ponto × struct novo_ponto com campos iguais = erro).
  Struct aninhada: `c.ender.rua`.
- **Ideias de exemplos:** comparar declarar 4 cadastros com 16 variáveis soltas × `struct cadastro
  c1, c2, c3, c4` × `struct cadastro c[4]`.
- **Ideias de exercícios:** struct `endereco` dentro de `cadastro`; ler e imprimir.

### 0065-typedef
- **Conceitos-chave:** `typedef` cria sinônimo, não tipo novo (`typedef int inteiro;` — int e
  inteiro se misturam livremente). Uso principal: `typedef struct cadastro cad;` ou tudo junto
  `typedef struct { ... } cad;` (nome da struct pode ser omitido).
- **Pegadinhas:** sinônimos que escondem demais confundem: `typedef unsigned int positivos[5];` —
  `positivos v;` não deixa claro que v é vetor.

### 0066-vetor-de-structs
- **Conceitos-chave:** `struct cadastro c[4]`; acesso `c[i].nome` (índice antes do ponto);
  `c[1] = c[2]` é válido.

### 0067-ponteiro-para-struct
- **Conceitos-chave:** struct por valor (cópia inteira) ou só um campo (`imprime_valor(p1.x)`); por
  referência com `(*p).x` ou `p->x`. Função pode retornar struct (truque para "retornar vetor").
- **Pegadinhas:** exemplo `imprime_valor(int x)` da apostila usa `p.x` dentro da função (não
  compila).

### 0068-enum
- **Conceitos-chave:** lista de constantes inteiras com nome; primeira vale 0, cada uma vale a
  anterior + 1; pode fixar valores (`Domingo = 1, ..., Quarta = 7, Quinta` → 8); aceita caracteres
  (`'\n'`); como são inteiros, `s1 + s2` compila (mesmo sem sentido).
- **Ideias de exercícios:** prever valores de `enum {A=1, B, C, D=7, E, F}` → 1,2,3,7,8,9.

### 0069-union
- **Conceitos-chave:** sintaxe igual à struct, mas todos os campos compartilham a mesma memória; o
  tamanho é o do maior campo; só um valor válido por vez (alterar um altera os outros). Exemplo:
  `union { short x; unsigned char c; }` com x = 1545 → c = 9 (byte baixo); c = 69 → x = 1605. Uso
  típico: acessar os bytes de um tipo maior (`unsigned char c[2]` sobre um `short`).
- **Pegadinhas:** o resultado depende da ordem dos bytes da máquina (little-endian).
- **Ideias de exercícios:** explicar 1545 = 6·256 + 9 e 1605 = 6·256 + 69.

### 0070-bits
- **Conceitos-chave:** `~ & | ^ << >>` sobre inteiros (não em float/double, cuja representação é
  mantissa × 2^expoente). Com x = 44 (`00101100`) em `unsigned char`: `~x` = 211, `x & 167` = 36,
  `x | 129` = 173, `x ^ 167` = 139, `x << 2` = 176, `x >> 2` = 11; deslocar 1 posição ≈ ×2 ou ÷2.
  Compostos `&= |= ^= <<= >>=`. **Campos de bits** (12.7): membros de struct/union com largura em
  bits (`unsigned int ligado:1; signed int valor:4; unsigned int :3;`); campo sem nome preenche
  (*padding*); largura 0 força alinhamento; não têm endereço (sem `&`, ponteiro, vetor ou `sizeof`);
  `signed` de 1 bit não faz sentido — preferir `unsigned`. Usos: flags, hardware, formatos de arquivo.
- **Ideias de exercícios:** fazer as contas de 44 com 167/129 à mão em binário; struct `status` com
  campo ligado e valor de −8 a 7.

---

## 09-arquivos

### 0072-arquivos-texto
- **Conceitos-chave:** arquivo = sequência de bytes em memória secundária; vantagens: persistência,
  volume, acesso aleatório. **Texto** (legível, convertido para caracteres, maior e mais lento; `\n`
  pode virar `\r\n`) × **binário** (cópia da memória, sem conversão). Ex.: o int 12345678 ocupa 4
  bytes em binário e 8 em texto. `FILE *fp` = ponteiro para a estrutura/buffer do arquivo.
  `fopen(nome, modo)` → NULL em erro; modos `r w a` (+`b`, +`+`): `w` cria/apaga, `a` acrescenta,
  `r` exige existência. Caminho absoluto × relativo; no Windows escrever `\\` na string. Sempre
  testar NULL e `exit(1)`. `fclose` grava o que restou no buffer (0 = sucesso).
  `fputc/fgetc` (um caractere; `fgetc` devolve **int** para caber o `EOF`, que vale −1 em muitos
  sistemas); `stdin`, `stdout`, `stderr` são arquivos já abertos. `fputs` (não acrescenta `\n` nem
  espaço — "Hello"+"World" vira "HelloWorld"), `fgets` (para no `\n`, que fica na string, ou em
  tam−1; NULL no fim). `fprintf/fscanf` = printf/scanf com `FILE*` na frente.
- **Analogias/explicações boas:** buffer = área intermediária; gravar caractere a caractere no disco
  exigiria mover a cabeça de leitura a cada byte — junta-se tudo e grava de uma vez; `fflush(fp)`
  força a gravação.
- **Pegadinhas (erros presentes nos exemplos — usar como "ache o erro"):**
  `char c; while ((c = fgetc(arq)) != EOF)` — `c` deve ser `int`; `while (!feof(fp)) { c = fgetc(fp);
  printf(...) }` imprime um lixo a mais no fim (feof só fica verdadeiro **depois** de uma leitura
  falhar) — o mesmo bug soma o último número duas vezes no exemplo da matriz com `fscanf`;
  comparar o retorno de `fgets` com `EOF` (é ponteiro, compara-se com NULL); `fflush` em arquivo de
  leitura é indefinido. `stdaux`/`stdprn` não são padrão.
- **Ideias de exemplos:** gravar "Nome: Ricardo / Idade: 30 / Altura: 1.74" com fprintf e reler com
  fscanf pulando os rótulos; gravar matriz 2×2 em texto e somar ao reler.
- **Ideias de exercícios:** copiar um arquivo texto caractere a caractere; contar linhas de um
  arquivo com fgets; corrigir o laço `while(!feof)` para `while (fscanf(arq, "%d", &v) == 1)`.

### 0073-arquivos-binarios
- **Conceitos-chave:** `fwrite(ptr, tamItem, qtd, fp)` / `fread(...)` → devolvem quantos itens
  foram processados (menor que qtd = erro/fim). Variáveis simples e structs com `&`, vetores sem.
  Pode gravar parte de vetor (qtd = 2 grava só as 2 primeiras posições). Ao ler string, pôr o
  `'\0'` manualmente; **gravar o tamanho antes da string/vetor** facilita a leitura (`fwrite(&t,...)`
  e depois os t caracteres). `ftell` (posição; em binário = bytes desde o início) — com
  `fseek(arq, 0, SEEK_END)` dá o tamanho do arquivo. `fseek(fp, n, origem)` com `SEEK_SET`,
  `SEEK_CUR`, `SEEK_END` (n pode ser negativo); `rewind`; `remove(nome)`; `ferror(fp)` (testar logo
  após cada operação) e `perror("msg")` (imprime "msg: No such file or directory").
- **Pegadinhas:** a apostila diz que as três constantes SEEK valem 0 (são 0, 1, 2); usa extensão
  `.txt` para arquivo binário; `fprintf/fscanf` × `fwrite/fread`: velocidade/tamanho favorecem os
  binários.
- **Ideias de exemplos:** escrever "1234567890", `fseek(arq, 5, SEEK_SET)`, escrever "abcde" →
  arquivo fica "12345abcde".
- **Ideias de exercícios:** cadastro de structs em binário; ler o 3º registro direto com
  `fseek(fp, 2*sizeof(struct r), SEEK_SET)`; descobrir o tamanho de um arquivo.

### 0074-argumentos
- **Conceitos-chave:** `int main(int argc, char *argv[])`; `argc` ≥ 1 (o nome do programa conta);
  `argv[0]` = nome do programa; `atoi` converte texto em número.
- **Ideias de exemplos:** listar parâmetros (`prog par1 par2` → "Parametro 1: par1 …"); somar os
  números da linha de comando.
- **Ideias de exercícios:** `./soma 3 4 5` → 12; mensagem de uso se `argc == 1`.

---

## Funções variádicas (12.9) — encaixar como extra do módulo 04
- **Conceitos-chave:** `tipo f(int n, ...)`; precisa de ao menos um parâmetro fixo (que diz quantos
  e/ou de que tipo são os demais, como o formato do printf); `stdarg.h`: `va_list`, `va_start(lista,
  ultimo_fixo)`, `va_arg(lista, tipo)`, `va_end(lista)`. Sem verificação de tipo → perigoso;
  `printf` com `%x` a mais vaza memória (ataque de string de formato).
- **Ideias de exercícios:** `soma_int(3, 4, 5, 6)` → 15; `maior(n, ...)`.

---

## Obsoleto / evitar
- `system("pause")` em todos os exemplos (Windows) e `#include <stdlib.h>` só para isso.
- Code::Blocks 10.05 e link do BerliOS (fora do ar); substituir por gcc + terminal + gdb/VS Code.
- `gets` (removida no C11) e `gets` após `scanf`.
- `fflush(stdin)` e `setbuf(stdin, NULL)` para "limpar o buffer" (indefinido / explicação falsa).
- `while (!feof(fp))` como laço de leitura.
- `char c = fgetc(...)` comparado com `EOF`.
- `realloc(p, 0)` como free; `p = realloc(p, ...)` sem temporário.
- `int` implícito (`static y = 10;`, `static n = 0;`) e `main()` sem `int`.
- Ponteiros impressos com `%d`/`%u`; `int *p = 0x5DC` sem cast; aritmética em `void*`.
- `*p = (*p)++` e `index = (index==3) ? 0 : ++index` (UB).
- Tabelas com erros: faixa de `signed int`, `void` com 8 bits, `typeof` como palavra reservada,
  precedência de `++` pré acima de `()`, valores de `SEEK_*` todos 0, "float ocupa mais que int".
- `stdaux`, `stdprn`; `register` (inútil hoje); truque `volatile` por cast.
- Afirmação de que `#if` não avalia expressões; de que `static` é o padrão das globais.
- Ler `char` com `%d` e `double` com `%f` no scanf.

## Extras que não cabem no sumário
- Catálogo de funções por biblioteca (stdio, stdlib — `atof atoi atol strtod strtol strtoul abort
  atexit exit getenv system bsearch qsort abs div` —, math, ctype, string, time — `clock difftime
  mktime time asctime ctime gmtime localtime strftime`, `struct tm`, `CLOCKS_PER_SEC`). Bom para um
  apêndice de referência.
- História/influência de C (Ritchie, 1972, ANSI 1989; C++, Java, C#, PHP herdaram a sintaxe).
- Roteiro de debugger (pode virar um "bônus" no módulo 01 ou 04 com gdb).
- Diretivas `#line`, `#pragma`, macros pré-definidas, operadores `#`/`##`.
- `printf`/`scanf` avançados: flags, `%*d`, `%.*f`, `%.3s`, `%*d` no scanf, scanset `%[A-Z0-9]`.
- Classes de armazenamento completas, campos de bits, `volatile`, funções variádicas.
- Dica de segurança: ponteiros soltos podem ser explorados; strings de formato controladas pelo
  usuário vazam memória.
