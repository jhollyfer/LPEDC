// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0927 · ★★★ · O cadastro da clínica veterinária

#include <stdio.h>

typedef struct {
    char nome[12];
    int idade;
    double peso;
} Pet;

const char *CAMINHO = "/tmp/p0927_pets.bin";

void cadastra(const Pet *p) {
    FILE *arq = fopen(CAMINHO, "ab"); // acrescenta no fim, sem apagar
    if (arq == NULL) {
        perror(CAMINHO);
        return;
    }
    fwrite(p, sizeof *p, 1, arq); // o tamanho do Pet, não do ponteiro
    fclose(arq);
}

void lista(void) {
    FILE *arq = fopen(CAMINHO, "rb");
    if (arq == NULL) {
        perror(CAMINHO);
        return;
    }
    Pet p;
    while (fread(&p, sizeof p, 1, arq) == 1) {
        printf("%s: %d anos, %.1f kg\n", p.nome, p.idade, p.peso);
    }
    fclose(arq);
}

int le_meio(Pet *p) {
    FILE *arq = fopen(CAMINHO, "rb");
    if (arq == NULL) {
        return 0;
    }
    fseek(arq, 0, SEEK_END);
    long n = ftell(arq) / (long) sizeof(Pet);
    fseek(arq, (n / 2) * (long) sizeof(Pet), SEEK_SET); // conta do começo
    int ok = fread(p, sizeof *p, 1, arq) == 1;
    fclose(arq);
    return ok;
}

int main(void) {
    Pet pets[3] = {{"Rex", 3, 12.5}, {"Mimi", 5, 4.2}, {"Thor", 2, 30.0}};

    remove(CAMINHO); // começa do zero
    for (int i = 0; i < 3; i++) {
        cadastra(&pets[i]);
    }
    lista();
    Pet meio;
    if (le_meio(&meio)) {
        printf("Do meio: %s\n", meio.nome);
    } else {
        printf("Não achei o pet do meio\n");
    }
    remove(CAMINHO);
    return 0;
}
