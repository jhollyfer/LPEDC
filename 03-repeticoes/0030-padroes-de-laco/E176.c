// 0030 · Padrões de laço
// Exercício E176 · ★☆☆
//
// Complete as lacunas do controle de gastos do mês. O valor 0 é a sentinela:
// encerra a lista e não conta como gasto. Depois escreva o programa completo
// no arquivo e teste.
//
//   double gasto, total = ____;
//   int quantos = ____;
//   printf("Gasto (0 encerra): ");
//   scanf("%lf", &gasto);
//   while (________) {
//       total = ________;
//       quantos++;
//       printf("Gasto (0 encerra): ");
//       ________;
//   }
//   if (quantos > 0) {
//       printf("Total: R$ %.2f em %d gastos\n", total, quantos);
//       printf("Média: R$ %.2f\n", ________);
//   }
//
//   Com 45.90, 120 e 33.10 e depois 0:
//   Total: R$ 199.00 em 3 gastos
//   Média: R$ 66.33
//
// Dicas:
// 1. Contador e acumulador começam em 0.
// 2. A segunda leitura fica no FIM do corpo: é ela que traz o próximo valor
//    para a pergunta do while (leitura antecipada).
// 3. Resposta esperada: 0.0; 0; gasto != 0; total + gasto;
//    scanf("%lf", &gasto); total / quantos. Saída: R$ 199.00 em 3 gastos,
//    média R$ 66.33.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
