## 0022 · For

Você comprou uma TV de R$ 1.800 em 6 parcelas de R$ 300 e quer ver o carnê
inteiro, da parcela 1 à 6. Aqui você **sabe** quantas voltas são antes de
começar.

Com `while`, o contador aparece em três lugares:

```c
int parcela = 1;              // começa
while (parcela <= 6) {        // pergunta
    printf("Parcela %d\n", parcela);
    parcela++;                // passo, lá no fim do corpo
}
```

Esquecer o `parcela++` gera um laço infinito. O **`for`** junta começo,
pergunta e passo numa linha:

```c
for (int parcela = 1; parcela <= 6; parcela++) {
    printf("Parcela %d\n", parcela);
}
```

A ordem de execução não é a da escrita:

1. **início** (`int parcela = 1`): roda **uma vez**, antes de tudo;
2. **condição** (`parcela <= 6`): testada antes de cada volta; falsa, o laço
   acaba;
3. **corpo**: o que está entre as chaves;
4. **passo** (`parcela++`): roda **no fim** de cada volta e volta para a
   condição.

O `for` é o `while` acima reorganizado; o compilador trata os dois do mesmo
jeito. Use `for` quando há um **contador** com começo, fim e passo conhecidos;
`while` quando só se sabe a condição de parada.

O `int parcela` declarado no `for` só existe dentro do laço (C99 em diante). O
passo pode ser qualquer conta: `c += 10`, `s--`, `x *= 3`. O contador pode ser
`char`, porque `char` é número. A vírgula permite duas variáveis:
`for (int i = 1, j = 9; i < j; i++, j--)`. O exemplo A044 mostra tudo isso.
Qualquer parte pode ficar vazia, mas os dois `;` são obrigatórios: `for (;;)` é
um laço infinito de propósito.

Quantas voltas? `for (i = a; i < b; i++)` dá `b - a`. Com `<=`, dá
`b - a + 1`. De 1 a 6 com `<=`: 6 voltas.

O carnê começa com `parcela = 1` uma vez só, pergunta "parcela <= 6?", roda o
corpo, dá o passo e volta à pergunta. Na sétima, com `parcela = 7`, a resposta
é Não:

{{ideia}}

O carnê em C:

```c
#include <stdio.h>

int main(void) {
    double preco = 1800.0;
    int total_parcelas = 6;
    double valor = preco / total_parcelas;
    double falta = preco;

    for (int parcela = 1; parcela <= total_parcelas; parcela++) {
        falta = falta - valor;
        printf("Parcela %d/%d: R$ %.2f (falta R$ %.2f)\n",
               parcela, total_parcelas, valor, falta);
    }
    printf("Carnê quitado!\n");
    return 0;
}
// Saída:
// Parcela 1/6: R$ 300.00 (falta R$ 1500.00)
// Parcela 2/6: R$ 300.00 (falta R$ 1200.00)
// Parcela 3/6: R$ 300.00 (falta R$ 900.00)
// Parcela 4/6: R$ 300.00 (falta R$ 600.00)
// Parcela 5/6: R$ 300.00 (falta R$ 300.00)
// Parcela 6/6: R$ 300.00 (falta R$ 0.00)
// Carnê quitado!
```

O fluxograma é igual ao de um `while`, porque o `for` só reorganiza o código.
O passo `parcela++` fica no fim do corpo, e a seta sai dele de volta ao
losango:

{{fluxograma}}

> [!WARNING]
> O erro mais comum é o **erro por um** (*off-by-one*): uma volta a mais ou a
> menos. `for (int p = 1; p < 6; p++)` mostra 5 parcelas;
> `for (int p = 0; p <= 6; p++)` mostra 7. Pergunte: qual é o **primeiro**
> valor do contador e qual é o **último** que passa pela condição? Outro
> clássico: controlar o laço com `double`. `for (double x = 0.1; x != 1.0; x
> += 0.1)` nunca termina, porque 0,1 não é exato em binário e `x` pula o 1,0.
> Contador é sempre inteiro.

> [!NOTE]
> **Pergunta para você:** quantas vezes roda `for (int i = 10; i > 0; i -= 3)`
> e com quais valores de `i`? E qual valor faz a condição dar falso? Responda
> no papel e depois coloque um `printf` no corpo para conferir.

{{pratique}}
