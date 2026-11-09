// 0188 · Aproximação
// Exercício E1124 · ★☆☆
//
// Você vai copiar oito pastas para pendrives de 16 GB. Tamanhos, na ordem:
// 9, 7, 5, 8, 3, 6, 4, 2 GB. Implemente o BEST FIT: cada pasta vai para o
// pendrive em que ela cabe e que fica MAIS cheio depois de recebê-la (o de
// menor espaço livre suficiente); se não couber em nenhum, use um novo.
// Mostre o conteúdo de cada pendrive e quanto sobra.
//
//   Saída esperada:
//   Best fit: 3 pendrives
//     pendrive 1: 9 7  (sobram 0 GB)
//     pendrive 2: 5 8 3  (sobram 0 GB)
//     pendrive 3: 6 4 2  (sobram 4 GB)
//
// Dicas:
// 1. Guarde livre[p], qtd[p] e conteudo[p][k] para cada pendrive aberto.
// 2. Percorra todos os pendrives abertos e fique com o de menor livre[p]
//    entre os que têm livre[p] >= tamanho. Empate: o primeiro.
// 3. Resposta esperada: a saída acima. O limite inferior é 44 / 16 -> 3,
//    então esta resposta é ótima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
