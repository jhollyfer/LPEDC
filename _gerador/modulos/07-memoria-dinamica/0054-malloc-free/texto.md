## 0054 · malloc e free

Fim do mês, hora de somar as corridas de aplicativo. Teve mês com 4 corridas,
teve mês com 60. Se você declarar `double corridas[100];`, desperdiça espaço
nos meses fracos e estoura no mês em que passar de 100. O tamanho certo só
aparece quando o programa já está rodando.

Para isso existe o `malloc` (*memory allocation*), de `<stdlib.h>`. Você diz
**quantos bytes** quer e ele devolve o **endereço** de um bloco desse tamanho
no heap. Esse endereço vai para um ponteiro, que age como vetor:
`corridas[i]` funciona igual (assunto 0047).

```c
double *corridas = malloc(n * sizeof(double)); // n * 8 bytes
```

Três detalhes nessa linha:

- o `malloc` conta em **bytes**, não em elementos. `malloc(4)` dá 4 bytes, não
  4 `double`. Daí o `n * sizeof(tipo)`;
- ele devolve `void *` (assunto 0051), que vira `double *` sozinho. Em C o
  cast `(double *)` é dispensável;
- se não houver memória, devolve **`NULL`**. Sempre confira antes de usar.

O bloco vem com **lixo**: o `malloc` não zera nada. Preencha antes de ler.

Para devolver, use **`free(corridas)`**, com exatamente o endereço que o
`malloc` deu. O `free` não precisa do tamanho: o `malloc` o anotou num
cabeçalho escondido antes do bloco (por isso `free(p + 1)` dá errado). Depois
do `free`, o ponteiro guarda o endereço antigo, que não é mais seu. Por isso o
hábito: `corridas = NULL;`.

A regra: **todo `malloc` tem um `free`**. O bloco esquecido fica ocupado até o
programa acabar: é um **vazamento** (*memory leak*), tema do assunto 0057.

O programa pergunta quantas corridas foram (4), pede ao heap `4 * 8 = 32`
bytes, guarda os valores (R$ 12,50, R$ 18,00, R$ 25,90 e R$ 9,60), soma tudo e
devolve o bloco:

{{ideia}}

O comentário no fim do código mostra uma execução completa:

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

> [!WARNING]
> O erro mais comum é contar elementos em vez de bytes: `malloc(n)` para `n`
> inteiros reserva um quarto do necessário. Tire o tipo do próprio ponteiro:
> `int *v = malloc(n * sizeof *v);`. Se `v` virar `double *`, a conta
> acompanha.

> [!NOTE]
> **Pergunta para você:** se você tirar a linha `free(corridas);` o programa
> continua mostrando o total certo? Então qual é o problema? Rode sem o `free`
> e leia o fim da saída do gcc com as flags de estudo.

{{pratique}}
