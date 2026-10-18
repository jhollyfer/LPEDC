# Fichamento — Apostila "slago" de Linguagem C (Turbo C)

- **Título:** Linguagem C (apostila de 131 p., capítulos 1 a 8: introdução, decisão, repetição, macros e funções,
  vetores/strings/matrizes, estruturas e uniões, ponteiros, arquivos).
- **Autor:** Silvio Lago (nome aparece no próprio material — "Silvio Lago" na agenda de exemplo; arquivo "slago").
  Ambiente: Borland Turbo C / DOS.
- **Arquivo lido:** `d40c1084-slago-C.md` (3800 linhas, lido por completo).
- **Avaliação geral:** a mais "algorítmica" das apostilas de C: além da linguagem, traz **recursão bem explicada**
  (base/passo, simulação por substituição, fluxo de chamadas e retornos, rastreamento automático), **busca linear e
  binária com tabelas de execução e análise de custo**, **bolha, seleção e inserção com traços completos e
  contagem de comparações/trocas**, **estabilidade** (ordenação por chaves múltiplas), **union etiquetada, campos de
  bits**, ponteiros para função (vetor de funções para menu, `minmax` com comparador, `qsort`) e **lista encadeada**
  (inserção/remoção no início, acesso ao i-ésimo, tratamento recursivo). Ótimos exercícios temáticos (IMC, CPF,
  dígito verificador, campo minado, labirinto, cadeia de Freeman, criptografia XOR, gabarito de concurso).
  Contras: muito `conio.h`/`dos.h`/`bios.h`/`dir.h`, `void main`, `gets`, `int` de 2 bytes, e **vários erros nos
  próprios exemplos** (listados) — úteis para "ache o erro". O sumário promete árvores binárias, mas o texto não
  as traz.

---

### 0001-algoritmo / 0005-compilacao
- Figura do processo: `PRG.C` → pré-processador → compilador → `PRG.OBJ` → linkeditor (+ `*.LIB`) → `PRG.EXE`.
  C criada em 1972 (Ritchie, Bell Labs, PDP-11/UNIX), descendente de BCPL.

### 0006-primeiro-programa
- **Exemplo motivador ótimo:** IMC — "obeso se IMC > 30", `imc = peso / pow(altura, 2)`, `#define LIMITE 30`,
  `if (imc <= LIMITE) ... else ...`. Bom primeiro programa "de verdade".
- **Exercício "descubra os erros" (excelente para o curso):** programa PERIM.C com: comentário fechado com `/*`;
  `#include <studio.h>`; `#define PI = 3.1415` (o `=` vira parte do texto); `Main()` maiúsculo; `clrscr;` e
  `getch;` sem parênteses; comentário sem fechar engolindo o `scanf`; declaração `float perim;` no meio (C89);
  `perim := 2*PI*raio;` (sintaxe Pascal). Resposta esperada: listar cada um e a correção.
- Observações: `main` é reservado mas `Main` não (C diferencia maiúsculas).

### 0007-variaveis / 0008-tipos-e-limites
- **Conceitos-chave:** 5 tipos básicos (`char`, `int`, `float`, `double`, `void`); declaração = tipo + identificador;
  o computador só guarda números — um char é o código ASCII. **Bit de sinal**: bit mais à esquerda; `unsigned`
  reaproveita esse bit e dobra a faixa positiva; `unsigned` sozinho = `unsigned int`; `long` dobra, `short` pode
  reduzir; `long float` ≡ `double` (antigo).
- Tabela com `int` de 2 bytes — no curso, mostrar com `sizeof` que hoje são 4.

### 0009-constantes / 0010-printf / 0011-scanf
- Tabela de especificadores (`%c %o %d %x %u %ld %f %lf %s %%`) e de escapes (`\a \b \f \n \r \t \" \' \\`).
- `scanf("%d %c", &idade, &sexo)` — cada especificador casa com um endereço.
- **Exemplo de formatação:** `a = 678`: `|%5d|` → `|  678|`; `|%06d|` → `|000678|`.
- **ERROS na fonte (ótimos para "ache o erro"):** usa `%7.3d` e `%7.2d` para imprimir um `float` (deveria ser
  `%7.3f`/`%7.2f`) e mostra `12.34` como saída de `%.2f` de 12.3456, contradizendo a própria regra de
  arredondamento que enuncia (o correto é `12.35`). Também chama `getch()` antes do primeiro `printf` sem incluir
  `conio.h`.
- **Exercícios (com resposta esperada):** média de duas notas; consumo km/l; código ASCII de um caractere em octal,
  decimal e hexa (`'A'` → 101, 65, 41); Fahrenheit→Celsius com a dica `C = (F − 32) * (5 / 9)` — **pegadinha
  (intencional ou não):** `5/9` vale 0, então tudo dá 0; usar `5.0/9`; hipotenusa com `sqrt` (3, 4 → 5).

### 0012-aritmetica
- `7 / 2` → 3, `7.0 / 2` → 3.5; `7 % 2` → 1; `7.0 % 2` → erro.

### 0014-atribuicao
- **Argumento bom para os operadores compostos:** além de curtos, evitam redundância: `v[i+w[2*j]] += 3` garante que
  o lado esquerdo e o direito sejam a MESMA variável (em `v[i+w[2*j]] = v[i+w[2*j]] + 3` é fácil errar um índice).
- **Exercício (resposta):** por que `x = x * 2 + y` não pode virar `x *= 2 + y`? (o segundo é `x * (2 + y)`).
- **Exemplo pronto:** `x = 5, y = 5; v = ++x; w = y--;` → x=6 y=4 v=6 w=5. `++` não se aplica a constantes.
- **Exercício-pegadinha:** `x = 5; y = x++ + ++x;` — a fonte pede "quais os valores e por quê?". Resposta correta
  para o curso: **comportamento indefinido** (x modificado duas vezes sem ponto de sequência); não escreva assim.

### 0017-relacionais / 0018-logicos
- **Conceitos-chave:** 0 é falso, qualquer outro valor verdadeiro (5, −3, 1.2, `'a'` verdadeiros; 0 e `4−4` falsos);
  comparações produzem 0 ou 1; ordem de avaliação: aritméticos → relacionais → lógicos.
- **ERRO na fonte (pegadinha ótima):** afirma que `printf("%d %d", 5<6, 6>5)` imprime "1 0" — o correto é **1 1**
  (as duas comparações são verdadeiras). Usar como "ache o erro".
- **Exercício (resposta calculada):** `printf("%d %d %d %d", !3, !0, 3+'a'>'b'+2 && !'b', 1 || !2 && 3);` →
  `!3`=0; `!0`=1; `3+97 > 98+2` é `100 > 100` = 0, então `0 && ...` = 0; `1 || ...` = 1 → **0 1 0 1**.

### 0019-if / 0020-if-else / 0021-else-if
- **Exemplos:** aprovado/reprovado com média ≥ 7.0; salário de horista a R$ 19,50/h com IR de 10% acima de
  R$ 1500 (`if` sem `else`: `if (s > 1500) s = 0.90 * s;`) — 80 h → 1560 → 1404.00; 70 h → 1365.00;
  triângulo: verificar desigualdade triangular (`a < b + c && b < a + c && c < a + b`) e classificar equilátero /
  isósceles / escaleno com `if` aninhado (dentro) e encadeado (`else if`).
- **Exercícios:** maior de dois números; ano bissexto (a dica da fonte esquece a regra dos 400: 2000 é bissexto,
  1900 não — pegadinha); valor absoluto; reajuste de 5% com abono de R$ 100 para quem ganha até R$ 750
  (cuidado: abono sobre o salário antigo ou o novo?); aprovado (≥7) / recuperação / reprovado (<3); raízes reais
  por Báskara (a ≠ 0, delta < 0 sem raízes reais).

### 0022-ternario
- `abs = n > 0 ? n : -n;` e `printf("Máximo = %d", x > y ? x : y);` — vantagem: é expressão, cabe onde um
  `if` não cabe (argumento de função).
- **Exercícios bons (resposta):** plural automático: `printf("%d erro%s detectado%s", e, e == 1 ? "" : "s",
  e == 1 ? "" : "s");` → "1 erro detectado", "5 erros detectados"; imprimir valor lógico como texto:
  `printf("%s", v ? "true" : "false");`.

### 0023-switch
- **Conceitos-chave:** expressão `char`/`int`; executa a partir do case igual até um `break`; `default` opcional e
  pode estar em qualquer posição; `break` não faz parte da sintaxe do switch; "vazamento" (fall-through) quando
  falta o break; não precisa de chaves para vários comandos num case.
- **Exercício MODELO (tabela pronta):** `switch(n) { case 1: putchar('A'); break; case 3: putchar('B'); case 4:
  putchar('C'); break; default: putchar('*'); case 5: putchar('D'); } putchar('.');` → n=1 "A."; n=2 "*D." (default
  no meio vaza para o case 5!); n=3 "BC."; n=4 "C."; n=5 "D.". (A fonte escreve `printf('*')` — aspas simples num
  printf é erro; corrigir para `putchar('*')`.)
- **Exemplos:** calculadora `val1 oper val2` com switch; `if (y == 0)` dentro do `case '/'`; aceitar `:` também
  como divisão (case sem break).
- **Exercícios:** peso ideal por sexo (homem 72.7·h − 58; mulher 62.1·h − 44.7) — com h = 1.80 → 72.86 e 67.08;
  "perfil" pela data de nascimento (13/06/1970 → 1306 + 1970 = 3276 → 32 + 76 = 108 → 108 % 5 = 3 → "Atraente").

### 0025-while
- **Exemplo ótimo:** exibir os dígitos de um número dividindo por 10 e imprimindo o resto: 8503 → 3 0 5 8 (ordem
  inversa — gancho para a versão recursiva que imprime na ordem certa).
- **Exercícios (com resposta):** dígito verificador de conta: soma dos dígitos % 10 → 7314 → 15 → **007314-5**
  (com `%06d`); número triangular (1, 3, 6, 10, 15...): 10 → sim, 11 → não.
- `while (1)` com saída interna (programa do "rastro" com teclas N/S/L/O e F para fim; usa `gotoxy`/`getch` —
  adaptar ou descartar).

### 0026-do-while
- Usa chaves sempre para não confundir `do { } while (c);` com um `while` vazio.
- **Exercícios bons:** menor e maior idade de uma série terminada em 0; caixa de loja com tabela de desconto (abaixo
  de 50 → 5%; até 100 → 10%; até 200 → 15%; acima de 200 → 20%); **extrato bancário com CPMF**: saldo inicial
  1000, operações −200, +50, −320, +100, −200, 0 → créditos 150.00, débitos 520.00, CPMF (0,35% dos débitos)
  1.04, saldo final 628.96 (resposta pronta na fonte).
- Bola de pingue-pongue quicando nas bordas (`kbhit`, `sound`) — ideia de animação, mas não portátil.

### 0027-for
- **Exemplos:** contagem 1..9; tabuada formatada `"%d x %2d = %3d"` (7 x 1 = 7 ... 7 x 10 = 70); tabela ASCII
  com pausa a cada 23 linhas; tabuleiro de xadrez n×n onde a cor depende de `(lin + col) % 2`.
- **Exercícios:** contagem regressiva; tabela polegadas→cm de 0 a 10 de meio em meio (1" ≈ 2,54 cm); potência
  `x^n` com laço; fatorial; **quadrado pela soma dos n primeiros ímpares** (4² = 1+3+5+7 = 16); n-ésimo Fibonacci;
  retângulo de m × n caracteres.

### 0028-break-continue
- **Exemplo MODELO (primo):** `for (k = 2; k <= n - 1; k++) if (n % k == 0) break; if (k == n) "primo"` — o teste
  depois do laço descobre **por que** o laço terminou (pela condição ou pelo `break`). Bom para explicar. Figura:
  para 7 é preciso testar todos os divisores; para 9 basta achar o 3.
- Pegadinhas da fonte: lê `%u` numa variável `int`; para n = 1 o laço não roda, k = 2 ≠ 1 → "não é primo" (por
  sorte correto); otimização possível: testar só até √n.

### 0030-padroes-de-laco
- Contador de linhas com reinício (`n == 23 → n = 0`), acumulador, sentinela (0 encerra), maior/menor, flag.

### 0031-aleatorios
- **Ideia didática ótima:** gerador caseiro com `static unsigned s = 1234; n = s % 100; s += s / 10;` → sementes
  1234, 1357, 1492, 1641, 1805... (números 34, 57, 92, 41...). Mostra que "aleatório" de computador é uma
  sequência determinística a partir de uma **semente**; mesma semente → mesma sequência; semente 0 trava em 0.
  Depois: semente com `time()`. Ponte perfeita para `rand`/`srand(time(NULL))`.
- `rand() % 100` → 0..99; `aleat() % 80 + 1` → 1..80 ("céu estrelado").

### 0033-funcoes / 0034-parametros
- **Conceitos-chave:** `tipo nome(parâmetros) { declarações comandos }`; `void` no retorno e/ou na lista;
  `x = alarme() + 3` e `alarme(5)` são erros de compilação quando a função é `void f(void)`; protótipo ("assinatura")
  = cabeçalho + `;`, necessário se a definição vier depois do uso; cada parâmetro precisa do próprio tipo; `return`
  devolve um único valor e encerra a função (`max` sem `else`: o 1º return impede o 2º).
- **Exemplos:** verificação de senha que dispara `alarme()`; `linha(x, y, c)`; `hip(a, b)` (falta um `)` na fonte —
  "ache o erro"); `max(a, b)` com dois `return`.
- **Exercícios ótimos (com resposta):** `fat(n)`; `pot(x, n)`; quadrado por soma de ímpares; raiz por Newton com
  tolerância 0,001 (`r = (r*r + n) / (2*r)`); pontos dentro/fora/sobre uma circunferência usando `dist`;
  **dígito verificador mod 11**: n = 345702159 → s = 3·10 + 4·9 + ... + 9·2 = 202; x = 11 − 202 % 11 = 11 − 4 = 7;
  dv = 7 (0 se x > 9) — a fonte escreve "201%11" por engano; **CPF**: 1º dígito dv(345702159) = 7, 2º dígito
  dv(3457021597) = 1 → 345702159-71; rodízio de placas por dia da semana.

### 0035-escopo
- Tabela resumo de classes: local/`auto` (escopo função, duração função), global/`extern` (programa, programa),
  `static` (escopo função, duração programa; inicializada uma única vez), `register` (pedido de registrador; hoje o
  compilador decide). Exemplo do gerador `aleat` mostra o `static` na prática.

### 0037-recursao
- **Explicação EXCELENTE:** recursão = resolver o problema supondo já resolvida uma instância menor (2¹¹ = 2 × 2¹⁰,
  "sabendo" que 2¹⁰ = 1024). Identificar **base** (caso trivial) e **passo** (como encolher o problema e montar a
  resposta). Recursão sem parada: `void loop(void) { printf("loop "); loop(); }`.
- **Três ferramentas de visualização:** (1) simulação por substituição: `pot(2,3) = 2*pot(2,2) = 2*2*pot(2,1) =
  2*2*2*pot(2,0) = 2*2*2*1 = 8`; (2) fluxo de chamadas e retornos (ovais com a operação pendente em cada seta);
  (3) **rastreamento automático**: passar a profundidade `p` e imprimir `p` espaços antes de "pot(2.0,5)" na ida e
  do resultado na volta — ótimo exercício para o 0036/0037.
- **ERRO na fonte (pegadinha excelente):** `double pot(double x, unsigned n) { if (n=0) return 1; return x *
  pot(x, n-1); }` — o `=` atribui 0, a condição é sempre falsa e a recursão nunca para (com unsigned, n−1 dá a
  volta para 4294967295). Junta 0020 e 0037.
- **Procedimentos recursivos:** `prog(n)`: base n = 0 nada; passo: `prog(n-1)` e depois imprime n → `prog(3)` =
  "1 2 3"; instruções pendentes ficam numa pilha — imprimir antes ou depois da chamada inverte a ordem.
- **Exercícios (com resposta esperada):** fatorial; resto por subtrações; quociente por subtrações; produto por
  somas; soma usando só `suc`/`pred`; `regr(n)` contagem regressiva; **`bin(n)`** imprime n em binário (13 →
  1101: `bin(n/2)` depois `printf("%d", n%2)`).

### 0040-preprocessador
- **Conceitos-chave:** `#define identificador texto` troca texto (pode até ser palavra reservada:
  `#define diga printf`, `#define oi "\nOlá"` → `diga(oi);`); macro com parâmetro **sem espaço** entre o nome e o `(`.
- **Pegadinhas MODELO (tabela pronta):** `#define quad(n) n*n`: `quad(x+4)` → `x+4*x+4`; `quad(2+3)` → 11 em vez de
  25; `100/quad(2)` → `100/2*2` = 100 em vez de 25. Correção: `#define quad(n) ((n)*(n))` (parênteses no parâmetro
  E na expressão inteira).
- `macros.h` com `quad`, `abs(n) ((n)<0 ? -(n) : (n))`, `max(x,y)`; `""` para arquivos do usuário, `<>` para os
  padrão; qualquer arquivo pode ser incluído.
- **Exercícios divertidos:** `#define` para compilar `programa inicio diga("Olá!"); fim`; macros
  `eh_minuscula(c)`, `maiuscula(c)`; criar `boolean.h` para que `bool(not false)`, `bool(false and true)`,
  `bool(true or false)` imprimam "true false true".
- Pegadinha extra para o curso: `max(i++, j)` avalia `i++` duas vezes.

### 0042-vetores
- **Conceitos-chave:** elementos do mesmo tipo em posições consecutivas, índice 0..n−1; índice pode ser qualquer
  expressão inteira: com i = 3, `v[i%3]` ≡ v[0], `v['B'-'A']` ≡ v[1], `v[i-1]` ≡ v[2]; `v[i/2.0]` → erro.
  Globais e estáticos começam zerados; inicialização parcial zera o resto; tamanho omitido é contado.
- **Pegadinha MODELO (sem verificação de limites):** `int x[3], y[4]; x[2] = y[0] = 1; x[3] = 2; y[-1] = 3;
  printf("%d %d", x[2], y[0]);` → no Turbo C imprimiu **3 2** (x[3] invade y[0] e y[−1] invade x[2]). Hoje o
  layout é outro (pode até inverter) — mas a lição é a mesma: comportamento indefinido.
- **ERRO na fonte:** com `static int A[5] = {9, 3, 2, 7}` diz que "A[4] e A[5] ficam zeradas" — A[5] nem existe
  (off-by-one no próprio texto).
- **Exercícios:** ler 5 números e imprimir em ordem inversa; desvio padrão; avaliar polinômio para vários x;
  cédulas mínimas (209 → 2×100, 1×5, 4×1); tocar uma melodia com pares (frequência, duração).
- Exercício 5.2 da fonte (atribuições encadeadas em `w[9]` com i = 5) usa `w[2]` sem inicializar — pegadinha:
  pergunte "qual o problema antes de calcular?".

### 0043-vetores-e-funcoes
- **Conceitos-chave:** o nome do vetor é o endereço (`%p` mostra x e y consecutivos: FFD0 e FFD6, diferença = 6 bytes
  = tamanho de x); passar vetor = passar endereço ("por referência"); no parâmetro `float t[]` o tamanho não é
  necessário (nada é copiado).
- **Exemplo de projeto top-down:** temperaturas da semana acima da média: `main` com `obtem(temp)`, `m = media(temp)`,
  `conta(temp, m)` — escrever o main primeiro, como se as funções existissem.
- **Exercícios:** `minimax(t, x, y)`; **histograma** de temperaturas (19, 21, 25, 22, 20, 17, 15) com uma barra por
  dia; versão vertical.

### 0044-matrizes
- Matriz = vetor de vetores (`int A[3][4]`); dois `for` aninhados geram as coordenadas [0][0]..[2][3]; só a 1ª
  dimensão pode ser omitida na inicialização.
- **Exemplos ótimos:** **labirinto** 10×10 de 0/1 inicializado e desenhado (`lab[i][j] ? '#' : ' '`); menu como
  matriz de char `{"abrir", "editar", "salvar", "sair"}`; tabuleiro de jogo da velha.
- **Exercícios-projeto:** diagonal principal; **campo minado** (matriz 10×10 com borda, 9 = bomba; contar bombas
  vizinhas; abrir posições; jogo completo); nomes com inicial maiúscula.
- Bug na fonte: `printf("[%d][%d]= ")` sem os argumentos i, j.

### 0045-caracteres / 0046-strings
- **Conceitos-chave:** string = sequência de chars terminada por `'\0'` (código 0 — não confundir com `'0'`, código
  48); vetor precisa de uma posição a mais; `sizeof("verde e amarelo")` = **16** (15 letras + `'\0'`) — prova
  prática ótima.
- **Pegadinha MODELO:** `char y[] = {'d','o','i','s'};` não tem `'\0'` → `printf("%s", y)` imprime "dois" seguido de
  lixo até achar um zero.
- **Pegadinha MODELO:** `x == y` com duas strings "um" dá **falso** — compara endereços; usar `strcmp`. Regra:
  `strcmp(x, y) ◊ 0` equivale a `x ◊ y` para qualquer relacional ◊ (`"Ana" >= "Bia"` vira
  `strcmp("Ana","Bia") >= 0`). Tabela pronta: "um" < "dois"? F; "um" > "dois"? V; "dois" ≤ "um"? V.
- **Implementação curta de strcmp:** avança enquanto iguais e ≠ `'\0'`; devolve `s[i] - t[i]`.
- **Exercícios (implementar):** `strcpy`, `strlen`, `strupr` ("Teste" → "TESTE"), `strcat` ("facil" + "idade" =
  "facilidade"), `strpos(s, c)` (−1 se não houver), `strdel(s, p)`, `strins(s, c, p)`; **cadeia de Freeman**
  (perímetro com diagonais valendo 1.42).

### 0047-lendo-strings
- Usa `gets(n)` com `char n[21]` (o Enter vira `'\0'`) — trocar por `fgets` no curso.

### 0049-memoria / 0050-ponteiros
- **Analogia ótima:** `*p` = "**siga a seta** em p"; desenhar setas; quantos `*` = quantas setas
  (`**p` = siga duas setas). Nome de vetor e nome de função são ponteiros **constantes** (um para dados, outro para
  código); `&v` é ponteiro constante.
- **Pegadinha MODELO (tipos incompatíveis):** `int v = 0x4142; char *a; int *b; long *c; a = b = c = &v;
  printf("%c %x %lx", *a, *b, *c);` → só `b` lê certo; `a` lê metade (1 byte) e `c` lê lixo junto. A quantidade
  de memória lida depende do tipo do PONTEIRO, não da variável.
- **Exercício-pegadinha (resposta):** `int *p, x = 5; *p *= 2**p; printf("%d", x);` — explicar cada `*` (declaração,
  dereferência, multiplicação, dereferência) e perceber que `p` não foi inicializado → comportamento indefinido; com
  `p = &x` antes, x vira 5 × (2 × 5) = 50.

### 0051-passagem-por-referencia
- `perm(int p, int q)` falha (3 7 continua 3 7, com figura dos parâmetros como cópias); `permuta(int *p, int *q)`
  com `permuta(&a, &b)` → 7 3. **Exercício:** o que acontece se esquecer o `&` na chamada? (passa os valores 3 e 7
  como se fossem endereços → acesso inválido).
- **Exercício:** `minimax(v, n, &a, &b)`.

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** `v[i]` ≡ `*(v + i)`; somar i a um ponteiro de tipo t avança `i * sizeof(t)` bytes.
- **Exemplo MODELO ("1000 + 1 não é 1001"):** ponteiros `char*`, `int*`, `float*`, `double*` todos em 0x1000;
  `+1` dá 1001, 1002, 1004, 1008 (no Turbo C; hoje int = 4: 1001, 1004, 1004, 1008).
- **Exercício pronto:** `int *p = (int*)0x1000; p++; p -= 3; p += 2; p--;` → 1002, 0FFC, 1000, 0FFE (int de 2
  bytes; refazer com 4).
- Subtração de ponteiros = nº de elementos entre eles → `strlen` com dois ponteiros. Implementar `puts` e
  `carrega(v, n)` com notação de ponteiro.

### 0053-ponteiros-e-strings
- **Comparação ótima (com figura):** `char matcar[3][8] = {"azul","verde","amarelo"}` (cada linha do tamanho da maior
  → desperdício) × `char *vetpnt[3] = {...}` (strings contíguas + vetor de endereços; custa os ponteiros).
  Exercício: para guardar n nomes lidos do teclado, qual é melhor? (matriz, ou ponteiros com malloc — literal não
  serve para receber leitura).
- `dia_semana(n)` devolve ponteiro para string de um vetor `static` (índice 0 = "erro"): retornar ponteiro para algo
  que sobrevive à função (contraste: retornar endereço de local é erro).
- **Exercícios:** `strchr`, `strsub(s, i, n)`, `monet(1234.56)` → "R$ 1.234,56".

### 0054-ponteiro-para-ponteiro
- `char v = 'A'; char *q = &v; char **p = &q;` → v ≡ `*q` ≡ `**p`. Uso típico: passar um ponteiro por referência
  (ver lista encadeada). Exercício: cadeia p → q → r → s → t → 'A' e imprimir 'A' por cada uma.

### 0055-ponteiro-para-funcao
- **Conceitos-chave:** `t (*f)(t1, t2)`; nome da função = endereço; ponteiro de função só recebe endereço e chama
  (não se incrementa); `()` é o operador de chamada.
- **Exemplos MODELO:** `double (*p)(double) = sqrt; p(25)` → 5.0; **menu com vetor de funções**
  `void (*f[])(void) = {abrir, editar, salvar, fechar}; f[i]();`; **eliminar código duplicado**: `min` e `max`
  idênticos exceto pela comparação → `minmax(v, n, cmp)` com `menor`/`maior` — w = {78, 34, 12, 45, 51} → 12 e 78.
- **Exercício:** ordenar vetor de structs por cada campo com `qsort` (comparador recebe `const void *`).
- Bug na fonte: o menu testa `op != 3` mas a variável lida é `i`.

### 0056-void-generico
- `void *` aceita qualquer endereço mas não pode ser dereferenciado sem cast; `malloc` devolve `void *`.

### 0059-malloc-free
- **Conceitos-chave:** `malloc(bytes)` pega memória livre após o programa; devolve NULL se não houver; usar `sizeof`
  porque o tamanho do int varia; `free(p)`; ao terminar o programa tudo é liberado (mas libere você mesmo).
- **ERROS na fonte (ótimo "ache o erro"):** no vetor dinâmico: `if (v !== NULL) exit(1);` (operador inexistente e
  lógica invertida); `printf("\n%do. Valor? ")` sem argumento; e o laço `while (i >= 0) printf("%d ", v[--i]);`
  acessa `v[-1]` na última volta.
- **Exemplo:** vetor de 3 ponteiros para `funcionario` alocados um a um (`f[i] = malloc(sizeof(funcionario))`,
  `f[i]->salario`); exercício: alocar também o vetor (`funcionario **f`).

### 0064-struct / 0065-typedef / 0066-vetor-de-structs / 0067-ponteiro-para-struct
- **Conceitos-chave:** struct anônima (não dá para declarar outras variáveis do tipo) → struct com rótulo
  (`struct data hoje;`) → `typedef struct data {...} DATA;` → `typedef struct {...} DATA;` (só se não for
  recursiva). Inicialização na ordem `{19, 7, 2000}`; aninhamento (`PESSOA` com `DATA nasc`;
  `amigo.nasc.dia`; `amigo.dia` é erro); chaves extras na inicialização aninhada; vetor de structs = **tabela**
  (linhas = registros, colunas = campos); `agenda[1].nome[6] = 'o'`. `(*p).nome` exige parênteses (`.` > `*`);
  `p->nome`; passar ponteiro por eficiência.
- **Erro na fonte:** `typedef struct data {...};` sem nome no final (typedef inútil).
- **Exercícios:** livro (título, autor, editora, ano); complexos com soma; ponto e distância; horário "99:99:99";
  voo; segmento de reta usando struct ponto; agenda com busca de telefone.

### 0068-enum / 0069-union
- **Union:** todos os membros no mesmo endereço; tamanho = maior membro; só um válido por vez ("tipo mutante").
  **Union etiquetada** (struct com `etiqueta` + union) + `switch` na etiqueta para imprimir — padrão importante.
  Exercício: figura geométrica polimórfica (retângulo/círculo) com função de área.
- **Erro na fonte (pegadinha):** "para usar o membro inteiro: `m.etiqueta = 2; m.valor.a = 459;`" — grava no
  membro `a` (char) e não no `b`.
- **Erro na fonte:** no exercício do registrador AX, diz que AX = 0x1234 dá AH = 0x34 e AL = 0x12 (é o contrário:
  AH = 0x12 alto, AL = 0x34 baixo) — mas a união que o aluno escrever revela a ordem dos bytes (endianness) — bom
  gancho.

### 0070-bits
- **Campos de bits (tabela pronta):** `unsigned a:1; signed b:3; unsigned c:3;` → faixas 0..1, −4..3, 0..7;
  inicializar com 14 (1110) → **0 −2 6**; com {0, −4, 7}, `++a, --b, ++c` → **1 3 0** (estouro dá a volta;
  complemento de dois explicado). Restrições: sem `&`, sem vetor de campos, ordem depende da máquina.
- **Ideias de exemplo:** byte de status da impressora; **data compactada do DOS em 16 bits** (dia 5 bits, mês 4,
  ano 7 a partir de 1980 → funciona até 2107; nº de bits ≈ log₂ da quantidade de valores: 31 dias → 5 bits).
- `~` (negação bit a bit) e `^` (XOR) na criptografia (ver 0073).

### 0074-argumentos
- `COPY A.TXT A.BAK` → argc = 3; `ECO UM DOIS TRES` imprime cada palavra (i começa em 1 para pular argv[0]);
  **gráfico de barras** `GRAFICO 5 6 9 7 4` com `atoi(argv[i])` asteriscos; exercícios `CALC 2 + 3` com `atof`,
  cronômetro regressivo.

### 0072-arquivos-texto
- **Conceitos-chave:** arquivo = coleção em disco que persiste entre execuções; disco é lento → **buffer** (figura);
  `FILE *` é só um ponteiro (estrutura e buffer alocados no `fopen`); arquivos padrão `stdin`, `stdout`, `stderr`
  (+ `stdaux`, `stdprn` no DOS); `printf(...)` ≡ `fprintf(stdout, ...)`; abrir com teste de NULL embutido no if;
  fechar descarrega o buffer e libera a conexão.
- **Exemplo MODELO:** `cat` em 4 linhas com `int c; while ((c = getchar()) != EOF) putchar(c);` — explicação ótima de
  por que `c` é `int` (256 caracteres + EOF = 257 valores). **Redirecionamento** `cat > arq.txt` (cria arquivo) e
  `cat < arq.txt` (lê) — ensina E/S de arquivo sem nenhuma função nova.
- **Padrão de leitura correto da fonte:** ler (`c = fgetc(e)`), **depois** testar `feof(e)`, só então usar.
- **Exercício:** concurso: arquivo `cand.dat` com "125 acbde", "493 cdeaa", "384 deabc", "981 cadce", "394 bbced" e
  gabarito "abcde" → pontos 3, 0, 0, 1, 2 (resposta pronta).
- Converter texto para maiúsculas/minúsculas conforme `+`/`-` na linha de comando.

### 0073-arquivos-binarios
- **Texto × binário (explicação boa):** números gravados como texto (legível, maior) × como na memória (compacto);
  `'\n'` ↔ CR/LF só no modo texto (Windows); `^Z` como fim no modo texto (DOS). Modos "rb"/"wb".
- **Exemplos:** cadastro de funcionários com `fwrite(&f, sizeof(Func), 1, s)` até digitar "." e listagem com `fread`
  + `feof`; **criptografia ingênua** com `~c` ('S' 01010011 → 10101100) e exercício de **criptografia com senha por
  XOR** (`c = m ^ s`, `m = c ^ s`, senha usada ciclicamente — prova pelas propriedades x^0 = x, x^x = 0).
- Exercícios: ordenar o cadastro; buscar salário por nome com busca linear e binária direto no arquivo
  (`fseek`, `ftell`).
- Bug: `stcmp` (falta o r de `strcmp`).

### 0076-eficiencia / 0077-big-o
- **Busca linear:** em média ½(n+1) comparações; pior caso n → O(n) ("dobrar a lista dobra o tempo").
- **Busca binária:** 5000 itens → 5000, 2500, 1250, 625, 312, 156, 78, 39, 19, 9, 4, 2, 1, 0 → no máximo **13
  comparações**; recorrência C(n) = 1 + C(n/2), C(1) = 1 → ⌊lg n⌋ + 1 → O(lg n). Tabela linear × binária até
  n = 1 048 576 (1 048 576 × 20). Ótima para 0077.
- Ordenações: bolha e seleção sempre ½(n² − n) comparações; seleção faz no máximo n − 1 trocas (O(n)) contra O(n²)
  da bolha; inserção varia de n − 1 (já ordenado) a ½(n² − n) (ordem decrescente).
- **Exercício:** cronometrar os três métodos com `clock()` para tamanhos crescentes e tabular.

### 0094-busca-sequencial
- `pertence(x, L, n)` devolve 1/0; técnica da **sentinela** (pôr x numa posição extra no fim para eliminar o teste
  `i < n`); lista de convidados (vetor de strings).

### 0095-busca-binaria
- **Analogia:** procurar palavra no dicionário abrindo no meio. **Traços prontos:** x = 63 em ⟨14, 27, 39, 46, 55,
  63, 71, 80, 92⟩: (i,f,m) = (0,8,4) → (5,8,6) → (5,5,5) achou; x = 40: (0,8,4) → (0,3,1) → (2,3,2) → (3,3,3) →
  (3,2) i > f, não achou. Meio = `(i + f) / 2` truncado.
- **Exercícios:** simular para 33, 50, 77, 90, 99 numa lista de 18 itens; adaptar para vetor decrescente.

### 0096-bubble-sort
- **Analogia:** os pesados descem como pedras, os leves sobem como bolhas. Traço de uma passada em
  71 63 46 80 39 92 55 14 27 (o 92 vai para o fim) e ordenação completa de 46 39 55 14 27 com fases i e pares j.
  Código `for (i = 1; i < n; i++) for (j = 0; j < n - i; j++) if (v[j] > v[j+1]) troca`.
- **Exercícios:** simular com 92 80 71 63 55 41 39 27 14 (pior caso); versão decrescente.

### 0097-selection-sort
- **Traço pronto:** 46 55 59 14 38 27 → fase 1 (k=3): 14 55 59 46 38 27 → fase 2 (k=5): 14 27 59 46 38 55 →
  fase 3 (k=4): 14 27 38 46 59 55 → fase 4 (k=3, sem troca) → fase 5 (k=5): 14 27 38 46 55 59. Função auxiliar
  `selmin(v, i, n)` com traço de k e j.
- **Exercícios:** simular com 82 50 71 63 85 43 39 97 14; embutir `selmin`; ordenar vetor de strings.

### 0098-insertion-sort
- **Traço pronto:** 34 17 68 29 50 47 → 17 34 68 29 50 47 → (igual) → 17 29 34 68 50 47 → 17 29 34 50 68 47 →
  17 29 34 47 50 68. Código com `x = v[i]` e deslocamento `for (j = i-1; j >= 0 && x < v[j]; j--) v[j+1] = v[j];`.

### 0101-comparando
- **Estabilidade (explicação e exemplo prontos):** ordenar ⟨(c,2), (a,2), (b,3), (c,1), (a,3), (a,1), (c,3), (b,2)⟩
  primeiro pelo 2º campo e depois, com inserção (estável), pelo 1º → resultado ordenado pelos dois campos.
  Exercício: repetir com seleção e verificar que ela NÃO é estável.
- `qsort` da biblioteca com comparador.

### 0081-lista-encadeada / 0082-lista-busca-remocao
- **Conceitos-chave:** nó = (item, prox); lista = ponteiro para nó; definição **recursiva** (base: lista vazia =
  NULL); só o primeiro nó é acessível diretamente. `typedef struct no { char item; struct no *prox; } *lista;`
  (typedef de ponteiro — discutir: esconder o `*` confunde iniciantes).
- **Operações:** `insere(lista *p, char x)` no início (aloca, `n->prox = *p; *p = n;` — a lista é passada por
  referência, daí `lista *` = ponteiro para ponteiro); inserir 'a', 'b', 'c' gera ⟨c, b, a⟩ (ordem inversa);
  `remove(lista *p)` do início; `acessa(p, i)` ao i-ésimo; inserir na 3ª posição com `insere(&acessa(L,2)->prox,
  '*')`; remover o 4º com `remove(&acessa(L,3)->prox)`.
- **Pegadinha não apontada:** chamar a função de `remove` colide com `remove()` de `<stdio.h>` (apagar arquivo) —
  renomear (`remove_inicio`). E `acessa` com posição inválida devolve NULL → `->prox` em NULL quebra.
- **Exercícios:** remover devolvendo o item; `destroi(x)` liberando todos os nós; `concatena(x, y)`.
- **Tratamento recursivo:** macros `cabeca(p)` e `cauda(p)`; `comprimento(L) = L == NULL ? 0 : 1 +
  comprimento(cauda(L))` (⟨a,b,c⟩ → 1+1+1+0 = 3); `n_esimo(L, n)` (⟨a,b,c,d,e⟩, 4 → d; lista vazia não é caso base
  → `assert`); `maximo(L)` (⟨d,b,e,a,c⟩ → e, com a expansão completa). Exercícios: último item, pertence,
  ocorrências, soma, listas iguais; exibir, exibir invertido, inserir/remover em lista ordenada, liberar tudo.

---

## Obsoleto / evitar
| Na fonte | Problema | Alternativa em C padrão |
|---|---|---|
| `main()` / `void main(void)` | não padrão | `int main(void)` + `return 0;` |
| `conio.h`: `clrscr`, `getch`, `putch`, `gotoxy`, `textcolor`, `cprintf`, `kbhit` | DOS/Borland | `printf`/`putchar`/`getchar`; sem limpar tela; ANSI escape ou ncurses se indispensável |
| `sound`, `nosound`, `delay`, `sleep` (`dos.h`) | DOS | `\a`; `sleep()` do POSIX (`unistd.h`) |
| `random`, `randomize` | Borland | `rand() % n`, `srand(time(NULL))` |
| `alloc.h` | Borland | `stdlib.h` |
| `gets` | removida no C11 | `fgets` |
| `biosprint`, `_chmod`, `findfirst/findnext`, `dir.h`, `bios.h` | DOS | fora do escopo (POSIX `stat`, `opendir`) |
| `fcloseall()` | não padrão | `fclose` em cada arquivo |
| `stdaux`, `stdprn` | DOS | só `stdin/stdout/stderr` |
| `^Z` como fim de arquivo, CR/LF | DOS/Windows | Linux: Ctrl-D; `\n` puro |
| caracteres 219, 196, 01 da tabela estendida | não portáteis | `'#'`, `'-'`, `'o'` ou UTF-8 |
| `int` de 2 bytes, endereços FFD0 | Turbo C 16 bits | `sizeof`, `%p` mostra endereços de 64 bits |
| `char c = fgetc(...)` (na criptografia) | perde EOF em alguns casos | `int c` |
| `long float` | arcaico | `double` |

## Extras que não cabem no sumário
- Campos de bits com hardware (status de impressora) e datas compactadas — curiosidade de baixo nível.
- Cadeia de Freeman (visão computacional), campo minado, labirinto, jogo da velha — bons projetos de matriz.
- Dígito verificador mod 11 e CPF — exercício realista de laço + funções.
- Criptografia por complemento (`~`) e por XOR com senha — reforça 0070 e 0073.
- Rastreamento automático de recursão com indentação por profundidade — técnica de depuração.
- Redirecionamento de E/S (`<`, `>`) como primeiro contato com arquivos.
