## 0166 · O, Ω e Θ de verdade

A empresa que vendeu o sistema de caixa do mercadinho escreveu no contrato:
"o fechamento do dia com `n` vendas faz no máximo `4n²` operações, a partir
de 12 vendas". Você mediu o programa e contou exatamente
`f(n) = 3n² + 10n + 20` operações. A promessa vale? Para 10 vendas, o
fechamento faz 420 operações e `4 · 10² = 400`: estourou. O contrato mentiu?

Não. Ele disse "a partir de 12", e as definições de **O**, **Ω** e **Θ**
funcionam assim, com duas constantes que você escolhe: o fator **c** e o
ponto de partida **n₀**.

- **f(n) é O(g(n))** se existem `c > 0` e `n₀` tais que
  `f(n) ≤ c · g(n)` para todo `n ≥ n₀`. É um **teto**.
- **f(n) é Ω(g(n))** se existem `c > 0` e `n₀` tais que
  `f(n) ≥ c · g(n)` para todo `n ≥ n₀`. É um **piso**.
- **f(n) é Θ(g(n))** se é O e Ω ao mesmo tempo: existem `c₁`, `c₂` e `n₀`
  com `c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)` para todo `n ≥ n₀`. É um **sanduíche**.

O **n₀** existe porque só interessa o que acontece com `n` grande: para
poucas vendas, os termos `10n` e `20` ainda pesam. O **c** existe porque a
constante depende da máquina e de detalhes do código; o formato do
crescimento, não.

**Provar** um limite é exibir um par `c`, `n₀` que funciona e mostrar a conta.
Para o teto com `c = 4`: `3n² + 10n + 20 ≤ 4n²` vira `n² - 10n - 20 ≥ 0`, que
vale para `n ≥ 12` (a raiz é 11,7). Para o piso com `c = 3`: `3n² + 10n + 20 ≥
3n²` vale para todo `n ≥ 1`. Logo `f(n)` é **Θ(n²)**, com `c₁ = 3`, `c₂ = 4` e
`n₀ = 12`.

**Refutar** é o contrário: mostrar que **nenhum** par serve. `f(n)` é O(n)?
Seria preciso `3n² + 10n + 20 ≤ c · n`, isto é, `3n + 10 + 20/n ≤ c`. Para
qualquer `c` que alguém escolha, basta `n > c/3` e a desigualdade quebra. Não
existe teto linear.

Há ainda um terceiro eixo, independente de O, Ω e Θ: **qual entrada**.
O **melhor caso** é a entrada de tamanho `n` que dá menos trabalho, o **pior
caso** é a que dá mais, e o **caso médio** é a média sobre todas as entradas
(com alguma hipótese de probabilidade). Cada caso é uma **função de n
diferente**, e cada uma ganha o seu O, Ω ou Θ. Na busca sequencial, o melhor
caso é Θ(1) e o pior é Θ(n).

A tabela mostra o custo medido e o teto `4n²` para `n` de 6 a 15. Até 11, o teto fica abaixo do custo (vermelho); de 12 em
diante, fica acima e não cruza mais (verde). O `n₀` é a primeira coluna verde:

{{ideia}}

O programa faz a busca que você faria à mão: testa todo `n` até 100 mil e
guarda o último que falhou. O `n₀` é o seguinte a ele:

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

O fluxograma é a função `n0_teto`. Ela não para no primeiro `n` que funciona:
percorre tudo e **empurra** o `n₀` para depois de cada falha, que é como se
escreve "para todo `n ≥ n₀`" num laço. Na última parte da saída, com
`c = 1000`, o teto linear aguenta até 329 e depois quebra para sempre. Com
qualquer `c` acontece o mesmo, só que mais longe:


{{fluxograma}}

> [!WARNING]
> O, Ω e Θ **não** são "pior, melhor e médio". São tipos de limite (teto,
> piso, sanduíche), e você pode aplicar qualquer um deles a qualquer caso.
> "O pior caso da busca sequencial é Θ(n)" e "o melhor caso é Θ(1)" são duas
> frases certas. "A busca sequencial é Ω(n)" é falsa, porque o melhor caso
> termina em 1 comparação. E um programa que testa até 100 mil **não prova**
> nada para 100 mil e um: ele só acha candidatos. A prova é a conta
> `n² - 10n - 20 ≥ 0`.

> [!TIP]
> **Por dentro do C:** o `c` esconde a máquina. As 20 operações fixas e o
> `3` do `3n²` dependem de quantas instruções o `gcc` gera para cada linha, e
> isso muda com `-O0` ou `-O2`, com o processador, com o tipo (`int` ou
> `double`). O `g(n)` não muda: dobrar `n` quadruplica o trabalho em qualquer
> máquina. Um cuidado de C no próprio teste: `3 * n * n` com `n` do tipo
> `int` estoura perto de `n = 26.755` (passa de 2.147.483.647, o maior `int`),
> e estouro de `int` com sinal é comportamento indefinido. Por isso o
> programa usa `long`, que no Linux de 64 bits tem 8 bytes.

> [!NOTE]
> **Pergunta para você:** com `c = 3.1`, qual é o menor `n₀` do teto? Faça a
> conta `0,1 n² - 10n - 20 ≥ 0` antes de trocar o `3.5` por `3.1` no programa.
> O que acontece com o `n₀` quando o `c` chega perto de 3?

{{pratique}}
