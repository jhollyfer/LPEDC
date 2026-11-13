## 0110 · BFS: busca em largura

Num grafo, uma pergunta aparece o tempo todo: qual é o jeito mais curto de
sair de um vértice e chegar a outro? Você quer uma indicação para uma vaga e
não conhece a recrutadora, mas conhece pessoas que conhecem pessoas. A
corrente mais curta de apresentações é o caminho com menos arestas entre você
e ela no grafo de amizades.

Esse número tem nome. A **distância** de um vértice `s` até um vértice `v` é o
menor número de arestas de um caminho que sai de `s` e chega a `v`
(FEOFILOFF, 2009, cap. 5). A "conexão de 2º grau" de uma rede profissional é
distância 2. Não confunda com o grau do assunto 0109, que conta as arestas que
tocam um vértice.

Para achar todas as distâncias a partir de `s`, existe a **busca em largura**,
ou BFS (do inglês *breadth-first search*). Pense numa pedra jogada no lago. A
onda 0 é o próprio `s`. A onda 1 são os vizinhos dele, a uma aresta. A onda 2
são os vizinhos desses que ainda não apareceram, a duas arestas. E assim por
diante, sem pular nenhuma camada (CORMEN et al., 2024, cap. 20). Como a busca
termina uma onda inteira antes de começar a seguinte, a primeira vez que ela
encontra um vértice é sempre pelo caminho mais curto.

A peça que garante a ordem das ondas é a **fila** do assunto 0085: quem foi
descoberto primeiro sai primeiro. O laço tira um vértice `u` da frente da fila
e olha cada vizinho `v`. Se `v` ainda não foi descoberto, a busca faz
`dist[v] = dist[u] + 1`, anota `pai[v] = u` e põe `v` no fim da fila
(FEOFILOFF, 2009, cap. 5). Os vértices da onda 1 entram todos antes dos da
onda 2, então também saem antes.

O vetor `dist[]` faz dois papéis. Ele guarda a distância de cada vértice e,
com o valor `-1`, marca quem ainda não foi descoberto. A marca impede a busca
de andar em círculos: num grafo, dá para chegar ao mesmo vértice por caminhos
diferentes, e sem ela o vértice entraria na fila de novo a cada caminho
(FEOFILOFF, 2009, cap. 5).

O vetor `pai[]` guarda quem descobriu cada vértice. Os pares (`pai[v]`, `v`)
formam a **árvore da BFS**, uma árvore com raiz em `s` que contém um caminho
mais curto até cada vértice alcançado. Para montar o caminho até um destino,
siga `pai[]` a partir dele até chegar em `-1`, o pai da origem. O caminho sai
de trás para a frente, e você o inverte na hora de mostrar (CORMEN et al.,
2024, cap. 20).

O Cormen descreve o mesmo estado com **cores**. **Branco** é o vértice ainda
não descoberto, o nosso `dist == -1`. **Cinza** é o que já foi descoberto e
está na fila. **Preto** é o que já saiu da fila e teve todos os vizinhos
olhados. Na notação dele, `v.d` é o nosso `dist[v]` e `v.π` é o `pai[v]`
(CORMEN et al., 2024, cap. 20).

Quanto custa? Cada vértice entra na fila no máximo uma vez, então um vetor
`int fila[V]` basta e tirar da frente é só `fila[inicio++]`, em O(1). O resto
do custo é olhar vizinhos. Com matriz, cada vértice varre uma linha de V
casas, e a BFS custa O(V²). Com lista de adjacência, cada aresta é olhada um
número constante de vezes, e o total cai para O(V + E) (ZIVIANI, 2010, cap. 7).

A BFS tem um limite claro: ela acha o caminho com menos **arestas**, e isso só
é o mais curto quando toda aresta custa o mesmo. Se as arestas têm pesos, como
minutos de viagem, um caminho com mais arestas pode sair mais barato. Para
esse caso entra o algoritmo de Dijkstra, no assunto 0112 (CORMEN et al., 2024,
cap. 22).

> [!WARNING]
> Marque o vértice como descoberto **ao pôr na fila**, não ao tirar. Marcando
> ao tirar, um vértice com dois vizinhos já vistos entra duas vezes e a fila
> estoura.

{{exemplo}}

Lia quer uma indicação para a vaga da recrutadora Rita. A onda 1 é Max e
Nina; a 2, Otto e Pedro; a 3, Rita. As setas verdes são a árvore da BFS, e o
número de cada pessoa é a distância:

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

A busca termina quando a fila esvazia. O A219 agrupa por onda e o A220 roda a
BFS numa grade:

{{fluxograma}}

### Passo a passo

Cada linha é uma volta do `while`. Otto já foi descoberto por Max; quando Nina
o vê, nada acontece:

| Tira | Vizinhos novos | dist anotada | Fila depois |
| --- | --- | --- | --- |
| (início) | | Lia = 0 | Lia |
| Lia | Max, Nina | 1, 1 | Max, Nina |
| Max | Otto | 2 | Nina, Otto |
| Nina | Pedro (Otto já tem dist) | 2 | Otto, Pedro |
| Otto | Rita | 3 | Pedro, Rita |
| Pedro | nenhum (Rita já tem dist) | | Rita |
| Rita | nenhum | | (vazia) |
