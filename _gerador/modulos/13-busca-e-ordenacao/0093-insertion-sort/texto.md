## 0093 · Insertion sort

Rodada de buraco com a família. Você recebe as cartas uma a uma: 7, 4, 9, 2,
5. Ninguém espera chegarem todas para arrumar. A cada carta nova, você olha a
mão (que já está em ordem), acha o lugar dela e **encaixa**, empurrando as
maiores um pouco para o lado.

Esse é o **insertion sort** (ordenação por inserção). O vetor também tem uma
parte pronta à esquerda, `v[0..j-1]`, mas "pronta" aqui quer dizer **em
ordem entre si**, não "no lugar final" como no selection. A cada passo:

1. guarde a próxima carta, `x = v[j]`;
2. ande para a esquerda empurrando uma casa para a direita cada elemento
   **maior** que `x` (é um **deslocamento**, não uma troca);
3. quando achar alguém menor ou igual (ou o começo do vetor), ponha `x` no
   buraco que sobrou, `v[i + 1]`.

Repara que guardar `x` antes é obrigatório: o primeiro deslocamento escreve
por cima de `v[j]`.

O custo depende de **quanto** o vetor está bagunçado. Cada deslocamento
desfaz uma inversão (como cada troca do bubble), mas custa uma escrita, não
três. No pior caso (vetor ao contrário), cada carta anda até o começo:
`n(n - 1)/2` comparações, **O(n²)**. No melhor (já ordenado), cada carta
compara uma vez e fica: `n - 1` comparações, **O(n)**. E em vetor **quase**
ordenado, ele é quase linear. Isso o torna o melhor dos três algoritmos
simples na prática, e é por isso que bibliotecas de verdade usam insertion
para pedaços pequenos (até umas 16 a 32 posições).

Vamos ver na prática. Em cada linha, a parte verde é a mão já arrumada e a
amarela é a carta que acabou de entrar. O 9 não anda nada; o 2 atravessa a
mão inteira:

{{ideia}}

O mesmo exemplo em C. A função `maior` só existe para contar as
comparações:

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

Três comparações, três deslocamentos. Repara nas linhas do meio: durante o
encaixe, o vetor tem um valor **repetido** e o 2 não está em lugar nenhum. Ele
está guardado em `x`. Somando todos os encaixes: 1 + 1 + 3 + 3 = **8
comparações** e 1 + 0 + 3 + 2 = **6 deslocamentos**.

Repara no fluxograma: o laço de dentro tem uma pergunta dupla. Ele para por
dois motivos diferentes: acabou o vetor, ou achou alguém que não é maior:

{{fluxograma}}

> [!WARNING]
> A ordem das condições importa: `while (i >= 0 && v[i] > x)`. Escrita ao
> contrário, `while (v[i] > x && i >= 0)`, quando `i` chega a `-1` o programa
> lê `v[-1]` **antes** de perguntar se `i` é válido. É o curto-circuito do
> `&&` (assunto 0013) que protege o vetor: se `i >= 0` dá falso, o lado
> direito nem é avaliado.

> [!TIP]
> **Por dentro do C:** o laço de deslocamento é praticamente um `memmove`: ele
> empurra um bloco contínuo de memória uma casa para a direita. Por isso o
> insertion sort é tão rápido em vetores pequenos: acessa a memória em
> sequência, faz uma escrita por deslocamento e não chama função nenhuma. Ele
> também é **estável**: o `>` (e não `>=`) faz o laço parar ao encontrar um
> igual, e `x` entra **depois** dele. E é **online**: consegue ordenar à
> medida que os dados chegam, como as cartas na mão.

> [!NOTE]
> **Pergunta para você:** e se a condição fosse `v[i] >= x`? O vetor
> continuaria saindo ordenado? Quantos deslocamentos o código acima faria? E o
> que aconteceria com dois elementos iguais? (O A185 mostra por que isso
> importa.)

{{pratique}}
