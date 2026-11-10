// Lista · Módulo 08 · Tipos compostos
// Exercício P0819 · ★★☆ · A senha escondida com XOR
//
// O operador ^ (ou exclusivo) tem uma propriedade útil: (x ^ k) ^ k == x.
// Aplicar a mesma chave duas vezes devolve o original. Escreva void
// cifrar(char *s, size_t n, unsigned char chave), que aplica ^ chave em cada
// um dos n bytes de s, e void hexa(const char *s, size_t n), que mostra os n
// bytes em hexadecimal. Cifre a mensagem com a chave 0x5A, mostre os bytes,
// decifre e mostre de novo. Depois conte quantos bits a chave tem ligados e
// mostre a chave em binário:
//
//   char msg[] = "Encontro no Teatro Amazonas, 19h";
//
//   Saída esperada:
//   Cifrada:
//   1F 34 39 35 34 2E 28 35 7A 34 35 7A 0E 3F 3B 2E
//   28 35 7A 1B 37 3B 20 35 34 3B 29 76 7A 6B 63 32
//   Decifrada: Encontro no Teatro Amazonas, 19h
//   Chave 0x5A = 01011010 (4 bits ligados)
//
// Dicas:
// 1. Depois de cifrar, a mensagem pode ter um byte 0 no meio (quando o
//    caractere é igual à chave): por isso a função recebe n e não usa o
//    '\0'. Guarde n = strlen(msg) ANTES de cifrar.
// 2. Em hexa: printf("%02X ", (unsigned char) s[i]).
// 3. Para contar bits: while (x) { cont += x & 1; x >>= 1; }
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    char msg[] = "Encontro no Teatro Amazonas, 19h";
    (void) msg; // apague esta linha quando escrever

    return 0;
}
