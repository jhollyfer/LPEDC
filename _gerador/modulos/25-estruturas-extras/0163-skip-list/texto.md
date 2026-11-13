## 0163 · Skip list

Uma rodovia tem paradas de ônibus nos km 5, 12, 18, 23, 31, 40, 47 e 56. O
ônibus **parador** para em todas; o **semidireto** para em algumas; o
**direto**, só nas principais. Para chegar ao km 47, você não pega o
parador desde o começo. Vai de direto até onde der sem passar do 47, troca
para o semidireto e só no fim pega o parador.

Uma lista ordenada (assunto 0078) é o ônibus parador: achar uma chave custa
O(n), porque é preciso passar por todos os nós anteriores. A busca binária
não serve, já que a lista não tem índice para pular ao meio. A BST e a AVL
(módulo 14) resolvem isso trocando a lista por uma árvore e equilibrando-a
com rotações.

A **skip list** resolve de outro jeito: fica com a lista ordenada e
acrescenta as linhas expressas, os **andares** (PUGH, 1990). O andar 0 é a
lista completa, com todos os nós. O andar 1 liga só parte deles, o andar 2
menos ainda, e assim por diante. Cada nó, em vez de um único ponteiro
`prox`, tem um vetor deles: `prox[k]` é o próximo nó no andar `k`. Uma
**cabeça**, um nó sem chave, está em todos os andares e é o ponto de
partida de toda busca (MORIN, 2013, cap. 4).

**Buscar** é a viagem de ônibus. Comece na cabeça, no andar mais alto. Olhe
o próximo nó do andar. Se a chave dele é menor que a procurada, avance para
ele. Se ela já passou da procurada, ou se não há próximo, desça um andar e
repita. Quando chegar ao andar 0 e não puder mais avançar, o próximo nó é a
chave procurada ou ela não existe. Com as paradas acima, procurar o 47 anda
no andar 2 até o 23 (o próximo, 56, já passou), desce, anda até o 40 no
andar 1, desce, e no andar 0 o próximo é o 47.

E quem decide em quantos andares cada nó aparece? Uma **moeda** (PUGH,
1990). Todo nó novo entra no andar 0 e, enquanto der cara, sobe mais um.
Em média, metade dos nós chega ao andar 1, um quarto ao andar 2, um oitavo
ao andar 3. Isso imita os andares de uma lista "perfeita", em que cada
andar tem metade dos nós do de baixo, só que sem nunca reorganizar nada.

**Inserir** começa por uma busca, com um cuidado: em cada andar, guarde o
último nó visitado antes de descer. Esses nós ficam num vetor `antes`, e
`antes[k]` é o nó depois do qual o novo entra no andar `k`. Depois, sorteie
os andares do nó novo e ligue-o após `antes[k]` em cada um, como numa
inserção em lista comum. A remoção usa o mesmo vetor para desligar o nó de
cada andar (SEDGEWICK, 1998, cap. 13).

O custo é **O(log n) esperado**. "Esperado" quer dizer na média dos
sorteios da moeda: uma sequência de azar pode deixar a lista ruim, mas é
muito improvável. Com 1 milhão de chaves, a busca olha uns 40 nós, contra
meio milhão na lista simples. A AVL dá garantia de pior caso; a skip list
troca essa garantia por um código sem rotações.

Falta a memória. Se o nó declara `prox[SKIP_MAX]` com `SKIP_MAX` 12, todo
nó ocupa 104 bytes, mesmo usando em média 2 ponteiros. A saída é um
**membro vetor flexível**: o último campo da struct é declarado sem
tamanho, `struct NoSkip *prox[];`, e o `malloc` pede só o necessário,
`sizeof(NoSkip) + andares * sizeof(NoSkip *)` (CPPREFERENCE, s.d.).

> [!WARNING]
> Na remoção, o nó sai de **todos** os andares em que aparece. Se o 23 sair
> só do andar 0 e for liberado, a cabeça continua apontando para ele no andar
> 2: ponteiro solto (assunto 0057). O E976 pede essa remoção.

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
