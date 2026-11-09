// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0929 · ★★★ · O recado cifrado da linha de comando
//
// A cifra de César troca cada letra pela que está k posições adiante no
// alfabeto (com k = 3, a vira d, x vira a). Escreva um programa chamado
// assim:
//
//   $ ./rodar P0929.c 3 ataque ao amanhecer
//
// O primeiro argumento é a chave k; os outros são as palavras do recado. O
// programa cifra o recado (palavras separadas por um espaço), grava o texto
// cifrado em /tmp/p0929_recado.txt (sem '\n' no fim), lê o arquivo de
// volta, mostra o cifrado e o tamanho do arquivo, decifra o que leu (chave
// -k) e mostra o recado de novo. Maiúsculas giram dentro de A-Z, e o que
// não é letra passa igual. Se faltar argumento ou a chave não for número,
// mostre "uso: P0929 chave palavra1 palavra2 ..." e termine com return 1.
//
//   Saída esperada:
//   Cifrado: dwdtxh dr dpdqkhfhu
//   Arquivo: 19 bytes
//   Decifrado: ataque ao amanhecer
//
// Dicas:
// 1. Para girar uma minúscula: 'a' + ((c - 'a' + k) % 26 + 26) % 26. O
//    "+ 26) % 26" conserta o resto negativo quando k é negativo.
// 2. Valide a chave com strtol e o ponteiro de fim, como no assunto 0069.
// 3. Grave com fputc letra por letra (e um espaço entre as palavras) e leia
//    de volta com fgets.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
