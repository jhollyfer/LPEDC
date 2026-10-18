# Fichamento — Deitel & Deitel, *C: Como Programar* (parte 2)

- **Obra:** *C: Como Programar* (6ª ed. americana, com introdução a C++ nos caps. 15–24).
  Pearson, tradução brasileira. O arquivo .md foi gerado por OCR de PDF.
- **Autores:** Paul Deitel e Harvey Deitel.
- **Trecho lido:** linhas 13034–45201 do .md.
  - **Na íntegra, bloco a bloco:** cap. 7 (Ponteiros), 8 (Caracteres e strings), 9 (E/S
    formatada), 10 (Estruturas, uniões, bits, enumerações), 11 (Arquivos), 12 (Estruturas de
    dados), 13 (Pré-processador), 14 (Outros tópicos), linhas 13034–26393, e os apêndices B
    (ASCII), C (Sistemas numéricos) e D (Sudoku), linhas 43560–44510.
  - **Por varredura (títulos de seção + trechos procurados):** caps. 15–24 (C++) e o índice
    remissivo. Do C++ só aproveitei observações que valem para C (ver "Extras").
  - **Não existe neste arquivo:** o apêndice de C99 (o texto cita um "Apêndice G" que não
    está no arquivo) nem nada sobre gdb. Não há `bool`, `restrict`, VLA, `long long`,
    `stdint.h` nem `//`. O livro ensina C89 com uma ou outra nota sobre C99.

## Avaliação geral

É o livro mais **"enciclopédico"** das fontes: cobre a biblioteca padrão quase função por
função (ctype, stdlib, string.h, stdio, stdarg, signal), sempre com um programa completo e a
saída. Os pontos fortes são as caixas **"Erro comum de programação"** e **"Dica de prevenção
de erro"** (uma mina de pegadinhas), os quadros de resumo (especificadores de `printf`/`scanf`,
modos de `fopen`, operadores bit a bit) e os **exercícios**, muitos e bons: Simpletron
(montar e simular uma máquina), tartaruga e lebre, baralho, labirinto, notação pós-fixa,
simulação de fila de supermercado, remoção em BST, percurso por nível.

Pontos fracos para o LPEDC:
- C datado: **ints de 4 bytes e ponteiros de 4 bytes** assumidos (máquina de 32 bits, Visual
  C++), `while (!feof(f))` como padrão de leitura, `atoi`/`atof` sem verificação de erro, `%n`,
  `register`, nenhum `const` em vários lugares e nenhum teste de retorno de `scanf`/`fread`.
- **Muitos erros de OCR e de tradução no código** (identificadores trocados no meio do
  programa, `naipe` declarado duas vezes, `count` × `contador`), além de **alguns erros
  conceituais reais** (listados na seção final). Use o livro para ideias e exercícios; nunca
  copie código dele.
- Strings com acentos nos exemplos dão, em UTF-8, contagens diferentes das impressas.

### 0004-binario
- **Conceitos-chave:** Notação posicional: cada posição vale uma potência da base; o "valor do símbolo" é o dígito,
  o "valor posicional" é a potência. O maior dígito de uma base é sempre (base − 1).
- Octal e hexadecimal existem para **abreviar binário**, porque 8 = 2³ e 16 = 2⁴: agrupe os bits
  de 3 em 3 (octal) ou de 4 em 4 (hex), a partir da direita.
- Para decimal: some (dígito × valor posicional). De decimal: método das colunas (escreva as
  potências até passar do número, descarte a última e vá dividindo da esquerda para a direita).
- Negativos em **complemento de dois**: inverte todos os bits (`~`, complemento de um) e soma 1.
  O número mais o seu complemento de dois dá zero (o "vai um" final é descartado). A máquina
  faz `a - b` como `a + (~b + 1)`.
- **Analogias/explicações boas:** A tabela de 0 a 16 lado a lado em decimal/binário/octal/hex deixa o padrão visível (o hex
  "vira" em 16 = `10`, o octal em 8 = `10`).
- Prova do complemento de dois: some 13 com o suposto −13 e mostre a linha de zeros.
- **Pegadinhas e erros comuns:** Achar que o "maior dígito" é igual à base. Esquecer de completar com zeros à esquerda ao
  agrupar bits (`1101110` → `001 101 110`).
- Complemento de um tem dois zeros (+0 e −0); complemento de dois não.
- **Ideias de exemplos:** `100011010001₂` = `4321₈` = `8D1₁₆` (mostrar os grupos de 3 e de 4).
- `110101₂` = 53; `7614₈` = 3980; `AD3B₁₆` = 44347.
- 57 → `111001₂`; 103 → `147₈`; 375 → `177₁₆`.
- 13 = `...00001101`; −13 = `...11110011`; 27 − 13 calculado como 27 + (−13) = 14.
- **Ideias de exercícios:** Converter `110101011000₂` para octal e hex (resp.: `6530₈`, `D58₁₆`).
- `FACE₁₆` para binário (resp.: `1111 1010 1100 1110`); `4FEC₁₆` para octal via binário
  (resp.: `47754₈`).
- `EFD4₁₆` para decimal (resp.: 61396); 177 para as três bases (resp.: `10110001`, `261`, `B1`).
- Escrever −1 em 32 bits (resp.: 32 uns). Qual é o menor/maior dígito na base 12?
- Programa: ler um `unsigned` e imprimir os 32 bits (liga com 0070).

### 0005-compilacao
- **Conceitos-chave:** O pré-processador roda antes do compilador; o **ligador (linker)** resolve nomes usados num
  arquivo e definidos em outro. Uma declaração `extern int flag;` diz "existe em algum lugar";
  se o linker não achar a definição, o erro é **de ligação**, não de compilação.
- Protótipos (e os `.h` da biblioteca) só prometem que a função existe; quem acha `printf` é o
  linker.
- **Simpletron (exercícios 7.27–7.29):** uma máquina de brinquedo com acumulador, memória de
  100 palavras de 4 dígitos com sinal e instruções `opcode*100 + endereço` (READ 10, WRITE 11,
  LOAD 20, STORE 21, ADD 30, SUB 31, DIV 32, MUL 33, BRANCH 40, BRANCHNEG 41, BRANCHZERO 42,
  HALT 43). O simulador é o ciclo **busca → decodifica → executa**:
  `reg = mem[pc]; op = reg / 100; end = reg % 100; switch (op) ...; pc++`.
- **Analogias/explicações boas:** O programa "soma dois números" em linguagem de máquina: `+1007 +1008 +2007 +3008 +2109 +1109
  +4300` (lê A, lê B, carrega A, soma B, guarda C, escreve C, para). Mostra que o computador só
  move números entre memória e acumulador.
- **Pegadinhas e erros comuns:** Confundir erro de compilação com erro de ligação ("undefined reference").
- **Ideias de exemplos:** Desmontar à mão o programa "maior de dois" (usa BRANCHNEG após subtrair).
- **Ideias de exercícios:** Escrever em SML: somar inteiros até ler um negativo; calcular a média de 7 números.
- Projeto do módulo: o simulador do Simpletron em C, com validação de entrada (−9999..9999),
  erros fatais (divisão por zero, opcode inválido, estouro do acumulador) e "dump" da memória.

### 0008-tipos-e-limites
- **Conceitos-chave:** `sizeof` é avaliado **na compilação**; dá bytes. Tamanhos variam por máquina (o livro mostra
  `long` = 4 e `long double` = 8 numa máquina de 32 bits; hoje no Linux 64 bits são 8 e 16).
- `size_t` é o tipo inteiro sem sinal que `sizeof` devolve.
- Parênteses obrigatórios em `sizeof(long double)` (nome de tipo); opcionais com variável.
- Um `int` é só uma **aproximação** do inteiro da matemática: tem faixa limitada e o estouro
  pode passar em silêncio (vem do cap. 18, sobre TAD).
- Sufixos de constantes: `174u`, `8358L`, `28373ul`, `1.28f`, `3.14159L`. Literal real sem
  sufixo é `double`; literal inteiro sem sufixo vira o primeiro tipo que couber.
- **Pegadinhas e erros comuns:** Imprimir negativo com `%u`: −455 aparece como 4294966841.
- Escrever programa que depende de "int tem 4 bytes" em vez de usar `sizeof`.
- **Ideias de exemplos:** Tabela de `sizeof` de todos os tipos, impressa e depois gravada em arquivo (ex. 11.16).
- **Ideias de exercícios:** Prever e testar o que `printf("%u\n", -1)` mostra; explicar com complemento de dois.

### 0009-constantes
- **Conceitos-chave:** Sequências de escape: `\' \" \? \\ \a \b \f \n \r \t \v`. Para imprimir `%` em `printf`, `%%`.
- Constante de caractere é um `int` (`'z'` vale 122 em ASCII, `'\n'` vale 10).
- `#define PI 3.14159` substitui texto; tudo à direita do nome entra na substituição.
- **Pegadinhas e erros comuns:** `#define PI = 3.14159` coloca o `=` dentro de cada uso. `#define N 10;` idem com `;`.
- Aspas simples em volta de string (`'abc'`) ou aspas duplas em volta de caractere (`"a"` é um
  array de 2 bytes, não um `char`).
- **Ideias de exercícios:** Programa que testa cada escape que move o cursor, imprimindo um caractere antes e depois.

### 0010-printf
- **Conceitos-chave:** Forma geral: `%[flags][largura][.precisão][modificador]conversão`.
- Inteiros: `d`/`i` (iguais no `printf`), `o`, `u`, `x`/`X`; modificadores `h` (short) e `l`.
- Reais: `f` (6 casas), `e`/`E` (notação científica, 1 dígito antes do ponto), `g`/`G` (escolhe
  `e` se o expoente for < −4 ou ≥ precisão; tira zeros finais), `L` para `long double`.
- `c` pede um `char`; `s` pede um ponteiro e imprime até o `'\0'`; `p` endereço; `%%`.
- **Largura** = tamanho mínimo do campo, alinhado à direita (cresce se não couber; o `-` do
  negativo conta). **Precisão** muda de sentido: em inteiros é o mínimo de dígitos (preenche
  com zeros), em `f`/`e` é casas decimais (com arredondamento), em `g` é dígitos
  significativos, em `s` é o máximo de caracteres.
- `*` no lugar de largura/precisão pega o valor de um argumento `int`.
- Flags: `-` (esquerda), `+` (sempre sinal), espaço (espaço antes de positivo, alinha com
  negativos), `#` (prefixo `0`/`0x`, força o ponto decimal), `0` (zeros à esquerda).
- `printf` devolve quantos caracteres escreveu.
- **Analogias/explicações boas:** Mesmo número em várias larguras (`%4d` com 1, 12, 123, 1234, 12345 e os negativos) mostra a
  "coluna" e o campo crescendo.
- **Pegadinhas e erros comuns:** `%s` com um `char` → acesso inválido à memória; `%c` com uma string → lixo.
- `%d` com um `double` (`printf("%d", 10.987)`) é comportamento indefinido, não "trunca".
- `%` solto no fim do formato (`"%.3f%"`).
- Esquecer as aspas do formato: `printf(%d, x)`.
- **Ideias de exemplos:** `%.4d` de 873 → `0873`; `%.9d` → `000000873`; `%.3g` de 123.94536 → `124`;
  `%.11s` de "Feliz Aniversario" → `Feliz Anive`; `%9.3f` de 123.456789 → `  123.457`;
  `%*.*f` com 7, 2, 98.736 → `  98.74`; `%+09d` de 452 → `+00000452`; `%#x` de 1427 → `0x593`.
- Valores `0.0000875`, `8750000.0`, `87.50` com `%g` → `8.75e-05`, `8.75e+06`, `87.5`.
- **Ideias de exercícios:** Tabela Fahrenheit 0..212 → Celsius em duas colunas de largura 10, Celsius com sinal e 3
  casas (`%10d%+10.3f`).
- Imprimir 100.453627 arredondado para inteiro, décimos, centésimos, milésimos.
- `%g` de 9876.12345 com precisões de 1 a 9 (prever antes de rodar).
- "Proteção de cheque": imprimir um valor em 9 posições com asteriscos à esquerda
  (`****99,87`).

### 0011-scanf
- **Conceitos-chave:** Os argumentos são **endereços**. Array de `char` já é endereço (sem `&`).
- `%d` só decimal; `%i` aceita decimal, octal (`010`) e hex (`0x10`).
- No `scanf`, `double` exige `%lf` (no `printf` não faz diferença).
- `%c` não pula espaços e não põe `'\0'`; `%s` para no primeiro espaço e põe `'\0'`.
- Caracteres comuns no formato precisam aparecer na entrada (`"%d-%d-%d"`); um espaço no
  formato pula qualquer quantidade de espaços/quebras.
- `%*c` lê e descarta (supressão de atribuição): `"%d%*c%d%*c%d"` aceita `11-18-2003` e
  `11/18/2003`.
- Largura limita o que é lido: `%2d%d` com `123456` dá 12 e 3456; `%19s` protege `char s[20]`.
- Conjunto de varredura: `%[aeiou]` lê enquanto for vogal; `%[^aeiou]` lê enquanto não for.
- **Pegadinhas e erros comuns:** `scanf("%c", s[7])` sem `&`. `scanf("%f", &d)` com `d` double (o próprio livro erra isso numa
  resposta do cap. 8).
- `%s` sem largura em vetor pequeno = estouro.
- Deixar o `'\n'` no buffer e depois ler `%c` (o livro usa `" \n%c"`/`"\n%c"` para pular).
- Pedir muitos dados de uma vez; não pensar no que acontece **quando** (não "se") o usuário
  digitar errado.
- **Ideias de exemplos:** Entrada `-70 -70 070 0x70 70 70 70` com `"%d%i%i%i%o%u%x"` → `-70 -70 56 112 56 70 112`.
- `"Domingo"` lido com `"%c%s"` → `'D'` e `"omingo"`.
- **Ideias de exercícios:** Ler hora `hh:mm:ss` de dois jeitos: com `%*c` e com `:` literal no formato.
- Ler `3.5%` guardando 3.5 num `float` sem usar `*` (resp.: `scanf("%f%%", &p)`).
- Ler uma string entre aspas (`"suzy"`) descartando as aspas (resp.: `"\"%[^\"]\""`).

### 0031-aleatorios
- **Conceitos-chave:** **Adiamento indefinido:** o embaralhamento "natural" do cap. 7 (sorteia linha e coluna até
  achar uma posição vazia) pode demorar sem limite perto do fim, pois quase tudo já foi sorteado.
- Versão melhor (cap. 10): preencha o baralho em ordem e, para cada posição `i`, troque com uma
  posição sorteada; 52 trocas e acabou.
- Truque de índice: carta `i` de 0..51 → face `i % 13`, naipe `i / 13`, cor `i / 26`.
- **Pegadinhas e erros comuns:** A troca "cada `i` com `rand() % 52`" do livro não é perfeitamente uniforme; o correto
  (Fisher–Yates) sorteia `j` entre `i` e o fim.
- Distribuir procurando a carta 1, depois a 2... e continuar procurando depois de achar.
- **Ideias de exercícios:** **Tartaruga e lebre (7.17):** pista de 70 casas; a cada "tique" sorteie 1..10 e mova conforme
  a tabela (tartaruga: 1–5 anda 3, 6–7 volta 6, 8–10 anda 1; lebre: 20% dorme, 20% pula 9,
  10% volta 12, 30% anda 1, 20% volta 2; nunca abaixo da casa 1). Imprima a pista a cada tique.
- Pôquer (7.12): detectar par, dois pares, trinca, quadra, flush e sequência numa mão de 5.

### 0035-escopo
- **Conceitos-chave:** `static` numa global ou função dá **ligação interna**: só o próprio arquivo enxerga. Sem
  `static`, a ligação é externa.
- Globais violam o princípio do menor privilégio; use só para recursos realmente
  compartilhados.
- Protótipo declarado **dentro** de uma função restringe quem pode chamar (o livro põe o
  protótipo de `swap` dentro de `bubbleSort`).
- **Ideias de exemplos:** `static const double PI = 3.14159;` num `.c` utilitário; funções auxiliares `static`.

### 0036-pilha-de-chamadas
- **Conceitos-chave:** A cada chamada, o endereço de retorno e as variáveis automáticas vão para uma pilha (LIFO);
  ao retornar, saem e "deixam de existir". A recursão usa o mesmo mecanismo.
- **Ideias de exemplos:** Usar a própria pilha encadeada do cap. 12 para "imitar" a pilha de chamadas de `reverse`.

### 0037-recursao
- **Conceitos-chave / ideias de exemplos:** `reverse(s)`: se `s[0] == '\0'` retorna; senão chama `reverse(&s[1])` e **depois** imprime
  `s[0]` (a ordem das duas linhas é o que inverte). "apos a sopa" sai igual (palíndromo).
- `insertNode` na BST e os três percursos são recursivos (ver 0103/0104).
- **Ideias de exercícios:** Imprimir lista encadeada de trás para frente recursivamente; buscar recursivamente.
- **Labirinto (7.22):** percorrer uma grade 12×12 de `#` e `.` pelo método "mão direita na
  parede", marcando `X`; gerar labirintos aleatórios (7.23); generalizar o tamanho (7.24).

### 0039-modulos
- **Conceitos-chave:** A definição de uma função fica inteira em **um** arquivo. O `.h` traz protótipos, structs,
  enums; cada `.c` inclui o `.h` de que precisa.
- `make` + `makefile` recompilam só o que mudou.
- Interface × implementação (cap. 16, C++): a interface diz **o que** se pode pedir, não
  **como** é feito.
- **Analogias/explicações boas:** **Rádio:** os botões são a interface (trocar estação, volume); cada fabricante implementa
  por dentro de um jeito. Ótima para introduzir `.h`/`.c`.

### 0040-preprocessador
- **Conceitos-chave:** Diretivas começam com `#` (só espaços/comentários antes na linha).
- `#include <x.h>` procura nos diretórios do sistema; `#include "x.h"` procura primeiro no
  diretório do arquivo.
- Macros com argumento: `#define AREA_CIRCULO(x) ((PI) * (x) * (x))`. **Parênteses em cada
  argumento e em volta de tudo.** Linha longa continua com `\`. `#undef` encerra o escopo.
- Macro × função: macro evita o custo da chamada mas **avalia o argumento mais de uma vez** (e
  não verifica tipos). Hoje `inline`/otimizador resolvem o desempenho.
- Compilação condicional: `#if`, `#ifdef`, `#ifndef`, `#elif`, `#else`, `#endif`,
  `defined(NOME)`. Só expressões inteiras constantes (nada de `sizeof`, cast ou enum).
- `#if 0 ... #endif` "comenta" um trecho que já contém comentários `/* */`.
- `#ifdef DEBUG printf(...); #endif` para depuração ligável.
- `#error` para a compilação com mensagem; `#pragma` depende do compilador.
- `#x` vira string (`#define HELLO(x) printf("Olá, " #x "\n")`); `a##b` cola tokens; literais
  adjacentes são concatenados. `#line`. Pré-definidas: `__LINE__`, `__FILE__`, `__DATE__`,
  `__TIME__`, `__STDC__`.
- `assert(expr)` (`<assert.h>`): se falso, mostra arquivo/linha e aborta; `#define NDEBUG`
  desliga todas. Serve para achar erro de lógica, não para tratar entrada inválida.
- **Pegadinhas e erros comuns:** `AREA_CIRCULO(c + 2)` sem parênteses vira `3.14159 * c + 2 * c + 2`.
- Passar `x++` para uma macro (incrementa duas vezes).
- `printf` de depuração dentro de um `if` sem chaves: quando o `DEBUG` some, o `if` passa a
  controlar outra linha. Use bloco.
- **Ideias de exercícios:** Macros `VOLUME_CUBO(x)`, `MINIMO2(a,b)` e `MINIMO3(a,b,c)` usando `MINIMO2`; mostrar o bug de
  `MINIMO2(i++, j)`.
- Programa que imprime as cinco constantes pré-definidas (atenção: `__STDC__` é inteiro; a
  resposta do livro usa `%s`, o que está errado).

### 0042-vetores / 0043-vetores-e-funcoes
- **Conceitos-chave:** Ao passar um vetor, a função recebe só o endereço do 1º elemento; o tamanho **não vai junto**
  → sempre passe o tamanho (ou ponteiro de início + ponteiro de fim).
- `sizeof(v)/sizeof(v[0])` dá o número de elementos **só no escopo onde o vetor foi
  declarado**; dentro da função, `sizeof(param)` dá o tamanho do ponteiro (o livro mostra 80
  bytes no `main` e 4 dentro de `getSize`).
- Truque curioso: um vetor dentro de uma `struct` é copiado quando a struct é passada por valor.
- **Ideias de exercícios:** Prever a saída de `getSize` (vetor de 20 `float`) no `main` e dentro da função, no seu PC.

### 0045-caracteres
- **Conceitos-chave:** `char` é número; comparar caracteres é comparar códigos (ASCII: `'0'`=48, `'A'`=65,
  `'a'`=97, `'&'`=38). Dígitos vêm antes das maiúsculas, que vêm antes das minúsculas.
- `<ctype.h>`: `isdigit isalpha isalnum isxdigit islower isupper isspace iscntrl ispunct
  isprint isgraph tolower toupper`. Recebem `int` (por causa do `EOF`).
- Retornam "não zero" para verdadeiro — **não necessariamente 1**.
- `toupper` de algo que não é minúscula devolve o mesmo caractere.
- `isprint` inclui o espaço; `isgraph` não. `isspace`: espaço, `\f \n \r \t \v`.
- **Pegadinhas e erros comuns:** Testar `if (isdigit(c) == 1)`.
- Valor numérico de um dígito: `c - '0'`.
- **Ideias de exercícios:** Reescrever as funções de `ctype.h` usando só a tabela ASCII (8.26).
- Ler um caractere e imprimir o retorno de cada função; ler códigos 0..255 e imprimir.

### 0046-strings
- **Conceitos-chave:** String = vetor de `char` terminado em `'\0'`; o "valor" de uma string é o endereço do 1º
  caractere. `char cor[] = "azul";` tem 5 elementos.
- `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, `strlen` (não conta o `'\0'`,
  devolve `size_t`).
- Busca: `strchr`, `strrchr`, `strstr`, `strpbrk`, `strspn`, `strcspn` (devolvem `NULL` se não
  acham). `strtok` quebra em tokens.
- Memória: `memcpy`, `memmove` (aceita sobreposição), `memcmp`, `memchr`, `memset`. Recebem
  `void *` + tamanho em bytes, servem para qualquer tipo.
- Conversões (`<stdlib.h>`): `strtol(s, &resto, base)`, `strtoul`, `strtod` informam onde a
  conversão parou; base 0 detecta `0`/`0x`; bases 2..36.
- `sprintf` escreve formatado numa string; `sscanf` lê de uma string.
- **Analogias/explicações boas:** Ordem alfabética = comparar códigos numéricos letra a letra (por isso "Nunes" < "Silva").
- **Pegadinhas e erros comuns:** `strcmp` devolve **0 quando iguais** (falso!). `if (strcmp(a, b))` significa "diferentes".
  E o valor não é só −1/0/1: o livro mostra `strncmp` devolvendo 6 e −6. Teste o **sinal**.
- `strncpy` **não garante** `'\0'` quando `n <= strlen(origem)`; termine à mão.
- `strcat`: o destino precisa caber as duas strings mais o `'\0'`.
- `strtok` **modifica** a string (troca delimitadores por `'\0'`) e guarda estado entre
  chamadas: 1ª chamada com a string, as seguintes com `NULL`. Copie antes se precisar do
  original.
- `memcpy` com regiões sobrepostas é indefinido; use `memmove`.
- `atoi`/`atof` não avisam erro ("abc" vira 0) → prefira `strtol`/`strtod`.
- Esquecer o espaço do `'\0'`; imprimir vetor sem `'\0'`.
- **Ideias de exemplos:** `strtol("-1234567abc", &resto, 0)` → −1234567, resto `"abc"`.
- `strtod("51.2% admitidos", &resto)` → 51.2, resto `"% admitidos"`.
- `strstr("abcdefabcdef", "def")` → `"defabcdef"`; `strrchr(frase, 'z')` → `"zebras"`.
- `memset(s, 'b', 7)` em `"BBBBBBBBBBBBBB"` → `"bbbbbbbBBBBBBB"`.
- `strcspn("O valor 3.14", "0123456789")` → 8 (tamanho do trecho inicial sem dígitos).
- **Ideias de exercícios:** Reescrever `strlen`, `strcpy`, `strcat`, `strcmp` em duas versões: índice e ponteiro (8.28–8.33).
- Contar ocorrências de uma substring com `strstr` avançando `p + 1` (8.16–8.17).
- Contar palavras com `strtok`; imprimir as palavras de uma frase em ordem inversa.
- "Falso latim": 1ª letra vai para o fim + "ei" (`salto` → `altosei`).
- Telefone `(55) 5555-5555` → código de área `int` e número `long` com `strtok`.
- Frequência de letras; tabela de tamanhos de palavra; datas `21/07/2011` → `21 de julho de
  2011`; valor de cheque por extenso; codificador/decodificador Morse.
- Ordenar 10 nomes de cidades com `strcmp` + bubble sort.

### 0047-lendo-strings
- **Conceitos-chave:** `fgets(s, n, stdin)` lê no máximo `n - 1` caracteres, para no `'\n'` (e **o inclui**) e põe
  `'\0'`.
- `scanf("%s")` para no primeiro espaço; use `%19s` para `char s[20]`.
- `%[^\n]` lê até o fim da linha (scanset invertido).
- Leitura caractere a caractere: `while ((c = getchar()) != '\n') s[i++] = c; s[i] = '\0';`.
- **Pegadinhas e erros comuns:** O laço de `getchar` do livro não confere o limite do vetor nem o `EOF`, e guarda `c` num
  `char`: bom para pedir "ache os 3 bugs".
- O livro menciona `gets` no início do cap. 9 sem alertar; ver "Obsoleto".

### 0049-memoria / 0050-ponteiros
- **Conceitos-chave:** Ponteiro é uma variável cujo valor é um endereço; acessar um valor através dele é
  **indireção**. `&` dá o endereço; `*` desreferencia. `&*p` e `*&p` dão o mesmo.
- `int *a, b;` → só `a` é ponteiro (o `*` não "distribui").
- Inicialize ponteiros: `NULL`, `0` ou um endereço. O único inteiro atribuível é 0.
- `&` não se aplica a constantes, expressões nem variáveis `register`.
- `%p` imprime endereço (formato depende da implementação, em geral hex).
- **Analogias/explicações boas:** Referência direta (o nome) × indireta (o ponteiro "aponta" para a caixa que contém 7).
- Diagrama com endereços fictícios (`y` em 600000, `yPtr` em 500000 guardando 600000).
- **Pegadinhas e erros comuns:** Desreferenciar ponteiro não inicializado: pode travar ou, pior, rodar com dados corrompidos.
- O livro sugere sufixo `Ptr` no nome (`countPtr`): convenção útil no começo.
- **Ideias de exercícios:** Sequência guiada (7.4): declarar `float *fPtr`, apontar para `n1 = 7.3`, imprimir `*fPtr`,
  copiar para `n2`, imprimir `&n1` e `fPtr` com `%p` e comparar.
- Achar o erro: `int *n; printf("%d", *n);`, `float *r; long *i; i = r;`, `int *x, y; x = y;`,
  `char *s; printf("%s", s);`.

### 0051-passagem-por-referencia
- **Conceitos-chave:** **Em C tudo é passado por valor**; "por referência" é simulado passando o endereço.
- `cuboPorValor(n)` devolve o resultado com `return`; `cuboPorReferencia(&n)` faz
  `*p = *p * *p * *p`.
- No parâmetro, `int b[]` e `int *b` são a mesma coisa.
- Elemento isolado de vetor é escalar → vai por valor; para trocar, `swap(&v[j], &v[j+1])`.
- Structs grandes: passe ponteiro para `const` (desempenho de referência + segurança de valor).
- **Ideias de exemplos:** Diagrama em 5 etapas (antes da chamada, dentro, depois do cálculo, retorno, atribuição)
  para valor e em 3 etapas para referência: vale redesenhar.
- **Pegadinhas e erros comuns:** Passar um valor onde se espera ponteiro (o compilador pode só avisar; roda e dá segfault).

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** Aritmética: `p++`, `p--`, `p + n`, `p - n`, `p2 - p1`. Somar `n` avança `n * sizeof(*p)` bytes.
- Com `int v[5]` em 3000 e `int` de 4 bytes, `vPtr += 2` dá 3008; se `v2Ptr` = 3008 e
  `vPtr` = 3000, `v2Ptr - vPtr` = **2** (elementos, não bytes).
- Quatro notações equivalentes: `b[3]`, `*(b + 3)`, `bPtr[3]`, `*(bPtr + 3)`. `&b[3]` = `b + 3`.
- O nome do vetor é um ponteiro **constante**: `b += 3` e `b++` são erro.
- Comparar/subtrair ponteiros só faz sentido dentro do mesmo vetor; comparar com `NULL` é o
  uso mais comum.
- **Pegadinhas e erros comuns:** `*bPtr + 3` (soma 3 ao valor) × `*(bPtr + 3)`: `*` tem precedência maior que `+`.
- Aritmética em ponteiro que não aponta para vetor; passar do fim; supor que duas variáveis
  vizinhas no código estão vizinhas na memória.
- **Ideias de exemplos:** `copia1` com índice (`for (i = 0; (d[i] = o[i]) != '\0'; i++);`) e `copia2` com ponteiro
  (`for (; (*d = *o) != '\0'; d++, o++);`): corpo vazio, a cópia acontece na condição.
- **Ideias de exercícios:** `float numeros[10]` = 0.0, 1.1, ..., 9.9 começando em 1002500, `float` de 4 bytes: que
  endereço tem `nPtr + 8` e qual valor? (resp.: 1002532, 8.8). Com `nPtr` em `numeros[5]`,
  `nPtr -= 4`? (resp.: 1002504, 1.1).
- Imprimir o vetor das quatro maneiras. Achar o erro em `for (i = 0; i <= 5; i++) zPtr[i]`
  e em `++z` (z é vetor).
- "O que faz?" `mystery1` (anda até o `'\0'` de s1 e copia s2 → é um `strcat`); `mystery2`
  (conta até o `'\0'` → `strlen`); `mystery3` (compara caractere a caractere; tem bug: diz
  "iguais" quando uma é prefixo da outra).

### 0053-ponteiros-e-strings
- **Conceitos-chave:** `char cor[] = "azul";` cria um vetor modificável; `const char *p = "azul";` aponta para um
  literal que pode estar em memória só de leitura → se for alterar, use vetor.
- **Vetor de ponteiros** para strings (`const char *naipe[4] = {"Copas", ...}`): só os
  ponteiros ficam no vetor; cada string tem o tamanho que precisa. Matriz 2D desperdiçaria
  (todas as linhas com o tamanho da maior).
- `const` com ponteiros, lido **da direita para a esquerda**:
  - `char *p` → muda o ponteiro e os dados (ex.: converter para maiúsculas);
  - `const char *p` → muda o ponteiro, não os dados (ex.: imprimir caractere a caractere);
  - `int *const p` → dados mudam, ponteiro fixo (é o que o nome de um vetor é);
  - `const int *const p` → nada muda.
- Princípio do menor privilégio: dê à função só o acesso de que ela precisa.
- **Pegadinhas e erros comuns:** Tratar um `char` como string (`printf("%s", 'a')`) → endereço baixo inválido.
- Ponteiro `const` precisa ser inicializado na definição.
- **Ideias de exercícios:** Escrever `maiusculas(char *s)` e `imprime(const char *s)`; tentar alterar `*s` na segunda e
  ler a mensagem de erro do compilador.
- Sentenças aleatórias com 4 vetores de `char *` (artigo, substantivo, verbo, preposição),
  maiúscula inicial e ponto final (8.11).

### 0055-ponteiro-para-funcao
- **Conceitos-chave:** O nome de uma função é o endereço do seu código. Ponteiros para função podem ser passados,
  devolvidos, guardados em vetores e atribuídos.
- `int (*compara)(int, int)` → ponteiro para função; sem os parênteses, `int *compara(int,int)`
  declara uma função que devolve `int *`.
- Chamada: `(*compara)(a, b)` ou simplesmente `compara(a, b)`.
- **Menu com vetor de ponteiros para função:** `void (*f[3])(int) = {f1, f2, f3};` e
  `(*f[op])(op);` (validar `0 <= op < 3`). Todas as funções precisam ter a mesma assinatura.
- **Ideias de exemplos:** Bubble sort genérico: `bubble(v, n, crescente)` ou `bubble(v, n, decrescente)`, com
  `crescente` devolvendo `b < a` ("precisa trocar?").
- **Ideias de exercícios:** Calculadora com menu: vetor de 4 ponteiros `void op(double, double)` (soma, sub, mul, div).
- Círculo: circunferência, área, volume da esfera via vetor de ponteiros `void f(double)`.
- Reescrever o menu de notas (mínimo, máximo, médias) uniformizando as assinaturas.

### 0056-void-generico
- **Conceitos-chave:** `void *` recebe e é atribuído a qualquer ponteiro de dado sem cast (em C).
- Não pode ser desreferenciado: o compilador não sabe quantos bytes ler. Converta antes:
  `*(int *)p`.
- Por isso `memcpy`/`memset`/`malloc` usam `void *` + tamanho em bytes.
- **Pegadinhas e erros comuns:** Atribuir ponteiros de tipos diferentes (nenhum `void *`) é erro.

### 0058-pilha-e-heap / 0059-malloc-free
- **Pilha × heap (pouco no livro):** automáticas vivem na pilha e somem no retorno; o que vem
  de `malloc` dura até o `free`, limitado pela memória disponível.
- **Conceitos-chave:** `p = malloc(sizeof(struct no));` devolve `void *`; **memória não inicializada**; `NULL` se
  faltar memória. `free(p)` devolve.
- `sizeof` de uma struct não é a soma dos membros (alinhamento, "buracos"): sempre `sizeof`.
- **Pegadinhas e erros comuns (caixas do livro):** Não testar `NULL`. Não liberar (vazamento). Liberar o que não veio de `malloc`. Usar
  memória já liberada.

### 0060-calloc-realloc
- **Conceitos-chave:** `calloc(n, tam)` aloca `n` elementos e **zera**. `realloc(p, novo)` muda o tamanho
  preservando o conteúdo até o menor dos dois tamanhos; `realloc(NULL, n)` = `malloc`;
  `realloc(p, 0)` libera; se falhar devolve `NULL` e o bloco original fica intacto.
- O ponteiro devolvido pode ser indexado como vetor ("vetor dinâmico").
- **Pegadinhas e erros comuns:** `p = realloc(p, n)` perde o bloco original se falhar → use um temporário.
- **Ideias de exercícios:** Ler `n`, alocar `n` inteiros, preencher, imprimir, reduzir para `n/2` com `realloc` e
  conferir que a primeira metade se manteve (14.7).

### 0062-erros-de-memoria
- O livro lista: vazamento, uso após `free`, `free` de memória não dinâmica, não testar
  `NULL`, último nó sem `NULL` (estrutura "sem fim"). Não fala de valgrind/ASan nem de free
  duplo. Exercício bom: pegar o laço de liberação de lista da resposta 12.4(e), em que o
  `free(tempPtr)` saiu do laço por erro de diagramação, e pedir para achar o vazamento.

### 0064-struct
- **Conceitos-chave:** Struct (agregação) junta membros de tipos diferentes; a declaração cria um **tipo**, não
  reserva memória. Termina com `;`.
- Pode conter vetores e outras structs, mas **não uma instância de si mesma**; pode conter um
  ponteiro para o próprio tipo (struct autorreferenciada, base das listas).
- Operações válidas: atribuir struct do mesmo tipo, `&`, acessar membros, `sizeof`. **Não**
  pode comparar com `==`/`!=` (há bytes de preenchimento com lixo).
- Inicialização com chaves; membros que faltam viram 0/`NULL`. Globais começam zeradas.
- Struct é passada **por valor** (cópia inteira). Para alterar ou economizar cópia, passe
  ponteiro.
- **Analogias/explicações boas:** Hierarquia de dados (cap. 11): bit → byte/caractere → campo → registro (struct) → arquivo →
  banco de dados. Liga struct com arquivos.
- **Pegadinhas e erros comuns:** Esquecer o `;` final. Comparar structs com `==`. Achar que struct vai por referência como
  vetor. Atribuir struct de um tipo a outra de tipo diferente.
- **Ideias de exercícios:** Definir `estoque`, `endereco`, `aluno` (com `endereco` aninhado) e escrever os acessos
  aninhados `reg.pessoal.telefone` e `p->pessoal.telefone`.
- `PerfilSaude` (nome, sexo, data de nascimento, altura, peso) + funções de idade e IMC.

### 0065-typedef
- `typedef struct carta Carta;` ou `typedef struct { ... } Carta;`. Cria **sinônimo**, não
  tipo novo. Maiúscula inicial por convenção. Útil para portabilidade (`typedef int Inteiro4;`).
- `typedef ListNode *ListNodePtr;` aparece no cap. 12. (Esconder ponteiro em typedef costuma
  confundir iniciantes; decidir a convenção do curso.)

### 0066-vetor-de-structs
- Baralho como `Carta deck[52]`; embaralhar trocando structs inteiras (`temp = d[i]; d[i] =
  d[j]; d[j] = temp;`); distribuir numa passada. Erro comum: esquecer o índice
  (`copas.face` em vez de `copas[10].face`).

### 0067-ponteiro-para-struct
- **Conceitos-chave:** `p->m` é o mesmo que `(*p).m`; os parênteses são obrigatórios porque `.` tem precedência
  maior que `*`. `-` e `>` sem espaço entre eles.
- **Pegadinhas e erros comuns:** `*p.m` é erro. `*p->face` desreferencia o **char** (imprime lixo com `%s`). A "correção" do
  próprio livro, `(*cPtr)->face`, está errada: o certo é `cPtr->face` ou `(*cPtr).face`.
- **Ideias de exercícios:** Com `Peca b[10]` e `ptr = b`, imprimir o elemento 3 por `ptr` (resp.: `(ptr + 3)->num` ou
  `ptr[3].num`).

### 0068-enum
- Constantes inteiras com nome; começam em 0 e sobem de 1, a não ser que se atribua
  (`enum meses {JAN = 1, FEV, ..., DEZ}` → 1..12). Nomes únicos; valores podem repetir; não se
  atribui depois. Maiúsculas.
- Exemplo: laço `for (m = JAN; m <= DEZ; m++)` indexando `nomeMes[m]` com `nomeMes[0] = ""`.

### 0069-union
- **Conceitos-chave:** Membros **compartilham** o mesmo espaço; tamanho ≥ maior membro. Só um membro "vale" por vez;
  quem controla é o programador. Inicializa só com o tipo do **primeiro** membro.
- Operações: atribuição, `&`, `.` e `->`; não compara.
- **Ideias de exemplos:** `union numero {int x; double y;}`: grava `x = 100` e lê `y` (lixo enorme); grava `y = 100.0`
  e lê `x` (0 no livro). Mostra que `int` e `double` têm representações diferentes.
- **Ideias de exercícios:** `union inteiro {char c; short s; int i; long l;}`: guardar em um, imprimir como todos;
  "os valores saem certos sempre?".

### 0070-bits
- **Conceitos-chave:** `&` (os dois 1), `|` (algum 1), `^` (exatamente um 1), `~` (inverte), `<<` (entra 0 à
  direita), `>>` (em `unsigned` entra 0; em `signed` depende da máquina). Use `unsigned`.
- **Máscara**: valor com bits escolhidos em 1; `&` com máscara isola bits, `|` liga bits.
- Imprimir bits: máscara `1u << 31`, testa `valor & mascara`, desloca `valor <<= 1`, espaço a
  cada 8. Portável: `CHAR_BIT * sizeof(unsigned) - 1` (`<limits.h>`).
- `&= |= ^= <<= >>=`.
- **Campos de bit** em struct: `unsigned face : 4; unsigned naipe : 2; unsigned cor : 1;`.
  Campo sem nome = preenchimento; largura 0 = pula para a próxima unidade. Sem endereço (`&`),
  não são "vetor de bits", dependem da máquina; economizam espaço mas geram código mais lento.
- **Pegadinhas e erros comuns:** `&&` no lugar de `&`, `||` no lugar de `|`.
- Precedência: `&`, `^`, `|` ficam **abaixo** de `==` → `x & 1 == 0` é `x & (1 == 0)`.
- Deslocar por quantidade negativa ou ≥ número de bits: indefinido.
- O livro se contradiz: a figura mostra `960 << 8` = 245760 e o texto diz 49152 (o certo é
  245760).
- **Ideias de exemplos:** `65535 & 1` = 1; `15 | 241` = 255; `139 ^ 199` = 76; `~21845` (32 bits) = 4294945450;
  `960 >> 8` = 3; `65000` = `00000000 00000000 11111101 11101000`.
- **Ideias de exercícios:** `potencia2(n, p)` = `n << p` (= n·2ᵖ), imprimindo em bits.
- Compactar dois `char` num `unsigned` (`(a << 8) | b`) e descompactar com máscaras 65280 e
  255; depois 4 caracteres.
- Inverter a ordem dos bits; contar bits 1 e dizer a paridade ("o que faz?" 10.20).
- "Qual é X?" (10.19): a função testa se os 10 bits baixos são zero → X = 1024.

### 0072-arquivos-texto
- **Conceitos-chave:** Para o C, arquivo = sequência de bytes com marca de fim; o "registro" é convenção sua.
- `FILE *f = fopen(nome, modo)`; `NULL` se falhar (não existe, sem permissão, disco cheio).
  `fclose(f)` assim que não precisar mais.
- Modos: `r`, `w` (cria ou **apaga sem aviso**), `a` (acrescenta), `r+`, `w+` (apaga), `a+`.
- `fprintf`, `fscanf`, `fgetc`, `fputc`, `fgets`, `fputs`. `stdin`, `stdout`, `stderr` já vêm
  abertos (`fprintf(stdout, ...)` funciona; `fgetc(stdin)` = `getchar()`).
- `rewind(f)` volta ao byte 0. A "posição do arquivo" é um número dentro de `FILE`.
- Arquivo texto sequencial **não se atualiza no lugar**: trocar "White" por "Worthington"
  sobrescreve o próximo registro, porque os campos de texto têm tamanho variável. Reescreve-se
  o arquivo todo.
- Fim de arquivo no teclado: Ctrl+D (Linux/Mac), Ctrl+Z (Windows).
- **Analogias/explicações boas:** `FILE *` → estrutura `FILE` → descritor → tabela de arquivos abertos do SO → bloco de
  controle. Só para mostrar que o `FILE *` é um "crachá", não o arquivo.
- **Pegadinhas e erros comuns:** `while (!feof(f))` com a leitura no fim do laço funciona; com a leitura no começo processa a
  última linha duas vezes, porque `feof` só fica verdadeiro **depois** de uma leitura falhar.
  Ensinar `while (fscanf(f, "%d%s%lf", ...) == 3)`.
- `w` no lugar de `r+`/`a` apaga tudo. Ponteiro de arquivo trocado. `open` não é C padrão.
- **Ideias de exemplos:** `clientes.txt`: `100 Jones 24.98 / 200 Doe 345.67 / 300 White 0.00 / 400 Stone -42.16 /
  500 Rich 224.62`; consulta de crédito com menu (saldo zero / negativo / positivo) usando
  `rewind` entre as consultas.
- **Ideias de exercícios:** **Atualização mestre × transações (11.7–11.10):** dois arquivos ordenados por conta; somar
  transações ao mestre, copiar contas sem transação, avisar transação sem conta, permitir
  várias transações por conta. Dados de teste prontos no livro.
- Copiar arquivo trocando `\t` por espaço; contar palavras de phishing num arquivo.

### 0073-arquivos-binarios
- **Conceitos-chave:** `fwrite(&x, sizeof(int), 1, f)` sempre grava `sizeof(int)` bytes (com `fprintf` seriam de
  1 a 11 caracteres). `fread` análogo. O 3º argumento é o número de elementos (vale vetores).
- Registros de tamanho fixo → posição calculada pela chave:
  `fseek(f, (conta - 1) * sizeof(struct cliente), SEEK_SET)`. `SEEK_SET`, `SEEK_CUR`,
  `SEEK_END`.
- Criar o arquivo com N registros vazios (`{0, "", "", 0.0}`); "apagar" = regravar vazio;
  "existe?" = `conta != 0`.
- Retornos: `fread`/`fwrite` devolvem quantos itens; `fseek` devolve ≠ 0 em erro; `fscanf`
  devolve itens lidos ou `EOF`.
- Binário é mais rápido e compacto, mas os bytes dependem da máquina/compilador; texto é
  portável e legível com qualquer editor.
- **Analogias/explicações boas:** **Trem de carga:** todos os vagões do mesmo tamanho, alguns vazios; o vagão n começa em
  n × tamanho. Ótima para `fseek`.
- **Ideias de exercícios:** Sistema de contas (11.10): menu gerar relatório texto / atualizar saldo / incluir / excluir,
  sobre `credito.dat` aberto em `rb+`.
- Inventário de ferramentas `ferragens.dat` com 100 registros (dados iniciais no livro).

### 0074-argumentos
- **Conceitos-chave:** `int main(int argc, char *argv[])`; `argv[0]` é o nome do programa (conta em `argc`).
- Redirecionamento é do **sistema operacional**, não do C: `prog < entrada`, `prog > saida`,
  `prog >> saida`, `gera | soma`. Programa que lê `stdin` até `EOF` já funciona com arquivos.
- `exit(EXIT_SUCCESS)`/`exit(EXIT_FAILURE)` terminam de qualquer ponto.
- **Ideias de exemplos:** `copia origem destino`: confere `argc == 3`, abre os dois, `while ((c = fgetc(in)) != EOF)
  fputc(c, out);` (com `c` do tipo `int`).
- **Ideias de exercícios:** Imprimir todos os argumentos; ordenar um vetor com opção `-c`/`-d`; copiar arquivo
  invertido.

### 0077-big-o
- Busca numa BST balanceada: no máximo log₂ n comparações (1.000 itens → 10; 1.000.000 → 20).
- Inserir/remover no meio de vetor ordenado exige deslocar tudo; vetor tem acesso direto por
  cálculo de endereço, lista não.
- Exercício 12.18: eliminar duplicatas com vetor × com BST e comparar os custos.

### 0079-tad
- **Conceitos-chave (cap. 18, parte C++, mas a ideia é de C):** TAD = representação dos dados + operações permitidas. O próprio `int` é um TAD: aproxima o
  inteiro matemático com faixa limitada.
- O cliente de uma pilha/fila só quer saber **o que** ela faz (push/pop, enqueue/dequeue), não
  **como**; a implementação pode trocar sem afetar o resto. O TAD protege sua estrutura
  interna: operações fora da interface não existem para o cliente.
- Funções com erro comum devem devolver um código (0, `NULL`) em vez de abortar (cap. 24).

### 0081-lista-encadeada / 0082-lista-busca-remocao / 0083-lista-ordenada
- **Conceitos-chave:** Nó = dado + ponteiro para o próximo; acesso pelo ponteiro do 1º nó; último aponta `NULL`.
- Vantagens sobre vetor: tamanho imprevisível, cresce e encolhe, não desperdiça; desvantagens:
  sem acesso direto, ponteiros ocupam espaço, custo de cada `malloc`.
- Funções que mudam a cabeça recebem **ponteiro para ponteiro** (`ListNodePtr *sPtr`):
  indireção dupla. `isEmpty` é uma "função predicado".
- **Inserção ordenada:** `ant = NULL; atual = *lista;` avança enquanto `atual != NULL &&
  valor > atual->dado`; se `ant == NULL` insere no início, senão entre `ant` e `atual`.
- **Remoção:** se é o primeiro, guarda em `temp`, avança a cabeça, `free(temp)`; senão percorre
  com `ant`/`atual`, faz `ant->prox = atual->prox` e libera.
- **Analogias/explicações boas:** As figuras "antes/depois" com as setas tracejadas que mudam (inserir 'C' entre 'B' e 'D';
  remover 'C') valem reproduzir como diagramas.
- **Pegadinhas e erros comuns:** Esquecer `novo->prox = NULL`. Perder a cabeça por não passar `&lista`.
- A `delete` do livro acessa `(*sPtr)->data` sem testar lista vazia (o `main` testa antes):
  bom exercício de robustez.
- **Ideias de exercícios:** Concatenar duas listas; **mesclar duas listas ordenadas**; inserir 25 aleatórios em ordem e
  calcular soma e média; criar uma cópia invertida; imprimir de trás para frente
  (recursivo); busca recursiva que devolve ponteiro ou `NULL`.
- Traço de mesa (12.4): lista Jones → Smith; inserir Adams, Thompson e Pritchard dizendo para
  onde `ant` e `atual` apontam em cada caso (início: `ant == NULL`; fim: `atual == NULL`;
  meio: entre Jones e Smith).

### 0087-pilha / 0088-pilha-encadeada
- **Conceitos-chave:** Pilha = lista com inserção e remoção só no topo (LIFO). Mesma representação da lista.
- `push`: novo nó aponta para o topo antigo; topo passa a ser o novo.
- `pop`: guarda o topo em `temp`, salva o valor, topo avança, `free(temp)`, devolve o valor.
- Aplicações: endereços de retorno e variáveis automáticas das chamadas; avaliação de
  expressões pelo compilador.
- **Pegadinhas e erros comuns:** `pop` do livro não testa pilha vazia (quem testa é o `main`).

### 0089-pilha-aplicacoes
- **Conceitos-chave / exercícios:** **Infixa → pós-fixa (12.12):** empilhe `(` e acrescente `)` ao fim; dígito vai direto para a
  saída; `(` empilha; operador: desempilha para a saída enquanto o topo tiver precedência
  maior ou igual, depois empilha; `)` desempilha até o `(` e o descarta.
  `(6 + 2) * 5 - 8 / 4` → `6 2 + 5 * 8 4 / -`.
- **Avaliar pós-fixa (12.13):** dígito empilha `c - '0'`; operador desempilha `x` (topo) e
  depois `y` e empilha `y op x` (a ordem importa em `-` e `/`). Extensão: números com mais de
  um dígito.
- Inverter uma linha com pilha; testar palíndromo ignorando espaços e pontuação.

### 0090-fila / 0091-fila-encadeada
- **Conceitos-chave:** FIFO com dois ponteiros: cabeça (sai) e cauda (entra). Aplicações: processos esperando a
  CPU, fila de impressão (spool), pacotes num roteador.
- `enqueue`: novo nó com `prox = NULL`; se vazia, cabeça = novo, senão `cauda->prox = novo`;
  cauda = novo.
- `dequeue`: guarda valor, `temp = cabeça`, cabeça avança; **se a cabeça virou `NULL`, a cauda
  também vira `NULL`**; libera; devolve.
- **Analogias/explicações boas:** Fila do caixa do supermercado.
- **Pegadinhas e erros comuns:** Esquecer de zerar a cauda quando a fila esvazia (próximo `enqueue` escreve em nó liberado).
- **Ideias de exercícios:** **Simulação de supermercado (12.15):** clientes chegam a cada 1–4 min e são atendidos em
  1–4 min, por 720 min; medir o maior tamanho de fila e a maior espera; repetir com chegada
  de 1–3 min e observar a fila crescer sem parar.

### 0096-bubble-sort / 0101-comparando
- Bubble sort com `swap(&v[j], &v[j+1])` e protótipo de `swap` dentro de `bubbleSort`;
  parâmetros `int *const v` e `const int n` (menor privilégio).
- Versão com ponteiro para função de comparação (crescente/decrescente) → prepara o `qsort`.

### 0102-arvores / 0103-arvore-binaria
- **Conceitos-chave:** Árvore é não linear; na binária cada nó tem dois links (qualquer um pode ser `NULL`). Raiz,
  filho esquerdo/direito, subárvores, irmãos, folha, pai. Desenha-se de cima para baixo.
- Percursos recursivos: **em ordem** (esq, nó, dir), **pré-ordem** (nó, esq, dir), **pós-ordem**
  (esq, dir, nó).
- **Por nível (12.24):** não recursivo, usa fila: enfileira a raiz; enquanto houver nós,
  desenfileira, imprime, enfileira os filhos não nulos.
- **Imprimir a árvore deitada (12.25):** em ordem invertida (direita, nó, esquerda), com
  recuo `espacos + 5` a cada nível.
- **Ideias de exemplos:** Árvore 27 / 13 42 / 6 17 33 48: em ordem `6 13 17 27 33 42 48`; pré `27 13 6 17 42 33 48`;
  pós `6 17 13 33 48 42 27`.
- **Ideias de exercícios:** Árvore de 15 nós 49 / 28 83 / 18 40 71 97 / 11 19 32 44 69 72 92 99 → dar os três percursos
  (resp.: em ordem `11 18 19 28 32 40 44 49 69 71 72 83 92 97 99`; pré `49 28 18 11 19 40 32
  44 83 71 69 72 97 92 99`; pós `11 19 18 32 44 40 28 69 72 71 92 99 97 83 49`).
- `profundidade(raiz)` (número de níveis).

### 0104-bst-busca-insercao
- **Conceitos-chave:** BST: tudo à esquerda é menor que o pai, tudo à direita é maior. O formato depende da ordem
  de inserção. **Insere-se sempre como folha.**
- `insere(&raiz, v)` recursivo: se `*raiz == NULL` aloca e preenche (filhos `NULL`); se menor
  desce `&(*raiz)->esq`; se maior, `&(*raiz)->dir`; se igual, descarta (duplicatas somem
  sozinhas).
- O percurso em ordem sai ordenado ("ordenação por árvore binária").
- **Ideias de exemplos:** Inserção de 6 7 4 12 7 2 2 5 7 11 (duplicatas ignoradas) → pré `6 4 2 5 7 12 11`; em ordem
  `2 4 5 6 7 11 12`; pós `2 5 4 11 12 7 6`.
- **Ideias de exercícios:** `buscaBST(raiz, chave)` devolvendo ponteiro ou `NULL`; BST de palavras com `strtok`;
  versão que aceita duplicatas.

### 0105-bst-remocao
- Exercício 12.22 descreve os três casos: folha (pai aponta `NULL`), um filho (pai aponta
  para o neto), dois filhos (substituto = maior da subárvore esquerda, o nó "mais à direita",
  ou menor da direita), com o passo a passo de religação para o substituto folha ou com filho
  esquerdo. Bom roteiro para a aula; pedir os três percursos depois de cada remoção.

## Obsoleto / evitar

- **`gets`**: citado no cap. 9 como função de entrada sem nenhum alerta. Nunca usar.
- **`while (!feof(f))`** como laço de leitura (caps. 11 e 14). Testar o retorno da leitura.
- **`atoi`/`atof`/`atol`** sem detecção de erro; preferir `strtol`/`strtod`.
- **`%n`** (risco de segurança; desativado no MSVC) e **`register`**.
- Suposições de **32 bits** (int e ponteiro de 4 bytes, `long` de 4, `1 << 31` para a máscara);
  usar `sizeof`, `CHAR_BIT`, `unsigned`.
- `f()` sem `void` nos protótipos: em C isso **desliga a verificação de argumentos** (nota do
  cap. 15). Sempre `f(void)`.
- `tmpfile` (o livro avisa que a Microsoft o retirou); `goto` fora de saída de laços
  aninhados; embaralhamento por "sorteia até achar vazio".
- Erros do próprio livro para **não** reproduzir (e que rendem exercícios de "ache o erro"):
  - `(*cPtr)->face` dado como correção (o certo é `cPtr->face`).
  - `sscanf(..., "%f%f%f", &d, &e, &f)` com `double`; `scanf("%d%25s", ..., &a.nome)` com `&`
    em vetor.
  - `printf("__STDC__ = %s", __STDC__)` (é inteiro).
  - Texto diz `960 << 8 = 49152`; o certo é 245760.
  - Saída de `memmove(x, &x[5], 10)` impressa igual à entrada.
  - Laço de liberação de lista com `free` fora do laço (resposta 12.4e).
  - "3 elevado à sétima = 2187 palavras" para telefone de 8 dígitos (seriam 3⁸ = 6561).
  - Códigos com nomes trocados no meio (`embaralha`/`shuffle`, `naipe` duas vezes,
    `contador`/`count`).

## Extras que não cabem no sumário

- **Listas de argumentos variáveis** (`<stdarg.h>`): `va_list`, `va_start(ap, ultimoFixo)`,
  `va_arg(ap, double)`, `va_end`. Exemplo: `media(4, w, x, y, z)` com 37.5, 22.5, 1.7, 10.2 →
  17.975. `printf` descobre os tipos pelos especificadores. Exercício: `produto(n, ...)`.
- **`exit` e `atexit`**: registra até 32 funções sem parâmetro, chamadas em ordem inversa no
  término normal; `exit` também fecha os streams.
- **Sinais** (`<signal.h>`): `signal(SIGINT, trata)`, `raise`, `SIGABRT SIGFPE SIGILL SIGINT
  SIGSEGV SIGTERM`; tratar Ctrl+C perguntando se continua.
- **`volatile`**: impede otimizações; a variável pode mudar "por fora" (hardware, outro
  programa).
- **`inline`**: C++ e C99; sugere ao compilador expandir funções pequenas; troca tamanho do
  executável por velocidade. Alternativa moderna às macros-função.
- **Arquivo temporário** (`tmpfile`, modo `wb+`) e técnica "copia para o temporário, volta
  para o original".
- **Sudoku (apêndice D):** validação de linhas/colunas/blocos 3×3 numa matriz 10×10 ignorando
  a linha/coluna 0; estratégias (singletons, duplas, triplas, ocultas); força bruta com
  retrocesso; heurística "manter opções abertas"; gerar tabuleiros por permutações aleatórias
  de linhas; esvaziar células simetricamente (`s[10-l][10-c]`). Projeto grande para matrizes
  e recursão.
- **Projeto "construa seu compilador"** (cap. 12): linguagem tipo BASIC traduzida para SML e
  executada no Simpletron (enunciados só no site da editora).
- **C++ (caps. 15–24):** nada entra no LPEDC; aproveitei a analogia do rádio, o TAD e `f()` × `f(void)`.
- **Não encontrado neste material:** C99 (`bool`, `long long`, `stdint.h`, VLA, `restrict`,
  `//`, inicializadores designados), gdb, valgrind/ASan, hash, grafos, merge/quick sort,
  AVL, heap.
