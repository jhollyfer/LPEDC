## 0127 · Backtracking

Você ganhou um cartão-presente de R$ 35 da livraria do bairro, e o cartão não
dá troco: ou você gasta o valor exato, ou o resto fica perdido. Na vitrine há
um atlas (R$ 30), um mangá (R$ 20), um livro de poesia (R$ 15) e um marcador
de página (R$ 5). Que combinações fecham exatamente R$ 35?

Dá para resolver com o assunto 0125: gerar os 2⁴ = 16 subconjuntos, somar
cada um e ficar com os que dão 35. Só que isso desperdiça trabalho. Escolheu o
atlas e o mangá? Já são R$ 50. Nenhum subconjunto que comece assim pode dar
certo, e mesmo assim a enumeração cega vai até o fim de cada um deles.

O **backtracking** (retrocesso) é a enumeração que **desiste cedo**. Ela
constrói a solução uma escolha por vez, como antes. Mas, a cada passo,
pergunta: "este começo ainda pode virar uma solução?". Se não pode, ela nem
desce: volta um passo e tenta a próxima opção. Cortar um galho inteiro da
árvore de decisões assim se chama **poda**.

O esqueleto é sempre o mesmo, e você já viu as três primeiras partes:

1. **caso de parada**: a solução está completa? Mostre (ou conte) e volte;
2. **poda**: o começo já é inviável? Volte sem descer;
3. **escolha**: para cada opção, escolha, desça e **desfaça**.

Neste problema, a poda é simples: os preços são positivos, então se a soma
**passou** de 35, acrescentar mais itens só piora. E quando a soma bate
**exatamente** 35, também não precisa descer: os próximos itens só poderiam
entrar com a soma passando de 35.

Vamos ver na prática. Cada caixa da árvore mostra a soma até ali. O galho da
esquerda leva o item do nível, o da direita não leva. As caixas vermelhas são
podas, as verdes são soluções e as cinzas são becos sem saída (os itens
acabaram antes de a soma chegar a 35):

{{ideia}}

No código, a poda é o primeiro `if` da função. A chamada que passou do alvo
começa, percebe o problema e volta na hora:

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

A árvore completa de 4 itens tem 1 + 2 + 4 + 8 + 16 = 31 nós. A poda deixou
21. Parece pouco, mas o efeito cresce com o tamanho: cada poda perto da raiz
corta um galho com metade da árvore. Com 30 itens e um alvo pequeno, a
diferença é entre um bilhão de chamadas e alguns milhares.

Repara no fluxograma: as duas perguntas de cima mandam embora cedo, e só quem
passa por elas chega às duas chamadas recursivas:

{{fluxograma}}

> [!WARNING]
> A ordem dos testes importa. Se o `if (i == N) return;` viesse **antes** do
> `if (soma == ALVO)`, a solução que fecha justo com o último item
> (`atlas marcador`, que chega a 35 com `i` valendo 4) seria descartada como
> "acabaram os itens", e só `mangá poesia` apareceria. Outro clássico é
> escrever a poda com `>=` no lugar de `>`: aí toda soma que bate o alvo é
> cortada antes de ser mostrada, e a saída fica vazia. A poda só pode cortar
> o que **com certeza** não leva a solução. Uma poda gananciosa demais deixa o
> programa rápido e errado.

> [!TIP]
> **Por dentro do C:** a soma viaja como **parâmetro**, então cada frame tem a
> sua e voltar desfaz a soma de graça. Já `leva[]` é global e um só: por isso
> a linha `leva[i] = false` antes do segundo caminho. O vetor ocupa `N` bytes
> e a pilha nunca passa de `N + 1` frames, mesmo quando as chamadas somam
> milhões. O custo no pior caso continua **O(2ⁿ)**: a poda não muda a ordem
> de grandeza garantida, muda o quanto da árvore você visita na prática. E
> repara que ordenar os preços do maior para o menor, como aqui, faz a soma
> estourar mais cedo e podar mais perto da raiz.

> [!NOTE]
> **Pergunta para você:** se o cartão fosse de R$ 50, quais combinações
> sairiam? A primeira linha da saída ainda seria a do atlas?

{{pratique}}
