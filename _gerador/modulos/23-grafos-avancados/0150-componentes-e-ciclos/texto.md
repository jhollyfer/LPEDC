## 0150 · Componentes e ciclos

Você monta a planilha da reforma do apartamento. A célula Total soma Obra e
Frete; Obra soma Tinta e Piso; Piso inclui o Frete. Numa outra aba, o
financiamento: Juros usa o Saldo, Saldo usa a Parcela, e alguém fez a Parcela
usar os Juros. Ao apertar Enter, a planilha reclama: **referência circular**.
Ela não tem como calcular um valor que depende dele mesmo.

A planilha é um **grafo dirigido**: cada célula é um vértice, e a seta
`a -> b` diz "a fórmula de `a` usa `b`". Ela faz duas perguntas sobre esse
grafo, e as duas se respondem com a DFS do assunto 0111:

- **quais pedaços são independentes?** São os **componentes conexos**: grupos
  em que todo mundo está ligado a todo mundo por algum caminho, sem olhar a
  direção das setas. Mudar o Frete nunca mexe nos Juros.
- **existe um ciclo?** Um caminho que sai de uma célula e volta para ela,
  seguindo as setas.

**Componentes.** Uma DFS a partir de um vértice marca tudo que ele alcança.
Num grafo não dirigido, isso é exatamente o componente dele. Para achar todos,
um **laço externo** passa por cada vértice e, se ele ainda não tem grupo,
começa uma DFS nova com um número de grupo novo. Cada recomeço é um
componente. Custa O(V + E) com lista de adjacência: cada vértice é marcado uma
vez só.

**Ciclo num grafo dirigido.** Aqui o `visitado[]` simples engana. Repare no
Frete: Total chega nele direto e também por Obra, Piso. Quando a DFS volta a
Total e olha o Frete, ele já foi visitado, mas isso não é ciclo: são dois
caminhos que se encontram. Ciclo é voltar a um vértice que **ainda está na
pilha** da recursão, um ancestral de quem está sendo explorado.

Por isso a DFS usa **três cores**:

- **branco**: nunca visto;
- **cinza**: a chamada dele começou e não terminou (está na pilha);
- **preto**: terminado, tudo abaixo dele já foi explorado.

Achar uma seta para um vértice **cinza** é achar um ciclo. Seta para preto é
só um atalho para algo já resolvido. E o vetor `pai[]` reconstrói o ciclo:
basta subir de pai em pai até o vértice cinza.

Vamos ver na prática. Os números mostram a ordem em que a DFS descobre cada
célula. No momento do desenho, o grupo da obra já está todo preto (verde) e a
DFS do financiamento está no fundo da pilha, com os três em cinza (amarelo).
A seta de Parcela para Juros aponta para um cinza:

{{ideia}}

O código usa uma DFS para cada pergunta. Os grupos ignoram a direção
(`usa[u][v] || usa[v][u]`); o ciclo respeita a direção e usa as cores:

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

Repara no fluxograma: é a chamada `acha_ciclo(u)`. Cada vizinho cai numa de
três situações. Cinza encerra tudo com o ciclo; branco desce na recursão;
preto é ignorado. Quando os vizinhos acabam, `u` fica preto e a chamada
volta para quem a chamou:

{{fluxograma}}

### Passo a passo

As cores no fim de cada chamada ou descoberta. Repare na linha do Frete visto
de Total: ele já está preto, e a DFS segue em frente sem alarme:

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

O exemplo A299 faz o mesmo num grafo **não dirigido** (a rede de cabos de um
escritório), onde não há cores: basta ignorar o pai. O A300 conta os grupos
de amigos à medida que as amizades chegam, com o union-find do assunto 0148.

> [!WARNING]
> Usar só `visitado[]` para achar ciclo num grafo dirigido dá **alarme
> falso**. No exemplo, Total encontraria o Frete já visitado e gritaria
> "ciclo!" sem existir ciclo nenhum. A pergunta certa não é "já vi?", é "ele
> ainda está na pilha?". No grafo **não dirigido** o erro é o oposto: toda
> aresta aparece nos dois sentidos, e o vizinho que é o pai sempre parece um
> ciclo. Lá, ignore o pai.

> [!TIP]
> **Por dentro do C:** a cor cinza é a pilha de chamadas escrita num vetor.
> Os vértices cinza são exatamente os que têm um frame de `acha_ciclo` vivo
> na pilha do programa, e o `enum` deixa isso legível: `BRANCO`, `CINZA` e
> `PRETO` são só as constantes inteiras 0, 1 e 2. Como os vetores são
> globais, começam zerados, ou seja, todo mundo nasce `BRANCO` e com
> `grupo` 0 sem precisar de laço de inicialização. O vetor `volta[V]` é
> local: só existe durante a chamada que achou o ciclo.

> [!NOTE]
> **Pergunta para você:** se a fórmula da Parcela deixar de usar os Juros e
> passar a usar o Frete (troque `{6, 5}` por `{6, 4}`), quantos grupos
> independentes sobram e ainda existe referência circular? Responda antes de
> rodar.

{{pratique}}
