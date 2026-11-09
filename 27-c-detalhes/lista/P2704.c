// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2704 · ★☆☆ · Quatro operações sobre um bit
//
// Escreva as funções abaixo, com n de 0 a 7, e uma void mostrar(unsigned x)
// que escreve os 8 bits de baixo de x:
//
//   bool testar(unsigned x, int n)
//   unsigned ligar(unsigned x, int n)
//   unsigned desligar(unsigned x, int n)
//   unsigned inverter(unsigned x, int n)
//
// Comece com x = 0x2C e mostre o que se pede.
//
//   Saída esperada:
//   x = 00101100
//   bit 3 ligado? sim
//   ligar 0 -> 00101101
//   desligar 5 -> 00001100
//   inverter 7 -> 10101100
//
// Dicas:
// 1. A máscara do bit n é 1u << n.
// 2. Ligar é |, desligar é & com ~, inverter é ^, testar é (x >> n) & 1u.
// 3. Cada operação parte do x original: as funções não mudam x.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
