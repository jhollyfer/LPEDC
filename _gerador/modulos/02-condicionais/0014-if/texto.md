## 0014 · if

- **`if`**: a **seleção simples**. Com a condição verdadeira, roda o bloco;
  com ela falsa, pula o bloco e segue. Um passo extra ou nada
  (DEITEL; DEITEL, 2011, cap. 3).

```c
if (condição) {
    // só roda quando a condição é verdadeira
}
// daqui em diante roda sempre
```

- **Condição**: entre parênteses, qualquer expressão numérica: comparação,
  combinação lógica ou variável sozinha. Zero é falso, o resto é verdade:
  `if (saldo)` é `if (saldo != 0)` (BACKES, 2013, cap. 4).
- **Bloco**: as chaves agrupam quantas instruções quiser. Sem chaves, o `if`
  controla **uma** instrução só, a primeira depois dele
  (BACKES, 2013, cap. 4).

```c
if (total >= 200)
    total = total * 0.9;   // depende do if
printf("Pronto\n");        // NÃO depende, apesar de qualquer recuo
```

- **Recuo**: só para quem lê; o compilador o ignora. Por isso o curso usa
  **chaves sempre**, mesmo com uma linha só (KERNIGHAN; RITCHIE, 1988, cap. 3).

> [!WARNING]
> **O `;` depois do `if` mata a condição.** Em `if (total >= 200);`, o `;` é
> uma **instrução vazia** e vira o corpo; o bloco seguinte roda **sempre**. O
> `-Wextra` avisa ("suggest braces around empty body").

{{exemplo}}

No mercado, compras a partir de R$ 200 ganham 10% de desconto. Entram
R$ 230, a resposta é Sim e o valor final é R$ 207; com Não, a seta cinza iria
direto ao final (`%%` mostra um `%` no `printf`):

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double total = 230.0;

    printf("Total: R$ %.2f\n", total);
    if (total >= 200) {
        total = total * 0.9; // 10% de desconto
        printf("Desconto de 10%% aplicado!\n");
    }
    printf("A pagar: R$ %.2f\n", total);
    return 0;
}
// Saída:
// Total: R$ 230.00
// Desconto de 10% aplicado!
// A pagar: R$ 207.00
```

A saída Não do losango não faz nada: vai direto ao "Mostrar", onde o Sim chega
depois do desconto:

{{fluxograma}}
