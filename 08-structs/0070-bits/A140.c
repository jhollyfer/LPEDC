// A140 · O chmod 755

#include <stdio.h>

// três grupos de 3 bits: dono (bits 8-6), grupo (5-3) e outros (2-0)
#define DONO   6
#define GRUPO  3
#define OUTROS 0

unsigned montar(unsigned dono, unsigned grupo, unsigned outros) {
    return (dono << DONO) | (grupo << GRUPO) | (outros << OUTROS);
}

void mostrar(unsigned modo) {
    const char letras[] = "rwx";
    printf("octal %03o, hexa 0x%03X, decimal %u\n", modo, modo, modo);
    printf("bits  ");
    for (int b = 8; b >= 0; b--) {
        printf("%u", (modo >> b) & 1u);
    }
    printf("\nls    ");
    for (int b = 8; b >= 0; b--) {
        // bit 8 é r, 7 é w, 6 é x, e o padrão se repete a cada 3
        printf("%c", ((modo >> b) & 1u) ? letras[(8 - b) % 3] : '-');
    }
    printf("\n");
}

int main(void) {
    unsigned modo = montar(7, 5, 5); // rwx r-x r-x
    mostrar(modo);

    unsigned outros = (modo >> OUTROS) & 7u; // máscara 111 pega 3 bits
    printf("outros podem escrever? %s\n", (outros & 2u) ? "sim" : "não");
    printf("é igual ao literal octal 0755? %s\n", modo == 0755 ? "sim" : "não");
    return 0;
}
// Saída:
// octal 755, hexa 0x1ED, decimal 493
// bits  111101101
// ls    rwxr-xr-x
// outros podem escrever? não
// é igual ao literal octal 0755? sim
