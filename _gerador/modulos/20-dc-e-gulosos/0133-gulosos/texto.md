## 0133 · Algoritmos gulosos

Na padaria, o pão deu R$ 3,10 e você pagou com uma nota de 5. O caixa
precisa devolver R$ 1,90 com o menor número de moedas. Ninguém no balcão
testa todas as combinações. O caixa pega a maior moeda que cabe no que
falta, depois a maior que cabe no resto, e assim por diante: 100, 50, 25,
10 e 5 centavos. Cinco moedas, e é o mínimo possível.

Esse jeito de decidir tem nome. Um **algoritmo guloso** (*greedy*) monta a
solução passo a passo e, a cada passo, faz a escolha que parece a **melhor
agora**, sem nunca voltar atrás (CORMEN et al., 2024, cap. 15). Ele não
desfaz escolhas, como o backtracking (0127), e não divide o problema em
pedaços para resolver cada um, como a divisão e conquista (0131). Você já
viu um guloso: o Dijkstra (0112) fixa o vértice mais perto da origem e nunca
mais mexe nele (ZIVIANI, 2010, cap. 2).

Quando funciona, o guloso é curto e barato. O troco é um laço que percorre
os `k` tipos de moeda do maior para o menor, e o custo é O(k + moedas
dadas). O problema é que uma escolha boa agora pode estragar o resto, e o
guloso não percebe, porque nunca olha para trás.

Veja isso num fliperama com fichas de 1, 3 e 4 créditos. O troco de 6
créditos pelo guloso começa pela maior ficha que cabe, a de 4. Sobram 2,
que só se pagam com 1 + 1. São três fichas. Mas 3 + 3 resolve com duas. O 4
parecia a melhor escolha e fechou o caminho bom. O sistema do Real é
**canônico**: para ele, o guloso sempre acha o mínimo. O sistema {1, 3, 4}
não é (KOZEN; ZAKS, 1994).

Como saber se o guloso acerta? O Cormen pede duas propriedades. A
**propriedade da escolha gulosa** diz que existe alguma solução ótima que
começa pela escolha que o guloso faz. Então escolher assim não fecha a porta
para o ótimo (CORMEN et al., 2024, cap. 15). A **subestrutura ótima** diz que,
depois da escolha, o que sobra é um problema do mesmo tipo, menor, e que a
solução ótima do todo contém uma solução ótima desse resto (CORMEN et al.,
2024, cap. 15). No troco: depois de dar a moeda de 100, falta dar R$ 0,90 com
o mínimo de moedas, que é o mesmo problema.

A primeira propriedade costuma sair de uma **prova por troca**. Você pega
uma solução ótima qualquer, troca um pedaço dela pela escolha gulosa e
mostra que o resultado não piora (KLEINBERG; TARDOS, 2006, cap. 4). No Real,
se um troco usasse duas moedas de 25 no lugar de uma de 50, trocar as duas
pela de 50 diminuiria a contagem. Logo o ótimo nunca evita a moeda maior que
cabe. Com {1, 3, 4} a troca falha: duas fichas de 3 não viram uma de 4.

A lição vale para todo guloso: **um contraexemplo derruba, e só uma prova
garante** (KLEINBERG; TARDOS, 2006, cap. 4). Testar meia dúzia de casos que
dão certo não prova nada. Quando o guloso não serve, a programação dinâmica
(módulo 21) resolve o troco de qualquer sistema de moedas, a um custo maior
(CORMEN et al., 2024, cap. 15).

> [!WARNING]
> O troco guloso **depende da ordem** do vetor: com `{5, 10, 25, 50, 100}`, a
> função dá 38 moedas de 5 centavos para R$ 1,90. E use **centavos** em `int`:
> em `double`, `1.90 - 1.00 - 0.50 - 0.25 - 0.10` não dá 0,05 exato.

{{exemplo}}

O troco de R$ 1,90 na padaria (o guloso acerta) e o de 6 créditos no
fliperama com fichas de 1, 3 e 4 (o 4 deixa um resto de 2, e o 3 + 3 nunca é
visto):

{{ideia}}

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
No fluxograma não há volta a uma moeda maior:

{{fluxograma}}
