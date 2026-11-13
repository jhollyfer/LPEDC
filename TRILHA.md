# Trilha de estudo para a prova do PPGI

A prova cobra um recorte dos 29 módulos. A trilha põe esse recorte em **ordem de dependência**:
cada bloco usa o que o anterior ensinou. O [plano dia a dia](PPGI.md#comece-aqui) ordena pelo
**peso** na prova; a trilha diz **o que vem antes de quê**. O mapa do edital está em
[`PPGI.md`](PPGI.md#tópico-por-tópico).

Versão interativa, com os 189 assuntos como degraus: [jhollyfer.github.io/LPEDC/#trilha](https://jhollyfer.github.io/LPEDC/#trilha).

## 1. Conceitos gerais

Cada bloco tem três itens:

- **Antes:** o que o bloco supõe. Se travar, volte a ele.
- **Estude:** os assuntos, na ordem em que se apoiam (o número leva ao módulo).
- **De cabeça:** o que a prova cobra sem consulta.

### Bloco 1 · A base de C que as questões usam

**Antes:** nada.

**Estude:** tipos, operadores e precedência (0003, 0007, 0009, 0170), laços (0020-0022), funções e
recursão (0028-0034), vetores e matrizes (0037-0039), ponteiros (0044-0049), `malloc` e `free`
(0053-0056), `struct`, `union` e `enum` (0059-0065), arquivos (0067-0068), com e sem sinal (0171) e
VLA (0172).

**De cabeça:**

- `&` pega o endereço e `*` acessa o que está nele; `v[i]` é `*(v + i)`.
- Ponteiro para ponteiro (`**prim`) é o que permite a função mudar o início de uma lista.
- O que `malloc` devolve vive no heap até o `free`; variável local morre com a função.
- Divisão de inteiros trunca; `&&` e `||` param na primeira resposta (curto-circuito).

### Bloco 2 · Custo: a régua de todos os outros blocos

**Antes:** bloco 1, principalmente laços e recursão.

**Estude:** contar passos (0071), notação O (0072), O, Ω e Θ (0166), somatórios (0167),
complexidade espacial (0168) e recorrências (0114, 0115).

**De cabeça:**

- Ordem de crescimento: 1 < log n < n < n log n < n² < n³ < 2ⁿ < n!.
- Laço dentro de laço, cada um até n, dá n²; laço que divide o problema ao meio dá log n.
- Teorema mestre para `T(n) = a·T(n/b) + f(n)`: compare `f(n)` com `n^(log_b a)`.
- Pior caso, melhor caso e caso médio são análises diferentes do mesmo algoritmo.

### Bloco 3 · Estruturas lineares

**Antes:** blocos 1 e 2. A lista encadeada é ponteiro e `malloc`; o custo de cada operação é a
régua do bloco 2.

**Estude, nesta ordem:**

1. Vetor dinâmico (0075), que mostra o custo de inserir no meio.
2. Lista encadeada, com busca e remoção (0076, 0077), ordenada (0078), dupla (0079), circular
   (0080) e com sentinela (0174).
3. Pilha (0082, 0083, 0084), que é a lista com acesso só por um lado.
4. Fila e fila circular (0085, 0086), deque (0087).

**De cabeça:**

| Estrutura | Inserir | Remover | Buscar |
| --- | --- | --- | --- |
| vetor não ordenado | O(1) no fim | O(n) | O(n) |
| vetor ordenado | O(n) | O(n) | O(log n) |
| lista encadeada | O(1) no início | O(1) se já tem o nó anterior | O(n) |
| pilha e fila | O(1) | O(1) | não se usa |

- Pilha é LIFO; fila é FIFO. Uma fila feita com duas pilhas e o contrário são questões recorrentes.
- Na fila circular, `(i + 1) % n` dá a próxima posição; cheia e vazia se distinguem por um contador
  ou por uma posição sempre livre.
- Na lista dupla, a inserção atualiza quatro ponteiros: confira a ordem.

### Bloco 4 · Busca e ordenação

**Antes:** bloco 2 (custo) e bloco 3 (vetor).

**Estude:** busca sequencial e binária (0089, 0090); bubble, selection e insertion (0091-0093);
merge e quick (0094, 0095); estabilidade e espaço (0096); counting, radix e bucket (0119-0121);
chave composta e pigeonhole (0180). O heapsort (0103) fica para o bloco 5, porque usa o heap.

**De cabeça:**

| Algoritmo | Pior caso | Estável | Espaço extra |
| --- | --- | --- | --- |
| bubble (com parada antecipada) | O(n²) | sim | O(1) |
| selection | O(n²) | não | O(1) |
| insertion (melhor caso O(n)) | O(n²) | sim | O(1) |
| merge | O(n log n) | sim | O(n) |
| quick | O(n²), média O(n log n) | não | O(log n) de pilha |
| counting | O(n + k) | sim | O(n + k) |

- Busca binária exige vetor ordenado e faz no máximo ⌊log₂ n⌋ + 1 comparações.
- Hoare e Lomuto particionam de formas diferentes: a mesma entrada dá vetores diferentes.
- Radix sort só funciona porque o ordenador de cada dígito é estável.

### Bloco 5 · Árvores

**Antes:** bloco 3 (ponteiros e recursão) e bloco 4 (a busca binária, que a ABB reproduz em
ponteiros).

**Estude, nesta ordem, porque cada uma conserta o defeito da anterior:**

1. Vocabulário e percursos (0097, 0098; altura em arestas, folha tem altura 0).
2. ABB: busca, inserção, remoção (0099, 0100). O defeito: chaves em ordem formam uma lista.
3. AVL e suas rotações (0101); remoção (0176). Conserta a ABB mantendo a altura em O(log n).
4. Heap, fila de prioridade e heapsort (0102, 0103).
5. Rubro-negra (0145, 0177) e árvore B (0146): outras formas de manter o equilíbrio.
6. Nível, grau, fator de balanceamento, sucessor e antecessor (0175).

**De cabeça:**

- Percurso em ordem numa ABB devolve as chaves ordenadas.
- AVL: fator de balanceamento em {-1, 0, 1}. Fator +2 com filho em +1 pede rotação simples; com
  filho em -1 pede rotação dupla. O caso simétrico espelha tudo.
- Menor número de nós de uma AVL de altura h: `N(h) = N(h-1) + N(h-2) + 1`.
- Árvore binária de altura h tem no máximo `2^(h+1) - 1` nós.
- Heap em vetor (base 0): filhos de `i` em `2i+1` e `2i+2`, pai em `(i-1)/2`. Construir é O(n);
  inserir e extrair são O(log n).
- Sequência de busca que "cruza" um limite já descartado não pode ser de uma ABB.

### Bloco 6 · Tabelas hash

**Antes:** bloco 3 (a lista do encadeamento) e bloco 2 (custo esperado).

**Estude:** função hash e divisão (0105); encadeamento (0106); endereçamento aberto com sondagem
linear (0107); multiplicação (0178); sondagem quadrática e dispersão dupla (0179).

**De cabeça:**

- Fator de carga `α = n / m`. No encadeamento, a busca custa em média O(1 + α); no pior caso, O(n).
- Endereçamento aberto exige `α < 1`. Remover sem marcar a casa como "removida" quebra a busca.
- Sondagem linear forma agrupamentos primários; a quadrática reduz o problema, mas não o elimina.
- Na divisão, `m` primo longe de potência de 2 espalha melhor.

### Bloco 7 · Grafos

**Antes:** bloco 3 (fila e pilha: a BFS usa fila, a DFS usa pilha ou recursão) e bloco 5 (heap, para
o Dijkstra).

**Estude, nesta ordem:** representação (0109); BFS e DFS (0110, 0111); Dijkstra (0112);
conectividade (0150); ordenação topológica (0151); árvore geradora mínima, Kruskal e Prim
(0152, 0153); Bellman-Ford e Floyd-Warshall (0154, 0155); grau, caminho, ciclo, euleriano e
hamiltoniano (0182, 0183); pontes e articulações (0184).

**De cabeça:**

| Operação | Matriz de adjacências | Lista de adjacências |
| --- | --- | --- |
| espaço | O(V²) | O(V + E) |
| existe a aresta (u, v)? | O(1) | O(grau de u) |
| percorrer vizinhos de u | O(V) | O(grau de u) |

| Algoritmo | Custo | Cuidado |
| --- | --- | --- |
| BFS e DFS | O(V + E) com lista | BFS dá caminho mínimo em número de arestas |
| Dijkstra | O((V + E) log V) com heap | não aceita peso negativo |
| Bellman-Ford | O(V·E) | aceita peso negativo e detecta ciclo negativo |
| Floyd-Warshall | O(V³) | todos os pares |
| Kruskal e Prim | O(E log V) | árvore geradora mínima de grafo não dirigido |

- Grafo conexo e não dirigido tem circuito euleriano se, e só se, todo vértice tem grau par.
- Achar caminho hamiltoniano é NP-completo; o euleriano é fácil. A diferença cai em prova.

### Bloco 8 · Técnicas de projeto e NP (o que o cursinho acrescenta)

**Antes:** blocos 2 e 7. Recorrência e grafos aparecem em tudo daqui.

**Estude:** divisão e conquista (0131, 0132); método guloso (0133-0136); programação dinâmica,
mochila e LCS (0138-0142); cadeia de matrizes (0185); P, NP e reduções (0186, 0187);
aproximação e caixeiro viajante (0188).

**De cabeça:**

- Guloso só vale quando a escolha local é provadamente ótima; programação dinâmica guarda
  subproblemas repetidos; divisão e conquista divide em subproblemas independentes.
- P ⊆ NP. NP-completo é o que está em NP e é tão difícil quanto qualquer problema de NP.
- Reduzir A a B mostra que B é pelo menos tão difícil quanto A.

## 2. Exemplos de uso

Como a trilha resolve uma dúvida, na prática:

- **Errou uma questão de AVL.** A AVL está no bloco 5, que pede os blocos 3 e 4. Se a rotação
  confunde, o problema costuma ser ponteiro (bloco 1) ou a ABB (0099). Refaça nessa ordem.
- **Errou o custo de buscar num vetor ordenado.** É o bloco 2 (custo) aplicado ao bloco 4 (busca
  binária, 0090). Revise a tabela "De cabeça" dos dois.
- **Tem só dois dias.** Fique nos blocos 3, 4, 5 e 6, que somam mais de 80% das questões.

## 3. Exercícios práticos

Marque cada bloco quando fechar o treino dele (questões dos módulos e provas em [`PROVAS.md`](PROVAS.md)):

- [ ] **Bloco 1 · A base de C que as questões usam**: `[!WARNING]` de cada assunto e a prova 061/2018.
- [ ] **Bloco 2 · Custo: a régua de todos os outros blocos**: questões do módulo 10; as questões de cálculo de 2022 e 2023.
- [ ] **Bloco 3 · Estruturas lineares**: questões dos módulos 11 e 12; provas 053/2016 e 024/2017.
- [ ] **Bloco 4 · Busca e ordenação**: questões dos módulos 13 e 18; provas 055/2017 e 032/2016.
- [ ] **Bloco 5 · Árvores**: questões dos módulos 14, 22 e 28; provas 032/2016 e 057/2022. Árvores somam um terço das questões: refaça cada inserção no papel.
- [ ] **Bloco 6 · Tabelas hash**: questões do módulo 15; prova 023/2018.
- [ ] **Bloco 7 · Grafos**: questões dos módulos 16, 23 e 29; as questões de grafo de 2022 e 2023.
- [ ] **Bloco 8 · Técnicas de projeto e NP (o que o cursinho acrescenta)**: questões dos módulos 20, 21 e 29. Como esse bloco está no cursinho e fora do edital, só entre nele depois dos blocos 1 a 7.

### Fechamento

1. Refaça os `[!WARNING]` dos assuntos que mais caem: 0090, 0095, 0099, 0101, 0102 e 0106.
2. Rode os três simulados de [`SIMULADOS.md`](SIMULADOS.md), cronometrando 3 minutos por questão.
3. Para cada erro, volte ao bloco que ensina o assunto, não só ao assunto.
4. Resolva as provas antigas em [`PROVAS.md`](PROVAS.md), das mais antigas às mais recentes, e
   releia o [formato de cada questão](PPGI.md#o-que-caiu-de-2016-a-2023).

Se faltar tempo, mantenha os blocos 3, 4, 5 e 6, que juntos somam mais de 80% das questões, e
corte o treino antes de cortar o assunto.
