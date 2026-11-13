## 0023 · Break e continue

- **`break`**: sai do laço **na hora** e segue depois da `}`. É o mesmo
  `break` do `switch` (0018) (DEITEL; DEITEL, 2011, cap. 4).
- **`continue`**: abandona só a **volta atual**; o resto do corpo é pulado. No
  `for`, o passo (`i++`) ainda roda antes da pergunta; no `while`, o salto vai
  direto para a pergunta (DEITEL; DEITEL, 2011, cap. 4).
- **Dentro de um `if`**: os dois quase sempre aparecem assim, "se acontecer
  tal coisa, saia" ou "pule" (BACKES, 2013, cap. 5).
- **`while (1)`** (ou `for (;;)`): condição sempre verdadeira, com um `break`
  no meio do corpo. Serve quando o motivo de parar só aparece **depois** de
  ler o dado (KERNIGHAN; RITCHIE, 1988, cap. 3).
- **Por que parou?** Depois de um laço com `break`, às vezes é preciso saber
  se saiu pela condição ou pelo `break`. O A046 testa um primo assim.
- **Só o mais interno**: `break` e `continue` valem para o laço mais próximo.
  O C não tem `break` com rótulo; existe o `goto`, que deve ser evitado
  (BACKES, 2013, cap. 5).

> [!WARNING]
> `continue` num `while` pode pular o passo. Em
> `while (i < 10) { if (i == 5) continue; printf("%d", i); i++; }`, o `i`
> fica 5 para sempre. No `for`, o mesmo código funciona, porque o `i++` está
> no cabeçalho.

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
