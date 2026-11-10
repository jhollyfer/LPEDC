## 0127 · Backtracking

Um cartão-presente de R$ 35 não dá troco: ou você gasta o valor exato, ou o
resto se perde. Na vitrine há um atlas (R$ 30), um mangá (R$ 20), um livro de
poesia (R$ 15) e um marcador (R$ 5). Que combinações fecham R$ 35?

Pelo assunto 0125, bastaria somar os 2⁴ = 16 subconjuntos. Mas atlas e mangá
já somam R$ 50, e a enumeração cega continua até o fim de cada subconjunto que
começa assim.

O **backtracking** (retrocesso; o Ziviani chama de **tentativa e erro**) é a
enumeração que **desiste cedo**: a cada escolha, pergunta se o começo ainda
pode virar solução e, se não, volta um passo. Cortar um galho inteiro da
árvore de decisões se chama **poda**. O esqueleto tem três partes:

1. **caso de parada**: a solução está completa? Mostre (ou conte) e volte;
2. **poda**: o começo já é inviável? Volte sem descer;
3. **escolha**: para cada opção, escolha, desça e **desfaça**.

Aqui os preços são positivos: se a soma **passou** de 35, acrescentar itens só
piora, e se bateu **exatamente** 35, também não precisa descer. Na árvore, a
esquerda leva o item e a direita não. As caixas vermelhas são podas, as verdes
são soluções e as cinzas são becos sem saída (os itens acabaram antes de a soma
chegar a 35):

{{ideia}}

A poda é o primeiro `if`: a chamada que passou do alvo volta na hora:

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4
#define ALVO 35

const char *itens[N] = {"atlas", "mangá", "poesia", "marcador"};
const int precos[N] = {30, 20, 15, 5}; // reais
bool leva[N];
int chamadas = 0;

// já decidiu os itens 0..i-1, que somam soma reais
void tenta(int i, int soma) {
    chamadas++;
    if (soma > ALVO) {
        return;                         // poda: passou, nada abaixo serve
    }
    if (soma == ALVO) {                 // fechou: mostra e não desce mais
        printf("R$ %d:", soma);
        for (int j = 0; j < i; j++) {
            if (leva[j]) {
                printf(" %s", itens[j]);
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;                         // acabaram os itens sem fechar
    }
    leva[i] = true;                     // tenta com o item i
    tenta(i + 1, soma + precos[i]);
    leva[i] = false;                    // volta e tenta sem ele
    tenta(i + 1, soma);
}

int main(void) {
    tenta(0, 0);
    printf("%d chamadas (sem poda seriam 31)\n", chamadas);
    return 0;
}
// Saída:
// R$ 35: atlas marcador
// R$ 35: mangá poesia
// 21 chamadas (sem poda seriam 31)
```

A árvore completa de 4 itens tem 31 nós, e a poda deixou 21. O ganho cresce
com `n`: uma poda perto da raiz corta metade da árvore, e com 30 itens e um
alvo pequeno são alguns milhares de chamadas em vez de um bilhão:

{{fluxograma}}

> [!WARNING]
> A ordem dos testes importa. Com `if (i == N) return;` **antes** de
> `if (soma == ALVO)`, a solução que fecha com o último item (`atlas
> marcador`, com `i` valendo 4) seria descartada. Poda com `>=` no lugar de
> `>` corta toda soma que bate o alvo, e a saída fica vazia. A poda só pode
> cortar o que **com certeza** não leva a solução.

> [!TIP]
> **Por dentro do C:** a soma é **parâmetro**, e voltar a desfaz de graça;
> `leva[]` é global, por isso `leva[i] = false` antes do segundo caminho. O
> pior caso continua **O(2ⁿ)**: a poda muda o quanto da árvore você visita, não
> a garantia.

> [!NOTE]
> **Pergunta para você:** se o cartão fosse de R$ 50, quais combinações
> sairiam? A primeira linha da saída ainda seria a do atlas?

{{pratique}}
