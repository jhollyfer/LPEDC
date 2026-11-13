## 0073 · Invariantes de laço e corretude

- **Invariante de laço**: relação entre as variáveis que vale **no começo de
  cada iteração**, logo antes do teste. Serve para explicar e para provar o
  laço (FEOFILOFF, 2009).
- **Notação `v[0..i-1]`**: os elementos de índice 0 até i − 1, vazio quando i
  vale 0. Em "achar o maior": **`maior` é um máximo de `v[0..i-1]`**
  (FEOFILOFF, 2009).
- **Quatro passos**, como numa indução (CORMEN et al., 2024, cap. 2):
  1. **Início**: vale antes da primeira volta.
  2. **Manutenção**: se vale no começo de uma volta, vale no começo da seguinte.
  3. **Término**: quando o teste falha, invariante + condição de parada dão o
     resultado.
  4. **Parada**: uma quantidade inteira, a **variante**, diminui a cada volta.
- **Contrato**: a documentação diz o que a função faz, não como. "Recebe n ≥ 1
  e v; devolve o valor de **um** elemento máximo de `v[0..n-1]`"
  (FEOFILOFF, 2009).
- **`assert(cond)`** (`<assert.h>`): se `cond` for falsa, mostra arquivo e linha
  e aborta. Com `-DNDEBUG`, vira nada (CPPREFERENCE, s.d.).

> [!WARNING]
> O erro clássico é o **início**: `int maior = 0;` passa nos testes com valores
> positivos, mas com −120, −45, −300 devolve 0, que nem está no vetor. Comece
> com `maior = v[0]` e i = 1. E nunca ponha no `assert` algo que o programa
> precisa fazer.

{{exemplo}}

Os Pix do dia foram 120, 45, 300, 80, 210 e 95. No começo da volta com i = 4, a
parte verde já foi vista e `maior` (300) é o maior dela:

{{ideia}}

O `assert` transforma o invariante em código. A `eh_maximo` é lenta de
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
