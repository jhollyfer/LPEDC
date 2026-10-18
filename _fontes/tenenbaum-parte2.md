# Fichamento — Tenenbaum, Langsam, Augenstein: "Estruturas de Dados Usando C" (parte 2)

- **Título:** Estruturas de Dados Usando C (tradução brasileira, Makron Books).
- **Autores:** Aaron M. Tenenbaum, Yedidyah Langsam, Moshe J. Augenstein.
- **Arquivo lido:** `0aea0b0f-ebookEstruturas_de_Dados_Usando_C_Tenenbaum.md`, linhas **9590 a 17802**
  (lidas por completo): cap. 6 (classificação), cap. 7 (busca), cap. 8 (grafos), cap. 9 (gerenciamento de
  armazenamento), mais bibliografia e índice analítico (só referências, sem conteúdo didático).
- **Avaliação geral:** obra de referência densa e rigorosa, muito mais profunda que o necessário para um
  curso introdutório: analisa cada algoritmo com contagem de comparações, casos melhor/pior/médio e
  variantes pouco conhecidas (Bsort, Cook-Kim, Brent, LH2P, Schorr-Waite, sistema buddy). Os exemplos
  numéricos recorrentes (o vetor `25 57 48 37 12 92 86 33` atravessa todo o cap. 6) são ótimos para
  comparar algoritmos lado a lado. Pontos fracos para o LPEDC: C pré-ANSI (parâmetros no estilo K&R,
  `TRUE/FALSE` por macro, "pools" de nós em vetor com `getnode/freenode` em vez de `malloc`), muito
  pseudocódigo misturado com C, tradução com jargão estranho ("classificação" = ordenação,
  "espalhamento" = hashing, "reespalhamento" = endereçamento aberto, "provas" = sondagens,
  "sistema em turma" = buddy system, "hiperpaginação" = thrashing) e o OCR introduziu muitos erros
  nos códigos e fórmulas. Há também **bugs reais** em alguns códigos (listados em "Obsoleto / evitar").
  Use como fonte de ideias, análises e exercícios — nunca copie código daqui sem revisar.

---

## Glossário de tradução (útil para o curso inteiro)

| Termo no livro | Termo que o LPEDC deve usar |
|---|---|
| classificação / classificar | ordenação / ordenar (sort) |
| classificação por bolha, seleção direta, inserção simples, intercalação | bubble, selection, insertion, merge sort |
| classificação por troca de partição | quicksort |
| classificação de raízes | radix sort |
| classificação de Shell / incremento decrescente | shell sort |
| classificação in loco | ordenação in-place |
| espalhamento, função de espalhamento | hashing, função hash |
| reespalhamento, teste linear | endereçamento aberto, sondagem linear |
| provas | sondagens (probes) |
| espalhamento combinado | coalesced hashing |
| encadeamento separado | encadeamento (separate chaining) |
| fator de carga (lf) | fator de carga (α = n / m) |
| arco / nó de grafo | aresta / vértice |
| dígrafo, dag | grafo dirigido, grafo acíclico dirigido |
| percurso em profundidade / em largura | DFS / BFS |
| floresta geradora, árvore geradora mínima | floresta de busca, árvore geradora mínima (MST) |
| sistema em turma, companheiro | buddy system, buddy |
| marca limítrofe | boundary tag |
| hiperpaginação | thrashing |
| primeira/melhor/pior escolha | first fit / best fit / worst fit |

---

### 0071-eficiencia
- **Conceitos-chave:** três custos competem: tempo do programador, tempo de máquina e espaço. Para
  arquivos pequenos ou programas rodados uma única vez, o método simples basta — mas "ineficiente" é
  aceitável, "incorreto" nunca. Mede-se o tempo não em segundos (dependem da máquina), mas pelo número
  de **operações críticas**: comparações de chaves, trocas, movimentações. Duas formas de estimar:
  análise matemática (melhor/pior/médio) ou medição empírica com vários arquivos de teste.
- **Boa explicação:** a tabela de `f(n) = 0,01n² + 10n`. Para n pequeno o termo `10n` domina (dobrar n
  ~dobra o tempo); em n = 1000 os dois termos empatam (10.000 cada); depois o `n²` domina e dobrar n
  ~quadruplica o tempo. Mostra visualmente por que só o termo de maior ordem importa "no limite" e por
  que para n pequeno as constantes podem inverter a escolha.
- **Ideia didática forte:** "ordenar ou não ordenar?" — se vou buscar UMA vez, uma busca sequencial
  custa menos que ordenar; se vou buscar milhares de vezes, ordenar uma vez e usar busca binária
  compensa. Não há resposta universal; depende do uso.
- **Pegadinhas:** escolher um algoritmo "porque é O(n log n)" sem olhar constantes e tamanho real da
  entrada; contar `j++` do laço como operação crítica (não é: o custo dominante é a comparação/troca).
- **Ideias de exercícios:**
  - Instrumentar bubble, selection e insertion com contadores globais de comparações e trocas; rodar
    com vetores de 10, 100 e 1000 elementos aleatórios (0–999), ordenados e invertidos; tabular.
    (Resp. esperada: insertion ≈ n comparações no ordenado e ≈ n²/2 no invertido; selection sempre
    n(n−1)/2 comparações e n−1 trocas.)
  - Dada `T(n) = a·n² + b·n·log₂n`, para que n os dois termos se igualam? (Resp.: `a·n = b·log₂n`;
    resolver numericamente para a = 1, b = 100: n ≈ 997.)
  - Ordenar as condições de `if (c1 && c2 && c3)`: sabendo o custo de avaliar cada uma e a
    probabilidade de ser falsa, qual ordem minimiza o tempo médio? (Resp.: avaliar primeiro as baratas
    e com alta chance de serem falsas — razão custo / P(falsa) crescente; bom gancho com curto-circuito.)

### 0072-big-o
- **Conceitos-chave:** definição formal: f(n) é O(g(n)) se existem constantes positivas a e b tais que
  f(n) ≤ a·g(n) para todo n ≥ b. Exemplo do livro: n² + 100n ≤ 2n² para n ≥ 100 (a = 2, b = 100).
  Propriedades: transitividade; constantes são O(1); polinômio de grau k é O(nᵏ); todos os logaritmos
  são da mesma ordem (log_m n = log_m k · log_k n), por isso se omite a base. Hierarquia:
  1 < log n < (log n)ᵏ < n < n log n < n² < nᵏ < dⁿ. Polinomial × exponencial: 2¹⁰ = 1024, mas 2¹⁰⁰ tem
  31 dígitos — problemas exponenciais são "intratáveis".
- **Analogia boa:** multiplicar a entrada por 100 multiplica o tempo por menos de 200 num algoritmo
  O(n log n), mas por 10.000 num O(n²).
- **Resultado bonito para bônus:** qualquer ordenação baseada em comparações precisa de pelo menos
  log₂(n!) ≈ n log n comparações no pior caso (árvore de decisão com n! folhas; uma árvore binária com
  n! folhas tem altura ≥ log₂ n!). Para n = 3: 6 permutações → pelo menos 3 comparações.
- **Pegadinhas:** O(·) é limite superior — n² também é O(n³), mas se pede o limite mais justo, com
  coeficiente 1; achar que O(n log n) é sempre mais rápido que O(n²) para qualquer n.
- **Exercícios:**
  - Mostrar a, b para provar que 10n² + 37n + 153 é O(n²). (Ex.: a = 11, b = 41.)
  - Quantas comparações para achar máximo e mínimo de n elementos? (Resp.: ingênuo 2n−2; em pares,
    ⌈3n/2⌉−2.) Para achar o maior e o segundo maior? (Resp.: n + ⌈log₂n⌉ − 2, via "torneio".)
  - Provar que f(1)=1, f(n)=f(n−1)+1/n é O(log n) (série harmônica).

### 0073-invariantes
- **Gancho do livro:** o particionamento do quicksort mantém o invariante "tudo acima de `up` é ≥ pivô,
  tudo abaixo de `down` é ≤ pivô" — ótimo exemplo de invariante de laço que prova corretude.
- **Outro:** após a passada i do bubble sort, `x[n−i..n−1]` estão na posição final; após a iteração k do
  insertion sort, `x[0..k]` está ordenado (não necessariamente na posição final).
- **Exercício:** provar que, se o pivô a fica na posição j com tudo à esquerda ≤ a e tudo à direita ≥ a,
  então a é o (j+1)-ésimo menor e não sai mais dali.

### 0074-tad
- **Conceitos-chave:** o livro especifica o **dicionário** (tabela de busca) como TAD definido sobre um
  *conjunto* (não sequência): `member(tbl, k)`, `search(tbl, k)` (devolve registro ou "registro nulo"),
  `insert(tbl, r)` com pré-condição "chave ainda não existe", `delete(tbl, k)`. Distingue **tabela
  desordenada** (só busca por chave) de **tabela ordenada** (tem primeiro, último, sucessor).
- **Ideia:** usar o dicionário como fio condutor dos módulos 13–15: a mesma interface `.h` implementada
  com vetor desordenado, vetor ordenado + busca binária, BST e tabela hash, comparando custos.
- **Terminologia útil:** chave interna (dentro do registro) × externa (tabela à parte); chave primária
  (única) × secundária (pode repetir, ex.: "estado" num cadastro); busca interna (memória) × externa
  (disco); "busca e inserção" (insere se não achar).

### 0075-vetor-dinamico / 0078-lista-ordenada (ganchos)
- Remover de um vetor **desordenado**: copiar o último elemento para o buraco e decrementar n — O(1).
  Num vetor que precisa manter ordem, remover move metade dos elementos em média. Em lista ligada,
  remover é barato em qualquer caso.
- "Inserção de lista": insertion sort sobre um vetor auxiliar `link[]` — insere ajustando índices, sem
  deslocar dados (comparações continuam O(n²), mas movimentações caem para O(n)). Bom exercício de
  lista ordenada em vetor.

### 0089-busca-sequencial
- **Conceitos-chave:** percorre até achar; sucesso custa em média (n+1)/2 comparações, fracasso custa n.
  Versão "busca e inserção": se não achar, insere no fim (exige espaço reservado). **Sentinela:** colocar
  a própria chave em `k[n]` antes de buscar elimina o teste `i < n` do laço (cada iteração faz uma
  comparação em vez de duas). Em lista ligada, a sentinela exige ponteiro para o último nó.
- **Ideias boas:**
  - Se as probabilidades de acesso forem desiguais, ordenar por probabilidade decrescente minimiza
    p(0)·1 + p(1)·2 + … Exemplo do livro: registros de calouros e formandos são consultados mais.
  - **Mover-para-frente** (achou → move para o início) × **transposição** (achou → troca com o anterior).
    Transposição é melhor a longo prazo com distribuição fixa; mover-para-frente reage mais rápido a
    mudanças e tem melhor pior caso. Transposição funciona bem em vetor; mover-para-frente só em lista.
  - Tabela ordenada: busca sem sucesso para assim que acha chave maior (n/2 em média). Muitas consultas
    acumuladas e ordenadas podem ser respondidas numa única passada paralela ("arquivo mestre" +
    "arquivo de transações").
  - **Busca sequencial indexada:** índice com cada k-ésima chave; busca no índice e depois num trecho
    pequeno da tabela. Índice secundário = índice do índice (precursor da árvore B+).
- **Pegadinhas:** esquecer de verificar capacidade na busca-e-inserção (estouro do vetor); com chaves
  repetidas, a busca indexada pode não devolver a primeira ocorrência.
- **Exemplos:** vetor `{7, 3, 9, 3, 5}` buscando 3 (acha na posição 1 com 2 comparações) e 8 (5
  comparações); depois a versão com sentinela contando comparações.
- **Exercícios:**
  - Implementar busca sequencial com e sem sentinela e contar comparações para 10⁶ buscas.
  - Implementar mover-para-frente numa lista ligada e simular acessos com 80% concentrados em 20% das
    chaves; medir o comprimento médio percorrido antes e depois.
  - Busca que começa no último elemento encontrado e pode ir para frente ou para trás (lista dupla).

### 0090-busca-binaria
- **Conceitos-chave:** versão iterativa com `low`, `hi`, `mid = (low+hi)/2`; ~log₂ n iterações. Em C cada
  iteração faz duas comparações de chave (`==` e `<`), então são ~2 log₂ n comparações. Só funciona em
  vetor (precisa de índice consecutivo) — inútil se há muitas inserções/remoções.
- **Visão bonita:** um vetor ordenado é uma BST implícita — o meio é a raiz, as metades são as subárvores.
- **Variações (bônus):**
  - **Busca por interpolação:** estima a posição por regra de três:
    `mid = low + (high−low)·(key−k[low])/(k[high]−k[low])`. Com chaves uniformes: ~log₂(log₂ n)
    comparações; com chaves aglomeradas degenera para O(n). Dado real do livro: lista de ~40.000 nomes —
    binária ~16 comparações, interpolação 134 (nomes não são uniformes: muitos "Silva", poucos "Quiroga"),
    interpolação robusta 12,5.
  - "Lista preenchida": vetor ordenado com buracos marcados por flag, para permitir inserções sem
    deslocar tudo.
  - Busca de Fibonacci (divide pelos números de Fibonacci em vez de pela metade).
- **Pegadinhas:** `mid = (low + hi)/2` pode estourar `int` para vetores gigantes (usar
  `low + (hi−low)/2` — o livro não menciona); laço `while (low <= hi)` vs `<` (erro de um).
- **Exercícios:**
  - Modificar a busca binária para, em caso de falha, devolver o índice i tal que k[i] < key < k[i+1]
    (ponto de inserção; −1 se key < k[0]).
  - Contar comparações da binária vs. interpolação em vetor uniforme (0, 10, 20, …) e em vetor
    exponencial (1, 2, 4, 8, …). (Resp.: interpolação ganha no uniforme e perde feio no exponencial.)

### 0091-bubble-sort
- **Conceitos-chave:** compara vizinhos e troca os fora de ordem; após a passada i o i-ésimo maior está
  no lugar ("borbulha"). Duas melhorias: (1) a passada i não precisa olhar os últimos i elementos;
  (2) flag `switched`: se uma passada não trocou nada, acabou. Com isso é O(n) no vetor já ordenado,
  mas continua O(n²) no médio/pior. Espaço O(1). É, segundo o livro, provavelmente o menos eficiente
  de todos; o custo real está mais nas trocas que nas comparações.
- **Exemplo pronto (vetor do livro):** `25 57 48 37 12 92 86 33`
  - passada 1 → `25 48 37 12 57 86 33 92` (92 chegou ao fim)
  - passada 2 → `25 37 12 48 57 33 86 92`
  - passada 3 → `25 12 37 48 33 57 86 92`
  - passada 4 → `12 25 37 33 48 57 86 92`
  - passada 5 → `12 25 33 37 48 57 86 92` (ordenado; passada 6 não troca e encerra)
- **Observação interessante:** o número de passadas necessárias é a maior distância que um elemento
  precisa andar "para a esquerda" (o 33 sai da posição 7 para a 2: 5 passadas). Elementos pequenos no
  fim são "tartarugas". Daí o **cocktail/shaker sort** (passadas alternando direção).
- **Pegadinhas:** laço interno indo até `n−1` e acessando `x[j+1]` fora do vetor; esquecer de zerar a
  flag a cada passada.
- **Exercícios:**
  - Implementar o shaker sort e contar passadas no vetor acima (resp.: menos que o bubble).
  - **Odd-even transposition sort:** passadas alternadas comparando pares (ímpar, ímpar+1) e
    (par, par+1). Qual a condição de parada? (Resp.: duas passadas seguidas sem trocas.)
  - Contar trocas do bubble num vetor invertido de n elementos. (Resp.: n(n−1)/2.)

### 0092-selection-sort
- **Conceitos-chave:** o livro apresenta toda ordenação por seleção como "fila de prioridade genérica":
  insere todos numa fila de prioridade e retira sempre o máximo, preenchendo o vetor de trás para frente.
  O selection sort é o caso em que a fila é o próprio vetor desordenado: a cada passo acha o maior entre
  `x[0..i]` e troca com `x[i]`. Sempre n(n−1)/2 comparações e exatamente n−1 trocas,
  independentemente da entrada (não melhora com vetor ordenado).
- **Analogia/insight:** heapsort = mesma ideia com a fila de prioridade implementada por heap;
  insertion sort = fila de prioridade como vetor ordenado (a "seleção" fica trivial).
- **Quando usar:** registros grandes (trocas caras) e chaves baratas de comparar — selection faz bem
  menos movimentações que insertion.
- **Pegadinhas:** no código do livro há `x[ind]` em vez de `x[indx]` (erro); selection **não é estável**
  na forma clássica de troca.
- **Exercícios:**
  - Ordenar `25 57 48 37 12 92 86 33` mostrando o vetor após cada troca (versão "maior vai para o fim").
  - Mostrar um vetor com chaves repetidas em que a selection troca a ordem relativa de iguais
    (ex.: `(3,a) (3,b) (1,c)` → `(1,c) (3,b) (3,a)`).

### 0093-insertion-sort
- **Conceitos-chave:** insere `x[k]` no trecho já ordenado `x[0..k−1]` deslocando os maiores uma casa.
  Ordenado: n−1 comparações (O(n)); invertido: n(n−1)/2; médio O(n²). Espaço O(1). Quanto mais perto
  de ordenado, mais rápido — é o melhor algoritmo simples para entradas quase ordenadas.
- **Insight importante:** usar busca binária para achar a posição reduz as comparações para O(n log n),
  mas o deslocamento continua O(n²) — portanto não melhora a ordem global. Ótima pegadinha conceitual.
- **Número prático do livro:** o ponto de equilíbrio com o quicksort fica em torno de 20–30 elementos
  (com o heapsort, 60–70). Otimização clássica: quicksort que passa a usar insertion em subvetores
  pequenos.
- **Shell sort (bônus dentro do tópico):** ordena por inserção os subvetores de elementos separados por
  um incremento k (5, depois 3, depois 1). Exemplo do livro com `25 57 48 37 12 92 86 33` e incrementos
  (5, 3, 1):
  - inc 5 → `25 57 33 37 12 92 86 48`
  - inc 3 → `25 12 33 37 48 92 86 57`
  - inc 1 → `12 25 33 37 48 57 86 92`
  Por que funciona: cada passada deixa o vetor "mais ordenado" e a passada final com incremento 1 é um
  insertion sort sobre vetor quase ordenado. Uma ordenação parcial por k não é desfeita pelas passadas
  seguintes. Os incrementos não devem ter divisores comuns; custo empírico ~n^1,25, O(n^1,5) para
  certas sequências. Recomendado para algumas centenas de elementos.
- **Pegadinhas:** no laço `for (i = k−1; i >= 0 && y < x[i]; i--)` inverter a ordem das condições acessa
  `x[−1]` (o curto-circuito protege!) — ótimo gancho com 0013-logicos.
- **Exercícios:**
  - Rastrear o insertion sort em `5 2 4 6 1 3` mostrando o vetor após cada k. (Resp.: `2 5 4 6 1 3`,
    `2 4 5 6 1 3`, `2 4 5 6 1 3`, `1 2 4 5 6 3`, `1 2 3 4 5 6`.)
  - Contar comparações e deslocamentos do insertion e da insertion com busca binária em vetores de
    1000 elementos invertidos.
  - Implementar shell sort com incrementos (5,3,1) e com a sequência de Knuth (1, 4, 13, 40, …) e
    comparar.

### 0094-merge-sort
- **Conceitos-chave:** intercalar (merge) dois vetores ordenados em um terceiro: compara as frentes,
  copia o menor, e no fim despeja o que sobrou. O livro apresenta primeiro a versão **iterativa de baixo
  para cima**: intercala blocos de tamanho 1, depois 2, 4, 8… até n. No máximo log₂ n passadas de até n
  comparações → nunca mais que n log₂ n comparações (média ainda menor: ≈ n log₂ n − n + 1, contra
  1,386 n log₂ n do quicksort). Custos: vetor auxiliar O(n) e cerca do dobro de atribuições do quicksort.
- **Exemplo pronto:** `[25] [57] [48] [37] [12] [92] [86] [33]` → `[25 57] [37 48] [12 92] [33 86]` →
  `[25 37 48 57] [12 33 86 92]` → `[12 25 33 37 48 57 86 92]`.
- **Comparação conceitual excelente:** merge sort = dividir fácil (pela metade), juntar difícil
  (intercalar); quicksort = dividir difícil (particionar), juntar fácil (já está no lugar). Insertion é
  um merge "desequilibrado" (1 elemento + resto); selection é um quick "desequilibrado" (maior + resto).
- **Variações:** alternar x→aux e aux→x para evitar cópia de volta; **merge natural** (aproveita trechos
  já crescentes); merge sort em **lista ligada** dispensa o vetor auxiliar e só mexe em ponteiros —
  ideal para registros grandes.
- **Pegadinhas:** último bloco de tamanho menor quando n não é potência de 2; usar `<` em vez de `<=`
  na comparação quebra a estabilidade.
- **Exercícios:**
  - Escrever `merge(x, lb, mid, ub)` e a versão recursiva `msort(x, lb, ub)`; depois a versão iterativa.
  - Intercalar k arquivos ordenados usando um min-heap com (valor, nº do arquivo).
  - Número médio de comparações para intercalar vetores de tamanhos 2 e 1 (resp. pela fórmula do livro
    a(l1,l2) = l1·l2·(l1+l2+2)/((l1+1)(l2+1)) = 2·1·5/(3·2) = 5/3).

### 0095-quick-sort
- **Conceitos-chave:** escolhe pivô, particiona (≤ pivô à esquerda, ≥ à direita, pivô na posição final)
  e ordena recursivamente as duas partes. Particionamento do livro com dois índices: `down` sobe até
  achar elemento > pivô, `up` desce até achar ≤ pivô, troca se `down < up`; no fim troca o pivô com
  `x[up]`. Exemplo: `25 57 48 37 12 92 86 33` com pivô 25 vira `12 25 48 37 57 92 86 33`.
- **Análise:** pivô sempre no meio → n log₂ n; vetor **já ordenado** (ou invertido) com pivô = primeiro
  elemento → partições 0 e n−1 → O(n²). "O quicksort funciona melhor no caos e pior na ordem" — o oposto
  do bubble. Média ~1,386 n log₂ n; na prática costuma ser o mais rápido.
- **Escolha de pivô:** mediana-de-três (primeiro, meio, último) evita o pior caso em vetor ordenado;
  pivô aleatório; "meansort" (média do subvetor); Bsort (pivô do meio + pequenas trocas que detectam
  subvetores já ordenados).
- **Versão não recursiva:** pilha explícita com pares (lb, ub); sempre empilhar o subvetor **maior** e
  processar o menor primeiro → pilha de no máximo O(log n). Outra vantagem: localidade de referência
  (bom para cache/memória virtual).
- **Pegadinhas:** laço de `down` sem o limite `down < ub` sai do vetor quando o pivô é o maior;
  recursão em vetor ordenado de 10⁵ elementos estoura a pilha de chamadas (gancho com 0031); quicksort
  não é estável.
- **Exercícios:**
  - Rastrear a partição em `25 57 48 37 12 92 86 33` mostrando cada troca.
  - Medir tempo do quicksort (pivô = primeiro) em vetor aleatório vs. ordenado de 20.000 elementos;
    repetir com mediana-de-três.
  - Quicksort híbrido: insertion para subvetores com menos de s elementos; achar o melhor s
    experimentalmente (resp. típica: 10–20).
  - Contar a profundidade máxima de recursão com e sem a regra "processar o menor primeiro".

### 0096-comparando
- **Conceitos-chave:** **estável** = mantém a ordem relativa de chaves iguais; **in loco** = espaço extra
  O(1); interna (memória) × externa (disco). Ordenar ponteiros/índices em vez dos registros
  ("classificação por endereço") quando os registros são grandes. Não existe "melhor" ordenação geral.
- **Quadro-resumo extraível do livro:**

| Algoritmo | Melhor | Médio | Pior | Espaço extra | Estável | Observação do livro |
|---|---|---|---|---|---|---|
| bubble (com flag) | n | n² | n² | 1 | sim | o mais lento; bom só p/ quase ordenado |
| selection | n² | n² | n² | 1 | não | poucas trocas (n−1) |
| insertion | n | n² | n² | 1 | sim | melhor simples p/ quase ordenado e n < ~25 |
| shell | — | ~n^1,25 | n^1,5 | 1 | não | bom p/ centenas de elementos |
| merge | n log n | n log n | n log n | n | sim | menos comparações; o dobro de atribuições |
| quick | n log n | 1,39 n log n | n² | log n (pilha) | não | o mais rápido na média |
| heap | n log n | n log n | n log n | 1 | não | ~2× mais lento que quick na média |
| radix | m·n | m·n | m·n | n + filas | sim | sem comparações de chaves |

- **Recomendações práticas do livro:** quase ordenado e pequeno → insertion; grande e aleatório →
  quicksort (pivô do meio); precisa de garantia de pior caso → heapsort ou merge; lista ligada → merge
  ou inserção de lista; registros enormes → ordenar índices.
- **Exercício:** dados 5 cenários (ex.: "10 milhões de inteiros aleatórios", "planilha de 50 linhas
  quase ordenada", "registros de 2 KB", "precisa ser estável"), escolher o algoritmo e justificar.
- **Exercício bônus:** ordenação por **contagem** (count[i] = nº de elementos menores que x[i]) e por
  **distribuição** (histograma de inteiros entre a e b) — O(n + faixa), sem comparações.

### 0097-arvores / 0099-bst-busca-insercao
- **Conceitos-chave:** BST: à esquerda chaves menores, à direita maiores ou iguais; percurso em ordem
  devolve a sequência ordenada ("tree sort"). Busca e inserção descem um caminho; a forma da árvore
  depende da ordem de inserção. Sentinela em árvore: todos os ponteiros nulos apontam para um nó
  sentinela onde se grava a chave antes de buscar (laço `while (key != k(p))` sem teste de nulo).
- **Exemplo do livro (ótimo para aula):** inserir `4 8 12 17 26` (ordenado) gera um "pau" com 14
  comparações; inserir `12 8 17 4 26` gera árvore balanceada com 10 comparações. Mesmo conjunto,
  custos diferentes.
- **Medidas:** comprimento interno de caminhos i (soma dos níveis); busca com sucesso média = (i + n)/n.
  Estendendo a árvore com "nós externos" nos n+1 ponteiros nulos, o comprimento externo e satisfaz
  **e = i + 2n**, e a busca sem sucesso média = e/(n+1). Em BST aleatória, busca média ≈ 2 ln n ≈
  1,386 log₂ n — só ~39% pior que a árvore perfeitamente balanceada.
- **Pegadinhas:** toda BST com n nós tem n+1 ponteiros nulos; inserir dados já ordenados degenera em
  lista (O(n)); chave repetida vai sempre para a direita.
- **Exercícios:**
  - Inserir `50 30 70 20 40 60 80` e depois `20 30 40 50 60 70 80` numa BST vazia; desenhar e calcular a
    altura e o comprimento interno de cada uma. (Resp.: altura 2 e i = 10; altura 6 e i = 21.)
  - Quantas permutações de 1..3 geram cada uma das 5 BSTs possíveis? (Resp.: a balanceada (raiz 2) é
    gerada por 2 permutações; as outras 4 por 1 cada.)
  - Implementar `sinsert(tree, key, rec)` em C com `malloc`.

### 0100-bst-remocao
- **Conceitos-chave:** três casos: folha (remove), um filho (o filho sobe), dois filhos (o **sucessor em
  ordem** — mais à esquerda da subárvore direita — ocupa o lugar; o filho direito do sucessor sobe para
  o lugar dele, pois o sucessor nunca tem filho esquerdo).
- **Exemplo do livro:** árvore com raiz 8; nível 1: 3, 11; nível 2: 1, 5, 9, 14; nível 3: 6, 10, 12, 15;
  nível 4: 7, 13 (6 é filho direito de 5, 7 filho direito de 6, 12 filho esquerdo de 14, 13 filho
  direito de 12). Remover 15 (folha); remover 5 (um filho: 6 sobe com 7); remover 11 (dois filhos: 12
  assume o lugar e 13 sobe para onde 12 estava). Comprimento interno i = 30, n = 13, e = 56 = 30 + 2·13.
- **Curiosidade (bônus):** remoções sempre pelo sucessor tendem, após muitas inserções/remoções, a
  piorar a árvore; alternar sucessor/predecessor ("eliminação simétrica") mantém a árvore melhor que a
  aleatória.
- **Pegadinhas:** esquecer de atualizar o ponteiro do pai (ou a raiz, quando o nó removido é a raiz);
  vazar memória por não dar `free`; tratar o caso "o sucessor é o próprio filho direito".
- **Exercícios:**
  - Na árvore acima, remover 8 (raiz) e desenhar. (Resp.: 9 sobe para a raiz; 10 vira filho esquerdo
    de 11.)
  - Escrever a remoção usando o predecessor em ordem.
  - Remover todas as chaves entre k1 e k2 (inclusive).

### 0101-avl
- **Conceitos-chave:** altura da árvore vazia = −1; balanceamento de um nó = altura(esq) − altura(dir);
  AVL exige |bal| ≤ 1 em todos os nós. Após inserção, só desbalanceia se o novo nó entra do lado
  "pesado" de um ancestral; o mais jovem ancestral desbalanceado (ya) é o único a consertar. Dois casos:
  mesmo lado (rotação simples) e lados opostos (rotação dupla: primeiro no filho, depois no ancestral).
  Rotação esquerda em p: `q = right(p); hold = left(q); left(q) = p; right(p) = hold;` — preserva a ordem
  do percurso em ordem.
- **Números úteis:** altura máxima ≈ 1,44 log₂ n (nunca mais que 44% pior que a perfeita); na prática
  ~log₂ n + 0,25. Rotação em ~46,5% das inserções; inserção precisa de no máximo uma rotação (simples
  ou dupla), remoção pode precisar de O(log n) (média 0,214 por remoção). Árvore de Fibonacci = AVL com
  o menor número de nós para dada altura.
- **Outras árvores balanceadas citadas (bônus):** balanceada por peso (wb[α]) e a de Tarjan
  (caminho mais longo até nó externo ≤ 2× o mais curto — é a ideia da rubro-negra; no máximo uma
  rotação por inserção ou remoção).
- **Pegadinhas:** atualizar os campos `bal` errado após rotação dupla (três subcasos); esquecer de
  religar a subárvore rotacionada ao pai.
- **Exercícios:**
  - Inserir 1..7 em ordem numa AVL vazia, desenhando cada rotação. (Resp.: termina perfeitamente
    balanceada com raiz 4.)
  - Inserir `30 10 20` (caso esquerda-direita → rotação dupla, raiz final 20).

### 0102-heap
- **Conceitos-chave:** max-heap (o livro: "heap descendente") = árvore binária quase completa em que
  cada nó ≤ pai; guardada em vetor: filhos de i em 2i+1 e 2i+2, pai em (i−1)/2. Inserção: coloca no fim e
  sobe trocando com o pai menor (O(log n)). Remoção do máximo: tira a raiz, pega o último elemento e
  desce trocando com o **maior** filho (O(log n)). Qualquer caminho raiz→folha é decrescente.
- **Por que heap e não outra coisa (comparação do livro):** fila de prioridade em lista ordenada →
  inserir O(n); em BST → O(log n) médio mas O(n) pior; heap → O(log n) sempre, sem ponteiros.
- **Exemplo pronto:** inserir `25 57 48 37 12 92 86 33` num max-heap vazio dá o vetor
  `92 37 86 33 12 48 57 25`.
- **Aplicações do livro:** intercalar k arquivos ordenados (min-heap de (valor, arquivo)); achar os k
  maiores de um arquivo enorme com um min-heap de tamanho k; Huffman; Dijkstra e Prim eficientes;
  **torneio** (árvore em que cada nó interno guarda o maior dos dois filhos).
- **Pegadinhas:** confundir heap com BST (heap não permite busca eficiente por chave); escolher o filho
  errado na descida (tem que ser o maior); índice do pai com vetor começando em 1 vs. 0.
- **Exercícios:**
  - Mostrar o vetor do heap acima após 3 remoções do máximo.
  - k maiores de 10⁶ números com heap de tamanho k (resp.: O(n log k)).
  - Heap ternário (filhos 3i+1, 3i+2, 3i+3).

### 0103-heapsort
- **Conceitos-chave:** fase 1 constrói o heap no próprio vetor (inserções sucessivas); fase 2 troca a
  raiz com o último elemento do heap, encolhe o heap e desce o novo topo. In loco, O(n log n) mesmo no
  pior caso. O livro dá o código com todas as sub-rotinas "em linha" (inlined) — hoje desnecessário.
- **Comparação:** ~2× mais lento que o quicksort na média, mas sem o pior caso O(n²); ruim para n
  pequeno (sobrecarga).
- **Exercício:** rastrear o heapsort completo em `25 57 48 37 12 92 86 33` desenhando a árvore após
  cada remoção.

### 0105-hashing
- **Conceitos-chave:** endereçamento direto (chave = índice) é perfeito para 100 itens de código de 2
  dígitos (`part[100]`), mas inviável para códigos de 7 dígitos (10 milhões de posições para alguns
  milhares de itens). Função hash reduz a chave a um índice; **colisão** quando h(k1) = h(k2). Exemplo:
  `h(k) = k % 1000` (últimos 3 dígitos): 4618396 e 4618996 ficam longe; 0000991 e 9846995 ficam perto;
  0596397 colide com 4957397.
- **Boa função hash:** depende de todos os bits da chave; anagramas/permutações devem dar valores
  diferentes; distribui uniformemente; barata de calcular.
  - **Divisão:** `k % m` com m primo. Armadilha: m = 1000 com chaves que terminam igual; e m tal que
    256 % m == 1 (ex.: m = 17) faz o resto ser a soma dos bytes mod m → "steam" e "mates" colidem.
    Ex.: 37956 = 148·256 + 68 e 37956 % 17 = 12 = (148 + 68) % 17.
  - **Multiplicação:** h(k) = ⌊m · frac(k·c)⌋ com c ≈ 0,6180339887 ((√5−1)/2).
  - **Meio do quadrado:** eleva ao quadrado e pega dígitos do meio (fraca, não uniforme).
  - **Dobramento (folding):** quebra a chave em pedaços e soma/XOR. Ex.: `010111001010110` →
    `01011 ⊕ 10010 ⊕ 10110 = 01111` = 15.
  - **Strings:** tratar cada letra como dígito em base 26 (ou 31/256): "hello" =
    8·26⁴ + 5·26³ + 12·26² + 12·26 + 15.
- **Pegadinhas:** hash não preserva ordem → não dá para listar em ordem de chave; funções que
  preservam ordem (`k / c`) costumam ser não uniformes; tabela um pouco maior que o número de itens
  (troca espaço por tempo).
- **Exercícios:**
  - Simular 0,8·m chaves aleatórias e medir % de posições vazias, % com colisão e maior número de
    chaves numa posição, para `k % m` com m primo, m potência de 2, folding com XOR e meio do quadrado.
  - Mostrar duas strings que colidem com "soma dos códigos ASCII % m" e não colidem com base 31.
  - Provar que `(i + c) % m` percorre todas as posições se e só se mdc(c, m) = 1.

### 0106-encadeamento
- **Conceitos-chave:** **encadeamento separado:** vetor de cabeças de lista (`bucket[i]`) e cada lista
  guarda as chaves com o mesmo hash; busca percorre a lista; inserção no fim (ou no início). Vantagens:
  não "enche", remoção trivial, nós não precisam ser contíguos. Custo médio: sucesso ≈ 1 + α/2;
  fracasso ≈ e^(−α) + α (listas desordenadas). Com α = 1: 1,5 e 1,27 sondagens.
- **Exemplo do livro:** m = 10, h = k % 10, inserindo `75 66 42 192 91 40 49 87 67 16 417 130 372 227`
  → lista 0: 40, 130; lista 1: 91; lista 2: 42, 192, 372; lista 5: 75; lista 6: 66, 16; lista 7: 87, 67,
  417, 227; lista 9: 49.
- **Insights:** o fator de carga "engana" no encadeamento (α pode passar de 1 e o espaço dos nós não
  entra na conta); manter cada lista ordenada reduz o custo de busca sem sucesso; truque de guardar só
  o quociente `k / m` no nó (a chave se reconstrói com o índice) — só funciona no encadeamento.
- **Espalhamento combinado (coalesced, bônus):** a lista fica dentro da própria tabela, com campo
  `next` e alocação de posições livres de baixo para cima. Exemplo do livro: m = 10, inserindo
  `14 29 34 28 42 39 84 38` → as cadeias de 4 e 8 se fundem (4→8→7→5→3). Com "porão" (área extra só
  para colisões) ~15% da tabela, tabela cheia com ~1,69 sondagens por busca bem-sucedida.
- **Pegadinhas:** esquecer de liberar todas as listas ao destruir a tabela; hash ruim transforma a
  tabela numa lista única.
- **Exercícios:**
  - Desenhar a tabela do exemplo acima e calcular o nº médio de comparações para buscas bem-sucedidas.
    (Resp.: (1·7 + 2·4 + 3·2 + 4·1)/14 = 25/14 ≈ 1,79.)
  - Implementar dicionário de palavras (contagem de frequência de um texto) com encadeamento.

### 0107-enderecamento-aberto
- **Conceitos-chave:** em caso de colisão, tenta-se outra posição da própria tabela por uma função de
  "reespalhamento". **Sondagem linear:** `i = (i + 1) % m`. Ex. do livro: 0596397 cai em 397 (ocupada)
  e vai para 398; depois 8764397 e 2194398 vão ambos parar em 400.
- **Laço infinito (ótimo exemplo):** com `rh(i) = (i + 2) % 1000`, chave que cai em posição ímpar só
  visita ímpares — se as ímpares encherem, não insere mesmo com metade vazia; com `(i + 200) % 1000`
  cada chave só tem 5 posições possíveis. Regra: passo c com mdc(c, m) = 1, e contar elementos para
  detectar tabela cheia.
- **Agrupamento primário:** na linear, uma sequência de ocupadas "atrai" mais chaves (no exemplo, a
  posição 994 é 5× mais provável que a 401). Soluções: sondagem **quadrática** (h + j²), passo
  dependente da chave, **hash duplo**: `h1 = k % m`, `h2 = 1 + k % (m − 1)` com m primo (elimina também o
  agrupamento secundário, de chaves com o mesmo h1).
- **Tabela de custos do livro (sondagens médias):**

| α | linear (sucesso) | duplo (sucesso) | linear (fracasso) | duplo (fracasso) |
|---|---|---|---|---|
| 25% | 1,17 | 1,15 | 1,39 | 1,33 |
| 50% | 1,50 | 1,39 | 2,50 | 2,00 |
| 75% | 2,50 | 1,85 | 7,50 | 4,00 |
| 90% | 5,50 | 2,56 | 50,50 | 10,00 |
| 95% | 10,50 | 3,15 | 200,50 | 20,00 |

  Fórmulas da linear: sucesso ≈ 0,5/(1−α) + 0,5; fracasso ≈ 0,5/(1−α)² + 0,5. Conclusão do livro:
  evitar sondagem linear acima de ~75% de ocupação. Para disco, porém, a linear acessa blocos vizinhos
  (menos movimento da cabeça).
- **Remoção (pegadinha central):** não se pode simplesmente esvaziar a posição — uma chave que tinha
  "pulado" por ela deixaria de ser encontrada. Solução: marcar como "removido" (lápide/tombstone) e
  continuar a busca ao passar por ela; com muitas remoções, buscas sem sucesso percorrem a tabela toda.
- **Melhorias (bônus):** tabela ordenada de Amble-Knuth (busca sem sucesso para cedo), método de Brent e
  hash em árvore binária (reorganizam na inserção para encurtar buscas), "bit de passagem", preditores.
- **Exercícios:**
  - m = 11, h(k) = k % 11, sondagem linear, inserir `22 1 13 11 24 33 18 42 31`; desenhar a tabela e
    contar sondagens de cada inserção. (Resp.: posições 22→0, 1→1, 13→2, 11→3, 24→4, 33→5, 18→7,
    42→9, 31→10.)
  - Mesmas chaves com hash duplo h2(k) = 1 + k % 10; comparar o total de sondagens.
  - Implementar remoção com lápide e mostrar o bug da remoção ingênua: com m = 11, inserir 22, 33, 44 (hash 0;
    vão para 0, 1, 2), remover 33 "esvaziando" e buscar 44 (não acha).

### 0109-grafos
- **Conceitos-chave:** grafo = vértices + arestas; dirigido (pares ordenados) ou não; grau, grau de
  entrada/saída; adjacente, sucessor, predecessor; grafo ponderado (rede); caminho de comprimento k;
  ciclo; dag. Uma **relação** sobre um conjunto vira grafo (ex.: x→y se x < y e y % x é ímpar, sobre
  {3,5,6,8,10,17}). Um grafo não precisa ser árvore, mas toda árvore é grafo.
- **Representações:** matriz de adjacência (`int adj[N][N]`, O(n²) espaço, testar aresta O(1), percorrer
  sucessores O(n)) × listas de adjacência (espaço O(n + e), sucessores em O(grau)); o livro também mostra
  a versão "multiligada" com lista de nós-cabeçalho + listas de arcos. Na lista, achar quem **chega** num
  vértice é difícil (precisa de lista de entrada também). Não dirigido = matriz simétrica / aresta
  guardada nas duas listas.
- **Fecho transitivo:** `adj2 = adj ⊗ adj` (produto booleano: && no lugar de ×, || no lugar de +) diz
  se há caminho de comprimento 2; path = adj ∨ adj2 ∨ … ∨ adjⁿ, O(n⁴). **Warshall** faz em O(n³):
  `for k, for i, if path[i][k], for j: path[i][j] |= path[k][j]`.
- **Exemplo do livro (problema motivador):** "existe caminho de A a B usando exatamente nr estradas?"
  com `findpath(k, a, b)` recursivo (caminho de 1 = adjacente; senão existe c adjacente a a com caminho
  k−1 de c a b). Defeitos discutidos: recomputa caminhos, não diz qual é o caminho.
- **Pegadinhas:** confundir `adj[i][j]` "de i para j" com "de j para i"; matriz para grafo esparso de
  10⁵ vértices (10¹⁰ células!); esquecer de pôr a aresta nos dois sentidos em grafo não dirigido.
- **Exercícios:**
  - Grafo dirigido A→C, A→D, B→C, C→D, C→E, D→E, E→D: montar matriz, calcular adj², o fecho transitivo
    por potências e por Warshall. (Resp.: A e B alcançam {C, D, E}; C alcança {D, E}; D e E alcançam {D, E} —
    inclusive a si mesmos, pelo ciclo D↔E.)
  - Decidir se uma relação é simétrica / transitiva olhando a matriz.
  - Contar quantos caminhos de comprimento k existem entre dois vértices (produto de matrizes inteiras).

### 0110-bfs
- **Conceitos-chave:** visita todos os sucessores de um vértice antes dos sucessores deles, usando
  **fila**; marca visitado ao enfileirar. Gera árvores largas e baixas. Num grafo não ponderado, o
  caminho na árvore BFS da origem ao alvo é o **menor caminho em número de arestas**. Custo O(n²) com
  matriz, O(n + e) com listas. Árvore BFS não tem arestas "para frente".
- **Três dificuldades de percorrer grafos (boa explicação do livro):** não há primeiro vértice natural
  (e nem todos são alcançáveis — precisa de `select()` para recomeçar de um não visitado); não há ordem
  natural entre sucessores; um vértice pode ser alcançado por vários caminhos (precisa de flag
  `visited`).
- **Exemplo:** grafo não dirigido A–B, A–C, B–D, C–D, D–E, vizinhos em ordem alfabética. BFS de A:
  A, B, C, D, E (níveis: {A}, {B, C}, {D}, {E}); distância A→E = 3.
- **Pegadinhas:** marcar visitado só ao desenfileirar (o vértice entra várias vezes na fila); esquecer
  do laço externo para grafos desconexos.
- **Exercícios:**
  - Labirinto em matriz de caracteres: menor número de passos da entrada à saída com BFS.
  - Contar componentes conexos de um grafo não dirigido.
  - Imprimir o caminho mínimo guardando o vetor `pai[]`.

### 0111-dfs
- **Conceitos-chave:** vai fundo por um caminho até não ter sucessor novo, depois volta (backtracking);
  recursivo ou com pilha explícita (o livro empilha o par (vértice, posição na lista de sucessores)).
  Em árvore, DFS = pré-ordem. Floresta geradora: cada recomeço via `select()` inicia uma nova árvore.
  Classificação das arestas: de árvore, para frente (para descendente não filho), para trás (para
  ancestral) e cruzadas. Em grafo não dirigido, DFS só gera arestas de árvore e para trás.
- **Aplicações:** componentes conexos; **detecção de ciclo** (existe ciclo ⇔ existe aresta para trás;
  em não dirigido, ignorar a aresta para o pai); **ordenação topológica** (a ordem de término — pós-ordem
  — é a ordem topológica invertida); pontos de articulação (bônus).
- **Exemplo:** mesmo grafo do BFS (A–B, A–C, B–D, C–D, D–E). DFS de A: A, B, D, C, E.
- **Exemplo do livro de escalonamento (topológica por contagem — ótimo para aula):** fritar um ovo com
  subtarefas e precedências ("pegar o ovo" antes de "quebrar o ovo", "esquentar o óleo" antes de "pôr o
  ovo na frigideira"…). Guardar em cada vértice o nº de predecessores; a cada "período" executar todos
  com contagem 0 e decrementar os sucessores. Resultado: 6 períodos com no máximo 2 ajudantes. Se
  sobrarem vértices, há ciclo. (É o algoritmo de Kahn.)
- **Pegadinhas:** recursão profunda em grafo grande estoura a pilha; em dirigido, `visited[nd] == true`
  não basta para dizer que há ciclo (pode ser aresta cruzada) — precisa do estado "em andamento" (cinza).
- **Exercícios:**
  - Implementar DFS recursiva e iterativa e comparar as ordens de visita (podem diferir!).
  - Ordenação topológica das disciplinas de um curso com pré-requisitos.
  - Detectar ciclo em grafo dirigido com três cores (branco/cinza/preto).
  - Exercício do livro: algoritmo de DFS que empilha todos os sucessores de uma vez — gera a mesma
    ordem da recursiva? (Resp.: não necessariamente; a ordem dos sucessores fica invertida.)

### 0112-dijkstra
- **Conceitos-chave:** menor caminho com pesos **não negativos**. `distance[s] = 0`, demais ∞; conjunto
  `perm` dos vértices com distância definitiva; a cada passo relaxa os sucessores do vértice atual
  (`distance[current] + w < distance[i]` → atualiza e grava `precede[i]`) e escolhe o não permanente de
  menor distância. Com matriz: O(n²). Com listas de adjacência + heap (fila de prioridade com ajuste de
  chave): O((n + e) log n) — muito melhor em grafos esparsos.
- **Exemplo próprio:** dirigido A→B 4, A→C 1, C→B 2, B→D 1, C→D 5, D→E 3. A partir de A: C = 1,
  B = 3 (via C, melhor que 4 direto), D = 4 (via B), E = 7. Caminho A→C→B→D→E.
- **Pegadinhas (várias no próprio código do livro):** usar `INT_MAX` como ∞ e somar peso → overflow;
  se o destino é inalcançável, o `k` do mínimo nunca é atribuído (lixo/laço infinito); pesos
  negativos quebram o algoritmo.
- **Exercícios:**
  - Rastrear o exemplo acima em tabela (iteração × distâncias).
  - Mapa de cidades com distâncias em km: imprimir rota e total.
  - Mostrar um grafo com aresta negativa em que Dijkstra erra. (Ex.: A→B 2, A→C 3, C→B −2: Dijkstra
    fixa B = 2, mas o certo é 1.)

### 0113-juntando-tudo (ideias de projeto)
- **Árvore geradora mínima (bônus forte):** Prim (cresce uma árvore, sempre a aresta mais barata que sai
  dela; O(n²) com matriz, O((n+e) log n) com heap) e Kruskal (ordena arestas, junta árvores diferentes;
  usa campo `father` — union-find; O(e log e)). O livro prova o Prim pela troca de arestas. Projeto:
  "ligar todas as cidades com o menor custo de cabo".
- **Escalonamento PERT/caminho crítico:** tempo mais cedo (máximo sobre predecessores) e mais tarde
  (mínimo sobre sucessores); caminho crítico onde os dois coincidem.

### 0050-ponteiro-para-funcao / 0051-void-generico (ganchos)
- O livro trabalha com `KEYTYPE`/`RECTYPE` genéricos via `typedef` e notação algorítmica `k(i)`, `r(p)`.
  Bom contraste para mostrar como em C moderno se faz o genérico com `void *` + função de comparação
  (estilo `qsort`/`bsearch`).

### 0053-pilha-e-heap / 0054-malloc-free (cap. 9.3: o que há por trás do `malloc`)
- **Conceitos-chave:** quando os blocos têm tamanho variável, o gerenciador precisa (1) achar um bloco
  livre grande o bastante e (2) juntar blocos livres vizinhos ao liberar. Exemplo do livro: memória de
  1024 palavras, alocam-se blocos de 348, 110 e 212; liberado o de 110 há 464 palavras livres, mas um
  pedido de 400 falha (livre não contíguo); liberado também o de 212, os livres vizinhos se fundem em
  um de 676.
- **Estratégias:** first fit (primeiro que serve), best fit (menor que serve), worst fit (maior). Na
  prática, first fit é o preferido. Aloca-se a **parte final** do bloco livre para não mexer em ponteiros
  da lista. Não deixar "migalhas" menores que um mínimo (vira fragmentação interna em vez de externa).
  Lista livre circular com início rotativo evita acumular blocos pequenos no começo.
- **Exemplos prontos (ótimos para exercício):**
  - Livres 110 e 54; pedidos 25, 70, 50. First fit: 110→85→15, depois 54→4: atende todos. Best fit:
    54→29, 110→40, e o pedido de 50 **falha** (restam 40 e 29).
  - Livres 200, 300, 100; pedidos 150, 100, 125, 100, 100. Worst fit atende todos; first fit falha no
    último (sobram 50 e 75).
  - Livres 110 e 354; pedidos 300, 25, 100: best fit atende, first fit falha no 100.
- **Liberação e fusão:** lista livre ordenada por endereço (percorre metade em média) ou **boundary tag**
  (flag + tamanho no início E no fim de cada bloco, lista duplamente ligada → fusão em O(1)) —
  é exatamente o que os `malloc` reais fazem com os cabeçalhos.
- **Pegadinhas para o curso:** fragmentação externa × interna; por que `free(p)` não precisa do tamanho
  (está no cabeçalho escondido antes de p); por que escrever antes do início ou depois do fim de um bloco
  corrompe o heap (estraga as tags do vizinho) — gancho direto com 0057.
- **Exercícios:**
  - Simulador: vetor `memory[1024]`, entrada com "A tamanho id" e "L id"; implementar first fit e best
    fit com fusão na liberação; imprimir o mapa da memória.
  - Refazer os três exemplos acima à mão.

### 0057-erros-de-memoria (cap. 9.1–9.2)
- **Listas compartilhadas:** com o "método do ponteiro", uma sublista pode pertencer a várias listas;
  liberar ou alterar uma afeta as outras (o livro mostra `addone2` somando 1 duas vezes ao mesmo nó
  compartilhado). O "método da cópia" evita isso, mas custa caro. É a origem de **ponteiro solto** e
  **double free**: quem é o dono do nó?
- **Contagem de referências:** cada nó conta quantos ponteiros apontam para ele; chega a 0 → libera
  (recursivamente). Problemas: custo a cada atribuição, campo extra e **ciclos nunca chegam a 0**
  (vazamento). Truque: liberar "preguiçosamente" na hora de reaproveitar o nó.
- **Coleta de lixo (mark & sweep):** marca tudo que é alcançável a partir dos ponteiros externos (DFS
  com pilha, ou Schorr-Waite, que inverte ponteiros para não precisar de pilha) e depois varre a
  memória devolvendo os não marcados. Pausa o programa (ruim em tempo real; "nave espacial esperando o
  coletor"); se quase tudo está em uso, o coletor roda sem parar (**thrashing**). Compactação move os
  blocos vivos para um lado e corrige os ponteiros (duas passadas, O(n)).
- **Ideia para o curso:** contrastar C (o programador é o "coletor") com linguagens com GC; explicar
  vazamento como "nó inalcançável que ninguém liberou" — exatamente o que valgrind reporta como
  "definitely lost".
- **Exercícios:**
  - Desenhar as listas `l1 = (3,4,7)` e `l2 = addon(l1, 5)` pelo método do ponteiro e da cópia; depois
    `sethead(l1, 7)`: o que muda em l2 em cada caso? (Resp.: no do ponteiro l2 vira (5,7,4,7); na cópia
    l2 não muda.)
  - Implementar `freelist` recursiva e iterativa para listas gerais (com sublistas), supondo que não há
    compartilhamento.
  - Detectar se uma lista é circular/recursiva (gancho com o algoritmo da lebre e da tartaruga).

### 0064-union (gancho)
- O livro implementa **listas gerais** (elementos inteiros, caracteres ou sublistas) com
  `struct { int utype; union { int i; char c; struct node *lst; } info; struct node *next; }`.
  Exemplo de lista: `(5, (3, 2, (14, 9, 3), (), 4), 2, (6, 3, 10))`; `head` = 5; `head(tail(·))` =
  `(3, 2, (14,9,3), (), 4)`. Excelente exemplo de union com "tag" de tipo e de por que union evita
  `switch` sobre dez tipos de nós atômicos.
- **Exercício:** imprimir uma lista geral na notação com parênteses (recursão sobre `utype`).

---

## Obsoleto / evitar

- **C pré-ANSI (K&R):** `bubble(x, n) int x[], n; { … }` — declarar parâmetros entre o cabeçalho e a
  chave. Usar protótipos modernos `void bubble(int x[], int n)`.
- `#define TRUE 1 / FALSE 0` → `stdbool.h`. `exit(1)` dentro de funções de biblioteca (`tail`, `head`)
  → devolver código de erro.
- **Pool de nós em vetor** (`node[MAXNODES]`, `getnode()`, `freenode()`, ponteiros como índices `int`):
  era o jeito de simular memória dinâmica; no LPEDC usar `malloc/free` (o pool pode virar bônus de
  "alocador próprio").
- **Inline manual** ("remova chamadas de função dos laços internos"), `%` trocado por comparação e
  subtração, "algumas versões de C não deixam função retornar struct": tudo isso o compilador moderno
  resolve ou é padrão desde C89. Não ensinar como regra.
- **`goto again`** no Schorr-Waite. Comentários sobre FORTRAN (IF aritmético), PL/I, fitas e cilindros de
  disco: contexto histórico.
- **Bugs/erros a NÃO copiar (do texto ou do OCR):**
  - `selectsort`: usa `x[ind]` em vez de `x[indx]`.
  - `quicksort` não recursivo: `newbnds.up` em vez de `newbnds.ub`.
  - Hash linear: diz `rh(i) = (i + 1) % 100` onde deveria ser `% 1000`.
  - `maxflow`: grava `forward[nd]` em vez de `forward[i]` e depois lê `forward[pred]` — inconsistente.
  - `shortpath` (Dijkstra): `dc + weight[current][i]` com `weight = INFINITY` estoura `int`; se t não é
    alcançável, `k` fica sem valor.
  - Prim: usa `distance = INFINITY` tanto para "já está na árvore" quanto para "ainda não alcançado" e
    só atualiza se `distance[nd] < INFINITY` — vértices não adjacentes à raiz nunca seriam atualizados.
    Usar um vetor `naarvore[]` separado.
  - "Sistema Decimal de Davey" (é Dewey); "aproximadamente 31 comparações" na BST (é ≈ 3,3); muitas
    fórmulas com sobrescritos perdidos (ler com desconfiança).
- **Busca binária com `mid = (low + hi) / 2`** sem comentar overflow.
- **Recomendação de "classificação por média" e Bsort:** curiosidades; hoje o padrão é quicksort com
  mediana-de-três/introsort ou o `qsort` da biblioteca.

---

## Extras que não cabem no sumário (candidatos a bônus)

### Radix sort (classificação de raízes)
- Distribui os números em 10 filas pelo dígito **menos** significativo, concatena as filas em ordem
  0..9, e repete para o próximo dígito. Funciona porque cada passada é **estável**: a ordem obtida pelos
  dígitos menos significativos é preservada entre números com o mesmo dígito mais significativo.
- Exemplo: `25 57 48 37 12 92 86 33` → pelas unidades: `12 92 33 25 86 57 37 48` → pelas dezenas:
  `12 25 33 37 48 57 86 92`.
- Custo O(m·n) (m = nº de dígitos); filas implementadas como listas ligadas (front/rear) para
  concatenar em O(1). Variante MSD ("troca de raízes") lembra o particionamento do quicksort. Ótimo
  exercício integrador de **filas** (módulo 12).
- **Classificação por cálculo de endereço (bucket sort):** função que preserva ordem manda cada chave
  para um balde (ex.: primeiro dígito); cada balde é lista ordenada; concatena. Quase O(n) se a
  distribuição for uniforme e houver ~1 chave por balde.

### Árvores B, B*, B+, tries
- **Árvore de busca multidirecional de ordem n:** nó com até n filhos e n−1 chaves ordenadas. Motivação:
  disco — ler um bloco grande custa quase o mesmo que um pequeno; minimizar nº de nós lidos. Exemplo do
  livro: 4000 chaves → ordem 5 precisa de profundidade ≥ 5; ordem 11, só 3; ordem 100 guarda > 1 milhão
  de chaves com profundidade 2.
- **Árvore B de ordem n:** balanceada (todas as folhas no mesmo nível) e todo nó não raiz tem pelo menos
  n/2 chaves. Inserção na folha; se encher, **divide** em duas e **promove a chave do meio** ao pai (que
  pode dividir também, até a raiz — é assim que a árvore cresce em altura). Remoção: empréstimo do
  irmão ou fusão (concatenação) com o irmão + chave separadora do pai. Árvore 2-3 = B de ordem 3.
  Utilização média ~69% (pior 50%). Atenção: autores diferentes definem "ordem" de jeitos diferentes.
- **B\*:** redistribui com o irmão antes de dividir; divide 2 nós cheios em 3 → utilização ≥ 67%.
- **B+:** todas as chaves nas folhas, folhas encadeadas ("conjunto de sequência") → acesso sequencial em
  O(1) por registro; é a estrutura dos índices de bancos de dados e sistemas de arquivos. Compressão de
  prefixo/sufixo das chaves (ex.: anchor, andrew, antoin).
- **Trie / árvore digital:** cada nível decide por um símbolo da chave (10 ou 26 ponteiros por nó, ou
  representação filho/irmão); fim de chave marcado com `eok`. Bônus: autocompletar palavras.

### Fluxo em redes (Ford-Fulkerson)
- Rede de canos com capacidade por aresta; fonte S e sumidouro T; fluxo respeita capacidade e
  conservação (entra = sai em todo nó intermediário). Melhora-se o fluxo por **caminhos aumentantes**
  (semicaminhos): arestas para frente com folga ou arestas para trás com fluxo positivo (desviar fluxo).
  Repete até não haver caminho → fluxo máximo. Ligação com corte mínimo (exercício do livro). Aplicações:
  redes elétricas, tráfego, comunicação. Projeto bônus: "quantos litros/minuto chegam ao bairro?".

### Hashing avançado
- **Hash em disco com buckets** (blocos de 10–100 registros); tabela do livro mostra que buckets
  maiores tornam até a sondagem linear eficiente.
- **Hash dinâmico (Larson) e extensível (Fagin et al.):** o diretório usa os primeiros d bits do hash; um
  balde cheio se divide pelo próximo bit; se o balde já usava d bits, o diretório dobra. Um acesso a
  disco por busca, crescimento e encolhimento suaves, utilização ~69%.
- **Hash linear (Litwin, LH2P):** cresce um balde por vez, sem diretório.
- **Hash perfeito:** sem colisões para um conjunto fixo (palavras reservadas de um compilador!).
  Cichelli: h = val(1ª letra) + val(última letra) + comprimento, com valores das letras achados por
  backtracking — ótimo desafio. Sprugnoli: `(k + s) / d` (ex.: `(k + 25)/64` para
  17, 138, 173, 294, 306, 472, 540, 551, 618). Jaeschke: `(c / k) % n` (para 3, 5, 11, 14, c = 11).
- **Hashing universal (Carter-Wegman):** escolher aleatoriamente `h(k) = ((s·k + t) % p) % m` com p primo
  > maior chave; garante bom desempenho esperado para qualquer conjunto de entrada (defesa contra
  entradas maliciosas).

### Coleta de lixo e alocadores
- Contagem de referências × mark & sweep × compactação; Schorr-Waite (marcar sem pilha invertendo
  ponteiros); coleta incremental/concorrente; coleta geracional (objetos jovens morrem cedo).
- **Buddy system ("sistema em turma"):** memória de 2^m; pedidos arredondados para potência de 2;
  divide blocos ao meio até o tamanho certo; ao liberar, funde com o "companheiro" se ele estiver livre
  e com o mesmo tamanho. Endereço do companheiro de um bloco de tamanho 2^i em p:
  `p % 2^(i+1) == 0 ? p + 2^i : p − 2^i` (ex.: i = 6, p = 704 → 640). Exemplo do livro: memória de 1024,
  pedido de 100 vira bloco de 128 em 896. Variantes: Fibonacci, ponderado (2^k → 2^(k−2) + 3·2^(k−2)),
  recombinação adiada. Excelente exercício de bits (módulo 08, 0065) e recursão.
- **Boundary tags** e listas livres por tamanho: base para entender `malloc` de verdade.

### Busca: outras ideias
- Árvores de busca ótimas (chaves com probabilidades diferentes; O(n²) exato, métodos gulosos ou de
  balanceamento quase ótimos em O(n)); "árvore dividida mediana".
- Cook-Kim: retira pares fora de ordem de um vetor quase ordenado, ordena-os à parte e intercala.

---

## Achados mais valiosos para o LPEDC
1. O vetor-padrão `25 57 48 37 12 92 86 33` com o estado após cada passo de bubble, quick, shell, heap
   (vetor do heap: `92 37 86 33 12 48 57 25`), merge e radix — permite um quadro comparativo único.
2. Exemplos-armadilha prontos: inserção binária não melhora o insertion sort (deslocamentos continuam
   O(n²)); passo de sondagem com divisor comum causa laço infinito com tabela meio vazia; remoção
   ingênua em endereçamento aberto "perde" chaves; 256 % 17 == 1 faz anagramas colidirem; first fit ×
   best fit × worst fit com sequências em que cada um vence.
3. Tabelas numéricas de custo (sondagens por fator de carga; BST aleatória 1,386 log₂ n; AVL 1,44 log₂ n;
   interpolação 134 vs. binária 16 em nomes reais) que dão concretude ao Big-O.
