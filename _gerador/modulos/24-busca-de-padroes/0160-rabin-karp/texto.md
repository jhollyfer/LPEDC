## 0160 · Rabin-Karp

- **Impressão digital**: o hash (assunto 0105) resume um texto. Hashes
  diferentes garantem textos diferentes; hashes iguais só pedem conferência.
- **Rabin-Karp**: calcula o hash do padrão e o de cada **janela** de `m` letras
  do texto, e só compara letra a letra quando os hashes batem
  (KARP; RABIN, 1987).
- **Hash rolante**: a janela seguinte perde uma letra e ganha outra, e o hash
  novo sai do antigo em O(1). Com dígitos, de `271` para `718`:
  `(271 - 2·100)·10 + 8` (CORMEN et al., 2024, cap. 32).
- **Módulo `q`**: com letras, base 256 e tudo **módulo um primo `q`** grande
  (como 1.000.003), em `long long`, porque os números ficam enormes
  (SEDGEWICK; WAYNE, 2011).
- **Colisão** ou **falso positivo**: janelas diferentes com o mesmo resto. Por
  isso a conferência letra a letra nunca pode ser pulada (A319 mostra os falsos
  positivos caindo com `q` maior).
- **Custo**: O(n + m) na média com `q` grande; O(n·m) se tudo colidir
  (CORMEN et al., 2024, cap. 32).

> [!WARNING]
> Em C, `-7 % 13` vale `-7`, não `6`. `ht - t[i] * pot` fica negativo, e um hash
> negativo nunca bate: a busca **perde ocorrências** sem erro. Por isso a linha
> é `(ht - t[i] * pot % Q + Q) % Q`.

{{exemplo}}

Procure `182` em `2718281828459` com `q = 13`, pequeno de propósito. O hash do
padrão é 0, e nas 11 janelas o 0 aparece três vezes: duas são o `182` e uma é o
`845`, um falso positivo:

{{ideia}}

Em C:

```c
#include <stdio.h>
#include <string.h>

#define BASE 10   // dígitos: cada janela é um número na base 10
#define Q 13      // o módulo (de propósito pequeno, para aparecer colisão)

// as m letras de t e de p são iguais? (a conferência de verdade)
int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

int rabin_karp(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pot = 1;                              // BASE^(m-1) % Q
    for (int j = 0; j < m - 1; j++) {
        pot = pot * BASE % Q;
    }
    int hp = 0, ht = 0;                       // hash do padrão e da 1ª janela
    for (int j = 0; j < m; j++) {
        hp = (hp * BASE + (p[j] - '0')) % Q;
        ht = (ht * BASE + (t[j] - '0')) % Q;
    }

    int achados = 0;
    for (int i = 0; i <= n - m; i++) {
        printf("janela %.*s: hash %2d", m, t + i, ht);
        if (ht == hp) {                       // hash igual: só agora compara
            if (iguais(t + i, p, m)) {
                printf("  confere: ocorrência em %d", i);
                achados++;
            } else {
                printf("  confere: falso positivo");
            }
        }
        printf("\n");
        if (i < n - m) {                      // rola: tira t[i], põe t[i+m]
            ht = (ht - (t[i] - '0') * pot % Q + Q) % Q;
            ht = (ht * BASE + (t[i + m] - '0')) % Q;
        }
    }
    return achados;
}

int main(void) {
    const char *codigo = "2718281828459";
    printf("hash de 182: %d\n", 182 % Q);
    int total = rabin_karp(codigo, "182");
    printf("%d ocorrências\n", total);
    return 0;
}
// Saída:
// hash de 182: 0
// janela 271: hash 11
// janela 718: hash  3
// janela 182: hash  0  confere: ocorrência em 2
// janela 828: hash  9
// janela 281: hash  8
// janela 818: hash 12
// janela 182: hash  0  confere: ocorrência em 6
// janela 828: hash  9
// janela 284: hash 11
// janela 845: hash  0  confere: falso positivo
// janela 459: hash  4
// 2 ocorrências
```

### Passo a passo

A primeira rolada, de `271` (hash 11) para `718`. O `pot` é `10² % 13 = 9`:

| Passo | Conta | Resultado |
| --- | --- | --- |
| tira o 2 | `2 · 9 % 13 = 5`; `(11 - 5 + 13) % 13` | 6 |
| desloca e põe o 8 | `(6 · 10 + 8) % 13 = 68 % 13` | **3** |
| confere do zero | `718 % 13 = 718 - 715` | 3 |

São duas operações por janela, com qualquer `m`. A conferência letra a letra
quase nunca roda quando `q` é grande:

{{fluxograma}}
