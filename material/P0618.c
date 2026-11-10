// Lista · Módulo 06 · Ponteiros
// Exercício P0618 · ★★☆ · Ponteiro para uma linha inteira
//
// Numa matriz int m[3][4], o nome m vira um ponteiro para a primeira LINHA:
// o tipo é int (*)[4], e m + 1 pula 4 int de uma vez. Com as notas de 3
// alunos em 4 provas,
//
//   int notas[3][4] = {{7, 8, 6, 9}, {5, 6, 7, 4}, {10, 9, 9, 8}};
//
// escreva void medias(int (*linha)[4], int n, double *saida), que anda com
// o ponteiro linha (linha++) pelas n linhas e calcula a média de cada uma em
// saida[i]. Mostre as médias e, para ver o salto, sizeof *linha e a
// distância em bytes entre notas e notas + 1:
//
//   Saída esperada:
//   Aluno 1: 7.50
//   Aluno 2: 5.50
//   Aluno 3: 9.00
//   sizeof *p = 16 bytes
//   notas + 1 fica 16 bytes depois de notas
//
// Dicas:
// 1. Dentro de medias, (*linha)[j] é a nota j da linha atual (os parênteses
//    são obrigatórios: *linha[j] seria *(linha[j])).
// 2. A distância em bytes: (char *) (notas + 1) - (char *) notas.
// 3. O parâmetro int (*linha)[4] é o mesmo que int linha[][4]: o compilador
//    precisa saber o tamanho da linha para dar o salto.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int notas[3][4] = {{7, 8, 6, 9}, {5, 6, 7, 4}, {10, 9, 9, 8}};
    (void) notas; // apague esta linha quando escrever

    return 0;
}
