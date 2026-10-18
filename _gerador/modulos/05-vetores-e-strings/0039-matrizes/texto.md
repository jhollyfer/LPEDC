## 0039 · Matrizes

Uma rede de açaí tem 3 lojas e quer comparar as vendas das últimas 4 semanas.
Você abre uma planilha: uma linha por loja, uma coluna por semana. No fim de
cada linha, o total da loja; no pé de cada coluna, o total da semana. Essa
planilha, no C, é uma **matriz**.

Uma matriz é um **vetor de vetores**. `int vendas[3][4]` são 3 linhas, e cada
linha é um vetor de 4 `int`. Para chegar numa célula você usa dois índices,
**primeiro a linha, depois a coluna**: `vendas[2][0]` é a loja 3 na semana 1.
Os dois começam em 0, como em qualquer vetor.

```c
int vendas[3][4];                          // 12 int com lixo
int m[2][3] = {{1, 2, 3}, {4, 5, 6}};      // uma chave por linha
int z[2][3] = {{1}, {4, 5}};               // o que falta vira 0: 1 0 0 / 4 5 0
int t[][2] = {{1, 2}, {3, 4}, {5, 6}};     // só a 1ª dimensão pode sumir: 3 linhas
```

Dá para escrever os valores sem as chaves internas (`{1, 2, 3, 4, 5, 6}`):
eles enchem a matriz linha por linha. Mas o gcc avisa (`-Wmissing-braces`), e
com razão: com as chaves, quem lê vê as linhas. Use as chaves.

Um índice pede um laço; dois índices pedem **dois laços aninhados** (assunto
0024). O de fora escolhe a linha, o de dentro anda pelas colunas dessa linha.
Para somar por coluna, você inverte: a coluna fica por fora e a linha por
dentro. Os laços são os mesmos; muda só quem é o "relógio das horas" e quem é
o "dos minutos".

No C, a matriz não é um punhado de linhas soltas, cada uma num canto da
memória. Ela é **um bloco só, contínuo**, com todas as linhas do mesmo tamanho,
uma colada na outra.

Vamos ver na prática. A planilha tem 3 linhas e 4 colunas. Na memória, as 12
células ficam enfileiradas: primeiro a linha 0 inteira, depois a linha 1,
depois a 2. A célula `vendas[1][2]` (o 14) é a 7ª da fila, na posição 1 × 4 + 2
= 6:

{{ideia}}

O código mostra a tabela com o total de cada linha e, num segundo par de
laços, o total de cada coluna:

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

Repara no fluxograma: são dois laços, um dentro do outro. O de dentro dá 4
voltas para **cada** volta do de fora, então o corpo roda 3 × 4 = 12 vezes,
uma por célula:

{{fluxograma}}

Para passar uma matriz a uma função, vale a regra do assunto 0038 (vai o
endereço, a função mexe no original), com um detalhe: **todas as dimensões,
menos a primeira, são obrigatórias** no parâmetro: `void mostrar(int
m[][4], int linhas)`. O compilador precisa saber quantas colunas tem cada
linha para achar `m[l][c]`. O exemplo A078 faz isso com um tabuleiro de jogo da
velha.

> [!WARNING]
> Escreva `m[l][c]`, nunca `m[l, c]`. A vírgula, no C, é um operador que
> descarta o da esquerda: `m[1, 2]` vira `m[2]`, a linha inteira. Às vezes
> compila com um aviso só, e o resultado é absurdo. Outro erro comum é trocar
> os limites: com `int m[3][4]`, o laço das linhas vai até 3 e o das colunas
> até 4. Trocou, e o laço lê `m[3][...]`, fora da matriz.

> [!TIP]
> **Por dentro do C:** a memória não tem linhas nem colunas, só uma fila de
> bytes. O C guarda a matriz **linha após linha** (*row-major*): `vendas[l][s]`
> fica em início + (l × 4 + s) × 4 bytes. É essa conta que exige o número de
> colunas no parâmetro. E isso tem custo real: percorrer linha por linha (`l`
> por fora, `s` por dentro) lê bytes vizinhos, que o processador já trouxe
> para o **cache**. Percorrer coluna por coluna pula 16 bytes a cada passo. Em
> matrizes grandes, a ordem errada dos laços pode deixar o programa várias
> vezes mais lento, com o mesmo resultado.

> [!NOTE]
> **Pergunta para você:** em `int t[][2] = {{1, 2}, {3, 4}, {5}};`, quantas
> linhas o compilador cria? Quanto vale `t[2][1]`? E `sizeof(t)`?

{{pratique}}
