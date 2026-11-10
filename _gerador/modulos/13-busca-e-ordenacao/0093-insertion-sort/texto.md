## 0093 · Insertion sort

Numa rodada de buraco, você recebe as cartas uma a uma: 7, 4, 9, 2, 5. Cada
carta nova é **encaixada** no lugar certo da mão, que já está em ordem.

Esse é o **insertion sort** (ordenação por inserção). A parte pronta é
`v[0..j-1]`, **em ordem entre si** (no selection, a parte pronta já estava no
lugar final). A cada passo:

1. guarde a próxima carta, `x = v[j]`;
2. ande para a esquerda empurrando uma casa para a direita cada elemento
   **maior** que `x` (um **deslocamento**, não uma troca);
3. ao achar alguém menor ou igual (ou o começo), ponha `x` em `v[i + 1]`.

Guardar `x` antes é obrigatório: o primeiro deslocamento escreve por cima de
`v[j]`.

Cada deslocamento desfaz uma inversão, como a troca do bubble, mas custa uma
escrita, não três. No pior caso (vetor ao contrário): `n(n - 1)/2`
comparações, **O(n²)**. No melhor (já ordenado): `n - 1`, **O(n)**. É o melhor
dos três simples; bibliotecas o usam para pedaços de 16 a 32 posições.

Cada linha é uma carta nova: verde é a mão arrumada, amarela é a carta que
entrou. O 9 não anda; o 2 atravessa a mão inteira:

{{ideia}}

A função `maior` só conta as comparações:

```c
#include <stdio.h>
#include <stdbool.h>

static int comparacoes = 0;

// a > b, contando a comparação
bool maior(int a, int b) {
    comparacoes++;
    return a > b;
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void insertion_sort(int v[], int n) {
    int deslocamentos = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];                   // a carta que vai ser encaixada
        int i = j - 1;
        while (i >= 0 && maior(v[i], x)) {
            v[i + 1] = v[i];            // abre espaço: empurra para a direita
            deslocamentos++;
            i--;
        }
        v[i + 1] = x;                   // encaixa no buraco
        printf("j = %d (x = %d):", j, x);
        mostra(v, n);
    }
    printf("%d comparações, %d deslocamentos\n", comparacoes, deslocamentos);
}

int main(void) {
    int mao[] = {7, 4, 9, 2, 5};
    int n = 5;

    printf("início:       ");
    mostra(mao, n);
    insertion_sort(mao, n);
    return 0;
}
// Saída:
// início:         7  4  9  2  5
// j = 1 (x = 4):  4  7  9  2  5
// j = 2 (x = 9):  4  7  9  2  5
// j = 3 (x = 2):  2  4  7  9  5
// j = 4 (x = 5):  2  4  5  7  9
// 8 comparações, 6 deslocamentos
```

### Passo a passo

O encaixe do 2 (`j = 3`), o mais caro. A mão antes é `4 7 9 | 2 5`:

| i | v[i] | `v[i] > 2`? | o que acontece | vetor |
| --- | --- | --- | --- | --- |
| 2 | 9 | sim | `v[3] = 9` | 4 7 9 9 5 |
| 1 | 7 | sim | `v[2] = 7` | 4 7 7 9 5 |
| 0 | 4 | sim | `v[1] = 4` | 4 4 7 9 5 |
| -1 | | (`i >= 0` falso: nem compara) | `v[0] = 2` | 2 4 7 9 5 |

Foram três comparações e três deslocamentos. Somando todos os encaixes:
1 + 1 + 3 + 3 = **8 comparações** e 1 + 0 + 3 + 2 = **6 deslocamentos**.

O laço de dentro para por dois motivos: acabou o vetor ou achou alguém que
não é maior:

{{fluxograma}}

> [!WARNING]
> Escreva `while (i >= 0 && v[i] > x)`. Na ordem inversa, com `i = -1` o
> programa lê `v[-1]`. O curto-circuito do `&&` (assunto 0013) protege o vetor.

> [!TIP]
> O insertion sort é **estável**: o `>` (e não `>=`) para ao encontrar um
> igual, e `x` entra depois dele. Também é **online**: ordena à medida que os
> dados chegam.

> [!NOTE]
> **Pergunta para você:** se a condição fosse `v[i] >= x`, o vetor continuaria
> saindo ordenado? Quantos deslocamentos o código faria? E com dois elementos
> iguais? (O A185 mostra por que isso importa.)

{{pratique}}
