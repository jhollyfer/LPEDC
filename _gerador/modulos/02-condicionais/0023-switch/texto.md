## 0023 · switch, case, break e fall-through

Na lanchonete, o cardápio tem número: 1 é X-Burger, 2 é X-Salada, 3 é Misto
quente. Você não diz "quero um pão com hambúrguer, alface e tomate". Diz "um
2". O atendente não testa faixa nenhuma: só procura **qual número é igual** ao
que você falou.

Quando a decisão é "qual destes valores exatos?", o C tem o **`switch`**:

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

O `switch` calcula a expressão entre parênteses uma vez e **pula direto** para
o `case` com o mesmo valor. O **`default`** pega o que não casou com nenhum
`case` (é opcional, mas quase sempre vale a pena tratar o inválido).

As regras são mais rígidas que as do `if`, e é bom saber por quê:

- a expressão tem que ser **inteira**: `int`, `char` (que é número) ou
  parecido. Nada de `double`, e nada de string: `switch (nome)`
  com um texto não compila;
- cada `case` leva uma **constante** conhecida na compilação (`case 2:`,
  `case 'S':`). Não dá para escrever `case x:` nem `case > 10:`;
- dois `case` não podem ter o mesmo valor.

E a regra mais importante: o `case` é só um **rótulo**, um ponto de entrada.
Depois de entrar, o C executa **tudo para baixo**, atravessando os outros
`case`, até achar um **`break`** (ou o fim do `switch`). Isso é o
**fall-through** ("cair através"). O `break` é o que diz "pronto, saia do
`switch`".

O fall-through às vezes é o que você quer. Vários `case` empilhados, sem nada
entre eles, dividem o mesmo código: `case 'S': case 's':` aceita maiúscula e
minúscula. Quando é de propósito e tem código no meio, avise quem lê com um
comentário `// fall through` (o `gcc` reconhece esse comentário e não reclama).

Vamos ver na prática. O código 2 entra, o `switch` pula direto para o
`case 2`, sem testar o 1 nem o 3, e o `break` sai antes do `case 3`:

{{ideia}}

O mesmo exemplo em C:

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

Repara no fluxograma: o losango do `switch` tem **várias** saídas, uma para
cada `case` e uma para o `default`. Por isso as setas levam o valor no lugar
de Sim e Não:

{{fluxograma}}

> [!WARNING]
> **Esquecer o `break`.** Tire o `break` do `case 2` e peça um X-Salada: a
> saída vira "X-Salada", "Misto quente" e o preço fica **9.00**, porque o
> `case 3` também rodou e sobrescreveu o preço. O compilador não vê erro
> nenhum: para ele, você pediu isso. O `-Wextra` do `rodar` ajuda
> (`-Wimplicit-fallthrough`: "this statement may fall through"). Regra de
> bolso: escreva o `break` logo depois de escrever o `case`, antes do miolo.

> [!TIP]
> **Por dentro do C:** é por causa das constantes que o `switch` pode ser
> mais rápido que uma escada de `else if`. Quando os `case` são números
> próximos (1, 2, 3, 4...), o compilador monta uma **tabela de saltos**: um
> vetor com o endereço do código de cada `case`. Em vez de comparar um por um,
> ele usa o valor como índice da tabela e pula direto, em **um passo só**,
> tenha o `switch` 3 ou 300 casos. Com valores espalhados (1, 500, 90000), ele
> volta a comparar. E o fall-through? É só não ter um salto no fim do bloco:
> o código do próximo `case` está logo ali embaixo na memória.

> [!NOTE]
> **Pergunta para você:** com `codigo = 7`, o que aparece? E o total? Pense
> no valor inicial de `preco` antes de mudar o A045.

{{pratique}}
