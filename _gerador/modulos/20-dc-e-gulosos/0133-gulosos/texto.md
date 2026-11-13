## 0133 · Algoritmos gulosos

- **Algoritmo guloso** (*greedy*): a cada passo faz a escolha que parece a
  **melhor agora** e **nunca volta atrás** (CORMEN et al., 2024, cap. 15).
- **Diferença**: não desfaz, como o backtracking (0127), nem divide em
  subproblemas, como a divisão e conquista (0131). O Dijkstra (0112) é guloso
  (ZIVIANI, 2010, cap. 2).
- **Propriedade da escolha gulosa**: alguma solução ótima começa pela escolha
  do guloso (CORMEN et al., 2024, cap. 15).
- **Subestrutura ótima**: o que sobra depois da escolha é um problema do
  mesmo tipo (CORMEN et al., 2024, cap. 15).
- **Prova por troca**: troque um pedaço da solução ótima pela escolha gulosa
  e mostre que ela não piora. **Um contraexemplo derruba; só uma prova
  garante** (KLEINBERG; TARDOS, 2006, cap. 4).
- **Troco guloso**: dá sempre a maior moeda que cabe. Acerta o mínimo nos
  sistemas **canônicos**, como o Real; com fichas {1, 3, 4}, o troco de 6 sai
  4 + 1 + 1, e o ótimo é 3 + 3 (KOZEN; ZAKS, 1994).
- **Quando falha**: a programação dinâmica (módulo 21) resolve o troco de
  qualquer sistema (CORMEN et al., 2024, cap. 15).

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
