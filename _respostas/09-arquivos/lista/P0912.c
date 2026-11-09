// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0912 · ★★☆ · Tirando um produto do catálogo

#include <stdio.h>

typedef struct {
    int codigo;
    char nome[20];
    double preco;
} Produto;

int remove_produto(const char *origem, const char *destino, int codigo) {
    FILE *ent = fopen(origem, "rb");
    if (ent == NULL) {
        return -1;
    }
    FILE *sai = fopen(destino, "wb");
    if (sai == NULL) {
        fclose(ent);
        return -1;
    }
    Produto p;
    int copiados = 0;
    while (fread(&p, sizeof p, 1, ent) == 1) {
        if (p.codigo != codigo) {
            fwrite(&p, sizeof p, 1, sai);
            copiados++;
        }
    }
    fclose(ent);
    fclose(sai);
    return copiados;
}

int main(void) {
    const char *origem = "/tmp/p0912_catalogo.bin";
    const char *destino = "/tmp/p0912_novo.bin";
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

    int n = remove_produto(origem, destino, 103);
    if (n < 0) {
        printf("Não consegui abrir os arquivos\n");
        remove(origem);
        return 1;
    }
    printf("Depois: %d produtos\n", n);

    arq = fopen(destino, "rb");
    if (arq != NULL) {
        Produto p;
        while (fread(&p, sizeof p, 1, arq) == 1) {
            printf("%d %-12s R$ %6.2f\n", p.codigo, p.nome, p.preco);
        }
        fclose(arq);
    }
    remove(origem);
    remove(destino);
    return 0;
}
