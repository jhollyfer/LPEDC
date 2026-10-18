// 0100 · Quick sort
// Exercício E600 · ★★★
//
// Num app de entregas, as avaliações vão de 1 a 3 estrelas: muitos valores
// iguais. A separação de Lomuto sofre com isso: com 12 valores TODOS iguais,
// cada separação manda todo mundo para a esquerda e o quick sort vira O(n²).
//
// Implemente o quick sort de TRÊS VIAS: a separação deixa v[p..lt-1] menores
// que o pivô, v[lt..gt] iguais e v[gt+1..r] maiores, e a recursão só olha os
// menores e os maiores. Compare as comparações com o Lomuto (conte uma por
// elemento examinado, mesmo que o teste tenha três saídas).
//
//   estrelas: 2, 3, 1, 2, 2, 3, 1, 1, 2, 3, 2, 1
//   iguais:   doze vezes o 2
//
//   Saída esperada:
//   1 a 3 estrelas: Lomuto 30, três vias 23 | 1 1 1 1 2 2 2 2 2 3 3 3
//   todos iguais:   Lomuto 66, três vias 12 | 2 2 2 2 2 2 2 2 2 2 2 2
//
// Dicas:
// 1. Três índices: lt, i e gt. Comece com lt = i = p e gt = r; pivô = v[r].
// 2. v[i] < pivô: troca v[lt] com v[i], avança os dois. v[i] > pivô: troca
//    v[i] com v[gt] e só diminui gt (o que veio de lá ainda não foi visto).
//    Igual: só avança i.
// 3. O laço roda enquanto i <= gt. Depois, recursão em [p, lt-1] e [gt+1, r].
// 4. Todos iguais: uma passada só, sem recursão nenhuma. Lomuto: 11 + 10 +
//    ... + 1 = 66.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
