// 0181 · Juntando tudo
// Exercício E1081 · ★☆☆

#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    ag_cadastra(a, 301000001, "Rosa");
    ag_cadastra(a, 301000002, "Saulo");
    ag_cadastra(a, 301000003, "Tania");
    ag_cadastra(a, 301000004, "Ugo");
    ag_marca(a, 1100, 301000001);
    ag_marca(a, 830, 301000002);
    ag_marca(a, 1315, 301000003);
    if (!ag_marca(a, 830, 301000004)) {
        printf("Ugo: 08:30 ocupado\n");
    }
    if (!ag_marca(a, 900, 301000005)) {
        printf("CPF 301000005: não cadastrado\n");
    }
    ag_mostra(a);
    ag_libera(a);
    return 0;
}
