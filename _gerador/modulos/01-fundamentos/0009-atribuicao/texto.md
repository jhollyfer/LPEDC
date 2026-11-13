## 0009 · Atribuição, ++ e --

- **Atribuição (`=`)**: guarda o valor da direita na variável da esquerda; não
  é o "igual" da matemática. `saldo = saldo + 30.00` calcula com o valor antigo
  e escreve o novo por cima (BACKES, 2013, cap. 3).
- **Lado esquerdo**: só algo com endereço, uma variável. `30 = saldo` e
  `saldo + 1 = 5` não compilam (BACKES, 2013, cap. 3).
- **Operadores compostos**: `+=`, `-=`, `*=`, `/=`, `%=`. Agem sobre **toda** a
  expressão da direita: `x *= y + 1` é `x = x * (y + 1)`
  (DEITEL; DEITEL, 2011, cap. 3).
- **`++` e `--`**: somam ou tiram 1. Sozinhos na linha, `x++` e `++x` são
  iguais (DEITEL; DEITEL, 2011, cap. 3).
- **Pós e pré**: `x++` vale o valor **antigo** e depois aumenta; `++x` aumenta
  primeiro e vale o valor **novo** (FEOFILOFF, 2009).
- **Atribuição é expressão**: vale o valor guardado e associa da direita para
  a esquerda. Em `a = b = c = 7`, o C faz `c = 7`, depois `b` e por fim `a`
  (DEITEL; DEITEL, 2011, cap. 3).

| Atalho | Quer dizer | Com `x = 10` |
| --- | --- | --- |
| `x += 3` | `x = x + 3` | 13 |
| `x -= 3` | `x = x - 3` | 7 |
| `x *= 3` | `x = x * 3` | 30 |
| `x /= 3` | `x = x / 3` | 3 (divisão inteira!) |
| `x %= 3` | `x = x % 3` | 1 |

> [!WARNING]
> Nunca altere a mesma variável duas vezes na mesma expressão, nem altere e
> leia ao mesmo tempo: `i = i++;` e `printf("%d %d", n++, n);` são
> **comportamento indefinido**. O `-Wall` avisa (`operation on 'i' may be undefined`).

{{exemplo}}

Um bilhete único com R$ 20,00 recebe uma recarga e paga duas viagens. O saldo
passa por quatro valores na mesma caixinha, e as viagens sobem de um em um:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double saldo = 20.00;
    int viagens = 0;

    saldo += 30.00;   // recarga: saldo = saldo + 30.00
    saldo -= 4.40;    // 1ª viagem
    viagens++;        // viagens = viagens + 1
    saldo -= 4.40;    // 2ª viagem
    viagens++;

    printf("Saldo: R$ %.2f depois de %d viagens\n", saldo, viagens);

    int antes = viagens++;   // pós: usa o 2, depois soma (viagens vira 3)
    int depois = ++viagens;  // pré: soma primeiro (vira 4), depois usa o 4
    printf("antes = %d, depois = %d, viagens = %d\n", antes, depois, viagens);
    return 0;
}
// Saída:
// Saldo: R$ 41.20 depois de 2 viagens
// antes = 2, depois = 4, viagens = 4
```

Cada atualização é um retângulo sobre as mesmas duas variáveis. No módulo 03,
esses passos viram laço, com `+=` e `++` como acumulador e contador:

{{fluxograma}}
