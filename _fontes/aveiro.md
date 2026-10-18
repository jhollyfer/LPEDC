# Fichamento: Programação, Estruturas de Dados e Algoritmos em C (Aveiro)

- **Título:** Programação, Estruturas de Dados e Algoritmos em C
- **Autores:** António Manuel Adrego da Rocha e António Rui Oliveira e Silva Borges, Departamento de Eletrônica e Telecomunicações, Universidade de Aveiro (Portugal)
- **Origem:** apostila da disciplina Programação II, padrão ANSI C (C89), ambiente Unix/Linux, escrita para alunos vindos de Pascal
- **Lido:** 5564 linhas, por completo (7 capítulos: introdução ao C, complementos, arquivos, recursão, "memórias"/programação modular, pesquisa e ordenação, filas e pilhas)
- **Nota de linguagem:** o original está em português de Portugal. Aqui os termos foram trazidos para o Brasil: agregado → vetor/array; ficheiro → arquivo; ciclo → laço; cadeia de caracteres → string; registo → registro; alusão → protótipo/declaração; atribuição de memória → alocação; pesquisa → busca; Concha → Shell sort; Crivo → Shaker sort; tabela de dispersão → tabela hash.

## Avaliação geral

É um material sério e rigoroso, muito bom em **detalhes de C que quase ninguém explica**: conversões de tipo
com perda, ordem de avaliação, `scanf` como ferramenta de validação, a dualidade ponteiro/vetor,
modos do `fopen`, por que `while(!feof())` está errado, módulos com `static` e tipos opacos. Os exemplos de
ordenação são excelentes: **o mesmo vetor de 10 elementos passa por todos os algoritmos, com contagem de
comparações e trocas**, o que dá uma tabela comparativa pronta. Pontos fracos: comparações constantes com
Pascal (inúteis para o nosso público), estilo antigo (identificadores em MAIÚSCULAS, `unsigned` para
índice, C89), suposição de máquina de 32 bits e vários bugs nos códigos (listados por assunto e na seção
final). Não cobre listas encadeadas genéricas, AVL, heap, hash implementado nem grafos (árvore e hash só
aparecem como conceito).

---

### 0004-binario
- **Conceitos-chave:** literais inteiros em três bases: decimal, octal (prefixo `0`) e hexadecimal (`0x`). Negativos em octal/hex aparecem em complemento de dois. Um `char` com sinal vai de -128 a 127; um `unsigned char`, de 0 a 255.
- **Exemplos bons:** 54 = `066` = `0x36`; -135 em 32 bits = `0xFFFFFF79`; o caractere 'B' pode ser escrito `'\102'` (octal) ou `'\x42'` (hex).
- **Pegadinhas:** `010` vale 8, não 10 (o zero à esquerda faz o número ser lido em octal).
- **Ideia de exercício:** dados 54 e -135, escrever as formas decimal, octal e hex e conferir com `printf("%d %o %x")`.

### 0005-compilacao
- **Conceitos-chave:** `#include <...>` procura no diretório do sistema (ex.: `/usr/include`); `#include "..."` procura primeiro na pasta do projeto. Compilação separada: `cc -c modulo.c` gera `modulo.o`, e depois `cc prog.c modulo.o -o prog`. O uso de `math.h` exige `-lm` na ligação (o erro aparece no ligador, não no compilador).
- **Analogia:** o C foi pensado para espalhar o programa em vários arquivos-fonte. O `.h` é o "contrato" e o `.c` é a "obra".
- **Pegadinha:** esquecer `-lm` dá "undefined reference to sqrt", mesmo com o `#include` presente.

### 0006-primeiro-programa
- **Conceitos-chave:** o programa em C é um "mar de funções" no mesmo nível, e `main` é a que roda primeiro. `main` devolve `int` porque o shell usa esse valor (0 = sucesso), e daí o `return 0`. Comentários `/* */` **não se aninham**.
- **Ideia de exemplo:** conversão de milhas para km (fator 1,609) com leitura validada em `do...while` até o valor ser não negativo. É o programa de abertura do livro e serve de "esqueleto completo".
- **Pegadinha:** um `*/` dentro de um comentário encerra o comentário externo antes da hora.

### 0007-variaveis
- **Conceitos-chave:** em C os tipos descrevem **formato de armazenamento**, não significado: `char` é um número de 1 byte que *pode* ser lido como caractere. Declarar reserva memória e liga o nome a ela. **O valor inicial é indefinido** até a primeira atribuição. O compilador pode deixar "buracos" de alinhamento entre variáveis. `sizeof(expr)` não avalia a expressão, só olha o tipo, e o resultado é `size_t`.
- **Exemplos bons:** `char c = 'A';` e `char c = 65;` guardam o mesmo byte; já `char n = 3;` e `char c = '3';` são diferentes (3 vs 51). `%d` e `%c` mostram o mesmo byte de dois jeitos.
- **Pegadinhas:** identificadores que começam com `_` são reservados à implementação. C diferencia maiúsculas de minúsculas.
- **Ideia de exercício:** imprimir `'3'` com `%d` e `%c`, e depois `'3' - '0'`. Resposta esperada: 51, 3, 3.

### 0008-tipos-e-limites
- **Conceitos-chave:** `short` ≥ 2 bytes; `int` com 2 ou 4 bytes; `long` com 4 ou 8; `signed`/`unsigned`. Os limites estão em `limits.h` e `float.h`. `float` tem cerca de 6-7 dígitos significativos; `double`, 15-16.
- **Conversões descendentes (ótimas para ilustrar overflow):**
  - `int -1024` atribuído a `unsigned` vira 4294966272 (os bits são os mesmos; só a leitura muda);
  - `unsigned 1025` atribuído a `unsigned char` vira 1 (fica o resto da divisão por 256);
  - `int 1152` atribuído a `char` vira -128 (overflow com troca de sinal).
- **Pegadinha:** uma expressão que o compilador pode reorganizar, como `K1*K1*(K2-K3)` com K1=1024, K2=4096, K3=4094, estoura em 32 bits se for transformada em `K1*K1*K2 - K1*K1*K3`. A saída é quebrar o cálculo em etapas.
- **Ideia de exercício:** prever o resultado das três atribuições acima antes de rodar; depois conferir com `printf`.

### 0009-constantes
- **Conceitos-chave:** `#define` faz substituição textual pura. Se o valor for uma expressão, ponha-o **entre parênteses**. `const` cria uma variável protegida contra escrita, que ocupa memória (o `#define` não ocupa). Sufixos `U`, `L`, `UL` e `F`. Escapes: `\n`, `\t`, `\b`, `\"`, `\?`, `\0`.
- **Analogia:** uma constante com nome documenta o valor e centraliza a mudança. Um número repetido no código é um erro esperando para acontecer.
- **Pegadinhas:** terminar um `#define` com `;` (o `;` entra na substituição); `#define X 2+3` seguido de `X*2` dá 8, não 10.

### 0010-printf
- **Conceitos-chave:** as flags `-` (alinha à esquerda), `0` (completa com zeros), `+` (sempre mostra o sinal), espaço e `#` (prefixo 0x/0, ou ponto decimal forçado). A **precisão** muda de sentido conforme o tipo: no inteiro é o número mínimo de dígitos, no real (`f`/`e`) é o número de casas decimais, no `g` é o máximo de dígitos significativos e na string é o máximo de caracteres. `printf` devolve o número de caracteres escritos. `%%` imprime um `%`.
- **Exemplos de valores (reescritos):** `%012d` de 675 dá `000000000675`; `%12.4f` de 675.95 dá `    675.9500`; `%12.1f` arredonda para `676.0`; `%.3s` de "pim pam" dá `pim`; `%-5c` alinha o caractere à esquerda.
- **Pegadinha clássica:** no `scanf`, `double` pede `%lf`; no `printf`, `%f` já basta (os reais são promovidos a `double`).
- **Ideia de exercício:** montar uma tabela alinhada (nome com `%-10s`, nota com `%6.2f`) e prever a saída caractere a caractere.

### 0011-scanf
- **Conceitos-chave:** `scanf` devolve **quantas conversões deram certo**, ou `EOF`. Num conflito, o caractere que causou o problema **fica no buffer**. Use `%*` para ler e descartar, `%n` para contar os caracteres consumidos e `%[...]` / `%[^...]` para conjuntos de caracteres. **Ponha sempre a largura máxima em `%s`** (ex.: `%7s` para um `char[8]`).
- **Idioma muito útil (o "readln" do C):** ler o valor; depois `scanf("%*[^\n]")` para descartar o resto da linha; depois `scanf("%*c")` para consumir o `\n`; repetir enquanto o retorno for 0. As duas etapas de descarte precisam ser separadas, senão o `\n` fica para trás quando não há lixo na linha.
- **Exemplo bom:** ler uma hora `HH:MM:SS` com `"%2hu:%2hu:%2hu"`, repetindo enquanto o retorno for diferente de 3 ou os valores estiverem fora da faixa (H>23, M>59, S>59).
- **Pegadinhas:**
  - um `\n` (ou espaço) **no fim** do formato, como em `scanf("%d%d\n")`, faz o `scanf` esperar um caractere não branco, e o prompt seguinte aparece atrasado;
  - inventar um `%s[...]` (os dois formatos são alternativos, não se combinam);
  - `%s` não lê string vazia nem frase com espaço.
- **Ideias de exercícios:** (1) menu com opção 1-3 que rejeita lixo e linhas longas; (2) ler um telefone só com dígitos usando `%9[0123456789]`; (3) explicar por que o programa com `"%d%d\n"` "trava".

### 0012-aritmetica
- **Conceitos-chave:** precedência e associatividade; `/` faz divisão inteira se os dois operandos forem inteiros; `%` só aceita inteiros. Relacionais retornam `int` 0/1, e `>=`, `<=` têm precedência **maior** que `==`, `!=`.
- **Pegadinhas:**
  - `X = K * K++` dá resultado imprevisível (9 ou 12). Regra prática: uma variável com efeito colateral deve aparecer **uma vez só** na expressão;
  - o livro diz que `7/(-3)` pode dar -2 ou -3 conforme o compilador. Isso valia no C89; **desde o C99 a divisão sempre trunca em direção a zero** (dá -2).
- **Ideia de exercício:** com `X = 2`, avaliar `Y = 5 * X++` e depois, partindo de novo de `X = 2`, `Y = 5 * ++X`. Resposta: Y=10, X=3 e Y=15, X=3.

### 0013-conversao
- **Conceitos-chave:** promoções automáticas (`char`/`short` → `int`, `float` → `double` nas expressões) e a hierarquia `long double > double > float > unsigned long > long > unsigned int > int`. Converter subindo na hierarquia é seguro; descendo, pode haver arredondamento, truncamento ou overflow.
- **Exemplo bom:** `int A=5, B=2; double D;` então `D = A/B` dá 2.0, mas `D = (double)A/B` dá 2.5.
- **Pegadinha:** `(double)(A/B)` continua dando 2.0, porque o cast vem depois da divisão inteira.

### 0014-atribuicao
- **Conceitos-chave:** quatro formas: `=`, `op=`, `++`/`--` e o condicional `?:`. A atribuição **também é uma expressão** (vale o valor atribuído), o que permite `X = Y = Z`.
- **Pegadinha:** encadear operadores compostos, como `X += Y -= Z`, compila mas é ilegível. O livro desaconselha, com razão.

### 0015-math
- **Conceitos-chave:** `sqrt`, `pow`, `fabs`, `floor`, `ceil`, `fmod`, `exp`, `log`, `log10` e as trigonométricas. Erros de domínio sinalizam `errno = EDOM` (resultado `nan`); estouro sinaliza `ERANGE` (`inf`). `perror`/`strerror` traduzem o erro.
- **Exemplo bom:** zerar `errno`, chamar `sqrt(-1)`, testar `errno` e imprimir `strerror(errno)` ("Numerical argument out of domain").
- **Lembrete:** compilar com `-lm`.

### 0017-relacionais / 0018-logicos
- **Conceitos-chave:** 0 é falso e qualquer outro valor é verdadeiro. `&&` e `||` param assim que o resultado está definido (curto-circuito), da esquerda para a direita. Os operadores bit a bit (`& | ^ ~ << >>`) atuam em cada bit.
- **Pegadinhas:** **nunca usar `==` com `float`/`double`**; não usar um real como contador de laço.

### 0019-if / 0020-if-else / 0021-else-if
- **Conceitos-chave:** a condição vem entre parênteses e não há `then`. Em `if` encadeado, o `else` se liga ao `if` mais próximo.
- **Exemplos bons:**
  - classificar um caractere em maiúsculo, minúsculo, dígito ou outro com `else if`;
  - "else pendurado": `if (V1>0) if (V2>0) V2++; else V1++;` liga o `else` ao **segundo** `if`, mesmo que a indentação diga o contrário. Soluções: chaves (a preferida) ou um `else ;` vazio (só como curiosidade).
- **Pegadinha:** `if (A = 5) B = 2;` atribui, a expressão vale 5 (verdadeiro) e B vira sempre 2. O compilador não acusa erro.

### 0022-ternario
- **Exemplo:** valor absoluto: `ABSX = X < 0 ? -X : X;`. É o único operador ternário do C e associa da direita para a esquerda.

### 0023-switch
- **Conceitos-chave:** só aceita valores inteiros. A execução **segue em frente** a partir do `case` de entrada até achar um `break` (fall-through). Não aceita faixas de valores.
- **Exemplo bom:** vogais "ásperas" (a, e, o) e "doces" (i, u), empilhando vários `case` para a mesma ação.
- **Ideia de exercício:** tirar um `break` e prever o que é impresso.

### 0025-while / 0026-do-while
- **Conceitos-chave:** `do...while` repete **enquanto** a condição é verdadeira (o `repeat...until` do Pascal repetia *até* ela ser verdadeira, ou seja, a condição é a negação).
- **Exemplo bom (padrão sentinela):** média de números lidos até aparecer 0. Com `do-while` é preciso um `if` dentro do laço para não contar o 0; com `while`, a leitura acontece antes do laço e de novo no fim do corpo. Os dois lado a lado mostram bem o contraste.
- **Pegadinha:** todas as variáveis da condição precisam estar inicializadas antes do laço.

### 0027-for
- **Conceitos-chave:** três partes (inicialização, condição, atualização), cada uma pode ser omitida; `for(;;)` é um laço infinito. O contador tem valor definido depois do laço. Bom estilo: não mexer no contador dentro do corpo.
- **Exemplo bom:** potências de 2 com duas variáveis no `for`: `for (POT=1, I=1; I<=N; I++, POT*=2)`.
- **Pegadinha:** escrever a condição de parada no lugar da de continuação (`I == N`): o laço não roda nenhuma vez.

### 0028-break-continue
- **Exemplos bons:**
  - `break`: somar no máximo 10 valores não negativos, parando antes se aparecer um negativo. A condição do laço fica simples;
  - `continue`: contar as letras de uma linha e trocar a caixa só das vogais, pulando o que não é letra ou não é vogal;
  - laço de corpo vazio: `while (s[++comp] != '\0');` calcula o tamanho da string (é um `strlen` manual).

### 0031-aleatorios
- **Conceitos-chave:** `rand()` devolve um valor de 0 a `RAND_MAX`; `srand(semente)` fixa a sequência. Mesma semente, mesma sequência.

### 0033-funcoes / 0034-parametros
- **Conceitos-chave:** em C só existe a "função generalizada"; um procedimento é uma função `void`. Cada função aparece de três formas: definição, chamada e protótipo (o "contrato", que permite ao compilador conferir quantidade e tipo dos argumentos e converter quando possível). Parâmetros passam **por valor**; para alterar uma variável do chamador, passe o endereço dela.
- **Analogia:** função como caixa-preta: entram parâmetros, saem um resultado e/ou parâmetros de saída, e o meio fica escondido.
- **Pegadinha:** chegar ao fim de uma função não `void` sem `return` deixa o valor devolvido indefinido.
- **Ideia de exemplo:** `CONVERTE_DISTANCIA(double ml)` usada numa atribuição e direto dentro do `printf`.

### 0035-escopo
- **Conceitos-chave (quatro níveis):** global de programa (visível em todos os arquivos), global de arquivo (`static` fora de função), local de função e de bloco. **`static` tem dois sentidos:** fora de função limita a visibilidade ao arquivo; dentro de função dá duração permanente. `extern` declara sem alocar; a definição é única. Vale o nome declarado mais perto (sombreamento).
- **Exemplo excelente:** uma função `INCREMENTAR` com `int TEMP = 1;` e `static int PERM = 1;`, as duas incrementadas e impressas. Chamada 3 vezes, imprime TEMP = 2, 2, 2 e PERM = 2, 3, 4.
- **Pegadinhas:**
  - declarar uma variável local com o mesmo nome de um parâmetro é erro;
  - uma `static` só pode ser inicializada com constante e, sem inicialização, vale 0;
  - o livro diz que as globais ficam "na RAM" e as locais "na stack". Na verdade tudo está na RAM: as globais ficam no segmento de dados.
- **Ideia de exercício:** prever a saída de INCREMENTAR chamada 4 vezes. Resposta: TEMP 2, 2, 2, 2 e PERM 2, 3, 4, 5.

### 0036-pilha-de-chamadas
- **Conceitos-chave:** cada chamada copia os parâmetros e guarda o ponto de retorno na pilha. Recursão profunda pode **esgotar a pilha**.
- **Ideia de exemplo:** a "árvore de recorrência" do fatorial de 3: cada caixa é uma ativação, e o resultado é montado na volta (1 × 1 × 2 × 3 = 6).

### 0037-recursao
- **Conceitos-chave:** um ou mais casos de parada mais um passo que reduz o problema. Esqueleto: se chegou ao caso base, resolve; senão, quebra em subproblemas iguais e menores.
- **Exemplos bons:**
  - fatorial iterativo e recursivo, com a proteção `if (N < 0) return 0;` para não cair em recursão infinita;
  - seno por série de Taylor reescrito sem fatorial, por fatoração sucessiva (Horner). Iterativo de baixo para cima, recursivo de cima para baixo; a versão recursiva precisa de **duas funções** e é pior.
- **Dados úteis:** o maior fatorial que cabe em 32 bits é 12! = 479001600.
- **Ideia de exercício:** tabela comparando o cosseno por Taylor com 5, 10 e 15 termos contra `cos()` num intervalo lido do teclado. Uma versão iterativa e uma recursiva.

### 0038-recursao-na-pratica
- **Fibonacci:** a árvore de fib(5) recalcula fib(3) duas vezes, fib(2) três vezes, fib(1) cinco vezes e fib(0) três vezes. As adições crescem 7, 12, 20, 33 (quase dobram a cada passo, ou seja, custo exponencial). Há três versões: recursiva, programação dinâmica (vetor `FIB[]` com 0, 1, 1) e iterativa com três variáveis (ANTERIOR, ATUAL, PRÓXIMO), que é linear e a melhor. O maior que cabe em `unsigned` de 32 bits é fib(47) = 2971215073.
- **Coeficiente binomial:** a fórmula com fatoriais estoura; usar o triângulo de Pascal, C(n,k) = C(n-1,k) + C(n-1,k-1). Exemplo: C(5,3) = 10. A versão recursiva calcula 2·C(n,k) − 1 termos; a dinâmica com matriz calcula cerca de N·K. O maior que cabe em 32 bits é C(35,16) = 4059928950.
- **Permutações (backtracking):** troca, chama a recursão, destroca. "abc" gera 6 permutações.
- **Hanói:** move N−1 discos de A para C, o maior de A para B, e N−1 de C para B; são 2^N − 1 movimentos. Há uma simulação completa com três vetores e contadores, imprimindo o estado das torres a cada movimento (com 3 discos: 7 movimentos). Não rodar com mais de ~10 discos.
- **Determinante:** cálculo recursivo por operações de colunas até chegar a uma matriz diagonal (exemplo 4×4 com resultado 15). É avançado: só como extra.
- **Ideias de exercícios (do livro, reescritas):** MDC de Euclides iterativo e recursivo; Ackermann recursivo e com tabela; permutações de "0123456789" mostrando só as que alternam dígito par e ímpar.
- **Pegadinhas:**
  - no código de permutações do livro, `printf("%s", LISTA[J])` está errado (o certo é `LISTA`);
  - na árvore de Fibonacci, o código para em N ≤ 2, mas o desenho desce até 0 (inconsistência).

### 0039-modulos
- **Conceitos-chave:** a programação modular esconde não só o algoritmo mas também os dados ("decida os módulos e encapsule as estruturas neles"). Um módulo é um `.h` (constantes de erro e protótipos) mais um `.c` (dados internos `static` e funções auxiliares `static`). Proteja o `.h` com `#ifndef/#define/#endif`.
- **Duas formas de deixar o módulo genérico:**
  - (a) **abstrato**: `void*`, uma função `Create(tamanho_do_elemento)` e `memcpy`;
  - (b) **concreto**: um `elemento.h` com `typedef ... TIPO_ELEMENTO` e `N_ELEMENTOS`. Exige recompilar o módulo a cada mudança.
- **Exemplo excelente:** o módulo de números complexos com **tipo opaco**: `typedef struct complexo *PtComplexo;` no `.h` e a struct definida só no `.c`. Permite várias instâncias e trocar a representação (cartesiana ou polar) sem mexer em quem usa. O módulo tem funções para criar, ler, escrever, somar, subtrair, multiplicar, dividir e apagar (`Apagar(PtComplexo *)` libera e põe NULL).
- **Pegadinhas:**
  - os guards do livro (`_MODULO`, `_ELEMENTO`) começam com `_` + maiúscula, que é **nome reservado**. Usar `MODULO_H`;
  - `Complexo_Nulo` devolve 0 quando o número É nulo (lógica invertida e confusa);
  - na calculadora de complexos, `while (Opcao<1 && Opcao>7)` nunca é verdadeiro (o certo é `||`);
  - cada operação cria um novo complexo, que precisa ser apagado (risco de vazamento).

### 0040-preprocessador
- Apenas `#define` (com o alerta dos parênteses e do `;`), `#include` e os guards. Não há conteúdo sobre macros com parâmetros nem `#ifdef` de depuração.

### 0042-vetores
- **Conceitos-chave:** inicialização parcial zera o resto (`double B[3] = {10.2, 11.8};` deixa `B[2] = 0`); sem tamanho, o compilador conta os elementos (`int C[] = {22, 12};`). O índice começa em 0. O nome do vetor é um **ponteiro constante** (`A = ...` é ilegal).
- **Exemplo de pegadinha imperdível:** `int I, AR[10]; for (I=0; I<=10; I++) AR[I]=0;`. Na máquina do livro, `AR[10]` caía em cima de `I`, que voltava a 0, e o laço ficava infinito. Serve para mostrar que **C não confere limites** (na prática é comportamento indefinido e depende do layout).
- **Ideia de exercício:** prever o que pode acontecer com o código acima, e depois reproduzir com `-fsanitize=address`.

### 0043-vetores-e-funcoes
- **Conceitos-chave:** a função não sabe o tamanho do vetor recebido, então passe-o junto. `sizeof(v)/sizeof(v[0])` só funciona **onde o vetor foi declarado**.
- **Exemplo:** `INICIALIZAR(int A[], int N)` zerando o vetor do chamador. Isso mostra que a função altera o original.

### 0044-matrizes
- **Conceitos-chave:** uma matriz é um vetor de vetores, guardado linha após linha em memória contígua. Na passagem para função, só a primeira dimensão pode ser omitida (`int M[][COL]`). Inicialização parcial por linha: `int C[3][3] = {{10},{13,14}};` deixa todo o resto em zero.
- **Exercício pronto:** `A[I] = I` para I = 0..2; depois `B[I][J] = A[(I+J)%3]` numa matriz 2×3. Resposta: linha 0 = 0 1 2, linha 1 = 1 2 0.
- **Exemplo de layout:** o elemento `[i][j][k]` de uma matriz X×Y×Z está no deslocamento `i*Y*Z + j*Z + k`.
- **Pegadinha:** o livro passa uma matriz 3D como `int AM[][][]` / `int ***`. **Isso não compila (ou está errado):** uma matriz estática não é um ponteiro para ponteiro.

### 0045-caracteres
- **Conceitos-chave:** `ctype.h` tem as funções de teste (`isalpha`, `isdigit`, `isspace`, `isupper`, ...) e de conversão (`toupper`, `tolower`).
- **Exemplo excelente (cifra de César):** `'a' + (c - 'a' + 26 + K) % 26`. 'z' deslocado 3 vira 'c'; o `+26` permite K negativo.
- **Ideia de exercício:** codificar e decodificar "zebra" com K=3 e K=-3 (resposta: "cheud" e de volta "zebra").

### 0046-strings
- **Conceitos-chave:** uma string é um vetor de `char` terminado em `'\0'`, então reserve tamanho + 1. Casos de declaração:
  - `char v[5] = {'a','e','i','o','u'};` **não** é string (falta o `\0`);
  - `char c[10] = "aveiro";` é string (o resto do vetor é zerado);
  - `char t[] = "tudo bem";` tem tamanho exato (9).
- **Biblioteca `string.h`:**
  - `memcpy` exige regiões que não se sobrepõem; `memmove` aceita sobreposição;
  - `strncpy` **pode não colocar o `\0`**;
  - `strcmp` devolve <0, 0 ou >0, então `!strcmp(a,b)` quer dizer "iguais";
  - `strtok` **modifica a string** e guarda estado interno (as chamadas seguintes recebem `NULL`).
- **Exemplos bons:**
  - `strtok("#era$#uma$vez#um$", "$#")` dá "era", "uma", "vez", "um";
  - `sscanf("Aveiro, 25 de Fevereiro de 2003", "%9[^,],%d de %9s de %d", ...)` separa cidade, dia, mês e ano;
  - montar um formato com `sprintf(fmt, "%%%ds", MAX)`, que produz "%40s".
- **Pegadinhas:** `cidade = "Lisboa"` é erro (use `strcpy`); `'a'` (1 byte) é diferente de `"a"` (2 bytes).
- **Ideia de exercício:** ler frases até digitar "FIM" (no máximo 10), contando-as.

### 0047-lendo-strings
- **Conceitos-chave:** `scanf("%79[^\n]")` lê uma linha com espaços e limite; `fgets(s, n, f)` lê até n−1 caracteres e **guarda o `\n`** se ele couber; `fputs` não acrescenta `\n`.
- **Exemplo:** depois da leitura, testar o retorno do `scanf`: se for 0, a linha estava vazia, e então `s[0] = '\0'`.

### 0049-memoria / 0050-ponteiros
- **Conceitos-chave:** um ponteiro não é "só um endereço": ele tem **tipo**. Dois ponteiros podem guardar o mesmo endereço e ser coisas diferentes (`int*` olhando 4 bytes, `double*` olhando 8, no mesmo lugar). `NULL` não aponta para nada.
- **Pegadinhas:**
  - `int *PA; *PA = 23;` grava num lugar desconhecido. Inicialize o ponteiro, nem que seja com `NULL`;
  - o livro afirma que todo ponteiro tem 4 bytes (só em 32 bits; hoje são 8).

### 0051-passagem-por-referencia
- **Exemplo:** `TROCA(int *X, int *Y)` chamada com `TROCA(&A, &B)`. Também explica o `&` no `scanf` e por que um vetor vai sem `&`.

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** `A == &A[0]`, `A+i == &A[i]`, `*(A+i) == A[i]`. Somar 1 a um ponteiro avança `sizeof(tipo)` bytes. A subtração de ponteiros dá a distância em elementos; dá para comparar ponteiros do mesmo tipo; não há aritmética com `void*`.
- **Exemplo:** `int A[8], *PA = A; PA++; PA += 4; PA -= 2;` deixa PA em A[3]; `&A[3] - &A[0]` vale 3.
- **Matriz:** `B[i]` equivale a `&B[i][0]`, e `B[i][j]` a `*(*(B+i)+j)`. Ponteiro para linha: `int (*PB)[N2] = B;`.
- **Precedência:** `TIPO *AP[4]` é um vetor de 4 ponteiros; `TIPO (*PA)[4]` é um ponteiro para um vetor de 4.

### 0053-ponteiros-e-strings
- **Exemplo bom:** `char *PTS = "Aveiro";` aponta para um literal **só de leitura**: `*PTS = 'A'` falha em tempo de execução, mas `PTS = "Lisboa"` é válido. Já `char CIDADE[10] = "aveiro";` permite `CIDADE[0] = 'A'`, mas não `CIDADE = "Lisboa"`.
- **Exemplo de vetor de strings:** `char *FLORES[4] = {"rosa","dahlia","cravo"};` deixa o quarto elemento NULL. O mês por extenso usa um vetor de 13 strings com o índice 0 = "MêsErrado" (sentinela para mês inválido).

### 0054-ponteiro-para-ponteiro
- **Exemplos:** `int A, *PA = &A, **PPA = &PA; **PPA = 45;`. Na agenda em arquivo, `ABRIR(char nome[], FILE **FP)` devolve o `FILE*` por referência.

### 0055-ponteiro-para-funcao
- **Exemplo excelente:** `typedef int (*PtFComp)(TElem, TElem);` com três comparadores (CompNRegisto, CompNome, CompData) que devolvem -1, 0 ou 1, mais um parâmetro `tord` (1 crescente, -1 decrescente). Troca só se `fcomp(a,b) == tord`. O mesmo algoritmo ordena pintores por nome (crescente), por data de nascimento (decrescente) e por registro (crescente). `fcomp = CompNome;` (o nome da função já é um ponteiro).
- **Extra:** contar comparações e trocas com uma função "embrulho" que tem um contador `static` e modos INIC, NORM e REP.
- **Pegadinhas:** o livro **define funções dentro do `.h`** (dá definição múltipla se dois `.c` incluírem o arquivo); passa `TElem` grande por valor. Ligar com `qsort` e comparadores `const void*`.

### 0056-void-generico
- **Conceitos-chave:** não existe variável `void`, só `void*`. `*PV = 5` é ilegal; `*(int*)PV = 5` é válido. `void*` converte para qualquer ponteiro de objeto e vice-versa sem cast; entre tipos diferentes, só com cast.
- **Exemplo grande:** fila e pilha abstratas com `memcpy(dest, orig, size)`, que trabalham com qualquer tipo.

### 0058-pilha-e-heap / 0059-malloc-free / 0060-calloc-realloc
- **Conceitos-chave:** `malloc` (não inicializa), `calloc` (zera), `realloc` (redimensiona, pode mover o bloco) e `free`. Teste sempre se veio `NULL`.
- **Exemplo bom:** um arquivo cuja primeira linha diz N, seguido de N inteiros: `calloc(N, sizeof(int))`, leitura, fechar o arquivo, `free`. Dimensionar o vetor "pelo pior caso" desperdiça memória e mesmo assim pode faltar.
- **Implementações "semiestáticas"** (vetor de ponteiros, cada elemento com `malloc`): uma ponte didática entre o vetor e a lista.

### 0062-erros-de-memoria
- Fontes de exemplos de erro tiradas do próprio livro: vetor estourado no `for` (`<=`); ponteiro não inicializado; `strncpy` sem `\0`; função que devolve ponteiro para variável local (o livro "resolve" com `static`; hoje se prefere devolver a struct por valor ou usar `malloc`); `Merge_Sort` com `calloc` sem testar `NULL`.

### 0064-struct / 0065-typedef / 0066-vetor-de-structs / 0067-ponteiro-para-struct
- **Conceitos-chave:** vetor = acesso por índice; struct = acesso **por nome**. Duas formas de declarar: `struct tag {...};` ou `typedef struct {...} T;`. Inicialização em ordem: `{"Vincent Van Gogh", 'M', {30, 3, 1853}}`. **Structs podem ser atribuídas** com `=`, vetores não. `p->campo` é o mesmo que `(*p).campo`. Uma struct que aponta para si mesma precisa da tag: `typedef struct tnodo { ...; struct tnodo *prox; } TNODO;`.
- **Passagem:** por valor quando a função só lê e a struct é pequena; por ponteiro quando altera ou a struct é grande (ex.: `LER_DADOS(TDADOS *p)` e `ESCREVER_DADOS(TDADOS p)`).
- **Exemplo pronto:** um vetor com 5 pintores (Van Gogh, Vieira da Silva, Modigliani, Monet, O'Keeffe) e a função que conta os homens, em duas versões: com índice e com ponteiro `P++`.
- **Pegadinha:** devolver o endereço de uma struct local é proibido (morre quando a função termina).

### 0068-enum
- **Exemplos:** `enum t_cor {BRANCO, AZUL, VERDE, ROSA, PRETO};` e `typedef enum {SEGUNDA=2, TERCA, QUARTA, QUINTA, SEXTA} T_DIA_UTIL;` (os seguintes continuam a contagem). Dá para fazer conta: `DIA += 4`.
- **Pegadinha:** o livro lê um enum com `scanf("%1d", &DIA)`. É arriscado, porque o tamanho do enum não é garantido; leia num `int` e converta.

### 0070-bits
- **Conceitos-chave:** `& | ^ ~ << >>`. Deslocar uma quantidade ≥ largura do tipo é indefinido; deslocar valor `signed` não é portátil, então faça cast para `unsigned` antes.

### 0072-arquivos-texto
- **Conceitos-chave:** todo dispositivo é um **stream** (sequência de bytes num buffer). `FILE` guarda a posição, o buffer, o indicador de erro e o de EOF. `stdin`, `stdout` e `stderr` já vêm abertos. Modos `r`, `w`, `a`, `r+`, `w+`, `a+` (a tabela de permissões é ótima). `fopen` devolve NULL e preenche `errno`.
- **Bons hábitos do livro:** testar `fopen`; mandar o erro para `stderr` (o `stdout` pode estar redirecionado); terminar com `exit(EXIT_FAILURE)`; se a abertura do segundo arquivo falhar, fechar o primeiro; `fclose` descarrega o buffer.
- **Laço de leitura correto:** `while ((n = fscanf(f, fmt, ...)) == NITEMS) {...}` e depois `if (n != EOF)` acusa uma linha mal formatada. Variante: continuar lendo e só avisar as linhas ruins.
- **Pegadinha central:** **nunca usar `while (!feof(f))`**. O `feof` só fica verdadeiro *depois* de uma leitura falhar: a última linha é processada duas vezes e um arquivo vazio dá problema.
- **Exemplos:**
  - converter um arquivo para minúsculas caractere a caractere (`tolower`, com os nomes vindos de `argv`);
  - aniversariantes de 29/02: linhas `registro:nome:dia:mes:ano:telefone` lidas com `"%*d:%40[^:]:%d:%d:%*d:%9s\n"`.
- **Ideia de exercício:** gravar os aniversariantes num arquivo de saída cujo nome vem da linha de comando.

### 0073-arquivos-binarios
- **Conceitos-chave:** um arquivo binário costuma ter **cabeçalho + registros de tamanho fixo**, o que permite acesso aleatório. `fread`/`fwrite` devolvem o número de elementos efetivamente transferidos. `fseek` com SEEK_SET, SEEK_CUR e SEEK_END (em texto, só SEEK_SET com 0 ou com um valor vindo de `ftell`); `ftell`; `rewind` (também limpa erro e EOF); `fflush`; `remove`; `rename`; `tmpfile`.
- **Exemplo-projeto excelente (agenda telefônica binária):**
  - o cabeçalho guarda o número de registros; cada registro tem nome[41], telefone[16] e data;
  - menu: inserir em ordem alfabética, apagar por telefone, listar, sair;
  - abre com `rb+`; se o arquivo não existir, pergunta se deve criá-lo com `wb+` e grava 0 no cabeçalho;
  - posição do registro P = `sizeof(cabeçalho) + P*sizeof(registro)`;
  - inserir desloca os registros **de trás para frente**; apagar desloca de frente para trás;
  - `fflush` depois de atualizar o cabeçalho; validação de telefone com `%15[0123456789]`.
  - Serve como "juntando-tudo" do módulo 09 (e lembra o insertion sort).

### 0074-argumentos
- **Conceitos-chave:** `int main(int argc, char *argv[])`; `argv[0]` é o nome do programa. Valide `argc` e imprima o uso: `fprintf(stderr, "Uso: %s entrada saida\n", argv[0]);`.

### 0076-eficiencia / 0077-big-o
- **Conceitos-chave:** ordem de grandeza = o termo que domina (n² + n é O(n²)). Busca sequencial: pior caso N, média (N+1)/2, ou seja O(N). Busca binária: pior caso log₂(N+1), ou seja O(log N). O pior caso da ordenação é o vetor invertido; o melhor, o já ordenado; o caso médio se mede com vetores aleatórios.
- **Critério prático ótimo:** comparação barata com elementos pesados pede minimizar trocas; comparação cara (strings longas) com elementos leves ou ponteiros pede minimizar comparações.

### 0079-tad
- **Conceitos-chave:** um TAD é interface (`.h`) + implementação escondida (`.c`). Interfaces com **códigos de retorno** (OK, NULL_PTR, NO_MEM, EMPTY, FULL...) em vez de imprimir dentro do módulo.
- **As quatro "memórias" (boa visão geral de TADs):**
  - RAM: acesso por índice (Read/Write/Search/Sort);
  - FIFO: entra na cauda, sai pela cabeça;
  - LIFO: entra e sai pelo topo;
  - CAM (memória associativa): acesso por chave, sempre ordenada.
- **Três implementações para o mesmo TAD:**
  - estática: vetor de elementos;
  - semiestática: vetor de ponteiros;
  - dinâmica: lista ou árvore, sem limite.
- **Exemplo:** a mesma interface `Fifo_In`/`Fifo_Out` com três `.c` diferentes. Mostra que o usuário não muda nada.

### 0081-lista-encadeada
- **Conceitos-chave:** o nó tem um ponteiro para o elemento e um para o próximo; o último aponta para NULL. Inserção na fila: aloca o nó, aloca o elemento (se falhar, libera o nó), liga o nó, atualiza a cauda e só então copia o dado. Remoção: copia o dado, avança a cabeça e libera o elemento e o nó, nessa ordem.

### 0084-lista-dupla
- Aparece só como conceito: a CAM dinâmica linear usa uma lista duplamente encadeada porque precisa andar nos dois sentidos.

### 0087-pilha
- **Implementação estática:** `PILHA[top++] = e;` e `*p = PILHA[--top];`; `top == N` quer dizer cheia, `top == 0` quer dizer vazia. Aqui o **topo é a primeira posição livre**, enquanto outro material usa topo = -1. Vale comparar as duas convenções.
- **Interface:** `Stack_Push(TElem e)` recebe por valor; `Stack_Pop(TElem *p)` devolve NULL_PTR se `p` for nulo e STACK_EMPTY se a pilha estiver vazia.

### 0088-pilha-encadeada
- **Conceitos-chave:** cada nó aponta para o anterior (`pant`). Push: `novo->pant = top; top = novo;`. Pop: `top = top->pant;`. `top == NULL` quer dizer vazia; nunca enche (no máximo, falta memória).
- **Versão abstrata com várias instâncias:** `typedef struct stack *PtStack;`, `Stack_Create(sizeof(char))` e `Stack_Destroy(&p)`. **Exemplo:** dupla inversão de um texto com duas pilhas.

### 0089-pilha-aplicacoes
- **Exemplo excelente (parênteses balanceados com `( [ {`):**
  - expressão boa: `{A+B*[C/(F+A)+(C+D)*(E-F)]}/[(A+B)*C]`;
  - contraexemplo que **mostra por que contar não basta**: trocar `]}` por `}]`;
  - algoritmo: empilha os que abrem; ao fechar, desempilha e compara. Se a pilha estiver vazia ao fechar, há mais fechamentos que aberturas; se sobrar algo no fim, há mais aberturas;
  - as quatro saídas possíveis: balanceada, "[ e } discordantes", sobra de direitos, sobra de esquerdos.
- **Outro exemplo:** palíndromo usando fila e pilha juntas (o da frente da fila contra o topo da pilha).
- **Aplicações citadas:** recursão, avaliação de notação pós-fixa e análise sintática de blocos aninhados.
- **Pegadinha:** o programa lê a expressão com `%80s`, então ela não pode ter espaços.

### 0090-fila
- **Fila circular estática:** a cauda é a primeira posição livre; a cabeça é o próximo elemento a sair; **cabeça = N é a sentinela de fila vazia** (assim não sobra ambiguidade entre cheia e vazia sem contador). Ao inserir o primeiro elemento, cabeça = cauda; a fila enche quando a cauda alcança a cabeça; ao tirar o último, a cabeça volta a N. A volta é feita com `% N`. A alternativa linear desloca todos os elementos (ineficiente).
- **Aplicações:** fila de impressão em rede, sincronização de processos, simulação de atendimento.
- **Pegadinha grave no código do livro:** `tail = ++tail % N_ELEMENTOS;` é **comportamento indefinido** (a mesma variável é modificada duas vezes). Escreva `tail = (tail + 1) % N;`.
- **Ideia de exercício:** com N=4, simular In(1), In(2), Out, In(3), In(4), In(5) (cheia?), Out, Out, mostrando cabeça e cauda em cada passo.

### 0091-fila-encadeada
- **Conceitos-chave:** ponteiros `head` e `tail`; os dois NULL quer dizer vazia. Ao remover o último elemento, zerar também o `tail` (esquecer isso é um bug clássico).
- **Versão abstrata:** `typedef struct fifo *PtFifo;` com uma struct `{size, head, tail}`; `Fifo_Create(sz)` devolve NULL se `sz == 0`.

### 0094-busca-sequencial
- **Funções com índice de início (reaproveitáveis):** ProcurarMaior, ProcurarMenor (em empate, o primeiro), ProcurarValor (devolve -1 se não achar, com `return` dentro do `for`).
- **"Encaixe" (ótimo e pouco visto):**
  - *first fit*: o primeiro valor ≤ alvo;
  - *best fit*: o maior valor ≤ alvo;
  - *worst fit*: o menor valor ≤ alvo.
- **Analogia:** sobra de 100 cm de calha e cortes de 80, 50 e 40 cm. O best fit pega 80 e sobram 20; o worst fit pega 40, depois 50, e sobram só 10.
- **Valores prontos:** vetor `20 3 330 25 22 24 15 32 42 2 5 1 8 7 6 39 55 145 209 250`, começando no índice 7:
  - maior = 250 (índice 19), menor = 1 (índice 11);
  - procurar 55 dá o índice 16; procurar 40 dá -1;
  - com alvo 40: first fit = 32 (índice 7), best fit = 39 (índice 15), worst fit = 1 (índice 11);
  - começando no índice 17, todos dão -1.
- **Analogia de pauta:** pauta desordenada pede busca sequencial; ordenada por número pede busca binária; separada por curso e depois ordenada pede tabela/hash.

### 0095-busca-binaria
- **Trace pronto:** vetor `3 7 20 25 26 28 30 34 42 44 50 60 68 75 86 99 125 145 209 250`.
  - Procurar 34: meio no índice 9 (44), depois 4 (26), depois 6 (30), depois 7 (34): achou em 4 tentativas (a sequencial levaria 8).
  - Procurar 40: 5 tentativas até mínimo e máximo se cruzarem.
- **Pegadinhas (todas reais no código do livro):**
  - `return -1` dentro do `while`;
  - a versão recursiva **sem `return`** nas chamadas recursivas, o que perde o resultado;
  - índices `unsigned`: `maximo = medio - 1` com `medio = 0` dá a volta para um número enorme;
  - `(min+max)/2` pode estourar; usar `min + (max-min)/2`.
- **Ideia de exercício:** dar o código do livro com esses defeitos e pedir para achá-los.

### 0096-bubble-sort / 0097-selection-sort / 0098-insertion-sort
- **Vetor-padrão do livro:** `209 330 25 15 42 2 32 8 55 145`, que vira `2 8 15 25 32 42 55 145 209 330`.
- **Tabela comparativa (comparações / trocas):**

| Algoritmo | Comparações | Trocas |
|---|---|---|
| "Sequencial" (troca sempre que acha um menor) | 45 | 25 |
| Seleção | 45 | 7 |
| Bolha | 45 | 25 |
| Shell v1 (troca) | 52 | 11 |
| Shell v2 (inserção) | 29 | ~18 |
| Shaker | 39 | 25 |
| Inserção | 34 | ~14 (43 atribuições) |

- **Seleção:** guardar o índice do mínimo e trocar no máximo uma vez por passada, então O(N) trocas, mas continua O(N²) em comparações.
- **Bolha:** varre de trás para frente e para quando uma passada não troca nada. É boa para vetor quase ordenado e péssima para vetor muito desordenado.
- **Inserção:** analogia da mão de cartas. Cópia para temporário, desloca os maiores, insere. Atribuições = deslocamentos + 2(N−1); uma troca equivale a 3 atribuições. Na média faz cerca de N²/4. **É a melhor das simples para vetores parcialmente ordenados.** O livro tem o trace passo a passo do vetor-padrão.
- **Extras:** Shell sort (a sequência de incrementos muda a complexidade: Shell O(N²), Hibbard O(N^1,5), Sedgewick O(N^(4/3))) e Shaker sort (bolha nos dois sentidos, usando a posição da última troca).
- **Ideia de exercício:** rodar a seleção no vetor-padrão à mão e contar as trocas (resposta: 7).

### 0099-merge-sort
- **Intercalação de duas listas:** A = `8 32 42 209 330` e B = `2 15 25 55 145` dão 8 comparações até B acabar; o resto de A é copiado. Melhor caso N/2 comparações, pior N−1. Funciona também para **ordenação externa** (arquivos).
- **Merge sort recursivo:** cópia para um vetor temporário alocado em cada intercalação; no vetor-padrão, 21 comparações e 68 atribuições. Melhor caso (N log N)/2, pior N log N − N + 1.
- **Exercício do livro:** intercalação que remove repetidos.

### 0100-quick-sort
- **Conceitos-chave:** Hoare (1960). Pivô pela **mediana de três** (início, meio, fim); tratamento especial para 1, 2 e 3 elementos.
  - Versão 1: o pivô anda pelo vetor; 28 comparações e 19 trocas.
  - Versão 2: o pivô fica escondido na penúltima posição; 30 comparações e 17 trocas.
  - Pior caso (N²−N)/2; média ~1,4(N+1) log₂ N.
- **Trace:** no vetor-padrão, a mediana entre 209, 42 e 145 é 145, que vira o pivô e termina no índice 7.
- **Pegadinha:** índices `unsigned` em `medio-1` / `fim-inicio+1` dão a volta quando o subvetor fica vazio.

### 0101-comparando
- Use a tabela acima. O livro conclui que inserção e Shell v2 são as melhores simples, e que merge e quick sort são O(N log N). Falta falar de estabilidade e de `qsort`: complementar com outra fonte.

### 0102-arvores / 0104-bst-busca-insercao (só conceitual)
- **Conceitos-chave:** a árvore é recursiva (vazia ou raiz + subárvores). Na árvore binária de busca, menores à esquerda e maiores à direita; o nó tem ponteiros para o elemento, para a esquerda e para a direita. Árvore completa com K níveis tem N = 2^K − 1 nós. A busca só é log₂ N se a árvore estiver balanceada, então inserir e remover deveriam preservar o balanceamento (gancho para AVL).

### 0110-hashing / 0111-encadeamento (só conceitual)
- **Conceitos-chave:** a função hash calcula a posição a partir da chave. Problemas: overflow (tabela cheia) e colisão. Solução: **vetor de listas** (encadeamento), busca em dois tempos (hash, depois sequencial na lista curta). Chaves repetidas ficam em ordem de chegada se cada lista funcionar como fila. Limite: o vetor tem tamanho fixo.

---

## Ideias de "juntando-tudo" vindas do livro
- **Módulo 03 ou 04:** menu com validação robusta (`scanf` + descarte da linha).
- **Módulo 04 (0041):** calculadora de números complexos com módulo `.h`/`.c` e tipo opaco.
- **Módulo 09 (0075):** agenda telefônica em arquivo binário com cabeçalho, inserção ordenada e remoção.
- **Módulo 12 (0093):** verificador de parênteses mais palíndromo com fila e pilha.
- **Módulo 13:** ordenar a mesma base de pintores por nome, data e registro com ponteiro para função e contadores de operações.

## Obsoleto / evitar
- Comparações com Pascal (`readln`, `repeat until`, `:=`, `case of`): retirar.
- Máquina de 32 bits: "ponteiro tem 4 bytes", "`int` e `long` têm 4 bytes", "deslocar ponteiros custa 4 bytes".
- Divisão e resto com negativos "dependem do compilador": no C99 a divisão trunca em direção a zero.
- `register`: inútil hoje, e não deixa usar `&`.
- `tmpnam`: inseguro (preferir `tmpfile`/`mkstemp`).
- `atoi`/`atof` sem detecção de erro (preferir `strtol`/`strtod`). O livro cita "idiv" (o nome correto é `div`).
- Identificadores todos em MAIÚSCULAS para variáveis (o costume moderno reserva maiúsculas para macros).
- Guards com `_NOME` (nome reservado).
- Índices `unsigned` em algoritmos que fazem `i-1` (bugs de volta ao máximo).
- Variáveis de bloco "devem ser evitadas" (opinião antiga: hoje se recomenda declarar perto do uso; o C99 permite `for (int i=...)`).
- Devolver ponteiro para struct `static` local (não reentrante).
- Bugs a não copiar:
  - `tail = ++tail % N` (comportamento indefinido);
  - busca binária recursiva sem `return`;
  - `printf("%s", LISTA[J])`;
  - `int AM[][][]`;
  - `while(Opcao<1 && Opcao>7)`;
  - `utroca` sem inicialização no shaker;
  - `CCount` sem `return` no fim;
  - funções definidas dentro de `.h`;
  - `EXIT_SUCESS` (erro de digitação);
  - `DISCOS_MAX` não definido no Hanói.

## Extras que não cabem no sumário
- **Série de Taylor reescrita por Horner** (sem fatorial): um bom exemplo de "pensar antes de programar" e de estabilidade numérica.
- **Determinante recursivo** por operações de colunas.
- **Tabela de permissões dos modos do `fopen`.**
- **`%n` do `scanf`** para validar o formato.
- **Classes de "memória" RAM/FIFO/LIFO/CAM** e implementações estática, semiestática e dinâmica: uma visão unificada de TADs.
- **First/best/worst fit:** ligam-se a alocadores de memória e ao problema de corte.
- **Ordenação externa** por intercalação de arquivos.
- **Contagem de operações com contadores `static`** (instrumentar algoritmos).
- **Leituras recomendadas pelo livro:** Darnell & Margolis, *C: A Software Approach*; Standish, *Data Structures, Algorithms and Software Principles in C*; Weiss, *Data Structures and Algorithm Analysis in C*.
