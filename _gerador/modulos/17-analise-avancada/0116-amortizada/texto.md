## 0116 · Análise amortizada

Mudar de apartamento custa um dia inteiro carregando **todos** os móveis. Mas
mudança é rara, e ninguém mede o custo de morar num lugar pela pior semana do
ano. A análise deste assunto faz a mesma conta com operações de uma estrutura
de dados.

O caso clássico é o vetor que cresce, do assunto 0075. Inserir no fim custa
uma escrita, até o vetor encher. Cheio, é preciso alocar um vetor maior e
**copiar tudo** para ele. Olhando uma inserção isolada no pior caso, ela custa
O(n), e a conta pessimista diria que `n` inserções custam O(n²). Essa conta
erra porque as inserções caras não vêm em sequência: depois de uma cópia
grande, vêm muitas inserções baratas até o próximo aperto (ROVAI, 2018).

A **análise amortizada** olha para isso do jeito certo. Ela mede o custo de
uma **sequência** de operações no pior caso e divide pelo número de operações.
O resultado é o **custo amortizado** de cada operação, e ele é uma garantia
sobre o total: nenhuma sorte entra na conta (CORMEN et al., 2024, cap. 16). O
Cormen ensina três maneiras de fazer essa conta, e as três chegam ao mesmo
número para o vetor que dobra.

O **método agregado** soma tudo de uma vez. Comece com capacidade 1 e dobre
sempre que encher. As `n` inserções fazem `n` escritas. As cópias acontecem
quando a capacidade passa de 1 para 2, de 2 para 4, de 4 para 8, e copiam
`1 + 2 + 4 + ...` elementos. Essa soma de potências de 2 fica abaixo de `2n`,
porque cada termo é maior que todos os anteriores juntos. O total é menor que
`3n`, e dividindo por `n` cada inserção custa **O(1) amortizado** (CORMEN et
al., 2024, cap. 16).

O **método do banqueiro**, também chamado de contábil, troca a soma por um
cofrinho. Cada inserção paga **3 moedas**: 1 pela própria escrita e 2 que vão
para o cofrinho. Quando a capacidade `c` enche e vira `2c`, os `c/2` elementos
que entraram depois da última cópia guardaram 2 moedas cada, `c` moedas no
total, e isso paga exatamente as `c` cópias. Se o cofrinho nunca fica
negativo, nenhuma operação deixou de ser paga, e o custo amortizado é 3
(SZWARCFITER; MARKENZON, 2010).

O **método do potencial** formaliza o cofrinho. Em vez de contar moedas, você
define uma função Φ do estado da estrutura, o **potencial**, que mede a
"energia guardada". Para o vetor, Φ = 2 · n - capacidade, com `n` os elementos
guardados. O custo amortizado de uma operação é o custo real mais a variação
do potencial: real + Φ(depois) - Φ(antes). Uma inserção barata aumenta Φ em 2;
uma cópia grande gasta o potencial acumulado (CORMEN et al., 2024, cap. 16).

Dois mal-entendidos rondam esse assunto. O primeiro é confundir amortizado com
**caso médio**. O caso médio supõe que as entradas são sorteadas e calcula uma
média sobre elas. O amortizado não sorteia nada: vale para a **pior**
sequência possível. O segundo é achar que o amortizado promete que cada
operação é rápida. Ele promete o total. Um sistema que não pode travar nem
por um instante, como o controle de um freio, precisa de outra solução
(SZWARCFITER; MARKENZON, 2010).

A técnica serve para outras estruturas. Num **contador binário** que soma 1 a
cada passo, uma soma pode trocar muitos bits (de 0111 para 1000 trocam 4), mas
em média cada soma troca menos de 2 bits (exemplo A231). Numa pilha com a
operação `multipop(k)`, que tira `k` itens de uma vez, um `multipop` pode ser
caro, mas cada item só sai uma vez depois de ter entrado uma vez (exemplo
A232) (CORMEN et al., 2024, cap. 16).

No C, o vetor que cresce usa `realloc` (assunto 0055), que às vezes consegue
esticar o bloco no lugar e nem copia. A análise conta o pior caso, copiar
tudo. O preço que sobra é memória: logo depois de dobrar, metade do vetor está
vazia (CORTÉS, 2015). Use o `realloc` seguro, guardando o resultado num
ponteiro à parte e conferindo `NULL` antes de trocar.

> [!WARNING]
> Crescer por **tamanho fixo** estraga tudo. Com `nova = cap + 10`, as cópias
> são 10, 20, 30...: quase **500 milhões** para 100.000 inserções, contra
> 131.071 dobrando. Qualquer fator maior que 1 (1,5 ou 2) dá O(1) amortizado;
> somar uma constante, não.

{{exemplo}}

O app do banco guarda o histórico de Pix num vetor de 1 posição que dobra ao
encher. Chegam 16 Pix; as inserções 2, 3, 5 e 9 são as mudanças, em vermelho,
e o cofrinho cai nelas e se recupera:

{{ideia}}

O `insere` devolve o custo real. O vetor cresce com `malloc`, cópia e `free`
à mão, para contar cada cópia:

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
O fluxograma segue a 9ª inserção, a mais cara: 8 de 8 ocupados, e o caminho
passa pela mudança inteira:

{{fluxograma}}
