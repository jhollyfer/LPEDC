# Fichamento — SENAI-RS: "Fundamentos de Linguagem C"

- **Título:** Fundamentos de Linguagem C ("Tudo que você precisa saber sobre C para não passar vergonha!")
- **Autor:** Adalberto A. Dornelles F. — Centro Tecnológico de Mecatrônica, SENAI-RS, Caxias do Sul, nov./1997.
- **Arquivo lido:** `2948665d-apostila_C.md` (2967 linhas, lido por completo).
- **Avaliação geral:** apostila curta e didática, com boa progressão (constantes → operadores → E/S →
  controle → funções → vetores → ponteiros) e uma lista final de exercícios muito boa (jogo de adivinhação,
  número por extenso, Morse, 8 damas, calculadora RPN, jogo "Reverse"). Porém é **muito datada**: Turbo C++
  3.0/DOS, `int` de 2 bytes, `void main`, `conio.h`, `dos.h`, `alloc.h`, `random()`. Contém **vários erros
  factuais** (listados abaixo) que servem, ao contrário, como material de "ache o erro". Não cobre structs,
  arquivos, nem estruturas de dados.

---

### 0001-algoritmo
- **Conceitos-chave:** programa = conjunto de instruções que representa um algoritmo; linguagem = símbolos +
  regras de sintaxe. Linguagens de baixo nível (Assembly: rápido, compacto, pouco portátil) × alto nível
  (legível, portátil, precisa de compilador/interpretador). Interpretador executa instrução a instrução;
  compilador traduz tudo e gera executável.
- **Boa ideia didática:** mostrar o MESMO algoritmo (tabuada de um número) em pseudocódigo, C, BASIC,
  Fortran e Assembly 8088, lado a lado — evidencia que o algoritmo é independente da linguagem.
- **Ideia de exemplo:** tabuada do `num` lido, de 1 a 10, nas várias "línguas".

### 0002-pseudocodigo
- **Conceitos-chave:** tabela de correspondência pseudocódigo ↔ C: `se/então/senão/fim se` ↔ `if/else`;
  `faça ... até condição` ↔ `do { } while (condição)` (atenção: "até" inverte a condição!); `←` ↔ `=`.
- **Pegadinha:** o "repita... até X" do Portugol termina quando X fica verdadeiro; o `do...while(X)` do C
  continua enquanto X é verdadeiro. A apostila coloca lado a lado sem alertar — bom ponto para o curso.

### 0003-fluxograma
- Fluxogramas simples de `do...while`, `while`, `if`, `if-else`, `else if` encadeado e `switch` (rótulos
  em cascata, mostrando visualmente o fall-through). Útil como modelo de figuras.

### 0004-binario
- **Conceitos-chave:** constantes inteiras em decimal, octal (começa com `0`) e hexadecimal (`0x`).
  ASCII: códigos 0–31 controle, 32–127 padrão, 128–255 estendido (depende do fabricante).
- **Pegadinhas:** `045` NÃO é quarenta e cinco: é octal (= 37). `01784` é inválido (8 não é dígito octal).
  `0x ff` (com espaço) e `FFEE` (sem `0x`) não são hexadecimais.
- **Exercício:** classificar constantes como válidas/inválidas e em qual base: `0`, `-45`, `045`, `0x4f5a`,
  `0Xfg34`, `01784`, `1,2`. (Resp.: dec, dec, octal=37, hex=20314, inválida, inválida, inválida.)

### 0005-compilacao
- Diretivas são processadas antes da compilação; `#include` anexa arquivos; `#define` cria constantes
  simbólicas. Programa = cabeçalho com diretivas + bloco principal + rotinas + comentários.

### 0006-primeiro-programa
- **Conceitos-chave:** estrutura geral; comentários `/* */` e `//` (a apostila diz que `//` é "só C++" —
  hoje é C padrão desde C99).
- **Conjunto de caracteres:** acentos e `@`, `$` só valem dentro de strings/char, não em identificadores.

### 0007-variaveis
- **Conceitos-chave:** declarar = informar nome e tipo para o processador reservar espaço; várias
  variáveis separadas por vírgula; inicialização na declaração; locais (dentro da rotina) × globais.
  Regras de identificadores (letra ou `_` no início; letras, dígitos e `_`; maiúsculas ≠ minúsculas).
  Palavras reservadas (inclui lixo de C++/Borland: `near`, `far`, `huge`, `class`, `new`...).
- **Analogia boa:** a variável tem nome, tipo, tamanho do bloco, valor e endereço do primeiro byte
  (exemplo `int num = 17` decomposto nesses 5 atributos — ótimo para 0007 e 0049).
- **Exercício:** quais nomes são válidos? `abc`, `y24`, `nota_1`, `3dia`, `vetor-1`, `pao&leite`,
  `iteração`, `do`, `new`. (Válidos: abc, y24, nota_1, new — em C, `new` NÃO é reservada; `do` é.)
- **Exercício divertido:** "posso declarar `int do, re, mi, fa, sol, la, si;`?" (Não: `do` é reservada.)

### 0008-tipos-e-limites
- **Conceitos-chave:** `char` 1 byte, `int` 2 bytes (Turbo C!), `float` 4 (~7 dígitos), `double` 8
  (~15 dígitos); modificadores `long` e `unsigned` (o bit de sinal passa a guardar valor → dobra a faixa
  positiva). `limits.h` com `INT_MAX`/`INT_MIN`.
- **Pegadinha (overflow):** com `int` de 16 bits, `5000 + 30000` vira `-30536` sem nenhum aviso. Adaptar ao
  `int` de 32 bits: `2147483647 + 1`. Em C, estourar a faixa não é tratado como erro (e em `signed` é
  comportamento indefinido — a apostila não diz isso).
- **Atualizar no curso:** tamanhos dependem da plataforma; hoje `int` costuma ter 4 bytes; usar `sizeof`.

### 0009-constantes
- **Conceitos-chave:** 4 tipos de constantes: inteiras, ponto flutuante, caractere (aspas simples), string
  (aspas duplas). Real exige ponto (não vírgula) e aceita notação científica (`1.23e4`). O número 314 pode
  ser escrito `314.`, `3.14e2`, `31.4e1`, `.314E+3`... Tabela de sequências de escape (`\0 \a \b \t \n \v
  \f \r \" \' \? \\`).
- `#define NOME valor` sem `;`, por convenção em maiúsculas; o pré-processador troca o texto.
  Constantes pré-definidas: `M_PI` em `math.h` (não é padrão ISO; em gcc precisa de `_DEFAULT_SOURCE` ou
  POSIX).
- **Argumento (discutível) da apostila:** `#define PI` seria melhor que `float pi` porque não ocupa memória.
  No curso: comparar com `const double PI` (tem tipo, respeita escopo, aparece no depurador).
- **Exercício:** escrever 314 de 5 formas diferentes como literal real.

### 0010-printf
- **Conceitos-chave:** `printf` devolve o nº de caracteres impressos; string de controle = máscara;
  um especificador por argumento; formato `%[flag][largura][.precisão]tipo`; flags `-` (alinha à esquerda),
  `+` (sempre sinal), espaço; `0n` completa com zeros; tipos `d o x f e c s`.
- **ERRO da apostila (bom para "ache o erro"):** usa `"%f.2"` achando que dá 2 casas — imprime o número com
  6 casas seguido do texto ".2". O correto é `%.2f`.
- **Ideia de exemplo:** recibo de troco: total 12.30, dinheiro 15.00, troco 2.70 com `%.2f`.

### 0011-scanf
- **Conceitos-chave:** `scanf` recebe ENDEREÇOS; variável simples leva `&`, vetor/string não. Formato
  `%[*][largura]tipo`; `*` lê e descarta o campo; largura limita caracteres lidos.
- `getchar()` é *line buffered*: nada chega ao programa até o Enter; os caracteres extras ficam no buffer
  e são consumidos pelas próximas chamadas (ótimo gancho para "sobra no buffer").
- **Ideia de exercício:** ler 2 reais e imprimir a média (Ex. 4.1); ler graus e imprimir seno, cosseno e
  tangente (lembrar de converter para radianos); volume da esfera `4/3·π·R³` (pegadinha: `4/3` inteiro = 1).

### 0012-aritmetica
- **Conceitos-chave:** `+ - * / %`; `%` só com inteiros; divisão por zero = erro em tempo de execução;
  não há operador de potência (usar `pow`). Precedência `* / %` antes de `+ -`, esquerda para direita;
  parênteses quebram a ordem.
- **Tabela ótima para exercício (mesmos operadores, valores diferentes por causa de parênteses):**
  `1+2-3`=0; `24-3*5`=9; `4-2*6/4+1`=2; `6/2+11%3*4`=11 ×
  `1+(2-3)`=0; `(24-3)*5`=105; `(4-2*6)/4+1`=-1; `6/((2+11)%3)*4`=24.
- **Pegadinha:** `7/2` = 3, mas `7.0/2`, `7/2.0` = 3.5 (tabela com num_i, den_i, num_f, den_f).
- **Pegadinha:** `6.4 % 3` não compila; usar `(int)valor % 2` ou `fmod`.

### 0013-conversao
- **Conceitos-chave:** em atribuição, o valor da direita é convertido para o tipo da esquerda; conversões
  "perigosas" quando o destino é menor (`double → float → int → char`) e o compilador não avisa.
  Em expressões, o menor tipo é promovido (`char → int → float → double`). C tem tipos "macios".
  Cast `(tipo)expr` muda o DADO momentaneamente, não a variável.
- **Pegadinha:** `int i; float r = 654.321; i = r;` → i = 654 (trunca, não arredonda).
- **Exemplo:** `'A' + 1` é `'B'`; `'A' + 32` é `'a'` (gancho para 0045).

### 0014-atribuicao
- **Conceitos-chave:** `=` não é igualdade matemática; lado esquerdo tem de ser variável (`1 = a` e
  `b + 1 = a` são inválidos). Atribuição múltipla `i = j = k = 1` da direita para a esquerda.
  `+= -= *= /= %=`, com a regra `num *= 1 + k` ≡ `num = num * (1 + k)` (parênteses implícitos!).
- **Exercício de pré/pós (resposta pronta):** `int a,b,c,i=3; a=i++; b=++i; c=--i;` → a=3, b=5, c=4, i=4.
- **Exercício:** reescrever `num *= 1 + k` sem o operador composto (pegadinha dos parênteses).

### 0015-math
- **Conceitos-chave:** `abs`, `fabs`, trigonométricas em radianos, `ceil`, `floor`, `log` (natural),
  `log10`, `pow`, `sqrt`. Protótipo como "contrato": `double cos(double)`.
- **ERRO da apostila:** exemplos trocados — diz `ceil(3.2) == 3.0` e `floor(3.2) == 4.0`. Correto: ceil=4.0,
  floor=3.0. Ótimo para "ache o erro". (Também: `abs` está em `stdlib.h`, não em `math.h`.)
- **Exercício (6.1):** função de arredondamento: 5.4 → 5, 6.5 → 7 (hoje existe `round`).

### 0016-juntando-tudo
- Ideias: calcular raiz quadrada pelo método de Newton; épsilon da máquina (`eps=1.0; while(1.0+eps>1.0)
  eps/=2;`) — exemplo excelente e curto de `while` com reais.

### 0017-relacionais
- **Conceitos-chave:** 6 operadores; em C (antigo) não há tipo lógico: verdadeiro vale 1, falso 0; qualquer
  valor ≠ 0 é verdadeiro (inclusive 0.4 e -5.2). Precedência: aritméticos > `< > <= >=` > `== !=`.
- **Exercício (resposta pronta):** com `i=5, j=-3, r=7.3, s=1.7`: `i==7`→0, `r!=s`→1, `i>r`→0, `6>=i`→1,
  `i<j`→0, `s<=5.9`→1. Com `m=4, n=1`: `m+n==5`→1; `m != 2*n > m`→1; `6>=n<3-m`→0; `m==n<=m>m`→0.
- **Tabela (i=0, j=3):** `(i==0)`→1 verdadeiro; `(i>j)`→0; `(i)`→0 falso; `(j)`→3 verdadeiro.

### 0018-logicos
- **Conceitos-chave:** `&& || !` = AND, OR, NOT; tabelas-verdade; `&&` tem precedência sobre `||`; ambos
  abaixo dos relacionais; `!` no nível dos unários.
- **Exercício (a=0,b=1,c=2):** `a&&b`→0; `c>b||a<c`→1; `a+b && !c-b`→1; `!b && c || a`→0.
- **Lacuna:** não fala de curto-circuito — complementar com outra fonte.

### 0019-if / 0020-if-else / 0021-else-if
- **Conceitos-chave:** condição de controle é qualquer expressão numérica (0 falso, resto verdadeiro); if de
  um bloco, de dois blocos e cadeia `else if` (só um bloco executa; o `else` final é o "nenhuma das
  anteriores"). Alerta de não confundir `=` com `==`.
- **Ideias de exemplo:** limitar número de repetições a 10 (`if (iter > 10) iter = 10;`); tipo de raízes da
  equação do 2º grau (delta >0, =0, <0); positivo/negativo/nulo.
- **Exercícios:** maior valor absoluto entre 3 números (5.1); triângulo: 0 não forma, 1 escaleno,
  2 isósceles, 3 equilátero (6.4).

### 0022-ternario
- **Conceitos-chave:** `cond ? e1 : e2`, precedência só acima das atribuições.
- **Exercício (i=1,j=2,k=3):** `i ? j : k`→2; `j>i ? ++k : --k`→4; `k==i && k!=j ? i+j : i-j`→-1;
  `i>k ? i : k`→3.

### 0023-switch
- **Conceitos-chave:** expressão inteira, rótulos constantes inteiros distintos; execução começa no rótulo e
  segue para baixo; `default` opcional. Usa o fall-through **de propósito**: estágios de usinagem
  (desbaste grosso → fino → acabamento → polimento) — começar no estágio N executa todos os seguintes.
  Ótima analogia para ensinar que fall-through pode ser útil.
- **ERRO da apostila:** o exemplo "switch com break" da pizza (M/C/A) não tem nenhum `break` — escolher
  muçarela prepara as três pizzas e ainda imprime "Opção incorreta". Excelente para "ache o erro".
- **Ideia de exemplo:** valor de um lanche escolhido no cardápio; "piano" no teclado.

### 0025-while / 0026-do-while / 0027-for
- **Conceitos-chave:** `do...while` executa ao menos uma vez (validação: repetir enquanto número ≤ 0);
  `while` pode executar zero vezes; `for(init; cond; incr)` com várias expressões separadas por vírgula
  (`for(i=0, j=10; i<10; i++, j--)`), mas uma só condição. Equivalência `for` ↔ `do...while`
  (a apostila erra: só são equivalentes se a condição for verdadeira na entrada).
- **Ideias:** fatorial com `do...while`; amplitude (maior − menor) de um conjunto com `for`; imprimir
  1..10.

### 0028-break-continue
- **Conceitos-chave:** média de valores até ler um negativo, resolvida de 4 maneiras: `do...while(1)` com
  `break`; sem `break` (condição repetida); com `continue`; com `goto`; e com `exit(0)`. Excelente para
  discutir estilo e mostrar que todas funcionam, mas a versão estruturada é a mais legível.
- **Pegadinha:** dividir `soma/num` quando nenhum valor válido foi lido → divisão por zero.

### 0030-padroes-de-laco
- Sentinela (valor negativo encerra), contador (`num++`), acumulador (`soma += val`), maior/menor
  (amplitude). Exercícios: ímpares em [a,b] (5.4); 10 primeiros primos (5.3); N primeiros Fibonacci (5.7).

### 0031-aleatorios
- Usa `random(num)` (Turbo C, não padrão). Ideia boa: **jogo de adivinhação 1–100** que informa o novo
  intervalo a cada palpite e conta tentativas (5.12): "entre 1 e 100" → palpite 45 → "entre 1 e 44" →
  27 → "entre 28 e 44" → 36 → acertou em 3. Também o algoritmo de embaralhar (Fisher-Yates) do Ex. 7.11:
  para i de n-1 até 0, j aleatório em [0,i], troca v[i] e v[j] (baralho).

### 0033-funcoes / 0034-parametros
- **Conceitos-chave:** definição = tipo de retorno + nome + lista de parâmetros + bloco; `return` dá o fim
  lógico e o valor; só um valor de retorno (contornável com ponteiros); sem tipo declarado o compilador
  antigo assume `int`; função após `main` exige protótipo (pode conter só os tipos). Parâmetros formais
  são locais: passagem por valor, a função recebe cópia.
- **Ideia de exemplo:** `media2(float a, float b)`; `max(a,b)`; "hierarquia de funções" de um jogo de
  jackpot (main → regras, abertura, sorte, saída, simnao...).
- **Exercícios:** `sim_nao()` que devolve 1/0; `primo(N)`; `fib(n)`; média aritmético-geométrica de 4 e 7
  ≈ 5.5932 (while a<b).
- **Prática ruim da apostila:** `#include "c:\tc\userbib\stat.h"` contendo definições de funções; nomear
  arquivo com várias funções como `.h`. No curso (0039): `.h` só com protótipos, `.c` com definições.

### 0035-escopo
- Local (criada ao entrar no bloco, destruída ao sair; mesmo nome em funções diferentes = variáveis
  diferentes), formal (parâmetro) e global (vive o programa todo). Exemplo de `media2` usando globais
  `a, b, med` — bom para mostrar por que globais acoplam o código.

### 0037-recursao / 0038-recursao-na-pratica
- Fatorial via `n! = n·(n-1)!`; cada chamada cria novo conjunto de locais; recursão não ganha velocidade;
  todo recursivo tem versão iterativa. Exercícios: MDC de Euclides recursivo (mdc(20,16)=4, mdc(21,7)=7);
  Fibonacci recursivo; inverter vetor recursivamente.

### 0042-vetores
- **Conceitos-chave:** conjunto de variáveis do mesmo tipo com nome e índice; índice 0..tam-1, inteiro;
  memória = tamanho do tipo × nº de elementos; inicialização com `{}`; C não confere limites.
- **Analogia boa:** memória como fila de segmentos; `vet[i]` é "base + i"; `vet[7]` num vetor de 3 cai em
  área de outra variável ou lixo — e pode destruí-la, sem aviso do compilador.
- **Pegadinha:** índice com `sqrt(MAX)` (double) é inválido.
- **Desatualizado:** diz que `float valor[num]` com `num` lido é sempre errado — em C99 é VLA (válido, mas
  arriscado e opcional desde C11). Recomenda tamanho via `#define MAX`.
- **Exercícios:** inverter o vetor de fato, não só imprimir ao contrário ({1,3,5,7} → {7,5,3,1});
  multiplicar vetor por k ({1,2,3}, k=5 → {5,10,15}); corrigir prova com gabarito de 10 questões.

### 0043-vetores-e-funcoes
- Passa-se só o nome; parâmetro `tipo v[]`; a função PODE alterar o original (passagem por endereço).
- **Exercícios:** `min_vet` (índice do menor); `remove_dup` (retorna nº removidos); `insert(v,n,valor,pos)`
  deslocando; `merge` (união ordenada sem duplicatas); `intersec`; `find` de padrão em texto ("As bananas
  do Panamá são bacanas", "anas" → 6); produto escalar.
- **ERRO recorrente:** protótipos `void le_vet(int v, int n)` — faltou `[]`/`*` (bom "ache o erro").

### 0044-matrizes
- Tabela de notas 5 alunos × 3 provas; 1º índice = linha, 2º = coluna; inicialização com listas
  aninhadas; na função é obrigatório informar as dimensões (exceto, de fato, a primeira).
- **ERRO:** escreve `nota[2,1]` como notação — em C isso é o operador vírgula (vale `nota[1]`)! Pegadinha
  excelente para o curso.
- **Exercícios:** produto de matrizes; 8 damas; jogo "Reverse" 3×3 (tabela de quais casas invertem).

### 0045-caracteres
- `char` guardado como inteiro (0–255 / -128..127); aritmética com char; tabela ASCII completa no apêndice.
- **Exercício:** imprimir todos os caracteres com código decimal e hexadecimal (5.2); ler decimal e mostrar
  o caractere e o hex (4.2); converter para maiúsculas lendo com `getchar`/`putchar`.

### 0046-strings
- String = vetor de char terminado em `'\0'`; declarada como `char nome[tam]` ou `char *nome`.
- **Pegadinha não apontada:** `char* nome; nome = "João..."` aponta para literal (só leitura) — não se
  pode modificá-lo nem ler para dentro dele com `scanf`.
- **Exercícios:** relatório de frase (nº palavras, vogais, letras) (5.5); número por extenso 0–1000
  (279 → "duzentos e setenta e nove"); Morse.

### 0049-memoria / 0050-ponteiros
- **Conceitos-chave:** ponteiro = variável que guarda endereço; tipo do ponteiro = tipo do bloco apontado;
  `&` (endereço), `*` (conteúdo); NULL não aponta para lugar nenhum; `scanf("%d", &num)` explicado como
  "guarde no bloco localizado no endereço de num".
- **ERRO GRAVE da apostila:** afirma que `float* s_1, s_2;` declara DOIS ponteiros porque o `*` está colado
  ao tipo. Falso: só `s_1` é ponteiro; `s_2` é `float`. Pegadinha clássica para o curso.
- Outros erros: `&(a+b)` inválido (correto); atribuição de endereço absoluto `0x03F8` (porta serial) e
  `int *p = 0x3f8` — não portável, não usar.

### 0051-passagem-por-referencia
- `troca(int *p1, int *p2)` com `temp`; passagem por valor = cópia em bloco diferente; por referência =
  endereço. Retornar vários valores: `stat(vet, N, &med, &dsvpd)`; `extremos(vet, N, &max, &min)`.
- **ERRO de digitação na apostila:** `void troca(int *p1, int *p1)` (dois p1) — "ache o erro".
- **Exercício:** `void round(float *r)` que arredonda o próprio número.

### 0052-ponteiros-e-vetores
- Nome do vetor = endereço do 1º elemento; `&vet[i] == vet + i`; `vet[i] == *(vet + i)`; somar n ao
  ponteiro avança n blocos (não n bytes). Comparação de ponteiros do mesmo tipo.

### 0055-ponteiro-para-funcao
- Declaração `float (*pt)(int,int)` (parênteses obrigatórios); `pt = &fun;` `(*pt)(10,20)`; passar função
  como argumento: `grad(x, y, soma)`. Exercício: `graf(a, b, pf)` que desenha o gráfico de uma função.

### 0059-malloc-free
- `vet = (int*)malloc(num * sizeof(int))`; retorna NULL se falhar; `free(pont)`.
- **Pegadinha:** a apostila mostra `malloc(num*2)` assumindo int de 2 bytes — motivo para SEMPRE usar
  `sizeof`. Biblioteca citada `alloc.h` → padrão é `stdlib.h`. Em C o cast do `malloc` é desnecessário.
- **Exercício:** vetor de N elementos aleatórios em [0,10] com N lido, e reaproveitar `remove_dup`.

### 0087-pilha / 0089-pilha-aplicacoes
- Ex. 7.16: **calculadora RPN** (HP) com pilha em vetor: `2+5*3` → 5 Enter 3 `*` → 15; 2 `+` → 17.

---

## Obsoleto / evitar
| Na apostila | Problema | Alternativa em C padrão |
|---|---|---|
| `void main()` | não padrão | `int main(void)` + `return 0;` |
| `conio.h`: `getch`, `getche`, `kbhit` | só DOS/Windows | `getchar()`; para tecla sem Enter, termios/ncurses (fora do escopo) |
| `clrscr`, `clreol`, `gotoxy`, `window`, `textcolor`, `textbackground`, `cprintf` | conio/Borland | não limpar tela; se preciso, sequências ANSI (`\x1b[2J`) ou ncurses |
| `dos.h`: `sound`, `delay`, `nosound` | DOS | `\a` (campainha); pausa: `sleep`/`nanosleep` (POSIX) |
| `random(n)` | Borland | `rand() % n` com `srand(time(NULL))` |
| `alloc.h` | Borland | `stdlib.h` |
| `M_PI` | não ISO | `#define PI 3.14159265358979` ou `acos(-1.0)` |
| `int` de 2 bytes, tabelas de faixa | plataforma antiga | `sizeof`, `limits.h`, `stdint.h` |
| `#include "c:\tc\...\stat.h"` com corpo de funções | prática ruim | `.h` com protótipos + `.c` compilado junto |
| `%f.2` | errado | `%.2f` |
| `float valor[num]` "proibido" | desatualizado | VLA existe (C99), mas preferir `malloc` |
| comentário `//` "só C++" | desatualizado | válido desde C99 |
| arquivos `.cpp` | é C++ | usar `.c` e `gcc` |

## Extras que não cabem no sumário
- Precisão da máquina (épsilon) e raiz por Newton — bons exemplos numéricos de laço.
- Tabela ASCII estendida e caracteres de moldura (179–218) — curiosidade; não portáveis (UTF-8 hoje).
- Códigos de tecla especiais (F1 = 0 seguido de 59) — histórico.
- `goto` com rótulos e `exit(status)` (valor vai para o sistema operacional, `errorlevel` no DOS; hoje
  `echo $?`).
- Desafios: proteção de tela, mover caractere com setas, 8 damas, Morse sonoro, jogo Reverse,
  média aritmético-geométrica de Gauss.
