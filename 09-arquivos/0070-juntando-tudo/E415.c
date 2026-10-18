// 0070 · Juntando tudo
// Exercício E415 · ★☆☆
//
// Placar do bolão. O programa recebe três argumentos: o arquivo, o nome de
// quem apostou e o palpite. Ele ACRESCENTA a linha "nome palpite" no fim do
// arquivo (criando o arquivo se ele não existir) e depois mostra todas as
// linhas, numeradas. Com outra quantidade de argumentos, mostra o uso em
// stderr e devolve 1.
//
//   $ rm -f /tmp/bolao.txt
//   $ rodar E415.c /tmp/bolao.txt Rita 2x1
//   1. Rita 2x1
//   $ rodar E415.c /tmp/bolao.txt Caio 0x0
//   1. Rita 2x1
//   2. Caio 0x0
//
// Dicas:
// 1. O modo que cria se não existe e escreve no fim é o "a".
// 2. Feche o arquivo depois de gravar e abra de novo com "r" para mostrar.
// 3. Resposta esperada: na segunda execução, "1. Rita 2x1" e "2. Caio 0x0".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
