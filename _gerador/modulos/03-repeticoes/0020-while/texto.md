## 0020 · While

Você quer um celular de R$ 1.000 e guarda R$ 150 por mês. Em quantos meses
consegue comprar? Com o que você viu até aqui, teria de escrever um `if` para
cada mês, sem saber quantos `if` seriam necessários. O raciocínio que você faz
de cabeça já mostra a saída: "guardo, confiro se deu; se não deu, guardo de
novo". Falta ao programa esse "de novo".

Esse "de novo" é a **repetição**: rodar o mesmo trecho de código várias vezes.
Cada passada pelo trecho repetido se chama **iteração**, ou volta, e o trecho
em si é o **corpo** do laço (DEITEL; DEITEL, 2011, cap. 3). A forma mais
simples de repetir em C é o **`while`** ("enquanto"): ele faz uma pergunta e,
enquanto a resposta for verdadeira, roda o corpo (BACKES, 2013, cap. 5).

```c
while (condição) {
    // corpo: roda enquanto a condição for verdadeira
}
```

A leitura segue o ciclo do cofrinho. O `while` testa a condição; se ela vale,
roda o corpo inteiro, volta ao topo e testa de novo. Quando a resposta for
falsa, ele pula o corpo e o programa segue na linha depois da `}`. A condição
é a mesma que você já usa no `if`: um número, e todo valor diferente de zero
conta como verdadeiro (assunto 0012). A diferença para o `if` é a volta: o
`if` pergunta uma vez, o `while` pergunta a cada passada.

Como a pergunta vem **antes** do corpo, o `while` é um laço **com teste no
início**, também chamado de pré-teste. Isso tem uma consequência prática: o
corpo pode rodar **zero vezes**. Se o saldo já começasse em R$ 1.200, a
primeira pergunta daria falso e o programa nem entraria no laço (BACKES, 2013,
cap. 5). Esse comportamento é o certo aqui, porque quem já tem o dinheiro não
precisa guardar nada.

O `while` serve bem quando você **não sabe quantas voltas** vão acontecer, mas
sabe **quando parar**. No cofrinho, ninguém diz "repita 7 vezes"; a regra é
"repita até o saldo chegar na meta". O número de voltas sai como resultado da
conta, não como dado de entrada (CARVALHO, 2010).

Para um `while` funcionar, três peças precisam estar no lugar, todas ligadas à
mesma variável (DEITEL; DEITEL, 2011, cap. 3). Primeiro, a variável da
pergunta tem um valor **antes** do laço: `saldo = 0`. Sem isso, a primeira
pergunta compara lixo de memória. Segundo, a condição usa essa variável:
`saldo < meta`. Terceiro, o corpo **muda** essa variável na direção de parar:
`saldo = saldo + deposito`. É a terceira peça que garante o fim, porque cada
volta deixa o saldo mais perto da meta.

Se a terceira peça falta, a condição dá sempre a mesma resposta e o laço nunca
acaba. Esse é o **laço infinito**. O programa parece travado: não aparece
nada novo ou aparece a mesma linha sem parar. No terminal, `Ctrl+C` interrompe
o programa (BACKES, 2013, cap. 5). Quando isso acontecer, procure no corpo a
linha que deveria mudar a variável da condição.

Para conferir quantas voltas um laço dá, monte um **teste de mesa**: uma
linha por pergunta, uma coluna por variável. O detalhe que mais engana é
contar as perguntas. Um laço que roda o corpo 7 vezes faz 8 perguntas, porque
a última pergunta é a que responde "não" e libera a saída.

> [!WARNING]
> Um `;` logo depois do `while` acaba com o laço: `while (saldo < meta);` tem
> corpo **vazio**, o bloco seguinte nunca é alcançado e o programa trava. Sem
> chaves, só a **primeira** linha depois do `while` repete, seja qual for o
> recuo. O gcc avisa este caso com `-Wmisleading-indentation`, mas o `;` vazio
> passa calado. Use chaves sempre.

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
