## 0156 · Juntando tudo: o assistente do calouro

Primeira semana na faculdade. O calouro tem duas dúvidas que não saem da
cabeça. A primeira é de calendário: com esses pré-requisitos, em quantos
semestres dá para se formar, e o que cursar em cada um? A segunda é de
geografia: o campus é enorme, e a aula de Laboratório começa cinco minutos
depois do almoço no Bandejão. Qual o caminho mais rápido entre os prédios?

São dois grafos diferentes, e cada pergunta tem o seu algoritmo. O módulo
inteiro serve para você bater o olho na pergunta e saber qual usar:

| Pergunta | Algoritmo | Custo |
| --- | --- | --- |
| Quais pedaços são independentes? | componentes (DFS + laço externo) | O(V + E) |
| Tem ciclo num grafo dirigido? | DFS com três cores | O(V + E) |
| Em que ordem fazer, respeitando as setas? | ordenação topológica (Kahn ou DFS) | O(V + E) |
| Ligar todos pelo menor custo total | Kruskal ou Prim (árvore geradora mínima) | O(E log E) ou O(E log V) |
| Menor caminho de uma origem, pesos >= 0 | Dijkstra (assunto 0112) | O((V + E) log V) |
| Menor caminho de uma origem, com pesos negativos | Bellman-Ford | O(V · E) |
| Menor caminho entre todos os pares | Floyd-Warshall | O(V³) |

A grade de disciplinas é um **DAG**: setas "antes de", sem peso. A pergunta
"quantos semestres" é o Kahn por rodadas do exemplo A302: cada rodada pega
tudo que já está liberado. E de quebra ele avisa se a coordenação criou um
pré-requisito circular.

O mapa do campus é um grafo **não dirigido** e ponderado, com seis prédios.
O calouro vai perguntar rotas entre pares variados ao longo do semestre, então
vale calcular a tabela inteira uma vez com o **Floyd-Warshall**, guardando o
próximo passo de cada rota (como no A309), e depois responder qualquer
pergunta só consultando a matriz.

O programa usa um único tipo `Grafo` para os dois mapas: o número de
vértices, os nomes e uma matriz de pesos. A função `liga` recebe se a aresta
é de mão dupla. Na grade, o peso só marca a seta (vale 1); no campus, são os
minutos de caminhada. As funções recebem `const Grafo *` para não copiar a
struct, que passa de 300 bytes.

Vamos ver na prática. Em cima, a grade com o semestre de cada disciplina;
embaixo, o campus com as duas rotas que o programa calcula, em verde:

{{ideia}}

O código completo. Cada algoritmo mora numa função, e o `main` só monta os
dois grafos e faz as perguntas:

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

Repara no fluxograma: é o `main`, e as duas perguntas são independentes. A
grade passa pelo Kahn e por um teste de ciclo; o campus passa pelo
Floyd-Warshall uma vez e depois só consulta a tabela:

{{fluxograma}}

O exemplo A311 é um planejador de entregas que escolhe sozinho entre
Dijkstra e Bellman-Ford, olhando se existe peso negativo. O A312 é um mini
gerenciador de pacotes: instala só as dependências do pacote pedido, na
ordem certa, com a DFS em pós-ordem.

> [!WARNING]
> Usar a matriz de pesos com "0 = sem aresta" tem um preço: uma aresta de peso
> **zero** de verdade some. Na grade isso não importa (o peso é sempre 1), mas
> um mapa com uma passarela "de graça" entre dois prédios precisaria de outra
> marca para "sem aresta", como o próprio INFINITO. E não misture as
> perguntas: Floyd-Warshall num grafo de 100 mil vértices é inviável (10¹⁵
> passos), e Kruskal não responde caminho mínimo. A árvore mínima liga
> todos barato, mas a rota entre dois pontos dentro dela pode ser bem pior
> que a ótima.

> [!TIP]
> **Por dentro do C:** cada `Grafo` tem o `n` (4 bytes), 4 bytes de
> alinhamento para o vetor de ponteiros começar num múltiplo de 8, os 8
> ponteiros para os nomes (64 bytes numa máquina de 64 bits) e `int
> peso[8][8]` (256 bytes): `sizeof(Grafo)` dá 328, no frame de `main`. Os
> nomes em si são literais de string, que moram numa área só de leitura do
> programa; a struct guarda só os endereços. Passar `&campus` copia 8 bytes;
> passar `campus` por valor copiaria os 328 a cada chamada. Já `int d[][MAX]` como parâmetro é, na
> verdade, um ponteiro para linhas de `MAX` inteiros: o compilador precisa
> saber o `MAX` para calcular onde fica `d[i][j]`.

> [!NOTE]
> **Pergunta para você:** se a coordenação colocar Projeto como pré-requisito
> de Cálculo (`liga(&grade, 6, 1, 1, 0)`), o que o programa mostra? E se a
> trilha Lab–Reitoria fechar para obra, qual passa a ser a rota do Lab ao
> Ginásio, e quantos minutos leva?

{{pratique}}
