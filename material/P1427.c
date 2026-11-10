// Lista · Módulo 14 · Árvores
// Exercício P1427 · ★★★ · A mediana que acompanha o fluxo
//
// O app de delivery mostra, a cada pedido entregue, a MEDIANA do tempo de
// entrega do dia até agora. Os tempos chegam assim, em minutos:
// 35, 12, 50, 20, 41, 8, 27, 60. Ordenar tudo a cada pedido seria caro; use
// DOIS heaps:
//
// - baixo: heap de MÁXIMO com a metade menor dos tempos;
// - alto: heap de MÍNIMO com a metade maior.
//
// Para cada tempo x: se baixo está vazio ou x <= raiz de baixo, ele entra em
// baixo; senão, em alto. Depois equilibre: baixo pode ter no máximo um a mais
// que alto (se tiver dois a mais, passe a raiz de baixo para alto; se alto
// ficar maior, passe a raiz de alto para baixo). A mediana é a raiz de
// baixo (quantidade ímpar) ou a média das duas raízes (par).
//
//   Saída esperada:
//   chegou 35: mediana 35.0
//   chegou 12: mediana 23.5
//   chegou 50: mediana 35.0
//   chegou 20: mediana 27.5
//   chegou 41: mediana 35.0
//   chegou  8: mediana 27.5
//   chegou 27: mediana 27.0
//   chegou 60: mediana 31.0
//
// Dicas:
// 1. Um parâmetro sinal (1 ou -1) deixa um só sobe/desce servir para os dois
//    heaps: compare sinal * h[i] com sinal * h[pai].
// 2. Escreva insere(h, &n, x, sinal) e extrai(h, &n, sinal).
// 3. Cada pedido custa O(log n), e a mediana sai em O(1).
// 4. Use printf("chegou %2d: mediana %.1f\n", ...) e divida por 2.0.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
