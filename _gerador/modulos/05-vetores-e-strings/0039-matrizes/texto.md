## 0039 · Matrizes

- **Matriz**: um **vetor de vetores** (bidimensional). `int vendas[3][4]` são
  3 linhas, cada uma um vetor de 4 `int` (BACKES, 2013, cap. 6).
- **Dois índices**: primeiro a linha, depois a coluna, os dois a partir de 0:
  `vendas[2][0]` é a linha 3, coluna 1 (DEITEL; DEITEL, 2011, cap. 6).
- **Inicialização**: uma chave por linha; o que falta vira 0. Só a 1ª dimensão
  pode ser omitida (DEITEL; DEITEL, 2011, cap. 6).
- **Dois laços aninhados**: o de fora escolhe a linha, o de dentro anda pelas
  colunas. Para somar por coluna, inverta (BACKES, 2013, cap. 6).
- **Linha após linha** (*row-major*): a matriz é um bloco contínuo.
  `vendas[l][s]` é o item `l × 4 + s` da fila (KERNIGHAN; RITCHIE, 1989,
  cap. 5).
- **Matriz como parâmetro**: vai o endereço, mas todas as dimensões menos a
  primeira são obrigatórias (`int m[][4]`), porque a conta acima precisa das
  colunas (DEITEL; DEITEL, 2011, cap. 6).

```c
int vendas[3][4];                          // 12 int com lixo
int m[2][3] = {{1, 2, 3}, {4, 5, 6}};      // uma chave por linha
int z[2][3] = {{1}, {4, 5}};               // o que falta vira 0: 1 0 0 / 4 5 0
int t[][2] = {{1, 2}, {3, 4}, {5, 6}};     // só a 1ª dimensão pode sumir: 3 linhas
```

> [!WARNING]
> Escreva `m[l][c]`, nunca `m[l, c]`: a vírgula descarta o da esquerda e
> `m[1, 2]` vira `m[2]`. E não troque os limites: com `int m[3][4]`, linhas
> até 3 e colunas até 4.

{{exemplo}}

Uma rede de açaí compara 3 lojas em 4 semanas. As 12 células ficam
enfileiradas, linha após linha; `vendas[1][2]` (o 14) está na posição
1 × 4 + 2 = 6:

{{ideia}}

```c
#include <stdio.h>

#define LOJAS 3
#define SEMANAS 4

int main(void) {
    // 3 linhas (lojas) x 4 colunas (semanas): caixas de açaí vendidas
    int vendas[LOJAS][SEMANAS] = {
        {12, 15, 9, 20},
        {8, 11, 14, 10},
        {17, 13, 16, 19},
    };

    printf("        S1  S2  S3  S4  Total\n");
    for (int l = 0; l < LOJAS; l++) {         // uma volta por linha
        int total_loja = 0;
        printf("Loja %d", l + 1);
        for (int s = 0; s < SEMANAS; s++) {   // uma volta por coluna
            printf("%4d", vendas[l][s]);
            total_loja += vendas[l][s];
        }
        printf("%7d\n", total_loja);
    }

    int geral = 0;
    printf("Semana");
    for (int s = 0; s < SEMANAS; s++) {       // agora a coluna fica por fora
        int total_semana = 0;
        for (int l = 0; l < LOJAS; l++) {
            total_semana += vendas[l][s];
        }
        printf("%4d", total_semana);
        geral += total_semana;
    }
    printf("%7d\n", geral);
    return 0;
}
// Saída:
//         S1  S2  S3  S4  Total
// Loja 1  12  15   9  20     56
// Loja 2   8  11  14  10     43
// Loja 3  17  13  16  19     65
// Semana  37  39  39  49    164
```

O laço de dentro dá 4 voltas para cada volta do de fora: o corpo roda
3 × 4 = 12 vezes:

{{fluxograma}}
