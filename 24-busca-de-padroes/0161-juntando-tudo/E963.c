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
// Dicas:
// 1. Peça as posições: int pos[16]; pb_kmp(linha, n, padrao, m, pos, 16, &comp).
// 2. Para a ocorrência em ini, o lado esquerdo está livre se ini == 0 ou se
//    linha[ini - 1] não é de palavra. O direito, se ini + m == n ou se
//    linha[ini + m] não é de palavra. Confira os limites ANTES de ler.
// 3. "De palavra": isalnum((unsigned char) c) || c == '_'. Por isso
//    "sal_marinho" não conta.
// 4. Resposta esperada: a saída acima. (Com acentos isso complica: o 'ã' em
//    UTF-8 são dois bytes que o isalnum não reconhece como letra. Esta lista
//    foi escolhida sem esse problema.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "padroes.h"

int main(void) {

    return 0;
}
