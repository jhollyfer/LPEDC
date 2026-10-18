## 0163 · Skip list

A linha de ônibus da rodovia tem paradas nos km 5, 12, 18, 23, 31, 40, 47 e 56.
O ônibus **parador** para em todas. O **semidireto** só em algumas, e o
**direto** só nas principais. Quem vai para o km 47 não pega o parador desde o
começo: vai de direto até onde der sem passar do destino, troca para o
semidireto, e só no fim pega o parador.

Uma lista encadeada ordenada (assunto 0078) é o ônibus parador. Para achar uma
chave, você passa por todas as anteriores: O(n). A busca binária não serve,
porque lista não tem índice: não dá para pular para o meio. A BST e a AVL
(módulo 14) resolvem isso, mas trocam a lista por uma árvore com rotações.

A **skip list** fica com a lista e acrescenta as linhas expressas. Ela tem vários
**andares**. O andar 0 é a lista completa, em ordem. O andar 1 é uma lista com
só parte dos nós, o andar 2 com menos ainda, e assim por diante. Cada nó tem um
vetor de ponteiros `prox`: `prox[0]` é o próximo no andar 0, `prox[1]` o próximo
no andar 1, `prox[k]` o próximo no andar `k`. Uma **cabeça** sem chave está em todos os andares
e é por onde toda busca começa.

**Buscar** é a viagem de ônibus. Comece no andar mais alto da cabeça. Se o
próximo nó do andar ainda é menor que a chave, avance. Se ele já passou da chave
(ou não existe), desça um andar. No andar 0, o próximo nó é a chave ou ela não
existe.

E quem decide em quais andares cada nó aparece? Se fosse "um nó sim, um não"
em cada andar, a busca seria uma busca binária, mas qualquer inserção quebraria o
padrão e obrigaria a refazer tudo. A skip list usa uma **moeda**: todo nó novo
entra no andar 0; enquanto a moeda der cara, ele sobe mais um andar. Em média,
metade dos nós chega ao andar 1, um quarto ao andar 2, um oitavo ao andar 3. É o
padrão "um sim, um não" sem nunca precisar arrumar nada.

**Inserir** é buscar guardando, em cada andar, o último nó visitado antes de
descer (o vetor `antes`). Depois sorteie os andares do nó novo e ligue-o depois
de `antes[k]` em cada andar `k` dele. A remoção usa o mesmo vetor para desligar
o nó em todos os andares.

O custo é **O(log n) esperado**: com 1 milhão de chaves, cerca de 20 andares e uns
40 nós olhados por busca, contra meio milhão em média na lista simples. "Esperado"
quer dizer na média dos sorteios, não garantido: uma sequência de azar absurda
poderia deixar todos os nós no andar 0. Na prática, isso não acontece.

Vamos ver na prática. As oito paradas entram com os andares que a moeda "deu":
o 23 e o 56 em 3 andares, o 12 e o 40 em 2, os outros só no andar 0. A busca
pelo 47 anda no andar 2 até o 23 (o próximo, 56, já passou), desce, anda até o
40, desce, e o próximo no andar 0 é o 47:

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

Para o desenho ficar igual em toda execução, o exemplo usa
`skip_insere_andares`, que recebe os andares prontos. No uso normal, `skip_insere`
joga a moeda sozinha. O `skip_mostra` imprime cada chave sempre na mesma coluna:

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

Repara no fluxograma: são dois laços, um dentro do outro. O de dentro avança no
andar; o de fora desce. O caminho verde é a busca do 47: avança uma vez no andar
2, uma no andar 1, nenhuma no andar 0, e o próximo é o 47:

{{fluxograma}}

> [!WARNING]
> Na remoção, o nó tem que sair de **todos** os andares em que aparece, não só do
> andar 0. Se o 23 for removido só do andar 0 e liberado com `free`, a cabeça
> continua apontando para ele no andar 2, e o 12 no andar 1. A próxima busca entra
> num nó que não existe mais: é um ponteiro solto (assunto 0057), e o
> AddressSanitizer acusa *heap-use-after-free*. O exercício E976 traz esse bug.

> [!TIP]
> **Por dentro do C:** com `prox[SKIP_MAX]`, todo nó ocupa 4 + 4 + 12 × 8 = 104
> bytes, mesmo que use só 1 ou 2 ponteiros (a média é 2). Dá para alocar só o
> necessário com um **membro vetor flexível**, `struct NoSkip *prox[];` no fim da
> struct, e `malloc(sizeof(NoSkip) + andares * sizeof(NoSkip *))`: o exercício
> E978 faz essa troca. E a moeda? `skip.c` não usa `rand`: tem um gerador próprio
> de uma linha (`semente = semente * 1103515245u + 12345u`). Cada biblioteca C
> implementa `rand` de um jeito, e com o gerador próprio a mesma semente monta a
> mesma skip list em qualquer máquina, o que deixa os testes repetíveis.

> [!NOTE]
> **Pergunta para você:** se o km 35 entrar com 2 andares, quais ponteiros mudam?
> Quem fica em `antes[0]` e em `antes[1]`? Desenhe antes de conferir com
> `skip_insere_andares` e `skip_mostra`.

{{pratique}}
