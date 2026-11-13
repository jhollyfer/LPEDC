## 0050 · Ponteiro para função

- **Ponteiro para função**: o código da função mora na memória, e o nome dela,
  sem parênteses, já é o endereço. Uma variável que guarda esse endereço é um
  ponteiro para função (BACKES, 2013, cap. 13).
- **Declaração**: `int (*criterio)(int);` lê-se de dentro para fora. Sem os
  parênteses, `int *criterio(int);` é uma função que devolve `int *` (DEITEL;
  DEITEL, 2011, cap. 7).
- **Assinatura**: o ponteiro só aceita funções com o mesmo protótipo (BACKES,
  2013, cap. 13).
- **Uso**: `criterio = eh_calor;` guarda o endereço; `criterio(31)` chama.
  `(*criterio)(31)` também vale (DEITEL; DEITEL, 2011, cap. 7).
- **Callback**: a função passada como parâmetro. A função que recebe fica
  genérica, e quem chama decide o comportamento (CELES; RANGEL, 2002).
- **`qsort`**: ordena qualquer vetor com a sua função de comparação, que recebe
  dois `const void *` e devolve negativo, zero ou positivo (o A100 usa)
  (KERRISK, s.d.).

```text
int (*criterio)(int);
```

> [!WARNING]
> `return *(const int *)a - *(const int *)b;` estoura o `int` com sinais
> opostos (`signed integer overflow`). Use `return (x > y) - (x < y);`. E
> `int *f(int)` é função, não ponteiro.

{{exemplo}}

As máximas da semana estão num vetor. `conta_se` conta os dias que passam num
critério que ela não conhece: recebe o endereço de `eh_calor` (ou `eh_frio`) e
chama por ele:

{{ideia}}

```c
#include <stdio.h>

int eh_calor(int t) { return t >= 30; }
int eh_frio(int t) { return t <= 18; }

// conta quantos elementos passam no teste; QUAL teste, quem chama decide
int conta_se(const int *v, int n, int (*criterio)(int)) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(v[i])) { // chama a função para onde criterio aponta
            cont++;
        }
    }
    return cont;
}

int main(void) {
    int temps[7] = {31, 27, 33, 18, 16, 29, 34}; // máximas da semana

    int (*regra)(int) = eh_calor;  // o nome da função já é o endereço dela
    printf("Dias de calor: %d\n", conta_se(temps, 7, regra));
    printf("Dias de frio:  %d\n", conta_se(temps, 7, eh_frio));
    return 0;
}
// Saída:
// Dias de calor: 3
// Dias de frio:  2
```

É o contador do assunto 0025; a novidade é que a pergunta do losango é a
função que chegou pelo parâmetro:

{{fluxograma}}
