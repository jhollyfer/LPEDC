## 0092 · Selection sort

Final da bateria de kart: os tempos da melhor volta, em segundos, foram 58, 31,
47, 19 e 26. Para montar o pódio, você procura o **menor** tempo, que é o
primeiro lugar.
Depois procura o menor entre os que **sobraram**, e assim por diante.

Esse é o **selection sort** (ordenação por seleção). O vetor tem uma parte
**pronta** à esquerda (os menores, na ordem final) e o resto à direita. Cada
passada `i`:

1. procura o **índice** do menor elemento em `v[i..n-1]`;
2. troca esse menor com `v[i]`. A gaveta `i` nunca mais muda.

Guarda-se o **índice**, não o valor, para poder trocar no fim (padrão
"maior/menor" do assunto 0025).

São `n(n - 1)/2` comparações em **todos** os casos, porque achar o menor exige
olhar todos os que sobraram: **O(n²)**, mesmo com o vetor em ordem. A
vantagem são as **trocas**: no máximo **uma por passada**, `n - 1` no total,
contra até `n(n - 1)/2` do bubble. Pesa quando mover um elemento é caro.

Cada linha é uma passada: a gaveta roxa é a posição `i`, a amarela é o menor
achado. Depois da troca, a gaveta vira verde e fica:

{{ideia}}

Em C:

```c
#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void selection_sort(int v[], int n) {
    int comparacoes = 0, trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;                    // índice do menor de v[i..n-1]
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {                 // uma troca só por passada
            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            trocas++;
        }
        printf("i = %d:  ", i);
        mostra(v, n);
    }
    printf("%d comparações, %d trocas\n", comparacoes, trocas);
}

int main(void) {
    int tempos[] = {58, 31, 47, 19, 26}; // segundos por volta
    int n = 5;

    printf("início: ");
    mostra(tempos, n);
    selection_sort(tempos, n);
    return 0;
}
// Saída:
// início:  58 31 47 19 26
// i = 0:   19 31 47 58 26
// i = 1:   19 26 47 58 31
// i = 2:   19 26 31 58 47
// i = 3:   19 26 31 47 58
// 10 comparações, 4 trocas
```

### Passo a passo

A passada `i = 0`. O `menor` começa na gaveta 0:

| j | v[j] | v[menor] antes | `v[j] < v[menor]`? | menor |
| --- | --- | --- | --- | --- |
| | | | | 0 (58) |
| 1 | 31 | 58 | sim | 1 (31) |
| 2 | 47 | 31 | não | 1 |
| 3 | 19 | 31 | sim | 3 (19) |
| 4 | 26 | 19 | não | 3 |

Fim da passada: troca `v[0]` (58) com `v[3]` (19), depois de quatro comparações.
As passadas seguintes fazem 3, 2 e 1 comparações: 10 no total.

No fluxograma, a caixa "acha o menor" esconde um laço inteiro (a tabela). A
troca fica **fora** dele:

{{fluxograma}}

> [!WARNING]
> Trocar **dentro** do laço que procura o menor ordena o vetor, mas perde a
> vantagem das poucas trocas. Esquecer de reiniciar `menor = i` a cada passada
> faz `menor` apontar para a parte pronta.

> [!TIP]
> A troca é de **longa distância** (o 19 salta da gaveta 3 para a 0), por isso
> o selection é **instável**: iguais podem trocar de ordem (exemplo A184). Ele
> ordena **in-place**, com **O(1)** de memória extra.

> [!NOTE]
> **Pergunta para você:** quantas comparações e quantas trocas o selection faz
> no vetor `19 26 31 47 58`, que já está ordenado? E o bubble com bandeira?

{{pratique}}
