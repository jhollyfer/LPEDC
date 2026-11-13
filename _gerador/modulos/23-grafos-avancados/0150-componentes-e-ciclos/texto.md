## 0150 · Componentes e ciclos

- **Componente conexo**: grupo em que todo vértice se liga a todo outro por
  algum caminho, sem olhar a direção das setas (ZIVIANI, 2010, cap. 7).
- **Contar componentes**: um **laço externo** começa uma DFS (assunto 0111), com
  número de grupo novo, em cada vértice ainda sem grupo. Custa O(V + E) com
  lista de adjacência (CORMEN et al., 2024, cap. 20).
- **Ciclo** num grafo dirigido: caminho que volta ao vértice de partida seguindo
  as setas.
- **Três cores**: **branco** (nunca visto), **cinza** (na pilha da recursão) e
  **preto** (terminado). Seta para cinza é ciclo; seta para preto leva a algo já
  resolvido. O `pai[]` reconstrói o ciclo (CORMEN et al., 2024, cap. 20).
- **Aresta de retorno** (*back edge*): a seta para um cinza. Um grafo dirigido é
  acíclico se e só se a DFS não acha nenhuma (CORMEN et al., 2024, cap. 20).
- **Fortemente conexo**: cada vértice alcança cada outro **seguindo** as setas.
  Sai com duas DFS, a segunda no grafo invertido, em O(V + E). Ignorar a direção
  é ser só **fracamente conexo** (SEDGEWICK; WAYNE, 2011). Pontes e articulação:
  assunto 0184.

> [!WARNING]
> Só com `visitado[]`, o ciclo dá **alarme falso**: dois caminhos que se
> encontram não são ciclo. Pergunte "ainda está na pilha?", não "já vi?". No
> grafo **não dirigido**, o pai sempre parece ciclo: ignore-o.

{{exemplo}}

Uma planilha de reforma vira grafo: a seta `a -> b` diz "a fórmula de `a` usa
`b`". Os números dão a ordem de descoberta; a obra fica preta (verde), o
financiamento cinza (amarelo), e a seta de Parcela para Juros aponta para um
cinza:

{{ideia}}

Os grupos ignoram a direção; o ciclo a respeita e usa as cores:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 8
enum { BRANCO, CINZA, PRETO }; // nunca visto, na pilha, terminado

const char *nomes[V] = {"Total", "Obra", "Tinta", "Piso", "Frete", "Juros", "Parcela", "Saldo"};
int usa[V][V]; // usa[a][b] = 1: a fórmula de a usa o valor de b
int grupo[V];  // número do componente de cada célula (0 = sem grupo ainda)
int cor[V], pai[V];

// componentes: a direção não importa, só se as células estão ligadas
void marca_grupo(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if ((usa[u][v] || usa[v][u]) && grupo[v] == 0) marca_grupo(v, g);
}

// ciclo: DFS com três cores; devolve true se achar uma aresta para um CINZA
bool acha_ciclo(int u) {
    cor[u] = CINZA;
    for (int v = 0; v < V; v++) {
        if (!usa[u][v]) continue;
        if (cor[v] == CINZA) { // v ainda está na pilha: voltamos a ele
            int volta[V], n = 0; // sobe pelos pais de u até v
            for (int w = u; w != v; w = pai[w]) volta[n++] = w;
            printf("Referência circular: %s", nomes[v]);
            for (int i = n - 1; i >= 0; i--) printf(" -> %s", nomes[volta[i]]);
            printf(" -> %s\n", nomes[v]);
            return true;
        }
        if (cor[v] == BRANCO) {
            pai[v] = u;
            if (acha_ciclo(v)) return true;
        }
    }
    cor[u] = PRETO; // tudo abaixo de u já foi explorado
    return false;
}

int main(void) {
    int formulas[][2] = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {3, 4},  // orçamento da obra
                         {5, 7}, {7, 6}, {6, 5}};                 // financiamento
    for (int k = 0; k < 8; k++) usa[formulas[k][0]][formulas[k][1]] = 1;

    int grupos = 0;
    for (int u = 0; u < V; u++)
        if (grupo[u] == 0) marca_grupo(u, ++grupos); // cada recomeço é um grupo novo
    printf("Grupos independentes: %d\n", grupos);
    for (int g = 1; g <= grupos; g++) {
        printf("  grupo %d:", g);
        for (int v = 0; v < V; v++)
            if (grupo[v] == g) printf(" %s", nomes[v]);
        printf("\n");
    }

    bool ciclo = false;
    for (int u = 0; u < V && !ciclo; u++) {
        pai[u] = -1;
        if (cor[u] == BRANCO) ciclo = acha_ciclo(u);
    }
    if (!ciclo) printf("Nenhuma referência circular\n");
    return 0;
}
// Saída:
// Grupos independentes: 2
//   grupo 1: Total Obra Tinta Piso Frete
//   grupo 2: Juros Parcela Saldo
// Referência circular: Juros -> Saldo -> Parcela -> Juros
```

No fluxograma, cada vizinho de `u` é cinza (ciclo), branco (desce) ou preto
(ignorado). Sem vizinhos novos, `u` fica preto:

{{fluxograma}}

### Passo a passo

O Frete visto de Total já está preto: sem alarme.

| Evento | Cinza (na pilha) | Preto |
| --- | --- | --- |
| entra em Total, Obra, Tinta | Total, Obra, Tinta | |
| Tinta não usa ninguém | Total, Obra | Tinta |
| entra em Piso, Frete | Total, Obra, Piso, Frete | Tinta |
| Frete, Piso e Obra terminam | Total | Tinta, Frete, Piso, Obra |
| Total olha Frete: **preto**, segue | Total | (igual) |
| Total termina | | os 5 da obra |
| entra em Juros, Saldo, Parcela | Juros, Saldo, Parcela | os 5 da obra |
| Parcela olha Juros: **cinza**, ciclo | | |

O A299 faz o mesmo num grafo não dirigido; o A300 conta grupos com o
union-find (0148).
