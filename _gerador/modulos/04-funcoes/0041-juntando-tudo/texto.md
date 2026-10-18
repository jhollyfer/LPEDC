## 0041 · Juntando tudo: o caixa da lanchonete

Sexta à noite, fila no food truck. O caixa lança os pedidos pelo código, soma,
põe os 10% de serviço, recebe uma nota de R$ 50 e devolve o troco com o menor
número de notas e moedas. Parece um programa só, mas olhe as peças: um
**módulo** com o cardápio, funções pequenas com **parâmetros** e retorno, um
contador **`static`** escondido, uma **macro** para a taxa e uma função
**recursiva** para o troco. É o módulo inteiro trabalhando junto.

Antes de escrever, divida. Cada tarefa vira uma função com um nome que diz o
que ela faz:

| Peça | Onde | O que usa do módulo |
| --- | --- | --- |
| `mostrar_cardapio`, `preco_centavos`, `mostrar_item` | `cardapio.c` | módulo `.h`/`.c`, `switch` |
| `itens_vendidos` | `cardapio.c` | global `static`: só o módulo mexe |
| `ler_codigo` | `A081.c` | validação com `do...while` e retorno do `scanf` |
| `proxima_nota` | `A081.c` | função pura: entra uma nota, sai a seguinte |
| `dar_troco` | `A081.c` | recursão: caso base "troco zerado" |
| `TAXA_SERVICO` | `A081.c` | `#define` |

Uma decisão importante: dinheiro em **centavos**, num `int`. R$ 7,90 vira
`790`. Com `double`, `0.1 + 0.2` não dá exatamente `0.3`, e o troco de
centavos pode sair errado. Na hora de mostrar, `%d.%02d` com `total / 100` e
`total % 100` monta o "42.24". O único `double` é o valor pago, lido do
teclado e convertido com `lround(pago * 100)`.

O troco é recursivo e lê como uma frase: "se o troco zerou, acabou; se a nota
atual cabe, dê essa nota e resolva o resto; se não cabe, tente a nota
seguinte". Cada chamada chega mais perto do fim, porque ou o troco diminui ou
a nota diminui.

Vamos ver na prática. Os pedidos 1, 2 e 3 somam R$ 38,40. Com 10% de serviço,
a conta é R$ 42,24. Pagando R$ 50, o troco de R$ 7,76 sai da recursão como
5 + 2 + 0,50 + 0,25 + 0,01:

{{ideia}}

O programa principal. O `cardapio.h` e o `cardapio.c` estão na pasta do
assunto, e o `rodar` compila o módulo junto:

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
// Para testar sem digitar: printf '1\n2\n3\n9\n0\n50\n' | ~/LPEDC/rodar 04-funcoes/0041-juntando-tudo/A081.c
```

Repara no fluxograma: o laço dos pedidos termina com o código 0; depois vêm a
conta, o pagamento e a decisão "pagou o suficiente?". O troco, que parece um
laço, é a recursão de `dar_troco`:

{{fluxograma}}

O exemplo A082 mostra o outro lado de dividir em funções: dá para **testar
cada peça sozinha**. Com a macro `CONFERIR` (a do exercício E240), ele confere
o preço, o contador `static` e a contagem de notas sem digitar nada. Não
precisa de biblioteca de testes: uma macro de dez linhas resolve.

> [!WARNING]
> Efeito colateral escondido. `preco_centavos` parece só consultar um preço,
> mas também soma 1 no contador de itens vendidos. Se alguém chamar a função
> duas vezes para o mesmo pedido (uma para somar, outra para mostrar o
> preço), o item é contado em dobro, e nada no nome avisa. É a armadilha das
> globais em escala menor. Quando uma função muda estado, deixe isso no nome
> (`registrar_pedido`) ou separe em duas: uma que consulta e outra que
> registra.

> [!TIP]
> **Por dentro do C:** no troco de R$ 7,76, a pilha chega a 17 quadros de
> `dar_troco` ao mesmo tempo: 1 da primeira chamada, 5 das notas dadas, 11
> das trocas de nota (de 100 para 50, de 50 para 20...). Nenhum sai antes
> do caso base. Repare que a chamada recursiva é a última coisa que cada
> `dar_troco` faz: isso se chama **recursão de cauda**, e com `-O2` o `gcc`
> transforma tudo num laço, com um quadro só. Já o `cardapio.o` exporta 4 símbolos (`T`) e esconde o
> `vendidos` (`b`): confira com `nm`.

> [!NOTE]
> **Pergunta para você:** se o cliente pagar exatamente R$ 42,24, quantas
> chamadas de `dar_troco` acontecem? E o que o programa mostra se ele digitar
> 40?

{{pratique}}
