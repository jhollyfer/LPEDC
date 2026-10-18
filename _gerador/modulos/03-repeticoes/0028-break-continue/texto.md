## 0028 · Break e continue

No caixa do mercado, a atendente passa os produtos um a um. Às vezes o leitor
falha e marca um preço negativo: ela ignora e passa de novo. Quando a compra
acaba, ela digita 0 e fecha a conta. Dois atalhos dentro da mesma repetição:
"pula este" e "para tudo".

Em C, esses atalhos são o **`break`** e o **`continue`**:

- **`break`**: sai do laço **na hora**. O programa segue na primeira linha
  depois da `}` do laço. É o mesmo `break` do `switch` (assunto 0023).
- **`continue`**: abandona só a **volta atual**. O resto do corpo é pulado e o
  laço segue para a próxima pergunta. No `for`, o passo (`i++`) ainda roda
  antes da pergunta; no `while`, o salto vai direto para a pergunta.

Os dois quase sempre aparecem dentro de um `if`: "se acontecer tal coisa,
saia" ou "se acontecer tal coisa, pule".

Com o `break`, aparece um laço muito comum: o **`while (1)`** (ou `for (;;)`).
A condição é sempre verdadeira, e quem decide a saída é um `break` no meio do
corpo. Isso é útil quando o motivo para parar só aparece **depois** de ler o
dado, como no caixa: você lê o preço e só então descobre que é 0.

Depois de um laço com `break`, às vezes você precisa saber **por que** ele
parou: pela condição ou pelo `break`? O exemplo A056 testa se um número é
primo assim: se o laço chegou ao fim sem achar divisor, é primo.

Vamos ver na prática. A compra tem 12,90, uma leitura com erro (-1), 8,50,
4,00 e, para fechar, 0. O -1 cai no `continue` e volta direto para a leitura,
sem passar pela soma. O 0 cai no `break` e sai do laço:

{{ideia}}

O caixa em C:

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

Repara no fluxograma: o laço tem **duas** setas de volta para "Ler preço". Uma
sai direto do losango "preço < 0?" pelo Sim: é o `continue`, que pula a soma.
A outra sai do fim normal do corpo. E tem **uma** saída, o Sim de
"preço == 0?", que é o `break`:

{{fluxograma}}

> [!WARNING]
> `continue` num `while` pode pular o passo. Em
> `while (i < 10) { if (i == 5) continue; printf("%d", i); i++; }`, quando `i`
> chega a 5, o `continue` volta para a pergunta **sem** passar pelo `i++`. O
> `i` fica 5 para sempre: laço infinito. No `for`, o mesmo código funciona,
> porque o passo `i++` fica no cabeçalho e roda mesmo com `continue`. É a única
> diferença real entre um `for` e o `while` equivalente.

> [!TIP]
> **Por dentro do C:** `break` e `continue` são saltos com destino fixo. O
> `break` vira "pule para depois do laço"; o `continue`, "pule para o passo"
> (no `for`) ou "pule para a pergunta" (no `while`). Eles valem só para o laço
> **mais interno**. Não existe `break` com rótulo para sair de dois laços de
> uma vez. O C tem o `goto rotulo;`, que salta para qualquer ponto da
> mesma função. Evite: ele só é aceito, em código de verdade, para sair de
> vários laços de uma vez ou para pular para a limpeza no fim de uma função.

> [!NOTE]
> **Pergunta para você:** se o primeiro preço digitado for 0, o que aparece na
> tela? E se o primeiro for uma letra? Siga o código com o dedo e depois teste
> no A055 com `printf '0\n' | ~/LPEDC/rodar ...`.

{{pratique}}
