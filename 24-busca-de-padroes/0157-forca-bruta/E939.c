// 0157 · Força bruta
// Exercício E939 · ★★☆
//
// O cliente escreve "pix" de todo jeito. Escreva a função
// int busca_sem_caixa(const char *texto, const char *padrao), uma força bruta
// que ignora a diferença entre maiúsculas e minúsculas, mostra a posição e o
// trecho achado (do jeito que está no texto) e devolve o total. Teste com a
// mensagem abaixo e o padrão "pix":
//
//   "Recebi um PIX, mandei outro Pix e tem um pix agendado"
//
//   Saída esperada:
//   posição 10: PIX
//   posição 28: Pix
//   posição 41: pix
//   3 ocorrências
//
// Dicas:
// 1. Compare tolower(texto[i + j]) com tolower(padrao[j]) (ctype.h, 0040).
// 2. Passe o char convertido para unsigned char antes do tolower: char
//    negativo (letra acentuada) é comportamento indefinido nas funções de
//    ctype.h.
// 3. printf("%.*s", m, texto + i) mostra só as m letras a partir de i.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    return 0;
}
