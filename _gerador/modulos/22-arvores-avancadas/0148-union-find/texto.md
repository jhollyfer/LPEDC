## 0148 · Union-find: conjuntos disjuntos

Numa turma, quem se conhece (ou é "amigo de amigo") cai no mesmo sorteio de amigo
secreto. As amizades chegam aos poucos, e alguém pergunta: "Ana e Duda caem no
mesmo sorteio?".

São **conjuntos disjuntos**: grupos que não se misturam, com duas operações:

- **acha(x)**: devolve o **representante** do grupo de x, um elemento que
  responde pelo grupo. Dois elementos estão juntos se têm o mesmo representante;
- **une(a, b)**: junta o grupo de a com o grupo de b.

O **union-find** guarda cada grupo como uma árvore, e a floresta cabe num vetor:
`pai[x]` é o pai de x, e a raiz aponta para si mesma (`pai[x] == x`). A raiz é o
representante. `acha` sobe até a raiz; `une` acha as duas raízes e pendura uma
na outra.

Do jeito ingênuo, a árvore vira uma fila e `acha` custa O(n). Dois truques
resolvem:

1. **união por tamanho**: guarde o tamanho de cada grupo (`tam[raiz]`) e pendure
   a raiz do grupo **menor** na do maior. Um elemento só desce um nível quando o
   grupo dele pelo menos **dobra**, o que acontece log₂ n vezes no máximo: a
   altura nunca passa de log₂ n;
2. **compressão de caminho**: depois de achar a raiz, `acha` faz todo o caminho
   apontar **direto** para ela.

Com os dois, m operações custam O(m · α(n)), em que α não passa de 4 para nenhum
n realista: na prática, O(1) amortizado (assunto 0116).

O Cormen chama as operações de `MAKE-SET`, `FIND-SET` e `UNION` e usa a **união
por posto** (*rank*): cada raiz guarda um limite superior da altura, que só
ganha 1 quando duas raízes de mesmo posto se juntam. A garantia é a mesma, e o
Kruskal (0152) usa essa estrutura.

No exemplo, oito colegas, de 0 (Ana) a 7 (Hugo), e sete amizades deixam dois
grupos: {Ana, Beto, Caio, Duda} e {Edu, Fia, Gui, Hugo}. Duda e Hugo estão a dois
passos da raiz até as perguntas comprimirem o caminho:

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

Em "Beto e Duda", as raízes são 0 (Ana) e 2 (Caio), ambos com grupo de 2. No
empate, a raiz de a continua raiz: Caio vai para baixo da Ana, com a Duda.

O fluxograma acompanha `uf_une` em "Fia e Hugo". As raízes são 4 (Edu) e 6
(Gui), com grupos de tamanho 2: sem troca, o Gui (com o Hugo) vira filho do Edu:

{{fluxograma}}

> [!WARNING]
> O representante é a **raiz**, não o elemento. Unir com `pai[a] = b` arranca o
> `a` do grupo e leva só os descendentes dele; o certo é
> `pai[acha(a)] = acha(b)`. Testar `a == b` ou `pai[a] == pai[b]` falha com mais
> de um nível; o teste é `acha(a) == acha(b)`. E `tam[x]` só vale na raiz.

> [!TIP]
> `uf_acha` não tem `const`: **consultar modifica** a estrutura, porque a
> compressão reescreve `pai`.

> [!NOTE]
> **Pergunta para você:** depois de tudo, Ana e Hugo ficam amigos:
> `uf_une(turma, 0, 7)`. Os dois grupos têm 4 pessoas. Quem vira a raiz do grupo
> único e como fica o vetor `pai`? Acrescente a linha no exemplo e confira.

{{pratique}}
