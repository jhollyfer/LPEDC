## 0022 · For

Você comprou uma TV de R$ 1.800 em 6 parcelas de R$ 300 e quer ver o carnê
inteiro: parcela 1, parcela 2... até a 6. Aqui você **sabe** quantas voltas são,
antes de começar.

Dá para fazer com `while`, mas repare em quantos lugares o contador aparece:

```c
int parcela = 1;              // começa
while (parcela <= 6) {        // pergunta
    printf("Parcela %d\n", parcela);
    parcela++;                // passo, lá no fim do corpo
}
```

Três peças espalhadas: começo, pergunta e passo. Esqueça o `parcela++` lá
embaixo e você ganha um laço infinito. O **`for`** junta as três numa linha só:

```c
for (int parcela = 1; parcela <= 6; parcela++) {
    printf("Parcela %d\n", parcela);
}
```

A ordem em que as partes rodam não é a ordem em que estão escritas:

1. **início** (`int parcela = 1`): roda **uma vez**, antes de tudo;
2. **condição** (`parcela <= 6`): testada antes de cada volta; falsa, o laço
   acaba;
3. **corpo**: o que está entre as chaves;
4. **passo** (`parcela++`): roda **no fim** de cada volta, e então volta para
   a condição.

O `for` é exatamente o `while` de cima, reorganizado. O compilador trata os
dois do mesmo jeito. Use `for` quando há um **contador** com começo, fim e
passo conhecidos; `while` quando você só sabe a condição de parada.

O `int parcela` declarado dentro do `for` só existe
dentro do laço (C99 em diante). O passo pode ser qualquer conta: `c += 10`,
`s--`, `x *= 3`. O contador pode ser `char`, porque `char` é número. E a
vírgula permite duas variáveis: `for (int i = 1, j = 9; i < j; i++, j--)`. O
exemplo A044 mostra tudo isso. Qualquer parte pode ficar vazia, mas os dois
`;` são obrigatórios: `for (;;)` é um laço infinito de propósito.

Quantas voltas? `for (i = a; i < b; i++)` dá `b - a` voltas. Com `<=`, dá
`b - a + 1`. De 1 a 6 com `<=`: 6 voltas.

Vamos ver na prática. O carnê começa com `parcela = 1` uma vez só, pergunta
"parcela <= 6?", roda o corpo, dá o passo e volta para a pergunta. Na sétima
pergunta, com `parcela = 7`, a resposta é Não:

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

Repara no fluxograma: ele é igual ao de um `while`. O `for` não inventa forma
nova; ele só arruma o código. O passo `parcela++` fica no fim do corpo, e a
seta sai dele e volta para o losango:

{{fluxograma}}

> [!WARNING]
> O erro mais comum do `for` é o **erro por um** (*off-by-one*): uma volta a
> mais ou a menos. `for (int p = 1; p < 6; p++)` mostra só 5 parcelas;
> `for (int p = 0; p <= 6; p++)` mostra 7. Antes de rodar, faça duas perguntas:
> qual é o **primeiro** valor do contador e qual é o **último** que passa pela
> condição? Outro clássico: controlar o laço com `double`.
> `for (double x = 0.1; x != 1.0; x += 0.1)` nunca termina, porque 0,1 não é
> exato em binário e `x` pula o 1,0. Contador é sempre inteiro.

> [!TIP]
> **Por dentro do C:** compile o `for` e o `while` equivalente com `gcc -S` e
> compare o assembly: é o mesmo. O contador nem chega a ocupar memória: com
> otimização, o gcc o guarda num **registrador**, uma gaveta dentro do próprio
> processador. Com `-O2`, ele pode até **desenrolar** o laço (escrever o corpo
> várias vezes seguidas para economizar saltos) quando sabe quantas voltas são.
> É mais um motivo para usar `for` com contador: o compilador entende a sua
> intenção.

> [!NOTE]
> **Pergunta para você:** quantas vezes roda `for (int i = 10; i > 0; i -= 3)`
> e com quais valores de `i`? E qual valor faz a condição dar falso? Responda
> no papel e depois coloque um `printf` no corpo para conferir.

{{pratique}}
