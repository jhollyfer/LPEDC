// 0068 · Arquivos binários
// Exercício E406 · ★★☆

#include <stdio.h>

typedef struct {
    int matricula;
    float nota;
} Nota;

long contar_registros(const char *caminho, size_t tamanho_registro) {
    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        return -1;
    }
    fseek(arq, 0, SEEK_END);
    long tamanho = ftell(arq);
    fclose(arq);
    return tamanho / (long) tamanho_registro;
}

int main(void) {
    const char *caminho = "/tmp/notas.bin";
    Nota notas[7] = {
        {101, 8.5f}, {102, 6.0f}, {103, 9.5f}, {104, 7.0f},
        {105, 5.5f}, {106, 10.0f}, {107, 7.5f},
    };

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(notas, sizeof(Nota), 7, arq);
    fclose(arq);

    printf("Tamanho do registro: %zu bytes\n", sizeof(Nota));
    printf("Registros em %s: %ld\n", caminho, contar_registros(caminho, sizeof(Nota)));
    printf("Registros em %s: %ld\n", "/tmp/nao-existe.bin",
           contar_registros("/tmp/nao-existe.bin", sizeof(Nota)));
    remove(caminho);
    return 0;
}
