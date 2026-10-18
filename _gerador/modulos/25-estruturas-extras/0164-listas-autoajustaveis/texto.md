## 0164 · Listas autoajustáveis

Na cozinha, o sal e o óleo ficam na frente do armário, e o cravo que você usa uma
vez por ano fica lá no fundo. Ninguém planejou isso: cada vez que você usa um
pote, ele volta para a frente. Com o tempo, o armário se arruma sozinho pelo uso.

A busca sequencial (assunto 0089) custa a **posição** do item: o primeiro sai com
1 comparação, o décimo com 10. Se todo item fosse procurado com a mesma
frequência, a ordem não faria diferença. Mas quase nunca é assim: na agenda do
celular, meia dúzia de contatos recebe quase todas as ligações. Se eles
estivessem na frente, a busca média cairia muito.

O problema é que você não sabe de antemão quem são os mais procurados, e isso
muda com o tempo. A **lista autoajustável** descobre sozinha: a cada busca
bem-sucedida, ela muda a ordem para aproximar o item achado do começo. A busca
deixa de ser só leitura; ela também arruma. Há três políticas clássicas:

- **mover para a frente** (*move-to-front*): o item achado vira o primeiro.
  Reage rápido, mas um item procurado uma única vez também vai parar na frente;
- **transposição**: o item achado troca de lugar com o anterior, subindo uma
  casa por acesso. É conservadora: um acesso isolado quase não bagunça a lista,
  mas um item popular demora para chegar à frente;
- **contagem**: cada nó guarda quantas vezes foi achado, e a lista fica em ordem
  decrescente de acessos. Converge para a melhor ordem fixa, mas gasta um campo
  a mais e se apega ao passado: um item que foi popular demora a descer.

Mover para a frente combina com **lista encadeada**: achado o nó, tirá-lo do lugar
e pendurá-lo no início são três atribuições de ponteiro. Num vetor, seria
preciso empurrar todos os anteriores uma casa para trás. Já a transposição é uma
troca de dois vizinhos e funciona bem nos dois.

Vamos ver na prática. A agenda tem Ana, Bia, Caio, Duda e Edu, nessa ordem. As
ligações do dia são para Edu, Edu, Caio, Edu e Edu. Na terceira, Caio é achado na
quarta comparação e passa para a frente; Edu, que estava em primeiro, desce para
o segundo lugar:

{{ideia}}

O TAD fica em `autolista.h` e `autolista.c`, com as três políticas e uma busca
que não mexe em nada (`al_busca`), para comparar. Mover para a frente é a busca da
lista com o par `ant` e `p` (assunto 0077) e três linhas no fim:

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

O programa faz as cinco ligações em duas agendas iguais, uma que se ajusta e uma
fixa, e soma as comparações:

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

Repara no fluxograma: até achar, é a busca sequencial de sempre. A diferença está
depois do "Sim": se o nó não é o primeiro, ele é desligado e religado no início.
O caminho verde é a chamada para Caio, achado na quarta volta:

{{fluxograma}}

> [!WARNING]
> O caso do **primeiro nó** pega todo mundo. Se o nó achado já é o primeiro,
> `ant` é `NULL`, e `ant->prox = p->prox` derruba o programa (o exercício E982
> traz esse bug). E se você esquecer `l->inicio = p`, o nó achado sai do lugar
> mas ninguém aponta para ele: ele some da lista e vaza memória. Por isso a
> função recebe `AutoLista *` e não `const`: a busca muda o começo da lista.

> [!TIP]
> **Por dentro do C:** mover para a frente custa três atribuições de ponteiro,
> 8 bytes cada, não importa onde o nó estava; os nomes (20 bytes cada) nunca
> saem do lugar na memória. No vetor, levar o décimo item para a frente obriga a
> copiar os nove anteriores, e cada cópia move a struct inteira (o exemplo A327
> conta isso). A contagem custa um `int` a mais por nó e, a cada acesso, uma
> caminhada extra para reinserir o nó no lugar certo. E existe um resultado
> famoso (Sleator e Tarjan, 1985): mover para a frente nunca gasta mais que o
> dobro da melhor ordem fixa, aquela escolhida por quem já conhece todas as
> buscas de antemão.

> [!NOTE]
> **Pergunta para você:** com as mesmas cinco ligações, quanto custaria a
> **transposição**? E se as ligações fossem Ana, Bia, Caio, Duda, Edu, Ana, Bia,
> Caio, Duda, Edu, qual política sairia pior? Confira com `al_busca_transpoe`.

{{pratique}}
