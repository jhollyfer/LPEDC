// 0001 · O primeiro programa
// Exercício E005 · ★★★
//
// O número do return chega ao sistema, e é assim que scripts e ferramentas
// de CI sabem se um programa deu certo: 0 é sucesso, qualquer outro número
// é um código de erro. Escreva o programa de um backup que FALHOU: ele
// mostra as duas linhas abaixo e devolve o código 2 ao sistema. Rode assim,
// de dentro desta pasta, e confira as três linhas da saída esperada:
//
//   ~/LPEDC/rodar E005.c; echo "código: $?"
//
//   Saída esperada:
//   Backup falhou: disco cheio
//   Código de saída: 2
//   código: 2
//
// Depois rode ~/LPEDC/rodar E005.c && echo "pode seguir" e confira que o
// "pode seguir" NÃO aparece. Por fim, troque para return 258 e rode a
// primeira linha de novo: o terminal tem de mostrar "código: 2" outra vez.
//
// Dicas:
// 1. A segunda linha é um printf comum, com o texto fixo. A terceira quem
//    escreve é o echo do terminal: o $? guarda o código de saída do último
//    comando.
// 2. O && do terminal só roda o segundo comando se o primeiro devolveu 0.
// 3. O sistema guarda só 1 byte (8 bits) do código de saída, e um byte vai
//    de 0 a 255 (o porquê vem no assunto 0003): 258 dá a volta e vira 2.
// 4. Resposta esperada: dois printf e return 2;. A saída acima, sem o
//    "pode seguir"; com return 258, "código: 2" de novo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
