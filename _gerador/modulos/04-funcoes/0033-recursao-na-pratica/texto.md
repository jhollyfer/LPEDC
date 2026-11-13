## 0033 · Recursão na prática: Fibonacci, Hanói e Euclides

- **Fibonacci**: 0, 1, 1, 2, 3, 5, 8... `fib(0) = 0`, `fib(1) = 1` e
  `fib(n) = fib(n - 1) + fib(n - 2)`: dois casos base e **duas** chamadas
  (BACKES, 2013, cap. 9).
- **Árvore de chamadas**: um nó por chamada. Em `fib`, as duas chamadas não se
  comunicam e refazem o mesmo trabalho; o número de nós cresce de forma
  **exponencial** (DEITEL; DEITEL, 2011, cap. 5).
- **Tempo e memória**: o tempo segue o número de nós da árvore; a memória
  segue a altura, no máximo `n` quadros, porque um galho sai da pilha antes do
  seguinte (FEOFILOFF, 2009, cap. 5).
- **Torre de Hanói**: para levar `n` discos de A para C, leve `n - 1` para B,
  o maior para C e os `n - 1` de B para C. São `2ⁿ - 1` movimentos, o mínimo
  possível: aqui a recursão não desperdiça nada (DEITEL; DEITEL, 2011, cap. 5).
- **MDC de Euclides**: `mdc(a, b) = mdc(b, a % b)`, e `mdc(a, 0) = a`. Uma
  chamada por vez, e o resto encolhe depressa (DEITEL; DEITEL, 2011, cap. 5).

> [!WARNING]
> Fibonacci recursivo serve para aprender custo, não para calcular. E
> `fib(47)` = 2.971.215.073 não cabe num `int` de 32 bits; com `long long` vai
> até `fib(92)`.

{{exemplo}}

Uma escada de 4 degraus, subindo de 1 em 1 ou pulando 2, tem `fib(5) = 5`
jeitos. A árvore de `fib(5)` tem 15 nós, e os dois amarelos são `fib(3)`
calculado duas vezes:

{{ideia}}

```c
#include <stdio.h>

long chamadas = 0; // conta quantas vezes fib foi chamada

int fib(int n) {
    chamadas++;
    if (n < 2) {
        return n; // fib(0) = 0 e fib(1) = 1
    }
    return fib(n - 1) + fib(n - 2); // duas chamadas por vez
}

int main(void) {
    for (int n = 5; n <= 30; n += 5) {
        chamadas = 0;
        int resultado = fib(n);
        printf("fib(%d) = %d, com %ld chamadas\n", n, resultado, chamadas);
    }
    return 0;
}
// Saída:
// fib(5) = 5, com 15 chamadas
// fib(10) = 55, com 177 chamadas
// fib(15) = 610, com 1973 chamadas
// fib(20) = 6765, com 21891 chamadas
// fib(25) = 75025, com 242785 chamadas
// fib(30) = 832040, com 2692537 chamadas
```

Quase 2,7 milhões de chamadas para `fib(30)`, contra 30 passos de um laço. No
fluxograma, a segunda chamada só começa quando a primeira volta:

{{fluxograma}}

### Passo a passo

O MDC de Euclides em C é `return b == 0 ? a : mdc(b, a % b);`. O teste de
mesa de `mdc(1071, 462)`:

| Chamada | a | b | a % b |
| --- | --- | --- | --- |
| `mdc(1071, 462)` | 1071 | 462 | 147 |
| `mdc(462, 147)` | 462 | 147 | 21 |
| `mdc(147, 21)` | 147 | 21 | 0 |
| `mdc(21, 0)` | 21 | 0 | caso base: devolve **21** |
