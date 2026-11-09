// Lista · Módulo 15 · Tabelas hash
// Exercício P1520 · ★★☆ · O estacionamento pela placa
//
// O estacionamento cobra R$ 5,00 por hora e acha o carro pela placa com uma
// tabela hash de structs: m = 11, endereçamento aberto, sondagem linear,
// balde = djb2(placa) % 11. Placa vazia ("") marca posição livre.
//
//   typedef struct { char placa[8]; int entrada; } Carro;
//
// Escreva entra(t, placa, hora) e const Carro *procura(t, placa). Entram
// QWE1A23 às 8h, RTY4B56 às 9h, JKL7C89 às 9h, ZXC0D12 às 11h e MNB3E45 às
// 13h. Às 15h, saem JKL7C89, MNB3E45 e AAA0A00 (que nunca entrou).
//
//   Saída esperada:
//   JKL7C89: entrou às 9h, ficou 6h, paga R$ 30,00
//   MNB3E45: entrou às 13h, ficou 2h, paga R$ 10,00
//   AAA0A00: não entrou aqui
//
// Dicas:
// 1. Inicialize com Carro t[M] = {{"", 0}}; e teste vaga livre com
//    t[pos].placa[0] == '\0'.
// 2. Compare placas com strcmp, nunca com ==.
// 3. Use o djb2 com unsigned long long e copie a placa com snprintf.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define M 11

typedef struct {
    char placa[8];
    int entrada;
} Carro;

int main(void) {

    return 0;
}
