## 0050 · Ponteiro para função

Às vezes uma função precisa receber **outra função**. Uma rotina que conta
dias quentes e outra que conta dias frios fazem quase a mesma coisa: andam
pelo vetor de temperaturas e contam quem passa num teste. Só o teste muda.
Escrever uma função por teste repete o laço inteiro. O ideal seria uma rotina
só, que recebesse o teste pronto e se limitasse a chamá-lo. Em C, o mecanismo
para isso é um ponteiro.

O raciocínio começa na memória. O código de uma função também fica guardado
nela, numa área própria, a área de **código**. Se a função mora num lugar,
ela tem endereço, e o nome da função, sem parênteses, **já é esse
endereço**, do mesmo jeito que o nome de um vetor é o endereço do primeiro
item. Uma variável que guarda esse endereço é um **ponteiro para função**
(BACKES, 2013, cap. 13). Pense no número de telefone de um eletricista: você
não carrega o eletricista no bolso, só o número, e liga quando precisa.

A declaração parece estranha à primeira vista:

```text
int (*criterio)(int);
```

Leia de dentro para fora. `*criterio` diz que `criterio` é um ponteiro; o
`(int)` à direita diz que ele aponta para uma função que recebe um `int`; o
`int` à esquerda é o que essa função devolve. Os parênteses em volta de
`*criterio` são obrigatórios. Sem eles, `int *criterio(int);` declara uma
**função** chamada `criterio` que devolve `int *`, e não um ponteiro (DEITEL;
DEITEL, 2011, cap. 7).

O tipo do ponteiro inclui a **assinatura** da função, isto é, os tipos dos
parâmetros e do retorno. Por isso `criterio` só aceita funções que recebem um
`int` e devolvem `int`; uma função com outro protótipo não cabe ali (BACKES,
2013, cap. 13).

O uso é curto. `criterio = eh_calor;` guarda o endereço da função, sem `&` e
sem parênteses. `criterio(31)` chama a função apontada, passando 31, como se
`criterio` fosse o próprio nome dela. A forma `(*criterio)(31)` também vale e
aparece em código antigo; as duas fazem a mesma chamada (DEITEL; DEITEL,
2011, cap. 7).

O uso típico é passar o ponteiro como **parâmetro**. A função que o recebe
fica genérica, e quem chama decide o comportamento. A função entregue dessa
forma se chama **callback**, porque a rotina genérica "liga de volta" para
ela na hora certa (CELES; RANGEL, 2002). Com isso, uma única `conta_se`
conta dias quentes ou frios, dependendo de qual teste você entrega.

A biblioteca padrão usa esse recurso no **`qsort`**, do `<stdlib.h>`. Ele
ordena um vetor de qualquer tipo, desde que você entregue a função que
compara dois elementos. Essa função recebe dois `const void *`, os endereços
dos dois elementos (o assunto 0051 explica esse tipo), e devolve um número
negativo se o primeiro vem antes, zero se empatam e positivo se o primeiro
vem depois (KERRISK, s.d.). O A100 ordena a tabela do campeonato assim.

Chamar por ponteiro tem um custo pequeno. É uma **chamada indireta**: o
processador lê o endereço guardado na variável e salta para ele. Isso impede
o compilador de copiar o corpo da função no lugar da chamada, otimização
chamada *inline*, então `criterio(v[i])` pode sair mais lento que escrever o
teste `v[i] >= 30` direto no laço. Na maioria dos programas a diferença não
aparece.

> [!WARNING]
> A comparação "esperta" `return *(const int *)a - *(const int *)b;` estoura
> o `int` quando os números têm sinais opostos e são grandes (`signed integer
> overflow`), e a ordem sai errada. Use `return (x > y) - (x < y);`. E não
> esqueça os parênteses: `int *f(int)` é função, não ponteiro.

{{exemplo}}

As máximas da semana estão num vetor. `conta_se` conta os dias que passam num
critério que ela não conhece: recebe o endereço de `eh_calor` (ou `eh_frio`) e
chama por ele:

{{ideia}}

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

É o contador do assunto 0025; a novidade é que a pergunta do losango é a
função que chegou pelo parâmetro:

{{fluxograma}}
