// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0927 · ★★★ · O cadastro da clínica veterinária
//
// A clínica cadastra um pet por vez num arquivo binário e depois lista
// todos e mostra o pet do meio do arquivo. O programa abaixo compila sem
// aviso, mas não lista nada. Ele tem TRÊS erros de propósito, um em cada
// função de arquivo. Conserte os três para a saída ficar:
//
//   Saída esperada:
//   Rex: 3 anos, 12.5 kg
//   Mimi: 5 anos, 4.2 kg
//   Thor: 2 anos, 30.0 kg
//   Do meio: Mimi
//
// Dicas:
// 1. cadastra é chamada uma vez por pet. Com que modo de abertura cada
//    chamada preserva os pets anteriores?
// 2. Dentro de cadastra, p é um ponteiro. Quanto vale sizeof p? E quanto
//    vale sizeof *p?
// 3. O registro do meio é o n / 2, contado a partir de onde?
// 4. Resposta esperada: "wb" vira "ab"; sizeof p vira sizeof *p; e o fseek
//    de le_meio usa SEEK_SET em vez de SEEK_END. A saída fica igual à de
//    cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

typedef struct {
    char nome[12];
    int idade;
    double peso;
} Pet;

const char *CAMINHO = "/tmp/p0927_pets.bin";

void cadastra(const Pet *p) {
    FILE *arq = fopen(CAMINHO, "wb");
    if (arq == NULL) {
        perror(CAMINHO);
        return;
    }
    fwrite(p, sizeof p, 1, arq);
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
    fseek(arq, (n / 2) * (long) sizeof(Pet), SEEK_END);
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
