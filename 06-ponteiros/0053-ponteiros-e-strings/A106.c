// A106 · Os dias da feira

#include <stdio.h>

// conta os caracteres andando até o '\0': o mesmo que strlen faz
size_t comprimento(const char *s) {
    const char *p = s;
    while (*p != '\0') {
        p++;
    }
    return (size_t)(p - s); // distância entre o fim e o começo
}

int main(void) {
    // vetor de ponteiros: cada posição guarda o endereço de um literal
    const char *dias[] = {"segunda", "quarta", "sexta", "domingo"};
    // matriz: cada linha reserva espaço para o maior nome
    char tabela[4][10] = {"segunda", "quarta", "sexta", "domingo"};

    for (int i = 0; i < 4; i++) {
        printf("%-8s %zu letras\n", dias[i], comprimento(dias[i]));
    }
    printf("vetor de ponteiros: %zu bytes (só os endereços)\n", sizeof dias);
    printf("matriz de chars:    %zu bytes (4 linhas de 10)\n", sizeof tabela);
    printf("dias[2][0] = %c, tabela[2][0] = %c\n", dias[2][0], tabela[2][0]);
    return 0;
}
// Saída:
// segunda  7 letras
// quarta   6 letras
// sexta    5 letras
// domingo  7 letras
// vetor de ponteiros: 32 bytes (só os endereços)
// matriz de chars:    40 bytes (4 linhas de 10)
// dias[2][0] = s, tabela[2][0] = s
