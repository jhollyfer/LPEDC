## 0068 · Enum

O app de delivery mostra o seu pedido passando por etapas: recebido, em
preparo, saiu para entrega, entregue. São quatro estados, sempre os mesmos,
sempre nessa ordem. Como guardar isso no programa?

Dá para usar números: 0 é recebido, 1 é preparando, e assim por diante. Só que
daqui a um mês ninguém lembra o que significa `if (status == 2)`. Dá para
usar strings, mas comparar `"saiu para entrega"` com `strcmp` toda hora é lento
e um erro de digitação passa batido. O C tem uma terceira saída: o **enum**
(enumeração).

Um enum é uma lista de **constantes inteiras com nome**:

```c
typedef enum { RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE } Status;
```

O primeiro nome vale 0, e cada um vale o anterior mais 1: `RECEBIDO` é 0,
`ENTREGUE` é 3. Você também pode escolher os valores (`DEZ = 10, VINTE = 20`),
e quem vem depois de um valor escolhido continua contando a partir dele. Os
nomes ficam em MAIÚSCULAS por convenção, como as constantes do `#define`.

Se você usa `enum` no TypeScript, é quase a mesma coisa: `enum Status {
Recebido, Preparando }` também numera a partir de 0. A diferença é que no C o
enum é **só um inteiro com apelido**: o compilador deixa somar, comparar com
`<` e até guardar 42 numa variável `Status`.

Vamos ver na prática. A variável `s` começa em `RECEBIDO` e anda uma etapa
por vez, porque um enum é um inteiro e aceita `s++`. Cada valor tem um nome
no código e um número na memória:

{{ideia}}

O código percorre as etapas e traduz cada uma para texto com um `switch`:

```c
#include <stdio.h>

typedef enum {
    RECEBIDO,   // 0
    PREPARANDO, // 1
    A_CAMINHO,  // 2
    ENTREGUE    // 3
} Status;

const char *nome_status(Status s) {
    switch (s) {
    case RECEBIDO:
        return "recebido pelo restaurante";
    case PREPARANDO:
        return "em preparo";
    case A_CAMINHO:
        return "saiu para entrega";
    case ENTREGUE:
        return "entregue";
    }
    return "desconhecido"; // só chega aqui com um valor inválido
}

int main(void) {
    Status s = RECEBIDO;

    while (s != ENTREGUE) {
        printf("[%d] Pedido %s\n", s, nome_status(s));
        s++; // enum é um inteiro: avança para o próximo status
    }
    printf("[%d] Pedido %s. Bom apetite!\n", s, nome_status(s));
    return 0;
}
// Saída:
// [0] Pedido recebido pelo restaurante
// [1] Pedido em preparo
// [2] Pedido saiu para entrega
// [3] Pedido entregue. Bom apetite!
```

Enum e `switch` foram feitos um para o outro. Cada `case` usa um nome, e o
código se explica sozinho. Um truque comum é pôr um último nome que só conta
os outros: `{ RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE, QTD_STATUS }`. Como
`QTD_STATUS` vale 4, ele serve de tamanho para um vetor de textos
(`const char *nomes[QTD_STATUS]`) e cresce sozinho quando você acrescenta um
status.

Repara no fluxograma: é um laço comum, controlado por uma pergunta sobre o
enum. O `s++` é o que faz o pedido andar:

{{fluxograma}}

> [!WARNING]
> O C **não confere** se o valor de um enum é válido. `Status s = 42;`
> compila, e `s++` depois de `ENTREGUE` dá 4, que não é status nenhum. Por isso
> o `nome_status` tem um `return "desconhecido"` depois do `switch`. Outro
> tropeço: os nomes de um enum são globais. Se outro enum do mesmo programa
> também tiver `ENTREGUE`, não compila. Daí o costume de usar prefixo:
> `STATUS_ENTREGUE`, `PAG_PIX`.

> [!TIP]
> **Por dentro do C:** o enum some na compilação. `A_CAMINHO` vira o número 2
> no código de máquina, e uma variável `Status` ocupa o mesmo que um `int` (4
> bytes, como mostra o A136). Então por que não usar `#define`? Porque o
> compilador **conhece** o enum. Apague o `case ENTREGUE:` do exemplo e rode:
> o `-Wall` avisa `enumeration value 'ENTREGUE' not handled in switch`. Com
> `#define`, ninguém avisaria. Esse aviso só aparece se o `switch` **não** tiver
> `default`; por isso, num switch de enum, prefira tratar todos os casos e
> deixar o "valor inválido" depois do switch.

> [!NOTE]
> **Pergunta para você:** em `enum { BRONZE = 1, PRATA, OURO = 5, DIAMANTE }`, quanto vale
> cada nível? E se o laço do exemplo usasse `s <= ENTREGUE` em vez de
> `s != ENTREGUE`, sem o `printf` depois do laço, a saída mudaria?

{{pratique}}
