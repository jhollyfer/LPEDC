## 0052 · Juntando tudo: o ranking da feira

Sábado, fim de feira. A associação dos feirantes quer o ranking das barracas
pelo faturamento do dia e o nome da campeã, sem mudar a ordem da planilha
original, porque outras contas usam a posição de cada barraca.

O problema junta o módulo inteiro:

- **vetores paralelos** com nome, quantidade e preço de cada barraca, e o
  faturamento calculado (`fat[i] = qtd[i] * preco[i]`);
- um **vetor de ponteiros** `const double *ordem[N]`, cada posição apontando
  para um elemento de `fat` (assunto 0049). Ele é ordenado, `fat` não, como num
  índice de livro: as páginas não mudam, só a lista que aponta para elas;
- o **`qsort`** com função de comparação (assunto 0050). Cada elemento de
  `ordem` é um `const double *`, então o `qsort` entrega o endereço de um
  ponteiro, que chega como `const void *` (assunto 0051). Dois saltos, `**`,
  levam ao faturamento;
- **subtração de ponteiros** (assunto 0047): `ordem[i] - fat` dá a posição em
  `fat`, a mesma que dá o nome em `produtos`;
- **passagem por referência** (assunto 0046): `resumo` devolve duas respostas,
  o total (num `double *`) e **onde** está o maior (num `const double **`, pois
  ela muda um ponteiro do `main`).

São 4 barracas: tomate (30 × R$ 6,50), alface (45 × R$ 3,00), queijo (8 ×
R$ 32,00) e pastel (60 × R$ 9,00). Depois do `qsort`, `ordem[0]` aponta para o
pastel e `ordem[3]` para a alface, e `fat` segue na ordem de sempre:

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

O `const double * const *` da comparação lê-se da direita para a esquerda:
ponteiro para um ponteiro constante para um `double` constante. Os `const` só
prometem que a comparação não muda nada.

Três fases: calcula e aponta, ordena os ponteiros e percorre a ordem nova,
traduzindo cada ponteiro em índice:

{{fluxograma}}

> [!WARNING]
> Passar `sizeof(double)` ao `qsort` para ordenar `ordem` parece certo e está
> errado: os elementos de `ordem` são **ponteiros** (8 bytes). Aqui os dois têm
> 8 bytes e o erro fica escondido, mas com `int *ordem[]` e `sizeof(int)` o
> `qsort` embaralharia meio ponteiro com meio ponteiro. Escreva sempre
> `sizeof ordem[0]`.

> [!TIP]
> **Por dentro do C:** ordenar ponteiros em vez dos dados é técnica clássica:
> cada troca do `qsort` move 8 bytes, mesmo com structs de 200 bytes (módulo 08),
> e vários vetores de ponteiros (por faturamento, por nome) podem coexistir sobre
> os mesmos dados, a ideia dos índices de banco de dados.

> [!NOTE]
> **Pergunta para você:** se você trocar `maior_primeiro` por uma função que
> ordena pelo **nome** do produto, o que muda no programa? A comparação ainda
> recebe endereços de `const double *`; como ela chegaria ao nome?

{{pratique}}
