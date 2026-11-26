## 0014 · if

Com as comparações (0012) e os operadores lógicos (0013), o programa já
sabe fazer perguntas e calcular a resposta, mas ainda não sabe agir
diferente conforme ela. Todo programa até aqui executava as mesmas linhas,
sempre. O `if` é o primeiro comando que muda o caminho: ele deixa um trecho
rodar só quando uma condição é verdadeira.

Pense no caixa do mercado com a placa: compras a partir de R$ 200 ganham
10% de desconto. A operadora soma tudo e olha o total. Se passou de
R$ 200, ela faz um passo a mais e aplica o desconto. Se não passou, não faz
nada de especial e segue para o pagamento. O passo extra depende da
resposta; o resto acontece de qualquer jeito.

Esse "só se" é o **`if`**, a **seleção simples**. Quando a condição é
verdadeira, o programa executa o bloco do `if`; quando é falsa, pula o
bloco inteiro e continua na linha seguinte. É um passo extra ou nada
(DEITEL; DEITEL, 2011, cap. 3). Não há "senão" aqui; ele chega no 0015.

```c
if (condição) {
    // só roda quando a condição é verdadeira
}
// daqui em diante roda sempre
```

A **condição** vem entre parênteses e pode ser qualquer expressão que dê um
número. Pode ser uma comparação, como `total >= 200`; uma combinação lógica,
como `idade >= 18 && tem_cnh`; ou uma variável sozinha. Vale a regra do
0012: **zero é falso, o resto é verdade** (BACKES, 2013, cap. 4). Assim,
`if (saldo)` equivale a `if (saldo != 0)`, e `if (!saldo)` equivale a
`if (saldo == 0)`. As duas formas funcionam; a segunda deixa a pergunta
mais explícita.

O **bloco** é o trecho entre chaves, e ele aceita quantas instruções você
quiser. Tudo o que está entre a `{` e a `}` roda junto, ou nada roda. Sem
chaves, o `if` controla **uma** instrução só: a primeira que vem depois
dele (BACKES, 2013, cap. 4). A linha seguinte já está fora do `if`, mesmo
que pareça dentro.

```c
if (total >= 200)
    total = total * 0.9;   // depende do if
printf("Pronto\n");        // NÃO depende, apesar de qualquer recuo
```

O que engana é o **recuo**, os espaços no começo da linha. Ele existe só
para quem lê; o compilador o ignora por completo. Se você acrescentar uma
segunda linha recuada debaixo de um `if` sem chaves, ela parece fazer parte
do `if`, mas roda sempre. Por isso o curso usa **chaves sempre**, mesmo
quando o bloco tem uma linha só (KERNIGHAN; RITCHIE, 1988, cap. 3). Com as
chaves, acrescentar uma linha depois não muda o sentido do código.

Um último detalhe sobre a condição: ela é avaliada uma vez, no momento em
que o programa chega ao `if`. Se `total` mudar depois, o `if` não volta
atrás. No exemplo do mercado, o desconto multiplica o total por 0,9 dentro
do bloco, e a linha que mostra o valor final, fora do bloco, enxerga o
total já atualizado ou o original, conforme o caminho tomado.

> [!WARNING]
> **O `;` depois do `if` mata a condição.** Em `if (total >= 200);`, o `;`
> é uma **instrução vazia** e vira o corpo; o bloco seguinte roda
> **sempre**, e todo mundo ganha desconto. O `-Wextra` avisa ("suggest
> braces around empty body"). No fim da linha do `if` nunca vai `;`.

{{exemplo}}

No mercado, compras a partir de R$ 200 ganham 10% de desconto. Entram
R$ 230, a resposta é Sim e o valor final é R$ 207; com Não, a seta cinza iria
direto ao final (`%%` mostra um `%` no `printf`):

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double total = 230.0;

    printf("Total: R$ %.2f\n", total);
    if (total >= 200) {
        total = total * 0.9; // 10% de desconto
        printf("Desconto de 10%% aplicado!\n");
    }
    printf("A pagar: R$ %.2f\n", total);
    return 0;
}
// Saída:
// Total: R$ 230.00
// Desconto de 10% aplicado!
// A pagar: R$ 207.00
```

A saída Não do losango não faz nada: vai direto ao "Mostrar", onde o Sim chega
depois do desconto:

{{fluxograma}}
