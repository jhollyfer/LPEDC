## 0133 · Algoritmos gulosos

Na padaria, o pão deu R$ 3,10 e você pagou com uma nota de 5. O caixa precisa
devolver R$ 1,90 com o **menor número de moedas**. Ninguém ali testa
combinações. O caixa pega a maior moeda que cabe (R$ 1), depois a maior que
cabe no que falta (50 centavos), e assim por diante: 100 + 50 + 25 + 10 + 5,
cinco moedas. Rápido e certo.

Esse jeito de pensar tem nome: **algoritmo guloso** (em inglês, *greedy*). A
cada passo ele faz a escolha que parece a **melhor agora**, sem pensar no
futuro, e **nunca volta atrás**. Não existe "desfazer", como no backtracking
(assunto 0127), nem dividir em subproblemas para depois combinar, como na
divisão e conquista (0131). É uma decisão por vez, e cada decisão é final.

Você já viu um guloso famoso: o Dijkstra (assunto 0112) fixa, a cada passo, o
vértice mais perto da origem, e nunca mais mexe nele. Os próximos assuntos
trazem mais três: escolher reuniões numa sala, encher uma mochila e comprimir
arquivos (Huffman).

Quando funciona, o guloso é o algoritmo mais simples e rápido que existe.
Aqui, é um laço só: O(k + número de moedas dadas), para `k` tipos de moeda. O
problema é o "quando funciona". Uma escolha boa agora pode estragar o resto, e
o guloso não tem como perceber.

Imagine um fliperama que só tem fichas de **1, 3 e 4 créditos**. O troco é de
6 créditos. O guloso pega a maior que cabe, 4, e sobram 2, que só saem com
1 + 1: **três fichas**. Mas 3 + 3 dá **duas**. O guloso errou, e errou por
causa da primeira escolha: o 4 parecia ótimo e fechou o caminho bom.

Então por que no Real dá certo? Porque o sistema do Real é **canônico**: para
ele, dá para provar que o guloso sempre acha o mínimo. A prova é do tipo
"troca": se um troco usasse, por exemplo, duas moedas de 25 onde cabe uma de
50, trocar as duas pela de 50 diminuiria a conta. Repetindo o argumento para
cada moeda, a solução ótima só pode ser a gulosa. Com {1, 3, 4}, a troca não
funciona: duas fichas de 3 não viram uma de 4.

A lição vale para todo guloso: **um contraexemplo derruba, e só uma prova
garante**. "Testei uns casos e deu certo" não é prova. Quando o guloso não
serve, o caminho é testar as combinações com esperteza: a programação
dinâmica do módulo 21 resolve o troco de qualquer sistema de moedas.

Vamos ver na prática. Em cima, o troco de R$ 1,90: cada moeda escolhida é a
maior que cabe no que falta, e o guloso acerta. Embaixo, as fichas: o 4
parece a melhor escolha, mas deixa um resto de 2 que custa duas fichas, e o
ótimo (3 + 3) nunca é visto:

{{ideia}}

O mesmo exemplo em C. A função recebe as moedas em ordem **decrescente** e
anda por elas: se a moeda cabe, dá a moeda e continua nela (pode precisar de
outra igual); se não cabe, passa para a próxima menor:

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

O código não tem como saber que errou: ele devolve 3 com a mesma confiança
com que devolve 5. Quem sabe que 3 não é o mínimo é você, que achou o
contraexemplo.

Repara no fluxograma: as duas perguntas fazem todo o trabalho. "Ainda falta
troco?" controla o laço, e "a moeda da vez cabe?" decide entre dar a moeda ou
descer para a próxima. Não há caminho de volta para uma moeda maior:

{{fluxograma}}

> [!WARNING]
> O guloso do troco **depende da ordem** do vetor. Com as moedas em ordem
> crescente (`{5, 10, 25, 50, 100}`), a função dá 38 moedas de 5 centavos para
> o troco de R$ 1,90: ela pega a primeira que cabe, e a primeira é a menor.
> Se as moedas chegam fora de ordem, ordene antes, de forma decrescente (com o
> `qsort`, assunto 0096). E lembre: mesmo ordenado, o guloso só garante o
> mínimo em sistema canônico.

> [!TIP]
> **Por dentro do C:** o troco é feito em **centavos**, num `int`, e não em
> reais num `double`. O valor 0,10 não tem representação exata em binário:
> `1.90 - 1.00 - 0.50 - 0.25 - 0.10` dá `0.049999999999999906` num `double`, e
> aí a moeda de 5 centavos "não cabe" (`0.05 <= 0.0499...` é falso). O laço
> termina devendo troco. Todo programa que lida com dinheiro guarda centavos
> num inteiro e só divide por 100 na hora de mostrar.

> [!NOTE]
> **Pergunta para você:** com moedas de 1, 10 e 25 centavos (sem a de 5), o
> guloso acerta o troco de 30? E o de 40? Faça as contas no papel e depois
> rode a função com `{25, 10, 1}`.

{{pratique}}
