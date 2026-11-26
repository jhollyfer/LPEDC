## 0166 · O, Ω e Θ de verdade

Até aqui, dizer que um algoritmo é O(n²) queria dizer, sem muito rigor, que
o custo "cresce como n²". A prova do mestrado cobra mais: cobra a definição
com constantes, e cobra que você saiba provar e refutar uma afirmação como
"`3n² + 10n + 20` é O(n)". A seguir vêm as três notações no papel, do
jeito que o Cormen as define.

Pense no contrato do sistema de caixa de um mercadinho. Ele diz: "o
fechamento com `n` vendas faz no máximo `4n²` operações, a partir de 12
vendas". Você contou as operações e chegou a `f(n) = 3n² + 10n + 20`. Com 10
vendas, são 420 operações contra um limite de 400. O contrato foi quebrado?
Não, porque ele só promete a partir de 12 vendas. As notações funcionam
assim, com duas constantes: um fator **c** que multiplica a função de
referência e um ponto de partida **n₀** a partir do qual a promessa vale.

A primeira notação é o **teto**. Dizemos que **f(n) é O(g(n))** se existem
constantes `c > 0` e `n₀` tais que `f(n) ≤ c · g(n)` para todo `n ≥ n₀`
(CORMEN et al., 2024, cap. 3). Em palavras: depois de certo ponto, `f` nunca
passa de um múltiplo fixo de `g`. O contrato do caixa afirma que o custo é
O(n²), com `c = 4` e `n₀ = 12`.

A segunda é o **piso**, a mesma ideia virada ao contrário. **f(n) é
Ω(g(n))** (lê-se "ômega de g") se existem `c > 0` e `n₀` tais que
`f(n) ≥ c · g(n)` para todo `n ≥ n₀` (CORMEN et al., 2024, cap. 3). Depois
de certo ponto, `f` nunca fica abaixo de um múltiplo fixo de `g`.

A terceira junta as duas. **f(n) é Θ(g(n))** (lê-se "teta de g") se é O e
Ω ao mesmo tempo: existem `c₁`, `c₂` e `n₀` com
`c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)` para todo `n ≥ n₀` (ZIVIANI, 2010, cap. 1).
É um **sanduíche**: `f` fica presa entre dois múltiplos de `g`, e por isso
Θ diz que as duas funções crescem no mesmo ritmo.

Por que as duas constantes? O **n₀** existe porque só interessa o
comportamento para `n` grande; para `n` pequeno, termos como `10n` e `20`
ainda pesam e atrapalham. O **c** existe porque a constante depende da
máquina e do compilador, e a notação quer falar do algoritmo. Nenhum dos
dois é único: se `c = 4` e `n₀ = 12` servem, `c = 5` com o mesmo `n₀`
também serve (LINTZMAYER; MOTA, 2023).

**Provar** que `f` é O(g) é exibir um par `c`, `n₀` e mostrar a conta. Para
o teto com `c = 4`, a desigualdade `3n² + 10n + 20 ≤ 4n²` vira
`n² - 10n - 20 ≥ 0`. A raiz positiva de `n² - 10n - 20` é 11,7, então a
desigualdade vale para todo `n ≥ 12`. Para o piso com `c = 3`, a
desigualdade `3n² + 10n + 20 ≥ 3n²` vale para todo `n ≥ 1`. Logo `f(n)` é
**Θ(n²)**, com `c₁ = 3`, `c₂ = 4` e `n₀ = 12`.

**Refutar** é mostrar que **nenhum** par serve, o que é bem diferente de
não achar um. `f(n)` é O(n)? Seria preciso `3n² + 10n + 20 ≤ c · n`.
Dividindo tudo por `n`, isso vira `3n + 10 + 20/n ≤ c`. Só que o lado
esquerdo cresce sem limite: para qualquer `c` que alguém proponha, basta
tomar `n > c/3` e a desigualdade quebra. Então não existe `c`, e `f` não é
O(n) (FEOFILOFF, s.d.).

Há outro eixo, independente das notações: **qual entrada** você está
olhando. Para o mesmo `n`, o **melhor caso** é a entrada que dá menos
trabalho, o **pior caso** a que dá mais, e o **caso médio** é a média sobre
todas as entradas, segundo alguma distribuição de probabilidade
(SZWARCFITER; MARKENZON, 2010, cap. 1). Cada caso é uma função de `n`
diferente, e cada uma tem o seu O, Ω ou Θ. Na busca sequencial, o melhor
caso é Θ(1), achar no primeiro, e o pior é Θ(n), não achar.

Ao testar uma desigualdade num programa, cuidado com o tamanho das contas:
`3 * n * n` com `int` estoura perto de `n = 26.755`, e estouro de inteiro
com sinal é comportamento indefinido. Por isso o exemplo usa `long`.

| Notação | Desigualdade (para `n ≥ n₀`) | Papel |
| --- | --- | --- |
| O(g) | `f(n) ≤ c · g(n)` | teto |
| Ω(g) | `f(n) ≥ c · g(n)` | piso |
| Θ(g) | `c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)` | sanduíche |

> [!WARNING]
> O, Ω e Θ **não** são "pior, melhor e médio": são teto, piso e sanduíche, e
> valem para qualquer caso. "A busca sequencial é Ω(n)" é falsa, pois o
> melhor caso faz 1 comparação. E testar até 100 mil **não prova** nada além
> disso: só acha candidatos. A prova é a conta `n² - 10n - 20 ≥ 0`.

{{exemplo}}

O fechamento de um caixa custa `f(n) = 3n² + 10n + 20` passos. O teto `4n²`
fica abaixo até `n = 11` e acima de 12 em diante; o `n₀` é a primeira coluna
verde:

{{ideia}}

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

A função `n0_teto` empurra o `n₀` para depois de cada falha; com `c = 1000`, o
teto linear aguenta até 329 e quebra para sempre:

{{fluxograma}}
