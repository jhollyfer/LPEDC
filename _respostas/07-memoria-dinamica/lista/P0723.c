// Lista · Módulo 07 · Memória dinâmica
// Exercício P0723 · ★★★ · Quebrar o texto em linhas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void liberar(char **linhas, int n) {
    for (int i = 0; i < n; i++) {
        free(linhas[i]);
    }
    free(linhas);
}

// tamanho da próxima palavra a partir de p
size_t palavra(const char *p) {
    size_t k = 0;
    while (p[k] != '\0' && p[k] != ' ') {
        k++;
    }
    return k;
}

char **quebrar(const char *texto, int largura, int *n_linhas) {
    char **linhas = NULL;
    int n = 0;
    const char *p = texto;
    while (*p != '\0') {
        while (*p == ' ') {
            p++;
        }
        if (*p == '\0') {
            break;
        }
        size_t tam = palavra(p);
        if (tam > (size_t) largura) {
            tam = largura; // palavra grande demais: corta
        } else {
            // junta mais palavras enquanto couber "espaço + palavra"
            while (p[tam] == ' ') {
                size_t prox = palavra(p + tam + 1);
                if (prox == 0 || tam + 1 + prox > (size_t) largura) {
                    break;
                }
                tam += 1 + prox;
            }
        }
        char *linha = malloc(tam + 1);
        char **novo = realloc(linhas, (n + 1) * sizeof *novo);
        if (linha == NULL || novo == NULL) {
            free(linha);
            liberar(novo != NULL ? novo : linhas, n);
            return NULL;
        }
        linhas = novo;
        memcpy(linha, p, tam);
        linha[tam] = '\0';
        linhas[n++] = linha;
        p += tam;
    }
    *n_linhas = n;
    return linhas;
}

int main(void) {
    const char *msg = "Pagamento aprovado no credito em 3x sem juros. "
                      "Obrigado pela preferencia, volte sempre!";
    int n = 0;

    char **linhas = quebrar(msg, 16, &n);
    if (linhas == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("|%-16s| %2zu\n", linhas[i], strlen(linhas[i]));
    }
    printf("%d linhas\n", n);
    liberar(linhas, n);
    return 0;
}
