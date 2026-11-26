## 0023 · Break e continue

Até aqui, um laço só para quando a condição do cabeçalho dá falso, e cada volta
roda o corpo inteiro. Às vezes isso não basta. Você só descobre que precisa
parar no meio do corpo, depois de ler um dado. Ou descobre que um dado não
presta e quer pular o resto da volta sem encerrar o laço.

No caixa do mercado, a atendente passa os produtos um a um. Se o leitor falha
e marca um preço negativo, ela ignora aquela leitura e passa o próximo. Quando
a compra acaba, ela digita 0 e fecha a conta. São dois atalhos na mesma
repetição: "pula este" e "para tudo". Em C, eles se chamam **`continue`** e
**`break`** (DEITEL; DEITEL, 2011, cap. 4).

O **`break`** sai do laço **na hora**. O que resta do corpo não roda, a
condição não é testada de novo e o programa segue na primeira linha depois da
`}` do laço. É o mesmo `break` que você usou no assunto 0018 para sair de um `case` no
`switch` (DEITEL; DEITEL, 2011, cap. 4).

O **`continue`** é mais brando: abandona só a **volta atual**. O resto do
corpo é pulado e o laço segue para a próxima volta. Onde ele cai depende do
laço (DEITEL; DEITEL, 2011, cap. 4). No `for`, o passo (`i++`) ainda roda e só
depois vem a condição. No `while` e no `do...while`, o salto vai direto para a
condição. Essa diferença parece pequena, mas é ela que decide se o contador
anda ou fica parado, como o alerta no fim deste texto mostra.

Os dois quase sempre aparecem dentro de um `if`, porque só fazem sentido
quando algo acontece: "se o preço for 0, saia" ou "se o preço for negativo,
pule" (BACKES, 2013, cap. 5). Um `break` solto, sem `if`, encerraria o laço
logo na primeira volta.

O `break` abre caminho para um laço muito usado: o **`while (1)`**, que também
se escreve `for (;;)`. A condição é sempre verdadeira, então quem decide a
saída é um `break` no meio do corpo (KERNIGHAN; RITCHIE, 1988, cap. 3). Ele
serve quando o motivo de parar só aparece **depois** de ler o dado. No caixa,
você lê o preço e só então descobre que é 0; um `while` comum teria de testar
um valor que ainda não foi lido.

Depois de um laço com `break`, às vezes você precisa saber **por que** ele
parou: porque a condição deu falso ou porque o `break` disparou? A resposta
muda o que o programa conclui. O exemplo A046 testa se um número é primo
assim: o laço procura um divisor e dá `break` ao achar um. Se chegou ao fim
sem `break`, nenhum divisor apareceu e o número é primo.

Por fim, o alcance. `break` e `continue` valem só para o laço **mais
interno**, aquele que os envolve mais de perto (BACKES, 2013, cap. 5). Com um
laço dentro de outro, o `break` de dentro encerra só o de dentro, e o de fora
continua. O C não tem um `break` que saia de dois laços de uma vez. Existe o
`goto`, que salta para um rótulo em qualquer ponto da função, mas ele embaralha
o caminho do programa e deve ser evitado.

> [!WARNING]
> `continue` num `while` pode pular o passo. Em
> `while (i < 10) { if (i == 5) continue; printf("%d", i); i++; }`, quando `i`
> chega a 5, o `continue` volta à pergunta **sem** passar pelo `i++`: `i` fica
> 5 para sempre. No `for`, o mesmo código funciona, porque o `i++` está no
> cabeçalho e roda mesmo com `continue`.

{{exemplo}}

No caixa do mercado entram 12,90, uma leitura com erro (-1), 8,50, 4,00 e, para
fechar, 0. O -1 cai no `continue` e volta direto à leitura, sem passar pela
soma; o 0 cai no `break` e sai do laço:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double preco;
    double total = 0.0;
    int itens = 0;
    int ignorados = 0;

    while (1) { // "para sempre": quem decide a saída é o break
        printf("Preço (0 encerra): ");
        if (scanf("%lf", &preco) != 1) {
            break;          // entrada acabou ou não é número
        }
        if (preco == 0) {
            break;          // fim da compra: sai do laço
        }
        if (preco < 0) {
            printf("  leitura inválida, passe de novo\n");
            ignorados++;
            continue;       // pula o resto e volta para o while
        }
        total = total + preco;
        itens++;
    }

    printf("Itens: %d | Ignorados: %d\n", itens, ignorados);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
// Preço (0 encerra): 12.90
// Preço (0 encerra): -1
//   leitura inválida, passe de novo
// Preço (0 encerra): 8.50
// Preço (0 encerra): 4.00
// Preço (0 encerra): 0
// Itens: 3 | Ignorados: 1
// Total: R$ 25.40
```

O laço tem **duas** setas de volta para "Ler preço": a do `continue`, que pula
a soma, e a do fim normal do corpo. A **única** saída é o Sim de
"preço == 0?", o `break`:

{{fluxograma}}
