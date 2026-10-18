// 0107 · Endereçamento aberto
// Exercício E638 · ★☆☆
//
// Sem rodar, preveja a saída. O número entre parênteses é a quantidade de
// sondagens de cada inserção:
//
//   #define M 8
//   
//   int main(void) {
//       int tab[M] = {0}; // 0 = livre (nenhuma chave é 0)
//       int chaves[] = {16, 8, 3, 24, 11};
//       for (int k = 0; k < 5; k++) {
//           int i = chaves[k] % M;
//           int s = 1;
//           while (tab[i] != 0) {
//               i = (i + 1) % M;
//               s++;
//           }
//           tab[i] = chaves[k];
//           printf("%d: vaga %d (%d)\n", chaves[k], i, s);
//       }
//       return 0;
//   }
//
// Dicas:
// 1. Calcule os restos por 8: 16 -> 0, 8 -> 0, 3 -> 3, 24 -> 0, 11 -> 3.
// 2. O 24 chega quando as vagas 0 e 1 já estão ocupadas.
// 3. Resposta esperada: 16: vaga 0 (1); 8: vaga 1 (2); 3: vaga 3 (1);
//    24: vaga 2 (3); 11: vaga 4 (2).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
