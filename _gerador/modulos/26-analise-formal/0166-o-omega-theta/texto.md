## 0166 · O, Ω e Θ de verdade

- **O (teto)**: `f(n)` é O(g(n)) se existem `c > 0` e `n₀` com
  `f(n) ≤ c · g(n)` para todo `n ≥ n₀` (CORMEN et al., 2024, cap. 3).
- **Ω (piso)**: o mesmo com `f(n) ≥ c · g(n)` para todo `n ≥ n₀`
  (CORMEN et al., 2024, cap. 3).
- **Θ (sanduíche)**: é O e Ω ao mesmo tempo, com `c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)`
  a partir de `n₀` (ZIVIANI, 2010, cap. 1).
- **c e n₀**: o `c` absorve a constante da máquina; o `n₀` descarta os `n`
  pequenos. Nenhum dos dois é único (LINTZMAYER; MOTA, 2023).
- **Provar** é exibir `c` e `n₀` e fazer a conta. **Refutar** é mostrar que
  nenhum par serve: para `3n² + 10n + 20` ser O(n) seria preciso
  `3n + 10 + 20/n ≤ c`, e `n > c/3` quebra qualquer `c` (FEOFILOFF, s.d.).
- **Melhor, pior e caso médio**: a entrada que dá menos trabalho, a que dá
  mais e a média sobre uma distribuição. Cada caso é uma função de `n` com seu
  próprio O, Ω ou Θ (SZWARCFITER; MARKENZON, 2010, cap. 1).
- **Contas no programa**: `3 * n * n` com `int` estoura perto de
  `n = 26.755`; por isso o exemplo usa `long`.

| Notação | Desigualdade (para `n ≥ n₀`) | Papel |
| --- | --- | --- |
| O(g) | `f(n) ≤ c · g(n)` | teto |
| Ω(g) | `f(n) ≥ c · g(n)` | piso |
| Θ(g) | `c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)` | sanduíche |

> [!WARNING]
> O, Ω e Θ **não** são pior, melhor e médio: valem para qualquer caso. "A busca
> sequencial é Ω(n)" é falsa, pois o melhor caso faz 1 comparação. E testar até
> 100 mil só acha candidatos: a prova é a conta.

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
