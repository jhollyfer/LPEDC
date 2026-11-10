// 0143 · Juntando tudo: um mini-diff
// Exercício E855 · ★★☆
//
// Duas versões de um programa em C estão em vetores de strings, uma linha por
// posição:
//
//   antiga: "#include <stdio.h>", "// versão 1", "int main(void) {",
//           "    printf(\"oi\\n\");", "    return 0;", "}"
//   nova:   "#include <stdio.h>", "// versão 2", "int main(void) {",
//           "    int x = 2;", "    printf(\"%d\\n\", x);", "    return 0;", "}"
//
// Escreva o mini-diff: monte a tabela da LCS dos sufixos e percorra-a do começo
// ao fim. Antes de cada linha, mostre o número dela na versão antiga e na nova
// (igual: os dois; removida: só o antigo; adicionada: só o novo), com estes
// formatos de printf:
//
//   igual:      "%3d %3d   %s\n"
//   removida:   "%3d     - %s\n"
//   adicionada: "    %3d + %s\n"
//
//   Saída esperada:
//     1   1   #include <stdio.h>
//     2     - // versão 1
//         2 + // versão 2
//     3   3   int main(void) {
//     4     -     printf("oi\n");
//         4 +     int x = 2;
//         5 +     printf("%d\n", x);
//     5   6       return 0;
//     6   7   }
//   (4 iguais, 2 removidas, 3 adicionadas)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
