// 0135 · Mochila fracionária
// Exercício E809 · ★★★
//
// Uma transportadora tem 8 tipos de carga esperando e um caminhão com 700
// kg livres. Ordenar as 8 pela razão funciona, mas, quando o caminhão
// enche logo, quase toda a ordenação é desperdício. Use um HEAP DE MÁXIMO
// pela razão (assunto 0102): monte o heap em O(n), com a descida a partir
// do último pai, e tire o topo só enquanto houver espaço.
//
//   móveis 400 kg R$ 2000      eletrônicos 150 kg R$ 4500
//   roupas 200 kg R$ 3000      cimento 900 kg R$ 900
//   remédios 50 kg R$ 2500     livros 300 kg R$ 1800
//   brinquedos 250 kg R$ 2750  areia 1000 kg R$ 300
//
//   Saída esperada:
//    50 de   50 kg  R$ 2500.00  remédios
//   150 de  150 kg  R$ 4500.00  eletrônicos
//   200 de  200 kg  R$ 3000.00  roupas
//   250 de  250 kg  R$ 2750.00  brinquedos
//    50 de  300 kg  R$  300.00  livros
//   Total: R$ 13050.00
//   Itens tirados do heap: 5 de 8
//
// Dicas:
// 1. Escreva double razao(Frete f) e a função desce do heap, comparando
//    razões. Monte com: for (int i = n / 2 - 1; i >= 0; i--) desce(v, n, i);
// 2. Para tirar o topo: guarde v[0], ponha v[n - 1] no lugar, diminua n e
//    desça a partir do 0. Depois aplique a regra da mochila no item tirado.
// 3. Resposta esperada: a saída acima (printf("%3.0f de %4.0f kg  R$ %7.2f
//    %s\n", ...)). O custo cai de O(n log n) para O(n + k log n), onde k é o
//    número de itens que entram na carga.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8

typedef struct {
    const char *carga;
    double peso, valor;
} Frete;

int main(void) {
    Frete v[N] = {
        {"móveis", 400, 2000},   {"eletrônicos", 150, 4500}, {"roupas", 200, 3000},
        {"cimento", 900, 900},   {"remédios", 50, 2500},     {"livros", 300, 1800},
        {"brinquedos", 250, 2750}, {"areia", 1000, 300},
    };
    (void)v;

    return 0;
}
