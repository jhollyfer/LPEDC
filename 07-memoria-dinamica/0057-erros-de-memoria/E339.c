// 0057 · Erros de memória
// Exercício E339 · ★★☆
//
// O placar do campeonato de futsal da firma guarda os gols dos 3 times. O
// programa tem um erro de propósito (o gcc até avisa). Rode e leia o aviso e
// o relatório. Depois conserte fazendo de backup uma cópia DE VERDADE, num
// bloco só dele. Para provar que ficou independente, zere placar[0] (o
// jogo foi anulado) antes de mostrar os dois.
//
//   Saída esperada depois do conserto:
//   Placar: 0 2 7
//   Backup: 4 2 7
//   Placar encerrado
//
// Dicas:
// 1. Procure "attempting double-free". Quantos blocos existem? Quantos
//    free?
// 2. backup = placar copia o ENDEREÇO, não os números.
// 3. Resposta esperada: a saída acima. No original, placar e backup apontam
//    para o MESMO bloco e liberar os dois é free duplo. Com
//    int *backup = malloc(3 * sizeof *backup); e um laço que copia os 3
//    números, são dois blocos: aí, sim, cada um tem o seu free.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *placar = malloc(3 * sizeof *placar);
    if (placar == NULL) {
        return 1;
    }
    placar[0] = 4;
    placar[1] = 2;
    placar[2] = 7;
    int *backup = placar; // "guardando uma cópia"

    printf("Gols: %d %d %d\n", backup[0], backup[1], backup[2]);
    free(placar);
    printf("Placar encerrado\n");
    free(backup);
    return 0;
}
