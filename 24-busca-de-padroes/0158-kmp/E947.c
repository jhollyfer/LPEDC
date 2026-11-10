// 0158 · KMP
// Exercício E947 · ★★★
//
// A central do alarme desarma quando a senha 1112 aparece nas teclas. Escreva
// void central(const char *senha, const char *teclas), que usa KMP
// (calcula_pi incluída) e recebe as teclas uma a uma, sem voltar atrás: ao
// achar a senha, mostra a tecla (contando de 1) em que desarmou e a posição
// onde a senha começou (contando de 0) e para; se nunca achar, avisa que
// continua armado. Atenção a sequências como 1, 1, 2, 1, 1, 2: o recuo pela
// tabela pode ter de se repetir. Teste com duas sequências:
//
//   Saída esperada:
//   1121112: desarmou na tecla 7 (a senha começou na posição 3)
//   112112111: continua armado
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAX 16

int main(void) {

    return 0;
}
