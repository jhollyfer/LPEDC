// Lista · Módulo 08 · Tipos compostos
// Exercício P0825 · ★★★ · Conserte o painel de sensores
//
// O painel de uma estufa lê sensores de tipos diferentes, guardados numa
// union etiquetada, e cada sensor tem flags de estado em bits. O programa
// tem TRÊS erros de propósito: o gcc avisa de dois (leia os warnings) e o
// terceiro é de lógica (o programa roda, mas mostra coisa errada).
// Conserte os três. O programa deve mostrar:
//
//   Saída esperada:
//   Estufa 1: 38.5 graus
//     ALERTA
//   Estufa 2: 81% de umidade
//   Depósito: porta aberta
//     bateria fraca
//
// Dicas:
// 1. == tem precedência MAIOR que &: flags & ALERTA == ALERTA é lido como
//    flags & (ALERTA == ALERTA), ou seja, flags & 1. Use parênteses.
// 2. Um case sem break "cai" no próximo: o sensor de umidade mostra duas
//    linhas.
// 3. A etiqueta tem que bater com o campo da union que foi preenchido: ler
//    .graus de um sensor que guardou .porcento interpreta os bytes errados.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

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
    case PORTA:
        printf("porta %s\n", s->leitura.aberta ? "aberta" : "fechada");
        break;
    }
    if (s->flags & ALERTA == ALERTA) {
        printf("  ALERTA\n");
    }
    if (s->flags & BATERIA_FRACA) {
        printf("  bateria fraca\n");
    }
}

int main(void) {
    Sensor s[3] = {
        {"Estufa 1", TEMPERATURA, LIGADO | ALERTA, {.graus = 38.5}},
        {"Estufa 2", TEMPERATURA, LIGADO, {.porcento = 81}},
        {"Depósito", PORTA, LIGADO | BATERIA_FRACA, {.aberta = 1}},
    };

    for (int i = 0; i < 3; i++) {
        mostrar(&s[i]);
    }
    return 0;
}
