## 0031 · A pilha de chamadas

O assunto 0030 deixou duas perguntas no ar. Por que uma variável local some
quando a função termina? E por que cada chamada começa com locais novas? A
resposta está no jeito como o programa organiza a memória das chamadas em
andamento. Entender esse mecanismo também ajuda a ler as mensagens de erro e
prepara o terreno para a recursão, no assunto 0032.

Quando um programa em C quebra dentro do `gdb`, o depurador do GNU, o comando
`bt` mostra algo assim:

```text
#0  calcular_taxa (valor=0) at pedido.c:12
#1  fechar_pedido () at pedido.c:30
#2  main () at pedido.c:5
```

Esse relatório é um **stack trace**, ou *backtrace* (GDB, s.d.). Ele mostra a
**pilha de chamadas**: a lista das funções que estão em andamento naquele
instante (CELES; CERQUEIRA; RANGEL, 2016). Leia de baixo para cima. O `main`
chamou `fechar_pedido`, que chamou `calcular_taxa`, e o erro aconteceu nesta
última, na linha 12. Só a de cima estava rodando; as de baixo esperavam um
retorno.

A cada chamada, o programa reserva um pedaço de memória só para ela, o
**quadro**, também chamado de *stack frame* ou registro de ativação (BACKES,
2013, cap. 9). O quadro guarda três coisas. Os **parâmetros**, com as cópias
dos argumentos (assunto 0029). As **variáveis locais** da função. E o
**endereço de retorno**: o ponto exato, dentro de quem chamou, em que o
programa deve continuar quando a função acabar. Sem esse endereço, o programa
não saberia para onde voltar.

Os quadros se empilham como pratos na pia. Chamou uma função, um quadro novo
vai para o **topo**. A função retornou, o quadro do topo sai, e o de baixo
continua do ponto em que parou. A última função a começar é sempre a primeira
a terminar. Essa regra tem nome: **último a entrar, primeiro a sair**, ou
**LIFO** (*last in, first out*) (DEITEL; DEITEL, 2011, cap. 5). A mesma regra
volta no módulo de estruturas de dados, quando você mesmo construir uma pilha.

Agora as perguntas do começo têm resposta. A local "some" no `return` porque
o quadro dela foi desempilhado. Cada chamada começa com locais novas porque
ganha um quadro novo. E uma função não enxerga as variáveis de quem a chamou
porque elas estão noutro quadro, mais embaixo, fora do seu escopo (CELES;
CERQUEIRA; RANGEL, 2016).

A pilha tem tamanho fixo. No Linux, o padrão é 8 MB por programa, e o comando
`ulimit -s` mostra o valor (BACKES, 2013, cap. 9). Dá para empilhar centenas
de milhares de chamadas pequenas, mas não infinitas. Se o programa passa do
limite, o sistema o encerra: é o **stack overflow**, o estouro da pilha, que
no Linux aparece como `Segmentation fault`. O caso mais comum é uma recursão
que nunca para, e o assunto 0032 mostra como evitar.

> [!WARNING]
> Local sem inicializar não "começa limpa". O quadro novo ocupa a memória que
> um quadro antigo acabou de liberar, e ninguém a apaga: uma `int soma;` pode
> nascer com o valor que outra função deixou ali. O `-Wall` avisa
> `may be used uninitialized`.

{{exemplo}}

Num pedido de R$ 50,00, o `main` chama `total_com_entrega`, que chama
`taxa_entrega`. No fundo há três quadros; quando `taxa_entrega` devolve 7.90,
seu quadro sai:

{{ideia}}

```c
#include <stdio.h>

double taxa_entrega(double valor) {
    printf("    entra taxa_entrega(%.2f)\n", valor);
    double taxa = valor < 80.00 ? 7.90 : 0.00;
    printf("    sai taxa_entrega -> %.2f\n", taxa);
    return taxa;
}

double total_com_entrega(double valor) {
    printf("  entra total_com_entrega(%.2f)\n", valor);
    double total = valor + taxa_entrega(valor);
    printf("  sai total_com_entrega -> %.2f\n", total);
    return total;
}

int main(void) {
    double subtotal = 50.00;

    printf("entra main\n");
    double total = total_com_entrega(subtotal);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
// Saída:
// entra main
//   entra total_com_entrega(50.00)
//     entra taxa_entrega(50.00)
//     sai taxa_entrega -> 7.90
//   sai total_com_entrega -> 57.90
// Total: R$ 57.90
```

As chamadas empilham na descida e os retornos desempilham na ordem contrária;
a decisão da taxa ocorre no topo:

{{fluxograma}}

### Passo a passo

A pilha em cada momento, de baixo para cima (o topo é o último):

| Momento | Pilha (base → topo) | Quem roda |
| --- | --- | --- |
| início | `main` (subtotal = 50.00) | `main` |
| chamou `total_com_entrega(50.00)` | `main` → `total_com_entrega` (valor = 50.00) | `total_com_entrega` |
| chamou `taxa_entrega(50.00)` | `main` → `total_com_entrega` → `taxa_entrega` (valor = 50.00, taxa = 7.90) | `taxa_entrega` |
| `taxa_entrega` devolveu 7.90 | `main` → `total_com_entrega` (total = 57.90) | `total_com_entrega` |
| `total_com_entrega` devolveu 57.90 | `main` (total = 57.90) | `main` |

Há dois `valor` e dois `total`, um em cada quadro.
