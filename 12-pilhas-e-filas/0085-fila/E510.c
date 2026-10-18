// 0085 · Fila
// Exercício E510 · ★★★
//
// O app de corrida mostra a velocidade média dos últimos 3 registros do GPS
// (uma média móvel). As leituras foram 60, 64, 70, 66, 58 e 62 km/h. A partir
// da terceira leitura, mostre a média da janela.
//
// A condição: nada de somar a janela inteira a cada leitura. Guarde a janela
// numa fila do fila.h e mantenha uma soma: quando um valor entra, soma; quando
// a janela passa de 3, o mais antigo sai da fila e é subtraído. Cada leitura
// custa O(1), qualquer que seja o tamanho da janela.
//
//   Saída esperada:
//   Leitura 3: média 64.7 km/h
//   Leitura 4: média 66.7 km/h
//   Leitura 5: média 64.7 km/h
//   Leitura 6: média 62.0 km/h
//
// Dicas:
// 1. A fila é a escolha certa porque o primeiro a sair da janela é o
//    primeiro que entrou.
// 2. Faça a divisão em double: soma / 3.0.
// 3. Resposta esperada: as quatro linhas acima (194/3, 200/3, 194/3,
//    186/3).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "fila.h"

int main(void) {

    return 0;
}
