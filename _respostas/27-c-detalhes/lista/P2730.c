// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2730 · ★★★ · O extrato do Pix

#include <stdio.h>
#include <string.h>

#define AGENDADO   (1u << 0)
#define CONTESTADO (1u << 1)
#define MAX_PIX 32

typedef enum { RECEBIDO, ENVIADO } Tipo;

typedef struct {
    int dia;
    Tipo tipo;
    long valor; // centavos
    unsigned flags;
} Pix;

int main(void) {
    FILE *f = fopen("p2730_pix.txt", "w");
    if (f == NULL) {
        printf("não consegui criar o arquivo\n");
        return 1;
    }
    fputs("1;R;250000;0\n1;E;12000;0\n2;E;8990;2\n2;E;4500;0\n3;R;3000;1\n3;E;30000;0\n", f);
    fclose(f);

    f = fopen("p2730_pix.txt", "r");
    if (f == NULL) {
        printf("não consegui abrir o arquivo\n");
        return 1;
    }
    Pix v[MAX_PIX];
    int n = 0, dias = 0;
    int dia;
    char letra;
    long valor;
    unsigned flags;
    while (n < MAX_PIX && fscanf(f, "%d;%c;%ld;%u", &dia, &letra, &valor, &flags) == 4) {
        switch (letra) {
        case 'R':
            v[n].tipo = RECEBIDO;
            break;
        case 'E':
            v[n].tipo = ENVIADO;
            break;
        default:
            continue; // linha com tipo desconhecido
        }
        if (dia < 1 || dia > 31) {
            continue;
        }
        v[n].dia = dia;
        v[n].valor = valor;
        v[n].flags = flags;
        if (dia > dias) {
            dias = dia;
        }
        n++;
    }
    fclose(f);
    remove("p2730_pix.txt");
    if (dias == 0) {
        printf("extrato vazio\n");
        return 0;
    }

    long saldo_dia[dias], gasto_dia[dias]; // VLA: o tamanho veio do arquivo
    memset(saldo_dia, 0, sizeof saldo_dia);
    memset(gasto_dia, 0, sizeof gasto_dia);
    long contestado = 0;
    int qtd_contestadas = 0;
    for (int i = 0; i < n; i++) {
        int d = v[i].dia - 1;
        if (v[i].tipo == RECEBIDO) {
            saldo_dia[d] += v[i].valor;
        } else {
            saldo_dia[d] -= v[i].valor;
            gasto_dia[d] += v[i].valor;
        }
        if (v[i].flags & CONTESTADO) {
            contestado += v[i].valor;
            qtd_contestadas++;
        }
    }

    long final = 0;
    int pior = 0;
    for (int d = 0; d < dias; d++) {
        printf("dia %d: %+.2f\n", d + 1, saldo_dia[d] / 100.0);
        final += saldo_dia[d];
        if (gasto_dia[d] > gasto_dia[pior]) {
            pior = d;
        }
    }
    printf("saldo final: R$ %.2f\n", final / 100.0);
    printf("maior gasto: dia %d (R$ %.2f)\n", pior + 1, gasto_dia[pior] / 100.0);
    printf("contestadas: %d (R$ %.2f)\n", qtd_contestadas, contestado / 100.0);
    return 0;
}
