// 0034 · Módulos: .h, .c e compilação separada
// Exercício E201 · ★★☆
//
// O app de academia tem três arquivos: main.c, treino.c e treino.h (o main.c
// e o treino.c incluem o treino.h). Responda:
//
// a) Escreva os três comandos gcc para compilar cada .c em separado (gerando
//    os .o) e depois ligar tudo no executável "academia".
// b) Você corrigiu um erro dentro de uma função de treino.c. Quais comandos
//    precisa repetir?
// c) Você mudou um protótipo em treino.h. Quais comandos precisa repetir?
// d) Por que o treino.h não aparece em nenhum comando?
//
// Dicas:
// 1. gcc -c arquivo.c gera arquivo.o; para ligar, passe os .o e -o nome.
// 2. Quem usa o .h precisa ser recompilado quando ele muda.
// 3. Resposta esperada: a) gcc -std=c17 -Wall -Wextra -c main.c;
//    gcc -std=c17 -Wall -Wextra -c treino.c; gcc main.o treino.o -o academia.
//    b) compilar treino.c e ligar de novo (main.o continua valendo).
//    c) compilar os dois .c e ligar, porque os dois incluem o .h.
//    d) porque o .h não é compilado sozinho: ele é colado pelo #include
//    dentro de cada .c. (Ferramentas como o make fazem essas contas por você.)
//
// Escreva sua resposta abaixo (em comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
