// Lista · Módulo 12 · Pilhas e filas
// Exercício P1211 · ★★☆ · Pós-fixa com potência (que associa à direita)
//
// Escreva void para_posfixa(const char *in, char *out), que converte uma
// expressão infixa com variáveis de UMA letra (A a Z), os operadores + - *
// / ^ e parênteses para a notação pós-fixa, com uma pilha de operadores.
// A potência tem a maior precedência e associa à DIREITA: A^B^C é A^(B^C).
// Os outros associam à esquerda: A-B-C é (A-B)-C.
//
//   Saída esperada:
//   A+B*C -> ABC*+
//   (A+B)*C -> AB+C*
//   A-B-C -> AB-C-
//   A^B^C -> ABC^^
//   A*(B+C)^D -> ABC+D^*
//   A/B^C-D -> ABC^/D-
//
// Dicas:
// 1. Letra vai direto para a saída. '(' é empilhado. ')' desempilha para a
//    saída até achar o '(' (que é descartado).
// 2. Operador op: enquanto o topo for operador e tiver precedência MAIOR
//    que op, ou IGUAL e op associar à esquerda, desempilhe para a saída.
//    Depois empilhe op. Com ^ e ^ no topo, a igualdade não desempilha.
// 3. No fim, desempilhe tudo para a saída e termine com '\0'.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
