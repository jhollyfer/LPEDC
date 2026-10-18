// 0124 · Juntando tudo
// Exercício E743 · ★★★
//
// Ache os bugs. Um colega reescreveu o counting sort pelo horário em vez de
// usar o pix_por_horario, para montar a linha do tempo do horário de
// almoço: pelo horário e, no mesmo segundo, pelo valor (por isso o
// pix_por_valor roda antes). A saída não tem nada em ordem de horário. São
// DOIS erros, os dois em ordena_horario. Conserte e rode.
//
//   Saída esperada:
//   #0000005 12:00:00 R$       8,70
//   #0000002 12:00:00 R$      12,50
//   #0000007 12:00:00 R$     150,00
//   #0000003 12:00:01 R$       9,90
//   #0000006 12:00:01 R$      25,00
//   #0000001 12:00:01 R$      50,00
//   #0000008 12:00:02 R$       6,40
//   #0000004 12:00:02 R$     300,00
//
// Dicas:
// 1. A saída que aparece está em ordem de VALOR: é como se ordena_horario
//    não tivesse feito nada. Onde fica o resultado do terceiro laço?
// 2. Consertado o primeiro erro, os horários entram em ordem, mas dentro de
//    cada segundo os valores saem do maior para o menor.
// 3. Resposta esperada: falta copiar aux de volta para v no fim (o
//    resultado ficava só no rascunho). E o terceiro laço anda da frente
//    para trás: com --c[...], o primeiro de cada segundo fica com a última
//    vaga, e a ordem de valor deixada pelo radix se inverte. O certo é
//    for (int i = n - 1; i >= 0; i--).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pix.h"

// counting sort estável pelo segundo do dia, escrito à mão
bool ordena_horario(Pix v[], Pix aux[], int n) {
    int *c = calloc(PIX_SEGUNDOS, sizeof(int));
    if (c == NULL) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        c[v[i].segundo]++;
    }
    for (int s = 1; s < PIX_SEGUNDOS; s++) {
        c[s] += c[s - 1];
    }
    for (int i = 0; i < n; i++) {
        aux[--c[v[i].segundo]] = v[i];
    }
    free(c);
    return true;
}

int main(void) {
    // Pix da virada do horário de almoço: vários no mesmo segundo
    Pix v[] = {
        {1, 43201, 5000}, {2, 43200, 1250}, {3, 43201, 990},  {4, 43202, 30000},
        {5, 43200, 870},  {6, 43201, 2500}, {7, 43200, 15000}, {8, 43202, 640},
    };
    Pix aux[8];
    int n = 8;

    pix_por_valor(v, aux, n);            // desempate: valor
    if (!ordena_horario(v, aux, n)) {    // chave principal: horário
        return 1;
    }
    for (int i = 0; i < n; i++) {
        pix_mostra(&v[i]);
    }
    return 0;
}
