## 0135 · Mochila fracionária

Um feirante leva **60 kg** na caminhonete. Ele tem café, castanha, feijão,
açafrão e arroz a granel, cada um num saco com peso e preço, e pode levar
**parte** de um saco, porque grão se divide. O que ele põe na caçamba para
voltar da feira com o máximo de dinheiro?

O problema tem nome. Na **mochila fracionária**, você tem uma mochila de
capacidade `W` e `n` itens, cada um com peso e valor, e pode levar qualquer
**fração** de cada item, recebendo o valor proporcional a essa fração. O
objetivo é o maior valor total sem passar de `W` (CORMEN et al., 2024, cap.
15). Metade de um saco de 30 kg que vale R$ 270 pesa 15 kg e vale R$ 135.

A intuição é pensar no espaço, não no item. Cada quilo da caçamba é um
recurso escasso, e ele deve ir para o produto que paga mais por quilo. Essa
medida é a **razão** `valor / peso`, o valor por unidade de espaço (CORMEN
et al., 2024, cap. 15). O açafrão pode custar menos por saco que o feijão e,
mesmo assim, render muito mais por quilo.

Daí sai o guloso (0133). Calcule a razão de cada item e ordene da maior para
a menor. Percorra nessa ordem e leve cada item **inteiro** enquanto ele
couber. No primeiro que não couber, leve **só a fração** que completa o
espaço que sobrou, e pare (ZIVIANI, 2010, cap. 2). No feirante, as razões são
açafrão R$ 80/kg, castanha R$ 50, café R$ 30, feijão R$ 9 e arroz R$ 5.
Açafrão, castanha e café cabem inteiros (5 + 15 + 20 = 40 kg). Sobram 20 kg
e o saco de feijão tem 30: vão dois terços dele. O arroz nem entra.

Repare que **no máximo um item fica partido**, o último. Todos antes dele
entraram inteiros, e todos depois ficaram de fora. O custo é dominado pela
ordenação, O(n log n); a passada que enche a caçamba é O(n) (CORMEN et al.,
2024, cap. 15).

Por que essa ordem é a ótima? A prova é por troca. Suponha uma carga que
leva 1 kg de feijão (R$ 9/kg) e deixa de fora 1 kg de castanha (R$ 50/kg).
Trocar um pelo outro mantém o peso e ganha R$ 41. Então uma carga ótima
nunca deixa de fora um quilo que paga mais enquanto leva um que paga menos,
e é exatamente isso que a ordem pela razão garante (KLEINBERG; TARDOS, 2006,
cap. 4).

Tudo isso depende de poder partir. Na **mochila 0/1**, cada item vai inteiro
ou não vai, como um notebook ou uma televisão. Ali a troca de um quilo por
outro deixa de ser possível, e o guloso pela razão pode errar. A mochila 0/1
se resolve com programação dinâmica (módulo 21), a um custo maior (CORMEN et
al., 2024, cap. 15).

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
