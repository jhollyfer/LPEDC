## 0036 · A pilha de chamadas

Quando um programa em C quebra dentro do `gdb`, o comando `bt` mostra algo
assim:

```text
#0  calcular_taxa (valor=0) at pedido.c:12
#1  fechar_pedido () at pedido.c:30
#2  main () at pedido.c:5
```

Isso é um **stack trace** (ou *backtrace*): a **pilha de chamadas** impressa no
momento do erro. A função de cima estava rodando; ela foi chamada pela de
baixo, que foi chamada pela de baixo dela. O C mostra essa pilha sem esconder
nada.

Cada vez que uma função é chamada, o programa reserva um pedaço de memória só
para aquela chamada: o **quadro** (em inglês, *stack frame*, ou registro de
ativação). Nele ficam:

- os **parâmetros**, com as cópias dos argumentos;
- as **variáveis locais** da função;
- o **endereço de retorno**: em que ponto de quem chamou o programa continua
  quando a função acabar.

Os quadros se empilham como pratos. Chamou, empilha um quadro no **topo**.
Retornou, o quadro do topo sai, e o de baixo continua de onde parou. A última
função a começar é sempre a primeira a terminar: **último a entrar, primeiro a
sair** (LIFO, de *last in, first out*). Só o quadro do topo está rodando; os
outros estão parados, esperando um retorno.

É por isso que local "some" no `return`: o quadro dela foi desempilhado. E é
por isso que uma função não enxerga as variáveis de quem a chamou: elas estão
noutro quadro, mais embaixo.

Vamos ver na prática. Um pedido de R$ 50,00: o `main` chama
`total_com_entrega`, que chama `taxa_entrega`. No momento mais fundo há três
quadros na pilha. Quando `taxa_entrega` devolve 7.90, o quadro dela sai, e
`total_com_entrega` volta a rodar, já com o valor:

{{ideia}}

O código imprime "entra" e "sai" em cada função, com recuo, e a pilha aparece
na saída:

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

Repara no fluxograma: as chamadas empilham na descida, e os retornos
desempilham na ordem contrária. A decisão da taxa acontece lá no topo, dentro
de `taxa_entrega`, enquanto as outras duas funções esperam paradas:

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

Repara que existem **dois** `valor`, um em cada quadro, e cada função mexe só
no seu. E dois `total`: o do `main` e o de `total_com_entrega`.

> [!WARNING]
> Usar uma local sem inicializar e achar que ela "começa limpa". O quadro
> novo ocupa o mesmo pedaço de memória que um quadro antigo acabou de
> liberar, e ninguém apaga nada. Uma `int soma;` pode nascer com o valor que
> uma local de outra função deixou ali. Às vezes o programa até "funciona",
> por sorte, e quebra quando você muda outra coisa. O `-Wall` avisa
> `may be used uninitialized`: não ignore.

> [!TIP]
> **Por dentro do C:** a pilha é uma região de memória de tamanho fixo (no
> Linux, 8 MB por padrão; confira com `ulimit -s`) e cresce **para baixo**,
> dos endereços altos para os baixos. Um registrador do processador, o `rsp`,
> aponta para o topo. Empilhar um quadro é só subtrair do `rsp`; desempilhar
> é somar. Por isso chamar função é tão barato. Se a pilha passar do limite,
> o sistema mata o programa: é o **stack overflow** (no Linux, aparece como
> `Segmentation fault`). Com 8 MB e quadros de algumas dezenas de bytes, dá
> para empilhar centenas de milhares de chamadas, mas não infinitas. No
> `gdb`, o comando `bt` (*backtrace*) imprime a pilha, como no começo deste
> assunto.

> [!NOTE]
> **Pergunta para você:** mude o subtotal para 95.00. Quantos quadros a pilha
> chega a ter? O que muda na saída?

{{pratique}}
