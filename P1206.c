// Lista · Módulo 12 · Pilhas e filas
// Exercício P1206 · ★☆☆ · Palíndromo pelas duas pontas do deque
//
// Um deque deixa tirar dos dois lados, e isso resolve o palíndromo: ponha
// todas as letras no deque e vá tirando uma da frente e uma de trás,
// comparando. Escreva um deque de char sobre vetor circular (capacidade 32)
// com insere_fim, retira_inicio, retira_fim e tamanho, e
//
//   bool palindromo(const char *palavra)
//
// Teste com arara, osso, ovo, casa e a.
//
//   Saída esperada:
//   arara: sim
//   osso: sim
//   ovo: sim
//   casa: não
//   a: sim
//
// Dicas:
// 1. Campos: char v[32]; int inicio, n. O fim é (inicio + n) % CAP.
//    retira_fim pega v[(inicio + n - 1) % CAP] e faz n--.
// 2. Pare quando sobrar 0 ou 1 letra: a do meio não tem par.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
