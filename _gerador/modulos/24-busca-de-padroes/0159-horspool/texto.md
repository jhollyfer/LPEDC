## 0159 · Horspool

Na feira, você procura "MANGA" nas placas. Se a placa termina com uma letra
que não existe em "MANGA", pule para a próxima. Dá para ler **menos** letras
que a força bruta e o KMP?

Dá: compare o padrão **da direita para a esquerda**. Olhe a letra do texto
sob a **última** casa do padrão. Se ela não aparece no padrão, nenhum
alinhamento que a cubra dá certo, e o padrão pula `m` casas. Se aparece, o
salto leva a ocorrência **mais à direita** dela no padrão até ficar sob a
mesma letra do texto. É o algoritmo de **Horspool** (1980), versão simples do
**Boyer-Moore** (1977).

Os saltos dependem só do padrão e ficam numa **tabela de saltos**, uma casa
por valor de byte (256):

- toda letra começa com `salto = m`;
- para cada `j` de 0 até `m - 2`, `salto[padrao[j]] = m - 1 - j`, a distância
  de `j` até a última casa. Como `j` cresce, a letra repetida fica com a
  ocorrência mais à direita.

A última letra fica de fora: seu salto seria 0 e a busca não andaria.

Cada alinhamento `i` compara de `j = m - 1` para trás. Achando ou não, o
próximo é `i + salto[texto[i + m - 1]]`.

A placa é "A BANCA VENDE MANGA" (19 letras) e o padrão é "MANGA" (`m = 5`).
Os saltos são M = 4, A = 3, N = 2, G = 1 e 5 para as outras. No alinhamento 0,
sob a última casa está o `N`: salta 2. No 2, o `A` bate, o `C` não, e o `A`
manda saltar 3. No 5, o `E` salta 5. No 10, o `M` salta 4. No 14, as cinco
letras batem:

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

Com alfabeto grande e padrão comprido, o salto fica perto de `m` e a busca
olha umas `n / m` letras: quanto **maior** o padrão, **mais rápida** a busca
(o A317 mede). O pior caso continua O(n·m): "baaa" num texto só de `a`
compara 4 letras e salta 1 por alinhamento (E952).

> [!WARNING]
> O índice da tabela tem que ser `unsigned char`. Em UTF-8, o `ã` começa com
> o byte 0xC3, que num `char` com sinal (gcc em x86) vale **-61**, e
> `salto[-61]` escreve fora do vetor sem erro de compilação. Converta:
> `salto[(unsigned char) c]`. E não ponha a última letra do padrão na tabela.

> [!TIP]
> O Boyer-Moore completo acrescenta a tabela do **bom sufixo**, que garante
> busca linear; o Horspool troca essa garantia por um código curto.

> [!NOTE]
> **Pergunta para você:** qual é a tabela de saltos de "BANANA"? E quantos
> alinhamentos o Horspool testa para procurar "BANANA" em "BANDANA BANANA"?
> Faça no papel e confira no código.

{{pratique}}
