// Lista · Módulo 04 · Funções e modularização
// Exercício P0423 · ★★★ · Os verificadores do CNPJ

#include <stdbool.h>
#include <stdio.h>

int verificador(long long n) {
    int soma = 0, peso = 2;
    while (n > 0) {
        soma += (int)(n % 10) * peso;
        n /= 10;
        peso = peso == 9 ? 2 : peso + 1;
    }
    int r = soma % 11;
    return r < 2 ? 0 : 11 - r;
}

bool todos_iguais(long long cnpj) {
    int ultimo = (int)(cnpj % 10);
    for (int i = 0; i < 14; i++) {
        if (cnpj % 10 != ultimo) {
            return false;
        }
        cnpj /= 10;
    }
    return true;
}

bool cnpj_valido(long long cnpj) {
    if (todos_iguais(cnpj)) {
        return false;
    }
    long long base = cnpj / 100;
    int dv1 = verificador(base);
    int dv2 = verificador(base * 10 + dv1);
    return cnpj % 100 == dv1 * 10 + dv2;
}

int main(void) {
    long long a = 11222333000181LL;
    long long b = 11222333000182LL;
    long long c = 11111111111111LL;

    printf("%lld: %s\n", a, cnpj_valido(a) ? "válido" : "inválido");
    printf("%lld: %s\n", b, cnpj_valido(b) ? "válido" : "inválido");
    printf("%lld: %s\n", c, cnpj_valido(c) ? "válido" : "inválido");
    return 0;
}
