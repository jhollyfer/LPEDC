## 0055 · Ponteiro para função

No TypeScript, você passa função para função o tempo todo:
`temps.filter((t) => t >= 30)`, `botao.addEventListener('click', salvar)`,
`lista.sort((a, b) => a - b)`. Quem escreveu o `filter` não sabe qual teste
você quer; você entrega o teste pronto. Em C dá para fazer o mesmo, e o
mecanismo é um ponteiro.

O código de uma função também mora na memória: numa região própria, a área
de **código**. Então a função tem endereço, e o nome dela, sozinho, sem os
parênteses, **já é esse endereço** (como o nome de um vetor). Uma variável
que guarda esse endereço é um **ponteiro para função**.

A declaração assusta na primeira vez:

```text
int (*criterio)(int);
```

Leia de dentro para fora: `criterio` é um ponteiro (`*criterio`) para uma
função que recebe um `int` e devolve `int`. Os parênteses em volta de
`*criterio` são obrigatórios: sem eles, `int *criterio(int);` declara uma
função que devolve `int *`. O ponteiro só aceita funções com essa mesma
assinatura.

Para usar: `criterio = eh_calor;` guarda o endereço (sem `&` e sem
parênteses) e `criterio(31)` chama a função apontada. A forma
`(*criterio)(31)` também vale e aparece em código antigo.

A graça está em passar o ponteiro como **parâmetro**. A função que recebe
fica genérica, e quem chama decide o comportamento. A função passada se
chama **callback**. A biblioteca padrão usa isso no **`qsort`**
(`stdlib.h`), que ordena qualquer vetor desde que você entregue a função
que compara dois elementos (o A110 ordena a tabela do campeonato com ele).

Vamos ver na prática. As máximas da semana estão num vetor. A função
`conta_se` percorre o vetor e conta quantos dias passam num critério que
ela não conhece: recebe o endereço da função `eh_calor` (ou `eh_frio`) e
chama por ele:

{{ideia}}

No código, a mesma `conta_se` responde duas perguntas diferentes:

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

Repara no fluxograma: é o laço contador do assunto 0030. A única novidade
está no losango: a pergunta não é fixa, ela é a função que chegou pelo
parâmetro:

{{fluxograma}}

O `qsort` segue a mesma ideia, com uma diferença: como ele ordena vetores
de qualquer tipo, a função de comparação recebe os endereços de dois
elementos como `const void *` ("endereço de qualquer coisa"). Você converte
para o tipo certo e devolve um número negativo (a vem antes), zero (tanto
faz) ou positivo (b vem antes). O `void *` é o assunto 0056; por enquanto,
copie o molde do A110.

> [!WARNING]
> A comparação "esperta" `return *(const int *)a - *(const int *)b;`
> aparece em todo canto e tem um bug: com números grandes de sinais
> opostos, a subtração estoura o `int` (assunto 0008), o sinal vira e a
> ordem sai errada. O `rodar` acusa `signed integer overflow`. Use
> `return (x > y) - (x < y);`, que só compara e nunca estoura. E não
> esqueça os parênteses da declaração: `int *f(int)` é uma função, não um
> ponteiro.

> [!TIP]
> **Por dentro do C:** chamar por ponteiro é uma **chamada indireta**: o
> processador lê o endereço na variável e salta para ele, em vez de saltar
> para um endereço fixo gravado na instrução. Custa pouco, mas impede o
> compilador de copiar o corpo da função no lugar da chamada (*inline*).
> Por isso um laço com `criterio(v[i])` pode ser mais lento que um com
> `v[i] >= 30` escrito direto. Outro detalhe: o C não garante que um
> endereço de função caiba num `void *`, então `printf("%p", ...)` com
> função gera aviso no `-pedantic`. Ponteiro de dado e ponteiro de função
> são coisas separadas.

> [!NOTE]
> **Pergunta para você:** como contar os dias "agradáveis" (de 19 a 29
> graus) sem mexer em `conta_se`? E quantos são no vetor `temps`?

{{pratique}}
