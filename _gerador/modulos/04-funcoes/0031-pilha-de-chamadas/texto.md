## 0031 · A pilha de chamadas

- **Pilha de chamadas**: a lista das funções em andamento. A de cima roda; as
  de baixo esperam um retorno (CELES; CERQUEIRA; RANGEL, 2016).
- **Quadro** (*stack frame*, registro de ativação): a memória de uma chamada,
  com os **parâmetros**, as **variáveis locais** e o **endereço de retorno**
  (BACKES, 2013, cap. 9).
- **LIFO**: chamou, empilha um quadro no topo; retornou, ele sai. A última
  função a começar é a primeira a terminar (DEITEL; DEITEL, 2011, cap. 5).
- **Por que a local some**: seu quadro foi desempilhado no `return`. E uma
  função não vê as locais de quem a chamou: estão noutro quadro (CELES;
  CERQUEIRA; RANGEL, 2016).
- **Stack trace**: o `bt` do `gdb` mostra a pilha no momento do erro (GDB, s.d.).
- **Stack overflow**: chamadas demais esgotam a pilha, que tem tamanho fixo
  (8 MB no Linux, `ulimit -s`), e o programa morre com `Segmentation fault`
  (BACKES, 2013, cap. 9).

```text
#0  calcular_taxa (valor=0) at pedido.c:12
#1  fechar_pedido () at pedido.c:30
#2  main () at pedido.c:5
```

> [!WARNING]
> Local sem inicializar não "começa limpa": o quadro novo reaproveita a memória
> de um quadro antigo, com o que ficou lá. O `-Wall` avisa
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
