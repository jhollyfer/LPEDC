// 0068 · Arquivos binários
// Exercício E404 · ★☆☆
//
// O arquivo /tmp/quatro.bin já está gravado com 4 ints em binário: 10, 20,
// 30 e 40 (cada int ocupa 4 bytes). Complete o programa: antes de cada
// fread, escreva UM fseek que leve o arquivo até o int certo, para a saída
// ficar exatamente assim:
//
//   Saída esperada:
//   a) 30, agora na posição 12
//   b) 20, agora na posição 8
//   c) 40, agora na posição 16
//   d) 10, agora na posição 4
//
// Use uma origem diferente em cada um: SEEK_SET em a), SEEK_CUR em b),
// SEEK_END em c) e d) com rewind(arq) no lugar do fseek.
//
// Dicas:
// 1. SEEK_SET conta do começo, SEEK_CUR da posição atual e SEEK_END do fim.
//    O deslocamento pode ser negativo.
// 2. Cada fread de um int anda 4 bytes para a frente: depois de a) você está
//    no byte 12. Para chegar ao 20 (byte 4), volte 8.
// 3. Resposta esperada: a) fseek(arq, 8, SEEK_SET); b) fseek(arq, -8,
//    SEEK_CUR); c) fseek(arq, -4, SEEK_END); d) rewind(arq). A saída fica
//    igual à de cima.
//
// Escreva sua resposta abaixo (complete onde estão os TODO):

#include <stdio.h>

// lê um int da posição atual e mostra o valor e onde o arquivo parou
void ler_e_mostrar(FILE *arq, const char *rotulo) {
    int x;
    if (fread(&x, sizeof x, 1, arq) == 1) {
        printf("%s %d, agora na posição %ld\n", rotulo, x, ftell(arq));
    } else {
        printf("%s nada lido\n", rotulo);
    }
}

int main(void) {
    const char *caminho = "/tmp/quatro.bin";
    int v[4] = {10, 20, 30, 40};

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(v, sizeof(int), 4, arq);
    fclose(arq);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    // TODO a): fseek com SEEK_SET
    ler_e_mostrar(arq, "a)");
    // TODO b): fseek com SEEK_CUR
    ler_e_mostrar(arq, "b)");
    // TODO c): fseek com SEEK_END
    ler_e_mostrar(arq, "c)");
    // TODO d): rewind
    ler_e_mostrar(arq, "d)");

    fclose(arq);
    remove(caminho);
    return 0;
}
