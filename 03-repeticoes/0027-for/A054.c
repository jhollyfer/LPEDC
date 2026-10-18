// A054 · De 10 em 10, para trás e com letras

#include <stdio.h>

int main(void) {
    // passo de 10: tabela de temperatura
    for (int c = 0; c <= 40; c += 10) {
        double f = c * 1.8 + 32;
        printf("%2d °C = %5.1f °F\n", c, f);
    }

    // para trás: contagem regressiva do réveillon
    for (int s = 5; s >= 1; s--) {
        printf("%d... ", s);
    }
    printf("Feliz Ano Novo!\n");

    // char também é número: as fileiras do ônibus
    for (char fileira = 'A'; fileira <= 'F'; fileira++) {
        printf("%c ", fileira);
    }
    printf("\n");

    // duas variáveis com vírgula: uma sobe, a outra desce
    for (int i = 1, j = 9; i < j; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n");
    return 0;
}
// Saída:
//  0 °C =  32.0 °F
// 10 °C =  50.0 °F
// 20 °C =  68.0 °F
// 30 °C =  86.0 °F
// 40 °C = 104.0 °F
// 5... 4... 3... 2... 1... Feliz Ano Novo!
// A B C D E F 
// (1,9) (2,8) (3,7) (4,6) 
