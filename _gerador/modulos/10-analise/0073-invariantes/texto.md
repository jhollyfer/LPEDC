## 0073 · Invariantes de laço e corretude

Fim do expediente na lanchonete: troco inicial mais vendas tem que bater com
a gaveta. E a conta vale depois de **cada** cliente: "gaveta = troco + vendas
até agora". Se em algum momento não bater, o erro foi ali.

Um laço funciona igual. Testar alguns valores mostra que ele acertou
**naqueles** valores. Para ter certeza de que acerta sempre, procure uma frase
que fica verdadeira volta após volta: o **invariante de laço**, uma relação
entre as variáveis que vale **no começo de cada iteração**, antes do teste do
laço.

Para falar de pedaços de vetor, use `v[0..i-1]`: os elementos de índice 0 até
i − 1 (vazio quando i vale 0). O invariante de "achar o maior" fica: **`maior`
é um máximo de `v[0..i-1]`**. Diz o que o laço já sabe, não como ele anda.

Mostrar que um laço está certo tem quatro passos, como numa prova por
indução:

1. **Início**: o invariante vale antes da primeira volta.
2. **Manutenção**: se vale no começo de uma volta, vale no começo da seguinte.
3. **Término**: quando o teste falha, invariante + condição de parada dão o
   resultado desejado.
4. **Parada**: uma quantidade inteira diminui a cada volta e não pode diminuir
   para sempre (é a **variante**). Garante que o laço acaba.

Isso também melhora a documentação. A função promete "recebe n ≥ 1 e v;
devolve o valor de **um** elemento máximo de `v[0..n-1]`". Cobre todos os
parâmetros, diz a restrição (n ≥ 1) e usa "um" por causa do empate. É o
contrato, sem o "como".

Os Pix do dia foram 120, 45, 300, 80, 210 e 95. No começo da volta com i = 4,
a parte verde já foi vista e `maior` (300) é o maior dela. A parte cinza ainda
não importa:

{{ideia}}

O `assert` de `<assert.h>` transforma o invariante em código: se a condição
for falsa, o programa para e mostra a linha. A `eh_maximo` é lenta de
propósito: confere o invariante pelo caminho ingênuo, só para testar.

```c
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Devolve true se x é um máximo de v[0..i-1]: x está lá e ninguém passa dele.
bool eh_maximo(const int v[], int i, int x) {
    bool esta = false;
    for (int k = 0; k < i; k++) {
        if (v[k] > x) {
            return false;
        }
        if (v[k] == x) {
            esta = true;
        }
    }
    return esta;
}

// Recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].
int maximo(const int v[], int n) {
    int maior = v[0];
    int i = 1;
    while (i < n) {
        // invariante: maior é um máximo de v[0..i-1]
        assert(eh_maximo(v, i, maior));
        printf("i = %d: maior = %d\n", i, maior);
        if (v[i] > maior) {
            maior = v[i];
        }
        i++;
    }
    // na saída, i == n: o invariante diz que maior é um máximo de v[0..n-1]
    assert(eh_maximo(v, n, maior));
    return maior;
}

int main(void) {
    int pix[6] = {120, 45, 300, 80, 210, 95};

    printf("Maior Pix: R$ %d\n", maximo(pix, 6));
    return 0;
}
// Saída:
// i = 1: maior = 120
// i = 2: maior = 120
// i = 3: maior = 300
// i = 4: maior = 300
// i = 5: maior = 300
// Maior Pix: R$ 300
```

### Passo a passo

Os quatro passos neste laço, com o teste de mesa:

| começo da volta | i | `v[0..i-1]` | maior | invariante vale? |
| --- | --- | --- | --- | --- |
| 1ª | 1 | 120 | 120 | sim: um elemento só é o máximo dele mesmo (**início**) |
| 2ª | 2 | 120, 45 | 120 | sim: 45 não passou de 120 |
| 3ª | 3 | 120, 45, 300 | 300 | sim: 300 passou e virou o maior |
| 4ª | 4 | ..., 80 | 300 | sim |
| 5ª | 5 | ..., 210 | 300 | sim |
| teste falha | 6 | o vetor todo | 300 | sim, e i == n: é a resposta (**término**) |

**Manutenção**: se `maior` é o máximo de `v[0..i-1]`, a volta compara com
`v[i]` e fica com o maior dos dois: `maior` passa a ser o máximo de `v[0..i]`,
e o `i++` devolve a forma "máximo de `v[0..i-1]`". **Parada**: n − i diminui 1
por volta e o laço acaba em 0.

No fluxograma, o invariante fica na seta que volta ao losango "i < 6?". Toda
vez que o caminho passa ali, a frase é verdadeira:

{{fluxograma}}

> [!WARNING]
> O erro clássico é o **início**: `int maior = 0;` passa em todos os testes
> com valores positivos. Com saldos negativos (−120, −45, −300), devolve 0,
> que nem está no vetor. O invariante denuncia: antes da primeira volta, 0 não
> é um máximo de `v[0..0]`. Comece com `maior = v[0]` e i = 1, e escreva n ≥ 1
> no contrato.

> [!TIP]
> **Por dentro do C:** `assert(cond)` é uma macro: se `cond` for falsa, imprime
> arquivo, linha e condição e chama `abort()`. Com `-DNDEBUG`, vira **nada**,
> nem a condição é calculada. Por isso o `eh_maximo` (O(n) dentro de um laço
> O(n)) não custa nada na versão final. Nunca ponha dentro do `assert` algo
> que o programa precisa fazer, como `assert(fp = fopen(...))`.

> [!NOTE]
> **Pergunta para você:** no exemplo A146 (fichas de R$ 5 com R$ 47), o
> invariante é `valor == q * ficha + r` e `r >= 0`. O que garante que o laço
> termina? E se a ficha custasse R$ 0, qual dos quatro passos falharia?

{{pratique}}
