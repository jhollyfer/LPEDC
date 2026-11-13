## 0163 · Skip list

- **Skip list**: lista ordenada (0078) com linhas expressas, os **andares**. O
  andar 0 é a lista completa; o 1 tem parte dos nós, o 2 menos ainda
  (PUGH, 1990).
- **Nó**: um vetor `prox`, em que `prox[k]` é o próximo no andar `k`. Uma
  **cabeça** sem chave está em todos os andares e começa toda busca
  (MORIN, 2013, cap. 4).
- **Buscar**: comece no andar mais alto. Se o próximo é menor que a chave,
  avance; se passou ou não existe, desça. No andar 0, o próximo é a chave ou ela
  não existe.
- **Moeda**: todo nó novo entra no andar 0 e sobe mais um enquanto der cara.
  Metade chega ao andar 1, um quarto ao 2, sem nunca arrumar nada (PUGH, 1990).
- **Inserir**: buscar guardando, em cada andar, o último nó antes de descer (o
  vetor `antes`); depois ligar o nó novo após `antes[k]` em cada andar. A
  remoção usa o mesmo vetor (SEDGEWICK, 1998, cap. 13).
- **Custo**: **O(log n) esperado**, na média dos sorteios, sem garantia. Com 1
  milhão de chaves, uns 40 nós por busca.
- **Memória**: com `prox[SKIP_MAX]` todo nó tem 104 bytes. Um **membro vetor
  flexível** (`struct NoSkip *prox[];`) aloca só os andares usados
  (CPPREFERENCE, s.d.).

> [!WARNING]
> Na remoção, o nó sai de **todos** os andares. Se o 23 sair só do andar 0 e
> for liberado, a cabeça ainda aponta para ele no andar 2: ponteiro solto
> (assunto 0057). O E976 pede essa remoção.

{{exemplo}}

As paradas de uma rodovia, nos km 5 a 56, entram com andares prontos: o 23 e o
56 em 3, o 12 e o 40 em 2, os outros só no 0. A busca pelo 47 anda no andar 2
até o 23, desce, anda até o 40, desce, e o próximo no andar 0 é o 47:

{{ideia}}

O TAD fica em `skip.h` e `skip.c`. O nó e a busca:

```c
#define SKIP_MAX 12 // andares no máximo: dá para uns 4 mil nós (2 elevado a 12)

typedef struct NoSkip {
    int chave;
    int andares;                   // em quantos andares o nó aparece
    struct NoSkip *prox[SKIP_MAX]; // prox[k]: o próximo no andar k
} NoSkip;

bool skip_busca(const Skip *s, int chave, int *passos) {
    int olhados = 0;
    const NoSkip *x = &s->cabeca;
    for (int k = s->andares - 1; k >= 0; k--) { // do andar mais alto ao 0
        while (x->prox[k] != NULL) {
            olhados++;
            if (x->prox[k]->chave >= chave) {
                break; // o próximo já passou (ou é a chave): desce
            }
            x = x->prox[k]; // o próximo ainda é menor: avança
        }
    }
    if (passos != NULL) {
        *passos = olhados;
    }
    x = x->prox[0]; // no andar 0, o próximo é a chave ou ela não existe
    return x != NULL && x->chave == chave;
}
```

Para o desenho sair igual em toda execução, o exemplo usa
`skip_insere_andares`, com andares prontos; no uso normal, `skip_insere` joga
a moeda. O `skip_mostra` imprime cada chave sempre na mesma coluna:

```c
#include <stdio.h>
#include "skip.h"

void procura(const Skip *s, int km) {
    int passos;
    bool achou = skip_busca(s, km, &passos);
    printf("km %d: %s, %d nós olhados\n", km, achou ? "tem parada" : "não tem parada", passos);
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3}; // o que a moeda "deu"
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    skip_mostra(linha);
    procura(linha, 47);
    procura(linha, 20);

    skip_libera(linha);
    return 0;
}
// Saída:
// andar 2:              23              56
// andar 1:      12      23      40      56
// andar 0:   5  12  18  23  31  40  47  56
// km 47: tem parada, 5 nós olhados
// km 20: não tem parada, 5 nós olhados
```

O laço de dentro avança no andar, o de fora desce. O caminho verde é a busca
do 47: uma vez no andar 2, uma no andar 1, nenhuma no andar 0:

{{fluxograma}}
