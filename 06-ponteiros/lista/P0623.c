// Lista · Módulo 06 · Ponteiros
// Exercício P0623 · ★★★ · Separar a linha do CSV no lugar
//
// Uma linha de CSV da agenda do mestrado tem campos separados por ';', e
// alguns podem estar vazios:
//
//   char linha[] = "27/11/2026;Prova de Conhecimentos;;08:00;Manaus";
//
// Escreva int separar(char *linha, char sep, char *campos[], int max), que
// NÃO copia nada: troca cada separador por '\0' dentro da própria linha e
// guarda em campos[i] o endereço do começo de cada campo. Devolve quantos
// campos achou (no máximo max). Campo vazio vira uma string vazia, e não
// some (diferente do strtok, que pula separadores seguidos). Mostre os
// campos e a posição de cada um dentro da linha:
//
//   Saída esperada:
//   5 campos
//   [0] posição  0: "27/11/2026"
//   [1] posição 11: "Prova de Conhecimentos"
//   [2] posição 34: ""
//   [3] posição 35: "08:00"
//   [4] posição 41: "Manaus"
//   A linha agora: "27/11/2026"
//
// Dicas:
// 1. O primeiro campo começa em linha: campos[0] = linha; n = 1.
// 2. Ande com char *p de linha até o '\0'. Ao achar sep: *p = '\0'; e, se
//    n < max, campos[n++] = p + 1.
// 3. A posição de cada campo é campos[i] - linha.
// 4. Depois de separar, printf("%s", linha) mostra só o primeiro campo: o
//    '\0' que você pôs no lugar do ';' termina a string ali.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    char linha[] = "27/11/2026;Prova de Conhecimentos;;08:00;Manaus";
    (void) linha; // apague esta linha quando escrever

    return 0;
}
