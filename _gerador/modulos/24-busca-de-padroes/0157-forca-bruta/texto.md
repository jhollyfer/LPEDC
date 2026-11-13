## 0157 · Força bruta

- **Busca de padrão**: achar um **padrão** de `m` letras dentro de um **texto**
  de `n` letras, `m <= n`. É o problema do Ctrl+F e do `grep`
  (CORMEN et al., 2024, cap. 32).
- **Alinhamento**: encostar o padrão no texto a partir da posição `i`. Se as `m`
  letras batem com `texto[i..i+m-1]`, há uma **ocorrência** em `i`.
- **Força bruta** (busca ingênua): testa todos os alinhamentos, de `i = 0` a
  `n - m`, comparando da esquerda para a direita e desistindo na primeira
  diferença (FEOFILOFF, 2009, cap. 13).
- **Sobreposição**: em "banana", "ana" aparece em 1 e em 3; como anda de 1 em 1,
  a força bruta acha as duas.
- **Custo**: num texto comum, perto de `n` comparações. No **pior caso**,
  `(n - m + 1) · m`, ou **O(n·m)**, como `"00001"` num código de vinte zeros
  (A314). Memória O(1) (ZIVIANI, 2010, cap. 8).
- **`strstr(texto, padrao)`** (`string.h`): devolve um ponteiro para a primeira
  ocorrência ou `NULL`; a posição é `p - texto`. Para a próxima, chame de novo a
  partir de `p + 1` (A313) (DEITEL; DEITEL, 2011, cap. 8).

> [!WARNING]
> O laço vai até `i <= n - m`, **inclusive**: com `<`, a última ocorrência some.
> Guarde `n` e `m` em `int`: `strlen` devolve `size_t`, sem sinal, e com padrão
> maior que o texto `n - m` **dá a volta**.

{{exemplo}}

Procure "ana" em "banana bacana": são 11 alinhamentos, com ocorrências no 1, no
3 e no 10. O 0 falha no "b" e o 5 falha no espaço:

{{ideia}}

Em C, contando as comparações de letra:

```c
#include <stdio.h>
#include <string.h>

// mostra cada posição onde o padrão aparece; devolve quantas vezes apareceu
int forca_bruta(const char *texto, const char *padrao, int *comparacoes) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int achados = 0;
    *comparacoes = 0;
    for (int i = 0; i <= n - m; i++) {    // cada alinhamento possível
        int j = 0;
        while (j < m) {
            (*comparacoes)++;
            if (texto[i + j] != padrao[j]) {
                break;                    // errou uma letra: desiste daqui
            }
            j++;
        }
        if (j == m) {                     // as m letras bateram
            printf("  achou na posição %d\n", i);
            achados++;
        }
    }
    return achados;
}

int main(void) {
    const char *placa = "banana bacana";
    int comparacoes;

    printf("Procurando \"ana\" em \"%s\":\n", placa);
    int total = forca_bruta(placa, "ana", &comparacoes);
    printf("%d ocorrências, %d comparações\n", total, comparacoes);
    return 0;
}
// Saída:
// Procurando "ana" em "banana bacana":
//   achou na posição 1
//   achou na posição 3
//   achou na posição 10
// 3 ocorrências, 19 comparações
```

### Passo a passo

As 19 comparações, alinhamento por alinhamento (`n = 13`, `m = 3`):

| i | trecho do texto | comparações | resultado |
| --- | --- | --- | --- |
| 0 | `ban` | 1 (`b` ≠ `a`) | falha |
| 1 | `ana` | 3 | **ocorrência** |
| 2 | `nan` | 1 | falha |
| 3 | `ana` | 3 | **ocorrência** |
| 4 | `na␣` | 1 | falha |
| 5 | `a␣b` | 2 (o espaço ≠ `n`) | falha |
| 6, 7 | `␣ba`, `bac` | 1 cada | falha |
| 8 | `aca` | 2 (`c` ≠ `n`) | falha |
| 9 | `can` | 1 | falha |
| 10 | `ana` | 3 | **ocorrência** |

O teto seria `11 · 3 = 33`; deu 19 porque quase todo alinhamento falha cedo.

O laço de fora anda o alinhamento `i`, o de dentro anda a letra `j`. O `i`
sempre avança 1, tenha achado ou não:

{{fluxograma}}
