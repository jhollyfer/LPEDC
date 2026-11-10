// Lista · Módulo 12 · Pilhas e filas
// Exercício P1213 · ★★☆ · A caixa-preta que guarda só as últimas leituras
//
// A caixa-preta do caminhão guarda só as 4 últimas leituras de velocidade:
// quando chega uma nova com o buffer cheio, a MAIS ANTIGA é descartada para
// abrir espaço. É uma fila circular que, em vez de recusar, sobrescreve.
// Escreva
//
//   void registra(Buffer *b, int leitura)   // nunca falha
//   void mostra(const Buffer *b)            // da mais antiga à mais nova
//
// e conte quantas leituras foram sobrescritas. Registre 60, 72, 80, 85, 90,
// 70 e 65 km/h, mostrando o buffer depois da 4ª e no fim.
//
//   Saída esperada:
//   depois de 4: 60 72 80 85
//   no fim: 85 90 70 65
//   sobrescritas: 3
//
// Dicas:
// 1. Campos: int v[4]; int inicio, n. Se n < 4, insira como numa fila
//    comum. Se n == 4, grave em v[inicio] (onde está a mais antiga) e
//    avance inicio: a segunda mais antiga vira a primeira.
// 2. Para mostrar: for (k = 0; k < n; k++) v[(inicio + k) % 4].
// 3. Resposta esperada: a saída acima. Cada registro é O(1), não importa
//    quantas leituras já passaram.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define CAP 4

typedef struct {
    int v[CAP];
    int inicio, n;
} Buffer;

int main(void) {

    return 0;
}
