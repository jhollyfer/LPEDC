## 0135 · Mochila fracionária

- **Mochila fracionária**: capacidade `W`, `n` itens com peso e valor, e pode
  levar qualquer **fração** de cada um, com valor proporcional. Objetivo: o
  maior valor sem passar de `W` (CORMEN et al., 2024, cap. 15).
- **Razão**: `valor / peso`, o valor por unidade de espaço. Cada quilo vai
  para quem paga mais (CORMEN et al., 2024, cap. 15).
- **Guloso**: ordene pela razão, da maior para a menor; leve cada item
  **inteiro** enquanto couber; no primeiro que não couber, leve **só a
  fração** que completa o espaço e pare (ZIVIANI, 2010, cap. 2).
- **No máximo um item partido**: o último. O custo é a ordenação,
  O(n log n) (CORMEN et al., 2024, cap. 15).
- **Prova por troca**: trocar 1 kg de um item caro por 1 kg de um barato
  perde valor sem ganhar espaço, então a carga ótima segue a razão
  (KLEINBERG; TARDOS, 2006, cap. 4).
- **Mochila 0/1**: itens indivisíveis. Ali o guloso pela razão pode errar e a
  solução é programação dinâmica (módulo 21) (CORMEN et al., 2024, cap. 15).

> [!WARNING]
> Esse guloso só vale na versão **fracionária**. Com capacidade 10 e itens
> (6, R$ 30), (5, R$ 20) e (5, R$ 20) indivisíveis, ele leva o primeiro e faz
> R$ 30, mas os dois de 5 dão R$ 40.

{{exemplo}}

Um feirante leva 60 kg na caminhonete. Por razão: açafrão R$ 80/kg, castanha
R$ 50, café R$ 30, feijão R$ 9, arroz R$ 5. Os três primeiros cabem inteiros
(40 kg); do feijão vão dois terços do saco; o arroz nem entra:

{{ideia}}

A comparação calcula a razão de cada lado e ordena do maior para o menor.
Nunca devolva `(int)(ry - rx)`: razões 4,7 e 4,2 virariam 0.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *nome;
    double peso;  // kg disponíveis
    double valor; // R$ pelo estoque inteiro
} Produto;

// ordem decrescente de valor por kg
int por_razao(const void *a, const void *b) {
    const Produto *x = a;
    const Produto *y = b;
    double rx = x->valor / x->peso;
    double ry = y->valor / y->peso;
    return (rx < ry) - (rx > ry);
}

int main(void) {
    Produto p[] = {
        {"café", 20, 600},    {"castanha", 15, 750}, {"feijão", 30, 270},
        {"açafrão", 5, 400},  {"arroz", 40, 200},
    };
    int n = 5;
    double livre = 60; // kg que cabem na caminhonete
    double total = 0;

    qsort(p, n, sizeof p[0], por_razao);
    for (int i = 0; i < n && livre > 0; i++) {
        double leva = p[i].peso <= livre ? p[i].peso : livre; // tudo ou o que cabe
        double ganho = p[i].valor * (leva / p[i].peso);       // valor proporcional
        printf("%4.1f de %4.1f kg  R$ %6.2f  (R$ %.0f/kg) %s\n",
               leva, p[i].peso, ganho, p[i].valor / p[i].peso, p[i].nome);
        livre -= leva;
        total += ganho;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
// Saída:
//  5.0 de  5.0 kg  R$ 400.00  (R$ 80/kg) açafrão
// 15.0 de 15.0 kg  R$ 750.00  (R$ 50/kg) castanha
// 20.0 de 20.0 kg  R$ 600.00  (R$ 30/kg) café
// 20.0 de 30.0 kg  R$ 180.00  (R$ 9/kg) feijão
// Total: R$ 1930.00
```

O nome vai no fim da linha de propósito: `%-10s` conta **bytes**, e em UTF-8 o
"ç" e o "ã" ocupam dois. O caminho marcado leva tudo três vezes e a fração uma
vez, que zera o espaço:

{{fluxograma}}
