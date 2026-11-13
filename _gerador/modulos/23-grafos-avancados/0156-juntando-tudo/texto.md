## 0156 · Juntando tudo: o assistente do calouro

- **Cada pergunta, um algoritmo**: o tipo do grafo (dirigido ou não, com peso ou
  sem) e a pergunta escolhem a técnica (ZIVIANI, 2010, cap. 7).
- **Grade de disciplinas**: um **DAG** de setas "antes de", sem peso. "Quantos
  semestres" é o Kahn por rodadas (A302), que também acusa pré-requisito
  circular (CORMEN et al., 2024, cap. 20).
- **Campus**: grafo **não dirigido** e ponderado. Com muitas consultas, compensa
  calcular a tabela uma vez com o **Floyd-Warshall** e guardar o **próximo
  passo** de cada rota (A309) (CORMEN et al., 2024, cap. 23).
- **Um tipo `Grafo`** serve aos dois: número de vértices, nomes e matriz de
  pesos. As funções recebem `const Grafo *` para não copiar a struct, que passa
  de 300 bytes.

| Pergunta | Algoritmo | Custo |
| --- | --- | --- |
| Quais pedaços são independentes? | componentes (DFS + laço externo) | O(V + E) |
| Tem ciclo num grafo dirigido? | DFS com três cores | O(V + E) |
| Em que ordem fazer, respeitando as setas? | ordenação topológica (Kahn ou DFS) | O(V + E) |
| Ligar todos pelo menor custo total | Kruskal ou Prim (árvore geradora mínima) | O(E log E) ou O(E log V) |
| Menor caminho de uma origem, pesos >= 0 | Dijkstra (assunto 0112) | O((V + E) log V) |
| Menor caminho de uma origem, com pesos negativos | Bellman-Ford | O(V · E) |
| Menor caminho entre todos os pares | Floyd-Warshall | O(V³) |

> [!WARNING]
> Na matriz com "0 = sem aresta", uma aresta de peso **zero** some. Não misture
> as perguntas: Floyd-Warshall com 100 mil vértices é inviável (10¹⁵ passos), e
> a árvore mínima não dá caminho mínimo (21 m contra 18 m no 0153).

{{exemplo}}

O calouro quer saber em quantos semestres se forma e qual o caminho mais rápido
entre os prédios do campus. O desenho mostra a grade, com o semestre de cada
disciplina, e o campus, com as duas rotas em verde:

{{ideia}}

```c
#include <stdio.h>

#define MAX 8
#define INFINITO 1000000000

typedef struct {
    int n;
    const char *nomes[MAX];
    int peso[MAX][MAX]; // 0 = sem aresta
} Grafo;

void liga(Grafo *g, int a, int b, int peso, int mao_dupla) {
    g->peso[a][b] = peso;
    if (mao_dupla) g->peso[b][a] = peso;
}

// pré-requisitos: Kahn por rodadas; devolve quantos semestres (ou -1 se houver ciclo)
int semestres(const Grafo *g) {
    int grau[MAX] = {0}, atual[MAX], n_atual = 0, feitas = 0, s = 0;
    for (int a = 0; a < g->n; a++)
        for (int b = 0; b < g->n; b++) grau[b] += g->peso[a][b] != 0;
    for (int v = 0; v < g->n; v++)
        if (grau[v] == 0) atual[n_atual++] = v;
    while (n_atual > 0) {
        int prox[MAX], n_prox = 0;
        printf("  %dº semestre:", ++s);
        for (int i = 0; i < n_atual; i++) {
            int u = atual[i];
            printf(" %s", g->nomes[u]);
            feitas++;
            for (int v = 0; v < g->n; v++)
                if (g->peso[u][v] && --grau[v] == 0) prox[n_prox++] = v;
        }
        printf("\n");
        for (int i = 0; i < n_prox; i++) atual[i] = prox[i];
        n_atual = n_prox;
    }
    return feitas == g->n ? s : -1;
}

// rotas: Floyd-Warshall com a matriz de próximo passo
void todas_as_rotas(const Grafo *g, int d[][MAX], int prox[][MAX]) {
    for (int i = 0; i < g->n; i++)
        for (int j = 0; j < g->n; j++) {
            d[i][j] = (i == j) ? 0 : (g->peso[i][j] ? g->peso[i][j] : INFINITO);
            prox[i][j] = (i == j || g->peso[i][j]) ? j : -1;
        }
    for (int k = 0; k < g->n; k++)
        for (int i = 0; i < g->n; i++)
            for (int j = 0; j < g->n; j++)
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    prox[i][j] = prox[i][k];
                }
}

void mostra_rota(const Grafo *g, int d[][MAX], int prox[][MAX], int a, int b) {
    printf("  %d min: %s", d[a][b], g->nomes[a]);
    for (int v = a; v != b;) {
        v = prox[v][b]; // um passo rumo a b
        printf(" -> %s", g->nomes[v]);
    }
    printf("\n");
}

int main(void) {
    Grafo grade = {.n = 7, .nomes = {"Lógica", "Cálculo", "C", "Estruturas", "Arquivos", "Grafos", "Projeto"}};
    liga(&grade, 0, 2, 1, 0); // Lógica antes de C (dirigido; o peso só marca a seta)
    liga(&grade, 2, 3, 1, 0);
    liga(&grade, 2, 4, 1, 0);
    liga(&grade, 1, 5, 1, 0);
    liga(&grade, 3, 5, 1, 0);
    liga(&grade, 4, 6, 1, 0);
    liga(&grade, 5, 6, 1, 0);
    printf("Grade:\n");
    int s = semestres(&grade);
    if (s < 0) printf("  pré-requisito circular!\n");
    else printf("  formatura em %d semestres\n", s);

    Grafo campus = {.n = 6, .nomes = {"Portaria", "Biblioteca", "Lab", "Bandejão", "Ginásio", "Reitoria"}};
    liga(&campus, 0, 1, 4, 1); // minutos a pé, mão dupla
    liga(&campus, 0, 3, 7, 1);
    liga(&campus, 1, 2, 3, 1);
    liga(&campus, 1, 3, 2, 1);
    liga(&campus, 3, 4, 5, 1);
    liga(&campus, 2, 5, 6, 1);
    liga(&campus, 4, 5, 2, 1);
    int d[MAX][MAX], prox[MAX][MAX];
    todas_as_rotas(&campus, d, prox);
    printf("Campus:\n");
    mostra_rota(&campus, d, prox, 0, 2); // da Portaria até o Lab
    mostra_rota(&campus, d, prox, 2, 4); // do Lab até o Ginásio
    return 0;
}
// Saída:
// Grade:
//   1º semestre: Lógica Cálculo
//   2º semestre: C
//   3º semestre: Estruturas Arquivos
//   4º semestre: Grafos
//   5º semestre: Projeto
//   formatura em 5 semestres
// Campus:
//   7 min: Portaria -> Biblioteca -> Lab
//   8 min: Lab -> Reitoria -> Ginásio
```

O fluxograma é o `main`: a grade passa pelo Kahn, e o campus passa uma vez
pelo Floyd-Warshall e depois só consulta a tabela:

{{fluxograma}}
