## 0127 · Backtracking

- **Backtracking** (retrocesso, ou **tentativa e erro**): enumeração que
  **desiste cedo**. A cada escolha, pergunta se o começo ainda pode virar
  solução; se não, volta um passo (ZIVIANI, 2010, cap. 2).
- **Poda**: cortar um galho inteiro da árvore de decisões sem visitá-lo
  (WIRTH, 1989).
- **Esqueleto**: (1) **parada**: a solução está completa? mostre e volte;
  (2) **poda**: o começo é inviável? volte sem descer; (3) **escolha**: para
  cada opção, escolha, desça e **desfaça** (FEOFILOFF, 2009).
- **Soma de subconjuntos**: achar os itens que somam um alvo exato. Com
  preços positivos, soma acima do alvo não tem conserto e pode ser podada
  (FEOFILOFF, 2009).
- **Estado na volta**: o que é **parâmetro** se desfaz sozinho; o que é
  global (`leva[]`) precisa ser desfeito à mão (KERNIGHAN; RITCHIE, 1989).
- **Custo**: o pior caso continua **O(2ⁿ)**. A poda muda o quanto da árvore
  você visita, não a garantia (ROVAI, 2018).

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
