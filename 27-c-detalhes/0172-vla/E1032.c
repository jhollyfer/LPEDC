// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1032 · ★★★
//
// Escreva long long soma_quadrados(int n), que soma 1² + 2² + ... + n²
// guardando os quadrados num vetor antes de somar. A função escolhe onde
// pôr o vetor:
//
//   - n <= 0: não cria nada e devolve -1;
//   - n <= 1000: um VLA long long v[n] na pilha (mostra "pilha, ");
//   - n maior: malloc (mostra "heap, "), com NULL conferido e free.
//
// No main, para n = 0, 10 e 100000, mostre "n = ...: " e depois "invalido"
// ou "soma = ...".
//
//   Saída esperada:
//   n = 0: invalido
//   n = 10: pilha, soma = 385
//   n = 100000: heap, soma = 333338333350000
//
// Dicas:
// 1. O VLA vai dentro do bloco do if: ele só existe ali, e só é criado
//    quando o n já foi conferido.
// 2. Para o quadrado não estourar o int, converta antes de multiplicar:
//    (long long)(i + 1) * (i + 1).
// 3. Confira com a fórmula n(n + 1)(2n + 1) / 6.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
