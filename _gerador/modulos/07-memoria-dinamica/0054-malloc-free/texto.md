## 0054 · malloc e free

Fim do mês, hora de somar as corridas de aplicativo. Teve mês com 4 corridas
e teve mês com 60. Se você declarar `double corridas[100];`, desperdiça
espaço nos meses fracos e estoura no mês em que passar de 100. O tamanho
certo só aparece quando o programa já está rodando e pergunta quantas
corridas foram. Falta um jeito de pedir memória nessa hora, do tamanho exato.

Quem atende o pedido é o **`malloc`** (*memory allocation*, alocação de
memória), da biblioteca `<stdlib.h>`. Você diz **quantos bytes** quer, e ele
separa um bloco desse tamanho no heap (assunto 0053) e devolve o
**endereço** do começo. Esse endereço vai para um ponteiro, e o ponteiro age
como vetor: `corridas[i]` funciona como em qualquer vetor, pela regra
`v[i] == *(v + i)` do assunto 0047 (BACKES, 2013, cap. 11).

```c
double *corridas = malloc(n * sizeof(double)); // n * 8 bytes
```

Leia a linha devagar, porque cada parte tem um motivo. O `malloc` conta em
**bytes**, não em elementos: `malloc(4)` dá 4 bytes, e não 4 `double`. Por
isso o pedido é `n * sizeof(double)`, o número de itens vezes o tamanho de
cada um; com `n` igual a 4, são 32 bytes (CELES; RANGEL, 2002).

O retorno do `malloc` é um `void *` (assunto 0051), porque ele não sabe o
que você vai guardar. Em C, esse `void *` vira `double *` sozinho na
atribuição, então o cast `(double *)` na frente do `malloc` é dispensável
(BACKES, 2013, cap. 11).

O pedido pode falhar. Se não houver memória livre suficiente, o `malloc`
devolve **`NULL`** em vez de um endereço. Confira sempre, com `if (corridas
== NULL)`, antes de usar o bloco; escrever num `NULL` derruba o programa
(FEOFILOFF, 2009, ap. F).

O bloco também não vem limpo. O `malloc` não zera nada, e os bytes guardam o
**lixo** que estava ali antes. Preencha cada posição antes de ler (BACKES,
2013, cap. 11). O assunto 0055 mostra o `calloc`, que entrega o bloco
zerado.

Quando não precisar mais do bloco, devolva-o com **`free(corridas)`**,
passando exatamente o endereço que o `malloc` deu. O `free` não pergunta o
tamanho porque o `malloc` anotou esse número num cabeçalho escondido, logo
antes do bloco. É por isso que `free(p + 1)` dá errado: o `free` procuraria o
cabeçalho no lugar errado (KERNIGHAN; RITCHIE, 1989, seção 8.7).

Depois do `free`, o ponteiro continua guardando o endereço antigo, que já
não é seu. Ele aponta para um lugar devolvido, e usá-lo é um erro. O hábito
que evita isso é anular o ponteiro logo em seguida: `corridas = NULL;`
(FEOFILOFF, 2009, ap. F).

A regra que resume tudo: **todo `malloc` tem um `free`**. O bloco esquecido
fica ocupado até o programa acabar, e se o pedido se repete num laço a
memória vai sumindo aos poucos. Esse erro se chama **vazamento de memória**
(*memory leak*) (DEITEL; DEITEL, 2011, cap. 12), e o assunto 0057 mostra como
encontrá-lo.

> [!WARNING]
> O erro mais comum é contar elementos em vez de bytes: `malloc(n)` para `n`
> inteiros reserva um quarto do necessário. Tire o tipo do próprio ponteiro:
> `int *v = malloc(n * sizeof *v);`. Se `v` virar `double *`, a conta
> acompanha.

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
