// Lista · Módulo 08 · Tipos compostos
// Exercício P0810 · ★☆☆ · A configuração com campos nomeados
//
// O som do carro tem uma struct de configuração com vários campos:
//
//   typedef struct {
//       int volume, graves, agudos, balanco;
//       bool loudness;
//       char fonte[12];
//   } Config;
//
// Com os inicializadores designados do C99, você escreve só os campos que
// importam, em qualquer ordem, e o resto vira zero (false, "" para a
// string): Config c = {.fonte = "Bluetooth", .volume = 18};. Monte os três
// perfis abaixo assim e mostre cada um com uma função
// void mostrar(const char *nome, const Config *c):
// - padrao: nada informado (tudo zero);
// - estrada: volume 22, graves 3, loudness ligado, fonte "Radio FM";
// - show: fonte "Pendrive", agudos 4, graves 5, volume 30, balanco -2.
//
//   Saída esperada:
//   padrao   vol  0, graves 0, agudos 0, balanço  0, loudness não, fonte ""
//   estrada  vol 22, graves 3, agudos 0, balanço  0, loudness sim, fonte "Radio FM"
//   show     vol 30, graves 5, agudos 4, balanço -2, loudness não, fonte "Pendrive"
//
// Dicas:
// 1. Config padrao = {0}; zera tudo. Nos outros, use .campo = valor.
// 2. A ordem dos .campo não precisa seguir a da struct.
// 3. Mostre a string vazia entre aspas para ver que ela está lá: "%s".
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
