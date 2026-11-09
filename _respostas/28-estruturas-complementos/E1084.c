// 0181 · Juntando tudo
// Exercício E1084 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include "agenda.h"

// troca a consulta do paciente para o horário novo, se ele estiver livre.
// O horário antigo é desmarcado (e pode ir para quem está na espera).
bool remarca(Agenda *a, int cpf, int novo) {
    int antigo = ag_horario_de(a, cpf);
    int x;
    if (antigo < 0 || ag_intervalo(a, novo, novo, &x, 1) == 1) {
        return false; // sem consulta, ou o horário novo está ocupado
    }
    int quem = ag_cancela(a, antigo);
    if (quem > 0) {
        printf("  %s assume as %02d:%02d\n", ag_nome(a, quem), antigo / 100, antigo % 100);
    }
    return ag_marca(a, novo, cpf);
}

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    ag_cadastra(a, 601000001, "Zeca");
    ag_cadastra(a, 601000002, "Alice");
    ag_cadastra(a, 601000003, "Breno");
    ag_marca(a, 900, 601000001);
    ag_marca(a, 1000, 601000002);
    ag_espera(a, 601000003);

    printf("Zeca para 10:00: %s\n", remarca(a, 601000001, 1000) ? "ok" : "recusado");
    printf("Zeca para 11:00:\n");
    printf("  %s\n", remarca(a, 601000001, 1100) ? "ok" : "recusado");
    ag_mostra(a);
    ag_mostra_espera(a);
    ag_libera(a);
    return 0;
}
