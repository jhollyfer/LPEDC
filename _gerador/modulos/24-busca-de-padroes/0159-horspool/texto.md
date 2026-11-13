## 0159 · Horspool

- **Comparar da direita para a esquerda**: olhe a letra do texto sob a
  **última** casa do padrão. Se ela não aparece no padrão, o padrão pula `m`
  casas (FEOFILOFF, 2009, cap. 13).
- **Horspool**: versão simples do **Boyer-Moore**. Se a letra aparece, o salto
  leva a ocorrência **mais à direita** dela no padrão até ficar sob ela
  (HORSPOOL, 1980).
- **Tabela de saltos**: uma casa por byte (256). Toda letra começa com `m`; para
  `j` de 0 até `m - 2`, `salto[padrao[j]] = m - 1 - j`. A última letra fica de
  fora: seu salto seria 0 (ZIVIANI, 2010, cap. 8).
- **Avanço**: achando ou não, o próximo alinhamento é
  `i + salto[texto[i + m - 1]]`.
- **Custo**: com alfabeto grande, o salto fica perto de `m` e a busca olha umas
  `n / m` letras: padrão **maior**, busca **mais rápida** (A317). O pior caso
  segue O(n·m): "baaa" num texto só de `a` (E952) (ZIVIANI, 2010, cap. 8).
- **Boyer-Moore completo**: acrescenta a tabela do **bom sufixo**, que garante
  busca linear; o Horspool troca essa garantia por um código curto.

> [!WARNING]
> O índice da tabela tem que ser `unsigned char`: em UTF-8, o `ã` começa com o
> byte 0xC3, que num `char` com sinal vale **-61**, e `salto[-61]` escreve fora
> do vetor. E não ponha a última letra do padrão na tabela.

{{exemplo}}

Procure "MANGA" (`m = 5`) na placa "A BANCA VENDE MANGA" (19 letras). Os saltos
são M = 4, A = 3, N = 2, G = 1 e 5 para as outras; o padrão salta 2, 3, 5 e 4
até casar no alinhamento 14:

{{ideia}}

Em C:

```c
#include <stdio.h>
#include <string.h>

#define ALFABETO 256

// salto[c]: quanto andar quando a letra c está sob a última casa do padrão
void monta_saltos(const char *p, int m, int salto[]) {
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;                     // letra fora do padrão: pula tudo
    }
    for (int j = 0; j < m - 1; j++) {     // a última letra fica de fora
        salto[(unsigned char) p[j]] = m - 1 - j;
    }
}

int horspool(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int salto[ALFABETO];
    int achados = 0, alinhamentos = 0;
    monta_saltos(padrao, m, salto);

    int i = 0;
    while (i <= n - m) {
        alinhamentos++;
        int j = m - 1;                    // compara da direita para a esquerda
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }
        unsigned char ultima = (unsigned char) texto[i + m - 1];
        if (j < 0) {
            printf("i = %2d: achou!\n", i);
            achados++;
        } else {
            printf("i = %2d: falhou; sob a última casa está '%c', salta %d\n",
                   i, ultima, salto[ultima]);
        }
        i += salto[ultima];
    }
    printf("%d alinhamentos (a força bruta faria %d)\n", alinhamentos, n - m + 1);
    return achados;
}

int main(void) {
    const char *placa = "A BANCA VENDE MANGA";
    int salto[ALFABETO];
    monta_saltos("MANGA", 5, salto);
    printf("saltos: M=%d A=%d N=%d G=%d outras=%d\n",
           salto['M'], salto['A'], salto['N'], salto['G'], salto['Z']);
    horspool(placa, "MANGA");
    return 0;
}
// Saída:
// saltos: M=4 A=3 N=2 G=1 outras=5
// i =  0: falhou; sob a última casa está 'N', salta 2
// i =  2: falhou; sob a última casa está 'A', salta 3
// i =  5: falhou; sob a última casa está 'E', salta 5
// i = 10: falhou; sob a última casa está 'M', salta 4
// i = 14: achou!
// 5 alinhamentos (a força bruta faria 15)
```

### Passo a passo

Os cinco alinhamentos; a última letra de `texto[i..i+4]` decide o salto:

| i | janela | comparações (da direita) | última letra | salto |
| --- | --- | --- | --- | --- |
| 0 | `A BAN` | 1 (`N` ≠ `A`) | `N` | 2 |
| 2 | `BANCA` | 2 (`A` = `A`, `C` ≠ `G`) | `A` | 3 |
| 5 | `CA VE` | 1 | `E` | 5 |
| 10 | `NDE M` | 1 | `M` | 4 |
| 14 | `MANGA` | 5: **achou** | `A` | 3 (passa do fim) |

Foram 10 comparações; a força bruta faz 19. O passo do `i` vem da tabela,
pela última letra da janela:

{{fluxograma}}
