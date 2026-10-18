# Fichamento — Celes & Rangel, *Apostila de Estruturas de Dados* (PUC-Rio)

- **Obra:** Waldemar Celes e José Lucas Rangel (cap. 9 com R. Cerqueira), *Apostila de Estruturas
  de Dados*, Curso de Engenharia, PUC-Rio, 2002. Segunda disciplina de programação (a primeira era
  em Scheme). Base do livro posterior *Introdução a Estruturas de Dados* (Celes, Cerqueira, Rangel).
- **Estrutura:** Parte I (C básico até matrizes e TAD), Parte II (listas, pilhas, filas, árvores,
  arquivos), Parte III (ordenação, busca, BST, hash).
- **Avaliação geral:** é a fonte mais **"engenharia"** e prática do par. Complementa perfeitamente o
  Feofiloff: onde ele prova e critica, a PUC **organiza em módulos**. Pontos fortes que o LPEDC deve
  herdar: (1) o **padrão TAD** com `.h` (tipo opaco `typedef struct x X;` + protótipos comentados)
  e `.c` (struct completa + implementação), e a demonstração de que **duas implementações diferentes
  servem à mesma interface** (matriz com vetor simples × vetor de ponteiros; pilha/fila com vetor ×
  lista); (2) **desenhos da pilha de execução e da memória** passo a passo (endereços fictícios
  104, 108, 112...); (3) funções de lista que **devolvem a lista atualizada** (`l = insere(l, v)`),
  com alerta repetido para não esquecer a atribuição; (4) generalização com `void*`, ponteiro para
  função, `qsort`/`bsearch` e **callbacks**; (5) uma aplicação completa de hash (contagem de
  palavras). Pontos fracos: texto de 2002 (Turbo C, Windows 2000, int de 4 bytes "na maioria"),
  **vários erros de digitação no código** (listados em cada seção — viram ótimos exercícios de
  "ache o bug"), não tem insertion/selection/merge sort, nem heap, nem AVL com rotações, nem grafos;
  pouca análise de corretude (nada de invariantes).
- **Convenções da apostila:** nó de lista chamado `Lista`/`No` com campos `info` e `prox`; árvore
  com `info`, `esq`, `dir`; siglas *sae*/*sad* (subárvore à esquerda/direita); notação textual de
  árvores `<a <b <> <>> <>>`; lista **sem cabeça**, representada pelo ponteiro para o 1º nó.

---

### logica5-compilacao
- **Conceitos-chave:** computador só executa linguagem de máquina; interpretação (interpretador lê
  e simula o fonte, que é "mais um dado de entrada") × compilação (compilador traduz para um
  programa objeto que roda sem o compilador). Executável compilado para uma plataforma (Windows) não
  roda em outra (Linux).
- **Ciclo:** editar → compilar → ligar → testar (repete). IDE junta tudo.
- **Compilação separada (excelente para 0034):** `gcc -c converte.c`, `gcc -c principal.c`,
  `gcc -o prog converte.o principal.o` — se só um módulo muda, só ele é recompilado. O ligador junta
  objetos e bibliotecas (ex.: código de printf/scanf).
- **Exemplo:** conversor Celsius → Fahrenheit (F = 1,8·C + 32), primeiro num arquivo só, depois
  separado em `converte.c` + `principal.c` com o protótipo repetido.
- Modelo de computador (CPU, memória principal de acesso aleatório e volátil, armazenamento
  secundário persistente e lento, E/S, barramento) — bom para 0001/0004.

### 0002-variaveis / 0003-tipos-e-limites / 0004-constantes
- Variável = espaço de memória com nome e tipo. Tabela de tamanhos: char 1, short 2, long 4,
  float 4 (±10^38), double 8 (±10^308).
- Constantes reais sem sufixo são `double`; `12.45F` é float; atribuir `12.45` a float pode gerar
  aviso.
- **Pegadinha "variável com lixo"** (ótima explicação): `c = a + b` com b não inicializada. "Todos
  os erros em computação têm lógica": o lixo existe; se por acaso for 0, o programa funciona de
  manhã e falha à tarde (ou funciona no desenvolvimento e falha no cliente).
- `int a = 4.3;` guarda 4 (trunca).

### 0005-printf / 0006-scanf
- Especificadores %c %d %u %f %e %g %s; `%%`; largura e precisão (`%4d`, `%7.2f`). printf devolve
  nº de campos (a rigor, de caracteres) impressos.
- **scanf:** precisa de endereços (&); `%f` é float e **`%lf` é double** (no printf ambos são %f —
  pegadinha clássica); scanf devolve nº de campos lidos; literal no formato obriga o separador
  (`"%d:%d"` para hora); espaço no formato pula brancos; `%d`/`%f` pulam brancos sozinhos, **`%c` não**
  (use `" %c"`).

### 0007..0014 operadores
- Divisão na precisão dos operandos (5/2 = 2; 5.0/2.0 = 2.5); % só para inteiros (paridade com
  x % 2); precedência; atribuição é expressão (`y = x = 5`, da direita para a esquerda).
- **`x *= y + 1` equivale a `x = x * (y + 1)`, não a `x*y + 1`** — pegadinha boa.
- `x = n++` × `x = ++n` (n = 5 → x = 5 ou 6; n vira 6 nos dois). `(i+1)++` é ilegal.
- Postura da apostila: evitar formas compactas quando atrapalham a leitura; compilador otimiza igual.
- Cast: `(int) 3.5 % 2` → 1; conversão automática para o tipo "mais representativo" (3/1.5).

### 0012 / 0013 relacionais e lógicos
- C (C89) não tinha booleano: 0 é falso, não zero é verdadeiro; relacionais produzem 0 ou 1.
- Curto-circuito: em `b = (c < 20) && (d > c)`, a segunda parte nem é avaliada.

### 0015 / 0016 if-else e else pendurado ⭐
- **Exemplo da temperatura (reescrever com outra história):** `if (t < 30) if (t > 20) "agradável"
  else "muito quente"`, indentado como se o else fosse do primeiro if. Com t = 5 imprime "muito
  quente"! Regra: o else casa com o **último if sem else**. Solução: chaves explícitas.
- Versão correta com else-if em cascata (< 10 muito fria, < 20 fria, < 30 agradável, senão muito
  quente). Observação: C não tem "elseif"; é if aninhado.
- Blocos: variável declarada num bloco só existe nele; declarar perto do uso.

### 0017-ternario / 0018-switch
- `maximo = a > b ? a : b;`.
- switch com `case` de inteiro/caractere, `break` e `default`; sem break, cai no caso seguinte.
  **Exemplo:** calculadora de 4 operações lendo `"%f %c %f"`.

### 0020..0028 laços
- Fatorial com while, for e do-while (do-while para **validar** entrada: repetir enquanto n < 0).
  Tradução de for em while.
- break: laço de 0 a 9 que para em 5 imprime "0 1 2 3 4 fim"; continue: pula o 5.
- **Pegadinha forte:** `continue` num **while** que pula o incremento → laço infinito quando i = 5.
  No for o incremento é executado mesmo com continue.

### 0028 / 0029 funções e passagem por valor
- Protótipo antes do uso (repetir a linha da definição + `;`; nomes dos parâmetros opcionais mas
  documentam); `void` em parâmetros e retorno; main devolve 0 em sucesso.
- **Exemplo:** fat que zera n dentro da função (while n != 0, n--) e o main continua com n = 5 —
  prova visual da passagem por valor.

### 0030-escopo
- Locais vivem enquanto a função executa; globais existem o programa todo, mas devem ser evitadas
  ("alto grau de interdependência"). **static dentro de função:** fica na área estática, mantém o valor
  entre chamadas, mas só é visível ali; inicializada com 0 se não explicitada.
- **Exemplo:** função `imprime(float a)` que imprime 5 números por linha usando um contador static.

### 0031-pilha-de-chamadas ⭐
- **Melhor material visual do par:** esquema de memória com endereços fictícios crescendo para cima
  (a em 104, b em 108, c em 112) e a pilha mostrada em 6 quadros: pilha vazia → main com n, r →
  chamada copia o parâmetro → local f da função → fim do laço (n = 0 só na cópia) → retorno desempilha.
- Repetir o mesmo formato para a função **troca** com ponteiros (px = 104, py = 108 apontando para
  a e b do main) — mostra *por que* o scanf precisa de &.

### 0032-recursao
- Recursão direta × indireta (A chama B que chama A). Cada chamada tem seu próprio ambiente local.
  "Recursivo costuma ser mais fácil; não recursivo costuma ser mais eficiente."
- Fatorial recursivo a partir da definição (0! = 1; n! = n·(n−1)!).
- **Strings recursivas:** string = vazia ou caractere + substring (&s[1]). Imprimir, imprimir
  **ao contrário** (só trocar a ordem do printf com a chamada!), comprimento, cópia (versão compacta
  copia o caractere e só recorre se não era '\0'). Exercício: imprimir invertido sem recursão.

### 0034-modulos ⭐
- Módulo = .c com parte das funções; cada módulo compilado em separado e depois ligado.
- **Arquivo de cabeçalho:** em vez de repetir protótipos em cada cliente, o módulo `str.c` ganha
  `str.h` com protótipos **comentados** (o comentário documenta o comportamento esperado).
  `#include <...>` para biblioteca padrão; `#include "..."` para os seus (procura primeiro no
  diretório atual).
- **Exemplo:** str.c com comprimento/copia/concatena e prog1.c lendo duas linhas, copiando,
  concatenando e imprimindo o comprimento.
- Lacuna: a apostila **não fala em include guards** — acrescentar no LPEDC.

### 0035-preprocessador ⭐
- `#define PI 3.14159` (constante simbólica recomendada). Macros com parâmetros: `MAX(a,b)`.
- **Pegadinhas clássicas com números prontos:** `#define DIF(a,b) a - b` → `4 * DIF(5,3)` dá **17**
  (não 8); `#define PROD(a,b) (a * b)` → `PROD(3+4, 2)` dá **11** (não 14). Regra: parênteses em
  cada parâmetro e na macro inteira: `((a) * (b))`. Erro de sintaxe em macro aparece na linha de uso,
  não na definição.
- (Faltou: macro que avalia argumento duas vezes, ex.: `MAX(i++, j)` — acrescentar.)

### 0037 / 0038 vetores e funções
- Vetor = espaço **contínuo**; índice 0..n−1; `v[10]` num vetor de 10 é invasão de memória.
- **Exemplo:** média e variância de 10 reais (depois separado em funções `media(n, v)` e
  `variancia(n, v, m)`).
- Passar vetor = passar endereço do 1º elemento (parâmetro `float* v` ou `float v[]`); a função
  pode alterar o original: `incr_vetor` sobre {1, 3, 5} imprime 2 4 6.
- Inicialização `int v[] = {5, 10, 15, 20, 25};` dimensiona automaticamente.

### 0039-matrizes
- `float mat[4][3]` guardada linha a linha de forma contínua; inicialização com chaves aninhadas ou
  sequencial; pode omitir o nº de linhas, nunca o de colunas.
- Parâmetro: `float (*mat)[3]` ou `float mat[][3]` (sintaxe "obscura"); sugestão: `typedef float
  Matrix4[4][4];` para matrizes de tamanho fixo (computação gráfica).

### 0040-caracteres
- char é inteiro pequeno; `printf("%d %c", c, c)` mostra 97 e a. Usar constantes `'a'` em vez de
  códigos (portabilidade). Garantias: dígitos consecutivos; minúsculas consecutivas; maiúsculas
  consecutivas.
- Exercícios: `digito(c)`, `letra(c)`, `maiuscula(c)` (converter só se for minúscula).

### 0041-strings
- Vetor de char terminado em '\0'; reservar uma posição a mais. Montar "Rio" caractere a caractere
  (cidade[4]), com chaves e com aspas. `char s1[] = ""` tem 1 elemento; `"Rio de Janeiro"` ocupa 15.
- Implementações didáticas: imprime, comprimento, copia (não esquecer de **fechar** com '\0'),
  concatena, **duplica** (malloc de n+1 + strcpy; quem chama libera).
- **Bug na apostila (exercício "ache o erro"):** `concatena` procura o fim usando `s[i]` em vez de
  `dest[i]` — não compila.

### 0042-lendo-strings
- `scanf("%s")` lê só até o primeiro branco ("Rio de Janeiro" → "Rio"). A apostila usa
  `scanf(" %80[^\n]", s)` (conjunto de caracteres negado, com limite de 80 para um vetor de 81).
- **Pegadinha:** sem o limite (`%[^\n]`) há invasão de memória se a linha for longa.
- `fgets(linha, 121, fp)` lê no máximo 120 + '\0' (aparece no cap. de arquivos). No LPEDC, fgets é a
  forma principal; mostrar o `%80[^\n]` como alternativa.
- Lacuna: não trata a sobra do '\n' no buffer nem o '\n' que o fgets guarda.

### 0044..0051 ponteiros e passagem por referência
- `&` = "endereço de"; `*` = "conteúdo de". Desenho com p = 104 apontando para a; `*p = 6` muda a.
- **ERRO típico (bom exemplo):** `int *p; *p = 3;` com p não inicializado — às vezes "funciona",
  escreve num lugar desconhecido; programas que "voam".
- Troca errada (por valor) × certa (por endereço), com o passo a passo da memória.

### 0047-ponteiros-e-vetores
- Nome do vetor é constante com o endereço do 1º elemento; `v+i` ≡ `&v[i]`; `v[i]` ≡ `*(v+i)`
  ("a forma indexada é mais clara"). p+1 avança sizeof(tipo) bytes.
- Diferença de ponteiros do mesmo vetor dá o índice: `p - v` (usado com bsearch).

### 0048-ponteiros-e-strings ⭐
- **Diferença sutil e importante:** `char s1[] = "Rio de Janeiro";` é um vetor local de 15 bytes,
  modificável (`s1[0] = 'X'` vale); `char* s2 = "Rio de Janeiro";` é um ponteiro (4/8 bytes) para uma
  constante na **área de constantes** — `s2[0] = 'X'` é inválido. `sizeof(s1)` × `sizeof(s2)` mostra
  a diferença.
- Vetor de strings: `char alunos[50][81]` (desperdício) × `char* alunos[MAX]` com cada nome alocado
  por `duplica` (lelinha + lenomes + imprimenomes + liberanomes).

### 0049-ponteiro-para-ponteiro
- Aparece como alternativa para listas: `insere(Lista** l, ...)` alterando `*l` em vez de devolver
  a lista. E em `char** argv` e `Palavra**` (vetor de ponteiros ordenado por qsort, em que a função de
  comparação recebe ponteiro para ponteiro).

### 0050-ponteiro-para-funcao ⭐ / 0051-void-generico ⭐
- **Construção passo a passo do bubble sort genérico** (ótima sequência didática):
  1. bolha de int com `>`; 2. extrair a comparação para `compara(a, b)` (devolve 1 se há inversão) —
     ordem decrescente = só trocar a função; 3. versões de compara para strings (strcmp) e para
     Aluno* (por nome); 4. tornar tudo `void*`: a ordenação recebe também `tam` (bytes por elemento);
     5. `acessa(v, i, tam)` converte para `char*` e soma i·tam (aritmética byte a byte);
     6. `troca(a, b, tam)` troca byte a byte (não dá para declarar temp do tipo desconhecido);
     7. a comparação vem por **ponteiro para função** `int (*cmp)(void*, void*)`.
- **Bug na apostila:** em `bolha_gen` faltam chaves no `if (cmp(p1,p2))`, então `fez_troca = 1` executa
  sempre e o "para cedo" nunca funciona (o resultado continua certo, só mais lento). E a chamada usa
  `buble_gen` (grafia errada). Exercício "ache o erro" perfeito.
- void* não pode ser desreferenciado; a responsabilidade de converter certo é do programador (o
  compilador não confere). Nota: C++ exige cast explícito de void*; C não.
- **Callbacks (17.5):** separar "percorrer a estrutura" da "ação por elemento": `percorre(tab, cb)`;
  imprimir com `cb = imprime_elemento`; contar com variável global (ruim) e depois com
  `percorre(tab, cb, void* dado)` passando `&total` (bom). Padrão aplicável a lista, árvore, hash.

### 0053-pilha-e-heap ⭐
- **Três formas de reservar memória:** globais/estáticas (vida inteira do programa), locais (na
  pilha, enquanto a função roda; a chamadora não pode usar o espaço local da chamada) e dinâmicas
  (até free; podem ser criadas numa função e usadas em outra).
- **Esquema didático:** código do programa | globais e estáticas | memória dinâmica → | livre | ←
  pilha. Pilha que cresce demais "estoura" e o programa aborta; malloc sem espaço devolve NULL.

### 0054-malloc-free / 0055-calloc-realloc
- `v = malloc(10*4)` → depois `10*sizeof(int)` (independência de máquina); malloc devolve `void*`.
  Checar NULL e sair com mensagem "Memória insuficiente".
- free só em endereço alocado dinamicamente; não acessar depois de liberar.
- **Exemplo:** média/variância de n reais com n lido do teclado — as funções media/variancia não
  mudam (não importa se o vetor é estático ou dinâmico).
- `realloc(v, m*sizeof(int))` preserva o conteúdo. Pegadinha a acrescentar: `v = realloc(v, ...)`
  perde o bloco original se realloc devolver NULL (usar ponteiro temporário). calloc não é tratado.
- Opinião da apostila: preferir estáticos quando possível (uma indireção a menos).

### 0056-matriz-dinamica ⭐
- C só aloca dinamicamente vetores 1D; duas estratégias:
  - **vetor simples** de m·n elementos com `v[i*n + j]` (n = nº de colunas); figura: para i = 1,
    j = 2, n = 4 → k = 6. Uma alocação, mas notação desconfortável.
  - **vetor de ponteiros:** aloca m ponteiros e depois cada linha; acesso natural `mat[i][j]`;
    liberar cada linha e depois o vetor de ponteiros.
- **Bugs na apostila:** `m[i] = malloc(...)` em vez de `mat[i]`; `Matriz mat = (Matriz*) malloc` sem `*`.
- **Matriz simétrica (extra, ver final):** guardar só o triângulo inferior: s = n(n+1)/2 elementos;
  acesso a (i, j) com i ≥ j em `i*(i+1)/2 + j`, e se i < j troca os papéis. Com vetor de ponteiros,
  a linha i tem i+1 elementos.

### 0057-erros-de-memoria
- Itens espalhados: lixo em variável, ponteiro não inicializado, invasão (v[10], scanf sem limite),
  acessar após free, esquecer de atribuir a lista atualizada (ficar apontando para nó liberado),
  liberar a subárvore antes de perder o acesso (pós-ordem), guardar o próximo antes do free.
  Não menciona Valgrind/ASan (acrescentar).

### 0059..0067 structs, typedef, vetor de structs, ponteiro para struct
- `struct ponto { float x, y; }`; operador `.`; `&p.x` funciona porque `.` tem precedência sobre &.
- `(*pp).x` precisa dos parênteses; `pp->x` é o atalho; `&pp->x` é o endereço do campo.
- **Passagem de struct:** por valor copia tudo (lento e não altera o original); preferir ponteiro
  mesmo quando só lê; para ler (captura) é obrigatório ponteiro. **Bug:** `captura` usa `&p->x`
  com parâmetro chamado `pp`.
- typedef: `typedef float Real;`, `typedef int* PInt;`, `typedef float Vetor[4];`,
  `typedef struct ponto Ponto, *PPonto;` — mesma regra de leitura (sem typedef seria declaração de
  variável). Estilo: tipos com inicial maiúscula.
- **Vetor de structs — área de polígono:** soma das "áreas" dos trapézios (x[i+1]−x[i])(y[i+1]+y[i])/2
  com índice circular `j = (i+1) % n`; valor absoluto no fim. Exemplo: triângulo (1,1), (5,1), (4,3)
  → área 4. Exercício: ler n, alocar o vetor de pontos dinamicamente.
- **Vetor de ponteiros para structs — tabela de alunos:** Aluno ocupa ≥ 227 bytes (81+4+121+21, mais
  alinhamento); `Aluno tab[100]` desperdiça; `Aluno* tab[100]` com NULL = posição livre;
  funções inicializa / preenche(i) (aloca se NULL) / remove(i) (free + NULL) / imprime(i) /
  imprime_tudo. Exercício: reescrever **sem variável global** criando um tipo Tabela.

### 0063-enum / 0064-union
- union: campos compartilham a mesma memória; tamanho ≥ maior campo; só um campo válido por vez.
- enum: constantes nomeadas (0, 1, ... por padrão); exemplo `enum bool { FALSE, TRUE }` — vantagem
  sobre `#define` + `typedef int Bool` (documenta os valores legais). Usado também para RET, TRI, CIR.

### 0067-arquivos-texto ⭐
- Memória secundária: lenta mas **persistente**; SO usa buffers. Arquivo texto (legível, editável)
  × binário (eficiente). Ponteiro de posição avança a cada leitura.
- `fopen(nome, modo)` → FILE* ou NULL (sempre testar); modos r, w (apaga se existe), a (acrescenta),
  t, b. `fclose` devolve 0 ou EOF.
- Leitura: fscanf (devolve nº lido), fgetc (devolve int; EOF no fim), fgets(s, n, fp) (para no '\n'
  ou em n−1 caracteres; NULL no fim). Escrita: fprintf, fputc. `sscanf`/`sprintf` em strings.
- **Três estratégias de formato (muito boas para exemplos):**
  1. **caractere a caractere:** contar linhas contando '\n'; copiar arquivo convertendo para
     maiúsculas com toupper (nomes lidos do teclado; fechar o primeiro se o segundo falhar).
  2. **linha a linha:** "grep" simplificado com fgets + strstr devolvendo o nº da linha; arquivo de
     figuras uma por linha (`r 2.0 1.2`, `c 5.8`, `t 4 1.02`), com comentários `#` e linhas em branco,
     lido com `sscanf(linha, " %c %f %f", ...)` e conferindo quantos campos vieram (3 para r/t, 2
     para c); pontos 2D/3D em que a 3ª coordenada pode faltar (só dá para ler linha a linha).
  3. **palavras-chave:** RETANGULO / TRIANGULO / CIRCULO / POLIGONO n seguido de n pares, lidos com
     `fscanf(fp, "%120s", palavra)` + strcmp.

### 0068-arquivos-binarios
- `fwrite(p, tam, nelem, fp)` / `fread(...)` copiam bytes da memória para o disco e vice-versa
  (`size_t` na prática). Exemplo: salvar e carregar vetor de `Ponto {x, y, z}` com "wb"/"rb".
- Lacunas: fseek/ftell não aparecem; não se verifica o retorno de fread; arquivo binário de struct
  não é portável entre máquinas (alinhamento, endianness).

### 0069-argumentos
- `int main(int argc, char** argv)`; `mensagem estruturas de dados` → argc = 4,
  argv[0] = "mensagem". Uso real no programa de contagem de palavras (nome do arquivo em argv[1],
  checando argc != 2).

### 0071-eficiencia / 0072-big-o
- Notação O introduzida na busca: pior caso, melhor caso (não serve para análise — "situação muito
  particular") e **caso médio** (n/2 comparações na busca linear ainda é O(n), pois O(kn) = O(n)).
- Bubble: (n−1) + (n−2) + ... + 1 → O(n²). Quicksort: O(n log n) melhor/médio, recai no bolha no
  pior. Busca binária: tabela "repetição × tamanho" (n, n/2, n/4, ..., 1) → log n repetições.
- Árvore binária de altura h tem no mínimo h+1 e no máximo 2^(h+1) − 1 nós → altura mínima
  O(log n), máxima O(n) (árvore degenerada). Hash: O(1) "se bem projetada".

### 0074-tad ⭐⭐ (o padrão a copiar)
- **Definição:** módulo que define um tipo e suas operações; "abstrato" = "esquecida a forma de
  implementação". O cliente só conhece a funcionalidade. Facilita manutenção e reuso.
- **Receita da apostila (usar como template do LPEDC):**
  - `x.h`: comentário com o nome do TAD; `typedef struct x X;` (**tipo opaco** — a composição da
    struct não é exportada, então o cliente não acessa campos); protótipos, cada um com comentário
    "Função nome — o que faz".
  - `x.c`: inclui as bibliotecas que usa **e o próprio `x.h`** (por dois motivos: precisa das
    definições e o compilador confere que as implementações batem com os protótipos); define a
    `struct x` completa; implementa.
  - Operações típicas: `cria` (aloca, checa NULL, inicializa), `libera`, `acessa`, `atribui`, mais
    as específicas.
- **TAD Ponto:** cria(x, y), libera, acessa(p, &x, &y) (devolve por ponteiros), atribui, distancia
  (sqrt(dx² + dy²)). Exercícios: usar o TAD; soma/subtração de pontos; coordenadas polares; Ponto 3D.
- **TAD Matriz:** cria(m, n), libera, acessa(i, j) e atribui(i, j, v) **com verificação de limites**
  (mensagem + exit), linhas, colunas. Duas implementações (`matriz1.c` vetor simples,
  `matriz2.c` vetor de ponteiros) com **a mesma** `matriz.h` — o cliente não muda.
  Exercícios: testar com as duas; função "é simétrica?" e "transposta" usando só a interface;
  TAD MatSim.
- **Calculadora pós-fixa** como TAD (`calc.h`) construído **em cima** do TAD pilha: mostra TAD
  usando TAD.

### 0075-vetor-dinamico
- Não há um TAD "lista sequencial" pronto; o material vem da motivação do cap. 10 (vetor tem
  tamanho fixo: se sobra, desperdiça; se falta, não há forma barata de crescer), do `realloc` (8.1)
  e da tabela de ponteiros de alunos. Juntar com o Cap. 3 do Feofiloff.

### 0076-lista-encadeada ⭐
- **Motivação:** vetor dá acesso aleatório mas é rígido; lista cresce e diminui, gasta memória
  proporcional ao nº de elementos, mas **sem acesso direto** — só seguindo o encadeamento.
- Nó auto-referenciado `struct lista { int info; struct lista* prox; }` + `typedef struct lista
  Lista;`; a lista é um `Lista*` para o 1º nó; vazia = NULL.
- Operações (lista sem cabeça, todas devolvem a lista atualizada quando ela pode mudar):
  `inicializa` (devolve NULL); `insere` no início (aloca, novo->prox = l, devolve novo); `imprime`
  com `for (p = l; p != NULL; p = p->prox)`; `vazia` (`return l == NULL;`); `busca` (devolve o nó ou
  NULL); `retira`; `libera`.
- **Exemplo-roteiro:** insere 23, 45, 56, 78 → imprime 78 56 45 23 (ordem inversa da inserção);
  retira 78 → 56 45 23; retira 45 → 56 23; libera.
- **Pegadinhas destacadas pela apostila:**
  - **esquecer `l = insere(l, x)`** — a variável fica apontando para o nó antigo; se retira o 1º, fica
    apontando para nó **já liberado**;
  - no libera, **guardar o próximo antes do free** (acessar p->prox depois de free(p) é usar memória
    que não é mais sua).
- Alternativa citada: funções recebendo `Lista** l`.
- **Recursivas (10.2):** lista = vazia ou elemento + sublista. imprime_rec (inverter a ordem do
  printf e da chamada imprime ao contrário), retira_rec (`l->prox = retira_rec(l->prox, v)`),
  libera_rec (libera a sublista e depois o nó).
- Exercícios: `igual(l1, l2)`; `copia(l)`.

### 0077-lista-busca-remocao
- **retira(l, v):** percorrer com `ant` (inicialmente NULL) e `p`; se não achou, devolve l; se
  `ant == NULL` o nó é o primeiro → l = p->prox; senão ant->prox = p->prox; free(p); devolve l.
  Retirar o último cai no caso "do meio" (mas numa fila com ponteiro de fim teria de atualizar o fim).
- Comparação com Feofiloff: PUC trata o 1º com `if`; Feofiloff evita com célula-cabeça ou `**`.

### 0078-lista-ordenada
- Inserir no início é O(1) e deve ser preferido quando a ordem não importa; manter ordenada exige
  percorrer.
- **insere_ordenado:** função auxiliar `cria(v)`; anda com ant/p enquanto `p != NULL && p->info < v`;
  se ant == NULL insere no início, senão entre ant e p. Funciona também no fim.
- **Exemplo:** inserir 40, 10, 30, 20 → lista 10 20 30 40 (rastrear ant e p em cada inserção).

### 0079-lista-dupla
- Motivação: com encadeamento simples não se percorre de trás para frente e, para retirar um nó
  conhecido, ainda é preciso achar o anterior.
- Nó com `ant` e `prox`. Inserção no início ajusta `l->ant = novo` se a lista não era vazia.
- **Retirar conhecendo só o ponteiro p:** conceitualmente `p->ant->prox = p->prox` e
  `p->prox->ant = p->ant`, mas tratar as bordas: se p é o 1º, a lista passa a ser p->prox (não existe
  p->ant->prox); se p é o último, não existe p->prox->ant.
- **Bug na apostila:** `typedef struct Lista2 Lista2;` com L maiúsculo (o tag é `lista2`).
- Lista circular dupla: percorre nos dois sentidos (imprime_circular_rev usando `ant`).
  Exercício: inserir e retirar em lista circular dupla.

### 0080-lista-circular
- Último aponta para o primeiro; não há "primeiro" de verdade — guarda-se um ponteiro para um nó
  qualquer. Percorrer com **do-while** a partir de l até voltar a l, tratando lista vazia (NULL) antes.
- Aplicação citada: arestas que delimitam uma face (computação gráfica).
- **Bug na apostila:** `if (p) { {` com chave sobrando em imprime_circular.
- Exercício: inserir e retirar em lista circular.

### 0082-pilha ⭐
- **Analogia:** pilha de pratos — põe e tira só do topo. LIFO. Operações push/pop. "Talvez a estrutura
  mais usada; implementada até em hardware"; a própria pilha de execução do C é exemplo.
- Figura-roteiro: push(a), push(b), push(c), pop() → c, push(d), pop() → d.
- **Interface `pilha.h`:** `typedef struct pilha Pilha;` cria, push, pop, vazia, libera.
- **Vetor:** `struct pilha { int n; float vet[MAX]; }`; topo em vet[n-1]; push checa `n == MAX`
  ("capacidade estourou" + exit); pop checa vazia; libera = free(p).
- `imprime` do topo para a base "só para testar" (não faz parte da definição pura de pilha).

### 0083-pilha-encadeada
- Quando não se conhece o máximo. `struct no { float info; struct no* prox; }` e
  `struct pilha { No* prim; }`. **Topo = início da lista**; funções auxiliares `ins_ini` e `ret_ini`
  (ambas devolvem o novo 1º nó). push = `p->prim = ins_ini(p->prim, v)`; pop lê `p->prim->info` e
  depois `ret_ini`. libera percorre liberando e por fim libera a struct.
- Mesma interface das duas implementações: o cliente não percebe a troca.

### 0084-pilha-aplicacoes ⭐
- **Calculadora pós-fixa estilo HP:** operando → empilha; operador binário → desempilha v2 e depois
  v1 (**nessa ordem**: v1 − v2, v1 / v2), calcula, empilha o resultado. Se faltar operando, vale 0.
  Imprime o topo com um formato guardado na própria calculadora (`"%.2f\n"`).
- Rastreio: `(1-2)*(4+5)` = `1 2 - 4 5 + *` → pilha: 1 | 1 2 | −1 | −1 4 | −1 4 5 | −1 9 | −9.
  Sessão: `3 5 8 * +` → 3.00 5.00 8.00 40.00 43.00; `7 /` → 7.00 6.14; `q` sai.
- Leitura do cliente: `scanf(" %c")`; se não for operador, **`ungetc`** devolve o caractere ao buffer e
  tenta `scanf("%f")` — truque de E/S que vale mostrar.
- **Pegadinha:** inverter v1 e v2 em − e /.
- Exercício: operadores `~` (menos unário), `#` (raiz), `^` (potência).

### 0085-fila ⭐
- **Analogia:** fila do dia a dia; em computação, **fila de impressão** compartilhada. FIFO; insere
  no fim, retira do início.
- **Interface `fila.h`:** cria, insere, retira, vazia, libera.
- **Vetor circular:** a fila "anda" no vetor; incremento circular `incr(i)` = `(i+1) % N`.
  Convenções: `ini` = próximo a sair; `fim` = posição **vazia** onde entra o próximo. Vazia:
  `ini == fim`; cheia: `incr(fim) == ini` → **capacidade N−1** (a posição de fim fica sempre livre para
  não confundir cheia com vazia). Alternativa: guardar o contador n.
- Exemplo: inserir 1.4, 2.2, 3.5, 4.0 e retirar dois; e situação com 20.0, 20.8 no fim do vetor e
  21.2, 24.3 no início (posições 98, 99, 0, 1 com N = 100).
- `imprime` com `for (i = ini; i != fim; i = incr(i))`.
- (Observação: a alternativa "contador n" na apostila diz cheia quando n == N−1; com contador dá
  para usar todas as N posições — corrigir no LPEDC.)

### 0086-fila-encadeada
- Dois ponteiros `ini` e `fim`; retira do início (fácil) e insere no fim (fácil porque guardamos
  `fim`); retirar do fim seria difícil (não acha o anterior).
- `ins_fim(fim, v)` devolve o novo fim e liga `fim->prox` se não era vazia; `ret_ini` igual ao da
  pilha.
- **Pegadinhas que a apostila destaca:** ao inserir na fila vazia, atualizar **também ini**; ao
  retirar o último, atualizar **também fim** para NULL.
- Exemplo de uso: insere 20.0, 20.8, 21.2, 24.3; retira dois (20.0 e 20.8); imprime 21.2 24.3.

### 0087-deque ⭐
- Fila dupla: insere e retira nas duas pontas ("duas filas em ordem inversa na mesma estrutura").
  Interface `fila2.h`: cria, insere_ini, insere_fim, retira_ini, retira_fim, vazia, libera.
- Com vetor: exercício; **dica**: o decremento circular **não** pode ser `(i-1) % N` (em C o resto de
  negativo é negativo) — decrementar e, se ficou negativo, pôr N−1 (ou usar `(i - 1 + N) % N`).
- Com lista: precisa de **lista dupla** por causa do retira_fim. Auxiliares ins2_ini, ins2_fim,
  ret2_ini, ret2_fim (acertando ant/prox e o NULL nas pontas); as funções da fila2 atualizam ini e
  fim quando a fila estava/ficou vazia.

### 0097-arvores ⭐
- **Motivação:** estruturas lineares não representam hierarquia; exemplo da árvore de diretórios.
  Definição recursiva: raiz com zero ou mais subárvores; filhos, pai, nós internos, folhas (nós
  externos). Desenha-se a raiz em cima; ponteiros sempre do pai para os filhos.
- Altura = caminho mais longo da raiz a uma folha; um nó → 0; vazia → −1. Só existe um caminho da
  raiz a cada nó.
- Exercício com resposta: árvore binária de altura h tem entre h+1 e 2^(h+1) − 1 nós.

### 0098-arvore-binaria ⭐
- **Exemplo motivador:** árvore de expressão `(3+6)*(4-1)+5` (folhas = operandos, internos = operadores).
- Definição recursiva: vazia, ou raiz + sae + sad. **Notação textual** `<raiz sae sad>` com `<>` para
  vazia: a árvore a(b(-, d), c(e, f)) é `<a<b<><d<><>>><c<e<><>><f<><>>>>`. As árvores `<a<b<><>><>>`
  e `<a<><b<><>>>` são **diferentes** (esquerda ≠ direita).
- **TAD `arvbin.h`:** inicializa (NULL), cria(c, sae, sad), vazia, imprime, libera, busca.
  `inicializa` e `cria` correspondem aos dois casos da definição recursiva.
- Construir a árvore exemplo de baixo para cima (a1..a5) ou numa única expressão aninhada.
- **imprime em pré-ordem** → `a b d c e f`; exercício: imprimir com a notação `<...>`; versões
  simétrica e pós-ordem.
- **libera em pós-ordem** (subárvores antes da raiz) e devolve NULL; o cliente faz
  `a->dir->esq = libera(a->dir->esq)` — mesma lição de atribuir o retorno.
- "Enxertar" com `a->esq->esq = cria('x', cria('y',...), cria('z',...))` e "podar" com libera.
  Exercício: desenhar o resultado.
- **busca com curto-circuito:** `return a->info == c || busca(a->esq, c) || busca(a->dir, c);` para
  assim que acha (explicar a equivalência com if/else-if).
- Ordens: pré (raiz, sae, sad), simétrica (sae, raiz, sad), pós (sae, sad, raiz). Exercício: altura.
- **Árvores genéricas (13.2):** cada nó com qualquer nº de filhos; definição sem árvore vazia (folha =
  nó com zero subárvores). Representações: campos fixos f1, f2, f3 (desperdício e limite) ×
  **"primeiro filho / próximo irmão"** (`prim`, `prox`) — que na prática é uma árvore binária.
  TAD arvgen: cria (folha), insere(a, sa) (no início da lista de filhos), imprime (pré-ordem; não
  existe ordem simétrica com nº variável de filhos), busca, libera (pós-ordem guardando o próximo
  irmão). Exemplo: `<a <b <c <d>> <e>> <f> <g <h> <i <j>>>>` montado com 9 inserts (atenção: inserir
  no início inverte a ordem, então insere-se o último filho primeiro). Exercícios: copia, igual.
  (Para 0097 como exemplo de árvore n-ária; percurso por nível não aparece.)
- **Bug:** `struct arv3 { char val; struct no *f1, *f2, *f3; }` usa tag errado.

### 0089-busca-sequencial
- busca(n, vet, elem) devolve índice ou −1. Pior caso n comparações; caso médio n/2; ambos O(n).
- **busca_ord** para vetor crescente: para quando acha um elemento maior que o procurado (ainda O(n)).
- Conclusão: em lista encadeada, mesmo ordenada, só dá para fazer busca linear.

### 0090-busca-binaria
- Versão clássica fechada: ini = 0, fim = n−1, `while (ini <= fim)`: meio; menor → fim = meio−1;
  maior → ini = meio+1; igual → devolve meio. Não achou → −1. Duas comparações por ciclo; O(log n).
- **Recursiva com aritmética de ponteiros:** busca na 1ª metade com o mesmo ponteiro e n = meio; na
  2ª com `&vet[meio+1]` e n−1−meio; para devolver o índice, somar `meio+1` ao resultado da 2ª metade
  (se não for −1). Bom exercício de ponteiros.
- **bsearch:** `bsearch(&chave, v, n, tam, cmp)` devolve ponteiro para o elemento ou NULL; índice =
  `p - v`. A chave pode ter **tipo diferente** do elemento (ex.: buscar por nome `char*` num vetor de
  `Aluno*`: cmp recebe `char*` e `Aluno**`). O vetor precisa estar ordenado pelo mesmo critério da cmp.
- **Bugs:** `comp_alunos (const void* p2, const void* p2)` (dois p2) e falta `{`.
- Comparação com o Feofiloff: aqui a versão "acha ou −1" com fechado [ini, fim]; lá a versão
  "onde deveria estar" com invariante v[e] < x ≤ v[d]. Mostrar as duas.

### 0091-bubble-sort ⭐ (só a PUC cobre)
- **Imagem:** elementos maiores "mais leves" sobem como bolhas. Comparar vizinhos e trocar quando há
  inversão; cada passada leva o maior restante ao fim.
- **Rastreio completo** com 25 48 37 12 57 86 33 92 (7 passadas; após a 4ª o vetor já está ordenado,
  mas a versão básica continua): fim da 1ª passada 25 37 12 48 57 33 86 92; 2ª 25 12 37 48 33 57 86 92;
  3ª 12 25 37 33 48 57 86 92; 4ª 12 25 33 37 48 57 86 92.
- Versão 2 com flag `troca` que encerra quando uma passada não troca nada.
- **Versão recursiva:** uma passada posiciona o maior; recorre em n−1 se houve troca (prepara a ideia
  do quicksort: resolver por partes).
- Custo: (n−1) + ... + 1 → O(n²). Estabilidade não é discutida (é estável com `>`).

### 0095-quick-sort
- Ideia: posicionar um pivô x (aqui x = v[0]) na posição definitiva i, com menores à esquerda e
  maiores à direita, e ordenar recursivamente os dois lados. Melhor caso (pivô mediano) n log n; pior
  caso recai no bolha; médio n log n.
- **Partição da apostila (estilo Hoare com pivô no início):** a sobe enquanto `a < n && v[a] <= x`;
  b desce enquanto `v[b] > x`; se a < b troca e avança ambos; repete enquanto a ≤ b; por fim troca
  v[0] com v[b]; recorre em `rapida(b, v)` e `rapida(n-a, &v[a])` (subvetor via ponteiro!).
- **Rastreio pronto** com 25 48 37 12 57 86 33 92: a = 1 (48), b = 3 (12) → troca → 25 12 37 48 ...;
  cruzam (b = 1, a = 2) → troca pivô com v[b] → 12 25 37 48 57 86 33 92; segue com (2-7) 37 48 57 86 33 92
  → troca 48 e 33 → 33 37 57 86 48 92 ...
- **Por que o guarda `a < n` só de um lado:** se o pivô é o maior, a passaria do fim; b nunca fica
  negativo porque v[0] = x para a descida. Ótima pegadinha para discutir.
- Uso prático: até para listas, copia-se ponteiros dos nós para um vetor, ordena e reencadeia.

### 0096-comparando (qsort)
- `qsort(v, n, tam, cmp)` com `int cmp(const void*, const void*)` devolvendo **negativo, 0, positivo**
  (a apostila diz −1, 0, 1). `const` = a função não altera os elementos.
- Exemplos: vetor de float; vetor de Aluno (cmp converte para `Aluno*` e devolve strcmp dos nomes);
  vetor de `Aluno*` (cmp converte para `Aluno**` — uma indireção a mais).
- **Pegadinha de contrato:** a `compara` da bolha devolvia 1/0 ("há inversão?"); a do qsort devolve
  <0/0/>0. Misturar os contratos ordena errado.
- **Bug:** no exemplo de `Aluno*` usa `*p1`/`*p2` em vez de `*pa1`/`*pa2`; falta `{`.
- Pegadinha a acrescentar: comparar inteiros com `return *a - *b;` pode dar overflow.

### 0099-bst-busca-insercao
- Motivação: busca binária é ótima em vetor ordenado, mas inserir/remover exige deslocar; lista
  permite inserir mas não busca rápido; BST junta as duas coisas — **se balanceada** (altura O(log n));
  degenerada vira O(n).
- Propriedade: raiz > tudo na sae e < tudo na sad; ordem simétrica dá crescente. Variante com
  repetidos: sad com ≥, simétrica dá não decrescente. Com dados complexos, usar função de comparação.
- Exemplo de árvore: 6 (2 (1, 4 (3, -)), 8).
- Funções: init (NULL); imprime em ordem simétrica; **busca recursiva**; **insere recursiva** que
  devolve a (nova) raiz: se vazia cria o nó; se v < info, `a->esq = insere(a->esq, v)`; senão na direita.
- **Pegadinha no texto:** o comentário do else diz `v < a->info` mas o caso é v ≥ info → repetidos
  vão para a direita.
- Exercício: inserir 50, 30, 70, 20, 40 e imprimir em ordem simétrica.

### 0100-bst-remocao ⭐
- **Três casos:** folha (libera e o pai passa a apontar NULL); um filho (o pai "pula" o nó; o neto vira
  filho); dois filhos: achar o **antecessor** (mais à direita da sae), **trocar as informações**, e
  remover recursivamente o valor da sae (onde agora ele está num nó com no máximo um filho). Poderia
  usar o sucessor (mais à esquerda da sad).
- Exemplo: na árvore 6 (2 (1, 4 (3)), 8), retirar 4 (um filho: 3 sobe); retirar 6 (troca com 4,
  retira 6 da sae).
- Implementação recursiva devolvendo a nova raiz da subárvore em todos os casos.
- **Achado:** o truque "troca info e chama retira de novo na sae" simplifica muito (compare com a
  remoção do Feofiloff, que move o nó).

### 0101-avl (balanceamento)
- Inserções/remoções desbalanceiam; a remoção acima favorece sempre a sae (sugestão: alternar o lado).
- **Algoritmo de balanceamento por contagem de nós (não é AVL):** se a sad tem n ≥ m + 2 nós a mais que
  a sae (m), desce a raiz para a sae (vira seu maior) e sobe o menor da sad para a raiz; repete até a
  diferença ≤ 1 e aplica recursivamente às subárvores. Exercício: implementar. Útil como ponte antes
  das rotações AVL.

### 0105-hashing ⭐
- **Motivação com números (ótima):** matrícula PUC de 7 dígitos efetivos + verificador
  (9711234-4). Indexar direto `vet[mat]` exige 10.000.000 de posições × ≥127 bytes ≈ 1,27 GB para ~50
  alunos (6.350 bytes). Vetor de ponteiros reduz para ~40 MB — ainda proibitivo.
- **Ideia central:** usar a parte da chave que mais varia: ano/período de ingresso (primeiros dígitos)
  se repetem na turma; os **últimos** dígitos sequenciais variam mais. Tabela de 100 → índice
  `mat % 100`. Preço: **colisões**, que não dá para eliminar, só minimizar e tratar.
- **Função de dispersão:** `hash(mat) = mat % N`. Propriedades: rápida de calcular e **espalhar bem**.
  Exemplo de hash ruim: usar os dois primeiros dígitos (todos caem em 3–4 posições).
- **Taxa de ocupação:** não passar de 75%; ~50% é bom; < 25% desperdiça memória.
- Tabela como `typedef Aluno* Hash[N];` (vetor de ponteiros, NULL = livre).

### 0107-enderecamento-aberto
- **Próxima posição livre (sondagem linear):** busca: a partir de h(x), avança circularmente
  `(h+1) % N` até achar a matrícula ou um NULL. Insere/modifica: mesmo laço; se parou em NULL, aloca;
  depois copia os dados (nome, email, turma). Sempre há posição livre porque a ocupação é ≤ 75%.
- Problema: concentra as ocupadas (agrupamento).
- **Dispersão dupla:** passo h'(x) = N − 2 − x % (N − 2); cuidados: h' nunca pode ser 0 e não deve ser
  divisor de N (senão só visita um subconjunto) — por isso N primo é preferível (a apostila usa
  N = 100, que não é primo: comentar). Exercício: escrever o insere com dispersão dupla.
- **Lacuna importante (acrescentar no LPEDC):** a apostila não trata **remoção** em endereçamento
  aberto — apagar pondo NULL quebra a cadeia de busca dos que vieram depois; é preciso marca de
  "removido" (lápide).

### 0106-encadeamento
- Cada posição da tabela é uma lista; o Aluno ganha um campo `prox`. Busca percorre a lista de
  `tab[hash(mat)]`; insere procura e, se não achar, encadeia no fim (guardando o anterior `p`).
  Vantagem: a dimensão da tabela não limita o nº de elementos (mas tabela muito justa degrada).

### 0108-juntando-tudo (contagem de palavras) ⭐
- **Projeto completo:** imprimir as palavras de um texto em ordem **decrescente de ocorrências**
  (empate em ordem alfabética). Palavra = sequência de letras (isalpha), sem acentos.
- Peças: `le_palavra(fp, s)` (pula não letras, junta letras até NPAL−1, fecha com '\0', devolve
  0 no EOF); `Palavra {char pal[64]; int n; Palavra* prox;}`; `Hash = Palavra*[127]`; `inicializa`;
  `hash(s)` = soma dos códigos % NTAB; `acessa(tab, s)` busca e, se não acha, cria com n = 0 e insere
  no início da lista; laço principal `while (le_palavra(fp, s)) acessa(tab, s)->n++;`;
  `conta_elems`, `cria_vetor` (vetor de `Palavra*`), `qsort` com compara (n decrescente, depois
  strcmp), `imprime`; main com argv[1].
- **Projeto "dividir para conquistar":** módulos independentes; cliente conhece só a funcionalidade.
- **Pegadinhas para discutir:** hash por soma faz **anagramas colidirem** ("amor", "roma", "mora");
  `total += s[i]` com `char` com sinal pode ficar negativo em textos com acentos (UTF-8) → índice
  negativo! (usar `unsigned char`/unsigned); o programa não libera a tabela nem fecha o arquivo;
  palavras com maiúsculas contam separado ("Casa" × "casa").
- Extensão com callbacks: `percorre(tab, cb, dado)` substitui conta_elems e cria_vetor.

---

## Obsoleto / evitar
- **Turbo C / DOS, int de 2 bytes, "processadores de 32 bits", ponteiro de 4 bytes, Windows 2000**:
  hoje int tem 4 bytes e ponteiros 8 (64 bits); `long` varia (8 no Linux, 4 no Windows).
- **Cast no retorno de malloc** `(int*) malloc(...)`: desnecessário em C (só C++ exige) e pode
  esconder a falta de `#include <stdlib.h>`. Preferir `p = malloc(n * sizeof *p);`.
- **`exit(1)` dentro de funções de TAD** (push com pilha cheia, acessa fora do limite): aceitável
  didaticamente, mas em biblioteca é melhor devolver código de erro.
- **Modo `"t"` em fopen** (`"rt"`, `"wt"`) não é padrão C (o padrão é `"r"`/`"w"`; `"b"` para binário).
- **`scanf("%s")` / `%[^\n]` sem limite**; preferir `fgets`. `scanf("%120s", nome)` está ok.
- **`float` como tipo real padrão** dos exemplos (pilha, fila de float): no LPEDC usar `double`.
- **Chamar `printf(c->f, v)` com formato vindo de dado**: perigoso se o formato for do usuário.
- **`return;` em `int main`** (exemplo de ponteiro) e `main` sem `return 0` em alguns trechos.
- **Funções sem `const`** em parâmetros de string (`char* orig`); prefira `const char*`.
- **Nomes genéricos `cria`, `libera`, `insere` iguais em vários TADs**: colidem se dois módulos forem
  ligados juntos — prefixar (`pilha_cria`, `fila_cria`).
- **Erros de digitação no código** (bons para "ache o bug", ruins para copiar): concatena com `s[i]`;
  captura com `p->x`; `scanf(" %c", %a)`; `m[i] = malloc`; `Matriz mat =` sem `*`;
  `typedef struct Lista2`; `(Circulo)p->info` sem `*`; `p->info>b` (falta `-`); chaves sobrando em
  imprime_circular; `bolha_gen` sem chaves e `buble_gen`; `comp_alunos` com parâmetros duplicados;
  aspas tipográficas “ ” em printf; travessão `–` no lugar de `-` em `fim = meio – 1`.

## Extras que não cabem no sumário
- **Listas genéricas / heterogêneas (10.3):** nó com `void* info` + campo `tipo` (RET, TRI, CIR via
  enum); cria_ret, cria_tri, cria_cir (duas alocações: objeto + nó); `area(p)` com switch convertendo o
  ponteiro; `max_area(l)`; refatoração com ret_area/tri_area/cir_area. Mostra polimorfismo "à mão" em C.
  Lista com info `Retangulo` (struct embutida, acesso `p->info.b`) × `Retangulo*` (`p->info->b`).
  Pode entrar como extra do módulo 11 ou de void* (0051).
- **Matriz simétrica e triangular (8.5):** armazenar n(n+1)/2 elementos; fórmula de índice
  `i*(i+1)/2 + j` (i ≥ j); versão com linhas de tamanhos diferentes (linha i com i+1 elementos);
  exercícios: TAD MatSim, triangular inferior/superior (o lado de fora devolve 0). Exemplo: n = 4 →
  10 elementos em vez de 16; (i, j) = (3, 1) → k = 3·4/2 + 1 = 7; (1, 3) → mesmo k = 7.
- **Árvores genéricas** (primeiro filho / próximo irmão) — ver 0098; serve para árvore de diretórios.
- **Balanceamento por contagem de nós** (não-AVL) — ver 0101.
- **Callbacks com `void* dado`** como padrão de "iterador" para qualquer estrutura (17.5).
- **Área de polígono por trapézios** (vetor de structs com índice circular) — exemplo de 0061.
- **Formatos de arquivo com palavras-chave e comentários `#`** — mini-parser (14.3), bom projeto de
  juntando-tudo do módulo 09 (salvar e recarregar a lista heterogênea de figuras).
- **Calculadora HP como TAD sobre TAD** e uso de `ungetc`.
- **Tabela de alunos com vetor de ponteiros e NULL = livre** — ponte natural para hash.
