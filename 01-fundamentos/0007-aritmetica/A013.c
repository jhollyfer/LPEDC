// A013 · O final da placa e o rodízio

#include <stdio.h>

// No rodízio de São Paulo, o dia em que o carro não roda depende do último
// dígito da placa (finais 7 e 8: quinta-feira). Quem separa dígitos é o par
// / e %, com divisores 10, 100, 1000...
int main(void) {
    int placa = 4827;                 // a parte numérica de ABC-4827

    int final = placa % 10;           // o resto por 10 é o último dígito: 7
    int sem_final = placa / 10;       // a divisão por 10 corta o último: 482
    int dois_primeiros = placa / 100; // 48
    int dois_ultimos = placa % 100;   // 27

    printf("Final da placa: %d\n", final);
    printf("Sem o final: %d\n", sem_final);
    printf("Metades: %d e %d\n", dois_primeiros, dois_ultimos);
    printf("Final %% 2 = %d (0 é par, 1 é ímpar)\n", final % 2);

    // a regra que amarra os dois: (a / b) * b + a % b devolve o a
    printf("%d * 100 + %d = %d\n", dois_primeiros, dois_ultimos,
           dois_primeiros * 100 + dois_ultimos);

    // o dígito do meio: corta pela direita com /, isola com %
    printf("Dígito das centenas: %d\n", placa / 100 % 10);
    return 0;
}
// Saída:
// Final da placa: 7
// Sem o final: 482
// Metades: 48 e 27
// Final % 2 = 1 (0 é par, 1 é ímpar)
// 48 * 100 + 27 = 4827
// Dígito das centenas: 8
