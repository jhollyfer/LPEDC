// 0062 · Erros de memória
// Exercício E369 · ★★☆
//
// O placar do campeonato de futsal da firma guarda os gols dos 3 times. O
// programa tem um erro de propósito (o gcc até avisa). Rode e leia o aviso e
// o relatório: qual é o erro? Por que "um ponteiro é um backup" é uma ideia errada? Conserte
// mantendo a saída.
//
//   Saída esperada depois do conserto:
//   Gols: 4 2 7
//   Placar encerrado
//
// Dicas:
// 1. Procure "attempting double-free". Quantos blocos existem? Quantos
//    free?
// 2. backup = placar copia o ENDEREÇO, não os números.
// 3. Resposta esperada: placar e backup apontam para o MESMO bloco; liberar
//    os dois é free duplo. Conserto: um só free (apague o free(backup)). Se
//    quisesse uma cópia de verdade, precisaria de outro malloc e de copiar
//    os 3 números.
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
