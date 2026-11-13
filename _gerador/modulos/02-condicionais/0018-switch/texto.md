## 0018 · switch, case, break e fall-through

O `else if` do 0016 resolve faixas: até 60, até 72, até 90. Há um outro
tipo de escolha, mais simples, em que você só quer saber **qual valor
exato** chegou. A opção 1, 2 ou 3 de um menu; a letra S ou N de uma
resposta. Dá para fazer com `else if`, repetindo `codigo == 1`,
`codigo == 2`, `codigo == 3`, mas o C tem um comando feito para isso.

Pense na lanchonete com cardápio numerado: 1 é X-Burger, 2 é X-Salada, 3 é
Misto quente. Você diz "um 2". O atendente não testa se o seu número é
maior ou menor que alguma coisa; ele vai direto à linha 2 do cardápio.

Esse "vá direto ao valor igual" é o **`switch`**, chamado de **seleção
múltipla**. Ele calcula a expressão entre parênteses uma vez só e **pula
direto** para o `case` que tem o mesmo valor. Se nenhum `case` casar, o
programa vai para o **`default`**, que pega todo o resto (DEITEL; DEITEL,
2011, cap. 4). O `default` é opcional, mas é nele que você trata o valor
inválido, como um código 7 que não existe no cardápio.

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

Em troca dessa rapidez, as regras são mais rígidas que as do `if`. A
expressão do `switch` tem de ser **inteira**: `int`, `char` (que é um
número, 0002) ou parecido. Um `double` ou um texto não compilam (DEITEL;
DEITEL, 2011, cap. 4). Cada `case` leva uma **constante**, um valor
conhecido já na hora de compilar, como `case 2:` ou `case 'S':`. Por isso
`case x:`, com uma variável, e `case > 10:`, com uma comparação, não
valem, e dois `case` não podem ter o mesmo valor (KERNIGHAN; RITCHIE,
1988, cap. 3).

Essas restrições têm um motivo. Como os valores dos `case` são conhecidos
antes de o programa rodar, o compilador pode montar uma **tabela de
saltos**, uma lista de endereços indexada pelo valor. Com valores próximos,
como 1, 2 e 3, o programa vai ao `case` certo num passo só, sem comparar
um por um como numa escada de `else if`.

Agora a parte que mais surpreende. O `case` não é um bloco: é só um
**rótulo**, uma marca que diz por onde entrar. Depois de entrar, o C
executa **tudo para baixo**, atravessando os `case` seguintes, até
encontrar um **`break`** ou chegar ao fim do `switch` (BACKES, 2013,
cap. 4). Esse atravessar tem nome, **fall-through**, "cair através". O
`break` é a ordem de sair do `switch` naquele ponto; por isso ele aparece
no fim de quase todo `case`.

Às vezes o fall-through é exatamente o que você quer. Vários `case`
empilhados, sem nada entre eles, dividem o mesmo trecho: `case 'S':
case 's':` aceita a resposta em maiúscula e em minúscula. Se o
fall-through for de propósito e houver código no meio do caminho, avise
quem lê com o comentário `// fall through`, que o gcc reconhece e não
reclama (GNU, s.d.).

> [!WARNING]
> **Esquecer o `break`.** Sem o do `case 2`, pedir X-Salada mostra também
> "Misto quente" e o preço vira **9.00**: o `case 3` também rodou e
> sobrescreveu o preço. O compilador não vê erro; o `-Wextra` avisa ("this
> statement may fall through").

{{exemplo}}

Na lanchonete, 1 é X-Burger, 2 é X-Salada, 3 é Misto quente. O código 2
entra, o `switch` pula direto para o `case 2`, sem testar o 1 nem o 3, e o
`break` sai antes do `case 3`:

{{ideia}}

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
