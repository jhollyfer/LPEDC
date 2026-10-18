## 0135 · Mochila fracionária

Um feirante vai vender produtos a granel na cidade vizinha. A caminhonete
leva **60 kg**, e o estoque dele tem mais do que isso: café, castanha,
feijão, açafrão e arroz, cada um com um peso disponível e um valor de venda.
Como é tudo a granel, ele pode levar **parte** de um saco. O que levar para
voltar com o máximo de dinheiro?

Esse é o problema da **mochila fracionária**: uma mochila com capacidade `W`
e `n` itens, cada um com peso e valor; você pode levar qualquer fração de
cada item, e o valor acompanha a fração (metade do café vale metade do
preço). O objetivo é o maior valor total sem passar de `W`.

O que importa não é o valor de cada saco, nem o peso: é o **valor por quilo**.
Cada quilo de espaço da caminhonete é igual aos outros, então ele deve ir para
o produto que paga mais por quilo. O guloso fica assim:

1. calcule a **razão** `valor / peso` de cada item;
2. **ordene** os itens pela razão, da maior para a menor;
3. leve cada item **inteiro** enquanto couber; no primeiro que não couber,
   leve **só a fração** que preenche o espaço que sobrou, e pare.

No máximo um item fica partido: o último. O custo é o da ordenação, O(n log n),
mais uma passada.

Por que o guloso acerta aqui? Pelo argumento de troca, de novo. Suponha uma
carga que leva 1 kg de feijão (R$ 9/kg) e deixa de fora 1 kg de castanha
(R$ 50/kg). Trocar esse quilo de feijão pelo de castanha aumenta o valor em
R$ 41 e não muda o peso. Então uma carga ótima nunca deixa de fora um quilo
que paga mais enquanto leva um que paga menos, e é exatamente isso que a
ordem pela razão garante.

Vamos ver na prática. Ordenados pela razão, o açafrão paga R$ 80/kg, a
castanha R$ 50, o café R$ 30, o feijão R$ 9 e o arroz R$ 5. Os três primeiros
cabem inteiros (5 + 15 + 20 = 40 kg). Sobram 20 kg, e o feijão tem 30: vão
dois terços do saco. O arroz nem entra:

{{ideia}}

O mesmo exemplo em C. A função de comparação calcula a razão de cada lado e
ordena do maior para o menor:

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
o "ç" e o "ã" ocupam dois bytes cada. Com o nome no começo, as colunas
ficariam tortas.

Repara no fluxograma: o laço tem duas saídas para cada item. O caminho marcado
passa pelo "leva tudo" três vezes (açafrão, castanha, café) e uma vez pelo
"leva a fração" (feijão), que zera o espaço e encerra o laço:

{{fluxograma}}

> [!WARNING]
> Esse guloso só vale para a mochila **fracionária**. Se os itens forem
> indivisíveis (uma geladeira, um notebook: leva inteiro ou não leva), é a
> **mochila 0/1**, e ordenar pela razão pode errar feio. Com capacidade 10 e
> itens (peso 6, R$ 30), (5, R$ 20) e (5, R$ 20), a maior razão é a do
> primeiro (R$ 5/kg): o guloso leva ele, os outros não cabem, e o total é
> R$ 30. Levar os dois de 5 dá R$ 40. A mochila 0/1 se resolve com
> programação dinâmica, no módulo 21.

> [!TIP]
> **Por dentro do C:** comparar razões com `double` funciona, mas a divisão
> arredonda. Quando os pesos e valores são inteiros, dá para comparar sem
> dividir: `x->valor / x->peso > y->valor / y->peso` é o mesmo que
> `x->valor * y->peso > y->valor * x->peso` (os pesos são positivos), e a
> conta com inteiros é exata. Só confira se o produto cabe no tipo: com
> `long long`, valores e pesos até uns 3 bilhões são seguros. E nunca devolva
> `(int)(ry - rx)` na comparação: razões 4,7 e 4,2 viram 0 depois do corte, e
> o `qsort` passa a tratar as duas como iguais.

> [!NOTE]
> **Pergunta para você:** se a caminhonete levasse 100 kg, quanto o feirante
> faria? E com 110 kg? A partir de que capacidade o arroz começa a entrar?

{{pratique}}
