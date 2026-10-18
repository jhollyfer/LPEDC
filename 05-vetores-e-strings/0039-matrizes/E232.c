// 0039 · Matrizes
// Exercício E232 · ★★☆
//
// Uma sala de cinema pequena tem 5 fileiras (A a E) de 6 poltronas. Na matriz,
// 1 é ocupada e 0 é livre:
//
//   1 1 0 1 1 1
//   0 0 1 1 0 0
//   1 1 1 1 1 1
//   0 1 0 0 0 1
//   1 0 0 1 1 0
//
// Mostre o mapa com 'X' para ocupada e '.' para livre, o número de lugares
// livres em cada fileira e a fileira com MAIS lugares livres (em caso de
// empate, a primeira).
//
//   Saída esperada:
//   A X X . X X X  livres: 1
//   B . . X X . .  livres: 4
//   C X X X X X X  livres: 0
//   D . X . . . X  livres: 4
//   E X . . X X .  livres: 3
//   Melhor fileira: B
//
// Dicas:
// 1. A letra da fileira é 'A' + f (um char é um número; você vai ver isso no
//    próximo assunto). printf("%c", 'A' + f) mostra A, B, C...
// 2. Conte os livres dentro do laço das colunas e compare com o melhor até
//    agora no laço das linhas (padrão maior, assunto 0025).
// 3. Use > (e não >=) para ficar com a primeira em caso de empate.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define FILEIRAS 5
#define POLTRONAS 6

int main(void) {

    return 0;
}
