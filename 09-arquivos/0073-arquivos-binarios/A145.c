// A145 · Pular direto para o registro

#include <stdio.h>

typedef struct {
    char nome[20];
    int qtd;
    double preco;
} Produto;

int main(void) {
    const char *caminho = "/tmp/estoque.bin";
    Produto estoque[3] = {
        {"Arroz", 12, 25.90},
        {"Feijão", 7, 8.75},
        {"Café", 4, 18.50},
    };

    // Gravar: os 3 registros de uma vez, byte a byte como estão na memória
    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    size_t gravados = fwrite(estoque, sizeof(Produto), 3, arq);
    fclose(arq);
    printf("Cada registro: %zu bytes\n", sizeof(Produto));
    printf("Gravados: %zu registros\n", gravados);

    // Ler só o registro 2, sem passar pelos outros
    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fseek(arq, 0, SEEK_END);              // vai para o fim...
    printf("Arquivo: %ld bytes\n", ftell(arq)); // ...e pergunta a posição

    Produto p;
    fseek(arq, 2 * sizeof(Produto), SEEK_SET); // byte 64: começo do registro 2
    if (fread(&p, sizeof(Produto), 1, arq) == 1) {
        printf("Registro 2: %s, %d un., R$ %.2f\n", p.nome, p.qtd, p.preco);
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
// Saída:
// Cada registro: 32 bytes
// Gravados: 3 registros
// Arquivo: 96 bytes
// Registro 2: Café, 4 un., R$ 18.50
