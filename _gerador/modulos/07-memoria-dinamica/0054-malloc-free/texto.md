## 0054 · malloc e free

- **`malloc`** (*memory allocation*, de `<stdlib.h>`): recebe **quantos bytes**
  você quer e devolve o endereço de um bloco no heap. O ponteiro que recebe age
  como vetor (BACKES, 2013, cap. 11).

```c
double *corridas = malloc(n * sizeof(double)); // n * 8 bytes
```

- **Conta em bytes**: `malloc(4)` dá 4 bytes, não 4 `double`. Por isso
  `n * sizeof(tipo)` (CELES; RANGEL, 2002).
- **`void *`**: o retorno vira `double *` sozinho; em C o cast é dispensável
  (BACKES, 2013, cap. 11).
- **`NULL`**: é o que volta quando falta memória. Confira sempre antes de usar
  (FEOFILOFF, 2009, ap. F).
- **Lixo**: o `malloc` não zera o bloco. Preencha antes de ler
  (BACKES, 2013, cap. 11).
- **`free(p)`**: devolve o bloco, com exatamente o endereço que o `malloc` deu.
  O tamanho fica num cabeçalho escondido, por isso `free(p + 1)` dá errado
  (KERNIGHAN; RITCHIE, 1989, seção 8.7).
- **Depois do `free`**, o ponteiro ainda guarda o endereço antigo. O hábito é
  `p = NULL;` (FEOFILOFF, 2009, ap. F).
- **Vazamento** (*memory leak*): bloco que ninguém libera. Todo `malloc` tem um
  `free` (DEITEL; DEITEL, 2011, cap. 12).

> [!WARNING]
> O erro mais comum é contar elementos em vez de bytes: `malloc(n)` para `n`
> inteiros reserva um quarto do necessário. Tire o tipo do próprio ponteiro:
> `int *v = malloc(n * sizeof *v);`.

{{exemplo}}

O programa pergunta quantas corridas de aplicativo houve no mês (4), pede ao
heap `4 * 8 = 32` bytes, guarda os valores, soma e devolve o bloco:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quantas corridas? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade inválida\n");
        return 1;
    }

    // pede n * 8 bytes ao heap; o tamanho só é conhecido agora
    double *corridas = malloc(n * sizeof(double));
    if (corridas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Valor da corrida %d: ", i + 1);
        if (scanf("%lf", &corridas[i]) != 1) { // usa como um vetor comum
            printf("Valor inválido\n");
            free(corridas);
            return 1;
        }
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += corridas[i];
    }
    printf("Total: R$ %.2f\n", total);
    printf("Média: R$ %.2f\n", total / n);

    free(corridas);  // devolve os bytes ao heap
    corridas = NULL; // o ponteiro não aponta mais para lugar nenhum
    return 0;
}
// Exemplo de uso:
// Quantas corridas? 4
// Valor da corrida 1: 12.50
// Valor da corrida 2: 18
// Valor da corrida 3: 25.90
// Valor da corrida 4: 9.60
// Total: R$ 66.00
// Média: R$ 16.50
```

Toda saída depois do `malloc` passa por um `free`, até a de erro no meio da
leitura, a mais fácil de esquecer:

{{fluxograma}}
