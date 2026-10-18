# Módulo 16 · Grafos

Lista, pilha, fila, árvore, hash: até aqui toda estrutura tinha uma forma
bem comportada. Cada nó tinha um próximo, ou um pai, ou um balde. O mundo
real não é tão educado. Ruas se cruzam e fecham voltas, pessoas se seguem sem
reciprocidade, pacotes dependem uns dos outros. Para tudo isso existe o
**grafo**: pontos e ligações, sem regra de forma.

Grafo é a estrutura que mais aparece fora da sala de aula. O GPS que acha a
rota, a rede social que sugere amigos, o `npm` que descobre a ordem de
instalar dependências e reclama de import circular, o roteador que escolhe
por onde mandar o pacote: todos rodam alguma variação dos algoritmos deste
módulo.

A mudança na cabeça é parar de perguntar "qual é o próximo?" e começar a
perguntar "quem são os vizinhos, e em que ordem eu visito?". Quase tudo aqui
é a mesma ideia de **busca**, com uma estrutura auxiliar diferente: a pilha
da recursão (DFS), a fila (BFS) ou o "menor primeiro" (Dijkstra). Este módulo
fecha o curso juntando o que veio antes: matrizes, `malloc`, listas, filas,
pilhas, recursão, structs e heap.

## O que você vai aprender

- o vocabulário de **grafos**: vértice, aresta, grau, caminho, ciclo, grafo dirigido e ponderado
- as duas representações: **matriz de adjacência** e **lista de adjacência**, e quando usar cada uma
- a **busca em largura** (BFS) com fila, e o menor caminho em número de arestas
- a **busca em profundidade** (DFS) com recursão ou pilha: componentes, ciclos e ordenação topológica
- o algoritmo de **Dijkstra** para o caminho mínimo com pesos, e a armadilha do INFINITO que estoura
- escolher o algoritmo certo para cada pergunta, e um bônus: a **árvore geradora mínima** com Prim

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com o
   grafo e a ordem da visita marcada.
2. Leia o código. É o mesmo exemplo, com os mesmos vértices e pesos.
3. Siga o **fluxograma** com o dedo e faça o **teste de mesa** da fila, da
   pilha ou do vetor de distâncias. Em grafos, o teste de mesa é metade do
   aprendizado.
4. Rode os exemplos. Apague uma aresta, mude um peso, troque a origem, rode
   de novo e veja a ordem mudar.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas ficam escondidas: abra só se travar.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa. Nos grafos, a origem da busca fica roxa, o destino verde, e as arestas
verdes são as que a busca usou (a árvore da busca ou a rota final).

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você vai usar sem cerimônia: matrizes (0044), structs e `typedef` (0064 e
0065), `malloc` e `free` (0059), lista encadeada (0081), pilha (0087), fila
(0090), recursão (0037) e, no último assunto, heap (0107). Se algum desses
estiver enferrujado, dê uma revisada antes.

Os vértices são sempre números de 0 a V-1, e o nome de cada um fica num
vetor de strings à parte. Nos exemplos, os vizinhos são examinados em ordem
crescente de índice. Isso decide empates e a ordem da visita: se você mudar a
numeração, a saída muda, e não está errada.

O assunto 0114 traz o TAD `grafo.h` + `grafo.c` com lista de adjacência; o
`rodar` compila o `grafo.c` junto com os arquivos daquela pasta. Nos outros
assuntos, cada arquivo traz tudo dentro dele, com matriz de adjacência, para
o algoritmo ficar inteiro na tela.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel ou num arquivo seu. Misturam os assuntos do
módulo.

**1. Contando arestas.** Um grafo não dirigido tem 10 vértices, todos de grau
3. Quantas arestas ele tem? Existe um grafo não dirigido com 7 vértices, todos
de grau 3?

<details><summary>Resposta</summary>

A soma dos graus é o dobro das arestas: 10 × 3 = 30, então **15 arestas**.
Com 7 vértices de grau 3 a soma seria 21, ímpar: **não existe**. Todo grafo
tem um número par de vértices de grau ímpar.

</details>

**2. Matriz ou lista?** Um mapa tem 10 mil esquinas e 30 mil ruas de mão
dupla. Quanta memória gasta a matriz de `int`? E a lista de adjacência com
nós de 16 bytes?

<details><summary>Resposta</summary>

Matriz: 10⁴ × 10⁴ × 4 bytes = **400 MB**, quase tudo zero. Lista: cada rua
vira 2 nós, 60 mil × 16 bytes = 960 KB, mais 80 KB do vetor de ponteiros:
**cerca de 1 MB**. Para grafos esparsos, a lista ganha de longe.

</details>

**3. Qual algoritmo?** Para cada pergunta, diga se você usaria BFS, DFS ou
Dijkstra: (a) o menor número de cliques para ir de uma página da Wikipédia a
outra; (b) se existe import circular num projeto; (c) o voo mais barato entre
duas cidades; (d) quantas ilhas há num mapa; (e) a ordem para cursar
disciplinas com pré-requisitos.

<details><summary>Resposta</summary>

(a) **BFS** (todo clique custa 1); (b) **DFS** com três cores; (c)
**Dijkstra** (preços são pesos, todos positivos); (d) **BFS ou DFS**, tanto
faz: é contar componentes; (e) **DFS** (pós-ordem invertida) ou o algoritmo
de Kahn, com fila.

</details>

**4. A mudança, com fila.** Tarefas: 0 alugar caminhão, 1 encaixotar, 2
desmontar móveis, 3 carregar, 4 descarregar, 5 montar móveis, 6 ligar a
internet nova. Precedências: 0, 1 e 2 antes de 3; 3 antes de 4; 4 antes de 5.
Escreva a ordenação topológica de **Kahn**: conte quantas setas chegam em
cada tarefa, ponha numa fila as que têm zero, e a cada tarefa tirada
desconte 1 das sucessoras. Em que ordem sai, examinando em ordem de índice?
Quantas "rodadas" de tarefas em paralelo são necessárias?

<details><summary>Resposta</summary>

Ordem: **alugar, encaixotar, desmontar, internet, carregar, descarregar,
montar** (0, 1, 2, 6, 3, 4, 5). Rodadas: {0, 1, 2, 6}, {3}, {4}, {5}: **4
rodadas**. Se no fim sobrar tarefa que nunca chegou a zero, o grafo tem
ciclo e não existe ordem possível.

</details>

**5. Dijkstra à mão.** Grafo dirigido: S→A 3, S→B 7, A→B 2, A→C 6, B→C 1,
C→T 2, B→T 8. Qual a distância de S a cada vértice e qual o caminho até T?

<details><summary>Resposta</summary>

Fixa S (0), A (3), B (5, via A, melhor que 7), C (6, via B), T (8, via C;
por B direto daria 13). Caminho: **S → A → B → C → T, custo 8**.

</details>

**6. Quantos caminhos mínimos?** Grafo não dirigido: A-B, A-C, B-D, C-D,
D-E, D-F, E-G, F-G. Quantos caminhos diferentes, todos com o menor número de
arestas, ligam A a G? Como adaptar a BFS para contar?

<details><summary>Resposta</summary>

**4 caminhos** de 4 arestas: A-B-D-E-G, A-B-D-F-G, A-C-D-E-G, A-C-D-F-G.
Na BFS, guarde `cont[origem] = 1` e, ao examinar a aresta u-v: se v é novo,
`cont[v] = cont[u]`; se `dist[v] == dist[u] + 1`, `cont[v] += cont[u]`.

</details>

**7. Estrada crítica.** No mapa da transportadora do A235 (sem a Ilha), existe
alguma estrada que, se cair, deixa algum lugar sem acesso ao CD? Como
descobrir com o que você já sabe?

<details><summary>Resposta</summary>

**Nenhuma.** Toda estrada está em algum ciclo (CD-Centro-Feira,
Centro-Porto-Morro-Feira, Centro-Porto-Vila). Método simples: para cada
aresta, apague, rode uma DFS do CD e veja se todos foram visitados; depois
recoloque. Custa O(E · (V + E)). Essas arestas se chamam **pontes**, e existe
um algoritmo com uma DFS só (Tarjan) para achar todas.

</details>

**8. Kruskal contra Prim.** Refaça a fibra óptica do A236 com o algoritmo de
**Kruskal**: ordene todos os trechos do mais barato ao mais caro e aceite cada
um que não feche ciclo. Em que ordem os trechos entram? O total muda?

<details><summary>Resposta</summary>

Entram Caicó–Currais Novos (9), Mossoró–Pau dos Ferros (16), Natal–Currais
Novos (18) e Mossoró–Caicó (20); os seguintes fechariam ciclo. Total **R$ 63
mil**, o mesmo do Prim (a árvore é a mesma, só a ordem muda). Para saber se
fecha ciclo, guarde em `grupo[v]` o "chefe" de cada vértice e só aceite a
aresta se os chefes forem diferentes (a ideia do union-find).

</details>

**9. Todas as distâncias.** Rodar Dijkstra a partir de cada vértice dá a
tabela de todas as distâncias. Existe um jeito com três laços aninhados,
o **Floyd-Warshall**: `para k, para i, para j: d[i][j] = min(d[i][j],
d[i][k] + d[k][j])`. Qual o custo? Qual cuidado com o INFINITO?

<details><summary>Resposta</summary>

**O(V³)**: igual a V execuções do Dijkstra com matriz, mas com código bem
menor. O cuidado é o mesmo do assunto 0117: `d[i][k] + d[k][j]` estoura se um
dos dois for `INT_MAX`. Teste antes de somar, ou use um INFINITO folgado,
como `1000000000`, que somado duas vezes ainda cabe em `int`.

</details>

**10. Labirinto com lama.** No galpão do A230, algumas casas têm lama: entrar
nelas custa 5 passos em vez de 1. A BFS ainda acha o caminho mais rápido? O
que você usaria?

<details><summary>Resposta</summary>

**Não**: a BFS conta casas, não custo. Use **Dijkstra** na grade: cada casa é
um vértice, e o peso da aresta é o custo de entrar na casa de destino. Os
vizinhos continuam saindo da conta das 4 direções; só a fila vira "o menor
`dist` primeiro".

</details>

## Para ler mais

- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 8: grafos e suas aplicações.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 5: filas e distâncias em uma rede.
- FEOFILOFF, P. *Algoritmos para grafos*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos_para_grafos/>.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Tipos abstratos de dados, pilhas e filas.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Parte VI: algoritmos de grafos.
- DIJKSTRA, E. W. A note on two problems in connexion with graphs. *Numerische Mathematik*, v. 1, p. 269-271, 1959.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989.
- CPPREFERENCE. *Numeric limits* (`INT_MAX`) e *Arithmetic operators* (estouro de inteiro com sinal). Disponível em: <https://en.cppreference.com/w/c/types/limits>.
