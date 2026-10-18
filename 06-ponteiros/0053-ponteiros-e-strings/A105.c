// A105 · O crachá do evento

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char nome[] = "ana";          // vetor de 4 chars, CÓPIA do literal: pode mudar
    const char *apelido = "bia";  // ponteiro para o literal: só leitura

    // passa o nome para maiúsculas andando com um ponteiro até o '\0'
    for (char *p = nome; *p != '\0'; p++) {
        *p = (char)toupper((unsigned char)*p);
    }
    printf("Crachá: %s (%s)\n", nome, apelido);

    printf("sizeof nome = %zu, sizeof apelido = %zu\n", sizeof nome, sizeof apelido);

    apelido = "bibi";  // vale: o ponteiro passa a apontar para outro literal
    // nome = "joana"; // não compila: vetor não pode receber outro endereço
    printf("Novo apelido: %s\n", apelido);
    return 0;
}
// Saída:
// Crachá: ANA (bia)
// sizeof nome = 4, sizeof apelido = 8
// Novo apelido: bibi
