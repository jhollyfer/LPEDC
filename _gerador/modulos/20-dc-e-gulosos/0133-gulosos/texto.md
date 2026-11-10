## 0133 · Algoritmos gulosos

Na padaria, o pão deu R$ 3,10 e você pagou com uma nota de 5. O caixa devolve
R$ 1,90 com o **menor número de moedas** pegando sempre a maior que cabe no
que falta: 100 + 50 + 25 + 10 + 5, cinco moedas, o mínimo possível.

Isso é um **algoritmo guloso** (*greedy*): a cada passo faz a escolha que
parece a **melhor agora** e **nunca volta atrás**. Não desfaz, como o
backtracking (0127), nem divide em subproblemas, como a divisão e conquista
(0131).

O Dijkstra (0112) é guloso: fixa o vértice mais perto da origem e nunca mais
mexe nele. Os próximos assuntos trazem reuniões numa sala, mochila e Huffman.

Quando funciona, o guloso é curto e barato: um laço, O(k + moedas dadas) para
`k` tipos de moeda. Mas uma escolha boa agora pode estragar o resto, e ele
não percebe.

Num fliperama com fichas de **1, 3 e 4 créditos**, o troco de 6 créditos pelo
guloso é 4 + 1 + 1, **três fichas**. Mas 3 + 3 dá **duas**: o 4 parecia ótimo
e fechou o caminho bom.

No Real dá certo porque o sistema é **canônico**: dá para provar que o guloso
acha o mínimo. A prova é por "troca": se um troco usasse duas moedas de 25 no
lugar de uma de 50, trocá-las pela de 50 diminuiria a conta. Com {1, 3, 4}, a
troca falha: duas fichas de 3 não viram uma de 4.

Vale para todo guloso: **um contraexemplo derruba, e só uma prova garante**.
O Cormen pede a **propriedade da escolha gulosa** (alguma solução ótima começa
pela escolha do guloso) e a **subestrutura ótima** (o que sobra é um problema
do mesmo tipo); a troca prova a primeira. Quando o guloso não serve, a
programação dinâmica (módulo 21) resolve o troco de qualquer sistema.

No desenho, em cima o troco de R$ 1,90 (o guloso acerta); embaixo, as fichas:
o 4 deixa um resto de 2 que custa duas fichas, e o 3 + 3 nunca é visto:

{{ideia}}

A função recebe as moedas em ordem **decrescente**: se a moeda cabe, dá e
continua nela; se não, passa para a próxima menor:

```c
#include <stdio.h>

// troco guloso: sempre a MAIOR moeda que ainda cabe no que falta.
// moedas[] precisa estar em ordem decrescente. Devolve quantas moedas deu.
int troco_guloso(const int moedas[], int k, int valor) {
    int quantas = 0;
    int i = 0;
    printf("Troco de %d:", valor);
    while (valor > 0 && i < k) {
        if (moedas[i] <= valor) {
            printf(" %d", moedas[i]); // escolhe e nunca volta atrás
            valor -= moedas[i];
            quantas++;
        } else {
            i++;                      // essa não cabe mais: tenta a próxima
        }
    }
    printf(" (%d moedas)\n", quantas);
    return quantas;
}

int main(void) {
    int real[] = {100, 50, 25, 10, 5}; // centavos
    int fichas[] = {4, 3, 1};          // créditos do fliperama

    troco_guloso(real, 5, 190);        // R$ 1,90
    troco_guloso(fichas, 3, 6);        // 6 créditos
    return 0;
}
// Saída:
// Troco de 190: 100 50 25 10 5 (5 moedas)
// Troco de 6: 4 1 1 (3 moedas)
```

O código não sabe que errou: só o contraexemplo mostra que 3 não é o mínimo.

No fluxograma, "ainda falta troco?" controla o laço e "a moeda da vez cabe?"
decide entre dar a moeda ou descer para a próxima. Não há volta a uma moeda
maior:

{{fluxograma}}

> [!WARNING]
> O guloso do troco **depende da ordem** do vetor: com `{5, 10, 25, 50, 100}`,
> a função dá 38 moedas de 5 centavos para R$ 1,90. Ordene da maior para a
> menor (`qsort`, 0096), e lembre que, mesmo ordenado, o guloso só garante o
> mínimo em sistema canônico.

> [!TIP]
> **Por dentro do C:** use **centavos** em `int`, não reais em `double`:
> `1.90 - 1.00 - 0.50 - 0.25 - 0.10` dá `0.049999999999999906`, e a moeda de 5
> centavos "não cabe" (`0.05 <= 0.0499...` é falso).

> [!NOTE]
> **Pergunta para você:** com moedas de 1, 10 e 25 centavos (sem a de 5), o
> guloso acerta o troco de 30? E o de 40? Faça as contas no papel e depois
> rode a função com `{25, 10, 1}`.

{{pratique}}
