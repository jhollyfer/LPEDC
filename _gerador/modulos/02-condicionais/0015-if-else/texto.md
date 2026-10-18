## 0015 · if/else e o = no lugar do ==

Catraca do metrô, horário de pico. Você encosta o cartão e a máquina decide em
um instante: tem saldo para a tarifa de R$ 5,00? Se tem, libera e desconta.
Se não tem, barra e mostra quanto falta. Não existe uma terceira opção, e uma
das duas **sempre** acontece.

O `if` do 0014 fazia um passo a mais ou nada. Agora são **dois caminhos**, e o
segundo é o **`else`** ("senão"):

```c
if (condição) {
    // caminho do Sim
} else {
    // caminho do Não
}
```

É a **seleção dupla**: exatamente um dos dois blocos roda, nunca os dois e
nunca nenhum. Repare que o `else` **não tem condição**. Ele é "todo o resto".
Escrever `else (saldo < 5)` é erro: se você precisa de outra pergunta, ela vira
um novo `if` (assunto 0016).

As regras de chaves são as mesmas: sem chaves, o `else` também manda em uma
instrução só. E o `;` depois do `if` do 0014 agora costuma virar erro de
compilação: em `if (c); { ... } else { ... }`, o bloco fica solto e o `else`
fica sem `if` para se apoiar. Pelo menos esse o compilador pega.

O que o compilador **não** pega sozinho é a pegadinha mais famosa do C: usar
`=` (atribuição) no lugar de `==` (comparação). No C, uma atribuição também é
uma expressão e tem valor: o valor atribuído. Então `if (saldo = 0)` não
pergunta nada. Ele **guarda 0 no saldo** e testa esse 0, que é falso. E
`if (opcao = 1)` guarda 1 e testa 1, que é sempre verdade. O programa compila,
roda e faz besteira em silêncio.

O compilador não recusa esse código, mas avisa se você pedir. Quem grita
é o `-Wall`: "suggest parentheses around assignment used as truth value". O
`rodar` liga esse aviso. **Nunca ignore um warning**: no curso, código bom
compila com zero avisos.

Vamos ver na prática. O cartão tem R$ 3,50, a tarifa é R$ 5,00. A pergunta
responde Não, e desta vez o caminho que vale é o de baixo:

{{ideia}}

O mesmo exemplo em C:

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

Repara no fluxograma: o caminho verde sai pelo Não. Cada lado do losango tem
o seu bloco, e os dois se encontram de novo no Fim. Não há como passar pelos
dois:

{{fluxograma}}

> [!WARNING]
> **`=` no lugar de `==`.** Com `if (saldo = 0)`, o saldo vira zero e o `else`
> roda sempre. Com `if (tentativas = 3)`, o cartão é bloqueado na primeira
> tentativa. Leia `=` como "recebe" e `==` como "é igual a". Dois truques
> ajudam: (1) compile com `-Wall` e trate aviso como erro; (2) quando um lado é
> constante, escreva a constante à esquerda: `if (0 == saldo)`. Se você
> esquecer um `=`, `0 = saldo` não compila, porque não dá para guardar nada
> dentro do número 0.

> [!TIP]
> **Por dentro do C:** o `if/else` vira **dois** saltos. O primeiro é o do
> `if`: "se a condição for falsa, pula para o bloco do `else`". O segundo fica
> no fim do bloco do `if`: um salto incondicional (`jmp`) que **pula por cima**
> do `else`, para os dois caminhos não se misturarem. E o `=` dentro do `if`?
> Para o compilador, `if (x = 0)` é "guarda 0 em `x`, depois compara `x` com 0".
> É código perfeitamente legal, por isso só dá aviso, não erro.

> [!NOTE]
> **Pergunta para você:** se o saldo fosse exatamente R$ 5,00, o que
> apareceria, e com quanto o cartão ficaria? E se você trocasse `>=` por `>`?
> Pense antes de mudar o A029.

{{pratique}}
