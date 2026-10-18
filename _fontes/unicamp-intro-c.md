# Fichamento — "Introdução à Linguagem C" (versão 2.0)

- **Autor:** Gerência de Atendimento ao Cliente (GACLI), Centro de Computação da UNICAMP (sem data,
  anos 1990; bibliografia: K&R 1986, Schildt Turbo C 1988, Mizrahi 1990).
- **Avaliação geral:** apostila-resumo curta, quase só sintaxe + um exemplo por tópico, sem
  exercícios. Escrita em **C pré-ANSI (K&R)**: `main()` sem tipo, definições de função no estilo
  `int f(a, b) int a, b; {...}`, protótipos sem parâmetros, `#include <stdio>`. Vários exemplos têm
  erros de digitação ou de lógica. Serve como **fonte de exemplos curtos de printf e ponteiros** e
  como **material de "isto é C antigo, não faça assim"**. Não cobre estruturas de dados.

### logica5-compilacao
- **Conceitos-chave:** cadeia editor → pré-processador (fonte expandido) → compilador (objeto) →
  ligador (executável); no UNIX o comando era `cc` (hoje `gcc`/`cc`). C nasceu para reescrever o
  UNIX (antes em assembly).

### 0002-variaveis / 0003-tipos-e-limites
- **Conceitos-chave:** identificadores começam com letra ou `_`, case sensitive; árvore de tipos
  (escalares: aritméticos e ponteiros; não escalares: struct, union, matriz). Tabela de faixas
  **mínimas** garantidas (int ≥ 16 bits, long ≥ 32) — boa ideia, ao contrário de tabelas "fixas".
  Programa que imprime `sizeof` de cada tipo.
- **Pegadinhas (erros da fonte):** `char` com faixa `[0,128)`; 2^32 escrito como 4.294.967.298
  (é …296); "unsigned sort/log"; `sizeof` impresso com `%d` (o correto é `%zu`).
- **Ideias de exercícios:** comparar a tabela mínima com o que `limits.h` mostra na máquina.

### 0005-printf (melhor parte da fonte)
- **Conceitos-chave:** largura menor que o número não trunca (`%2d` de 350 → `350`); `%6d` alinha à
  direita; `%10.2f` para colunas alinhadas; `%04d` e `%06d` completam com zeros; `%6.4d` de 21 →
  `  0016` (precisão em inteiro = mínimo de dígitos).
- **Ideias de exemplos:** `printf("%d %c %x %o\n", 'A','A','A','A')` → `65 A 41 101`;
  `printf("%c %c %c %c\n", 'A', 65, 0x41, 0101)` → `A A A A` (mesmo valor em quatro bases).
  Tabela de valores 8.0 / 15.3 / 584.13 alinhada com `%10.2f`.
- **Pegadinhas:** `%4.2f` de 3456.78 imprime `3456.78` (a largura é mínima, não máxima);
  `printf("%u", &num)` para endereço (usar `%p`).
- **Ideias de exercícios:** prever a saída das quatro linhas de `%04d %06d %6.4d %6.0d` com 21.

### 0006-scanf
- **Conceitos-chave:** argumentos são endereços; memória como bytes numerados de 0 em diante; o
  endereço de uma variável é o do seu primeiro byte.
- **Pegadinhas:** `scanf(%d,%d,&x,&y)` sem aspas (erro da fonte); formato `"%d,%d"` exige a vírgula
  digitada.

### 0007-aritmetica / 0009-atribuicao
- **Conceitos-chave:** `%` = resto da divisão inteira (10/3 → 3, 10%3 → 1); atribuição é expressão
  (`if ((produto = x*y) > 0)`); `x *= y + 1` ≡ `x = x*(y+1)`; `++x` × `x++` com printf.
- **Ideias de exercícios:** prever saída de `x=0; printf x++; printf x; printf ++x; printf x` →
  0, 1, 2, 2.

### 0008-conversao
- **Ideias de exemplos:** `printf("%f", (float) i/3)` com i = 1 → 0.333333 (cast antes da divisão).

### 0012-relacionais / 0013-logicos / 0014-if
- **Conceitos-chave:** verdadeiro = qualquer não-zero; relacionais/lógicos devolvem 0 ou 1 e têm
  precedência menor que os aritméticos. `if (b)` como teste de divisor não nulo.
- **Ideias de exemplos:** imprimir `i == j é 0/1` para todos os relacionais com dois números lidos.

### 0017-ternario
- **Pegadinhas:** o exemplo `max = (x>y) ? 1 : 0` não calcula o máximo (devolve um indicador) — bom
  "ache o erro": corrigir para `max = (x > y) ? x : y`.

### 0018-switch / 0021-do-while
- **Ideias de exemplos:** menu "1. inclusão 2. alteração 3. exclusão" com `getchar` + `switch`,
  depois envolvido num `do...while` que repete enquanto a opção for inválida.

### 0022-for / 0023-break-continue / 0024-lacos-aninhados
- **Ideias de exemplos:** `for (x=0, y=0; x+y < 100; ++x, ++y)` (vírgula); `for(;;)` + `break`
  quando lê 'a'; `continue` para imprimir só pares (`if (x % 2) continue;`); 24 linhas × 39 traços.
- **Pegadinhas:** `while (ch != 'a')` com `ch` não inicializado.

### 0026-aleatorios
- **Ideias de exemplos:** jogo "adivinhe o número" com `srand(time(NULL))` e dicas "muito alto /
  muito baixo".
- **Pegadinhas:** `segredo = rand()/100` gera números enormes — usar `rand() % 100 + 1`.

### 0037-vetores / 0039-matrizes
- **Conceitos-chave:** memória contígua, índice de 0 a N−1, C não verifica limites (exemplo que
  escreve 100 posições num vetor de 10).
- **Pegadinhas:** média de notas com `soma/5` inteira; afirmação de que vetor local só pode ser
  inicializado se `static` — restrição do C pré-ANSI, **obsoleta**. Exemplo de matriz percorre só a
  diagonal sem dizer.

### 0041-strings / 0042-lendo-strings
- **Conceitos-chave:** string = vetor de char com `'\0'`; constante entre aspas recebe o `'\0'`
  automático; `puts` acrescenta `\n`; `strcpy`, `strcat` (não verifica tamanho), `strcmp` (0 se
  iguais — exemplo de senha "laranja").
- **Pegadinhas:** usa `gets` (e admite que não testa limites); `static re[] = "lagarto"` sem tipo.

### 0045-ponteiros / 0047-ponteiros-e-vetores
- **Conceitos-chave:** `px = &x; y = *px;` ≡ `y = x`; `*px + 1` (soma no conteúdo) × `*(px+1)`
  (próxima posição); `(*px)++` incrementa o conteúdo, `*px++` avança o ponteiro (unários associam
  da direita para a esquerda); `pa = a` ≡ `pa = &a[0]`; `pa+i` = `&a[i]`, `*(pa+i)` = `a[i]`.
  Cópia de string em versão vetor (`while (t[i] = s[i]) i++;`) e versão ponteiro
  (`while (*ps) *pt++ = *ps++;`).
- **Pegadinhas:** "ponteiro perdido": `int *p; *p = 10;` grava em lugar desconhecido; a versão
  ponteiro da cópia não copia o `'\0'` final; ponteiros impressos com `%d`/`%u`; afirmação de que
  ponteiros são "geralmente mais rápidos" que índices (não vale com compiladores modernos).
- **Ideias de exercícios:** tabela de saída do programa que imprime `x`, `px`, `*px+1`, `(*px)++`,
  `*(px++)` em sequência.

### 0048-ponteiros-e-strings / 0049-ponteiro-para-ponteiro
- **Conceitos-chave:** `char *texto = "composto"` aponta para constante; vetor de ponteiros para
  mensagens de erro (`char *erro[] = {"arquivo não encontrado\n", "erro de leitura\n"}`);
  `int x, *p, **q; q = &p; **q` → 10.
- **Pegadinhas:** a fonte diz que `char *texto = "..."` "funciona como `static char texto[]`" —
  falso: o literal é só leitura, o vetor é modificável.

### 0028-funcoes / 0029-parametros / 0030-escopo
- **Conceitos-chave:** void para função sem retorno; chamada por valor (`sqr(t)` não altera t) e por
  referência (`troca(&x, &y)`); locais na pilha, globais em área fixa, `static` local conserva valor;
  local com mesmo nome oculta a global (exemplo `cont` em func1/func2).
- **Pegadinhas:** todas as definições em estilo K&R; `return;` sem valor em função `int`
  (`elevado` com expoente negativo); `void linha;` (falta parênteses).
- **Ideias de exercícios:** reescrever `elevado(base, expoente)` e `pertence(string, caracter)` em C
  moderno com protótipo completo.

### 0038-vetores-e-funcoes
- **Ideias de exemplos:** `mostra(int num[])` ≡ `mostra(int *num)`; `maiusc(char *s)` que altera a
  string original com `toupper`.

### 0059-struct / 0061-vetor-de-structs / 0062-ponteiro-para-struct
- **Ideias de exemplos:** `struct lapis {int dureza; char fabricante; int numero;}`, vetor de 3
  lápis impresso em tabela com `\t`; `(*p).dureza` ≡ `p->dureza`.

### 0054-malloc-free
- **Ideias de exemplos:** alocar 40 ints, preencher com `*(p+t) = t`, imprimir, liberar; ler N
  floats e achar o maior.
- **Pegadinhas:** diz que malloc vem de `stdio.h` (é `stdlib.h`); `#include <stdio>` sem `.h`; aloca
  `quant+1` e usa índices de 1 a quant (desperdício e confusão).

### 0067-arquivos-texto
- **Ideias de exemplos:** gravar inteiros até digitar 0 com `fprintf`, fechar, reabrir em `"r"` e
  reler com `fscanf`.
- **Pegadinhas:** laço `while (!feof(fp))`; não testa se `fopen` retornou NULL; não fecha o arquivo
  no fim.

### 0069-argumentos
- **Ideias de exemplos:** `alo <nome>` com checagem `argc != 2`; contagem regressiva a partir de
  `atoi(argv[1])` com opção `display` comparada por `strcmp` e bip `printf("%c", 7)`.

---

## Obsoleto / evitar
- `main()` sem `int`; tipo implícito (`static re[]`); definições de função K&R; protótipos vazios
  (`int elevado();`).
- `#include <stdio>` sem `.h`; malloc "em stdio.h"; `cc` como único compilador.
- `gets`; `while(!feof(fp))`; ponteiros impressos com `%d`/`%u`.
- Inicialização de vetor local "só se static" (regra pré-ANSI).
- `rand()/100` para sortear; "ponteiro é mais rápido que índice".

## Extras que não cabem no sumário
- História de C/UNIX; árvore de classificação dos tipos (escalares × agregados; incompletos).
