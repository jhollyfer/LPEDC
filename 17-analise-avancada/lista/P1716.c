// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1716 · ★★☆ · Contador com zerar: o reset que não varre tudo
//
// O contador de passageiros de uma estação tem 16 bits e duas operações:
// INCREMENTA e ZERA (no fim de cada turno). Zerar varrendo os 16 bits custa
// 16 sempre. Dá para fazer melhor: guarde em maior o índice do bit 1 mais
// alto já ligado desde o último zerar, e zere só os bits 0..maior (custo
// maior + 1).
//
// Com isso, n operações quaisquer custam O(n) no total. Pelo método
// contábil, cada INCREMENTA paga 3: 1 pelo bit que liga, 1 de crédito para
// quando esse bit for desligado, e 1 de crédito para o ZERA varrer a posição,
// caso o incremento tenha subido o maior (ele sobe no máximo 1 por vez).
//
// Escreva as duas versões do zerar e rode a sequência do esqueleto contando o
// custo total de cada uma (incrementar custa os bits trocados; zerar custa os
// bits varridos). Mostre também o limite 3 · (incrementos) + (zerares).
//
//   Saída esperada:
//   Incrementos: 1150 | zerares: 52
//   Zerar varrendo tudo: 3026
//   Zerar até o maior:   2304
//   Limite 3·1150 + 52 = 3502
//
// Dicas:
// 1. No incrementa, depois de ligar o bit i, faça maior = i se i > maior.
//    Comece com maior = -1.
// 2. zera_esperto: para i de 0 até maior, b[i] = 0 (custo maior + 1); depois
//    maior = -1. zera_bobo: varre os 16.
// 3. Um zerar logo depois de outro custa 0 na versão esperta (maior = -1).
// 4. Resposta esperada: versão boba 2228, esperta 2134, limite 3555; nos 50
//    turnos curtos, cada zerar esperto custa 2 em vez de 16.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define K 16

int main(void) {
    // o dia: 50 turnos curtos (3 passageiros e zera), depois um turno de
    // 1000 passageiros, zera, e um zerar repetido por engano
    char op[] = {'i', 'z', 'i', 'z', 'z'};
    int vezes[] = {3, 1, 1000, 1, 1};
    int repete[] = {50, 50, 1, 1, 1}; // os dois primeiros passos se alternam 50 vezes

    for (int k = 0; k < 5; k++) printf("%c x %d (repete %d)\n", op[k], vezes[k], repete[k]);
    return 0;
}
