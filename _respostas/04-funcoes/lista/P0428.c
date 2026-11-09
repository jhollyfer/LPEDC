// Lista · Módulo 04 · Funções e modularização
// Exercício P0428 · ★★★ · O cheque por extenso

#include <stdio.h>

void unidade(int n) {
    switch (n) {
        case 1: printf("um"); break;
        case 2: printf("dois"); break;
        case 3: printf("três"); break;
        case 4: printf("quatro"); break;
        case 5: printf("cinco"); break;
        case 6: printf("seis"); break;
        case 7: printf("sete"); break;
        case 8: printf("oito"); break;
        default: printf("nove"); break;
    }
}

void dez_a_dezenove(int n) {
    switch (n) {
        case 10: printf("dez"); break;
        case 11: printf("onze"); break;
        case 12: printf("doze"); break;
        case 13: printf("treze"); break;
        case 14: printf("quatorze"); break;
        case 15: printf("quinze"); break;
        case 16: printf("dezesseis"); break;
        case 17: printf("dezessete"); break;
        case 18: printf("dezoito"); break;
        default: printf("dezenove"); break;
    }
}

void dezena(int d) {
    switch (d) {
        case 2: printf("vinte"); break;
        case 3: printf("trinta"); break;
        case 4: printf("quarenta"); break;
        case 5: printf("cinquenta"); break;
        case 6: printf("sessenta"); break;
        case 7: printf("setenta"); break;
        case 8: printf("oitenta"); break;
        default: printf("noventa"); break;
    }
}

void centena(int c) {
    switch (c) {
        case 1: printf("cento"); break;
        case 2: printf("duzentos"); break;
        case 3: printf("trezentos"); break;
        case 4: printf("quatrocentos"); break;
        case 5: printf("quinhentos"); break;
        case 6: printf("seiscentos"); break;
        case 7: printf("setecentos"); break;
        case 8: printf("oitocentos"); break;
        default: printf("novecentos"); break;
    }
}

void ate_99(int n) { // 1 a 99
    if (n < 10) {
        unidade(n);
    } else if (n < 20) {
        dez_a_dezenove(n);
    } else {
        dezena(n / 10);
        if (n % 10 > 0) {
            printf(" e ");
            unidade(n % 10);
        }
    }
}

void ate_999(int n) { // 1 a 999
    if (n == 100) {
        printf("cem");
        return;
    }
    if (n >= 100) {
        centena(n / 100);
        if (n % 100 > 0) {
            printf(" e ");
        }
    }
    if (n % 100 > 0) {
        ate_99(n % 100);
    }
}

void extenso(int n) { // 0 a 999999
    if (n == 0) {
        printf("zero");
        return;
    }
    int milhar = n / 1000, resto = n % 1000;
    if (milhar == 1) {
        printf("mil");
    } else if (milhar > 1) {
        ate_999(milhar);
        printf(" mil");
    }
    if (milhar > 0 && resto > 0) {
        printf("%s", resto < 100 || resto % 100 == 0 ? " e " : " ");
    }
    if (resto > 0) {
        ate_999(resto);
    }
}

void testar(int n) {
    printf("%d: ", n);
    extenso(n);
    printf("\n");
}

int main(void) {
    testar(0);
    testar(15);
    testar(100);
    testar(101);
    testar(1000);
    testar(2026);
    testar(2100);
    testar(2150);
    testar(123456);
    testar(999999);
    return 0;
}
