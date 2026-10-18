// 0031 · A pilha de chamadas
// Exercício E181 · ★☆☆
//
// Faça o programa do IMC mostrar a pilha enquanto roda. Escreva:
//
//   double quadrado(double x)                  devolve x * x
//   double imc(double peso, double altura)     devolve peso / quadrado(altura)
//
// Cada função mostra uma linha ao entrar (com os parâmetros) e outra ao sair
// (com o valor que devolve), recuada 2 espaços a mais que a de quem a chamou.
// O main calcula imc(72.0, 1.80), guarda numa local e mostra o resultado.
//
//   Saída esperada:
//   main chama imc
//     entra imc(peso = 72.0, altura = 1.80)
//       entra quadrado(x = 1.80)
//       sai quadrado -> 3.24
//     sai imc -> 22.2
//   IMC: 22.2
//
// Dicas:
// 1. Os espaços do recuo podem ir direto no texto do printf.
// 2. Em imc, guarde o retorno de quadrado numa local antes de dividir; assim
//    a linha "sai imc" pode mostrar o resultado.
// 3. Resposta esperada: a saída acima. Na hora em que quadrado roda, a pilha
//    tem três quadros: main (esperando), imc (esperando) e quadrado no topo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
