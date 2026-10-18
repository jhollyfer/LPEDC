## 0115 · BFS: busca em largura

Você quer uma indicação para a vaga que a Rita, recrutadora, está anunciando
no LinkedIn. Você não conhece a Rita. Conhece o Max e a Nina; eles conhecem
outras pessoas, que conhecem outras. Qual é a corrente mais curta de
apresentações até ela?

Quem já reparou no "conexão de 2º grau" do LinkedIn viu essa ideia (nada a
ver com o grau do vértice do assunto anterior: ali é a **distância**). A rede é
um grafo não dirigido: pessoas são vértices, conexões são arestas. A pergunta é
o **menor caminho em número de arestas** de Lia (você) até Rita.

A **busca em largura** (BFS, de *breadth-first search*) responde isso
explorando o grafo em ondas, como uma pedra jogada no lago:

- onda 0: a origem, Lia;
- onda 1: todo mundo a uma aresta de Lia (Max e Nina);
- onda 2: os vizinhos deles que ninguém viu ainda (Otto e Pedro);
- onda 3: Rita.

Para visitar na ordem das ondas, a BFS usa uma **fila** (assunto 0090): quem
foi descoberto primeiro é processado primeiro. O laço é sempre o mesmo: tira
`u` da frente da fila e, para cada vizinho `v` ainda não descoberto, anota
`dist[v] = dist[u] + 1`, guarda `pai[v] = u` e põe `v` no fim da fila.

O vetor `dist[]` faz dois papéis. Guarda a distância e, com `-1`, diz "ainda
não descoberto". É ele que impede a busca de andar em círculos: num grafo, ao
contrário da árvore, dá para chegar no mesmo vértice por caminhos diferentes
(Otto é vizinho de Max **e** de Nina).

O vetor `pai[]` guarda quem descobriu cada vértice. Os pares (pai, filho)
formam a **árvore da BFS**, e seguir `pai[]` a partir de Rita até chegar em
`-1` dá o caminho mais curto, de trás para frente.

Vamos ver na prática. As setas verdes são as arestas da árvore da BFS (cada
uma liga um vértice a quem o descobriu); o número em cima de cada pessoa é a
distância; embaixo, a fila na ordem em que cada um entrou:

{{ideia}}

O código monta a matriz, roda a BFS a partir de Lia e reconstrói o caminho:

```c
#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Lia", "Max", "Nina", "Otto", "Pedro", "Rita"};
    int adj[V][V] = {0};
    int conexoes[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 7; k++) {
        adj[conexoes[k][0]][conexoes[k][1]] = 1;
        adj[conexoes[k][1]][conexoes[k][0]] = 1;
    }

    int dist[V], pai[V];
    for (int v = 0; v < V; v++) {
        dist[v] = -1; // -1: ainda não descoberto
        pai[v] = -1;
    }

    int fila[V]; // cada vértice entra uma vez só: V posições bastam
    int inicio = 0, fim = 0;
    int origem = 0; // Lia
    dist[origem] = 0;
    fila[fim++] = origem;

    printf("Ordem da visita:\n");
    while (inicio < fim) {
        int u = fila[inicio++]; // tira da frente
        printf("  %-5s distância %d\n", nomes[u], dist[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1; // marca ao ENTRAR na fila
                pai[v] = u;
                fila[fim++] = v;
            }
        }
    }

    // o caminho sai de trás para frente, seguindo pai[]
    int destino = 5; // Rita
    int caminho[V], n = 0;
    for (int v = destino; v != -1; v = pai[v]) caminho[n++] = v;
    printf("Caminho até %s:", nomes[destino]);
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", nomes[caminho[i]], i > 0 ? " ->" : "");
    printf(" (distância %d)\n", dist[destino]);
    return 0;
}
// Saída:
// Ordem da visita:
//   Lia   distância 0
//   Max   distância 1
//   Nina  distância 1
//   Otto  distância 2
//   Pedro distância 2
//   Rita  distância 3
// Caminho até Rita: Lia -> Max -> Otto -> Rita (distância 3)
```

Repara no fluxograma: a pergunta "a fila esvaziou?" controla tudo. Cada volta
tira um vértice e pode colocar vários; quando ninguém novo aparece, a fila
seca e a busca termina:

{{fluxograma}}

### Passo a passo

Cada linha é uma volta do `while`. Otto já foi descoberto por Max, então
quando Nina olha para ele, nada acontece:

| Tira | Vizinhos novos | dist anotada | Fila depois |
| --- | --- | --- | --- |
| (início) | | Lia = 0 | Lia |
| Lia | Max, Nina | 1, 1 | Max, Nina |
| Max | Otto | 2 | Nina, Otto |
| Nina | Pedro (Otto já tem dist) | 2 | Otto, Pedro |
| Otto | Rita | 3 | Pedro, Rita |
| Pedro | nenhum (Rita já tem dist) | | Rita |
| Rita | nenhum | | (vazia) |

A distância só cresce na fila: primeiro saem todos os de distância 1, depois
todos os de 2. Por isso o primeiro caminho que alcança Rita é o mais curto.
Isso vale porque toda aresta "custa" 1. Com pesos diferentes (minutos, reais)
a BFS erra, e é aí que entra Dijkstra (assunto 0117).

O exemplo A230 usa a mesma BFS numa grade: cada casa de um galpão é um
vértice e os vizinhos são as casas de cima, de baixo, da esquerda e da direita.
Ninguém monta matriz de adjacência; os vizinhos saem de uma conta.

> [!WARNING]
> Marque o vértice como descoberto **ao colocar na fila**, não ao tirar. Se
> você só marca ao tirar, Otto entra duas vezes (uma por Max, outra por Nina) e,
> num grafo maior, o mesmo vértice entra muitas vezes. A fila de V posições
> estoura, e o vértice aparece repetido na ordem de visita.

> [!TIP]
> **Por dentro do C:** a fila da BFS é só `int fila[V]` com dois índices,
> `inicio` e `fim`. Como cada vértice entra uma vez só, `fim` nunca passa de V e
> não precisa nem da fila circular. Tirar do início deslocando todos os
> elementos uma casa para trás custaria O(n) a cada saída; aqui,
> `fila[inicio++]` é O(1). O custo total da BFS é O(V²) com matriz (para cada
> vértice, varre a linha inteira) e O(V + E) com lista de adjacência. Os três
> vetores (`dist`, `pai`, `fila`) somam 3 × 6 × 4 = 72 bytes na pilha.

> [!NOTE]
> **Pergunta para você:** se a conexão entre Max e Otto sumir, qual passa a ser
> o caminho até Rita, e quem descobre Otto? Preveja a nova tabela antes de
> apagar o par `{1, 3}` no A229.

{{pratique}}
