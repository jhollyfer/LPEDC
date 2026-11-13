## 0015 · if/else e o = no lugar do ==

- **`if/else`**: a **seleção dupla**. Exatamente um dos dois blocos roda,
  nunca os dois e nunca nenhum (DEITEL; DEITEL, 2011, cap. 3).

```c
if (condição) {
    // caminho do Sim
} else {
    // caminho do Não
}
```

- **`else` sem condição**: é "todo o resto". `else (saldo < 5)` é erro; outra
  pergunta vira um novo `if` (0016) (BACKES, 2013, cap. 4).
- **Chaves e `;`**: sem chaves, o `else` controla uma instrução só. Em
  `if (c); { ... } else { ... }`, o `else` fica sem `if` e não compila
  (DEITEL; DEITEL, 2011, cap. 3).
- **Atribuição é expressão**: vale o valor guardado. Por isso `if (saldo = 0)`
  **guarda 0** e testa esse 0, que é falso; `if (opcao = 1)` é sempre verdade
  (DEITEL; DEITEL, 2011, cap. 4).
- **Avisos**: o `-Wall` acusa "suggest parentheses around assignment used as
  truth value". Código bom compila com zero avisos (GNU, s.d.).

> [!WARNING]
> **`=` no lugar de `==`** compila e erra em silêncio: com `if (saldo = 0)`, o
> saldo vira zero e o `else` roda sempre. Compile com `-Wall` ou escreva a
> constante à esquerda: `0 = saldo` não compila.

{{exemplo}}

Na catraca do metrô, o cartão tem R$ 3,50 e a tarifa é R$ 5,00. A resposta é
Não, e o caminho de baixo é o que vale:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double saldo = 3.50;
    double tarifa = 5.00;

    if (saldo >= tarifa) {
        saldo = saldo - tarifa;
        printf("Catraca liberada. Saldo: R$ %.2f\n", saldo);
    } else {
        printf("Saldo insuficiente.\n");
        printf("Faltam R$ %.2f\n", tarifa - saldo);
    }
    return 0;
}
// Saída:
// Saldo insuficiente.
// Faltam R$ 1.50
```

Cada lado do losango tem seu bloco, e os dois se reencontram no Fim:

{{fluxograma}}
