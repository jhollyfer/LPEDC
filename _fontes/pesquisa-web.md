# Pesquisa web: o que falta no sumário do LPEDC (Estrutura de Dados e Algoritmos)

Data da pesquisa: 18/10/2026. Base: `_fontes/sumario.md` (módulos 10 a 16).

## 1. Como a pesquisa foi feita

- Buscas na web por ementas e planos de ensino: MAC0121 e MAC0323 (IME-USP), MC202 e MC458
  (IC-UNICAMP), o site do Paulo Feofiloff, CLRS 4ª ed., Sedgewick *Algorithms in C* (partes 1-4),
  *Algorithms* 4ª ed. (Sedgewick e Wayne, site algs4), CS50, VisuAlgo e Open Data Structures.
- **Aviso honesto:** desta máquina o WebFetch não conseguiu abrir `ime.usp.br`, `ic.unicamp.br`
  nem `opendatastructures.org` (falha de DNS/proxy). Os links abaixo vieram dos resultados de busca
  (título + trecho) ou são endereços conhecidos e estáveis. Confira cada link antes de publicar.
- CI1055/CI1056 (UFPR): a busca não achou a ementa oficial. Usei como equivalente o plano de
  "Algoritmos e Estruturas de Dados 2" da UTFPR, que cobre o mesmo tipo de conteúdo.
- Todo texto explicativo abaixo foi escrito com minhas palavras; nada foi copiado das fontes.

### Fontes consultadas (com o que cada uma confirma)

| Fonte | Link | O que confirma |
|---|---|---|
| Feofiloff, Projeto de Algoritmos em C (índice) | https://www.ime.usp.br/~pf/algoritmos/ | recursão, enumeração, backtracking, ordenação digital, busca de palavras, BST, hash, filas de prioridade |
| Feofiloff, livro *Algoritmos em linguagem C* | https://www.ime.usp.br/~pf/algoritmos-livro/ | mesmo conteúdo em livro (cap. 13: busca de palavras / Boyer-Moore) |
| Feofiloff, KMP | https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html | KMP (citado nos slides de MAC0323) |
| Feofiloff, livrinho de Análise de Algoritmos | https://www.ime.usp.br/~pf/livrinho-AA/ | recorrências, análise de custo |
| MAC0121 (USP) 2023 | https://www.ime.usp.br/~yoshi/2023ii/mac0121/html/docs/00info.pdf | corretude, complexidade, TAD; usa Sedgewick-Wayne |
| MAC0323 (USP) | https://ime.usp.br/~yoshi/2015i/mac323/html/docs/00info.pdf | estruturas avançadas (tabelas de símbolos, árvores balanceadas, grafos, strings) |
| MAC0323 slides de busca de padrões | https://www.ime.usp.br/~coelho/mac0323-2018/aulas/aula25/slides.pdf | KMP, Rabin-Karp, Boyer-Moore |
| MAC0323 rubro-negras | https://www.ime.usp.br/~coelho/mac0323-2017/aulas/aula11/rabiscos11.pdf | rubro-negra esquerdista (LLRB) simulando árvore 2-3 |
| Union-find (USP) | https://www.ime.usp.br/~cris/aulas/20_2_323/slides/aula05.pdf | QuickFind, QuickUnion, união ponderada |
| Union-find com compressão | https://www.ime.usp.br/~cris/aulas/14_1_6711/uf.pdf | união por posto + compressão de caminho |
| Quickselect (MAC122) | https://www.ime.usp.br/~yoshi/2006ii/mac122a/Slides/2006.10.17/lecture.pdf | seleção pelo particionamento do quicksort |
| MC202 (UNICAMP) | https://ic.unicamp.br/historico-ic/graduacao/plano-desenvolvimento-disciplinas/1s2022/MC202ABC.pdf | listas, pilhas, filas, ordenação, BST, rubro-negra, heap, árvore B, hash, grafos, Dijkstra |
| MC458 (UNICAMP) 2025 | https://www.ic.unicamp.br/~santiago/assets/mc458/MC458__2025___PDD.pdf | indução, divisão e conquista, estatísticas de ordem, PD, gulosos |
| UTFPR AED2 (no lugar de UFPR CI1056) | https://antigo.utfpr.edu.br/cursos/coordenacoes/graduacao/pato-branco/pb-engenharia-de-computacao/documentos/plano-de-ensino/3o-periodo/ae23cp-algoritmos-e-estrutura-de-dados-2 | árvores balanceadas, grafos, memória secundária, D&C, PD, backtracking |
| CLRS 4ª ed. | https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/ | recorrências/teorema mestre, ordenação linear, seleção, amortizada, árvore B, union-find, MST, caminhos mínimos, strings |
| Sedgewick, Algorithms in C 1-4 | https://www.informit.com/store/algorithms-in-c-parts-1-4-fundamentals-data-structures-9780201314526 | radix sort, ordenações especiais, árvores balanceadas, skip list, tries, busca externa |
| Sedgewick-Wayne, algs4 | https://algs4.cs.princeton.edu/home/ | 1.5 union-find, 2.1 shellsort, 3.3 balanceadas, 4.2-4.4 grafos, 5.1-5.3 strings, 5.5 Huffman |
| CS50 semana 5 | https://cs50.harvard.edu/x/2025/weeks/5 | TAD, pilhas, filas, listas, árvores, hash, **tries** |
| VisuAlgo | https://visualgo.net/en | animações: sorting, list, heap, bst, ufds, dfsbfs, mst, sssp |
| Open Data Structures (Pat Morin) | https://opendatastructures.org/ | skiplists, treaps, scapegoat, árvore B, tries binárias, amortizada |

## 2. Diagnóstico: o que já existe e o que falta

**Já existe (confirmado no sumário):** deque (0092), heap e fila de prioridade (0107), heapsort
(0108), AVL (0106), BFS/DFS (0115/0116), Dijkstra (0117), hash com encadeamento e sondagem linear,
merge/quick sort, Big-O e invariantes. Recursão básica (0037/0038, inclusive Hanói e Euclides)
está no módulo 04 e serve de pré-requisito para backtracking e divisão e conquista.

**Falta (todos os itens pedidos foram verificados e nenhum aparece no sumário):**

| # | Tema | Aparece em |
|---|---|---|
| T01 | recorrências e árvore de recursão | CLRS cap. 4, Feofiloff AA, MC458 |
| T02 | teorema mestre | CLRS cap. 4, MC458 |
| T03 | análise amortizada | CLRS (parte V), ODS cap. 1-2 |
| T04 | limite inferior Ω(n log n) | CLRS cap. 8, MC458 |
| T05 | shell sort | Sedgewick cap. 6, algs4 2.1 |
| T06 | counting sort | CLRS cap. 8, Feofiloff (ordenação digital) |
| T07 | radix sort | CLRS cap. 8, Sedgewick cap. 10 |
| T08 | bucket sort | CLRS cap. 8 |
| T09 | quickselect | CLRS cap. 9, MC458 (estatísticas de ordem), MAC122 |
| T10 | enumeração (subconjuntos, permutações) | Feofiloff (enumeração) |
| T11 | backtracking e N-rainhas | Feofiloff, UTFPR AED2 |
| T12 | divisão e conquista como técnica | MC458, CLRS cap. 4 |
| T13 | algoritmos gulosos | MC458, CLRS cap. 15 |
| T14 | Huffman | CLRS cap. 15, algs4 5.5 |
| T15 | programação dinâmica: memoização | MC458, CLRS cap. 14 |
| T16 | troco (PD) | idem |
| T17 | mochila 0/1 | idem, slides MAC0338 |
| T18 | LCS e distância de edição | CLRS cap. 14 |
| T19 | árvores gerais (filho-esquerdo/irmão-direito) | CLRS cap. 10 |
| T20 | árvore rubro-negra | MC202, MAC0323, CLRS cap. 13 |
| T21 | árvore B | MC202, CLRS cap. 18, ODS cap. 14 |
| T22 | trie | CS50 sem. 5, algs4 5.2, Sedgewick cap. 15 |
| T23 | union-find | MAC0323, CLRS cap. 19, VisuAlgo ufds |
| T24 | componentes conexos e ciclos | algs4 4.1/4.2 |
| T25 | ordenação topológica | CLRS cap. 20, algs4 4.2 |
| T26 | MST: Kruskal | CLRS cap. 21, VisuAlgo mst |
| T27 | MST: Prim | idem |
| T28 | Bellman-Ford | CLRS cap. 22, VisuAlgo sssp |
| T29 | Floyd-Warshall | CLRS cap. 23 |
| T30 | busca de padrão: força bruta | Feofiloff, algs4 5.3 |
| T31 | KMP | Feofiloff, MAC0323 |
| T32 | Boyer-Moore-Horspool | Feofiloff cap. 13, MAC0323 |
| T33 | Rabin-Karp | MAC0323, CLRS cap. 32 |
| T34 | matriz esparsa | ementas clássicas de ED (listas cruzadas) |
| T35 | skip list | ODS cap. 4, Sedgewick cap. 13 |
| T36 | listas autoajustáveis | Sedgewick (busca sequencial), literatura de ED |

**Fora do escopo (citar no máximo como "para ir além"):** treap, splay, scapegoat, heap de
Fibonacci, van Emde Boas, fluxo em redes, árvores de sufixo, ordenação externa, Fenwick/segment
tree, NP-completude. Aparecem em CLRS, ODS e VisuAlgo, mas pesam demais para um curso pessoal.

---

## 3. Fichas dos temas que faltam

Formato de cada ficha: definição, por que importa, passo a passo com exemplo, pegadinhas, custo,
3 exercícios com resposta e fonte.

### T01 · Recorrências e árvore de recursão
- **O que é:** uma recorrência é uma equação que dá o custo de uma função recursiva em termos do
  custo dela mesma com entradas menores, por exemplo T(n) = 2T(n/2) + n.
- **Por que importa:** é a única forma de medir merge sort, busca binária, Hanói. Sem isso,
  "O(n log n)" fica decorado e não entendido.
- **Passo a passo:** (1) olhe o código e conte quantas chamadas recursivas há e com que tamanho;
  (2) some o trabalho fora das chamadas; (3) escreva o caso base; (4) resolva desenhando a árvore:
  cada nível tem um custo, some os níveis.
- **Exemplo:** merge sort com n = 8. Nível 0: 1 problema de 8, custo 8. Nível 1: 2 de 4, custo 8.
  Nível 2: 4 de 2, custo 8. Nível 3: 8 de 1. São log₂8 = 3 níveis de custo 8, total 24 = n log₂ n.
- **Pegadinhas:** esquecer o caso base; confundir T(n-1) (cai de um em um, n níveis) com T(n/2)
  (cai pela metade, log n níveis); Fibonacci ingênuo é T(n) = T(n-1) + T(n-2) + 1, exponencial.
- **Custo:** é a própria ferramenta de análise.
- **Exercícios:**
  1. Escreva a recorrência da busca binária. → T(n) = T(n/2) + 1, T(1) = 1; resulta Θ(log n).
  2. Resolva T(n) = T(n-1) + n pela árvore (que vira uma linha). → n + (n-1) + ... + 1 = n(n+1)/2 = Θ(n²) (é o selection sort recursivo).
  3. Quantas chamadas faz `fib(5)` ingênuo? → 15 (em geral 2·F(n+1) − 1).
- **Fonte:** https://www.ime.usp.br/~pf/livrinho-AA/ · CLRS cap. 4 (https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)

### T02 · Teorema mestre
- **O que é:** uma "tabela pronta" que resolve recorrências da forma T(n) = a·T(n/b) + f(n),
  comparando f(n) com n^(log_b a), o custo total das folhas.
- **Por que importa:** resolve em 10 segundos quase todo algoritmo de divisão e conquista.
- **Passo a passo:** (1) identifique a, b, f(n); (2) calcule c = log_b a; (3) compare:
  - f(n) cresce mais devagar que n^c → T(n) = Θ(n^c) (as folhas dominam);
  - f(n) = Θ(n^c) → T(n) = Θ(n^c · log n) (todos os níveis pesam igual);
  - f(n) cresce mais rápido que n^c (e é "regular") → T(n) = Θ(f(n)) (a raiz domina).
- **Exemplo:** T(n) = 8T(n/2) + n². a = 8, b = 2, c = log₂8 = 3. n² é menor que n³ → Θ(n³).
- **Pegadinhas:** não vale para T(n) = T(n-1) + n (não divide n); não vale quando f e n^c diferem
  só por um log (ex.: 2T(n/2) + n/log n); "mais devagar" quer dizer por um fator polinomial n^ε.
- **Exercícios:**
  1. T(n) = 2T(n/2) + n. → c = 1, empate → Θ(n log n).
  2. T(n) = 3T(n/2) + n. → c = log₂3 ≈ 1,585, folhas dominam → Θ(n^1,585) (Karatsuba).
  3. T(n) = 2T(n/2) + 1. → c = 1, f = 1 menor → Θ(n) (ex.: achar o máximo dividindo ao meio).
- **Fonte:** CLRS cap. 4; MC458 (https://www.ic.unicamp.br/~santiago/assets/mc458/MC458__2025___PDD.pdf)

### T03 · Análise amortizada
- **O que é:** medir o custo médio por operação numa sequência longa de operações, sem
  probabilidade: algumas operações são caras, mas raras, e o total fica barato.
- **Por que importa:** explica por que o vetor que cresce (0060 e 0080) tem inserção "O(1)" mesmo
  copiando tudo de vez em quando. É a base de realloc em dobro, union-find e tabelas hash que crescem.
- **Passo a passo (método agregado):** (1) some o custo real de n operações; (2) divida por n.
- **Exemplo:** vetor de capacidade inicial 1 que dobra quando enche, 8 inserções. Cópias ao dobrar:
  1 (1→2), 2 (2→4), 4 (4→8) = 7 cópias + 8 escritas = 15 ≤ 2·8. Média < 2 por inserção → O(1) amortizado.
- **Outro exemplo:** contador binário incrementado n vezes. O bit 0 vira n vezes, o bit 1 n/2, o
  bit 2 n/4... total < 2n trocas de bit.
- **Pegadinhas:** amortizado não é caso médio (não há sorteio) nem garante que cada operação é
  rápida; crescer de +10 em +10 (em vez de dobrar) dá O(n) amortizado, que é a armadilha clássica.
- **Exercícios:**
  1. Se o vetor cresce somando 1 à capacidade, quantas cópias para n inserções? → 1+2+...+(n−1) = Θ(n²).
  2. Pilha com `multipop(k)`: n operações custam no máximo quanto? → O(n): cada item sai no máximo uma vez.
  3. Com fator 1,5 em vez de 2, continua O(1) amortizado? → Sim, qualquer fator constante > 1 serve.
- **Fonte:** CLRS (parte "Advanced Data Structures"); ODS cap. 2 (https://opendatastructures.org/)

### T04 · Limite inferior da ordenação por comparação
- **O que é:** a prova de que qualquer ordenação que só compara pares precisa, no pior caso, de
  pelo menos log₂(n!) ≈ n log₂ n comparações.
- **Por que importa:** mostra que merge sort e heapsort são ótimos, e explica por que counting e
  radix "furam" o limite: eles não comparam, olham os dígitos.
- **Passo a passo:** (1) desenhe a árvore de decisão: cada nó é uma comparação "a < b?";
  (2) cada folha é uma ordem final; precisa haver n! folhas; (3) árvore binária de altura h tem
  no máximo 2^h folhas, então 2^h ≥ n! e h ≥ log₂(n!).
- **Exemplo:** n = 3 → 3! = 6 folhas → h ≥ log₂6 ≈ 2,58 → pelo menos 3 comparações no pior caso.
- **Pegadinhas:** é limite de pior caso (insertion sort faz n−1 comparações em vetor já ordenado);
  vale só para o modelo de comparação.
- **Exercícios:**
  1. Mínimo de comparações para ordenar 4 elementos? → ⌈log₂24⌉ = 5.
  2. Achar o máximo exige quantas comparações? → n−1 (cada não-máximo tem de perder uma vez); não é n log n.
  3. Por que counting sort não contradiz o limite? → Ele usa o valor como índice, não compara.
- **Fonte:** CLRS cap. 8; MC458 (programa 2025)

### T05 · Shell sort
- **O que é:** insertion sort feito várias vezes com "saltos" h decrescentes; termina com h = 1,
  que é o insertion sort comum, mas sobre um vetor já quase ordenado.
- **Por que importa:** é o primeiro algoritmo que quebra a barreira O(n²) com código curto e sem
  memória extra; ótimo para mostrar que a escolha de parâmetros muda o custo.
- **Passo a passo:** (1) escolha a sequência de saltos (Knuth: 1, 4, 13, 40..., h = 3h+1);
  (2) para cada h, do maior ao menor, faça insertion sort entre elementos a distância h.
- **Exemplo:** v = [8,5,3,9,1,6,2,7], saltos 4, 2, 1.
  h=4: pares (8,1)(5,6)(3,2)(9,7) → [1,5,2,7,8,6,3,9].
  h=2: posições pares 1,2,8,3 → 1,2,3,8; ímpares 5,7,6,9 → 5,6,7,9 → [1,5,2,6,3,7,8,9].
  h=1: insertion final → [1,2,3,5,6,7,8,9] com poucas trocas.
- **Pegadinhas:** não é estável; a sequência n/2, n/4... (a original) tem pior caso O(n²); sempre
  terminar com h = 1.
- **Custo:** depende dos saltos; com Knuth, O(n^1,5) no pior caso; espaço O(1).
- **Exercícios:**
  1. Gere os saltos de Knuth menores que 100. → 1, 4, 13, 40.
  2. Mostre que não é estável. → [3, 2a, 2b, 1] com h=2 vira [2b,1,3,2a]; com h=1 fica [1,2b,2a,3]: 2b passou à frente de 2a.
  3. Shell sort com só h = 1 é qual algoritmo? → insertion sort.
- **Fonte:** algs4 2.1 (https://algs4.cs.princeton.edu/21elementary/); Sedgewick cap. 6

### T06 · Counting sort (ordenação por contagem)
- **O que é:** ordena inteiros pequenos (0..k) contando quantas vezes cada valor aparece e
  calculando onde cada valor começa na saída.
- **Por que importa:** é linear, é estável e é a peça interna do radix sort.
- **Passo a passo:** (1) conte cada valor em `cont[0..k]`; (2) transforme em somas acumuladas
  (cont[x] = quantos são ≤ x); (3) percorra a entrada **de trás para frente** e coloque cada
  item em `saida[--cont[x]]`.
- **Exemplo:** v = [2,5,3,0,2,3,0,3], k = 5. Contagem: 0→2, 1→0, 2→2, 3→3, 4→0, 5→1.
  Acumulado: 2,2,4,7,7,8. Saída: [0,0,2,2,3,3,3,5].
- **Pegadinhas:** k grande (ex.: valores até 10⁹) estoura a memória; percorrer da frente quebra a
  estabilidade; negativos exigem deslocamento (somar −mínimo).
- **Custo:** O(n + k) tempo, O(n + k) espaço.
- **Exercícios:**
  1. Acumulado de [1,0,1,1] com k=1? → contagem 1,3 → acumulado 1,4.
  2. Como ordenar notas de 0 a 10 de 1 milhão de alunos? → counting sort com k = 10.
  3. Adapte para valores de −3 a 3. → índice = valor + 3.
- **Fonte:** CLRS cap. 8; Feofiloff, "ordenação digital" (https://www.ime.usp.br/~pf/algoritmos/)

### T07 · Radix sort (ordenação digital, LSD)
- **O que é:** ordena números dígito a dígito, do menos significativo ao mais significativo,
  usando a cada passo uma ordenação estável (counting sort com k = base − 1).
- **Por que importa:** ordena milhões de inteiros ou strings de tamanho fixo em tempo linear.
- **Passo a passo:** (1) d = número de dígitos do maior; (2) para cada dígito, da unidade para
  cima, faça counting sort estável por aquele dígito.
- **Exemplo:** [170,45,75,90,802,24,2,66].
  Unidade: [170,90,802,2,24,45,75,66]. Dezena: [802,2,24,45,66,170,75,90].
  Centena: [2,24,45,66,75,90,170,802].
- **Pegadinhas:** se a ordenação interna não for estável, o resultado sai errado; começar pelo
  dígito mais significativo exige outra versão (MSD, recursiva).
- **Custo:** O(d·(n + b)), b = base. Com base 256 (um byte por vez), int de 32 bits = 4 passadas.
- **Exercícios:**
  1. Quantas passadas para números até 99 999 em base 10? → 5.
  2. Ordene [31,12,22,11] por radix. → unidade [31,11,12,22] → dezena [11,12,22,31].
  3. Por que usar base 256 em vez de 10? → menos passadas e o dígito sai com `>>` e `& 0xFF`.
- **Fonte:** CLRS cap. 8; Sedgewick cap. 10; algs4 5.1 (https://algs4.cs.princeton.edu/51radix/)

### T08 · Bucket sort (ordenação por baldes)
- **O que é:** espalha valores em n baldes por faixa, ordena cada balde (insertion sort) e junta.
- **Por que importa:** linear em média quando os dados são bem espalhados; usa listas (módulo 11).
- **Passo a passo:** para x em [0,1): balde = ⌊n·x⌋; insira na lista do balde; ordene cada lista;
  concatene na ordem dos baldes.
- **Exemplo:** [0,78; 0,17; 0,39; 0,26; 0,72; 0,94; 0,21; 0,12; 0,23; 0,68], 10 baldes:
  b1={0,17; 0,12}, b2={0,26; 0,21; 0,23}, b3={0,39}, b6={0,68}, b7={0,78; 0,72}, b9={0,94}.
  Ordena cada um e concatena: 0,12 0,17 0,21 0,23 0,26 0,39 0,68 0,72 0,78 0,94.
- **Pegadinhas:** com dados concentrados (tudo num balde) vira O(n²); precisa saber o intervalo.
- **Custo:** médio O(n) com distribuição uniforme; pior O(n²); espaço O(n).
- **Exercícios:**
  1. Em que balde cai 0,5 com 10 baldes? → 5.
  2. E se todos forem 0,51..0,59? → todos no balde 5; custo do insertion sort, O(n²).
  3. Como usar para idades de 0 a 120? → balde = idade / 10, 13 baldes.
- **Fonte:** CLRS cap. 8; VisuAlgo sorting (https://visualgo.net/en/sorting)

### T09 · Quickselect (seleção do k-ésimo menor)
- **O que é:** acha o k-ésimo menor elemento usando o particionamento do quicksort, mas
  descendo só para o lado onde o k está.
- **Por que importa:** mediana em O(n) médio, sem ordenar tudo; reaproveita 0100.
- **Passo a passo:** (1) particione em torno de um pivô, que vai para a posição p; (2) se p == k,
  achou; se k < p, repita à esquerda; senão, à direita.
- **Exemplo:** v = [7,2,9,4,1,8,3], k = 4 (índice 0, ou seja, o 5º menor). Pivô 3 (último,
  Lomuto) → [2,1,3,4,7,8,9], p = 2 < 4 → direita [4,7,8,9]; pivô 9 → p = 6 > 4 → [4,7,8];
  pivô 8 → p = 5 > 4 → [4,7]; pivô 7 → p = 4. Resposta: 7.
- **Pegadinhas:** índice 0 vs. "k-ésimo" a partir de 1; vetor já ordenado com pivô fixo dá
  O(n²) (use pivô aleatório); o vetor fica alterado.
- **Custo:** médio O(n) (n + n/2 + n/4...), pior O(n²); a "mediana das medianas" garante O(n).
- **Exercícios:**
  1. Qual a mediana de [5,1,4,2,3]? → 3 (k = 2 em índice 0).
  2. Por que não ordenar e pegar v[k]? → custa O(n log n); quickselect é O(n) em média.
  3. Como achar os 10 maiores de um milhão de números? → quickselect para o (n−10)-ésimo e pegar o lado direito (ou um heap de 10).
- **Fonte:** https://www.ime.usp.br/~yoshi/2006ii/mac122a/Slides/2006.10.17/lecture.pdf · CLRS cap. 9

### T10 · Enumeração: subconjuntos e permutações
- **O que é:** gerar sistematicamente todas as possibilidades (todos os subconjuntos, todas as
  ordens) com uma recursão que, a cada nível, decide uma posição.
- **Por que importa:** é a "força bruta organizada" e o esqueleto do backtracking.
- **Passo a passo (subconjuntos):** `gera(i)`: se i == n, imprime o escolhido; senão, chama
  `gera(i+1)` sem o elemento i e `gera(i+1)` com ele.
- **Passo a passo (permutações):** `perm(i)`: se i == n, imprime; senão, para cada j de i a n−1,
  troca v[i] e v[j], chama `perm(i+1)` e desfaz a troca.
- **Exemplo:** {1,2,3} → {}, {3}, {2}, {2,3}, {1}, {1,3}, {1,2}, {1,2,3} (8 = 2³).
  Permutações de 123: 123, 132, 213, 231, 321, 312 (6 = 3!).
- **Pegadinhas:** esquecer de desfazer a troca; 2ⁿ e n! explodem (20! ≈ 2,4·10¹⁸); subconjuntos
  também saem de contar de 0 a 2ⁿ−1 em binário (liga com 0070-bits).
- **Custo:** subconjuntos Θ(n·2ⁿ); permutações Θ(n·n!).
- **Exercícios:**
  1. Quantos subconjuntos de 2 elementos tem {a,b,c,d}? → 6.
  2. Qual subconjunto corresponde ao número 5 = 101₂ em {a,b,c}? → {a,c} (bits 0 e 2).
  3. Liste os anagramas de "aab" sem repetir. → aab, aba, baa.
- **Fonte:** Feofiloff, "Enumeração" (https://www.ime.usp.br/~pf/algoritmos/)

### T11 · Backtracking (N-rainhas, soma de subconjuntos)
- **O que é:** enumeração que abandona um caminho assim que ele não pode mais dar solução
  (poda), volta um passo e tenta a próxima opção.
- **Por que importa:** resolve quebra-cabeças (sudoku, labirinto, N-rainhas) que seriam
  impraticáveis por força bruta pura.
- **Passo a passo (N-rainhas):** coloque uma rainha por linha. `rainha(lin)`: se lin == n, achou
  solução; para cada coluna c, se c não é atacada (mesma coluna ou diagonal: |c−c'| == |lin−lin'|),
  marque, chame `rainha(lin+1)`, desmarque.
- **Exemplo:** n = 4. Linha 0 col 0 → linha 1 col 2 → linha 2 sem opção → volta; linha 1 col 3 →
  linha 2 col 1 → linha 3 sem opção → volta... Primeira solução (colunas por linha, a partir de 1):
  2,4,1,3. A outra: 3,1,4,2.
- **Soma de subconjuntos:** {3,34,4,12,5,2}, alvo 9: poda quando a soma passa de 9 → acha {3,4,2}
  e {4,5}.
- **Pegadinhas:** esquecer o "desmarcar" ao voltar; testar a diagonal só num sentido; poda que
  descarta soluções válidas.
- **Custo:** exponencial no pior caso; a poda muda muito a prática (8 rainhas: 92 soluções,
  achadas em milésimos).
- **Exercícios:**
  1. Quantas soluções para n = 4? E n = 8? → 2 e 92.
  2. Por que n = 2 e n = 3 não têm solução? → toda rainha da 2ª linha fica em coluna ou diagonal atacada.
  3. Labirinto em matriz 0/1: qual a poda? → não pisar em parede nem em casa já visitada.
- **Fonte:** Feofiloff (https://www.ime.usp.br/~pf/algoritmos/); UTFPR AED2

### T12 · Divisão e conquista como técnica
- **O que é:** dividir o problema em partes menores do mesmo tipo, resolver cada uma
  recursivamente e combinar as respostas.
- **Por que importa:** o curso já usa a técnica (merge, quick, busca binária) sem dar nome a ela;
  nomear permite aplicá-la em problemas novos.
- **Exemplos:**
  - **Potência rápida:** xⁿ = (x^(n/2))² se n é par, x·xⁿ⁻¹ se é ímpar. 3¹³: 13 = 1101₂ →
    3⁸·3⁴·3¹ = 6561·81·3 = 1 594 323, com cerca de 5 multiplicações em vez de 12.
  - **Contar inversões:** no merge sort, quando um elemento da metade direita sai antes, ele forma
    inversão com todos os que sobram da esquerda. [2,4,1,3,5] → 3 inversões: (2,1),(4,1),(4,3).
  - **Subvetor de soma máxima:** a melhor faixa está na esquerda, na direita ou cruza o meio.
    [−2,1,−3,4,−1,2,1,−5,4] → 6 (faixa 4,−1,2,1).
- **Pegadinhas:** subproblemas que se repetem (Fibonacci) pedem PD, não D&C; dividir em partes
  desiguais (quicksort com pivô ruim) estraga o custo.
- **Custo:** analisado por recorrência (T01/T02): potência Θ(log n), inversões Θ(n log n).
- **Exercícios:**
  1. Quantas multiplicações para x¹⁶ por potência rápida? → 4 (x², x⁴, x⁸, x¹⁶).
  2. Inversões em [5,4,3,2,1]? → 10 (n(n−1)/2).
  3. Máximo de um vetor por D&C: recorrência? → T(n) = 2T(n/2) + 1 = Θ(n).
- **Fonte:** MC458 2025; CLRS cap. 4; algs4 2.2

### T13 · Algoritmos gulosos
- **O que é:** constrói a solução tomando, a cada passo, a escolha que parece melhor agora, sem
  nunca voltar atrás.
- **Por que importa:** quando funciona, é o algoritmo mais simples e rápido; e saber quando
  **não** funciona é uma lição central de projeto.
- **Exemplo 1 (seleção de atividades):** intervalos (1,4) (3,5) (0,6) (5,7) (3,9) (5,9) (6,10)
  (8,11) (8,12) (2,14) (12,16). Ordene pelo fim e pegue o próximo que começa depois do último
  escolhido: (1,4), (5,7), (8,11), (12,16) → 4 atividades (ótimo).
- **Exemplo 2 (troco):** moedas {1,5,10,25}, troco 30: 25 + 5 (ótimo). Moedas {1,3,4}, troco 6:
  guloso dá 4+1+1 (3 moedas), mas o ótimo é 3+3 (2 moedas). Guloso falhou → PD (T16).
- **Exemplo 3 (mochila fracionária):** capacidade 50; itens (valor,peso) (60,10) (100,20)
  (120,30); razões 6, 5, 4. Pega os dois primeiros inteiros e 20/30 do terceiro: 60+100+80 = 240.
- **Pegadinhas:** guloso precisa de prova (troca ou "fica à frente"); ordenar pelo início ou pela
  duração na seleção de atividades dá resposta errada; mochila 0/1 **não** é gulosa.
- **Custo:** normalmente dominado pela ordenação, O(n log n).
- **Exercícios:**
  1. Contraexemplo para "escolher a atividade mais curta". → (1,5) (4,6) (5,10): a mais curta (4,6) bloqueia as outras duas.
  2. Mochila fracionária capacidade 10, itens (valor,peso) (10,5) (12,4) (6,6). → razões 2; 3; 1 → pega o 2º (4), o 1º (5) e 1/6 do 3º: 12+10+1 = 23.
  3. Com moedas {1,10,25} o guloso dá troco ótimo para 30? → Não: 25+1·5 (6 moedas) contra 10+10+10 (3).
- **Fonte:** MC458 2025; CLRS cap. 15

### T14 · Código de Huffman
- **O que é:** compressão sem perda que dá códigos curtos aos símbolos frequentes e longos aos
  raros, montando uma árvore binária de forma gulosa.
- **Por que importa:** junta heap (0107), árvore binária (0103), bits (0070) e arquivos binários
  (0073) num projeto real; está dentro de ZIP, PNG e JPEG.
- **Passo a passo:** (1) conte as frequências; (2) ponha uma folha por símbolo num heap de
  mínimo; (3) enquanto houver mais de um nó: tire os dois menores, crie um pai com a soma e
  devolva-o ao heap; (4) o código de cada símbolo é o caminho da raiz (esquerda 0, direita 1).
- **Exemplo:** a:5 b:9 c:12 d:13 e:16 f:45. Junta 5+9=14; 12+13=25; 14+16=30; 25+30=55;
  45+55=100. Códigos: f=0, c=100, d=101, a=1100, b=1101, e=111. Total: 224 bits contra 300
  com 3 bits fixos (25% menor).
- **Pegadinhas:** empates mudam a árvore (mas não o tamanho total); só 1 símbolo diferente gera
  código vazio; é preciso guardar a árvore ou a tabela no arquivo para descompactar.
- **Custo:** O(n log n) para n símbolos distintos.
- **Exercícios:**
  1. Por que nenhum código é prefixo de outro? → símbolos só ficam nas folhas.
  2. Frequências A:1 B:1 C:2. Códigos? → C=0, A=10, B=11 (ou equivalente); total 1·2+1·2+2·1 = 6 bits.
  3. Decodifique 1100 0 111 com a tabela do exemplo. → a f e.
- **Fonte:** CLRS cap. 15; algs4 5.5 (https://algs4.cs.princeton.edu/55compression/)

### T15 · Programação dinâmica: memoização e tabela
- **O que é:** resolver cada subproblema uma vez só, guardando a resposta, quando a recursão
  repete os mesmos subproblemas.
- **Por que importa:** transforma algoritmos exponenciais em polinomiais; responde a pergunta que
  0038 deixa aberta ("Fibonacci é caro, e daí?").
- **Passo a passo:** (1) escreva a recursão correta; (2) **de cima para baixo:** guarde cada
  resultado num vetor `memo` e consulte antes de calcular; ou (3) **de baixo para cima:** preencha
  a tabela do menor para o maior subproblema.
- **Exemplo:** fib(40) ingênuo faz 331 160 281 chamadas; com memo, 79 chamadas (cerca de 2n);
  de baixo para cima, um laço de 40 passos com duas variáveis.
- **Pegadinhas:** inicializar o memo com um valor que não seja resposta válida (−1); fib(93)
  estoura `long long`; PD só vale se o problema tem subestrutura ótima.
- **Custo:** (número de subproblemas) × (custo de cada um).
- **Exercícios:**
  1. Número de caminhos numa grade 3×3 andando só para a direita e para baixo (de canto a canto)? → C(4,2) = 6.
  2. Escadas: subir 5 degraus de 1 ou 2 em 2. Quantas formas? → 8 (é Fibonacci).
  3. Qual o espaço mínimo para fib(n) de baixo para cima? → O(1): só os dois últimos valores.
- **Fonte:** CLRS cap. 14; MC458 2025

### T16 · Troco com programação dinâmica
- **O que é:** menor número de moedas para dar um troco (ou quantas formas existem) com qualquer
  sistema de moedas, inclusive os que enganam o guloso.
- **Passo a passo (mínimo de moedas):** dp[0] = 0; para v de 1 a T,
  dp[v] = 1 + min(dp[v − m]) para cada moeda m ≤ v.
- **Exemplo:** moedas {1,3,4}, troco 6: dp = [0,1,2,1,1,2,2]. dp[6] = 2 (3+3).
- **Passo a passo (formas):** w[0] = 1; para cada moeda m, para v de m a T: w[v] += w[v − m].
  Moedas {1,2,5}, troco 5 → 4 formas: 5; 2+2+1; 2+1+1+1; 1+1+1+1+1.
- **Pegadinhas:** no "formas", trocar a ordem dos laços conta permutações (2+1 e 1+2 como
  diferentes); troco impossível precisa de um "infinito" (ex.: T+1).
- **Custo:** O(T·k) tempo, O(T) espaço, k = número de moedas.
- **Exercícios:**
  1. {1,5,6,9}, troco 11. → 2 (5+6); o guloso daria 9+1+1 (3).
  2. Formas de 4 com {1,2,3}. → 4 (3+1; 2+2; 2+1+1; 1+1+1+1).
  3. Troco 7 com {2,4}? → impossível (todo valor é par).
- **Fonte:** CLRS cap. 14 (problemas); MC458 2025

### T17 · Mochila 0/1
- **O que é:** escolher itens inteiros (pega ou não pega) para caber num peso W com o maior
  valor total.
- **Por que importa:** é o problema-modelo da PD em duas dimensões e o contraponto da mochila
  fracionária (T13).
- **Passo a passo:** t[i][c] = melhor valor usando os i primeiros itens com capacidade c.
  t[i][c] = t[i−1][c] (não pega) ou, se peso_i ≤ c, valor_i + t[i−1][c − peso_i] (pega); fica o maior.
- **Exemplo:** W = 5; itens (peso,valor): (1,1) (3,4) (4,5) (2,3). Melhor: itens 2 e 4 →
  peso 5, valor 7. Para recuperar os itens, volte na tabela vendo onde o valor mudou.
- **Pegadinhas:** com vetor 1D, percorra c de W para baixo (senão o item é usado duas vezes);
  O(nW) não é polinomial no tamanho da entrada (W pode ter muitos dígitos), por isso "pseudo-polinomial".
- **Custo:** O(n·W) tempo; O(n·W) ou O(W) espaço.
- **Exercícios:**
  1. Com W = 50 e itens (10,60) (20,100) (30,120), qual o ótimo 0/1? → 220 (itens 2 e 3).
  2. W = 4, itens (peso,valor) (2,3) (2,3) (3,5)? → 6 (os dois de peso 2).
  3. Por que o guloso por razão falha no exercício 1? → pega 60 e 100 (razões 6 e 5) e sobra 20, sem caber o 120: 160 < 220.
- **Fonte:** slides de PD de MAC0338/MAC5711 (https://www.ime.usp.br/~cris/aulas/24_2_338/slides/aula15.pdf); CLRS cap. 14

### T18 · LCS e distância de edição
- **O que é:** LCS é a maior subsequência (não precisa ser contígua) comum a duas strings;
  distância de edição é o menor número de inserções, remoções e trocas que transforma uma na outra.
- **Por que importa:** é o coração do `diff`, do corretor ortográfico e do alinhamento de DNA;
  usa matriz (0044) e strings (0046).
- **Passo a passo (LCS):** c[i][j] = 0 se i ou j é 0; c[i−1][j−1] + 1 se a[i] == b[j];
  senão max(c[i−1][j], c[i][j−1]).
- **Exemplo:** "ABCBDAB" e "BDCABA" → comprimento 4 (por exemplo "BCBA").
- **Distância de edição:** d[i][j] = d[i−1][j−1] se as letras são iguais; senão
  1 + min(d[i−1][j], d[i][j−1], d[i−1][j−1]). Bases: d[i][0] = i, d[0][j] = j.
  "kitten" → "sitting" = 3; "casa" → "massa" = 2 (troca c→m, insere s).
- **Pegadinhas:** subsequência ≠ substring; índice da tabela começa em 1 e o da string em 0;
  tabela de (m+1)×(n+1).
- **Custo:** O(m·n) tempo e espaço (O(min(m,n)) se só quiser o comprimento).
- **Exercícios:**
  1. LCS de "ABC" e "AC"? → 2 ("AC").
  2. Distância de "gato" para "rato"? → 1.
  3. Distância de "" para "abc"? → 3 (três inserções).
- **Fonte:** CLRS cap. 14; MC458 2025

### T19 · Árvores gerais (filho-esquerdo, irmão-direito)
- **O que é:** árvore em que cada nó tem qualquer número de filhos; a representação
  filho-esquerdo/irmão-direito usa só dois ponteiros: o primeiro filho e o próximo irmão.
- **Por que importa:** diretórios, organogramas, árvore DOM e árvores de jogo não são binárias.
  A representação reaproveita o nó da árvore binária (0103).
- **Passo a passo:** `struct no { int info; struct no *filho, *irmao; }`. Para percorrer os
  filhos de x: `for (p = x->filho; p; p = p->irmao)`.
- **Exemplo:** A tem filhos B, C, D; B tem filhos E, F. Fica: A.filho = B; B.irmao = C;
  C.irmao = D; B.filho = E; E.irmao = F. Pré-ordem: A B E F C D.
- **Pegadinhas:** a altura da árvore geral não é a altura da binária resultante; liberar exige
  descer pelos dois ponteiros (pós-ordem).
- **Custo:** cada nó usa 2 ponteiros, qualquer que seja o grau; achar o k-ésimo filho é O(k).
- **Exercícios:**
  1. Conte as folhas de uma árvore geral. → nó com `filho == NULL` é folha; some recursivamente por filho e irmão.
  2. Calcule o grau (número de filhos) de um nó. → conte o laço sobre `irmao` a partir de `filho`.
  3. Imprima um diretório com recuo por nível. → pré-ordem passando a profundidade como parâmetro.
- **Fonte:** CLRS cap. 10 (representação de árvores enraizadas)

### T20 · Árvore rubro-negra
- **O que é:** BST balanceada em que cada nó é vermelho ou preto e regras de cor garantem altura
  no máximo 2·log₂(n+1). Na versão de Sedgewick (LLRB), ela simula uma árvore 2-3: um nó
  vermelho "cola" no pai como se os dois formassem um só nó de 2 chaves.
- **Por que importa:** é a árvore por trás de `std::map`, `TreeMap` e do escalonador do Linux;
  aparece em MC202 e MAC0323. Comparar com a AVL (0106) é ótimo exercício.
- **Regras (LLRB):** links vermelhos só à esquerda; nenhum nó com dois links vermelhos seguidos;
  todo caminho da raiz até NULL tem o mesmo número de links pretos.
- **Passo a passo da inserção:** insere como BST com link vermelho; na volta da recursão:
  (1) vermelho só à direita → rotação à esquerda; (2) dois vermelhos seguidos à esquerda →
  rotação à direita; (3) dois filhos vermelhos → inverte as cores. A raiz sempre fica preta.
- **Exemplo:** inserir 10, 20, 30. 10 (raiz preta). 20 entra vermelho à direita → rotação à
  esquerda: 20 raiz, 10 vermelho à esquerda. 30 entra vermelho à direita de 20 → dois filhos
  vermelhos → inverte cores → 20 raiz preta, 10 e 30 pretos.
- **Pegadinhas:** esquecer de pintar a raiz de preto; aplicar as três correções na ordem errada;
  remoção é bem mais difícil (pode ficar como "para ir além").
- **Custo:** busca, inserção O(log n) no pior caso.
- **Exercícios:**
  1. Altura máxima com n = 7? → 2·log₂8 = 6.
  2. Insira 1,2,3,4,5 numa LLRB e diga a raiz. → 4, com 2 vermelho à esquerda (filhos 1 e 3) e 5 preto à direita.
  3. Diferença prática para AVL? → AVL é mais rígida (buscas um pouco mais rápidas); rubro-negra rotaciona menos na inserção/remoção.
- **Fonte:** https://www.ime.usp.br/~coelho/mac0323-2017/aulas/aula11/rabiscos11.pdf · algs4 3.3 (https://algs4.cs.princeton.edu/33balanced/)

### T21 · Árvore B
- **O que é:** árvore de busca balanceada com nós "gordos" (muitas chaves por nó), feita para
  disco: cada nó ocupa um bloco, e a altura fica minúscula.
- **Por que importa:** é como bancos de dados e sistemas de arquivos indexam dados; liga com
  0073 (fseek em arquivos binários).
- **Regras (grau mínimo t):** todo nó, menos a raiz, tem entre t−1 e 2t−1 chaves; todas as folhas
  estão na mesma profundidade; nó com k chaves tem k+1 filhos.
- **Passo a passo da inserção (divisão preventiva):** ao descer, se o filho está cheio (2t−1
  chaves), divida-o: a chave do meio sobe para o pai; insira sempre numa folha.
- **Exemplo (t = 2, árvore 2-3-4):** insere 10,20,30 → [10 20 30] (cheio). Insere 40: raiz cheia
  → 20 sobe → raiz [20], filhos [10] e [30 40]. Insere 50 → [30 40 50]. Insere 60: o filho está
  cheio → 40 sobe → raiz [20 40], filhos [10] [30] [50 60].
- **Pegadinhas:** confundir "ordem" (máx. de filhos) com "grau mínimo t"; a árvore cresce pela
  raiz, não pelas folhas; B+ (dados só nas folhas) é a variante usada na prática.
- **Custo:** altura O(log_t n); com t = 500 e um bilhão de chaves, altura 3 ou 4 (poucos acessos ao disco).
- **Exercícios:**
  1. Máximo de chaves num nó com t = 3? → 5.
  2. Altura máxima aproximada para n = 10⁶ e t = 100? → cerca de log₁₀₀ 10⁶ = 3.
  3. Por que não usar AVL em disco? → cada nó seria um acesso ao disco e a altura seria ~20 para 10⁶.
- **Fonte:** MC202 (https://ic.unicamp.br/historico-ic/graduacao/plano-desenvolvimento-disciplinas/1s2022/MC202ABC.pdf); CLRS cap. 18; ODS cap. 14

### T22 · Trie (árvore de prefixos)
- **O que é:** árvore em que cada aresta é uma letra; o caminho da raiz até um nó soletra um
  prefixo, e uma marca no nó diz se ali termina uma palavra.
- **Por que importa:** autocompletar, corretor ortográfico (o "speller" do CS50), roteamento IP;
  busca em tempo proporcional ao tamanho da palavra, não ao número de palavras.
- **Passo a passo:** `struct no { struct no *filho[26]; bool fim; }`. Inserir: para cada letra,
  desça criando o filho se faltar; no final, `fim = true`. Buscar: desça; falhou se faltar filho
  ou se `fim` for falso no último nó.
- **Exemplo:** inserir "casa", "caso", "cama", "bola". A raiz tem filhos c e b; "ca" é prefixo
  comum de 3 palavras; buscar "cas" acha o nó mas `fim` é falso → não é palavra.
- **Pegadinhas:** 26 ponteiros por nó gastam muita memória (alternativas: lista de filhos, ou
  a árvore ternária de busca); letras acentuadas e maiúsculas precisam de mapeamento; liberar
  recursivamente.
- **Custo:** inserir/buscar O(L), L = tamanho da palavra; espaço O(total de letras × alfabeto).
- **Exercícios:**
  1. Quantos nós (fora a raiz) para "casa","caso","cama"? → c,a,s,a,o,m,a = 7.
  2. Como listar todas as palavras com prefixo "ca"? → desça até o nó de "ca" e faça DFS imprimindo onde `fim` é verdadeiro.
  3. Como contar quantas palavras começam com um prefixo em O(L)? → guardar em cada nó um contador de palavras abaixo dele.
- **Fonte:** CS50 semana 5 (https://cs50.harvard.edu/x/2025/weeks/5); algs4 5.2 (https://algs4.cs.princeton.edu/52trie/)

### T23 · Union-find (conjuntos disjuntos)
- **O que é:** estrutura que mantém elementos divididos em grupos e responde rápido a duas
  operações: `find(x)` (quem é o representante do grupo de x) e `union(x,y)` (junta os grupos).
- **Por que importa:** é o motor do Kruskal, de componentes conexos dinâmicos, de percolação e de
  "amigos de amigos"; mostra como dois truques simples tornam uma estrutura quase O(1).
- **Passo a passo:** vetor `pai[]`, com `pai[i] = i` no começo. `find`: suba até a raiz e, na
  volta, ligue todos direto na raiz (compressão de caminho). `union`: ligue a raiz da árvore mais
  baixa (ou menor) na da mais alta (união por posto/tamanho).
- **Exemplo:** n = 6. union(0,1), union(2,3), union(1,3) → {0,1,2,3}; union(4,5) → {4,5}.
  find(0) == find(2)? sim. find(0) == find(5)? não. Restam 2 grupos.
- **Pegadinhas:** sem união por tamanho, a árvore pode virar lista (find O(n)); comparar `x == y`
  em vez de `find(x) == find(y)`; QuickFind (vetor de rótulos) faz union O(n).
- **Custo:** com os dois truques, O(α(n)) amortizado por operação (α ≤ 4 para qualquer n real).
- **Exercícios:**
  1. Depois de union(0,1), union(1,2), union(3,4), quantos grupos com n = 5? → 2.
  2. Como detectar ciclo num grafo não dirigido com union-find? → para cada aresta (u,v), se find(u) == find(v) há ciclo; senão union.
  3. Por que a altura fica ≤ log₂n com união por tamanho? → um elemento só desce de nível quando seu grupo pelo menos dobra.
- **Fonte:** https://www.ime.usp.br/~cris/aulas/20_2_323/slides/aula05.pdf · https://www.ime.usp.br/~cris/aulas/14_1_6711/uf.pdf · VisuAlgo (https://visualgo.net/en/ufds) · algs4 1.5

### T24 · Componentes conexos e detecção de ciclo
- **O que é:** componentes são os "pedaços" do grafo onde todo mundo alcança todo mundo; ciclo é
  um caminho que volta ao início.
- **Por que importa:** é a primeira aplicação real de BFS/DFS (0115/0116); detectar ciclo é
  pré-requisito da ordenação topológica e de dependências (make, imports).
- **Passo a passo (componentes):** para cada vértice não visitado, rode uma DFS/BFS marcando
  todos com o mesmo número de componente.
- **Passo a passo (ciclo):** não dirigido: na DFS, aresta para vértice já visitado que não é o
  pai → ciclo. Dirigido: três cores (branco = novo, cinza = na pilha da recursão, preto =
  terminado); aresta para um cinza → ciclo.
- **Exemplo:** arestas 0-1, 1-2, 3-4, vértice 5 sozinho → 3 componentes {0,1,2} {3,4} {5}.
  Dirigido 0→1→2→0: DFS em 0 (cinza), 1 (cinza), 2 (cinza), aresta 2→0 cinza → ciclo.
- **Pegadinhas:** usar "visitado" simples no dirigido dá falso ciclo (0→1, 0→2, 1→2 não tem
  ciclo); no não dirigido, a aresta de volta ao pai não conta.
- **Custo:** O(V + E) com lista de adjacência.
- **Exercícios:**
  1. Grafo não dirigido com V vértices e E arestas sem ciclo e conexo: quanto vale E? → V − 1 (é uma árvore).
  2. 0→1, 1→2, 0→2 tem ciclo? → não.
  3. Conte ilhas numa matriz de 0/1 (vizinhos em cruz). → componentes conexos com DFS na grade (flood fill).
- **Fonte:** algs4 4.1 e 4.2 (https://algs4.cs.princeton.edu/42digraph/); VisuAlgo (https://visualgo.net/en/dfsbfs)

### T25 · Ordenação topológica
- **O que é:** listar os vértices de um grafo dirigido sem ciclos (DAG) de modo que toda aresta
  u→v tenha u antes de v.
- **Por que importa:** ordem de compilação, pré-requisitos de disciplinas, planilhas; é a base de
  caminhos mínimos em DAG.
- **Passo a passo (Kahn):** (1) calcule o grau de entrada de cada vértice; (2) ponha numa fila
  (0090) os de grau 0; (3) tire da fila, imprima, diminua o grau dos vizinhos e enfileire os que
  zerarem. Se sobrarem vértices, há ciclo.
- **Alternativa (DFS):** a ordem reversa de término da DFS é uma ordem topológica.
- **Exemplo:** arestas 0→1, 0→2, 1→3, 2→3, 3→4. Graus: 0,1,1,2,1. Fila: 0 → saem 1 e 2 → 3 → 4.
  Ordem: 0 1 2 3 4 (0 2 1 3 4 também vale).
- **Pegadinhas:** a resposta não é única; grafo com ciclo não tem ordem topológica.
- **Custo:** O(V + E).
- **Exercícios:**
  1. Uma ordem para camisa→gravata, gravata→paletó, calça→cinto, cinto→paletó? → camisa, calça, gravata, cinto, paletó.
  2. Como saber pelo Kahn que há ciclo? → menos de V vértices foram impressos.
  3. Quantas ordens tem 0→1, 0→2? → 2.
- **Fonte:** CLRS cap. 20; algs4 4.2

### T26 · Árvore geradora mínima: Kruskal
- **O que é:** a árvore geradora mínima (MST) liga todos os vértices de um grafo com pesos usando
  as arestas de menor soma possível. Kruskal ordena as arestas e aceita cada uma que não forme ciclo.
- **Por que importa:** projeto de redes (cabos, estradas), agrupamento; une ordenação (13) e
  union-find (T23) num algoritmo guloso.
- **Passo a passo:** (1) ordene as arestas pelo peso; (2) para cada aresta (u,v): se
  find(u) ≠ find(v), aceite e faça union(u,v); (3) pare com V−1 arestas.
- **Exemplo:** A-B 4, A-C 1, B-C 2, B-D 5, C-D 8, C-E 10, D-E 2. Ordem: A-C 1 ✓, B-C 2 ✓,
  D-E 2 ✓, A-B 4 ✗ (ciclo), B-D 5 ✓ → 4 arestas, total 10.
- **Pegadinhas:** só vale para grafo não dirigido; grafo desconexo dá floresta; empates geram
  MSTs diferentes com o mesmo custo.
- **Custo:** O(E log E) (domina a ordenação).
- **Exercícios:**
  1. Quantas arestas tem uma MST de 10 vértices? → 9.
  2. Se todos os pesos são diferentes, a MST é única? → sim.
  3. Como obter a árvore geradora **máxima**? → ordenar em ordem decrescente (ou negar os pesos).
- **Fonte:** CLRS cap. 21; algs4 4.3 (https://algs4.cs.princeton.edu/43mst/); VisuAlgo (https://visualgo.net/en/mst)

### T27 · Árvore geradora mínima: Prim
- **O que é:** faz a MST crescer a partir de um vértice, sempre puxando a aresta mais barata que
  sai da árvore atual.
- **Por que importa:** é quase o código do Dijkstra (0117), com uma linha diferente; comparar os
  dois fixa a diferença entre "distância até a origem" e "custo da aresta".
- **Passo a passo:** (1) chave[s] = 0, demais ∞; (2) tire do heap o vértice de menor chave e
  coloque na árvore; (3) para cada vizinho v fora da árvore, se peso(u,v) < chave[v], atualize
  chave[v] = peso(u,v) e pai[v] = u.
- **Exemplo (mesmo grafo do T26, a partir de A):** A-C 1, C-B 2, B-D 5 (A-B 4 já é interna, C-D 8
  é pior), D-E 2 → total 10, igual ao Kruskal.
- **Pegadinhas:** no Dijkstra a chave é dist[u] + peso; no Prim é só o peso; esquecer de ignorar
  vértices já na árvore.
- **Custo:** O(E log V) com heap binário; O(V²) com matriz de adjacência (bom para grafos densos).
- **Exercícios:**
  1. Prim e Kruskal sempre dão o mesmo custo? → sim (o custo mínimo é único, a árvore pode variar com empates).
  2. Qual escolher para grafo completo com 1 000 vértices? → Prim com matriz, O(V²).
  3. Que linha muda para virar Dijkstra? → `chave[v] = dist[u] + peso(u,v)`.
- **Fonte:** CLRS cap. 21; algs4 4.3

### T28 · Bellman-Ford
- **O que é:** caminho mínimo de uma origem que aceita arestas de peso negativo e detecta ciclo
  negativo, relaxando todas as arestas V−1 vezes.
- **Por que importa:** mostra o limite do Dijkstra; é a base do roteamento por vetor de distâncias (RIP).
- **Passo a passo:** dist[s] = 0, demais ∞; repita V−1 vezes: para cada aresta (u,v,p), se
  dist[u] + p < dist[v], atualize. Faça mais uma rodada: se algo ainda melhorar, há ciclo negativo.
- **Exemplo:** S→A 4, S→B 5, B→A −3, A→C 2. Rodada 1 (nessa ordem): A=4, B=5, A=2, C=4. Rodada 2:
  nada muda. Resposta: A=2, B=5, C=4. O Dijkstra fecharia A com 4 antes de ver B→A e daria C=6 (errado).
- **Pegadinhas:** somar com "∞" representado por INT_MAX estoura; aresta negativa em grafo não
  dirigido já é ciclo negativo; pode parar antes se uma rodada não muda nada.
- **Custo:** O(V·E).
- **Exercícios:**
  1. Por que V−1 rodadas bastam? → um caminho mínimo simples tem no máximo V−1 arestas.
  2. A→B 1, B→A −2 tem caminho mínimo? → não: ciclo de peso −1, dá para diminuir para sempre.
  3. Quando preferir Dijkstra? → sem pesos negativos: O(E log V) é bem menor que O(VE).
- **Fonte:** CLRS cap. 22; VisuAlgo (https://visualgo.net/en/sssp); algs4 4.4

### T29 · Floyd-Warshall
- **O que é:** calcula a distância mínima entre **todos** os pares de vértices com três laços
  aninhados sobre uma matriz.
- **Por que importa:** é PD em grafos com código de 4 linhas; usa matriz (0044/0061).
- **Passo a passo:** d[i][j] = peso da aresta (∞ se não há, 0 em i == j). Para k de 0 a V−1,
  para todo i, j: d[i][j] = min(d[i][j], d[i][k] + d[k][j]). O k (vértice intermediário) é o laço de fora.
- **Exemplo:** 1→2 3, 2→3 1, 1→3 7, 3→1 2. k=1: d[3][2] = 2+3 = 5. k=2: d[1][3] = 3+1 = 4.
  k=3: d[2][1] = 1+2 = 3. Final: d12=3, d13=4, d21=3, d23=1, d31=2, d32=5.
- **Pegadinhas:** k precisa ser o laço externo; ∞ + algo estoura (teste antes de somar); d[i][i] < 0
  no fim indica ciclo negativo.
- **Custo:** O(V³) tempo, O(V²) espaço.
- **Exercícios:**
  1. Para V = 100, quantas iterações do miolo? → 10⁶.
  2. Como recuperar o caminho? → matriz `prox[i][j]` atualizada junto com d.
  3. Como saber se j é alcançável a partir de i (fecho transitivo)? → mesma estrutura com `||` e `&&` em vez de min e +.
- **Fonte:** CLRS cap. 23; algs4 4.4

### T30 · Busca de padrão: força bruta
- **O que é:** procurar uma palavra P (tamanho m) num texto T (tamanho n) testando cada posição
  inicial e comparando letra a letra.
- **Por que importa:** é o `strstr`; serve de referência para medir os algoritmos espertos.
- **Passo a passo:** para i de 0 a n−m: compare P[j] com T[i+j] para j = 0..m−1; se todos batem,
  achou em i.
- **Exemplo:** T = "abracadabra", P = "abra" → ocorrências em 0 e 7.
- **Pegadinhas:** laço até n−m (inclusive), não n; T = "aaaa...a" e P = "aaab" é o pior caso.
- **Custo:** O((n−m+1)·m) no pior caso; na prática, com texto comum, perto de O(n).
- **Exercícios:**
  1. Quantas comparações no pior caso para n = 10, m = 3? → 8 posições × 3 = 24.
  2. Quantas ocorrências de "aa" em "aaaa"? → 3 (contando sobrepostas).
  3. Implemente contando também as sobrepostas. → avance i de 1 em 1, não de m em m.
- **Fonte:** Feofiloff, "busca de palavras" (https://www.ime.usp.br/~pf/algoritmos/); algs4 5.3

### T31 · KMP (Knuth-Morris-Pratt)
- **O que é:** busca de padrão que nunca volta no texto: quando falha, usa uma tabela pré-calculada
  do padrão para saber quanto do que já casou ainda serve.
- **Por que importa:** garante O(n + m), útil em streams onde não se pode reler o texto.
- **Passo a passo:** (1) calcule π[j] = tamanho do maior prefixo próprio de P[0..j] que também é
  sufixo dele; (2) percorra T mantendo k (letras casadas); se T[i] == P[k], k++; se falhar e
  k > 0, faça k = π[k−1] e tente de novo; se k == m, achou e faça k = π[m−1].
- **Exemplo:** P = "ABABAC" → π = [0,0,1,2,3,0]. P = "AABAAA" → π = [0,1,0,1,2,2].
- **Pegadinhas:** a tabela tem várias convenções (deslocada de 1, com −1); misturar convenções é o
  erro mais comum; o "tente de novo" é um `while`, não um `if`.
- **Custo:** O(m) para π, O(n) para a busca; espaço O(m).
- **Exercícios:**
  1. π de "AAAA"? → [0,1,2,3].
  2. π de "ABCD"? → [0,0,0,0] (sem bordas: KMP vira força bruta sem voltar no texto).
  3. Por que a busca é O(n)? → k aumenta no máximo n vezes e cada recuo diminui k, então recua no máximo n vezes.
- **Fonte:** https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html · https://www.ime.usp.br/~coelho/mac0323-2018/aulas/aula25/slides.pdf

### T32 · Boyer-Moore-Horspool
- **O que é:** compara o padrão da **direita para a esquerda** e, quando falha, pula pelo valor de
  uma tabela indexada pela letra do texto que está sob a última posição do padrão.
- **Por que importa:** em texto comum é o mais rápido dos clássicos: frequentemente pula m
  letras de uma vez (sublinear). É a versão simples do Boyer-Moore usado em editores e no grep.
- **Passo a passo:** (1) tabela `salto[c] = m` para todo c; para j de 0 a m−2: `salto[P[j]] = m−1−j`;
  (2) alinhe em i = 0; compare de trás para frente; se casar tudo, achou; (3) avance
  i += salto[T[i+m−1]].
- **Exemplo:** T = "ESTE E UM TESTE", P = "TESTE" (m = 5). Saltos: T→1, E→3, S→2, demais→5.
  i=0: T[4] = ' ' ≠ 'E' → salta 5. i=5: T[9] = ' ' → salta 5. i=10: "TESTE" casa → achou em 10.
  Só 3 alinhamentos em vez de 11.
- **Pegadinhas:** a última letra do padrão não entra na tabela (senão o salto seria 0); a tabela
  precisa de 256 posições para `unsigned char`; o Boyer-Moore completo tem também a regra do bom sufixo.
- **Custo:** pior O(n·m), melhor O(n/m), média sublinear em alfabetos grandes.
- **Exercícios:**
  1. Tabela de saltos de "ABCAB"? → A→1, B→3, C→2, demais 5 (posições 0..3: A0,B1,C2,A3).
  2. Pior caso para Horspool? → T = "aaaa...a", P = "baaa": cada alinhamento compara m letras e salta 1.
  3. Por que comparar da direita? → a falha na última letra já permite pular quase m posições.
- **Fonte:** Feofiloff, livro cap. 13 (https://www.ime.usp.br/~pf/algoritmos-livro/); slides MAC0323 (link do T31)

### T33 · Rabin-Karp
- **O que é:** compara o hash do padrão com o hash de cada janela de m letras do texto; o hash da
  próxima janela sai do anterior em O(1) (hash "rolante"); só confere letra a letra quando os hashes batem.
- **Por que importa:** liga hash (15) com strings; estende-se a vários padrões ao mesmo tempo
  (detecção de plágio).
- **Passo a passo:** h(janela) = (c₀·d^(m−1) + ... + c_(m−1)) mod q. Próxima janela:
  h' = (d·(h − c_sai·d^(m−1)) + c_entra) mod q. Se h' == h(P), compare de verdade.
- **Exemplo (dígitos, d = 10, q = 13):** T = "31415926", P = "15" → h(P) = 15 mod 13 = 2.
  Janelas: 31→5, 14→1, 41→2 (**falso positivo**: confere e descarta), 15→2 (ocorrência na posição 3),
  59→7, 92→1, 26→0.
- **Pegadinhas:** `%` de número negativo em C dá negativo (some q antes); estouro de inteiro (use
  q primo e `long long`); sem a conferência final, o algoritmo "acha" falsos positivos.
- **Custo:** médio O(n + m); pior O(n·m) (muitas colisões).
- **Exercícios:**
  1. h("26") com q = 13? → 0.
  2. Calcule h de "14" a partir de h("31") = 5. → (10·(5 − 3·10) + 4) mod 13 = (−246) mod 13 = 1 (somando 13 até ficar positivo).
  3. Por que q deve ser primo e grande? → espalha melhor os valores e reduz falsos positivos.
- **Fonte:** https://www.ime.usp.br/~coelho/mac0323-2018/aulas/aula25/slides.pdf · CLRS cap. 32

### T34 · Matriz esparsa
- **O que é:** matriz com quase todos os elementos iguais a zero, guardada só com os não-zeros:
  lista de triplas (linha, coluna, valor) ou listas encadeadas cruzadas (uma por linha e uma por coluna).
- **Por que importa:** grafos grandes, planilhas e sistemas lineares são esparsos; uma matriz
  10⁵×10⁵ de double ocupa 80 GB cheia e alguns MB esparsa. Exercita listas (11) e structs (08).
- **Passo a passo (lista por linha):** vetor de n ponteiros, um por linha; cada nó tem
  (coluna, valor, prox), ordenado por coluna. `get(i,j)`: percorra a linha i; se não achar, vale 0.
  `set(i,j,0)` remove o nó.
- **Exemplo:** matriz 4×4 com a[0][2] = 5, a[1][0] = 3, a[3][3] = 7 → linha 0: (2,5); linha 1:
  (0,3); linha 3: (3,7). 3 nós em vez de 16 posições.
- **Pegadinhas:** guardar um zero (set com valor 0 deve remover); somar duas esparsas exige
  intercalar as linhas como no merge; vale a pena só se a densidade for baixa.
- **Custo:** espaço O(n + não-zeros); acesso O(não-zeros da linha).
- **Exercícios:**
  1. Some duas matrizes esparsas linha a linha. → intercalação por coluna, somando quando as colunas coincidem e descartando zeros.
  2. Transponha uma matriz em triplas. → troque linha e coluna em cada tripla e reordene.
  3. Nó com coluna, valor e ponteiro ocupa ~24 bytes contra 8 de um double. Até que densidade compensa? → abaixo de ~1/3 de não-zeros (na prática, bem menos, pelo custo de acesso).
- **Fonte:** ementas clássicas de ED (listas cruzadas); CLRS/ODS discutem representação de grafos esparsos

### T35 · Skip list
- **O que é:** lista encadeada ordenada com "andares" de atalhos: cada nó sobe para o andar de cima
  com probabilidade 1/2 (cara ou coroa), e a busca desce pelos andares como um elevador expresso.
- **Por que importa:** dá O(log n) esperado como uma árvore balanceada, mas com código de lista
  (sem rotações); usada no Redis e no LevelDB; liga com rand (0031).
- **Passo a passo (busca de x):** comece no andar mais alto da cabeça; avance enquanto o próximo
  for < x; quando não der, desça um andar; no andar 0, o próximo é x ou x não existe.
  **Inserção:** busque guardando o último nó visitado em cada andar, sorteie a altura e ligue o
  novo nó em cada andar.
- **Exemplo:** andar 0: 3 6 7 9 12 17 19 25; andar 1: 6 9 17 25; andar 2: 9 25. Buscar 19: andar 2:
  9 (25 > 19, desce); andar 1: 17 (25 > 19, desce); andar 0: 19 → achou em 4 passos.
- **Pegadinhas:** altura máxima precisa de limite (ex.: 16 ou 32); a garantia é esperada, não de
  pior caso; esquecer de atualizar os ponteiros de todos os andares na remoção.
- **Custo:** busca, inserção e remoção O(log n) esperado; espaço O(n) esperado (em média 2 ponteiros por nó).
- **Exercícios:**
  1. Com probabilidade 1/2, quantos de 1 024 nós chegam ao andar 3, em média? → 128.
  2. Qual a altura esperada para n = 10⁶? → cerca de log₂10⁶ ≈ 20.
  3. Por que não promover "um nó sim, um não" de forma fixa? → inserir e remover quebraria o padrão e exigiria reconstruir tudo.
- **Fonte:** ODS cap. 4 (https://opendatastructures.org/); Sedgewick cap. 13

### T36 · Listas autoajustáveis
- **O que é:** listas de busca sequencial que se reorganizam a cada acesso para aproximar dos
  itens mais procurados: mover para a frente (MTF), transpor (troca com o anterior) ou contar
  acessos e manter ordenado pela contagem.
- **Por que importa:** com acessos desiguais (poucos itens muito usados), a busca sequencial
  (0094) fica muito mais rápida; é a ideia por trás de caches e do algoritmo MTF da compressão bzip2.
- **Passo a passo (MTF):** busque; ao achar, remova o nó do lugar e insira-o no início.
  **Transposição:** ao achar, troque com o anterior.
- **Exemplo:** lista [A,B,C,D], acessos D, D, C.
  MTF: [D,A,B,C] → [D,A,B,C] → [C,D,A,B]. Transposição: [A,B,D,C] → [A,D,B,C] → [A,D,C,B].
- **Pegadinhas:** MTF reage rápido mas um acesso raro joga um item ruim para a frente;
  transposição é estável mas lenta para aprender; em vetor, MTF custa deslocar (melhor em lista encadeada).
- **Custo:** cada acesso continua O(n) no pior caso; MTF custa no máximo 2× o da melhor ordem
  fixa (análise amortizada de Sleator e Tarjan).
- **Exercícios:**
  1. Lista [A,B,C], acessos C, B, C com MTF. Estado final? → [C,B,A] (C,A,B → B,C,A → C,B,A).
  2. Mesmos acessos com transposição. → C: [A,C,B]; B: [A,B,C]; C: [A,C,B]. Final [A,C,B].
  3. Que padrão de acesso faz MTF sair pior que a lista fixa? → acessos cíclicos A,B,C,D,A,B,C,D: sempre o último da lista.
- **Fonte:** Sedgewick, *Algorithms in C* (busca sequencial, heurísticas de autoorganização);
  CLRS problema 17-5 (MTF, competitividade)

---

## 4. Proposta de novos módulos

Princípios: (1) não repetir nada de 00 a 16; (2) cada técnica entra depois dos pré-requisitos
(recorrências antes de D&C; union-find antes de Kruskal; heap antes de Huffman e Prim; hash antes
de Rabin-Karp; PD antes de Bellman-Ford/Floyd); (3) 4 a 8 assuntos por módulo, sempre fechando
com um "juntando-tudo"; (4) numeração continua de 0119 em diante (A e E seguem a regra 2N−1, 2N).

## 17-analise-avancada · Medindo algoritmos recursivos
- 0119-recorrencias · recorrência a partir do código e árvore de recursão
- 0120-teorema-mestre · os três casos e quando não se aplica
- 0121-amortizada · vetor que dobra, contador binário, pilha com multipop
- 0122-limite-inferior · árvore de decisão e o Ω(n log n) da ordenação por comparação
- 0123-juntando-tudo · medir e prever o tempo de quatro ordenações reais

## 18-ordenacao-linear · Ordenação além da comparação e seleção
- 0124-shell-sort · insertion sort com saltos (Knuth 3h+1)
- 0125-counting-sort · contagem, somas acumuladas e estabilidade
- 0126-radix-sort · dígito a dígito (LSD) com base 10 e base 256
- 0127-bucket-sort · baldes com listas encadeadas
- 0128-quickselect · k-ésimo menor e mediana pelo particionamento
- 0129-juntando-tudo · ordenar 1 milhão de registros e comparar com qsort

## 19-backtracking · Enumeração e backtracking
- 0130-subconjuntos · enumeração recursiva e por bits
- 0131-permutacoes · troca, recursão e desfazer
- 0132-backtracking · poda; soma de subconjuntos
- 0133-n-rainhas · N-rainhas com vetores de colunas e diagonais
- 0134-labirinto · caminho em matriz e flood fill
- 0135-juntando-tudo · resolvedor de sudoku

## 20-dc-e-gulosos · Divisão e conquista e algoritmos gulosos
- 0136-divisao-e-conquista · a técnica; potência rápida
- 0137-inversoes-e-subvetor · contar inversões e subvetor de soma máxima
- 0138-gulosos · a ideia, troco canônico e o contraexemplo {1,3,4}
- 0139-intervalos · seleção de atividades
- 0140-mochila-fracionaria · ordenar por valor/peso
- 0141-huffman · árvore de Huffman com heap
- 0142-juntando-tudo · compactador/descompactador Huffman de arquivos

## 21-programacao-dinamica · Programação dinâmica
- 0143-memoizacao · Fibonacci memoizado e de baixo para cima; escadas e grade
- 0144-troco-pd · mínimo de moedas e número de formas
- 0145-mochila-01 · tabela n×W e recuperação dos itens
- 0146-lcs · maior subsequência comum
- 0147-distancia-de-edicao · Levenshtein
- 0148-juntando-tudo · mini-diff entre dois arquivos de texto

## 22-arvores-avancadas · Árvores e conjuntos avançados
- 0149-arvores-gerais · filho-esquerdo/irmão-direito
- 0150-rubro-negra · rubro-negra esquerdista (LLRB): inserção
- 0151-arvore-b · árvore B: busca, divisão e inserção
- 0152-trie · árvore de prefixos e autocompletar
- 0153-union-find · conjuntos disjuntos com compressão e união por tamanho
- 0154-juntando-tudo · corretor ortográfico com trie (e comparação com hash e BST)

## 23-grafos-avancados · Grafos: estrutura e caminhos
- 0155-componentes-e-ciclos · componentes conexos e detecção de ciclo (3 cores)
- 0156-ordenacao-topologica · Kahn e DFS
- 0157-kruskal · MST com ordenação e union-find
- 0158-prim · MST com heap; comparação com Dijkstra
- 0159-bellman-ford · pesos negativos e ciclo negativo
- 0160-floyd-warshall · todos os pares
- 0161-juntando-tudo · planejador de rotas e de pré-requisitos

## 24-busca-de-padroes · Busca de padrões em texto
- 0162-forca-bruta · busca ingênua e strstr
- 0163-kmp · tabela de bordas (π) e busca linear
- 0164-horspool · Boyer-Moore-Horspool e tabela de saltos
- 0165-rabin-karp · hash rolante e falsos positivos
- 0166-juntando-tudo · mini-grep com os quatro algoritmos e cronômetro

## 25-estruturas-extras · Estruturas especiais
- 0167-matriz-esparsa · triplas e listas por linha
- 0168-skip-list · lista com andares aleatórios
- 0169-listas-autoajustaveis · mover para a frente, transposição, contagem
- 0170-juntando-tudo · comparar BST, AVL, skip list e lista autoajustável no mesmo teste

**Resumo:** 9 módulos novos (17 a 25), 52 assuntos (0119 a 0170), que cobrem os 36 temas
levantados. Deque (0092) e heap (0107) já existem e são reaproveitados em 0156 (fila no Kahn),
0141 e 0158 (heap no Huffman e no Prim).
