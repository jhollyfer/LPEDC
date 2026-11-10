## 0018 · switch, case, break e fall-through

Na lanchonete, o cardápio tem número: 1 é X-Burger, 2 é X-Salada, 3 é Misto
quente. Você diz "um 2", e o atendente só procura **qual número é igual** ao
que você falou, sem testar faixas.

Para "qual destes valores exatos?", o C tem o **`switch`**, a **seleção
múltipla** (nome usado pelo Deitel e pela prova):

```c
switch (codigo) {
case 1:
    // código igual a 1
    break;
case 2:
    // código igual a 2
    break;
default:
    // nenhum dos anteriores
}
```

O `switch` calcula a expressão uma vez e **pula direto** para o `case` de mesmo
valor. O **`default`** pega o que não casou com nenhum `case` (opcional, mas
vale tratar o inválido).

As regras são mais rígidas que as do `if`:

- a expressão tem que ser **inteira**: `int`, `char` (que é número) ou
  parecido. `double` e string (`switch (nome)` com texto) não compilam;
- cada `case` leva uma **constante** conhecida na compilação (`case 2:`,
  `case 'S':`); `case x:` e `case > 10:` não valem;
- dois `case` não podem ter o mesmo valor.

O `case` é só um **rótulo**, um ponto de entrada. Depois de entrar, o C executa
**tudo para baixo**, atravessando os outros `case`, até um **`break`** ou o
fim do `switch`. Isso é o **fall-through** ("cair através"); o `break` manda
sair do `switch`.

Às vezes o fall-through é desejado: `case` empilhados sem código entre eles
dividem o mesmo trecho (`case 'S': case 's':` aceita maiúscula e minúscula).
Se for de propósito e houver código no meio, avise com o comentário
`// fall through` (o `gcc` o reconhece).

No pedido do desenho, o código 2 entra, o `switch` pula direto para o
`case 2`, sem testar o 1 nem o 3, e o `break` sai antes do `case 3`:

{{ideia}}

O pedido em C:

```c
#include <stdio.h>

int main(void) {
    int codigo = 2;
    int quantidade = 2;
    double preco = 0;

    switch (codigo) {
    case 1:
        printf("X-Burger\n");
        preco = 15.00;
        break;
    case 2:
        printf("X-Salada\n");
        preco = 18.00;
        break; // sem ele, cairia no case 3
    case 3:
        printf("Misto quente\n");
        preco = 9.00;
        break;
    default:
        printf("Código inválido\n");
    }
    printf("Total: R$ %.2f\n", quantidade * preco);
    return 0;
}
// Saída:
// X-Salada
// Total: R$ 36.00
```

O losango do `switch` tem **várias** saídas, uma por `case` e uma para o
`default`; as setas levam o valor no lugar de Sim e Não:

{{fluxograma}}

> [!WARNING]
> **Esquecer o `break`.** Sem o `break` do `case 2`, pedir X-Salada mostra
> "X-Salada", "Misto quente" e o preço fica **9.00**: o `case 3` também rodou
> e sobrescreveu o preço. O compilador não vê erro. O `-Wextra` ajuda
> (`-Wimplicit-fallthrough`: "this statement may fall through"). Escreva o
> `break` logo depois do `case`, antes do miolo.

> [!TIP]
> Como os `case` são constantes, com valores próximos (1, 2, 3...) o
> compilador monta uma **tabela de saltos** e vai direto ao `case` em um passo
> só, mais rápido que uma escada de `else if`.

> [!NOTE]
> **Pergunta para você:** com `codigo = 7`, o que aparece? E o total? Pense
> no valor inicial de `preco` antes de mudar o código acima.

{{pratique}}
