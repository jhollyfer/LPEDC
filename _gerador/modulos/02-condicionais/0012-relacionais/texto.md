## 0012 · Relacionais e a verdade em C

- **Operadores relacionais**: `>`, `<`, `>=`, `<=`, `==` (igual, dois sinais)
  e `!=` (diferente). Toda decisão começa numa comparação
  (DEITEL; DEITEL, 2011, cap. 2).
- **Comparação vale número**: um `int`, **1** se é verdade e **0** se é
  mentira. Dá para mostrar com `%d`, somar e multiplicar
  (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Verdade em C**: na condição, **0 é falso e qualquer outro valor é
  verdadeiro** (1, 42, -3, 0.5). `if (num)` é `if (num != 0)`
  (BACKES, 2013, cap. 3).
- **`bool`**: o `<stdbool.h>` do C99 dá `bool`, `true` (1) e `false` (0). Todo
  valor diferente de zero vira `true`: `bool b = 42;` guarda 1
  (BACKES, 2013, cap. 3).
- **Erros de escrita**: `=<`, `=>` e `<>` não existem; `= =` com espaço também
  não. `=` sozinho é **atribuição**: leia `=` como "recebe" e `==` como "é
  igual a" (DEITEL; DEITEL, 2011, cap. 2).

| Operador | Pergunta | Com o placar 2 x 1 |
| --- | --- | --- |
| `>` | maior que? | `2 > 1` vale 1 |
| `<` | menor que? | `2 < 1` vale 0 |
| `>=` | maior ou igual? | `2 >= 1` vale 1 |
| `<=` | menor ou igual? | `2 <= 1` vale 0 |
| `==` | igual? (dois sinais!) | `2 == 1` vale 0 |
| `!=` | diferente? | `2 != 1` vale 1 |

> [!WARNING]
> **Não compare `float` ou `double` com `==`.** `0.1 + 0.2 == 0.3` vale **0**:
> a soma dá 0.30000000000000004. Pergunte se estão perto o bastante,
> `fabs(a - b) < 1e-9`, ou guarde dinheiro em **centavos** num `int`.

{{exemplo}}

Fim de jogo, mandante 2 x 1 visitante. Os dois placares viram três perguntas,
cada resposta é 0 ou 1, e a tabela usa esses números direto na conta dos
pontos:

{{ideia}}

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

O fluxograma não tem losango: comparar só **calcula** uma resposta e a guarda.
Quem escolhe o caminho é o `if` (0014):

{{fluxograma}}
