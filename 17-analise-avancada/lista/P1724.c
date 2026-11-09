// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1724 · ★★★ · A fila circular que dobra sem perder a ordem
//
// A fila de senhas de um banco é um vetor CIRCULAR: ini aponta o primeiro,
// num diz quantos há, e o próximo entra em (ini + num) % cap. Quando enche,
// a fila dobra. A pegadinha: não dá para copiar o vetor velho como está,
// porque a fila pode "dar a volta" no fim. É preciso copiar NA ORDEM DA FILA
// (de ini até o fim, depois do começo até ini - 1) para o começo do vetor
// novo, e fazer ini = 0.
//
// Escreva enfileira, desenfileira e cresce, contando as cópias. Comece com
// cap = 1 e rode o dia do esqueleto: 1000 rodadas de "chega, chega, atende,
// chega, atende, chega, atende". Confira que as senhas saem na ordem em que chegaram,
// mostre cada vez que a fila cresceu (de quanto para quanto, e com ini em
// que posição) e o total de cópias, comparado com o número de enfileiramentos.
//
//   Saída esperada:
//   cresce    1 ->    2 (ini era 0)
//   cresce    2 ->    4 (ini era 1)
//   cresce    4 ->    8 (ini era 2)
//   cresce    8 ->   16 (ini era 4)
//   cresce   16 ->   32 (ini era 8)
//   cresce   32 ->   64 (ini era 16)
//   cresce   64 ->  128 (ini era 32)
//   cresce  128 ->  256 (ini era 64)
//   cresce  256 ->  512 (ini era 128)
//   cresce  512 -> 1024 (ini era 256)
//   Crescimentos: 10 | cópias: 1023 | senhas enfileiradas: 4000
//   Atendidas em ordem: sim | na fila: 1000 (cap 1024)
//
// Dicas:
// 1. Em cresce: para i de 0 a num - 1, novo[i] = velho[(ini + i) % cap].
//    Depois libere o velho, ini = 0 e cap *= 2.
// 2. Mostre o ini ANTES da cópia: quando ele não é 0, a fila estava dando a
//    volta, e um memcpy do vetor inteiro embaralharia a ordem.
// 3. As cópias somam 1 + 2 + 4 + ... + 512 < 2 · 1024: menos de uma cópia por
//    senha enfileirada. Custo amortizado O(1).
// 4. Resposta esperada: 11 crescimentos (até cap 1024), 1023 cópias para
//    3000 senhas, ordem conferida, 1000 senhas na fila no fim.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int ini, num, cap;
} Fila;

int main(void) {
    Fila f = {malloc(sizeof(int)), 0, 0, 1};
    if (f.item == NULL) return 1;
    int proxima = 1; // número da próxima senha

    for (int r = 0; r < 1000; r++) {
        // chega, chega, atende, chega, atende, chega, atende
    }
    (void)proxima; // apague esta linha
    free(f.item);
    return 0;
}
