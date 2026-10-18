// 0048 · Juntando tudo
// Exercício E283 · ★☆☆
//
// Leia uma frase com fgets e conte quantas vezes aparece cada vogal, sem
// diferenciar maiúscula de minúscula. Guarde as contagens num vetor de 5 int
// e use a string "aeiou" para saber qual vogal é qual.
//
//   Exemplo de execução:
//   Frase: O Rato Roeu A Roupa Do Rei De Roma
//   a: 4
//   e: 3
//   i: 1
//   o: 6
//   u: 2
//
// Dicas:
// 1. char vogais[] = "aeiou"; e int contagem[5] = {0};
// 2. Para cada caractere da frase (até o '\0'), passe por tolower e compare
//    com vogais[0] a vogais[4]. Achou em k? contagem[k]++.
// 3. Não precisa tirar o '\n': ele não é vogal. Mas tirar é um bom hábito.
// 4. Resposta esperada: a execução acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    return 0;
}
