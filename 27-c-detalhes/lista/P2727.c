// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2727 · ★★★ · O wc de bolso
//
// Escreva um programa que grave o texto abaixo no arquivo p2727_texto.txt,
// feche, e depois o leia caractere por caractere com fgetc, contando linhas
// (quantidade de '\n'), palavras (sequências de não espaços) e bytes, como o
// comando wc do Linux. Apague o arquivo no fim.
//
//   "Bom dia\nfeira no domingo\n\ncafe com pao\n"
//
//   Saída esperada:
//   linhas: 4
//   palavras: 8
//   bytes: 39
//
// Dicas:
// 1. O fgetc devolve int, não char: só assim dá para diferenciar o EOF de
//    um byte válido. int c; while ((c = fgetc(f)) != EOF).
// 2. Uma palavra começa quando c não é espaço e o anterior era espaço (ou é
//    o começo). Use isspace de <ctype.h>.
// 3. A linha em branco conta como linha, mas não tem palavra.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdio.h>

int main(void) {

    return 0;
}
