// 0049 · Ponteiro para ponteiro
// Exercício E291 · ★★☆

#include <stdio.h>
#include <ctype.h>

void pula_ate_digito(const char **s) {
    while (**s != '\0' && !isdigit((unsigned char)**s)) {
        (*s)++;
    }
}

int main(void) {
    const char *msg = "Pedido numero 4521 confirmado";
    const char *outra = "Sem numero";

    pula_ate_digito(&msg);
    printf("%s\n", msg);
    pula_ate_digito(&outra);
    printf("%s\n", outra);
    return 0;
}
