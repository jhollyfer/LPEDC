## 0121 · Radix sort

Nos censos antigos, uma máquina **classificadora** jogava cada cartão perfurado
num de 10 escaninhos, do 0 ao 9, conforme uma coluna. O operador juntava os
escaninhos e passava o maço pela coluna seguinte, começando pela **menos**
significativa.

O **radix sort** (ordenação digital) faz o mesmo com números: ordena pelo
dígito das **unidades**, depois pelo das **dezenas**, depois pelo das
**centenas**, até o dígito mais alto do maior número. Cada passada é um
**counting sort** (assunto 0120) com chaves de 0 a 9, e o dígito de `x` na
casa `exp` (1, 10, 100...) sai de `(x / exp) % 10`. Começar pelo dígito menos
significativo se chama **LSD** (*least significant digit*).

Cada passada **precisa ser estável**: números com a mesma centena ficam na
ordem que a passada anterior deu a eles.

Com `d` dígitos e base `b`, o custo é **O(d · (n + b))**: para números de
tamanho fixo, `d` é constante e o radix sort é linear. Para chaves de `b` bits
em dígitos de `r` bits, Θ((b/r)(n + 2^r)), e a melhor escolha fica perto de
r = log₂ n.

No exemplo, em amarelo, o 807 e o 830: a passada das dezenas põe o 807 na
frente, e a das centenas respeita essa ordem:

{{ideia}}

A `passada` é o counting sort do assunto 0120 com o dígito como chave; o vetor
auxiliar é alocado uma vez só:

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
na saída ficam `807 509 | 216 | 830 | 047 | 251 553 | 074`. No bloco do 0, o
807 vem antes do 509 porque já vinha antes.

O laço para quando `exp` passa do maior número: com 830, são três passadas
(`exp` = 1, 10, 100), e `830 / 1000` dá 0:

{{fluxograma}}

> [!WARNING]
> Com o terceiro laço da `passada` da frente para trás, cada passada inverte
> os empates e o resultado sai `074 047 251 216 553 509 830 807`, sem erro. A
> última passada é a que manda, então tem que ser a do dígito mais
> importante. O número de passadas vem do **maior** elemento, não do primeiro.

> [!TIP]
> **Por dentro do C:** na **base 256**, o "dígito" é um byte, e
> `(x >> 8 * b) & 0xFF` (assunto 0065) é o byte `b` de `x`. Um `int` de 32
> bits faz 4 passadas, com `c[256]`.

> [!NOTE]
> **Pergunta para você:** este código funciona com números negativos? Veja o
> que `(-47 / 1) % 10` dá em C (o resto tem o sinal do dividendo) e em que
> posição de `c` isso cairia.

{{pratique}}
