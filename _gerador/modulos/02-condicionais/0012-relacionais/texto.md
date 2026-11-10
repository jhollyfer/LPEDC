## 0012 · Relacionais e a verdade em C

Domingo, fim de jogo: mandante 2 x 1 visitante. A tabela do campeonato faz
três perguntas de sim ou não: o mandante fez mais gols? Empatou? Fez menos?
E soma 3, 1 ou 0 ponto.

Toda decisão começa numa **comparação**. O C tem seis **operadores
relacionais**:

| Operador | Pergunta | Com o placar 2 x 1 |
| --- | --- | --- |
| `>` | maior que? | `2 > 1` vale 1 |
| `<` | menor que? | `2 < 1` vale 0 |
| `>=` | maior ou igual? | `2 >= 1` vale 1 |
| `<=` | menor ou igual? | `2 <= 1` vale 0 |
| `==` | igual? (dois sinais!) | `2 == 1` vale 0 |
| `!=` | diferente? | `2 != 1` vale 1 |

No C, uma comparação dá um **`int`**: **1** se é verdade e **0** se é mentira.
Dá para imprimir com `%d`, somar e multiplicar.

No sentido inverso, **0 é falso e qualquer outro valor é verdadeiro**: 1, 42,
-3 e 0.5 contam como verdade. Isso será usado a partir do `if` (0014).

O C99 criou o `_Bool` e o cabeçalho **`<stdbool.h>`**, com os nomes
**`bool`**, **`true`** (vale 1) e **`false`** (vale 0). Use `bool` para
respostas de sim ou não. Ele é rígido: `bool b = 42;` guarda **1**, porque
todo valor diferente de zero vira `true`.

Três erros de escrita: `=<`, `=>` e `<>` não existem (o símbolo vem antes do
`=`, e diferente é `!=`); `= =` com espaço também não; e `=` sozinho é
**atribuição**, não comparação. Leia `=` como "recebe" e `==` como "é igual
a". O estrago dessa troca fica para o 0015.

Os dois placares viram três perguntas, e cada resposta é 0 ou 1. A tabela usa
esses números direto na conta dos pontos:

{{ideia}}

O placar em C não tem nenhum `if`: a verdade vira número e entra na conta:

```c
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int gols_casa = 2;
    int gols_fora = 1;

    printf("casa >  fora? %d\n", gols_casa > gols_fora);
    printf("casa == fora? %d\n", gols_casa == gols_fora);
    printf("casa <  fora? %d\n", gols_casa < gols_fora);

    bool venceu = gols_casa > gols_fora;   // guarda a resposta: true
    bool empatou = gols_casa == gols_fora; // false

    int pontos = 3 * venceu + empatou;     // 3 * 1 + 0
    printf("Pontos do mandante: %d\n", pontos);
    return 0;
}
// Saída:
// casa >  fora? 1
// casa == fora? 0
// casa <  fora? 0
// Pontos do mandante: 3
```

O fluxograma não tem losango: comparar não é decidir, apenas **calcula** uma
resposta e a guarda numa caixinha. Quem escolhe o caminho é o `if` (0014):

{{fluxograma}}

> [!WARNING]
> **Não compare `float` ou `double` com `==`.** `printf("%d", 0.1 + 0.2 ==
> 0.3);` mostra **0**: 0,1 não tem representação exata em binário, e a soma
> dá 0.30000000000000004. Pergunte se os valores estão **perto o bastante**:
> `fabs(a - b) < 1e-9`. Para dinheiro, o mais seguro é guardar **centavos**
> num `int`.

> [!NOTE]
> **Pergunta para você:** quanto vale `7 > 3 > 1`? Lembre que o C avalia da
> esquerda para a direita e que `7 > 3` já virou um número. Responda antes de
> colocar num `printf` com `%d`.

{{pratique}}
