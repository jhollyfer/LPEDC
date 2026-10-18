// A124 · Free, NULL e valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int noites = 3;
    int *diarias = malloc(noites * sizeof *diarias); // reserva do hotel
    if (diarias == NULL) {
        return 1;
    }
    diarias[0] = 220;
    diarias[1] = 220;
    diarias[2] = 310; // sábado é mais caro

    int total = 0;
    for (int i = 0; i < noites; i++) {
        total += diarias[i];
    }
    printf("Reserva: %d noites, R$ %d\n", noites, total);

    // o hóspede cancelou
    free(diarias);
    diarias = NULL; // hábito: o ponteiro solto vira um ponteiro vazio

    free(diarias); // por engano, de novo: free(NULL) não faz nada
    if (diarias == NULL) { // dá para perguntar antes de usar
        printf("Reserva cancelada: nada a mostrar\n");
    }
    return 0;
}
// Saída:
// Reserva: 3 noites, R$ 750
// Reserva cancelada: nada a mostrar
//
// Rode também com o valgrind: ~/LPEDC/rodar --valgrind 07-memoria-dinamica/0062-erros-de-memoria/A124.c
// O fim da saída mostra o balanço do heap (o número entre == muda):
//   ==4242== HEAP SUMMARY:
//   ==4242==     in use at exit: 0 bytes in 0 blocks
//   ==4242==   total heap usage: 2 allocs, 2 frees, 4,108 bytes allocated
//   ==4242== All heap blocks were freed -- no leaks are possible
//   ==4242== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// São 2 allocs: o seu e o buffer que o printf pediu para ele mesmo.
