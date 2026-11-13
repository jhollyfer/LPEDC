## 0148 · Union-find: conjuntos disjuntos

- **Conjuntos disjuntos**: grupos que não se misturam, com duas operações
  (CORMEN et al., 2024, cap. 19):
  **acha(x)** devolve o **representante** do grupo de x; **une(a, b)** junta os
  grupos de a e de b. Dois elementos estão juntos se têm o mesmo representante.
- **Floresta num vetor**: `pai[x]` é o pai de x, e a raiz aponta para si mesma
  (`pai[x] == x`); a raiz é o representante. `acha` sobe até a raiz; `une`
  pendura uma raiz na outra (SEDGEWICK; WAYNE, 2011).
- **União por tamanho**: pendure a raiz do grupo **menor** na do maior. Um
  elemento só desce quando o grupo dele pelo menos dobra: altura até log₂ n
  (LINTZMAYER; MOTA, 2023).
- **Compressão de caminho**: depois de achar a raiz, `acha` faz todo o caminho
  apontar **direto** para ela. Por isso consultar **modifica** `pai`.
- **Custo**: com os dois truques, m operações custam O(m · α(n)), e α não passa
  de 4 para nenhum n realista: O(1) amortizado na prática (TARJAN, 1975).
- **No Cormen**: `MAKE-SET`, `FIND-SET` e `UNION`, com **união por posto**
  (*rank*), um limite da altura que só cresce quando dois postos iguais se
  juntam. Mesma garantia; o Kruskal (0152) usa esta estrutura
  (CORMEN et al., 2024, cap. 19).

> [!WARNING]
> O representante é a **raiz**. `pai[a] = b` arranca o `a` do grupo; o certo é
> `pai[acha(a)] = acha(b)`. Testar `pai[a] == pai[b]` falha com mais de um nível:
> o teste é `acha(a) == acha(b)`. E `tam[x]` só vale na raiz.

{{exemplo}}

Oito colegas de uma turma, de 0 (Ana) a 7 (Hugo), e sete amizades: quem se
conhece cai no mesmo sorteio de amigo secreto. Sobram dois grupos, e Duda e Hugo
ficam a dois passos da raiz até as perguntas comprimirem o caminho:

{{ideia}}

`uf_acha` e `uf_une`, em `uniao.c`:

```c
int uf_acha(UF *u, int x) {
    int raiz = x;
    while (u->pai[raiz] != raiz) { // sobe até a raiz
        raiz = u->pai[raiz];
    }
    while (u->pai[x] != raiz) {    // compressão: todo mundo do caminho
        int prox = u->pai[x];      // passa a apontar direto para a raiz
        u->pai[x] = raiz;
        x = prox;
    }
    return raiz;
}

bool uf_une(UF *u, int a, int b) {
    int ra = uf_acha(u, a);
    int rb = uf_acha(u, b);
    if (ra == rb) {
        return false; // já estavam juntos
    }
    if (u->tam[ra] < u->tam[rb]) { // ra fica sendo a raiz do grupo maior
        int t = ra;
        ra = rb;
        rb = t;
    }
    u->pai[rb] = ra; // a raiz do menor vira filha da raiz do maior
    u->tam[ra] += u->tam[rb];
    u->grupos--;
    return true;
}
```

O cliente registra as amizades e mostra `pai` depois de cada uma:

```c
#include <stdio.h>
#include "uniao.h"

int main(void) {
    const char *nome[] = {"Ana", "Beto", "Caio", "Duda", "Edu", "Fia", "Gui", "Hugo"};
    int amizades[][2] = {{0, 1}, {2, 3}, {4, 5}, {1, 3}, {6, 7}, {5, 7}, {0, 2}};
    UF *turma = uf_cria(8);

    for (int i = 0; i < 7; i++) {
        int a = amizades[i][0], b = amizades[i][1];
        bool novo = uf_une(turma, a, b);
        printf("%s e %s: %s | grupos: %d | ", nome[a], nome[b],
               novo ? "juntou" : "já estavam", uf_grupos(turma));
        uf_mostra(turma);
    }
    printf("Ana e Duda se conhecem? %s\n", uf_juntos(turma, 0, 3) ? "sim" : "não");
    printf("Caio e Hugo se conhecem? %s\n", uf_juntos(turma, 2, 7) ? "sim" : "não");
    printf("Grupo do Edu: %d pessoas\n", uf_tamanho(turma, 4));
    printf("Depois das buscas, ");
    uf_mostra(turma);

    uf_libera(turma);
    return 0;
}
// Saída:
// Ana e Beto: juntou | grupos: 7 | pai: 0 0 2 3 4 5 6 7
// Caio e Duda: juntou | grupos: 6 | pai: 0 0 2 2 4 5 6 7
// Edu e Fia: juntou | grupos: 5 | pai: 0 0 2 2 4 4 6 7
// Beto e Duda: juntou | grupos: 4 | pai: 0 0 0 2 4 4 6 7
// Gui e Hugo: juntou | grupos: 3 | pai: 0 0 0 2 4 4 6 6
// Fia e Hugo: juntou | grupos: 2 | pai: 0 0 0 2 4 4 4 6
// Ana e Caio: já estavam | grupos: 2 | pai: 0 0 0 2 4 4 4 6
// Ana e Duda se conhecem? sim
// Caio e Hugo se conhecem? não
// Grupo do Edu: 4 pessoas
// Depois das buscas, pai: 0 0 0 0 4 4 4 4
```

No empate de tamanhos, a raiz de `a` continua raiz. O fluxograma segue `uf_une`
em "Fia e Hugo": as raízes 4 (Edu) e 6 (Gui) têm grupos de 2, e o Gui, com o
Hugo, vira filho do Edu:

{{fluxograma}}
