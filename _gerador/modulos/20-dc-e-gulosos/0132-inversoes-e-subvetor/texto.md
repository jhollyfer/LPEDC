## 0132 · Inversões e subvetor de soma máxima

Você e o Caio montaram o top 8 de séries do ano. Os gostos batem? Se você
põe "Sintonia" antes de "Cidade Invisível" e o Caio faz o contrário, esse
par de séries está em desacordo. Medir o quanto dois rankings discordam
serve para recomendação de filmes, comparação de buscadores e votação.

Para transformar a pergunta em conta, escreva as suas séries em ordem e,
embaixo de cada uma, a posição que ela tem no ranking do Caio. Se ele
concordasse com tudo, o vetor sairia `1 2 3 4 5 6 7 8`. Cada par fora de
ordem nesse vetor é uma **inversão**: um par de posições `i < j` com
`v[i] > v[j]` (CORMEN et al., 2024). O vetor ordenado tem zero inversões. O
vetor ao contrário tem todas: cada um dos `n(n - 1)/2` pares está invertido.

O jeito direto é testar todos os pares com dois laços, o que custa O(n²).
A divisão e conquista (0131) faz melhor. Divida o vetor ao meio. Toda
inversão cai num de três tipos: os dois elementos estão inteiros na metade
esquerda, os dois estão inteiros na metade direita, ou um está em cada
metade e a inversão **cruza** o meio. A recursão conta os dois primeiros
tipos sozinha, porque cada metade é o mesmo problema com metade do tamanho
(KLEINBERG; TARDOS, 2006, cap. 5).

Falta contar as que cruzam, e aqui entra o truque. Se as duas metades já
estiverem **ordenadas**, a intercalação do merge sort (0094) conta de
graça. Na intercalação, `i` anda pela esquerda (que termina antes de `q`) e
`j` anda pela direita. Quando o menor da vez vem da direita, `v[j]` é menor
que `v[i]` e, como a esquerda está ordenada, menor também que todos os que
vêm depois dele. São `q - i` inversões de uma vez (KLEINBERG; TARDOS, 2006,
cap. 5). Intercalando `1 3 5 7` com `2 4 6 8`, o 2 sai antes de 3, 5 e 7 e
soma 3; o 4 sai antes de 5 e 7 e soma 2; o 6 sai antes do 7 e soma 1.

Para isso funcionar, a função precisa devolver a contagem **e** deixar o
pedaço ordenado, pronto para a intercalação do nível de cima. Ela é o merge
sort com um contador, e o custo é o mesmo: **O(n log n)**, contra O(n²) de
testar todos os pares (KLEINBERG; TARDOS, 2006, cap. 5). Um efeito colateral:
contar ordena o vetor. Se precisar da ordem original, conte numa cópia.

O número de inversões cresce rápido. Um vetor de 100 000 elementos ao
contrário tem 4 999 950 000 inversões, mais do que um `int` de 32 bits
guarda. O contador tem de ser `long long` (KERNIGHAN; RITCHIE, 1989).

A mesma divisão em três casos resolve outro problema clássico, o
**subvetor de soma máxima**: a faixa de posições **seguidas** cuja soma é a
maior possível. Um food truck anotou o lucro de 8 dias, `4 -6 3 5 -2 6 -9 2`,
e quer saber qual sequência de dias rendeu mais. Divida ao meio. A melhor
faixa está inteira na esquerda (`3 5`, soma 8), inteira na direita (`6`,
soma 6) ou cruzando o meio. A que cruza é o melhor final da esquerda (`3 5`,
8) somado ao melhor começo da direita (`-2 6`, 4): `3 5 -2 6`, soma 12. A
resposta é o maior dos três, 12. Achar a que cruza é um laço do meio para
fora, O(n), e o total fica O(n log n) (CORMEN et al., 2012, seção 4.1).

> [!WARNING]
> A soma é `inv += q - i`, e não `inv++`: o `v[j]` que sai está fora de ordem
> com **todos** de `v[i]` a `v[q - 1]`. E o `<=` importa: valores iguais
> **não** são inversão.

{{exemplo}}

Você e o Caio montaram o top 8 de séries. Embaixo de cada série sua vai a
posição dela no ranking do Caio. São 3 inversões na esquerda, 4 na direita e 6
na intercalação:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

// junta v[p..q-1] e v[q..r-1], já ordenados, e devolve quantas inversões
// cruzam as duas metades
long long intercala(int v[], int w[], int p, int q, int r) {
    long long inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;       // v[j] é menor que TODOS os que sobram à esquerda
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

// ordena v[p..r-1] e devolve o número de inversões que havia nele
long long conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;                       // 0 ou 1 elemento: nenhuma inversão
    }
    int q = p + (r - p) / 2;
    long long esq = conta(v, w, p, q);  // inversões dentro da esquerda
    long long dir = conta(v, w, q, r);  // inversões dentro da direita
    long long cruz = intercala(v, w, p, q, r); // um de cada lado
    printf("[%d, %d): %lld + %lld + %lld\n", p, r, esq, dir, cruz);
    return esq + dir + cruz;
}

int main(void) {
    // posição, no ranking do Caio, de cada série do seu top 8
    int caio[] = {3, 7, 1, 5, 8, 2, 6, 4};
    int n = 8;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    long long total = conta(caio, w, 0, n);
    printf("Pares em desacordo: %lld de %d\n", total, n * (n - 1) / 2);
    free(w);
    return 0;
}
// Saída:
// [0, 2): 0 + 0 + 0
// [2, 4): 0 + 0 + 0
// [0, 4): 0 + 0 + 3
// [4, 6): 0 + 0 + 1
// [6, 8): 0 + 0 + 1
// [4, 8): 1 + 1 + 2
// [0, 8): 3 + 4 + 6
// Pares em desacordo: 13 de 28
```

Contar também **ordena**; para manter a ordem original, conte numa cópia. As
duas chamadas recursivas contam dentro de cada metade e a intercalação conta o
que cruza:

{{fluxograma}}

### Passo a passo

Última intercalação: `1 3 5 7` com `2 4 6 8`. Quando o menor vem da direita,
soma os que sobram na esquerda:

| sai | de onde | sobram na esquerda | soma |
| --- | --- | --- | --- |
| 1 | esquerda | | 0 |
| 2 | direita | 3, 5, 7 | 3 |
| 3 | esquerda | | 3 |
| 4 | direita | 5, 7 | 5 |
| 5 | esquerda | | 5 |
| 6 | direita | 7 | 6 |
| 7 | esquerda | | 6 |
| 8 | direita | (nenhum) | 6 |

No subvetor de soma máxima, com o lucro de 8 dias `4 -6 3 5 -2 6 -9 2`: a
esquerda dá `3 5` (8), a direita `6` (6) e o que cruza, `3 5 -2 6`, dá **12**,
do dia 2 ao 5. O A263 traz o algoritmo em C e o A264, um jeito em O(n).
