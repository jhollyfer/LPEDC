// A045 · Poltronas da excursão: continue com o passo no topo

#include <stdio.h>

int main(void) {
    int alunos = 10;    // a excursão leva 10 alunos
    int poltrona = 0;   // última poltrona olhada
    int reservadas = 0;

    // a sala tem 20 poltronas; as de número múltiplo de 5 estão quebradas
    printf("Poltronas reservadas:");
    while (poltrona < 20) {
        poltrona++;               // o passo vem PRIMEIRO: o continue não o pula
        if (poltrona % 5 == 0) {
            continue;             // quebrada: volta para a pergunta do while
        }
        printf(" %d", poltrona);
        reservadas++;
        if (reservadas == alunos) {
            break;                // todo mundo sentado: para de procurar
        }
    }
    printf("\n");

    printf("Reservadas: %d | Última poltrona olhada: %d\n", reservadas, poltrona);
    return 0;
}
// Saída:
// Poltronas reservadas: 1 2 3 4 6 7 8 9 11 12
// Reservadas: 10 | Última poltrona olhada: 12
