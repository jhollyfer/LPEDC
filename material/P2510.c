// Lista · Módulo 25 · Estruturas especiais
// Exercício P2510 · ★☆☆ · A conta da feira em formato esparso
//
// A matriz compras[cliente][produto] (4 clientes, 10 produtos) guarda
// quantas unidades cada cliente levou e está em triplas, só com o que não
// é zero. O vetor preco[] tem o preço de cada produto em R$. A conta de
// cada cliente é a multiplicação matriz × vetor: conta = compras × preco.
// Escreva do zero, fazendo UMA multiplicação por tripla (os zeros não
// custam nada), e mostre quantas multiplicações a matriz cheia faria.
//
//   Triplas (cliente, produto, unidades):
//   (0, 1, 2) (0, 6, 1) (1, 0, 3) (1, 4, 2) (1, 8, 5) (2, 3, 1) (3, 1, 4) (3, 9, 2)
//   Preços: 5 8 12 3 7 10 4 6 2 9
//
//   Saída esperada:
//   cliente 0: R$ 20
//   cliente 1: R$ 39
//   cliente 2: R$ 3
//   cliente 3: R$ 50
//   Multiplicações: 8 (a matriz cheia faria 40)
//
// Dicas:
// 1. conta[t.lin] += t.valor * preco[t.col], para cada tripla t.
// 2. A ordem das triplas nem importa aqui: cada uma soma no seu cliente.
// 3. Resposta esperada: R$ 20, 39, 3 e 50; 8 multiplicações contra 40.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
