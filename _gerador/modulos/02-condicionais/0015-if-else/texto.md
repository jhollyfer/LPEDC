## 0015 · if/else e o = no lugar do ==

Catraca do metrô. Você encosta o cartão: tem saldo para a tarifa de R$ 5,00?
Se tem, libera e desconta. Se não, barra e mostra quanto falta. Uma das duas
**sempre** acontece.

O `if` do 0014 fazia um passo a mais ou nada. Agora são **dois caminhos**, e
o segundo é o **`else`** ("senão"):

```c
if (condição) {
    // caminho do Sim
} else {
    // caminho do Não
}
```

É a **seleção dupla**: exatamente um dos blocos roda, nunca os dois e nunca
nenhum. O `else` **não tem condição**: é "todo o resto". `else (saldo < 5)` é
erro; outra pergunta vira um novo `if` (0016).

Valem as mesmas regras de chaves: sem chaves, o `else` controla uma instrução
só. O `;` do 0014 agora costuma dar erro de compilação: em
`if (c); { ... } else { ... }`, o `else` fica sem `if`.

O compilador **não** pega a pegadinha mais famosa do C: `=` (atribuição) no
lugar de `==` (comparação). Atribuição também é expressão e vale o valor
atribuído. Então `if (saldo = 0)` **guarda 0 no saldo** e testa esse 0, que é
falso; `if (opcao = 1)` guarda 1 e é sempre verdade. O programa compila e erra
em silêncio.

O `-Wall` avisa: "suggest parentheses around assignment used as truth value".
**Nunca ignore um warning**: código bom compila com zero avisos.

No exemplo, o cartão tem R$ 3,50 e a tarifa é R$ 5,00. A resposta é Não, e o
caminho de baixo é o que vale:

{{ideia}}

O metrô em C:

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

O caminho verde sai pelo Não. Cada lado do losango tem seu bloco, e os dois se
reencontram no Fim, sem passar pelos dois:

{{fluxograma}}

> [!WARNING]
> **`=` no lugar de `==`.** Com `if (saldo = 0)`, o saldo vira zero e o `else`
> roda sempre. Com `if (tentativas = 3)`, o cartão é bloqueado na primeira
> tentativa. Dois truques: (1) compile com `-Wall` e trate aviso como erro;
> (2) escreva a constante à esquerda, `if (0 == saldo)`: se faltar um `=`,
> `0 = saldo` não compila.

> [!NOTE]
> **Pergunta para você:** se o saldo fosse exatamente R$ 5,00, o que
> apareceria, e com quanto o cartão ficaria? E se você trocasse `>=` por `>`?
> Pense antes de mudar o código acima.

{{pratique}}
