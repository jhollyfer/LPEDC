## 0166 · O, Ω e Θ de verdade

O contrato do caixa do mercadinho diz: "o fechamento com `n` vendas faz no
máximo `4n²` operações, a partir de 12 vendas". Você contou
`f(n) = 3n² + 10n + 20`. Com 10 vendas são 420 contra 400: estourou? Não, ele
disse "a partir de 12". **O**, **Ω** e **Θ** funcionam assim, com duas
constantes: o fator **c** e o ponto de partida **n₀**.

- **f(n) é O(g(n))** se existem `c > 0` e `n₀` tais que
  `f(n) ≤ c · g(n)` para todo `n ≥ n₀`. É um **teto**.
- **f(n) é Ω(g(n))** se existem `c > 0` e `n₀` tais que
  `f(n) ≥ c · g(n)` para todo `n ≥ n₀`. É um **piso**.
- **f(n) é Θ(g(n))** se é O e Ω ao mesmo tempo: existem `c₁`, `c₂` e `n₀`
  com `c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)` para todo `n ≥ n₀`. É um **sanduíche**.

O **n₀** existe porque só interessa o `n` grande, onde `10n` e `20` já não
pesam. O **c** existe porque a constante depende da máquina.

**Provar** é exibir `c` e `n₀` e mostrar a conta. Teto com `c = 4`:
`3n² + 10n + 20 ≤ 4n²` vira `n² - 10n - 20 ≥ 0`, que vale para `n ≥ 12` (a
raiz é 11,7). Piso com `c = 3`: vale para todo `n ≥ 1`. Logo `f(n)` é
**Θ(n²)**, com `c₁ = 3`, `c₂ = 4` e `n₀ = 12`.

**Refutar** é mostrar que **nenhum** par serve. `f(n)` é O(n)? Exigiria
`3n + 10 + 20/n ≤ c`, e `n > c/3` quebra para qualquer `c`.

Outro eixo, independente, é **qual entrada**: o **melhor caso** dá menos
trabalho, o **pior caso** mais, e o **caso médio** é a média. Cada caso é uma
**função de n diferente**, com seu próprio O, Ω ou Θ. Na busca sequencial, o
melhor caso é Θ(1) e o pior é Θ(n).

Custo medido e teto `4n²` para `n` de 6 a 15: até 11 o teto fica abaixo
(vermelho); de 12 em diante, acima (verde). O `n₀` é a primeira coluna verde:

{{ideia}}

O programa testa todo `n` até 100 mil e guarda o último que falhou; o `n₀` é
o seguinte:

```c
#include <stdio.h>

#define LIMITE 100000

// passos medidos no fechamento do caixa com n vendas
long custo(long n) {
    return 3 * n * n + 10 * n + 20;
}

// O: menor n0 com custo(n) <= c * n² para todo n de n0 até LIMITE
long n0_teto(double c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) > c * n * n) {
            n0 = n + 1;                 // falhou aqui: n0 tem que vir depois
        }
    }
    return n0;
}

// Ω: menor n0 com custo(n) >= c * n² para todo n de n0 até LIMITE
long n0_piso(double c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) < c * n * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    printf(" n   custo(n)   4n²\n");
    for (long n = 10; n <= 14; n++) {
        printf("%2ld %10ld %5ld\n", n, custo(n), 4 * n * n);
    }

    double tetos[] = {4.0, 3.5, 3.0};
    for (int i = 0; i < 3; i++) {
        long n0 = n0_teto(tetos[i]);
        if (n0 > LIMITE) {
            printf("O(n²) com c = %.1f: nenhum n0 até %d\n", tetos[i], LIMITE);
        } else {
            printf("O(n²) com c = %.1f: n0 = %ld\n", tetos[i], n0);
        }
    }
    printf("Ω(n²) com c = 3.0: n0 = %ld\n", n0_piso(3.0));

    // refutar O(n): para cada c, o custo passa de c·n e não volta mais
    long cs[] = {10, 100, 1000};
    for (int i = 0; i < 3; i++) {
        long ultimo_ok = 0;
        for (long n = 1; n <= LIMITE; n++) {
            if (custo(n) <= cs[i] * n) {
                ultimo_ok = n;
            }
        }
        printf("O(n) com c = %4ld: falha de n = %ld em diante\n", cs[i], ultimo_ok + 1);
    }
    return 0;
}
// Saída:
//  n   custo(n)   4n²
// 10        420   400
// 11        493   484
// 12        572   576
// 13        657   676
// 14        748   784
// O(n²) com c = 4.0: n0 = 12
// O(n²) com c = 3.5: n0 = 22
// O(n²) com c = 3.0: nenhum n0 até 100000
// Ω(n²) com c = 3.0: n0 = 1
// O(n) com c =   10: falha de n = 1 em diante
// O(n) com c =  100: falha de n = 30 em diante
// O(n) com c = 1000: falha de n = 330 em diante
```

A função `n0_teto` **empurra** o `n₀` para depois de cada falha: é "para
todo `n ≥ n₀`" num laço. Com `c = 1000`, o teto linear aguenta até 329 e
quebra para sempre:


{{fluxograma}}

> [!WARNING]
> O, Ω e Θ **não** são "pior, melhor e médio": são teto, piso e sanduíche, e
> valem para qualquer caso. "A busca sequencial é Ω(n)" é falsa, pois o melhor
> caso faz 1 comparação. E testar até 100 mil **não prova** nada além: só acha
> candidatos. A prova é a conta `n² - 10n - 20 ≥ 0`.

> [!TIP]
> No teste, `3 * n * n` com `int` estoura perto de `n = 26.755`
> (comportamento indefinido); por isso o programa usa `long`.

> [!NOTE]
> **Pergunta para você:** com `c = 3.1`, qual é o menor `n₀` do teto? Faça a
> conta `0,1 n² - 10n - 20 ≥ 0` antes de trocar o `3.5` por `3.1` no programa.
> O que acontece com o `n₀` quando `c` chega perto de 3?

{{pratique}}
