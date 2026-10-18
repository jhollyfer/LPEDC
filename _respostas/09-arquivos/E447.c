// 0075 · Juntando tudo
// Exercício E447 · ★★☆

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[8];
    char telefone[16];
} Contato;

const char *CAMINHO = "/tmp/agenda.bin";

int criar(void) {
    FILE *arq = fopen(CAMINHO, "wb");
    if (arq == NULL) {
        perror(CAMINHO);
        return 0;
    }
    int zero = 0;
    fwrite(&zero, sizeof zero, 1, arq); // agenda vazia: só o cabeçalho
    fclose(arq);
    return 1;
}

int adicionar(const char *nome, const char *telefone) {
    Contato c = {{0}, {0}};
    strncpy(c.nome, nome, sizeof c.nome - 1);
    strncpy(c.telefone, telefone, sizeof c.telefone - 1);

    FILE *arq = fopen(CAMINHO, "rb+");
    if (arq == NULL) {
        perror(CAMINHO);
        return 0;
    }
    int quantidade;
    if (fread(&quantidade, sizeof quantidade, 1, arq) != 1) {
        fclose(arq);
        return 0;
    }
    fseek(arq, (long) sizeof(int) + quantidade * (long) sizeof(Contato), SEEK_SET);
    if (fwrite(&c, sizeof c, 1, arq) != 1) {
        fclose(arq);
        return 0;
    }
    quantidade++;
    rewind(arq);
    size_t ok = fwrite(&quantidade, sizeof quantidade, 1, arq);
    fclose(arq);
    return ok == 1;
}

void listar(void) {
    FILE *arq = fopen(CAMINHO, "rb");
    if (arq == NULL) {
        perror(CAMINHO);
        return;
    }
    int quantidade;
    if (fread(&quantidade, sizeof quantidade, 1, arq) != 1) {
        fclose(arq);
        return;
    }
    fseek(arq, 0, SEEK_END);
    printf("%d contatos (arquivo de %ld bytes)\n", quantidade, ftell(arq));
    fseek(arq, sizeof(int), SEEK_SET);
    Contato c;
    for (int i = 0; i < quantidade && fread(&c, sizeof c, 1, arq) == 1; i++) {
        printf("%d. %-11s %s\n", i, c.nome, c.telefone);
    }
    fclose(arq);
}

int main(void) {
    if (!criar()) {
        return 1;
    }
    adicionar("Marta", "(11) 98888-1234");
    adicionar("Joel", "(21) 97777-4321");
    adicionar("Iara", "(31) 96666-0000");
    listar();
    remove(CAMINHO);
    return 0;
}
