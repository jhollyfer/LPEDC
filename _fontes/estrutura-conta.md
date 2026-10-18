# Fichamento: Estrutura de Dados com Algoritmos e C (Laureano)

- **Título:** Estrutura de Dados com Algoritmos e C
- **Autor:** Marcos Laureano (Brasport, 2008), em português do Brasil
- **Lido:** 3078 linhas, por completo. As linhas 1-20 trazem um trecho cifrado (pedido de contribuição com dados bancários): foi ignorado e não aparece aqui.
- **Capítulos:**
  1. dados homogêneos e heterogêneos (vetor, matriz, ponteiros, struct)
  2. uso de memória (malloc/calloc/realloc/free, ponteiro para ponteiro, agenda)
  3. pilha
  4. fila
  5. recursividade
  6. lista
  7. pesquisa
  8. ordenação
  9. árvores binárias

## Avaliação geral

Livro curto e direto, pensado para cursos tecnológicos. Os pontos fortes são **as figuras e os exemplos visuais**
(expansão e contração do fatorial, memória com endereços numerados para ponteiro e ponteiro para ponteiro, vetor
crescendo em memória fragmentada), **os exercícios de pilha, fila e recursão**, bons de reaproveitar, e uma
**árvore binária de busca completa em C** (inserção recursiva com ponteiro para ponteiro, remoção pelo antecessor,
intervalo, sucessor, impressão "deitada"). Os pontos fracos são sérios: **muitos bugs no código** (vários de memória),
afirmações imprecisas ("vetor é ponteiro", "matriz é vetor de ponteiros", "lista tem acesso randômico") e
práticas obsoletas (`gets`, `fflush(stdin)`, `getch`, `%d` para ponteiro, notação húngara). **Use como fonte de
ideias e de pegadinhas ("ache o erro"), nunca como código-modelo.** Não cobre arquivos, strings em profundidade,
módulos, hash, heap, AVL nem grafos.

---

### 0007-variaveis (tipo de dado)
- **Conceitos-chave:** um tipo de dado é um conjunto de valores mais as operações válidas sobre eles. Tipos atômicos (inteiro, real, caractere, lógico) contra compostos/estruturados. Estruturas homogêneas (vetor, matriz) contra heterogêneas (registro/struct).
- **Explicação boa:** uma estrutura de dados é uma forma organizada de guardar informação, quase sempre inspirada em algo do mundo real (pilha de pratos, fila de banco, árvore genealógica).
- **Pegadinha:** "somar duas letras" não faz sentido como conceito, mas em C compila (soma os códigos ASCII). É um gancho para 0045.

### 0042-vetores
- **Conceitos-chave:** um vetor tem tamanho fixo, um único tipo e células contíguas. Inserir ou excluir no meio obriga a mover elementos. Endereço do elemento i: `início + i * sizeof(tipo)` (o livro usa a fórmula começando em 1, com (n−1)).
- **Exemplos:**
  - vetor de notas em que NOTA[4] = 4.6;
  - ler 5 inteiros e calcular a média com `(float) soma / TAMANHO` (é preciso o cast);
  - `a[2]++` incrementa o conteúdo da posição 2, não o índice.
- **Ideia de exercício (do livro, reescrito):** escrever `imprime_elemento(int *v, int i)` que acessa o elemento só pela fórmula de endereço, sem usar `[]`.

### 0044-matrizes
- **Conceitos-chave:** uma matriz pode ser guardada linha por linha (é o caso do C) ou coluna por coluna. Endereço: `início + (i*C + j) * sizeof(tipo)`. **Regra prática boa:** um laço `for` por dimensão.
- **Exemplos:**
  - determinante 2×2: `a[0][0]*a[1][1] - a[0][1]*a[1][0]`;
  - matriz 4D preenchida com `i+j+k+l` e quatro laços aninhados;
  - matriz de strings 3×6 em que `M[3]` é a palavra da linha inteira (ex.: "DONALD").
- **Pegadinhas:** no livro, a afirmação "em C, uma matriz é na prática um vetor de ponteiros" é **falsa** para `int m[2][3]`, que é contígua. Só vale para `int**` alocado linha a linha (ver 0061). Também há bugs de digitação: usa `matriz` em vez de `aMatriz` e escreve `For`.
- **Ideia de exercício:** função que recebe `int m[][2]` e imprime m[i][j] calculando o endereço à mão. Depois, a mesma coisa com `int **`, para mostrar que as duas não são equivalentes.

### 0049-memoria / 0050-ponteiros
- **Conceitos-chave:** `&` lê-se "endereço de"; `*` lê-se "valor no endereço de". Declarar um ponteiro reserva espaço **para o endereço**, não para o dado apontado. Antes de usar, é preciso apontar para algo válido.
- **Explicação excelente (o gaveteiro numerado):** um ponteiro fica na "gaveta 1", o `malloc` devolve a "gaveta 4" e o valor 20 é guardado lá. Então `&p` vale 1, `p` vale 4 e `*p` vale 20. Repetindo com `int **pp` na gaveta 6: `&pp` vale 6, `pp` vale 1, `*pp` vale 4 e `**pp` vale 20. Vale a pena redesenhar isso para o curso.
- **Pegadinhas:**
  - o livro imprime endereço com `%d`/`%ld`. O correto é `%p` com `(void*)p`;
  - não confundir o `*` da declaração e da desreferência com a multiplicação;
  - o livro usa números como `27121975` só como valor de exemplo (sem significado; dá para trocar).
- **Ideia de exercício:** desenhar a memória (gaveteiro) para `int x=7, *p=&x, **pp=&p; **pp = 9;` e dizer quanto vale x. Resposta: 9.

### 0051-passagem-por-referencia
- **Exemplo bom:** `soma(int a, int b, int *res)` imprime o endereço de `res` dentro da função e o de `resultado` no `main`. Os dois são iguais, o que mostra que a função escreve na variável do chamador.
- **Ideia de exercício:** função `minmax(int v[], int n, int *min, int *max)`.

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** `p++` avança `sizeof(*p)` bytes: com `int*`, 4 bytes; com `char*`, 1 byte (o programa imprime os dois endereços antes e depois). O nome do vetor é o endereço do primeiro elemento: `t == &t[0]`, `*(t+i) == t[i]`.
- **Pegadinhas:**
  - o livro diz que "vetores nada mais são do que ponteiros com alocação estática". É impreciso: um vetor **decai** para ponteiro, mas não é um ponteiro (`sizeof` é diferente e não se pode atribuir ao nome do vetor);
  - **bug grave e didático:** `char t[5]; strcpy(t, "abcde");` estoura o vetor, porque "abcde" ocupa 6 bytes por causa do `\0`. É um ótimo "ache o erro" para 0046/0062.

### 0054-ponteiro-para-ponteiro
- **Conceitos-chave:** para uma função **alocar** um ponteiro do chamador, passe `&ptr` e receba `T **`. A regra mnemônica do livro: cada nível de indireção que a função precisa alterar acrescenta um `*`. Dentro da função, use `(*p)[i]` (os parênteses são obrigatórios).
- **Exemplo:** `void aloca(int ***p, int lin, int col)` aloca uma matriz e é chamada com `aloca(&m, 4, 5)`; depois `m[i][k] = i + k`.
- **Pegadinhas (do código do livro):**
  - `int *pi; *pi = malloc(...)` desreferencia um ponteiro não inicializado (o certo é `pi = malloc(...)`);
  - em `aloca`, o laço vai até `y` em vez de `x`, e o vetor de linhas é alocado com `sizeof(int)` em vez de `sizeof(int*)`;
  - a matriz nunca é liberada.

### 0058-pilha-e-heap
- **Conceitos-chave:** alocação estática é decidida na compilação e dura até o fim do bloco ou do programa; alocação dinâmica acontece na execução, reservando e liberando sob demanda. Em Java a estrutura cresce "sozinha"; em C o programador cuida de tudo.
- **Ideia de exemplo:** um vetor dinâmico precisa saber o tamanho na hora de alocar, e realocar o vetor inteiro custa caro; uma estrutura encadeada aloca **por elemento**.

### 0059-malloc-free / 0060-calloc-realloc
- **Conceitos-chave:** `malloc(bytes)`; `calloc(qtd, tam)`, que zera a memória; `realloc(p, novo)`, que pode mover o bloco; `free(p)`, só com ponteiros vindos dessas funções. Teste sempre se veio `NULL`.
- **Exemplos:**
  - ler N inteiros num vetor alocado com `malloc`, depois perguntar quantos acrescentar e usar `realloc` para N+M;
  - struct `ST_DADOS` (nome, salário, data de nascimento aninhada) alocada com `malloc` e acessada com `->`.
- **Pegadinhas:**
  - `malloc(10 * sizeof(int*))` para um `int*` usa o `sizeof` errado. Prefira `malloc(n * sizeof *p)`;
  - `p = realloc(p, ...)` **perde o bloco original se falhar**. Use um temporário;
  - os protótipos do livro usam `int` para tamanhos (o correto é `size_t`);
  - o livro manda fazer cast do retorno do `malloc`, o que é desnecessário em C;
  - `scanf("%s", p->nome)` sem limite de tamanho.

### 0061-matriz-dinamica
- **Conceitos-chave:** `int **m = malloc(L * sizeof(int*));` e depois, para cada linha, `m[i] = malloc(C * sizeof(int));`. `m[i][j]` equivale a `*(*(m+i)+j)`. Libere na **ordem inversa**: primeiro as linhas, depois o vetor de ponteiros.
- **Exemplo bom de design:** quatro funções, `int **aloca(l,c)`, `leitura(m,l,c)`, `imprime(m,l,c)` e `libera(m,l,c)`, usadas para duas matrizes 3×2 e 2×3.
- **Pegadinha grave (se repete em três programas do livro):** `p = calloc(i, sizeof(int))` para o vetor de **ponteiros**. Em 64 bits, `sizeof(int)` vale 4 e `sizeof(int*)` vale 8: aloca a metade e corrompe o heap. É um excelente "ache o erro" com valgrind/ASan.

### 0062-erros-de-memoria
- **Catálogo de erros reais do livro, para exercícios "ache o erro":**
  - `strcpy` em `char[5]` com uma string de 5 letras (falta espaço para o `\0`);
  - ponteiro não inicializado desreferenciado;
  - `sizeof(int)` no lugar de `sizeof(int*)`;
  - `p = realloc(p, ...)` sem guardar o ponteiro antigo;
  - lista que sempre aloca um nó extra e não libera o último (vazamento);
  - `excluir_menor` da árvore, que desliga o nó sem dar `free`;
  - `delete` da lista, que faz `free(p)` em vez de `free(*p)`;
  - `maior`/`menor` da árvore, que leem `arvore->info` antes de testar NULL;
  - a árvore nunca é liberada ao sair.

### 0064-struct / 0066-vetor-de-structs / 0067-ponteiro-para-struct
- **Conceitos-chave:** registro = campos de tipos diferentes, acessados por nome (o vetor é acessado por índice). Struct aninhada (data de nascimento dentro de funcionário); vetor de structs; `p->campo`.
- **Exemplos:**
  - registro de funcionário: nome[40], data de nascimento {dia, mês, ano}, departamento[10], salário;
  - ler nome e idade de 5 pessoas num vetor de structs e listar.
- **Três formas equivalentes de acessar o campo do elemento i (na agenda):** `(p+i)->nome`, `(*(p+i)).email` e `p[i].telefone`. É ótimo para fixar a equivalência.
- **Pegadinhas:**
  - `scanf("%s", &sDados[i].sNome)`: o `&` sobra, porque o vetor já é um endereço;
  - `return;` dentro de `int main`;
  - variável de índice não declarada.

### 0080-vetor-dinamico
- **Exemplo-projeto (agenda em memória):**
  - `typedef struct { char nome[40]; char email[40]; int telefone; } AGENDA;`;
  - um vetor de structs que **cresce com `realloc` a cada inclusão**, passando `&pAgenda` e `&n` para a função de alocação;
  - menu com inclusão, alteração, consulta, exclusão e pesquisa;
  - antes de listar, ordena com quicksort por nome;
  - a busca usa `strncmp(nome, chave, strlen(chave))` (casa por prefixo);
  - **a exclusão copia o último elemento para o buraco e diminui o tamanho**: O(1), mas desfaz a ordem;
  - a pesquisa navega com "Próximo?" de forma circular.
- **Melhorias para o curso:**
  - **dobrar a capacidade** em vez de fazer `realloc` a cada item (um `realloc` por item dá custo total O(n²));
  - guardar o telefone como string (como `int` ele estoura e perde o zero à esquerda);
  - trocar `gets`/`getch`/`fflush(stdin)` por `fgets`.
- **Ideia de exercício:** comparar as duas exclusões (copiar o último contra deslocar todos), em custo e em efeito na ordem.

### 0081-lista-encadeada / 0082-lista-busca-remocao
- **Conceitos-chave:** cada nó guarda os dados mais o endereço do próximo. A struct aponta para o próprio tipo. Guarda-se um ponteiro para o início; o último nó aponta para NULL (ou para o primeiro, na lista circular); lista sem nós = lista vazia. Uma lista simples serve de base para pilha ou fila dinâmicas.
- **Analogia excelente (fragmentação):** imagine 90 posições de memória com um vetor ocupando de 01 a 12. Ele só pode crescer até 15, que é o maior bloco livre contíguo. Uma lista ocupa 13, 14 e 15, e depois continua em 17, 18 e 19, aproveitando os "buracos".
- **Exemplo do livro:** 25 nós com `numero = i` e `string = "Numero %02d"`, percorridos e liberados guardando o próximo **antes** do `free`.
- **Operações citadas:** insert (num ponto), add (no fim), delete, info, next e last (anterior).
- **Pegadinhas:**
  - o livro diz que "a lista pode ser acessada de maneira randômica". **Errado**: o acesso é sequencial;
  - o livro diz que "pilha e fila têm tamanho fixo". Também errado: depende da implementação;
  - o programa 6.1 sempre cria um nó extra vazio e não libera o último.
- **Ideia de exercício:** reescrever o 6.1 sem o nó extra (com `inicio == NULL` como lista vazia) e sem vazamento.

### 0084-lista-dupla
- **Conceitos-chave:** ponteiros `next` e `last` (anterior), o que permite andar nos dois sentidos. O livro também justifica a lista dupla por "reconstruir a lista se uma ponta se perder por falha de hardware" (argumento datado).
- **Exemplos:**
  - lista dupla com 25 nós percorrida de trás para frente;
  - conjunto de funções `add`, `insert`, `delete`, `next`, `last` e `info` com `struct NOPTR`, e um `main` que insere 0..9, anda nos dois sentidos, insere 99 e 88 e remove.
- **Pegadinhas:**
  - `insert` testa `p == NULL` quando deveria testar `*p`;
  - `delete` faz `free(p)` e `(p)->next` (errado) e não trata a remoção do primeiro nó;
  - a lista é controlada só por um ponteiro "atual" (o início se perde). Melhor manter cabeça e cauda.
- **Ideias de exercícios (do livro):**
  - fazer `next`/`last` tratarem corretamente o começo e o fim;
  - fazer `insert` chamar `add` quando a inserção for no fim.

### 0085-lista-circular
- **Conceitos-chave:** em uma lista circular, o próximo do último é o primeiro (e o anterior do primeiro é o último): um anel.
- **Ideia de exercício (do livro):** lista circular com 20 elementos e funções para tratá-la. Sugestão de cenário: jogo da batata quente / problema de Josephus.

### 0087-pilha
- **Conceitos-chave:** LIFO; operações `push`, `pop`, `size`, `stackpop` (lê o topo sem remover, o *peek*) e `empty`. Usada em compiladores e no sistema operacional. O cuidado principal é controlar o fim, por isso existe `empty`.
- **Sequência para trace:** a partir de uma pilha com D, E, F: push(H), push(I), pop → I, pop → H, pop → F, pop → E, pop → D, push(D), push(E).
- **Duas versões do livro:**
  - (a) globais `int pilha[20], pos = 0;` sem nenhuma verificação;
  - (b) `struct pilha { int topo; int itens[100]; }` com **topo = -1 para vazia**, `push` verificando `topo == MAX-1` ("estouro"), `pop` verificando vazia e `size = topo + 1`. O `main` faz **4 pops com 3 itens**, e o quarto mostra "Pilha vazia": um bom exemplo de underflow.
- **Pegadinhas:**
  - na versão (a), `stacktop` devolve `pilha[pos]`, que é a posição vazia (o certo é `pos-1`);
  - a inicialização `x.topo = -1` fica solta no `main` (melhor uma função `inicializa`).
- **Para o curso:** contrastar a convenção topo = -1 (aponta para o último) com topo = 0 (aponta para a primeira posição livre).
- **Ideias de exercícios (do livro, reescritos):**
  1. inverter uma pilha usando só uma estrutura auxiliar, tratando a pilha vazia;
  2. trocar o topo com a base usando uma pilha auxiliar;
  3. deixar os pares na base e os ímpares no topo usando duas pilhas auxiliares (ex.: entrada 1 2 3 4 5, com 5 no topo, deve ficar com os pares 2 e 4 embaixo e os ímpares por cima).

### 0088-pilha-encadeada
- Aparece como exercício: "crie uma pilha usando lista". Observação para o curso: o livro diz que a pilha "cresce e diminui no fim", mas numa lista simples **o topo deve ficar no início** para push e pop serem O(1).

### 0090-fila
- **Conceitos-chave:** FIFO, como fila de banco, pedágio ou restaurante. Operações `enqueue`/`insert` (no fim), `dequeue`/`remove` (no início), `empty`, `size` e `front`. Remover de uma fila vazia é *underflow*.
- **Sequência para trace:** dequeue → A, enqueue(F), dequeue → B, enqueue(G).
- **Fila linear (programa 4.1):** cada `dequeue` desloca todos os elementos uma posição. Funciona, mas custa O(n) por remoção (com 1000 ou 2000 itens fica caro).
- **Fila circular:** "dobrar o vetor num círculo"; `front = rear = -1` no início; o índice volta a 0 ao passar do fim. O livro traz um trace com D, E, F, G, H, I e K dando a volta no vetor.
- **Pegadinhas (bugs reais, bons para "ache o erro"):**
  - na fila linear, `size` devolve `rear + 1` (o certo é `rear - front`, aqui igual a `rear`);
  - na circular, `size` devolve `rear + front` quando os índices deram a volta (o certo é `MAX - front + rear`);
  - `front()` lê `itens[front+1]` sem dar a volta;
  - `enqueue` avança `rear` antes de detectar o estouro;
  - é preferível escrever `rear = (rear + 1) % MAX` em vez de `if`.
- **Ideias de exercícios (do livro):**
  1. adiar o deslocamento até `rear` chegar ao fim do vetor, e então deslocar tudo de uma vez. Discutir vantagens (menos deslocamentos) e desvantagens (picos de custo) e reescrever `enqueue`, `dequeue` e `size`;
  2. uma fila de pilhas.

### 0091-fila-encadeada
- Aparece como exercício: fila sobre lista (cresce no fim e diminui na frente, com ponteiros de início e fim).

### 0037-recursao
- **Conceitos-chave:** algo definido em termos de si mesmo, com um caso base e um passo recursivo. Na computação é **obrigatório** ter uma condição de parada (a memória é finita). Cada chamada empilha parâmetros e variáveis locais novos; o código da função não é copiado.
- **Analogias boas:**
  - *ancestral*: os pais de uma pessoa são ancestrais dela (caso base); os pais de um ancestral também são (passo);
  - *números naturais*: 0 é natural, e o sucessor de um natural é natural.
- **Explicação visual excelente:** a **expansão e contração** de `fatorial(6)`: `6 * f(5)`, depois `6 * 5 * f(4)`, ..., até `6*5*4*3*2*1`, e então a volta multiplicando até 720. Dá para colocar ao lado da tabela iterativa (t, f) = (1,1), (2,2), (3,6), (4,24), (5,120), (6,720).
- **Número triangular:** 1, 3, 6, 10, 15, 21, 28; T(n) = n + T(n−1) = n(n+1)/2. O 5º vale 5+4+3+2+1 = 15 (o livro desenha bolinhas em triângulo). Há versão iterativa (com `while`) e recursiva.
- **Lista de casos base do livro (bom resumo):** fatorial 0! = 1; triangular n = 1; Fibonacci fib(1) = fib(2) = 1; Euclides n = 0; Hanói com 1 disco.
- **Vantagens e custos:** código mais claro, porém mais lento, com risco de estourar a pilha. Evite a recursão múltipla (Fibonacci).
- **Pegadinha:** os códigos do livro de fatorial (`n==0||n==1`) e de triangular (`n==1`) entram em recursão infinita com n negativo ou 0. Proteja com `n <= 1`.
- **Ideias de exercícios (do livro, reescritos):**
  1. dizer o que calcula `f(n) = n + f(n-1)`, com `f(0) = 0`, e escrever a versão iterativa (resposta: a soma de 1 a n, o número triangular);
  2. máximo, mínimo, soma, produto e média de um vetor, nas versões iterativa e recursiva;
  3. palíndromo recursivo `int palindromo(char *s, int ini, int fim)` com "seres", "arara", "ama" e "A torre da derrota" (para a frase, ignorar espaços e maiúsculas);
  4. Ackermann: a(0,n) = n+1; a(m,0) = a(m−1,1); a(m,n) = a(m−1, a(m,n−1)), só com valores pequenos (ex.: a(2,3) = 9).

### 0038-recursao-na-pratica
- **Fibonacci:** a história dos casais de coelhos; 1, 1, 2, 3, 5, 8, 13, 21, 34. A versão iterativa usa três variáveis e a recursiva faz duas chamadas. Para fib(5), calcula fib(4) 1 vez, fib(3) 2 vezes, fib(2) 3 vezes e fib(1) 2 vezes (há também uma figura da árvore para o 7º termo). Pegadinha: o texto define "fib(n) = n se n ≤ 2", o que contradiz o código (fib(2) = 1).
- **Euclides:**
  - em passos: m, n, r = m % n; se r for 0, o MDC é n; senão m recebe n e n recebe r;
  - iterativo: `while (m % n != 0)`;
  - recursivo: `if (n == 0) return m; return mdc(n, m % n);`;
  - por subtrações: 60−36 = 24; 36−24 = 12; 24−12 = 12; 12 = 12, então MDC = 12;
  - valores prontos: mdc(60,36) = 12 e mdc(36,24) = 12.
- **Hanói:**
  - a lenda do templo de Benares (64 discos de ouro) e Édouard Lucas (1883);
  - solução: N−1 discos para o pino auxiliar, o maior para o destino, os N−1 para o destino;
  - contagem de movimentos sem recursão dupla: `h(n) = 2*h(n-1) + 1`, que dá 2^n − 1 (3 discos: 7; 7 discos: 127; 15 discos: 32767; 64 discos: 18446744073709551615, uns 585 bilhões de anos a 1 movimento por segundo);
  - programa `hanoi(n, origem, destino, ajuda)` que imprime "Mova o disco k de X para Y".
- **Ideia de exercício:** prever a lista de movimentos de `hanoi(3, 'A', 'B', 'C')` (7 linhas) antes de rodar.

### 0094-busca-sequencial
- **Conceitos-chave:** busca sequencial em dados desordenados (também funciona em ordenados); devolve o índice ou -1. Média de (n+1)/2 comparações.
- **Ideia ótima e pouco vista (frequência de acesso):** com as entradas em ordem de frequência A = 0,5; B = 0,3; C = 0,15; D = 0,05; E = 0,03, a média é 1×0,5 + 2×0,3 + 3×0,15 + 4×0,05 + 5×0,03 = 1,9 comparações, contra 3 com a ordem aleatória. A heurística **mover para a frente** a cada acesso aproxima esse ganho. Atenção: as frequências do livro somam 1,03; no curso, use por exemplo E = 0,00 ou D = 0,02.
- **Pegadinha:** o livro usa `register int t` (obsoleto).
- **Ideia de exercício:** simular "mover para a frente" com os acessos C, C, A, C, B e mostrar o vetor depois de cada busca.

### 0095-busca-binaria
- **Exemplo:** procurar 4 em 1..9: meio 5 > 4, então fica com a metade esquerda; meio 3 < 4, então fica com a direita; acha o 4. O custo é log₂ n. Há uma figura da busca do 34.
- **Pegadinha:** a função do livro se chama `binário`, e acento em identificador não é portável (era inválido em C89).
- **Ideias de exercícios (do livro):** média de comparações para 15, 127, 32767 e 35215 elementos. Respostas: na sequencial (n+1)/2 = 8, 64, 16384 e 17608; na binária, no pior caso, 4, 7, 15 e 16. Depois, gerar vetores aleatórios e conferir na prática.

### 0096-bubble-sort
- **Trace pronto:** `10 9 7 13 5`. A 1ª varredura dá `9 7 10 5 13` (o maior já está no lugar); a 2ª dá `7 9 5 10 13`. São necessárias n−1 varreduras.
- **Melhoria:** uma flag `troca` permite parar quando uma passada não troca nada (melhor caso O(n)).
- **Pegadinhas:**
  - as tabelas do livro varrem da esquerda para a direita, mas o código varre da direita para a esquerda (confunde o aluno);
  - as fórmulas de custo estão truncadas no texto;
  - o livro chama o bubble de "uma das piores ordenações já concebidas" (é verdade para dados grandes; ainda serve para ensinar).
- **Ideias de exercícios (do livro):** fazer o código refletir o algoritmo; bolha oscilante (bidirecional, *shaker*).

### 0097-selection-sort
- **Trace pronto:** `13 7 5 1 4` → `1 7 5 13 4` → `1 4 5 13 7` → (sem troca) → `1 4 5 7 13`. Comparações: n(n−1)/2 (o livro escreve "= n²", o que é impreciso).
- **Pegadinha grave:** no programa 8.3 a troca ficou **fora do laço externo** (fechamento de chaves errado), então o vetor não é ordenado. Além disso, o texto diz que o programa "implementa a inserção". É um ótimo "ache o erro".

### 0098-insertion-sort
- **Analogia:** organizar as cartas na mão, como no pôquer.
- **Trace pronto:** `13 7 5 1 4` → `7 13 5 1 4` → `5 7 13 1 4` → `1 5 7 13 4` → `1 4 5 7 13`.
- **Código correto no livro:** guarda o elemento em `aux`, desloca enquanto `j >= 0 && aux < v[j]` e grava em `v[j+1]`. É bom para listas pequenas ou quase ordenadas.

### 0099-merge-sort
- **Conceitos-chave:** dividir, ordenar cada metade recursivamente e intercalar. Custo n log n em **todos** os casos; a desvantagem é o vetor auxiliar do mesmo tamanho.
- **Exemplos:** `{9,1,11,13,17,19,21,1,3,89,24}` (versão com função `intercala`) e `{9,8,7,6,5,4,3,2,1}` (versão tudo-em-uma).
- **Pegadinhas:**
  - aloca o auxiliar a cada intercalação, sem testar NULL;
  - `calloc(sizeof(int), n)` com os argumentos invertidos (funciona, mas confunde);
  - **estabilidade:** a versão 1 compara com `<=` e é estável; a versão 2 usa `<` e, no empate, pega o elemento da direita, o que **quebra a estabilidade**. É um gancho para 0101.

### 0100-quick-sort
- **Conceitos-chave:** Hoare; escolher o pivô, separar em L (≤ pivô) e G (≥ pivô) e recursar nas duas partes. Varre dos dois lados trocando os pares fora do lugar.
- **Exemplo de partição:** S = {7,1,3,9,8,4,2,7,4,2,3,5}; pivô = o elemento da posição (1+12)/2 = 6, que vale 4.
- **Escolha do pivô:** o do meio, ou a mediana de três escolhidos ao acaso.
- **Custo:** n log n no melhor caso e na média; n² se o pivô for sempre o maior.
- **Exemplo divertido:** `qs()` ordena **os caracteres de uma string** cheia de símbolos, mostrando a ordem ASCII (o código esquece `#include <string.h>`).

### 0101-comparando
- **Ideias de exercícios (do livro):**
  1. vetor de 15 mil aleatórios: rodar todos os algoritmos, medir o tempo em ordem crescente e decrescente;
  2. se ordenar n leva t segundos, estimar o tempo para 10, 100, 1000, 10000 e 100000 elementos em cada algoritmo (n² contra n log n).

### 0102-arvores
- **Conceitos-chave:** hierarquias como árvore genealógica, chaveamento de campeonato, organograma, decisões e gramáticas. Analogia com a árvore de verdade: raiz, galhos/filhos, folha (nó terminal). Grau de saída = número de filhos. Caminho de k nós tem comprimento k−1. A raiz está no nível 0.
- **Exemplo pronto (figura 9.2):**
  - A é a raiz; B e C são filhos de A; D e E são irmãos; H e I são irmãos;
  - folhas: D, G, H, I;
  - grau de saída: B = 2, C = 1;
  - caminho de A até H tem comprimento 3;
  - níveis: 0 = A; 1 = B, C; 2 = D, E, F; 3 = G, H, I.
- **Pegadinha:** o livro conta **folha com altura 1** (A = 4, C = 3, E = F = 2). Muitas fontes usam folha = 0 (altura medida em arestas). **Fixe uma convenção no curso** e avise o aluno.
- **Definições extras:**
  - estritamente binária (todo nó interno tem 2 filhos): com n folhas, tem 2n−1 nós;
  - completa com profundidade k: 2^(k+1) − 1 nós e 2^k folhas (k = 3: 15 nós, 8 folhas).

### 0103-arvore-binaria
- **Representações:**
  - vetor de filhos (`filhos[4]`), que limita o número de filhos;
  - "primeiro filho / próximo irmão", que transforma qualquer árvore em binária;
  - nó binário `{info, esquerda, direita, pai}`.
- **Percursos:** pré-ordem (o nó antes dos filhos), em-ordem (esquerda, nó, direita) e pós-ordem (filhos antes do nó), todos recursivos.
- **Exemplo excelente:** `imprimir(v, nivel)` em-ordem com recuo de 2 espaços por nível. Desenha a árvore **deitada** no terminal, ótimo para o aluno conferir as inserções.
- **Ideia de exercício:** liberar a árvore inteira (em pós-ordem), algo que falta no livro.

### 0104-bst-busca-insercao
- **Conceitos-chave:** à esquerda ficam os menores (ou iguais), à direita os maiores. **Os mesmos dados geram árvores diferentes** conforme a ordem de inserção: com {2,3,5,5,7,8}, a árvore com raiz 5 encontra o 8 em 2 comparações mais o acerto; a árvore com raiz 2 precisa de 3 mais o acerto. Árvore cheia: ~log n; degenerada (tudo para um lado): ~n.
- **Código excelente:**
  - `inserir(arvore *p, int chave)` recursivo com **ponteiro para ponteiro**: `inserir(&((*p)->direita), chave)`. Evita tratar a raiz como caso especial;
  - `pesquisar` recursivo;
  - `range(v, x, y)` imprime os valores em [x, y] podando as subárvores;
  - `proxmaior(chave)` (sucessor): o menor da subárvore direita ou, se ela não existir, o último ancestral em que se desceu à esquerda.
- **Pegadinhas:**
  - `root` global;
  - `typedef ... *arvore` esconde o ponteiro (discutível);
  - duplicatas vão para a esquerda;
  - `malloc` sem teste;
  - **maior/menor:** o livro diz que o maior está "na folha mais à direita". O nó mais à direita **pode ter filho esquerdo**, então não é necessariamente uma folha.
- **Ideia de exercício (do livro):** versões iterativas de inserir e pesquisar.

### 0105-bst-remocao
- **Três casos:** folha (só remove); um filho (o avô herda o neto); dois filhos (troca pelo sucessor, o mais à esquerda da subárvore direita, ou pelo antecessor, o mais à direita da subárvore esquerda, e remove esse nó).
- **Código do livro:** `excluir(&root, chave)` com uma auxiliar `del()` que usa o **antecessor**: copia a informação e libera o nó do antecessor (estilo Wirth; correto).
- **Pegadinhas:**
  - a explicação da figura (remover o 50, com 53, 54 e 55 envolvidos) está confusa: refazer o exemplo;
  - `excluir_menor` não dá `free` e quebra com a árvore vazia.
- **Ideia de exemplo:** inserir 50, 30, 70, 20, 40, 60, 80, 55 e remover 20 (folha), depois 60 (um filho), depois 50 (dois filhos), mostrando a árvore deitada depois de cada passo.

---

## Obsoleto / evitar
- `gets(...)`: removido do C11. Usar `fgets` e tirar o `\n`.
- `flush(stdin)` / `fflush(stdin)`: o primeiro nem existe, o segundo é indefinido. Descartar até `\n` com um laço de `getchar`.
- `getch()`, `conio.h` e `curses.h` só para pausar: não são portáveis. Usar `getchar()`.
- `register`: inútil hoje.
- `%d` / `%ld` para endereço: usar `%p` com `(void*)`.
- Cast no retorno de `malloc`/`calloc`: desnecessário em C.
- `int` para tamanhos de alocação: usar `size_t`.
- `return;` em `int main`, `main` sem `return 0`, `main(_,o,O)` de estilo K&R.
- `_Bool` direto: preferir `bool` de `stdbool.h`.
- Notação húngara (`iIndice`, `aVetor`, `piValor`, `fMedia`): não adotar no curso.
- Telefone guardado em `int`.
- Exemplos do IOCCC (código ofuscado): só como curiosidade, nunca como didática.
- Afirmações conceituais a corrigir:
  - "vetor é ponteiro";
  - "matriz em C é vetor de ponteiros";
  - "lista tem acesso randômico";
  - "pilha e fila têm tamanho fixo";
  - "o maior elemento está sempre numa folha";
  - "lista dupla serve para recuperar após falha de hardware".
- Bugs a não copiar:
  - `strcpy` em `char[5]` com "abcde";
  - `*pi = malloc(...)`;
  - `calloc(n, sizeof(int))` para `int**`;
  - `p = realloc(p, ...)`;
  - `stacktop` lendo `pilha[pos]`;
  - os `size` errados da fila;
  - a troca fora do laço na seleção;
  - `free(p)` em vez de `free(*p)` no `delete`;
  - `maior`/`menor` sem testar NULL;
  - a lista com nó extra e vazamento.

## Extras que não cabem no sumário
- **Busca com frequência de acesso e "mover para a frente"** (autoajuste de listas).
- **Contagem de movimentos do Hanói por recorrência sem recursão dupla**: `h(n) = 2h(n−1) + 1`.
- **MDC por subtrações sucessivas** (variante de Euclides).
- **Representação "primeiro filho / próximo irmão"**, que converte uma árvore geral em binária.
- **Operações extras de BST:** `range` (consulta de intervalo) e sucessor (`proxmaior`).
- **Impressão de árvore deitada** com recuo por nível.
- **Analogia de fragmentação de memória** (vetor contra lista em 90 posições), também útil em 0058.
- **Exercício "fila de pilhas"** (composição de estruturas).
- **Referências citadas pelo livro:** Tenenbaum et al., *Estruturas de Dados Usando C*; Cormen et al., *Algoritmos*; Wirth, *Algorithms and Data Structures*; Koenig, *C Traps and Pitfalls*; Schildt, *C: The Complete Reference*; Lorenzi et al., *Estrutura de Dados*.
