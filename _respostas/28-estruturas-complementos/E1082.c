// 0181 · Juntando tudo
// Exercício E1082 · ★☆☆

#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    int cpfs[] = {401000001, 401000002, 401000003, 401000004};
    const char *nomes[] = {"Vera", "Wagner", "Xenia", "Yuri"};
    int horarios[] = {1500, 800, 1045, 1330};
    for (int i = 0; i < 4; i++) {
        ag_cadastra(a, cpfs[i], nomes[i]);
        ag_marca(a, horarios[i], cpfs[i]);
    }
    int chegadas[] = {700, 801, 1045, 1400, 1600};
    for (int i = 0; i < 5; i++) {
        int h = ag_proximo(a, chegadas[i]);
        printf("às %02d:%02d, a próxima: ", chegadas[i] / 100, chegadas[i] % 100);
        if (h < 0) {
            printf("nenhuma\n");
        } else {
            printf("%02d:%02d\n", h / 100, h % 100);
        }
    }
    ag_libera(a);
    return 0;
}
