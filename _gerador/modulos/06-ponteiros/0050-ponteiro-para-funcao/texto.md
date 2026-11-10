## 0050 · Ponteiro para função

Às vezes uma função precisa receber **outra função**. Uma rotina que filtra
temperaturas não sabe o teste que você quer (acima de 30? abaixo de 0?); uma
que ordena não sabe a ordem. Você entrega o teste pronto e ela só o chama. Em
C, o mecanismo é um ponteiro.

O código de uma função fica na memória, na área de **código**. Logo, a função
tem endereço, e o nome dela, sem parênteses, **já é esse endereço** (como o
nome de um vetor). Uma variável que guarda esse endereço é um **ponteiro para
função**.

A declaração estranha:

```text
int (*criterio)(int);
```

Leia de dentro para fora: `criterio` é um ponteiro (`*criterio`) para uma
função que recebe um `int` e devolve `int`. Os parênteses em volta de
`*criterio` são obrigatórios: sem eles, `int *criterio(int);` declara uma
função que devolve `int *`. O ponteiro só aceita funções com essa assinatura.

`criterio = eh_calor;` guarda o endereço (sem `&` nem parênteses) e
`criterio(31)` chama a função apontada. `(*criterio)(31)` também vale e
aparece em código antigo.

O uso típico é passar o ponteiro como **parâmetro**: a função fica genérica e
quem chama decide o comportamento. A função passada é um **callback**. A
biblioteca padrão usa isso no **`qsort`** (`stdlib.h`), que ordena qualquer
vetor se você entregar a função que compara dois elementos (o A100 ordena a
tabela do campeonato com ele).

As máximas da semana estão num vetor. A função `conta_se` conta quantos dias
passam num critério que ela não conhece: recebe o endereço de `eh_calor` (ou
`eh_frio`) e chama por ele:

{{ideia}}

A mesma `conta_se` responde duas perguntas:

```c
#include <stdio.h>

int eh_calor(int t) { return t >= 30; }
int eh_frio(int t) { return t <= 18; }

// conta quantos elementos passam no teste; QUAL teste, quem chama decide
int conta_se(const int *v, int n, int (*criterio)(int)) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(v[i])) { // chama a função para onde criterio aponta
            cont++;
        }
    }
    return cont;
}

int main(void) {
    int temps[7] = {31, 27, 33, 18, 16, 29, 34}; // máximas da semana

    int (*regra)(int) = eh_calor;  // o nome da função já é o endereço dela
    printf("Dias de calor: %d\n", conta_se(temps, 7, regra));
    printf("Dias de frio:  %d\n", conta_se(temps, 7, eh_frio));
    return 0;
}
// Saída:
// Dias de calor: 3
// Dias de frio:  2
```

É o contador do assunto 0025. A novidade está no losango: a pergunta é a função
que chegou pelo parâmetro:

{{fluxograma}}

O `qsort` segue a mesma ideia, mas, como ordena qualquer tipo, a função de
comparação recebe dois endereços como `const void *`. Você converte para o tipo
certo e devolve negativo (a vem antes), zero (tanto faz) ou positivo (b vem
antes). O `void *` é o assunto 0051; por ora, copie o molde do A100.

> [!WARNING]
> A comparação "esperta" `return *(const int *)a - *(const int *)b;` tem um bug:
> com números grandes de sinais opostos, a subtração estoura o `int` (assunto
> 0003) e a ordem sai errada. O gcc com as flags de estudo acusa `signed integer
> overflow`. Use `return (x > y) - (x < y);`. E não esqueça os parênteses da
> declaração: `int *f(int)` é uma função, não um ponteiro.

> [!TIP]
> **Por dentro do C:** chamar por ponteiro é uma **chamada indireta**: o
> processador lê o endereço na variável e salta para ele. Isso impede o
> compilador de copiar o corpo da função no lugar da chamada (*inline*), então
> `criterio(v[i])` pode ser mais lento que `v[i] >= 30` direto.

> [!NOTE]
> **Pergunta para você:** como contar os dias "agradáveis" (de 19 a 29
> graus) sem mexer em `conta_se`? E quantos são no vetor `temps`?

{{pratique}}
