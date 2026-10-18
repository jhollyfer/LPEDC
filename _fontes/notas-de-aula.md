# Fichamento — "Linguagem C — Notas de Aula" (UFPR)

- **Título:** Linguagem C — Notas de Aula (Parte I: Programação Básica; Parte II: Tópicos Avançados), maio/2008, 140 p.
- **Autores:** Profª Carmem Hara e Prof. Wagner Zola; revisão: Prof. Armando Luiz N. Delgado (UFPR).
- **Arquivo lido:** `2a420542-NotasAula.md` (3765 linhas, lido por completo).
- **Avaliação geral:** a melhor das cinco fontes em **didática de sala de aula**: explica o "porquê" (variável como
  caixa com nome/tipo/endereço/valor; expressão de atribuição tem valor; registro de ativação LIFO; por que o
  vetor é alterado na função e a variável simples não), traz **muitos "o que é impresso?"** com resposta e
  dezenas de **pegadinhas reais** (`=` no `if`, `else` pendurado, laço sem chaves, `!=` como condição de parada,
  ordem de avaliação de `++` em argumentos, sobra no buffer e laço infinito do `scanf`). Ambiente Dev-C++
  (int de 16 bits nas tabelas, `main()` sem `int`, `gets`). Alguns exemplos têm erros de digitação ou de
  conceito — anotados aqui como material de "ache o erro". Não cobre estruturas de dados (só busca linear,
  seleção e bolha).

> Prioridade deste fichamento: pegadinhas e exercícios "o que imprime?" com resposta.

---

### logica2-pseudocodigo
- **Ideia de exemplo:** o mesmo problema (perímetro e área do círculo de raio R) escrito como
  `ALGORITMO PERIMETRO_AREA ... FIM_ALGORITMO` (com `Leia`, `Escreva`, `**` para potência) e depois em C.
  Bom modelo de "tradução" pseudocódigo → C, linha a linha (Leia→scanf, Escreva→printf, `**`→pow).
- **Pegadinha da própria fonte:** no algoritmo, `Raio` é `int` — lê só raio inteiro. Pergunta: e se o usuário
  digitar 2.5? (lê 2 e deixa ".5" no buffer).

### 0001-primeiro-programa
- **Conceitos-chave:** programa = uma ou mais funções; `main` marca o início; sentença simples termina em
  `;`; sentença composta (bloco) entre chaves; o corpo de `main` é uma sentença composta.
- **Comentários:** `/* ... */` não aninham — `/* a /* b */ c */` é ilegal (o primeiro `*/` fecha tudo e
  sobra `c */`). Ótima pegadinha.
- **Boas regras de comentário (parafraseadas):** comentar a intenção, não transcrever o código ("obtém idade
  e converte em dias" em vez de "usando scanf, obter idade e multiplicar por 365"); não comentar o óbvio
  (`i++; /* incrementa i */`); documentar cada função com **ação, entrada, saída, suposições, algoritmo**.
- **Exercício:** dado um comentário ruim, reescrevê-lo (comentar o código, não codificar o comentário).

### 0002-variaveis
- **Analogia excelente:** variável é uma caixa: nome e endereço nunca mudam, o conteúdo muda, o tipo diz o
  tamanho da caixa e como interpretar o que está dentro. Resumo: **tipo, nome, endereço, valor**.
- **Conceitos-chave:** declarar antes de usar (senão, erro de compilação); declarar NÃO dá valor — usar antes
  de atribuir dá "lixo" (o que estava naquele endereço); inicialização na definição (`int pera = 3;`).
  Regras de nome; convenções: nomes significativos, `i, j, k` só para contadores, `horaInicio` ou
  `hora_inicio` — mas **seja consistente**.
- **Pegadinha:** `'5'` é um caractere (código 53), não o inteiro 5.
- **Exercício:** quais nomes são válidos? `hora_inicio`, `tempo`, `var1`, `3horas`, `total$`, `azul-claro`
  (válidos os três primeiros).
- `float` guarda mantissa e expoente (como 6.023e23); só ~6-7 dígitos significativos — gancho para
  "por que 0.1 + 0.2 não dá exatamente 0.3".

### 0003-tipos-e-limites
- Tabela de modificadores (`short`, `long`, `signed`, `unsigned`) com faixas mínimas (int 16 bits na
  tabela; dizer no curso que hoje é 32). `sizeof(char *)` dá o tamanho de um ponteiro.

### 0004-constantes
- **Conceitos-chave:** constantes não ocupam lugar com nome na memória e têm tipo pela forma de escrever:
  `2` é int, `2.0` é double (toda constante real é double por convenção). Sequência de escape: a barra
  invertida avisa que o próximo caractere não é ele mesmo (`\n`, `\\`). `'A' + 1` vale 66, e como char é
  `'B'`. `#define PRECO 1.99`: o pré-processador troca texto como um "localizar e substituir" — o compilador
  nunca vê o nome `PRECO`. Convenção: maiúsculas para `#define`, minúsculas para variáveis. Alternativa:
  `const`. Vantagem: `#define NUM_ALUNOS 81` muda num lugar só.

### 0005-printf
- **Conceitos-chave:** o 1º argumento é sempre uma string; especificadores casam com os argumentos NA ORDEM;
  argumentos podem ser expressões (`peso * PRECO`). Largura é mínima: `%6d`, `%6.3f`, `%.3f`, `%6.0f`; se o
  número não couber, sai inteiro.
- **Exemplo pronto:** 3 peras de qualidade 'A' pesando 2.5 kg a 1.99/kg → "Existem 3 peras de qualidade A
  pesando 2.500000 quilos." / "O preco por quilo e 1.990000, total e 4.975000".
- **Pegadinha (excelente):** `printf("%d\n", 3.14159);` compila e imprime lixo (ex.: -31147) — o tipo do
  argumento tem de casar com o especificador; o compilador antigo não avisava (hoje use `-Wall`).
- **Pegadinha:** o exemplo da fonte `printf("area do triangulo = ", triang_area(0.03, 1.25));` não tem `%f`
  — o valor é calculado e nunca impresso. Bom "ache o erro".
- `%%` para imprimir `%` (ex.: "Juros 7%%.").

### 0006-scanf
- **Conceitos-chave:** `&` antes de variáveis simples; vários valores num `scanf` separados por qualquer
  espaço em branco (espaço, tab, Enter) — os espaços no formato `"%d %d %d"` são só estética, `"%d%d%d"`
  funciona igual; **`%c` NÃO pula espaços** (espaço é caractere, código 32).
- **Explicação boa (sobra no buffer):** digitando `42␣␣⏎`, o `scanf("%d")` consome só 42; os espaços e o
  `\n` ficam esperando e serão lidos pelo próximo `getchar`/`%c`. Remédio: `while (getchar() != '\n');`
  depois da leitura — só onde precisa (antes de um `getchar`/`%c`, especialmente em laços).
- **Pegadinha CLÁSSICA (laço infinito):** num `while (total < 20) { scanf("%d", &num); total += num; }`, se o
  usuário digitar uma letra, o `scanf` falha, deixa a letra no buffer e falha de novo para sempre. Solução
  da fonte: `if (scanf("%d", &num) < 1) while (getchar() != '\n'); else total += num;` — usa o **retorno do
  scanf** (nº de itens lidos). Ótimo exemplo para 0011.
- **Exemplo:** data de aniversário `dd mm aa` num só scanf → "Voce nasceu em 12/5/90".
- **Pegadinha da fonte:** `double raio; scanf("%f", &raio);` — para double é `%lf` no scanf (no printf `%f`
  serve para os dois). "Ache o erro".

### 0007-aritmetica
- **Conceitos-chave:** `* / %` mesma precedência, acima de `+ -`; operadores de mesma precedência associam da
  esquerda para a direita: `a * b / c * d % e` ≡ `((((a*b)/c)*d)%e)`. `%` só com inteiros (`22.3 % 5` é erro
  de compilação). `22 % 5` = 2. Expressões podem aparecer onde se usa valor, mas não à esquerda de `=` nem
  dentro de `&`: `int yucky + 2 = 5;` e `scanf("%d", &(oops * 5))` são ilegais.
- **Divisão inteira:** `30/5`=6, `31/5`=6, `29/5`=5, `3/5`=0.
- **Pegadinha:** `1 / 2 * x` é sempre 0 (porque `1/2` = 0); escrever `1.0 / 2.0 * x` ou `x / 2.0`.
- **Exercício "o que imprime?" (respostas da fonte):** `5 + 10 * 5 % 6` → 7; `10 / 4` → 2; `10.0 / 4.0` →
  2.5; `'A' + 1` com `%c` → B; `score + (score == 0)` com score = 5 → 5 (e com score = 0 → 1).
- **Exercício encadeado (resposta calculada):** ler n1; `n1 += n1 * 10; n2 = n1 / 5; n3 = n2 % 5 * 7;
  n2 *= n3-- % 4; printf("%d %d %d", n2, n3, n2 != n3 + 21);` — com n1 = 1: n1 = 11, n2 = 2, n3 = 14,
  `14 % 4` = 2 → n2 = 4, n3 = 13 → imprime **4 13 1**.
- **Exemplos:** par/ímpar imprimindo `numero % 2` (0 par, 1 ímpar); soma, média (`soma / 3.0`) e produto de
  3 inteiros; Fahrenheit → Celsius `(f - 32) * 5.0 / 9.0`.

### 0008-conversao
- **Conceitos-chave:** expressão tem valor **e tipo**; operandos iguais → resultado do mesmo tipo; diferentes
  → promove para o "mais complexo" (`char < int < long < float < double`). Na atribuição, converte para o
  tipo da esquerda: `float a = 3;` → 3.0; `int a = 3.1415;` → 3 (trunca); valor que não cabe → resultado
  errado. Cast `(tipo) expr` tem precedência alta: `(float) a / b` converte só `a` (suficiente); a
  variável `a` continua `int` para sempre.
- **Pegadinha (excelente) para exercício:** por que `1.0 * a / b` ≠ `a / b * 1.0`? (no segundo, `a / b` é
  divisão inteira ANTES de virar real; a=7, b=2 → 3.5 × 3.0).
- **Exemplo:** fração para decimal com `1.0 * a / b` e testando `b != 0` antes (divisão por zero).

### 0009-atribuicao
- **Conceitos-chave (explicação muito boa):** `=` é um operador e **a atribuição é uma expressão com valor**
  (o valor atribuído). Por isso `i = j = k = 0` funciona (associa da direita: `i = (j = (k = 0))`). lvalue =
  algo que tem endereço (por enquanto, só variáveis). Efeito colateral:
  `printf("%d", (quadrado = n * n) < 50)` imprime 1 **e** altera `quadrado` para 4; precisa dos parênteses
  porque `=` tem precedência menor que `<`. Regra prática da fonte: **não use atribuições dentro de outras
  sentenças**.
- `x *= y + 1` ≡ `x = x * (y + 1)` (não `x * y + 1`).
- `k++` × `++k`: com k = 5, `printf("%d", k++)` imprime 5 (k vira 6); `printf("%d", ++k)` imprime 6. O
  valor de `x` termina igual; o que muda é o **valor da expressão**.
- `(ack + 2)++` e `(nope + 3) += 5` → erro de compilação (não são lvalues).
- **Pegadinha IMPORTANTE (ordem de avaliação):** `printf("%d %d\n", ++uhoh, uhoh * 2);` — C não fixa a ordem
  de avaliação dos argumentos; o resultado muda conforme o compilador. Idem `x + x++`, `y = x + x--`,
  `x = x++` (hoje: comportamento indefinido). Solução: incrementar numa sentença separada.
- **Exercício:** o que imprime `int k = 5; printf("%d ", k++); printf("%d ", k); printf("%d", ++k);`?
  (5 6 7).

### 0012-relacionais
- **Conceitos-chave:** resultado é 0 (falso) ou 1 (verdadeiro); C (antigo) não tem tipo booleano e guarda
  isso em `int`; mas qualquer valor ≠ 0 conta como verdadeiro. Aritméticos têm precedência maior:
  `3 + 5 < 6 * 2` ≡ `(3+5) < (6*2)`.
- **Exemplo pronto:** "Pode tirar carteira de motorista? %d" com `idade >= 18` → 0 para 17, 1 para 35.
- **Truque:** `score + (score == 0)` — usa o 0/1 da comparação dentro de uma conta.
- **Pegadinha:** `=` no lugar de `==` não é erro de sintaxe (ver 0015).

### 0013-logicos
- **Conceitos-chave:** `!` (unário, precedência alta, junto do `-` unário), `&&` (verdadeiro só se ambos),
  `||` (falso só se ambos); `&&` antes de `||`; ambos abaixo dos relacionais (dispensa parênteses em
  `x >= 3 && x <= 50` e `x == 1 || x == 2 || x == 3`). **Leis de De Morgan:** `!(x && y)` ≡ `!x || !y`;
  `!(x || y)` ≡ `!x && !y` (usadas para reescrever condição de parada de laço).
- **Exercícios "o que imprime?" (respostas da fonte):** x=5, y=8: `if (x == 5 && y == 8)` → a. x=4, y=8:
  `x == 5 || y == 8` → a; `!(x == 5 || y == 8)` → b; `!(x == 5 && y == 8)` → a.
  `x == 5 || y == 8 && z == 10` ≡ `x == 5 || (y == 8 && z == 10)`.
- **Exemplo:** "par e não negativo" com `if` aninhado × `(num >= 0) && (num % 2 == 0)` × `!(num % 2)`.
- **Pegadinha da fonte (ache o erro):** o exemplo do triângulo retângulo tem `s2 == s1 + s2` (deveria ser
  `s3`) e um parêntese a mais; e a versão com `!(num % 2)` usa `num > 0` em vez de `>=` (exclui o zero).
- Curto-circuito não é explicado — complementar com outra fonte.

### 0014-if
- **Conceitos-chave:** se a expressão vale ≠ 0, executa a sentença (simples ou bloco).
- **Exemplos:** fração → decimal só se `b != 0`; ordenar dois números trocando com `aux` se `num1 > num2`
  (gancho para o swap de 0046).

### 0015-if-else
- **Pegadinha MODELO (usar no curso):** `int saldo = 2000; if (saldo = 1) printf("Voce esta quebrado!");
  else printf("Seu saldo e %d", saldo);` → imprime "Voce esta quebrado!" **e** muda o saldo para 1. Com
  `==` imprime "Seu saldo e 2000". Não é erro de compilação (use `-Wall`).
- **Exercício "o que imprime?" (resposta da fonte):** x = 4, y = 8:
  `if (y = 8) if (x = 5) printf("a "); else printf("b "); printf("c "); printf("d\n");` → **a c d**. Trocando
  `=` por `==` → **b c d**. Desafio: alterar (só com chaves/`else`) para produzir "a" / "a d" / "b c d"
  conforme x e y.
- **Exemplo:** calculadora `5 * 3.5` → "= 17.50"; `10 x 5.0` → "Operador invalido" (com `else if`).

### 0016-else-if
- **Regra do else pendurado (enunciado curto):** um `else` pertence ao último `if` sem `else`.
- **Pegadinha MODELO:** número de peras: `if (num != 0) if (num == 1) "Voce tem uma pera."; else "Voce nao tem
  nenhuma pera.";` — a endentação engana: o `else` é do `if (num == 1)`, então com 5 peras diz "não tem
  nenhuma" e com 0 não diz nada. Correção com chaves.
- **Exemplo:** comparar dois números (iguais / primeiro menor / primeiro maior) — a última opção nem
  precisa de teste.
- **Exercício:** ler 3 números e imprimir o maior.
- `if` aninhado: positivo/negativo × par/ímpar (4 mensagens).

### 0018-switch
- **Conceitos-chave:** compara a expressão com constantes; executa a partir do `case` igual e **segue
  executando tudo abaixo** até um `break` (diagrama mostra a diferença com e sem break); lista de sentenças
  do case não precisa de chaves; pode ser vazia — vários `case` compartilham a ação:
  `case '*': case 'x': case 'X':` multiplicação; `case '/': case '\\':` divisão. `default` opcional. Regra da
  fonte: case sem break deve ser comentado (`/* sem break: continua */`).
- **Exercício:** ler mês e ano e imprimir o número de dias do mês (fevereiro com ano bissexto: divisível por
  4 e não por 100, ou por 400). Ex.: 2/2024 → 29; 2/1900 → 28; 4/2023 → 30.

### 0020-while
- **Conceitos-chave:** testa antes; corpo simples ou bloco; ao sair, a variável de controle vale o primeiro
  valor que falhou (`contador` termina em 5).
- **Exemplo:** pedir números até a soma ≥ 20 (3, 8, 15 → total final 26) — número de repetições desconhecido.
- **Pegadinha MODELO (chaves):** `while (i < 5) i += 1; j += 1;` — só `i += 1` está no laço, apesar da
  endentação. Regra: use chaves sempre (ao acrescentar uma linha depois, você não esquece).
- **Estilo:** três posições de chaves e espaço depois do `while` — escolha um e seja consistente.

### 0021-do-while
- **Conceitos-chave:** testa depois; executa pelo menos uma vez; ideal para validar entrada.
- **Exemplo:** "Entre com um numero par": digita 3, 1, 5, 4 → "Obrigado." Comparação com a versão `while`,
  que obriga a inicializar `num = 1` artificialmente para entrar no laço (explicação ótima de quando usar
  do-while).
- Erro da fonte: `#include <stdio>` sem `.h`.

### 0022-for
- **Conceitos-chave:** 4 partes (inicialização uma vez, teste, corpo, incremento); equivalência exata com
  `inicialização; while (teste) { corpo; incremento; }`; vírgula para várias inicializações
  (`contador = 0, total = 0`); escolha `for` quando há inicialização + incremento, `while` quando o nº de
  repetições é desconhecido.
- **Pegadinha (boa):** condição `contador != 5` em vez de `< 5`: se a inicialização mudar para 25, o laço
  nunca termina. Prefira `<`/`<=`.
- **Exemplos prontos:** soma acumulada de 0 a 9 (total final 45, imprimindo cada passo); números de 30 a 5
  divisíveis por 3 em ordem decrescente → 30 27 24 21 18 15 12 9 6, soma = 162.
- Pré ou pós-incremento na 3ª parte do `for` dá no mesmo.

### 0024-lacos-aninhados
- **Exemplos:** tabuada 4×4 com `while` aninhado e `%3d`; mesma coisa com o `printf("\n")` dentro do laço
  interno (um número por linha) — exercício "onde fica o `\n`?"; triângulo de asteriscos com `\t` e
  `while (coluna < linha)`.
- **Pegadinha da fonte (ótima para exercício):** o triângulo com `linha` de 1 a 7 e `coluna < linha` imprime
  de 0 a 6 asteriscos (a 1ª linha sai vazia), mas a saída mostrada no texto vai de 1 a 8. Pergunta: quantos
  asteriscos tem a 1ª e a última linha? Como corrigir para 1..7? (`coluna <= linha`).
- Tabuada 10×10 com cabeçalho de colunas, linha de traços e `%2d|` na margem.

### 0025-padroes-de-laco
- Acumulador (`total += num`), contador, sentinela (EOF / valor negativo), flag `ordenado` no bubble sort,
  validação com do-while. Contar caracteres até EOF: `while ((ch = getchar()) != EOF) total++;`.

### 0028-funcoes
- **Por que funções (bem explicado):** evitar repetição (o teste de primo escrito duas vezes no main vira
  `ehPrimo(n)`), corrigir num só lugar, reduzir complexidade, projeto *top-down*; quem usa precisa saber **o
  que** a função faz e **como chamar**, não como foi feita (como `printf`, `sqrt`).
- **Conceitos-chave:** não se define função dentro de função; protótipo = cabeçalho + `;` (nomes dos
  parâmetros opcionais), permite chamar antes da definição e faz o compilador detectar número/tipo errado
  de argumentos; `void alo(void)` sem retorno e sem argumentos; chamada é sentença (termina com `;`);
  `return expr;` converte para o tipo da função e encerra NA HORA (código depois não roda); vários
  `return` permitidos; em função `void`, `return;` sai antecipadamente.
- **Exemplos:** `alo()` chamado 3 vezes num while; `cumprimenta(char, char)` com iniciais lidas por
  `getchar` ("Ola, YK!"); `quadrado` usado em `quadrado(3) + quadrado(4)` = 25; `cinco()` retorna 5;
  `obtem_valor()` (15 e 4 → soma 19); `obtem_valor_positivo` (se negativo avisa e retorna `-valor`);
  `instrucoes()` com `return;` se a resposta for 'n'; `volume(c, l, a)`; `dinheiro(c25, c10, c5, c1)`
  (moedas → reais).
- **Exercício:** `dinheiro(3, 2, 1, 4)` → 0.75 + 0.20 + 0.05 + 0.04 = 1.04.

### 0029-parametros
- **Conceitos-chave:** cada parâmetro precisa de tipo e nome; são variáveis locais já definidas no
  cabeçalho (redefini-las no corpo é erro) e já chegam inicializadas pelo chamador; argumentos reais podem
  ser expressões, avaliadas antes da chamada; ordem e tipos devem casar.
- **Chamada por valor (explicação ótima):** `quadrado(x)`, `quadrado(5)` e `quadrado(625/25 - 4*5)` são
  indistinguíveis para a função — ela só recebe o número 5, não sabe de onde veio nem onde `x` mora;
  por isso não consegue alterá-lo.
- **Exemplos:** `abs` que faz `x = -x` no parâmetro sem afetar `n`; `fahr_para_cels(212.0)` = 100.0;
  `area(14.0, 21.5)` = 301.0; `triang_area(raio, circ_area(raio))` (chamada como argumento).

### 0030-escopo
- **Conceitos-chave:** local = visível só na função (ou bloco), existe só durante a ativação ("automatic");
  duas funções podem ter `x` próprios sem conflito; `static` local guarda o valor entre chamadas; global =
  visível do ponto de definição até o fim do arquivo; local com mesmo nome **esconde** a global.
- **Pegadinha:** usar no `main` uma variável `x` que só existe dentro de `obtem_int()` → erro de compilação
  (o certo é a função retornar o valor).
- **Exercício "o que imprime?" (EXCELENTE):** `int y = 100;` global; `soma_y(x)` retorna `x + y`;
  `soma_yy(x)` faz `y = 300` e retorna `x + y`; main com `z = 0` chama `soma_y(z)`, `soma_yy(z)`,
  `soma_y(z)` → **100 300 300** (mesma chamada, resultados diferentes: o perigo das globais).
- **Exercício:** `int valor = 3;` global e `int valor = 4;` dentro do main; `printf` → 4.
- **Exemplo de global (com ressalva):** caixa eletrônico com `saldo` global alterado por `credito`, `debito`,
  `juros` (7%): 1000 + 200 − 80 = 1120 × 1.07 = **1198.40**. A fonte só permite globais com autorização.

### 0031-pilha-de-chamadas
- **Explicação ótima:** cada execução de uma função é uma **ativação**; ao chamar, cria-se um **registro de
  ativação** com o endereço de retorno; locais são alocadas na entrada e liberadas na saída; o retorno vai
  para um lugar combinado. Se A chama B e B chama C, C é a última a começar e a primeira a terminar
  (**último que entra, primeiro que sai**) — base para desenhar a pilha de frames.
- **Exercício:** desenhar os registros de ativação para main → triang_area → (volta) → circ_area.

### 0035-preprocessador
- Diretivas ocupam a linha inteira; `#define` = substituição de texto antes da compilação; `#include
  "geom.h"` (diretório do projeto, para compartilhar `#define PI` entre vários arquivos de uma biblioteca
  geométrica) × `<stdio.h>` (diretório padrão); `.h` é convenção (*header*); o pré-processador remove
  comentários. Não trata macros com parâmetro nem `#ifdef`.

### 0037-vetores
- **Motivação boa:** média de 4 alunos com `nota0..nota3` — e se fossem 100? → array.
- **Conceitos-chave:** elementos do mesmo tipo em endereços adjacentes; índice de 0 a n−1; índice pode ser
  qualquer expressão inteira; o nome do array é um endereço constante; o array como um todo não tem valor,
  cada elemento tem. `&nota[i]` no scanf dispensa parênteses (`[]` tem precedência maior que `&`).
  Tamanho via `#define ESTUDANTES 4` para mudar num lugar só.
- **Inicialização:** `{1, 42, -13, 273}`; tamanho omitido é contado (`int peso[] = {153, 135, 170}` ≡ `[3]`);
  mais valores que o tamanho → erro; só na definição (atribuir `{...}` depois é erro); sem inicializar →
  lixo.
- **ERRO na fonte (usar como pegadinha):** diz que, com menos valores que o tamanho, os restantes ficam
  com lixo — na verdade ficam **zerados** (`int v[5] = {1};` → 1 0 0 0 0; `int v[100] = {0};` zera tudo).
  A fonte também diz que os valores têm de ser constantes (vale para C89; hoje locais aceitam expressões).
- **Pegadinha (limites):** `int ops[10]; i = 0; while (i <= 10) ops[i++] = 0;` escreve em `ops[10]`,
  fora do vetor — o compilador não reclama e o efeito é imprevisível.
- **Exemplo pronto:** notas 93, 85, 74, 100 → média inteira 88.
- **Pegadinha:** `arr2 = arr1;` não copia e `arr1 == arr2` não compara conteúdos (compara endereços) —
  copiar/comparar elemento a elemento.

### 0038-vetores-e-funcoes
- **Explicação MODELO (usar):** `troca(x)` com x = 10 não altera x (imprime x=10), mas `troca_vet(v)` com
  v = {30, 40, 50} deixa v = {60, 70, 80}: o nome do array vale o **endereço** do 1º elemento (ex.: 1342),
  e é esse endereço que é copiado para o parâmetro — a função escreve na mesma memória. Passar um único
  elemento (`v[0]`) se comporta como variável simples (v[0] continua 30).
- **Conceitos-chave:** no parâmetro, `int a[]` ou `int a[TAMANHO]` (o tamanho é só legibilidade); para
  multidimensional, todas as dimensões menos a primeira são obrigatórias.
- **Exemplos/exercícios:** `array_max` (73, 85, 42, −103, 15 → 85); `inicializaArray(v, n, 42)`;
  `pesquisa_linear(v, n, chave)` devolve índice ou −1; `soma_array(a, b, c, n)`.

### 0039-matrizes
- **Conceitos-chave:** array de arrays; `int tabela[3][5]` → índices 0..2 e 0..4; armazenamento com o
  **último índice variando mais rápido** (tabela[0][0], [0][1], [0][2], [1][0]...); `tabela[4][5]` pode ser
  vista como 4 elementos, cada um um vetor de 5 (tabela[1] → {20, 22, 24, 26, 28}); inicialização com
  chaves aninhadas e 1ª dimensão omitível.
- **Exemplos:** marcar coordenadas `y,x` digitadas com 1 numa matriz 5×5 de zeros (negativo sai);
  tabuada 10×10 em matriz; funções `pontos`, `marca_triang` (abaixo da diagonal), `flip` (transpor
  trocando `[y][x]` com `[x][y]` só no triângulo `x <= y` — exercício: o que acontece se percorrer a matriz
  inteira? volta ao original).

### 0040-caracteres
- `getchar` devolve `int` (código do caractere ou EOF); digitar `AbcD⏎` e chamar `getchar` uma vez lê só o
  'A' (o resto fica no buffer).
- **Pegadinha não percebida pela fonte (ótima):** testa letra com `if (ch < 'A' || ch > 'z')` — aceita
  `[ \ ] ^ _ `` ` `` como letras (estão entre 'Z' e 'a' na ASCII). Correto: `isalpha(ch)` ou
  `(ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')`.
- Ordem garantida só dentro de cada grupo ('0' < ... < '9', 'A' < ... < 'Z', 'a' < ... < 'z');
  `tolower('A')` = 'a', `tolower('1')` = '1'.

### 0041-strings
- **Conceitos-chave:** string = array de char que **deve** terminar em `'\0'`; `"ci208"` ocupa 6; para guardar
  "programar e divertido" (21 caracteres) precisa de 22; `puts` imprime e pula linha (sem formatação);
  `%s`; array de strings `char nomes[5][20]`.
- **Implementações próprias (bons exercícios):** `strlen` (conta até `'\0'`), `strcmp` (retorna 0, negativo
  ou positivo; ordem de dicionário: "tudo" < "xadrez", "calor" < "calorao", "" < qualquer), `strcpy`
  (copia inclusive o `'\0'`). Para comparar sem diferenciar maiúsculas, converter com `tolower`.
- **Pegadinhas da fonte:** compara caracteres com `NULL` e sugere `#define NULL '\0'` — confusão entre ponteiro
  nulo e caractere nulo (use `'\0'`); protótipo `void strcmp(...)` escrito no lugar de `strcpy`.
- **Exemplo:** "Dostoevsky" → 10 caracteres.

### 0042-lendo-strings
- `gets` lê a linha toda, mas estoura se o usuário digitar mais que o tamanho (perigoso); `scanf("%s", nome)`
  lê só a 1ª palavra ("Jose Silva" → "Oi, Jose.") e **sem `&`** (o nome do array já é endereço).
- Na parte de arquivos, a própria fonte pergunta "por que `fgets` e não `gets`?" e usa
  `while (fgets(linha, 80, stdin) != NULL) fputs(linha, fp);`.

### 0044-memoria / 0045-ponteiros
- **Explicação boa:** `int i = 5; char c = 'G';` desenhados na memória: i no endereço 1342 (ocupa 1342-1343;
  o endereço é onde começa), c em 1346. `&i` vale 1342. `&` só se aplica a lvalues.
- **Conceitos-chave:** ponteiro guarda endereço; há um tipo de ponteiro para cada tipo (todos os endereços têm
  o mesmo tamanho, mas é preciso saber quantos bytes ler e como interpretar); em `int *pi`, o nome é `pi` e o
  tipo é `int *`; `*` de dereferência nada tem a ver com multiplicação; `*pi` pode ser lvalue:
  `*pi = *pi + 5` muda o valor apontado, não o ponteiro. Acesso direto (pelo nome) × indireto (pelo
  ponteiro).
- **Pegadinha:** `float *p3 = p1;` (p1 é `int *`) → só aviso, mas está errado.

### 0046-passagem-por-referencia
- **Sequência didática MODELO:** (1) troca no próprio main com `temp` funciona; (2) função `troca(int x, int y)`
  NÃO funciona (3 5 → continua 3 5) — por valor e `return` só devolve um valor; (3) `troca(int *px, int *py)`
  chamada com `troca(&a, &b)` funciona (5 3). Regra: se a função precisa alterar variável do chamador,
  passe o endereço e use ponteiro no parâmetro. Explica o `&` do `scanf`.

### 0047-ponteiros-e-vetores
- **Conceitos-chave:** só soma/subtração de inteiros; subtração e comparação entre ponteiros do mesmo tipo
  (com sentido só no mesmo array); somar dois ponteiros não faz sentido. `ptr = val` ≡ `ptr = &val[0]`;
  `nome + 4` ≡ `&nome[4]`; `*(ptr + 3)` ≡ `ptr[3]` ≡ `val[3]`.
- **Pegadinhas MODELO:** `pstr = nome++;` é erro (nome de array não é variável); `ptr += 4; ptr[3] = 20;`
  altera **val[7]**, não val[3] (indexar ponteiro é relativo a onde ele aponta agora); `diff = pstr - pnum`
  com tipos diferentes é incorreto; `pstr = &str[30]` com `str[30]` → `pstr - str` = 30 (endereço "um depois
  do fim" é válido para conta, não para acesso).
- **Contraste ótimo:** dentro de `func_1(char vet[])`, `vet++` É permitido (o parâmetro é um ponteiro
  comum), enquanto no main `ender++` não é.

### 0048-ponteiros-e-strings
- Constante string = array anônimo; seu valor é um ponteiro para o 1º caractere. Array de ponteiros:
  `char *frases[60]; frases[3] = "..."; puts(frases[3]);`.
- **Recomendação da fonte a corrigir no curso:** propõe `char *nome = "..."` como forma preferida — hoje:
  usar `const char *nome = "..."` (literal não pode ser modificado) ou `char nome[] = "..."` (cópia
  modificável). Bom ponto para 0048.

### 0050-ponteiro-para-funcao
- Não coberto.

### 0054-malloc-free / 0055-calloc-realloc
- **Motivação boa:** reservar o tamanho máximo para todo arquivo desperdiça memória e prejudica outros
  processos num sistema multitarefa (swapping).
- **Conceitos-chave:** `malloc(bytes)`, `calloc(n, tam)` (zera a área), `realloc(p, novo)` (pode mover e
  copiar), `free(p)`; testar NULL sempre.
- **Exemplo:** ler inteiros até digitar 0, crescendo o vetor de 1 em 1 com `realloc` (`(i + 2) * sizeof(int)`)
  — bom ponto de partida para 0055, discutindo o custo de crescer de 1 em 1 × dobrar.
- **Pegadinhas/desatualizações:** diz que malloc retorna `char *` (é `void *` desde C89; cast desnecessário
  em C); `memint = realloc(memint, ...)` perde o bloco se falhar; afirma que realloc mantém o endereço ao
  diminuir e muda ao aumentar (não é garantido).

### 0059-struct / 0061-vetor-de-structs / 0062-ponteiro-para-struct
- **Conceitos-chave:** declaração de struct cria um TIPO (não aloca); definir variável aloca; membros
  uninicializados = indefinidos; inicialização na ordem `{3, 'C'}`; nomes de membros podem repetir nomes de
  variáveis sem conflito. **Diferença essencial com array:** struct pode ser atribuída inteira com `=`
  (copia todos os membros, inclusive arrays internos), passada por valor e retornada por função; array não.
  Únicos usos da struct inteira: `=`, `&` e acesso a membros (`+=`, `++`, `==` em struct → erro).
- **Exemplos:** `struct endereco` com `obtem_endereco()` retornando a struct (comparado lado a lado com
  `obtem_int()` — analogia ótima); vetor de 10 endereços; struct aninhada `student` com `casa` e `escola`
  (`pessoa.casa.rua`).
- **Ponteiro para struct:** `(*pfac).num` precisa de parênteses porque `.` tem precedência maior que `*`;
  `->` simplifica: `pfac->num`. Regra: `.` para variável struct, `->` para ponteiro. Passar ponteiro é mais
  eficiente que copiar struct grande; se só vai ler, pode passar por valor.
- **Exercício:** por que `*pfac.num` não compila? (vira `*(pfac.num)`).

### 0063-enum
- **Motivação boa:** códigos mágicos (`sexo == 2`, `cor = cor + sexo`) tornam o programa obscuro.
  `enum TpSemana {SEG, TER, QUA, QUI, SEX, SAB, DOM};` (0..6); usar valor fora da lista (`AZUL`) é erro.
- **Exemplo:** pagamento que cai no fim de semana passa para segunda: `if (diaSem == SAB) dia += 2; else if
  (diaSem == DOM) dia++;` — compare com a versão `== 5`/`== 6`.
- **Pegadinha (para exercício):** no dia 31 isso gera "dia 33" — falta tratar a virada do mês.

### 0067-arquivos-texto
- **Conceitos-chave:** arquivo = fluxo sequencial de bytes; abrir → processar → fechar; `FILE *` aponta para
  o bloco de controle do arquivo; `stdin`, `stdout`, `stderr` já abertos; modos "r", "w" (cria/apaga), etc.;
  fopen devolve NULL em caso de erro (inexistente para leitura, disco cheio, sem permissão) — testar;
  depois de aberto, o nome é irrelevante; `fclose` devolve 0 ou EOF. Três jeitos de ler texto: caractere
  (`fgetc/fputc`), linha (`fgets/fputs`), formatado (`fscanf/fprintf`, que devolvem EOF/nº de itens).
- **Exemplos:** `cat` caseiro com `while ((ch = fgetc(fp)) != EOF)` (ch é `int`); gravar o que se digita até
  Ctrl-D com `fgets`/`fputs`; **base de agentes secretos** (`agentes.txt`: "Klara 89", "Edward 888",
  "ZipZap 109") com menu e/l/q, carregar/listar/inserir/salvar — ótimo "juntando tudo" do módulo 09.
- **Pegadinhas na fonte:** `cargadb` não testa `fopen` nem o limite de 50 registros; compara `fscanf` com
  `EOF` (se a linha estiver malformada, retorna 0 e entra em laço infinito — comparar com `== 2`).

### 0069-argumentos
- `main(int argc, char *argv[])`; `argc` ≥ 1; `argv[0]` = nome do programa; aspas agrupam palavras.
  **Exercício:** `nroff -mm -TXR memo1` → argc = 4; argv[2] = "-TXR".

### 0091-bubble-sort / 0092-selection-sort / 0089-busca-sequencial
- **Seleção (traço pronto):** 9 5 2 7 3 8 1 4 6 → após cada passagem: 1 5 2 7 3 8 9 4 6 / 1 2 5 7 3 8 9 4 6 /
  1 2 3 7 5 8 9 4 6 / ... / 1 2 3 4 5 6 7 8 9; sempre n−1 passagens mesmo se já ordenado.
- **Bolha (traço pronto):** começando do fim e comparando com o anterior; 9 8 7 6 5 4 3 2 1 → 1 9 8 7 6 5 4 3 2
  → 1 2 9 8 7 6 5 4 3 → ...; versão otimizada com flag `ordenado` (para quando uma passagem não troca nada).
- **Busca linear:** `pesquisa_linear(v, n, chave)` → índice ou −1.

### 0105-hashing … 0113
- Não cobertos.

---

## Obsoleto / evitar
| Na fonte | Problema | Alternativa em C padrão |
|---|---|---|
| `main()` / `main(void)` sem tipo | "int implícito" removido no C99 | `int main(void) { ... return 0; }` |
| `gets(nome)` | estouro de buffer; removida no C11 | `fgets(nome, sizeof nome, stdin)` + tirar `'\n'` |
| `#define NULL '\0'` | confunde ponteiro nulo com caractere nulo | `'\0'` para caractere; `NULL` (de stdio.h) só para ponteiros |
| Dev-C++ / Turbo C (`^Z`, int 16 bits, ponteiro "5 bytes") | ambiente antigo | gcc no terminal; `sizeof`; Ctrl-D no Linux |
| `'\xB1'` (quadrado da tabela estendida) | não portátil | `'#'` ou UTF-8 |
| malloc "retorna char *" + cast | desatualizado | `int *p = malloc(n * sizeof *p);` |
| `p = realloc(p, ...)` | vaza se falhar | ponteiro temporário |
| `char *s = "literal"` como forma preferida | literal é só leitura | `const char *s` ou `char s[] = "..."` |
| reiniciar o computador após acesso fora do array | mito de DOS/Windows 9x | hoje: segmentation fault; usar `-fsanitize=address` |

## Extras que não cabem no sumário
- Documentação padrão de função (ação/entrada/saída/suposições/algoritmo) — pode virar convenção do curso.
- "Raiz quadrada inteira" por divide-e-calcula-média (Newton com inteiros): para 42 → palpites 1, 21, 11, 7, 6
  (6² = 36 ≤ 42 < 49); condição reescrita com De Morgan — exemplo ótimo de laço com condição composta e
  suposição (x ≥ 0).
- Linhas de texto têm limite (a fonte cita 254 caracteres) — curiosidade.
- `memcpy` aparece no exemplo de malloc.
- Programa "agentes secretos" (arquivo + struct + menu) como projeto integrador.
