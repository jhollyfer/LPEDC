// 0057 · Erros de memória
// Exercício E337 · ★☆☆
//
// O painel da rodoviária monta 4 avisos, um de cada vez. A saída está certa,
// mas o programa vaza memória. O erro está de propósito. Rode, leia o
// relatório do LeakSanitizer e responda: quantos bytes vazaram, em quantos
// blocos, e por quê? Depois conserte.
//
//   Saída esperada (antes e depois do conserto):
//   Aviso: Ônibus para Belém às 08h
//   Aviso: Ônibus para Macapá às 09h
//   Aviso: Ônibus para Santarém às 11h
//   Aviso: Ônibus para Manaus às 14h
//
// Dicas:
// 1. Conte quantos malloc e quantos free acontecem durante a execução.
// 2. A cada volta, msg recebe um endereço novo. O que acontece com o
//    anterior?
// 3. Resposta esperada: "Direct leak of 192 byte(s) in 3 object(s)": 4
//    malloc de 64 bytes e só 1 free (o do último bloco, depois do laço).
//    Conserto: free(msg) dentro do laço, depois do printf, e apagar o free
//    de fora.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *destinos[] = {"Belém", "Macapá", "Santarém", "Manaus"};
    const char *horas[] = {"08h", "09h", "11h", "14h"};
    char *msg = NULL;

    for (int i = 0; i < 4; i++) {
        msg = malloc(64);
        if (msg == NULL) {
            return 1;
        }
        strcpy(msg, "Ônibus para ");
        strcat(msg, destinos[i]);
        strcat(msg, " às ");
        strcat(msg, horas[i]);
        printf("Aviso: %s\n", msg);
    }
    free(msg);
    return 0;
}
