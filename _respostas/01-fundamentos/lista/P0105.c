// Lista · Módulo 01 · Fundamentos de C
// Exercício P0105 · ★☆☆ · O painel de senhas do banco

#include <stdio.h>

int main(void) {
    int senha = 41;

    int chamada = senha++; // chamada = 41, senha vira 42
    int proxima = ++senha; // senha vira 43, proxima = 43

    printf("Chamada: %d\n", chamada);
    printf("Próxima: %d\n", proxima);
    printf("Senha no painel: %d\n", senha);
    return 0;
}
