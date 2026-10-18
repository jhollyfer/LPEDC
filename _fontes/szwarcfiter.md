# Fichamento: Szwarcfiter & Markenzon, *Estruturas de Dados e Seus Algoritmos*, 3ª ed. (LTC, 2010)

Fonte lida: `a4ebab45-Estruturas_de_dados_e_seus_algoritmos_3a._ed.._Jayme_Luiz_Szwarcfiter.md`, linhas 1–7521 (livro inteiro,
incluindo exercícios, notas bibliográficas e referências). Tudo abaixo está parafraseado; os exemplos numéricos foram
criados (ou recalculados) para o curso e conferidos à mão.

## Avaliação geral

- **Perfil.** É um texto universitário clássico brasileiro (UFRJ), denso e com foco matemático: cada estrutura vem com
  definição formal, lema de correção e cálculo de complexidade (pior caso, às vezes caso médio e amortizado). Linguagem
  dos algoritmos é um pseudocódigo estilo Pascal (`:=`, blocos por endentação, `pt↑.campo`, λ para ponteiro nulo,
  passagem por referência). Nada de C: tudo precisará ser traduzido.
- **Público.** Mais adequado ao professor do que ao aluno iniciante do LPEDC. Serve como "fonte de verdade" para
  definições, provas curtas e boas perguntas de prova/exercício (o livro marca dificuldade com ° e •).
- **Cobertura forte (sustenta módulos novos):** análise amortizada (banqueiro e físico), union-find com fusão por tamanho
  e três tipos de compactação de caminho, árvores de difusão (splay), listas autoajustáveis (mover para frente,
  transposição, contador) com prova de que MF é 2-competitivo, rubro-negra (via árvores "graduadas"), árvore B,
  árvore digital (trie) e Patricia, KMP detalhado, Huffman com prova de otimalidade, árvore de decisão e limite
  Ω(n log n), ordenação por distribuição (radix com filas), ordenação topológica, programação dinâmica (árvore binária
  de busca ótima), tabelas de dispersão completas (4 funções, encadeamento exterior/interior, linear/quadrática/dupla,
  dispersão linear dinâmica), heaps avançados (m-heap, esquerdista, binomial, Fibonacci, min-max).
- **Não cobre (procurar em outra fonte):** grafos em geral (BFS, DFS, Dijkstra, Prim, Kruskal, Bellman-Ford,
  Floyd-Warshall, componentes conexos), backtracking, shell/counting/bucket sort, seleção do k-ésimo, teorema mestre,
  skip list, selection sort. Boyer-Moore e Rabin-Karp aparecem só citados nas notas bibliográficas.
- **Convenções que diferem de outras fontes (atenção ao copiar fórmulas):** nível da raiz = 1; altura de folha = 1
  (nó externo tem altura 0 no capítulo de rubro-negras); balanço AVL = h(dir) − h(esq); árvore B "de ordem d" tem
  entre d e 2d chaves por página (não é a "ordem = nº máximo de filhos" de Knuth/Cormen).
- **Erros de digitação no texto-fonte** (não propagar): na função da divisão aparece "h(x) = h mod m" (o certo é
  x mod m); no `ins-AVL`, o ramo direito repete "0: bal := −1" (o certo é +1); no `buscapat` falta o "<" em
  "k < pt↑.r"; o Algoritmo 7.1 (bolha) percorre i = 1..n desnecessariamente.

---

## Parte A — assuntos que já existem no sumário

### 0037-recursao
**Conceitos-chave**
- Chamada externa (de fora) versus chamada recursiva (de dentro). Procedimento não recursivo = só tem chamadas externas.
- Todo recursivo tem um equivalente iterativo; recursão vence em concisão e na ligação direta com prova por indução,
  mas pode perder em eficiência.
- Técnica de custo: (número total de chamadas) × (custo de uma chamada, sem contar as recursivas).

**Explicações boas**
- O livro raciocina Hanói como uma indução: "se eu sei mover n−1, movo n assim": n−1 para o pino de trabalho, o
  maior para o destino, n−1 do trabalho para o destino.
- Comparação fatorial recursivo × iterativo com vetor `fat[0..n]` mostra que "iterativo" não implica "menos memória"
  se a versão iterativa guarda tudo; o exercício pede a versão iterativa com uma única variável.

**Pegadinhas**
- Exercício-armadilha do livro: "o fatorial recursivo usa memória constante" é FALSO, a pilha de chamadas cresce O(n).
- Todo recursivo precisa de pelo menos uma saída sem chamada recursiva (caso base), senão não termina.

**Ideias de exemplos:** `fat(4)`: chamadas fat(4)→fat(3)→fat(2)→fat(1); 4 chamadas, cada uma O(1) ⇒ O(n). Mostrar a pilha com 4 frames.

**Ideias de exercícios**
- "Certo ou errado: o fatorial recursivo precisa de memória constante." → Errado: n frames na pilha.
- Escrever fatorial iterativo sem vetor. → `long r = 1; for (int j = 2; j <= n; j++) r *= j;`

### 0038-recursao-na-pratica
**Conceitos-chave**
- Hanói faz exatamente 2ⁿ − 1 movimentos (e isso é mínimo); Fibonacci recursivo ingênuo é exponencial; existe versão
  linear iterativa.
- Curiosidade forte: o número de chamadas de `f(h)` (Fibonacci recursivo) é igual ao número mínimo de nós de uma
  árvore AVL de altura h (exercício 5.6), boa ponte para o módulo de árvores.

**Explicações boas:** Generalizações de Hanói com 4 ou m pinos (exercícios 1.9–1.11) como desafio.

**Pegadinhas:** Parar a recursão em n = 1 em vez de n = 0 economiza chamadas vazias (exercício 1.7): com n = 0 como base, cada folha
  da árvore de recursão faz duas chamadas inúteis.

**Ideias de exemplos**
- Hanói n = 3 (A origem, B destino, C trabalho): A→B, A→C, B→C, A→B, C→A, C→B, A→B = 7 = 2³ − 1.
- Contar chamadas de fib(5) ingênuo: C(n) = C(n−1) + C(n−2) + 1, C(0)=C(1)=1 ⇒ C(2)=3, C(3)=5, C(4)=9, C(5)=15.

**Ideias de exercícios**
- Quantos movimentos para 10 discos? → 1023.
- Provar por indução M(n) = 2M(n−1) + 1 ⇒ M(n) = 2ⁿ − 1.

### 0076-eficiencia
**Conceitos-chave**
- "Passo" = bloco com número fixo de operações básicas; a operação mais frequente é a *dominante*; contar passos ≈
  contar execuções da dominante.
- Complexidade de pior caso (máximo sobre entradas), melhor caso (mínimo) e caso médio (Σ probabilidade × passos).

**Explicações boas**
- Exemplo didático: um programa que soma (x = 0) ou multiplica (x = 1) duas matrizes n×n tem melhor caso O(n²),
  pior O(n³) e caso médio q·n² + (1 − q)·n³, onde q é a chance de x = 0.
- Caso médio da busca sequencial: o algoritmo "enxerga" só n + 1 entradas distintas (chave na posição 1..n ou ausente).

**Pegadinhas**
- Inverter vetor faz ⌊n/2⌋ trocas, não n.
- Caso médio exige conhecer a distribuição das entradas; por isso o pior caso é o mais usado.

**Ideias de exemplos:** Inverter vetor de 9 elementos: ⌊9/2⌋ = 4 trocas; de 10: 5 trocas.

**Ideias de exercícios:** Quantas multiplicações faz o produto de matrizes 3×3 ingênuo? → 27 = n³.

### 0077-big-o
**Conceitos-chave**
- O (limite superior), Ω (limite inferior), Θ (mesma ordem: f = O(g) e g = O(f)), com definição por constante c e n₀.
- Regras: O(g + h) = O(g) + O(h); constantes multiplicativas somem.
- Limite inferior de um *problema* e algoritmo ótimo (complexidade casa com o limite inferior). Limite trivial: ler a
  entrada (somar matrizes é Ω(n²) e o algoritmo O(n²) é ótimo; multiplicar matrizes O(n³) não é ótimo).

**Explicações boas:** Lista de exemplos: 5 + 2 log n + 3 log² n é O(log² n) e também O(n), mas Θ só de log² n.

**Pegadinhas**
- O não é "igual": n² − 1 é O(n³) (verdade, mas frouxo).
- Exercícios certo/errado ótimos: "se o pior caso é f, todo caso é Θ(f)" (errado: só O(f)); "melhor caso f ⇒ todo
  caso é Ω(f)" (certo); "melhor caso de um algoritmo é sempre maior que qualquer limite inferior do problema" (errado,
  o limite inferior é sobre pior caso).

**Ideias de exemplos:** Classificar: n³ − 1 → O(n³); n² + 2 log n → O(n²); 3nⁿ + 5·2ⁿ → O(nⁿ); 302 → O(1).

**Ideias de exercícios:** "f = O(g) e g = Ω(f) implica f = Θ(g)?" → Não: as duas afirmações dizem a mesma coisa.

### 0079-tad
**Conceitos-chave:** TAD = modelo matemático + conjunto de operações; estrutura de dados é a representação concreta do modelo.
**Explicações boas:** Algoritmo é projetado sobre o TAD; só depois escolhe-se a estrutura, e a escolha depende do custo das operações.
**Pegadinhas:** Mesma interface (pilha) com duas implementações (vetor e lista) e custos iguais O(1): a escolha depende de memória.
**Ideias de exemplos:** Lista de prioridades com três implementações (não ordenada, ordenada, heap) e a tabela de custos de cada operação
  (ver 0107): ótimo exemplo de "mesmo TAD, custos diferentes".
**Ideias de exercícios:** Preencher tabela seleção/inserção/remoção para lista não ordenada → O(n)/O(1)/O(n); ordenada → O(1)/O(n)/O(1).

### 0080-vetor-dinamico
**Conceitos-chave**
- Lista linear sequencial: busca, inserção, remoção; overflow e underflow; posição extra para sentinela.
- Busca com sentinela: grava a chave em L[n+1] e elimina o teste `i ≤ n` (um teste por iteração em vez de dois).
- Remoção alternativa: mover o último para o buraco (O(1) depois da busca, mas perde a ordem).

**Explicações boas**
- Busca binária reduz a busca, mas não reduz inserção/remoção em lista ordenada, que continuam O(n) por causa do
  deslocamento.
- Caso médio da busca sequencial com probabilidade q de sucesso: ≈ n/2 se q = 1, ≈ 3n/4 se q = 1/2, n se q = 0. Na
  lista ordenada com parada antecipada, ≈ n/2 para qualquer q.

**Pegadinhas**
- Sentinela exige espaço reservado (M + 1 posições).
- Inserção numa lista não ordenada ainda custa O(n) se for preciso verificar duplicata.

**Ideias de exemplos:** Vetor [7, 3, 9, 1], n = 4, buscar 5 com sentinela: L[5] = 5; compara 7, 3, 9, 1, 5 → para em i = 5 = n+1 ⇒ ausente.

**Ideias de exercícios:** Contar comparações da busca com e sem sentinela para chave ausente em n = 4. → Sem: 4 de chave + 5 de índice = 9;
  com: 5.

### 0081-lista-encadeada
**Conceitos-chave**
- Alocação encadeada = dinâmica; cada nó ganha um campo ponteiro. Lista de Espaço Disponível (LED) simulada num vetor
  com `ocupar`/`desocupar` (equivalente a malloc/free feitos à mão).
- Nó-cabeça: nó fixo que nunca sai e elimina casos especiais do primeiro elemento.
- Inserção e remoção têm três fases (pedir nó à LED, preencher/ler, acertar ponteiros), em ordem inversa uma da outra.

**Explicações boas:** A LED em vetor é um ótimo exercício de C: um pool de nós com `int prox` em vez de ponteiros, "free list".

**Pegadinhas**
- Esquecer a ordem: ligar `novo->prox = ant->prox` ANTES de `ant->prox = novo`.
- Sem nó-cabeça, inserir/remover no início exige atualizar o ponteiro da lista (passar `No **`).

**Ideias de exemplos:** Pool de 5 nós: inicial `vago = 0`, prox = 1,2,3,4,−1. Ocupar dois nós → `vago = 2`; desocupar o nó 0 → `vago = 0`,
  prox[0] = 2.

**Ideias de exercícios:** Implementar `ocupar`/`desocupar` sobre vetor e mostrar o estado após ocupar, ocupar, desocupar(1). → vago = 1,
  prox[1] = 2.

### 0082-lista-busca-remocao
**Conceitos-chave:** Busca retorna dois ponteiros: `pont` (achado ou λ) e `ant` (o anterior), porque remover/inserir precisa do anterior.
**Explicações boas:** O ponteiro `ant` "rastreia" o ponteiro de percurso; é ele que torna a remoção O(1) depois da busca.
**Pegadinhas:** Liberar o nó antes de religar a lista (uso após free).
**Ideias de exemplos:** Lista com cabeça → 10 → 20 → 30; remover 20: ant aponta 10, pont aponta 20; `ant->prox = pont->prox; free(pont)`.
**Ideias de exercícios:** Intercalar duas listas não ordenadas alternando nós (exercício 2.13): L1 = 1,3,5,7 e L2 = 2,4 → 1,2,3,4,5,7.

### 0083-lista-ordenada
**Conceitos-chave**
- Busca ordenada para assim que encontra chave ≥ x; inserção ordenada usa o `ant` devolvido.
- Intercalação de duas listas ordenadas (exercício 2.14) é a base do mergesort.
**Explicações boas:** Polinômio como lista encadeada ordenada por expoente (exercício 2.18): somar e multiplicar polinômios.
**Pegadinhas:** Parada antecipada só vale se a lista estiver de fato ordenada.
**Ideias de exemplos:** P(x) = 3x⁴ + 2x + 1 e Q(x) = x⁴ − 2x + 5 em listas (coef, exp): soma percorre as duas como uma intercalação →
  4x⁴ + 6 (o termo de x some e deve ser removido da lista).
**Ideias de exercícios:** Avaliar P(2) com Horner sobre a lista. → 3·16 + 4 + 1 = 53.

### 0084-lista-dupla
**Conceitos-chave:** Campos `ant` e `post`; lista circular duplamente encadeada com nó-cabeça é a versão "sem casos especiais".
**Explicações boas**
- Busca devolve o nó encontrado ou o que seria seu sucessor; com isso a inserção é feita "antes de pont".
- Truque: compara x com a chave do último (`cabeca->ant`) antes de percorrer; se x for maior, já sabe que não está.
**Pegadinhas:** Na remoção, atualizar os dois vizinhos (anterior->post e posterior->ant).
**Ideias de exemplos:** Cabeça ⇄ 10 ⇄ 30; inserir 20: anterior = 10, pont = 30; quatro atribuições de ponteiros.
**Ideias de exercícios:** Escrever as 4 atribuições da inserção e as 2 da remoção. → novo->ant=anterior; novo->post=pont; anterior->post=novo;
  pont->ant=novo / anterior->post=posterior; posterior->ant=anterior.

### 0085-lista-circular
**Conceitos-chave:** Último nó aponta para o nó-cabeça; colocando a chave procurada na cabeça (sentinela), o teste de fim desaparece.
**Explicações boas:** É a versão encadeada da busca com sentinela de 0080: mesmo truque, outra estrutura.
**Pegadinhas:** Ao terminar, distinguir "achei a sentinela" (ausente) de "achei a chave" testando `pont != cabeca`.
**Ideias de exemplos:** Cabeça → 5 → 9 → 12 → cabeça; buscar 10: cabeça.chave = 10; anda 5, 9, para em 12 (≥ 10) ⇒ 12 ≠ 10 ⇒ ausente.
**Ideias de exercícios:** Implementar busca circular com sentinela para lista NÃO ordenada. → para quando chave == x; ausente se parou na cabeça.

### 0087-pilha
**Conceitos-chave**
- Pilha em vetor: só `topo` (0 = vazia), O(1). Duas pilhas no mesmo vetor crescendo das pontas (exercício 2.7).
- Permutações admissíveis: saídas obtidas empilhando 1..n em ordem e desempilhando quando quiser. Uma permutação é
  admissível sse não existem i < j < k com p_j < p_k < p_i (exercício 2.25). Para n = 4 há 14 (número de Catalan).

**Explicações boas:** Notação I/R: IIRIRR com entrada 1,2,3 produz 2,3,1.

**Pegadinhas:** 3,1,2 não é admissível (para tirar 3 primeiro, 1 e 2 ficam com 2 por cima de 1).

**Ideias de exemplos:** IIIRRIRR com 1..4: empilha 1,2,3; tira 3, 2; empilha 4; tira 4, 1 ⇒ 3,2,4,1.

**Ideias de exercícios**
- 4,1,3,2 é admissível? → Não: i=1 (4), j=2 (1), k=3 (3): 1 < 3 < 4.
- Escrever as duas pilhas num vetor de tamanho M; quando há overflow? → quando topo1 + 1 == topo2.

### 0088-pilha-encadeada
**Conceitos-chave:** Topo = primeiro nó da lista sem cabeça; topo = λ quando vazia; push/pop O(1).
**Explicações boas:** Mesmas três fases de 0081 (pedir nó, preencher, acertar ponteiro).
**Pegadinhas:** Pop em pilha vazia (underflow) deve ser tratado antes de desreferenciar.
**Ideias de exemplos:** push 1, push 2, pop → devolve 2; topo aponta 1.
**Ideias de exercícios:** Palíndromo com pilha (exercício 2.17): "raiar" → empilha metade, compara com a outra metade → sim.

### 0089-pilha-aplicacoes
**Conceitos-chave**
- Três notações: completamente parentizada, polonesa (prefixa) e polonesa reversa (pós-fixa).
- Converter parentizada → pós-fixa: operandos vão direto para a saída; operador vai para a pilha; ao ler ")", desempilha
  um operador para a saída.
**Explicações boas**
- Observações que justificam o algoritmo: os operandos mantêm a ordem; os operadores saem na ordem em que devem ser
  calculados; cada operador vem logo após seus operandos.
- Ponte com árvores: pré-ordem da árvore de expressão dá a polonesa; pós-ordem dá a reversa.
**Pegadinhas:** O algoritmo do livro pressupõe expressão TOTALMENTE parentizada (sem regras de precedência).
**Ideias de exemplos:** ((A*B)−(C/D)): lê A → saída A; * → pilha; B → AB; ")" → AB*; − → pilha; C → AB*C; / → pilha [−,/]; D → AB*CD;
  ")" → AB*CD/; ")" → AB*CD/−.
**Ideias de exercícios:** Converter (A+(B*C)). → ABC*+. Prefixa? → +A*BC.

### 0090-fila
**Conceitos-chave:** Fila circular em vetor de M posições: `prov = r mod M + 1`; se `prov == f` ⇒ overflow; vazia quando f = r = 0.
**Explicações boas**
- A fila "anda" pelo vetor e daria falsa impressão de memória cheia; daí a circularidade (F[1] segue F[M]).
- Ao remover o último elemento, volta para f = r = 0 (não precisa de contador).
**Pegadinhas:** Com esse esquema, todas as M posições podem ser usadas (vazia é sinalizada por f = 0, não por "uma posição livre").
**Ideias de exemplos:** M = 3: insere a (f=r=1), b (r=2), c (r=3); insere d: prov = 3 mod 3 + 1 = 1 = f ⇒ overflow. Remove a (f=2);
  insere d: prov = 1 ≠ 2 ⇒ r = 1.
**Ideias de exercícios:** Mostrar f e r após: ins x, ins y, rem, rem, ins z (M = 4). → depois do segundo rem f=r=0; ins z ⇒ f = r = 1.

### 0091-fila-encadeada
**Conceitos-chave**
- Ponteiros `inicio` e `fim`; ao remover o único nó, `fim` volta a λ.
- Aplicação: ordenação por distribuição (radix) usa b filas, uma por dígito (ver NOVO: radix).
**Explicações boas:** O livro conta a história da classificadora mecânica de cartões perfurados: cada escaninho era uma fila.
**Pegadinhas:** Esquecer de zerar `fim` quando a fila esvazia (próxima inserção escreve em nó liberado).
**Ideias de exemplos:** ins 1, ins 2, rem, rem: após o último rem, inicio = fim = NULL.
**Ideias de exercícios:** Permutações obtidas com fila em vez de pilha (exercício 2.26). → Só a identidade 1,2,…,n.

### 0092-deque
**Conceitos-chave:** Inserção e remoção apenas nas extremidades (E1, E2); em vetor, implementar circular.
**Explicações boas:** Pilha e fila são casos particulares do deque.
**Pegadinhas:** Exercício de pesquisa: caracterizar permutações obtidas com deque (•2.28) — difícil; usar só como curiosidade.
**Ideias de exemplos:** Deque em vetor M = 5: insere 7 em E1, 8 em E2, 9 em E1 ⇒ 9 7 8.
**Ideias de exercícios:** Com deque, a partir de 1,2,3, é possível obter 3,1,2? → Sim: insere 1, 2 em E2, 3 em E1, retira tudo por E1.

### 0094-busca-sequencial
Ver 0080 (sentinela, caso médio) e 0085 (versão circular). Exercício extra do livro: se a probabilidade de cada chave é o
dobro da anterior, a busca não ordenada fica muito melhor se a lista for posta em ordem decrescente de probabilidade —
gancho para listas autoajustáveis (NOVO).

### 0095-busca-binaria
**Conceitos-chave:** No máximo 1 + ⌊log₂ n⌋ iterações; O(log n). Equivale a buscar numa árvore binária completa cuja raiz é o meio.
**Explicações boas:** Analogia da lista telefônica; e a ligação com BST: a busca binária é uma BST "implícita".
**Pegadinhas**
- Serve para busca, mas a tabela ordenada continua cara para inserir/remover (motivação para BST e AVL).
- `meio = (inf + sup) / 2` pode estourar `int` em vetores enormes; em C usar `inf + (sup - inf) / 2`.
**Ideias de exemplos:** [2, 5, 8, 12, 16, 23, 38, 56, 72, 91], buscar 23: meio 5 (16) → inf=6; meio 8 (56) → sup=7; meio 6 (23) achou;
  3 comparações ≤ 1 + ⌊log₂ 10⌋ = 4.
**Ideias de exercícios:** Máximo de iterações para n = 1000. → 1 + 9 = 10.

### 0096-bubble-sort
**Conceitos-chave:** Versão ingênua O(n²) em qualquer caso; duas melhorias: flag `mudou` (melhor caso O(n)) e `guarda` = posição da última
  troca (tudo depois dela já está ordenado).
**Explicações boas:** Cada passada leva o maior restante para o fim.
**Pegadinhas:** "Lebre e tartaruga": elemento pequeno no fim anda uma posição por passada.
**Ideias de exemplos:** 10 20 30 40 50 5: cinco passadas com uma troca cada (5 caminha para a esquerda) + uma passada vazia.
  90 10 20 30 40 50: uma passada com 5 trocas e uma vazia.
**Ideias de exercícios:** Contar passadas e trocas nas duas entradas acima (é o exercício 7.2). → 6 passadas/5 trocas e 2 passadas/5 trocas.

### 0097-selection-sort
O livro **não** apresenta seleção. Usar outra fonte. O heapsort (0108) pode ser apresentado como "seleção com heap".

### 0098-insertion-sort
**Conceitos-chave:** Número de deslocamentos = número de inversões da tabela; melhor caso O(n) (0 inversões), pior O(n²) (n(n−1)/2).
**Explicações boas:** L[0] como posição extra para o teste não sair do vetor (sentinela).
**Pegadinhas:** Com todas as chaves iguais, é O(n) se a comparação for estrita (exercício 7.3).
**Ideias de exemplos:** 5 2 4 6 1 3 tem 9 inversões ⇒ 9 deslocamentos.
**Ideias de exercícios:** Lista ordenada seguida de alguns elementos fora de ordem: qual método escolher (exercício 7.13)? → Inserção.

### 0099-merge-sort
**Conceitos-chave**
- Dividir ao meio, ordenar metades, intercalar com área temporária única passada como parâmetro.
- Recorrência T(n) = 2T(n/2) + n resolvida "dividindo por n e somando em telescópio" ⇒ O(n log n).
**Explicações boas:** Duas otimizações: alocar o temporário uma única vez; alternar os papéis de L e Tmp entre níveis para evitar a cópia.
**Pegadinhas:** Alocar o temporário dentro de cada chamada (malloc em cada nível) destrói o desempenho.
**Ideias de exemplos:** 38 27 43 3 9 82 10: [38 27 43 3] → [27 38] [3 43] → [3 27 38 43]; [9 82 10] → [9 82] [10] → [9 10 82]; intercala.
**Ideias de exercícios:** Telescopar T(n)/n = T(n/2)/(n/2) + 1 para n = 16. → T(16)/16 = T(1)/1 + 4 ⇒ T(16) = 16 + 64 = 80.

### 0100-quick-sort
**Conceitos-chave**
- Pivô por mediana de três (primeiro, meio, último); pivô vai para o fim; dois índices i (sobe) e j (desce) param em
  elementos "do lado errado" e trocam.
- Pior caso O(n²) (pivô sempre o menor); melhor O(n log n); caso médio O(n log n) via soma harmônica.
**Explicações boas:** Chaves iguais ao pivô: os dois índices devem PARAR nelas (mais trocas, mas partições equilibradas); se pularem,
  tabela com tudo igual vira o pior caso.
**Pegadinhas:** Primeiro elemento como pivô em tabela já ordenada (ou invertida) ⇒ quadrático.
**Ideias de exemplos:** 24 9 31 5 17 40 12: mediana(24, 5, 12) = 12, já no fim. i para em 24, j para em 5 → troca: 5 9 31 24 17 40 12;
  i para em 31, j para em 9 (j < i) → troca L[i] com o pivô: 5 9 12 24 17 40 31. Partes {5, 9} e {24, 17, 40, 31}.
**Ideias de exercícios:** Simular a partição em 1 2 3 4 5 6 7 com pivô = primeiro elemento. → partes vazia e {2..7}: pior caso.

### 0101-comparando
**Conceitos-chave**
- Estabilidade (exercício 7.11): bolha, inserção e merge são estáveis; quick e heap não.
- Limite inferior Ω(n log n) para ordenação por comparação (ver NOVO: limite inferior).
**Explicações boas:** Métodos O(n²) continuam úteis para tabelas pequenas ou quase ordenadas.
**Pegadinhas:** Radix (distribuição) foge do limite porque não compara chaves.
**Ideias de exemplos:** Tabela de pares (nota, nome) ordenada por nota: mostrar que heapsort pode trocar a ordem de dois alunos com nota 7.
**Ideias de exercícios:** 8 7 6 5 4 3 2 1 vira, num momento, 6 5 3 1 4 2 7 8. Bolha, inserção ou heap? (exercício 7.4) → Heap: o vetor
  inicial já é heap; após duas extrações com `descer` obtém-se exatamente 6 5 3 1 4 2 | 7 8 (bolha daria 6 5 4 3 2 1 7 8).

### 0102-arvores
**Conceitos-chave**
- Definição recursiva (vazia ou raiz + subárvores disjuntas); floresta; pai, filho, irmão, tio, avô; descendente
  próprio; folha; grau de saída; caminho e comprimento; nível (raiz = 1) e altura (folha = 1).
- Árvore ordenada; isomorfismo (ordenadas ou não).
- Representações: hierárquica, diagrama de inclusão, diagrama de barras (índice de livro), parênteses aninhados.
**Explicações boas:** Toda árvore com n > 1 nós tem entre 1 e n − 1 folhas.
**Pegadinhas:** Convenção de nível/altura do livro (começa em 1) difere de fontes que começam em 0: decidir uma e avisar.
**Ideias de exemplos:** A(B, C(D, E(F))) em parênteses: A(B()C(D()E(F()))); nível de F = 4; altura de A = 4; altura de C = 3.
**Ideias de exercícios:** Desenhar a árvore de [(a+b)(c+d)/e] − [(f+g)h] (exercício 3.6). → raiz "−"; esquerda "/" com filhos "*" e e; etc.

### 0103-arvore-binaria
**Conceitos-chave**
- Árvore binária não é formalmente "árvore": distingue filho esquerdo de direito e pode ter as duas subárvores vazias.
- n nós ⇒ n + 1 subárvores vazias (prova por indução retirando uma folha); m-ária ⇒ (m − 1)n + 1.
- Estritamente binária (0 ou 2 filhos), completa (vazios só nos dois últimos níveis), cheia (vazios só no último).
  Completa tem altura mínima 1 + ⌊log n⌋; zigue-zague tem altura n.
- Percursos pré, simétrica, pós (recursivos, O(n)) e em nível (com fila, não recursivo). Altura de todos os nós via
  pós-ordem.
**Explicações boas**
- Árvore com costura (threaded): os ponteiros nulos guardam predecessor/sucessor em ordem simétrica, com bits
  `ecostura`/`dcostura`; dá percurso simétrico iterativo sem pilha.
- Exercício 3.29: desenhar árvore usando x = posição na ordem simétrica e y = nível (ótimo para imprimir no terminal).
**Pegadinhas:** Pré + pós-ordem NÃO determinam a árvore binária; pré + simétrica determinam (exercício 3.32).
**Ideias de exemplos:** Árvore A(B(D(_, G), _), C(E(H, I), F)): pré A B D G C E H I F; simétrica D G B A H E I C F; pós G D B H I E F C A;
  nível A B C D E F G H I.
**Ideias de exercícios**
- Quantos ponteiros NULL tem uma árvore binária de 9 nós? → 10.
- Reconstruir a árvore com pré A B C e simétrica B A C. → A raiz, B esquerda, C direita.

### 0104-bst-busca-insercao
**Conceitos-chave**
- Busca devolve código f: 0 árvore vazia, 1 achou, 2/3 não achou e o novo nó entraria à esquerda/direita do último nó.
- Construção por inserções sucessivas: depende da ordem; pode chegar a O(n²) (zigue-zague). Inserindo sempre a chave
  mediana entre duas já inseridas obtém-se árvore completa em O(n log n).
- Comprimento de caminho interno I(T) e externo E(T); médias I/n (sucesso) e E/(n+1) (fracasso); E = I + n na
  convenção do livro.
**Explicações boas:** Nós externos (quadrados) representam os intervalos onde termina uma busca sem sucesso.
**Pegadinhas**
- Inserir 1, 2, 3, 4, 5 em ordem gera lista; ordem 3 1 2 5 4 gera árvore de altura 3.
- E = I + n vale com raiz no nível 1 e contando "nível − 1" comparações nos externos; com raiz no nível 0 a fórmula
  muda (no Cormen é E = I + 2n).
**Ideias de exemplos:** Inserir 3 1 7 2 5 4 6: raiz 3; 1 à esq; 7 à dir; 2 dir de 1; 5 esq de 7; 4 esq de 5; 6 dir de 5. Níveis 1,2,2,3,3,4,4
  ⇒ I = 19; média de sucesso 19/7 ≈ 2,71.
**Ideias de exercícios:** Dar duas permutações diferentes de 1..3 que geram a mesma BST. → 2 1 3 e 2 3 1.

### 0105-bst-remocao
**Conceitos-chave:** O livro só pede como exercício (4.15): remover com custo da ordem da altura. Na árvore B ele mostra a ideia do
  sucessor: chave interna é trocada pela imediatamente maior, que está mais abaixo.
**Explicações boas:** Usar o argumento da árvore B para justificar "substituir pelo sucessor".
**Pegadinhas:** A remoção em AVL pode exigir O(log n) rotações (ao contrário da inserção, que precisa de uma).
**Ideias de exemplos:** Na BST de 0104, remover 3 (raiz): sucessor 4 sobe; 5 perde o filho esquerdo.
**Ideias de exercícios:** Remover 7 da BST de 0104. → 7 só tem filho esquerdo (5), então 5 sobe e vira filho direito de 3.

### 0106-avl
**Conceitos-chave**
- Nó regulado: |h(esq) − h(dir)| ≤ 1. Mínimo de nós N(h) = N(h−1) + N(h−2) + 1 (árvores de Fibonacci):
  0, 1, 2, 4, 7, 12, 20, 33, 54… ⇒ altura ≈ 1,44 log₂ n, logo balanceada.
- Quatro rotações (direita, esquerda, dupla direita, dupla esquerda). Na inclusão, regula-se o nó desregulado mais
  próximo das folhas e UMA rotação basta (a subárvore volta à altura antiga).
- Campo `bal` = h(dir) − h(esq) e flag h ("a altura cresceu?") devolvida pela recursão: casos bal = +1 → 0 (para),
  0 → −1 (propaga), −1 → −2 (gira).
**Explicações boas:** Por que árvore completa não serve para dados dinâmicos: restaurar a completude após uma inserção pode mexer em todos os
  nós (Ω(n)); balanceamento "frouxo" custa O(log n).
**Pegadinhas**
- Sinal do `bal` invertido em relação a outras fontes.
- Rotação dupla = duas simples (exercício 5.7).
- Exclusão: até O(log n) rotações.
**Ideias de exemplos**
- Inserir 30, 20, 10: 30 fica com bal −2, filho 20 com −1 ⇒ rotação direita em 30 ⇒ 20(10, 30).
- Inserir 10, 30, 20: 10 com +2, filho 30 com −1 ⇒ rotação dupla esquerda ⇒ 20(10, 30).
**Ideias de exercícios**
- Mínimo de nós de AVL de altura 5. → 12.
- Inserir 50 40 30 20 10 numa AVL vazia: quantas rotações? → 2 (direita em 50 ao inserir 30; direita em 30 ao inserir
  10) e a árvore final é 40(20(10, 30), 50).

### 0107-heap
**Conceitos-chave**
- Lista de prioridades: seleção, inserção, remoção do máximo, alteração de prioridade, construção. Tabela de custos:
  não ordenada (O(n), O(1), O(n), O(n), O(n)); ordenada (O(1), O(n), O(1), O(n), O(n log n)); heap (O(1), O(log n),
  O(log n), O(log n), O(n)).
- Aumentar prioridade = subir; diminuir = descer (escolhendo o maior filho). Inserir = colocar em n+1 e subir; remover
  = trazer o último para a raiz e descer.
- Construção em O(n) (Floyd): `descer` de ⌊n/2⌋ até 1; prova pela soma das alturas (no máximo ⌈n/2ʲ⌉ nós de altura j).
**Explicações boas**
- Lista ordenada já é heap, mas construir ordenando custa O(n log n); construir "de baixo para cima" é linear.
- Variações: heap min-max (níveis alternados min/max; mínimo na raiz, máximo num dos filhos), m-heap (árvore m-ária:
  subir O(log_m n), descer O(m log_m n)), lista de prioridades (L,U)-limitada (vetor de listas indexado pela prioridade,
  O(t + Δ) para t inserções — primeira aparição de análise amortizada).
**Pegadinhas:** Construir com n inserções (subir) é O(n log n); com `descer` a partir do meio é O(n).
**Ideias de exemplos:** Construir heap de 18 25 41 34 14 10 52 50 48 (exercício 6.9): i=4: 34↔50; i=3: 41↔52; i=2: 25↔50, depois 25↔48;
  i=1: 18↔52, depois 18↔41 ⇒ 52 50 41 48 14 10 18 34 25.
**Ideias de exercícios:** 33 32 28 31 26 29 25 30 27 é heap? → Não: 29 (posição 6) > 28 (pai, posição 3). E 33 32 28 31 29 26 25 30 27? → Sim.

### 0108-heapsort
**Conceitos-chave:** `arranjar(n)` (O(n)) + n vezes (troca raiz com último, diminui m, `descer(1, m)`) ⇒ O(n log n).
**Explicações boas:** É a aplicação "natural" da lista de prioridades: quem tem maior prioridade é o último da ordem.
**Pegadinhas:** Exercício certo/errado: "se a entrada já é heap, heapsort é O(n)" → errado, as n descidas continuam custando log n.
**Ideias de exemplos:** 80 35 20 60 42 36 85 (exercício 7.6): arranjar ⇒ 85 60 80 35 42 36 20; depois extrações sucessivas.
**Ideias de exercícios:** Ver exercício de 0101 (8 7 6 5 4 3 2 1 → 6 5 3 1 4 2 7 8).

### 0110-hashing
**Conceitos-chave**
- Acesso direto (chave = índice) como caso motivador; função de dispersão h; colisão; chaves sinônimas; fator de carga
  α = n/m. Boa função: poucas colisões, cálculo barato, uniforme.
- Quatro métodos: divisão (m primo, longe de potência de 2), dobra (somar dígitos sem "vai um" ou XOR de blocos de bits),
  multiplicação (meio do quadrado), análise de dígitos (escolhe os dígitos de menor desvio; exige conhecer as chaves).
**Explicações boas**
- Por que não m par/potência de 2 na divisão: o endereço passa a depender só dos bits finais.
- Por que XOR na dobra: AND tende a números pequenos e OR a números grandes.
**Pegadinhas:** Acesso direto com chaves 0 e 999.999 exige um milhão de posições para guardar duas.
**Ideias de exemplos:** Dobra com XOR, tabela de 32: chave 100 = 00011 00100 (10 bits) ⇒ 00011 XOR 00100 = 00111 = 7.
**Ideias de exercícios:** Múltiplos de 7 (7, 14, 21, …) com h = x mod 7, mod 14 e mod 5: quantas colisões? (exercício 10.1) → mod 7: todos
  em 0; mod 14: só 0 e 7; mod 5: espalha bem (5 primo com 7).

### 0111-encadeamento
**Conceitos-chave**
- Exterior: m listas fora da tabela. Busca sem sucesso: α comparações em média; com sucesso: 1 + α/2 − 1/(2m).
  Com m proporcional a n, ambas O(1). Pior caso O(n).
- Interior: listas dentro da própria tabela, com zona de base (p) e zona de colisão (s); sem zonas separadas surgem
  colisões secundárias (listas de endereços diferentes se fundem).
- Remoção por marcação: estados vazio / ocupado / liberado.
**Explicações boas:** Inserir no fim da lista não custa mais, pois a lista tem de ser percorrida para evitar duplicata.
**Pegadinhas:** Zona de colisão cheia gera "falso overflow" mesmo com espaços na zona de base.
**Ideias de exemplos:** m = 5, h = x mod 5, chaves 12, 7, 22, 9: lista 2 = 12 → 7 → 22; lista 4 = 9. Buscar 17: percorre 3 nós.
**Ideias de exercícios:** n = 200, m = 100: número médio de comparações numa busca sem sucesso? → α = 2.

### 0112-enderecamento-aberto
**Conceitos-chave**
- Sequência de tentativas h(x, k), k = 0..m−1, deve ser uma permutação de 0..m−1.
- Linear: (h′(x) + k) mod m ⇒ agrupamento primário. Quadrática: (h′ + c₁k + c₂k²) mod m; pela recorrência
  h(x,k) = h(x,k−1) + k com m potência de 2 varre toda a tabela ⇒ agrupamento secundário. Dupla:
  (h′(x) + k·h″(x)) mod m, com h″(x) primo com m (m primo ou h″ ímpar com m potência de 2).
- Busca sem sucesso ≈ 1/(1 − α) tentativas (função de sequência uniforme). Remoção: estado "liberado".
**Explicações boas**
- Agrupamento primário se autoalimenta: quanto maior o bloco ocupado, maior a chance de crescer.
- Linear gera no máximo m sequências distintas; dupla, até m².
**Pegadinhas**
- Remover "de verdade" quebra a cadeia de tentativas e faz chaves existentes sumirem.
- h″(x) = 0 trava a sondagem; daí o "1 + x mod 5".
**Ideias de exemplos:** m = 11, h′ = x mod 11, chaves 22, 34, 45, 13, 56, 1. Linear: 22→0, 34→1, 45→2, 13→3, 56→4, 1→5 (bloco 0..5).
  Dupla com h″ = 1 + x mod 7: 22→0, 34→1, 45: 1 ocupado, passo 4 → 5; 13→2; 56: passo 1 → 2, 3 ⇒ 3; 1: passo 2 →
  3, 5, 7 ⇒ 7.
**Ideias de exercícios:** Com α = 0,9, quantas tentativas em média numa busca sem sucesso? → 10.

### 0114-grafos / 0115-bfs / 0116-dfs / 0117-dijkstra
O livro não tem capítulo de grafos. Aproveitáveis: (a) a ordenação topológica (cap. 2) já usa listas de sucessores
— é uma lista de adjacência com contador de grau de entrada; (b) percurso em nível com fila (ex. 3.27) é a BFS
restrita a árvores; (c) heaps de Fibonacci são citados como motivados por Dijkstra/árvore geradora mínima.

---

## Parte B — candidatos a assuntos novos

### NOVO: recorrências (sem teorema mestre)
**Conceitos-chave**
- O livro resolve recorrências por telescópio: mergesort T(n) = 2T(n/2) + n ⇒ dividir por n e somar; quicksort pior
  caso T(n) = T(n−1) + cn ⇒ somar ⇒ O(n²); quicksort médio: multiplicar por n, subtrair a equação de n − 1, dividir por
  n(n+1) e somar ⇒ série harmônica ⇒ O(n log n). Também Hanói (2ⁿ − 1), AVL mínima (Fibonacci) e Fibonacci recursivo.
- Teorema mestre NÃO aparece.
**Explicações boas:** O truque de "dividir por n" para tornar a recorrência somável é muito didático para iniciantes.
**Pegadinhas:** O livro supõe n potência de 2; dizer isso explicitamente ao aluno.
**Ideias de exemplos:** T(n) = T(n−1) + n, T(1) = 1 ⇒ T(n) = n(n+1)/2 ⇒ T(5) = 15.
**Ideias de exercícios:** Resolver T(n) = 2T(n/2) + 1 com T(1) = 1 para n = 8. → 15 (= 2n − 1), O(n).

### NOVO: divisão e conquista
**Conceitos-chave:** Não é nomeada como técnica, mas mergesort, quicksort, busca binária e Hanói seguem o esquema dividir/resolver/combinar.
**Explicações boas:** Quicksort põe o trabalho na divisão (partição); mergesort o põe na combinação (intercalação).
**Pegadinhas:** Divisão desequilibrada (quick com pivô ruim) destrói o ganho.
**Ideias de exemplos:** Comparar a árvore de recursão do merge (n = 8: 3 níveis de custo 8) com a do quick no pior caso (7 níveis).
**Ideias de exercícios:** Máximo de um vetor por divisão e conquista: quantas comparações para n = 8? → 7 (n − 1), igual ao método linear.

### NOVO: programação dinâmica
**Conceitos-chave**
- Introduzida com a árvore binária de busca ótima (frequências diferentes): subárvores de uma árvore ótima são ótimas;
  c(i, j) = min_k [c(i, k−1) + c(k, j)] + F(i, j), c(i, i) = 0; preencher por diagonais (diferença j − i crescente);
  O(n³), O(n²) com o princípio da monotonicidade; guardar o k minimizante para reconstruir a árvore.
- A recursão direta é exponencial porque recalcula subproblemas; a tabela calcula cada um uma vez.
- Versão bem mais difícil: árvore de partilha ótima, O(n⁵) — fora do escopo.
**Explicações boas:** Dois critérios intuitivos (raiz = mais frequente; raiz = mediana) são contraditórios e nenhum garante o ótimo.
**Pegadinhas:** Árvore ótima pode ser bem desbalanceada; e pode haver mais de uma ótima (empates em k).
**Ideias de exemplos:** Chaves s1 < s2 < s3 com frequências 1, 2, 5 (externas 0). c(0,1)=1, c(1,2)=2, c(2,3)=5; c(0,2)=min(5, 4)=4 (raiz
  s2); c(1,3)=min(12, 9)=9 (raiz s3); c(0,3)=min(0+9, 1+5, 4+0)+8 = 12, raiz s3 ⇒ cadeia s3–s2–s1 com custo
  5·1 + 2·2 + 1·3 = 12, enquanto a árvore balanceada (raiz s2) custa 2 + 1·2 + 5·2 = 14.
**Ideias de exercícios:** Frequências 4, 1, 1 (externas 0): qual a raiz ótima e o custo? → tabela: c(1,3) = 3, c(0,2) = 6;
  c(0,3) = min(0 + 3, 4 + 1, 6 + 0) + 6 = 9, raiz s1 (custo 4·1 + 1·2 + 1·3 = 9).

### NOVO: algoritmo guloso
**Conceitos-chave**
- Nomeado no Huffman: a cada passo junta as duas subárvores de menor frequência. Prova de otimalidade: lema da troca
  (as duas menores podem ser irmãs no último nível) + indução.
- Exercício 12.27 (intercalação ótima de arquivos): sempre intercalar os dois menores — mesmo esquema do Huffman.
**Explicações boas:** O guloso precisa de prova; os critérios "intuitivos" da BST ótima (seção de PD) mostram um guloso que falha.
**Pegadinhas:** Guloso de frequência para BST (pôr o mais frequente na raiz) não é ótimo, ao contrário do Huffman.
**Ideias de exemplos:** Arquivos com 20, 30, 10, 5 chaves: junta 5+10 = 15 (custo 15), 15+20 = 35 (35), 30+35 = 65 (65) ⇒ 115 comparações;
  na ordem dada (20+30, +10, +5) seria 50 + 60 + 65 = 175.
**Ideias de exercícios:** Arquivos de 2, 3, 4, 5: custo mínimo? → 2+3=5, 4+5=9, 5+9=14 ⇒ 28.

### NOVO: análise amortizada
**Conceitos-chave**
- Visão do banqueiro (créditos pré-pagos que operações baratas guardam e caras gastam) e do físico (função potencial Φ:
  custo amortizado = real + Φ(depois) − Φ(antes); se Φ final ≥ Φ inicial, a soma amortizada limita a soma real).
- Exemplo do livro: pilha com operação "k retiradas + 1 inserção"; pior caso individual O(n), mas m operações custam
  ≤ 2m (Φ = tamanho da pilha; custo amortizado = (1 + k) + (p − k + 1) − p = 2).
- Usada depois em listas autoajustáveis, union-find, splay, heaps binomial/Fibonacci, KMP (argumento de "índice que
  nunca volta").
**Explicações boas:** A análise de pior caso não está errada, só é pessimista.
**Pegadinhas:** Amortizado ≠ caso médio: é garantia de pior caso para a SEQUÊNCIA, sem probabilidade.
**Ideias de exemplos:** Contador binário (exercício 8.2) de 0 até 8: bits trocados 1, 2, 1, 3, 1, 2, 1, 4 = 15 < 2·8.
**Ideias de exercícios**
- m incrementos no contador binário: pior caso de um incremento e total amortizado? → O(n bits) e < 2m.
- Vetor que dobra de tamanho (0060/0080): custo amortizado do push? → O(1) (cada elemento paga 3 créditos).

### NOVO: ordenação por distribuição (radix)
**Conceitos-chave**
- b filas (uma por dígito), d passadas do dígito menos significativo ao mais; concatena F0, F1, …; O(n·d).
- Base 2ᵐ (grupos de m bits) evita converter base.
**Explicações boas:** História da classificadora de cartões. Precisa de filas encadeadas (b filas de tamanho imprevisível).
**Pegadinhas:** Cada passada tem de ser estável (fila FIFO garante); usar pilha quebraria o método.
**Ideias de exemplos:** 23 7 41 15 38 2 31, b = 10: unidades → 41 31 2 23 15 7 38; dezenas → 2 7 15 23 31 38 41.
**Ideias de exercícios:** Quantas passadas para ordenar inteiros de 32 bits em base 256? → 4.

### NOVO: limite inferior da ordenação
**Conceitos-chave**
- Árvore de decisão: cada nó interno é uma comparação; folhas são as n! ordens possíveis; altura ≥ log₂(n!) ≈
  n log n ⇒ Ω(n log n) no pior caso para quem só compara. Prova curta: n! ≥ (n/2)^(n/2).
- Logo merge e heap são ótimos.
**Explicações boas:** O livro desenha a árvore de decisão do bolha para 3 elementos (6 folhas).
**Pegadinhas:** O limite é só para métodos por comparação (radix escapa).
**Ideias de exemplos:** n = 3: ⌈log₂ 6⌉ = 3 comparações no pior caso; n = 4: ⌈log₂ 24⌉ = 5; n = 5: ⌈log₂ 120⌉ = 7.
**Ideias de exercícios:** Desenhar a árvore de decisão da inserção para 3 elementos (exercício 7.10). → altura 3, 6 folhas.

### NOVO: árvores gerais (n-árias)
**Conceitos-chave**
- Representar árvore geral com m ponteiros por nó desperdiça O(n²) campos; converter em binária: filho esquerdo =
  primeiro filho, filho direito = próximo irmão (também para florestas, tratando raízes como irmãs). Reversível.
- Árvore m-ária: (m − 1)n + 1 subárvores vazias. Percursos pré e pós para árvores gerais. Isomorfismo.
**Explicações boas:** Por que a binária é a melhor representação: minimiza ponteiros nulos.
**Pegadinhas:** Pré-ordem da geral = pré-ordem da binária convertida; pós-ordem da geral = ordem simétrica da binária.
**Ideias de exemplos:** A(B, C(E, F), D): binária A.esq=B, B.dir=C, C.esq=E, E.dir=F, C.dir=D. Pré: A B C E F D (igual nas duas);
  pós da geral B E F C D A = simétrica da binária.
**Ideias de exercícios**
- Converter a floresta {X(Y), Z} em binária. → X.esq = Y, X.dir = Z.
- Representação sequencial do exercício 3.30 (pré-ordem + índice do nó após a subárvore): calcular níveis.

### NOVO: árvore rubro-negra
**Conceitos-chave**
- Regras: externos negros; mesmo número de negros em todo caminho até externos; rubro não-raiz tem pai negro.
- Equivalente às "árvores graduadas" (posto por nó); conversões de um lado para o outro. h ≤ 2⌊log(n + 1)⌋.
- Inserção: novo nó rubro; pai negro ⇒ fim; pai rubro e tio rubro ⇒ recolorir (pode subir até a raiz, O(log n)
  vezes); tio negro ⇒ uma rotação (simples ou dupla) + troca de duas cores, e acabou. Raiz sempre negra. 1 bit por nó.
- Exercício 5.25: juntando cada rubro ao pai obtém-se uma árvore 2-4 (ponte com árvore B).
**Explicações boas:** Nó externo único compartilhado (sentinela `externo`, cor negra) para economizar memória — o NIL do Cormen.
**Pegadinhas:** Nem toda AVL "precisa" de recoloração para ser rubro-negra, mas toda AVL é rubro-negra e a recíproca é falsa (ex. 5.26).
**Ideias de exemplos:** Inserir 19, 18, 16, 15, 17, 2, 6 (exercício 5.17): 16 ⇒ rotação direita em 19 ⇒ 18N(16R, 19R); 15 ⇒ tio 19 rubro,
  recolore e raiz volta a negra ⇒ 18N(16N(15R), 19N); 17 entra sem problema; 2 ⇒ recolore 15N, 17N, 16R; 6 (filho
  direito de 2, que é filho esquerdo de 15, tio externo negro) ⇒ rotação dupla direita em 15 ⇒ 18N(16R(6N(2R, 15R),
  17N), 19N).
**Ideias de exercícios:** Contar negros (incluindo o externo) em todos os caminhos da árvore final acima. → 3 em todos.

### NOVO: árvore B
**Conceitos-chave**
- Ordem d: raiz com 1..2d chaves; demais páginas d..2d chaves (d+1..2d+1 filhos); folhas no mesmo nível.
- Busca percorre a página; inserção numa folha cheia faz cisão (d ficam, d vão para a nova página, a do meio sobe);
  cisão propaga e pode criar nova raiz (a árvore cresce pela raiz).
- Remoção: chave interna é trocada pela sucessora (sempre numa folha); falta de chave ⇒ concatenação (irmão adjacente,
  soma < 2d, propaga e pode encolher a árvore) ou redistribuição (soma ≥ 2d, não propaga).
- Custos medidos em páginas lidas/escritas (disco). Variante B⁺: dados só nas folhas, índice nas internas.
**Explicações boas:** Motivação: tabela grande em memória secundária; acesso a disco domina o custo.
**Pegadinhas:** "Ordem" do livro ≠ "ordem" do Cormen/Knuth.
**Ideias de exemplos:** d = 2, inserir 10 20 30 40 50: página cheia 10 20 30 40; 50 ⇒ cisão: [10 20] [30] [40 50]. Inserir 60, 70, 80 ⇒
  [40 50 60 70 80] cinde ⇒ raiz [30 60], folhas [10 20] [40 50] [70 80]. Remover 70 ⇒ [80] com 1 chave; irmão [40 50]
  soma 3 < 4 ⇒ concatena [40 50 60 80], raiz [30].
**Ideias de exercícios:** Desenhar árvore B de ordem 3 com 1 3 6 8 14 32 36 38 39 41 43 (exercício 5.34). → cabe numa raiz e duas folhas, ex.
  raiz [14], folhas [1 3 6 8] e [32 36 38 39 41 43]; checar 3 ≤ chaves ≤ 6.

### NOVO: trie (árvore digital) e Patricia
**Conceitos-chave**
- Chave tratada dígito a dígito; árvore m-ária em que o j-ésimo filho representa o j-ésimo símbolo do alfabeto; nó
  marcado "terminal" quando fecha uma chave. Busca O(k) (k = tamanho da chave), independente de n.
- Achar um prefixo acha todas as chaves com esse prefixo (subárvore). Espaço O(n·m·t) é o problema.
- Árvore digital binária; árvore binária de prefixo (nenhuma chave é prefixo de outra); Patricia: comprime zigue-zagues
  e guarda em cada nó o índice do próximo dígito a testar; como pula dígitos, compara a chave inteira na folha.
  Folhas da esquerda para a direita = ordem lexicográfica.
**Explicações boas:** A trie é única para um conjunto, independentemente da ordem de inserção (exercício 11.2) — contraste com a BST.
**Pegadinhas**
- Sem o campo "terminal", o prefixo "ar" seria dado como achado só por existir "arara".
- Na Patricia, uma chave inválida pode chegar a uma folha: sem a comparação final daria falso positivo.
**Ideias de exemplos**
- Chaves {as, asa, sal, ar, arara}: raiz → a → {r → a → r → a, s → a}, s → a → l; terminais em "ar", "arara", "as",
  "asa", "sal". Buscar "ara": caminho existe, mas o nó não é terminal ⇒ ausente.
- Patricia com {0001, 0011, 1000}: raiz testa o dígito 1; à esquerda, nó que testa o dígito 3 (o 2 é igual nas duas).
  Buscar 0111: dígito 1 = 0, dígito 3 = 1 ⇒ folha 0011 ≠ 0111 ⇒ ausente.
**Ideias de exercícios:** Quantos nós tem a trie de {ar, as}? → 4 (raiz, a, r, s).

### NOVO: conjuntos disjuntos (union-find)
**Conceitos-chave**
- Operações gerar, buscar(x), fundir(a, b); floresta com ponteiro para o pai; nó-cabeça liga nome do conjunto à raiz.
- Fusão por tamanho (menor aponta para maior) ⇒ altura O(log n) (prova: 2^(h−1) ≤ tamanho).
- Compactação no buscar: compressão (todos apontam para a raiz), separação (cada um para o avô), divisão (nós
  alternados para o avô). Com tamanho + compressão: O(n + m·α(m+n, n)), α = inversa de Ackermann ≤ 4 na prática.
**Explicações boas:** Sequência ruim sem critério: fundir(2,1), fundir(3,2), … forma uma lista de altura n.
**Pegadinhas:** Com fusão por tamanho, o nome do conjunto nem sempre é a raiz (por isso o vetor `nome`).
**Ideias de exemplos:** Cadeia a6 → a5 → … → a1 (raiz), buscar(a6): compressão ⇒ todos apontam a1; separação ⇒ a6→a4, a5→a3, a4→a2,
  a3→a1; divisão ⇒ a6→a4, a4→a2 (a5 e a3 inalterados).
**Ideias de exercícios**
- Gerar {1..5}; fundir(1,3), fundir(2,5), fundir(1,4) com tamanho. → árvores {raiz 1: filhos 3, 4} e {raiz 2: filho 5}.
- Pegadinha do exercício 8.7 do livro: `fundir` recebe NOMES de conjuntos; depois de fundir(1,3) o conjunto "3" deixou
  de existir, então fundir(3,4) deve ser lido como fundir(buscar(3), 4) = fundir(1, 4).

### NOVO: código de Huffman (e compactação)
**Conceitos-chave**
- Códigos de prefixo = folhas de árvore binária; custo = Σ fᵢ·ℓᵢ (comprimento de caminho externo ponderado).
- Algoritmo: lista de prioridades (min-heap) com as frequências; n − 1 vezes retira as duas menores, junta, reinsere;
  O(n log n). Prova pelo lema da troca + indução.
- Antes, compactação por frequência de símbolos repetidos (RLE): "BBBE…" → "3BE…", com caractere de escape (@) quando
  o texto tem dígitos.
**Explicações boas**
- Decodificação: anda na árvore conforme o bit, volta à raiz a cada folha; linear.
- Desvantagem: um bit errado na transmissão bagunça o resto da decodificação.
**Pegadinhas:** Empates geram árvores diferentes com o mesmo custo ótimo (não similares, exercício 12.21).
**Ideias de exemplos**
- "ABRACADABRA": A5 B2 R2 C1 D1. Junta C+D = 2; B+R = 4 (ou CD+B); 2+4 = 6; A+6 = 11. Comprimentos A1, B3, R3, C3, D3
  ⇒ 5 + 6 + 6 + 3 + 3 = 23 bits, contra 33 com 3 bits fixos. Desempate alternativo dá A1, R2, B3, C4, D4 = 23 também.
- RLE: AAAABBBCCD → 4A3B2CD.
**Ideias de exercícios:** Frequências 1, 1, 2, 3, 5: custo da árvore de Huffman? → 1+1=2, 2+2=4, 3+4=7, 5+7=12; Σ das junções = 2+4+7+12 = 25.

### NOVO: ordenação topológica
**Conceitos-chave:** Ordem parcial (reflexiva, antissimétrica, transitiva); imergir numa ordem linear. Repetidamente retira um elemento sem
  predecessores. Implementação com uma lista de sucessores por objeto e contador de predecessores no nó-cabeça; fila de
  candidatos encadeada pelo próprio campo contador; O(n + m).
**Explicações boas:** Exemplo de tarefas de montagem de carro; pares supérfluos (dedutíveis por transitividade) não atrapalham.
**Pegadinhas**
- Se em algum momento não há elemento com contador 0, existe ciclo (não é ordem parcial).
- Reaproveitar o campo contador como ponteiro de fila é esperto, mas confuso para iniciantes: em C, usar fila separada.
**Ideias de exemplos:** Objetos 1..6, pares (1,2) (1,3) (2,4) (3,4) (4,5) (6,5): contadores 0,1,1,2,2,0; fila 1, 6; sai 1 (2 e 3 zeram);
  sai 6; sai 2; sai 3 (4 zera); sai 4 (5 zera); sai 5 ⇒ 1 6 2 3 4 5.
**Ideias de exercícios:** Acrescentar o par (5,1) ao exemplo: o que acontece? → nenhum contador chega a zero para 1..5; detecta ciclo.

### NOVO: busca de padrões (força bruta e KMP)
**Conceitos-chave**
- Força bruta: testa cada deslocamento ℓ = 0..n−m, abandona na primeira discordância; pior caso (n − m + 1)·m.
- KMP: vetor d(k) = maior prefixo próprio de y₁..y_k que também é sufixo; ao discordar em j, faz j := d[j] sem nunca
  recuar o índice do texto; d é calculado casando o padrão consigo mesmo; total O(n + m) (argumento amortizado:
  decrementos de j ≤ incrementos).
- Boyer-Moore e Karp-Rabin só citados (não sustenta módulo sobre eles).
**Explicações boas:** O deslocamento seguro depende só do padrão, não do texto — por isso dá para pré-processar.
**Pegadinhas:** Índices: o livro usa padrão de 1..m; em C (0..m−1) o vetor de falha muda de deslocamento.
**Ideias de exemplos**
- d para "ababaca": 0 0 1 2 3 0 1.
- Força bruta, X = "aaaaab", Y = "aab": cada deslocamento compara até 3 caracteres; casamento em ℓ = 3.
**Ideias de exercícios:** Vetor d de "araraquara" (exercício 12.13). → 0 0 1 2 3 0 0 1 2 3.

### NOVO: matriz esparsa
**Conceitos-chave:** Só como exercício (2.20–2.22): estrutura com espaço O(k) para k elementos relevantes; localizar a_ij; calcular A².
**Explicações boas:** Bom exercício-síntese de listas encadeadas (listas por linha e por coluna).
**Pegadinhas:** Matriz 1000×1000 com 3000 não nulos: 1.000.000 de posições densas contra ~3000 nós.
**Ideias de exemplos:** Lista por linha de (coluna, valor): linha 0 → (2, 5); linha 3 → (0, 1) → (4, 7).
**Ideias de exercícios:** Custo de buscar a_ij com listas por linha ordenadas por coluna? → O(número de elementos da linha i).

### NOVO: listas autoajustáveis
**Conceitos-chave**
- Métodos: mover para a frente (MF), transposição (TR), contador de frequência (CF), mover k posições, híbridos.
- Teorema: MF custa no máximo o dobro de qualquer método "admissível" (prova com potencial = número de inversões entre a
  lista MF e a outra). Falso para TR e CF (contraexemplos do livro).
- Usos: listas de colisão em hash, política LRU de memória virtual.
**Explicações boas:** Nó raro movido para a frente atrapalha todos os outros (custo do MF); TR é bom em vetor, CF converge para a ordem
  estática ótima.
**Pegadinhas:** "MF é o melhor método" — errado, o teorema só limita a 2× (exercício 8.6).
**Ideias de exemplos:** Lista a b c d e, acessos e e d e. MF: custos 5, 1, 5, 2 = 13 (final e d a b c). TR: 5, 4, 5, 3 = 17. CF: 5, 1, 5,
  1 = 12 (final e d a b c).
**Ideias de exercícios:** a b c d e f g com acessos g f d f b f f d c, configuração final com MF (exercício 8.4). → c d f b g a e.

### NOVO: árvore de difusão (splay)
**Conceitos-chave**
- BST comum (sem campo extra) que, após cada acesso/inserção, leva o nó até a raiz por "difusões": zig (pai é a raiz),
  zig-zig (mesmo lado: gira o avô e depois o pai), zig-zag (lados opostos: rotação dupla). Remoção difunde o pai.
- Custo amortizado O(log n) por operação (potencial = soma dos log dos tamanhos das subárvores; lema 1 + 3[p(r) − p(q)]).
**Explicações boas:** Comparação com balanceadas: nada de informação extra, ajustes locais frequentes em vez de rebalanceamento por regras.
**Pegadinhas**
- Uma operação isolada pode custar O(n); só a sequência é garantida.
- Zig-zig gira primeiro o AVÔ (girar o pai primeiro dá a "rotação simples repetida", que é O(n) amortizado, ex. 8.21).
**Ideias de exemplos:** Cadeia à direita 1→2→3→4→5, acessar 5: zig-zig em (3, 4, 5) ⇒ 5(4(3)) pendurado em 2; zig-zig em (1, 2, 5) ⇒ raiz
  5, filho esquerdo 2 com filhos 1 e 4, 4 com filho 3. Altura cai de 5 para 4 e o caminho fica pela metade.
**Ideias de exercícios:** Por que a árvore splay não precisa guardar altura nem cor? → O ajuste não depende de padrão de balanceamento.

### NOVO: heaps fundíveis (esquerdista, binomial, Fibonacci) — opcional/avançado
**Conceitos-chave**
- Esquerdista: CC(v) (caminho curto) do filho esquerdo ≥ do direito; caminho direito O(log n); fusão recursiva pelo
  caminho direito trocando filhos quando preciso; inserir e remover = fusão.
- Binomial: floresta de árvores binomiais Bₕ de ordens distintas (2ʰ nós; nível j tem C(h, j) nós); corresponde à
  representação binária de n; fusão = soma binária; inserção O(1) esperado/amortizado.
- Fibonacci: binomial "relaxado" com marcas e cortes em cascata; aumento de prioridade O(1) amortizado.
- Heaps distorcidos (skew): esquerdista sem guardar CC, sempre troca filhos; O(log n) amortizado.
**Explicações boas:** 26 = 11010₂ ⇒ o único heap binomial de 26 nós é {B1, B3, B4}.
**Pegadinhas:** Heap esquerdista pode ser muito desbalanceado e ainda assim eficiente.
**Ideias de exemplos:** Fundir heaps binomiais de 5 (101) e 3 (011) nós ⇒ 8 (1000): só uma B3.
**Ideias de exercícios:** Quais árvores tem o heap binomial de 13 nós? → 1101₂ ⇒ B0, B2, B3.

### NOVO: tabela hash dinâmica (dispersão linear)
**Conceitos-chave:** Expande um compartimento por vez (ponteiro p): divide a lista de p entre p e p + m·2ˡ com h_{ℓ+1}(x) = x mod (m·2^{ℓ+1});
  endereço = h_ℓ(x), e se < p, recalcula com h_{ℓ+1}. Diretório de segmentos de tamanho fixo. Só funciona bem com
  encadeamento exterior.
**Explicações boas:** Evita o "rehash" de tudo de uma vez (custo diluído — liga com análise amortizada).
**Pegadinhas:** Com endereçamento aberto a expansão exige copiar chaves e não há listas bem definidas.
**Ideias de exemplos:** m = 5: chaves 10, 15, 3. Expandir p = 0: com mod 10, 10 fica em 0 e 15 vai para 5; p passa a 1.
**Ideias de exercícios:** Com m = 3, ℓ = 0, p = 1, onde fica a chave 12? → h₀ = 0 < p ⇒ h₁ = 12 mod 6 = 0.

### NOVO: alocação de memória de tamanho variável
**Conceitos-chave:** Lista de blocos livres guardada dentro da própria memória (tamanho + próximo); primeira escolha (first-fit) com limite
  c contra fragmentos; liberação funde com vizinhos livres, lista em ordem de endereço; O(n) por operação (O(log n) com
  lista de prioridades, ex. 6.20). Melhor escolha (best-fit) nem sempre é melhor (ex. 2.29).
**Explicações boas:** Mostra o que malloc/free fazem por dentro; ótimo para o módulo de memória dinâmica.
**Pegadinhas:** Reservar a parte de cima do bloco para não mexer no cabeçalho do bloco livre.
**Ideias de exemplos:** Livres: [100 palavras em 10], [30 em 200]; pedido de 25 com first-fit ⇒ sai do primeiro (sobra 75).
**Ideias de exercícios:** Com best-fit, o mesmo pedido sai de onde? → do bloco de 30 (sobra 5).

### Candidatos que o livro NÃO sustenta
Backtracking; shell, counting e bucket sort; seleção do k-ésimo (só menciona que achar a mediana para pivô é caro);
teorema mestre; componentes conexos; MST de Prim/Kruskal (só citação nas notas dos heaps); Bellman-Ford;
Floyd-Warshall; Boyer-Moore e Rabin-Karp (só citados com a observação: BM costuma ser melhor para alfabeto e padrão
grandes; Karp-Rabin usa hash, pior caso quadrático e médio linear); skip list.

---

## Recomendações de assuntos novos

O livro sustenta muito bem (definição + algoritmo + análise + exercícios com resposta verificável):
**análise amortizada, union-find, listas autoajustáveis, splay, rubro-negra, árvore B, trie/Patricia, KMP, Huffman,
ordenação topológica, radix, limite inferior, programação dinâmica (BST ótima), árvores gerais, hash dinâmico**.
Sustenta parcialmente: recorrências (só telescópio), divisão e conquista (implícita), guloso (só Huffman e
intercalação de arquivos), matriz esparsa (só exercícios), heaps fundíveis (avançado demais para o público).

Ordem sugerida, encaixando no sumário atual:

1. **Depois de 0079-tad:** recorrências por telescópio (usa Hanói/Fibonacci já vistos) e análise amortizada básica
   (pilha com multipop, contador binário, vetor que dobra de 0060/0080).
2. **Depois do módulo 11/12 (listas, pilhas, filas):** matriz esparsa (síntese de listas), listas autoajustáveis (MF/TR/CF,
   usa a amortizada), alocação first-fit (retoma 0059/0062).
3. **No módulo 13 (ordenação):** radix por distribuição (usa filas de 0091), limite inferior por árvore de decisão (fecha
   0101), divisão e conquista como lente sobre merge/quick.
4. **No módulo 14 (árvores):** árvores gerais com conversão primeiro-filho/próximo-irmão (logo após 0103); depois de 0106,
   rubro-negra e árvore B; depois de 0108, Huffman como primeiro algoritmo guloso (usa o heap como min-fila).
5. **Novo módulo "árvores especiais":** splay (usa rotações da AVL + amortizada), trie e Patricia (pode vir junto de hash
   como "outra forma de buscar").
6. **Módulo 15 (hash):** tabela dinâmica (dispersão linear) como extensão de 0113.
7. **Novo módulo "conjuntos e grafos" (antes ou junto do 16):** union-find e ordenação topológica — esta última pode ser o
   primeiro algoritmo do módulo de grafos, já que só precisa de listas de adjacência e uma fila.
8. **Novo módulo "técnicas de projeto":** programação dinâmica com a BST ótima (e um exemplo mais simples de outra fonte),
   guloso com intercalação ótima de arquivos, e KMP como fecho (texto), com força bruta antes.
9. **Opcional/avançado:** heaps min-max, esquerdista, binomial, Fibonacci.

Para backtracking, shell/counting/bucket sort, k-ésimo, teorema mestre, Prim/Kruskal, Bellman-Ford, Floyd-Warshall,
componentes conexos, Boyer-Moore, Rabin-Karp e skip list, usar outra fonte (este livro não ajuda).
