## 0017 · Relacionais e a verdade em C

Domingo, fim de jogo: mandante 2 x 1 visitante. A tabela do campeonato não
quer saber de lances bonitos. Ela faz três perguntas de sim ou não: o mandante
fez mais gols? Empatou? Fez menos? E soma 3, 1 ou 0 ponto.

Toda decisão de um programa começa assim: uma **comparação**. O C tem seis
**operadores relacionais**:

| Operador | Pergunta | Com o placar 2 x 1 |
| --- | --- | --- |
| `>` | maior que? | `2 > 1` vale 1 |
| `<` | menor que? | `2 < 1` vale 0 |
| `>=` | maior ou igual? | `2 >= 1` vale 1 |
| `<=` | menor ou igual? | `2 <= 1` vale 0 |
| `==` | igual? (dois sinais!) | `2 == 1` vale 0 |
| `!=` | diferente? | `2 != 1` vale 1 |

Repare na última coluna. No C, uma comparação não dá um valor de tipo
especial: dá um **`int`**: **1** quando é verdade e **0**
quando é mentira. Dá para imprimir com `%d`, somar, multiplicar.

E o caminho de volta é ainda mais solto: para o C, **0 é falso e qualquer
outro valor é verdadeiro**. 1, 42, -3 e 0.5 contam como verdade. Só o zero é
falso. Você vai usar isso o tempo todo a partir do `if` (assunto 0019).

Durante muito tempo o C não teve um tipo para verdadeiro e falso: usava `int`
mesmo. O C99 criou o `_Bool` e o cabeçalho **`<stdbool.h>`**, que dá os nomes
amigáveis **`bool`**, **`true`** (vale 1) e **`false`** (vale 0). Use `bool`
sempre que a variável for uma resposta de sim ou não: o nome do tipo já conta
a intenção.

Cuidado com três detalhes de escrita: `=<`, `=>` e `<>` não existem (o
símbolo vem sempre antes do `=`, e diferente é `!=`); `= =` com espaço também
não; e `=` sozinho é **atribuição**, não comparação. Leia `=` como "recebe" e
`==` como "é igual a". O estrago que essa troca faz fica para o 0020.

Vamos ver na prática. Os dois placares entram, viram três perguntas, e cada
resposta é um 0 ou um 1. A tabela usa esses números direto na conta dos
pontos:

{{ideia}}

O mesmo exemplo em C. Não tem nenhum `if`: a verdade vira número e entra na
conta:

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

Repara no fluxograma: não tem losango. Comparar não é decidir. A comparação
só **calcula** uma resposta e guarda numa caixinha, como qualquer conta. Quem
escolhe um caminho é o `if`, que vem daqui a dois assuntos:

{{fluxograma}}

> [!WARNING]
> **Não compare `float` ou `double` com `==`.** Rode `printf("%d", 0.1 + 0.2
> == 0.3);` e veja um **0**. O motivo: 0,1 não tem representação exata em
> binário, e a soma fica em 0.30000000000000004. Para números
> com vírgula, pergunte se estão **perto o bastante**:
> `fabs(a - b) < 1e-9`. Para dinheiro, a saída mais segura é guardar
> **centavos** num `int`.

> [!TIP]
> **Por dentro do C:** o processador não tem uma instrução "maior que" que
> devolve verdadeiro. Ele faz uma subtração de mentira (`cmp`), que só acende
> umas chavinhas de estado (deu zero? deu negativo?). Para guardar a resposta
> num `bool`, o compilador usa uma instrução como `setg`, que escreve 1 ou 0
> num byte. Por isso `sizeof(bool)` é 1. E o `bool` é rígido: `bool b = 42;`
> guarda **1**, porque qualquer valor diferente de zero vira `true` na
> conversão. Num `int`, o 42 ficaria 42.

> [!NOTE]
> **Pergunta para você:** quanto vale `7 > 3 > 1`? Lembre que o C avalia da
> esquerda para a direita e que `7 > 3` já virou um número. Responda antes de
> colocar num `printf` com `%d`.

{{pratique}}
