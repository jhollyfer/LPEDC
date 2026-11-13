## 0106 · Encadeamento

- **Encadeamento** (ou encadeamento separado): cada balde guarda a **cabeça
  de uma lista encadeada** com os itens que caíram ali. A tabela vira um vetor
  de ponteiros, `No *baldes[m]` (CORMEN et al., 2024, cap. 11).
- **Operações**: calcule `i = hash(chave) % m` e use a lista de `baldes[i]`
  (módulo 11). Inserir procura a chave; se não achar, põe um nó **no início**
  em O(1). Buscar e remover andam só nessa lista (CELES; RANGEL, 2002).
- **Custo médio**: com hash que espalha bem, cada lista tem em média α nós e
  a busca custa Θ(1 + α). Se `m` cresce com `n`, α fica constante e a busca é
  O(1) na média (CORMEN et al., 2024, cap. 11).
- **Pior caso**: um hash ruim joga tudo num balde, a tabela vira uma lista só
  e a busca é O(n) (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Nunca enche**: α pode passar de 1 (exemplo A211: 8 itens em 2 baldes)
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Liberar**: cada nó é um `malloc`. `tabela_libera` dá `free` em todos,
  guardando o `prox` antes; `free(t->baldes)` sozinho vaza as listas
  (CELES; CERQUEIRA; RANGEL, 2016).

> [!WARNING]
> Compare chave de texto com `strcmp`, nunca com `==`: `p->chave == chave`
> compara **endereços**. O nó guarda a sua **cópia** da chave, porque o buffer
> de quem chamou é reaproveitado.

{{exemplo}}

O hortifrúti guarda o estoque em 5 baldes, com o hash polinomial do 0105.
Banana, uva, pera, kiwi, manga e caju caem em 4, 2, 4, 1, 1 e 4; cada nova
entra no início. Buscar "kiwi" vai ao balde 1 e faz 2 comparações:

{{ideia}}

A estrutura segue o padrão TAD: `tabela.h` com a interface e o tipo opaco,
`tabela.c` com o nó, os baldes e as operações:

```c
typedef struct No {
    char chave[TAM_CHAVE]; // cópia da chave (não um ponteiro emprestado)
    int valor;
    struct No *prox;
} No;

struct Tabela {
    int m;       // número de baldes
    int n;       // número de itens
    No **baldes; // vetor de m cabeças de lista
};

bool tabela_busca(const Tabela *t, const char *chave, int *valor, int *comparacoes) {
    int i = (int)(hash(chave) % (unsigned)t->m);
    int olhados = 0;
    for (No *p = t->baldes[i]; p != NULL; p = p->prox) {
        olhados++;
        if (strcmp(p->chave, chave) == 0) {
            *valor = p->valor;
            if (comparacoes != NULL) {
                *comparacoes = olhados;
            }
            return true;
        }
    }
    if (comparacoes != NULL) {
        *comparacoes = olhados;
    }
    return false;
}
```

O cliente conhece só o `tabela.h`:

```c
#include <stdio.h>
#include "tabela.h"

int main(void) {
    Tabela *estoque = tabela_cria(5);
    if (estoque == NULL) {
        return 1;
    }
    const char *frutas[] = {"banana", "uva", "pera", "kiwi", "manga", "caju"};
    int caixas[] = {12, 30, 8, 5, 20, 14};
    for (int i = 0; i < 6; i++) {
        tabela_insere(estoque, frutas[i], caixas[i]);
    }
    tabela_mostra(estoque);

    int qtd, olhados;
    if (tabela_busca(estoque, "kiwi", &qtd, &olhados)) {
        printf("kiwi: %d caixas (%d comparações)\n", qtd, olhados);
    }
    if (!tabela_busca(estoque, "limao", &qtd, &olhados)) {
        printf("limao: não tem (%d comparações)\n", olhados);
    }
    tabela_libera(estoque);
    return 0;
}
// Saída:
// [0]
// [1] -> manga:20 -> kiwi:5
// [2] -> uva:30
// [3]
// [4] -> caju:14 -> pera:8 -> banana:12
// kiwi: 5 caixas (2 comparações)
// limao: não tem (0 comparações)
```

No fluxograma da busca, o hash leva ao balde e o resto é o laço de lista. O
"kiwi" dá uma volta (passa pela manga) e para no Sim; o "limao" cai no balde
0, vazio, e sai pelo Não:

{{fluxograma}}
