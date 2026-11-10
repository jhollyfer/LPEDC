// A362 · Encaixes ao longo do dia

#include <stdio.h>
#include "0181-agenda.h"

void cancela(Agenda *a, int horario) {
    int quem = ag_cancela(a, horario);
    printf("Cancela %02d:%02d: ", horario / 100, horario % 100);
    if (quem > 0) {
        printf("%s assume o horário\n", ag_nome(a, quem));
    } else if (quem == 0) {
        printf("ninguém na espera, o horário fica vago\n");
    } else {
        printf("não havia consulta\n");
    }
}

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    int cpfs[] = {210000001, 210000002, 210000003, 210000004, 210000005, 210000006};
    const char *nomes[] = {"Gil", "Ines", "Joel", "Kátia", "Luan", "Mara"};
    for (int i = 0; i < 6; i++) {
        ag_cadastra(a, cpfs[i], nomes[i]);
    }
    ag_marca(a, 1400, cpfs[0]);
    ag_marca(a, 1430, cpfs[1]);
    ag_marca(a, 1500, cpfs[2]);
    ag_espera(a, cpfs[3]);
    ag_espera(a, cpfs[4]);
    ag_mostra_espera(a);

    cancela(a, 1430); // Kátia, a primeira da fila, assume
    cancela(a, 1400); // Luan assume
    cancela(a, 1500); // fila vazia: vago
    cancela(a, 1600); // nunca houve consulta
    ag_mostra(a);

    // a Mara liga e pega o horário vago das 15:00; a Kátia não pode marcar outro
    printf("Mara marca 15:00: %s\n", ag_marca(a, 1500, cpfs[5]) ? "ok" : "recusado");
    int h = ag_horario_de(a, cpfs[3]);
    printf("Kátia marca 16:00: %s (já tem as %02d:%02d)\n",
           ag_marca(a, 1600, cpfs[3]) ? "ok" : "recusado", h / 100, h % 100);
    ag_mostra(a);
    ag_mostra_espera(a);
    ag_libera(a);
    return 0;
}
// Saída:
// Espera: Kátia Luan
// Cancela 14:30: Kátia assume o horário
// Cancela 14:00: Luan assume o horário
// Cancela 15:00: ninguém na espera, o horário fica vago
// Cancela 16:00: não havia consulta
// 14:00  Luan
// 14:30  Kátia
// 15:00  (vago)
// Mara marca 15:00: ok
// Kátia marca 16:00: recusado (já tem as 14:30)
// 14:00  Luan
// 14:30  Kátia
// 15:00  Mara
// Espera: (ninguém)
