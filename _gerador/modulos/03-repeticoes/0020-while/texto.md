## 0020 · While

Você quer um celular de R$ 1.000 e guarda R$ 150 por mês. Em quantos meses
compra? O raciocínio já é um laço: "guardo, confiro se deu; se não deu, guardo
de novo".

Esse "de novo" é a **repetição**. Em C, a forma mais simples é o **`while`**
("enquanto"):

```c
while (condição) {
    // corpo: roda enquanto a condição for verdadeira
}
```

O `while` **pergunta**, roda o corpo, volta e **pergunta de novo**. Quando a
resposta é falsa, pula o corpo e segue na linha depois da `}`. Cada passada
pelo corpo é uma **iteração** (ou volta).

Como a pergunta vem **antes** (laço **com teste no início**, ou pré-teste), o
corpo pode rodar **zero vezes**: com saldo inicial de R$ 1.200, o laço nem
entra. A condição é um número, e todo valor diferente de zero é verdadeiro
(assunto 0012).

Use o `while` quando **não sabe quantas voltas** vão ocorrer, mas sabe quando
parar ("quando o saldo chegar na meta"). Três coisas precisam existir:

1. a variável da pergunta tem valor **antes** do laço (`saldo = 0`);
2. a pergunta usa essa variável (`saldo < meta`);
3. o corpo **muda** essa variável, chegando mais perto de parar
   (`saldo = saldo + deposito`).

Sem a terceira, você tem um **laço infinito**: a pergunta dá sempre a mesma
resposta. No terminal, `Ctrl+C` encerra.

O saldo começa vazio e "saldo < 1000?" responde Sim sete vezes, com um
depósito a cada Sim. Na oitava, com R$ 1.050, responde Não:

{{ideia}}

O mesmo cofrinho em C:

```c
#include <stdio.h>

int main(void) {
    double meta = 1000.0;    // o celular custa R$ 1000
    double deposito = 150.0; // quanto você guarda por mês
    double saldo = 0.0;
    int meses = 0;

    while (saldo < meta) {   // pergunta ANTES de cada volta
        saldo = saldo + deposito;
        meses++;
        printf("Mês %d: R$ %.2f\n", meses, saldo);
    }

    printf("Meta batida em %d meses. Sobra R$ %.2f\n", meses, saldo - meta);
    return 0;
}
// Saída:
// Mês 1: R$ 150.00
// Mês 2: R$ 300.00
// Mês 3: R$ 450.00
// Mês 4: R$ 600.00
// Mês 5: R$ 750.00
// Mês 6: R$ 900.00
// Mês 7: R$ 1050.00
// Meta batida em 7 meses. Sobra R$ 50.00
```

### Passo a passo

No teste de mesa (uma linha por pergunta, uma coluna por variável), são **8
perguntas** para **7 voltas**: a última dá Não.

| Pergunta | saldo antes | `saldo < 1000?` | saldo depois | meses |
| --- | --- | --- | --- | --- |
| 1ª | 0 | Sim | 150 | 1 |
| 2ª | 150 | Sim | 300 | 2 |
| ... | ... | Sim | ... | ... |
| 7ª | 900 | Sim | 1050 | 7 |
| 8ª | 1050 | **Não** | (sai) | 7 |

No fluxograma, a seta de "Mostrar mês e saldo" **volta para o losango**: assim
a repetição aparece. O caminho verde passa várias vezes pelo Sim e uma pelo
Não:

{{fluxograma}}

> [!WARNING]
> Um `;` logo depois do `while` acaba com o laço: `while (saldo < meta);` tem
> corpo **vazio**, o `{ ... }` seguinte nunca é alcançado e o programa trava.
> Parecido: sem chaves, só a **primeira** linha depois do `while` repete, seja
> qual for a indentação. O gcc avisa este caso com `-Wmisleading-indentation`
> (ligado nas flags de estudo), mas o `;` vazio passa calado. Use chaves
> sempre.

> [!NOTE]
> **Pergunta para você:** se o depósito fosse R$ 200, quantas voltas o laço
> daria e quanto sobraria? E se o saldo começasse em R$ 1.000? Responda pelo
> teste de mesa e depois mude os valores no código acima e rode.

{{pratique}}
