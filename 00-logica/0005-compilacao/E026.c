// 0005 · Do .c ao executável
// Exercício E026 · ★☆☆
//
// Rode no terminal, dentro desta pasta, e responda como comentário:
//
//   gcc -E E026.c | wc -l
//   gcc -E E026.c | tail -5
//
// a) Quantas linhas o arquivo tem depois do pré-processador?
// b) De onde veio tanta linha, se o arquivo é pequeno?
// c) O que aconteceu com os comentários?
//
// Dicas:
// 1. O wc -l conta linhas.
// 2. Procure no resultado por "printf": ele está declarado lá dentro.
// 3. Resposta esperada: a) algumas centenas (uns 700 a 900, depende do
//    sistema); b) é o conteúdo do stdio.h e dos arquivos que ele inclui, colado
//    no lugar do #include; c) sumiram: o pré-processador apaga os comentários.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
