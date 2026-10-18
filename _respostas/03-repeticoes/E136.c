// 0023 · Break e continue
// Exercício E136 · ★★☆
//
// Resposta: o break do "case 9" sai só do switch (o mais interno), não do for.
// Conserto: depois do switch, "if (codigo == 9) break;". Corrigido, mostra
// normal, alerta, "sensor desligou" e "Leituras: 3".

#include <stdio.h>

int main(void) {
    int codigo;
    int leituras = 0;

    for (int i = 1; i <= 5; i++) {
        if (scanf("%d", &codigo) != 1) {
            break;
        }
        leituras++;
        switch (codigo) {
        case 1:
            printf("normal\n");
            break;
        case 2:
            printf("alerta\n");
            break;
        case 9:
            printf("sensor desligou\n");
            break; // este break só sai do switch
        default:
            printf("código desconhecido\n");
        }
        if (codigo == 9) {
            break; // este sai do for
        }
    }
    printf("Leituras: %d\n", leituras);
    return 0;
}
