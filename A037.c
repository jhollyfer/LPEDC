// A037 · A situação no fim do semestre

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double nota1 = 6.5;
    double nota2 = 8.0;
    int frequencia = 80; // porcentagem de presença

    // guarda: dado impossível sai logo
    if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 ||
        frequencia < 0 || frequencia > 100) {
        printf("Dados inválidos.\n");
        return 1;
    }

    double media = (nota1 + nota2) / 2;
    bool presente = frequencia >= 75;
    printf("Média: %.2f\n", media);
    printf("Frequência: %d%% (%s)\n", frequencia, presente ? "ok" : "abaixo de 75%");

    if (!presente) { // a falta reprova antes de olhar a nota
        printf("Reprovado por falta.\n");
    } else if (media >= 7) {
        printf("Aprovado.\n");
    } else if (media >= 4) {
        printf("Recuperação: precisa de %.2f na prova final.\n", 10 - media);
    } else {
        printf("Reprovado por nota.\n");
    }

    switch ((int) media) { // o cast corta as casas: 7.25 vira 7
    case 10:
    case 9:
        printf("Menção: excelente\n");
        break;
    case 8:
    case 7:
        printf("Menção: bom\n");
        break;
    default:
        printf("Menção: precisa melhorar\n");
    }
    return 0;
}
// Saída:
// Média: 7.25
// Frequência: 80% (ok)
// Aprovado.
// Menção: bom
