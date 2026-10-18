// 0065 · Bits, máscaras e flags
// Exercício E390 · ★★★

#include <stdio.h>

#define DOM (1u << 0)
#define SEG (1u << 1)
#define TER (1u << 2)
#define QUA (1u << 3)
#define QUI (1u << 4)
#define SEX (1u << 5)
#define SAB (1u << 6)
#define TODOS 0x7Fu

void listar(const char *rotulo, unsigned dias) {
    const char *nomes[] = {"dom", "seg", "ter", "qua", "qui", "sex", "sáb"};
    int n = 0;
    printf("%s:", rotulo);
    for (int d = 0; d < 7; d++) {
        if (dias & (1u << d)) {
            printf(" %s", nomes[d]);
            n++;
        }
    }
    printf(" (%d dias)\n", n);
}

int main(void) {
    unsigned alarme = SEG | TER | QUA | QUI | SEX;
    unsigned academia = SEG | QUA | SEX;

    listar("alarme", alarme);
    listar("academia", academia);
    listar("alarme sem academia", alarme & ~academia);
    listar("sem alarme", ~alarme & TODOS);
    printf("academia em dia sem alarme? %s\n", (academia & ~alarme) != 0 ? "sim" : "não");
    return 0;
}
