## 0164 · Listas autoajustáveis

- **Custo da busca sequencial** (0089): a **posição** do item. Se poucos itens
  levam quase todas as buscas, a ordem importa.
- **Lista autoajustável**: a cada busca bem-sucedida, aproxima o item achado do
  começo; a busca também escreve na lista (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Mover para a frente** (*move-to-front*): o item achado vira o primeiro.
  Reage rápido, mas um acesso isolado também vai para a frente
  (CORTÉS, 2015).
- **Transposição**: o item troca de lugar com o anterior. Bagunça pouco, mas um
  item popular demora a chegar à frente (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Contagem**: cada nó guarda quantas vezes foi achado, e a lista fica em
  ordem decrescente. Converge para a melhor ordem fixa, com um campo a mais.
- **Lista ou vetor**: mover para a frente numa lista são três atribuições; num
  vetor, copia todos os anteriores (A327). A transposição serve aos dois.
- **Garantia**: mover para a frente nunca gasta mais que o dobro da melhor ordem
  fixa escolhida por quem conhece as buscas de antemão
  (SLEATOR; TARJAN, 1985; CORMEN et al., 2024, cap. 27).

> [!WARNING]
> Se o nó achado já é o primeiro, `ant` é `NULL` e `ant->prox = p->prox`
> derruba o programa (E982). Sem `l->inicio = p`, o nó some da lista e vaza.

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
