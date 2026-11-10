// A089 · Duas cancelas, um contador

#include <stdio.h>

int main(void) {
    int vagas = 40; // vagas livres no estacionamento do shopping

    // dois ponteiros podem apontar para a MESMA variável
    int *entrada = &vagas, *saida = &vagas; // o * vai em cada nome
    int *cancela_vip = NULL;                // ainda não foi instalada

    *entrada -= 1; // entrou um carro
    *entrada -= 1; // entrou outro
    *saida += 1;   // saiu um
    printf("vagas = %d\n", vagas);

    // comparar ponteiros pergunta "apontam para a mesma gaveta?"
    printf("entrada == saida? %d\n", entrada == saida);
    printf("*entrada = %d, *saida = %d\n", *entrada, *saida);

    // antes de usar *cancela_vip, confira: *NULL derruba o programa
    if (cancela_vip != NULL) {
        *cancela_vip -= 1;
    } else {
        printf("cancela VIP desligada: nada a fazer\n");
    }

    int vagas_moto = 12;
    saida = &vagas_moto; // saida agora aponta para outra gaveta
    *saida += 1;
    printf("entrada == saida? %d\n", entrada == saida);
    printf("vagas = %d, vagas_moto = %d\n", vagas, vagas_moto);
    return 0;
}
// Saída:
// vagas = 39
// entrada == saida? 1
// *entrada = 39, *saida = 39
// cancela VIP desligada: nada a fazer
// entrada == saida? 0
// vagas = 39, vagas_moto = 13
