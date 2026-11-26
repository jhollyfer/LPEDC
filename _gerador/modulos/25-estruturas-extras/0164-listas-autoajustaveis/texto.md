## 0164 · Listas autoajustáveis

Na cozinha, o sal fica na frente do armário e o cravo, lá no fundo. Ninguém
planejou isso: cada pote usado volta para a frente, e os mais usados acabam
sempre à mão. Uma lista pode aprender o mesmo truque.

A busca sequencial (assunto 0089) percorre a lista do começo até achar o
item, então custa a **posição** dele: o primeiro sai com uma comparação, o
décimo com dez. Se todos os itens fossem procurados com a mesma frequência,
a ordem não faria diferença. Só que quase nunca é assim. Na agenda do
celular, meia dúzia de contatos recebe quase todas as ligações. Se esses
contatos estivessem no começo, a busca média seria muito mais barata.

O problema é que ninguém sabe de antemão quem são os favoritos. A **lista
autoajustável** descobre sozinha: a cada busca bem-sucedida, ela aproxima do
começo o item achado (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7). Isso
muda o papel da busca, que além de ler a lista passa a escrever nela. A
regra que decide quanto o item anda se chama **política**, e há três
clássicas.

A primeira é **mover para a frente** (em inglês, *move-to-front*): o item
achado vira o primeiro da lista (CORTÉS, 2015). Ela reage rápido. Se Edu
passa a receber todas as ligações, depois da primeira ele já está na frente.
O defeito é o mesmo: um contato procurado uma única vez também pula para a
frente e empurra os favoritos uma casa para trás.

A segunda é a **transposição**: o item achado troca de lugar com o vizinho
da frente, o anterior, e anda só uma casa (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
Um acesso isolado quase não bagunça a lista. Em compensação, um item que
ficou popular de repente leva muitas buscas para chegar à frente.

A terceira é a **contagem**: cada nó guarda quantas vezes foi achado, e a
lista se mantém em ordem decrescente desse contador. Com o tempo, ela
converge para a melhor ordem fixa possível, a das frequências reais. O
preço é um campo a mais em cada nó e o trabalho de reposicionar o item
quando o contador dele ultrapassa o do vizinho.

A estrutura por baixo importa. Mover para a frente combina com **lista
encadeada**: tirar o nó do lugar e pendurá-lo no início são três
atribuições de ponteiro, `ant->prox = p->prox`, `p->prox = l->inicio` e
`l->inicio = p`. Num vetor, levar o décimo item para a frente obriga a
copiar os nove anteriores uma casa para trás (o A327 conta isso). A
transposição é a troca de dois vizinhos e serve igualmente bem aos dois.

Será que mover para a frente, tão simples, pode sair muito caro? Sleator e
Tarjan provaram que não: em qualquer sequência de buscas, ele nunca gasta
mais que o dobro da melhor ordem fixa, aquela que alguém escolheria
conhecendo todas as buscas de antemão (SLEATOR; TARJAN, 1985; CORMEN et
al., 2024, cap. 27). Esse tipo de comparação com um adversário que conhece o
futuro se chama **análise competitiva**.

> [!WARNING]
> Se o nó achado já é o primeiro, `ant` é `NULL` e `ant->prox = p->prox`
> derruba o programa (o E982 cobre esse caso). E sem `l->inicio = p`, o nó
> some da lista e vaza memória.

{{exemplo}}

Uma agenda com Ana, Bia, Caio, Duda e Edu recebe ligações para Edu, Edu, Caio,
Edu e Edu. Na terceira, Caio é achado na quarta comparação e vai para a frente;
Edu desce para o segundo lugar:

{{ideia}}

O TAD (`autolista.h`, `autolista.c`) tem as três políticas e uma busca que não
mexe em nada (`al_busca`), para comparar. Mover para a frente é a busca com
`ant` e `p` (assunto 0077) e três linhas no fim:

```c
bool al_busca_mtf(AutoLista *l, const char *nome, int *custo) {
    int c = 0;
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    while (p != NULL) {
        c++;
        if (strcmp(p->nome, nome) == 0) {
            break;
        }
        ant = p;
        p = p->prox;
    }
    if (custo != NULL) {
        *custo = c;
    }
    if (p == NULL) {
        return false;
    }
    if (ant != NULL) {       // se p já é o primeiro, nada a fazer
        ant->prox = p->prox; // tira p do lugar...
        p->prox = l->inicio; // ...e põe na frente
        l->inicio = p;
    }
    return true;
}
```

O programa faz as cinco ligações numa agenda que se ajusta e numa fixa, e soma
as comparações:

```c
#include <stdio.h>
#include "autolista.h"

int main(void) {
    const char *contatos[] = {"Ana", "Bia", "Caio", "Duda", "Edu"};
    const char *chamadas[] = {"Edu", "Edu", "Caio", "Edu", "Edu"};
    AutoLista *agenda = al_cria(); // a que se ajusta
    AutoLista *fixa = al_cria();   // a de sempre, para comparar
    for (int i = 0; i < 5; i++) {
        al_insere_fim(agenda, contatos[i]);
        al_insere_fim(fixa, contatos[i]);
    }

    int total = 0, total_fixa = 0;
    for (int i = 0; i < 5; i++) {
        int custo, custo_fixa;
        al_busca_mtf(agenda, chamadas[i], &custo);
        al_busca(fixa, chamadas[i], &custo_fixa);
        total += custo;
        total_fixa += custo_fixa;
        printf("%-4s custo %d -> ", chamadas[i], custo);
        al_mostra(agenda);
        printf("\n");
    }
    printf("Total: %d comparações (sem ajuste: %d)\n", total, total_fixa);

    al_libera(agenda);
    al_libera(fixa);
    return 0;
}
// Saída:
// Edu  custo 5 -> Edu Ana Bia Caio Duda
// Edu  custo 1 -> Edu Ana Bia Caio Duda
// Caio custo 4 -> Caio Edu Ana Bia Duda
// Edu  custo 2 -> Edu Caio Ana Bia Duda
// Edu  custo 1 -> Edu Caio Ana Bia Duda
// Total: 13 comparações (sem ajuste: 23)
```

Até achar, é a busca de sempre. Depois do "Sim", o nó que não é o primeiro é
religado no início. O verde é Caio, achado na quarta volta:

{{fluxograma}}
