// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0524 · ★★★ · A nuvem de palavras do trava-língua
//
// Conte quantas vezes cada palavra aparece no trava-língua abaixo, sem
// diferenciar maiúscula de minúscula. Mostre as palavras na ordem em que
// apareceram pela primeira vez e, no fim, a mais repetida (no empate, a que
// apareceu antes):
//
//   char frase[] = "O rato roeu a roupa do Rei de Roma, e o rei riu do rato.";
//
// Guarde as palavras distintas numa matriz char palavras[20][16] e as
// contagens num vetor int cont[20].
//
//   Saída esperada:
//   o      2
//   rato   2
//   roeu   1
//   a      1
//   roupa  1
//   do     2
//   rei    2
//   de     1
//   roma   1
//   e      1
//   riu    1
//   Distintas: 11
//   Mais repetida: o (2 vezes)
//
// Dicas:
// 1. Monte cada palavra numa string auxiliar char p[16]: junte letras
//    (isalpha), já em minúscula (tolower); ao ver algo que não é letra, se p
//    tiver alguma letra, feche com '\0' e processe.
// 2. Processar: procure p em palavras[0..n-1] com strcmp. Achou na posição
//    k? cont[k]++. Não achou? strcpy(palavras[n], p), cont[n] = 1, n++.
// 3. Cuidado com a última palavra: se a frase não terminar com pontuação,
//    ela fica em p quando o laço acaba. Processe-a depois do laço também.
// 4. Resposta esperada: a saída acima (11 palavras distintas).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char frase[] = "O rato roeu a roupa do Rei de Roma, e o rei riu do rato.";
    (void) frase; // apague esta linha quando escrever

    return 0;
}
