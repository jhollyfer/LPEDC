## 0039 · Matrizes

Uma rede de açaí tem 3 lojas e compara as vendas de 4 semanas. Na planilha,
uma linha por loja, uma coluna por semana, o total da loja no fim de cada
linha e o da semana no pé de cada coluna. No C, essa planilha é uma
**matriz**.

Uma matriz é um **vetor de vetores** (**bidimensional**). `int vendas[3][4]`
são 3 linhas, cada uma um vetor de 4 `int`. Para chegar a uma célula, use dois
índices, **primeiro a linha, depois a coluna**: `vendas[2][0]` é a loja 3 na
semana 1. Os dois começam em 0.

```c
int vendas[3][4];                          // 12 int com lixo
int m[2][3] = {{1, 2, 3}, {4, 5, 6}};      // uma chave por linha
int z[2][3] = {{1}, {4, 5}};               // o que falta vira 0: 1 0 0 / 4 5 0
int t[][2] = {{1, 2}, {3, 4}, {5, 6}};     // só a 1ª dimensão pode sumir: 3 linhas
```

Dá para omitir as chaves internas (`{1, 2, 3, 4, 5, 6}`): os valores enchem a
matriz linha por linha. Mas o gcc avisa (`-Wmissing-braces`); use as chaves.

Dois índices pedem **dois laços aninhados** (assunto 0024): o de fora escolhe
a linha, o de dentro anda pelas colunas. Para somar por coluna, inverta: coluna
por fora, linha por dentro.

No C, a matriz é **um bloco contínuo**, com as linhas coladas uma na outra. As
12 células do exemplo ficam enfileiradas: a linha 0 inteira, depois a 1, depois
a 2. A célula `vendas[1][2]` (o 14) é a 7ª da fila, na posição 1 × 4 + 2 = 6:

{{ideia}}

O código mostra a tabela com o total de cada linha e, em outro par de laços, o
total de cada coluna:

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

O laço de dentro dá 4 voltas para **cada** volta do de fora: o corpo roda
3 × 4 = 12 vezes, uma por célula:

{{fluxograma}}

Ao passar uma matriz a uma função vale a regra do assunto 0038 (vai o
endereço, a função mexe no original), mas **todas as dimensões, menos a
primeira, são obrigatórias**: `void mostrar(int m[][4], int linhas)`. O
compilador precisa do número de colunas para achar `m[l][c]`. O exemplo A078
faz isso com um tabuleiro de jogo da velha.

> [!WARNING]
> Escreva `m[l][c]`, nunca `m[l, c]`. A vírgula é um operador que descarta o
> da esquerda: `m[1, 2]` vira `m[2]`, a linha inteira. Outro erro comum é
> trocar os limites: com `int m[3][4]`, o laço das linhas vai até 3 e o das
> colunas até 4. Trocados, o laço lê `m[3][...]`, fora da matriz.

> [!TIP]
> **Por dentro do C:** a memória só tem uma fila de bytes. O C guarda a matriz
> **linha após linha** (*row-major*): `vendas[l][s]` fica em início +
> (l × 4 + s) × 4 bytes. É essa conta que exige o número de colunas no
> parâmetro. Percorrer linha por linha lê bytes vizinhos, já no **cache**;
> percorrer coluna por coluna pula 16 bytes a cada passo e, em matrizes
> grandes, deixa o programa bem mais lento com o mesmo resultado.

> [!NOTE]
> **Pergunta para você:** em `int t[][2] = {{1, 2}, {3, 4}, {5}};`, quantas
> linhas o compilador cria? Quanto vale `t[2][1]`? E `sizeof(t)`?

{{pratique}}
