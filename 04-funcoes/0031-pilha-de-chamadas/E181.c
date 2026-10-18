// 0031 · A pilha de chamadas
// Exercício E181 · ★☆☆
//
// Desenhe (em texto) a pilha de chamadas no momento em que a linha marcada
// com (*) roda. Liste os quadros de baixo para cima, com os parâmetros e as
// locais que já têm valor.
//
//   double quadrado(double x) {
//       return x * x;                       // (*)
//   }
//
//   double imc(double peso, double altura) {
//       return peso / quadrado(altura);
//   }
//
//   int main(void) {
//       double resultado = imc(72.0, 1.80);
//       printf("IMC: %.1f\n", resultado);
//       return 0;
//   }
//
// Dicas:
// 1. Quem chamou quadrado? E quem chamou essa função?
// 2. resultado ainda não tem valor: o main está esperando imc voltar.
// 3. Resposta esperada (base -> topo): main (resultado ainda sem valor) ->
//    imc (peso = 72.0, altura = 1.80) -> quadrado (x = 1.80). Ao rodar,
//    mostra "IMC: 22.2".
//
// Escreva sua resposta abaixo (em comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
