## 0187 · Reduções

A síndica quer montar a comissão do condomínio com o **maior** número de
moradores possível, sem nenhum par que já brigou em assembleia. Ela não
sabe resolver isso. Mas o sobrinho dela tem um programa que acha o **maior
grupo de amigos** numa rede social. Dá para usar o programa do sobrinho no
problema da síndica? Dá, se ela souber **traduzir** a pergunta.

Traduzir um problema em outro é uma **redução**, a ferramenta que separa os
problemas fáceis dos difíceis.

**Redução polinomial.** Reduzir A a B (escreve-se **A ≤p B**) é dar um
algoritmo de tempo polinomial que transforma qualquer instância de A numa
instância de B com **a mesma resposta**. Com isso, um resolvedor de B
resolve A: transforma, resolve, devolve. A redução diz que A **não é mais
difícil** que B.

Ela serve para duas coisas, em sentidos opostos:

- **resolver**: tenho um programa para B e quero resolver A;
- **provar dificuldade**: se A já é NP-difícil e A ≤p B, então B também é
  NP-difícil. Se B fosse fácil, A seria fácil, e A não é (até onde se sabe).

Três problemas de grafo, todos NP-completos na versão de decisão ("existe
um de tamanho k?"):

- **conjunto independente**: vértices sem **nenhuma** aresta entre eles
  (a comissão sem brigas);
- **clique**: vértices com **todas** as arestas entre eles (o grupo de
  amigos);
- **cobertura de vértices**: vértices que **tocam toda aresta** (quem
  precisa de um mediador para que toda briga tenha um lado vigiado).

As duas pontes entre eles cabem numa linha cada. O **complemento** de G tem
aresta entre os pares que G não liga, e só entre eles. Então:

- S é independente em G ⇔ S é **clique no complemento** de G;
- S é independente em G ⇔ **V − S** é uma **cobertura** de G (se uma aresta
  não tivesse ponta fora de S, as duas pontas estariam em S, e S não seria
  independente).

Logo, um conjunto independente de tamanho k existe ⇔ uma clique de tamanho
k existe no complemento ⇔ uma cobertura de tamanho n − k existe em G. Montar
o complemento custa O(V²): é uma redução polinomial.

Seis moradores, sete brigas. À esquerda, G e a maior
comissão; no meio, o complemento, em que a mesma comissão vira uma clique; à
direita, os outros três formam a cobertura:

{{ideia}}

O programa usa a força bruta de clique como uma **caixa-preta**: ele nem
sabe que existe "conjunto independente". A redução se resume à montagem de
`paz`:

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

Toda redução segue os três passos do fluxograma: transformar a entrada,
chamar o resolvedor do outro problema e traduzir a resposta de volta. Só o
primeiro e o último são novos, e os dois são polinomiais:

{{fluxograma}}

**E o 3-SAT?** A prova clássica de que clique é NP-completo reduz 3-SAT a
clique. Para cada cláusula, um grupo de vértices, um por literal; ligue dois
vértices quando estão em cláusulas **diferentes** e **não se contradizem**
(`x` e `não x` nunca se ligam). Uma clique com um vértice de cada cláusula
escolhe um literal verdadeiro por cláusula sem contradição: é uma atribuição
que satisfaz a fórmula. O A373 faz essa construção em C; o A374 reduz
caminho hamiltoniano a ciclo hamiltoniano.

> [!WARNING]
> A pegadinha mais comum é o sentido da redução. Para provar que um problema
> novo X é difícil, reduza um difícil conhecido **a X** (conhecido ≤p X),
> nunca o contrário. Reduzir X a SAT só mostra que X não é mais difícil que
> SAT, o que vale para qualquer problema de NP. E a redução precisa ser
> polinomial: transformar em tempo exponencial não prova nada.

> [!TIP]
> **Por dentro do C:** os conjuntos são máscaras de bits num `int`: o bit
> `v` ligado quer dizer "v está no grupo". O complemento de um conjunto é
> `todos & ~comissao`, em que `todos = (1 << V) - 1` tem os V bits de baixo

> ligados; sem o `& todos`, o `~` ligaria também os 26 bits de cima. Já o
> complemento do **grafo** é outra matriz, `paz[a][b] = a != b && !briga[a][b]`:
> o `a != b` evita o laço de um vértice para ele mesmo.

> [!NOTE]
> **Pergunta para você:** se a Kátia e o Márcio também brigarem
> (`{2, 4}`), qual o tamanho da maior comissão? E da menor cobertura? A
> soma dos dois continua sendo 6?


{{pratique}}
