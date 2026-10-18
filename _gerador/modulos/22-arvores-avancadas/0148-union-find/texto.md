## 0148 · Union-find: conjuntos disjuntos

A turma do cursinho vai fazer amigo secreto, mas por panelinha: quem se conhece
fica no mesmo sorteio, e "amigo de amigo" também conta. As amizades chegam aos
poucos no grupo de mensagens: Ana conhece Beto, Caio conhece Duda, Beto conhece
Duda... A cada nova amizade, dois grupos podem virar um só. E a qualquer
momento alguém pergunta: "Ana e Duda caem no mesmo sorteio?".

O problema tem nome: **conjuntos disjuntos**. Os elementos estão divididos em
grupos que não se misturam, e só existem duas operações:

- **acha(x)**: devolve o **representante** do grupo de x, um elemento que
  responde pelo grupo inteiro. Dois elementos estão juntos se têm o mesmo
  representante;
- **une(a, b)**: junta o grupo de a com o grupo de b.

A estrutura que faz isso é o **union-find**. Cada grupo é uma árvore, e a
floresta inteira cabe num vetor: `pai[x]` é o pai de x, e a raiz é quem aponta
para si mesmo (`pai[x] == x`). A raiz é o representante. `acha` sobe pelos
pais até a raiz; `une` acha as duas raízes e pendura uma na outra. Repare que
aqui as setas vão do filho para o pai: ninguém precisa descer na árvore.

Do jeito ingênuo, a árvore pode virar uma fila indiana, e `acha` passa a custar
O(n). Dois truques resolvem:

1. **união por tamanho**: guarde o tamanho de cada grupo (`tam[raiz]`) e
   pendure sempre a raiz do grupo **menor** na do maior. Um elemento só desce um
   nível quando o grupo dele se junta a outro pelo menos do mesmo tamanho, ou
   seja, quando o grupo pelo menos **dobra**. Isso só acontece log₂ n vezes:
   a altura nunca passa de log₂ n;
2. **compressão de caminho**: depois de achar a raiz, `acha` faz todo mundo do
   caminho apontar **direto** para ela. A próxima busca por qualquer um deles
   sobe um passo só.

Com os dois juntos, uma sequência de m operações custa O(m · α(n)), em que α é
uma função que cresce tão devagar que não passa de 4 para nenhum n que caiba
num computador. Na prática, cada operação é O(1) amortizado (a ideia de custo
amortizado é do assunto 0116).

Vamos ver na prática. Oito colegas, de 0 (Ana) a 7 (Hugo), e sete amizades. No
fim sobram dois grupos: {Ana, Beto, Caio, Duda} e {Edu, Fia, Gui, Hugo}. Duda e
Hugo estão a dois passos da raiz; as perguntas sobre eles comprimem o caminho e
os deixam pendurados direto no representante:

{{ideia}}

O `acha` e o `une` do `uniao.c`:

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

O cliente registra as amizades e mostra o vetor `pai` depois de cada uma:

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

Em "Beto e Duda", as raízes são 0 (Ana, grupo de 2) e 2 (Caio, grupo de 2).
Empate: a raiz de a continua raiz, e o Caio vai para baixo da Ana, levando a
Duda junto. A Duda fica a dois passos da raiz até a pergunta "Ana e Duda?"
subir por ela e comprimir o caminho.

Repara no fluxograma: é o `uf_une` de "Fia e Hugo". As raízes são 4 (Edu) e 6
(Gui), diferentes; os dois grupos têm tamanho 2, então não há troca, e o Gui
(com o Hugo embaixo) vira filho do Edu:

{{fluxograma}}

> [!WARNING]
> O representante é a **raiz**, não o elemento. Três erros vêm daí. Unir com
> `pai[a] = b` arranca o `a` do grupo dele e leva só os descendentes de `a`
> junto (é o bug do E887); o certo é `pai[acha(a)] = acha(b)`. Testar `a == b`
> ou `pai[a] == pai[b]` para saber se estão juntos falha assim que as árvores
> têm mais de um nível; o teste é `acha(a) == acha(b)`. E `tam[x]` só vale na
> raiz: num elemento que já foi raiz, ele guarda o tamanho antigo do grupo.

> [!TIP]
> **Por dentro do C:** a floresta inteira são dois vetores de `int`, sem um
> ponteiro sequer: 8 bytes por elemento, 8 MB para um milhão de pessoas, tudo
> contíguo na memória (o cache do processador agradece). Repare na assinatura
> `int uf_acha(UF *u, int x)`: sem `const`, porque **consultar modifica** a
> estrutura (a compressão reescreve `pai`). Até `uf_juntos`, que parece só uma
> pergunta, mexe no vetor. O A295 mede o efeito dos truques: com 10 mil
> elementos, a versão ingênua sobe 50 milhões de vezes pelos pais; com união por
> tamanho, nenhuma vez durante as uniões.

> [!NOTE]
> **Pergunta para você:** depois de tudo, Ana e Hugo ficam amigos:
> `uf_une(turma, 0, 7)`. Os dois grupos têm 4 pessoas. Quem vira a raiz do
> grupo único e como fica o vetor `pai`? Acrescente a linha no exemplo e
> confira.

{{pratique}}
