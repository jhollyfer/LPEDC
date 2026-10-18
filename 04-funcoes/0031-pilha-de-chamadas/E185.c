// 0031 · A pilha de chamadas
// Exercício E185 · ★★★
//
// Um programa de notas travou com divisão por zero. No gdb, o comando bt
// (backtrace) mostrou isto:
//
//   #0  dividir (a=27, b=0) at notas.c:4
//   #1  media (soma=27, quantidade=0) at notas.c:9
//   #2  relatorio (turma=3) at notas.c:15
//   #3  main () at notas.c:22
//
// Responda:
// a) Qual função estava rodando quando o programa travou?
// b) Quem chamou media? E quem chamou relatorio?
// c) Se dividir não tivesse travado, qual função voltaria a rodar primeiro
//    quando ela retornasse? E qual seria a última a terminar?
// d) Onde está o erro de lógica, provavelmente: em dividir ou antes?
// e) Escreva um programa com as quatro funções (dividir, media, relatorio e
//    main) formando essa mesma pilha, mas com a proteção certa: media devolve
//    0 quando quantidade é 0. Com soma 27 e quantidade 3, mostre
//    "Turma 3: média 9.0"; com quantidade 0, "Turma 3: média 0.0".
//
// Dicas:
// 1. O bt lista do topo (#0) para a base (main): a função que estava rodando
//    quando o programa parou aparece primeiro.
// 2. dividir só fez a conta que pediram. Quem deveria ter conferido o zero?
// 3. Resposta esperada: a) dividir; b) relatorio chamou media, main chamou
//    relatorio; c) media volta primeiro, main termina por último; d) antes:
//    media (ou relatorio) passou quantidade 0 adiante sem conferir. e) as
//    duas linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
