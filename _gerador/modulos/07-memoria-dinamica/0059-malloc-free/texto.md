## 0059 · malloc e free

Fim do mês, hora de somar as corridas de aplicativo. Teve mês com 4 corridas,
teve mês com 60. Se você declarar `double corridas[100];`, desperdiça espaço
nos meses fracos e estoura no mês em que passar de 100. O tamanho certo só
aparece quando o programa já está rodando.

Para isso existe o `malloc` (*memory allocation*), de `<stdlib.h>`. Você diz
**quantos bytes** quer e ele devolve o **endereço** de um bloco desse tamanho
no heap. Esse endereço vai para um ponteiro, e o ponteiro passa a se comportar
como um vetor: `corridas[i]` funciona igualzinho (assunto 0052).

```c
double *corridas = malloc(n * sizeof(double)); // n * 8 bytes
```

Três detalhes nessa linha:

- o `malloc` conta em **bytes**, não em elementos. `malloc(4)` não é espaço
  para 4 `double`, é espaço para 4 bytes. Por isso sempre `n * sizeof(tipo)`;
- ele devolve `void *` (assunto 0056), que vira `double *` sozinho. Em C não
  precisa de cast; o `(double *)` que você vê em livro antigo é dispensável;
- se não houver memória, ele devolve **`NULL`**. Sempre confira antes de usar.

O bloco vem com **lixo**: o que estava naqueles bytes antes. O `malloc` não
zera nada. Preencha antes de ler.

Quando terminar, devolva com **`free(corridas)`**. O `free` recebe exatamente
o endereço que o `malloc` deu, nem um byte a mais. Ele não precisa do tamanho:
o próprio `malloc` anotou isso num cabeçalho escondido antes do bloco. Depois
do `free`, o ponteiro continua guardando o endereço antigo, só que agora ele
aponta para um bloco que não é mais seu. Por isso o hábito: `corridas = NULL;`.

A regra de ouro é simples de dizer: **todo `malloc` tem um `free`**. Nada some
sozinho: o bloco que você esquece de liberar fica ocupado até o programa acabar. Isso é
um **vazamento** (*memory leak*), tema do assunto 0062.

Vamos ver na prática. O programa pergunta quantas corridas foram (4), pede ao
heap `4 * 8 = 32` bytes, guarda os valores (R$ 12,50, R$ 18,00, R$ 25,90 e
R$ 9,60), soma tudo e devolve o bloco:

{{ideia}}

O código completo. Para testar sem digitar, use o comando que está no fim do
arquivo:

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

Repara no fluxograma: toda saída do programa depois do `malloc` passa por um
`free`, até a saída de erro no meio da leitura. É fácil esquecer justamente
esse caminho:

{{fluxograma}}

> [!WARNING]
> O erro mais comum é contar elementos em vez de bytes: `malloc(n)` para `n`
> inteiros reserva só um quarto do necessário, e o programa escreve além do
> fim do bloco. Um jeito à prova de distração é tirar o tipo do próprio
> ponteiro: `int *v = malloc(n * sizeof *v);`. Se um dia `v` virar `double *`,
> a conta acompanha sozinha.

> [!TIP]
> **Por dentro do C:** o `malloc` pede memória ao sistema operacional em
> pedaços grandes (chamadas `brk` e `mmap`) e depois fatia esses pedaços para
> você. Cada bloco ganha um cabeçalho de uns 8 a 16 bytes, logo antes do
> endereço que você recebe, com o tamanho dele. É por isso que `free(p)` sabe
> quanto liberar, e é por isso que `free(p + 1)` é um desastre: ele vai ler um
> "cabeçalho" que não existe. Pedir 1 byte custa, na prática, uns 32: pedidos
> pequenos demais desperdiçam memória.

> [!NOTE]
> **Pergunta para você:** se você tirar a linha `free(corridas);` o programa
> continua mostrando o total certo? Então qual é o problema? Rode sem o `free`
> e leia o fim da saída do `rodar`.

{{pratique}}
