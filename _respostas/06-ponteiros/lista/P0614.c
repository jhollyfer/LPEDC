// Lista · Módulo 06 · Ponteiros
// Exercício P0614 · ★★☆ · A extensão do arquivo

#include <stdio.h>

const char *extensao(const char *nome) {
    const char *ultimo = NULL;
    const char *p = nome;
    while (*p != '\0') {
        if (*p == '.') {
            ultimo = p;
        }
        p++;
    }
    if (ultimo == NULL || ultimo == nome) {
        return p; // o '\0' do fim: string vazia
    }
    return ultimo + 1;
}

int main(void) {
    const char *arquivos[5] = {"relatorio.final.pdf", "foto.JPG", "LEIAME",
                               ".bashrc", "backup.tar.gz"};

    for (int i = 0; i < 5; i++) {
        const char *ext = extensao(arquivos[i]);
        printf("%-20s [%s] posição %d\n", arquivos[i], ext, (int) (ext - arquivos[i]));
    }
    return 0;
}
