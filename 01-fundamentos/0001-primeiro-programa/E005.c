// 0001 · O primeiro programa
// Exercício E005 · ★★★
//
// O número do return chega ao sistema e é assim que scripts e ferramentas
// de CI sabem se um programa deu certo.
// Escreva um programa que mostre "Backup concluído" e termine com return 0.
// Rode assim, de dentro desta pasta:
//
//   ~/LPEDC/rodar E005.c; echo $?
//   ~/LPEDC/rodar E005.c && echo "pode seguir"
//
// Depois troque para return 3 e rode as duas linhas de novo. Por fim, teste
// return 256. Responda como comentário:
//
// a) O que o echo $? mostra com return 0, return 3 e return 256?
// b) Com return 3, a mensagem "pode seguir" aparece? Por quê?
// c) Por que 256 dá esse resultado?
//
// Dicas:
// 1. O $? guarda o código de saída do último comando.
// 2. O && do terminal só roda o segundo comando se o primeiro devolveu 0.
// 3. O sistema guarda só 1 byte (8 bits) do código de saída, e um byte vai
//    de 0 a 255 (você vai ver o porquê no assunto 0003).
// 4. Resposta esperada: a) 0, 3 e 0; b) não: 3 significa erro, e o && para;
//    c) só os 8 bits de baixo chegam ao sistema: 256 é 1 0000 0000 em
//    binário, e os 8 bits de baixo são todos zero.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
