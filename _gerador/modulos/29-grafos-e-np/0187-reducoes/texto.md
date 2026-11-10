## 0187 · Reduções

A síndica quer a **maior** comissão do condomínio sem nenhum par que já
brigou. O sobrinho tem um programa que acha o **maior grupo de amigos** numa
rede social. Dá para usá-lo, se ela **traduzir** a pergunta: uma **redução**.

**Redução polinomial.** Reduzir A a B (**A ≤p B**) é dar um algoritmo
polinomial que transforma toda instância de A numa de B com **a mesma
resposta**. A **não é mais difícil** que B. Serve em dois sentidos:

- **resolver**: tenho um programa para B e quero resolver A;
- **provar dificuldade**: se A é NP-difícil e A ≤p B, então B também é. Se B
  fosse fácil, A seria fácil.

Três problemas de grafo, NP-completos na versão de decisão ("existe um de
tamanho k?"):

- **conjunto independente**: vértices sem **nenhuma** aresta entre eles (a
  comissão sem brigas);
- **clique**: vértices com **todas** as arestas entre eles (os amigos);
- **cobertura de vértices**: vértices que **tocam toda aresta**.

O **complemento** de G tem aresta entre os pares que G não liga, e só entre
eles. Então:

- S é independente em G ⇔ S é **clique no complemento** de G;
- S é independente em G ⇔ **V − S** é uma **cobertura** de G (sem ponta fora
  de S, uma aresta teria as duas pontas em S).

Logo, um independente de tamanho k existe ⇔ uma clique de tamanho k existe no
complemento ⇔ uma cobertura de tamanho n − k existe em G. O complemento custa
O(V²).

Seis moradores, sete brigas. À esquerda, G e a maior comissão; no meio, o
complemento, em que ela vira clique; à direita, os outros três são a
cobertura:

{{ideia}}

O programa usa a força bruta de clique como **caixa-preta**. A redução é a
montagem de `paz`:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *moradores[V] = {"Jorge", "Rita", "Kátia", "Léo", "Márcio", "Nina"};
int briga[V][V];    // G: aresta = os dois brigaram
int paz[V][V];      // complemento de G: aresta = não brigaram

// a "caixa-preta": maior clique por força bruta (devolve a máscara)
int maior_clique(int g[V][V]) {
    int melhor = 0, tam_melhor = 0;
    for (int m = 1; m < (1 << V); m++) {
        bool ok = true;
        int tam = 0;
        for (int a = 0; a < V; a++) {
            if (!(m >> a & 1)) continue;
            tam++;
            for (int b = a + 1; b < V; b++)
                if ((m >> b & 1) && !g[a][b]) ok = false;
        }
        if (ok && tam > tam_melhor) melhor = m, tam_melhor = tam;
    }
    return melhor;
}

void mostra(const char *rotulo, int m) {
    int tam = 0;
    printf("%s:", rotulo);
    for (int v = 0; v < V; v++)
        if (m >> v & 1) printf(" %s", moradores[v]), tam++;
    printf(" (%d)\n", tam);
}

int main(void) {
    int brigas[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {2, 5}};
    for (int k = 0; k < 7; k++) briga[brigas[k][0]][brigas[k][1]] = briga[brigas[k][1]][brigas[k][0]] = 1;

    // a redução: montar o complemento custa O(V²)
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) paz[a][b] = a != b && !briga[a][b];

    int comissao = maior_clique(paz);         // clique no complemento...
    mostra("Comissão sem brigas", comissao);   // ...é conjunto independente em G
    int todos = (1 << V) - 1;
    mostra("Mediadores (cobertura)", todos & ~comissao); // o resto cobre toda briga
    return 0;
}
// Saída:
// Comissão sem brigas: Rita Kátia Márcio (3)
// Mediadores (cobertura): Jorge Léo Nina (3)
```

O fluxograma mostra os três passos de toda redução: transformar a entrada,
chamar o resolvedor do outro problema e traduzir a resposta:

{{fluxograma}}

**Do 3-SAT à clique.** Cada cláusula vira um grupo de vértices, um por
literal; ligue vértices de cláusulas **diferentes** que **não se
contradizem**. Uma clique com um vértice por cláusula escolhe um literal
verdadeiro por cláusula: uma atribuição que satisfaz a fórmula. O A373 faz
essa construção; o A374 reduz caminho hamiltoniano a ciclo hamiltoniano.

> [!WARNING]
> A pegadinha é o sentido. Para provar que X é difícil, reduza um difícil
> conhecido **a X** (conhecido ≤p X). Reduzir X a SAT só mostra que X não é
> mais difícil que SAT, o que vale para todo NP. E a redução precisa ser
> polinomial.

> [!TIP]
> Os conjuntos são máscaras de bits: o complemento é `todos & ~comissao`, com
> `todos = (1 << V) - 1`. O do **grafo** é `paz[a][b] = a != b && !briga[a][b]`.

> [!NOTE]
> **Pergunta para você:** se a Kátia e o Márcio também brigarem (`{2, 4}`),
> qual o tamanho da maior comissão? E da menor cobertura? A soma dos dois
> continua sendo 6?

{{pratique}}
