// A004 · O programa que faz o próprio teste de mesa

#include <stdio.h>

// Troca o conteúdo de dois copos usando um terceiro copo vazio.
// A cada passo, o programa mostra uma linha da tabela do teste de mesa.
int main(void) {
    int suco = 1; // copo A tem suco (1)
    int agua = 2; // copo B tem água (2)
    int vazio = 0;

    printf("passo          | suco | agua | vazio\n");
    printf("início         |  %d   |  %d   |  %d\n", suco, agua, vazio);
    vazio = suco;
    printf("vazio <- suco  |  %d   |  %d   |  %d\n", suco, agua, vazio);
    suco = agua;
    printf("suco <- agua   |  %d   |  %d   |  %d\n", suco, agua, vazio);
    agua = vazio;
    printf("agua <- vazio  |  %d   |  %d   |  %d\n", suco, agua, vazio);
    return 0;
}
// Saída:
// passo          | suco | agua | vazio
// início         |  1   |  2   |  0
// vazio <- suco  |  1   |  2   |  1
// suco <- agua   |  2   |  2   |  1
// agua <- vazio  |  2   |  1   |  1
