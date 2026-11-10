// Lista · Módulo 08 · Tipos compostos
// Exercício P0806 · ★☆☆ · As permissões do arquivo
//
// No Linux, as permissões de um arquivo são 9 bits: rwx do dono, rwx do
// grupo e rwx dos outros, do bit 8 ao bit 0 (r vale 4, w vale 2 e x vale 1
// dentro de cada trio). Por isso chmod 754 é 111 101 100 em binário.
// Escreva void mostrar(const char *rotulo, unsigned modo), que mostra o
// rótulo, o número em octal (%o) e as letras (com '-' no lugar do bit
// desligado), e teste com 0754 e 0644.
// Depois, partindo de 0644, ligue o x do dono, desligue o r dos outros e
// INVERTA o w do grupo, mostrando o modo depois de cada passo:
//
//   Saída esperada:
//   chmod 754:             754 rwxr-xr--
//   chmod 644:             644 rw-r--r--
//   liga x do dono:        744 rwxr--r--
//   desliga r dos outros:  740 rwxr-----
//   inverte w do grupo:    760 rwxrw----
//
// Dicas:
// 1. Em C, 0754 (com zero na frente) é um número OCTAL: cada dígito é
//    exatamente um trio de bits.
// 2. Para as letras, ande do bit 8 ao 0: (modo >> b) & 1 diz se o bit b
//    está ligado. A letra do bit b é "rwx"[(8 - b) % 3].
// 3. Ligar: modo |= 1u << 6. Desligar: modo &= ~(1u << 2). Inverter:
//    modo ^= 1u << 4.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
