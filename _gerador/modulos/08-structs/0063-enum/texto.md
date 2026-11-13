## 0063 · Enum

- **Enum** (enumeração): lista de **constantes inteiras com nome**. Melhor que
  número solto (`status == 2` não diz nada) e que string (pede `strcmp`)
  (BACKES, 2013, cap. 8).

```c
typedef enum { RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE } Status;
```

- **Valores**: o primeiro nome vale 0 e cada um vale o anterior mais 1. Dá
  para escolher (`DEZ = 10, VINTE = 20`), e o seguinte continua a contagem
  (DEITEL; DEITEL, 2011, cap. 10).
- **Só um inteiro com apelido**: o compilador deixa somar, comparar com `<` e
  guardar 42 numa variável `Status`. A variável ocupa o mesmo que um `int`
  (BACKES, 2013, cap. 8).
- **Nomes em MAIÚSCULAS**, como no `#define`. Ao contrário dele, o compilador
  conhece o enum: sem um `case`, o `-Wall` avisa, desde que o `switch` não
  tenha `default` (DEITEL; DEITEL, 2011, cap. 10).
- **Contador no fim**: `{ RECEBIDO, ..., ENTREGUE, QTD_STATUS }`. `QTD_STATUS`
  vale 4 e dimensiona um vetor de textos (`const char *nomes[QTD_STATUS]`).

> [!WARNING]
> O C **não confere** se o valor de um enum é válido: `Status s = 42;` compila,
> e `s++` depois de `ENTREGUE` dá 4. E os nomes são globais: dois enums com
> `ENTREGUE` não compilam. Use prefixo: `STATUS_ENTREGUE`.

{{exemplo}}

O pedido no app de delivery passa por quatro etapas. A variável `s` começa em
`RECEBIDO` e anda uma etapa por vez, com `s++`:

{{ideia}}

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

O laço é comum, controlado por uma pergunta sobre o enum, e o `s++` faz o
pedido andar:

{{fluxograma}}
