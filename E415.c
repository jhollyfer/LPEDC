// 0070 · Juntando tudo
// Exercício E415 · ★☆☆
//
// Placar do bolão. O programa recebe três argumentos: o arquivo, o nome de
// quem apostou e o palpite. Ele ACRESCENTA a linha "nome palpite" no fim do
// arquivo (criando o arquivo se ele não existir) e depois mostra todas as
// linhas, numeradas. Com outra quantidade de argumentos, mostra o uso em
// stderr e devolve 1.
//
//   Argumentos (arquivo inexistente):
//   /tmp/bolao.txt Rita 2x1
//
//   Saída esperada:
//   1. Rita 2x1
//
//   Argumentos (rodando de novo, com o arquivo já criado):
//   /tmp/bolao.txt Caio 0x0
//
//   Saída esperada:
//   1. Rita 2x1
//   2. Caio 0x0
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    return 0;
}
