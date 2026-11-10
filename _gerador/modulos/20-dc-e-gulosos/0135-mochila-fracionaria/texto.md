## 0135 · Mochila fracionária

Um feirante leva **60 kg** na caminhonete e tem café, castanha, feijão,
açafrão e arroz a granel, então pode levar **parte** de um saco. O que levar
para voltar com o máximo de dinheiro?

É a **mochila fracionária**: capacidade `W`, `n` itens com peso e valor e
qualquer fração de cada um, com valor proporcional. O objetivo é o maior
valor total sem passar de `W`.

Decide o **valor por quilo**: cada quilo de espaço deve ir para quem paga
mais. O guloso:

1. calcule a **razão** `valor / peso` de cada item;
2. **ordene** os itens pela razão, da maior para a menor;
3. leve cada item **inteiro** enquanto couber; no primeiro que não couber,
   leve **só a fração** que preenche o espaço que sobrou, e pare.

No máximo um item fica partido, o último. O custo é a ordenação, O(n log n).

A prova é por troca: levar 1 kg de feijão (R$ 9/kg) e deixar 1 kg de castanha
(R$ 50/kg) perde R$ 41 sem ganhar peso. Uma carga ótima nunca deixa de fora um
quilo que paga mais enquanto leva um que paga menos.

Por razão: açafrão R$ 80/kg, castanha R$ 50, café R$ 30, feijão R$ 9, arroz
R$ 5. Os três primeiros cabem inteiros (5 + 15 + 20 = 40 kg). Sobram 20 kg e
o feijão tem 30: vão dois terços do saco. O arroz nem entra:

{{ideia}}

A comparação calcula a razão de cada lado e ordena do maior para o menor:

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

O nome vai no fim da linha de propósito: `%-10s` conta **bytes**, e em UTF-8
o "ç" e o "ã" ocupam dois bytes cada.

No fluxograma, o caminho marcado leva tudo três vezes (açafrão, castanha, café)
e a fração uma vez (feijão), que zera o espaço e encerra o laço:

{{fluxograma}}

> [!WARNING]
> Esse guloso só vale para a mochila **fracionária**. Com itens indivisíveis é
> a **mochila 0/1**, e ordenar pela razão pode errar: com capacidade 10 e
> itens (peso 6, R$ 30), (5, R$ 20) e (5, R$ 20), o guloso leva o primeiro
> (R$ 5/kg) e o total é R$ 30, mas os dois de 5 dão R$ 40. A mochila 0/1 se
> resolve com programação dinâmica (módulo 21).

> [!TIP]
> **Por dentro do C:** nunca devolva `(int)(ry - rx)` na comparação: razões
> 4,7 e 4,2 viram 0 e o `qsort` as trata como iguais.

> [!NOTE]
> **Pergunta para você:** se a caminhonete levasse 100 kg, quanto o feirante
> faria? E com 110 kg? A partir de que capacidade o arroz começa a entrar?

{{pratique}}
