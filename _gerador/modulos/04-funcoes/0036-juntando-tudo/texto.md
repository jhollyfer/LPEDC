## 0036 · Juntando tudo: o caixa da lanchonete

Sexta à noite, fila no food truck. O caixa lança os pedidos pelo código,
soma, põe 10% de serviço, recebe uma nota de R$ 50 e devolve o troco com o
menor número de notas e moedas. Parece um programa só, mas cabe nele quase
tudo o que o módulo 04 ensinou: um **módulo** separado com o cardápio, funções pequenas com
**parâmetros** e retorno, um contador **`static`** escondido, uma constante
do pré-processador para a taxa e uma função **recursiva** para o troco.

Antes de escrever uma linha, divida o trabalho. Cada tarefa vira uma função
com um nome que diz o que ela faz (DEITEL; DEITEL, 2011, cap. 5). Pense na
lanchonete de verdade: o gerente não frita, não cobra e não conta troco; ele
pede a cada um e junta os resultados. No programa, o `main` faz o papel do
gerente. Ele chama `ler_codigo`, `preco_centavos` e `dar_troco`, e cada uma
resolve a sua parte sem saber como as outras trabalham. Quando algo dá
errado, o nome da função já diz onde procurar.

O cardápio fica num módulo próprio, o par `cardapio.h` e `cardapio.c` do
assunto 0034 (BACKES, 2013, cap. 13). O `.h` promete as funções de
consulta; o `.c` guarda os preços e o contador `vendidos`, uma global
`static` que só o módulo pode alterar. Quem está em `caixa.c` lê o contador
pela função `itens_vendidos()`, mas não consegue mudá-lo por engano.

Uma decisão vem antes de qualquer código: dinheiro em **centavos**, num
`int`. R$ 7,90 vira `790`. O motivo é a precisão. Um `double` guarda os
números em binário, e valores como 0,1 não têm representação exata; por isso
`0.1 + 0.2` não dá exatamente `0.3` (assunto 0012), e um troco calculado
assim pode errar um centavo. Com inteiros, toda conta é exata. Para mostrar,
`%d.%02d` com `total / 100` e `total % 100` monta o texto "42.24". O único
`double` do programa é o valor pago, que chega do teclado e é convertido de
imediato com `lround(pago * 100)`, que arredonda para o inteiro mais
próximo.

O troco recursivo se lê como uma frase (FEOFILOFF, 2009, cap. 5). "Se o troco
zerou, acabou. Se a nota atual cabe no troco, dê essa nota e resolva o resto.
Se não cabe, tente a nota seguinte." O caso base é o troco zerado. Os dois
casos recursivos diminuem alguma coisa: o primeiro diminui o troco, o segundo
passa para uma nota menor. Como a menor moeda é de 1 centavo, que cabe em
qualquer troco positivo, toda chamada chega mais perto do fim. A função
`proxima_nota` diz qual é a nota seguinte; ela é uma **função pura**, que só
depende do que recebe e não muda nada fora dela.

Com as peças separadas, dá para testar cada uma sozinha, sem digitar pedidos
no teclado. O exemplo A072 usa uma macro `CONFERIR` para comparar o preço, o
contador e as notas com o valor esperado. A tabela mostra onde cada peça mora
e o que ela usa do módulo:

| Peça | Onde | O que usa do módulo |
| --- | --- | --- |
| `mostrar_cardapio`, `preco_centavos`, `mostrar_item` | `cardapio.c` | módulo `.h`/`.c`, `switch` |
| `vendidos` | `cardapio.c` | global `static`: só o módulo mexe |
| `ler_codigo` | `caixa.c` | validação com `do...while` e retorno do `scanf` |
| `proxima_nota` | `caixa.c` | função pura: entra uma nota, sai a seguinte |
| `dar_troco` | `caixa.c` | recursão: caso base "troco zerado" |
| `TAXA_SERVICO` | `caixa.c` | `#define` |

> [!WARNING]
> Efeito colateral escondido: `preco_centavos` parece só consultar um preço,
> mas também soma 1 no contador de vendidos. Chamá-la duas vezes para o mesmo
> pedido conta o item em dobro. Quando a função muda estado, diga no nome
> (`registrar_pedido`) ou separe em duas.

{{exemplo}}

Os pedidos 1, 2 e 3 somam R$ 38,40; com 10% de serviço, R$ 42,24. Pagando
R$ 50, o troco de R$ 7,76 sai da recursão como 5 + 2 + 0,50 + 0,25 + 0,01:

{{ideia}}

O `caixa.c` usa o módulo do cardápio (o `cardapio.h` e o `cardapio.c` estão na
pasta do assunto):

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

O laço dos pedidos termina com o código 0; depois vêm a conta, o pagamento e o
troco, que é a recursão de `dar_troco`:

{{fluxograma}}
