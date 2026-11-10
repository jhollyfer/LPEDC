// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0912 · ★★☆ · Tirando um produto do catálogo
//
// Um arquivo binário não tem "apagar registro do meio". O jeito clássico é
// copiar todos os registros, MENOS o que sai, para um arquivo novo. Escreva
//
//   int remove_produto(const char *origem, const char *destino, int codigo)
//
// que faz essa cópia e devolve quantos registros foram para o destino (ou
// -1 se não conseguir abrir algum arquivo). O main grava 5 produtos em
// /tmp/p0912_catalogo.bin, remove o código 103 gerando
// /tmp/p0912_novo.bin, lista o arquivo novo e apaga os dois no fim.
//
//   Saída esperada:
//   Antes: 5 produtos
//   Depois: 4 produtos
//   101 Arroz        R$  24.90
//   102 Feijao       R$   8.75
//   104 Farinha      R$   6.40
//   105 Cafe         R$  17.30
//
// Dicas:
// 1. Abra a origem em "rb" e o destino em "wb". Leia um registro por vez
//    com fread e só chame fwrite se o código for diferente do que sai.
// 2. Para listar, um while (fread(&p, sizeof p, 1, arq) == 1) basta.
// 3. Resposta esperada: Depois: 4 produtos, sem o 103 (Acucar) na lista.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int codigo;
    char nome[20];
    double preco;
} Produto;

int main(void) {
    const char *origem = "/tmp/p0912_catalogo.bin";
    Produto catalogo[5] = {
        {101, "Arroz", 24.90}, {102, "Feijao", 8.75}, {103, "Acucar", 5.20},
        {104, "Farinha", 6.40}, {105, "Cafe", 17.30},
    };

    FILE *arq = fopen(origem, "wb");
    if (arq == NULL) {
        perror(origem);
        return 1;
    }
    fwrite(catalogo, sizeof(Produto), 5, arq);
    fclose(arq);
    printf("Antes: 5 produtos\n");

    // escreva remove_produto acima do main, chame aqui e liste o arquivo novo

    remove(origem);
    return 0;
}
