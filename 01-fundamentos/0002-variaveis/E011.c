// 0002 · Variáveis
// Exercício E011 · ★★★
//
// Este programa tem TRÊS erros e o gcc mostra um aviso para cada um (numa
// versão mais nova do gcc, um deles já vira erro). Rode, leia os avisos, diga
// o que cada um quer dizer e conserte. O jogo terminou 2 x 1 para o time da
// casa, com público de 45000 pessoas.
//
//   Saída esperada (depois de consertar):
//   Placar: 2 x 1
//   Resultado: V
//   Público: 45000
//
// Dicas:
// 1. Procure as palavras "uninitialized", "pointer" e "format" nos avisos.
// 2. Aspas simples são um caractere; aspas duplas são um texto.
// 3. O %d espera int. Que tipo é publico?
// 4. Resposta esperada: (1) gols_fora não tem valor (lixo; aviso
//    "uninitialized"): int gols_fora = 1;. (2) "V" é texto, não caractere
//    ("makes integer from pointer"): use 'V'. (3) %d com double ("expects
//    argument of type 'int'"): declare publico como int (ou mostre com
//    %.0f).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int gols_casa = 2;
    int gols_fora;
    char resultado = "V";
    double publico = 45000;

    printf("Placar: %d x %d\n", gols_casa, gols_fora);
    printf("Resultado: %c\n", resultado);
    printf("Público: %d\n", publico);
    return 0;
}
