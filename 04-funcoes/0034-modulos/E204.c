// 0034 · Módulos: .h, .c e compilação separada
// Exercício E204 · ★★★
//
// Escreva o módulo "cofrinho" num arquivo só, já organizado como se fosse
// virar cofrinho.h e cofrinho.c: um bloco de protótipos em cima (marcado
// "// cofrinho.h"), o main, e embaixo a implementação (marcada
// "// cofrinho.c"). A interface:
//
//   void depositar(double valor);   ignora valores <= 0
//   bool sacar(double valor);       só saca se tiver saldo; devolve se deu certo
//   double saldo(void);
//   int operacoes(void);            quantos depósitos e saques DERAM CERTO
//
// O saldo e o contador ficam em globais static na parte do cofrinho.c. O main
// faz: deposita 50, deposita -10, saca 30, saca 100, deposita 25.
//
//   Saída esperada:
//   Saque de 30.00: ok
//   Saque de 100.00: sem saldo
//   Saldo: R$ 45.00
//   Operações: 3
//
// O bloco "// cofrinho.h" tem que estar pronto para virar arquivo: com o
// include guard COFRINHO_H em volta dos protótipos.
//
// Dicas:
// 1. static double saldo_atual = 0; e static int contador = 0; no bloco de baixo.
//    Para usar os nomes no main, os protótipos de cima bastam.
// 2. Cuidado: a função se chama saldo, então a variável precisa de outro nome.
// 3. Resposta esperada: a saída acima (o depósito de -10 e o saque de 100 não
//    contam). No bloco do .h: #ifndef COFRINHO_H, #define COFRINHO_H, os
//    quatro protótipos e #endif. No bloco do .c: as duas variáveis static e
//    os corpos das funções.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
