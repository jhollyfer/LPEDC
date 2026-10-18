## 0057 · Juntando tudo: o ranking da feira

Sábado, fim de feira. A associação dos feirantes quer o ranking das
barracas pelo faturamento do dia e o nome da campeã. Mas tem uma condição:
a planilha original não pode mudar de ordem, porque outras contas usam a
posição de cada barraca.

O problema junta tudo o que o módulo ensinou:

- **vetores paralelos** com o nome, a quantidade e o preço de cada barraca,
  e o faturamento calculado (`fat[i] = qtd[i] * preco[i]`);
- um **vetor de ponteiros** `const double *ordem[N]`, em que cada posição
  aponta para um elemento de `fat` (assunto 0054). É ele que vai ser
  ordenado, não `fat`. Como num índice de livro: as páginas não mudam de
  lugar, só a lista que aponta para elas;
- o **`qsort`** com uma função de comparação (assunto 0055). Cada elemento
  de `ordem` é um `const double *`, então o `qsort` entrega o endereço de um
  ponteiro, que chega como `const void *` (assunto 0056). Dois saltos
  depois, `**`, chega-se ao faturamento;
- **subtração de ponteiros** (assunto 0052): `ordem[i] - fat` diz em que
  posição de `fat` aquele ponteiro aponta, e a mesma posição dá o nome em
  `produtos`;
- **passagem por referência** (assunto 0051): a função `resumo` devolve
  duas respostas, o total (num `double *`) e **onde** está o maior (num
  `const double **`, porque ela precisa mudar um ponteiro do `main`).

Vamos ver na prática. São 4 barracas: tomate (30 × R$ 6,50), alface (45 ×
R$ 3,00), queijo (8 × R$ 32,00) e pastel (60 × R$ 9,00). Depois do `qsort`,
`ordem[0]` aponta para o pastel e `ordem[3]` para a alface, enquanto `fat`
continua na ordem de sempre:

{{ideia}}

O programa completo:

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

O `const double * const *` da comparação se lê da direita para a esquerda:
ponteiro para um ponteiro constante para um `double` constante. Os dois
`const` só prometem que a comparação não muda nada, nem o ponteiro do
vetor, nem o faturamento.

Repara no fluxograma: três fases. Calcula e aponta, ordena os ponteiros,
percorre a ordem nova traduzindo cada ponteiro para um índice:

{{fluxograma}}

> [!WARNING]
> Ordenar `ordem` com `sizeof(double)` no terceiro argumento do `qsort`
> parece certo e está errado: os elementos de `ordem` são **ponteiros**
> (8 bytes), não `double`. Aqui os dois têm 8 bytes e o erro fica
> escondido, mas com `int *ordem[]` e `sizeof(int)` o `qsort` embaralharia
> meio ponteiro com meio ponteiro. Escreva sempre `sizeof ordem[0]`: o
> tamanho do elemento do próprio vetor que você está ordenando.

> [!TIP]
> **Por dentro do C:** ordenar ponteiros em vez dos dados é um truque
> clássico. Cada troca do `qsort` move 8 bytes, não importa o tamanho do
> dado apontado. Com structs de 200 bytes (módulo 08), a diferença é
> enorme. E várias "visões" ordenadas podem conviver: um vetor de ponteiros
> por faturamento, outro por nome, todos apontando para os mesmos dados. É
> a ideia por trás dos índices de um banco de dados.

> [!NOTE]
> **Pergunta para você:** se você trocar `maior_primeiro` por uma função que
> ordena pelo **nome** do produto, o que muda no programa? A comparação
> ainda recebe endereços de `const double *`; como ela chegaria ao nome?

{{pratique}}
