## 0121 · Radix sort

Antes dos computadores de hoje, os censos eram processados com cartões
perfurados e uma máquina **classificadora**. Ela olhava uma coluna do cartão e
jogava cada cartão num de 10 escaninhos, do 0 ao 9. O operador juntava os
escaninhos em ordem e passava o maço de novo, agora pela coluna seguinte.
Depois de passar por todas as colunas, o maço estava ordenado.

O truque, que parece ao contrário, é começar pela coluna **menos**
significativa. O **radix sort** (ordenação digital, ou por raiz) faz
exatamente isso com números:

1. ordene pelo dígito das **unidades**;
2. depois pelo das **dezenas**;
3. depois pelo das **centenas**, e assim até o dígito mais alto do maior
   número.

Cada passada é um **counting sort** (assunto 0120) com 10 chaves, de 0 a 9.
O dígito de `x` na casa `exp` (1, 10, 100...) sai com `(x / exp) % 10`. Essa
versão, que começa pelo dígito menos significativo, se chama **LSD** (*least
significant digit*).

Por que funciona? Depois da passada das dezenas, os números estão em ordem
pelos dois últimos dígitos. Na passada das centenas, dois números com a mesma
centena, como 807 e 830, ficam na ordem em que já estavam, que é a ordem das
dezenas. É por isso que cada passada **precisa ser estável**: a estabilidade
guarda o trabalho das passadas anteriores.

O custo é de `d` passadas de counting sort, com `d` dígitos e base `b`:
**O(d · (n + b))**. Para números de tamanho fixo, `d` é constante e o radix
sort é linear. De novo, nenhuma comparação entre elementos.

Vamos ver na prática. Oito números de pedido de um mercado online, com até
três dígitos (escritos com zeros à esquerda para os dígitos ficarem
alinhados). Acompanhe o 807 e o 830, em amarelo: a passada das dezenas põe o
807 na frente, e a das centenas, que vê os dois empatados no 8, respeita:

{{ideia}}

O mesmo exemplo em C. A `passada` é o counting sort do assunto 0120 com a
chave trocada pelo dígito; o vetor auxiliar é alocado uma vez só e
reaproveitado em todas as passadas:

```c
#include <stdio.h>
#include <stdlib.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %03d", v[i]);
    }
    printf("\n");
}

// counting sort estável de v pelo dígito (v[i] / exp) % 10
void passada(int v[], int aux[], int n, int exp) {
    int c[10] = {0};
    for (int i = 0; i < n; i++) {
        c[(v[i] / exp) % 10]++;
    }
    for (int d = 1; d < 10; d++) {
        c[d] += c[d - 1];
    }
    for (int i = n - 1; i >= 0; i--) {      // de trás para a frente
        int d = (v[i] / exp) % 10;
        c[d]--;
        aux[c[d]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

void radix_sort(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return;
    }
    for (int exp = 1; maior / exp > 0; exp *= 10) {  // um dígito por passada
        passada(v, aux, n, exp);
        printf("exp = %3d:", exp);
        mostra(v, n);
    }
    free(aux);
}

int main(void) {
    int pedidos[] = {251, 47, 830, 509, 74, 216, 553, 807};
    int n = 8;

    printf("início:   ");
    mostra(pedidos, n);
    radix_sort(pedidos, n);
    return 0;
}
// Saída:
// início:    251 047 830 509 074 216 553 807
// exp =   1: 830 251 553 074 216 047 807 509
// exp =  10: 807 509 216 830 047 251 553 074
// exp = 100: 047 074 216 251 509 553 807 830
```

### Passo a passo

A passada das dezenas (`exp = 10`) recebe o vetor da passada anterior. O
dígito de cada número é `(x / 10) % 10`:

| número | 830 | 251 | 553 | 074 | 216 | 047 | 807 | 509 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| dígito | 3 | 5 | 5 | 7 | 1 | 4 | 0 | 0 |

Contagem por dígito: 0 → 2, 1 → 1, 3 → 1, 4 → 1, 5 → 2, 7 → 1. Os blocos
na saída ficam: `807 509 | 216 | 830 | 047 | 251 553 | 074`. Dentro do
bloco do 0, o 807 vem antes do 509 porque já vinha antes: a passada não
olhou as unidades, mas também não estragou a ordem delas.

Repara no fluxograma: o laço para quando `exp` passa do maior número. Com o
maior igual a 830, são três passadas (`exp` = 1, 10, 100); com `exp = 1000`,
`830 / 1000` dá 0:

{{fluxograma}}

> [!WARNING]
> Use uma ordenação **estável** em cada passada. Se o terceiro laço da
> `passada` andar da frente para trás, cada passada inverte os empates, e o
> resultado sai `074 047 251 216 553 509 830 807`: as centenas em ordem, o
> resto bagunçado, sem erro nenhum. Também não
> dá para começar pelas centenas com esse código: a última passada é a que
> manda, então ela tem que ser a do dígito mais importante. E o número de
> passadas vem do **maior** elemento, não do primeiro: um número de 4 dígitos
> escondido no meio do vetor precisa da quarta passada.

> [!TIP]
> **Por dentro do C:** divisão e resto custam caro para o processador, e
> base 10 é uma escolha humana. Programas de verdade usam **base 256**: o
> "dígito" é um byte, e sai com operadores de bits (assunto 0065):
> `(x >> 8 * b) & 0xFF` é o byte `b` de `x`. Um `int` de 32 bits tem 4 bytes,
> então são sempre 4 passadas, com `c[256]` (1 KB, cabe no cache L1). Um
> milhão de inteiros vira 4 passadas de 1 milhão, contra uns 20 milhões de
> comparações de um bom O(n log n). O preço é a memória: o vetor auxiliar tem
> o tamanho da entrada.

> [!NOTE]
> **Pergunta para você:** este código funciona com números negativos? Pense
> no que `(-47 / 1) % 10` dá em C (o resto tem o sinal do dividendo) e onde
> isso cairia no vetor `c`.

{{pratique}}
