// 0078 · Invariantes de laço e corretude
// Exercício E465 · ★★☆
//
// A função ultima() procura a ÚLTIMA vez que um aluno tirou certa nota,
// andando do fim para o começo. Ela já funciona (rode). Prove que está certa
// com os quatro passos, usando o invariante "x não está em v[k+1..n-1]":
//
//   1. início: vale antes da primeira volta?
//   2. manutenção: se vale no começo de uma volta, vale no começo da próxima?
//   3. término: o laço para por um de dois motivos. O que cada um garante?
//   4. parada: que quantidade diminui?
//
// Escreva a prova como comentário.
//
// Dicas:
// 1. No começo, k = n - 1. Quem é v[n..n-1]?
// 2. Uma volta só acontece se v[k] != x. Depois do k--, o pedaço já visto
//    ganhou exatamente esse v[k].
// 3. Atenção à ordem do && no while: o que aconteceria se fosse
//    v[k] != x && k >= 0?
// 4. Resposta esperada: 1) k = n - 1 e v[n..n-1] é vazio: x não está nele;
//    2) a volta só roda se v[k] != x, então depois do k-- o x continua fora
//    de v[k+1..n-1]; 3) se parou com k >= 0, v[k] == x e ninguém à direita é
//    x: é a última ocorrência; se parou com k == -1, x não está em v[0..n-1]
//    e devolver -1 é o certo; 4) k diminui 1 por volta e não passa de -1. O
//    k >= 0 vem primeiro no && para nunca ler v[-1] (curto-circuito).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

// Recebe n >= 0, v e x; devolve o maior k tal que v[k] == x, ou -1 se não há.
int ultima(const int v[], int n, int x) {
    int k = n - 1;
    while (k >= 0 && v[k] != x) {
        k--;
    }
    return k;
}

int main(void) {
    int notas[5] = {7, 9, 4, 9, 6};

    printf("última nota 9: posição %d\n", ultima(notas, 5, 9));
    printf("última nota 5: posição %d\n", ultima(notas, 5, 5));
    return 0;
}
