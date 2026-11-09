// 0171 · Com sinal e sem sinal
// Exercício E1024 · ★★☆

#include <stdio.h>
#include <string.h>

const char *mais_longo(const char *a, const char *b) {
    if (strlen(a) > strlen(b)) { // compara direto, sem subtrair
        return a;
    }
    return b;
}

size_t restantes(const char *msg, size_t limite) {
    size_t usado = strlen(msg);
    if (usado >= limite) { // testa antes de subtrair
        return 0;
    }
    return limite - usado;
}

int main(void) {
    printf("mais longo: %s\n", mais_longo("Ana", "Bernardo"));
    printf("mais longo: %s\n", mais_longo("Bernardo", "Ana"));
    printf("restam %zu caracteres\n", restantes("Oi, tudo bem?", 20));
    printf("restam %zu caracteres\n", restantes("Chego em 15 minutos, me espera", 20));
    return 0;
}
