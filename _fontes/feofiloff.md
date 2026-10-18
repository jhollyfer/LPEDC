# Fichamento — Feofiloff, *Algoritmos em linguagem C*

- **Obra:** Paulo Feofiloff, *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier/Campus, 2009 (2ª impressão corrigida). Nasceu das notas de aula do IME-USP (www.ime.usp.br/~pf/algoritmos/).
- **Público original:** quem já programa um pouco em C (segundo semestre de computação). Os apêndices resumem a linguagem.
- **Avaliação geral:** é a melhor fonte que temos para **pensar antes de codar**. Quatro marcas
  que o LPEDC deve herdar: (1) **documentar o que a função faz** (não como faz); (2) **invariantes de laço**
  como explicação e prova; (3) **recursão** como ferramenta de primeira classe; (4) **elegância**:
  nada de casos especiais desnecessários, flags supérfluas ou código "esperto". O livro mostra
  quase sempre o **bom código ao lado de maus exemplos** (deselegante, ineficiente, errado), e isso
  rende exercícios ótimos do tipo "critique esta versão". Pontos fracos: o texto é muito enxuto
  (pouca analogia, poucas figuras no nosso arquivo), a eficiência é tratada só de forma intuitiva
  ("proporcional a n²"), não há notação O formal, não há bubble sort, hash, AVL implementada nem grafos
  além da BFS em matriz. Usa listas **com cabeça** como padrão e índices às vezes em 1..n (heap,
  enumeração, Boyer-Moore), o que pede adaptação.
- **Convenções do livro que vale adotar:** a notação `v[0..n-1]` para "o vetor com índices 0 a n-1";
  `v[p..r-1]` com extremo direito aberto em mergesort; nomes `e`, `m`, `d` (esquerda, meio,
  direita) na busca binária; a palavra **"célula"** para nó de lista.

---

## Princípios transversais (usar em todo o curso)

### Documentação = minimanual
- A documentação de uma função diz **o que entra, o que sai e qual a relação entre os dois**,
  mencionando **todos os parâmetros** e nenhuma variável interna. Não descreve o "como"
  (se percorre da esquerda para a direita, se é recursiva etc.).
- Analogia do livro (parafraseada): uma transportadora promete pegar seu pacote em São Paulo e
  entregá-lo no Rio no dia seguinte. Isso é *o que* ela faz. Se vai de caminhão, avião ou navio é
  problema interno dela. É exatamente a separação entre o `.h` (interface) e o `.c` (implementação).
- Escada de documentações ruins para o máximo de um vetor (bom exercício de "conserte a frase"):
  "devolve o máximo de um vetor" (vago) → "do vetor v" (não explica `n`) → "de v com n elementos"
  (é `v[0..n-1]` ou `v[1..n]`?) → "de v[0..n-1]" (esqueceu a restrição `n >= 1`) → versão correta:
  "recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1]".
- Detalhe fino: dizer "**um** elemento máximo" e não "**o** máximo", porque pode haver empate.
- Comentários dentro do corpo: praticamente só o **enunciado do invariante** merece estar lá.
  Comentários do tipo "j percorre o vetor" são lixo.

### Correção, eficiência, elegância (a "Computação anda sobre três pernas")
- **Correto:** cumpre o que a documentação promete. **Eficiente:** não desperdiça tempo (nem
  memória). **Elegante:** simples, limpo, sem tratar casos especiais à parte, sem variáveis
  supérfluas, sem truques.
- Lição: o código elegante quase sempre funciona **sozinho nos casos extremos** (vetor vazio,
  k = 0, k = n-1). Tratar `n == 0` com um `if` separado é sinal de que o laço foi mal pensado.

### Decisões de projeto explícitas
- Antes de codar, decidir e escrever: o que devolver quando não acha (−1? n?), qual o menor n
  aceito, se a lista tem cabeça, onde fica o topo da pilha etc. O livro trata isso como etapa do
  algoritmo, não como detalhe.

### Teste com conferência
- Vários exercícios pedem um **programa de teste que gera vetor aleatório e confere** o resultado
  com uma função ingênua (ex.: conferir Boyer-Moore com o algoritmo trivial; conferir se o
  mergesort deixou o vetor crescente). Ótimo hábito para o LPEDC.

---

### 0001-algoritmo
- **Conceitos-chave:** programa = implementação concreta de um algoritmo; "instância" = um
  exemplo concreto do problema (um conjunto de dados). Tamanho da instância (ex.: n).
- **Ideia de exemplo:** mostrar a mesma tarefa (máximo de um vetor) com documentação boa e ruim.

### 0006-primeiro-programa (leiaute — Apêndice A)
- **Conceitos-chave:** leiaute é para humanos; dois pilares: **espaços** na linha e **indentação**.
  Regras tipográficas de livro: espaço entre palavras (`while`, `=`, `<=` contam como palavras);
  espaço depois (não antes) de pontuação; espaço antes de abrir parêntese e depois de fechá-lo.
  Exceções: `x->seg`, `x[i]`, `x++` sem espaços. Pode-se colar o nome de **função** no parêntese
  (`f(9, v)`), mas `while`, `if`, `for`, `return`, `sizeof` não são funções.
- **Analogia:** "os espaços no código são como as pausas na música". `while(j < n)` "soa" como
  "enquantoj for menor que n".
- **Exercícios:** dar um trecho todo amontoado (uma função de separação do quicksort numa linha só)
  e pedir para reescrever com bom leiaute; comparar pares de linhas e dizer qual tem melhor leiaute.
  Ferramenta: `indent` (hoje também `clang-format`).

### 0004-binario e 0008-tipos-e-limites (Apêndice C)
- **Conceitos-chave:** byte = 8 bits = 256 valores. `unsigned int` com s bytes cobre 0..2^(8s)−1 e
  "dá a volta" (módulo 2^(8s)). `int` usa **complemento de dois**: sequência que começa com 1
  representa k − 2^(8s).
- **Boa explicação:** imaginar um computador de brinquedo com int de 4 bits: os valores formam um
  **relógio** de 16 posições; −8..7 para `int`, 0..15 para `unsigned`; 6+1 = 7, 6+2 = −8 (overflow),
  2*6 = −4. Desenhar o círculo é muito didático.
- **Pegadinhas:** `unsigned n = -1` vira o maior unsigned; `m - n` com unsigned m=2, n=3 vale −1 em
  aritmética int (no livro) — na prática moderna o resultado é um unsigned enorme se a expressão
  ficar unsigned (ver "Obsoleto").
- **Exercícios:** (a) com unsigned de 16 bits, por que `for (n = 0; n < 65536; n++)` nunca termina?
  (resposta: n nunca chega a 65536, volta a 0); (b) imprimir n², n³, ... até não caber em unsigned;
  (c) criticar a representação "sinal-magnitude" de 4 bits (duas representações do zero, soma mais
  complicada).
- **Representação texto vs binária:** −123 como caracteres '-','1','2','3' (4 bytes 45 49 50 51) vs
  complemento de dois em 2 bytes. Daí arquivo-texto × arquivo binário; `atoi` converte.

### 0012-aritmetica (C.3)
- Divisão inteira trunca; com negativos, `-9/2` dá −4 (truncamento para zero), que **não** é o piso
  matemático (−5). Ótima pegadinha para quem usa `/2` em índices.

### 0017-relacionais / 0018-logicos (J.2)
- Expressão booleana vale 0 ou 1; avaliação da esquerda para a direita com **curto-circuito**.
- **Pegadinha clássica (usar em vários módulos):** `if (j <= 99 && v[j] < x)` está certo;
  `if (v[j] < x && j <= 99)` pode ler fora do vetor. Aparece de novo na busca em vetor
  (`k >= 0 && v[k] != x`) e na busca em lista (`p != NULL && p->conteudo != x`).

### 0014-atribuicao (J.1)
- Toda expressão tem valor; `y = 3*x + 4` vale 301 e tem o efeito colateral de mudar y.
  `x++` vale o valor antigo, `++x` o novo. Operador vírgula: `t = a, a = b, b = t` faz a troca.
- **Uso idiomático explicado pelo livro:** `x = f[s++]` (remove da fila), `p[t++] = y` (empilha),
  `x = p[--t]` (desempilha). Bom para mostrar ++/-- "a serviço" de uma estrutura.

### 0031-aleatorios (Apêndice I)
- `rand()` dá 0..RAND_MAX; semente com `srand(time(NULL))`; sem semente o sistema usa uma fixa.
- **Inteiro aleatório em a..b** (método do livro, parafraseado): converter `rand()` em real
  x em [0,1) dividindo por (RAND_MAX + 1.0); multiplicar por (b − a + 1) e truncar; somar a.
- **Pegadinhas/exercícios:** por que `rand() % 2` para cara/coroa pode ser ruim (bits baixos de
  geradores antigos alternam par/ímpar); por que `RAND_MAX * 5 / 6` pode estourar int; o que muda
  se dividir por `RAND_MAX` em vez de `RAND_MAX + 1` (o valor b fica raríssimo / pode passar de b).

### 0036-pilha-de-chamadas (6.5)
- **Explicação boa:** cada chamada cria um "espaço de trabalho" (parâmetros + locais) que é
  empilhado; ao terminar é descartado e o de baixo é reativado no ponto exato onde parou. Recursão
  é só o caso em que F e G são a mesma função.
- **Exemplo do livro (reescrever com outros valores):** main chama F(111, 222, 444), F chama
  G(i, j) que devolve 333, F devolve 333 + 444 = 777. Marcar no código os pontos /*1*/../*4*/ e
  desenhar a pilha em cada ponto.
- **Exercício:** simular com pilha explícita uma função recursiva simples (soma dos positivos de
  x[1..n]).

### 0037-recursao
- **Método (parafraseado):** se a instância é pequena, resolva direto; senão, reduza a uma instância
  menor do **mesmo** problema, resolva-a recursivamente e volte à original.
- **Roteiro de verificação de função recursiva (excelente, usar como "checklist"):** (1) escreva o
  que a função faz; (2) verifique o caso pequeno; (3) suponha que a função acerta para tudo que é
  menor que n e verifique que então ela acerta para n. É indução sem o nome.
- **Exemplo-base:** máximo de v[0..n-1]: se n = 1, é v[0]; senão é o maior entre o máximo de
  v[0..n-2] e v[n-1]. Segunda versão: recursão sobre v[i..n-1] com uma **função-embalagem** que
  chama a recursiva com i = 0.
- **Generalizar o problema:** muitas recursões precisam de parâmetros extras (i, e, d, prefixo).
  O papel deles deve estar na documentação. Frases como "a primeira chamada deve ser com i = 0" são
  proibidas como documentação.
- **Pegadinhas (exercícios "critique"):**
  - caso base redundante (tratar n == 2 além de n == 1) — deselegante;
  - chamar a recursão **duas vezes** com o mesmo argumento (`if (max(v,n-1) < v[n-1]) ... else return max(v,n-1)`) — vira exponencial;
  - recursão que **não diminui** a instância: `XX(n/3 + 1)` com n = 1 chama XX(1) para sempre;
  - `if (n = 1)` (atribuição) dentro de uma função recursiva de rastreio;
  - caso base em n == 1 quando o problema faz sentido para n == 0 (busca recursiva "feia").
- **Exercícios com resposta:**
  - X(n) = n se n ∈ {1,2}; senão X(n−1) + n·X(n−2). X(4)? → X(3) = 2 + 3·1 = 5; X(4) = 5 + 4·2 = **13**.
  - soma recursiva dos positivos de v[0..n-1]; faz sentido n = 0? (sim, soma 0).
  - soma dos dígitos (132 → 6); piso de log2 n recursivo; max − min recursivo.

### 0038-recursao-na-pratica
- **Fibonacci:** a versão recursiva ingênua recalcula F(2) várias vezes para F(4); pedir a árvore de
  chamadas indentada de F(5) (o livro dá a de F(3): F(3) → F(2) → F(1), F(0); depois F(1)).
- **Euclides recursivo:** mdc(m, n) = m se n = 0; senão mdc(n, m % n).
- **Exponenciação rápida:** k^n = (k^(n/2))² vezes k se n ímpar; no máximo ≈ 2·log2 n
  multiplicações (contra n−1 da ingênua). Ótimo exemplo ligando recursão e log.
- **Exercício de rastreio:** função ff que imprime sua chamada com recuo proporcional à
  profundidade — rodar com (7, 0). (Usar com o `=`/`==` corrigido ou como pegadinha.)

### 0039-modulos / 0079-tad (visão do Feofiloff)
- O livro não monta TADs completos, mas dá o fundamento: **documentação = interface (.h)**,
  **código = implementação (.c)**. O Apêndice K mostra amostras comentadas de `stdlib.h`,
  `stdio.h`, `string.h`, `limits.h`, `time.h` — bom material para mostrar "um .h é um contrato".
- Exercício útil: "uma fila é um pacote com três objetos (vetor e dois índices); escreva as funções
  sem variáveis globais" — prepara a passagem para struct + TAD.

### 0042-vetores / 0043-vetores-e-funcoes (Capítulo 3)
- **Vetor** = sequência de objetos do mesmo tipo em posições consecutivas. Espaço `v[N]`, conteúdo
  `v[0..n-1]`, com 0 ≤ n ≤ N; vazio se n = 0, cheio se n = N.
- **Busca** (decisão: devolver −1 se não achar): varrer **do fim para o começo**, `k = n-1` e
  decrementar enquanto `k >= 0 && v[k] != x`. Funciona com n = 0 sem `if` especial.
  **Invariante:** x é diferente de todos os elementos de v[k+1..n-1].
- **Maus exemplos (exercício "classifique: deselegante / ineficiente / errado"):**
  - flag `achou` desnecessária (deselegante);
  - `if (n == 0) return -1;` antes do laço (deselegante);
  - `for` que continua depois de achar guardando `sol` (ineficiente);
  - `while (v[k] != x && k >= 0)` (errado: lê v[-1]);
  - `while (k < n && v[k] != x) k++; if (v[k] == x)` (errado: lê v[n] quando não acha);
  - `for (...) if (v[k]==x) sol=k; else sol=-1;` (errado: só vale o último).
- **Sentinela:** se a decisão for devolver n quando não acha, colocar x em v[n] elimina a
  comparação `k < n` a cada passo (exige espaço extra).
- **Remoção** do índice k (0 ≤ k < n): deslocar v[k+1..n-1] uma casa para a esquerda e devolver
  n−1. Uso: `n = Remove(51, v, n);`. Funciona para k = 0 e k = n−1 sem caso especial.
  Pegadinhas: laço de trás para frente (`j = n-2` descendo) **estraga** o vetor; zerar v[n-1] é inútil;
  `if (k < n-1)` antes do laço é supérfluo.
- **Inserção** de y entre k−1 e k (0 ≤ k ≤ n, e n < N): deslocar v[k..n-1] uma casa para a direita
  **começando do fim**, pôr y em v[k], devolver n+1.
- **Remover todos os zeros** (busca + remoção), algoritmo de dois índices: i marca o fim da parte
  "limpa", j varre; se v[j] != 0, copia para v[i] e avança i. **Invariantes:** i ≤ j e v[0..i-1] é
  v[0..j-1] original sem zeros. Linear e sem vetor auxiliar.
  Maus exemplos: copiar para um vetor auxiliar fixo `w[1000]`; remover cada zero deslocando o resto
  (quadrático); versão com `v[i-z] = v[i]` que acessa v[−1].
- **Ideias de exemplos:** vetor 111, 222, 0, 0, 333, 0, 444, 0 → 111, 222, 333, 444 (n passa de 8 a 4).
  Remoção do índice 3 em 000..555 → 000, 111, 222, 444, 555.
- **Versões recursivas** de busca, remoção, inserção e remove-zeros: bons exercícios de 0037.

### 0045-caracteres (Apêndice B)
- `char` e `unsigned char` são duas leituras dos mesmos 8 bits (−128..127 e 0..255). Tabela ASCII
  para 0..127; acima disso depende (ISO 8859-1 no livro). Em ISO-Latin1, char negativo c tem o mesmo
  símbolo que unsigned char c+256 → acentuadas ficam "antes" das sem acento em `char`.
- Aritmética com char é feita em `int` (255 + 2 = 257), mas **atribuição** a char é módulo 256.
- **Pegadinha ótima:** `for (unsigned char u = 0; u < 256; u++)` e `for (char c = 0; c < 128; c++)`
  **nunca terminam**. Já `for (c = 'a'; c <= 'z'; c++)` funciona.
- Exercícios: diferença entre 'O', '0' e '\0'; decodificar 70 65 67 73 76 32 ... como texto;
  `isspace` recebe valor de unsigned char ou EOF.

### 0046-strings (Apêndice G)
- String = segmento do vetor de char até o **primeiro** '\0'; comprimento não conta o '\0';
  endereço da string = endereço do 1º caractere.
- Implementações simples de `strlen`, `strcpy` (inclui o '\0') e `strcmp` (compara como unsigned
  char; devolve negativo/0/positivo). Ordem lexicográfica = ordem de dicionário; prefixo próprio
  vem antes.
- **Pegadinhas/exercícios:** "A" × 'A'; "MN\0P" tem comprimento 2; `char s[10]; s = "ABC";` não
  compila (vetor não é atribuível); comparar strings com `a < b` compara **endereços**; `*a < *b`
  compara só a primeira letra. Diferença entre `char a[8]` + strcpy, malloc + strcpy e `a = "abacate"`.
- Exercícios: contar vogais; colapsar espaços repetidos; converter string binária em número; imitar
  `atoi`; extrair s[i..j] sem alocar.

### 0049..0052 ponteiros (Apêndice D)
- Memória = sequência de bytes numerados; `&i` é o endereço; ponteiro guarda endereço; `NULL` é
  inválido; `*p` é o objeto apontado.
- **Troca:** versão errada com `int i, int j` (recebe cópias) e certa com `int *p, int *q` +
  `troca(&i, &j)`. Pegadinha: `int *temp; *temp = *i;` usa ponteiro não inicializado.
- **Vetores:** o compilador cria a ilusão de que elementos consecutivos distam 1: `v + i` ≡ `&v[i]`.
  Vetor declarado é "ponteiro constante".
- Exercícios: `hm(t, &h, &m)` minutos → horas e minutos; `mm(v, n, &min, &max)`; se int tem 8 bytes
  e v[0] está em 55000, quanto vale v+3? (55024); sentido de `*&i` e `&&i`.

### 0054-ponteiro-para-ponteiro (soluções 4.4.2, 4.5.3, 15.3.1)
- **Achado valioso:** remover/inserir em lista **sem cabeça** com um parâmetro `célula **pp`:
  a mesma função remove a primeira célula (`Remv(&lst)`) ou a sucessora de p (`Remv(&p->seg)`).
  Idem inserir. E inserir em BST com `árvore *eer` evita o `if` da árvore vazia.
- Precedência: `&p->seg` é `&(p->seg)`.

### 0058..0062 memória dinâmica (Apêndice F)
- `malloc` devolve `void *`; usar `sizeof`; **verificar NULL** (o livro omite por brevidade, mas
  manda o aluno verificar sempre). `free` só no bloco inteiro alocado por malloc. Depois de `free`,
  atribuir NULL ao ponteiro (proteção contra **ponteiro solto**, explorável por hackers).
- Vetor de tamanho lido em tempo de execução: ler n e alocar n·sizeof(int) (o livro diz que ANSI
  C não aceita `int v[n]`).
- **Matriz dinâmica** como vetor de m ponteiros, cada um apontando para um vetor de n ints;
  elemento A[i][j].
- Exercício: ler n e depois n inteiros e imprimi-los ao contrário, sem limite para n.

### 0064 / 0067 structs (Apêndice E)
- Registro com nome (`struct dma {int dia, mes, ano;}`), operador `.`; ponteiro para struct e
  `p->mes` ≡ `(*p).mes`; `*p.dia` é outra coisa (`*(p.dia)`).
- Exercícios: dias entre duas datas; FimEvento(data, duração); **TAD racional** com p/q, q > 0 e
  mdc(p, q) = 1: criar, negar, somar, multiplicar, dividir (ótimo para 0079).

### 0065-typedef (J.3)
- **Truque para ler typedef:** escreva a declaração de uma variável do tipo desejado e ponha
  `typedef` na frente — o nome da variável vira nome de tipo.
- Tipo de dado = conjunto de valores + operações (definição que conecta com TAD).

### 0040-preprocessador (J.4)
- `#include` copia o arquivo; `#define` substitui texto. Exemplo do pré-processamento de um
  programa com `MAX` e `EXIT_SUCCESS`.

### 0072 / 0074 arquivos e argumentos (Apêndice H)
- `fopen` devolve `FILE *` ou NULL; `fscanf` devolve quantos itens leu (usar para detectar fim);
  `stdin`/`stdout` são arquivos já abertos.
- **Lição de projeto (getc):** `getc` devolve **int**, não char, porque precisa de um valor fora
  dos 256 caracteres para sinalizar fim: EOF. "Devolver um objeto de um superconjunto do que
  realmente interessa" é truque geral. **Pegadinha:** guardar o retorno de getc em `char` —
  arquivo vazio ou byte 255 quebram o programa.
- argv: `prog a bb 999` → argc = 4, argv[0] = "prog". Exemplo: média dos números passados na linha
  de comando com `atoi`.
- Exercícios: copiar arquivo; remover comentários de um .c; contar ocorrências de cada caractere
  (inspirado no `wc`).

### 0076-eficiencia / 0077-big-o
- **Conceito do livro:** "consumo de tempo proporcional a f(n) no pior caso", com unidade de tempo
  que depende da máquina, não de n. Conta-se a operação dominante (comparações).
- **Explicação boa com números (reaproveitar em tabela):**
  - linear: n → 1000n multiplica o tempo por 1000;
  - quadrático: 2n → 4t; 10n → 100t;
  - log: dobrar n acrescenta **uma** unidade; 1024n acrescenta só 10 unidades ("log transforma
    multiplicação em soma");
  - n log n (mergesort): para 16n, menos de 32t; para 128n, menos de 352t, contra 256t e 16384t
    dos quadráticos.
- Soma 1 + 2 + ... + (n−1) = n(n−1)/2 ≈ n²/2 (inserção, seleção).
- **Observação honesta:** constantes importam para n pequeno — mergesort só ganha dos elementares
  a partir de certo n.
- Exercícios: tabela de ⌊log2 n⌋ para n = 10..10^5; se a busca binária leva t em n elementos, quanto
  leva em n²? (≈ 2t).

### 0078-invariantes ⭐ (o grande diferencial do livro)
- **Definição:** relação entre os valores das variáveis que vale **no início de cada iteração**
  (imediatamente antes do teste do laço). Serve para explicar e para provar por indução.
- **Roteiro de prova (usar como molde de exercício):** (1) vale antes da 1ª iteração; (2) se vale no
  início de uma iteração, vale no início da seguinte; (3) no início da última (quando o teste
  falha), o invariante + a condição de parada implicam o resultado; (4) o laço termina (alguma
  quantidade diminui).
- **Catálogo de invariantes do livro (base para exercícios "qual é o invariante?"):**
  - Max: x é um máximo de v[0..j-1].
  - soma: x é a soma de v[0..i-1].
  - Busca do fim para o começo: x ≠ v[k+1..n-1].
  - RemoveZeros: i ≤ j e v[0..i-1] = v[0..j-1] original sem zeros.
  - BuscaERemove em lista: q == p->seg (q um passo à frente de p).
  - Busca sequencial em vetor crescente: v[j-1] < x.
  - Busca binária: v[e] < x ≤ v[d] (imaginando v[−1] = −∞ e v[n] = +∞).
  - Inserção: v[0..j-1] é crescente e v é permutação do original.
  - Seleção: v[0..i-1] crescente e v[i-1] ≤ todo elemento de v[i..n-1] ("pequenos à esquerda,
    grandes à direita").
  - Separa (quicksort): v[p..j-1] ≤ c < v[j..k-1], v[r] = c, p ≤ j ≤ k ≤ r.
  - Heapsort (2ª fase): v[1..m] é max-heap, v[1..m] ≤ v[m+1..n] e v[m+1..n] crescente.
  - Parênteses: s é bem-formada sse p[0..t-1] seguido de s[i..] é bem-formada.
  - BFS (distâncias): fila ordenada por distância, com no máximo dois valores consecutivos k e k+1.
- **Exercício projeto:** função lg(n) = ⌊log2 n⌋ iterativa, com invariante enunciado, testada
  contra `log` da math.h.

### 0080-vetor-dinamico
- O livro **não** trata realloc/vetor que cresce; contribui com inserção/remoção em vetor
  (Cap. 3) e com a ideia de pacote (vetor + n). Usar o Cap. 3 como as operações do TAD lista
  sequencial; a parte de crescer vem da PUC.

### 0081-lista-encadeada ⭐
- **Conceitos-chave:** lista = sequência de registros (células), cada um com um conteúdo e o
  endereço da seguinte (NULL na última). Células consecutivas **não** ficam em posições
  consecutivas da memória. O endereço da lista é o endereço da 1ª célula; "p é uma lista" é atalho
  verbal.
- **Natureza recursiva:** toda lista p é NULL ou p->seg é uma lista. Muitas funções ficam mais
  simples recursivas.
- **Com cabeça × sem cabeça:** com cabeça, a 1ª célula é só marcador (conteúdo irrelevante); vazia
  quando lst->seg == NULL; pode ser criada como variável local ou via malloc. Sem cabeça: vazia
  quando lst == NULL. O livro prefere **com cabeça** porque toda inserção/remoção vira "depois de
  p" e nunca muda o ponteiro da lista. (O LPEDC pode apresentar as duas; a PUC usa sem cabeça.)
- **Imprimir:** for (p = lst; p != NULL; p = p->seg); para lista com cabeça, começar em lst->seg.
- **Exercício teórico (bom para quem gosta de definição):** uma coleção de células é lista sse
  (1) a sucessora de cada uma está na coleção, (2) cada uma tem no máximo uma antecessora,
  (3) exatamente uma não tem antecessora, (4) não há ciclos.
- **Liberação:** exercício 4.7.10 (aplicar free em todas).
- **Exercícios do 4.7 (todos em versão com/sem cabeça e iterativa/recursiva):** vetor → lista
  (dica da solução: percorrer o vetor **de trás para frente** inserindo no início); lista → vetor;
  cópia; comparação; concatenação; contagem; **ponto médio sem contar n** (dois ponteiros: um anda
  1, outro anda 2 — técnica "lebre e tartaruga"); remover a k-ésima; inserir após a k-ésima;
  **inverter só mexendo nos ponteiros**; projeto: contar ocorrências de cada palavra de um texto.

### 0082-lista-busca-remocao
- **Busca** (com cabeça): p = lst->seg; avança enquanto `p != NULL && p->conteudo != x`; devolve
  p (NULL se não achou). Correta com lista vazia. Versão recursiva olha lst->seg.
- **Remoção — decisão de projeto importante:** em vez de receber a célula a remover, receber a
  **anterior** p e remover p->seg (exige p e p->seg não nulos). Tempo constante, sem copiar nada,
  ao contrário do vetor.
- **Busca seguida de remoção:** dois ponteiros p (anterior) e q (atual), com invariante q == p->seg;
  ao achar, p->seg = q->seg e free(q).
- **Pegadinhas:** inverter a ordem do teste (`p->conteudo != x && p != NULL`) → acesso a NULL;
  flag `achou` + avançar p depois de achar (devolve a célula errada); função Remove com parâmetro
  inútil e `if` que trata o último à parte; **não dá para remover a própria célula p numa lista
  simples sem saber a anterior**.
- **Exercícios:** remover todas as ocorrências de x (iterativo e recursivo); remover a célula de
  conteúdo mínimo; versão sem cabeça (resposta do livro: devolver o novo início, ou usar `**`).

### 0083-lista-ordenada
- **Inserção:** nova célula **depois** de p (aloca, nova->seg = p->seg, p->seg = nova). Funciona no
  fim da lista; com cabeça, inserir após a cabeça = inserir no início. Inserir *antes* de p numa lista
  simples: "não há como" (resposta do livro ao 4.5.2) — bom exercício de reflexão.
- **Pegadinha forte:** usar uma `célula nova;` **local** em vez de malloc — a célula some quando a
  função termina e a lista aponta para lixo.
- **BuscaEInsere:** inserir y antes da 1ª célula com x, ou no fim se não houver x; mesmo esquema
  p/q.
- **Lista crescente:** buscar parando quando o conteúdo passa de x (exercício 4.3.5). Inserção
  ordenada = BuscaEInsere com critério "primeiro maior que y".
- **Ordenar lista por inserção** (solução 8.4.4 do livro): rearranja só ponteiros; com cabeça não
  precisa devolver nada.
- **Intercalar duas listas crescentes sem alocar** (9.1.10) e **mergesort de lista** (9.4.3) —
  exercícios de "juntando tudo".

### 0084-lista-dupla / 0085-lista-circular
- Só em 4.8: circular (última aponta para a primeira, com ou sem cabeça; sem cabeça "primeira" e
  "última" perdem o sentido); dupla (cada célula com anterior e seguinte).
- **Checklist de perguntas para qualquer variante de lista (ótimo como roteiro de exercício):**
  quando está vazia? como remover p? como remover a seguinte a p? a anterior a p? como inserir
  entre p e a anterior? entre p e a seguinte?
- **Problema de Josephus:** n pessoas em círculo numeradas 1..n, elimina-se cada m-ésima; quem
  sobra? Excelente aplicação de lista circular (ex.: n = 7, m = 3 → sobrevivente 4).
- Fila em lista circular com cabeça (5.4.2): basta o endereço da cabeça; 1º elemento na 2ª célula,
  último na célula anterior à cabeça.

### 0087-pilha
- **Definição:** sequência dinâmica em que se remove sempre o **último** inserido (LIFO). Vetor
  p[0..N-1], ocupado p[0..t-1], topo em t−1; vazia t = 0, cheia t = N.
- Idiomas: desempilhar `x = p[--t]`; consultar `p[t-1]`; empilhar `p[t++] = y`.
- Empilhar em pilha cheia = indício de **mau planejamento lógico** do programa.
- **Exercícios:** convenção alternativa p[0..t] (escrever push/pop); inverter as letras de cada
  palavra mantendo a ordem ("AMU MEGASNEM ATERCES" → "UMA MENSAGEM SECRETA"); **permutações
  obtidas empilhando 1,2,3,4 em ordem e desempilhando quando quiser** (E,E,D,E,D,D,E,D imprime
  2,3,1,4). Quais das 24 são possíveis? (14; as impossíveis contêm o padrão "3..1..2", ex.: 3,1,2,4
  ou 4,1,2,3).

### 0088-pilha-encadeada
- Lista **com cabeça**, topo na **2ª célula** (logo após a cabeça), não no fim. Empilhar = inserir
  após a cabeça; desempilhar = remover após a cabeça. Vazia se cabeça->seg == NULL.
- Exercícios: versão sem cabeça (pilha = endereço da 1ª célula); refazer BemFormada e infixa →
  posfixa com pilha encadeada.

### 0089-pilha-aplicacoes ⭐
- **Parênteses e chaves bem-formados:** percorrer a string; abre → empilha; `)` exige topo `(`,
  `}` exige topo `{`, senão malformada; no fim, bem-formada sse pilha vazia. A pilha nunca passa de
  strlen(s). Exemplo: `( { ) }` é malformada.
  Exercícios: funciona com 0, 1 e 2 caracteres?; provar o invariante; acrescentar colchetes.
  Pegadinha do próprio livro: esqueceu `free(p)` antes dos returns "para não obscurecer".
- **Infixa → posfixa (supondo expressão correta, variáveis de uma letra, + - * /, tudo entre
  parênteses):** letra vai direto para a saída; `(` empilha; `)` desempilha para a saída até achar
  `(` (descartado); `+`/`-` desempilha até `(` e depois empilha a si; `*`/`/` desempilha até `(`,
  `+` ou `-` e depois empilha a si.
  Rastreio pronto: (A*(B*C+D)) → A B C * D + *.
  Tabela de exemplos (refazer com letras diferentes): (A+B*C) → A B C * +;
  (A*(B+C)/D-E) → A B C + * D / E -.
- **Valor de expressão posfixa** com variáveis A..Z num vetor val (cuidado com divisão por zero).
- Exercícios: aplicar a (A+B)*D+E/(F+A*D)+C (resposta: A B + D * E F A D * + / + C +); altura
  máxima da pilha; versão sem o parêntese externo; versão que detecta expressão incorreta.

### 0090-fila
- **Definição:** remove-se sempre o que está há **mais** tempo (FIFO). Vetor f[0..N-1], ocupado
  f[s..t-1]; vazia s == t; cheia t == N (versão não circular). Remover `x = f[s++]`; inserir
  `f[t++] = y`. Inserir em fila cheia = **transbordamento**.
- **Circular:** s e t em 0..N-1, sem supor s ≤ t; vazia t == s; **cheia quando (t+1) % N == s**
  — a posição t fica sempre livre para distinguir cheia de vazia (capacidade N−1). Avanço:
  `t++; if (t == N) t = 0;`.
- Exercício: com a convenção f[s..t] (fechada), escrever remover/inserir; funções tamanho,
  remove e insere da fila circular sem globais.

### 0091-fila-encadeada
- Lista **sem cabeça**, 1º da fila na 1ª célula, último na última; dois ponteiros s e t; vazia
  s = t = NULL (um é NULL sse o outro é).
- Remover recebe `**es, **et` porque pode ter de mudar ambos (se a fila esvaziar, t vira NULL).
  Inserir trata fila vazia (s e t passam a apontar a nova).
- Exercícios: fila em lista com cabeça; em lista circular com cabeça (só o ponteiro da cabeça);
  em lista dupla sem cabeça.

### 0115-bfs (5.2 — "distâncias em uma rede") ⭐
- **Cenário:** n cidades, estradas de mão única em matriz A (A[x][y] = 1 se há estrada x→y).
  Distância de o a x = menor nº de estradas. d[x] = −1 representa ∞.
- **Algoritmo (descrever passo a passo):** d[] = −1; d[o] = 0; fila f com o; enquanto a fila não
  esvazia: tira x; para cada y com A[x][y] = 1 e d[y] == −1, faz d[y] = d[x] + 1 e põe y na fila.
  Cada cidade entra no máximo uma vez → vetor de n posições basta (não precisa ser circular).
- **Invariantes:** f[0..s-1] já saíram; as distâncias na fila são não decrescentes e diferem no
  máximo de 1; toda estrada que sai de f[0..s-1] chega em f[0..t-1].
- **Exercício:** formiga num tabuleiro 10×10 com casas bloqueadas (−1) indo de (1,1) a (10,10),
  movendo-se para cima/baixo/esquerda/direita — labirinto via BFS.
- (Para 0114: a matriz de adjacência aparece aqui naturalmente.)

### 0094-busca-sequencial / 0095-busca-binaria ⭐
- **Reformulação inteligente:** em vez de "onde x está", perguntar **"onde x deveria estar"**:
  achar j em 0..n com v[j-1] < x ≤ v[j] (com v[−1] = −∞ e v[n] = +∞ imaginários). Daí resolver o
  problema original é comparar x com v[j].
  Exemplo: n = 13; x = 555 → j = 4; x = 1000 → j = 13; x = 110 ou 111 → j = 0.
- **Sequencial em vetor crescente:** avança enquanto `j < n && v[j] < x`. Tempo ∝ n.
- **Binária (versão do livro):** e = −1, d = n; enquanto e < d − 1: m = (e+d)/2; se v[m] < x então
  e = m senão d = m; devolve d. **Invariante:** v[e] < x ≤ v[d]. Termina porque d − e − 1 diminui
  (e < m < d). Iterações ≈ log2 n.
- Versão recursiva com função-embalagem: BuscaBinR(x, e, d, v) documentada com a pré-condição
  v[e] < x ≤ v[d]; profundidade ≈ log2 n.
- **Pegadinhas (exercícios "o que acontece se..."):** trocar `e < d-1` por `e < d` (loop infinito);
  trocar `v[m] < x` por `<=` (muda a especificação: passa a achar o primeiro maior); `e = m+1` ou
  `d = m-1` na versão de e = −1 (pode pular a resposta); **overflow em (e+d)/2** para n perto de
  INT_MAX → usar `e + (d-e)/2` (só adia o problema); tratar v[n-1] < x e x ≤ v[0] à parte
  (deselegante).
- **Variantes corretas para comparar (7.6):** e = 0, d = n, `while (e < d)`, e = m+1 ou d = m
  (quase tão elegante); e = 0, d = n−1, `while (e <= d)` com e = m+1/d = m−1, devolve d+1.
- **Rastreio:** v[i] = i, n = 9, x = 3; n = 14, x = 7; n = 15, x = 7. Com n = 16, quais m possíveis
  em cada iteração?
- **Exercícios de variação:** devolver j com v[j-1] ≤ x < v[j]; vetor decrescente; versão "devolve
  índice ou −1" (resposta do livro: o mesmo laço com `if (v[m] == x) return m;`); vetor de strings
  em ordem lexicográfica; vetor de structs (aluno por número); **achar i com v[i] = i em vetor
  estritamente crescente com no máximo ⌊log2 n⌋ comparações**; máximo por divisão e conquista
  (não é mais rápido; profundidade log n).
- Citação de Manber usada pelo livro: busca binária está para os algoritmos como a roda para a
  mecânica (simples, elegante, imensamente importante).

### 0097-selection-sort
- **Ideia:** escolher o menor, depois o segundo menor... Para i de 0 a n−2: achar o índice min do
  menor de v[i..n-1] e trocar com v[i].
- **Invariantes:** permutação; v[0..i-1] crescente; v[i-1] ≤ todos de v[i..n-1] → os i primeiros já
  estão na posição definitiva. ≈ n²/2 comparações sempre.
- Pegadinhas: `for (i = 1` pula a posição 0; `i < n` em vez de `n-1` só faz uma iteração inútil;
  `<=` no lugar de `<` na escolha do min mantém a ordenação mas afeta estabilidade.
- **Estável?** Não (a troca de longa distância pula elementos iguais). Ex.: 2a 2b 1 → 1 2b 2a.

### 0098-insertion-sort
- **Ideia (baralho):** para j de 1 a n−1: guardar x = v[j]; deslocar para a direita os elementos
  de v[0..j-1] maiores que x; pôr x no buraco.
- **Invariantes:** permutação do original; v[0..j-1] crescente. Pior caso ≈ n²/2 comparações
  (vetor decrescente); melhor caso linear (já ordenado).
- **Pegadinhas:** trocar `v[i] > x` por `>=` continua ordenando mas **perde a estabilidade**;
  `v[i] = x` em vez de `v[i+1] = x`; implementação com trocas sucessivas (3 atribuições por passo,
  deselegante); procurar a posição da esquerda para a direita e depois deslocar (correto mas
  deselegante/menos eficiente).
- Exercícios: invariante alternativo (v[j+1..n-1] crescente, varrendo da direita); **busca binária
  para achar a posição** (economiza comparações mas não movimentações — continua n²); ordem
  estritamente crescente (impossível com repetidos — resposta do livro); versão recursiva;
  ordenar strings, structs, linhas de um arquivo; ordenar lista encadeada.

### 0099-merge-sort ⭐
- **Intercalação:** dados v[p..q-1] e v[q..r-1] crescentes, deixar v[p..r-1] crescente usando
  vetor auxiliar w de r−p posições: enquanto as duas metades têm elementos, copia o menor
  (com `<=` para estabilidade); depois copia a sobra; depois copia w de volta. Tempo ∝ r − p.
- **Mergesort(p, r, v):** se p < r − 1: q = (p+r)/2; ordena v[p..q-1]; ordena v[q..r-1]; intercala.
  Chamada para o vetor todo: Mergesort(0, n, v). Intervalo **semiaberto** [p, r).
- **Desempenho:** ≈ log2 n rodadas, cada uma ∝ n → n log n. Não é in-place (vetor auxiliar).
- **Árvore de chamadas** para v[1..4]: (1,5) → (1,3) → (1,2),(2,3); (3,5) → (3,4),(4,5). Pedir
  a de v[1..5].
- **Pegadinhas:** `if (p < r)` em vez de `p < r-1` → recursão infinita com 1 elemento;
  q = (p+r−1)/2 pode gerar metade vazia e loop; chamar Intercala sem ordenar a 1ª metade; malloc/free
  a cada intercalação (exercício: alocar uma vez só); overflow em (p+r)/2; na intercalação trocar
  `else` por `if (v[i] > v[j])` quebra; versão que esquece de checar `j < r` lê fora.
- **Estável?** Sim, se a intercalação usar `<=` (com `<` deixa de ser).
- **Versão iterativa (bottom-up):** b = 1, 2, 4, ...; intercalar blocos [p, p+b) e [p+b, min(p+2b, n)).
- Exercícios: ordem decrescente; strings; **mergesort natural** (partir em segmentos crescentes
  maximais, ex.: 1 2 3 | 0 2 4 6 | 4 5 6 7 8 9); mergesort de lista encadeada sem alocar células;
  comparar experimentalmente com inserção e seleção em vetores aleatórios.

### 0100-quick-sort ⭐
- **Problema da separação** (formulado de propósito de forma vaga): pequenos à esquerda, grandes
  à direita, sem vetor auxiliar e sem lado vazio. Formulação usada: achar j com
  v[p..j-1] ≤ v[j] < v[j+1..r].
- **Separa (estilo Lomuto/CLRS):** pivô c = v[r]; j = p; para k de p a r−1: se v[k] ≤ c, troca v[j]
  com v[k] e j++; no fim troca v[j] com v[r]; devolve j. Comparar com RemoveZeros (mesma ideia de
  dois índices!). Tempo ∝ número de elementos.
- **Quicksort(p, r, v):** se p < r: j = Separa; ordena v[p..j-1] e v[j+1..r]. Chamada:
  Quicksort(0, n−1, v) — intervalo **fechado**, diferente do mergesort.
- **Desempenho:** se j cai sempre perto do meio, ≈ n log n comparações; **vetor já ordenado (ou
  decrescente) dá ≈ n²**; média n log n.
- **Altura da pilha:** no pior caso chega a n (pode estourar a memória). Remédio: recursão só na
  **parte menor** e `while` para a maior (eliminação da recursão de cauda) → altura ≤ log2 n.
- **Quicksort aleatorizado:** trocar v[p] (ou v[r]) com um elemento sorteado antes de separar.
- **Pegadinhas:** `if (p != r)` em vez de `p < r` (pode não parar quando p > r); chamar
  Quicksort(p, j) ou (j, r) incluindo o pivô (não para); separação com vetor auxiliar fixo
  `w[1000]`; versões de separação de livros diferentes (Gries, CLRS 1ª ed. com índices que se
  cruzam, Sedgewick com pivô do meio) resolvem **formulações diferentes** — trocar uma pela outra
  sem ajustar as chamadas recursivas quebra o algoritmo.
- **Estável?** Não.
- Exercícios: aplicar Separa a vetor todo igual, só com dois valores, crescente, decrescente;
  árvore de chamadas para 99 55 33 77 (dada: (1,4) → (1,2) → (1,0),(2,2); (4,4)) e para
  55 44 22 11 66 33; versão iterativa com pilhas de (p, r); rearranjar negativos/nulos à esquerda e
  positivos à direita (aquecimento de separação); quicksort de lista.

### 0101-comparando (estabilidade, qsort)
- **Estabilidade:** não altera a ordem relativa de iguais. **Exemplo do livro (excelente):** datas
  (dia, mês) já ordenadas por dia; ordenar por mês com algoritmo estável dá ordem cronológica; com
  instável, não necessariamente. Isso motiva "ordenar por chave secundária e depois pela primária".
- Resumo a montar: inserção (estável, n² pior, ótimo para quase ordenado), seleção (instável, n²
  sempre), mergesort (estável, n log n, memória extra), quicksort (instável, n log n médio, n² pior,
  in-place), heapsort (instável, n log n, in-place).
- `qsort` da stdlib: vetor, nº de elementos, tamanho, função de comparação (o livro só pede para
  "se familiarizar").

### 0102-arvores / 0103-arvore-binaria
- **Nó** com conteúdo, esq e dir; filho, pai, folha (sem filhos). Definição formal de árvore
  binária como conjunto de nós sem ciclos, cada nó com no máximo um pai, exatamente uma raiz e
  filhos esquerdo/direito distintos ("o programador raramente pensa nisso porque constrói nó a nó").
- **Folclore usado como abertura:** as árvores da computação crescem para baixo — raiz no ar,
  folhas enterradas no chão.
- **Natureza recursiva:** r é NULL ou r->esq e r->dir são árvores. Caminho, comprimento,
  descendente, subárvore. Endereço da árvore = endereço da raiz; `typedef nó *árvore`.
- **Varredura e-r-d (in-order), r-e-d (pré), e-d-r (pós).** e-r-d recursiva é imediata.
  **Versão iterativa com pilha explícita:** pilha de nós + um nó x "pronto para empilhar"; a pilha
  é um "roteiro do que falta fazer". Variante equivalente: desce pela esquerda empilhando; desempilha,
  imprime, vai para a direita.
- **Altura** = comprimento do caminho mais longo até uma folha; árvore vazia tem altura −1; um nó
  tem altura 0. ⌊log2 n⌋ ≤ h < n. Altura recursiva = 1 + max(alturas das subárvores).
- **Profundidade** = distância até a raiz (raiz = 0).
- **Nós com campo pai** e **nó seguinte em e-r-d:** se x tem filho direito, o seguinte é o nó mais
  à esquerda da subárvore direita; senão, sobe enquanto x for filho direito e devolve o pai.
- **Exercícios:** contar nós; imprimir folhas em e-r-d; primeiro/último nó em e-r-d (descer pela
  esquerda); preencher campos pai; profundidade de um nó; imprimir a árvore com recuo proporcional à
  profundidade usando '-' para NULL; árvore de **expressão** e relação e-r-d ↔ infixa, e-d-r ↔
  posfixa; relação entre árvores e sequências bem-formadas de parênteses; desenhar árvore de 17 nós
  com altura mínima (altura 4).

### 0104-bst-busca-insercao
- **Definição:** para todo nó X, chaves da subárvore esquerda ≤ X.chave ≤ chaves da direita;
  equivalente: a varredura e-r-d dá chaves em ordem crescente. "BST generaliza lista crescente assim
  como árvore binária generaliza lista."
- **Pegadinha (exercício 15.1.2):** exigir só X.esq->chave ≤ X.chave ≤ X.dir->chave (pai × filhos
  diretos) **não** basta para ser BST.
- **Busca:** recursiva (se r é NULL ou tem a chave, devolve r; senão desce pela esquerda ou direita)
  ou iterativa. Tempo ∝ altura; log2 n se balanceada.
- **Inserção do livro:** o nó novo é criado antes (chave, esq = dir = NULL) e vira folha; a função
  devolve a raiz (que só muda se a árvore era vazia). Versões alternativas: recursiva
  (`r->esq = InsereR(r->esq, novo)`) e com ponteiro para ponteiro.
- Exercícios: mínimo e máximo; chave seguinte; **vetor crescente → BST balanceada** (raiz = meio,
  recursão nas metades); BST → vetor crescente; relação BST × busca binária.

### 0105-bst-remocao
- **Remover a raiz:** se não tem filho esquerdo, a nova raiz é o direito; senão, achar q = nó
  **anterior** em e-r-d (mais à direita da subárvore esquerda) e seu pai p; se p ≠ r, p->dir recebe
  q->esq e q->esq recebe r->esq; q->dir recebe r->dir; liberar r; devolver q.
  **Detalhe:** move o **nó** q (troca ponteiros), não copia a chave (a PUC copia).
- Remover um filho de x: `x->esq = RemoveRaiz(x->esq)` (idem dir).
- Exercício ótimo: inserir 50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45, 36 numa BST vazia, desenhar e
  remover 30 (o anterior de 30 é 25, que sobe; 20 continua filho esquerdo).

### 0106-avl
- Só a definição: balanceada no sentido AVL se, em cada nó, as alturas das subárvores diferem de no
  máximo 1. Exercício: decidir se uma árvore é AVL **visitando cada nó uma vez** (calcular altura e
  balanceamento juntos, devolvendo −2/ou flag quando falha). Rotações não aparecem (remete a
  Sedgewick e CLRS). Observação útil: inserções/remoções simples desbalanceiam.

### 0107-heap ⭐
- **Max-heap** em v[1..m] (índices a partir de 1!): v[⌊f/2⌋] ≥ v[f] para f = 2..m. Visão de árvore:
  raiz 1, pai de f é f/2, filhos de p são 2p e 2p+1. Todo pai é pelo menos tão valioso quanto os
  filhos; v[1] é um máximo. Nº de camadas = 1 + ⌊log2 m⌋; mais da metade dos elementos fica na
  última camada.
- Observação do livro: a palavra **heap** também nomeia a área de alocação dinâmica — **não tem
  relação** (pegadinha de vocabulário para 0058).
- **Inserção (sobe):** pôr o novo em v[m+1]; enquanto f > 1 e pai < filho, troca e sobe. ≤ log2(m+1).
- **Sacode (desce) em quase-heap** (só a raiz pode estar fora do lugar): f = 2; enquanto f ≤ m: se
  f < m e v[f] < v[f+1], f++ (escolhe o **filho mais valioso**); se pai ≥ v[f], para; senão troca e
  f *= 2. ≤ log2 m. Otimização: guardar a raiz em t e só "abrir buraco" (menos atribuições).
- **Pegadinha (10.3.3):** descer trocando com o primeiro filho que for maior, sem escolher o maior
  dos dois, quebra o heap.
- Exercícios: vetor decrescente é heap (a recíproca é falsa); 161 41 101 141 71 91 31 21 81 17 16 é
  heap? (não: 41 < 141); função "é max-heap?"; construir heap de vetor arbitrário com InsereEmHeap;
  por que "ordenar decrescente para fazer heap" é ineficiente; heap representado por árvore
  encadeada; trocar dois elementos mantém heap?

### 0108-heapsort
- **Duas fases:** (1) transformar v[1..n] em max-heap (inserindo v[2], v[3], ...); (2) para m de n
  até 2: trocar v[1] com v[m] e sacudir v[1..m-1]. Não usa vetor auxiliar.
- **Invariantes da 2ª fase:** permutação; v[1..m] heap; v[1..m] ≤ v[m+1..n]; v[m+1..n] crescente.
- Desempenho ≤ soma de logs ≈ n log n.
- Exercícios: ordenar 16 15 ... 4; ordem decrescente (usar min-heap); strings; por que "girar o
  vetor" a cada passo (10.4.2) não funciona.

---

## Obsoleto / evitar (ao reaproveitar o Feofiloff)
- **Acentos em identificadores** (`célula`, `conteúdo`, `Máximo`, `InteiroAleatório`): o próprio
  livro avisa que é licença tipográfica. No LPEDC, identificadores sempre em ASCII.
- **"ANSI C não permite `int v[n]`":** desde C99 existem VLAs (e C11 as tornou opcionais). Ainda assim
  recomendar malloc para tamanhos grandes/desconhecidos.
- **Divisão de negativos "na maioria dos computadores":** desde C99 o truncamento para zero é
  **garantido**.
- **Amostras de .h simplificadas:** `NULL 0`, `RAND_MAX 32767`, `void *malloc(unsigned int)`,
  `unsigned int strlen`, `long time(long *)`, `qsort` com `void *` sem `const` — hoje é `size_t`,
  `time_t`, `const void *`. RAND_MAX costuma ser 2147483647 no gcc/glibc.
- **`malloc` sem checar NULL e `free` omitido** nos exemplos (assumido pelo livro "para não cansar").
  No LPEDC: sempre checar e liberar; usar Valgrind/ASan.
- **Vetor de pilha fixo `nó *p[100]`** na varredura iterativa; mostrar com pilha dinâmica.
- **Mistura de convenções de índice:** heap e enumeração em 1..n, quicksort fechado [p, r],
  mergesort semiaberto [p, r). No curso, padronizar e avisar.
- **Tabela ISO 8859-1:** hoje o padrão de fato é **UTF-8** (acentos ocupam 2 bytes; `strlen("ã")` é
  2). Tratar acentos como caracteres de 1 byte é armadilha moderna.
- **Atribuições `m - n` com unsigned "valendo −1":** em C moderno, `unsigned - unsigned` é unsigned
  (dá um número enorme); só vira −1 se convertido para int. Ajustar o exemplo.
- `return EXIT_SUCCESS` está ok; `int main(int numargs, char *arg[])` é válido mas use `argc/argv`.

## Extras que não cabem no sumário
- **Enumeração (Cap. 12):** gerar as 2^n subsequências de 1..n.
  - Ordem lexicográfica iterativa usando o vetor s[1..k] **como pilha** e uma sentinela s[0] = 0:
    se s[k] < n, empilha s[k] + 1; senão desempilha e incrementa o novo topo.
    Lista para n = 4: 1; 1 2; 1 2 3; 1 2 3 4; 1 2 4; 1 3; 1 3 4; 1 4; 2; 2 3; 2 3 4; 2 4; 3; 3 4; 4.
  - Versão recursiva SseqR(s, k, m, n): imprime prefixo + m; depois "inclui m" (recursão com k+1) e
    "não inclui m" (recursão com k). A documentação precisa explicar o papel do prefixo s[1..k] —
    exemplo perfeito de **generalizar o problema** para recursão.
  - Ordem lexicográfica especial (mais longas primeiro): 1 2 3 4; 1 2 3; 1 2 4; 1 2; ...
  - Exercícios: combinações k a k (solução no livro com poda m ≤ n − k + j + 1); permutações (n!);
    desarranjos (9 de 1..4); partições em m blocos; **subset sum** com cheques (p = 61, 62, 63, 64,
    T = 125 → {1,4} ou {2,3}); 8 rainhas; passeio do cavalo; ordem "militar". Serve como extra do
    módulo de recursão (backtracking).
- **Busca de palavra em texto (Cap. 13):** contar ocorrências de a[1..m] em b[1..n].
  - Trivial: para cada k de m a n, comparar da direita para a esquerda; pior caso m·n
    (palavra "*xxxxx" em texto "xxx...x").
  - **Boyer-Moore 1 (caractere ruim):** tabela T1[c] = distância da última ocorrência de c em a até o
    fim (m se não ocorre); após cada tentativa, saltar T1[b[k+1]] + 1. Exemplo do livro: palavra
    BCBA. Pior caso ainda m·n, mas raro.
  - **Boyer-Moore 2 (bom sufixo):** tabela T2[i] pelo maior "índice bom"; pré-processamento m² no
    código simples; caso médio linear. BM3 = máximo dos dois saltos; com T2 aperfeiçoada fica m + n.
  - Projeto: implementar BM3 e conferir contra o trivial. Pode entrar como extra de strings/vetores.
- **Problema de Josephus** (lista circular) e **permutações por pilha** (empilha 1..n) — desafios.
- **Contador de base 100/256 em lista encadeada** para contar além de UINT_MAX (exercício C.1.2) —
  bom "aritmética de precisão arbitrária" introdutória.
- **CWEB / programação literária (Knuth)** e citações de Dijkstra sobre programa como "metade de uma
  conjectura" — material de motivação para o módulo de documentação/invariantes.
- **Medição de tempo com `clock()` / CLOCKS_PER_SEC** (K.6), repetindo o bloco 100 vezes — útil para
  o projeto "comparar ordenações na prática" (0101).
- **Anagramas:** maior classe de palavras equivalentes num dicionário (ordenar as letras de cada
  palavra como "assinatura" e depois ordenar a lista) — projeto de juntando-tudo de ordenação/hash.
