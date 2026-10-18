## 0025 · While

Você quer um celular de R$ 1.000 e consegue guardar R$ 150 por mês. Em
quantos meses compra? Dá para fazer a conta de cabeça, mas repare no jeito
que você pensa: "guardo, confiro se já deu; se não deu, guardo de novo".

Esse "de novo" é a terceira peça de todo algoritmo, depois da sequência e da
decisão: a **repetição**. Em C, a forma mais simples de repetir é o **`while`** ("enquanto"):

```c
while (condição) {
    // corpo: roda enquanto a condição for verdadeira
}
```

A ordem é sempre a mesma: **pergunta**, roda o corpo, volta e **pergunta de
novo**. Quando a resposta for falsa, o programa pula o corpo e segue na linha
depois da `}`. Cada passada pelo corpo se chama **iteração** (ou volta).

Como a pergunta vem **antes**, o corpo pode rodar **zero vezes**: se o saldo
já começasse em R$ 1.200, o laço nem entraria. E vale a regra de
sempre no C: a condição é um número, e qualquer valor
diferente de zero conta como verdadeiro (assunto 0017).

O `while` serve quando você **não sabe quantas voltas** vai dar. Você sabe
quando parar ("quando o saldo chegar na meta"), mas não sabe em que volta isso
acontece. Para isso, três coisas precisam existir:

1. a variável da pergunta tem um valor **antes** do laço (`saldo = 0`);
2. a pergunta usa essa variável (`saldo < meta`);
3. o corpo **muda** essa variável, chegando mais perto de parar
   (`saldo = saldo + deposito`).

Esqueça a terceira e você tem um **laço infinito**: a pergunta dá sempre a
mesma resposta, e o programa nunca sai dali. No terminal, `Ctrl+C` encerra.

Vamos ver na prática. O saldo começa vazio, a pergunta "saldo < 1000?" responde
Sim sete vezes seguidas e, a cada Sim, entra um depósito e o programa volta à
pergunta. Na oitava vez, com R$ 1.050, a resposta é Não:

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

O teste de mesa (uma linha por pergunta, uma coluna por variável) mostra tudo. Repare que são **8
perguntas** para **7 voltas**: a última pergunta é a que dá Não.

| Pergunta | saldo antes | `saldo < 1000?` | saldo depois | meses |
| --- | --- | --- | --- | --- |
| 1ª | 0 | Sim | 150 | 1 |
| 2ª | 150 | Sim | 300 | 2 |
| ... | ... | Sim | ... | ... |
| 7ª | 900 | Sim | 1050 | 7 |
| 8ª | 1050 | **Não** | (sai) | 7 |

Repara no fluxograma: a seta que sai de "Mostrar mês e saldo" **volta para o
losango**. É assim que uma repetição aparece no desenho. O caminho verde passa
pelo Sim várias vezes e só uma vez pelo Não:

{{fluxograma}}

> [!WARNING]
> Um `;` logo depois do `while` acaba com o laço: `while (saldo < meta);`
> é um laço com o corpo **vazio**. O `{ ... }` que vem depois vira um bloco
> solto que nunca é alcançado, porque o saldo nunca muda e a pergunta dá Sim
> para sempre: o programa trava. Parecido: sem chaves, só a **primeira** linha
> depois do `while` repete, por mais que a indentação diga outra coisa. O gcc
> avisa os dois casos com `-Wmisleading-indentation` (o `rodar` liga esse
> aviso). Use chaves sempre.

> [!TIP]
> **Por dentro do C:** o processador não tem "while". O compilador traduz o
> laço em duas instruções de **salto**: no topo, "compara saldo com meta e, se
> não for menor, pula para depois do laço"; no fim do corpo, "pula de volta para
> o topo". Cada volta custa uma comparação e um salto, quase nada. Por isso o
> laço infinito trava a máquina em 100% de um núcleo: ele é só um salto para
> trás que nunca deixa de acontecer.

> [!NOTE]
> **Pergunta para você:** se o depósito fosse R$ 200, quantas voltas o laço
> daria e quanto sobraria? E se o saldo começasse em R$ 1.000? Responda pelo
> teste de mesa e depois mude os valores no exemplo A049.

{{pratique}}
