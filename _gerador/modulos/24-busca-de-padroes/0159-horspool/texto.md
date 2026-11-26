## 0159 · Horspool

Na feira, você procura a banca que vende "MANGA" lendo as placas. A força
bruta e o KMP leem todas as letras do texto, uma por uma. Dá para ler
**menos** do que isso? Dá, se você olhar primeiro para o lugar certo.

A ideia é comparar o padrão **da direita para a esquerda**. Encoste o padrão
no texto e olhe primeiro a letra do texto que está sob a **última** casa do
padrão. Se essa letra nem existe no padrão, nenhum alinhamento que a cubra
pode dar certo, e o padrão pode pular `m` casas de uma vez (FEOFILOFF, 2009,
cap. 13). Procurando "MANGA" (`m = 5`), se sob a última casa aparece um `E`,
você avança cinco posições sem olhar as outras quatro letras.

E se a letra existe no padrão? Então ela pode fazer parte de uma ocorrência,
e o salto tem de ser menor. O **algoritmo de Horspool** move o padrão até
que a ocorrência **mais à direita** dessa letra no padrão fique exatamente
sob ela (HORSPOOL, 1980). Ele é uma versão simplificada do **Boyer-Moore**,
de quem ele herda a comparação da direita para a esquerda.

Os saltos dependem só do padrão, e por isso ficam numa **tabela de saltos**
calculada antes da busca. Como uma letra em C é um byte, a tabela tem uma
casa para cada um dos 256 valores possíveis. Ela se monta em dois passos
(ZIVIANI, 2010, cap. 8). Primeiro, toda letra recebe `m`, o salto de quem
não está no padrão. Depois, para cada `j` de 0 até `m - 2`,
`salto[padrao[j]] = m - 1 - j`, a distância da posição `j` até a última
casa. Como `j` cresce, uma letra repetida fica com o valor da ocorrência mais
à direita, que é o menor salto e o mais seguro.

Para "MANGA", o `M` está na posição 0 e salta `5 - 1 - 0 = 4`; o primeiro
`A` daria 3, o `N` dá 2 e o `G` dá 1. O último `A`, na posição 4, fica de
fora: seu salto seria 0, e a busca não sairia do lugar. Assim, a tabela fica
M = 4, A = 3, N = 2, G = 1, e 5 para todas as outras letras.

A busca em si é curta. Em cada alinhamento `i`, compare de `j = m - 1` para
trás enquanto as letras baterem. Achando ou não, o próximo alinhamento é
`i + salto[texto[i + m - 1]]`: quem decide o salto é sempre a letra do texto
sob a última casa do padrão.

```c
while (i <= n - m) {
    int j = m - 1;
    while (j >= 0 && texto[i + j] == padrao[j]) j--;
    if (j < 0) printf("ocorrência em %d\n", i);
    i += salto[(unsigned char) texto[i + m - 1]];
}
```

O ganho aparece com alfabeto grande, como o das letras e sinais de um texto
comum. A maioria das letras do texto não está no padrão, o salto fica perto
de `m` e a busca olha mais ou menos `n / m` letras. Daí uma propriedade que
surpreende: quanto **maior** o padrão, **mais rápida** a busca (ZIVIANI,
2010, cap. 8). O A317 mede isso. O pior caso, porém, continua O(n·m):
procurar "baaa" num texto só de `a` compara quatro letras e salta só uma
casa por alinhamento (E952).

O Boyer-Moore completo acrescenta uma segunda tabela, a do **bom sufixo**,
que aproveita as letras que já casaram e garante busca linear. O Horspool
abre mão dessa garantia em troca de um código de poucas linhas, que no texto
do dia a dia é tão rápido quanto.

> [!WARNING]
> O índice da tabela tem que ser `unsigned char`. Em UTF-8, o `ã` começa com
> o byte 0xC3, que num `char` com sinal vale **-61**, e `salto[-61]` escreve
> fora do vetor sem erro de compilação. Converta: `salto[(unsigned char) c]`.
> E não ponha a última letra do padrão na tabela.

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
