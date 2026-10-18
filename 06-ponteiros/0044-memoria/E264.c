// 0044 · Memória e endereços
// Exercício E264 · ★★★
//
// Um programa tem variáveis de "espécies" diferentes (assunto 0030).
// Escreva um programa com:
//
//   - uma variável global int total_vendas = 0;
//   - uma função void registra(int valor) com uma variável local static
//     int chamadas e mostrando o endereço de chamadas e do parâmetro valor;
//   - no main, uma variável local int caixa = 100 e um texto fixo
//     const char *loja = "Feira"; (mostre o endereço do texto com
//     (void *)loja, sem &).
//
// Chame registra(10) e registra(20) e mostre todos os endereços. Agrupe
// os endereços pelo começo (0x55... ou 0x7f...) e responda: quem mora
// "perto" de quem? Qual endereço se repete nas duas chamadas de registra?
//
// Dicas:
// 1. Olhe só os 4 primeiros dígitos hexa de cada endereço.
// 2. Globais, static e textos fixos vivem enquanto o programa vive; locais
//    e parâmetros nascem e morrem a cada chamada.
// 3. Resposta esperada: total_vendas, chamadas e o texto "Feira" ficam
//    juntos numa região (começando com 0x55... ou 0x56...); caixa e valor
//    ficam em outra, bem mais alta (0x7f...), a pilha. O endereço de
//    chamadas é o mesmo nas duas chamadas; o de valor pode mudar. O mapa
//    completo (pilha, heap, dados e código) é o assunto 0053.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
