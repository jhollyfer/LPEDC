## 0116 · Análise amortizada

Uma família mora num apartamento de um quarto. Nasce o primeiro filho: muda
para um de dois quartos. Depois para um de quatro. Cada mudança é um dia
inteiro carregando **todos** os móveis, mas é rara: entre uma e outra, a
vida segue barata. Ninguém mede o custo de morar pela pior semana do ano.

O vetor que cresce do assunto 0075 vive a mesma coisa. Inserir no fim custa
uma escrita, até o dia em que o vetor enche: aí é preciso alocar um maior e
**copiar tudo**. Olhando uma operação isolada, o pior caso de uma inserção é
O(n). Multiplicando por `n` inserções, dá O(n²). A conta está certa, mas é
pessimista demais: as inserções caras não acontecem uma atrás da outra.

A **análise amortizada** mede o custo de uma **sequência** de operações, no
pior caso, e divide pelo número de operações. O resultado é o **custo
amortizado** por operação: uma garantia sobre o total, sem nenhum sorteio
envolvido.

O jeito mais direto é o **método agregado**: somar tudo. Com capacidade
inicial 1 e dobrando quando enche, `n` inserções fazem `n` escritas mais as
cópias das mudanças: `1 + 2 + 4 + ... + (a última potência de 2 menor que
n)`. Essa soma é sempre menor que `2n`. O total fica abaixo de `3n`: **O(1)
amortizado** por inserção.

O outro jeito é o **método do banqueiro** (ou contábil). Cada inserção paga
um preço fixo, digamos **3 moedas**: 1 paga a própria escrita e 2 vão para
um cofrinho. Quando o vetor de capacidade `c` enche e vira `2c`, metade dos
`c` elementos chegou depois da última mudança, e cada um guardou 2 moedas:
são `c` moedas, exatamente as `c` cópias. Se o cofrinho **nunca fica
negativo**, o preço fixo cobre o custo real, e o custo amortizado é 3.

Vamos ver na prática. O app do banco guarda o histórico de Pix num vetor que
começa com 1 posição e dobra quando enche. Chegam 16 Pix. As inserções 2, 3,
5 e 9 são as mudanças, em vermelho; o cofrinho embaixo cai nelas e se
recupera depois:

{{ideia}}

O `insere` devolve o custo real de cada inserção. O vetor cresce com
`malloc`, cópia e `free` feitos à mão, para dar para contar cada cópia:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n;   // quantos tem
    int cap; // quantos cabem
} Vetor;

// insere no fim e devolve o custo: 1 escrita + as cópias, se precisou crescer
int insere(Vetor *v, int valor) {
    int custo = 1;
    if (v->n == v->cap) {
        int nova = v->cap * 2;                       // dobra
        int *maior = malloc(nova * sizeof *maior);
        if (maior == NULL) {
            exit(1);
        }
        for (int i = 0; i < v->n; i++) {
            maior[i] = v->dados[i];                  // a mudança: copia tudo
            custo++;
        }
        free(v->dados);
        v->dados = maior;
        v->cap = nova;
    }
    v->dados[v->n++] = valor;
    return custo;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1};
    if (v.dados == NULL) {
        return 1;
    }
    int total = 0, cofrinho = 0;
    printf("Pix  custo  cofrinho\n");
    for (int i = 1; i <= 16; i++) {
        int custo = insere(&v, 100 * i);             // valor do Pix, tanto faz
        total += custo;
        cofrinho += 3 - custo;                       // cada inserção paga 3
        printf("%3d  %5d  %8d\n", i, custo, cofrinho);
    }
    printf("total: %d para 16 inserções (%.2f por inserção)\n", total, total / 16.0);
    free(v.dados);
    return 0;
}
// Saída:
// Pix  custo  cofrinho
//   1      1         2
//   2      2         3
//   3      3         3
//   4      1         5
//   5      5         3
//   6      1         5
//   7      1         7
//   8      1         9
//   9      9         3
//  10      1         5
//  11      1         7
//  12      1         9
//  13      1        11
//  14      1        13
//  15      1        15
//  16      1        17
// total: 31 para 16 inserções (1.94 por inserção)
```

As cópias somam `1 + 2 + 4 + 8 = 15`, mais 16 escritas: 31, menos de `2 · 16`.
O cofrinho desce até 3 em cada mudança e nunca chega a zero. As duas contas
dizem a mesma coisa: em média, menos de 2 por inserção, e nunca mais de 3.

Repara no fluxograma: é o `insere` da 9ª inserção, a mais cara das 16. O
vetor tem 8 de 8 ocupados, então o caminho passa pela mudança inteira:

{{fluxograma}}

O vetor que dobra não é o único caso. O assunto também aparece num
**contador binário** (somar 1 às vezes vira muitos bits, mas em média vira
menos de 2; exemplo A231) e numa **pilha com `multipop(k)`**, que tira até
`k` itens de uma vez (cada item só sai uma vez depois de entrar; exemplo
A232). Nos três, o argumento é o mesmo: a operação cara "gasta" um trabalho
que as baratas acumularam antes.

Duas confusões comuns. Amortizado **não** é caso médio: o caso médio supõe
entradas sorteadas, e o amortizado vale para a **pior** sequência possível.
E amortizado **não** garante que cada operação é rápida: a 1.048.577ª
inserção copia mais de um milhão de elementos de uma vez. Para quem conta o
total, tudo bem; para um sistema que não pode travar nem por um instante,
pode não estar.

> [!WARNING]
> Crescer de um **tamanho fixo** em vez de multiplicar estraga tudo. Com
> `nova = cap + 10`, as mudanças acontecem a cada 10 inserções e copiam 10,
> 20, 30... elementos: para 100.000 inserções, quase **500 milhões** de
> cópias, contra 131.071 dobrando. A soma `10 + 20 + ... ` é uma progressão
> aritmética, Θ(n²) no total: O(n) amortizado por inserção. Qualquer fator
> multiplicativo maior que 1 (1,5 ou 2) dá O(1) amortizado; somar uma
> constante, por maior que seja, não dá.

> [!TIP]
> **Por dentro do C:** na prática você usa `realloc` (assunto 0055), e às
> vezes ele nem copia: se o espaço logo depois do bloco estiver livre, ele
> só estica o bloco no lugar. Mas isso não é garantido, e a análise conta o
> pior caso: copiar tudo. O preço do O(1) amortizado é memória: logo depois
> de dobrar, metade do vetor está vazia. Com 1.048.577 inteiros, o vetor
> ocupa espaço para 2.097.152, 8 MB em vez de 4 MB. E lembre do `realloc`
> seguro: `int *novo = realloc(v, ...)` num ponteiro à parte, conferindo
> `NULL` antes de jogar fora o antigo.

> [!NOTE]
> **Pergunta para você:** e na volta? Suponha que o vetor também **encolhe
> pela metade** quando fica com metade das posições ocupadas. Com 16
> elementos e capacidade 16, o que acontece se o programa alternar "insere,
> remove, insere, remove..." mil vezes? Quantas cópias cada operação faz?

{{pratique}}
