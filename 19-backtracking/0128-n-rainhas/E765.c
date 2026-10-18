// 0128 · N-rainhas
// Exercício E765 · ★★☆
//
// No tabuleiro 8 × 8 do clube, alguém colou a rainha da linha 0 na coluna 3,
// e ela não sai mais. Quantas das 92 soluções do 8-rainhas ainda são
// possíveis? Escreva o programa (pode partir do código do texto) e mostre a
// primeira solução encontrada e o total.
//
//   Saída esperada:
//   primeira: 3 0 4 7 1 6 2 5
//   18 soluções com a rainha em (0, 3)
//
// Dicas:
// 1. Jeito simples: na linha 0, só deixe passar c == 3 (um continue a
//    mais no laço).
// 2. Jeito melhor: marque a coluna 3 e as diagonais da casa (0, 3) no main,
//    ponha pos[0] = 3 e comece a busca em rainha(1). Os dois jeitos dão o
//    mesmo resultado; o segundo nem visita as outras colunas da linha 0.
// 3. Para mostrar só a primeira, guarde uma cópia de pos quando o contador
//    de soluções passar de 0 para 1.
// 4. Resposta esperada: as 2 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
