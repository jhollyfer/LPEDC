## 0063 · Enum

O app de delivery mostra o pedido em quatro etapas, sempre nesta ordem:
recebido, em preparo, saiu para entrega, entregue. O programa precisa guardar
em que etapa cada pedido está. Com números soltos (0, 1, 2, 3), daqui a um mês
ninguém lembra o que quer dizer `if (status == 2)`. Com strings, cada
comparação pede um `strcmp`, que é lento, e um erro de digitação como
`"entrege"` passa sem nenhum aviso.

Pense nas etapas de um processo num painel de senhas: cada etapa tem um nome
para quem lê e um número para a máquina. O **enum** (enumeração) faz isso: é
uma lista de **constantes inteiras com nome**, em que você escreve o nome e o
compilador usa o número (BACKES, 2013, cap. 8):

```c
typedef enum { RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE } Status;
```

A linha cria o tipo `Status` (com o `typedef` do assunto anterior) e quatro
constantes. Agora o código diz `if (s == A_CAMINHO)`, e quem lê entende na
hora. Uma variável `Status s = RECEBIDO;` guarda a etapa de um pedido.

Os valores seguem uma regra fixa. O primeiro nome vale 0, e cada um vale o
anterior mais 1: `RECEBIDO` é 0, `PREPARANDO` é 1, `A_CAMINHO` é 2 e
`ENTREGUE` é 3. Se precisar de outros números, escolha: em
`enum { DEZ = 10, ONZE, VINTE = 20 }`, `ONZE` vale 11, porque o nome sem
valor continua a contagem do anterior (DEITEL; DEITEL, 2011, cap. 10). Por
convenção, os nomes ficam em MAIÚSCULAS, como as constantes do `#define`.

Por baixo, o enum é **só um inteiro com apelido**. Na compilação, `A_CAMINHO`
vira o número 2, e uma variável `Status` ocupa o mesmo espaço que um `int`
(BACKES, 2013, cap. 8). Por isso o compilador deixa fazer contas com ela:
somar, comparar com `<`, avançar com `s++`. É prático para andar pelas
etapas em ordem, e é também a origem do perigo do alerta abaixo.

Se o enum vira número, por que não usar `#define RECEBIDO 0`? Porque o
`#define` é só troca de texto antes da compilação, e o enum o compilador
conhece como tipo. Isso aparece no `switch`: quando cada `case` usa um nome
do enum e você esquece um deles, o `-Wall` avisa `enumeration value
'ENTREGUE' not handled in switch`. O aviso só aparece se o `switch` não tiver
`default`, porque o `default` cobre os casos que faltam (DEITEL; DEITEL,
2011, cap. 10).

Um truque útil é pôr no fim um nome que só conta os outros:
`{ RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE, QTD_STATUS }`. Como a contagem
começa em 0, `QTD_STATUS` vale 4, exatamente o número de etapas. Ele serve de
tamanho para um vetor de textos, `const char *nomes[QTD_STATUS]`, e o vetor
cresce sozinho se você acrescentar uma etapa antes dele.

Os nomes de um enum valem no arquivo todo, não só dentro do enum. Dois enums
diferentes não podem ter um nome igual, e por isso projetos maiores usam
prefixo: `STATUS_ENTREGUE`, `PAG_PIX`.

> [!WARNING]
> O C **não confere** se o valor de um enum é válido. `Status s = 42;`
> compila, e `s++` depois de `ENTREGUE` dá 4, que não é etapa nenhuma. Quem
> traduz o enum para texto precisa de uma saída para valor inválido depois do
> `switch`. E dois enums com `ENTREGUE` não compilam: use prefixo.

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
