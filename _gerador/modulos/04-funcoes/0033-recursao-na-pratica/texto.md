## 0033 · Recursão na prática: Fibonacci, Hanói e Euclides

A escada do prédio tem 4 degraus, e você sobe de 1 em 1 ou pulando 2. De
quantos jeitos dá para subir? Pense no último passo: você veio do degrau 3 (um
passo) ou do 2 (um pulo). Os jeitos de chegar ao 4 são os do 3 **mais** os do
2. Cada resposta é a soma das duas anteriores: 1, 2, 3, 5... São 5 jeitos.

Essa é a sequência de **Fibonacci**: 0, 1, 1, 2, 3, 5, 8, 13, 21... Cada termo
é a soma dos dois anteriores, e os dois primeiros são dados. A definição já é
recursiva:

- `fib(0) = 0` e `fib(1) = 1` (dois casos base);
- `fib(n) = fib(n - 1) + fib(n - 2)` (o caso recursivo, com **duas**
  chamadas).

A escada de 4 degraus é `fib(5) = 5`. O código tem três linhas e funciona, mas
custa caro. Cada chamada de `fib` gera mais duas, que não se comunicam:
`fib(5)` calcula `fib(3)` duas vezes e `fib(2)` três, refazendo o trabalho do
zero. As chamadas quase dobram a cada `n` a mais: o crescimento é
**exponencial**.

A **árvore de chamadas** de `fib(5)` tem 15 nós, um por chamada (o número no
círculo é o `n`). Os dois nós amarelos são `fib(3)`: o mesmo cálculo, com tudo
o que vem embaixo, feito duas vezes. A pilha nunca passa de 5 quadros de `fib`,
porque o programa desce um galho de cada vez:

{{ideia}}

O programa conta as chamadas com uma global:

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

Quase 2,7 milhões de chamadas para `fib(30)`. Um laço com duas variáveis
(`anterior` e `atual`) faz a conta em 30 passos. Para `fib(50)`, a versão
recursiva levaria minutos; o laço, microssegundos. Quando as chamadas **repetem
trabalho**, desconfie.

No fluxograma, o caso recursivo tem duas chamadas em sequência. A segunda só
começa quando a primeira voltou com a resposta inteira:

{{fluxograma}}

### Quando a recursão é a melhor ideia: Hanói

A **Torre de Hanói** tem três estacas (A, B e C) e discos de tamanhos
diferentes em A, o maior embaixo. Leve todos para C, um disco por vez, sem pôr
um maior sobre um menor. Parece difícil até você pensar recursivamente. Para
mover `n` discos de A para C:

1. mova os `n - 1` de cima de A para B (usando C de apoio);
2. mova o disco maior de A para C;
3. mova os `n - 1` de B para C (usando A de apoio).

Os passos 1 e 3 são o mesmo problema com um disco a menos e com as estacas
trocadas de papel. Por isso a função recebe as três estacas como parâmetro. O
exemplo A066 resolve 3 discos em 7 movimentos. Com `n` discos são `2ⁿ - 1`
movimentos, e não existe jeito mais curto: aqui a recursão não desperdiça
nada.

### Passo a passo: o MDC de Euclides

O **máximo divisor comum** tem uma recursão de 2.300 anos: o MDC de `a` e `b` é
o MDC de `b` e `a % b`; quando o segundo vira 0, o primeiro é a resposta. Em C:
`return b == 0 ? a : mdc(b, a % b);`. O teste de mesa de `mdc(1071, 462)`:

| Chamada | a | b | a % b |
| --- | --- | --- | --- |
| `mdc(1071, 462)` | 1071 | 462 | 147 |
| `mdc(462, 147)` | 462 | 147 | 21 |
| `mdc(147, 21)` | 147 | 21 | 0 |
| `mdc(21, 0)` | 21 | 0 | caso base: devolve **21** |

Quatro chamadas para números na casa do milhar: o resto cai muito rápido.
Euclides faz **uma** chamada por vez e encolhe depressa, por isso sai barato.

> [!WARNING]
> Fibonacci recursivo serve para aprender recursão e custo, não para calcular.
> Outra pegadinha: `fib(47)` não cabe num `int` de 32 bits (dá 2.971.215.073,
> acima de 2.147.483.647). Com `unsigned` vai até `fib(47)`, com `long long`
> até `fib(92)`.

> [!TIP]
> A árvore mostra o **tempo** e a pilha mostra a **memória**. O tempo de
> `fib(n)` é proporcional ao número de nós da árvore, que cresce como 1,618ⁿ.
> A memória é a altura da árvore: no máximo `n` quadros ao mesmo tempo, porque
> quando um galho termina, seus quadros saem da pilha e o espaço é reaproveitado
> pelo galho seguinte. Por isso `fib(40)` demora, mas não estoura a pilha.

> [!NOTE]
> **Pergunta para você:** quantas vezes `fib(1)` é chamada dentro de
> `fib(5)`? Conte na árvore antes de alterar o programa para contar.

{{pratique}}
