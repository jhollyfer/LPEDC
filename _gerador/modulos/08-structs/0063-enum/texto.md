## 0063 · Enum

O app de delivery mostra o pedido em quatro etapas, sempre nesta ordem:
recebido, em preparo, saiu para entrega, entregue. Como guardar isso?

Números (0, 1, 2...) são ruins: em um mês ninguém lembra o que significa
`if (status == 2)`. Strings pedem `strcmp` toda hora, são lentas e um erro de
digitação passa batido. A terceira saída é o **enum** (enumeração).

Um enum é uma lista de **constantes inteiras com nome**:

```c
typedef enum { RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE } Status;
```

O primeiro nome vale 0 e cada um vale o anterior mais 1: `RECEBIDO` é 0,
`ENTREGUE` é 3. Você pode escolher valores (`DEZ = 10, VINTE = 20`); o que vem
depois continua a contagem. Por convenção, os nomes ficam em MAIÚSCULAS, como
no `#define`.

No C, o enum é **só um inteiro com apelido**: o compilador deixa somar,
comparar com `<` e guardar 42 numa variável `Status`.

A variável `s` começa em `RECEBIDO` e anda uma etapa por vez, com `s++`. Cada
valor tem um nome no código e um número na memória:

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

Enum combina com `switch`: cada `case` usa um nome. Um truque é pôr um último
nome que só conta os outros: `{ RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE,
QTD_STATUS }`. `QTD_STATUS` vale 4 e serve de tamanho para um vetor de textos
(`const char *nomes[QTD_STATUS]`), que cresce sozinho com novos status.

O laço é comum, controlado por uma pergunta sobre o enum, e o `s++` faz o
pedido andar:

{{fluxograma}}

> [!WARNING]
> O C **não confere** se o valor de um enum é válido. `Status s = 42;` compila,
> e `s++` depois de `ENTREGUE` dá 4. Por isso `nome_status` tem
> `return "desconhecido"` depois do `switch`. Os nomes de um enum também são
> globais: dois enums com `ENTREGUE` não compilam. Daí o prefixo:
> `STATUS_ENTREGUE`, `PAG_PIX`.

> [!TIP]
> O enum some na compilação: `A_CAMINHO` vira o número 2 e a variável ocupa o
> mesmo que um `int` (4 bytes, A126). Ao contrário do `#define`, o compilador
> o conhece: sem o `case ENTREGUE:`, o `-Wall` avisa `enumeration value
> 'ENTREGUE' not handled in switch`, desde que o `switch` não tenha `default`.

> [!NOTE]
> **Pergunta para você:** em `enum { BRONZE = 1, PRATA, OURO = 5, DIAMANTE }`, quanto vale
> cada nível? E se o laço do exemplo usasse `s <= ENTREGUE` em vez de
> `s != ENTREGUE`, sem o `printf` depois do laço, a saída mudaria?

{{pratique}}
