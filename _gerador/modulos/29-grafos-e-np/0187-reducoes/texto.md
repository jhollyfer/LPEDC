## 0187 · Reduções

A síndica quer montar a maior comissão possível no condomínio sem nenhum par
de moradores que já brigou. O sobrinho dela tem um programa que acha o maior
grupo de amigos numa rede social, um grupo em que todo mundo conhece todo
mundo. Os dois problemas parecem diferentes, mas o programa do sobrinho serve
para a síndica, desde que ela **traduza** a pergunta dela para a linguagem
dele. Essa tradução se chama **redução**, e ela é a ferramenta que separa os
problemas fáceis dos difíceis.

Uma **redução polinomial** de um problema A para um problema B, escrita
**A ≤p B**, é um algoritmo de tempo polinomial que transforma qualquer
instância de A numa instância de B com **a mesma resposta**: se a de A é
"sim", a de B também é, e vice-versa. Com ela, quem sabe resolver B resolve A:
traduz a entrada, roda o programa de B e devolve a resposta. Por isso A ≤p B
quer dizer que A **não é mais difícil** que B (CORMEN et al., 2024, cap. 34).

A redução tem dois usos, em sentidos opostos. O primeiro é prático:
**resolver** A quando você já tem um programa para B, como a síndica com o
programa do sobrinho. O segundo é teórico: **provar dificuldade**. Se A é
NP-difícil e A ≤p B, então B também é NP-difícil, porque um algoritmo rápido
para B daria, pela tradução, um algoritmo rápido para A (LINTZMAYER; MOTA,
2023). É assim que a lista de problemas NP-completos cresceu desde o SAT: cada
novo membro entra por uma redução a partir de um já conhecido.

Três problemas de grafo aparecem juntos o tempo todo. Um **conjunto
independente** é um conjunto de vértices sem nenhuma aresta entre eles: a
comissão sem brigas, se cada briga for uma aresta. Uma **clique** é o oposto,
um conjunto de vértices com todas as arestas possíveis entre eles: o grupo de
amigos. Uma **cobertura de vértices** é um conjunto de vértices que toca toda
aresta, isto é, toda aresta tem pelo menos uma ponta no conjunto. Na versão de
decisão ("existe um de tamanho k?"), os três são NP-completos (KARP, 1972).

A ponte entre eles é o **complemento** de um grafo G: um grafo com os mesmos
vértices e com aresta exatamente entre os pares que G **não** liga. No
condomínio, G é o grafo das brigas, e o complemento é o grafo da paz. Um
conjunto S sem nenhuma briga dentro dele é um conjunto em que todo par está
em paz. Logo, S é independente em G se e só se S é uma clique no
complemento. Montar o complemento é percorrer os V² pares da matriz de
adjacência: custo O(V²), polinomial (CORMEN et al., 2024, cap. 34). Em C,
com a matriz `briga`, a linha que monta o complemento é `paz[a][b] = a != b
&& !briga[a][b]`.

A cobertura entra pelo mesmo raciocínio. Se S é independente em G, nenhuma
aresta tem as duas pontas em S, então toda aresta tem pelo menos uma ponta
fora de S, em **V − S**. Logo V − S é uma cobertura de G, e a volta também
vale. Juntando: existe independente de tamanho k em G se e só se existe clique
de tamanho k no complemento, se e só se existe cobertura de tamanho V − k em
G. Com conjuntos guardados como máscaras de bits, o complemento de um conjunto
é `todos & ~comissao`, com `todos = (1 << V) - 1`.

Uma redução mais engenhosa leva do 3-SAT (0186) à clique. Cada cláusula da
fórmula vira um grupo de vértices, um vértice por literal. Ligue dois
vértices quando estão em cláusulas **diferentes** e não se contradizem, isto
é, um não é `x` enquanto o outro é `não x`. Uma clique com um vértice de cada
cláusula escolhe, em cada cláusula, um literal que pode ser verdadeiro sem
conflito com os outros escolhidos. Tornar verdadeiros esses literais satisfaz
a fórmula; e uma atribuição que satisfaz a fórmula dá essa clique. Como o
3-SAT é NP-completo, a clique também é (CORMEN et al., 2024, cap. 34).

> [!WARNING]
> A pegadinha é o sentido. Para provar que X é difícil, reduza um difícil
> conhecido **a X**. Reduzir X a SAT só mostra que X não é mais difícil que
> SAT. E a redução precisa ser polinomial.

{{exemplo}}

Uma síndica quer a maior comissão sem nenhum par que já brigou, e o sobrinho
tem um programa que acha o maior grupo de amigos. À esquerda, G e a maior
comissão; no meio, o complemento, em que ela vira clique; à direita, os
outros três são a cobertura:

{{ideia}}

A força bruta de clique é a **caixa-preta**; a redução é a montagem de
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

Os três passos de toda redução: transformar a entrada, chamar o resolvedor do
outro problema e traduzir a resposta:

{{fluxograma}}
