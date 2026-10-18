// 0034 · Módulos: .h, .c e compilação separada
// Exercício E201 · ★★☆
//
// Resposta:
// a) gcc -std=c17 -Wall -Wextra -c main.c      (gera main.o)
//    gcc -std=c17 -Wall -Wextra -c treino.c    (gera treino.o)
//    gcc main.o treino.o -o academia           (liga)
// b) Só gcc -c treino.c e a ligação. O main.o não muda.
// c) Os dois gcc -c e a ligação: main.c e treino.c incluem o treino.h, e o
//    texto colado neles mudou.
// d) O .h não é compilado sozinho: o #include cola o texto dele dentro de cada
//    .c, e é o .c que vai para o compilador.
