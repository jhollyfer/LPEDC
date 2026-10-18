// 0157 · Força bruta
// Exercício E937 · ★☆☆
//
// O narrador gritou tanto que a transcrição ficou "gol gol golaco do gol".
// Escreva int conta_ocorrencias(const char *texto, const char *padrao), que
// faz a busca por força bruta, mostra cada posição onde o padrão começa e
// devolve quantas vezes ele aparece (ocorrências sobrepostas também contam).
// No main, procure "gol" e "o" na transcrição:
//
//   Saída esperada:
//   gol: 0 4 8 18 (4 vezes)
//   o: 1 5 9 13 16 19 (6 vezes)
//
// Dicas:
// 1. n = strlen(texto), m = strlen(padrao); guarde os dois em int.
// 2. Os alinhamentos vão de i = 0 até i = n - m, inclusive.
// 3. Para cada i, avance j enquanto j < m e texto[i + j] == padrao[j]. Se j
//    chegou a m, achou em i.
// 4. Resposta esperada: a saída acima. O "gol" de "golaco" conta.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
