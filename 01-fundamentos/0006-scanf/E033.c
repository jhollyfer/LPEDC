// 0006 · scanf
// Exercício E033 · ★★☆
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
// Depois rode com "6 05" (espaço no lugar dos dois pontos):
// printf '6 05\n' | ~/LPEDC/rodar E033.c. O seu programa tem de mostrar
// "Itens lidos: 1" e os minutos zerados: "Alarme para 6h00".
//
// Dicas:
// 1. O : no formato tem de aparecer na entrada: "%d:%d".
// 2. Inicialize as variáveis com 0 para o teste com espaço ficar previsível.
// 3. Resposta esperada: com 6:05, "Itens lidos: 2", "Alarme para 6h05" e
//    "Alarme para 06:05". Com "6 05", o scanf lê o 6, espera um ":" e acha
//    um espaço: para ali, lê só 1 item, e os minutos ficam 0 ("Alarme para
//    6h00" e "Alarme para 06:00").
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
