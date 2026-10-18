# Fichamento — Lintzmayer & Mota, *Análise de Algoritmos e de Estruturas de Dados*

- **Obra:** Carla Negri Lintzmayer (CMCC-UFABC) e Guilherme Oliveira Mota (IME-USP), *Análise de
  Algoritmos e de Estruturas de Dados*. Rascunho de 4 de agosto de 2023 (o próprio texto avisa
  "pode conter erros"). Nosso arquivo tem 9367 linhas; as fórmulas exibidas sumiram na conversão
  (sobram linhas em branco onde havia equações), mas o texto corrido e os pseudocódigos estão inteiros.
- **Público original:** disciplina de Análise de Algoritmos (graduação em computação). Pressupõe
  que o aluno já programa, já viu vetor, lista, pilha, fila e árvore, e sabe indução.
- **Estrutura:** I. revisão matemática (potência, log, somatório, PA/PG, piso/teto) · II. princípios
  (busca linear/binária, invariantes, tempo de execução, melhor/pior/médio, O/Ω/Θ/o/ω, recursão,
  recorrências por substituição, iteração, árvore de recursão e mestre) · III. estruturas de dados
  (vetor, lista dupla, pilha, fila circular, BST, heap, union-find, hash) · IV. ordenação (insertion,
  shellsort, merge, selection, heapsort, quicksort com análise esperada, limite inferior, counting) ·
  V. técnicas (divisão e conquista/Karatsuba, guloso, programação dinâmica) · VI. grafos (conceitos,
  BFS, DFS, componentes, fortemente conexas, ordenação topológica, Kruskal, Prim, Euler/Fleury,
  Dijkstra, Bellman-Ford, Floyd-Warshall, Johnson) · VII. redução, P, NP, NP-completo.
- **Avaliação geral:** é a fonte mais **rigorosa** que temos para a parte de análise e para os
  módulos novos de técnicas e grafos. Três qualidades que o LPEDC deve herdar:
  (1) **todo algoritmo vem com invariante de laço ou indução**, sempre no mesmo molde
  ("antes da t-ésima iteração começar, vale que...", caso base, passo, uso de P(T+1) no fim);
  (2) **toda técnica nasce de um algoritmo recursivo ingênuo** cuja árvore de recursão mostra a
  repetição (Fibonacci, corte de barras, mochila, alinhamento, Floyd-Warshall), e só então vem a
  tabela, primeiro *top-down* e depois *bottom-up*;
  (3) **análise separada para matriz e lista de adjacências** em todo algoritmo de grafo.
  Pontos fracos: texto denso e formal (prova longa até para somatório), quase nenhuma analogia do
  cotidiano, pseudocódigo com vetores **1..n** (no C do curso será 0..n-1), a seção de **árvores
  balanceadas está vazia** ("ainda em construção"), **hash tem uma página só**, o capítulo 30
  (como lidar com NP-difíceis) diz apenas "Em breve", e não há nada de backtracking, análise
  amortizada formal, strings/busca de padrões, trie, B-tree, rubro-negra, skip list ou matriz esparsa.
  Há alguns erros de rascunho (listados nas pegadinhas de cada seção) que viram bons exercícios de "ache o erro".
- **Convenções do livro que vale adotar (adaptando para C):** `A[esq..dir]` para subvetor;
  atributos de nó com ponto (`x.chave`, `v.pred`, `v.dist`, `v.visitado`) que em C viram campos de
  struct ou vetores paralelos indexados pelo vértice; nomes `ConstroiCaminho`, `Particiona`,
  `Combina`, `CorrigeHeapDescendo/Subindo` são bons nomes de função em português.

## Princípios transversais (usar em todo o curso)

### Problema, instância, solução, algoritmo correto
- Um problema computacional é descrito por **entrada** e **saída**; uma **instância** é um valor
  concreto de entrada; a **solução** é a saída esperada para ela. Algoritmo **correto** devolve a
  solução para *qualquer* instância. Para mostrar que está **errado** basta *uma* instância
  (contraexemplo); para mostrar que está certo é preciso prova.
- Bom hábito para o curso inteiro: todo módulo novo abre com a caixa "Problema X — Entrada/Saída" como o livro faz.

### Roteiro de cinco passos para resolver um problema (Cap. 6, Soma em Vetor)
1. Entender o problema fazendo exemplos à mão (inclusive casos-limite).
2. Criar um algoritmo, de preferência reaproveitando um que já existe (redução).
3. Verificar a correção (testar nos exemplos; depois provar com invariante).
4. Analisar o tempo.
5. Perguntar "dá para fazer melhor?" e voltar ao passo 2.
- O exemplo do livro: achar `i != j` com `A[i] + A[j] == k`. Versão 1 chama busca linear de
  `k - A[j]` para cada `j` (O(n²)); versão 2 testa todos os pares `i < j` (O(n²)); o livro deixa
  no ar que existe O(n lg n). Ótimo fio condutor para um "juntando tudo" de análise.

### Molde de invariante (o que o aluno deve escrever)
- "P(t) = antes da t-ésima iteração começar, vale que [variável de controle = ...] e [o que já
  foi feito com A[1..i-1]]". Prova por **indução no número de vezes que o teste do laço executa**.
- O teste roda **T+1 vezes** quando o corpo roda T vezes; é P(T+1) que diz algo útil no final.
- Caso base quase sempre é verdadeiro **por vacuidade** (subvetor vazio). O livro usa a piada
  "todos os unicórnios vomitam arco-íris" para explicar vacuidade: vale reaproveitar com outra frase.

### 0076-eficiencia
**Conceitos-chave**
- Tempo de execução = **número de passos básicos** em função do **tamanho da entrada**, não segundos
  de relógio. Passos básicos: aritmética, comparação, lógica, atribuição, acesso a índice/campo,
  chamada e retorno (a chamada é barata; executar a função chamada não).
- Tamanho da entrada depende do problema: número de elementos (busca, ordenação), **número de bits**
  (multiplicação, potência, primalidade) ou mais de um número (dois vetores: `T(n, m)`).
- **Melhor caso, pior caso, caso médio**: menor, maior e média dos tempos entre todas as instâncias
  de tamanho n. O caso médio exige supor uma distribuição (ex.: todas as n! permutações igualmente
  prováveis). **Tempo esperado** é o nome usado para algoritmos aleatorizados.
- Algoritmo **eficiente** = pior caso limitado por um polinômio no tamanho da entrada.

**Explicações boas**
- Contagem linha a linha da busca linear com custo `t` por operação: `12t` no melhor caso e
  `7tn + 8t` no pior; caso médio `(7tn + 17t)/2`. Mostra que pior e médio têm a mesma "forma" an+b.
- `SomatorioPar` dá a faixa `6tn + 4t <= T(n) <= 9tn + 4t`: o mesmo n gera tempos diferentes
  conforme o conteúdo do vetor. Bom gancho para "por que existe melhor e pior caso".
- Busca binária: o laço roda entre `⌈lg n⌉` e `⌊lg n⌋ + 2` vezes, **independente do conteúdo**.
- Para n < 5 a busca linear faz menos operações que a binária: eficiência assintótica não é tudo.
- Potência `x^n` com n decrescendo de 1 em 1 leva Θ(n) passos, mas o tamanho da entrada é
  `m = lg n` bits, então é **Θ(2^m), exponencial**. Contraste com a versão que divide n por 2 (Θ(m)).

**Pegadinhas**
- Confundir "valor da entrada" com "tamanho da entrada" (n vs. lg n bits).
- Achar que caso médio sempre é melhor que o pior: na busca linear é só metade.
- Somar números gigantes (Fibonacci de 0,694n bits) **não** é passo básico.

**Ideias de exemplos**
- Contar à mão os passos de `soma` sobre `A = {12, 99, 37, 24, 2, 15}` linha a linha, depois para
  n genérico (teste do `for` roda n+1 vezes, corpo n vezes).
- Busca linear em `{12, 99, 37, 24, 2, 15}` procurando 24 (4 comparações) e 10 (6 comparações + falha).

**Ideias de exercícios**
- Quantas vezes roda o teste do laço de `for (i = 1; i <= n; i *= 2)`? Resp.: `⌊lg n⌋ + 2`.
- Caracterize o melhor e o pior caso de `BuscaLinearEmOrdem` (para quando `A[i] >= k`).
  Resp.: melhor = k menor que todos (1 comparação); pior = k maior que todos ou igual ao último.
- Por que `PotenciaV1(x, n)` é exponencial? Resp.: Θ(n) chamadas, mas a entrada tem lg n bits.

### 0077-big-o
**Conceitos-chave**
- `f = O(g)`: existem C e n0 com `f(n) <= C g(n)` para todo n >= n0. `Ω`: limitante inferior com c.
  `Θ`: os dois ao mesmo tempo. `o` e `ω`: versões estritas ("para **toda** constante c existe n0"),
  equivalentes a `lim f/g = 0` e `lim f/g = ∞`.
- Propriedades: reflexiva (O, Ω, Θ), transitiva (todas), simétrica (Θ), simetria transposta
  (O↔Ω, o↔ω). Soma de funções é Θ do termo de maior crescimento.
- Funções de várias variáveis: `45n² + 2nm/3 + 678m = O(n² + nm)`, mas **não** é `O(n²)` porque n e
  m crescem de forma independente.
- **Notação não é caso**: dá para dizer "Θ(1) no melhor caso" e "Θ(n) no pior caso" da busca linear.
  Sem citar o caso, a frase vale para toda instância: "busca linear é O(n)" e "é Ω(1)" são
  verdadeiras; "busca linear é Θ(n)" é **falsa**.

**Explicações boas**
- `475n + 34` vs `n² + 3`: para n = 4 a linear é muito maior (1934 vs 19), mas a partir de n = 477 a
  quadrática vence. A notação esconde essas constantes e o "começo".
- Três estratégias de prova para `5 lg n + √n = O(√n)`: isolar C (`C >= 5 lg n/√n + 1`, com cuidado
  ao escolher n0, pois n0 = 1, C = 1 falha em n = 2), majorar termo a termo (`lg n <= √n` para
  n >= 16, logo C = 6), e limite com L'Hôpital.
- Prova de que `7n² != O(n)` por contradição: isolando C chega-se a `C >= 7n` para todo n >= n0.

**Pegadinhas**
- "Ω é melhor caso e O é pior caso": o livro chama isso de "muito errado".
- `f(n) <= 475 g(n)` para todo n >= 1 também mostra `f = O(g)`: constantes e n0 não são únicos.
- `log_a n` e `log_b n` são Θ um do outro (mudança de base é constante), mas nenhum é o do outro.
- No passo da prova é preciso chegar exatamente em `<= C g(n)`; ver também a seção de recorrências.

**Ideias de exemplos**
- Tabela n = 1, 10, 100, 1000 para `lg n`, `√n`, `n`, `n lg n`, `n²`, `2^n` (o livro tem os gráficos;
  reproduzir em tabela de texto). Mostrar que até 5 "parece" maior que √x no começo.
- Provar `10n² + 5n + 3 = Θ(n²)` com C = 18, c = 10, n0 = 1, passo a passo.

**Ideias de exercícios**
- Prove `3 lg(n²) + 2 = Θ(lg n)`. Resp.: `= 6 lg n + 2`; c = 6 com n0 = 1; C = 8 com n0 = 2.
- Verdadeiro ou falso: `2n = o(n²)`, `2n² = o(n²)`, `1000n² = o(n² lg n)`, `lg n = o(n^0,01)`. Resp.: V, F, V, V.
- Classifique cada frase sobre a busca binária (V/F): "é O(lg n)", "é Θ(lg n)", "é Θ(1) no melhor
  caso". Resp.: V; V para a versão iterativa do livro (o laço não para cedo), F para a recursiva
  (que pode achar no meio); V só para a recursiva.

### 0078-invariantes
**Conceitos-chave**
- Invariante = afirmação verdadeira **no início** de toda iteração (entre o teste e a primeira linha
  do corpo). Serve para provar correção e também para **descrever a ideia** do algoritmo.
- Invariante inútil é invariante verdadeiro que não ajuda no final ("os elementos de A[1..i-1] já
  foram acessados" é verdade em `Somatorio`, mas não prova a soma).
- Laços com dois critérios de parada (busca linear): a prova final faz **análise de casos** sobre
  qual condição falhou.
- Prova de correção de "se e somente se" separa ida e volta (busca linear: existe ⇔ devolve índice).

**Explicações boas**
- Sequência Somatório → Produtório → BuscaLinear → ConverteBase, em dificuldade crescente.
- **ConverteBase**: invariante "B[1..i-1] representa z = n − m·2^(i−1)", provada separando m par e
  m ímpar. Ao fim m = 0, logo z = n. Liga direto com o assunto 0004-binario.
- InsertionSort precisa de **duas** invariantes (uma para o `enquanto` interno, com uma cópia B do
  vetor no início do laço, e outra para o `para` externo, com cópia C).
- Particiona do quicksort: invariante com três faixas "< pivô | >= pivô | ?" desenhada como régua.

**Pegadinhas**
- A variável de controle nem sempre vale t (laço decrescente, passo 2, i *= 2): o invariante precisa
  dizer explicitamente quanto ela vale em função de t.
- Invariante só vale no **início** da iteração; no meio do corpo pode estar quebrado.
- Não confundir "início do laço" com "início da iteração" (nota do livro no insertion sort).

**Ideias de exemplos**
- Trace de ConverteBase(10): m = 10, 5, 2, 1, 0; B = (0), (0,1), (0,1,0), (0,1,0,1). Em cada linha
  conferir z = n − m·2^(i−1): 0 = 10−10·1; 0 = 10−5·2; 2 = 10−2·4; 2 = 10−1·8; 10 = 10−0.
- Escrever o invariante como comentário no C de `soma`, `produto`, `busca`.

**Ideias de exercícios**
- Prove a busca binária com o invariante sugerido pelo livro: "esq <= dir e A[1..esq-1] e
  A[dir+1..n] não contêm k". Resp.: base vacuidade; passo pelos dois ramos do `se`; no fim esq = dir.
- Ache um invariante para `max` de um vetor. Resp.: "antes da iteração com i, `max` é o maior de A[1..i-1]".
- Invariante do laço de SelectionSort externo. Resp.: "A[i+1..n] está ordenado e contém os n−i maiores".

### 0079-tad
**Conceitos-chave**
- Tipo abstrato de dados = dados + relações + operações; estrutura de dados = **uma implementação**
  dele. Nenhuma estrutura é boa em tudo; escolher a certa muda a complexidade (exemplo do livro: Fibonacci com vetor).
- Fila de prioridade, disjoint set, dicionário (hash) aparecem como TADs com várias implementações
  possíveis, comparadas pelo custo de cada operação.

**Ideias de exercícios**
- Tabela "operação × implementação" para fila de prioridade (vetor desordenado, vetor ordenado,
  lista ordenada, heap). Resp.: inserir O(1)/O(n)/O(n)/O(lg n); remover máximo O(n)/O(1)/O(1)/O(lg n).

### 0080-vetor-dinamico
**Conceitos-chave**
- Distinção **capacidade** × **tamanho** (o livro insiste nela). Acesso por índice Θ(1).
- Vetor **desordenado**: inserir no fim Θ(1); remover sabendo a posição Θ(1) (copia o último para o
  buraco); remover por valor O(n) por causa da busca.
- Vetor **ordenado**: buscar O(lg n), mas inserir e remover são O(n) por causa do deslocamento,
  **mesmo usando busca binária** para achar a posição.

**Pegadinhas**
- O truque "copia o último para o buraco" destrói a ordem: só serve em vetor desordenado.

**Ideias de exercícios**
- Por que inserir em vetor ordenado é O(n) se a busca binária é O(lg n)? Resp.: o deslocamento de A[i..n] domina.

### 0081-lista-encadeada / 0082-lista-busca-remocao / 0083-lista-ordenada / 0084-lista-dupla / 0085-lista-circular
**Conceitos-chave**
- Inserção ordenada em lista é O(n) (percorre até a posição); serve de contraste com a BST.
- Lista dupla com ponteiros `cabeca` e `cauda`; inserir no início e no fim Θ(1); buscar e remover por
  chave O(n). Lista circular: `prox` da cauda aponta a cabeça e `ante` da cabeça aponta a cauda.
- Remoção dupla trata quatro casos com dois `if` independentes: x é cauda? x é cabeça?

**Explicações boas**
- Pseudocódigos curtos e limpos de `InsereNoInicioLista`, `InsereNoFimLista`, `RemoveDaLista`
  (bons para traduzir para C quase linha a linha). Inserir no fim com `cauda` é o que permite fila
  sobre lista e as listas de pós-ordem da DFS.

**Pegadinhas**
- Esquecer de atualizar `L.cauda` quando o removido é o último.
- O pseudocódigo do livro não libera o nó: em C lembrar o `free`.

**Ideias de exercícios**
- Liste os casos de teste mínimos para `RemoveDaLista`. Resp.: lista vazia, chave ausente, único nó,
  cabeça, cauda, meio.

### 0087-pilha / 0089-pilha-aplicacoes
**Conceitos-chave**
- LIFO, `topo` começa em 0, invariante "P[1..topo] guarda a pilha, do mais antigo ao mais recente".
  Empilha/Desempilha/Consulta Θ(1).
- Aplicações citadas: palíndromo, desfazer/refazer, DFS iterativa.

**Ideias de exemplos**
- Sequência da Figura 10.1: Empilha 3, 5, 1; Desempilha, Desempilha; Empilha 8 → pilha (3, 8).

### 0090-fila
**Conceitos-chave**
- Fila circular com `cabeca`, `cauda` (posição **seguinte** ao último) e campo `tamanho`, que resolve
  a ambiguidade cheia/vazia (cabeca == cauda nos dois casos).

**Ideias de exemplos**
- Figura 10.2: Enfileira 3, 5, 1; Desenfileira ×2; Enfileira 8 → fila (1, 8), cabeca = 3, cauda = 5.

**Ideias de exercícios**
- Por que o livro mantém `tamanho`? Resp.: sem ele, cabeca == cauda não distingue cheia de vazia.

### 0036-pilha-de-chamadas / 0037-recursao / 0038-recursao-na-pratica
**Conceitos-chave**
- Recursão serve quando **toda instância contém instâncias menores do mesmo problema** e a solução
  delas ajuda a resolver a grande. Não basta achar um subproblema qualquer: na busca, "k está em
  A[5..n/2]?" é subproblema mas não ajuda; "k está em A[1..n−1]?" ajuda.
- Esquema: (i) instância pequena → resolve direto; (ii) senão divide, resolve recursivamente e combina.
- Correção de algoritmo recursivo = **indução no tamanho da entrada**.
- Recursivo vs. iterativo: recursão é concisa, mas gasta pilha; "recursão é sempre mais lenta" é mito
  (depende do compilador e do problema).

**Explicações boas**
- Figura 7.1: Fatorial(3) desenhado como pilha de quadrinhos "3 × ?", "2 × ?", "1 × ?" que vão sendo
  preenchidos na volta. Ótimo para 0036.
- **PotenciaV2 vs PotenciaV3**: a V2 chama `Potencia(x, n/2)` **duas vezes** e vira Θ(n); a V3 guarda
  em `aux` e fica Θ(lg n). Mesma ideia, uma linha de diferença.
- Fibonacci recursivo: F(200) levaria ~10^21 milênios a 4 bilhões de instruções por segundo; com
  vetor, F(1.000.000) em menos de 1 s (ignorando o tamanho dos números).

**Pegadinhas**
- Chamar duas vezes a mesma recursão com o mesmo argumento (PotenciaV2).
- O livro avisa que a análise "soma de Fibonacci é constante" é simplificada: F_n tem ~0,694n bits.

**Ideias de exemplos**
- Trace de PotenciaV3(4, 3): n = 3 ímpar → aux = Pot(4, 1); n = 1 → aux = Pot(4, 0) = 1, devolve
  4·1·1 = 4; volta: 4·4·4 = 64.
- Árvore de recursão de Fib(6) (15 nós, Fib(2) aparece 5 vezes).

**Ideias de exercícios**
- Quantas chamadas faz PotenciaV2(x, 8)? E PotenciaV3(x, 8)? Resp.: V2: 1+2+4+8+16 = 31 chamadas
  (n = 8,4,2,1,0); V3: 5 chamadas.
- Escreva BuscaLinearRecursiva(A, n, k) que olha A[n] e chama com n−1; prove por indução.

### 0094-busca-sequencial / 0095-busca-binaria
**Conceitos-chave**
- Três buscas para vetor ordenado: linear, linear com parada antecipada (`A[i] < k`), binária.
- A binária do livro (iterativa) usa `enquanto esq < dir`, `meio = ⌊(esq+dir)/2⌋`, `se k > A[meio]
  então esq = meio+1 senão dir = meio` e **só compara igualdade no final**. A recursiva compara
  igualdade no meio e usa `esq > dir` como caso base.
- `meio = ⌊(esq+dir)/2⌋` dá o elemento central nos dois casos de paridade (o livro justifica).

**Pegadinhas**
- A iterativa do livro é Θ(lg n) sempre; a recursiva é O(lg n) e Ω(1). Mesmo nome, análises diferentes.
- `dir = meio` (e não `meio − 1`) na versão iterativa: trocar por `meio − 1` quebra o algoritmo.
- Em C, `(esq + dir) / 2` pode estourar `int` para vetores enormes: `esq + (dir − esq) / 2`.

**Ideias de exemplos**
- Vetor do livro `{2, 8, 12, 15, 24, 32, 37, 45, 87, 99}`: buscar 37 (esq,meio,dir: (1,5,10) → esq = 6;
  (6,8,10) → dir = 8; (6,7,8) → dir = 7; (6,6,7) → esq = 7; esq = dir = 7 e A[7] = 37), buscar 11 (falha) e 103 (maior que todos).

**Ideias de exercícios**
- Quantas iterações faz a binária iterativa com n = 10? Resp.: entre ⌈lg 10⌉ = 4 e ⌊lg 10⌋+2 = 5 testes do laço.
- Resolva Soma em Vetor em O(n lg n). Resp.: ordenar (mergesort) e, para cada j, busca binária de
  k − A[j] cuidando de i ≠ j; ou ordenar e usar dois índices nas pontas.

### 0097-selection-sort (0096-bubble-sort: o livro não trata bubble sort)
**Conceitos-chave**
- Versão do livro coloca o **maior** de A[1..i] na posição i, com i de n até 2. Sempre Θ(n²)
  comparações, independente da entrada; a linha `iMax = j` roda O(n²).
- Duas invariantes (interno: A[iMax] >= tudo em A[1..j−1] e A[i]; externo: A[i+1..n] ordenado com os maiores).

**Ideias de exemplos**
- Trace com `{7, 3, 1, 10, 2, 8, 15, 6}` (o vetor-padrão do livro em todos os sorts).

### 0098-insertion-sort
**Conceitos-chave**
- Analogia das cartas na mão. In-place e estável. Melhor caso Θ(n) (já ordenado), pior Θ(n²)
  (decrescente), médio ~n(n−1)/4 execuções do laço interno, Θ(n²).

**Ideias de exercícios**
- Quantas vezes roda o teste do `enquanto` para `{5,4,3,2,1}`? Resp.: 2+3+4+5 = 14.

### 0099-merge-sort
**Conceitos-chave**
- Divide em ⌊n/2⌋ e ⌈n/2⌉, ordena recursivamente, `Combina` com vetores auxiliares B e C. Combina é
  Θ(n); recorrência T(n) = 2T(n/2) + n = Θ(n lg n). Não é in-place.
- Invariante de Combina: "A[inicio..k−1] ordenado e todo B[i..] e C[j..] é >= que ele".

**Pegadinhas**
- Usar `<` em vez de `<=` em `B[i] <= C[j]` quebra a estabilidade.

**Ideias de exemplos**
- Combina de B = {1,3,7,10} e C = {2,6,8,15} (Figura 16.4): A recebe 1,2,3,6,7,8,10 e depois o resto 15.

### 0100-quick-sort
**Conceitos-chave**
- Particiona de Lomuto: pivô em `A[fim]`, `i` marca o fim dos menores, `j` varre; uma passada, Θ(n).
- Pior caso Θ(n²) (pivô sempre o maior/menor: T(n) = T(n−1) + n). Melhor caso Θ(n lg n).
- **Qualquer divisão proporcional constante** (1/1000 e 999/1000, até 1/10^100) ainda dá O(n lg n):
  a árvore tem altura log_{k/(k−1)} n = Θ(lg n) e cada nível custa ≤ n.
- Pivô **aleatório** → tempo esperado O(n lg n) para **qualquer** entrada (protege contra "usuários malignos").

**Explicações boas**
- Análise esperada por pares: o_i e o_j são comparados só se um dos dois for o primeiro pivô
  escolhido entre o_i..o_j; probabilidade 2/(j−i+1); soma dá O(n lg n). Para o curso, basta a ideia.

**Pegadinhas**
- **Erro do livro**: o Teorema 18.1 diz "menores à esquerda, maiores ou iguais à direita", mas o
  código usa `A[j] <= pivo` (iguais vão para a esquerda). Bom exercício "o enunciado bate com o código?".
- Vetor já ordenado + pivô no fim = pior caso.

**Ideias de exemplos**
- Particiona({7,3,1,10,2,8,15,6}) com pivô 6 (Figura 18.3): resultado {3,1,2,6,7,8,15,10}, devolve 4.

**Ideias de exercícios**
- Qual a profundidade da recursão do quicksort (pivô no fim) em `{1,2,...,8}`? Resp.: 7 níveis (n−1).

### 0101-comparando
**Conceitos-chave**
- Definições de **in-place** (espaço extra constante) e **estável** (iguais mantêm a ordem relativa).
- Quadro do livro: insertion (in-place, estável, Θ(n)–Θ(n²)), selection (in-place, Θ(n²)), merge
  (estável, não in-place, Θ(n lg n)), heapsort (in-place, não estável, Θ(n lg n)), quicksort
  (in-place, não estável, Θ(n²) pior, O(n lg n) esperado), counting (estável, não in-place, Θ(n+k)).
- Merge e heap são **assintoticamente ótimos** entre os algoritmos por comparação (ver limite inferior).

### 0102-arvores / 0103-arvore-binaria
**Conceitos-chave**
- Raiz (nível 0), filho, pai, folha, descendente, ancestral, subárvore enraizada em x.
  **Nível/profundidade** = arestas da raiz até x; **altura** de x = arestas no maior caminho até uma
  folha; altura da árvore = altura da raiz.
- Árvore binária com n nós tem altura >= lg(n+1) − 1, isto é, **Ω(lg n)** (cada nível tem no máximo 2^i
  nós). **Completa**: todos os níveis cheios (2^(h+1) − 1 nós). **Quase completa**: só o último nível pode faltar.

**Ideias de exercícios**
- Na Figura 11.1 (x raiz; y, z, w filhos; a, b filhos de y; c filho de w; d filho de b): altura de y?
  Resp.: 2. Folhas? Resp.: a, d, z, c.

### 0104-bst-busca-insercao / 0105-bst-remocao
**Conceitos-chave**
- Busca e inserção recursivas em O(h). `InsereABB` devolve a nova raiz e religa com
  `r.esq = InsereABB(r.esq, x)` (padrão ótimo para C, evita ponteiro para ponteiro).
- Remoção em três casos reorganizados: (1) sem filho esquerdo → sobe o direito (cobre folha);
  (2) sem filho direito → sobe o esquerdo; (3) dois filhos → copia a chave do **sucessor** (mínimo da
  subárvore direita) e remove o sucessor recursivamente (que cai no caso 1).
- Sucessor sem filho direito = menor ancestral cujo filho esquerdo também é ancestral (Figura 11.6:
  sucessor de 20 é 30).
- A forma da árvore depende da **ordem de inserção**: inserir em ordem crescente gera um caminho de
  altura n. Mesma árvore pode vir de ordens diferentes ((18,15,20,10), (18,15,10,20), (18,20,15,10)).

**Explicações boas**
- Figuras 11.2, 11.3 e 11.5 (busca de 5, inserção de 18, remoção de 3 na árvore 14/3/29/1/10/20/34/5/22/7).

**Pegadinhas**
- O livro assume chaves distintas; inserir repetida não faz nada (nenhum dos dois `if` dispara).

**Ideias de exercícios**
- Insira 37, 45, 60, 90, 97 em quatro ordens da Figura 11.7 e desenhe. Resp.: (37,45,60,90,97) dá caminho de altura 4.
- Remova 3 da árvore da Figura 11.5. Resp.: 3 é trocado por 5; o 7 sobe para o lugar do 5.

### 0106-avl
- **Lacuna**: a seção 11.2 "Árvores balanceadas" só define (altura O(lg n) após qualquer sequência de
  operações) e diz "em construção". Usar outra fonte para AVL e rotações.

### 0107-heap
**Conceitos-chave**
- Vetor visto como árvore quase completa: filhos 2i e 2i+1, pai ⌊i/2⌋; posição i está no nível
  ⌊lg i⌋ e tem altura ⌊lg(n/i)⌋. Propriedade de heap: pai >= filhos.
- Cada elemento guarda `prioridade` e `indice` (posição atual no vetor), porque heap **não busca**
  bem e a alteração de prioridade precisa achar o elemento. Toda troca atualiza os dois `indice`.
- `CorrigeHeapDescendo` (O(lg n); pior caso T(n) <= T(2n/3) + 1 porque a subárvore esquerda pode ter
  2/3 dos nós) e `CorrigeHeapSubindo` (O(lg i)). Inserir = põe no fim e sobe; remover = troca raiz
  com o último, diminui e desce; alterar = sobe se aumentou, desce se diminuiu.
- **ConstroiHeap é O(n)**, não O(n lg n): há no máximo ⌈n/2^(h+1)⌉ nós de altura h e Σ h/2^h converge.

**Explicações boas**
- "Prioridade" é genérica: no banco tem prioridade quem tem **mais** idade; na farmácia, o remédio com
  **menos** estoque. Ótima analogia para max-heap vs. min-heap.
- Prim e Dijkstra usam o max-heap do livro com prioridade **negativa** (−peso, −dist) para simular um min-heap.

**Pegadinhas**
- Esquecer de atualizar `indice` nas trocas: AlteraHeap passa a mexer no elemento errado.
- O "truque do negativo" confunde: em C, melhor escrever um min-heap direto.

**Ideias de exemplos**
- ConstroiHeap({3,1,5,8,2,4,7,6,9}) (Figura 12.4): resultado {9,8,7,6,2,4,5,3,1}.
- CorrigeHeapSubindo após inserir 32 na posição 22 (Figura 12.3): 32 troca com 3 e depois com 29.

**Ideias de exercícios**
- Em qual nível está a posição 20? Qual é o pai? Resp.: ⌊lg 20⌋ = 4; pai 10.
- Por que ConstroiHeap começa em ⌊n/2⌋? Resp.: de ⌊n/2⌋+1 em diante são folhas, já são heaps.

### 0108-heapsort
- Seleção com heap: ConstroiHeap e depois troca A[1] com A[i], diminui o tamanho e corrige.
  Θ(n lg n) (Σ lg i = lg n! <= n lg n), in-place, não estável. Invariante: "A[i+1..n] ordenado com
  os maiores e A[1..tamanho] é heap".

### 0110-hashing / 0111-encadeamento / 0112-enderecamento-aberto
**Conceitos-chave (só o que o livro traz)**
- Motivação com **CPF**: endereçamento direto seria Θ(1) mas exigiria bilhões de posições.
- Colisões são inevitáveis (universo grande, tabela pequena) e aparecem mesmo com poucas chaves:
  **paradoxo do aniversário** — 2450 chaves em tabela de 1 milhão têm ~95% de chance de colisão.
- Busca, inserção e remoção em O(1) **no caso médio**.
- **Lacuna**: o capítulo tem uma página; não há encadeamento, sondagem, fator de carga nem funções.

**Ideias de exercícios**
- Calcular, para m = 365, a partir de quantas chaves a chance de colisão passa de 50%. Resp.: 23.

### 0114-grafos
**Conceitos-chave**
- Grafo como tripla (V, E, ψ) e depois **simples** (sem laço nem paralela), arestas como pares.
  Digrafo: arcos ordenados, grau de entrada/saída. Grafo subjacente, digrafo associado, orientação.
- Soma dos graus = 2m (digrafo: soma das saídas = soma das entradas = m). m <= n(n−1)/2 = O(n²).
- Lista de adjacências Θ(n + m) de espaço; matriz Θ(n²). Esparso (m = O(n)) → lista; denso
  (m = Θ(n²)) → matriz. Peso na matriz exige um marcador de "sem aresta" porque peso 0 é válido.
- Passeio, trilha (sem aresta repetida), caminho (sem vértice repetido), ciclo; componente conexa;
  fortemente conexa; distância (∞ se não há caminho); árvore = conexo com n−1 arestas = conexo sem
  ciclos (Teorema 23.3, seis caracterizações equivalentes); floresta; arborescência.

**Explicações boas**
- `GrauMaximo` em quatro versões (abstrata, com laço de vizinhos, matriz, lista) e análise
  linha a linha: matriz Θ(n²); lista O(n²) na análise frouxa e **Θ(n + m)** na justa (Σ d(v) = 2m).
  Excelente para ensinar que a mesma frase "para todo y ∈ N(x)" custa diferente em cada representação.

**Pegadinhas**
- O pseudocódigo esconde custo em notações como "x ∈ V(G)" e "d(x)".
- Em digrafo, "conexo" usa o grafo subjacente; "fortemente conexo" exige uv-caminho e vu-caminho.

**Ideias de exercícios**
- Na Figura 23.5 (graus 3,3,2,4,3,2,1,1,1,0): δ, Δ e grau médio. Resp.: 0, 4, 2. Quantas arestas?
  Resp.: soma 20 / 2 = 10.
- Grafo com 7 vértices e 9 arestas (Figura 23.8): escreva lista e matriz.

### 0115-bfs
**Conceitos-chave**
- Busca genérica = crescer uma árvore a partir de s adicionando arestas entre visitados e não
  visitados; BFS escolhe pela **fila** (FIFO), DFS pela **pilha** (LIFO). A árvore fica implícita
  em `pred`; `ConstroiCaminho` refaz s→v seguindo `pred` e inserindo no início de uma lista.
- BFS calcula **distância** em grafo sem peso (`v.dist = u.dist + 1`). Prova usa o lema: na fila há
  vértices de distância k seguidos de distância k+1.
- Tempo Θ(n_s + m_s) com listas, Θ(n_s · n) com matriz.

**Pegadinhas**
- Marcar como visitado **ao enfileirar**, não ao desenfileirar (senão o vértice entra várias vezes).
- A inicialização (`visitado = 0`, `pred = NULL`) fica **fora** da busca (`ChamaBusca`), para permitir
  várias buscas seguidas.

**Ideias de exercícios**
- Pesos inteiros positivos podem ser resolvidos com BFS trocando cada arco de peso w por um caminho de
  w arcos. Qual o problema? Resp.: o grafo cresce com a soma dos pesos (pseudopolinomial).

### 0116-dfs
**Conceitos-chave**
- DFS iterativa consulta o topo sem tirar e empilha **um** vizinho não visitado por vez; só desempilha
  quando acabaram os vizinhos. Para ser O(n + m) cada vértice precisa lembrar **onde parou** na sua
  lista de vizinhos. A versão recursiva usa a pilha de chamadas.
- Ordens **pré-ordem**, **pós-ordem** e **pós-ordem reversa** (lista com inserção no início),
  base de componentes fortemente conexas e ordenação topológica.

**Pegadinhas**
- Recomeçar a varredura dos vizinhos do zero a cada consulta deixa a DFS iterativa quadrática.

### 0117-dijkstra
**Conceitos-chave**
- **Relaxação** de uv: se `v.dist > u.dist + w(uv)`, atualiza dist e pred. Lema central: relaxações
  nunca deixam dist abaixo da distância real e, se os arcos de um caminho mínimo forem relaxados na
  ordem (mesmo intercalados com outros), o último vértice fica com a distância certa.
- Dijkstra: guloso, escolhe o não visitado de menor `dist`, visita (dist congelado) e relaxa os arcos
  de saída. Só vale com pesos **>= 0**. Versão simples O(n²); com heap O((n + m) lg n) em listas.
- Subcaminho de caminho mínimo é mínimo (prova por troca de trecho).
- Grafo não orientado = digrafo associado; aresta negativa vira ciclo negativo (u, v, u).

**Pegadinhas**
- O algoritmo **não avisa** quando há peso negativo: termina normalmente com resposta errada.
- **Erro de redação do livro**: diz "se m for assintoticamente menor que log n, Dijkstra é mais
  eficiente" e escreve m = ω(log n), trocando "menor" por "maior". Bom exercício de leitura crítica.

**Ideias de exemplos**
- Contraexemplo para pesos negativos: arcos s→a (4), s→b (5), b→a (−3), a→c (2). Dijkstra visita s,
  a (4), c (6), b (5) e não relaxa b→a porque a já foi visitado: devolve dist(a) = 4, dist(c) = 6; correto é 2 e 4.

## Módulos novos que o livro cobre bem

### NOVO: recorrências e teorema mestre
**Conceitos-chave**
- Recorrência = função descrita por valores em entradas menores; caso base costuma ser Θ(1) e é omitido.
- Quatro métodos: **substituição** (chuta e prova por indução; precisa do palpite), **iterativo**
  (expande até o caso base), **árvore de recursão** (soma por nível; ótima para chutar) e **mestre**.
- Mestre para T(n) = aT(n/b) + f(n): compare f(n) com n^(log_b a) (o custo de "só dividir", que é o
  número de folhas). (1) f menor por um fator n^ε → Θ(n^(log_b a)); (2) igual → Θ(n^(log_b a) lg n);
  (3) f maior por n^ε **e** regularidade a·f(n/b) <= c·f(n), c < 1 → Θ(f(n)).
- **Versão simplificada** para f = Θ(n^k): compare a com b^k. a > b^k → Θ(n^(log_b a));
  a = b^k → Θ(n^k lg n); a < b^k → Θ(n^k). Vem de somar c·n^k·(a/b^k)^j nos níveis (PG).
- Pisos e tetos podem ser ignorados (prova para n entre potências de 2).
- Quando o mestre não se aplica, **sanduíche**: limite por recorrências vizinhas que se aplicam.

**Explicações boas**
- A regra de ouro do método da substituição: no passo da indução é preciso chegar **exatamente** na
  expressão escolhida. `T(n) <= cn + 1` não prova `T(n) <= cn`, mesmo que cn + 1 seja O(n).
- **Fortalecer a hipótese**: para T(n) = 3T(n/3) + 1, `cn` falha mas `cn − d` funciona (d = 1/2,
  c = 3/2). A sobra de uma constante é o sinal de que é preciso subtrair algo.
- Árvore de recursão de 2T(n/2) + n: lg n + 1 níveis, cada um custando n → n(lg n + 1).
- 3T(n/2) + n: custo por nível n·(3/2)^j, soma dá 3n^(lg 3) − 2n = Θ(n^1,59).
- Exemplo 1 do livro: T(n) = T(n/2) + n(2 − cos n) satisfaz f = Ω(n^ε) mas **falha a regularidade**.

**Pegadinhas**
- Casos "no buraco" entre (1) e (2) ou (2) e (3): f = n^(log_b a)/lg n ou n^(log_b a)·lg n.
  Ex.: 2T(n/2) + n lg n **não** cabe no mestre do livro.
- log_b a precisa ser calculado com cuidado: log_10 4 ≈ 0,6, log_16 4 = 1/2, log_4 5 > 1.
- Recorrências por subtração (T(n) = 2T(n−1) + n) não são do formato do mestre: usar iteração.
- Escolha de n0 quando T(1) = 1 e o palpite é c·n lg n (dá 0 em n = 1): começar a base em n = 2.

**Ideias de exemplos**
- Tabela "algoritmo → recorrência → resposta": busca binária T(n/2)+1 → lg n; mergesort 2T(n/2)+n →
  n lg n; PotenciaV2 2T(n/2)+1 → n; MultiplicaInteiros 4T(n/2)+n → n²; Karatsuba 3T(n/2)+n → n^1,59;
  CorrigeHeapDescendo T(2n/3)+1 → lg n; quicksort pior T(n−1)+n → n²; Fibonacci recursivo
  T(n−1)+T(n−2)+1 → Ω(1,618^n); CorteBarras ingênuo T(n) = n + Σ T(i) → Ω(2^n).

**Ideias de exercícios** (com resposta)
- 2T(n/2) + n → Θ(n lg n) (caso 2).
- 4T(n/10) + 5√n → Θ(n^(log_10 4)) (caso 1, 0,5 < 0,6).
- 4T(n/16) + 5√n → Θ(√n lg n) (caso 2).
- 4T(n/2) + 10n³ → Θ(n³) (caso 3).
- 5T(n/4) + n → Θ(n^(log_4 5)) (caso 1).
- 2T(n/3) + 1 → Θ(n^(log_3 2)) (iterativo ou mestre caso 1).
- 16T(n/4) + n²/lg n: mestre não se aplica; sanduíche dá Ω(n²) e O(n² lg n).
- 3T(n/9) + √n lg n: não se aplica (está entre os casos 2 e 3).
- Prove por substituição que 2T(n/2) + n = O(n lg n) e Ω(n lg n). Resp.: c = 3 com base n = 2; c = 1 com base n = 1.
- T(n) = T(⌊n/2⌋ + 2) + 1 é O(lg n). Dica do livro: provar `c lg(n − 4)`.

### NOVO: divisão e conquista
**Conceitos-chave**
- Três passos: dividir em pelo menos dois subproblemas, resolver recursivamente, combinar. Merge e
  quick são os exemplos já conhecidos.
- Multiplicação de inteiros de n dígitos: a escola faz O(n²). Escrevendo x = 10^⌈n/2⌉a + b e
  y = 10^⌈n/2⌉c + d, xy = 10^(2⌈n/2⌉)ac + 10^⌈n/2⌉(ad + bc) + bd.
  Quatro produtos recursivos → 4T(n/2) + n = Θ(n²), **sem ganho**. **Karatsuba**: (a+b)(c+d) − ac − bd
  = ad + bc, só três produtos → 3T(n/2) + n = O(n^1,59).
- Moral: em D&C o que manda é **quantos** subproblemas e quanto custa combinar (mestre).

**Pegadinhas**
- Somar números de muitos dígitos também é Θ(n), não Θ(1).
- `IgualaTam` põe zeros à esquerda para os dois números terem o mesmo número de dígitos.

**Ideias de exemplos**
- 5678 × 1234: a = 56, b = 78, c = 12, d = 34; ac = 672, bd = 2652, (a+b)(c+d) = 134 × 46 = 6164;
  meio = 6164 − 672 − 2652 = 2840; resultado 672·10^4 + 2840·10^2 + 2652 = 7.006.652.

**Ideias de exercícios**
- Quantas multiplicações de 1 dígito Karatsuba faz para n = 4, se o caso base é n = 1? Resp.: 9
  (contra 16 na versão de quatro produtos).
- Por que a versão de quatro produtos não melhora? Resp.: a = 4 = b^2 com k = 1 < 2 → n².

### NOVO: algoritmos gulosos
**Conceitos-chave**
- Guloso decide o melhor *agora* sem voltar atrás. Fácil de escrever e analisar; o difícil é provar
  que é ótimo, e quase sempre **não é**. Para refutar basta um **contraexemplo** (e nem precisa saber
  a solução ótima, só uma melhor que a do algoritmo).
- **Escalonamento de tarefas compatíveis** (intervalos [s, f)): falham "menor duração" e "começa
  primeiro"; funciona "**termina primeiro**". Versão recursiva O(n²); versão iterativa ordenando por
  f e pegando quem começa depois do último escolhido: Θ(n lg n). Prova: existe solução ótima que
  contém a tarefa que termina primeiro (troca), e o resto é subproblema ótimo.
- **Mochila fracionária**: "maior valor" falha; "maior razão valor/peso" é ótima. Θ(n lg n).
  Prova por troca: transforma a ótima f* na gulosa f sem piorar.
- Kruskal, Prim e Dijkstra também são gulosos.

**Pegadinhas**
- "Não achei contraexemplo" não é prova.
- Razão valor/peso é ótima para a mochila **fracionária**, mas não para a **inteira** (ver PD).

**Ideias de exemplos**
- Mochila W = 60 com itens (v, w): (60,10), (150,30), (120,30), (160,40), (200,50), (150,50), (60,60).
  "Maior valor" pega o item 5 inteiro e 1/4 do item 4: valor 240. "Maior v/w" (razões 6,5,4,4,4,3,1)
  pega itens 1 e 2 inteiros e 2/3 do 3: valor 290, ótimo.
- Tarefas: A=[0,6), B=[1,3), C=[3,5), D=[5,8), E=[7,9). Terminar primeiro: B, C, D? D começa em 5 >= 5
  sim → B, C, D; E começa em 7 < 8 não. Resposta 3 tarefas. "Começa primeiro" pega A e depois só E:
  2 tarefas (contraexemplo).

**Ideias de exercícios**
- Dê contraexemplo para "escolha a tarefa de menor duração". Resp.: [0,5), [4,6), [5,10): a curta
  [4,6) bloqueia as duas outras.
- Mostre que "maior razão" falha na mochila inteira: W = 50, (60,10), (100,20), (120,30). Gulosa leva
  itens 1 e 2 (160); ótima leva 2 e 3 (220).

### NOVO: Huffman (compressão)
**Conceitos-chave**
- Código de largura fixa vs. variável; variável precisa ser **livre de prefixo** para não ser ambíguo
  (a=0, b=01, c=10, d=1 faz "0100010" virar "acaba" ou "baaac").
- Código = árvore binária com 0 à esquerda e 1 à direita; livre de prefixo ⇔ símbolos só nas folhas.
  Custo = Σ f_i · profundidade(i).
- Huffman junta sempre as **duas árvores de menor peso** (n − 1 uniões). Com heap: Θ(n lg n).
  Prova: existe árvore ótima em que os dois menos frequentes são irmãos no nível mais fundo.

**Ideias de exemplos**
- f_a = 60, f_b = 25, f_c = 10, f_d = 5 (por 100 símbolos): junta c+d (15), depois b+cd (40), depois
  a+bcd. Códigos a = 0, b = 10, c = 110, d = 111. Custo 60 + 50 + 30 + 15 = 155 bits contra 200 do
  código fixo de 2 bits.

**Ideias de exercícios**
- Codifique e decodifique "abacad" com a tabela acima. Resp.: 0 10 0 110 0 111 = "01001100111", 11 bits.

### NOVO: programação dinâmica
**Conceitos-chave**
- "Divisão e conquista com tabela" (Parberry). Use quando a recursão **repete subproblemas**.
  Contar subproblemas distintos (n para Fibonacci, n+1 para barras, (n+1)(W+1) para mochila,
  (m+1)(n+1) para alinhamento, n³ para Floyd-Warshall) dá o tamanho da tabela e, em geral, o tempo.
- *Top-down* (memoização): recursão natural + consulta à tabela inicializada com −1. *Bottom-up*:
  laços do menor para o maior. Mesmo tempo assintótico; bottom-up é mais rápido na prática; top-down
  pode resolver só os subproblemas necessários.
- Precisa de **subestrutura ótima** (solução ótima contém soluções ótimas de subproblemas), provada
  por "corta e cola".
- Para recuperar a solução, guardar escolhas (vetor S do corte de barras) ou refazer o caminho na
  tabela (ConstroiMochila).
- **Pseudopolinomial**: mochila Θ(nW) não é polinomial, pois W ocupa lg W bits (nW = n·2^s).

**Explicações boas**
- Corte de barras com preços p = (1, 3, 11, 16, 19, 10) e n = 6: guloso por maior p_i dá p5 + p1 = 20;
  guloso por p_i/i dá p4 + p2 = 19; ótimo é 2·p3 = 22. Força bruta: 2^(n−1) cortes possíveis.
  Recorrência L_k = max_i (p_i + L_{k−i}); tabela B = 0, 1, 3, 11, 16, 19, 22; S[6] = 3.
- Mochila 0/1 com n = 4, W = 7, (w, v) = (1,10), (3,40), (4,50), (5,70): tabela final do livro, última
  linha 0 10 10 40 50 70 80 90 (resposta 90 = itens 2 e 3).
- Alinhamento de sequências (AGGGCT × AGGCA) com match +2, mismatch −4, gap −1: três escolhas por
  célula (diagonal, gap em Y, gap em X), Θ(mn). Base: M[i][0] = i·gap.

**Pegadinhas**
- `ConstroiMochila` do livro testa `M[j][X] == M[j−1][X − w_j] + v_j` sem verificar `w_j <= X`:
  em C acessa índice negativo. Corrigir com `X >= w_j &&`.
- Memoização com sentinela −1 só funciona se −1 nunca é resposta válida.
- Na prova da mochila o livro compara `|S'| > |S*|` (cardinalidade) onde deveria comparar valor.

**Ideias de exemplos**
- Fibonacci: árvore de Fib(6) ingênua (25 nós) × top-down (só um ramo desce; 11 nós).

**Ideias de exercícios**
- Preencha a tabela do corte de barras para p = (1, 5, 8, 9) e n = 4. Resp.: B = 0, 1, 5, 8, 10 (2+2).
- Quantos subproblemas tem a mochila com n = 50 itens e W = 1000? Resp.: 51 × 1001.
- Prove que CorteBarras ingênuo faz T(n) >= 2^n. Resp.: T(n) = n + Σ_{i<n} T(i) >= n + 2^n − 1.

### NOVO: shellsort
**Conceitos-chave**
- Insertion com saltos: um vetor está **h-ordenado** se toda subsequência de passo h está ordenada.
  Ordena com h decrescentes terminando em 1 (no fim é um insertion sobre vetor "quase ordenado").
- Complexidade depende da sequência de saltos e é **problema em aberto**. Knuth (1, 4, 13, 40, 121,
  364, …) faz O(n^(3/2)) comparações; potências de 2 são ruins (pares e ímpares só se comparam no fim).

**Pegadinhas**
- **Erro do livro**: escreve a sequência de Knuth como "1, 4, 13, 40, 121, 246"; o certo é 364 (h = 3h + 1).
- O pseudocódigo do livro tem uma indexação estranha (`A[j − H[t] + 1]`); para o curso, reescrever
  com `j` andando de h em h.

**Ideias de exemplos**
- O livro dá `{1,3,5,8,4,15,20,7,9,6}` como 5-ordenado (pares (1,15), (3,20), (5,7), (8,9), (4,6)).

**Ideias de exercícios**
- O vetor `{1,3,5,6,4,9,8,7,15,20}` está 3-ordenado? Resp.: sim (1,6,8,20 / 3,4,7 / 5,9,15).

### NOVO: limite inferior para ordenação por comparação
**Conceitos-chave**
- Todo algoritmo correto por comparação precisa distinguir as n! entradas; com k comparações há no
  máximo 2^k execuções distintas (cadeia de sim/não). Pombos: 2^k >= n!, e n! >= (n/2)^(n/2), logo
  k >= (n/2) lg(n/2) = **Ω(n lg n)**. Merge e heap são ótimos.
- Para fugir do limite é preciso **não comparar** (counting, radix) e saber algo sobre os dados.

**Ideias de exercícios**
- Mínimo de comparações no pior caso para ordenar 3 elementos. Resp.: ⌈lg 3!⌉ = ⌈lg 6⌉ = 3.
- E para 5? Resp.: ⌈lg 120⌉ = 7.

### NOVO: counting sort (e menção a radix)
**Conceitos-chave**
- Chaves inteiras em 0..k. C[i] conta ocorrências, depois vira acumulado ("quantos <= i"), e o laço
  final percorre A **de trás para frente** colocando A[j] em B[C[A[j]]] e decrementando. Θ(n + k);
  linear se k = O(n). Estável, não in-place.
- É a sub-rotina do **radix sort**, que **depende** da estabilidade (o livro só cita, não apresenta).

**Pegadinhas**
- Percorrer de frente para trás no último laço destrói a estabilidade.
- k enorme (chaves até 10^9) torna o algoritmo inviável em memória e tempo.

**Ideias de exemplos**
- A = (3,0,5,4,0,3,1,2,0,4), k = 5 (Figura 19.1): contagem C = 3,1,1,2,2,1; acumulado 3,4,5,7,9,10;
  B = 0,0,0,1,2,3,3,4,4,5.

**Ideias de exercícios**
- Por que o laço final vai de n até 1? Resp.: para que, entre iguais, o último da entrada vá para a
  última posição livre do seu bloco, preservando a ordem.

### NOVO: seleção do k-ésimo (só menção)
- Usado como exemplo de **redução**: ordenar e devolver V[k] dá Θ(n lg n). O livro diz que existe
  Θ(n) para qualquer k mas **não mostra** (quickselect/mediana das medianas: outra fonte).
- Exemplo: V = (3,7,12,6,8,234,9,78,45): k = 5 → 9; k = 8 → 78.

### NOVO: union-find (disjoint set)
**Conceitos-chave**
- Partição em grupos com representante; operações MakeSet, FindSet, Union.
- Implementação do livro (não é a floresta clássica): cada elemento guarda `representante` e o
  representante guarda `tamanho`; um vetor de listas L[x] guarda os membros do grupo de x.
  FindSet Θ(1); Union percorre a lista do **menor** grupo, troca o representante e concatena as
  listas: Θ(min dos tamanhos).
- Argumento agregado: cada elemento tem o representante trocado no máximo lg n vezes (o grupo dele
  pelo menos dobra a cada troca), então todas as unions juntas custam O(n lg n). Total O(m + n lg n).
- Cita (sem implementar) a versão com árvores, **união por rank + compressão de caminhos**:
  O(m·α(n)), α <= 4 na prática.

**Pegadinhas**
- Atualizar os representantes do grupo **maior** dá O(n²) no pior caso.

**Ideias de exemplos**
- Elementos 1..8: Union(2,4), (7,3), (1,2), (4,8), (3,5), (5,6) (Figura 13.1). Ao fim: grupo {2,4,1,8}
  com representante 2 e grupo {3,7,5,6} com representante 3.

**Ideias de exercícios**
- Quantas trocas de representante faz a sequência Union(1,2), Union(3,4), Union(1,3)? Resp.: 1 + 1 + 2 = 4.
- Este é o melhor gancho do livro para **análise amortizada** (contagem agregada).

### NOVO: componentes conexos
- `BuscaComponentes`: para cada vértice não visitado, inicia uma busca e marca
  `componente = vértice de origem`. Θ(n + m) com listas, Θ(n²) com matriz (a soma das buscas
  parciais cobre cada vértice e aresta uma vez). Testar se x e y estão juntos = comparar `componente`.
- Exercício: quantas componentes tem o grafo da Figura 23.5? Resp.: 3 ({v1..v7}, {v8, v9}, {v10}).

### NOVO: componentes fortemente conexas (Kosaraju)
**Conceitos-chave**
- Entre duas componentes fortes os arcos só vão num sentido; sempre há uma componente **ralo**.
- Passo 1: DFS completa no **digrafo reverso** só para obter a pós-ordem reversa. Passo 2: DFS no
  digrafo original seguindo essa ordem; cada busca iniciada pinta exatamente uma componente forte.
  Θ(n + m) com listas.

**Ideias de exemplos**
- O digrafo de 8 vértices das Figuras 24.6 e 24.7: pós-ordem reversa (7,8,1,5,4,2,3,6); componentes
  {7,8}, {1,2,4,5}, {3}, {6}.

**Ideias de exercícios**
- Por que não basta uma DFS no digrafo original? Resp.: a partir de 3 a busca visita {1,2,3,4,5},
  que mistura duas componentes.

### NOVO: ordenação topológica
**Conceitos-chave**
- Rotular vértices 1..n com f(u) < f(v) para todo arco uv. Existe **se e só se** o digrafo é acíclico.
  Todo acíclico tem um ralo; o ralo pode receber o último rótulo, e o resto continua acíclico.
- Implementação eficiente: DFS completa e rótulos na ordem da **pós-ordem reversa**. Θ(n + m).
- Aplicação: grade de disciplinas com pré-requisitos.

**Ideias de exemplos**
- Disciplinas: Lógica → C → ED; C → Arquivos; ED → Grafos; Matemática → Grafos. Uma ordem válida:
  Matemática, Lógica, C, Arquivos, ED, Grafos.

**Ideias de exercícios**
- O que acontece se o digrafo tiver ciclo? Resp.: não existe ordenação; a DFS precisa detectar arco de
  volta (o algoritmo do livro supõe acíclico e não verifica).

### NOVO: árvore geradora mínima (Kruskal e Prim)
**Conceitos-chave**
- Corte (S, V−S), arestas que cruzam, aresta mínima do corte. Lema: aresta de ciclo que cruza um
  corte tem uma parceira no mesmo ciclo que também cruza. Teorema do corte: se F está numa AGM e o
  corte respeita F, F ∪ {aresta mínima do corte} está numa AGM. Começa com F = ∅.
- **Kruskal**: ordena arestas e adiciona se não fecha ciclo. Ingênuo (busca para detectar ciclo) O(mn);
  com union-find O(m lg n).
- **Prim**: cresce uma árvore a partir de s; é a busca genérica com **fila de prioridade**. Ingênuo
  O(nm); com heap (prioridade = −menor peso para a árvore) O(m lg n).
- Grafo desconexo → floresta geradora mínima (uma AGM por componente).

**Explicações boas**
- Figura 25.1 lista **as 16 árvores geradoras** de um grafo de 4 vértices e marca as mínimas.
- Mesmo grafo de 11 vértices usado em Kruskal, KruskalUnionFind e Prim, com as tabelas de
  representante/tamanho e de heap passo a passo.

**Pegadinhas**
- Empates permitem AGMs diferentes de mesmo peso.
- O algoritmo de Kruskal com BFS para detectar ciclo busca em G[F], não em G.

**Ideias de exemplos**
- Vértices A, B, C, D; arestas AB 1, BC 2, AC 3, CD 4, BD 5. Kruskal: AB, BC, (AC fecha ciclo), CD →
  peso 7. Prim a partir de D: CD 4, BC 2, AB 1 → mesma árvore.

**Ideias de exercícios**
- Quantas arestas tem a AGM de um grafo conexo com 11 vértices? Resp.: 10.
- Trace Kruskal com union-find no exemplo acima mostrando os representantes.

### NOVO: Bellman-Ford
**Conceitos-chave**
- Relaxa **todos os arcos** n − 1 vezes; todo caminho mínimo tem no máximo n − 1 arcos, então seus
  arcos acabam relaxados na ordem certa. Uma passada extra: se ainda dá para relaxar, há **ciclo
  negativo** (`cicloNeg = 1`). Θ(nm) com listas, Θ(n³) com matriz.
- Aceita pesos negativos; Dijkstra não.

**Ideias de exemplos**
- s→a 4, s→b 5, b→a −3, a→c 2, arcos na ordem (a→c, b→a, s→a, s→b). Iteração 1: a = 4, b = 5.
  Iteração 2: c = 6, a = 2. Iteração 3: c = 4. Precisou das n − 1 = 3 iterações por causa da ordem.
- Figura 27.4: com um ciclo negativo as estimativas continuam caindo a cada iteração.

**Ideias de exercícios**
- Com a ordem (s→a, s→b, b→a, a→c), quantas iterações até estabilizar? Resp.: 1 (a ordem segue os caminhos).
- Quanto tempo leva todos os pares com n Bellman-Fords em grafo denso? Resp.: Θ(n²m) = Θ(n⁴).

### NOVO: Floyd-Warshall
**Conceitos-chave**
- P^k_{ij} = peso do ij-caminho mínimo com internos em {1..k}. P^0 = 0 (i = j), w(ij) ou ∞;
  P^k = min(P^{k−1}_{ij}, P^{k−1}_{ik} + P^{k−1}_{kj}). Três laços com **k por fora**: Θ(n³).
- Nasce de uma recursão "uso k ou não?" que é O(3^n) por par; a tabela n×n×(n+1) colapsa para n×n.
- Predecessor por par (`j.pred[i]`). Aceita arcos negativos; **ciclo negativo** aparece como `W[i][i] < 0` no final.

**Pegadinhas**
- Colocar k como laço **interno** dá resultado errado.
- A versão top-down do livro usa ∞ como marca de "não calculado", que se confunde com distância ∞
  de verdade (recalcula à toa).
- Somar ∞ + algo em C estoura: usar um "infinito" seguro (ex.: INT_MAX/2) ou testar antes de somar.

**Ideias de exemplos**
- Vértices 1, 2, 3; arcos 1→2 (4), 2→3 (1), 1→3 (7), 3→1 (2). Depois de k = 1: 3→2 = 6. k = 2:
  1→3 = 5. k = 3: 2→1 = 3. Matriz final linhas (0,4,5), (3,0,1), (2,6,0).

**Ideias de exercícios**
- Por que n Dijkstras não resolvem o caso com pesos negativos? Resp.: Dijkstra falha com arco negativo.

### NOVO (extra): algoritmo de Johnson
- Todos os pares com arcos negativos: novo vértice s com arcos de peso 0 para todos, Bellman-Ford a
  partir de s, **repondera** w̄(xy) = dist(s,x) + w(xy) − dist(s,y) >= 0 e roda n Dijkstras.
  O((mn + n²) lg n). Somar uma constante a todos os pesos **não** funciona (caminhos com mais arcos
  são penalizados). Bom exercício: dê contraexemplo para "somar constante".

### NOVO (extra): trilhas eulerianas (Fleury)
- Grafo conexo tem trilha euleriana fechada ⇔ todos os graus pares; aberta ⇔ exatamente dois ímpares
  (versões para digrafo com entrada = saída). Fleury: só atravessa arco "inseguro" (que não está em
  ciclo) se não houver alternativa. Custoso (testa segurança com busca). Bom tema de desafio/curiosidade
  (pontes de Königsberg), não prioritário.

### NOVO (extra): redução, P e NP
**Conceitos-chave**
- Reduzir A a B = resolver A transformando a instância (f), chamando um algoritmo de B e convertendo a
  resposta (g). Exemplos: Seleção → Ordenação; Quadrado ↔ Multiplicação (xy = ((x+y)² − x² − y²)/2);
  Escalonamento → Conjunto Independente (aresta entre tarefas incompatíveis); Caminho Hamiltoniano →
  Ciclo Hamiltoniano (vértice novo ligado a todos); BARRA → MOCHILA; SUBSETSUM → MOCHILA.
- Decisão (sim/não) vs. otimização; certificado positivo; algoritmo verificador; P, NP, NP-completo,
  NP-difícil; Cook-Levin (3-SAT); 3-SAT → CLIQUE → VERTEXCOVER (complemento, k' = n − k).

**Pegadinhas**
- Provar "se e somente se" numa redução **não** prova a redução na direção contrária.
- O livro passa de decisão para otimização testando k = 0..nC um por um: isso é pseudopolinomial
  (busca binária em k resolveria com O(lg(nC)) chamadas).

**Ideias de exercícios**
- Reduza Quadrado a Multiplicação e Multiplicação a Quadrado. Resp.: ⟨a⟩ → ⟨a, a⟩; a fórmula acima.
- Mostre que BIPARTIDO está em NP. Resp.: certificado é o conjunto X; verificar cada aresta.

## Recomendações de assuntos novos
Em ordem de prioridade para o LPEDC, considerando a força do livro e o encaixe com o C do curso:

1. **Recorrências e teorema mestre** (logo depois de 0077/0078 ou junto do merge sort). É o ponto mais
   forte do livro: quatro métodos, a regra "provar exatamente a expressão", o truque de fortalecer a
   hipótese, versão simplificada do mestre (a vs. b^k) e uma lista pronta de recorrências com resposta.
2. **Programação dinâmica** (Fibonacci memo → corte de barras → mochila 0/1 → alinhamento). Sequência
   didática impecável: recursão ingênua, árvore com repetição, contagem de subproblemas, top-down,
   bottom-up, reconstrução da solução. Tudo vira C com vetores e matrizes simples.
3. **Algoritmos gulosos + Huffman** (escalonamento, mochila fracionária, Huffman com heap). Ensina a
   cultura do contraexemplo e reaproveita heap e qsort do curso.
4. **Divisão e conquista com Karatsuba** (curto; bom fechamento do módulo de recorrências).
5. **Ordenação linear e limite inferior** (counting sort + argumento das n! folhas; radix com outra fonte).
   Shellsort pode entrar como "variação do insertion" no módulo 13.
6. **Union-find** (implementação com listas e "atualiza o menor", depois menção à floresta com rank e
   compressão) seguido de **Kruskal**; e **Prim** com heap, reaproveitando 0107.
7. **Ordenação topológica e componentes** (conexos e fortemente conexos) como extensões da DFS (0116),
   usando as listas de pré/pós-ordem.
8. **Bellman-Ford e Floyd-Warshall** depois de Dijkstra (0117), com o contraexemplo de peso negativo
   como motivação.
9. Opcionais/curiosidades: Johnson, trilhas eulerianas, redução e P vs NP (um assunto de fechamento
   "o que não dá para resolver rápido"), análise de caso médio e o/ω.

Para os candidatos sem cobertura (backtracking, amortizada, trie, rubro-negra, B, busca de padrões,
matriz esparsa, skip list, AVL, hash detalhado, seleção linear) este livro não serve; buscar em
Feofiloff, Tenenbaum ou nas notas de aula.
