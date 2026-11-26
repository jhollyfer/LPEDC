## 0127 · Backtracking

A enumeração dos assuntos 0125 e 0126 visita tudo, inclusive o que já nasceu
perdido. Imagine um cartão-presente de R$ 35 que não dá troco: ou você gasta o
valor exato, ou o resto se perde. Na vitrine há um atlas de R$ 30, um mangá de
R$ 20, um livro de poesia de R$ 15 e um marcador de R$ 5. Você quer as
combinações que fecham R$ 35. Bastaria testar os 2⁴ = 16 subconjuntos, só que
atlas e mangá juntos já somam R$ 50, e a enumeração cega continua testando
todo subconjunto que começa assim, como se ainda houvesse chance.

O **backtracking**, que também se chama retrocesso ou **tentativa e erro**, é
a enumeração que **desiste cedo**. A cada escolha, ele pergunta se o começo
montado até ali ainda pode virar uma solução. Se não pode, volta um passo e
tenta outra coisa, sem completar o que já está condenado (ZIVIANI, 2010,
cap. 2).

Na árvore de decisões, desistir cedo tem um efeito grande. Cada nó tem abaixo
dele uma subárvore inteira de possibilidades, e voltar daquele nó descarta
todas de uma vez. Cortar um galho inteiro sem visitá-lo se chama **poda**
(WIRTH, 1989). Quanto mais perto da raiz a poda acontece, mais folhas ela
elimina.

Todo backtracking segue o mesmo esqueleto, com três partes, nesta ordem
(FEOFILOFF, 2009). Primeiro, o **caso de parada**: a solução está completa? Se
está, mostre ou conte e volte. Segundo, a **poda**: o começo já é inviável? Se
é, volte sem descer. Terceiro, a **escolha**: para cada opção disponível,
escolha, desça com uma chamada recursiva e, na volta, **desfaça** a escolha,
como nas permutações.

O problema do cartão é um caso clássico, a **soma de subconjuntos**: achar
quais itens de uma lista somam exatamente um valor-alvo (FEOFILOFF, 2009). A
poda vem de uma propriedade dos dados. Os preços são positivos, então
acrescentar um item só aumenta a soma. Se a soma **passou** de 35, nenhum item
a mais conserta, e o galho pode ser cortado. E se a soma bateu
**exatamente** 35, a solução está pronta, e também não há por que descer. Com
atlas e mangá na cesta, a soma de 50 corta de uma vez os quatro subconjuntos
que começam com os dois.

Assim como nos subconjuntos, a volta precisa deixar o estado como estava. O
que é **parâmetro**, como a soma acumulada, se desfaz sozinho: cada chamada tem
a sua cópia, e voltar devolve o valor anterior. O que é global, como o vetor
`leva[]` que marca os itens escolhidos, é um só para todas as chamadas e
precisa ser desfeito à mão: `leva[i] = false` antes de tentar o caminho sem o
item (KERNIGHAN; RITCHIE, 1989).

A poda não muda a garantia de pior caso. Se os dados forem desfavoráveis, ela
quase não corta nada, e o backtracking continua **O(2ⁿ)**. O que muda é quanto
da árvore você visita na prática, e em muitos problemas a diferença é enorme
(ROVAI, 2018).

> [!WARNING]
> A poda só corta o que **com certeza** não leva a solução. Poda com `>=` no
> lugar de `>` descarta as somas que batem o alvo, e a saída fica vazia. A
> ordem dos testes também importa: teste "fechou" antes de "acabaram os itens".

{{exemplo}}

Um cartão-presente de R$ 35 não dá troco. Na vitrine: atlas (R$ 30), mangá
(R$ 20), poesia (R$ 15) e marcador (R$ 5). Na árvore, a esquerda leva o item;
caixas vermelhas são podas, verdes são soluções e cinzas, becos sem saída:

{{ideia}}

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

A árvore completa de 4 itens tem 31 nós, e a poda deixou 21. Com 30 itens e um
alvo pequeno, são alguns milhares de chamadas em vez de um bilhão:

{{fluxograma}}
