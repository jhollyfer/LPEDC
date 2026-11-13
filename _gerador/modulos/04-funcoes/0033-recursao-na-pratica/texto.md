## 0033 · Recursão na prática: Fibonacci, Hanói e Euclides

O fatorial do assunto 0032 faz uma chamada recursiva por vez, e o custo é
fácil de prever. Muitos problemas pedem mais de uma chamada, e aí a recursão
pode sair muito barata ou muito cara, dependendo do caso. Três clássicos da
prova mostram os dois lados: Fibonacci, que desperdiça trabalho; a Torre de
Hanói, que não desperdiça nada; e o MDC de Euclides, que encolhe depressa.

Comece pela escada do prédio. Ela tem 4 degraus, e você sobe de 1 em 1 ou
pulando 2. De quantos jeitos dá para subir? Pense no último passo: você
chegou ao degrau 4 vindo do 3, com um passo, ou vindo do 2, com um pulo.
Então os jeitos de chegar ao 4 são os jeitos de chegar ao 3 **mais** os de
chegar ao 2. Cada resposta é a soma das duas anteriores: 1, 2, 3, 5. São 5
jeitos.

Essa conta gera a sequência de **Fibonacci**: 0, 1, 1, 2, 3, 5, 8, 13, 21...
Cada termo é a soma dos dois anteriores, e os dois primeiros são dados. A
definição já nasce recursiva (BACKES, 2013, cap. 9). Há **dois** casos base,
`fib(0) = 0` e `fib(1) = 1`, e um caso recursivo com **duas** chamadas:
`fib(n) = fib(n - 1) + fib(n - 2)`. A escada de 4 degraus é `fib(5) = 5`.

O código tem três linhas e funciona, mas custa caro. Para ver por quê,
desenhe a **árvore de chamadas**: um nó para cada chamada, ligado aos nós das
chamadas que ele faz (DEITEL; DEITEL, 2011, cap. 5). Cada `fib` gera mais
duas, e essas duas não se comunicam. Para calcular `fib(5)`, a árvore calcula
`fib(3)` duas vezes e `fib(2)` três vezes, sempre do zero. O total chega a 15
nós. A cada `n` a mais, o número de chamadas quase dobra, e o crescimento é
**exponencial**: `fib(30)` já faz perto de 2,7 milhões de chamadas.

A árvore ajuda a separar duas medidas (FEOFILOFF, 2009, cap. 5). O **tempo**
de `fib(n)` acompanha o número de nós, que cresce como 1,618ⁿ. A **memória**
acompanha a altura da árvore, que é no máximo `n`. O programa desce um galho
de cada vez; quando um galho termina, seus quadros saem da pilha e o espaço
serve ao galho seguinte. Por isso `fib(40)` demora, mas não estoura a pilha.
Um laço com duas variáveis, `anterior` e `atual`, faz a mesma conta em `n`
passos. Quando as chamadas **repetem trabalho**, desconfie da recursão.

A **Torre de Hanói** mostra o outro lado. São três estacas, A, B e C, e
discos de tamanhos diferentes empilhados em A, o maior embaixo. O objetivo é
levar todos para C, movendo um disco por vez, sem nunca pôr um disco maior
sobre um menor. Pensando recursivamente, a solução tem três passos
(DEITEL; DEITEL, 2011, cap. 5). Mova os `n - 1` discos de cima de A para B,
usando C de apoio. Mova o disco maior de A para C. Mova os `n - 1` discos de
B para C, usando A de apoio. O primeiro e o terceiro passos são o mesmo
problema com um disco a menos e com as estacas trocadas de papel; por isso a
função recebe as três estacas como parâmetro.

Com `n` discos, a solução faz `2ⁿ - 1` movimentos, e não existe jeito mais
curto. As duas chamadas de Hanói resolvem pedaços diferentes do problema, sem
repetir nada, e a recursão aqui não desperdiça trabalho. O custo continua
exponencial, mas porque o próprio problema exige tantos movimentos.

O terceiro clássico é o **máximo divisor comum** (MDC), com uma recursão de
mais de 2.000 anos, atribuída a Euclides: o MDC de `a` e `b` é o MDC de `b` e
`a % b`, e, quando o segundo número chega a 0, o primeiro é a resposta
(DEITEL; DEITEL, 2011, cap. 5). Em `mdc(1071, 462)`, as chamadas passam por
`mdc(462, 147)`, `mdc(147, 21)` e `mdc(21, 0)`, que devolve 21. Há uma
chamada por vez, como no fatorial, e o resto encolhe tão depressa que poucos
passos bastam até para números enormes.

> [!WARNING]
> Fibonacci recursivo serve para aprender recursão e custo, não para
> calcular. E `fib(47)` = 2.971.215.073 não cabe num `int` de 32 bits, que vai
> até 2.147.483.647. Com `long long`, a conta vai até `fib(92)`.

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
