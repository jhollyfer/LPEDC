// Lista · Módulo 08 · Tipos compostos
// Exercício P0807 · ★☆☆ · O endereço IP em 32 bits
//
// Um endereço IPv4 como 192.168.10.42 são 4 bytes, e cabe num uint32_t
// (do stdint.h), com o primeiro número nos 8 bits de cima. Escreva:
//
//   uint32_t montar(int a, int b, int c, int d);
//   void mostrar(const char *rotulo, uint32_t ip);  // os 4 bytes: >> e & 0xFF
//
// A máscara de rede /24 tem os 24 bits de cima ligados: 0xFFFFFF00. A REDE
// de um IP é ip & mascara, e o número do computador na rede é ip & ~mascara.
// Mostre o IP, em hexa e em pontos, a rede e o computador, para /24 e /16:
//
//   Saída esperada:
//   192.168. 10. 42  0xC0A80A2A  IP
//   Com /24:
//   255.255.255.  0  0xFFFFFF00  máscara
//   192.168. 10.  0  0xC0A80A00  rede
//     0.  0.  0. 42  0x0000002A  máquina
//   Com /16:
//   255.255.  0.  0  0xFFFF0000  máscara
//   192.168.  0.  0  0xC0A80000  rede
//     0.  0. 10. 42  0x00000A2A  máquina
//
// Dicas:
// 1. montar: ((uint32_t) a << 24) | (b << 16) | (c << 8) | d. O cast vem
//    antes do << para a conta ser feita em 32 bits sem sinal.
// 2. mostrar: (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF e
//    ip & 0xFF.
// 3. Máscara /n: os n bits de cima ligados: 0xFFFFFFFFu << (32 - n) (vale
//    para n de 1 a 31).
// 4. Para mostrar um uint32_t em hexa: printf("%08X", (unsigned) ip).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>

int main(void) {

    return 0;
}
