// Lista · Módulo 07 · Memória dinâmica
// Exercício P0717 · ★★☆ · A média móvel do sensor
//
// Um sensor de temperatura de uma câmara fria manda uma leitura por minuto, e
// o painel mostra a média das K últimas. Guarde as últimas K leituras num
// bloco de K double alocado com malloc, usado em roda (buffer circular): a
// leitura nova entra na posição pos, que avança e volta a 0 depois da
// última. Com K = 4 e as leituras abaixo, mostre, a cada minuto, a média do
// que já está guardado (no começo, menos de K):
//
//   double leituras[9] = {4.0, 4.5, 5.0, 6.5, 8.0, 7.5, 5.0, 4.0, 3.5};
//
//   Saída esperada:
//   Min 1: leitura 4.0, média das últimas 1 = 4.00
//   Min 2: leitura 4.5, média das últimas 2 = 4.25
//   Min 3: leitura 5.0, média das últimas 3 = 4.50
//   Min 4: leitura 6.5, média das últimas 4 = 5.00
//   Min 5: leitura 8.0, média das últimas 4 = 6.00
//   Min 6: leitura 7.5, média das últimas 4 = 6.75
//   Min 7: leitura 5.0, média das últimas 4 = 6.75
//   Min 8: leitura 4.0, média das últimas 4 = 6.12
//   Min 9: leitura 3.5, média das últimas 4 = 5.00
//
// Dicas:
// 1. Guarde: double *janela, int pos (onde entra a próxima), int usados
//    (quantas posições já têm leitura, até K) e double soma.
// 2. Ao entrar uma leitura com a janela cheia, tire da soma o valor que vai
//    ser sobrescrito (janela[pos]) antes de escrever o novo.
// 3. pos = (pos + 1) % K faz a volta.
// 4. A média é soma / usados: sem somar a janela inteira a cada minuto.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double leituras[9] = {4.0, 4.5, 5.0, 6.5, 8.0, 7.5, 5.0, 4.0, 3.5};
    (void) leituras; // apague esta linha quando escrever

    return 0;
}
