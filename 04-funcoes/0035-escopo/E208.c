// 0035 · Escopo e tempo de vida
// Exercício E208 · ★★☆
//
// O vale-refeição foi escrito com uma variável global. Primeiro preveja a
// saída. Depois refatore: tire a global, faça gastar receber o saldo e
// devolver o saldo novo, e mantenha a mesma saída.
//
//   double saldo = 300.00;
//
//   double preco_com_taxa(double valor) {
//       saldo = saldo - 1.00; // "taxa escondida"
//       return valor;
//   }
//
//   void gastar(double valor) {
//       saldo = saldo - preco_com_taxa(valor);
//   }
//
//   int main(void) {
//       gastar(45.00);
//       gastar(32.50);
//       printf("Saldo: R$ %.2f\n", saldo);
//       return 0;
//   }
//
// Dicas:
// 1. Toda função mexe na mesma global, inclusive a que só deveria calcular um preço.
// 2. Na versão nova: double gastar(double saldo, double valor) devolve
//    saldo - valor - 1.00, e o main faz saldo = gastar(saldo, 45.00).
// 3. Resposta esperada: Saldo: R$ 220.50 (300 - 45 - 1 - 32.50 - 1). Sem
//    global, a taxa fica visível na função que a cobra.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
