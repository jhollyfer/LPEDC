## 0036 · Juntando tudo: o caixa da lanchonete

Sexta à noite, fila no food truck. O caixa lança os pedidos pelo código, soma,
põe 10% de serviço, recebe uma nota de R$ 50 e devolve o troco com o menor
número de notas e moedas. Parece um programa só, mas tem um **módulo** com o
cardápio, funções pequenas com **parâmetros** e retorno, um contador
**`static`** escondido, uma **macro** para a taxa e uma função **recursiva**
para o troco.

Antes de escrever, divida: cada tarefa vira uma função com um nome que diz o
que ela faz.

| Peça | Onde | O que usa do módulo |
| --- | --- | --- |
| `mostrar_cardapio`, `preco_centavos`, `mostrar_item` | `cardapio.c` | módulo `.h`/`.c`, `switch` |
| `itens_vendidos` | `cardapio.c` | global `static`: só o módulo mexe |
| `ler_codigo` | `caixa.c` | validação com `do...while` e retorno do `scanf` |
| `proxima_nota` | `caixa.c` | função pura: entra uma nota, sai a seguinte |
| `dar_troco` | `caixa.c` | recursão: caso base "troco zerado" |
| `TAXA_SERVICO` | `caixa.c` | `#define` |

Decisão importante: dinheiro em **centavos**, num `int`. R$ 7,90 vira `790`.
Com `double`, `0.1 + 0.2` não dá exatamente `0.3` (assunto 0012), e o troco
pode sair errado. Para mostrar, `%d.%02d` com `total / 100` e `total % 100`
monta o "42.24". O único `double` é o valor pago, lido do teclado e convertido
com `lround(pago * 100)`.

O troco recursivo lê como uma frase: "se o troco zerou, acabou; se a nota atual
cabe, dê essa nota e resolva o resto; se não cabe, tente a nota seguinte". Cada
chamada chega mais perto do fim, pois o troco ou a nota diminui.

Os pedidos 1, 2 e 3 somam R$ 38,40. Com 10% de serviço, a conta é R$ 42,24.
Pagando R$ 50, o troco de R$ 7,76 sai da recursão como
5 + 2 + 0,50 + 0,25 + 0,01:

{{ideia}}

O programa principal, `caixa.c`, usa o módulo do cardápio. O `cardapio.h` e o
`cardapio.c` estão na pasta do assunto (abra os dois):

```c
#include <math.h>
#include <stdio.h>

#include "cardapio.h"

#define TAXA_SERVICO 10 // por cento

// lê um código de 0 a 4; insiste até vir um válido
int ler_codigo(void) {
    int codigo;
    int lidos;
    do {
        printf("Código (0 fecha): ");
        lidos = scanf("%d", &codigo);
        if (lidos != 1) {
            return 0; // entrada acabou ou não é número: fecha a conta
        }
    } while (codigo < 0 || codigo > 4);
    return codigo;
}

// a nota seguinte, da maior para a menor (em centavos)
int proxima_nota(int nota) {
    switch (nota) {
    case 10000: return 5000;
    case 5000: return 2000;
    case 2000: return 1000;
    case 1000: return 500;
    case 500: return 200;
    case 200: return 100;
    case 100: return 50;
    case 50: return 25;
    case 25: return 10;
    case 10: return 5;
    default: return 1;
    }
}

// recursão: dá uma nota e resolve o troco que sobrou
void dar_troco(int centavos, int nota) {
    if (centavos == 0) {
        return; // caso base: troco completo
    }
    if (centavos >= nota) {
        printf("  %d.%02d\n", nota / 100, nota % 100);
        dar_troco(centavos - nota, nota);
    } else {
        dar_troco(centavos, proxima_nota(nota));
    }
}

int main(void) {
    int total = 0;

    mostrar_cardapio();
    for (int codigo = ler_codigo(); codigo != 0; codigo = ler_codigo()) {
        total += preco_centavos(codigo);
        mostrar_item(codigo);
        printf(" adicionado\n");
    }

    int servico = total * TAXA_SERVICO / 100;
    int conta = total + servico;
    printf("%d itens, conta com serviço: R$ %d.%02d\n",
           itens_vendidos(), conta / 100, conta % 100);

    double pago;
    printf("Valor pago: ");
    if (scanf("%lf", &pago) != 1) {
        return 0;
    }
    int troco = (int)lround(pago * 100) - conta;
    if (troco < 0) {
        printf("Faltam R$ %d.%02d\n", -troco / 100, -troco % 100);
        return 0;
    }
    printf("Troco: R$ %d.%02d\n", troco / 100, troco % 100);
    dar_troco(troco, 10000);
    return 0;
}
// Exemplo de uso (o que você digita vem depois dos dois-pontos):
// 1 X-salada   R$ 18.50
// 2 Batata     R$ 12.00
// 3 Suco       R$  7.90
// 4 Açaí       R$ 15.00
// Código (0 fecha): 1
// X-salada adicionado
// Código (0 fecha): 2
// Batata adicionado
// Código (0 fecha): 3
// Suco adicionado
// Código (0 fecha): 9
// Código (0 fecha): 0
// 3 itens, conta com serviço: R$ 42.24
// Valor pago: 50
// Troco: R$ 7.76
//   5.00
//   2.00
//   0.50
//   0.25
//   0.01
// Para testar sem digitar, salve como caixa.c numa pasta sua, com cópias do
// cardapio.h e do cardapio.c, e rode: printf '1\n2\n3\n9\n0\n50\n' | ./caixa
```

O laço dos pedidos termina com o código 0; depois vêm a conta, o pagamento e a
decisão "pagou o suficiente?". O troco, que parece um laço, é a recursão de
`dar_troco`:

{{fluxograma}}

O exemplo A072 mostra a outra vantagem de dividir em funções: **testar cada
peça sozinha**. Com a macro `CONFERIR`, definida no próprio arquivo, ele confere o
preço, o contador `static` e a contagem de notas sem digitar nada. Não precisa
de biblioteca de testes: uma macro de dez linhas resolve.

> [!WARNING]
> Efeito colateral escondido. `preco_centavos` parece só consultar um preço,
> mas também soma 1 no contador de itens vendidos. Chamá-la duas vezes para o
> mesmo pedido (uma para somar, outra para mostrar o preço) conta o item em
> dobro, e nada no nome avisa. É a armadilha das globais em escala menor.
> Quando uma função muda estado, deixe isso no nome (`registrar_pedido`) ou
> separe em duas: uma que consulta e outra que registra.

> [!NOTE]
> **Pergunta para você:** se o cliente pagar exatamente R$ 42,24, quantas
> chamadas de `dar_troco` acontecem? E o que o programa mostra se ele digitar
> 40?

{{pratique}}
