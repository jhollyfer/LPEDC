// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2717 · ★★☆ · Boletim em arquivo binário

#include <stdio.h>

typedef struct {
    char nome[16];
    float nota;
} Aluno;

int main(void) {
    Aluno turma[] = {{"Ana", 8.5f}, {"Bruno", 6.0f}, {"Caio", 7.0f}, {"Duda", 4.5f}};

    FILE *f = fopen("p2717_boletim.bin", "wb");
    if (f == NULL) {
        printf("não consegui criar o arquivo\n");
        return 1;
    }
    size_t gravados = fwrite(turma, sizeof turma[0], 4, f);
    fclose(f);
    printf("gravados %zu registros (%zu bytes)\n", gravados, gravados * sizeof(Aluno));

    f = fopen("p2717_boletim.bin", "rb");
    if (f == NULL) {
        printf("não consegui abrir o arquivo\n");
        return 1;
    }
    Aluno a;
    while (fread(&a, sizeof a, 1, f) == 1) {
        if (a.nota >= 7.0f) {
            printf("aprovado: %s (%.1f)\n", a.nome, a.nota);
        }
    }
    fclose(f);
    remove("p2717_boletim.bin");
    return 0;
}
