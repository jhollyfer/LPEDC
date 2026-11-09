// Lista · Módulo 03 · Laços
// Exercício P0323 · ★★★ · Validação de CPF com laço

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    long long cpf;

    printf("CPF (11 dígitos): ");
    if (scanf("%lld", &cpf) != 1 || cpf < 0 || cpf > 99999999999LL) {
        printf("Entrada inválida\n");
        return 1;
    }

    long long potencia = 10000000000LL; // 10 elevado a 10
    int primeiro = (int)(cpf / potencia % 10);
    bool iguais = true;
    int soma1 = 0, soma2 = 0, dv1_lido = 0, dv2_lido = 0;

    for (int p = 1; p <= 11; p++) {
        int d = (int)(cpf / potencia % 10);
        potencia /= 10;
        if (d != primeiro) {
            iguais = false;
        }
        if (p <= 9) {
            soma1 += d * (11 - p);
        }
        if (p <= 10) {
            soma2 += d * (12 - p);
        }
        if (p == 10) {
            dv1_lido = d;
        }
        if (p == 11) {
            dv2_lido = d;
        }
    }

    int r1 = soma1 % 11;
    int dv1 = r1 < 2 ? 0 : 11 - r1;
    int r2 = soma2 % 11;
    int dv2 = r2 < 2 ? 0 : 11 - r2;

    if (iguais) {
        printf("CPF inválido: dígitos todos iguais\n");
    } else if (dv1 != dv1_lido) {
        printf("CPF inválido: o 1º dígito deveria ser %d\n", dv1);
    } else if (dv2 != dv2_lido) {
        printf("CPF inválido: o 2º dígito deveria ser %d\n", dv2);
    } else {
        printf("CPF válido\n");
    }
    return 0;
}
