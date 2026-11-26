## 0012 · Relacionais e a verdade em C

Os programas do módulo 01 seguiam sempre o mesmo caminho, de cima para
baixo. Um programa que decide precisa, antes de tudo, de uma pergunta de sim
ou não: a compra passou de R$ 200? A senha está certa? O saldo dá? Este
módulo inteiro se apoia nessas perguntas, e elas começam numa comparação.

Pense na tabela do campeonato no fim do domingo. O jogo terminou 2 x 1 para
o mandante, e a tabela precisa saber três coisas: o mandante fez mais gols?
Empatou? Fez menos? Cada resposta é sim ou não, e dela sai a pontuação: 3
pontos pela vitória, 1 pelo empate, 0 pela derrota.

Para fazer essas perguntas, o C tem seis **operadores relacionais**, que
comparam dois valores: `>` (maior), `<` (menor), `>=` (maior ou igual),
`<=` (menor ou igual), `==` (igual, com dois sinais) e `!=` (diferente)
(DEITEL; DEITEL, 2011, cap. 2). Toda decisão do curso começa num deles.

| Operador | Pergunta | Com o placar 2 x 1 |
| --- | --- | --- |
| `>` | maior que? | `2 > 1` vale 1 |
| `<` | menor que? | `2 < 1` vale 0 |
| `>=` | maior ou igual? | `2 >= 1` vale 1 |
| `<=` | menor ou igual? | `2 <= 1` vale 0 |
| `==` | igual? (dois sinais!) | `2 == 1` vale 0 |
| `!=` | diferente? | `2 != 1` vale 1 |

Repare na última coluna: a resposta sai como um número. No C, uma
comparação produz um `int` que vale **1** quando é verdade e **0** quando
é mentira (KERNIGHAN; RITCHIE, 1988, cap. 2). Como é um número, dá
para mostrar com `%d`, somar e multiplicar. A tabela do campeonato nem
precisa decidir nada: os pontos do mandante são `3 * (gm > gv) + (gm == gv)`.
Com 2 x 1, a conta dá 3 × 1 + 0 = 3.

```c
int gm = 2, gv = 1;
printf("%d %d %d\n", gm > gv, gm == gv, gm < gv);   // 1 0 0
```

O caminho de volta também existe, e é ele que o `if` (0014) vai usar.
Quando o C precisa saber se um valor é verdadeiro, ele segue uma regra
simples: **0 é falso, e qualquer outro valor é verdadeiro**. Valem como
verdade 1, 42, -3 e até 0.5. Por isso `if (num)` é o mesmo que
`if (num != 0)` (BACKES, 2013, cap. 3).

Como a comparação vale número, uma comparação em cadeia não faz o que
parece. Em `7 > 3 > 1`, o C resolve da esquerda para a direita: `7 > 3`
vale 1, e depois `1 > 1` vale 0. A expressão inteira dá falso, apesar de 7
ser maior que 3 e 3 maior que 1. Para juntar duas comparações, você precisa
do E lógico do 0013.

Para deixar claro que uma variável guarda sim ou não, o C99 criou o
cabeçalho **`<stdbool.h>`**, com o tipo **`bool`** e os nomes **`true`**
(vale 1) e **`false`** (vale 0). O `bool` é rígido: qualquer valor
diferente de zero vira `true`, então `bool b = 42;` guarda 1 (BACKES,
2013, cap. 3).

Por fim, três erros de escrita aparecem muito. Os símbolos `=<`, `=>` e
`<>` não existem: o sinal vem antes do `=`, e diferente se escreve `!=`.
O `= =` com espaço no meio também não vale. E o `=` sozinho é
**atribuição**, não comparação (DEITEL; DEITEL, 2011, cap. 2). Leia `=`
como "recebe" e `==` como "é igual a"; o estrago dessa troca dentro de um
`if` aparece no 0015.

> [!WARNING]
> **Não compare `float` ou `double` com `==`.** `0.1 + 0.2 == 0.3` vale
> **0**: 0,1 não tem representação exata em binário, e a soma dá
> 0.30000000000000004. Pergunte se estão perto o bastante,
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
