// Lista · Módulo 08 · Tipos compostos
// Exercício P0825 · ★★★ · Conserte o painel de sensores

#include <stdio.h>

typedef enum { TEMPERATURA, UMIDADE, PORTA } Tipo;

#define LIGADO 1u
#define ALERTA 2u
#define BATERIA_FRACA 4u

typedef struct {
    const char *nome;
    Tipo tipo;
    unsigned flags;
    union {
        double graus;
        int porcento;
        int aberta;
    } leitura;
} Sensor;

void mostrar(const Sensor *s) {
    printf("%s: ", s->nome);
    switch (s->tipo) {
    case TEMPERATURA:
        printf("%.1f graus\n", s->leitura.graus);
        break;
    case UMIDADE:
        printf("%d%% de umidade\n", s->leitura.porcento);
        break; // faltava: caía no case PORTA
    case PORTA:
        printf("porta %s\n", s->leitura.aberta ? "aberta" : "fechada");
        break;
    }
    if ((s->flags & ALERTA) == ALERTA) { // parênteses: == vem antes de &
        printf("  ALERTA\n");
    }
    if (s->flags & BATERIA_FRACA) {
        printf("  bateria fraca\n");
    }
}

int main(void) {
    Sensor s[3] = {
        {"Estufa 1", TEMPERATURA, LIGADO | ALERTA, {.graus = 38.5}},
        {"Estufa 2", UMIDADE, LIGADO, {.porcento = 81}}, // a etiqueta bate com o campo
        {"Depósito", PORTA, LIGADO | BATERIA_FRACA, {.aberta = 1}},
    };

    for (int i = 0; i < 3; i++) {
        mostrar(&s[i]);
    }
    return 0;
}
