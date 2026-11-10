// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1902 · ★☆☆ · Cara ou coroa quatro vezes
//
// Na pelada de domingo, o juiz tira cara (C) ou coroa (K) quatro vezes
// para decidir quem escolhe o lado em cada tempo da prorrogação. Quais são
// as sequências possíveis? Aqui pode repetir símbolo: é permutação COM
// repetição, 2 opções em cada uma das 4 posições. O programa abaixo já
// mostra cada sequência e conta; complete o corpo de sorteia(pos), que
// preenche a posição pos com cada símbolo e chama a próxima.
//
//   Saída esperada:
//   CCCC
//   CCCK
//   CCKC
//   CCKK
//   CKCC
//   CKCK
//   CKKC
//   CKKK
//   KCCC
//   KCCK
//   KCKC
//   KCKK
//   KKCC
//   KKCK
//   KKKC
//   KKKK
//   16 sequências, 6 com duas caras
//
// Dicas:
// 1. Não há vetor usado[]: qualquer símbolo pode entrar em qualquer
//    posição, mesmo que já tenha aparecido.
// 2. for (int s = 0; s < 2; s++) { seq[pos] = simbolos[s]; sorteia(pos + 1); }
// 3. Resposta esperada: 16 sequências (2^4), de CCCC até KKKK; 6 delas têm
//    duas caras e duas coroas.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 4

const char simbolos[2] = {'C', 'K'};
char seq[N + 1];
int total = 0, empates = 0;

void sorteia(int pos) {
    if (pos == N) {
        int caras = 0;
        for (int i = 0; i < N; i++) {
            if (seq[i] == 'C') {
                caras++;
            }
        }
        total++;
        if (caras == 2) {
            empates++;
        }
        printf("%s\n", seq);
        return;
    }
    // COMPLETE AQUI
}

int main(void) {
    seq[N] = '\0';
    sorteia(0);
    printf("%d sequências, %d com duas caras\n", total, empates);
    return 0;
}
