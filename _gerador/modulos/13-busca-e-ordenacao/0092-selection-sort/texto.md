## 0092 · Selection sort

- **Selection sort** (ordenação por seleção): escolhe o menor, depois o
  segundo menor, e assim por diante (FEOFILOFF, 2009).
- **Parte pronta**: à esquerda ficam os menores, já na posição final. Cada
  passada `i` procura o **índice** do menor em `v[i..n-1]` e o troca com
  `v[i]`; a gaveta `i` nunca mais muda (FEOFILOFF, 2009).
- **Índice, não valor**: guarda-se o índice do menor para poder trocar no
  fim (padrão "maior/menor" do 0025).
- **Custo**: `n(n - 1)/2` comparações em **todos** os casos, mesmo com o
  vetor em ordem: **O(n²)**. A vantagem é no máximo **uma troca por
  passada**, `n - 1` no total (ZIVIANI, 2010, cap. 4).
- **Instável**: a troca é de longa distância e pode inverter a ordem de
  iguais. Ordena **in-place**, com O(1) de memória extra (FEOFILOFF, 2009).

> [!WARNING]
> Trocar **dentro** do laço que procura o menor ordena, mas perde a vantagem
> das poucas trocas. Esquecer de reiniciar `menor = i` a cada passada faz
> `menor` apontar para a parte pronta.

{{exemplo}}

Os tempos da melhor volta numa bateria de kart, em segundos: 58, 31, 47, 19 e
26. Cada linha é uma passada: a gaveta roxa é a posição `i`, a amarela é o
menor achado; depois da troca, a gaveta vira verde e fica:

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

Fim da passada: troca `v[0]` (58) com `v[3]` (19). As passadas seguintes
fazem 3, 2 e 1 comparações: 10 no total.

A caixa "acha o menor" esconde um laço inteiro (a tabela); a troca fica
**fora** dele:

{{fluxograma}}
