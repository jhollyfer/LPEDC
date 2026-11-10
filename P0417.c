// Lista · Módulo 04 · Funções e modularização
// Exercício P0417 · ★★☆ · A pilha da potência na tela
//
// Escreva a potência recursiva "int potencia(int base, int exp, int nivel)"
// (base^0 = 1; base^exp = base × base^(exp − 1)) que mostra a pilha de
// chamadas: ao entrar, mostra a chamada com 2 espaços por nível; ao voltar,
// mostra o resultado no mesmo recuo. O main chama potencia(2, 4, 0):
//
//   Saída esperada:
//   potencia(2, 4)
//     potencia(2, 3)
//       potencia(2, 2)
//         potencia(2, 1)
//           potencia(2, 0) = 1
//         = 2
//       = 4
//     = 8
//   = 16
//   Resultado: 16
//
// Dicas:
// 1. Uma função auxiliar "void recuo(int nivel)" mostra 2 * nivel espaços com
//    um for.
// 2. No caso base, mostre a chamada já com o "= 1" na mesma linha.
// 3. Cada chamada recursiva vai com nivel + 1. Depois que ela volta, mostre
//    "= resultado".
// 4. Resposta esperada: o desenho acima, Resultado: 16.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
