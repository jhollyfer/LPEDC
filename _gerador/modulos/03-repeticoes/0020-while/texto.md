## 0020 · While

- **Repetição**: rodar o mesmo trecho várias vezes. Cada passada pelo corpo é
  uma **iteração** (ou volta) (DEITEL; DEITEL, 2011, cap. 3).
- **`while`** ("enquanto"): **pergunta**, roda o corpo, volta e pergunta de
  novo. Com a resposta falsa, segue depois da `}` (BACKES, 2013, cap. 5).

```c
while (condição) {
    // corpo: roda enquanto a condição for verdadeira
}
```

- **Teste no início** (pré-teste): como a pergunta vem antes, o corpo pode
  rodar **zero vezes** (BACKES, 2013, cap. 5).
- **Quando usar**: não se sabe quantas voltas vão ocorrer, mas se sabe quando
  parar (CARVALHO, 2010).
- **Três peças**: a variável da pergunta tem valor **antes** do laço; a
  pergunta usa essa variável; o corpo **muda** essa variável rumo ao fim
  (DEITEL; DEITEL, 2011, cap. 3).
- **Laço infinito**: sem a terceira peça, a pergunta dá sempre a mesma
  resposta. No terminal, `Ctrl+C` encerra (BACKES, 2013, cap. 5).

> [!WARNING]
> Um `;` logo depois do `while` acaba com o laço: `while (saldo < meta);` tem
> corpo **vazio** e o programa trava. Sem chaves, só a **primeira** linha
> repete, seja qual for o recuo. Use chaves sempre.

{{exemplo}}

Um celular de R$ 1.000, guardando R$ 150 por mês. "saldo < 1000?" responde
Sim sete vezes, com um depósito a cada Sim; na oitava, com R$ 1.050, responde
Não:

{{ideia}}

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

A seta de "Mostrar mês e saldo" **volta para o losango**: assim a repetição
aparece. O caminho verde passa várias vezes pelo Sim e uma pelo Não:

{{fluxograma}}
