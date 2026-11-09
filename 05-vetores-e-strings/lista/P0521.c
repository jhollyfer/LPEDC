// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0521 · ★★★ · Quem ganhou o jogo da velha
//
// Escreva o juiz do jogo da velha. O tabuleiro tem 3 linhas de 3 casas, com
// 'X', 'O' ou '.' (casa vazia), e cada linha é uma string: char t[3][4] (3
// letras + '\0'). Escreva:
//
//   char vencedor(char t[3][4]);  // 'X', 'O' ou '.' se ninguém fechou linha
//   bool cheio(char t[3][4]);     // true se não sobrou casa vazia
//
// e void julgar(char t[3][4]), que mostra o tabuleiro e uma das três frases:
// "Vitória do X", "Deu velha" ou "Em andamento". Julgue os quatro tabuleiros
// abaixo (escritos linha por linha):
//
//   "XOX" "OXO" "OOX"   (X na diagonal principal)
//   "OXX" "XOO" "XOX"   (cheio, ninguém fechou)
//   "XX." "OO." "..."   (ainda tem jogo)
//   "XXO" "XOX" "OXX"   (O na diagonal secundária)
//
//   Saída esperada:
//   Jogo 1:
//   X O X
//   O X O
//   O O X
//   Vitória do X
//   Jogo 2:
//   O X X
//   X O O
//   X O X
//   Deu velha
//   Jogo 3:
//   X X .
//   O O .
//   . . .
//   Em andamento
//   Jogo 4:
//   X X O
//   X O X
//   O X X
//   Vitória do O
//
// Dicas:
// 1. São 8 linhas para conferir: 3 linhas, 3 colunas e 2 diagonais. Para cada
//    uma, as três casas são iguais e diferentes de '.'?
// 2. Um laço de i = 0 a 2 confere a linha i (t[i][0], t[i][1], t[i][2]) e a
//    coluna i (t[0][i], t[1][i], t[2][i]). As diagonais ficam fora do laço.
// 3. A ordem dos testes no julgar importa: um tabuleiro cheio pode ter
//    vencedor, então pergunte primeiro por vencedor.
// 4. Os tabuleiros estão em char jogos[4][3][4]: 4 jogos, 3 linhas, 3 letras
//    + '\0'. jogos[k] é um char [3][4]: passe direto para a função.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char jogos[4][3][4] = {
        {"XOX", "OXO", "OOX"},
        {"OXX", "XOO", "XOX"},
        {"XX.", "OO.", "..."},
        {"XXO", "XOX", "OXX"},
    };
    (void) jogos; // apague esta linha quando escrever

    return 0;
}
