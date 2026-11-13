## 0039 · Matrizes

Uma rede de açaí tem 3 lojas e quer comparar as vendas de 4 semanas. Na
planilha, cada loja ocupa uma linha e cada semana uma coluna; o total da loja
fica no fim da linha e o da semana no pé da coluna. Um vetor só dá conta de
uma linha. Para a planilha inteira, você precisa de um nome para a tabela e
de dois números para achar uma célula.

Em C, essa tabela é a **matriz**, um **vetor de vetores**, também chamada de
vetor **bidimensional**. Em `int vendas[3][4]`, o primeiro número diz quantas
linhas existem e o segundo quantos itens cada linha tem: são 3 linhas, e cada
uma é um vetor de 4 `int` (BACKES, 2013, cap. 6). A imagem certa é a de uma
estante: 3 prateleiras, cada uma com 4 caixas.

```c
int vendas[3][4];                          // 12 int com lixo
int m[2][3] = {{1, 2, 3}, {4, 5, 6}};      // uma chave por linha
int z[2][3] = {{1}, {4, 5}};               // o que falta vira 0: 1 0 0 / 4 5 0
int t[][2] = {{1, 2}, {3, 4}, {5, 6}};     // só a 1ª dimensão pode sumir: 3 linhas
```

Para chegar a uma célula, você usa dois índices, **primeiro a linha, depois a
coluna**, e os dois começam em 0. `vendas[2][0]` é a loja 3 na semana 1. Cada
célula se comporta como uma variável comum, igual às gavetas do vetor
(DEITEL; DEITEL, 2011, cap. 6).

Na inicialização, cada linha ganha o seu par de chaves. Como no vetor, o que
você não listar vira 0: em `z`, a primeira linha fica `1 0 0` e a segunda
`4 5 0`. Dá para deixar vazia só a primeira dimensão, a das linhas, e o
compilador conta quantas chaves internas você escreveu; a das colunas é
obrigatória (DEITEL; DEITEL, 2011, cap. 6). Também é possível omitir as
chaves internas e escrever os seis valores seguidos, que enchem a matriz
linha por linha, mas o gcc avisa (`-Wmissing-braces`). Use as chaves: elas
mostram a forma da tabela.

Dois índices pedem **dois laços aninhados** (assunto 0024). O laço de fora
escolhe a linha; o de dentro anda pelas colunas daquela linha. Assim você
soma o total de cada loja. Para somar por semana, inverta a ordem: a coluna
por fora, a linha por dentro (BACKES, 2013, cap. 6).

A memória, porém, não tem linhas nem colunas: é uma fila só de bytes. O C
guarda a matriz como **um bloco contínuo**, linha após linha, arranjo chamado
de *row-major*. As 12 células de `vendas` ficam enfileiradas: a linha 0
inteira, depois a linha 1, depois a 2. A célula `vendas[l][s]` é o item
`l × 4 + s` da fila; `vendas[1][2]` é o item 6, o sétimo (KERNIGHAN; RITCHIE,
1989, cap. 5).

Essa conta tem duas consequências. A primeira aparece quando a matriz vai
para uma função. Como no vetor, vai só o endereço do começo, mas a função
precisa saber quantas colunas cada linha tem para fazer a conta `l × 4 + s`.
Por isso o parâmetro exige todas as dimensões menos a primeira: `int m[][4]`
(DEITEL; DEITEL, 2011, cap. 6). A segunda é de desempenho. Percorrer linha
por linha lê bytes vizinhos, que o processador já trouxe para o **cache**, a
memória pequena e rápida que fica dentro dele. Percorrer coluna por coluna
pula 16 bytes a cada passo e, numa matriz grande, deixa o programa bem mais
lento, com o mesmo resultado.

> [!WARNING]
> Escreva `m[l][c]`, nunca `m[l, c]`: a vírgula é um operador que descarta o
> da esquerda, e `m[1, 2]` vira `m[2]`, a linha inteira. E não troque os
> limites: com `int m[3][4]`, o laço das linhas vai até 3 e o das colunas até
> 4. Trocados, o laço lê `m[3][...]`, fora da matriz.

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
