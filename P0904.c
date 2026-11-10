// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0904 · ★☆☆ · Quantos produtos tem o arquivo?
//
// O main abaixo já grava 5 produtos em /tmp/p0904_produtos.bin. Escreva a
// função
//
//   long conta_registros(FILE *arq)
//
// que descobre quantos registros Produto o arquivo tem SEM ler nenhum: vá
// até o fim com fseek, pergunte a posição com ftell e divida pelo tamanho
// de um registro. Depois, no main, leia só o ÚLTIMO produto, com um fseek
// a partir do fim, e mostre-o. Num PC de 64 bits comum, cada Produto ocupa
// 16 bytes (4 do int, 4 de preenchimento, 8 do double).
//
//   Saída esperada:
//   Tamanho do arquivo: 80 bytes
//   Registros: 5
//   Último: código 105, R$ 4.99
//
// Dicas:
// 1. fseek(arq, 0, SEEK_END) e depois ftell(arq) dá o tamanho em bytes.
// 2. O último registro começa sizeof(Produto) bytes antes do fim:
//    fseek(arq, -(long) sizeof(Produto), SEEK_END).
// 3. Resposta esperada: 80 bytes, 5 registros, último código 105 a R$ 4.99.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int codigo;
    double preco;
} Produto;

// escreva aqui long conta_registros(FILE *arq)

int main(void) {
    const char *caminho = "/tmp/p0904_produtos.bin";
    Produto p[5] = {{101, 7.50}, {102, 12.00}, {103, 3.25}, {104, 9.90}, {105, 4.99}};

    FILE *arq = fopen(caminho, "wb+"); // "+": também deixa ler
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(p, sizeof(Produto), 5, arq);

    // complete aqui: tamanho, número de registros e o último produto

    fclose(arq);
    remove(caminho);
    return 0;
}
