// A006 · Chamando as senhas (a seta que volta)

#include <stdio.h>

// No fluxograma, este laço é uma seta que volta para o losango "senha <= 3?".
int main(void) {
    int senha = 1;

    while (senha <= 3) {
        printf("Senha %d, guichê 2\n", senha);
        senha = senha + 1;
    }
    printf("Fim do atendimento\n");
    return 0;
}
// Saída:
// Senha 1, guichê 2
// Senha 2, guichê 2
// Senha 3, guichê 2
// Fim do atendimento
