## 0131 · Divisão e conquista

- **Divisão e conquista** (*divide and conquer*): resolve o problema
  quebrando-o em pedaços menores do mesmo tipo (CORMEN et al., 2024, cap. 4).
- **Três passos**: **dividir** em pedaços menores; **conquistar** cada pedaço
  com a própria função (recursão, assunto 0032); **combinar** as respostas
  (CORMEN et al., 2024, cap. 4).
- **Caso base**: o pedaço pequeno o bastante para resolver direto
  (ZIVIANI, 2010, cap. 2).
- **Onde fica o esforço**: o merge sort (0094) gasta na combinação; o quick
  sort (0095), na divisão, e não combina; a busca binária (0090) descarta uma
  metade (FEOFILOFF, 2009).
- **Potência rápida**: xⁿ = (x^(n/2))², com mais um `x` se `n` é ímpar. O
  caso base é `n == 0`, pois x⁰ = 1 (LINTZMAYER; MOTA, 2023).
- **Custo**: T(n) = T(n/2) + O(1), que dá **O(log n)** pelo teorema mestre
  (assunto 0115). Para n = 1 milhão, uns 20 níveis (CORMEN et al., 2024, cap. 4).
- **Pedaços repetidos**: divisão e conquista só compensa quando os pedaços
  **não se repetem** (ZIVIANI, 2010, cap. 2).

> [!WARNING]
> `return potencia(x, n / 2) * potencia(x, n / 2);` dá o resultado certo, mas
> faz **duas** chamadas por nível: T(n) = 2T(n/2) + O(1), que é O(n). Guarde a
> metade numa variável.

{{exemplo}}

Numa corrente de mensagens, cada um repassa para 3 contatos: na rodada 20,
saem 3²⁰. A recursão desce dividindo o expoente (20, 10, 5, 2, 1, 0) e sobe
combinando: o 1 do caso base vira 3, 9, 243, até 3²⁰.

{{ideia}}

```c
#include <stdio.h>

static int mult = 0; // quantas multiplicações foram feitas

// x elevado a n, dividindo o expoente ao meio
long long potencia(long long x, int n) {
    if (n == 0) {
        return 1;                          // caso base: x^0 = 1
    }
    long long metade = potencia(x, n / 2); // conquista: resolve o pedaço menor
    long long r;
    if (n % 2 == 0) {
        r = metade * metade;               // combina: x^n = (x^(n/2))^2
        mult += 1;
    } else {
        r = metade * metade * x;           // n ímpar: sobra um x
        mult += 2;
    }
    printf("3^%-2d = %lld\n", n, r);
    return r;
}

int main(void) {
    long long total = potencia(3, 20);
    printf("Na rodada 20: %lld mensagens\n", total);
    printf("%d multiplicações (o laço simples faria 19)\n", mult);
    return 0;
}
// Saída:
// 3^1  = 3
// 3^2  = 9
// 3^5  = 243
// 3^10 = 59049
// 3^20 = 3486784401
// Na rodada 20: 3486784401 mensagens
// 7 multiplicações (o laço simples faria 19)
```

Os resultados saem de baixo para cima, pela pilha de chamadas (0031). Cuidado
com o estouro: 3³⁹ cabe num `long long`, 3⁴⁰ não. O fluxograma segue a chamada
com `n = 20`:

{{fluxograma}}
