// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0916 · ★★☆ · A linha mais comprida do poema

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *caminho = "/tmp/p0916_poema.txt";
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Choveu em Manaus\no rio subiu devagar\ne a balsa atrasou\nfim\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char linha[100], maior[100] = "", menor[100] = "";
    size_t t_maior = 0, t_menor = 0;
    int n = 0, n_maior = 0, n_menor = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        size_t t = strlen(linha);
        n++;
        if (n == 1 || t > t_maior) {
            t_maior = t;
            n_maior = n;
            strcpy(maior, linha);
        }
        if (n == 1 || t < t_menor) {
            t_menor = t;
            n_menor = n;
            strcpy(menor, linha);
        }
    }
    fclose(arq);
    remove(caminho);

    if (n == 0) {
        printf("Arquivo vazio\n");
        return 1;
    }
    printf("Mais comprida: linha %d (%zu caracteres): %s\n", n_maior, t_maior, maior);
    printf("Mais curta: linha %d (%zu caracteres): %s\n", n_menor, t_menor, menor);
    return 0;
}
