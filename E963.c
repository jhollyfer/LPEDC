// 0161 · Juntando tudo
// Exercício E963 · ★★☆
//
// O grep tem a opção -w: só vale a ocorrência que é uma palavra INTEIRA.
// Procurando "sal", "salada" e "salsicha" não contam. Escreva
// int conta_palavra(const char *linha, const char *padrao), que usa o pb_kmp
// para pegar as posições e conta só as ocorrências sem letra, dígito ou '_'
// colados antes ou depois. Mostre as linhas que têm "sal" como palavra:
//
//   "churrasco: sal grosso na picanha"
//   "salada de alface e tomate"
//   "pouco sal, por favor"
//   "cachorro-quente com salsicha"
//   "faltou sal!"
//   "o sal_marinho acabou"
//
//   Saída esperada:
//   1: churrasco: sal grosso na picanha
//   3: pouco sal, por favor
//   5: faltou sal!
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "0161-padroes.h"

int main(void) {

    return 0;
}
