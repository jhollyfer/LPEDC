## 0158 · KMP

- **KMP** (Knuth, Morris e Pratt): busca que nunca volta no texto, lê cada letra
  uma vez e custa **O(n + m)** sempre (KNUTH; MORRIS; PRATT, 1977).
- **Ideia**: se `k` letras casaram e a próxima falhou, o fim do texto lido é
  `padrao[0..k-1]`. O quanto disso ainda serve depende **só do padrão** e se
  calcula antes (CORMEN et al., 2024, cap. 32).
- **Borda**: o maior prefixo próprio que também é sufixo. Em `1212` é `12`; em
  `121`, `1`; em `1213`, nenhuma (SZWARCFITER; MARKENZON, 2010).
- **Tabela π**: `pi[j]` é o tamanho da borda de `padrao[0..j]`. Para `12123`,
  `pi = [0, 0, 1, 2, 0]`. Sai procurando o padrão nele mesmo.
- **Busca**: guarda só `k`. Se a letra é `padrao[k]`, `k++`; se não e `k > 0`,
  recua `k = pi[k - 1]` e tenta a **mesma** letra; se `k == m`, achou e recua
  para `pi[m - 1]` (CORMEN et al., 2024, cap. 32).
- **Por que O(n)**: `k` sobe no máximo 1 por letra, `n` vezes no total; cada
  recuo o diminui e ele nunca fica negativo. São no máximo `2n` comparações; a
  tabela custa O(m) pelo mesmo argumento.

> [!WARNING]
> O recuo é um `while`, não um `if`: depois de `k = pi[k - 1]` a letra pode
> continuar não servindo (o E947 testa isso). E os livros usam convenções
> diferentes para a tabela (começando em 1, com -1): misturar dá erro de um.

{{exemplo}}

A central de um alarme desarma quando a senha `12123` aparece no teclado, sem
guardar histórico. Com as teclas `1 2 1 2 1 2 3`, a quinta tecla falha, a
central usa `pi[3] = 2` e o padrão escorrega duas casas; a senha se completa na
sétima tecla:

{{ideia}}

Em C, o `printf` do laço mostra o `k` depois de cada tecla:

```c
#include <stdio.h>
#include <string.h>

#define MAX_PADRAO 32

// pi[j] = tamanho da maior borda de p[0..j] (prefixo próprio que também é sufixo)
void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;                            // tamanho da borda atual
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];                // tenta a borda menor
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

// lê o texto uma vez só, da esquerda para a direita; k = letras já casadas
int kmp(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int pi[MAX_PADRAO];
    int k = 0, achados = 0;
    calcula_pi(padrao, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && texto[i] != padrao[k]) {
            printf("  '%c' não continua os %d casados: k = pi[%d] = %d\n",
                   texto[i], k, k - 1, pi[k - 1]);
            k = pi[k - 1];
        }
        if (texto[i] == padrao[k]) {
            k++;
        }
        printf("tecla %c: k = %d\n", texto[i], k);
        if (k == m) {
            printf("  senha completa! começou na posição %d\n", i - m + 1);
            achados++;
            k = pi[k - 1];                // continua valendo para a próxima
        }
    }
    return achados;
}

int main(void) {
    const char *senha = "12123";
    const char *teclas = "1212123";
    int pi[MAX_PADRAO];
    int m = (int) strlen(senha);

    calcula_pi(senha, m, pi);
    printf("pi de %s:", senha);
    for (int j = 0; j < m; j++) {
        printf(" %d", pi[j]);
    }
    printf("\n");
    kmp(teclas, senha);
    return 0;
}
// Saída:
// pi de 12123: 0 0 1 2 0
// tecla 1: k = 1
// tecla 2: k = 2
// tecla 1: k = 3
// tecla 2: k = 4
//   '1' não continua os 4 casados: k = pi[3] = 2
// tecla 1: k = 3
// tecla 2: k = 4
// tecla 3: k = 5
//   senha completa! começou na posição 2
```

### Passo a passo

A tabela π de `12123`; o `k` é a borda do pedaço anterior:

| j | pedaço `p[0..j]` | `p[j]` vs `p[k]` | k depois | `pi[j]` | borda |
| --- | --- | --- | --- | --- | --- |
| 0 | `1` | (sempre 0) | 0 | 0 | nenhuma |
| 1 | `12` | `2` vs `1`: não | 0 | 0 | nenhuma |
| 2 | `121` | `1` vs `1`: sim | 1 | 1 | `1` |
| 3 | `1212` | `2` vs `2`: sim | 2 | 2 | `12` |
| 4 | `12123` | `3` vs `1`: não, recua para `pi[1] = 0`; `3` vs `1`: não | 0 | 0 | nenhuma |

Na busca, foram 8 comparações para 7 teclas (uma a mais pelo recuo). A força
bruta faria 11.

O recuo é um laço **dentro** do laço do texto e mexe só em `k`. O índice `i`
nunca anda para trás:

{{fluxograma}}
