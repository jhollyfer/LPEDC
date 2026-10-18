# Fichamento — *Linguagem C Completa e Descomplicada*

- **Autor:** André Backes (FACOM-UFU)
- **Editora/ano:** Elsevier, 2013 (≈ 370 p.). Arquivo lido: versão .md convertida (10.817 linhas, lidas integralmente).
- **Estrutura do livro:** 1 Introdução (Code::Blocks, esqueleto, compilação, bibliotecas) · 2 Variáveis, printf/scanf, escopo, constantes · 3 Operadores · 4 Condicionais · 5 Laços (+ goto) · 6 Arrays · 7 Strings · 8 struct/union/enum/typedef · 9 Funções e recursão · 10 Ponteiros · 11 Alocação dinâmica · 12 Arquivos · 13 Avançado (printf/scanf completos, classes de armazenamento, volatile, campos de bits, variádicas, argc/argv, ponteiro p/ função, pré-processador) · 14 C99 · 15 Apêndice (bases numéricas, ASCII).

**Avaliação geral.** Ótima espinha dorsal para a parte de C: didático, linear, cheio de "avisos" (caixas de lembrete) que já são pegadinhas prontas, figuras de memória com endereços fictícios (#120, #122...) que viram ótimas analogias, e listas de exercícios longas (15–20 por capítulo, sem gabarito). **Pontos fracos:** é de 2013 e centrado em Windows/Code::Blocks (`system("pause")` em todo exemplo); recomenda práticas hoje condenadas (`gets`, `fflush(stdin)`, `setbuf(stdin,NULL)`, `while(!feof(f))`); várias imprecisões técnicas (tamanhos de tipos "fixos", "nome do array é um ponteiro", `%f` para ler `double`, extensões GCC apresentadas como C99). Usar a didática e a ordem, mas **revisar cada afirmação técnica** com o padrão (C11/C17) e gcc no Linux. Não cobre: estruturas de dados (listas, pilhas, filas, árvores, hash, grafos), análise de algoritmos, ordenação/busca (só exercícios), `rand/srand`, valgrind/ASan.

---

## 00 · Lógica antes do código

### 0003-fluxograma
- **Conceitos-chave:** o livro usa fluxogramas só como apoio visual: o losango é a decisão sim/não; no laço, a seta volta para o losango ao fim do bloco. Cada comando de controle (if, if-else, if aninhado, switch com/sem break, while, for, do-while, break, continue) ganha um fluxograma desenhado *sobre o próprio código C*.
- **Boa ideia:** desenhar o fluxograma com as linhas de código dentro das caixas — liga o diagrama ao C sem passar por notação abstrata.
- **Exemplo:** pseudocódigo "Leia A e B; enquanto A < B: A ← A+1; imprima A" lado a lado com o fluxograma.

### 0004-binario
- **Conceitos-chave (Cap. 15 + 2.1.3 + 3.5):** número posicional = soma de dígito × base^posição (da direita, começando em 0). Decimal→base b por divisões sucessivas, lendo os restos de baixo para cima. Hex↔binário: cada dígito hex = 4 bits (tabela 0–F). Octal tratado igual. Na memória tudo é 0 e 1; não existe posição "vazia".
- **Exemplos com valores do livro (bons para reaproveitar):** 10011₂ = 19; 19 → restos 1,1,0,0,1 → 10011; 10AF4₁₆ = 68340; A5₁₆ = 1010 0101; 00111111₂ = 3F; 1024₈ = 532; 44 = 00101100₂.
- **Pegadinhas:** em C, `044` é octal (= 36) e `0x44` é hex (= 68) — zero à esquerda muda o valor! (`int b = 0435;` vale 285; `0x1FA` vale 506).
- **Exercícios:** converter 19, 68340, 532 nas três bases (respostas acima); "por que 0x3F e 077 e 63 são o mesmo número?".

### 0005-compilacao
- **Conceitos-chave:** compilar = traduzir fonte (texto para humanos) em código de máquina. Etapas citadas: pré-processamento (remove comentários, expande `#...`), verificação sintática, compilação (um arquivo objeto por .c, ainda não executável), link-edição (junta objetos do programa + objetos das bibliotecas num executável). `#include` = "cole aqui o conteúdo deste arquivo".
- **Pegadinha:** o livro funde "verificação sintática" como etapa separada; no curso, apresentar pré-processador → compilador (inclui análise sintática) → montador → ligador, com `gcc -E`, `-c`, `-o`.
- **Ideia de exemplo:** o "Build/Build and run" do Code::Blocks mapeado para `gcc -c` e `gcc -o`.
- **Debugger (1.2.2):** boa explicação conceitual — breakpoint, passo a passo ("next line"), entrar na função ("step into"), sair ("step out"), continuar, janela de *watches*. Traduzir para `gdb` (break/next/step/finish/continue/print). Exemplo usado: programa que lê x, diz se é positivo/negativo/zero e calcula fatorial.

---

## 01 · Fundamentos de C

### 0006-primeiro-programa
- **Conceitos-chave:** esqueleto = região de declarações globais (`#include`) + `int main()` + bloco `{}` + `return 0` ("terminou e está tudo OK"). Comandos quase sempre terminam em `;`. Parênteses delimitam argumentos de função. `\n` muda de linha. Comentários `//` (linha) e `/* */` (bloco); servem de documentação interna.
- **Analogia/explicação boa:** indentação = hierarquia visual; o mesmo programa espremido em 3 linhas compila igual mas fica ilegível (Fig. 1.18) — ótimo "antes e depois".
- **Pegadinhas:** `<arquivo.h>` procura nos diretórios do sistema; `"arquivo.h"` procura primeiro na pasta do projeto. O livro escreve caminhos Windows com `\` dentro de `#include` — evitar.
- **Exercício (Cap. 2, nº 1):** imprimir "Início do programa" e "Fim" em linhas separadas com **um único** `printf` (resposta: usar `\n` no meio).

### 0007-variaveis
- **Conceitos-chave:** variável = posição de memória com nome e tipo; ao nome o computador associa um endereço. Tipo define valores e operações possíveis. Declarar antes de usar; várias no mesmo comando com vírgula. Regras de nome: letras, dígitos e `_`, não começa por dígito, case-sensitive (`Soma`, `soma`, `SOMA` são três), não pode ser palavra-chave. Tipos básicos: `char`, `int`, `float`, `double`, `void`. `sizeof` dá o tamanho em bytes (de tipo ou de variável).
- **Analogia boa:** **lixo de memória** — memória nunca está "vazia", sempre tem 0s e 1s; a variável recém-criada herda o que estava lá. Exemplo: imprimir `x` antes de atribuir mostra "qualquer valor".
- **Pegadinhas:** usar variável não inicializada; `char` usa aspas simples (`'a'`) — sem elas, `a` seria o nome de outra variável; número real usa ponto, não vírgula; não existe variável `void`.
- **Erros do livro a corrigir:** tabela das 32 palavras-chave traz `typeof` no lugar de `typedef`; `void` aparece com "8 bits"; diz que `sizeof` é função (é operador).
- **Exemplos:** tabela de nomes válidos/inválidos (`comp!`, `.var`, `int`, `1var`, `-x`, `Va-123` inválidos; `cont`, `Cont`, `Val_123`, `_teste`, `Int1` válidos) — virar exercício "quais compilam?".
- **Exercício:** programa que imprime `sizeof` de char, int, float, double e de uma `struct ponto {int x,y;}` (resposta típica x86-64: 1, 4, 4, 8, 8).

### 0008-tipos-e-limites
- **Conceitos-chave:** modificadores `signed`, `unsigned`, `short`, `long` (combináveis: `unsigned long int`). `unsigned` perde o bit de sinal e dobra a faixa positiva (`char` −128..127 → `unsigned char` 0..255). C99: `long long` (64 bits, sufixos `LL`/`ULL`, `%lld`/`%llu`) e `stdint.h`/`inttypes.h` com `int8_t…int64_t`, `int_leastN_t`, `int_fastN_t`, `intptr_t`.
- **Pegadinhas/erros do livro:** afirma que `short` tem 16 e `long` 32 bits "independentemente do processador" — falso (Linux 64 bits: `long` = 64). A Tabela 2.2 dá `signed int` com faixa de 16 bits (erro de digitação). Ensinar via `limits.h` (`INT_MAX`, `UINT_MAX`) e `sizeof`, não por tabela fixa.
- **Exemplo bom (Fig. 13.4):** `unsigned int n = 2147483647;` imprimir com `%d` e `%u`, somar 1 e imprimir de novo → `%d` mostra −2147483648, `%u` mostra 2147483648. Ótimo para overflow/interpretação de bits.
- **Exercício:** prever a saída do exemplo acima; "quantos valores cabem em 8, 16, 32 bits com e sem sinal?".

### 0009-constantes
- **Conceitos-chave:** literal = valor escrito no próprio código; tem tipo (`10` é int, `10.5` é double). Sufixos: `F` float, `L` long double/long, `U` unsigned, `UL`, `LL`. Notação científica `5.0e10`. `#define PI 3.1415` = substituição textual feita antes da compilação; `const float PI = 3.1415;` = variável somente leitura (sujeita a escopo e tipo). Constante precisa de valor na declaração. Sequências de escape: `\a \b \n \r \t \v \' \" \\ \f \? \0`, além de `\ooo` (octal) e `\xhh` (hex): `\x3D` = `=`, `\x5A` = `Z`, `\044` = `$`, `\105` = `E`.
- **Pegadinhas:** `#define` não leva `=` nem `;`; `const` não serve como tamanho de vetor em C89 (serve `#define`).
- **Exercícios (Cap. 2):** imprimir um caractere lido entre aspas duplas (resposta: `printf("\"%c\"", c)`); constante float via `#define` e int via `const`.

### 0010-printf
- **Conceitos-chave:** `printf("formato", valores...)`: um especificador para cada valor, na mesma ordem; texto livre pode vir antes, entre e depois. Especificadores: `%c %d %i %u %f %e %E %g %G %x %X %o %s %p %%`. Forma completa: `%[flag][largura][.precisão][comprimento]tipo`. Flags: `-` (alinha à esquerda), `+` (força sinal), espaço, `#` (prefixo `0`/`0x`, força ponto), `0` (preenche com zeros). Largura e precisão podem vir de argumento com `*` (`%*d`, `%.*f`). Precisão: casas decimais em `%f`, dígitos mínimos em inteiros (`%.8d` → `00000125`), máximo de caracteres em `%s` (`%.3s` de "Meu programa C" → `Meu`). `printf` retorna nº de caracteres escritos. Quebra de string longa com `\` no fim da linha (melhor: concatenação de literais adjacentes).
- **Pegadinhas:** `printf` não usa `&` (com `&` imprimiria endereço); `%d` com float/`%f` com int dá lixo (exercícios 4 e 5 do Cap. 2 exploram isso de propósito); `%p` para endereços, não `%d`/`%x` (o livro usa `%d` com ponteiros em vários exemplos — errado em 64 bits).
- **Exemplo:** `int n = 125;` em `%d`, `%o` (175), `%x` (7d), `%X` (7D), `%#o` (0175), `%#X` (0X7D); `n = 5` com `%5d`, `%-5d`, `%+d`, `%05d`.
- **Exercícios:** ler char, int, float e imprimir de três formas (espaço, `\t`, uma por linha) com um único printf cada; imprimir "Juros de 25%" (resposta: `%%`).

### 0011-scanf
- **Conceitos-chave:** `scanf("formato", &var...)`: o `&` entrega o endereço da variável para a função escrever lá. Espaços no formato são ignorados (`"%d%d"` ≡ `"%d %d"`); usuário pode separar por espaço ou ENTER. Outros caracteres no formato precisam ser digitados e são descartados (`"%d/%d/%d"` para datas; se o usuário não digitar a barra, a leitura falha). `%*d` lê e descarta. Largura limita caracteres (`%2d`, `%10s`). Scanset `%[aeiou]`, `%[A-Z0-9]`, `%[^A-Z]`. Retorno = nº de itens lidos (ou EOF). `getchar()` lê um caractere e retorna `int`.
- **Pegadinhas (várias o livro erra ou omite):** ler `double` exige `%lf` (o livro diz que `%f` serve para float e double — erro grave); `scanf("%s", str)` sem `&` porque o nome do vetor já é endereço; `%s` para no primeiro espaço; **sobra do `\n` no buffer**: `scanf("%d")` seguido de `gets`/`fgets`/`%c` lê a linha vazia — o próprio livro tem esse bug nos exemplos de struct (lê idade com scanf e depois rua com gets). Correção: `" %c"` (espaço antes) ou consumir até `\n` com um laço de getchar. Scanset é `%[...]`, sem `s` depois (o livro escreve `%[aeiou]s`).
- **Exercício:** ler data em `dd/mm/aaaa` e imprimir `d - m - a`; testar o retorno do scanf para recusar entrada não numérica.

### 0012-aritmetica
- **Conceitos-chave:** `+ - * / %`; `*`, `/`, `%` antes de `+`, `-`; parênteses forçam ordem; `-` unário inverte sinal. Divisão entre inteiros descarta a parte fracionária; basta um operando real para virar divisão real. `%` só para inteiros. Atribuição: avalia a direita e guarda na esquerda (`5 = x` e `y + 5 = x` são erros); atribuição múltipla `x = y = z = 5` vai da direita para a esquerda. Operador vírgula: `x = (y = 2, y + 3)` → x = 5.
- **Pegadinhas:** `float x = 5/4;` dá 1.000000; `5/4.0` dá 1.25. Média de inteiros: dividir por `5.0`.
- **Erros do livro:** tabela de precedência (3.8) coloca pré-incremento acima de `()`, separa `< <=` de `> >=` em níveis diferentes e chama o E lógico de `&`. Usar tabela de referência correta.
- **Exercícios (Cap. 3) bons:** antecessor/sucessor; ano de nascimento; km/h → m/s (`M = K/3.6`); Celsius→Fahrenheit (`C*(9.0/5.0)+32`); prêmio de R$780.000 dividido 46%/32%/resto (respostas: 358.800, 249.600, 171.600); inverter número de 3 dígitos com `/` e `%` (123 → 321).

### 0013-conversao
- **Conceitos-chave:** conversão implícita na atribuição para o tipo da esquerda, podendo perder informação; cast explícito `(tipo) expressão`.
- **Exemplo do livro (ótimo para "preveja a saída"):** `int x = 65; char ch; float f = 25.1; ch = x; x = f; f = ch; f = x;` → `ch = A`, `x = 25`, `f = 65.0`, `f = 25.0`. E `float f = 65.5; x = f/10.0` (6.55) vs `y = (int)(f/10.0)` (6.0).
- **Pegadinha:** cast em `(float)(a/b)` é tarde demais — a divisão inteira já aconteceu; o certo é `(float)a/b`.

### 0014-atribuicao
- **Conceitos-chave:** `+= -= *= /= %= &= |= ^= <<= >>=`; `++`/`--` pré (altera e depois usa) e pós (usa e depois altera); sozinhos na linha dão o mesmo resultado.
- **Explicação boa:** o operador composto age sobre **toda** a expressão à direita: `x *= y - 10` ≡ `x = x * (y - 10)`, não `x*y - 10`. Com x=10, y=20: forma longa `x = x*y-10` dá 190, forma curta dá 100; em seguida `x = x-5+y` dá 205 e `x -= 5+y` dá 75.
- **Exemplo:** `y = ++x` (x=11, y=11) vs `y = x++` (x=11, y=10), com a "tradução" em duas linhas.
- **Pegadinhas/erros do livro:** `*p = (*p)++;` e `index = (index==3) ? 0 : ++index;` modificam a mesma variável duas vezes na mesma expressão — comportamento indefinido; usar como contraexemplo.

### 0015-math
- **Conceitos-chave:** `math.h`: trigonométricas (radianos), `exp`, `log`, `log10`, `pow`, `sqrt`, `ceil`, `floor`, `fabs`, `fmod`, `modf`, `frexp`; constantes `M_PI`, `M_E`, `M_SQRT2` (não são do padrão ISO; no glibc exigem `_DEFAULT_SOURCE`/`_GNU_SOURCE` em modo estrito). `stdlib.h`: `abs`, `labs`, `div`.
- **Pegadinhas:** no Linux compilar com `-lm` (o livro não menciona); `round` não aparece no livro (C99).
- **Exercícios:** hipotenusa com `sqrt`; área do círculo e volume do cilindro (π = 3.141592); graus→radianos; equação do 2º grau com Δ (casos: Δ<0 "não existe raiz", Δ=0 "raiz única", Δ>0 duas raízes; a=0 → "não é equação do 2º grau").

---

## 02 · Decisões

### 0017-relacionais
- **Conceitos-chave:** `> >= < <= == !=` retornam 1 (verdadeiro) ou 0 (falso). Em condição, qualquer valor ≠ 0 é verdadeiro: `if (num)` ≡ `if (num != 0)`; `if (!num)` ≡ `if (num == 0)`. C99: `_Bool` e `stdbool.h` (`bool`, `true`, `false`).
- **Pegadinhas:** `=<`, `=>` e `<>` não existem (este último é do Pascal); `0 < x < 10` não significa o que parece (usar `&&`).
- **Exemplo:** `x=5, y=3`: `x>4` → 1, `x==4` → 0, `x!=y` → 1, `x!=y+2` → 0 (imprimir com `%d`).

### 0018-logicos
- **Conceitos-chave:** `&&`, `||`, `!`; tabela-verdade completa (Tab. 3.4). `!(x == 10)` equivale a `x > 10 || x < 10`.
- **Exemplo (Fig. 3.4) — "preveja":** com x=5, y=3: `(x>2)&&(y<x)` 1; `(x%2==0)&&(y>0)` 0; `(x>2)||(y>x)` 1; `(x%2==0)||(y<0)` 0; `!(x>2)` 0; `!(x>7)&&(x>y)` 1.
- **Lacuna:** o livro não explica **curto-circuito** — complementar com outra fonte.
- **Exercício:** divisível por 3 ou 5, mas não pelos dois (resposta: `(n%3==0) != (n%5==0)` ou com `&&`/`||`/`!`).

### 0019-if / 0020-if-else
- **Conceitos-chave:** `if` executa o bloco se a condição for não-zero; `else` é o "caso contrário", **sem condição**. Comandos de controle atuam só sobre o comando seguinte; para vários, usar `{}`. `if` e `else` têm blocos independentes, cada um com suas chaves.
- **Pegadinhas fortes (o livro as destaca bem):** `if (num > 10);` — o `;` encerra o if e o printf roda sempre (compila sem erro!); `else (num != 10)` é erro; `else ;{ ... }` faz o bloco rodar sempre; `=` no lugar de `==` compila e quase sempre dá "verdadeiro".
- **Exercícios (Cap. 4):** maior de dois números (com mensagem "Números iguais"); par ou ímpar; empréstimo negado se prestação > 20% do salário; peso ideal (homens `72.7*h - 58`, mulheres `62.1*h - 44.7`).

### 0021-else-if
- **Conceitos-chave:** if aninhado para 3+ caminhos (igual/maior/menor que 10). **Else pendurado:** o `else` se liga ao `if` mais próximo antes dele no mesmo bloco, não ao alinhado visualmente; para ligá-lo ao externo, envolver o interno em `{}`. Não existe "else do else" sem if.
- **Exercícios:** categoria de nadador por idade (Infantil A 5–7, Infantil B 8–10, Juvenil A 11–13, Juvenil B 14–17, Sênior 18+); tabela altura × peso com 9 classes (A–I); imposto por estado (MG 7%, SP 12%, RJ 15%, MS 8%, inválido → erro).

### 0022-ternario
- **Conceitos-chave:** `cond ? a : b` é um if-else que **produz valor**; ideal para atribuição condicional (`z = x > y ? x : y;`). Pode chamar funções nos ramos, mas fica ilegível.
- **Pegadinha:** o "contador circular" do livro `index = (index==3) ? 0 : ++index;` tem UB; versão certa: `index = (index == 3) ? 0 : index + 1;` ou `index = (index + 1) % 4;`.

### 0023-switch
- **Conceitos-chave:** compara uma variável inteira/char com constantes; `default` opcional; executa a partir do `case` igual **até achar um `break`** (fall-through). Equivale a um if-else-if só de igualdade.
- **Explicação boa:** o mesmo switch de pontuação (`. , : ;`) com e sem `break` — sem break, digitar `.` imprime todas as mensagens. Uso deliberado: contagem regressiva por extenso (`case 9: "Nove"` … `case 0: "Zero"` sem breaks; digitar 5 imprime de "Cinco" a "Zero").
- **Pegadinha:** declarar variável logo após um `case` exige abrir `{}` (o salto não pode pular uma declaração no mesmo escopo).
- **Exercícios:** mês por número (4 → Abril); dia da semana 1–7; calculadora com menu (+ − * /).

---

## 03 · Laços

### 0025-while
- **Conceitos-chave:** testa antes; repete 0 ou mais vezes. Laço infinito: sem condição de parada, ou condição que nunca é atingida (variável que se afasta do limite, ou que nunca muda).
- **Pegadinhas:** `while (a < b);{...}` → laço infinito vazio; esquecer de atualizar a variável de controle.
- **Exemplo:** imprimir os inteiros entre a e b; pseudocódigo de laço infinito com `X ← X − 1` enquanto `X < 5`.

### 0026-do-while
- **Conceitos-chave:** executa e depois testa; 1 ou mais vezes; **exige `;` após o `while(...)`**. Uso clássico: menu/validação `do { mostra opções; lê i; } while (i < 1 || i > 3);`.
- **Exercício:** ler N até ser positivo; menu de 3 opções que repete enquanto inválida.

### 0027-for
- **Conceitos-chave:** `for (inicialização; condição; incremento)`: inicializa uma vez, testa, executa, incrementa, volta a testar. Qualquer cláusula pode ser omitida, mas os dois `;` são obrigatórios; sem condição = infinito. O "incremento" pode ser qualquer atualização (`c = c + 2`, até um `scanf`). Vírgula permite duas variáveis: `for (i=0, j=100; i<j; i++, j--)`. Variável de controle pode ser `char` (`for (c='A'; c<='Z'; c++)`). C99: `for (int i = 0; ...)` com i local ao laço.
- **Exemplo:** for vs while para soma de 1 a 10 (= 55).

### 0028-break-continue
- **Conceitos-chave:** `break` sai do laço (ou do switch) e segue na linha após ele; `continue` pula o resto da iteração e volta ao teste (só em laços). Ambos fazem sentido dentro de um `if`.
- **Exemplo:** imprimir de a+1 até b, com `break` quando a == 5 (para antes do 5) vs `continue` (só o 5 some).
- **Pegadinha:** `continue` num `while` antes do incremento → laço infinito; `break` só sai do laço mais interno.
- **Erro do livro:** o texto de 5.7 troca as palavras e diz que "o break interrompe apenas aquela repetição".

### 0029-lacos-aninhados
- **Conceitos-chave:** um laço completo roda a cada volta do externo; pode misturar tipos de laço.
- **Exemplo:** matriz identidade 4×4 impressa com dois for ou dois while (`i==j ? "1 " : "0 "`).
- **Exercícios:** triângulo de Floyd (1 / 2 3 / 4 5 6 …); função que imprime n linhas de `!` crescentes; losango lateral de `*` (1..n..1).

### 0030-padroes-de-laco
- **Conceitos-chave (espalhados no Cap. 5 e 6.6):** acumulador começa em 0 (soma); maior/menor começa com **o primeiro elemento**, não com 0 (o livro explica: se todos forem negativos, 0 viraria o "maior" falso); média = soma / quantidade em real; sentinela (ler até negativo).
- **Exercícios bons (Cap. 5):** soma dos 50 primeiros pares (2550); soma dos múltiplos de 3 ou 5 abaixo de 1000 (233168); divisores de 66 (1,2,3,6,11,22,33,66) e soma dos divisores próprios (78); primo; Fibonacci iterativo (0,1,1,2,3,5,8…); maior valor e quantas vezes apareceu; número harmônico Hn.

### 0031-aleatorios
- **Cobertura mínima:** só cita `rand()` e `srand()` na lista de `stdlib.h` e `time()` em `time.h`. Buscar outra fonte.

---

## 04 · Funções e modularização

### 0033-funcoes
- **Conceitos-chave:** função = bloco nomeado chamável; motivos: estruturar o programa e reutilizar código. Forma: `tipo nome(parâmetros) { ... }`. Deve ser definida antes do uso **ou** ter protótipo antes (`int Square(int a);`, nomes de parâmetros opcionais no protótipo). Ao chamar: o chamador pausa, argumentos são copiados para os parâmetros, corpo executa, `return` devolve o valor e o fluxo volta. `return` encerra a função na hora (código depois dele não roda); `return;` em função void. Não se retorna array (mas pode retornar struct contendo array).
- **Boa orientação de design:** a função faz uma tarefa; entrada/saída (`scanf`/`printf`) fica com quem chama (fatorial dentro do main vs em função própria). Exceção legítima: função `menu()` que lê e valida.
- **Pegadinha:** `int soma(int x, y)` é erro — cada parâmetro com seu tipo.
- **Exercícios (9.4.1):** maior de dois; Fahrenheit→Celsius; IMC; h/m/s → segundos; quadrado perfeito; média aritmética ou ponderada (pesos 5,3,2) conforme letra 'A'/'P'; potência x^y sem `pow`; maior fator primo; somatório 1..n.

### 0034-parametros
- **Conceitos-chave:** em C a passagem é **sempre por valor** (cópia); o parâmetro é variável local. `void f()` vs `void f(void)`: no primeiro o compilador não confere argumentos (`f(5)` passa), no segundo é erro — prefira `(void)`.
- **Exemplo do livro:** `soma_mais_um(int n)` — antes 5, dentro 6, depois 5. Excelente com a figura "int a = n1" (cópia na chamada).

### 0035-escopo
- **Conceitos-chave:** escopo = onde e quando a variável existe. Global: fora das funções, vive o programa todo, visível em todo lugar (evitar: qualquer parte altera, dificulta manutenção, ocupa memória sempre). Local: dentro de `{}`, só existe no bloco. Mesmo nome em blocos diferentes = variáveis diferentes; a declaração mais próxima **esconde** as outras. `static` local mantém o valor entre chamadas (Fig. 13.30: imprime 0..9 em 10 chamadas).
- **Exemplo bom:** x global = ?, local na função, outro x num bloco interno — rastrear qual x cada printf vê (a figura 2.12 mostra escopos como caixas aninhadas).
- **Pegadinha/erro do livro:** diz que `static` é o "modo padrão" das globais e que `int x` e `static int y` globais têm a mesma classe — confunde duração com ligação; `static` global = visível só naquele .c.

### 0036-pilha-de-chamadas
- **Analogia boa (Figs. 9.28/9.29):** cada chamada empilha uma "cópia" da função na memória acima de quem chamou (`main` → `fatorial(4)` → … → `fatorial(0)`); no retorno, cada uma devolve o valor e é removida. Cada chamada guarda parâmetros, locais e endereço de retorno — por isso recursão gasta memória proporcional à profundidade (fatorial(4) = 5 chamadas).
- **Lacuna:** o livro não fala de "stack frame" nem de stack overflow com esse nome; usar as figuras como ponto de partida.

### 0037-recursao
- **Conceitos-chave:** função que chama a si mesma; precisa de **critério de parada** (caso base) e de **parâmetro que muda** a cada chamada em direção ao caso base; sem isso, esgota a memória. Caminho de ida (chamadas até o caso base) e de volta (retornos combinando resultados).
- **Analogia excelente:** **esvaziar um vaso com N flores** — se não está vazio, tire uma flor e esvazie o vaso com N−1; vaso vazio, pare. Depois a mesma estrutura no fatorial (`0! = 1`, `n! = n·(n−1)!`).
- **Exercícios (9.4.3):** soma dos n primeiros cubos; somatório 1..N; imprimir 0..N crescente e decrescente (ensina a diferença entre imprimir antes ou depois da chamada); soma/média/menor de vetor; x^y; multiplicação por somas sucessivas; inverter inteiro (123 → 321); decimal → binário.

### 0038-recursao-na-pratica
- **Conceitos-chave:** recursivo é mais elegante, mas tende a gastar mais tempo e memória que o iterativo. Fibonacci recursivo faz duas chamadas e **recalcula** os mesmos valores — a árvore de `fibo(4)` e `fibo(5)` mostra subárvores repetidas.
- **Exemplo:** fibo recursivo vs iterativo (a, b, c com laço). Hanói e Euclides não aparecem — buscar fora.
- **Exercício:** contar quantas chamadas `fibo(n)` faz para n = 5, 10, 20 (resposta: 15, 177, 21891 — cresce exponencialmente).

### 0039-modulos
- **Conceitos-chave (1.6.1 + 13.5.2):** biblioteca própria = `.h` com protótipos (o "o que") + `.c` com implementações (o "como"), sem `main`; o `.c` inclui o próprio `.h`; o programa inclui com aspas. Exemplo: `aritmetica.h/.c` com soma, subtração, produto, divisão + calculadora com switch. `extern int soma;` declara global definida em outro arquivo (não pode inicializar ali). Função `static` fica visível só no seu arquivo.
- **Lacuna:** não mostra include guards nem `gcc a.c b.c -o prog` (só "Add file" do Code::Blocks). Complementar.

### 0040-preprocessador
- **Conceitos-chave:** diretivas começam com `#`, uma por linha, processadas antes da compilação: `#include`, `#define` (símbolo, constante, macro com parâmetros), `#undef`, `#ifdef/#ifndef/#if/#elif/#else/#endif`, `#line`, `#error`, `#pragma`; operadores `#` (vira string) e `##` (cola tokens); macros pré-definidas `__LINE__ __FILE__ __DATE__ __TIME__`, `__func__` (C99), `__STDC_VERSION__`. Macro multilinha com `\`. Macros variádicas com `__VA_ARGS__` (C99).
- **Explicação boa ("macro não é função"):** `#define prod1(x,y) x*y` com `prod1(a+2,b)` (a=1,b=2) vira `a+2*b` = 5; com parênteses `(x)*(y)` dá 6.
- **Pegadinhas:** o próprio livro escreve `#define prod1(x,y) x*y;` (o `;` vai junto na substituição) e `maior(x,y) x>y?x:y` sem parênteses no todo — ótimos contraexemplos; macro avalia o argumento várias vezes (`maior(i++, j)`); `TROCA(a,b,tipo) {tipo t=a; a=b; b=t;}` quebra em `if/else` (ensinar `do { } while (0)`); `##__VA_ARGS__` é extensão GNU.
- **Exercício:** prever o valor de `prod1(a+2,b)` e `prod2(a+2,b)`; escrever `QUADRADO(x)` correto e mostrar a falha de `QUADRADO(1+2)` sem parênteses (5 em vez de 9).

---

## 05 · Vetores, matrizes e strings

### 0042-vetores
- **Conceitos-chave:** motivação: notas de 5 alunos com 5 variáveis e 5 ifs → inviável para 100 alunos. Vetor = várias variáveis do mesmo tipo, um nome, acesso por índice; elementos adjacentes na memória; índices 0..N−1; cada posição é uma variável comum (entra em scanf, expressões, atribuições); acesso a qualquer posição custa o mesmo. Inicialização com `{}` só na declaração; posições não informadas viram 0; tamanho pode ser omitido (`int v[] = {1,...,10}` → 10).
- **Explicação boa:** **o nome indica onde o vetor começa; o índice diz quantas posições pular** — por isso começa em 0, e por isso `notas[100]` ou `notas[-1]` acessam memória vizinha que pertence a outras variáveis. "É função do programador garantir os limites."
- **Pegadinhas:** C não confere limites; `v1 = v;` não copia vetor (copiar elemento a elemento); declarado sem inicializar = lixo. O livro diz que `int v[n]` com n variável é erro — desde C99 é VLA válido (o próprio Cap. 14 mostra).
- **Exemplos (6.6):** soma de `{3,51,18,2,45}` = 119; maior de `{3,18,2,51,45}` = 51; média = 23.8.
- **Exercícios (6.7.1):** ler 6 e imprimir invertido; A = {1,0,5,−2,−5,7}: soma A[0]+A[1]+A[5] (= 8), trocar A[4] por 100; contar pares; maior e menor; C = A − B; 100 primeiros naturais não múltiplos de 7; detectar repetidos; ler 10 números **sem repetição** (pede outro se já existe); desvio-padrão; ordenar 10 reais.

### 0043-vetores-e-funcoes
- **Conceitos-chave:** passa-se o nome (endereço do 1º elemento) **e o tamanho separado**; `int *v`, `int v[]` e `int v[5]` no parâmetro são equivalentes (o 5 é ignorado). Como a função recebe o endereço, altera o vetor original. Matriz como parâmetro exige todas as dimensões menos a primeira (`int m[][5]`), porque o compilador precisa saber o tamanho de cada "linha". C99: VLA no parâmetro `void f(int n, int m, int mat[n][m])` (dimensões antes da matriz). Truque: passar `&mat[0][0]` e tratar como vetor de n·m elementos.
- **Pegadinha/imprecisão do livro:** diz "arrays são passados por referência"; mais exato: o endereço é passado por valor (e `sizeof` do parâmetro dá o tamanho do ponteiro, não do vetor).
- **Exercícios (9.4.2):** soma de vetor de 10; média de notas; transposta 5×5 na própria matriz; soma das diagonais por referência; índice do aluno de maior média num vetor de structs; ordenar vetor.

### 0044-matrizes
- **Conceitos-chave:** `tipo m[linhas][colunas]`; dois índices, dois laços aninhados; 3D+ igual. Memória é **sempre linear**; o índice mais à direita varia mais rápido (row-major). Inicialização `{1,...,12}` ou `{{1,2,3,4},{5,6,7,8},{9,10,11,12}}`; só a 1ª dimensão pode ser omitida (`int m[][2] = {1..10}` → 5 linhas).
- **Exemplo:** soma de `{{1,2,3},{4,5,6},{7,8,9}}` = 45.
- **Exercícios (6.7.2):** menor de 3×3; maior de 4×4 e sua posição; identidade 5×5; soma da diagonal principal/secundária; soma acima/abaixo da diagonal; fora das duas diagonais; soma por coluna (exemplo do livro: `{{5,−8,10},{1,2,15},{25,10,7}}` → `{31,4,32}`); pior prova de 10 alunos × 3 provas; B = A².

### 0045-caracteres
- **Conceitos-chave:** `char` guarda um número pequeno que é o código ASCII; `%c` mostra o símbolo, `%d` o código; `putchar(65)` imprime `A`. ASCII padrão: 128 códigos, 0–31 e 127 de controle, 32–126 imprimíveis. `ctype.h`: `isalpha isdigit isalnum isspace isupper islower ispunct isxdigit toupper tolower`.
- **Pegadinhas:** o livro diz que putchar(65) mostra "a" (é `A`); tabela ASCII do apêndice tem erros (88 = 'Z' em vez de 'X', 96 = '-' em vez de '`', 10 = '/f'). `getchar` retorna `int`.
- **Exercícios:** maiúscula→minúscula pela tabela (somar 32 nos códigos 65–90) e o inverso; cifra de César com deslocamento 3 (exemplo do livro: "a ligeira raposa marrom saltou sobre o cachorro cansado" → "d oljhlud udsrvd pduurp vdowrx vreuh r fdfkruur fdqvdgr"); contar vogais.

### 0046-strings
- **Conceitos-chave:** string = vetor de `char` terminado em `'\0'`, que marca onde o texto acaba (o resto do vetor é lixo e não deve ser impresso). Tamanho declarado precisa de 1 posição para o `'\0'` (vetor de 50 → 49 letras). `char s[10] = "Joao";` já coloca o `'\0'`; `char t[] = "Linguagem C.";` tem 13 posições. Aspas duplas = string, simples = caractere. Não se atribui nem compara string com `=`/`==`. `string.h`: `strlen` (conta até o `'\0'`, não o tamanho do vetor: "teste" em `char[15]` → 5), `strcpy(dest, orig)`, `strcat(dest, orig)` (a 1ª letra de orig ocupa o lugar do `'\0'` de dest), `strcmp` (0 se iguais, case-sensitive). Lista ampla na 1.7.5 (`strncpy strncat strncmp strchr strrchr strstr strtok memcpy memset`...).
- **Explicação boa:** desenho `o i \0 ? ã #` — o `\0` como "fim do texto válido".
- **Pegadinhas:** destino de `strcpy`/`strcat` pequeno demais = estouro de buffer; `strcmp` retorna <0/0/>0 (o livro só diz "diferente de zero" — explorar a ordem alfabética); `printf("%d", strlen(s))` deveria ser `%zu`.
- **Exemplo:** cópia manual com `for (i=0; s1[i] != '\0'; i++) s2[i] = s1[i]; s2[i] = '\0';` — esquecer a última linha é o erro clássico.
- **Exercícios (7.4):** contar caracteres sem strlen; imprimir de trás para frente; inverter na própria variável; palíndromo (ovo, arara, rever, asa, osso); substring contida e quantas vezes; segmento de i a j; duas strings em ordem alfabética.

### 0047-lendo-strings
- **Conceitos-chave:** `scanf("%s")` lê só uma palavra. `fgets(str, tam, stdin)` lê até `\n` ou `tam−1` caracteres, sempre termina com `'\0'` e **guarda o `\n`** se couber; retorna NULL em erro/fim. Escrita com `printf("%s")` ou `fputs(str, stdout)` (fputs não acrescenta `\n`).
- **Pegadinhas:** tirar o `\n` do fgets (`s[strcspn(s, "\n")] = '\0';`); `scanf("%10s")` para limitar; sobra de `\n` de um scanf anterior faz o fgets "pular".
- **Obsoleto no livro:** apresenta `gets` como "alternativa mais eficiente" e o usa em dezenas de exemplos — `gets` foi **removida no C11** (não tem limite de tamanho). Também ensina `setbuf(stdin, NULL)` e `fflush(stdin)` para "limpar o buffer" (comportamento indefinido/não portável; a explicação do setbuf está errada).

---

## 06 · Ponteiros

### 0049-memoria
- **Analogia central (melhor material do livro):** tabelas "Memória: # | var | conteúdo" com endereços fictícios: `int count = 10` mora no endereço #122; `int *p` mora no #120 e seu conteúdo é **#122**. O computador precisa do endereço; o programador usa o nome. `&x` = "em que gaveta x está?". Imprimir com `%p`.
- **Exercícios (10.7):** comparar endereços de duas variáveis e mostrar o maior; imprimir o endereço de cada posição de um vetor de float (endereços sobem de 4 em 4) e de uma matriz 3×3.

### 0050-ponteiros
- **Conceitos-chave:** ponteiro = variável que guarda endereço. `tipo *nome;` — o tipo diz para que tipo de dado ele aponta. `*` tem três papéis: multiplicação (binário), declaração de ponteiro, acesso ao conteúdo apontado. Só dois operadores no dia a dia: `&` (endereço) e `*` (conteúdo). Ponteiro não inicializado aponta para qualquer lugar (usar = comportamento indefinido); `NULL` = "endereço de lugar nenhum", valor fixo e testável. Alterar `*p` altera a variável apontada (`*p = 12` muda `count`). Comparação `==` (apontam para o mesmo lugar) e `<`/`>` (útil dentro de vetores).
- **Pegadinhas:** confundir `p` (endereço) com `*p` (valor); `int *p = &y` com y float compila com aviso, mas `*p` dá lixo (Fig. 10.5: imprime 1101004800 e 0.000000; com cast `*(float*)p` dá 20.0); `int *p = 0x3F8;` e `int *p = 1500;` (o livro mostra como "útil para microcontroladores" — em PC, desreferenciar é crash; em C padrão exige cast); comparar `<` ponteiros de variáveis não relacionadas não tem significado garantido; NULL está em `stddef.h`/`stdio.h` também.
- **Exercício:** `int a, *b, **c, ***d;` — ler `a` e calcular dobro, triplo e quádruplo usando só `b`, `c` e `d`.

### 0051-passagem-por-referencia
- **Conceitos-chave:** para a função alterar a variável de quem chama, passa-se o **endereço** (`f(&x)`) e a função recebe ponteiro (`void f(int *n)`) e usa `*n`. É exatamente o que `scanf` faz — explica o `&` do scanf.
- **Exemplo do livro (ótimo lado a lado):** `Troca(int a, int b)` vs `Troca(int *a, int *b)` com x=2, y=3: "Antes 2 e 3 / Dentro 3 e 2 / Depois 2 e 3" vs "… Depois 3 e 2". Também `soma_mais_um` por referência (5 → 6 → 6).
- **Exercícios:** separar parte inteira e fracionária de um real por referência; volume e área da esfera devolvidos por referência; soma de pares e de ímpares de um vetor; maior e menor; maior e quantas vezes ocorre; equação do 2º grau retornando nº de raízes e as raízes por referência (−1 se a = 0).

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** o nome do vetor se converte no endereço do primeiro elemento (`p = vet` ≡ `p = &vet[0]`). `p[i]` ≡ `*(p+i)`; `&vet[i]` ≡ `vet+i`. Aritmética de ponteiros: só somar/subtrair inteiros; o passo é `sizeof(tipo)` (int* anda 4 bytes: 1500 → 1504; `+15` → 1564; `−2` → 1556; double* andaria 8). Matriz: `*(*(mat+i)+j)`; ou `int *p = &mat[0][0]` percorrendo as 4 posições de 2×2 linearmente. `A[B]` ≡ `*(A+B)` ≡ `B[A]` (`1[A]` funciona — curiosidade; o livro diz ser novidade do C99, mas sempre valeu).
- **Imprecisão do livro (importante corrigir):** repete que "o nome do array é apenas um ponteiro". Não é: `sizeof(vet)` dá o vetor inteiro, `vet = ...` é proibido, `&vet` tem outro tipo. Melhor: "o nome *decai* para ponteiro na maioria das expressões".
- **Exercícios:** ler um vetor de 5 e imprimir o dobro usando só aritmética de ponteiros; preencher vetor com um valor sem usar índices; imprimir vetor só com ponteiro; imprimir endereços das posições com valores pares.

### 0053-ponteiros-e-strings
- **Cobertura fraca:** só diz que ponteiro pode percorrer string. Não discute `char *s = "abc"` (literal somente leitura) vs `char s[] = "abc"`. Exercício aproveitável: verificar se uma string ocorre dentro de outra usando aritmética de ponteiros.

### 0054-ponteiro-para-ponteiro
- **Analogia boa:** "anotar o endereço de um papel que tem o endereço da casa do seu amigo". Tabela de memória: `x` (#124) = 10, `p` (#122) = #124, `p2` (#120) = #122; `*p2` = #124, `**p2` = 10. Nº de asteriscos = nº de níveis; acessar com a mesma quantidade. Evitar muitos níveis.
- **Exemplo:** `char letra='a'; char *ptrChar; char **ptrPtrChar; char ***ptrPtr;` imprimindo `'a'` pelos três caminhos.
- **Array de ponteiros:** `int *p[10]`; cada posição guarda o endereço de uma variável ou do início de outro vetor (`pvet[1] = y; pvet[1][1]` → 30). Contraste `int (*p3)[10]` (ponteiro para vetor de 10) vs `int *p4[10]` (vetor de 10 ponteiros).

### 0055-ponteiro-para-funcao
- **Conceitos-chave:** função também mora na memória; o nome da função é seu endereço (não precisa de `&`). Declaração `int (*p)(int, int);` — parênteses obrigatórios (sem eles, `int *p(int,int)` é função que retorna ponteiro). Só aponta para funções com o mesmo protótipo. Chamar com `p(x, y)`. Passar como parâmetro: `int executa(int (*p)(int,int), int x, int y)`. Vetor de ponteiros para função: `int (*p[4])(int,int)`. Motivação do livro: ordenação genérica trocando só a função de comparação (ponte para `qsort`).
- **Exemplo:** calculadora em que o switch escolhe `p = soma/subtracao/produto/divisao` (ou índice num vetor de funções); `default` → `p = NULL` e teste antes de chamar.
- **Lacuna:** `qsort`/`bsearch` aparecem só na lista da `stdlib.h` (com protótipo). Escrever o exemplo de qsort com outra fonte.

### 0056-void-generico
- **Conceitos-chave:** `void *` guarda endereço de qualquer tipo (inclusive de outro ponteiro); para ler o conteúdo é obrigatório converter: `*(int*)pp`; `*pp` direto é erro. `malloc` retorna `void *` porque não sabe o uso da memória.
- **Pegadinha:** o livro ensina que aritmética em `void *` anda de 1 em 1 byte (1500 → 1501 → 1516 → 1514) — é **extensão do GCC**, inválida em C padrão (`-pedantic` avisa). Para bytes, usar `char *`/`unsigned char *`.

---

## 07 · Memória dinâmica

### 0058-pilha-e-heap
- **Cobertura indireta:** não usa os termos stack/heap/segmentos. Diz que variáveis locais são criadas e destruídas automaticamente com o bloco (classe `auto`), globais/static vivem o programa todo, e memória de `malloc` só sai com `free`. VLA (C99) segue o escopo; malloc não. Usar como gancho para o modelo stack/heap/dados/código de outra fonte.
- **Motivação boa (11.1):** salários de uma empresa num `float salarios[1000]` — desperdiça se houver 10 funcionários, não basta se houver 1001.

### 0059-malloc-free
- **Conceitos-chave:** alocação dinâmica = pedir memória em tempo de execução; o sistema devolve o endereço inicial e o ponteiro passa a se comportar como vetor (Fig. 11.1: `int *n` de NULL para #123 com n[0..4]). `malloc(bytes)` → `void*` ou NULL; calcular bytes com `N * sizeof(tipo)`; **sempre testar NULL**. `free(p)` devolve; o sistema sabe quantos bytes porque guardou o tamanho numa "tabela de alocação" interna. Liberar só quando não for mais usar; depois do free, fazer `p = NULL`.
- **Explicação boa:** `malloc(1000)` vira 1000 chars ou 250 ints — o nº de elementos depende do tipo.
- **Pegadinhas:** o cast `(int*)` é desnecessário em C; o livro chama `sizeof` de função e diz que `float` ocupa mais que `int` (ambos 4 em geral); tamanho errado (`malloc(5)` querendo 5 ints).
- **Exercícios (11.4):** ler N e alocar vetor; função que devolve vetor de N preenchido com 0..N−1 (NULL se N ≤ 0); string invertida em memória nova; C[i] = A[i] + B[i] em vetor novo; produto matriz × vetor.

### 0060-calloc-realloc
- **Conceitos-chave:** `calloc(n, tam)` = malloc que separa quantidade e tamanho e **zera todos os bits** (comparar lado a lado: calloc imprime zeros, malloc lixo). `realloc(p, novo_tam)` aumenta ou diminui; pode **mover** o bloco (copia o conteúdo antigo); parte nova vem com lixo; `realloc(NULL, n)` ≡ `malloc(n)`; em falha retorna NULL e **o bloco original continua intacto**.
- **Pegadinhas:** `p = realloc(p, ...)` perde o bloco se falhar (vazamento) — usar ponteiro temporário (o livro usa a forma perigosa); `realloc(p, 0)` como free é dependente de implementação (o livro apresenta como regra); exemplos do livro usam `i` não declarado.
- **Ponte para 0080 (vetor dinâmico):** exemplo de 5 → 3 → 10 elementos com realloc é a semente do "vetor que cresce".

### 0061-matriz-dinamica
- **Três soluções (ótima sequência didática):**
  1. **Vetor único** de L·C elementos, acesso `p[i*C + j]` (perde a notação `[i][j]`; `p[i][j]` não compila).
  2. **Ponteiro para ponteiro**: 1º malloc cria o vetor de `int*` (linhas), um malloc por linha cria as colunas; libera na ordem inversa (cada linha, depois o vetor de linhas — senão perde-se o acesso às linhas). Permite linhas de tamanhos diferentes (matriz triangular com `malloc((i+1)*sizeof(int))`).
  3. **Misto**: um bloco único de dados + vetor de ponteiros com `p[i] = v + i*C`; só 2 mallocs e 2 frees, mantém `[i][j]`.
- **Regra útil do livro:** "o que se aloca tem um nível de `*` a menos que o ponteiro que recebe" (`int**` recebe vetor de `int*`; o livro erra o caso `int***`, dizendo que aloca "array de inteiros" em vez de `int**`).
- **Exercícios:** função que devolve N×N identidade; diagonal secundária; 0 na diagonal, 1 acima, −1 abaixo; produto de matrizes (NULL se dimensões incompatíveis); ler matriz de arquivo cujas 2 primeiras entradas são as dimensões.

### 0062-erros-de-memoria
- **Coberto pelo livro:** usar memória após `free` "funciona" às vezes (o ponteiro ainda guarda o endereço), mas não há garantia do conteúdo — exemplo imprime o vetor depois de liberado; ponteiro solto (*dangling pointer*) e a recomendação `p = NULL`; esquecer `free` (sem o termo "vazamento"); acessar fora dos limites do vetor.
- **Lacuna:** free duplo, valgrind e AddressSanitizer não aparecem.
- **Exercício:** dado o exemplo "free e depois imprime", explicar por que pode imprimir os valores certos e mesmo assim estar errado; rodar com `-fsanitize=address` para ver o erro.

---

## 08 · Tipos compostos

### 0064-struct
- **Conceitos-chave:** struct = "variável que contém outras variáveis" de tipos diversos (campos). Declarar normalmente no escopo global; `;` depois do `}` (pode-se declarar variáveis ali: `} cad1, cad2;`). Variável: `struct cadastro c;`. Acesso com `.`; strings dos campos com `strcpy`. Inicialização `{"Carlos", 18, "Avenida Brasil", 1082}`; campos omitidos = 0/"" . Atribuição `p1 = p2` copia todos os campos (inclusive vetores internos), mas só entre o **mesmo tipo de struct** (mesmo nome — `struct ponto` ≠ `struct novo_ponto` mesmo com campos iguais). Structs aninhadas: `c.ender.rua`. C99: inicialização designada `{ .x = 10, .y = 20 }` e literal composto `(struct ponto){1,2}`.
- **Explicação boa:** 4 cadastros com 16 variáveis soltas vs `struct cadastro c1, c2, c3, c4;` vs `struct cadastro c[4];`.
- **Pegadinhas:** esquecer o `;` final; comparar structs com `==` não existe; o bug `scanf` + `gets` nos exemplos de leitura (ver 0011).
- **Exercícios (8.5):** pessoa (nome, idade, endereço); ponto e distância até a origem / entre dois pontos; Retângulo com dois Pontos → área, diagonal, perímetro e "ponto está dentro?"; aluno com 3 notas → maior média entre 5; hora → maior de 5; mais novo e mais velho; dias entre duas datas.

### 0065-typedef
- **Conceitos-chave:** `typedef tipo_existente novo_nome;` cria **sinônimo**, não tipo novo (`inteiro` e `int` se misturam livremente). Uso principal: tirar o `struct` da declaração (`typedef struct cadastro cad;` ou tudo junto, com a tag opcional `typedef struct { ... } cad;`).
- **Pegadinha:** `typedef unsigned int positivos[5];` esconde que é vetor — contraexemplo de legibilidade. O livro também traz `typedef vetor int [10];` com a ordem invertida (errado; o certo é `typedef int vetor[10];`).

### 0066-vetor-de-structs
- **Conceitos-chave:** `struct cadastro c[4];` lido num for; o ponto vem **depois** dos colchetes (`c[i].nome`) porque primeiro se escolhe a posição, depois o campo; `c[1] = c[2]` é válido.
- **Exercícios:** 5 atletas (nome, esporte, idade, altura) → mais alto e mais velho; ordenar por idade decrescente.

### 0067-ponteiro-para-struct
- **Conceitos-chave:** struct é passada por valor (cópia inteira) por padrão; por referência com `struct ponto *p` e `&p1` na chamada. Acesso `(*p).x` — **parênteses obrigatórios**, porque `.` tem prioridade: `*p.x` significa `*(p.x)`. `p->x` é o atalho de `(*p).x`. Também dá para passar só um campo por valor (`f(p1.x)`) ou por referência (`f(&p1.x)`). C99: array flexível no fim da struct (`int notas[];`) alocado com `malloc(sizeof(struct aluno) + 5*sizeof(int))`.
- **Exemplo:** `atribui(struct ponto *p)` com `(*p).x = 10` vs `p->x = 10`, lado a lado.
- **Exercício:** função que recebe N e devolve vetor dinâmico de `Cadastro` preenchido pelo usuário (11.4 nº 3).
- **Imprecisão:** o livro diz que `->` também vale para enum passada por referência — enum não tem campos.

### 0068-enum
- **Conceitos-chave:** lista de constantes inteiras com nomes; a primeira vale 0 e cada uma vale a anterior + 1, a menos que se atribua valor (`{Domingo=1, Segunda, Terca, Quarta=7, Quinta,...}` → 1, 2, 3, 7, 8, 9, 10). Podem receber caracteres (`novalinha = '\n'`). Funcionam em qualquer expressão inteira (até somar dias, "ainda que não faça sentido": Segunda + Terca = 3).
- **Exercícios:** enum de dias → ler inteiro e mostrar o dia; meses com número de dias; itens de compra com preço.

### 0069-union
- **Conceitos-chave:** sintaxe igual à struct, mas **todos os campos dividem o mesmo espaço**; tamanho = o do maior campo; só um valor válido por vez; escrever num campo muda os outros.
- **Exemplo bom (com bits desenhados):** `union { short x; unsigned char c; }`: `x = 1545` → `c = 9` (byte baixo 00001001; alto 00000110 = 6); `c = 69` → `x = 1605`. Com `unsigned char c[2]`, `c[0] = 9` e `c[1] = 6` acessam os bytes de x sem operações de bits.
- **Pegadinha:** o resultado depende da ordem dos bytes (little-endian x86) — dizer isso explicitamente.
- **Exercício:** união com dois tipos básicos; inicializar um e exibir o outro; prever a saída do exemplo 1545/69.

### 0070-bits
- **Conceitos-chave:** `~ & | ^ << >>` só em tipos inteiros (float tem mantissa e expoente, não é "só um monte de bits"). Cada deslocamento equivale a ×2 ou ÷2 (divisão inteira). Compostos `&= |= ^= <<= >>=`. **Campos de bits** em structs: `unsigned int ligado:1; signed int valor:4; unsigned int :3;` (sem nome = preenchimento; tamanho 0 = alinhar no próximo byte); sem endereço (`&`, ponteiros e vetores proibidos); prefira `unsigned`.
- **Exemplos (valores para reaproveitar, x = 44 = 00101100):** `~x` = 211 (como unsigned char); `x & 167` = 36; `x | 129` = 173; `x ^ 167` = 139; `x << 2` = 176; `x >> 2` = 11.
- **Lacuna:** não mostra o uso de máscaras e flags (`flags |= 1u << n`, testar com `&`) — completar com outra fonte.
- **Exercícios:** ×2 e ÷2 com deslocamento; complemento de um número; deslocar o 1º pelo 2º; `^ | &` entre dois números.

---

## 09 · Arquivos e linha de comando

### 0072-arquivos-texto
- **Conceitos-chave:** arquivo = sequência de bytes em memória secundária, interpretada pelo programa. Texto: tudo convertido em caracteres (12345678 ocupa 8 bytes no texto vs 4 bytes como int), legível em editor, pode trocar `\n` por `\r\n` no Windows. `FILE *fp = fopen(nome, modo)` → NULL em erro; modos `r w a` (+ `b`, + `+`); `w` apaga o anterior; `a` acrescenta no fim. Fechar com `fclose` grava o que restou no **buffer**. Funções: `fputc/fgetc`, `fputs/fgets`, `fprintf/fscanf`; `stdin`, `stdout`, `stderr` são arquivos já abertos. `exit(1)` termina o programa de qualquer ponto (0 = sucesso, ≠0 = erro). `perror("msg")` mostra o motivo do erro do sistema ("No such file or directory"). `remove(nome)` apaga. Caminhos com `\\` no Windows.
- **Explicação boa do buffer:** gravar caractere a caractere no disco seria lentíssimo (posicionar a cabeça de leitura toda vez); o buffer junta e grava em lotes; `fflush(fp)` força a gravação.
- **Pegadinhas fortes (o livro erra várias):** `char c; while ((c = fgetc(f)) != EOF)` — `c` precisa ser `int` (EOF não cabe/confunde com o byte 255); **`while (!feof(f))` antes de ler** processa um item a mais no fim (o exemplo de soma de matriz do livro soma o último número duas vezes) — testar o retorno da leitura; `fclose(fp)` mesmo quando fopen retornou NULL (Fig. 12.2); `fputs` não põe `\n`; `fscanf` com `%s` para no espaço; `stdaux`/`stdprn` não são padrão.
- **Exercícios (12.10):** contar linhas; concatenar dois arquivos num terceiro; converter para maiúsculas; contar ocorrências de uma palavra; lista de compras (nome, qtd, preço unitário) → total; cadastro nome/telefone até telefone 0; nomes + datas → nomes + idades; contar vogais, palavras, frequência de cada letra; salvar matriz linha a linha em "matriz.txt".

### 0073-arquivos-binarios
- **Conceitos-chave:** binário grava os bytes exatamente como estão na memória (sem conversão, mais rápido e compacto, ilegível). `fwrite(ptr, tam_elem, qtd, fp)` e `fread(...)` retornam quantos **itens** foram processados (compare com `qtd`). Passar endereço: `&x` para variáveis e structs; vetor já é endereço. Gravar partes (`fwrite(v, sizeof(int), 2, f)` grava só as 2 primeiras). Ao gravar strings/vetores de tamanho variável, gravar **antes o tamanho** (`fwrite(&t,...)` e depois `t` chars; na leitura, ler t, ler t chars e pôr `'\0'`). `fseek(fp, deslocamento, SEEK_SET|SEEK_CUR|SEEK_END)` (deslocamento pode ser negativo), `ftell` (posição; em texto não é garantidamente nº de bytes), `rewind`, `ferror`. Tamanho do arquivo: `fseek(f,0,SEEK_END); ftell(f)`.
- **Exemplo ótimo (Fig. 12.15):** gravar vetor de 4 structs cadastro (Ricardo/Rua 1/31, Carlos/Rua 2/28, Ana/Rua 3/45, Bianca/Rua 4/32), reabrir, `fseek(f, 2*sizeof(struct cadastro), SEEK_SET)` e ler só a Ana — acesso direto a registro.
- **Pegadinhas:** abrir binário sem `b` (no Windows corrompe); o livro dá `.txt` a arquivos binários; struct com ponteiros não pode ser gravada assim (grava o endereço, não o dado); arquivo binário não é portável entre arquiteturas (tamanho/ordem de bytes).
- **Exercícios:** gravar 100 números em binário e depois somá-los; arquivo cujo 1º número diz quantos vêm → maior e menor; 5 atletas em binário → ler e mostrar mais alto e mais velho.

### 0074-argumentos
- **Conceitos-chave:** `int main(int argc, char *argv[])`; `argc ≥ 1` porque o nome do programa conta; `argv[0]` = nome do programa; argumentos chegam como strings — converter com `atoi`/`atof`/`strtol`.
- **Exemplos:** listar os parâmetros ("Nenhum parametro passado…" se argc == 1); somar os números passados (`./prog 3 4 5` → 12).
- **Pegadinha:** `atoi("abc")` retorna 0 sem avisar; preferir `strtol` com verificação.

---

## 10 a 16 · Análise e Estruturas de Dados
- **Não coberto.** O livro não trata Big-O, TAD, listas, pilhas, filas, árvores, hash nem grafos. Aproveitáveis como ponte:
  - **0076/0077 (eficiência):** comparação fatorial recursivo × iterativo e a árvore de chamadas do Fibonacci (custo exponencial).
  - **0079 (tad):** a biblioteca `aritmetica.h/.c` como primeiro exemplo de interface × implementação; `static` em funções para esconder detalhes.
  - **0080 (vetor-dinamico):** `realloc` 5 → 3 → 10.
  - **0081 em diante:** ponteiro para struct + malloc + `->` são os pré-requisitos (0067, 0059).
  - **0094–0101:** só exercícios soltos ("ordene um vetor de 10 reais", "ordene structs por idade") e a lista de `qsort/bsearch` com protótipo; ponteiro para função motivado por "ordenação genérica".

---

## Obsoleto / evitar
- **Code::Blocks** (criar projeto, "Build and run", "Add file", "Build options… -std=c99", debugger por menus): trocar por terminal + `gcc -Wall -Wextra -std=c17` + `gdb`.
- **`system("pause")` e `#include <stdlib.h>` só para ele** em praticamente todo exemplo: remover (é dependente do Windows).
- **`gets()`**: removida no C11; usar `fgets` + remoção do `\n`.
- **`fflush(stdin)`** e **`setbuf(stdin, NULL)`** para "limpar o teclado": comportamento indefinido/não portável; consumir até `\n` com getchar.
- **`while (!feof(fp))`** como laço de leitura; **`char c = fgetc(...)`** comparado com EOF.
- **`scanf("%f", &double)`**: usar `%lf`; `%d` para imprimir ponteiro/`size_t` (usar `%p`, `%zu`).
- **Tabelas com tamanhos fixos de tipos** ("int 32 bits", "long 32 bits independentemente do processador", "long double 96 bits", "void 8 bits"): ensinar `sizeof`/`limits.h`.
- **Cast no retorno de `malloc`** (desnecessário em C) e `p = realloc(p, n)` sem temporário; `realloc(p, 0)` como free.
- **Inicializar ponteiro com número** (`int *p = 0x3F8;`) e **aritmética em `void *`** (extensão GNU).
- **Ditos "C99" que não são C99:** literais binários `0b11001` (extensão GCC, padrão só no C23), intervalos `[0 ... 1] = 10` em inicialização designada (GNU), `##__VA_ARGS__` (GNU), `B[A]` como novidade (sempre valeu).
- **`setlocale(LC_ALL, "ptb")`** (nome de localidade do Windows; no Linux `"pt_BR.UTF-8"` ou `""`).
- **Expressões com UB apresentadas como corretas:** `*p = (*p)++;`, `index = ... ++index;`.
- **"Nome do array é um ponteiro"** e **"arrays são passados por referência"**: reformular (decaimento; endereço passado por valor).
- **Recomendação de um único `return` por função**: hoje se aceitam retornos antecipados (guard clauses); tratar como estilo, não regra.
- **`register`**: irrelevante com compiladores modernos (o próprio livro admite).

## Extras que não cabem no sumário
- **Classes de armazenamento** (`auto`, `extern`, `static` em local/global/função, `register`) — usar trechos em 0035 e 0039.
- **`volatile`** (variável alterada por hardware; exemplo do laço `while (resposta != 255)` que o otimizador transformaria em `while(1)`; truque `*(volatile int*)&resposta`).
- **Campos de bits** (já resumidos em 0070; podem virar extra opcional).
- **Funções variádicas** (`stdarg.h`: `va_list`, `va_start`, `va_arg`, `va_end`, `va_copy`; exemplo `soma_int(3, 4, 5, 6)` = 15; alerta de falta de *type-safety* e ataques de formato com `printf`).
- **Macros variádicas** (`__VA_ARGS__`, macro `log(...)` com `fprintf(stderr, ...)`), `_Pragma`, `#line`, `#error`, `#pragma`, `__STDC_VERSION__`.
- **`goto` e labels**: teorema da programação estruturada (não é necessário); único uso defendido: sair de 3 laços aninhados de uma vez (ex.: parar em i=2, j=3, k=1). Em C real também se usa para limpeza de recursos em caminhos de erro.
- **printf/scanf avançados**: `%n` (armazena nº de caracteres já impressos: "ABCDE%nFGHIJ%n" → 5 e 10; perigoso), `%a` (hex float), `%g`, comprimentos `h l L`, scansets.
- **`time.h`**: `time`, `localtime`, `strftime` (tabela completa de especificadores `%A %d %b %Y %H %M %S…`, mais os do C99 `%F %T %D %R`), `clock`/`CLOCKS_PER_SEC`, `difftime`, `struct tm` (mês 0–11, ano desde 1900 — pegadinha clássica). Útil para 0031 (`srand(time(NULL))`) e para medir tempo em 0076.
- **Localidade e caracteres largos**: `setlocale`, `wchar_t`, `L"..."`, `©`, `wprintf` com `%lc`/`%ls`.
- **C99 diverso**: `long long`, `_Bool`/`stdbool.h`, `_Complex`/`complex.h` (exemplo com conj, creal, cimag), `tgmath.h`, `__func__`, `inline` (comparação com macro: type-safety), `restrict` (aliasing), VLA (escopo de bloco, não inicializável, não pode ser static), `[*]` em protótipos, qualificadores `int v[const]`/`int v[static 10]`, array flexível, inicialização designada, literais compostos (`&(struct ponto){1,2}`, `(int[]){1,2,3}`).
- **IEEE 754**: `INFINITY`, `NAN`, `isnan`, `isfinite`, zero negativo; NaN não é igual nem a si mesmo — boa curiosidade para 0013/0015.
- **Lista de funções de bibliotecas padrão** (1.7: stdio, stdlib, math, ctype, string, time) — referência rápida, com protótipos às vezes errados (`fgets(char*)`, `sscanf` com int extra, `strftime` retornando `time_t`).
