# Fichamento — UFU: "Apostila de Linguagem C (Conceitos Básicos)"

- **Título:** Apostila de Linguagem C — Conceitos Básicos (82 p.)
- **Autor:** Prof. Luiz Gustavo Almeida Martins — Faculdade de Computação, Universidade Federal de Uberlândia.
- **Arquivo lido:** `d9f55f67-Apostila_Linguagem_C.md` (3111 linhas, lido por completo).
- **Avaliação geral:** a mais "técnica" das apostilas básicas: explica bem o processo de compilação e
  linkedição, diretivas (`#include <>` × `""`, `#define`, macros com parênteses, operadores `#` e `##`),
  protótipos, modificadores (`signed/unsigned/short/long`), qualificadores `const`/`volatile` e as quatro
  classes de armazenamento (`auto`, `extern`, `static`, `register`). Tem capítulo bom de **arquivos** (modos
  de `fopen`, `fgets` × `gets`, `fread`/`fwrite` com struct, `fseek`, `ferror`, `perror`) e `argc/argv`.
  Ponteiros e alocação dinâmica vêm como "leitura complementar" com a analogia do papel com endereço.
  Base Turbo C/DOS (int 16 bits, `void main`, `conio.h`, `gets`). **Muitos exemplos de código têm bugs**
  (listados por seção) — ótimo acervo para exercícios "ache o erro", péssimo para copiar.

---

### 0005-compilacao
- **Conceitos-chave:** fonte (.c) → pré-processamento (inclui arquivos, expande macros) → compilação de
  CADA arquivo separadamente → objeto (.obj/.o) → linkedição junta objetos + bibliotecas → executável.
  Objeto contém código de máquina, mas ainda não roda sozinho.
- **Analogia/explicação boa:** a figura das etapas "fonte → fonte + arquivos de inclusão → objeto →
  conjunto de objetos + bibliotecas → executável". Usar como base do diagrama do 0005 (trocando .obj/.exe
  por .o/a.out e mostrando `gcc -E`, `gcc -c`, `gcc x.o y.o -o prog`).
- **Pegadinha:** o erro "rótulo duplicado"/"multiple definition" só aparece na LIGAÇÃO, porque cada arquivo
  compila isolado (ver `extern` em 0039).
- **Exercício:** dado um projeto com `main.c` e `util.c`, quantos arquivos objeto são gerados? (2) Em
  qual etapa um protótipo faltando é detectado? (compilação) E uma função declarada mas nunca definida?
  (ligação).

### 0006-primeiro-programa
- **Conceitos-chave:** execução começa em `main`; chaves agrupam blocos; `;` encerra comandos; C diferencia
  maiúsculas de minúsculas e todas as palavras-chave são minúsculas; comentários são descartados pelo
  compilador. Esqueleto: diretivas → globais → protótipos → main → demais funções.
- **Pegadinha:** a própria apostila escreve `If`, `Printf`, `Int`, `While` com maiúscula em vários
  exemplos — não compila. Bom exercício: "por que este código não compila?".
- `main` retorna `int` ao sistema: 0 = término normal, ≠ 0 = erro (explicação boa).

### 0007-variaveis
- **Conceitos-chave:** variável = posição de memória com nome e tipo; declarar antes de usar; três lugares
  de declaração: dentro de função (local), na lista de parâmetros (formal), fora de tudo (global).
  Inicialização na declaração. `void` como 5º tipo básico (sem valor).
- **Identificadores:** letra ou `_` + letras/dígitos/`_`; sem espaço nem acento; não podem coincidir com
  palavras-chave nem com funções da biblioteca. Significativos: 31 internos / 6 externos (C89).
- **Desatualizado:** "declarações só no início do bloco, antes de qualquer comando" — regra do C89; desde
  C99 pode-se declarar no meio do bloco (inclusive no `for`).

### 0008-tipos-e-limites
- **Conceitos-chave:** o padrão fixa FAIXAS MÍNIMAS, não tamanhos: `short` e `int` ≥ 16 bits, `long` ≥ 32
  bits, `short ≤ int ≤ long`; `int` costuma ser o tamanho natural da palavra da máquina. `unsigned` só
  positivos; `signed int` é redundante; `long double`. Tabela com faixa e o especificador de `scanf` de
  cada tipo (`%hd`, `%hu`, `%u`, `%ld`, `%lu`, `%f`, `%lf`, `%Lf`).
- **Explicação boa:** figura do armazenamento: `char` = 1 bit de sinal + 7 de dados; `unsigned char` = 8 de
  dados; `float` = 1 sinal + 8 expoente + 23 mantissa; `double` = 1 + 11 + 52. Ótimo para 0004/0008.
- **Pegadinha:** constante numérica cabe no menor tipo compatível (10 → int; 100000 → long); constantes
  reais são `double` por padrão; sufixos `L` e `F` (`-15L`, `3.141F`).
- **Exercício:** qual o tipo de `10`, `3.0`, `3.0f`, `100000L`? (int, double, float, long).

### 0009-constantes
- **Conceitos-chave:** `'a'` (char) × `"a"` (string = `'a'` + `'\0'`, ocupa 1 byte a mais); octal começa com
  `0` (015 ≠ 15), hexa com `0x`. Tabela completa de escapes, incluindo `\N` (octal) e `\xN` (hexa).
  `const` = não pode ser modificada após a inicialização; `volatile` = pode mudar "por fora" do programa
  (relógio, porta de hardware); `const volatile` juntos.
- **ERRO na apostila (bom para exercício):** `const int pi = 3.14;` → pi vale 3 (truncado). Pergunta:
  "quanto vale `2 * pi * r` com r = 10?" (60, não 62.8).
- **`#define`:** troca textual pura; não substitui dentro de strings (`"Digite o seu NOME"` fica intacto);
  continuação de linha com `\`. Exercício: com `#define NOME "Fulano"`, o que imprime
  `printf("NOME: %s", NOME)`? (`NOME: Fulano`).

### 0010-printf
- **Conceitos-chave:** string de controle tem 3 tipos de caractere: texto literal, escapes e
  especificadores. Tabela completa (`%d %i %o %x %X %u %c %s %f %e %E %g %G %%`); modificadores: `-`
  (esquerda), largura mínima, `.precisão` (casas decimais em real, máximo de caracteres em string, mínimo de
  dígitos em inteiro), `h`/`l`.
- **Exemplo pronto (com saída):** `%-10.2f` de 8.0, 15.253, 584.13 → "8.00      15.25     584.13";
  `%04d` de 21 → `0021`; `%6d` → `    21`; `%10.3f` de 3456.78 → `  3456.780`; `%3.1f` → `3456.8` (largura é
  mínima: não corta); `%c` de 47 → `/`.
- **Pegadinha:** largura menor que o número não trunca (`%3.1f` de 3456.78 imprime 6 caracteres).
- **Pegadinha de segurança:** a apostila sugere `printf(string)` para imprimir uma string — se a string
  contiver `%`, dá problema. Usar `printf("%s", string)` ou `puts`.
- Bug no exemplo: `printf("%hd %c \n", CH)` passa um argumento para dois especificadores.

### 0011-scanf
- **Conceitos-chave:** `scanf` recebe a lista de ENDEREÇOS (`&var`); `%i` aceita decimal, octal (`0..`)
  ou hexa (`0x..`); `%f` lê `float` e `%lf` lê `double` (no `printf` ambos usam `%f`). `scanf` devolve
  quantos itens leu: `while (scanf("%f", &n) == 1)` soma até o fim da entrada (Ctrl-Z/Ctrl-D) — padrão
  excelente para 0011/0030.
- `getchar` devolve `int` (para caber o `EOF`, que vale -1) e é "bufferizado": nada chega antes do Enter.
- **Pegadinhas da apostila:** `scanf("%s\n\n", &FRASE)` (o `\n` no formato faz o scanf esperar mais
  entrada; e `&` em vetor é desnecessário); `scanf("&d", &TEMP)` (digitado `&` no lugar de `%` — lê nada);
  `scanf("%li", FOLHA_PAGTO.NRO_SEG)` (faltou `&`); `scanf("%d,%d", ...)` exige digitar a vírgula.
- **Exercício:** somar números até o fim da entrada, imprimindo subtotal a cada 10 (exemplo do livro).
  Entrada 1..25 → subtotais 55 e 210, total 325.

### 0012-aritmetica / 0013-conversao
- **Conceitos-chave:** resultado tem o tipo "maior" da expressão; inteiro/inteiro = divisão inteira; `%` só
  inteiros; `-` unário troca sinal. Regras de promoção: `char`/`short` → `int`; operandos diferentes →
  converte para o de maior capacidade. Cast: `(float) NRO / 2`.
- **Exemplo pronto:** `A=1, B=2, X=2.0, Y=3.5`: `(2*A+B)/B` → 2; `X*Y + C` → 9.0; `(A+B)%B` → 1; `-B` → -2.
- **Pegadinha (boa):** `(float) NRO / 2` funciona porque o cast vem ANTES da divisão; `(float)(NRO / 2)`
  já fez divisão inteira. Exercício: NRO = 7 → 3.5 × 3.0.
- Protótipos evitam promoções antigas (sem protótipo, `char`→`int` e `float`→`double` nos argumentos).

### 0014-atribuicao
- `Y = X++` (Y=10, X=11) × `Y = ++X` (ambos 11). Expressões reduzidas `+= -= *= /= %=` para contadores e
  acumuladores. Tabela de precedência completa (inclui `( ) [ ]`, unários, cast, ternário, atribuição).
- **Exercício:** `int X = 10, Y; Y = X++ + 1;` → Y = 11, X = 11.

### 0015-math
- `ceil(3.4)=4`, `floor(3.4)=3` (aqui corretos), `exp`, `fabs`, `log`, `log10`, `pow`, `sqrt`, trig em
  radianos. Boa observação: `pow` também faz radiciação com expoente fracionário (`pow(27, 1.0/3)` = 3).
  Pegadinha associada: `pow(27, 1/3)` = 1 (divisão inteira!).
- `ctype.h`: `tolower`, `toupper` (não-letras voltam inalteradas).

### 0017-relacionais / 0018-logicos
- Resultado de comparação é 0 ou ≠ 0. Exemplo: pares de 1 a 100 com `if (!(NRO % 2))` — bom para
  discutir legibilidade (`NRO % 2 == 0` é mais claro).

### 0019-if / 0020-if-else / 0021-else-if
- **Conceitos-chave:** chaves opcionais com um comando só; endentação não muda a semântica; `else if`
  avaliado em ordem e para no primeiro verdadeiro.
- **Pegadinha EXCELENTE (else pendurado):** termostato — objetivo: "agradável" entre 20 e 30, "muito
  quente" acima de 30. Código sem chaves `if (T<30) if (T>20) ...; else "muito quente";` — o `else` gruda
  no `if` mais próximo, então "muito quente" sai quando T ≤ 20! Correção com chaves. Usar no 0021.
- **Exemplo:** faixas de temperatura com `if` aninhado (<10 muito fria, <20 fria, <30 agradável, senão
  quente) e reescrito com `else if` — mostra que a cadeia é mais legível.
- **Pegadinha `=` × `==` (0020):** o exemplo de contar letras usa `If (FRASE[I] = LETRA)` — atribui em vez
  de comparar e conta TODAS as posições. Usar como "ache o erro".

### 0022-ternario
- `Z = (A > B) ? A : B;` equivalente ao if/else de máximo.

### 0023-switch
- **Conceitos-chave:** compara uma variável contra constantes; só testa igualdade (diferença para o if);
  `break` opcional (sem ele, cai no próximo case); `default` opcional.
- **Ideia de exemplo:** calculadora com menu (1 soma, 2 subtração, 3 multiplicação, 4 divisão com teste de
  divisor zero, 5 sair) dentro de um `while (op != '5')`. Bom modelo para 0024 (trocar `getche` por
  `scanf(" %c")`).

### 0025-while / 0026-do-while / 0027-for
- Mesma tarefa (soma 1..10 = 55) com `while`, `do-while` e `for` — ótimo exemplo comparativo.
- `for`: qualquer das três partes pode ser omitida (os `;` ficam); `for(;;)` infinito com `break`;
  incremento dentro do corpo (`for (x=0; x != 123;) scanf(...)`); múltiplas expressões com vírgula
  (`for (x=0, y=100; x < y; x++, --y)`).
- **Pegadinha:** no exemplo do `do-while` falta `;` depois de `while (i <= 10)` — erro de sintaxe clássico.
- **Exercício:** quantas linhas imprime `for (x=0, y=100; x<y; x++, --y)`? (50).

### 0028-break-continue
- `break` sai só do laço MAIS INTERNO; `continue` vai para a próxima iteração; `return` sai do laço e da
  função; `goto` (mesma função; único uso defensável: sair de laços muito aninhados); `exit` encerra o
  programa.
- **Exemplo:** teste de primo com `break` ao achar divisor; ler números ignorando negativos com `continue`
  até digitar 100.
- **Bugs da apostila:** `TEXTO = "O número é primo";` com `char TEXTO[80]` — não se atribui string a vetor
  (usar `strcpy` ou `const char *`); `exit;` sem parênteses/argumento — compila como expressão sem efeito e
  NÃO sai do programa (pegadinha ótima).

### 0034-parametros / 0033-funcoes
- **Conceitos-chave:** forma geral; tipo de cada parâmetro deve ser escrito individualmente
  (`int a, int b`, não `int a, b`); parâmetros são locais; vários `return` possíveis, só um executa;
  tipo omitido = `int` (C antigo); valor de retorno pode ser ignorado (ex.: o de `printf`).
  `void` para procedimentos e para lista vazia: `int f(void)` (chamar com argumentos vira erro).
- Protótipo: permite checar tipos e quantidade de argumentos; nomes dos parâmetros opcionais.
- **Exemplos:** `square`, `EPar` (retorna 1/0), `sqr` por valor (original não muda) × `sqr(float *num)` por
  referência.
- **Exercício:** o que imprime `nro` depois de `sq = sqr(nro)` na versão por valor? (o valor original).

### 0035-escopo
- **Conceitos-chave:** local = automática (`auto`), criada na entrada do bloco e destruída na saída;
  mesmo nome em funções diferentes não conflita; global em área fixa, vive o programa todo; evitar
  globais (efeitos colaterais, reuso). **`static` local** mantém valor entre chamadas.
- **Ideia de exemplo excelente:** gerador de número de série `obtem_nro_serie()` com
  `static int NRO_SERIE = 1000;` somando 10 → 1010, 1020, 1030... Exercício: o que acontece sem `static`?
  (sempre 1010).
- `static` em global = visível só no arquivo; `register` = pedido de acesso rápido, proíbe `&`;
  `auto` é o padrão (inútil escrever).

### 0037-recursao
- Primeiro passo é definir o critério de parada; fatorial `n > 1 ? n*fat(n-1) : 1`. Recursão costuma
  gastar mais memória e tempo (cada chamada fica pendente), mas é mais compacta; estruturas recursivas
  (árvores) combinam com ela.
- **Pegadinha:** o exemplo de protótipo escreve `if NRO < 2 return (1);` sem parênteses na condição.

### 0039-modulos
- **Conceitos-chave:** `extern` resolve a duplicação de globais entre arquivos: define em UM arquivo
  (`int x, y;`) e declara nos outros (`extern int x, y;`); sem isso, cada arquivo compila, mas a ligação
  acusa símbolo duplicado. `static` global esconde a variável dos outros arquivos.
- `#include <x.h>` procura nos diretórios do sistema; `"x.h"` procura primeiro no diretório de trabalho.
  Inclusões podem ser aninhadas (o padrão garante pelo menos 8 níveis).
- **Exercício:** dois arquivos com `int contador;` cada — compila? liga? (compila cada um; na ligação, erro
  ou comportamento dependente do compilador; corrigir com `extern`).

### 0040-preprocessador
- **Conceitos-chave:** diretivas começam com `#`, não levam `;`; `#define` cria constantes e macros com
  argumentos; substituição é textual, a verificação de sintaxe só ocorre depois.
- **Pegadinha CLÁSSICA (bem explicada):** `#define CUBO(X) ((X)*(X)*(X))`; sem parênteses, `CUBO(A+B)` viraria
  `A+B*A+B*A+B`. Exercício: com `#define QUAD(x) x*x`, quanto vale `QUAD(2+3)`? (2+3*2+3 = 11, não 25).
- Operadores `#` (transforma argumento em string: `mkstr(Processamento de Dados)` → `"Processamento de
  Dados"`) e `##` (cola tokens).
- Não cobre `#ifdef`/`#ifndef` (diz que foge ao escopo).

### 0042-vetores / 0044-matrizes
- **Conceitos-chave:** vetor = matriz de 1 dimensão; elementos do mesmo tipo, contíguos; índice começa em
  0; C não confere limites (risco de sobrescrever outras variáveis ou travar); inicialização com `{}`;
  tamanho da 1ª dimensão pode ser omitido se houver inicialização (`int V[] = {5,10,15,20,25}`;
  `char T[][2] = {'a','b','c','d'}`). Na varredura de matriz, o índice mais à direita varia mais rápido.
- **Exemplo:** ler até 100 números ou até digitar 0 e reimprimir; preencher matriz 20×10 com 1..200.
- **ERRO na apostila:** diz que `int NUMEROS[10]` é indexado "de 0 a 19" (confundiu bytes com índices).
  Correto: 0 a 9. Bom para "ache o erro".
- **Pegadinha:** no contador de letras, `while (FRASE[I] != '\0' && I <= 100)` com vetor de 100 → índice
  100 já está fora (off-by-one).

### 0043-vetores-e-funcoes
- Ao passar matriz, passa-se o endereço do 1º elemento (exceção à "passagem por valor"); 3 formas
  equivalentes de declarar o parâmetro: `int v[50]`, `int v[]`, `int *v` — dentro da função é sempre um
  ponteiro (por isso o 50 é ignorado e `sizeof` não dá o tamanho do vetor).

### 0046-strings
- **Conceitos-chave:** string = vetor de char terminado em `'\0'`; espaço = caracteres + 1; não se copia
  string com `=` (copiar caractere a caractere ou `strcpy`); `for (i = 0; s[i]; i++)` aproveita o `\0`
  como falso. `strcpy(dest, orig)`, `strcat(dest, orig)`, `strlen` (não conta o `\0`), `strcmp` (0 se
  iguais — por isso `if (strcmp(a,b))` significa "diferentes"!), `atoi`, `atof` (stdlib.h).
  Vetor de strings = matriz `char nomes[5][100]`; `nomes[i]` é uma string.
- **Pegadinha:** `if (strcmp(s1, s2))` entra quando são DIFERENTES — confunde iniciantes.
- **ERRO na apostila:** `char str1[2] = "12"` — não sobra espaço para o `'\0'`, e `atoi` lê além do vetor.
  Exercício: qual o tamanho mínimo? (3).
- **Exemplo:** `atoi("12") + atof("2.14")` = 14.14.

### 0047-lendo-strings
- **Explicação boa:** `gets` não sabe o tamanho do destino → estouro de buffer; `fgets(str, tam, stdin)`
  lê no máximo tam-1 caracteres, sempre põe `'\0'` e GUARDA o `'\n'` (diferente de `gets`). Usar como base
  para "por que nunca gets" e "tirar o \n".
- A apostila ainda usa `gets` em quase todos os exemplos.

### 0049-memoria / 0050-ponteiros
- **Analogia excelente:** ponteiro = papel onde você anota o endereço de um colega; agenda = vetor de
  ponteiros; ponteiro tem tipo como "endereço de amigo" × "endereço de firma" (mesmo formato, conteúdo
  diferente). `&` = ligar para a firma e pedir o endereço; `*` = ir até a firma e mexer lá dentro.
  Ponteiro para ponteiro = anotar o endereço do papel que tem o endereço do amigo.
- **Conceitos-chave:** `int *pt; char *temp, *pt2;` (asterisco em cada nome); ponteiro não inicializado
  aponta para lugar indefinido — inicializar SEMPRE; `%p` imprime endereço; `*` de multiplicação (binário)
  ≠ `*` de indireção (unário).
- **Pegadinha (bem explicada):** `int x, *p; x = 13; *p = x;` compila e roda, gravando 13 em lugar
  desconhecido.
- **ERRO grave na apostila:** o exemplo "vetor reescrito com ponteiro" declara `int *num;` e faz
  `scanf("%d", num + count)` sem alocar memória — exatamente o erro que ela mesma condena depois.
  Ótimo "ache o erro".

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** `p+1` avança um elemento (2 bytes num int de 16 bits, 8 num double); `p++` × `(*p)++`
  (mover o ponteiro × incrementar o valor apontado); permitido: atribuir, somar/subtrair inteiro, comparar;
  proibido: multiplicar, dividir, somar dois ponteiros, somar float. `v[i] ≡ *(v+i)` explica por que o
  índice começa em 0 e por que C não confere limites. Ponteiros também podem ser indexados (`p[2]`).
- **Pegadinha (boa):** o nome do vetor não é variável: `vetor = vetor + 2`, `vetor++`, `vetor = ponteiro`
  são erros ("not an lvalue"); `ponteiro = vetor + 2` é válido.
- **Exemplo:** zerar matriz 50×50 com índices × com ponteiro percorrendo 2500 posições (a apostila diz que
  é mais rápido; hoje o compilador otimiza ambos — vale discutir).
- Erro de digitação na apostila: "v+1 aponta para o 1º elemento; v+2 aponta para o 1º elemento".

### 0053-ponteiros-e-strings
- Literais ficam num "banco de strings" do compilador; no código fica o endereço. `char *str1 = "String
  constante.";` — se alterar o ponteiro perde a string; se escrever através dele corrompe o banco
  (hoje: literal é só leitura, escrever é comportamento indefinido).

### 0054-ponteiro-para-ponteiro
- `float fpi = 3.1415, *pf, **ppf; pf = &fpi; ppf = &pf;` → `**ppf` e `*pf` imprimem 3.1415.

### 0059-malloc-free / 0060-calloc-realloc
- **Conceitos-chave:** ANSI define 4 funções em `stdlib.h`: `malloc(bytes)` devolve `void *` (NULL se
  falhar); `calloc(num, tam)` (aloca num × tam — e zera, o que a apostila não diz); `realloc(p, novo)` pode
  mover o bloco e copia o conteúdo; NULL em `realloc` aloca; tamanho 0 libera; se faltar memória devolve
  NULL e mantém o original; `free(p)` consulta uma tabela interna para saber quantos bytes liberar.
- **Pegadinha (não apontada, mas presente):** `p = realloc(p, ...)` perde o bloco original se der NULL —
  usar ponteiro temporário. E o exemplo nem testa o retorno.
- **Pegadinha:** `if (!p) { printf(...); exit; }` — `exit;` não chama nada; o programa segue e usa NULL.
- **Exemplo:** vetor de 30 quadrados realocado para 80.

### 0064-struct / 0065-typedef / 0066-vetor-de-structs
- **Conceitos-chave:** registro = estrutura heterogênea; `struct` + tag opcional + membros; variáveis podem
  vir após a `}`; declaração sem variáveis só descreve o formato, não aloca; inicialização com chaves na
  ordem dos membros (inclusive aninhada); acesso com `.` (encadeado para struct aninhada:
  `FOLHA_PAGTO.ENDERECO.BAIRRO`); `r1 = r2` copia campo a campo (diferente de vetores!); vetor de structs;
  `typedef` cria apelido (`typedef struct tipo_endereco {...} tp_endereco;`).
- **Ideia de exemplo:** folha de pagamento (nome, endereço com logradouro/número/bairro/complemento,
  número do seguro, salário); cadastro de alunos com endereço; desconto de IR = salário × 0.25.
- **ERRO na apostila:** `ALUNOS.nome = "Joaquim Manoel";` (nome é vetor — usar `strcpy`). Pegadinha ótima.
- **Exercício:** struct com dois registros: `a = b;` funciona? E `a == b`? (sim; não — comparar campo a
  campo).

### 0072-arquivos-texto
- **Conceitos-chave:** `FILE *fp` aponta para uma estrutura com buffer, posição, modo e indicadores de erro/
  fim; arquivos pré-abertos `stdin`, `stdout`, `stderr` (`stdaux`, `stdprn` são DOS). Tabela de modos
  `r w a r+ w+ a+` (+ `b`): `r` exige que exista; `w` apaga o conteúdo; `a` acrescenta no fim.
  `fopen` devolve NULL se falhar → sempre testar. `fclose` grava o que restou no buffer e devolve 0 se ok.
  `putc/fputc`, `getc/fgetc` (EOF no fim), `fgets/fputs`, `fprintf/fscanf` (iguais a printf/scanf com `fp`;
  `fscanf(stdin, ...)` = `scanf`). `remove(nome)` com confirmação; `fflush(fp)` descarrega buffer de SAÍDA.
- **Analogia boa (buffer):** gravar caractere a caractere no disco seria como mover a cabeça de gravação a
  cada letra; o buffer junta tudo e grava de uma vez quando enche ou no `fclose`.
- **Ideias de exemplo:** gravar string caractere a caractere em `string.txt`; `type`/`cat` caseiro que
  recebe o nome via `argv`; gravar linhas até linha vazia; copiar TESTE → TESTE1 com `fgets`.
- **Pegadinhas da apostila:** `char ch = getc(fp)` — EOF (-1) pode não ser distinguível em `char` → usar
  `int`; `while (!feof(fp)) { c = getc(fp); printf("%c", c); }` imprime um caractere-lixo no final, pois
  `feof` só fica verdadeiro DEPOIS de uma leitura falhar (padrão errado clássico — ótimo para o curso);
  "NULL é definido como '\0'" (não: é ponteiro nulo); macros `SEEK_*` "em stdlib.h" (são de `stdio.h`).
- `ferror`, `clearerr`, `perror("Erro na gravacao")` (mensagem vai para `stderr` com a descrição do
  `errno`).

### 0073-arquivos-binarios
- **Conceitos-chave:** `fwrite(buf, tam, qtd, fp)` / `fread(...)` devolvem nº de ELEMENTOS transferidos
  (testar `!= 1`); `rewind`; `fseek(fp, deslocamento, SEEK_SET|SEEK_CUR|SEEK_END)` para acesso aleatório.
  Gravar struct inteira: `fwrite(&folha, sizeof(struct f), 1, fp)`.
- **Exemplo:** gravar e reler um `double` 12.23, um `int` 101 e um `long` 1230232; mostrar o N-ésimo
  caractere de um arquivo com `fseek` + `getc` (nome e N vêm de `argv`).

### 0074-argumentos
- **Conceitos-chave:** `int main(int argc, char *argv[])`; `argc` ≥ 1 (conta o nome do programa);
  `argv[0]` é o nome; argumentos separados por espaço chegam como strings (converter com `atoi`/`atol`).
- **Ideia de exemplo:** `data 19 04 1999` → "19 de abril de 1999" com vetor de nomes de meses e validação de
  1..12. (Bugs na apostila: variável `mês` com acento, `nm_mes` × `nomemes`, e imprime "19%s".)
- **Exercício:** quanto vale `argc` em `./data 19 04 1999`? (4).

---

## Obsoleto / evitar
| Na apostila | Problema | Alternativa em C padrão |
|---|---|---|
| `void main(void)` | não padrão | `int main(void)` + `return 0;` |
| `gets(str)` | estouro de buffer; removida no C11 | `fgets(str, sizeof str, stdin)` + remover `'\n'` |
| `clrscr()`, `gotoxy()`, `getch()`, `getche()` (`conio.h`) | DOS/Borland | não limpar a tela; `getchar()`; ANSI escape se for indispensável |
| `getchar()` no fim "para segurar a tela do DOS" | hábito de IDE antiga | rodar no terminal |
| nomes de arquivo 8.3, `C:\TC\INCLUDE`, `.obj/.exe` | DOS | `.o`, `a.out`, `gcc -o` |
| `stdaux`, `stdprn` | DOS | só `stdin`, `stdout`, `stderr` |
| declarações só no início do bloco | regra C89 | C99+: declarar perto do uso, `for (int i = 0; ...)` |
| `fflush(stdin)` (implícito na cultura da época) | indefinido para entrada | ler e descartar até `'\n'` |
| `while (!feof(fp))` | lê um item a mais | `while ((c = getc(fp)) != EOF)` / `while (fgets(...))` |
| `char c = getc(fp)` | perde EOF | `int c` |
| `exit;` | não faz nada | `exit(1);` ou `return 1;` |
| `p = realloc(p, n)` | vaza se falhar | `tmp = realloc(p, n); if (tmp) p = tmp;` |
| cast em `malloc` | desnecessário em C | `int *p = malloc(n * sizeof *p);` |
| `printf(string)` | vulnerável a `%` | `printf("%s", string)` / `fputs` |
| `register`, `auto` | sem efeito prático hoje | omitir |

## Extras que não cabem no sumário
- `volatile` e `const volatile` (registradores de hardware, rotinas de relógio).
- Operadores de pré-processador `#` e `##`; continuação de linha com `\` em `#define`.
- Funções sem protótipo e promoções padrão de argumentos (`char`→`int`, `float`→`double`) — explica por que
  `printf` usa `%f` para float e double.
- `ferror`, `clearerr`, `perror` e `errno`; `remove`; `fflush` em saída.
- Representação IEEE 754 resumida (sinal/expoente/mantissa) — ponte para 0004.
