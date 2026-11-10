## 0150 · Componentes e ciclos

Na planilha da reforma, o Total soma Obra e Frete, a Obra soma Tinta e Piso, e
o Piso inclui o Frete. Em outra aba, os Juros usam o Saldo, o Saldo usa a
Parcela, e alguém fez a Parcela usar os Juros. A planilha reclama:
**referência circular**.

A planilha é um **grafo dirigido**: cada célula é um vértice, e a seta
`a -> b` diz "a fórmula de `a` usa `b`". Duas perguntas sobre ele se
respondem com a DFS do assunto 0111:

- **quais pedaços são independentes?** São os **componentes conexos**: grupos
  em que todo vértice se liga a todo outro por algum caminho, sem olhar a
  direção das setas;
- **existe um ciclo?** Um caminho que volta à célula de partida, seguindo as
  setas.

**Componentes.** Uma DFS marca tudo que o vértice alcança: esse é o
componente dele. Um **laço externo** começa uma DFS nova, com número de grupo
novo, em cada vértice ainda sem grupo. Custa O(V + E) com lista de
adjacência.

**Ciclo num grafo dirigido.** O `visitado[]` simples engana: Total chega ao
Frete direto e por Obra e Piso. O Frete já visitado são dois caminhos que se
encontram, não um ciclo. Ciclo é voltar a um vértice que **ainda está na
pilha** da recursão. Por isso a DFS usa **três cores**:

- **branco**: nunca visto;
- **cinza**: a chamada começou e não terminou (está na pilha);
- **preto**: terminado, tudo abaixo dele já foi explorado.

Seta para **cinza** é ciclo; seta para preto leva a algo já resolvido. O
`pai[]` reconstrói o ciclo, subindo até o cinza. O Cormen chama essa seta de
**aresta de retorno** (*back edge*): um grafo dirigido é acíclico se e só se
a DFS não encontra nenhuma.

> [!NOTE]
> "Conexo ignorando a direção" é ser **fracamente conexo**. Os
> **componentes fortemente conexos** são grupos em que cada vértice alcança
> cada outro **seguindo** as setas (Juros, Saldo e Parcela formam um). Saem
> com duas DFS, a segunda no grafo com as setas invertidas, em O(V + E).
> Pontes e vértices de articulação: assunto 0184.

No desenho, os números dão a ordem de descoberta: a obra está preta (verde),
o financiamento está cinza (amarelo), e a seta de Parcela para Juros aponta
para um cinza:

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

O A299 faz o mesmo num grafo **não dirigido**, ignorando o pai. O A300 conta
grupos de amigos com o union-find do assunto 0148 (módulo 22).

> [!WARNING]
> Só com `visitado[]`, o ciclo dá **alarme falso** (o Frete). Pergunte
> "ainda está na pilha?", não "já vi?". No grafo **não dirigido**, o pai
> sempre parece um ciclo: ignore-o.

> [!NOTE]
> **Pergunta para você:** se a fórmula da Parcela deixar de usar os Juros e
> passar a usar o Frete (troque `{6, 5}` por `{6, 4}`), quantos grupos
> independentes sobram e ainda existe referência circular? Responda antes de
> compilar.

{{pratique}}
