## 0019 · if

No caixa do mercado, a placa avisa: compras a partir de R$ 200 ganham 10% de
desconto. Sua compra deu R$ 230. A moça do caixa faz uma pergunta e, só se a
resposta for sim, faz um passo a mais. Se for não, a vida segue sem desconto.

Esse "só se" é o **`if`**. No C, a sintaxe é esta:

```c
if (condição) {
    // só roda quando a condição é verdadeira
}
// daqui em diante roda sempre
```

A **condição** vai sempre entre parênteses. Ela pode ser qualquer expressão
que dê um número: uma comparação (`total >= 200`), uma combinação lógica
(`idade >= 18 && tem_cnh`) ou até uma variável sozinha. Vale a regra do 0017:
**zero é falso, o resto é verdade**. `if (saldo)` é o mesmo que
`if (saldo != 0)`, e `if (!saldo)` é o mesmo que `if (saldo == 0)`.

O **bloco** entre chaves pode ter quantas instruções você quiser. Sem chaves, o
`if` manda em **uma** instrução só, a primeira depois dele:

```c
if (total >= 200)
    total = total * 0.9;   // depende do if
printf("Pronto\n");        // NÃO depende, apesar de qualquer recuo
```

O recuo (indentação) é só para quem lê. O compilador ignora espaços. Isso
engana muita gente quando acrescenta uma segunda linha "dentro" do `if` sem
chaves e ela roda sempre. Por isso o conselho do curso: **use chaves sempre**,
mesmo com uma linha só. Abra e feche as chaves antes de escrever o miolo.

Repare que o `if` sozinho não tem um "senão". Quando a condição é falsa, o
bloco é pulado e o programa continua na linha seguinte. É o que chamamos de
**seleção simples**: fazer um passo extra ou não fazer nada.

Vamos ver na prática. Os R$ 230 entram, a pergunta responde Sim, o desconto
acontece e o valor final sai com R$ 207. Se a resposta fosse Não, a seta
cinza levaria direto para o final, sem passar pelo desconto:

{{ideia}}

O mesmo exemplo em C. O `%%` dentro do `printf` mostra um `%`:

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

Repara no fluxograma: o losango tem duas saídas, como sempre, mas a do Não
não faz nada. Ela vai direto para o "Mostrar", o mesmo ponto onde o caminho do
Sim chega depois do desconto:

{{fluxograma}}

> [!WARNING]
> **O `;` depois do `if` mata a condição.** Em `if (total >= 200);` o
> ponto e vírgula é uma **instrução vazia**: ela é o corpo do `if`. O bloco
> `{ ... }` que vem embaixo vira um bloco solto, que roda **sempre**. Compila
> sem erro, e todo mundo ganha desconto. O `-Wextra` do `rodar` avisa
> ("suggest braces around empty body"). No fim da linha do `if` nunca vai
> `;`: ou vem `{`, ou vem a instrução.

> [!TIP]
> **Por dentro do C:** o `if` vira duas instruções de máquina. Primeiro um
> `cmp` compara `total` com 200. Depois vem um salto condicional que faz o
> **contrário** do que você escreveu: "se for **menor**, pula o bloco". Quando
> a condição é verdadeira, o processador simplesmente não pula e cai dentro do
> bloco. Rode `gcc -S A037.c` e procure um `jb`, `jl` ou parecido logo depois
> do `comisd` ou `cmp`. O `if` é só isso: comparar e, talvez, pular.

> [!NOTE]
> **Pergunta para você:** e se a compra der exatamente R$ 200,00? E R$ 199,99?
> Responda olhando o `>=` e depois troque `230.0` no A037 para conferir.

{{pratique}}
