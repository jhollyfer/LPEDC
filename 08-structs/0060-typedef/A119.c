// A119 · O Pix da madrugada

#include <stdbool.h>
#include <stdio.h>

typedef double Reais; // Reais é só outro nome para double

typedef struct {      // struct sem nome, batizada de Pix pelo typedef
    char chave[40];
    Reais valor;
    int hora;         // 0 a 23
} Pix;

#define LIMITE_NOTURNO 1000.0

bool pix_permitido(Pix p) {
    bool noturno = p.hora >= 20 || p.hora < 6;
    return !(noturno && p.valor > LIMITE_NOTURNO);
}

int main(void) {
    Pix p = {"ana@email.com", 1500.00, 22}; // sem a palavra struct

    printf("Pix de R$ %.2f para %s às %dh\n", p.valor, p.chave, p.hora);
    if (pix_permitido(p)) {
        printf("Enviado!\n");
    } else {
        printf("Bloqueado: o limite noturno é R$ %.2f\n", LIMITE_NOTURNO);
    }
    return 0;
}
// Saída:
// Pix de R$ 1500.00 para ana@email.com às 22h
// Bloqueado: o limite noturno é R$ 1000.00
