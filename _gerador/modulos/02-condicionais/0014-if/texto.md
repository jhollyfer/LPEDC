## 0014 · if

No caixa do mercado, a placa avisa: compras a partir de R$ 200 ganham 10% de
desconto. Sua compra deu R$ 230. Só se a resposta for sim, a moça faz um
passo a mais.

Esse "só se" é o **`if`**:

```c
if (condição) {
    // só roda quando a condição é verdadeira
}
// daqui em diante roda sempre
```

A **condição** fica entre parênteses e pode ser qualquer expressão numérica:
uma comparação (`total >= 200`), uma combinação lógica
(`idade >= 18 && tem_cnh`) ou uma variável sozinha. Vale a regra do 0012:
**zero é falso, o resto é verdade**. `if (saldo)` equivale a
`if (saldo != 0)`, e `if (!saldo)` a `if (saldo == 0)`.

O **bloco** entre chaves aceita quantas instruções quiser. Sem chaves, o `if`
controla **uma** instrução só, a primeira depois dele:

```c
if (total >= 200)
    total = total * 0.9;   // depende do if
printf("Pronto\n");        // NÃO depende, apesar de qualquer recuo
```

O recuo é só para quem lê; o compilador o ignora. Uma segunda linha "dentro"
do `if` sem chaves roda sempre. Por isso o curso manda **usar chaves sempre**,
mesmo com uma linha só.

O `if` sozinho não tem "senão": com a condição falsa, o bloco é pulado e o
programa segue. É a **seleção simples**: um passo extra ou nada.

No exemplo, entram R$ 230, a resposta é Sim, o desconto acontece e o valor
final é R$ 207. Se fosse Não, a seta cinza iria direto ao final:

{{ideia}}

O desconto em C (`%%` mostra um `%` no `printf`):

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

> [!WARNING]
> **O `;` depois do `if` mata a condição.** Em `if (total >= 200);`, o ponto e
> vírgula é uma **instrução vazia** e vira o corpo do `if`. O bloco `{ ... }`
> seguinte fica solto e roda **sempre**: compila sem erro e todo mundo ganha
> desconto. O `-Wextra` avisa ("suggest braces around empty body"). No fim da
> linha do `if` nunca vai `;`.

> [!NOTE]
> **Pergunta para você:** e se a compra der exatamente R$ 200,00? E R$ 199,99?
> Responda olhando o `>=` e depois troque `230.0` no código acima para conferir.

{{pratique}}
