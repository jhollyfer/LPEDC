// 0061 · Vetor de structs
// Exercício E363 · ★★☆
//
// Leia do teclado 3 atletas: o nome (pode ter espaço) numa linha e, na linha
// seguinte, a altura e a idade. Guarde num vetor de structs e mostre o mais
// alto e o mais velho.
//
//   Exemplo de execução:
//   Nome: Rebeca Andrade
//   Altura e idade: 1.55 26
//   Nome: Darlan Romani
//   Altura e idade: 1.88 34
//   Nome: Rayssa Leal
//   Altura e idade: 1.50 17
//   Mais alto: Darlan Romani (1.88 m)
//   Mais velho: Darlan Romani (34 anos)
//
// Para testar sem digitar:
//
//   printf 'Rebeca Andrade\n1.55 26\nDarlan Romani\n1.88 34\nRayssa Leal\n1.50 17\n' | ~/LPEDC/rodar 08-structs/0061-vetor-de-structs/E363.c
//
// Dicas:
// 1. Nome com fgets(v[i].nome, sizeof v[i].nome, stdin) e tire o '\n' com
//    strcspn (assunto 0042).
// 2. Depois do scanf("%lf %d", ...), o '\n' fica no buffer e o próximo fgets
//    leria uma linha vazia. Consuma o resto da linha: while (getchar() != '\n');
//    (num programa de verdade, pare também no EOF).
// 3. Confira o retorno do scanf: tem que ser 2.
// 4. Resposta esperada: com a entrada acima, Darlan Romani nos dois.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
