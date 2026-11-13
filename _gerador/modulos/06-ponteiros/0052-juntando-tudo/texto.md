## 0052 · Juntando tudo: o ranking da feira

- **Vetores paralelos**: nome, quantidade e preço de cada barraca na mesma
  posição, e o faturamento `fat[i] = qtd[i] * preco[i]` (DEITEL; DEITEL, 2011,
  cap. 7).
- **Vetor de ponteiros como índice**: `const double *ordem[N]` aponta para os
  elementos de `fat`. Ordena-se `ordem`, não `fat`, como o índice de um livro
  (assunto 0049) (CELES; RANGEL, 2002).
- **`qsort` com ponteiros**: cada elemento de `ordem` é um `const double *`, e
  o `qsort` entrega o endereço dele como `const void *`; dois saltos (`**`)
  levam ao faturamento (KERRISK, s.d.).
- **Subtração de ponteiros**: `ordem[i] - fat` dá o índice em `fat`, o mesmo
  do nome em `produtos` (assunto 0047) (KERNIGHAN; RITCHIE, 1989, cap. 5).
- **Dois resultados por referência**: `resumo` devolve o total num `double *`
  e **onde** está o maior num `const double **` (assunto 0046) (DEITEL;
  DEITEL, 2011, cap. 7).
- **Ler `const` da direita para a esquerda**: `const double * const *` é
  ponteiro para ponteiro constante para `double` constante (DEITEL; DEITEL,
  2011, cap. 7).

> [!WARNING]
> `sizeof(double)` no `qsort` de `ordem` está errado: os elementos são
> **ponteiros**. Aqui os dois têm 8 bytes e o erro se esconde; com `int *` não.
> Escreva sempre `sizeof ordem[0]`.

{{exemplo}}

Fim de feira, 4 barracas: tomate (30 × R$ 6,50), alface (45 × R$ 3,00), queijo
(8 × R$ 32,00) e pastel (60 × R$ 9,00). Depois do `qsort`, `ordem[0]` aponta
para o pastel e `ordem[3]` para a alface, e `fat` segue igual:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

#define N 4

// devolve dois resultados: o total (double *) e ONDE está o maior (const double **)
void resumo(const double *v, int n, double *total, const double **maior) {
    *total = 0;
    *maior = v;
    for (const double *p = v; p < v + n; p++) {
        *total += *p;
        if (*p > **maior) {
            *maior = p;
        }
    }
}

// cada elemento de ordem é um const double *; o qsort entrega o ENDEREÇO dele
int maior_primeiro(const void *a, const void *b) {
    double x = **(const double * const *)a;
    double y = **(const double * const *)b;
    return (x < y) - (x > y); // decrescente
}

int main(void) {
    const char *produtos[N] = {"tomate", "alface", "queijo", "pastel"};
    int qtd[N] = {30, 45, 8, 60};
    double preco[N] = {6.50, 3.00, 32.00, 9.00};
    double fat[N];               // faturamento de cada barraca
    const double *ordem[N];      // ponteiros para fat: é isso que vamos ordenar

    for (int i = 0; i < N; i++) {
        fat[i] = qtd[i] * preco[i];
        ordem[i] = &fat[i];
    }
    qsort(ordem, N, sizeof ordem[0], maior_primeiro); // fat continua intacto

    for (int i = 0; i < N; i++) {
        int k = (int)(ordem[i] - fat); // ponteiro - início = índice do produto
        printf("%dº %-7s R$ %7.2f\n", i + 1, produtos[k], *ordem[i]);
    }

    double total;
    const double *maior;
    resumo(fat, N, &total, &maior);
    printf("Total: R$ %.2f  Campeão: %s\n", total, produtos[maior - fat]);
    return 0;
}
// Saída:
// 1º pastel  R$  540.00
// 2º queijo  R$  256.00
// 3º tomate  R$  195.00
// 4º alface  R$  135.00
// Total: R$ 1126.00  Campeão: pastel
```

Três fases: calcula e aponta, ordena os ponteiros e percorre a ordem nova,
traduzindo cada ponteiro em índice:

{{fluxograma}}
