// Lista · Módulo 15 · Tabelas hash
// Exercício P1520 · ★★☆ · O estacionamento pela placa

#include <stdio.h>
#include <string.h>

#define M 11

typedef struct {
    char placa[8]; // "" = vaga livre na tabela
    int entrada;   // hora cheia
} Carro;

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

void entra(Carro t[], const char *placa, int hora) {
    int pos = (int)(djb2(placa) % M);
    while (t[pos].placa[0] != '\0') {
        pos = (pos + 1) % M;
    }
    snprintf(t[pos].placa, sizeof t[pos].placa, "%s", placa);
    t[pos].entrada = hora;
}

const Carro *procura(const Carro t[], const char *placa) {
    int pos = (int)(djb2(placa) % M);
    for (int i = 0; i < M && t[pos].placa[0] != '\0'; i++) {
        if (strcmp(t[pos].placa, placa) == 0) {
            return &t[pos];
        }
        pos = (pos + 1) % M;
    }
    return NULL;
}

int main(void) {
    Carro t[M] = {{"", 0}};
    entra(t, "QWE1A23", 8);
    entra(t, "RTY4B56", 9);
    entra(t, "JKL7C89", 9);
    entra(t, "ZXC0D12", 11);
    entra(t, "MNB3E45", 13);

    const char *saem[] = {"JKL7C89", "MNB3E45", "AAA0A00"};
    int hora_saida = 15;
    for (int i = 0; i < 3; i++) {
        const Carro *c = procura(t, saem[i]);
        if (c == NULL) {
            printf("%s: não entrou aqui\n", saem[i]);
        } else {
            int horas = hora_saida - c->entrada;
            printf("%s: entrou às %dh, ficou %dh, paga R$ %d,00\n", saem[i], c->entrada, horas, 5 * horas);
        }
    }
    return 0;
}
