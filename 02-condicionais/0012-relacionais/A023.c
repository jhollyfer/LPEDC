// A023 · A nota no limite e a contagem sem if

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double nota_ana = 7.0; // bem no limite da média
    double nota_bia = 6.9;
    double nota_caio = 8.5;

    // > e >= só discordam num caso: quando os dois lados são iguais
    printf("7.0 >  7? %d\n", nota_ana > 7);
    printf("7.0 >= 7? %d\n", nota_ana >= 7);

    bool ana = nota_ana >= 7;
    bool bia = nota_bia >= 7;
    bool caio = nota_caio >= 7;

    // cada bool vale 0 ou 1: somar conta quantos passaram
    int aprovados = ana + bia + caio;
    printf("Aprovados: %d de 3\n", aprovados);
    printf("Todos passaram? %d\n", aprovados == 3);
    printf("Alguém ficou de fora? %d\n", aprovados != 3);
    return 0;
}
// Saída:
// 7.0 >  7? 0
// 7.0 >= 7? 1
// Aprovados: 2 de 3
// Todos passaram? 0
// Alguém ficou de fora? 1
