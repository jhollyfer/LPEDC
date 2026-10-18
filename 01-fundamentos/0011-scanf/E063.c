// 0011 · scanf
// Exercício E063 · ★★☆
//
// O alarme do celular pede a hora no formato hh:mm. Leia a hora e os
// minutos com UM scanf só e mostre de dois jeitos. Mostre também quantos
// itens o scanf conseguiu ler.
//
//   Exemplo de execução:
//   Alarme (hh:mm): 6:05
//   Itens lidos: 2
//   Alarme para 6h05
//   Alarme para 06:05
//
// Depois rode digitando "6 05" (com espaço no lugar dos dois pontos). O que
// acontece com os itens lidos e com os minutos? Por quê?
//
// Dicas:
// 1. O : no formato tem de aparecer na entrada: "%d:%d".
// 2. Inicialize as variáveis com 0 para o teste com espaço ficar previsível.
// 3. Resposta esperada: com 6:05, "Itens lidos: 2", "Alarme para 6h05" e
//    "Alarme para 06:05". Com "6 05", o scanf lê o 6, espera um ":" e acha
//    um espaço: para ali, lê só 1 item, e os minutos ficam 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
