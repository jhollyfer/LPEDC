// 0031 · A pilha de chamadas
// Exercício E183 · ★★☆
//
// Monte o rastro de uma compra online. Escreva quatro funções que se chamam em
// cadeia: finalizar_compra chama pagar, que chama antifraude, que chama
// consultar_banco. Cada uma recebe o nível (int nivel) e passa nivel + 1 para
// a próxima. Use uma função "void recuo(int nivel)", que mostra 2 espaços por
// nível, para a saída ficar assim:
//
//   Saída esperada:
//   entra finalizar_compra
//     entra pagar
//       entra antifraude
//         consultar_banco: aprovado
//       sai antifraude
//     sai pagar
//   sai finalizar_compra
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
